/**********************************************************************************************************************
 * \file SafetyKit_AA_global.h
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
#ifndef SAFETYKIT_AA_GLOBAL_H_
#define SAFETYKIT_AA_GLOBAL_H_ 1
/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include "Ifx_Types.h"
#include "IfxCpu.h"
#include "SafetyKit_Main.h"
#include "SafetyKit_Cfg.h"
#include "IfxConvctrl.h"
#include "IfxEvadc_Adc.h"
#include "IfxEdsadc_Edsadc.h"

/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/
/* General macros for EVADC */
#define IFXEVADC_QUEUE_REFILL_DISABLED  (0 << 5u)

/* Macro to determine voltage measured by 12-bit EVADC */
#define EVADC_RESULT_TO_V(convRes)      ((float32)((float32)5 * (convRes / (float32)4096)))

#define MAX_DIFF            0.3                     /* Plausibility check max difference in V */
#define UPPER_LIMIT         5                       /* Plausibility check upper limit in V */
#define LOWER_LIMIT         0                       /* Plausibility check lower limit in V */


/* General macros for EDSADC */
#define DECIMATION_FACTOR   32                      /* Configure the CIC decimation factor (N)                      */
#define START_VALUE         32                      /* Configure start value of the decimation counter              */
#define CICSHIFT            15                      /* CIC shift calculated using the selected decimation factor    */
#define GAINFACTOR          5399                    /* Gain factor calculated using the CIC shift                   */

#define ANALOG_FULL_SCALE   5.0                     /* Analog full-scale voltage                                    */
#define RAW_FULL_SCALE  30000.0 /* EDSADC full-scale value(AFS), representing the analog full-scale(V_IN=V_AREF=5V) */

#define EDSADC_RESULT_TO_V(convRes)     ((float32) (convRes * ANALOG_FULL_SCALE) / RAW_FULL_SCALE )

/* Target frequency macros for EVADC, EDSADC and CONVTRL module */
#define EVADC_20MHZ_FREQ    (20.0e6) /* Analog frequency in Hz */
#define EDSADC_20MHZ_FREQ   (20.0e6) /* Modulator frequency in Hz */
#define CONVTRL_20MHZ_FREQ  IfxConvctrl_PhaseSynchronizerDivider_8 /* Divider of 8 as fPER is 160Mhz */

#define VOLT_TO_10BIT_ADC(voltage) (uint32)((float32)voltage * (float32)(4096/ANALOG_FULL_SCALE))

/* Additional Macros */

/* Macros for VAREF verification */
#define VAREF_TOLERANCE         0.1     /* 10% */
#define VAREF_EXPECTED_RESULT   0.901   /* V V_UC = 5V */

/* Macros for temperature calculation of NTC resistor */
#define NTC_BETA_25_85  3940.
#define NTC_R25         10000.
#define NTC_25C_TO_K    298.15
/* Macro for calculation of NTC resistance value */
#define ADC_RESULT_TO_NTC_R(res)    ((float32)((float32)1000 * res)/((float32)4096 - res))
#define VOLT_TO_NTC_R(volt) ((float32)(volt * (float32)1000) / ((float32)5 - volt))

/* Macros for plausibility check */
#define MAX_TEMP_DELTA 5.0 /* [°C] */
#define MAX_TEMP_NTC 160.0 /* [°C] */
#define MIN_TEMP_NTC -40.0 /* [°C] */

/* Macros for the offset calibration */
#define CALIBRATION_SAMPLE_AMOUNT       100

/* Macros for the FUCs */
/* FUC0: */
#define EVADC_GROUPS_NUM_AA_FUC0      3  /* Number of used EVADC groups  used for Analog Acquisition FUC0 */
#define EVADC_CHANNELS_NUM_AA_FUC0    3  /* Number of used EVADC channels used for Analog Acquisition FUC0 */

/* FUC1: */
#define EDSADC_CHANNELS_NUM_AA_FUC1   3  /* Number of used EDSADC channels used for Analog Acquisition FUC1 */

/* FUC2: */
#define EVADC_GROUPS_NUM_AA_FUC2      2  /* Number of used EVADC groups used for Analog Acquisition FUC2 */
#define EVADC_CHANNELS_NUM_AA_FUC2    2  /* Number of used EVADC channels used for Analog Acquisition FUC2 */

