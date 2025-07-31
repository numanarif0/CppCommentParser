/** @file HL_can.h
*   @brief CAN Driver Header File
*   @date 11-Dec-2018
*   @version 04.07.01
*   
*   This file contains:
*   - Definitions
*   - Types
*   - Interface Prototypes
*   .
*   which are relevant for the CAN driver.
*/

/* 
* Copyright (C) 2009-2018 Texas Instruments Incorporated - www.ti.com  
* 
* 
*  Redistribution and use in source and binary forms, with or without 
*  modification, are permitted provided that the following conditions 
*  are met:
*
*    Redistributions of source code must retain the above copyright 
*    notice, this list of conditions and the following disclaimer.
*
*    Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in the 
*    documentation and/or other materials provided with the   
*    distribution.
*
*    Neither the name of Texas Instruments Incorporated nor the names of
*    its contributors may be used to endorse or promote products derived
*    from this software without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
*  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
*  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
*  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/


#ifndef __CAN_H__
#define __CAN_H__

#include "%%CAN:HDRCAN_R%%"

#ifdef __cplusplus
extern "C" {
#endif

@@USERCODE

/* CAN General Definitions */

/** @def canLEVEL_ACTIVE
*   @brief Alias name for CAN error operation level active (Error counter 0-95)  
*/
#define canLEVEL_ACTIVE 0x00U

/** @def canLEVEL_WARNING
*   @brief Alias name for CAN error operation level warning (Error counter 96-127)  
*/
#define canLEVEL_WARNING 0x40U

/** @def canLEVEL_PASSIVE
*   @brief Alias name for CAN error operation level passive (Error counter 128-255)  
*/
#define canLEVEL_PASSIVE 0x20U

/** @def canLEVEL_BUS_OFF
*   @brief Alias name for CAN error operation level bus off (Error counter 256)  
*/
#define canLEVEL_BUS_OFF 0x80U

/** @def canLEVEL_PARITY_ERR
*   @brief Alias name for CAN Parity error (Error counter 256-511)  
*/
#define canLEVEL_PARITY_ERR 0x100U

/** @def canLEVEL_TxOK
*   @brief Alias name for CAN Sucessful Transmission
*/
#define canLEVEL_TxOK 0x08U

/** @def canLEVEL_RxOK
*   @brief Alias name for CAN Sucessful Reception
*/
#define canLEVEL_RxOK 0x10U

/** @def canLEVEL_WakeUpPnd
*   @brief Alias name for CAN Initiated a WakeUp to system
*/
#define canLEVEL_WakeUpPnd 0x200U

/** @def canLEVEL_PDA
*   @brief Alias name for CAN entered low power mode successfully.
*/
#define canLEVEL_PDA 0x400U

/** @def canERROR_NO
*   @brief Alias name for no CAN error occurred 
*/
#define canERROR_OK 0U

/** @def canERROR_STUFF
*   @brief Alias name for CAN stuff error an RX message 
*/
#define canERROR_STUFF 1U

/** @def canERROR_FORMAT
*   @brief Alias name for CAN form/format error an RX message 
*/
#define canERROR_FORMAT 2U

/** @def canERROR_ACKNOWLEDGE
*   @brief Alias name for CAN TX message wasn't acknowledged  
*/
#define canERROR_ACKNOWLEDGE 3U

/** @def canERROR_BIT1
*   @brief Alias name for CAN TX message sending recessive level but monitoring dominant  
*/
#define canERROR_BIT1 4U

/** @def canERROR_BIT0
*   @brief Alias name for CAN TX message sending dominant level but monitoring recessive  
*/
#define canERROR_BIT0 5U

/** @def canERROR_CRC
*   @brief Alias name for CAN RX message received wrong CRC  
*/
#define canERROR_CRC 6U

/** @def canERROR_NO
*   @brief Alias name for CAN no message has send or received since last call of CANGetLastError  
*/
#define canERROR_NO 7U

/** @def canMESSAGE_BOX1
*   @brief Alias name for CAN message box 1
*
*   @note This value should be used for API argument @a messageBox
*/
#define canMESSAGE_BOX1 1U

/** @def canMESSAGE_BOX2
*   @brief Alias name for CAN message box 2
*
*   @note This value should be used for API argument @a messageBox
*/
#define canMESSAGE_BOX2 2U

/** @def canMESSAGE_BOX3
*   @brief Alias name for CAN message box 3
*
*   @note This value should be used for API argument @a messageBox
*/
#define canMESSAGE_BOX3 3U

/** @def canMESSAGE_BOX4
*   @brief Alias name for CAN message box 4
*
*   @note This value should be used for API argument @a messageBox
*/
#define canMESSAGE_BOX4 4U

/** @def canMESSAGE_BOX5
*   @brief Alias name for CAN message box 5
*
*   @note This value should be used for API argument @a messageBox
*/
#define canMESSAGE_BOX5 5U

/** @def canMESSAGE_BOX6
*   @brief Alias name for CAN message box 6
*
*   @note This value should be used for API argument @a messageBox
*/
#define canMESSAGE_BOX6 6U

/** @def canMESSAGE_BOX7
*   @brief Alias name for CAN message box 7
*
*   @note This value should be used for API argument @a messageBox
*/
#define canMESSAGE_BOX7 7U

/** @def canMESSAGE_BOX8
*   @brief Alias name for CAN message box 8
*
*   @note This value should be used for API argument @a messageBox
*/
#define canMESSAGE_BOX8 8U

/** @def canMESSAGE_BOX9
*   @brief Alias name for CAN message box 9
*
*   @note This value should be used for API argument @a messageBox
*/
#define canMESSAGE_BOX9 9U

/** @def canMESSAGE_BOX10
*   @brief Alias name for CAN message box 10
*
*   @note This value should be used for API argument @a messageBox
*/
#define canMESSAGE_BOX10 10U

/** @def canMESSAGE_BOX11
*   @brief Alias name for CAN message box 11
*
*   @note This value should be used for API argument @a messageBox
*/
#define canMESSAGE_BOX11 11U

/** @def canMESSAGE_BOX12
*   @brief Alias name for CAN message box 12
*
*   @note This value should be used for API argument @a messageBox
*/
#define canMESSAGE_BOX12 12U

/** @def canMESSAGE_BOX13
*   @brief Alias name for CAN message box 13
*
*   @note This value should be used for API argument @a messageBox
*/
#define canMESSAGE_BOX13 13U

/** @def canMESSAGE_BOX14
*   @brief Alias name for CAN message box 14
*
*   @note This value should be used for API argument @a messageBox
*/
#define canMESSAGE_BOX14 14U

/** @def canMESSAGE_BOX15
*   @brief Alias name for CAN message box 15
*
*   @note This value should be used for API argument @a messageBox
*/
#define canMESSAGE_BOX15 15U

/** @def canMESSAGE_BOX16
*   @brief Alias name for CAN message box 16
*
*   @note This value should be used for API argument @a messageBox
*/
#define canMESSAGE_BOX16 16U

/** @def canMESSAGE_BOX17
*   @brief Alias name for CAN message box 17
*
*   @note This value should be used for API argument @a messageBox
*/
#define canMESSAGE_BOX17 17U

/** @def canMESSAGE_BOX18
*   @brief Alias name for CAN message box 18
*
*   @note This value should be used for API argument @a messageBox
*/
#define canMESSAGE_BOX18 18U

/** @def canMESSAGE_BOX19
*   @brief Alias name for CAN message box 19
*
*   @note This value should be used for API argument @a messageBox
*/
#define canMESSAGE_BOX19 19U

/** @def canMESSAGE_BOX20
*   @brief Alias name for CAN message box 20
*
*   @note This value should be used for API argument @a messageBox
*/
#define canMESSAGE_BOX20 20U

/** @def canMESSAGE_BOX21
*   @brief Alias name for CAN message box 21
*
*   @note This value should be used for API argument @a messageBox
*/
#define canMESSAGE_BOX21 21U

