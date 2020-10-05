/**
 * \file IfxMultican_PinMap.h
 * \brief MULTICAN I/O map
 * \ingroup IfxLld_Multican
 *
 * \version iLLD_1_0_1_11_0
 * \copyright Copyright (c) 2013 Infineon Technologies AG. All rights reserved.
 *
 *
 *                                 IMPORTANT NOTICE
 *
 *
 * Use of this file is subject to the terms of use agreed between (i) you or 
 * the company in which ordinary course of business you are acting and (ii) 
 * Infineon Technologies AG or its licensees. If and as long as no such 
 * terms of use are agreed, use of this file is subject to following:


 * Boost Software License - Version 1.0 - August 17th, 2003

 * Permission is hereby granted, free of charge, to any person or 
 * organization obtaining a copy of the software and accompanying 
 * documentation covered by this license (the "Software") to use, reproduce,
 * display, distribute, execute, and transmit the Software, and to prepare
 * derivative works of the Software, and to permit third-parties to whom the 
 * Software is furnished to do so, all subject to the following:

 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer, must
 * be included in all copies of the Software, in whole or in part, and all
 * derivative works of the Software, unless such copies or derivative works are
 * solely in the form of machine-executable object code generated by a source
 * language processor.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE 
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.

 *
 * \defgroup IfxLld_Multican_pinmap MULTICAN Pin Mapping
 * \ingroup IfxLld_Multican
 */

#ifndef IFXMULTICAN_PINMAP_H
#define IFXMULTICAN_PINMAP_H

#include <IfxCan_reg.h>
#include <_Impl/IfxMultican_cfg.h>
#include <Port/Std/IfxPort.h>

/** \addtogroup IfxLld_Multican_pinmap
 * \{ */

/** \brief RXD pin mapping structure */
typedef const struct
{
    Ifx_CAN*           module;   /**< \brief Base address */
    IfxMultican_NodeId nodeId;   /**< \brief Node ID */
    IfxPort_Pin        pin;      /**< \brief Port pin */
    Ifx_RxSel          select;   /**< \brief Input multiplexer value */
} IfxMultican_Rxd_In;

/** \brief TXD pin mapping structure */
typedef const struct
{
    Ifx_CAN*           module;   /**< \brief Base address */
    IfxMultican_NodeId nodeId;   /**< \brief Node ID */
    IfxPort_Pin        pin;      /**< \brief Port pin */
    IfxPort_OutputIdx  select;   /**< \brief Port control code */
} IfxMultican_Txd_Out;

