/**********************************************************************************************************************
 * \file ADC_Single_Channel.c
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

/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include "ADC_Single_Channel.h"
#include "IfxEvadc_Adc.h"

/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/
#define GROUPID_0       IfxEvadc_GroupId_0                      /* EVADC group                                      */

#define AN2_CHID        2                                       /* Channel ID for pin AN2                           */

#define LED_HIGH        &MODULE_P13, 0                          /* LED D107                                         */
#define LED_MID         &MODULE_P13, 1                          /* LED D108                                         */
#define LED_LOW         &MODULE_P13, 2                          /* LED D109                                         */

#define LIMIT_HIGH      0xC00                                   /* Higher limit to be compared with the measure     */
#define LIMIT_LOW       0x300                                   /* Lower limit to be compared with the measure      */

/*********************************************************************************************************************/
/*-------------------------------------------------Global variables--------------------------------------------------*/
/*********************************************************************************************************************/
 /* EVADC handle */
IfxEvadc_Adc         g_evadc;                                   /* EVADC module handle variable                     */
IfxEvadc_Adc_Group   g_adcGroup;                                /* EVADC group handle variable                      */
IfxEvadc_Adc_Channel g_adcChannel;                              /* EVADC channel handle variable                    */

Ifx_EVADC_G_RES g_result;                                       /* Variable to store the result of the measurement  */

/*********************************************************************************************************************/
/*------------------------------------------------Function Prototypes------------------------------------------------*/
/*********************************************************************************************************************/
void initEVADCModule(void);                                     /* Function to initialize the EVADC module          */
void initEVADCGroup(void);                                      /* Function to initialize the EVADC module          */
void initEVADCChannels(void);                                   /* Function to initialize the EVADC module          */
void fillQueue(void);                                           /* Function to add the channel to a queue           */

/*********************************************************************************************************************/
/*---------------------------------------------Function Implementations----------------------------------------------*/
/*********************************************************************************************************************/
/* The initialization of the port pins to control the LEDs is done by this function */
void initializeLEDs(void)
{
    /* Initialize the Port Pins */
    IfxPort_setPinMode(LED_HIGH, IfxPort_Mode_outputPushPullGeneral);
    IfxPort_setPinMode(LED_MID, IfxPort_Mode_outputPushPullGeneral);
    IfxPort_setPinMode(LED_LOW, IfxPort_Mode_outputPushPullGeneral);

    /* Turn off the LEDs */
    IfxPort_setPinHigh(LED_HIGH);
    IfxPort_setPinHigh(LED_MID);
    IfxPort_setPinHigh(LED_LOW);
}

/* Function to initialize the EVADC with default parameters */
void initEVADC(void)
{
    initEVADCModule();      /* Initialize the EVADC module  */
    initEVADCGroup();       /* Initialize the EVADC group   */
    initEVADCChannels();    /* Initialize the channel       */
    fillQueue();            /* Fill the queue request       */
}

/* Function to initialize the EVADC module with default parameters */
void initEVADCModule(void)
{
    /* Create configuration */
    IfxEvadc_Adc_Config adcConfig;
    IfxEvadc_Adc_initModuleConfig(&adcConfig, &MODULE_EVADC);

    /* Initialize module */
    IfxEvadc_Adc_initModule(&g_evadc, &adcConfig);
}

/* Function to initialize the EVADC group with default parameters */
void initEVADCGroup(void)
{
    /* Create and initialize group configuration with default values */
    IfxEvadc_Adc_GroupConfig adcGroupConfig;
    IfxEvadc_Adc_initGroupConfig(&adcGroupConfig, &g_evadc);

    /* Setting user configuration using group 0 */
    adcGroupConfig.groupId = GROUPID_0;
    adcGroupConfig.master = GROUPID_0;

    /* Enable queued source */
    adcGroupConfig.arbiter.requestSlotQueue0Enabled = TRUE;

    /* Enable all gates in "always" mode (no edge detection) */
    adcGroupConfig.queueRequest[0].triggerConfig.gatingMode = IfxEvadc_GatingMode_always;

    /* Initialize the group */
    IfxEvadc_Adc_initGroup(&g_adcGroup, &adcGroupConfig);
}

/* Function to initialize the EVADC channel */
void initEVADCChannels(void)
{
    /* Create channel configuration */
    IfxEvadc_Adc_ChannelConfig adcChannelConfig;

    /* Initialize the configuration with default values */
    IfxEvadc_Adc_initChannelConfig(&adcChannelConfig, &g_adcGroup);

    /* Select the channel ID and the respective result register */
    adcChannelConfig.channelId = (IfxEvadc_ChannelId)(AN2_CHID);
    adcChannelConfig.resultRegister = (IfxEvadc_ChannelResult)(AN2_CHID);

    /* Initialize the channel */
    IfxEvadc_Adc_initChannel(&g_adcChannel, &adcChannelConfig);

    /* Start the queue */
    IfxEvadc_Adc_startQueue(&g_adcGroup, IfxEvadc_RequestSource_queue0);
}

/* Function to add the channel to a queue */
void fillQueue(void)
{
    /* Add channel to queue with refill option enabled */
    IfxEvadc_Adc_addToQueue(&g_adcChannel, IfxEvadc_RequestSource_queue0, IFXEVADC_QUEUE_REFILL);
}

/* Function to read the EVADC used channel */
void readEVADC(void)
{
    Ifx_EVADC_G_RES conversionResult;

    /* Wait for valid result */
    do
    {
        conversionResult = IfxEvadc_Adc_getResult(&g_adcChannel); /* Read the result of the channel */
    } while(!conversionResult.B.VF);

    /* Store result */
    g_result = conversionResult;
}

/* This function retrieves the conversion value and indicates it using LEDs */
void indicateConversionValue(void)
{
    if(g_result.B.RESULT > LIMIT_HIGH)      /* LED D107 lights up if the conversion value is greater than 0xC00 */
    {
        IfxPort_setPinLow(LED_HIGH);
        IfxPort_setPinHigh(LED_MID);
        IfxPort_setPinHigh(LED_LOW);
    }
    else if(g_result.B.RESULT < LIMIT_LOW)  /* LED D109 lights up if the conversion value is smaller than 0x300 */
    {
        IfxPort_setPinHigh(LED_HIGH);
        IfxPort_setPinHigh(LED_MID);
        IfxPort_setPinLow(LED_LOW);
    }
    else                                    /* LED D108 lights up if the conversion value is in between         */
    {
        IfxPort_setPinHigh(LED_HIGH);
        IfxPort_setPinLow(LED_MID);
        IfxPort_setPinHigh(LED_LOW);
    }
}