/** @def canMESSAGE_BOX22
*   @brief Alias name for CAN message box 22
*
*   @note This value should be used for API argument @a messageBox
*/
#define canMESSAGE_BOX22 22U

/** @def canMESSAGE_BOX23
*   @brief Alias name for CAN message box 23
*
*   @note This value should be used for API argument @a messageBox
*/
#define canMESSAGE_BOX23 23U

/** @def canMESSAGE_BOX24
*   @brief Alias name for CAN message box 24
*
*   @note This value should be used for API argument @a messageBox
*/
#define canMESSAGE_BOX24 24U

/** @def canMESSAGE_BOX25
*   @brief Alias name for CAN message box 25
*
*   @note This value should be used for API argument @a messageBox
*/
#define canMESSAGE_BOX25 25U

/** @def canMESSAGE_BOX26
*   @brief Alias name for CAN message box 26
*
*   @note This value should be used for API argument @a messageBox
*/
#define canMESSAGE_BOX26 26U

/** @def canMESSAGE_BOX27
*   @brief Alias name for CAN message box 27
*
*   @note This value should be used for API argument @a messageBox
*/
#define canMESSAGE_BOX27 27U

/** @def canMESSAGE_BOX28
*   @brief Alias name for CAN message box 28
*
*   @note This value should be used for API argument @a messageBox
*/
#define canMESSAGE_BOX28 28U

/** @def canMESSAGE_BOX29
*   @brief Alias name for CAN message box 29
*
*   @note This value should be used for API argument @a messageBox
*/
#define canMESSAGE_BOX29 29U

/** @def canMESSAGE_BOX30
*   @brief Alias name for CAN message box 30
*
*   @note This value should be used for API argument @a messageBox
*/
#define canMESSAGE_BOX30 30U

/** @def canMESSAGE_BOX31
*   @brief Alias name for CAN message box 31
*
*   @note This value should be used for API argument @a messageBox
*/
#define canMESSAGE_BOX31 31U

/** @def canMESSAGE_BOX32
*   @brief Alias name for CAN message box 32
*
*   @note This value should be used for API argument @a messageBox
*/
#define canMESSAGE_BOX32 32U

/** @def canMESSAGE_BOX33
*   @brief Alias name for CAN message box 33
*
*   @note This value should be used for API argument @a messageBox
*/
#define canMESSAGE_BOX33 33U

/** @def canMESSAGE_BOX34
*   @brief Alias name for CAN message box 34
*
*   @note This value should be used for API argument @a messageBox
*/
#define canMESSAGE_BOX34 34U

/** @def canMESSAGE_BOX35
*   @brief Alias name for CAN message box 35
*
*   @note This value should be used for API argument @a messageBox
*/
#define canMESSAGE_BOX35 35U

/** @def canMESSAGE_BOX36
*   @brief Alias name for CAN message box 36
*
*   @note This value should be used for API argument @a messageBox
*/
#define canMESSAGE_BOX36 36U

/** @def canMESSAGE_BOX37
*   @brief Alias name for CAN message box 37
*
*   @note This value should be used for API argument @a messageBox
*/
#define canMESSAGE_BOX37 37U

/** @def canMESSAGE_BOX38
*   @brief Alias name for CAN message box 38
*
*   @note This value should be used for API argument @a messageBox
*/
#define canMESSAGE_BOX38 38U

/** @def canMESSAGE_BOX39
*   @brief Alias name for CAN message box 39
*
*   @note This value should be used for API argument @a messageBox
*/
#define canMESSAGE_BOX39 39U

/** @def canMESSAGE_BOX40
*   @brief Alias name for CAN message box 40
*
*   @note This value should be used for API argument @a messageBox
*/
#define canMESSAGE_BOX40 40U

/** @def canMESSAGE_BOX41
*   @brief Alias name for CAN message box 41
*
*   @note This value should be used for API argument @a messageBox
*/
#define canMESSAGE_BOX41 41U

/** @def canMESSAGE_BOX42
*   @brief Alias name for CAN message box 42
*
*   @note This value should be used for API argument @a messageBox
*/
#define canMESSAGE_BOX42 42U

/** @def canMESSAGE_BOX43
*   @brief Alias name for CAN message box 43
*
*   @note This value should be used for API argument @a messageBox
*/
#define canMESSAGE_BOX43 43U

/** @def canMESSAGE_BOX44
*   @brief Alias name for CAN message box 44
*
*   @note This value should be used for API argument @a messageBox
*/
#define canMESSAGE_BOX44 44U

/** @def canMESSAGE_BOX45
*   @brief Alias name for CAN message box 45
*
*   @note This value should be used for API argument @a messageBox
*/
#define canMESSAGE_BOX45 45U

/** @def canMESSAGE_BOX46
*   @brief Alias name for CAN message box 46
*
*   @note This value should be used for API argument @a messageBox
*/
#define canMESSAGE_BOX46 46U

/** @def canMESSAGE_BOX47
*   @brief Alias name for CAN message box 47
*
*   @note This value should be used for API argument @a messageBox
*/
#define canMESSAGE_BOX47 47U

/** @def canMESSAGE_BOX48
*   @brief Alias name for CAN message box 48
*
*   @note This value should be used for API argument @a messageBox
*/
#define canMESSAGE_BOX48 48U

/** @def canMESSAGE_BOX49
*   @brief Alias name for CAN message box 49
*
*   @note This value should be used for API argument @a messageBox
*/
#define canMESSAGE_BOX49 49U

/** @def canMESSAGE_BOX50
*   @brief Alias name for CAN message box 50
*
*   @note This value should be used for API argument @a messageBox
*/
#define canMESSAGE_BOX50 50U

/** @def canMESSAGE_BOX51
*   @brief Alias name for CAN message box 51
*
*   @note This value should be used for API argument @a messageBox
*/
#define canMESSAGE_BOX51 51U

/** @def canMESSAGE_BOX52
*   @brief Alias name for CAN message box 52
*
*   @note This value should be used for API argument @a messageBox
*/
#define canMESSAGE_BOX52 52U

/** @def canMESSAGE_BOX53
*   @brief Alias name for CAN message box 53
*
*   @note This value should be used for API argument @a messageBox
*/
#define canMESSAGE_BOX53 53U

/** @def canMESSAGE_BOX54
*   @brief Alias name for CAN message box 54
*
*   @note This value should be used for API argument @a messageBox
*/
#define canMESSAGE_BOX54 54U

/** @def canMESSAGE_BOX55
*   @brief Alias name for CAN message box 55
*
*   @note This value should be used for API argument @a messageBox
*/
#define canMESSAGE_BOX55 55U

/** @def canMESSAGE_BOX56
*   @brief Alias name for CAN message box 56
*
*   @note This value should be used for API argument @a messageBox
*/
#define canMESSAGE_BOX56 56U

/** @def canMESSAGE_BOX57
*   @brief Alias name for CAN message box 57
*
*   @note This value should be used for API argument @a messageBox
*/
#define canMESSAGE_BOX57 57U

/** @def canMESSAGE_BOX58
*   @brief Alias name for CAN message box 58
*
*   @note This value should be used for API argument @a messageBox
*/
#define canMESSAGE_BOX58 58U

/** @def canMESSAGE_BOX59
*   @brief Alias name for CAN message box 59
*
*   @note This value should be used for API argument @a messageBox
*/
#define canMESSAGE_BOX59 59U

/** @def canMESSAGE_BOX60
*   @brief Alias name for CAN message box 60
*
*   @note This value should be used for API argument @a messageBox
*/
#define canMESSAGE_BOX60 60U

/** @def canMESSAGE_BOX61
*   @brief Alias name for CAN message box 61
*
*   @note This value should be used for API argument @a messageBox
*/
#define canMESSAGE_BOX61 61U

/** @def canMESSAGE_BOX62
*   @brief Alias name for CAN message box 62
*
*   @note This value should be used for API argument @a messageBox
*/
#define canMESSAGE_BOX62 62U

