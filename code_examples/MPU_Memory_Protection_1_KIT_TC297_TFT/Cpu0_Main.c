/**********************************************************************************************************************
 * \file Cpu0_Main.c
 * \copyright Copyright (C) Infineon Technologies AG 2019
 * 
 * Use of this file is subject to the terms of use agreed between (i) you or the company in which ordinary course of 
 * business you are acting and (ii) Infineon Technologies AG or its licensees. If and as long as no such terms of use
 * are agreed, use of this file is subject to following:
 * 
 * Boost Software License - Version 1.0 - August 17th, 2003
 * 
 * Permission is hereby granted, free of charge, to any person or organization obtaining a copy of the software and 
 * accompanying documentation covered by this license (the "Software") to use, reproduce, display, distribute, execute,
 * and transmit the Software, and to prepare derivative works of the Software, and to permit third-parties to whom the
 * Software is furnished to do so, all subject to the following:
 * 
 * The copyright notices in the Software and this entire statement, including the above license grant, this restriction
 * and the following disclaimer, must be included in all copies of the Software, in whole or in part, and all 
 * derivative works of the Software, unless such copies or derivative works are solely in the form of 
 * machine-executable object code generated by a source language processor.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT SHALL THE 
 * COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN 
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS 
 * IN THE SOFTWARE.
 *********************************************************************************************************************/
 /*\title MPU memory protection
 * \abstract The MPU module is used to protect part of an array from read/write accesses.
 * \description The MPU module is configured to enable read/write access to the first half of an array.
 *              To test the function of the read protection, each element of the array is read in a loop.
 *              Two LEDs are used to indicate the progression of the CPU read accesses.
 *              When the loop reads the last accessible element, the first LED is turned on.
 *              The second LED is only turned on if the CPU reads an element which should be protected.
 *
 * \name MPU_Memory_Protection_1_KIT_TC297_TFT
 * \version V1.0.0
 * \board APPLICATION KIT TC2X7 V1.1, KIT_AURIX_TC297_TFT_BC-Step, TC29xTA/TX_B-Step
 * \keywords AURIX, MPU_Memory_Protection_1, MPU, Data Protection, Code Protection, Memory Protection
 * \documents https://www.infineon.com/aurix-expert-training/Infineon-AURIX_MPU_Memory_Protection_1_KIT_TC297_TFT-TR-v01_00_00-EN.pdf
 * \documents https://www.infineon.com/aurix-expert-training/TC29B_iLLD_UM_1_0_1_11_0.chm
 * \lastUpdated 2020-08-13
 *********************************************************************************************************************/
#include "Ifx_Types.h"
#include "IfxCpu.h"
#include "IfxScuWdt.h"
#include "MPU_Memory_Protection.h"

/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/
#define DUMMY_ELEMENTS_NUM          96      /* Array length. Must be multiple of DPR_GRANULARITY or CPR_GRANULARITY */
#define INDEX_FORTY_EIGHT           48
#define INDEX_FORTY_SEVEN           47
#define FIRST_ADDR                  0x00000000
#define LAST_ADDR                   0xFFFFFFFF

/*********************************************************************************************************************/
/*-------------------------------------------------Global variables--------------------------------------------------*/
/*********************************************************************************************************************/
IfxCpu_syncEvent g_cpuSyncEvent = 0;