IFX_EXTERN IfxMultican_Rxd_In IfxCanr_RXD0A_P10_5_IN;  /**< \brief CANR0_RXDA: CAN node 0 input (MultiCANr+) */
IFX_EXTERN IfxMultican_Rxd_In IfxCanr_RXD0B_P10_8_IN;  /**< \brief CANR0_RXDB: CAN node 0 input (MultiCANr+) */
IFX_EXTERN IfxMultican_Rxd_In IfxCanr_RXD0C_P34_2_IN;  /**< \brief CANR0_RXDC: CAN node 0 input (MultiCANr+) */
IFX_EXTERN IfxMultican_Rxd_In IfxCanr_RXD0D_P02_14_IN;  /**< \brief CANR0_RXDD: CAN node 0 input (MultiCANr+) */
IFX_EXTERN IfxMultican_Rxd_In IfxCanr_RXD0E_P01_8_IN;  /**< \brief CANR0_RXDE: CAN node 0 input (MultiCANr+) */
IFX_EXTERN IfxMultican_Rxd_In IfxCanr_RXD1A_P00_3_IN;  /**< \brief CANR1_RXDA: CAN node 1 input (MultiCANr+) */
IFX_EXTERN IfxMultican_Rxd_In IfxCanr_RXD1B_P13_12_IN;  /**< \brief CANR1_RXDB: CAN node 1 input (MultiCANr+) */
IFX_EXTERN IfxMultican_Rxd_In IfxCanr_RXD1C_P20_0_IN;  /**< \brief CANR1_RXDC: CAN node 1 input (MultiCANr+) */
IFX_EXTERN IfxMultican_Rxd_In IfxCanr_RXD1D_P32_2_IN;  /**< \brief CANR1_RXDD: CAN node 1 input (MultiCANr+) */
IFX_EXTERN IfxMultican_Rxd_In IfxCanr_RXD1E_P01_0_IN;  /**< \brief CANR1_RXDE: CAN node 1 input (MultiCANr+) */
IFX_EXTERN IfxMultican_Rxd_In IfxMultican_RXD0A_P02_1_IN;  /**< \brief CAN0_RXDA: CAN node 0 input */
IFX_EXTERN IfxMultican_Rxd_In IfxMultican_RXD0B_P20_7_IN;  /**< \brief CAN0_RXDB: CAN node 0 input */
IFX_EXTERN IfxMultican_Rxd_In IfxMultican_RXD0C_P12_0_IN;  /**< \brief CAN0_RXDC: CAN node 0 input */
IFX_EXTERN IfxMultican_Rxd_In IfxMultican_RXD0D_P02_4_IN;  /**< \brief CAN0_RXDD: CAN node 0 input */
IFX_EXTERN IfxMultican_Rxd_In IfxMultican_RXD0E_P33_7_IN;  /**< \brief CAN0_RXDE: CAN node 0 input */
IFX_EXTERN IfxMultican_Rxd_In IfxMultican_RXD0F_P01_8_IN;  /**< \brief CAN0_RXDF: CAN node 0 input */
IFX_EXTERN IfxMultican_Rxd_In IfxMultican_RXD0G_P34_2_IN;  /**< \brief CAN0_RXDG: CAN node 0 input */
IFX_EXTERN IfxMultican_Rxd_In IfxMultican_RXD0H_P02_14_IN;  /**< \brief CAN0_RXDH: CAN node 0 input */
IFX_EXTERN IfxMultican_Rxd_In IfxMultican_RXD1A_P15_3_IN;  /**< \brief CAN1_RXDA: CAN node 1 input */
IFX_EXTERN IfxMultican_Rxd_In IfxMultican_RXD1B_P14_1_IN;  /**< \brief CAN1_RXDB: CAN node 1 input   Used for single pin DAP (SPD) function */
IFX_EXTERN IfxMultican_Rxd_In IfxMultican_RXD1C_P01_4_IN;  /**< \brief CAN1_RXDC: CAN node 1 input */
IFX_EXTERN IfxMultican_Rxd_In IfxMultican_RXD1D_P00_1_IN;  /**< \brief CAN1_RXDD: CAN node 1 input */
IFX_EXTERN IfxMultican_Rxd_In IfxMultican_RXD1E_P02_10_IN;  /**< \brief CAN1_RXDE: CAN node 1 input */
IFX_EXTERN IfxMultican_Rxd_In IfxMultican_RXD2A_P15_1_IN;  /**< \brief CAN2_RXDA: CAN node 2 input */
IFX_EXTERN IfxMultican_Rxd_In IfxMultican_RXD2B_P02_3_IN;  /**< \brief CAN2_RXDB: CAN node 2 input */
IFX_EXTERN IfxMultican_Rxd_In IfxMultican_RXD2C_P32_6_IN;  /**< \brief CAN2_RXDC: CAN node 2 input */
IFX_EXTERN IfxMultican_Rxd_In IfxMultican_RXD2D_P14_8_IN;  /**< \brief CAN2_RXDD: CAN node 2 input */
IFX_EXTERN IfxMultican_Rxd_In IfxMultican_RXD2E_P10_2_IN;  /**< \brief CAN2_RXDE: CAN node 2 input */
IFX_EXTERN IfxMultican_Rxd_In IfxMultican_RXD3A_P00_3_IN;  /**< \brief CAN3_RXDA: CAN node 3 input */
IFX_EXTERN IfxMultican_Rxd_In IfxMultican_RXD3B_P32_2_IN;  /**< \brief CAN3_RXDB: CAN node 3 input */
IFX_EXTERN IfxMultican_Rxd_In IfxMultican_RXD3C_P20_0_IN;  /**< \brief CAN3_RXDC: CAN node 3 input */
IFX_EXTERN IfxMultican_Rxd_In IfxMultican_RXD3D_P11_10_IN;  /**< \brief CAN3_RXDD: CAN node 3 input */
IFX_EXTERN IfxMultican_Rxd_In IfxMultican_RXD3E_P20_9_IN;  /**< \brief CAN3_RXDE: CAN node 3 input */
IFX_EXTERN IfxMultican_Rxd_In IfxMultican_RXD3F_P01_0_IN;  /**< \brief CAN3_RXDF: CAN node 3 input */
IFX_EXTERN IfxMultican_Txd_Out IfxCanr_TXD0_P01_13_OUT;  /**< \brief CANR0_TXD: CAN node 0 output (MultiCANr+) */
IFX_EXTERN IfxMultican_Txd_Out IfxCanr_TXD0_P02_13_OUT;  /**< \brief CANR0_TXD: CAN node 0 output (MultiCANr+) */
IFX_EXTERN IfxMultican_Txd_Out IfxCanr_TXD0_P10_6_OUT;  /**< \brief CANR0_TXD: CAN node 0 output (MultiCANr+) */
IFX_EXTERN IfxMultican_Txd_Out IfxCanr_TXD0_P10_7_OUT;  /**< \brief CANR0_TXD: CAN node 0 output (MultiCANr+) */
IFX_EXTERN IfxMultican_Txd_Out IfxCanr_TXD0_P34_1_OUT;  /**< \brief CANR0_TXD: CAN node 0 output (MultiCANr+) */
IFX_EXTERN IfxMultican_Txd_Out IfxCanr_TXD1_P00_2_OUT;  /**< \brief CANR1_TXD: CAN node 1 output (MultiCANr+) */
IFX_EXTERN IfxMultican_Txd_Out IfxCanr_TXD1_P01_2_OUT;  /**< \brief CANR1_TXD: CAN node 1 output (MultiCANr+) */
IFX_EXTERN IfxMultican_Txd_Out IfxCanr_TXD1_P13_9_OUT;  /**< \brief CANR1_TXD: CAN node 1 output (MultiCANr+) */
IFX_EXTERN IfxMultican_Txd_Out IfxCanr_TXD1_P20_3_OUT;  /**< \brief CANR1_TXD: CAN node 1 output (MultiCANr+) */
IFX_EXTERN IfxMultican_Txd_Out IfxCanr_TXD1_P32_3_OUT;  /**< \brief CANR1_TXD: CAN node 1 output (MultiCANr+) */
IFX_EXTERN IfxMultican_Txd_Out IfxMultican_TXD0_P01_13_OUT;  /**< \brief CAN0_TXD: CAN node 0 output */
IFX_EXTERN IfxMultican_Txd_Out IfxMultican_TXD0_P02_0_OUT;  /**< \brief CAN0_TXD: CAN node 0 output */
IFX_EXTERN IfxMultican_Txd_Out IfxMultican_TXD0_P02_13_OUT;  /**< \brief CAN0_TXD: CAN node 0 output */
IFX_EXTERN IfxMultican_Txd_Out IfxMultican_TXD0_P02_5_OUT;  /**< \brief CAN0_TXD: CAN node 0 output */
IFX_EXTERN IfxMultican_Txd_Out IfxMultican_TXD0_P12_1_OUT;  /**< \brief CAN0_TXD: CAN node 0 output */
IFX_EXTERN IfxMultican_Txd_Out IfxMultican_TXD0_P20_8_OUT;  /**< \brief CAN0_TXD: CAN node 0 output */
IFX_EXTERN IfxMultican_Txd_Out IfxMultican_TXD0_P33_8_OUT;  /**< \brief CAN0_TXD: CAN node 0 output */
IFX_EXTERN IfxMultican_Txd_Out IfxMultican_TXD0_P34_1_OUT;  /**< \brief CAN0_TXD: CAN node 0 output */
IFX_EXTERN IfxMultican_Txd_Out IfxMultican_TXD1_P00_0_OUT;  /**< \brief CAN1_TXD: CAN node 1 output */
IFX_EXTERN IfxMultican_Txd_Out IfxMultican_TXD1_P01_3_OUT;  /**< \brief CAN1_TXD: CAN node 1 output */
IFX_EXTERN IfxMultican_Txd_Out IfxMultican_TXD1_P02_9_OUT;  /**< \brief CAN1_TXD: CAN node 1 output */
IFX_EXTERN IfxMultican_Txd_Out IfxMultican_TXD1_P14_0_OUT;  /**< \brief CAN1_TXD: CAN node 1 output   Used for single pin DAP (SPD) function */
IFX_EXTERN IfxMultican_Txd_Out IfxMultican_TXD1_P15_2_OUT;  /**< \brief CAN1_TXD: CAN node 1 output */
IFX_EXTERN IfxMultican_Txd_Out IfxMultican_TXD2_P02_2_OUT;  /**< \brief CAN2_TXD: CAN node 2 output */
IFX_EXTERN IfxMultican_Txd_Out IfxMultican_TXD2_P10_3_OUT;  /**< \brief CAN2_TXD: CAN node 2 output */
IFX_EXTERN IfxMultican_Txd_Out IfxMultican_TXD2_P14_10_OUT;  /**< \brief CAN2_TXD: CAN node 2 output */
IFX_EXTERN IfxMultican_Txd_Out IfxMultican_TXD2_P15_0_OUT;  /**< \brief CAN2_TXD: CAN node 2 output */
IFX_EXTERN IfxMultican_Txd_Out IfxMultican_TXD2_P32_5_OUT;  /**< \brief CAN2_TXD: CAN node 2 output */
IFX_EXTERN IfxMultican_Txd_Out IfxMultican_TXD3_P00_2_OUT;  /**< \brief CAN3_TXD: CAN node 3 output */
IFX_EXTERN IfxMultican_Txd_Out IfxMultican_TXD3_P01_2_OUT;  /**< \brief CAN3_TXD: CAN node 3 output */
IFX_EXTERN IfxMultican_Txd_Out IfxMultican_TXD3_P11_12_OUT;  /**< \brief CAN3_TXD: CAN node 3 output */
IFX_EXTERN IfxMultican_Txd_Out IfxMultican_TXD3_P20_10_OUT;  /**< \brief CAN3_TXD: CAN node 3 output */
IFX_EXTERN IfxMultican_Txd_Out IfxMultican_TXD3_P20_3_OUT;  /**< \brief CAN3_TXD: CAN node 3 output */
IFX_EXTERN IfxMultican_Txd_Out IfxMultican_TXD3_P32_3_OUT;  /**< \brief CAN3_TXD: CAN node 3 output */

/** \brief Table dimensions */
#define IFXMULTICAN_PINMAP_NUM_MODULES 2
#define IFXMULTICAN_PINMAP_NUM_NODES 4
#define IFXMULTICAN_PINMAP_RXD_IN_NUM_ITEMS 8
#define IFXMULTICAN_PINMAP_TXD_OUT_NUM_ITEMS 8


/** \brief IfxMultican_Rxd_In table */
IFX_EXTERN const IfxMultican_Rxd_In *IfxMultican_Rxd_In_pinTable[IFXMULTICAN_PINMAP_NUM_MODULES][IFXMULTICAN_PINMAP_NUM_NODES][IFXMULTICAN_PINMAP_RXD_IN_NUM_ITEMS];

/** \brief IfxMultican_Txd_Out table */
IFX_EXTERN const IfxMultican_Txd_Out *IfxMultican_Txd_Out_pinTable[IFXMULTICAN_PINMAP_NUM_MODULES][IFXMULTICAN_PINMAP_NUM_NODES][IFXMULTICAN_PINMAP_TXD_OUT_NUM_ITEMS];

/** \} */

#endif /* IFXMULTICAN_PINMAP_H */