/** @def canMESSAGE_BOX63
*   @brief Alias name for CAN message box 63
*
*   @note This value should be used for API argument @a messageBox
*/
#define canMESSAGE_BOX63 63U

/** @def canMESSAGE_BOX64
*   @brief Alias name for CAN message box 64
*
*   @note This value should be used for API argument @a messageBox
*/
#define canMESSAGE_BOX64 64U


/** @enum canloopBackType
*   @brief canLoopback type definition
*/
/** @typedef canloopBackType_t
*   @brief canLoopback type Type Definition
*
*   This type is used to select the can module Loopback type Digital or Analog loopback.
*/
typedef enum canloopBackType 
{
    Internal_Lbk = 0x00000010U, 
    External_Lbk = 0x00000100U,
	Internal_Silent_Lbk = 0x00000018U
}canloopBackType_t;

@@USERCODE

/* Configuration registers */
typedef struct can_config_reg
{
    uint32 CONFIG_CTL;
    uint32 CONFIG_ES;
    uint32 CONFIG_BTR;
    uint32 CONFIG_TEST;
    uint32 CONFIG_ABOTR;
    uint32 CONFIG_INTMUX0;
    uint32 CONFIG_INTMUX1;
    uint32 CONFIG_INTMUX2;
    uint32 CONFIG_INTMUX3;   
    uint32 CONFIG_TIOC;
    uint32 CONFIG_RIOC;
} can_config_reg_t;

#if %%SYSTEM:CAN1_ENABLE%%

/* Configuration registers initial value for CAN1*/
#define CAN1_CTL_CONFIGVALUE      ((uint32)%%CAN1:CAN_1_AUTO_BUS_ON%%U \
                                 | (uint32)%%CAN1:CAN_1_AUTO_RETRANSMISSION%%U \
                                 | (uint32)((uint32)%%CAN1:CAN_1_RAM_PARITY_ENA%%U  << 10U) | 0x00020002U)
#define CAN1_ES_CONFIGVALUE         0x00000007U 
#define CAN1_BTR_CONFIGVALUE      ((uint32)((uint32)%%CAN1:CAN_1_BRPE%%U << 16U) \
                                 | (uint32)((uint32)(%%CAN1:CAN_1_PHASE_SEG%%U - 1U) << 12U) \
                                 | (uint32)((uint32)((%%CAN1:CAN_1_PROP_SEG%%U + %%CAN1:CAN_1_PHASE_SEG%%U) - 1U) << 8U) \
                                 | (uint32)((uint32)(%%CAN1:CAN_1_SJW%%U - 1U) << 6U) | (uint32)%%CAN1:CAN_1_BRP%%U)
#define CAN1_TEST_CONFIGVALUE       0x00000080U 
#define CAN1_ABOTR_CONFIGVALUE    ((uint32)(%%CAN1:CAN_1_AUTO_BUS_ON_TR%%U))
#define CAN1_INTMUX0_CONFIGVALUE  ((uint32)%%CAN1:CAN_1_MESSAGE_64_INT_LEVEL%%U \
                                 | (uint32)%%CAN1:CAN_1_MESSAGE_1_INT_LEVEL%%U \
                                 | (uint32)%%CAN1:CAN_1_MESSAGE_2_INT_LEVEL%%U \
                                 | (uint32)%%CAN1:CAN_1_MESSAGE_3_INT_LEVEL%%U \
                                 | (uint32)%%CAN1:CAN_1_MESSAGE_4_INT_LEVEL%%U \
                                 | (uint32)%%CAN1:CAN_1_MESSAGE_5_INT_LEVEL%%U \
                                 | (uint32)%%CAN1:CAN_1_MESSAGE_6_INT_LEVEL%%U \
                                 | (uint32)%%CAN1:CAN_1_MESSAGE_7_INT_LEVEL%%U \
                                 | (uint32)%%CAN1:CAN_1_MESSAGE_8_INT_LEVEL%%U \
                                 | (uint32)%%CAN1:CAN_1_MESSAGE_9_INT_LEVEL%%U \
                                 | (uint32)%%CAN1:CAN_1_MESSAGE_10_INT_LEVEL%%U \
                                 | (uint32)%%CAN1:CAN_1_MESSAGE_11_INT_LEVEL%%U \
                                 | (uint32)%%CAN1:CAN_1_MESSAGE_12_INT_LEVEL%%U \
                                 | (uint32)%%CAN1:CAN_1_MESSAGE_13_INT_LEVEL%%U \
                                 | (uint32)%%CAN1:CAN_1_MESSAGE_14_INT_LEVEL%%U \
                                 | (uint32)%%CAN1:CAN_1_MESSAGE_15_INT_LEVEL%%U \
                                 | (uint32)%%CAN1:CAN_1_MESSAGE_16_INT_LEVEL%%U \
                                 | (uint32)%%CAN1:CAN_1_MESSAGE_17_INT_LEVEL%%U \
                                 | (uint32)%%CAN1:CAN_1_MESSAGE_18_INT_LEVEL%%U \
                                 | (uint32)%%CAN1:CAN_1_MESSAGE_19_INT_LEVEL%%U \
                                 | (uint32)%%CAN1:CAN_1_MESSAGE_20_INT_LEVEL%%U \
                                 | (uint32)%%CAN1:CAN_1_MESSAGE_21_INT_LEVEL%%U \
                                 | (uint32)%%CAN1:CAN_1_MESSAGE_22_INT_LEVEL%%U \
                                 | (uint32)%%CAN1:CAN_1_MESSAGE_23_INT_LEVEL%%U \
                                 | (uint32)%%CAN1:CAN_1_MESSAGE_24_INT_LEVEL%%U \
                                 | (uint32)%%CAN1:CAN_1_MESSAGE_25_INT_LEVEL%%U \
                                 | (uint32)%%CAN1:CAN_1_MESSAGE_26_INT_LEVEL%%U \
                                 | (uint32)%%CAN1:CAN_1_MESSAGE_27_INT_LEVEL%%U \
                                 | (uint32)%%CAN1:CAN_1_MESSAGE_28_INT_LEVEL%%U \
                                 | (uint32)%%CAN1:CAN_1_MESSAGE_29_INT_LEVEL%%U \
                                 | (uint32)%%CAN1:CAN_1_MESSAGE_30_INT_LEVEL%%U \
                                 | (uint32)%%CAN1:CAN_1_MESSAGE_31_INT_LEVEL%%U)