#define EDSADC_CHANNELS_NUM_AA_FUC2   2  /* Number of used EDSADC channels used for Analog Acquisition FUC2 */

/* FUC3: */
#define EVADC_GROUPS_NUM_AA_FUC3      3  /* Number of used EVADC groups used for Analog Acquisition  FUC3 */
#define EVADC_CHANNELS_NUM_AA_FUC3    3  /* Number of used EVADC channels used for Analog Acquisition FUC3 */

/* FUC4: */
#define EVADC_GROUPS_NUM_AA_FUC4      2  /* Number of used EVADC groups used for Analog Acquisition FUC4 */
#define EVADC_CHANNELS_NUM_AA_FUC4    2  /* Number of used EVADC channels used for Analog Acquisition FUC4 */

#define EDSADC_CHANNELS_NUM_AA_FUC4   2  /* Number of used EDSADC channels used for Analog Acquisition FUC4 */

/*********************************************************************************************************************/
/*---------------------------------------------------Enumerations----------------------------------------------------*/
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/*-------------------------------------------------Data Structures---------------------------------------------------*/
/*********************************************************************************************************************/
/* Structure for the EVADC channel configuration */
typedef struct
{
    IfxEvadc_Vadcg_In *analogInput;   /* Ptr to the analog input pin structure which is defined in IfxEvadc_PinMap.c */
    IfxEvadc_Adc_Group *groupHandle;        /* Pointer to the group configuration handle of the specific adc channel */
    IfxEvadc_ChannelResult resultRegister; /* Ch Result in MODULE_EVADC.G[x].CHCTR[y].B. RESREG(x=0,.,11;y=0,.,16)   */
    IfxEvadc_InputClasses  inputClass;     /* inputClass in MODULE_EVADC.G[x].CHCTR[y].B.ICLSEL(x=0,..,11;y=0,1..16) */
    IfxEvadc_RequestSource queueRequestSourceId; /* For EVADC in Queue mode three queues can be selected */
    boolean  initISR;                            /* TRUE if an ISR should be enabled and configured for this channel */
    IfxEvadc_SrcNr resultSrcNr;    /* Service Node in MODULE_EVADC.G[x].SRACT.U(x= 0,.,11)"not used if initISR=FALSE"*/
    IfxSrc_Tos resultServProvider; /* Identifier of ISR,  which handles the interrupt service request */
    Ifx_Priority resultPriority;   /* Interrupt service priority */
} SafetyKitEvadcChannelCfgType;

/* Structure for EVADC configuration */
typedef struct
{
    uint8                      amountOfGroups;        /* Amount of different EVADC groups used for the application   */
    uint8                      amountOfChannels;      /* Amount of different EVADC channels used for the application */
    IfxEvadc_Adc               evadc;                  /* EVADC module handle variable */
    IfxEvadc_Adc_Group         *evadcGroup;            /* Pointer to global array for configuring the EVADC groups   */
    IfxEvadc_Adc_Channel       *evadcChannel;          /* Pointer to global array for configuring the EVADC channels */
    SafetyKitEvadcChannelCfgType *evadcChannelConfig;    /* Pointer to the EVADC channel configuration structure */
} SafetyKitEvadcCfgType;

/* Structure for the EDSADC channel configuration */
typedef struct
{
    IfxEdsadc_Dsp_In            *posInput;        /* Pointer to EDSADC positive pin mapping structure */
    IfxEdsadc_Dsn_In            *negInput;        /* Pointer to EDSADC negative pin mapping structure */
} SafetyKitEdsadcChannelCfgType;

/* Structure for EDSADC configuration */
typedef struct
{
    uint8                         amountOfChannels;/* Amount of different EDSADC channels used for the application */
    IfxEdsadc_Edsadc              edsadc;          /* EDSADC module handle variable */
    IfxEdsadc_Edsadc_Channel      *edsadcChannel;  /* Pointer to global array for configuring the EDSADC channels*/
    SafetyKitEdsadcChannelCfgType *edsadcChannelConfig; /* Pointer to EDSADC channel configuration structure */
} SafetyKitEdsadcCfgType;