int core0_main(void)
{
    IfxCpu_enableInterrupts();
    
    /* !!WATCHDOG0 AND SAFETY WATCHDOG ARE DISABLED HERE!!
     * Enable the watchdogs and service them periodically if it is required
     */
    IfxScuWdt_disableCpuWatchdog(IfxScuWdt_getCpuWatchdogPassword());
    IfxScuWdt_disableSafetyWatchdog(IfxScuWdt_getSafetyWatchdogPassword());
    
    /* Wait for CPU sync event */
    IfxCpu_emitEvent(&g_cpuSyncEvent);
    IfxCpu_waitEvent(&g_cpuSyncEvent, 1);

    /* Initialize the LEDs */
    init_LEDs();

    /* Define an array of integers, specifying an alignment of 8 bytes.
     * Data and Code Protection Ranges have a granularity of 8 bytes.
     */
    uint8 dummyData[DUMMY_ELEMENTS_NUM] __attribute__ ((aligned(DPR_GRANULARITY)));
    
    /* Fill the array with dummy data */
    volatile uint8 i;
    for(i = 0; i < DUMMY_ELEMENTS_NUM; i++)
    {
        dummyData[i] = i; /* Initialize data with incrementing values. It is not necessary, but useful for testing. */
    }

    /* Configure memory protection */

    /* Rules for memory protection range configuration:
     * The lower and upper boundary addresses must be 8 byte aligned.
     * After enabling the Memory Protection, access to an address 'x' will be allowed only if:
     * lowerBoundAddress <= x < upperBoundAddress
     */
    /* Define the Data Protection Range 0: from 0x00000000 up to the address of the 48th index of the dummyData array */
    define_data_protection_range(FIRST_ADDR, (uint32)&dummyData[INDEX_FORTY_EIGHT], DATA_PROTECTION_RANGE_0);
    /* Enable read access to the Data Protection Range 0 in the Protection Set 1 */
    enable_data_read(PROTECTION_SET_1, DATA_PROTECTION_RANGE_0);
    /* Enable write access to the Data Protection Range 0 in the Protection Set 1 */
    enable_data_write(PROTECTION_SET_1, DATA_PROTECTION_RANGE_0);

    /* Define the Data Protection Range 1: from the address of the last element of dummyData array to 0xFFFFFFFF*/
    define_data_protection_range((uint32)&dummyData[DUMMY_ELEMENTS_NUM - 1], LAST_ADDR, DATA_PROTECTION_RANGE_1);
    /* Enable read access to the Data Protection Range 1 in the Protection Set 1 */
    enable_data_read(PROTECTION_SET_1, DATA_PROTECTION_RANGE_1);
    /* Enable write access to the Data Protection Range 1 in the Protection Set 1 */
    enable_data_write(PROTECTION_SET_1, DATA_PROTECTION_RANGE_1);

    /* Define the Code Protection Range 0: from 0x00000000 to 0xFFFFFFFF (every address of the microcontroller) */
    define_code_protection_range(FIRST_ADDR, LAST_ADDR, CODE_PROTECTION_RANGE_0);
    /* Enable code execution on every address for Protection Set 1 */
    enable_code_execution(PROTECTION_SET_1, CODE_PROTECTION_RANGE_0);

    /* When a trap occurs (i.e. in case of an access violation) the active Protection Set is automatically switched to 0.
     * The following code enables the write/read access and code execution to all the memory addresses on protection set 0.
     * This ensures that the trap vector table is still executable and readable.
     */
    /* Define the Code Protection Range 7: from 0x00000000 to 0xFFFFFFFF (every address of the microcontroller) */
    define_code_protection_range(FIRST_ADDR, LAST_ADDR, CODE_PROTECTION_RANGE_7);
    /* Define the Data Protection Range 15: from 0x00000000 to 0xFFFFFFFF (every address of the microcontroller) */
    define_data_protection_range(FIRST_ADDR, LAST_ADDR, DATA_PROTECTION_RANGE_15);
    /* Enable code execution on the trap table for Protection Set 0 (the default Protection Set) */
    enable_code_execution(PROTECTION_SET_0, CODE_PROTECTION_RANGE_7);
    /* Enable read access to the Data Protection Range 15 in the Protection Set 0 */
    enable_data_read(PROTECTION_SET_0, DATA_PROTECTION_RANGE_15);
    /* Enable write access to the Data Protection Range 15 in the Protection Set 0 */
    enable_data_write(PROTECTION_SET_0, DATA_PROTECTION_RANGE_15);

    /* Activate Protection Set 1.
     * The active protection set determines the read, write, and execute permissions of the CPU.
     */
    set_active_protection_set(PROTECTION_SET_1);

    /* Enable the Memory Protection */
    MPU_enable_protection();

    volatile uint8 dummyRead;

    /* Test the memory protection. */
    for(i = 0; i < DUMMY_ELEMENTS_NUM; i++)
    {
        /* Make a read access to the array which is partially protected. */
        dummyRead = dummyData[i];

        /* Check whether the last non-protected element has been read. */
        if(i == INDEX_FORTY_SEVEN)
        {
            /* Turn on the first LED to indicate all non-protected elements have been successfully read.*/
            switch_LED_ON(LED_FIRST_HALF);
        }
        /* Check whether somehow a protected element was read. */
        else if(i > INDEX_FORTY_SEVEN)
        {
            /* If the MPU is configured properly this will be unreachable code.
             * Thus, the LED should never be switched on. */
            switch_LED_ON(LED_SECOND_HALF);
        }
    }

    while(1)
    {
    }
    return (1);
}