#define CAN1_INTMUX1_CONFIGVALUE  ((uint32)%%CAN1:CAN_1_MESSAGE_32_INT_LEVEL%%U \
                                 | (uint32)%%CAN1:CAN_1_MESSAGE_33_INT_LEVEL%%U \
                                 | (uint32)%%CAN1:CAN_1_MESSAGE_34_INT_LEVEL%%U \
                                 | (uint32)%%CAN1:CAN_1_MESSAGE_35_INT_LEVEL%%U \
                                 | (uint32)%%CAN1:CAN_1_MESSAGE_36_INT_LEVEL%%U \
                                 | (uint32)%%CAN1:CAN_1_MESSAGE_37_INT_LEVEL%%U \
                                 | (uint32)%%CAN1:CAN_1_MESSAGE_38_INT_LEVEL%%U \
                                 | (uint32)%%CAN1:CAN_1_MESSAGE_39_INT_LEVEL%%U \
                                 | (uint32)%%CAN1:CAN_1_MESSAGE_40_INT_LEVEL%%U \
                                 | (uint32)%%CAN1:CAN_1_MESSAGE_41_INT_LEVEL%%U \
                                 | (uint32)%%CAN1:CAN_1_MESSAGE_42_INT_LEVEL%%U \
                                 | (uint32)%%CAN1:CAN_1_MESSAGE_43_INT_LEVEL%%U \
                                 | (uint32)%%CAN1:CAN_1_MESSAGE_44_INT_LEVEL%%U \
                                 | (uint32)%%CAN1:CAN_1_MESSAGE_45_INT_LEVEL%%U \
                                 | (uint32)%%CAN1:CAN_1_MESSAGE_46_INT_LEVEL%%U \
                                 | (uint32)%%CAN1:CAN_1_MESSAGE_47_INT_LEVEL%%U \
                                 | (uint32)%%CAN1:CAN_1_MESSAGE_48_INT_LEVEL%%U \
                                 | (uint32)%%CAN1:CAN_1_MESSAGE_49_INT_LEVEL%%U \
                                 | (uint32)%%CAN1:CAN_1_MESSAGE_50_INT_LEVEL%%U \
                                 | (uint32)%%CAN1:CAN_1_MESSAGE_51_INT_LEVEL%%U \
                                 | (uint32)%%CAN1:CAN_1_MESSAGE_52_INT_LEVEL%%U \
                                 | (uint32)%%CAN1:CAN_1_MESSAGE_53_INT_LEVEL%%U \
                                 | (uint32)%%CAN1:CAN_1_MESSAGE_54_INT_LEVEL%%U \
                                 | (uint32)%%CAN1:CAN_1_MESSAGE_55_INT_LEVEL%%U \
                                 | (uint32)%%CAN1:CAN_1_MESSAGE_56_INT_LEVEL%%U \
                                 | (uint32)%%CAN1:CAN_1_MESSAGE_57_INT_LEVEL%%U \
                                 | (uint32)%%CAN1:CAN_1_MESSAGE_58_INT_LEVEL%%U \
                                 | (uint32)%%CAN1:CAN_1_MESSAGE_59_INT_LEVEL%%U \
                                 | (uint32)%%CAN1:CAN_1_MESSAGE_60_INT_LEVEL%%U \
                                 | (uint32)%%CAN1:CAN_1_MESSAGE_61_INT_LEVEL%%U \
                                 | (uint32)%%CAN1:CAN_1_MESSAGE_62_INT_LEVEL%%U \
                                 | (uint32)%%CAN1:CAN_1_MESSAGE_63_INT_LEVEL%%U)

#define CAN1_INTMUX2_CONFIGVALUE   0x00000000U
#define CAN1_INTMUX3_CONFIGVALUE   0x00000000U
#define CAN1_TIOC_CONFIGVALUE    ((uint32)((uint32)%%CAN1:CAN_1_PORT_TX_PSL%%U  << 18U ) \
                                 |(uint32)((uint32)%%CAN1:CAN_1_PORT_TX_PULDIS%%U  << 17U ) \
								 |(uint32)((uint32)%%CAN1:CAN_1_PORT_TX_PDR%%U  << 16U ) \
                                 |(uint32)((uint32)%%CAN1:CAN_1_PORT_TX_FUN%%U  << 3U ) \
                                 |(uint32)((uint32)%%CAN1:CAN_1_PORT_TX_DIR%%U  << 2U ) \
                                 |(uint32)((uint32)%%CAN1:CAN_1_PORT_TX_DOUT%%U << 1U ))
#define CAN1_RIOC_CONFIGVALUE    ((uint32)((uint32)%%CAN1:CAN_1_PORT_RX_PSL%%U  << 18U ) \
                                 |(uint32)((uint32)%%CAN1:CAN_1_PORT_RX_PULDIS%%U  << 17U ) \
								 |(uint32)((uint32)%%CAN1:CAN_1_PORT_RX_PDR%%U  << 16U ) \
                                 |(uint32)((uint32)%%CAN1:CAN_1_PORT_RX_FUN%%U  << 3U ) \
                                 |(uint32)((uint32)%%CAN1:CAN_1_PORT_RX_DIR%%U  << 2U ) \
                                 |(uint32)((uint32)%%CAN1:CAN_1_PORT_RX_DOUT%%U << 1U ))
#endif

#if %%SYSTEM:CAN2_ENABLE%%

/* Configuration registers initial value for CAN2*/
#define CAN2_CTL_CONFIGVALUE      ((uint32)%%CAN2:CAN_2_AUTO_BUS_ON%%U \
                                 | (uint32)%%CAN2:CAN_2_AUTO_RETRANSMISSION%%U \
                                 | (uint32)((uint32)%%CAN2:CAN_2_RAM_PARITY_ENA%%U  << 10U) | 0x00020002U)
#define CAN2_ES_CONFIGVALUE      0x00000007U 
#define CAN2_BTR_CONFIGVALUE      ((uint32)((uint32)%%CAN2:CAN_2_BRPE%%U << 16U) \
                                 | (uint32)((uint32)(%%CAN2:CAN_2_PHASE_SEG%%U - 1U) << 12U) \
                                 | (uint32)((uint32)((%%CAN2:CAN_2_PROP_SEG%%U + %%CAN2:CAN_2_PHASE_SEG%%U) - 1U) << 8U) \
                                 | (uint32)((uint32)(%%CAN2:CAN_2_SJW%%U - 1U) << 6U) | (uint32)%%CAN2:CAN_2_BRP%%U)
#define CAN2_TEST_CONFIGVALUE    0x00000080U 
#define CAN2_ABOTR_CONFIGVALUE    ((uint32)(%%CAN2:CAN_2_AUTO_BUS_ON_TR%%U))
#define CAN2_INTMUX0_CONFIGVALUE  ((uint32)%%CAN2:CAN_2_MESSAGE_64_INT_LEVEL%%U \
                                 | (uint32)%%CAN2:CAN_2_MESSAGE_1_INT_LEVEL%%U \
                                 | (uint32)%%CAN2:CAN_2_MESSAGE_2_INT_LEVEL%%U \
                                 | (uint32)%%CAN2:CAN_2_MESSAGE_3_INT_LEVEL%%U \
                                 | (uint32)%%CAN2:CAN_2_MESSAGE_4_INT_LEVEL%%U \
                                 | (uint32)%%CAN2:CAN_2_MESSAGE_5_INT_LEVEL%%U \
                                 | (uint32)%%CAN2:CAN_2_MESSAGE_6_INT_LEVEL%%U \
                                 | (uint32)%%CAN2:CAN_2_MESSAGE_7_INT_LEVEL%%U \
                                 | (uint32)%%CAN2:CAN_2_MESSAGE_8_INT_LEVEL%%U \
                                 | (uint32)%%CAN2:CAN_2_MESSAGE_9_INT_LEVEL%%U \
                                 | (uint32)%%CAN2:CAN_2_MESSAGE_10_INT_LEVEL%%U \
                                 | (uint32)%%CAN2:CAN_2_MESSAGE_11_INT_LEVEL%%U \
                                 | (uint32)%%CAN2:CAN_2_MESSAGE_12_INT_LEVEL%%U \
                                 | (uint32)%%CAN2:CAN_2_MESSAGE_13_INT_LEVEL%%U \
                                 | (uint32)%%CAN2:CAN_2_MESSAGE_14_INT_LEVEL%%U \
                                 | (uint32)%%CAN2:CAN_2_MESSAGE_15_INT_LEVEL%%U \
                                 | (uint32)%%CAN2:CAN_2_MESSAGE_16_INT_LEVEL%%U \
                                 | (uint32)%%CAN2:CAN_2_MESSAGE_17_INT_LEVEL%%U \
                                 | (uint32)%%CAN2:CAN_2_MESSAGE_18_INT_LEVEL%%U \
                                 | (uint32)%%CAN2:CAN_2_MESSAGE_19_INT_LEVEL%%U \
                                 | (uint32)%%CAN2:CAN_2_MESSAGE_20_INT_LEVEL%%U \
                                 | (uint32)%%CAN2:CAN_2_MESSAGE_21_INT_LEVEL%%U \
                                 | (uint32)%%CAN2:CAN_2_MESSAGE_22_INT_LEVEL%%U \
                                 | (uint32)%%CAN2:CAN_2_MESSAGE_23_INT_LEVEL%%U \
                                 | (uint32)%%CAN2:CAN_2_MESSAGE_24_INT_LEVEL%%U \
                                 | (uint32)%%CAN2:CAN_2_MESSAGE_25_INT_LEVEL%%U \
                                 | (uint32)%%CAN2:CAN_2_MESSAGE_26_INT_LEVEL%%U \
                                 | (uint32)%%CAN2:CAN_2_MESSAGE_27_INT_LEVEL%%U \
                                 | (uint32)%%CAN2:CAN_2_MESSAGE_28_INT_LEVEL%%U \
                                 | (uint32)%%CAN2:CAN_2_MESSAGE_29_INT_LEVEL%%U \
                                 | (uint32)%%CAN2:CAN_2_MESSAGE_30_INT_LEVEL%%U \
                                 | (uint32)%%CAN2:CAN_2_MESSAGE_31_INT_LEVEL%%U)