/* Structure for the status data type of Analog Acquisition */
typedef struct
{
    sint32  evadcConversionResult[EVADC_CHANNELS_NUM_AA_FUC0]; /* Var to store the result of the ADC conversions */
    float32 evadcVoltageResults[EVADC_CHANNELS_NUM_AA_FUC0];   /* Variable to store the calculated voltages [V]  */
    float32 evadcRv1NtcTemp;     /* [°C] */
    float32 evadcRv2NtcTemp;     /* [°C] */
    float32 evadcRv1Calibration; /* Used to store the static error between ADC */
    float32 evadcRv2Calibration; /* Used to store the static error between ADC */

    boolean evadcRv1MeasDoneFlag;       /* Flag to signal that a EVADC rv1 measurement is done */
    boolean evadcRv2MeasDoneFlag;       /* Flag to signal that a EVADC rv2 measurement is done */
    boolean evadcUvSimSig1DoneFlag;     /* Flag to signal that a EVADC UV simulation signal 1 measurement is done */
    boolean evadcUvSimSig2DoneFlag;     /* Flag to signal that a EVADC UV simulation signal 2 measurement is done */
    boolean evadcBrokenWireMeasDoneFlag;/* Flag to signal that a EVADC broken wire measurement is done */

    sint32  edsadcConversionResult[EDSADC_CHANNELS_NUM_AA_FUC1]; /* Var to store the result of ADC conversions */
    float32 edsadcVoltageResults[EDSADC_CHANNELS_NUM_AA_FUC1]; /* Variable to store the calculated voltages [V] */
    float32 edsadcRv1NtcTemp;    /* [°C] */
    float32 edsadcRv2NtcTemp;    /* [°C] */
    float32 edsadcRv1Calibration;/* Used to store the static error between ADC [V] */
    float32 edsadcRv2Calibration;/* Used to store the static error between ADC [V] */

    uint8   initCnt;
} AnalogAcquisitionStatusDatatype;

/*********************************************************************************************************************/
/*-------------------------------------------------Global variables--------------------------------------------------*/
/*********************************************************************************************************************/
IFX_EXTERN AnalogAcquisitionStatusDatatype g_analogAcquisitionStatus;

/*********************************************************************************************************************/
/*------------------------------------------------Function Prototypes------------------------------------------------*/
/*********************************************************************************************************************/
void initCONVCTRL(void);                                           /* Function to initialize and verify the CONVCTRL */

void initEVADCModule(SafetyKitEvadcCfgType *evadcCfg);             /* Function to initialize the EVADC module       */
void initEVADCGroups(SafetyKitEvadcCfgType *evadcCfg);             /* Function to initialize the EVADC group        */
void initEVADCChannels(SafetyKitEvadcCfgType *evadcCfg);           /* Function to initialize the EVADC channels     */
void initEVADCBrokenWireDetection (IfxEvadc_Vadcg_In *evadcInput, const uint32 lowerBoundary,
        const uint32 upperBoundary, const IfxEvadc_SrcNr channelSrcNr, const IfxCpu_ResourceCpu tosCpuId,
        const Ifx_Priority priority);
void initEVADCGtmTrigger (SafetyKitEvadcCfgType *evadcCfg, uint8 groupIdx, IfxEvadc_TriggerMode triggerMode,
        IfxEvadc_TriggerSource triggerSource);
float32 evadcVarefPlausibilityCheck (SafetyKitEvadcCfgType *evadcCfg, const uint8 varefChId,
        const float32 varefExpectedResult, const float32 varefTolerance, const IfxEvadc_RequestSource sourceType);
sint32 getEvadcChannelResult(IfxEvadc_Adc_Channel *channel);

void initEDSADCModule(SafetyKitEdsadcCfgType *edsadcCfg);
void initEDSADCChannels(SafetyKitEdsadcCfgType *edsadcCfg);
float32 edsadcVarefPlausibilityCheck (SafetyKitEdsadcCfgType *edsadcCfg, const uint8 varefChId,
        const float32 varefExpectedResult, const float32 varefTolerance);

float32 convertNtcResistanceToDegrees(float32 R);
void getCalibrationOffset(float32 *accumulationResult, const uint16 amountOfSamples, float32 *calibrationResult);
boolean plausibilityCheck (float32 missionChannel, float32 monitorChannel, float32 maximumDifference,
        float32 upperLimit, float32 lowerLimit, IfxSmu_Alarm smuSoftwareAlarmLimit,
        IfxSmu_Alarm smuSoftwareAlarmDifference);

#endif /* SAFETYKIT_AA_GLOBAL_H_ */