#define CAN2_INTMUX1_CONFIGVALUE  ((uint32)%%CAN2:CAN_2_MESSAGE_32_INT_LEVEL%%U \
                                 | (uint32)%%CAN2:CAN_2_MESSAGE_33_INT_LEVEL%%U \
                                 | (uint32)%%CAN2:CAN_2_MESSAGE_34_INT_LEVEL%%U \
                                 | (uint32)%%CAN2:CAN_2_MESSAGE_35_INT_LEVEL%%U \
                                 | (uint32)%%CAN2:CAN_2_MESSAGE_36_INT_LEVEL%%U \
                                 | (uint32)%%CAN2:CAN_2_MESSAGE_37_INT_LEVEL%%U \
                                 | (uint32)%%CAN2:CAN_2_MESSAGE_38_INT_LEVEL%%U \
                                 | (uint32)%%CAN2:CAN_2_MESSAGE_39_INT_LEVEL%%U \
                                 | (uint32)%%CAN2:CAN_2_MESSAGE_40_INT_LEVEL%%U \
                                 | (uint32)%%CAN2:CAN_2_MESSAGE_41_INT_LEVEL%%U \
                                 | (uint32)%%CAN2:CAN_2_MESSAGE_42_INT_LEVEL%%U \
                                 | (uint32)%%CAN2:CAN_2_MESSAGE_43_INT_LEVEL%%U \
                                 | (uint32)%%CAN2:CAN_2_MESSAGE_44_INT_LEVEL%%U \
                                 | (uint32)%%CAN2:CAN_2_MESSAGE_45_INT_LEVEL%%U \
                                 | (uint32)%%CAN2:CAN_2_MESSAGE_46_INT_LEVEL%%U \
                                 | (uint32)%%CAN2:CAN_2_MESSAGE_47_INT_LEVEL%%U \
                                 | (uint32)%%CAN2:CAN_2_MESSAGE_48_INT_LEVEL%%U \
                                 | (uint32)%%CAN2:CAN_2_MESSAGE_49_INT_LEVEL%%U \
                                 | (uint32)%%CAN2:CAN_2_MESSAGE_50_INT_LEVEL%%U \
                                 | (uint32)%%CAN2:CAN_2_MESSAGE_51_INT_LEVEL%%U \
                                 | (uint32)%%CAN2:CAN_2_MESSAGE_52_INT_LEVEL%%U \
                                 | (uint32)%%CAN2:CAN_2_MESSAGE_53_INT_LEVEL%%U \
                                 | (uint32)%%CAN2:CAN_2_MESSAGE_54_INT_LEVEL%%U \
                                 | (uint32)%%CAN2:CAN_2_MESSAGE_55_INT_LEVEL%%U \
                                 | (uint32)%%CAN2:CAN_2_MESSAGE_56_INT_LEVEL%%U \
                                 | (uint32)%%CAN2:CAN_2_MESSAGE_57_INT_LEVEL%%U \
                                 | (uint32)%%CAN2:CAN_2_MESSAGE_58_INT_LEVEL%%U \
                                 | (uint32)%%CAN2:CAN_2_MESSAGE_59_INT_LEVEL%%U \
                                 | (uint32)%%CAN2:CAN_2_MESSAGE_60_INT_LEVEL%%U \
                                 | (uint32)%%CAN2:CAN_2_MESSAGE_61_INT_LEVEL%%U \
                                 | (uint32)%%CAN2:CAN_2_MESSAGE_62_INT_LEVEL%%U \
                                 | (uint32)%%CAN2:CAN_2_MESSAGE_63_INT_LEVEL%%U)

#define CAN2_INTMUX2_CONFIGVALUE 0x00000000U
#define CAN2_INTMUX3_CONFIGVALUE 0x00000000U
#define CAN2_TIOC_CONFIGVALUE    ((uint32)((uint32)%%CAN2:CAN_2_PORT_TX_PSL%%U  << 18U ) \
                                 |(uint32)((uint32)%%CAN2:CAN_2_PORT_TX_PULDIS%%U  << 17U ) \
								 |(uint32)((uint32)%%CAN2:CAN_2_PORT_TX_PDR%%U  << 16U )\
                                 |(uint32)((uint32)%%CAN2:CAN_2_PORT_TX_FUN%%U  << 3U ) \
                                 |(uint32)((uint32)%%CAN2:CAN_2_PORT_TX_DIR%%U  << 2U ) \
                                 |(uint32)((uint32)%%CAN2:CAN_2_PORT_TX_DOUT%%U << 1U ))
#define CAN2_RIOC_CONFIGVALUE    ((uint32)((uint32)%%CAN2:CAN_2_PORT_RX_PSL%%U  << 18U ) \
                                 |(uint32)((uint32)%%CAN2:CAN_2_PORT_RX_PULDIS%%U  << 17U ) \
								 |(uint32)((uint32)%%CAN2:CAN_2_PORT_RX_PDR%%U  << 16U )\
                                 |(uint32)((uint32)%%CAN2:CAN_2_PORT_RX_FUN%%U  << 3U ) \
                                 |(uint32)((uint32)%%CAN2:CAN_2_PORT_RX_DIR%%U  << 2U ) \
                                 |(uint32)((uint32)%%CAN2:CAN_2_PORT_RX_DOUT%%U << 1U ))
#endif

#if %%SYSTEM:CAN3_ENABLE%%                                 
/* Configuration registers initial value for CAN3*/
#define CAN3_CTL_CONFIGVALUE      ((uint32)%%CAN3:CAN_3_AUTO_BUS_ON%%U \
                                 | (uint32)%%CAN3:CAN_3_AUTO_RETRANSMISSION%%U \
								 | (uint32)((uint32)%%CAN3:CAN_3_RAM_PARITY_ENA%%U  << 10U) | 0x00020002U)
#define CAN3_ES_CONFIGVALUE      0x00000007U 
#define CAN3_BTR_CONFIGVALUE      ((uint32)((uint32)%%CAN3:CAN_3_BRPE%%U << 16U) \
                                 | (uint32)((uint32)(%%CAN3:CAN_3_PHASE_SEG%%U - 1U) << 12U) \
                                 | (uint32)((uint32)((%%CAN3:CAN_3_PROP_SEG%%U + %%CAN3:CAN_3_PHASE_SEG%%U) - 1U) << 8U) \
                                 | (uint32)((uint32)(%%CAN3:CAN_3_SJW%%U - 1U) << 6U) | (uint32)%%CAN3:CAN_3_BRP%%U)
#define CAN3_TEST_CONFIGVALUE    0x00000080U 
#define CAN3_ABOTR_CONFIGVALUE    ((uint32)(%%CAN3:CAN_3_AUTO_BUS_ON_TR%%U))
#define CAN3_INTMUX0_CONFIGVALUE  ((uint32)%%CAN3:CAN_3_MESSAGE_64_INT_LEVEL%%U \
                                 | (uint32)%%CAN3:CAN_3_MESSAGE_1_INT_LEVEL%%U \
                                 | (uint32)%%CAN3:CAN_3_MESSAGE_2_INT_LEVEL%%U \
                                 | (uint32)%%CAN3:CAN_3_MESSAGE_3_INT_LEVEL%%U \
                                 | (uint32)%%CAN3:CAN_3_MESSAGE_4_INT_LEVEL%%U \
                                 | (uint32)%%CAN3:CAN_3_MESSAGE_5_INT_LEVEL%%U \
                                 | (uint32)%%CAN3:CAN_3_MESSAGE_6_INT_LEVEL%%U \
                                 | (uint32)%%CAN3:CAN_3_MESSAGE_7_INT_LEVEL%%U \
                                 | (uint32)%%CAN3:CAN_3_MESSAGE_8_INT_LEVEL%%U \
                                 | (uint32)%%CAN3:CAN_3_MESSAGE_9_INT_LEVEL%%U \
                                 | (uint32)%%CAN3:CAN_3_MESSAGE_10_INT_LEVEL%%U \
                                 | (uint32)%%CAN3:CAN_3_MESSAGE_11_INT_LEVEL%%U \
                                 | (uint32)%%CAN3:CAN_3_MESSAGE_12_INT_LEVEL%%U \
                                 | (uint32)%%CAN3:CAN_3_MESSAGE_13_INT_LEVEL%%U \
                                 | (uint32)%%CAN3:CAN_3_MESSAGE_14_INT_LEVEL%%U \
                                 | (uint32)%%CAN3:CAN_3_MESSAGE_15_INT_LEVEL%%U \
                                 | (uint32)%%CAN3:CAN_3_MESSAGE_16_INT_LEVEL%%U \
                                 | (uint32)%%CAN3:CAN_3_MESSAGE_17_INT_LEVEL%%U \
                                 | (uint32)%%CAN3:CAN_3_MESSAGE_18_INT_LEVEL%%U \
                                 | (uint32)%%CAN3:CAN_3_MESSAGE_19_INT_LEVEL%%U \
                                 | (uint32)%%CAN3:CAN_3_MESSAGE_20_INT_LEVEL%%U \
                                 | (uint32)%%CAN3:CAN_3_MESSAGE_21_INT_LEVEL%%U \
                                 | (uint32)%%CAN3:CAN_3_MESSAGE_22_INT_LEVEL%%U \
                                 | (uint32)%%CAN3:CAN_3_MESSAGE_23_INT_LEVEL%%U \
                                 | (uint32)%%CAN3:CAN_3_MESSAGE_24_INT_LEVEL%%U \
                                 | (uint32)%%CAN3:CAN_3_MESSAGE_25_INT_LEVEL%%U \
                                 | (uint32)%%CAN3:CAN_3_MESSAGE_26_INT_LEVEL%%U \
                                 | (uint32)%%CAN3:CAN_3_MESSAGE_27_INT_LEVEL%%U \
                                 | (uint32)%%CAN3:CAN_3_MESSAGE_28_INT_LEVEL%%U \
                                 | (uint32)%%CAN3:CAN_3_MESSAGE_29_INT_LEVEL%%U \
                                 | (uint32)%%CAN3:CAN_3_MESSAGE_30_INT_LEVEL%%U \
                                 | (uint32)%%CAN3:CAN_3_MESSAGE_31_INT_LEVEL%%U)

#define CAN3_INTMUX1_CONFIGVALUE  ((uint32)%%CAN3:CAN_3_MESSAGE_32_INT_LEVEL%%U \
                                 | (uint32)%%CAN3:CAN_3_MESSAGE_33_INT_LEVEL%%U \
                                 | (uint32)%%CAN3:CAN_3_MESSAGE_34_INT_LEVEL%%U \
                                 | (uint32)%%CAN3:CAN_3_MESSAGE_35_INT_LEVEL%%U \
                                 | (uint32)%%CAN3:CAN_3_MESSAGE_36_INT_LEVEL%%U \
                                 | (uint32)%%CAN3:CAN_3_MESSAGE_37_INT_LEVEL%%U \
                                 | (uint32)%%CAN3:CAN_3_MESSAGE_38_INT_LEVEL%%U \
                                 | (uint32)%%CAN3:CAN_3_MESSAGE_39_INT_LEVEL%%U \
                                 | (uint32)%%CAN3:CAN_3_MESSAGE_40_INT_LEVEL%%U \
                                 | (uint32)%%CAN3:CAN_3_MESSAGE_41_INT_LEVEL%%U \
                                 | (uint32)%%CAN3:CAN_3_MESSAGE_42_INT_LEVEL%%U \
                                 | (uint32)%%CAN3:CAN_3_MESSAGE_43_INT_LEVEL%%U \
                                 | (uint32)%%CAN3:CAN_3_MESSAGE_44_INT_LEVEL%%U \
                                 | (uint32)%%CAN3:CAN_3_MESSAGE_45_INT_LEVEL%%U \
                                 | (uint32)%%CAN3:CAN_3_MESSAGE_46_INT_LEVEL%%U \
                                 | (uint32)%%CAN3:CAN_3_MESSAGE_47_INT_LEVEL%%U \
                                 | (uint32)%%CAN3:CAN_3_MESSAGE_48_INT_LEVEL%%U \
                                 | (uint32)%%CAN3:CAN_3_MESSAGE_49_INT_LEVEL%%U \
                                 | (uint32)%%CAN3:CAN_3_MESSAGE_50_INT_LEVEL%%U \
                                 | (uint32)%%CAN3:CAN_3_MESSAGE_51_INT_LEVEL%%U \
                                 | (uint32)%%CAN3:CAN_3_MESSAGE_52_INT_LEVEL%%U \
                                 | (uint32)%%CAN3:CAN_3_MESSAGE_53_INT_LEVEL%%U \
                                 | (uint32)%%CAN3:CAN_3_MESSAGE_54_INT_LEVEL%%U \
                                 | (uint32)%%CAN3:CAN_3_MESSAGE_55_INT_LEVEL%%U \
                                 | (uint32)%%CAN3:CAN_3_MESSAGE_56_INT_LEVEL%%U \
                                 | (uint32)%%CAN3:CAN_3_MESSAGE_57_INT_LEVEL%%U \
                                 | (uint32)%%CAN3:CAN_3_MESSAGE_58_INT_LEVEL%%U \
                                 | (uint32)%%CAN3:CAN_3_MESSAGE_59_INT_LEVEL%%U \
                                 | (uint32)%%CAN3:CAN_3_MESSAGE_60_INT_LEVEL%%U \
                                 | (uint32)%%CAN3:CAN_3_MESSAGE_61_INT_LEVEL%%U \
                                 | (uint32)%%CAN3:CAN_3_MESSAGE_62_INT_LEVEL%%U \
                                 | (uint32)%%CAN3:CAN_3_MESSAGE_63_INT_LEVEL%%U)

#define CAN3_INTMUX2_CONFIGVALUE 0x00000000U
#define CAN3_INTMUX3_CONFIGVALUE 0x00000000U
#define CAN3_TIOC_CONFIGVALUE    ((uint32)((uint32)%%CAN3:CAN_3_PORT_TX_PSL%%U  << 18U ) \
                                 |(uint32)((uint32)%%CAN3:CAN_3_PORT_TX_PULDIS%%U  << 17U ) \
								 |(uint32)((uint32)%%CAN3:CAN_3_PORT_TX_PDR%%U  << 16U )\
                                 |(uint32)((uint32)%%CAN3:CAN_3_PORT_TX_FUN%%U  << 3U ) \
                                 |(uint32)((uint32)%%CAN3:CAN_3_PORT_TX_DIR%%U  << 2U ) \
                                 |(uint32)((uint32)%%CAN3:CAN_3_PORT_TX_DOUT%%U << 1U ))
#define CAN3_RIOC_CONFIGVALUE    ((uint32)((uint32)%%CAN3:CAN_3_PORT_RX_PSL%%U  << 18U ) \
                                 |(uint32)((uint32)%%CAN3:CAN_3_PORT_RX_PULDIS%%U  << 17U ) \
								 |(uint32)((uint32)%%CAN3:CAN_3_PORT_RX_PDR%%U  << 16U )\
                                 |(uint32)((uint32)%%CAN3:CAN_3_PORT_RX_FUN%%U  << 3U ) \
                                 |(uint32)((uint32)%%CAN3:CAN_3_PORT_RX_DIR%%U  << 2U ) \
                                 |(uint32)((uint32)%%CAN3:CAN_3_PORT_RX_DOUT%%U << 1U ))
								 
#endif

#if %%SYSTEM:CAN4_ENABLE%%

/* Configuration registers initial value for CAN4*/
#define CAN4_CTL_CONFIGVALUE      ((uint32)%%CAN4:CAN_4_AUTO_BUS_ON%%U \
                                 | (uint32)%%CAN4:CAN_4_AUTO_RETRANSMISSION%%U \
                                 | (uint32)((uint32)%%CAN4:CAN_4_RAM_PARITY_ENA%%U  << 10U) | 0x00020002U)
#define CAN4_ES_CONFIGVALUE         0x00000007U 
#define CAN4_BTR_CONFIGVALUE      ((uint32)((uint32)%%CAN4:CAN_4_BRPE%%U << 16U) \
                                 | (uint32)((uint32)(%%CAN4:CAN_4_PHASE_SEG%%U - 1U) << 12U) \
                                 | (uint32)((uint32)((%%CAN4:CAN_4_PROP_SEG%%U + %%CAN4:CAN_4_PHASE_SEG%%U) - 1U) << 8U) \
                                 | (uint32)((uint32)(%%CAN4:CAN_4_SJW%%U - 1U) << 6U) | (uint32)%%CAN4:CAN_4_BRP%%U)
#define CAN4_TEST_CONFIGVALUE       0x00000080U 
#define CAN4_ABOTR_CONFIGVALUE    ((uint32)(%%CAN4:CAN_4_AUTO_BUS_ON_TR%%U))
#define CAN4_INTMUX0_CONFIGVALUE  ((uint32)%%CAN4:CAN_4_MESSAGE_64_INT_LEVEL%%U \
                                 | (uint32)%%CAN4:CAN_4_MESSAGE_1_INT_LEVEL%%U \
                                 | (uint32)%%CAN4:CAN_4_MESSAGE_2_INT_LEVEL%%U \
                                 | (uint32)%%CAN4:CAN_4_MESSAGE_3_INT_LEVEL%%U \
                                 | (uint32)%%CAN4:CAN_4_MESSAGE_4_INT_LEVEL%%U \
                                 | (uint32)%%CAN4:CAN_4_MESSAGE_5_INT_LEVEL%%U \
                                 | (uint32)%%CAN4:CAN_4_MESSAGE_6_INT_LEVEL%%U \
                                 | (uint32)%%CAN4:CAN_4_MESSAGE_7_INT_LEVEL%%U \
                                 | (uint32)%%CAN4:CAN_4_MESSAGE_8_INT_LEVEL%%U \
                                 | (uint32)%%CAN4:CAN_4_MESSAGE_9_INT_LEVEL%%U \
                                 | (uint32)%%CAN4:CAN_4_MESSAGE_10_INT_LEVEL%%U \
                                 | (uint32)%%CAN4:CAN_4_MESSAGE_11_INT_LEVEL%%U \
                                 | (uint32)%%CAN4:CAN_4_MESSAGE_12_INT_LEVEL%%U \
                                 | (uint32)%%CAN4:CAN_4_MESSAGE_13_INT_LEVEL%%U \
                                 | (uint32)%%CAN4:CAN_4_MESSAGE_14_INT_LEVEL%%U \
                                 | (uint32)%%CAN4:CAN_4_MESSAGE_15_INT_LEVEL%%U \
                                 | (uint32)%%CAN4:CAN_4_MESSAGE_16_INT_LEVEL%%U \
                                 | (uint32)%%CAN4:CAN_4_MESSAGE_17_INT_LEVEL%%U \
                                 | (uint32)%%CAN4:CAN_4_MESSAGE_18_INT_LEVEL%%U \
                                 | (uint32)%%CAN4:CAN_4_MESSAGE_19_INT_LEVEL%%U \
                                 | (uint32)%%CAN4:CAN_4_MESSAGE_20_INT_LEVEL%%U \
                                 | (uint32)%%CAN4:CAN_4_MESSAGE_21_INT_LEVEL%%U \
                                 | (uint32)%%CAN4:CAN_4_MESSAGE_22_INT_LEVEL%%U \
                                 | (uint32)%%CAN4:CAN_4_MESSAGE_23_INT_LEVEL%%U \
                                 | (uint32)%%CAN4:CAN_4_MESSAGE_24_INT_LEVEL%%U \
                                 | (uint32)%%CAN4:CAN_4_MESSAGE_25_INT_LEVEL%%U \
                                 | (uint32)%%CAN4:CAN_4_MESSAGE_26_INT_LEVEL%%U \
                                 | (uint32)%%CAN4:CAN_4_MESSAGE_27_INT_LEVEL%%U \
                                 | (uint32)%%CAN4:CAN_4_MESSAGE_28_INT_LEVEL%%U \
                                 | (uint32)%%CAN4:CAN_4_MESSAGE_29_INT_LEVEL%%U \
                                 | (uint32)%%CAN4:CAN_4_MESSAGE_30_INT_LEVEL%%U \
                                 | (uint32)%%CAN4:CAN_4_MESSAGE_31_INT_LEVEL%%U)

#define CAN4_INTMUX1_CONFIGVALUE  ((uint32)%%CAN4:CAN_4_MESSAGE_32_INT_LEVEL%%U \
                                 | (uint32)%%CAN4:CAN_4_MESSAGE_33_INT_LEVEL%%U \
                                 | (uint32)%%CAN4:CAN_4_MESSAGE_34_INT_LEVEL%%U \
                                 | (uint32)%%CAN4:CAN_4_MESSAGE_35_INT_LEVEL%%U \
                                 | (uint32)%%CAN4:CAN_4_MESSAGE_36_INT_LEVEL%%U \
                                 | (uint32)%%CAN4:CAN_4_MESSAGE_37_INT_LEVEL%%U \
                                 | (uint32)%%CAN4:CAN_4_MESSAGE_38_INT_LEVEL%%U \
                                 | (uint32)%%CAN4:CAN_4_MESSAGE_39_INT_LEVEL%%U \
                                 | (uint32)%%CAN4:CAN_4_MESSAGE_40_INT_LEVEL%%U \
                                 | (uint32)%%CAN4:CAN_4_MESSAGE_41_INT_LEVEL%%U \
                                 | (uint32)%%CAN4:CAN_4_MESSAGE_42_INT_LEVEL%%U \
                                 | (uint32)%%CAN4:CAN_4_MESSAGE_43_INT_LEVEL%%U \
                                 | (uint32)%%CAN4:CAN_4_MESSAGE_44_INT_LEVEL%%U \
                                 | (uint32)%%CAN4:CAN_4_MESSAGE_45_INT_LEVEL%%U \
                                 | (uint32)%%CAN4:CAN_4_MESSAGE_46_INT_LEVEL%%U \
                                 | (uint32)%%CAN4:CAN_4_MESSAGE_47_INT_LEVEL%%U \
                                 | (uint32)%%CAN4:CAN_4_MESSAGE_48_INT_LEVEL%%U \
                                 | (uint32)%%CAN4:CAN_4_MESSAGE_49_INT_LEVEL%%U \
                                 | (uint32)%%CAN4:CAN_4_MESSAGE_50_INT_LEVEL%%U \
                                 | (uint32)%%CAN4:CAN_4_MESSAGE_51_INT_LEVEL%%U \
                                 | (uint32)%%CAN4:CAN_4_MESSAGE_52_INT_LEVEL%%U \
                                 | (uint32)%%CAN4:CAN_4_MESSAGE_53_INT_LEVEL%%U \
                                 | (uint32)%%CAN4:CAN_4_MESSAGE_54_INT_LEVEL%%U \
                                 | (uint32)%%CAN4:CAN_4_MESSAGE_55_INT_LEVEL%%U \
                                 | (uint32)%%CAN4:CAN_4_MESSAGE_56_INT_LEVEL%%U \
                                 | (uint32)%%CAN4:CAN_4_MESSAGE_57_INT_LEVEL%%U \
                                 | (uint32)%%CAN4:CAN_4_MESSAGE_58_INT_LEVEL%%U \
                                 | (uint32)%%CAN4:CAN_4_MESSAGE_59_INT_LEVEL%%U \
                                 | (uint32)%%CAN4:CAN_4_MESSAGE_60_INT_LEVEL%%U \
                                 | (uint32)%%CAN4:CAN_4_MESSAGE_61_INT_LEVEL%%U \
                                 | (uint32)%%CAN4:CAN_4_MESSAGE_62_INT_LEVEL%%U \
                                 | (uint32)%%CAN4:CAN_4_MESSAGE_63_INT_LEVEL%%U)

#define CAN4_INTMUX2_CONFIGVALUE   0x00000000U
#define CAN4_INTMUX3_CONFIGVALUE   0x00000000U
#define CAN4_TIOC_CONFIGVALUE    ((uint32)((uint32)%%CAN4:CAN_4_PORT_TX_PSL%%U  << 18U ) \
                                 |(uint32)((uint32)%%CAN4:CAN_4_PORT_TX_PULDIS%%U  << 17U ) \
								 |(uint32)((uint32)%%CAN4:CAN_4_PORT_TX_PDR%%U  << 16U )\
                                 |(uint32)((uint32)%%CAN4:CAN_4_PORT_TX_FUN%%U  << 3U ) \
                                 |(uint32)((uint32)%%CAN4:CAN_4_PORT_TX_DIR%%U  << 2U ) \
                                 |(uint32)((uint32)%%CAN4:CAN_4_PORT_TX_DOUT%%U << 1U ))
#define CAN4_RIOC_CONFIGVALUE    ((uint32)((uint32)%%CAN4:CAN_4_PORT_RX_PSL%%U  << 18U ) \
                                 |(uint32)((uint32)%%CAN4:CAN_4_PORT_RX_PULDIS%%U  << 17U ) \
								 |(uint32)((uint32)%%CAN4:CAN_4_PORT_RX_PDR%%U  << 16U )\
                                 |(uint32)((uint32)%%CAN4:CAN_4_PORT_RX_FUN%%U  << 3U ) \
                                 |(uint32)((uint32)%%CAN4:CAN_4_PORT_RX_DIR%%U  << 2U ) \
                                 |(uint32)((uint32)%%CAN4:CAN_4_PORT_RX_DOUT%%U << 1U ))
#endif

/** 
 *  @defgroup CAN CAN
 *  @brief Controller Area Network Module.
 *  
 *  The Controller Area Network is a high-integrity, serial, multi-master communication protocol for distributed
 *  real-time applications. This CAN module is implemented according to ISO 11898-1 and is suitable for
 *  industrial, automotive and general embedded communications
 *
 *    Related Files
 *   - HL_reg_can.h
 *   - HL_can.h
 *   - HL_can.c
 *  @addtogroup CAN
 *  @{
 */
 
/* CAN Interface Functions */

void   canInit(void);
uint32 canTransmit(canBASE_t *node, uint32 messageBox, const uint8 * data);
uint32 canGetData(canBASE_t *node, uint32 messageBox, uint8 * const data);
uint32 canGetID(canBASE_t *node, uint32 messageBox);
void canUpdateID(canBASE_t *node, uint32 messageBox, uint32 msgBoxArbitVal);
uint32 canSendRemoteFrame(canBASE_t *node, uint32 messageBox);
uint32 canFillMessageObjectData(canBASE_t *node, uint32 messageBox, const uint8 * data);
uint32 canIsTxMessagePending(canBASE_t *node, uint32 messageBox);
uint32 canIsRxMessageArrived(canBASE_t *node, uint32 messageBox);
uint32 canIsMessageBoxValid(canBASE_t *node, uint32 messageBox);
uint32 canGetLastError(canBASE_t *node);
uint32 canGetErrorLevel(canBASE_t *node);
void   canEnableErrorNotification(canBASE_t *node);
void   canDisableErrorNotification(canBASE_t *node);
void   canEnableStatusChangeNotification(canBASE_t *node);
void   canDisableStatusChangeNotification(canBASE_t *node);
void   canEnableloopback(canBASE_t *node, canloopBackType_t Loopbacktype);
void   canDisableloopback(canBASE_t *node);
void   canIoSetDirection(canBASE_t *node,uint32 TxDir,uint32 RxDir);
void   canIoSetPort(canBASE_t *node, uint32 TxValue, uint32 RxValue);
uint32 canIoTxGetBit(canBASE_t *node);
uint32 canIoRxGetBit(canBASE_t *node);
#if %%SYSTEM:CAN1_ENABLE%%
void can1GetConfigValue(can_config_reg_t *config_reg, config_value_type_t type);
#endif
#if %%SYSTEM:CAN2_ENABLE%%
void can2GetConfigValue(can_config_reg_t *config_reg, config_value_type_t type);
#endif
#if %%SYSTEM:CAN3_ENABLE%%
void can3GetConfigValue(can_config_reg_t *config_reg, config_value_type_t type);
#endif
#if %%SYSTEM:CAN4_ENABLE%%
void can4GetConfigValue(can_config_reg_t *config_reg, config_value_type_t type);
#endif
/** @fn void canErrorNotification(canBASE_t *node, uint32 notification)
*   @brief Error notification
*   @param[in] node Pointer to CAN node:
*              - canREG1: CAN1 node pointer
*              - canREG2: CAN2 node pointer
*              - canREG3: CAN3 node pointer
*   @param[in] notification Error notification code:
*           - canLEVEL_PASSIVE    (0x20) : When RX- or TX error counter are between 32 and 63     
*           - canLEVEL_WARNING (0x40): When RX- or TX error counter are between 96 and 127     
*           - canLEVEL_BUS_OFF (0x80): When RX- or TX error counter are above 255     
*           - canLEVEL_PARITY_ERR (0x100): When RX- or TX error counter are above 256
*
*   @note This function has to be provide by the user.
*/
void canErrorNotification(canBASE_t *node, uint32 notification);

/** @fn void canStatusChangeNotification(canBASE_t *node, uint32 notification)
*   @brief Status Change notification
*   @param[in] node Pointer to CAN node:
*              - canREG1: CAN1 node pointer
*              - canREG2: CAN2 node pointer
*              - canREG3: CAN3 node pointer
*   @param[in] notification Status change notification code:
*           - canLEVEL_TxOK      (0x08) : When sucessful transmission     
*           - canLEVEL_RxOK      (0x10) : When sucessful reception     
*           - canLEVEL_WakeUpPnd (0x200): When sucessful WakeUp to system initiated
*           - canLEVEL_PDA       (0x400): When sucessful low power mode entrance
*           
*   @note This function has to be provide by the user.
*/
void canStatusChangeNotification(canBASE_t *node, uint32 notification);

/** @fn void canMessageNotification(canBASE_t *node, uint32 messageBox)
*   @brief Message notification
*   @param[in] node Pointer to CAN node:
*              - canREG1: CAN1 node pointer
*              - canREG2: CAN2 node pointer
*              - canREG3: CAN3 node pointer
*   @param[in] messageBox Message box number of CAN node:
*              - canMESSAGE_BOX1: CAN message box 1
*              - canMESSAGE_BOXn: CAN message box n [n: 1-64]
*              - canMESSAGE_BOX64: CAN message box 64
*
*   @note This function has to be provide by the user.
*/
void canMessageNotification(canBASE_t *node, uint32 messageBox);

@@USERCODE

/**@}*/
#ifdef __cplusplus
}
#endif

#endif
