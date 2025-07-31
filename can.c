/** @file HL_can.c 
*   @brief CAN Driver Source File
*   @date 11-Dec-2018
*   @version 04.07.01
*
*   This file contains:
*   - API Functions
*   - Interrupt Handlers
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


#if %%SYSTEM:CAN_ENABLE%%

@@USERCODE


/* Include Files */

#include "%%HDRCAN%%"
#if %%TOOLS:TI%%
#include "HL_sys_vim.h"
#endif
#if %%TOOLS:GCC%%
#include "HL_sys_vim.h"
#endif

@@USERCODE


/* Global and Static Variables */

#if ((__little_endian__ == 1) || (__LITTLE_ENDIAN__ == 1))
#else
    static const uint32 s_canByteOrder[8U] = {3U, 2U, 1U, 0U, 7U, 6U, 5U, 4U};
#endif

@@USERCODE


/**
 * @brief CAN modülünü başlatır ve genel ayarları yapar.
 * @param void Herhangi bir parametre almaz.
 * @retval void Geriye bir değer döndürmez.
 * @req [REQ-CAN-001]
 */
@@USERCODE
void canInit(void)
{
@@USERCODE  
#if %%SYSTEM:CAN1_ENABLE%%
    /** @b Initialize @b CAN1: */

#if %%CAN1:CAN_1_PIN_MODE%%
    /** - Setup control register
    *     - Disable automatic wakeup on bus activity
    *     - Local power down mode disabled
    *     - Disable DMA request lines
    *     - Enable global Interrupt Line 0 and 1
    *     - Disable debug mode
    *     - Release from software reset
    *     - Enable/Disable parity or ECC
    *     - Enable/Disable auto bus on timer
    *     - Setup message completion before entering debug state
    *     - Setup normal operation mode
    *     - Request write access to the configuration registers
    *     - Setup automatic retransmission of messages
    *     - Disable error interrupts
    *     - Disable status interrupts
    *     - Enter initialization mode
    */
    canREG1->CTL = (uint32)%%CAN1:CAN_1_AUTO_BUS_ON%%U 
                 | (uint32)%%CAN1:CAN_1_AUTO_RETRANSMISSION%%U 
                 | (uint32)((uint32)%%CAN1:CAN_1_RAM_PARITY_ENA%%U  << 10U)
                 | (uint32)0x00020043U;

    /** - Clear all pending error flags and reset current status */
    canREG1->ES |= 0xFFFFFFFFU;

    /** - Assign interrupt level for messages */
    canREG1->INTMUXx[0U] = (uint32)%%CAN1:CAN_1_MESSAGE_64_INT_LEVEL%%U
                         | (uint32)%%CAN1:CAN_1_MESSAGE_1_INT_LEVEL%%U
                         | (uint32)%%CAN1:CAN_1_MESSAGE_2_INT_LEVEL%%U
                         | (uint32)%%CAN1:CAN_1_MESSAGE_3_INT_LEVEL%%U
                         | (uint32)%%CAN1:CAN_1_MESSAGE_4_INT_LEVEL%%U
                         | (uint32)%%CAN1:CAN_1_MESSAGE_5_INT_LEVEL%%U
                         | (uint32)%%CAN1:CAN_1_MESSAGE_6_INT_LEVEL%%U
                         | (uint32)%%CAN1:CAN_1_MESSAGE_7_INT_LEVEL%%U
                         | (uint32)%%CAN1:CAN_1_MESSAGE_8_INT_LEVEL%%U
                         | (uint32)%%CAN1:CAN_1_MESSAGE_9_INT_LEVEL%%U
                         | (uint32)%%CAN1:CAN_1_MESSAGE_10_INT_LEVEL%%U
                         | (uint32)%%CAN1:CAN_1_MESSAGE_11_INT_LEVEL%%U
                         | (uint32)%%CAN1:CAN_1_MESSAGE_12_INT_LEVEL%%U
                         | (uint32)%%CAN1:CAN_1_MESSAGE_13_INT_LEVEL%%U
                         | (uint32)%%CAN1:CAN_1_MESSAGE_14_INT_LEVEL%%U
                         | (uint32)%%CAN1:CAN_1_MESSAGE_15_INT_LEVEL%%U
                         | (uint32)%%CAN1:CAN_1_MESSAGE_16_INT_LEVEL%%U
                         | (uint32)%%CAN1:CAN_1_MESSAGE_17_INT_LEVEL%%U
                         | (uint32)%%CAN1:CAN_1_MESSAGE_18_INT_LEVEL%%U
                         | (uint32)%%CAN1:CAN_1_MESSAGE_19_INT_LEVEL%%U
                         | (uint32)%%CAN1:CAN_1_MESSAGE_20_INT_LEVEL%%U
                         | (uint32)%%CAN1:CAN_1_MESSAGE_21_INT_LEVEL%%U
                         | (uint32)%%CAN1:CAN_1_MESSAGE_22_INT_LEVEL%%U
                         | (uint32)%%CAN1:CAN_1_MESSAGE_23_INT_LEVEL%%U
                         | (uint32)%%CAN1:CAN_1_MESSAGE_24_INT_LEVEL%%U
                         | (uint32)%%CAN1:CAN_1_MESSAGE_25_INT_LEVEL%%U
                         | (uint32)%%CAN1:CAN_1_MESSAGE_26_INT_LEVEL%%U
                         | (uint32)%%CAN1:CAN_1_MESSAGE_27_INT_LEVEL%%U
                         | (uint32)%%CAN1:CAN_1_MESSAGE_28_INT_LEVEL%%U
                         | (uint32)%%CAN1:CAN_1_MESSAGE_29_INT_LEVEL%%U
                         | (uint32)%%CAN1:CAN_1_MESSAGE_30_INT_LEVEL%%U
                         | (uint32)%%CAN1:CAN_1_MESSAGE_31_INT_LEVEL%%U;

    canREG1->INTMUXx[1U] = (uint32)%%CAN1:CAN_1_MESSAGE_32_INT_LEVEL%%U
                         | (uint32)%%CAN1:CAN_1_MESSAGE_33_INT_LEVEL%%U
                         | (uint32)%%CAN1:CAN_1_MESSAGE_34_INT_LEVEL%%U
                         | (uint32)%%CAN1:CAN_1_MESSAGE_35_INT_LEVEL%%U
                         | (uint32)%%CAN1:CAN_1_MESSAGE_36_INT_LEVEL%%U
                         | (uint32)%%CAN1:CAN_1_MESSAGE_37_INT_LEVEL%%U
                         | (uint32)%%CAN1:CAN_1_MESSAGE_38_INT_LEVEL%%U
                         | (uint32)%%CAN1:CAN_1_MESSAGE_39_INT_LEVEL%%U
                         | (uint32)%%CAN1:CAN_1_MESSAGE_40_INT_LEVEL%%U
                         | (uint32)%%CAN1:CAN_1_MESSAGE_41_INT_LEVEL%%U
                         | (uint32)%%CAN1:CAN_1_MESSAGE_42_INT_LEVEL%%U
                         | (uint32)%%CAN1:CAN_1_MESSAGE_43_INT_LEVEL%%U
                         | (uint32)%%CAN1:CAN_1_MESSAGE_44_INT_LEVEL%%U
                         | (uint32)%%CAN1:CAN_1_MESSAGE_45_INT_LEVEL%%U
                         | (uint32)%%CAN1:CAN_1_MESSAGE_46_INT_LEVEL%%U
                         | (uint32)%%CAN1:CAN_1_MESSAGE_47_INT_LEVEL%%U
                         | (uint32)%%CAN1:CAN_1_MESSAGE_48_INT_LEVEL%%U
                         | (uint32)%%CAN1:CAN_1_MESSAGE_49_INT_LEVEL%%U
                         | (uint32)%%CAN1:CAN_1_MESSAGE_50_INT_LEVEL%%U
                         | (uint32)%%CAN1:CAN_1_MESSAGE_51_INT_LEVEL%%U
                         | (uint32)%%CAN1:CAN_1_MESSAGE_52_INT_LEVEL%%U
                         | (uint32)%%CAN1:CAN_1_MESSAGE_53_INT_LEVEL%%U
                         | (uint32)%%CAN1:CAN_1_MESSAGE_54_INT_LEVEL%%U
                         | (uint32)%%CAN1:CAN_1_MESSAGE_55_INT_LEVEL%%U
                         | (uint32)%%CAN1:CAN_1_MESSAGE_56_INT_LEVEL%%U
                         | (uint32)%%CAN1:CAN_1_MESSAGE_57_INT_LEVEL%%U
                         | (uint32)%%CAN1:CAN_1_MESSAGE_58_INT_LEVEL%%U
                         | (uint32)%%CAN1:CAN_1_MESSAGE_59_INT_LEVEL%%U
                         | (uint32)%%CAN1:CAN_1_MESSAGE_60_INT_LEVEL%%U
                         | (uint32)%%CAN1:CAN_1_MESSAGE_61_INT_LEVEL%%U
                         | (uint32)%%CAN1:CAN_1_MESSAGE_62_INT_LEVEL%%U
                         | (uint32)%%CAN1:CAN_1_MESSAGE_63_INT_LEVEL%%U;

    /** - Setup auto bus on timer period */
    canREG1->ABOTR = (uint32)%%CAN1:CAN_1_AUTO_BUS_ON_TR%%U;

#if %%CAN1:CAN_1_MESSAGE_1_BOOL_ENA%%
    /** - Initialize message 1 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG1->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */


    canREG1->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_1_MASK%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF1ARB  = (uint32)%%CAN1:CAN_1_MESSAGE_1_ENA%%U | (uint32)%%CAN1:CAN_1_IDENTIFIER_MODE%%U | (uint32)%%CAN1:CAN_1_MESSAGE_1_DIR%%U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_1_ID%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF1MCTL = 0x00001000U | (uint32)%%CAN1:CAN_1_MESSAGE_1_INT_ENA%%U | (uint32)%%CAN1:CAN_1_MESSAGE_1_RTR%%U | (uint32)%%CAN1:CAN_1_MESSAGE_1_EOB%%U | (uint32)%%CAN1:CAN_1_MESSAGE_1_DLC%%U;
    canREG1->IF1CMD  = (uint8) 0xF8U;
    canREG1->IF1NO   = 1U;

#endif
#if %%CAN1:CAN_1_MESSAGE_2_BOOL_ENA%%
    /** - Initialize message 2 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG1->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG1->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_2_MASK%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF2ARB  = (uint32)%%CAN1:CAN_1_MESSAGE_2_ENA%%U | (uint32)%%CAN1:CAN_1_IDENTIFIER_MODE%%U | (uint32)%%CAN1:CAN_1_MESSAGE_2_DIR%%U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_2_ID%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF2MCTL = 0x00001000U | (uint32)%%CAN1:CAN_1_MESSAGE_2_INT_ENA%%U | (uint32)%%CAN1:CAN_1_MESSAGE_2_RTR%%U | (uint32)%%CAN1:CAN_1_MESSAGE_2_EOB%%U | (uint32)%%CAN1:CAN_1_MESSAGE_2_DLC%%U;
    canREG1->IF2CMD  = (uint8) 0xF8U;
    canREG1->IF2NO   = 2U;

#endif
#if %%CAN1:CAN_1_MESSAGE_3_BOOL_ENA%%
    /** - Initialize message 3 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG1->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG1->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_3_MASK%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF1ARB  = (uint32)%%CAN1:CAN_1_MESSAGE_3_ENA%%U | (uint32)%%CAN1:CAN_1_IDENTIFIER_MODE%%U | (uint32)%%CAN1:CAN_1_MESSAGE_3_DIR%%U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_3_ID%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF1MCTL = 0x00001000U | (uint32)%%CAN1:CAN_1_MESSAGE_3_INT_ENA%%U | (uint32)%%CAN1:CAN_1_MESSAGE_3_RTR%%U | (uint32)%%CAN1:CAN_1_MESSAGE_3_EOB%%U | (uint32)%%CAN1:CAN_1_MESSAGE_3_DLC%%U;
    canREG1->IF1CMD  = (uint8) 0xF8U;
    canREG1->IF1NO   = 3U;

#endif
#if %%CAN1:CAN_1_MESSAGE_4_BOOL_ENA%%
    /** - Initialize message 4 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG1->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG1->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_4_MASK%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF2ARB  = (uint32)%%CAN1:CAN_1_MESSAGE_4_ENA%%U | (uint32)%%CAN1:CAN_1_IDENTIFIER_MODE%%U | (uint32)%%CAN1:CAN_1_MESSAGE_4_DIR%%U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_4_ID%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF2MCTL = 0x00001000U | (uint32)%%CAN1:CAN_1_MESSAGE_4_INT_ENA%%U | (uint32)%%CAN1:CAN_1_MESSAGE_4_RTR%%U | (uint32)%%CAN1:CAN_1_MESSAGE_4_EOB%%U | (uint32)%%CAN1:CAN_1_MESSAGE_4_DLC%%U;
    canREG1->IF2CMD  = (uint8) 0xF8U;
    canREG1->IF2NO   = 4U;

#endif
#if %%CAN1:CAN_1_MESSAGE_5_BOOL_ENA%%
    /** - Initialize message 5 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG1->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG1->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_5_MASK%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF1ARB  = (uint32)%%CAN1:CAN_1_MESSAGE_5_ENA%%U | (uint32)%%CAN1:CAN_1_IDENTIFIER_MODE%%U | (uint32)%%CAN1:CAN_1_MESSAGE_5_DIR%%U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_5_ID%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF1MCTL = 0x00001000U | (uint32)%%CAN1:CAN_1_MESSAGE_5_INT_ENA%%U | (uint32)%%CAN1:CAN_1_MESSAGE_5_RTR%%U | (uint32)%%CAN1:CAN_1_MESSAGE_5_EOB%%U | (uint32)%%CAN1:CAN_1_MESSAGE_5_DLC%%U;
    canREG1->IF1CMD  = (uint8) 0xF8U;
    canREG1->IF1NO   = 5U;

#endif
#if %%CAN1:CAN_1_MESSAGE_6_BOOL_ENA%%
    /** - Initialize message 6 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG1->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG1->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_6_MASK%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF2ARB  = (uint32)%%CAN1:CAN_1_MESSAGE_6_ENA%%U | (uint32)%%CAN1:CAN_1_IDENTIFIER_MODE%%U | (uint32)%%CAN1:CAN_1_MESSAGE_6_DIR%%U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_6_ID%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF2MCTL = 0x00001000U | (uint32)%%CAN1:CAN_1_MESSAGE_6_INT_ENA%%U | (uint32)%%CAN1:CAN_1_MESSAGE_6_RTR%%U | (uint32)%%CAN1:CAN_1_MESSAGE_6_EOB%%U | (uint32)%%CAN1:CAN_1_MESSAGE_6_DLC%%U;
    canREG1->IF2CMD  = (uint8) 0xF8U;
    canREG1->IF2NO   = 6U;

#endif
#if %%CAN1:CAN_1_MESSAGE_7_BOOL_ENA%%
    /** - Initialize message 7 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG1->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG1->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_7_MASK%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF1ARB  = (uint32)%%CAN1:CAN_1_MESSAGE_7_ENA%%U | (uint32)%%CAN1:CAN_1_IDENTIFIER_MODE%%U | (uint32)%%CAN1:CAN_1_MESSAGE_7_DIR%%U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_7_ID%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF1MCTL = 0x00001000U | (uint32)%%CAN1:CAN_1_MESSAGE_7_INT_ENA%%U | (uint32)%%CAN1:CAN_1_MESSAGE_7_RTR%%U | (uint32)%%CAN1:CAN_1_MESSAGE_7_EOB%%U | (uint32)%%CAN1:CAN_1_MESSAGE_7_DLC%%U;
    canREG1->IF1CMD  = (uint8) 0xF8U;
    canREG1->IF1NO   = 7U;

#endif
#if %%CAN1:CAN_1_MESSAGE_8_BOOL_ENA%%
    /** - Initialize message 8 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG1->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG1->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_8_MASK%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF2ARB  = (uint32)%%CAN1:CAN_1_MESSAGE_8_ENA%%U | (uint32)%%CAN1:CAN_1_IDENTIFIER_MODE%%U | (uint32)%%CAN1:CAN_1_MESSAGE_8_DIR%%U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_8_ID%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF2MCTL = 0x00001000U | (uint32)%%CAN1:CAN_1_MESSAGE_8_INT_ENA%%U | (uint32)%%CAN1:CAN_1_MESSAGE_8_RTR%%U | (uint32)%%CAN1:CAN_1_MESSAGE_8_EOB%%U | (uint32)%%CAN1:CAN_1_MESSAGE_8_DLC%%U;
    canREG1->IF2CMD  = (uint8) 0xF8U;
    canREG1->IF2NO   = 8U;

#endif
#if %%CAN1:CAN_1_MESSAGE_9_BOOL_ENA%%
    /** - Initialize message 9 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG1->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG1->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_9_MASK%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF1ARB  = (uint32)%%CAN1:CAN_1_MESSAGE_9_ENA%%U | (uint32)%%CAN1:CAN_1_IDENTIFIER_MODE%%U | (uint32)%%CAN1:CAN_1_MESSAGE_9_DIR%%U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_9_ID%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF1MCTL = 0x00001000U | (uint32)%%CAN1:CAN_1_MESSAGE_9_INT_ENA%%U | (uint32)%%CAN1:CAN_1_MESSAGE_9_RTR%%U | (uint32)%%CAN1:CAN_1_MESSAGE_9_EOB%%U | (uint32)%%CAN1:CAN_1_MESSAGE_9_DLC%%U;
    canREG1->IF1CMD  = (uint8) 0xF8U;
    canREG1->IF1NO   = 9U;

#endif
#if %%CAN1:CAN_1_MESSAGE_10_BOOL_ENA%%
    /** - Initialize message 10 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG1->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG1->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_10_MASK%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF2ARB  = (uint32)%%CAN1:CAN_1_MESSAGE_10_ENA%%U | (uint32)%%CAN1:CAN_1_IDENTIFIER_MODE%%U | (uint32)%%CAN1:CAN_1_MESSAGE_10_DIR%%U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_10_ID%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF2MCTL = 0x00001000U | (uint32)%%CAN1:CAN_1_MESSAGE_10_INT_ENA%%U | (uint32)%%CAN1:CAN_1_MESSAGE_10_RTR%%U | (uint32)%%CAN1:CAN_1_MESSAGE_10_EOB%%U | (uint32)%%CAN1:CAN_1_MESSAGE_10_DLC%%U;
    canREG1->IF2CMD  = (uint8) 0xF8U;
    canREG1->IF2NO   = 10U;

#endif
#if %%CAN1:CAN_1_MESSAGE_11_BOOL_ENA%%
    /** - Initialize message 11 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG1->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG1->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_11_MASK%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF1ARB  = (uint32)%%CAN1:CAN_1_MESSAGE_11_ENA%%U | (uint32)%%CAN1:CAN_1_IDENTIFIER_MODE%%U | (uint32)%%CAN1:CAN_1_MESSAGE_11_DIR%%U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_11_ID%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF1MCTL = 0x00001000U | (uint32)%%CAN1:CAN_1_MESSAGE_11_INT_ENA%%U | (uint32)%%CAN1:CAN_1_MESSAGE_11_RTR%%U | (uint32)%%CAN1:CAN_1_MESSAGE_11_EOB%%U | (uint32)%%CAN1:CAN_1_MESSAGE_11_DLC%%U;
    canREG1->IF1CMD  = (uint8) 0xF8U;
    canREG1->IF1NO   = 11U;

#endif
#if %%CAN1:CAN_1_MESSAGE_12_BOOL_ENA%%
    /** - Initialize message 12 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG1->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG1->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_12_MASK%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF2ARB  = (uint32)%%CAN1:CAN_1_MESSAGE_12_ENA%%U | (uint32)%%CAN1:CAN_1_IDENTIFIER_MODE%%U | (uint32)%%CAN1:CAN_1_MESSAGE_12_DIR%%U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_12_ID%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF2MCTL = 0x00001000U | (uint32)%%CAN1:CAN_1_MESSAGE_12_INT_ENA%%U | (uint32)%%CAN1:CAN_1_MESSAGE_12_RTR%%U | (uint32)%%CAN1:CAN_1_MESSAGE_12_EOB%%U | (uint32)%%CAN1:CAN_1_MESSAGE_12_DLC%%U;
    canREG1->IF2CMD  = (uint8) 0xF8U;
    canREG1->IF2NO   = 12U;

#endif
#if %%CAN1:CAN_1_MESSAGE_13_BOOL_ENA%%
    /** - Initialize message 13 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG1->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG1->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_13_MASK%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF1ARB  = (uint32)%%CAN1:CAN_1_MESSAGE_13_ENA%%U | (uint32)%%CAN1:CAN_1_IDENTIFIER_MODE%%U | (uint32)%%CAN1:CAN_1_MESSAGE_13_DIR%%U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_13_ID%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF1MCTL = 0x00001000U | (uint32)%%CAN1:CAN_1_MESSAGE_13_INT_ENA%%U | (uint32)%%CAN1:CAN_1_MESSAGE_13_RTR%%U | (uint32)%%CAN1:CAN_1_MESSAGE_13_EOB%%U | (uint32)%%CAN1:CAN_1_MESSAGE_13_DLC%%U;
    canREG1->IF1CMD  = (uint8) 0xF8U;
    canREG1->IF1NO   = 13U;

#endif
#if %%CAN1:CAN_1_MESSAGE_14_BOOL_ENA%%
    /** - Initialize message 14 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG1->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG1->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_14_MASK%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF2ARB  = (uint32)%%CAN1:CAN_1_MESSAGE_14_ENA%%U | (uint32)%%CAN1:CAN_1_IDENTIFIER_MODE%%U | (uint32)%%CAN1:CAN_1_MESSAGE_14_DIR%%U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_14_ID%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF2MCTL = 0x00001000U | (uint32)%%CAN1:CAN_1_MESSAGE_14_INT_ENA%%U | (uint32)%%CAN1:CAN_1_MESSAGE_14_RTR%%U | (uint32)%%CAN1:CAN_1_MESSAGE_14_EOB%%U | (uint32)%%CAN1:CAN_1_MESSAGE_14_DLC%%U;
    canREG1->IF2CMD  = (uint8) 0xF8U;
    canREG1->IF2NO   = 14U;

#endif
#if %%CAN1:CAN_1_MESSAGE_15_BOOL_ENA%%
    /** - Initialize message 15 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG1->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG1->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_15_MASK%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF1ARB  = (uint32)%%CAN1:CAN_1_MESSAGE_15_ENA%%U | (uint32)%%CAN1:CAN_1_IDENTIFIER_MODE%%U | (uint32)%%CAN1:CAN_1_MESSAGE_15_DIR%%U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_15_ID%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF1MCTL = 0x00001000U | (uint32)%%CAN1:CAN_1_MESSAGE_15_INT_ENA%%U | (uint32)%%CAN1:CAN_1_MESSAGE_15_RTR%%U | (uint32)%%CAN1:CAN_1_MESSAGE_15_EOB%%U | (uint32)%%CAN1:CAN_1_MESSAGE_15_DLC%%U;
    canREG1->IF1CMD  = (uint8) 0xF8U;
    canREG1->IF1NO   = 15U;

#endif
#if %%CAN1:CAN_1_MESSAGE_16_BOOL_ENA%%
    /** - Initialize message 16 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG1->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG1->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_16_MASK%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF2ARB  = (uint32)%%CAN1:CAN_1_MESSAGE_16_ENA%%U | (uint32)%%CAN1:CAN_1_IDENTIFIER_MODE%%U | (uint32)%%CAN1:CAN_1_MESSAGE_16_DIR%%U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_16_ID%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF2MCTL = 0x00001000U | (uint32)%%CAN1:CAN_1_MESSAGE_16_INT_ENA%%U | (uint32)%%CAN1:CAN_1_MESSAGE_16_RTR%%U | (uint32)%%CAN1:CAN_1_MESSAGE_16_EOB%%U | (uint32)%%CAN1:CAN_1_MESSAGE_16_DLC%%U;
    canREG1->IF2CMD  = (uint8) 0xF8U;
    canREG1->IF2NO   = 16U;

#endif
#if %%CAN1:CAN_1_MESSAGE_17_BOOL_ENA%%
    /** - Initialize message 17 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG1->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG1->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_17_MASK%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF1ARB  = (uint32)%%CAN1:CAN_1_MESSAGE_17_ENA%%U | (uint32)%%CAN1:CAN_1_IDENTIFIER_MODE%%U | (uint32)%%CAN1:CAN_1_MESSAGE_17_DIR%%U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_17_ID%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF1MCTL = 0x00001000U | (uint32)%%CAN1:CAN_1_MESSAGE_17_INT_ENA%%U | (uint32)%%CAN1:CAN_1_MESSAGE_17_RTR%%U | (uint32)%%CAN1:CAN_1_MESSAGE_17_EOB%%U | (uint32)%%CAN1:CAN_1_MESSAGE_17_DLC%%U;
    canREG1->IF1CMD  = (uint8) 0xF8U;
    canREG1->IF1NO   = 17U;

#endif
#if %%CAN1:CAN_1_MESSAGE_18_BOOL_ENA%%
    /** - Initialize message 18 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG1->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG1->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_18_MASK%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF2ARB  = (uint32)%%CAN1:CAN_1_MESSAGE_18_ENA%%U | (uint32)%%CAN1:CAN_1_IDENTIFIER_MODE%%U | (uint32)%%CAN1:CAN_1_MESSAGE_18_DIR%%U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_18_ID%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF2MCTL = 0x00001000U | (uint32)%%CAN1:CAN_1_MESSAGE_18_INT_ENA%%U | (uint32)%%CAN1:CAN_1_MESSAGE_18_RTR%%U | (uint32)%%CAN1:CAN_1_MESSAGE_18_EOB%%U | (uint32)%%CAN1:CAN_1_MESSAGE_18_DLC%%U;
    canREG1->IF2CMD  = (uint8) 0xF8U;
    canREG1->IF2NO   = 18U;

#endif
#if %%CAN1:CAN_1_MESSAGE_19_BOOL_ENA%%
    /** - Initialize message 19 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG1->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG1->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_19_MASK%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF1ARB  = (uint32)%%CAN1:CAN_1_MESSAGE_19_ENA%%U | (uint32)%%CAN1:CAN_1_IDENTIFIER_MODE%%U | (uint32)%%CAN1:CAN_1_MESSAGE_19_DIR%%U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_19_ID%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF1MCTL = 0x00001000U | (uint32)%%CAN1:CAN_1_MESSAGE_19_INT_ENA%%U | (uint32)%%CAN1:CAN_1_MESSAGE_19_RTR%%U | (uint32)%%CAN1:CAN_1_MESSAGE_19_EOB%%U | (uint32)%%CAN1:CAN_1_MESSAGE_19_DLC%%U;
    canREG1->IF1CMD  = (uint8) 0xF8U;
    canREG1->IF1NO   = 19U;

#endif
#if %%CAN1:CAN_1_MESSAGE_20_BOOL_ENA%%
    /** - Initialize message 20 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG1->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG1->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_20_MASK%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF2ARB  = (uint32)%%CAN1:CAN_1_MESSAGE_20_ENA%%U | (uint32)%%CAN1:CAN_1_IDENTIFIER_MODE%%U | (uint32)%%CAN1:CAN_1_MESSAGE_20_DIR%%U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_20_ID%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF2MCTL = 0x00001000U | (uint32)%%CAN1:CAN_1_MESSAGE_20_INT_ENA%%U | (uint32)%%CAN1:CAN_1_MESSAGE_20_RTR%%U | (uint32)%%CAN1:CAN_1_MESSAGE_20_EOB%%U | (uint32)%%CAN1:CAN_1_MESSAGE_20_DLC%%U;
    canREG1->IF2CMD  = (uint8) 0xF8U;
    canREG1->IF2NO   = 20U;

#endif
#if %%CAN1:CAN_1_MESSAGE_21_BOOL_ENA%%
    /** - Initialize message 21 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG1->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG1->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_21_MASK%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF1ARB  = (uint32)%%CAN1:CAN_1_MESSAGE_21_ENA%%U | (uint32)%%CAN1:CAN_1_IDENTIFIER_MODE%%U | (uint32)%%CAN1:CAN_1_MESSAGE_21_DIR%%U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_21_ID%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF1MCTL = 0x00001000U | (uint32)%%CAN1:CAN_1_MESSAGE_21_INT_ENA%%U | (uint32)%%CAN1:CAN_1_MESSAGE_21_RTR%%U | (uint32)%%CAN1:CAN_1_MESSAGE_21_EOB%%U | (uint32)%%CAN1:CAN_1_MESSAGE_21_DLC%%U;
    canREG1->IF1CMD  = (uint8) 0xF8U;
    canREG1->IF1NO   = 21U;

#endif
#if %%CAN1:CAN_1_MESSAGE_22_BOOL_ENA%%
    /** - Initialize message 22 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG1->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG1->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_22_MASK%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF2ARB  = (uint32)%%CAN1:CAN_1_MESSAGE_22_ENA%%U | (uint32)%%CAN1:CAN_1_IDENTIFIER_MODE%%U | (uint32)%%CAN1:CAN_1_MESSAGE_22_DIR%%U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_22_ID%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF2MCTL = 0x00001000U | (uint32)%%CAN1:CAN_1_MESSAGE_22_INT_ENA%%U | (uint32)%%CAN1:CAN_1_MESSAGE_22_RTR%%U | (uint32)%%CAN1:CAN_1_MESSAGE_22_EOB%%U | (uint32)%%CAN1:CAN_1_MESSAGE_22_DLC%%U;
    canREG1->IF2CMD  = (uint8) 0xF8U;
    canREG1->IF2NO   = 22U;

#endif
#if %%CAN1:CAN_1_MESSAGE_23_BOOL_ENA%%
    /** - Initialize message 23 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG1->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG1->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_23_MASK%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF1ARB  = (uint32)%%CAN1:CAN_1_MESSAGE_23_ENA%%U | (uint32)%%CAN1:CAN_1_IDENTIFIER_MODE%%U | (uint32)%%CAN1:CAN_1_MESSAGE_23_DIR%%U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_23_ID%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF1MCTL = 0x00001000U | (uint32)%%CAN1:CAN_1_MESSAGE_23_INT_ENA%%U | (uint32)%%CAN1:CAN_1_MESSAGE_23_RTR%%U | (uint32)%%CAN1:CAN_1_MESSAGE_23_EOB%%U | (uint32)%%CAN1:CAN_1_MESSAGE_23_DLC%%U;
    canREG1->IF1CMD  = (uint8) 0xF8U;
    canREG1->IF1NO   = 23U;

#endif
#if %%CAN1:CAN_1_MESSAGE_24_BOOL_ENA%%
    /** - Initialize message 24 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG1->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG1->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_24_MASK%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF2ARB  = (uint32)%%CAN1:CAN_1_MESSAGE_24_ENA%%U | (uint32)%%CAN1:CAN_1_IDENTIFIER_MODE%%U | (uint32)%%CAN1:CAN_1_MESSAGE_24_DIR%%U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_24_ID%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF2MCTL = 0x00001000U | (uint32)%%CAN1:CAN_1_MESSAGE_24_INT_ENA%%U | (uint32)%%CAN1:CAN_1_MESSAGE_24_RTR%%U | (uint32)%%CAN1:CAN_1_MESSAGE_24_EOB%%U | (uint32)%%CAN1:CAN_1_MESSAGE_24_DLC%%U;
    canREG1->IF2CMD  = (uint8) 0xF8U;
    canREG1->IF2NO   = 24U;

#endif
#if %%CAN1:CAN_1_MESSAGE_25_BOOL_ENA%%
    /** - Initialize message 25 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG1->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG1->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_25_MASK%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF1ARB  = (uint32)%%CAN1:CAN_1_MESSAGE_25_ENA%%U | (uint32)%%CAN1:CAN_1_IDENTIFIER_MODE%%U | (uint32)%%CAN1:CAN_1_MESSAGE_25_DIR%%U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_25_ID%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF1MCTL = 0x00001000U | (uint32)%%CAN1:CAN_1_MESSAGE_25_INT_ENA%%U | (uint32)%%CAN1:CAN_1_MESSAGE_25_RTR%%U | (uint32)%%CAN1:CAN_1_MESSAGE_25_EOB%%U | (uint32)%%CAN1:CAN_1_MESSAGE_25_DLC%%U;
    canREG1->IF1CMD  = (uint8) 0xF8U;
    canREG1->IF1NO   = 25U;

#endif
#if %%CAN1:CAN_1_MESSAGE_26_BOOL_ENA%%
    /** - Initialize message 26 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG1->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG1->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_26_MASK%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF2ARB  = (uint32)%%CAN1:CAN_1_MESSAGE_26_ENA%%U | (uint32)%%CAN1:CAN_1_IDENTIFIER_MODE%%U | (uint32)%%CAN1:CAN_1_MESSAGE_26_DIR%%U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_26_ID%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF2MCTL = 0x00001000U | (uint32)%%CAN1:CAN_1_MESSAGE_26_INT_ENA%%U | (uint32)%%CAN1:CAN_1_MESSAGE_26_RTR%%U | (uint32)%%CAN1:CAN_1_MESSAGE_26_EOB%%U | (uint32)%%CAN1:CAN_1_MESSAGE_26_DLC%%U;
    canREG1->IF2CMD  = (uint8) 0xF8U;
    canREG1->IF2NO   = 26U;

#endif
#if %%CAN1:CAN_1_MESSAGE_27_BOOL_ENA%%
    /** - Initialize message 27 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG1->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG1->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_27_MASK%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF1ARB  = (uint32)%%CAN1:CAN_1_MESSAGE_27_ENA%%U | (uint32)%%CAN1:CAN_1_IDENTIFIER_MODE%%U | (uint32)%%CAN1:CAN_1_MESSAGE_27_DIR%%U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_27_ID%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF1MCTL = 0x00001000U | (uint32)%%CAN1:CAN_1_MESSAGE_27_INT_ENA%%U | (uint32)%%CAN1:CAN_1_MESSAGE_27_RTR%%U | (uint32)%%CAN1:CAN_1_MESSAGE_27_EOB%%U | (uint32)%%CAN1:CAN_1_MESSAGE_27_DLC%%U;
    canREG1->IF1CMD  = (uint8) 0xF8U;
    canREG1->IF1NO   = 27U;

#endif
#if %%CAN1:CAN_1_MESSAGE_28_BOOL_ENA%%
    /** - Initialize message 28 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG1->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG1->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_28_MASK%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF2ARB  = (uint32)%%CAN1:CAN_1_MESSAGE_28_ENA%%U | (uint32)%%CAN1:CAN_1_IDENTIFIER_MODE%%U | (uint32)%%CAN1:CAN_1_MESSAGE_28_DIR%%U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_28_ID%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF2MCTL = 0x00001000U | (uint32)%%CAN1:CAN_1_MESSAGE_28_INT_ENA%%U | (uint32)%%CAN1:CAN_1_MESSAGE_28_RTR%%U | (uint32)%%CAN1:CAN_1_MESSAGE_28_EOB%%U | (uint32)%%CAN1:CAN_1_MESSAGE_28_DLC%%U;
    canREG1->IF2CMD  = (uint8) 0xF8U;
    canREG1->IF2NO   = 28U;

#endif
#if %%CAN1:CAN_1_MESSAGE_29_BOOL_ENA%%
    /** - Initialize message 29 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG1->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG1->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_29_MASK%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF1ARB  = (uint32)%%CAN1:CAN_1_MESSAGE_29_ENA%%U | (uint32)%%CAN1:CAN_1_IDENTIFIER_MODE%%U | (uint32)%%CAN1:CAN_1_MESSAGE_29_DIR%%U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_29_ID%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF1MCTL = 0x00001000U | (uint32)%%CAN1:CAN_1_MESSAGE_29_INT_ENA%%U | (uint32)%%CAN1:CAN_1_MESSAGE_29_RTR%%U | (uint32)%%CAN1:CAN_1_MESSAGE_29_EOB%%U | (uint32)%%CAN1:CAN_1_MESSAGE_29_DLC%%U;
    canREG1->IF1CMD  = (uint8) 0xF8U;
    canREG1->IF1NO   = 29U;

#endif
#if %%CAN1:CAN_1_MESSAGE_30_BOOL_ENA%%
    /** - Initialize message 30 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG1->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG1->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_30_MASK%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF2ARB  = (uint32)%%CAN1:CAN_1_MESSAGE_30_ENA%%U | (uint32)%%CAN1:CAN_1_IDENTIFIER_MODE%%U | (uint32)%%CAN1:CAN_1_MESSAGE_30_DIR%%U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_30_ID%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF2MCTL = 0x00001000U | (uint32)%%CAN1:CAN_1_MESSAGE_30_INT_ENA%%U | (uint32)%%CAN1:CAN_1_MESSAGE_30_RTR%%U | (uint32)%%CAN1:CAN_1_MESSAGE_30_EOB%%U | (uint32)%%CAN1:CAN_1_MESSAGE_30_DLC%%U;
    canREG1->IF2CMD  = (uint8) 0xF8U;
    canREG1->IF2NO   = 30U;

#endif
#if %%CAN1:CAN_1_MESSAGE_31_BOOL_ENA%%
    /** - Initialize message 31 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG1->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG1->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_31_MASK%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF1ARB  = (uint32)%%CAN1:CAN_1_MESSAGE_31_ENA%%U | (uint32)%%CAN1:CAN_1_IDENTIFIER_MODE%%U | (uint32)%%CAN1:CAN_1_MESSAGE_31_DIR%%U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_31_ID%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF1MCTL = 0x00001000U | (uint32)%%CAN1:CAN_1_MESSAGE_31_INT_ENA%%U | (uint32)%%CAN1:CAN_1_MESSAGE_31_RTR%%U | (uint32)%%CAN1:CAN_1_MESSAGE_31_EOB%%U | (uint32)%%CAN1:CAN_1_MESSAGE_31_DLC%%U;
    canREG1->IF1CMD  = (uint8) 0xF8U;
    canREG1->IF1NO   = 31U;

#endif
#if %%CAN1:CAN_1_MESSAGE_32_BOOL_ENA%%
    /** - Initialize message 32 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG1->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG1->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_32_MASK%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF2ARB  = (uint32)%%CAN1:CAN_1_MESSAGE_32_ENA%%U | (uint32)%%CAN1:CAN_1_IDENTIFIER_MODE%%U | (uint32)%%CAN1:CAN_1_MESSAGE_32_DIR%%U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_32_ID%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF2MCTL = 0x00001000U | (uint32)%%CAN1:CAN_1_MESSAGE_32_INT_ENA%%U | (uint32)%%CAN1:CAN_1_MESSAGE_32_RTR%%U | (uint32)%%CAN1:CAN_1_MESSAGE_32_EOB%%U | (uint32)%%CAN1:CAN_1_MESSAGE_32_DLC%%U;
    canREG1->IF2CMD  = (uint8) 0xF8U;
    canREG1->IF2NO   = 32U;

#endif
#if %%CAN1:CAN_1_MESSAGE_33_BOOL_ENA%%
    /** - Initialize message 33 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG1->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG1->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_33_MASK%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF1ARB  = (uint32)%%CAN1:CAN_1_MESSAGE_33_ENA%%U | (uint32)%%CAN1:CAN_1_IDENTIFIER_MODE%%U | (uint32)%%CAN1:CAN_1_MESSAGE_33_DIR%%U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_33_ID%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF1MCTL = 0x00001000U | (uint32)%%CAN1:CAN_1_MESSAGE_33_INT_ENA%%U | (uint32)%%CAN1:CAN_1_MESSAGE_33_RTR%%U | (uint32)%%CAN1:CAN_1_MESSAGE_33_EOB%%U | (uint32)%%CAN1:CAN_1_MESSAGE_33_DLC%%U;
    canREG1->IF1CMD  = (uint8) 0xF8U;
    canREG1->IF1NO   = 33U;

#endif
#if %%CAN1:CAN_1_MESSAGE_34_BOOL_ENA%%
    /** - Initialize message 34 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG1->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG1->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_34_MASK%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF2ARB  = (uint32)%%CAN1:CAN_1_MESSAGE_34_ENA%%U | (uint32)%%CAN1:CAN_1_IDENTIFIER_MODE%%U | (uint32)%%CAN1:CAN_1_MESSAGE_34_DIR%%U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_34_ID%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF2MCTL = 0x00001000U | (uint32)%%CAN1:CAN_1_MESSAGE_34_INT_ENA%%U | (uint32)%%CAN1:CAN_1_MESSAGE_34_RTR%%U | (uint32)%%CAN1:CAN_1_MESSAGE_34_EOB%%U | (uint32)%%CAN1:CAN_1_MESSAGE_34_DLC%%U;
    canREG1->IF2CMD  = (uint8) 0xF8U;
    canREG1->IF2NO   = 34U;

#endif
#if %%CAN1:CAN_1_MESSAGE_35_BOOL_ENA%%
    /** - Initialize message 35 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG1->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG1->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_35_MASK%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF1ARB  = (uint32)%%CAN1:CAN_1_MESSAGE_35_ENA%%U | (uint32)%%CAN1:CAN_1_IDENTIFIER_MODE%%U | (uint32)%%CAN1:CAN_1_MESSAGE_35_DIR%%U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_35_ID%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF1MCTL = 0x00001000U | (uint32)%%CAN1:CAN_1_MESSAGE_35_INT_ENA%%U | (uint32)%%CAN1:CAN_1_MESSAGE_35_RTR%%U | (uint32)%%CAN1:CAN_1_MESSAGE_35_EOB%%U | (uint32)%%CAN1:CAN_1_MESSAGE_35_DLC%%U;
    canREG1->IF1CMD  = (uint8) 0xF8U;
    canREG1->IF1NO   = 35U;

#endif
#if %%CAN1:CAN_1_MESSAGE_36_BOOL_ENA%%
    /** - Initialize message 36 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG1->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG1->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_36_MASK%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF2ARB  = (uint32)%%CAN1:CAN_1_MESSAGE_36_ENA%%U | (uint32)%%CAN1:CAN_1_IDENTIFIER_MODE%%U | (uint32)%%CAN1:CAN_1_MESSAGE_36_DIR%%U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_36_ID%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF2MCTL = 0x00001000U | (uint32)%%CAN1:CAN_1_MESSAGE_36_INT_ENA%%U | (uint32)%%CAN1:CAN_1_MESSAGE_36_RTR%%U | (uint32)%%CAN1:CAN_1_MESSAGE_36_EOB%%U | (uint32)%%CAN1:CAN_1_MESSAGE_36_DLC%%U;
    canREG1->IF2CMD  = (uint8) 0xF8U;
    canREG1->IF2NO   = 36U;

#endif
#if %%CAN1:CAN_1_MESSAGE_37_BOOL_ENA%%
    /** - Initialize message 37 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG1->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG1->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_37_MASK%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF1ARB  = (uint32)%%CAN1:CAN_1_MESSAGE_37_ENA%%U | (uint32)%%CAN1:CAN_1_IDENTIFIER_MODE%%U | (uint32)%%CAN1:CAN_1_MESSAGE_37_DIR%%U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_37_ID%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF1MCTL = 0x00001000U | (uint32)%%CAN1:CAN_1_MESSAGE_37_INT_ENA%%U | (uint32)%%CAN1:CAN_1_MESSAGE_37_RTR%%U | (uint32)%%CAN1:CAN_1_MESSAGE_37_EOB%%U | (uint32)%%CAN1:CAN_1_MESSAGE_37_DLC%%U;
    canREG1->IF1CMD  = (uint8) 0xF8U;
    canREG1->IF1NO   = 37U;

#endif
#if %%CAN1:CAN_1_MESSAGE_38_BOOL_ENA%%
    /** - Initialize message 38 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG1->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG1->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_38_MASK%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF2ARB  = (uint32)%%CAN1:CAN_1_MESSAGE_38_ENA%%U | (uint32)%%CAN1:CAN_1_IDENTIFIER_MODE%%U | (uint32)%%CAN1:CAN_1_MESSAGE_38_DIR%%U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_38_ID%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF2MCTL = 0x00001000U | (uint32)%%CAN1:CAN_1_MESSAGE_38_INT_ENA%%U | (uint32)%%CAN1:CAN_1_MESSAGE_38_RTR%%U | (uint32)%%CAN1:CAN_1_MESSAGE_38_EOB%%U | (uint32)%%CAN1:CAN_1_MESSAGE_38_DLC%%U;
    canREG1->IF2CMD  = (uint8) 0xF8U;
    canREG1->IF2NO   = 38U;

#endif
#if %%CAN1:CAN_1_MESSAGE_39_BOOL_ENA%%
    /** - Initialize message 39 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG1->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG1->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_39_MASK%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF1ARB  = (uint32)%%CAN1:CAN_1_MESSAGE_39_ENA%%U | (uint32)%%CAN1:CAN_1_IDENTIFIER_MODE%%U | (uint32)%%CAN1:CAN_1_MESSAGE_39_DIR%%U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_39_ID%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF1MCTL = 0x00001000U | (uint32)%%CAN1:CAN_1_MESSAGE_39_INT_ENA%%U | (uint32)%%CAN1:CAN_1_MESSAGE_39_RTR%%U | (uint32)%%CAN1:CAN_1_MESSAGE_39_EOB%%U | (uint32)%%CAN1:CAN_1_MESSAGE_39_DLC%%U;
    canREG1->IF1CMD  = (uint8) 0xF8U;
    canREG1->IF1NO   = 39U;

#endif
#if %%CAN1:CAN_1_MESSAGE_40_BOOL_ENA%%
    /** - Initialize message 40 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG1->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG1->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_40_MASK%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF2ARB  = (uint32)%%CAN1:CAN_1_MESSAGE_40_ENA%%U | (uint32)%%CAN1:CAN_1_IDENTIFIER_MODE%%U | (uint32)%%CAN1:CAN_1_MESSAGE_40_DIR%%U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_40_ID%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF2MCTL = 0x00001000U | (uint32)%%CAN1:CAN_1_MESSAGE_40_INT_ENA%%U | (uint32)%%CAN1:CAN_1_MESSAGE_40_RTR%%U | (uint32)%%CAN1:CAN_1_MESSAGE_40_EOB%%U | (uint32)%%CAN1:CAN_1_MESSAGE_40_DLC%%U;
    canREG1->IF2CMD  = (uint8) 0xF8U;
    canREG1->IF2NO   = 40U;

#endif
#if %%CAN1:CAN_1_MESSAGE_41_BOOL_ENA%%
    /** - Initialize message 41 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG1->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG1->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_41_MASK%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF1ARB  = (uint32)%%CAN1:CAN_1_MESSAGE_41_ENA%%U | (uint32)%%CAN1:CAN_1_IDENTIFIER_MODE%%U | (uint32)%%CAN1:CAN_1_MESSAGE_41_DIR%%U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_41_ID%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF1MCTL = 0x00001000U | (uint32)%%CAN1:CAN_1_MESSAGE_41_INT_ENA%%U | (uint32)%%CAN1:CAN_1_MESSAGE_41_RTR%%U | (uint32)%%CAN1:CAN_1_MESSAGE_41_EOB%%U | (uint32)%%CAN1:CAN_1_MESSAGE_41_DLC%%U;
    canREG1->IF1CMD  = (uint8) 0xF8U;
    canREG1->IF1NO   = 41U;

#endif
#if %%CAN1:CAN_1_MESSAGE_42_BOOL_ENA%%
    /** - Initialize message 42 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG1->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG1->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_42_MASK%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF2ARB  = (uint32)%%CAN1:CAN_1_MESSAGE_42_ENA%%U | (uint32)%%CAN1:CAN_1_IDENTIFIER_MODE%%U | (uint32)%%CAN1:CAN_1_MESSAGE_42_DIR%%U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_42_ID%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF2MCTL = 0x00001000U | (uint32)%%CAN1:CAN_1_MESSAGE_42_INT_ENA%%U | (uint32)%%CAN1:CAN_1_MESSAGE_42_RTR%%U | (uint32)%%CAN1:CAN_1_MESSAGE_42_EOB%%U | (uint32)%%CAN1:CAN_1_MESSAGE_42_DLC%%U;
    canREG1->IF2CMD  = (uint8) 0xF8U;
    canREG1->IF2NO   = 42U;

#endif
#if %%CAN1:CAN_1_MESSAGE_43_BOOL_ENA%%
    /** - Initialize message 43 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG1->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG1->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_43_MASK%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF1ARB  = (uint32)%%CAN1:CAN_1_MESSAGE_43_ENA%%U | (uint32)%%CAN1:CAN_1_IDENTIFIER_MODE%%U | (uint32)%%CAN1:CAN_1_MESSAGE_43_DIR%%U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_43_ID%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF1MCTL = 0x00001000U | (uint32)%%CAN1:CAN_1_MESSAGE_43_INT_ENA%%U | (uint32)%%CAN1:CAN_1_MESSAGE_43_RTR%%U | (uint32)%%CAN1:CAN_1_MESSAGE_43_EOB%%U | (uint32)%%CAN1:CAN_1_MESSAGE_43_DLC%%U;
    canREG1->IF1CMD  = (uint8) 0xF8U;
    canREG1->IF1NO   = 43U;

#endif
#if %%CAN1:CAN_1_MESSAGE_44_BOOL_ENA%%
    /** - Initialize message 44 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG1->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG1->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_44_MASK%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF2ARB  = (uint32)%%CAN1:CAN_1_MESSAGE_44_ENA%%U | (uint32)%%CAN1:CAN_1_IDENTIFIER_MODE%%U | (uint32)%%CAN1:CAN_1_MESSAGE_44_DIR%%U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_44_ID%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF2MCTL = 0x00001000U | (uint32)%%CAN1:CAN_1_MESSAGE_44_INT_ENA%%U | (uint32)%%CAN1:CAN_1_MESSAGE_44_RTR%%U | (uint32)%%CAN1:CAN_1_MESSAGE_44_EOB%%U | (uint32)%%CAN1:CAN_1_MESSAGE_44_DLC%%U;
    canREG1->IF2CMD  = (uint8) 0xF8U;
    canREG1->IF2NO   = 44U;

#endif
#if %%CAN1:CAN_1_MESSAGE_45_BOOL_ENA%%
    /** - Initialize message 45 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG1->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG1->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_45_MASK%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF1ARB  = (uint32)%%CAN1:CAN_1_MESSAGE_45_ENA%%U | (uint32)%%CAN1:CAN_1_IDENTIFIER_MODE%%U | (uint32)%%CAN1:CAN_1_MESSAGE_45_DIR%%U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_45_ID%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF1MCTL = 0x00001000U | (uint32)%%CAN1:CAN_1_MESSAGE_45_INT_ENA%%U | (uint32)%%CAN1:CAN_1_MESSAGE_45_RTR%%U | (uint32)%%CAN1:CAN_1_MESSAGE_45_EOB%%U | (uint32)%%CAN1:CAN_1_MESSAGE_45_DLC%%U;
    canREG1->IF1CMD  = (uint8) 0xF8U;
    canREG1->IF1NO   = 45U;

#endif
#if %%CAN1:CAN_1_MESSAGE_46_BOOL_ENA%%
    /** - Initialize message 46 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG1->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG1->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_46_MASK%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF2ARB  = (uint32)%%CAN1:CAN_1_MESSAGE_46_ENA%%U | (uint32)%%CAN1:CAN_1_IDENTIFIER_MODE%%U | (uint32)%%CAN1:CAN_1_MESSAGE_46_DIR%%U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_46_ID%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF2MCTL = 0x00001000U | (uint32)%%CAN1:CAN_1_MESSAGE_46_INT_ENA%%U | (uint32)%%CAN1:CAN_1_MESSAGE_46_RTR%%U | (uint32)%%CAN1:CAN_1_MESSAGE_46_EOB%%U | (uint32)%%CAN1:CAN_1_MESSAGE_46_DLC%%U;
    canREG1->IF2CMD  = (uint8) 0xF8U;
    canREG1->IF2NO   = 46U;

#endif
#if %%CAN1:CAN_1_MESSAGE_47_BOOL_ENA%%
    /** - Initialize message 47 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG1->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG1->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_47_MASK%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF1ARB  = (uint32)%%CAN1:CAN_1_MESSAGE_47_ENA%%U | (uint32)%%CAN1:CAN_1_IDENTIFIER_MODE%%U | (uint32)%%CAN1:CAN_1_MESSAGE_47_DIR%%U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_47_ID%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF1MCTL = 0x00001000U | (uint32)%%CAN1:CAN_1_MESSAGE_47_INT_ENA%%U | (uint32)%%CAN1:CAN_1_MESSAGE_47_RTR%%U | (uint32)%%CAN1:CAN_1_MESSAGE_47_EOB%%U | (uint32)%%CAN1:CAN_1_MESSAGE_47_DLC%%U;
    canREG1->IF1CMD  = (uint8) 0xF8U;
    canREG1->IF1NO   = 47U;

#endif
#if %%CAN1:CAN_1_MESSAGE_48_BOOL_ENA%%
    /** - Initialize message 48 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG1->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG1->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_48_MASK%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF2ARB  = (uint32)%%CAN1:CAN_1_MESSAGE_48_ENA%%U | (uint32)%%CAN1:CAN_1_IDENTIFIER_MODE%%U | (uint32)%%CAN1:CAN_1_MESSAGE_48_DIR%%U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_48_ID%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF2MCTL = 0x00001000U | (uint32)%%CAN1:CAN_1_MESSAGE_48_INT_ENA%%U | (uint32)%%CAN1:CAN_1_MESSAGE_48_RTR%%U | (uint32)%%CAN1:CAN_1_MESSAGE_48_EOB%%U | (uint32)%%CAN1:CAN_1_MESSAGE_48_DLC%%U;
    canREG1->IF2CMD  = (uint8) 0xF8U;
    canREG1->IF2NO   = 48U;

#endif
#if %%CAN1:CAN_1_MESSAGE_49_BOOL_ENA%%
    /** - Initialize message 49 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG1->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG1->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_49_MASK%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF1ARB  = (uint32)%%CAN1:CAN_1_MESSAGE_49_ENA%%U | (uint32)%%CAN1:CAN_1_IDENTIFIER_MODE%%U | (uint32)%%CAN1:CAN_1_MESSAGE_49_DIR%%U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_49_ID%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF1MCTL = 0x00001000U | (uint32)%%CAN1:CAN_1_MESSAGE_49_INT_ENA%%U | (uint32)%%CAN1:CAN_1_MESSAGE_49_RTR%%U | (uint32)%%CAN1:CAN_1_MESSAGE_49_EOB%%U | (uint32)%%CAN1:CAN_1_MESSAGE_49_DLC%%U;
    canREG1->IF1CMD  = (uint8) 0xF8U;
    canREG1->IF1NO   = 49U;

#endif
#if %%CAN1:CAN_1_MESSAGE_50_BOOL_ENA%%
    /** - Initialize message 50 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG1->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG1->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_50_MASK%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF2ARB  = (uint32)%%CAN1:CAN_1_MESSAGE_50_ENA%%U | (uint32)%%CAN1:CAN_1_IDENTIFIER_MODE%%U | (uint32)%%CAN1:CAN_1_MESSAGE_50_DIR%%U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_50_ID%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF2MCTL = 0x00001000U | (uint32)%%CAN1:CAN_1_MESSAGE_50_INT_ENA%%U | (uint32)%%CAN1:CAN_1_MESSAGE_50_RTR%%U | (uint32)%%CAN1:CAN_1_MESSAGE_50_EOB%%U | (uint32)%%CAN1:CAN_1_MESSAGE_50_DLC%%U;
    canREG1->IF2CMD  = (uint8) 0xF8U;
    canREG1->IF2NO   = 50U;

#endif
#if %%CAN1:CAN_1_MESSAGE_51_BOOL_ENA%%
    /** - Initialize message 51 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG1->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG1->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_51_MASK%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF1ARB  = (uint32)%%CAN1:CAN_1_MESSAGE_51_ENA%%U | (uint32)%%CAN1:CAN_1_IDENTIFIER_MODE%%U | (uint32)%%CAN1:CAN_1_MESSAGE_51_DIR%%U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_51_ID%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF1MCTL = 0x00001000U | (uint32)%%CAN1:CAN_1_MESSAGE_51_INT_ENA%%U | (uint32)%%CAN1:CAN_1_MESSAGE_51_RTR%%U | (uint32)%%CAN1:CAN_1_MESSAGE_51_EOB%%U | (uint32)%%CAN1:CAN_1_MESSAGE_51_DLC%%U;
    canREG1->IF1CMD  = (uint8) 0xF8U;
    canREG1->IF1NO   = 51U;

#endif
#if %%CAN1:CAN_1_MESSAGE_52_BOOL_ENA%%
    /** - Initialize message 52 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG1->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG1->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_52_MASK%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF2ARB  = (uint32)%%CAN1:CAN_1_MESSAGE_52_ENA%%U | (uint32)%%CAN1:CAN_1_IDENTIFIER_MODE%%U | (uint32)%%CAN1:CAN_1_MESSAGE_52_DIR%%U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_52_ID%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF2MCTL = 0x00001000U | (uint32)%%CAN1:CAN_1_MESSAGE_52_INT_ENA%%U | (uint32)%%CAN1:CAN_1_MESSAGE_52_RTR%%U | (uint32)%%CAN1:CAN_1_MESSAGE_52_EOB%%U | (uint32)%%CAN1:CAN_1_MESSAGE_52_DLC%%U;
    canREG1->IF2CMD  = (uint8) 0xF8U;
    canREG1->IF2NO   = 52U;

#endif
#if %%CAN1:CAN_1_MESSAGE_53_BOOL_ENA%%
    /** - Initialize message 53 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG1->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG1->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_53_MASK%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF1ARB  = (uint32)%%CAN1:CAN_1_MESSAGE_53_ENA%%U | (uint32)%%CAN1:CAN_1_IDENTIFIER_MODE%%U | (uint32)%%CAN1:CAN_1_MESSAGE_53_DIR%%U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_53_ID%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF1MCTL = 0x00001000U | (uint32)%%CAN1:CAN_1_MESSAGE_53_INT_ENA%%U | (uint32)%%CAN1:CAN_1_MESSAGE_53_RTR%%U | (uint32)%%CAN1:CAN_1_MESSAGE_53_EOB%%U | (uint32)%%CAN1:CAN_1_MESSAGE_53_DLC%%U;
    canREG1->IF1CMD  = (uint8) 0xF8U;
    canREG1->IF1NO   = 53U;

#endif
#if %%CAN1:CAN_1_MESSAGE_54_BOOL_ENA%%
    /** - Initialize message 54 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG1->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG1->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_54_MASK%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF2ARB  = (uint32)%%CAN1:CAN_1_MESSAGE_54_ENA%%U | (uint32)%%CAN1:CAN_1_IDENTIFIER_MODE%%U | (uint32)%%CAN1:CAN_1_MESSAGE_54_DIR%%U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_54_ID%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF2MCTL = 0x00001000U | (uint32)%%CAN1:CAN_1_MESSAGE_54_INT_ENA%%U | (uint32)%%CAN1:CAN_1_MESSAGE_54_RTR%%U | (uint32)%%CAN1:CAN_1_MESSAGE_54_EOB%%U | (uint32)%%CAN1:CAN_1_MESSAGE_54_DLC%%U;
    canREG1->IF2CMD  = (uint8) 0xF8U;
    canREG1->IF2NO   = 54U;

#endif
#if %%CAN1:CAN_1_MESSAGE_55_BOOL_ENA%%
    /** - Initialize message 55 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG1->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG1->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_55_MASK%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF1ARB  = (uint32)%%CAN1:CAN_1_MESSAGE_55_ENA%%U | (uint32)%%CAN1:CAN_1_IDENTIFIER_MODE%%U | (uint32)%%CAN1:CAN_1_MESSAGE_55_DIR%%U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_55_ID%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF1MCTL = 0x00001000U | (uint32)%%CAN1:CAN_1_MESSAGE_55_INT_ENA%%U | (uint32)%%CAN1:CAN_1_MESSAGE_55_RTR%%U | (uint32)%%CAN1:CAN_1_MESSAGE_55_EOB%%U | (uint32)%%CAN1:CAN_1_MESSAGE_55_DLC%%U;
    canREG1->IF1CMD  = (uint8) 0xF8U;
    canREG1->IF1NO   = 55U;

#endif
#if %%CAN1:CAN_1_MESSAGE_56_BOOL_ENA%%
    /** - Initialize message 56 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG1->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG1->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_56_MASK%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF2ARB  = (uint32)%%CAN1:CAN_1_MESSAGE_56_ENA%%U | (uint32)%%CAN1:CAN_1_IDENTIFIER_MODE%%U | (uint32)%%CAN1:CAN_1_MESSAGE_56_DIR%%U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_56_ID%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF2MCTL = 0x00001000U | (uint32)%%CAN1:CAN_1_MESSAGE_56_INT_ENA%%U | (uint32)%%CAN1:CAN_1_MESSAGE_56_RTR%%U | (uint32)%%CAN1:CAN_1_MESSAGE_56_EOB%%U | (uint32)%%CAN1:CAN_1_MESSAGE_56_DLC%%U;
    canREG1->IF2CMD  = (uint8) 0xF8U;
    canREG1->IF2NO   = 56U;

#endif
#if %%CAN1:CAN_1_MESSAGE_57_BOOL_ENA%%
    /** - Initialize message 57 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG1->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG1->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_57_MASK%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF1ARB  = (uint32)%%CAN1:CAN_1_MESSAGE_57_ENA%%U | (uint32)%%CAN1:CAN_1_IDENTIFIER_MODE%%U | (uint32)%%CAN1:CAN_1_MESSAGE_57_DIR%%U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_57_ID%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF1MCTL = 0x00001000U | (uint32)%%CAN1:CAN_1_MESSAGE_57_INT_ENA%%U | (uint32)%%CAN1:CAN_1_MESSAGE_57_RTR%%U | (uint32)%%CAN1:CAN_1_MESSAGE_57_EOB%%U | (uint32)%%CAN1:CAN_1_MESSAGE_57_DLC%%U;
    canREG1->IF1CMD  = (uint8) 0xF8U;
    canREG1->IF1NO   = 57U;

#endif
#if %%CAN1:CAN_1_MESSAGE_58_BOOL_ENA%%
    /** - Initialize message 58 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG1->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG1->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_58_MASK%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF2ARB  = (uint32)%%CAN1:CAN_1_MESSAGE_58_ENA%%U | (uint32)%%CAN1:CAN_1_IDENTIFIER_MODE%%U | (uint32)%%CAN1:CAN_1_MESSAGE_58_DIR%%U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_58_ID%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF2MCTL = 0x00001000U | (uint32)%%CAN1:CAN_1_MESSAGE_58_INT_ENA%%U | (uint32)%%CAN1:CAN_1_MESSAGE_58_RTR%%U | (uint32)%%CAN1:CAN_1_MESSAGE_58_EOB%%U | (uint32)%%CAN1:CAN_1_MESSAGE_58_DLC%%U;
    canREG1->IF2CMD  = (uint8) 0xF8U;
    canREG1->IF2NO   = 58U;

#endif
#if %%CAN1:CAN_1_MESSAGE_59_BOOL_ENA%%
    /** - Initialize message 59 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG1->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG1->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_59_MASK%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF1ARB  = (uint32)%%CAN1:CAN_1_MESSAGE_59_ENA%%U | (uint32)%%CAN1:CAN_1_IDENTIFIER_MODE%%U | (uint32)%%CAN1:CAN_1_MESSAGE_59_DIR%%U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_59_ID%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF1MCTL = 0x00001000U | (uint32)%%CAN1:CAN_1_MESSAGE_59_INT_ENA%%U | (uint32)%%CAN1:CAN_1_MESSAGE_59_RTR%%U | (uint32)%%CAN1:CAN_1_MESSAGE_59_EOB%%U | (uint32)%%CAN1:CAN_1_MESSAGE_59_DLC%%U;
    canREG1->IF1CMD  = (uint8) 0xF8U;
    canREG1->IF1NO   = 59U;

#endif
#if %%CAN1:CAN_1_MESSAGE_60_BOOL_ENA%%
    /** - Initialize message 60 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG1->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG1->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_60_MASK%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF2ARB  = (uint32)%%CAN1:CAN_1_MESSAGE_60_ENA%%U | (uint32)%%CAN1:CAN_1_IDENTIFIER_MODE%%U | (uint32)%%CAN1:CAN_1_MESSAGE_60_DIR%%U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_60_ID%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF2MCTL = 0x00001000U | (uint32)%%CAN1:CAN_1_MESSAGE_60_INT_ENA%%U | (uint32)%%CAN1:CAN_1_MESSAGE_60_RTR%%U | (uint32)%%CAN1:CAN_1_MESSAGE_60_EOB%%U | (uint32)%%CAN1:CAN_1_MESSAGE_60_DLC%%U;
    canREG1->IF2CMD  = (uint8) 0xF8U;
    canREG1->IF2NO   = 60U;

#endif
#if %%CAN1:CAN_1_MESSAGE_61_BOOL_ENA%%
    /** - Initialize message 61 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG1->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG1->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_61_MASK%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF1ARB  = (uint32)%%CAN1:CAN_1_MESSAGE_61_ENA%%U | (uint32)%%CAN1:CAN_1_IDENTIFIER_MODE%%U | (uint32)%%CAN1:CAN_1_MESSAGE_61_DIR%%U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_61_ID%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF1MCTL = 0x00001000U | (uint32)%%CAN1:CAN_1_MESSAGE_61_INT_ENA%%U | (uint32)%%CAN1:CAN_1_MESSAGE_61_RTR%%U | (uint32)%%CAN1:CAN_1_MESSAGE_61_EOB%%U | (uint32)%%CAN1:CAN_1_MESSAGE_61_DLC%%U;
    canREG1->IF1CMD  = (uint8) 0xF8U;
    canREG1->IF1NO   = 61U;

#endif
#if %%CAN1:CAN_1_MESSAGE_62_BOOL_ENA%%
    /** - Initialize message 62 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG1->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG1->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_62_MASK%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF2ARB  = (uint32)%%CAN1:CAN_1_MESSAGE_62_ENA%%U | (uint32)%%CAN1:CAN_1_IDENTIFIER_MODE%%U | (uint32)%%CAN1:CAN_1_MESSAGE_62_DIR%%U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_62_ID%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF2MCTL = 0x00001000U | (uint32)%%CAN1:CAN_1_MESSAGE_62_INT_ENA%%U | (uint32)%%CAN1:CAN_1_MESSAGE_62_RTR%%U | (uint32)%%CAN1:CAN_1_MESSAGE_62_EOB%%U | (uint32)%%CAN1:CAN_1_MESSAGE_62_DLC%%U;
    canREG1->IF2CMD  = (uint8) 0xF8U;
    canREG1->IF2NO   = 62U;

#endif
#if %%CAN1:CAN_1_MESSAGE_63_BOOL_ENA%%
    /** - Initialize message 63 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG1->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG1->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_63_MASK%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF1ARB  = (uint32)%%CAN1:CAN_1_MESSAGE_63_ENA%%U | (uint32)%%CAN1:CAN_1_IDENTIFIER_MODE%%U | (uint32)%%CAN1:CAN_1_MESSAGE_63_DIR%%U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_63_ID%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF1MCTL = 0x00001000U | (uint32)%%CAN1:CAN_1_MESSAGE_63_INT_ENA%%U | (uint32)%%CAN1:CAN_1_MESSAGE_63_RTR%%U | (uint32)%%CAN1:CAN_1_MESSAGE_63_EOB%%U | (uint32)%%CAN1:CAN_1_MESSAGE_63_DLC%%U;
    canREG1->IF1CMD  = (uint8) 0xF8U;
    canREG1->IF1NO   = 63U;

#endif
#if %%CAN1:CAN_1_MESSAGE_64_BOOL_ENA%%
    /** - Initialize message 64 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG1->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG1->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_64_MASK%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF2ARB  = (uint32)%%CAN1:CAN_1_MESSAGE_64_ENA%%U | (uint32)%%CAN1:CAN_1_IDENTIFIER_MODE%%U | (uint32)%%CAN1:CAN_1_MESSAGE_64_DIR%%U | (uint32)((uint32)((uint32)%%CAN1:CAN_1_MESSAGE_64_ID%%U & (uint32)%%CAN1:CAN_1_MASK%%U) << (uint32)%%CAN1:CAN_1_SHIFT%%U);
    canREG1->IF2MCTL = 0x00001000U | (uint32)%%CAN1:CAN_1_MESSAGE_64_INT_ENA%%U | (uint32)%%CAN1:CAN_1_MESSAGE_64_RTR%%U | (uint32)%%CAN1:CAN_1_MESSAGE_64_EOB%%U | (uint32)%%CAN1:CAN_1_MESSAGE_64_DLC%%U;
    canREG1->IF2CMD  = (uint8) 0xF8U;
    canREG1->IF2NO   = 64U;

#endif
    /** - Setup IF1 for data transmission 
    *     - Wait until IF1 is ready for use 
    *     - Set IF1 control byte
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG1->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */
    canREG1->IF1CMD  = 0x87U;

    /** - Setup IF2 for reading data
    *     - Wait until IF1 is ready for use 
    *     - Set IF1 control byte
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG1->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */
    canREG1->IF2CMD = 0x17U;

    /** - Setup bit timing 
    *     - Setup baud rate prescaler extension
    *     - Setup TSeg2
    *     - Setup TSeg1
    *     - Setup sample jump width
    *     - Setup baud rate prescaler
    */
    canREG1->BTR = (uint32)((uint32)%%CAN1:CAN_1_BRPE%%U << 16U) |
                   (uint32)((uint32)(%%CAN1:CAN_1_PHASE_SEG%%U - 1U) << 12U) |
                   (uint32)((uint32)((%%CAN1:CAN_1_PROP_SEG%%U + %%CAN1:CAN_1_PHASE_SEG%%U) - 1U) << 8U) |
                   (uint32)((uint32)(%%CAN1:CAN_1_SJW%%U - 1U) << 6U) |
                   (uint32)%%CAN1:CAN_1_BRP%%U;

#else
    /** - Setup control register
    *     - Enter initialization mode
    */
    canREG1->CTL = 0x00000001U;
				 
     /** - CAN1 Port output values */
    canREG1->TIOC =  (uint32)((uint32)%%CAN1:CAN_1_PORT_TX_PSL%%U  << 18U )
                   | (uint32)((uint32)%%CAN1:CAN_1_PORT_TX_PULDIS%%U  << 17U )
                   | (uint32)((uint32)%%CAN1:CAN_1_PORT_TX_PDR%%U  << 16U )                
                   | (uint32)((uint32)%%CAN1:CAN_1_PORT_TX_FUN%%U  << 3U )  
                   | (uint32)((uint32)%%CAN1:CAN_1_PORT_TX_DIR%%U  << 2U )    
                   | (uint32)((uint32)%%CAN1:CAN_1_PORT_TX_DOUT%%U << 1U );
                   
    canREG1->RIOC =  (uint32)((uint32)%%CAN1:CAN_1_PORT_RX_PSL%%U  << 18U )    
                   | (uint32)((uint32)%%CAN1:CAN_1_PORT_RX_PULDIS%%U  << 17U )  
                   | (uint32)((uint32)%%CAN1:CAN_1_PORT_RX_PDR%%U  << 16U )   
                   | (uint32)((uint32)%%CAN1:CAN_1_PORT_RX_FUN%%U  << 3U )  
                   | (uint32)((uint32)%%CAN1:CAN_1_PORT_RX_DIR%%U  << 2U )
                   | (uint32)((uint32)%%CAN1:CAN_1_PORT_RX_DOUT%%U <<1U );        
#endif                 

#if %%CAN1:CAN_1_PIN_MODE%%

     /** - CAN1 Port output values */
    canREG1->TIOC =  (uint32)((uint32)%%CAN1:CAN_1_PORT_TX_PSL%%U  << 18U )
                   | (uint32)((uint32)%%CAN1:CAN_1_PORT_TX_PULDIS%%U  << 17U )
                   | (uint32)((uint32)%%CAN1:CAN_1_PORT_TX_PDR%%U  << 16U )                
                   | (uint32)((uint32)%%CAN1:CAN_1_PORT_TX_FUN%%U  << 3U )  
                   | (uint32)((uint32)%%CAN1:CAN_1_PORT_TX_DIR%%U  << 2U )    
                   | (uint32)((uint32)%%CAN1:CAN_1_PORT_TX_DOUT%%U << 1U );
                   
    canREG1->RIOC =  (uint32)((uint32)%%CAN1:CAN_1_PORT_RX_PSL%%U  << 18U )    
                   | (uint32)((uint32)%%CAN1:CAN_1_PORT_RX_PULDIS%%U  << 17U )  
                   | (uint32)((uint32)%%CAN1:CAN_1_PORT_RX_PDR%%U  << 16U )   
                   | (uint32)((uint32)%%CAN1:CAN_1_PORT_RX_FUN%%U  << 3U )  
                   | (uint32)((uint32)%%CAN1:CAN_1_PORT_RX_DIR%%U  << 2U )
                   | (uint32)((uint32)%%CAN1:CAN_1_PORT_RX_DOUT%%U <<1U );        

    /** - Leave configuration and initialization mode  */
    canREG1->CTL &= ~(uint32)(0x00000041U);

#endif
#endif

#if %%SYSTEM:CAN2_ENABLE%%
    /** @b Initialize @b CAN2: */

#if %%CAN2:CAN_2_PIN_MODE%%
    /** - Setup control register
    *     - Disable automatic wakeup on bus activity
    *     - Local power down mode disabled
    *     - Disable DMA request lines
    *     - Enable global Interrupt Line 0 and 1
    *     - Disable debug mode
    *     - Release from software reset
    *     - Enable/Disable parity or ECC
    *     - Enable/Disable auto bus on timer
    *     - Setup message completion before entering debug state
    *     - Setup normal operation mode
    *     - Request write access to the configuration registers
    *     - Setup automatic retransmission of messages
    *     - Disable error interrupts
    *     - Disable status interrupts
    *     - Enter initialization mode
    */
    canREG2->CTL = (uint32)%%CAN2:CAN_2_AUTO_BUS_ON%%U 
                 | (uint32)%%CAN2:CAN_2_AUTO_RETRANSMISSION%%U 
                 | (uint32)((uint32)%%CAN2:CAN_2_RAM_PARITY_ENA%%U << 10U)
                 | 0x00020043U;

    /** - Clear all pending error flags and reset current status */
    canREG2->ES |= 0xFFFFFFFFU;

    /** - Assign interrupt level for messages */
    canREG2->INTMUXx[0U] = (uint32)%%CAN2:CAN_2_MESSAGE_64_INT_LEVEL%%U
                         | (uint32)%%CAN2:CAN_2_MESSAGE_1_INT_LEVEL%%U
                         | (uint32)%%CAN2:CAN_2_MESSAGE_2_INT_LEVEL%%U
                         | (uint32)%%CAN2:CAN_2_MESSAGE_3_INT_LEVEL%%U
                         | (uint32)%%CAN2:CAN_2_MESSAGE_4_INT_LEVEL%%U
                         | (uint32)%%CAN2:CAN_2_MESSAGE_5_INT_LEVEL%%U
                         | (uint32)%%CAN2:CAN_2_MESSAGE_6_INT_LEVEL%%U
                         | (uint32)%%CAN2:CAN_2_MESSAGE_7_INT_LEVEL%%U
                         | (uint32)%%CAN2:CAN_2_MESSAGE_8_INT_LEVEL%%U
                         | (uint32)%%CAN2:CAN_2_MESSAGE_9_INT_LEVEL%%U
                         | (uint32)%%CAN2:CAN_2_MESSAGE_10_INT_LEVEL%%U
                         | (uint32)%%CAN2:CAN_2_MESSAGE_11_INT_LEVEL%%U
                         | (uint32)%%CAN2:CAN_2_MESSAGE_12_INT_LEVEL%%U
                         | (uint32)%%CAN2:CAN_2_MESSAGE_13_INT_LEVEL%%U
                         | (uint32)%%CAN2:CAN_2_MESSAGE_14_INT_LEVEL%%U
                         | (uint32)%%CAN2:CAN_2_MESSAGE_15_INT_LEVEL%%U
                         | (uint32)%%CAN2:CAN_2_MESSAGE_16_INT_LEVEL%%U
                         | (uint32)%%CAN2:CAN_2_MESSAGE_17_INT_LEVEL%%U
                         | (uint32)%%CAN2:CAN_2_MESSAGE_18_INT_LEVEL%%U
                         | (uint32)%%CAN2:CAN_2_MESSAGE_19_INT_LEVEL%%U
                         | (uint32)%%CAN2:CAN_2_MESSAGE_20_INT_LEVEL%%U
                         | (uint32)%%CAN2:CAN_2_MESSAGE_21_INT_LEVEL%%U
                         | (uint32)%%CAN2:CAN_2_MESSAGE_22_INT_LEVEL%%U
                         | (uint32)%%CAN2:CAN_2_MESSAGE_23_INT_LEVEL%%U
                         | (uint32)%%CAN2:CAN_2_MESSAGE_24_INT_LEVEL%%U
                         | (uint32)%%CAN2:CAN_2_MESSAGE_25_INT_LEVEL%%U
                         | (uint32)%%CAN2:CAN_2_MESSAGE_26_INT_LEVEL%%U
                         | (uint32)%%CAN2:CAN_2_MESSAGE_27_INT_LEVEL%%U
                         | (uint32)%%CAN2:CAN_2_MESSAGE_28_INT_LEVEL%%U
                         | (uint32)%%CAN2:CAN_2_MESSAGE_29_INT_LEVEL%%U
                         | (uint32)%%CAN2:CAN_2_MESSAGE_30_INT_LEVEL%%U
                         | (uint32)%%CAN2:CAN_2_MESSAGE_31_INT_LEVEL%%U;

    canREG2->INTMUXx[1U] = (uint32)%%CAN2:CAN_2_MESSAGE_32_INT_LEVEL%%U
                         | (uint32)%%CAN2:CAN_2_MESSAGE_33_INT_LEVEL%%U
                         | (uint32)%%CAN2:CAN_2_MESSAGE_34_INT_LEVEL%%U
                         | (uint32)%%CAN2:CAN_2_MESSAGE_35_INT_LEVEL%%U
                         | (uint32)%%CAN2:CAN_2_MESSAGE_36_INT_LEVEL%%U
                         | (uint32)%%CAN2:CAN_2_MESSAGE_37_INT_LEVEL%%U
                         | (uint32)%%CAN2:CAN_2_MESSAGE_38_INT_LEVEL%%U
                         | (uint32)%%CAN2:CAN_2_MESSAGE_39_INT_LEVEL%%U
                         | (uint32)%%CAN2:CAN_2_MESSAGE_40_INT_LEVEL%%U
                         | (uint32)%%CAN2:CAN_2_MESSAGE_41_INT_LEVEL%%U
                         | (uint32)%%CAN2:CAN_2_MESSAGE_42_INT_LEVEL%%U
                         | (uint32)%%CAN2:CAN_2_MESSAGE_43_INT_LEVEL%%U
                         | (uint32)%%CAN2:CAN_2_MESSAGE_44_INT_LEVEL%%U
                         | (uint32)%%CAN2:CAN_2_MESSAGE_45_INT_LEVEL%%U
                         | (uint32)%%CAN2:CAN_2_MESSAGE_46_INT_LEVEL%%U
                         | (uint32)%%CAN2:CAN_2_MESSAGE_47_INT_LEVEL%%U
                         | (uint32)%%CAN2:CAN_2_MESSAGE_48_INT_LEVEL%%U
                         | (uint32)%%CAN2:CAN_2_MESSAGE_49_INT_LEVEL%%U
                         | (uint32)%%CAN2:CAN_2_MESSAGE_50_INT_LEVEL%%U
                         | (uint32)%%CAN2:CAN_2_MESSAGE_51_INT_LEVEL%%U
                         | (uint32)%%CAN2:CAN_2_MESSAGE_52_INT_LEVEL%%U
                         | (uint32)%%CAN2:CAN_2_MESSAGE_53_INT_LEVEL%%U
                         | (uint32)%%CAN2:CAN_2_MESSAGE_54_INT_LEVEL%%U
                         | (uint32)%%CAN2:CAN_2_MESSAGE_55_INT_LEVEL%%U
                         | (uint32)%%CAN2:CAN_2_MESSAGE_56_INT_LEVEL%%U
                         | (uint32)%%CAN2:CAN_2_MESSAGE_57_INT_LEVEL%%U
                         | (uint32)%%CAN2:CAN_2_MESSAGE_58_INT_LEVEL%%U
                         | (uint32)%%CAN2:CAN_2_MESSAGE_59_INT_LEVEL%%U
                         | (uint32)%%CAN2:CAN_2_MESSAGE_60_INT_LEVEL%%U
                         | (uint32)%%CAN2:CAN_2_MESSAGE_61_INT_LEVEL%%U
                         | (uint32)%%CAN2:CAN_2_MESSAGE_62_INT_LEVEL%%U
                         | (uint32)%%CAN2:CAN_2_MESSAGE_63_INT_LEVEL%%U;


    /** - Setup auto bus on timer period */
    canREG2->ABOTR = (uint32)%%CAN2:CAN_2_AUTO_BUS_ON_TR%%U;


#if %%CAN2:CAN_2_MESSAGE_1_BOOL_ENA%%
    /** - Initialize message 1 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG2->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */


    canREG2->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_1_MASK%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF1ARB  = (uint32)%%CAN2:CAN_2_MESSAGE_1_ENA%%U | (uint32)%%CAN2:CAN_2_IDENTIFIER_MODE%%U | (uint32)%%CAN2:CAN_2_MESSAGE_1_DIR%%U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_1_ID%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF1MCTL = 0x00001000U | (uint32)%%CAN2:CAN_2_MESSAGE_1_INT_ENA%%U | (uint32)%%CAN2:CAN_2_MESSAGE_1_RTR%%U | (uint32)%%CAN2:CAN_2_MESSAGE_1_EOB%%U | (uint32)%%CAN2:CAN_2_MESSAGE_1_DLC%%U;
    canREG2->IF1CMD  = (uint8) 0xF8U;
    canREG2->IF1NO   = 1U;

#endif
#if %%CAN2:CAN_2_MESSAGE_2_BOOL_ENA%%
    /** - Initialize message 2 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG2->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG2->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_2_MASK%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF2ARB  = (uint32)%%CAN2:CAN_2_MESSAGE_2_ENA%%U | (uint32)%%CAN2:CAN_2_IDENTIFIER_MODE%%U | (uint32)%%CAN2:CAN_2_MESSAGE_2_DIR%%U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_2_ID%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF2MCTL = 0x00001000U | (uint32)%%CAN2:CAN_2_MESSAGE_2_INT_ENA%%U | (uint32)%%CAN2:CAN_2_MESSAGE_2_RTR%%U | (uint32)%%CAN2:CAN_2_MESSAGE_2_EOB%%U | (uint32)%%CAN2:CAN_2_MESSAGE_2_DLC%%U;
    canREG2->IF2CMD  = (uint8) 0xF8U;
    canREG2->IF2NO   = 2U;

#endif
#if %%CAN2:CAN_2_MESSAGE_3_BOOL_ENA%%
    /** - Initialize message 3 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG2->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG2->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_3_MASK%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF1ARB  = (uint32)%%CAN2:CAN_2_MESSAGE_3_ENA%%U | (uint32)%%CAN2:CAN_2_IDENTIFIER_MODE%%U | (uint32)%%CAN2:CAN_2_MESSAGE_3_DIR%%U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_3_ID%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF1MCTL = 0x00001000U | (uint32)%%CAN2:CAN_2_MESSAGE_3_INT_ENA%%U | (uint32)%%CAN2:CAN_2_MESSAGE_3_RTR%%U | (uint32)%%CAN2:CAN_2_MESSAGE_3_EOB%%U | (uint32)%%CAN2:CAN_2_MESSAGE_3_DLC%%U;
    canREG2->IF1CMD  = (uint8) 0xF8U;
    canREG2->IF1NO   = 3U;

#endif
#if %%CAN2:CAN_2_MESSAGE_4_BOOL_ENA%%
    /** - Initialize message 4 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG2->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG2->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_4_MASK%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF2ARB  = (uint32)%%CAN2:CAN_2_MESSAGE_4_ENA%%U | (uint32)%%CAN2:CAN_2_IDENTIFIER_MODE%%U | (uint32)%%CAN2:CAN_2_MESSAGE_4_DIR%%U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_4_ID%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF2MCTL = 0x00001000U | (uint32)%%CAN2:CAN_2_MESSAGE_4_INT_ENA%%U | (uint32)%%CAN2:CAN_2_MESSAGE_4_RTR%%U | (uint32)%%CAN2:CAN_2_MESSAGE_4_EOB%%U | (uint32)%%CAN2:CAN_2_MESSAGE_4_DLC%%U;
    canREG2->IF2CMD  = (uint8) 0xF8U;
    canREG2->IF2NO   = 4U;

#endif
#if %%CAN2:CAN_2_MESSAGE_5_BOOL_ENA%%
    /** - Initialize message 5 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG2->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG2->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_5_MASK%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF1ARB  = (uint32)%%CAN2:CAN_2_MESSAGE_5_ENA%%U | (uint32)%%CAN2:CAN_2_IDENTIFIER_MODE%%U | (uint32)%%CAN2:CAN_2_MESSAGE_5_DIR%%U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_5_ID%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF1MCTL = 0x00001000U | (uint32)%%CAN2:CAN_2_MESSAGE_5_INT_ENA%%U | (uint32)%%CAN2:CAN_2_MESSAGE_5_RTR%%U | (uint32)%%CAN2:CAN_2_MESSAGE_5_EOB%%U | (uint32)%%CAN2:CAN_2_MESSAGE_5_DLC%%U;
    canREG2->IF1CMD  = (uint8) 0xF8U;
    canREG2->IF1NO   = 5U;

#endif
#if %%CAN2:CAN_2_MESSAGE_6_BOOL_ENA%%
    /** - Initialize message 6 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG2->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG2->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_6_MASK%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF2ARB  = (uint32)%%CAN2:CAN_2_MESSAGE_6_ENA%%U | (uint32)%%CAN2:CAN_2_IDENTIFIER_MODE%%U | (uint32)%%CAN2:CAN_2_MESSAGE_6_DIR%%U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_6_ID%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF2MCTL = 0x00001000U | (uint32)%%CAN2:CAN_2_MESSAGE_6_INT_ENA%%U | (uint32)%%CAN2:CAN_2_MESSAGE_6_RTR%%U | (uint32)%%CAN2:CAN_2_MESSAGE_6_EOB%%U | (uint32)%%CAN2:CAN_2_MESSAGE_6_DLC%%U;
    canREG2->IF2CMD  = (uint8) 0xF8U;
    canREG2->IF2NO   = 6U;

#endif
#if %%CAN2:CAN_2_MESSAGE_7_BOOL_ENA%%
    /** - Initialize message 7 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG2->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG2->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_7_MASK%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF1ARB  = (uint32)%%CAN2:CAN_2_MESSAGE_7_ENA%%U | (uint32)%%CAN2:CAN_2_IDENTIFIER_MODE%%U | (uint32)%%CAN2:CAN_2_MESSAGE_7_DIR%%U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_7_ID%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF1MCTL = 0x00001000U | (uint32)%%CAN2:CAN_2_MESSAGE_7_INT_ENA%%U | (uint32)%%CAN2:CAN_2_MESSAGE_7_RTR%%U | (uint32)%%CAN2:CAN_2_MESSAGE_7_EOB%%U | (uint32)%%CAN2:CAN_2_MESSAGE_7_DLC%%U;
    canREG2->IF1CMD  = (uint8) 0xF8U;
    canREG2->IF1NO   = 7U;

#endif
#if %%CAN2:CAN_2_MESSAGE_8_BOOL_ENA%%
    /** - Initialize message 8 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG2->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG2->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_8_MASK%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF2ARB  = (uint32)%%CAN2:CAN_2_MESSAGE_8_ENA%%U | (uint32)%%CAN2:CAN_2_IDENTIFIER_MODE%%U | (uint32)%%CAN2:CAN_2_MESSAGE_8_DIR%%U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_8_ID%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF2MCTL = 0x00001000U | (uint32)%%CAN2:CAN_2_MESSAGE_8_INT_ENA%%U | (uint32)%%CAN2:CAN_2_MESSAGE_8_RTR%%U | (uint32)%%CAN2:CAN_2_MESSAGE_8_EOB%%U | (uint32)%%CAN2:CAN_2_MESSAGE_8_DLC%%U;
    canREG2->IF2CMD  = (uint8) 0xF8U;
    canREG2->IF2NO   = 8U;

#endif
#if %%CAN2:CAN_2_MESSAGE_9_BOOL_ENA%%
    /** - Initialize message 9 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG2->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG2->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_9_MASK%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF1ARB  = (uint32)%%CAN2:CAN_2_MESSAGE_9_ENA%%U | (uint32)%%CAN2:CAN_2_IDENTIFIER_MODE%%U | (uint32)%%CAN2:CAN_2_MESSAGE_9_DIR%%U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_9_ID%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF1MCTL = 0x00001000U | (uint32)%%CAN2:CAN_2_MESSAGE_9_INT_ENA%%U | (uint32)%%CAN2:CAN_2_MESSAGE_9_RTR%%U | (uint32)%%CAN2:CAN_2_MESSAGE_9_EOB%%U | (uint32)%%CAN2:CAN_2_MESSAGE_9_DLC%%U;
    canREG2->IF1CMD  = (uint8) 0xF8U;
    canREG2->IF1NO   = 9U;

#endif
#if %%CAN2:CAN_2_MESSAGE_10_BOOL_ENA%%
    /** - Initialize message 10 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG2->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG2->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_10_MASK%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF2ARB  = (uint32)%%CAN2:CAN_2_MESSAGE_10_ENA%%U | (uint32)%%CAN2:CAN_2_IDENTIFIER_MODE%%U | (uint32)%%CAN2:CAN_2_MESSAGE_10_DIR%%U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_10_ID%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF2MCTL = 0x00001000U | (uint32)%%CAN2:CAN_2_MESSAGE_10_INT_ENA%%U | (uint32)%%CAN2:CAN_2_MESSAGE_10_RTR%%U | (uint32)%%CAN2:CAN_2_MESSAGE_10_EOB%%U | (uint32)%%CAN2:CAN_2_MESSAGE_10_DLC%%U;
    canREG2->IF2CMD  = (uint8) 0xF8U;
    canREG2->IF2NO   = 10U;

#endif
#if %%CAN2:CAN_2_MESSAGE_11_BOOL_ENA%%
    /** - Initialize message 11 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG2->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG2->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_11_MASK%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF1ARB  = (uint32)%%CAN2:CAN_2_MESSAGE_11_ENA%%U | (uint32)%%CAN2:CAN_2_IDENTIFIER_MODE%%U | (uint32)%%CAN2:CAN_2_MESSAGE_11_DIR%%U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_11_ID%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF1MCTL = 0x00001000U | (uint32)%%CAN2:CAN_2_MESSAGE_11_INT_ENA%%U | (uint32)%%CAN2:CAN_2_MESSAGE_11_RTR%%U | (uint32)%%CAN2:CAN_2_MESSAGE_11_EOB%%U | (uint32)%%CAN2:CAN_2_MESSAGE_11_DLC%%U;
    canREG2->IF1CMD  = (uint8) 0xF8U;
    canREG2->IF1NO   = 11U;

#endif
#if %%CAN2:CAN_2_MESSAGE_12_BOOL_ENA%%
    /** - Initialize message 12 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG2->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG2->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_12_MASK%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF2ARB  = (uint32)%%CAN2:CAN_2_MESSAGE_12_ENA%%U | (uint32)%%CAN2:CAN_2_IDENTIFIER_MODE%%U | (uint32)%%CAN2:CAN_2_MESSAGE_12_DIR%%U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_12_ID%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF2MCTL = 0x00001000U | (uint32)%%CAN2:CAN_2_MESSAGE_12_INT_ENA%%U | (uint32)%%CAN2:CAN_2_MESSAGE_12_RTR%%U | (uint32)%%CAN2:CAN_2_MESSAGE_12_EOB%%U | (uint32)%%CAN2:CAN_2_MESSAGE_12_DLC%%U;
    canREG2->IF2CMD  = (uint8) 0xF8U;
    canREG2->IF2NO   = 12U;

#endif
#if %%CAN2:CAN_2_MESSAGE_13_BOOL_ENA%%
    /** - Initialize message 13 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG2->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG2->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_13_MASK%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF1ARB  = (uint32)%%CAN2:CAN_2_MESSAGE_13_ENA%%U | (uint32)%%CAN2:CAN_2_IDENTIFIER_MODE%%U | (uint32)%%CAN2:CAN_2_MESSAGE_13_DIR%%U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_13_ID%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF1MCTL = 0x00001000U | (uint32)%%CAN2:CAN_2_MESSAGE_13_INT_ENA%%U | (uint32)%%CAN2:CAN_2_MESSAGE_13_RTR%%U | (uint32)%%CAN2:CAN_2_MESSAGE_13_EOB%%U | (uint32)%%CAN2:CAN_2_MESSAGE_13_DLC%%U;
    canREG2->IF1CMD  = (uint8) 0xF8U;
    canREG2->IF1NO   = 13U;

#endif
#if %%CAN2:CAN_2_MESSAGE_14_BOOL_ENA%%
    /** - Initialize message 14 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG2->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG2->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_14_MASK%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF2ARB  = (uint32)%%CAN2:CAN_2_MESSAGE_14_ENA%%U | (uint32)%%CAN2:CAN_2_IDENTIFIER_MODE%%U | (uint32)%%CAN2:CAN_2_MESSAGE_14_DIR%%U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_14_ID%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF2MCTL = 0x00001000U | (uint32)%%CAN2:CAN_2_MESSAGE_14_INT_ENA%%U | (uint32)%%CAN2:CAN_2_MESSAGE_14_RTR%%U | (uint32)%%CAN2:CAN_2_MESSAGE_14_EOB%%U | (uint32)%%CAN2:CAN_2_MESSAGE_14_DLC%%U;
    canREG2->IF2CMD  = (uint8) 0xF8U;
    canREG2->IF2NO   = 14U;

#endif
#if %%CAN2:CAN_2_MESSAGE_15_BOOL_ENA%%
    /** - Initialize message 15 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG2->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG2->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_15_MASK%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF1ARB  = (uint32)%%CAN2:CAN_2_MESSAGE_15_ENA%%U | (uint32)%%CAN2:CAN_2_IDENTIFIER_MODE%%U | (uint32)%%CAN2:CAN_2_MESSAGE_15_DIR%%U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_15_ID%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF1MCTL = 0x00001000U | (uint32)%%CAN2:CAN_2_MESSAGE_15_INT_ENA%%U | (uint32)%%CAN2:CAN_2_MESSAGE_15_RTR%%U | (uint32)%%CAN2:CAN_2_MESSAGE_15_EOB%%U | (uint32)%%CAN2:CAN_2_MESSAGE_15_DLC%%U;
    canREG2->IF1CMD  = (uint8) 0xF8U;
    canREG2->IF1NO   = 15U;

#endif
#if %%CAN2:CAN_2_MESSAGE_16_BOOL_ENA%%
    /** - Initialize message 16 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG2->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG2->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_16_MASK%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF2ARB  = (uint32)%%CAN2:CAN_2_MESSAGE_16_ENA%%U | (uint32)%%CAN2:CAN_2_IDENTIFIER_MODE%%U | (uint32)%%CAN2:CAN_2_MESSAGE_16_DIR%%U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_16_ID%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF2MCTL = 0x00001000U | (uint32)%%CAN2:CAN_2_MESSAGE_16_INT_ENA%%U | (uint32)%%CAN2:CAN_2_MESSAGE_16_RTR%%U | (uint32)%%CAN2:CAN_2_MESSAGE_16_EOB%%U | (uint32)%%CAN2:CAN_2_MESSAGE_16_DLC%%U;
    canREG2->IF2CMD  = (uint8) 0xF8U;
    canREG2->IF2NO   = 16U;

#endif
#if %%CAN2:CAN_2_MESSAGE_17_BOOL_ENA%%
    /** - Initialize message 17 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG2->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG2->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_17_MASK%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF1ARB  = (uint32)%%CAN2:CAN_2_MESSAGE_17_ENA%%U | (uint32)%%CAN2:CAN_2_IDENTIFIER_MODE%%U | (uint32)%%CAN2:CAN_2_MESSAGE_17_DIR%%U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_17_ID%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF1MCTL = 0x00001000U | (uint32)%%CAN2:CAN_2_MESSAGE_17_INT_ENA%%U | (uint32)%%CAN2:CAN_2_MESSAGE_17_RTR%%U | (uint32)%%CAN2:CAN_2_MESSAGE_17_EOB%%U | (uint32)%%CAN2:CAN_2_MESSAGE_17_DLC%%U;
    canREG2->IF1CMD  = (uint8) 0xF8U;
    canREG2->IF1NO   = 17U;

#endif
#if %%CAN2:CAN_2_MESSAGE_18_BOOL_ENA%%
    /** - Initialize message 18 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG2->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG2->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_18_MASK%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF2ARB  = (uint32)%%CAN2:CAN_2_MESSAGE_18_ENA%%U | (uint32)%%CAN2:CAN_2_IDENTIFIER_MODE%%U | (uint32)%%CAN2:CAN_2_MESSAGE_18_DIR%%U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_18_ID%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF2MCTL = 0x00001000U | (uint32)%%CAN2:CAN_2_MESSAGE_18_INT_ENA%%U | (uint32)%%CAN2:CAN_2_MESSAGE_18_RTR%%U | (uint32)%%CAN2:CAN_2_MESSAGE_18_EOB%%U | (uint32)%%CAN2:CAN_2_MESSAGE_18_DLC%%U;
    canREG2->IF2CMD  = (uint8) 0xF8U;
    canREG2->IF2NO   = 18U;

#endif
#if %%CAN2:CAN_2_MESSAGE_19_BOOL_ENA%%
    /** - Initialize message 19 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG2->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG2->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_19_MASK%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF1ARB  = (uint32)%%CAN2:CAN_2_MESSAGE_19_ENA%%U | (uint32)%%CAN2:CAN_2_IDENTIFIER_MODE%%U | (uint32)%%CAN2:CAN_2_MESSAGE_19_DIR%%U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_19_ID%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF1MCTL = 0x00001000U | (uint32)%%CAN2:CAN_2_MESSAGE_19_INT_ENA%%U | (uint32)%%CAN2:CAN_2_MESSAGE_19_RTR%%U | (uint32)%%CAN2:CAN_2_MESSAGE_19_EOB%%U | (uint32)%%CAN2:CAN_2_MESSAGE_19_DLC%%U;
    canREG2->IF1CMD  = (uint8) 0xF8U;
    canREG2->IF1NO   = 19U;

#endif
#if %%CAN2:CAN_2_MESSAGE_20_BOOL_ENA%%
    /** - Initialize message 20 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG2->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG2->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_20_MASK%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF2ARB  = (uint32)%%CAN2:CAN_2_MESSAGE_20_ENA%%U | (uint32)%%CAN2:CAN_2_IDENTIFIER_MODE%%U | (uint32)%%CAN2:CAN_2_MESSAGE_20_DIR%%U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_20_ID%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF2MCTL = 0x00001000U | (uint32)%%CAN2:CAN_2_MESSAGE_20_INT_ENA%%U | (uint32)%%CAN2:CAN_2_MESSAGE_20_RTR%%U | (uint32)%%CAN2:CAN_2_MESSAGE_20_EOB%%U | (uint32)%%CAN2:CAN_2_MESSAGE_20_DLC%%U;
    canREG2->IF2CMD  = (uint8) 0xF8U;
    canREG2->IF2NO   = 20U;

#endif
#if %%CAN2:CAN_2_MESSAGE_21_BOOL_ENA%%
    /** - Initialize message 21 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG2->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG2->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_21_MASK%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF1ARB  = (uint32)%%CAN2:CAN_2_MESSAGE_21_ENA%%U | (uint32)%%CAN2:CAN_2_IDENTIFIER_MODE%%U | (uint32)%%CAN2:CAN_2_MESSAGE_21_DIR%%U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_21_ID%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF1MCTL = 0x00001000U | (uint32)%%CAN2:CAN_2_MESSAGE_21_INT_ENA%%U | (uint32)%%CAN2:CAN_2_MESSAGE_21_RTR%%U | (uint32)%%CAN2:CAN_2_MESSAGE_21_EOB%%U | (uint32)%%CAN2:CAN_2_MESSAGE_21_DLC%%U;
    canREG2->IF1CMD  = (uint8) 0xF8U;
    canREG2->IF1NO   = 21U;

#endif
#if %%CAN2:CAN_2_MESSAGE_22_BOOL_ENA%%
    /** - Initialize message 22 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG2->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG2->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_22_MASK%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF2ARB  = (uint32)%%CAN2:CAN_2_MESSAGE_22_ENA%%U | (uint32)%%CAN2:CAN_2_IDENTIFIER_MODE%%U | (uint32)%%CAN2:CAN_2_MESSAGE_22_DIR%%U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_22_ID%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF2MCTL = 0x00001000U | (uint32)%%CAN2:CAN_2_MESSAGE_22_INT_ENA%%U | (uint32)%%CAN2:CAN_2_MESSAGE_22_RTR%%U | (uint32)%%CAN2:CAN_2_MESSAGE_22_EOB%%U | (uint32)%%CAN2:CAN_2_MESSAGE_22_DLC%%U;
    canREG2->IF2CMD  = (uint8) 0xF8U;
    canREG2->IF2NO   = 22U;

#endif
#if %%CAN2:CAN_2_MESSAGE_23_BOOL_ENA%%
    /** - Initialize message 23 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG2->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG2->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_23_MASK%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF1ARB  = (uint32)%%CAN2:CAN_2_MESSAGE_23_ENA%%U | (uint32)%%CAN2:CAN_2_IDENTIFIER_MODE%%U | (uint32)%%CAN2:CAN_2_MESSAGE_23_DIR%%U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_23_ID%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF1MCTL = 0x00001000U | (uint32)%%CAN2:CAN_2_MESSAGE_23_INT_ENA%%U | (uint32)%%CAN2:CAN_2_MESSAGE_23_RTR%%U | (uint32)%%CAN2:CAN_2_MESSAGE_23_EOB%%U | (uint32)%%CAN2:CAN_2_MESSAGE_23_DLC%%U;
    canREG2->IF1CMD  = (uint8) 0xF8U;
    canREG2->IF1NO   = 23U;

#endif
#if %%CAN2:CAN_2_MESSAGE_24_BOOL_ENA%%
    /** - Initialize message 24 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG2->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG2->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_24_MASK%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF2ARB  = (uint32)%%CAN2:CAN_2_MESSAGE_24_ENA%%U | (uint32)%%CAN2:CAN_2_IDENTIFIER_MODE%%U | (uint32)%%CAN2:CAN_2_MESSAGE_24_DIR%%U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_24_ID%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF2MCTL = 0x00001000U | (uint32)%%CAN2:CAN_2_MESSAGE_24_INT_ENA%%U | (uint32)%%CAN2:CAN_2_MESSAGE_24_RTR%%U | (uint32)%%CAN2:CAN_2_MESSAGE_24_EOB%%U | (uint32)%%CAN2:CAN_2_MESSAGE_24_DLC%%U;
    canREG2->IF2CMD  = (uint8) 0xF8U;
    canREG2->IF2NO   = 24U;

#endif
#if %%CAN2:CAN_2_MESSAGE_25_BOOL_ENA%%
    /** - Initialize message 25 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG2->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG2->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_25_MASK%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF1ARB  = (uint32)%%CAN2:CAN_2_MESSAGE_25_ENA%%U | (uint32)%%CAN2:CAN_2_IDENTIFIER_MODE%%U | (uint32)%%CAN2:CAN_2_MESSAGE_25_DIR%%U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_25_ID%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF1MCTL = 0x00001000U | (uint32)%%CAN2:CAN_2_MESSAGE_25_INT_ENA%%U | (uint32)%%CAN2:CAN_2_MESSAGE_25_RTR%%U | (uint32)%%CAN2:CAN_2_MESSAGE_25_EOB%%U | (uint32)%%CAN2:CAN_2_MESSAGE_25_DLC%%U;
    canREG2->IF1CMD  = (uint8) 0xF8U;
    canREG2->IF1NO   = 25U;

#endif
#if %%CAN2:CAN_2_MESSAGE_26_BOOL_ENA%%
    /** - Initialize message 26 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG2->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG2->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_26_MASK%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF2ARB  = (uint32)%%CAN2:CAN_2_MESSAGE_26_ENA%%U | (uint32)%%CAN2:CAN_2_IDENTIFIER_MODE%%U | (uint32)%%CAN2:CAN_2_MESSAGE_26_DIR%%U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_26_ID%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF2MCTL = 0x00001000U | (uint32)%%CAN2:CAN_2_MESSAGE_26_INT_ENA%%U | (uint32)%%CAN2:CAN_2_MESSAGE_26_RTR%%U | (uint32)%%CAN2:CAN_2_MESSAGE_26_EOB%%U | (uint32)%%CAN2:CAN_2_MESSAGE_26_DLC%%U;
    canREG2->IF2CMD  = (uint8) 0xF8U;
    canREG2->IF2NO   = 26U;

#endif
#if %%CAN2:CAN_2_MESSAGE_27_BOOL_ENA%%
    /** - Initialize message 27 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG2->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG2->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_27_MASK%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF1ARB  = (uint32)%%CAN2:CAN_2_MESSAGE_27_ENA%%U | (uint32)%%CAN2:CAN_2_IDENTIFIER_MODE%%U | (uint32)%%CAN2:CAN_2_MESSAGE_27_DIR%%U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_27_ID%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF1MCTL = 0x00001000U | (uint32)%%CAN2:CAN_2_MESSAGE_27_INT_ENA%%U | (uint32)%%CAN2:CAN_2_MESSAGE_27_RTR%%U | (uint32)%%CAN2:CAN_2_MESSAGE_27_EOB%%U | (uint32)%%CAN2:CAN_2_MESSAGE_27_DLC%%U;
    canREG2->IF1CMD  = (uint8) 0xF8U;
    canREG2->IF1NO   = 27U;

#endif
#if %%CAN2:CAN_2_MESSAGE_28_BOOL_ENA%%
    /** - Initialize message 28 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG2->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG2->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_28_MASK%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF2ARB  = (uint32)%%CAN2:CAN_2_MESSAGE_28_ENA%%U | (uint32)%%CAN2:CAN_2_IDENTIFIER_MODE%%U | (uint32)%%CAN2:CAN_2_MESSAGE_28_DIR%%U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_28_ID%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF2MCTL = 0x00001000U | (uint32)%%CAN2:CAN_2_MESSAGE_28_INT_ENA%%U | (uint32)%%CAN2:CAN_2_MESSAGE_28_RTR%%U | (uint32)%%CAN2:CAN_2_MESSAGE_28_EOB%%U | (uint32)%%CAN2:CAN_2_MESSAGE_28_DLC%%U;
    canREG2->IF2CMD  = (uint8) 0xF8U;
    canREG2->IF2NO   = 28U;

#endif
#if %%CAN2:CAN_2_MESSAGE_29_BOOL_ENA%%
    /** - Initialize message 29 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG2->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG2->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_29_MASK%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF1ARB  = (uint32)%%CAN2:CAN_2_MESSAGE_29_ENA%%U | (uint32)%%CAN2:CAN_2_IDENTIFIER_MODE%%U | (uint32)%%CAN2:CAN_2_MESSAGE_29_DIR%%U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_29_ID%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF1MCTL = 0x00001000U | (uint32)%%CAN2:CAN_2_MESSAGE_29_INT_ENA%%U | (uint32)%%CAN2:CAN_2_MESSAGE_29_RTR%%U | (uint32)%%CAN2:CAN_2_MESSAGE_29_EOB%%U | (uint32)%%CAN2:CAN_2_MESSAGE_29_DLC%%U;
    canREG2->IF1CMD  = (uint8) 0xF8U;
    canREG2->IF1NO   = 29U;

#endif
#if %%CAN2:CAN_2_MESSAGE_30_BOOL_ENA%%
    /** - Initialize message 30 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG2->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG2->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_30_MASK%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF2ARB  = (uint32)%%CAN2:CAN_2_MESSAGE_30_ENA%%U | (uint32)%%CAN2:CAN_2_IDENTIFIER_MODE%%U | (uint32)%%CAN2:CAN_2_MESSAGE_30_DIR%%U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_30_ID%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF2MCTL = 0x00001000U | (uint32)%%CAN2:CAN_2_MESSAGE_30_INT_ENA%%U | (uint32)%%CAN2:CAN_2_MESSAGE_30_RTR%%U | (uint32)%%CAN2:CAN_2_MESSAGE_30_EOB%%U | (uint32)%%CAN2:CAN_2_MESSAGE_30_DLC%%U;
    canREG2->IF2CMD  = (uint8) 0xF8U;
    canREG2->IF2NO   = 30U;

#endif
#if %%CAN2:CAN_2_MESSAGE_31_BOOL_ENA%%
    /** - Initialize message 31 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG2->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG2->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_31_MASK%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF1ARB  = (uint32)%%CAN2:CAN_2_MESSAGE_31_ENA%%U | (uint32)%%CAN2:CAN_2_IDENTIFIER_MODE%%U | (uint32)%%CAN2:CAN_2_MESSAGE_31_DIR%%U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_31_ID%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF1MCTL = 0x00001000U | (uint32)%%CAN2:CAN_2_MESSAGE_31_INT_ENA%%U | (uint32)%%CAN2:CAN_2_MESSAGE_31_RTR%%U | (uint32)%%CAN2:CAN_2_MESSAGE_31_EOB%%U | (uint32)%%CAN2:CAN_2_MESSAGE_31_DLC%%U;
    canREG2->IF1CMD  = (uint8) 0xF8U;
    canREG2->IF1NO   = 31U;

#endif
#if %%CAN2:CAN_2_MESSAGE_32_BOOL_ENA%%
    /** - Initialize message 32 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG2->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG2->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_32_MASK%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF2ARB  = (uint32)%%CAN2:CAN_2_MESSAGE_32_ENA%%U | (uint32)%%CAN2:CAN_2_IDENTIFIER_MODE%%U | (uint32)%%CAN2:CAN_2_MESSAGE_32_DIR%%U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_32_ID%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF2MCTL = 0x00001000U | (uint32)%%CAN2:CAN_2_MESSAGE_32_INT_ENA%%U | (uint32)%%CAN2:CAN_2_MESSAGE_32_RTR%%U | (uint32)%%CAN2:CAN_2_MESSAGE_32_EOB%%U | (uint32)%%CAN2:CAN_2_MESSAGE_32_DLC%%U;
    canREG2->IF2CMD  = (uint8) 0xF8U;
    canREG2->IF2NO   = 32U;

#endif
#if %%CAN2:CAN_2_MESSAGE_33_BOOL_ENA%%
    /** - Initialize message 33 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG2->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG2->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_33_MASK%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF1ARB  = (uint32)%%CAN2:CAN_2_MESSAGE_33_ENA%%U | (uint32)%%CAN2:CAN_2_IDENTIFIER_MODE%%U | (uint32)%%CAN2:CAN_2_MESSAGE_33_DIR%%U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_33_ID%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF1MCTL = 0x00001000U | (uint32)%%CAN2:CAN_2_MESSAGE_33_INT_ENA%%U | (uint32)%%CAN2:CAN_2_MESSAGE_33_RTR%%U | (uint32)%%CAN2:CAN_2_MESSAGE_33_EOB%%U | (uint32)%%CAN2:CAN_2_MESSAGE_33_DLC%%U;
    canREG2->IF1CMD  = (uint8) 0xF8U;
    canREG2->IF1NO   = 33U;

#endif
#if %%CAN2:CAN_2_MESSAGE_34_BOOL_ENA%%
    /** - Initialize message 34 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG2->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG2->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_34_MASK%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF2ARB  = (uint32)%%CAN2:CAN_2_MESSAGE_34_ENA%%U | (uint32)%%CAN2:CAN_2_IDENTIFIER_MODE%%U | (uint32)%%CAN2:CAN_2_MESSAGE_34_DIR%%U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_34_ID%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF2MCTL = 0x00001000U | (uint32)%%CAN2:CAN_2_MESSAGE_34_INT_ENA%%U | (uint32)%%CAN2:CAN_2_MESSAGE_34_RTR%%U | (uint32)%%CAN2:CAN_2_MESSAGE_34_EOB%%U | (uint32)%%CAN2:CAN_2_MESSAGE_34_DLC%%U;
    canREG2->IF2CMD  = (uint8) 0xF8U;
    canREG2->IF2NO   = 34U;

#endif
#if %%CAN2:CAN_2_MESSAGE_35_BOOL_ENA%%
    /** - Initialize message 35 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG2->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG2->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_35_MASK%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF1ARB  = (uint32)%%CAN2:CAN_2_MESSAGE_35_ENA%%U | (uint32)%%CAN2:CAN_2_IDENTIFIER_MODE%%U | (uint32)%%CAN2:CAN_2_MESSAGE_35_DIR%%U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_35_ID%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF1MCTL = 0x00001000U | (uint32)%%CAN2:CAN_2_MESSAGE_35_INT_ENA%%U | (uint32)%%CAN2:CAN_2_MESSAGE_35_RTR%%U | (uint32)%%CAN2:CAN_2_MESSAGE_35_EOB%%U | (uint32)%%CAN2:CAN_2_MESSAGE_35_DLC%%U;
    canREG2->IF1CMD  = (uint8) 0xF8U;
    canREG2->IF1NO   = 35U;

#endif
#if %%CAN2:CAN_2_MESSAGE_36_BOOL_ENA%%
    /** - Initialize message 36 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG2->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG2->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_36_MASK%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF2ARB  = (uint32)%%CAN2:CAN_2_MESSAGE_36_ENA%%U | (uint32)%%CAN2:CAN_2_IDENTIFIER_MODE%%U | (uint32)%%CAN2:CAN_2_MESSAGE_36_DIR%%U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_36_ID%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF2MCTL = 0x00001000U | (uint32)%%CAN2:CAN_2_MESSAGE_36_INT_ENA%%U | (uint32)%%CAN2:CAN_2_MESSAGE_36_RTR%%U | (uint32)%%CAN2:CAN_2_MESSAGE_36_EOB%%U | (uint32)%%CAN2:CAN_2_MESSAGE_36_DLC%%U;
    canREG2->IF2CMD  = (uint8) 0xF8U;
    canREG2->IF2NO   = 36U;

#endif
#if %%CAN2:CAN_2_MESSAGE_37_BOOL_ENA%%
    /** - Initialize message 37 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG2->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG2->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_37_MASK%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF1ARB  = (uint32)%%CAN2:CAN_2_MESSAGE_37_ENA%%U | (uint32)%%CAN2:CAN_2_IDENTIFIER_MODE%%U | (uint32)%%CAN2:CAN_2_MESSAGE_37_DIR%%U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_37_ID%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF1MCTL = 0x00001000U | (uint32)%%CAN2:CAN_2_MESSAGE_37_INT_ENA%%U | (uint32)%%CAN2:CAN_2_MESSAGE_37_RTR%%U | (uint32)%%CAN2:CAN_2_MESSAGE_37_EOB%%U | (uint32)%%CAN2:CAN_2_MESSAGE_37_DLC%%U;
    canREG2->IF1CMD  = (uint8) 0xF8U;
    canREG2->IF1NO   = 37U;

#endif
#if %%CAN2:CAN_2_MESSAGE_38_BOOL_ENA%%
    /** - Initialize message 38 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG2->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG2->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_38_MASK%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF2ARB  = (uint32)%%CAN2:CAN_2_MESSAGE_38_ENA%%U | (uint32)%%CAN2:CAN_2_IDENTIFIER_MODE%%U | (uint32)%%CAN2:CAN_2_MESSAGE_38_DIR%%U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_38_ID%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF2MCTL = 0x00001000U | (uint32)%%CAN2:CAN_2_MESSAGE_38_INT_ENA%%U | (uint32)%%CAN2:CAN_2_MESSAGE_38_RTR%%U | (uint32)%%CAN2:CAN_2_MESSAGE_38_EOB%%U | (uint32)%%CAN2:CAN_2_MESSAGE_38_DLC%%U;
    canREG2->IF2CMD  = (uint8) 0xF8U;
    canREG2->IF2NO   = 38U;

#endif
#if %%CAN2:CAN_2_MESSAGE_39_BOOL_ENA%%
    /** - Initialize message 39 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG2->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG2->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_39_MASK%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF1ARB  = (uint32)%%CAN2:CAN_2_MESSAGE_39_ENA%%U | (uint32)%%CAN2:CAN_2_IDENTIFIER_MODE%%U | (uint32)%%CAN2:CAN_2_MESSAGE_39_DIR%%U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_39_ID%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF1MCTL = 0x00001000U | (uint32)%%CAN2:CAN_2_MESSAGE_39_INT_ENA%%U | (uint32)%%CAN2:CAN_2_MESSAGE_39_RTR%%U | (uint32)%%CAN2:CAN_2_MESSAGE_39_EOB%%U | (uint32)%%CAN2:CAN_2_MESSAGE_39_DLC%%U;
    canREG2->IF1CMD  = (uint8) 0xF8U;
    canREG2->IF1NO   = 39U;

#endif
#if %%CAN2:CAN_2_MESSAGE_40_BOOL_ENA%%
    /** - Initialize message 40 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG2->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG2->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_40_MASK%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF2ARB  = (uint32)%%CAN2:CAN_2_MESSAGE_40_ENA%%U | (uint32)%%CAN2:CAN_2_IDENTIFIER_MODE%%U | (uint32)%%CAN2:CAN_2_MESSAGE_40_DIR%%U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_40_ID%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF2MCTL = 0x00001000U | (uint32)%%CAN2:CAN_2_MESSAGE_40_INT_ENA%%U | (uint32)%%CAN2:CAN_2_MESSAGE_40_RTR%%U | (uint32)%%CAN2:CAN_2_MESSAGE_40_EOB%%U | (uint32)%%CAN2:CAN_2_MESSAGE_40_DLC%%U;
    canREG2->IF2CMD  = (uint8) 0xF8U;
    canREG2->IF2NO   = 40U;

#endif
#if %%CAN2:CAN_2_MESSAGE_41_BOOL_ENA%%
    /** - Initialize message 41 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG2->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG2->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_41_MASK%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF1ARB  = (uint32)%%CAN2:CAN_2_MESSAGE_41_ENA%%U | (uint32)%%CAN2:CAN_2_IDENTIFIER_MODE%%U | (uint32)%%CAN2:CAN_2_MESSAGE_41_DIR%%U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_41_ID%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF1MCTL = 0x00001000U | (uint32)%%CAN2:CAN_2_MESSAGE_41_INT_ENA%%U | (uint32)%%CAN2:CAN_2_MESSAGE_41_RTR%%U | (uint32)%%CAN2:CAN_2_MESSAGE_41_EOB%%U | (uint32)%%CAN2:CAN_2_MESSAGE_41_DLC%%U;
    canREG2->IF1CMD  = (uint8) 0xF8U;
    canREG2->IF1NO   = 41U;

#endif
#if %%CAN2:CAN_2_MESSAGE_42_BOOL_ENA%%
    /** - Initialize message 42 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG2->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG2->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_42_MASK%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF2ARB  = (uint32)%%CAN2:CAN_2_MESSAGE_42_ENA%%U | (uint32)%%CAN2:CAN_2_IDENTIFIER_MODE%%U | (uint32)%%CAN2:CAN_2_MESSAGE_42_DIR%%U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_42_ID%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF2MCTL = 0x00001000U | (uint32)%%CAN2:CAN_2_MESSAGE_42_INT_ENA%%U | (uint32)%%CAN2:CAN_2_MESSAGE_42_RTR%%U | (uint32)%%CAN2:CAN_2_MESSAGE_42_EOB%%U | (uint32)%%CAN2:CAN_2_MESSAGE_42_DLC%%U;
    canREG2->IF2CMD  = (uint8) 0xF8U;
    canREG2->IF2NO   = 42U;

#endif
#if %%CAN2:CAN_2_MESSAGE_43_BOOL_ENA%%
    /** - Initialize message 43 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG2->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG2->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_43_MASK%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF1ARB  = (uint32)%%CAN2:CAN_2_MESSAGE_43_ENA%%U | (uint32)%%CAN2:CAN_2_IDENTIFIER_MODE%%U | (uint32)%%CAN2:CAN_2_MESSAGE_43_DIR%%U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_43_ID%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF1MCTL = 0x00001000U | (uint32)%%CAN2:CAN_2_MESSAGE_43_INT_ENA%%U | (uint32)%%CAN2:CAN_2_MESSAGE_43_RTR%%U | (uint32)%%CAN2:CAN_2_MESSAGE_43_EOB%%U | (uint32)%%CAN2:CAN_2_MESSAGE_43_DLC%%U;
    canREG2->IF1CMD  = (uint8) 0xF8U;
    canREG2->IF1NO   = 43U;

#endif
#if %%CAN2:CAN_2_MESSAGE_44_BOOL_ENA%%
    /** - Initialize message 44 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG2->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG2->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_44_MASK%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF2ARB  = (uint32)%%CAN2:CAN_2_MESSAGE_44_ENA%%U | (uint32)%%CAN2:CAN_2_IDENTIFIER_MODE%%U | (uint32)%%CAN2:CAN_2_MESSAGE_44_DIR%%U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_44_ID%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF2MCTL = 0x00001000U | (uint32)%%CAN2:CAN_2_MESSAGE_44_INT_ENA%%U | (uint32)%%CAN2:CAN_2_MESSAGE_44_RTR%%U | (uint32)%%CAN2:CAN_2_MESSAGE_44_EOB%%U | (uint32)%%CAN2:CAN_2_MESSAGE_44_DLC%%U;
    canREG2->IF2CMD  = (uint8) 0xF8U;
    canREG2->IF2NO   = 44U;

#endif
#if %%CAN2:CAN_2_MESSAGE_45_BOOL_ENA%%
    /** - Initialize message 45 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG2->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG2->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_45_MASK%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF1ARB  = (uint32)%%CAN2:CAN_2_MESSAGE_45_ENA%%U | (uint32)%%CAN2:CAN_2_IDENTIFIER_MODE%%U | (uint32)%%CAN2:CAN_2_MESSAGE_45_DIR%%U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_45_ID%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF1MCTL = 0x00001000U | (uint32)%%CAN2:CAN_2_MESSAGE_45_INT_ENA%%U | (uint32)%%CAN2:CAN_2_MESSAGE_45_RTR%%U | (uint32)%%CAN2:CAN_2_MESSAGE_45_EOB%%U | (uint32)%%CAN2:CAN_2_MESSAGE_45_DLC%%U;
    canREG2->IF1CMD  = (uint8) 0xF8U;
    canREG2->IF1NO   = 45U;

#endif
#if %%CAN2:CAN_2_MESSAGE_46_BOOL_ENA%%
    /** - Initialize message 46 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG2->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG2->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_46_MASK%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF2ARB  = (uint32)%%CAN2:CAN_2_MESSAGE_46_ENA%%U | (uint32)%%CAN2:CAN_2_IDENTIFIER_MODE%%U | (uint32)%%CAN2:CAN_2_MESSAGE_46_DIR%%U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_46_ID%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF2MCTL = 0x00001000U | (uint32)%%CAN2:CAN_2_MESSAGE_46_INT_ENA%%U | (uint32)%%CAN2:CAN_2_MESSAGE_46_RTR%%U | (uint32)%%CAN2:CAN_2_MESSAGE_46_EOB%%U | (uint32)%%CAN2:CAN_2_MESSAGE_46_DLC%%U;
    canREG2->IF2CMD  = (uint8) 0xF8U;
    canREG2->IF2NO   = 46U;

#endif
#if %%CAN2:CAN_2_MESSAGE_47_BOOL_ENA%%
    /** - Initialize message 47 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG2->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG2->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_47_MASK%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF1ARB  = (uint32)%%CAN2:CAN_2_MESSAGE_47_ENA%%U | (uint32)%%CAN2:CAN_2_IDENTIFIER_MODE%%U | (uint32)%%CAN2:CAN_2_MESSAGE_47_DIR%%U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_47_ID%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF1MCTL = 0x00001000U | (uint32)%%CAN2:CAN_2_MESSAGE_47_INT_ENA%%U | (uint32)%%CAN2:CAN_2_MESSAGE_47_RTR%%U | (uint32)%%CAN2:CAN_2_MESSAGE_47_EOB%%U | (uint32)%%CAN2:CAN_2_MESSAGE_47_DLC%%U;
    canREG2->IF1CMD  = (uint8) 0xF8U;
    canREG2->IF1NO   = 47U;

#endif
#if %%CAN2:CAN_2_MESSAGE_48_BOOL_ENA%%
    /** - Initialize message 48 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG2->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG2->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_48_MASK%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF2ARB  = (uint32)%%CAN2:CAN_2_MESSAGE_48_ENA%%U | (uint32)%%CAN2:CAN_2_IDENTIFIER_MODE%%U | (uint32)%%CAN2:CAN_2_MESSAGE_48_DIR%%U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_48_ID%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF2MCTL = 0x00001000U | (uint32)%%CAN2:CAN_2_MESSAGE_48_INT_ENA%%U | (uint32)%%CAN2:CAN_2_MESSAGE_48_RTR%%U | (uint32)%%CAN2:CAN_2_MESSAGE_48_EOB%%U | (uint32)%%CAN2:CAN_2_MESSAGE_48_DLC%%U;
    canREG2->IF2CMD  = (uint8) 0xF8U;
    canREG2->IF2NO   = 48U;

#endif
#if %%CAN2:CAN_2_MESSAGE_49_BOOL_ENA%%
    /** - Initialize message 49 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG2->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG2->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_49_MASK%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF1ARB  = (uint32)%%CAN2:CAN_2_MESSAGE_49_ENA%%U | (uint32)%%CAN2:CAN_2_IDENTIFIER_MODE%%U | (uint32)%%CAN2:CAN_2_MESSAGE_49_DIR%%U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_49_ID%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF1MCTL = 0x00001000U | (uint32)%%CAN2:CAN_2_MESSAGE_49_INT_ENA%%U | (uint32)%%CAN2:CAN_2_MESSAGE_49_RTR%%U | (uint32)%%CAN2:CAN_2_MESSAGE_49_EOB%%U | (uint32)%%CAN2:CAN_2_MESSAGE_49_DLC%%U;
    canREG2->IF1CMD  = (uint8) 0xF8U;
    canREG2->IF1NO   = 49U;

#endif
#if %%CAN2:CAN_2_MESSAGE_50_BOOL_ENA%%
    /** - Initialize message 50 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG2->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG2->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_50_MASK%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF2ARB  = (uint32)%%CAN2:CAN_2_MESSAGE_50_ENA%%U | (uint32)%%CAN2:CAN_2_IDENTIFIER_MODE%%U | (uint32)%%CAN2:CAN_2_MESSAGE_50_DIR%%U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_50_ID%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF2MCTL = 0x00001000U | (uint32)%%CAN2:CAN_2_MESSAGE_50_INT_ENA%%U | (uint32)%%CAN2:CAN_2_MESSAGE_50_RTR%%U | (uint32)%%CAN2:CAN_2_MESSAGE_50_EOB%%U | (uint32)%%CAN2:CAN_2_MESSAGE_50_DLC%%U;
    canREG2->IF2CMD  = (uint8) 0xF8U;
    canREG2->IF2NO   = 50U;

#endif
#if %%CAN2:CAN_2_MESSAGE_51_BOOL_ENA%%
    /** - Initialize message 51 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG2->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG2->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_51_MASK%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF1ARB  = (uint32)%%CAN2:CAN_2_MESSAGE_51_ENA%%U | (uint32)%%CAN2:CAN_2_IDENTIFIER_MODE%%U | (uint32)%%CAN2:CAN_2_MESSAGE_51_DIR%%U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_51_ID%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF1MCTL = 0x00001000U | (uint32)%%CAN2:CAN_2_MESSAGE_51_INT_ENA%%U | (uint32)%%CAN2:CAN_2_MESSAGE_51_RTR%%U | (uint32)%%CAN2:CAN_2_MESSAGE_51_EOB%%U | (uint32)%%CAN2:CAN_2_MESSAGE_51_DLC%%U;
    canREG2->IF1CMD  = (uint8) 0xF8U;
    canREG2->IF1NO   = 51U;

#endif
#if %%CAN2:CAN_2_MESSAGE_52_BOOL_ENA%%
    /** - Initialize message 52 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG2->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG2->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_52_MASK%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF2ARB  = (uint32)%%CAN2:CAN_2_MESSAGE_52_ENA%%U | (uint32)%%CAN2:CAN_2_IDENTIFIER_MODE%%U | (uint32)%%CAN2:CAN_2_MESSAGE_52_DIR%%U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_52_ID%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF2MCTL = 0x00001000U | (uint32)%%CAN2:CAN_2_MESSAGE_52_INT_ENA%%U | (uint32)%%CAN2:CAN_2_MESSAGE_52_RTR%%U | (uint32)%%CAN2:CAN_2_MESSAGE_52_EOB%%U | (uint32)%%CAN2:CAN_2_MESSAGE_52_DLC%%U;
    canREG2->IF2CMD  = (uint8) 0xF8U;
    canREG2->IF2NO   = 52U;

#endif
#if %%CAN2:CAN_2_MESSAGE_53_BOOL_ENA%%
    /** - Initialize message 53 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG2->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG2->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_53_MASK%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF1ARB  = (uint32)%%CAN2:CAN_2_MESSAGE_53_ENA%%U | (uint32)%%CAN2:CAN_2_IDENTIFIER_MODE%%U | (uint32)%%CAN2:CAN_2_MESSAGE_53_DIR%%U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_53_ID%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF1MCTL = 0x00001000U | (uint32)%%CAN2:CAN_2_MESSAGE_53_INT_ENA%%U | (uint32)%%CAN2:CAN_2_MESSAGE_53_RTR%%U | (uint32)%%CAN2:CAN_2_MESSAGE_53_EOB%%U | (uint32)%%CAN2:CAN_2_MESSAGE_53_DLC%%U;
    canREG2->IF1CMD  = (uint8) 0xF8U;
    canREG2->IF1NO   = 53U;

#endif
#if %%CAN2:CAN_2_MESSAGE_54_BOOL_ENA%%
    /** - Initialize message 54 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG2->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG2->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_54_MASK%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF2ARB  = (uint32)%%CAN2:CAN_2_MESSAGE_54_ENA%%U | (uint32)%%CAN2:CAN_2_IDENTIFIER_MODE%%U | (uint32)%%CAN2:CAN_2_MESSAGE_54_DIR%%U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_54_ID%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF2MCTL = 0x00001000U | (uint32)%%CAN2:CAN_2_MESSAGE_54_INT_ENA%%U | (uint32)%%CAN2:CAN_2_MESSAGE_54_RTR%%U | (uint32)%%CAN2:CAN_2_MESSAGE_54_EOB%%U | (uint32)%%CAN2:CAN_2_MESSAGE_54_DLC%%U;
    canREG2->IF2CMD  = (uint8) 0xF8U;
    canREG2->IF2NO   = 54U;

#endif
#if %%CAN2:CAN_2_MESSAGE_55_BOOL_ENA%%
    /** - Initialize message 55 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG2->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG2->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_55_MASK%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF1ARB  = (uint32)%%CAN2:CAN_2_MESSAGE_55_ENA%%U | (uint32)%%CAN2:CAN_2_IDENTIFIER_MODE%%U | (uint32)%%CAN2:CAN_2_MESSAGE_55_DIR%%U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_55_ID%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF1MCTL = 0x00001000U | (uint32)%%CAN2:CAN_2_MESSAGE_55_INT_ENA%%U | (uint32)%%CAN2:CAN_2_MESSAGE_55_RTR%%U | (uint32)%%CAN2:CAN_2_MESSAGE_55_EOB%%U | (uint32)%%CAN2:CAN_2_MESSAGE_55_DLC%%U;
    canREG2->IF1CMD  = (uint8) 0xF8U;
    canREG2->IF1NO   = 55U;

#endif
#if %%CAN2:CAN_2_MESSAGE_56_BOOL_ENA%%
    /** - Initialize message 56 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG2->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG2->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_56_MASK%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF2ARB  = (uint32)%%CAN2:CAN_2_MESSAGE_56_ENA%%U | (uint32)%%CAN2:CAN_2_IDENTIFIER_MODE%%U | (uint32)%%CAN2:CAN_2_MESSAGE_56_DIR%%U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_56_ID%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF2MCTL = 0x00001000U | (uint32)%%CAN2:CAN_2_MESSAGE_56_INT_ENA%%U | (uint32)%%CAN2:CAN_2_MESSAGE_56_RTR%%U | (uint32)%%CAN2:CAN_2_MESSAGE_56_EOB%%U | (uint32)%%CAN2:CAN_2_MESSAGE_56_DLC%%U;
    canREG2->IF2CMD  = (uint8) 0xF8U;
    canREG2->IF2NO   = 56U;

#endif
#if %%CAN2:CAN_2_MESSAGE_57_BOOL_ENA%%
    /** - Initialize message 57 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG2->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG2->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_57_MASK%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF1ARB  = (uint32)%%CAN2:CAN_2_MESSAGE_57_ENA%%U | (uint32)%%CAN2:CAN_2_IDENTIFIER_MODE%%U | (uint32)%%CAN2:CAN_2_MESSAGE_57_DIR%%U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_57_ID%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF1MCTL = 0x00001000U | (uint32)%%CAN2:CAN_2_MESSAGE_57_INT_ENA%%U | (uint32)%%CAN2:CAN_2_MESSAGE_57_RTR%%U | (uint32)%%CAN2:CAN_2_MESSAGE_57_EOB%%U | (uint32)%%CAN2:CAN_2_MESSAGE_57_DLC%%U;
    canREG2->IF1CMD  = (uint8) 0xF8U;
    canREG2->IF1NO   = 57U;

#endif
#if %%CAN2:CAN_2_MESSAGE_58_BOOL_ENA%%
    /** - Initialize message 58 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG2->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG2->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_58_MASK%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF2ARB  = (uint32)%%CAN2:CAN_2_MESSAGE_58_ENA%%U | (uint32)%%CAN2:CAN_2_IDENTIFIER_MODE%%U | (uint32)%%CAN2:CAN_2_MESSAGE_58_DIR%%U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_58_ID%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF2MCTL = 0x00001000U | (uint32)%%CAN2:CAN_2_MESSAGE_58_INT_ENA%%U | (uint32)%%CAN2:CAN_2_MESSAGE_58_RTR%%U | (uint32)%%CAN2:CAN_2_MESSAGE_58_EOB%%U | (uint32)%%CAN2:CAN_2_MESSAGE_58_DLC%%U;
    canREG2->IF2CMD  = (uint8) 0xF8U;
    canREG2->IF2NO   = 58U;

#endif
#if %%CAN2:CAN_2_MESSAGE_59_BOOL_ENA%%
    /** - Initialize message 59 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG2->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG2->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_59_MASK%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF1ARB  = (uint32)%%CAN2:CAN_2_MESSAGE_59_ENA%%U | (uint32)%%CAN2:CAN_2_IDENTIFIER_MODE%%U | (uint32)%%CAN2:CAN_2_MESSAGE_59_DIR%%U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_59_ID%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF1MCTL = 0x00001000U | (uint32)%%CAN2:CAN_2_MESSAGE_59_INT_ENA%%U | (uint32)%%CAN2:CAN_2_MESSAGE_59_RTR%%U | (uint32)%%CAN2:CAN_2_MESSAGE_59_EOB%%U | (uint32)%%CAN2:CAN_2_MESSAGE_59_DLC%%U;
    canREG2->IF1CMD  = (uint8) 0xF8U;
    canREG2->IF1NO   = 59U;

#endif
#if %%CAN2:CAN_2_MESSAGE_60_BOOL_ENA%%
    /** - Initialize message 60 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG2->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG2->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_60_MASK%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF2ARB  = (uint32)%%CAN2:CAN_2_MESSAGE_60_ENA%%U | (uint32)%%CAN2:CAN_2_IDENTIFIER_MODE%%U | (uint32)%%CAN2:CAN_2_MESSAGE_60_DIR%%U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_60_ID%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF2MCTL = 0x00001000U | (uint32)%%CAN2:CAN_2_MESSAGE_60_INT_ENA%%U | (uint32)%%CAN2:CAN_2_MESSAGE_60_RTR%%U | (uint32)%%CAN2:CAN_2_MESSAGE_60_EOB%%U | (uint32)%%CAN2:CAN_2_MESSAGE_60_DLC%%U;
    canREG2->IF2CMD  = (uint8) 0xF8U;
    canREG2->IF2NO   = 60U;

#endif
#if %%CAN2:CAN_2_MESSAGE_61_BOOL_ENA%%
    /** - Initialize message 61 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG2->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG2->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_61_MASK%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF1ARB  = (uint32)%%CAN2:CAN_2_MESSAGE_61_ENA%%U | (uint32)%%CAN2:CAN_2_IDENTIFIER_MODE%%U | (uint32)%%CAN2:CAN_2_MESSAGE_61_DIR%%U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_61_ID%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF1MCTL = 0x00001000U | (uint32)%%CAN2:CAN_2_MESSAGE_61_INT_ENA%%U | (uint32)%%CAN2:CAN_2_MESSAGE_61_RTR%%U | (uint32)%%CAN2:CAN_2_MESSAGE_61_EOB%%U | (uint32)%%CAN2:CAN_2_MESSAGE_61_DLC%%U;
    canREG2->IF1CMD  = (uint8) 0xF8U;
    canREG2->IF1NO   = 61U;

#endif
#if %%CAN2:CAN_2_MESSAGE_62_BOOL_ENA%%
    /** - Initialize message 62 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG2->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG2->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_62_MASK%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF2ARB  = (uint32)%%CAN2:CAN_2_MESSAGE_62_ENA%%U | (uint32)%%CAN2:CAN_2_IDENTIFIER_MODE%%U | (uint32)%%CAN2:CAN_2_MESSAGE_62_DIR%%U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_62_ID%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF2MCTL = 0x00001000U | (uint32)%%CAN2:CAN_2_MESSAGE_62_INT_ENA%%U | (uint32)%%CAN2:CAN_2_MESSAGE_62_RTR%%U | (uint32)%%CAN2:CAN_2_MESSAGE_62_EOB%%U | (uint32)%%CAN2:CAN_2_MESSAGE_62_DLC%%U;
    canREG2->IF2CMD  = (uint8) 0xF8U;
    canREG2->IF2NO   = 62U;

#endif
#if %%CAN2:CAN_2_MESSAGE_63_BOOL_ENA%%
    /** - Initialize message 63 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG2->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG2->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_63_MASK%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF1ARB  = (uint32)%%CAN2:CAN_2_MESSAGE_63_ENA%%U | (uint32)%%CAN2:CAN_2_IDENTIFIER_MODE%%U | (uint32)%%CAN2:CAN_2_MESSAGE_63_DIR%%U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_63_ID%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF1MCTL = 0x00001000U | (uint32)%%CAN2:CAN_2_MESSAGE_63_INT_ENA%%U | (uint32)%%CAN2:CAN_2_MESSAGE_63_RTR%%U | (uint32)%%CAN2:CAN_2_MESSAGE_63_EOB%%U | (uint32)%%CAN2:CAN_2_MESSAGE_63_DLC%%U;
    canREG2->IF1CMD  = (uint8) 0xF8U;
    canREG2->IF1NO   = 63U;

#endif
#if %%CAN2:CAN_2_MESSAGE_64_BOOL_ENA%%
    /** - Initialize message 64 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG2->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG2->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_64_MASK%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF2ARB  = (uint32)%%CAN2:CAN_2_MESSAGE_64_ENA%%U | (uint32)%%CAN2:CAN_2_IDENTIFIER_MODE%%U | (uint32)%%CAN2:CAN_2_MESSAGE_64_DIR%%U | (uint32)((uint32)((uint32)%%CAN2:CAN_2_MESSAGE_64_ID%%U & (uint32)%%CAN2:CAN_2_MASK%%U) << (uint32)%%CAN2:CAN_2_SHIFT%%U);
    canREG2->IF2MCTL = 0x00001000U | (uint32)%%CAN2:CAN_2_MESSAGE_64_INT_ENA%%U | (uint32)%%CAN2:CAN_2_MESSAGE_64_RTR%%U | (uint32)%%CAN2:CAN_2_MESSAGE_64_EOB%%U | (uint32)%%CAN2:CAN_2_MESSAGE_64_DLC%%U;
    canREG2->IF2CMD  = (uint8) 0xF8U;
    canREG2->IF2NO   = 64U;

#endif
    /** - Setup IF1 for data transmission 
    *     - Wait until IF1 is ready for use 
    *     - Set IF1 control byte
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG2->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */
    canREG2->IF1CMD  = 0x87U;

    /** - Setup IF2 for reading data
    *     - Wait until IF1 is ready for use 
    *     - Set IF1 control byte
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG2->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */
    canREG2->IF2CMD = 0x17U;

    /** - Setup bit timing 
    *     - Setup baud rate prescaler extension
    *     - Setup TSeg2
    *     - Setup TSeg1
    *     - Setup sample jump width
    *     - Setup baud rate prescaler
    */
    canREG2->BTR = (uint32)((uint32)%%CAN2:CAN_2_BRPE%%U << 16U) |
                   (uint32)((uint32)(%%CAN2:CAN_2_PHASE_SEG%%U - 1U) << 12U) |
                   (uint32)((uint32)((%%CAN2:CAN_2_PROP_SEG%%U + %%CAN2:CAN_2_PHASE_SEG%%U) - 1U) << 8U) |
                   (uint32)((uint32)(%%CAN2:CAN_2_SJW%%U - 1U) << 6U) |
                   (uint32)%%CAN2:CAN_2_BRP%%U;		
#else

    /** - Setup control register
    *     - Enter initialization mode
    */
    canREG2->CTL = 0x00000001U;
	
   /** - CAN2 Port output values */
    canREG2->TIOC =  (uint32)((uint32)%%CAN2:CAN_2_PORT_TX_PSL%%U  << 18U )
                   | (uint32)((uint32)%%CAN2:CAN_2_PORT_TX_PULDIS%%U  << 17U )
                   | (uint32)((uint32)%%CAN2:CAN_2_PORT_TX_PDR%%U  << 16U )  
                   | (uint32)((uint32)%%CAN2:CAN_2_PORT_TX_FUN%%U  << 3U )  
                   | (uint32)((uint32)%%CAN2:CAN_2_PORT_TX_DIR%%U  << 2U )    
                   | (uint32)((uint32)%%CAN2:CAN_2_PORT_TX_DOUT%%U << 1U );
                   
    canREG2->RIOC =  (uint32)((uint32)%%CAN2:CAN_2_PORT_RX_PSL%%U  << 18U )    
                   | (uint32)((uint32)%%CAN2:CAN_2_PORT_RX_PULDIS%%U  << 17U )  
                   | (uint32)((uint32)%%CAN2:CAN_2_PORT_RX_PDR%%U  << 16U )   
                   | (uint32)((uint32)%%CAN2:CAN_2_PORT_RX_FUN%%U  << 3U )  
                   | (uint32)((uint32)%%CAN2:CAN_2_PORT_RX_DIR%%U  << 2U )
                   | (uint32)((uint32)%%CAN2:CAN_2_PORT_RX_DOUT%%U <<1U );       
#endif

#if %%CAN2:CAN_2_PIN_MODE%%

   /** - CAN2 Port output values */
    canREG2->TIOC =  (uint32)((uint32)%%CAN2:CAN_2_PORT_TX_PSL%%U  << 18U )
                   | (uint32)((uint32)%%CAN2:CAN_2_PORT_TX_PULDIS%%U  << 17U )
                   | (uint32)((uint32)%%CAN2:CAN_2_PORT_TX_PDR%%U  << 16U )  
                   | (uint32)((uint32)%%CAN2:CAN_2_PORT_TX_FUN%%U  << 3U )  
                   | (uint32)((uint32)%%CAN2:CAN_2_PORT_TX_DIR%%U  << 2U )    
                   | (uint32)((uint32)%%CAN2:CAN_2_PORT_TX_DOUT%%U << 1U );
                   
    canREG2->RIOC =  (uint32)((uint32)%%CAN2:CAN_2_PORT_RX_PSL%%U  << 18U )    
                   | (uint32)((uint32)%%CAN2:CAN_2_PORT_RX_PULDIS%%U  << 17U )  
                   | (uint32)((uint32)%%CAN2:CAN_2_PORT_RX_PDR%%U  << 16U )   
                   | (uint32)((uint32)%%CAN2:CAN_2_PORT_RX_FUN%%U  << 3U )  
                   | (uint32)((uint32)%%CAN2:CAN_2_PORT_RX_DIR%%U  << 2U )
                   | (uint32)((uint32)%%CAN2:CAN_2_PORT_RX_DOUT%%U <<1U );   

    /** - Leave configuration and initialization mode  */
    canREG2->CTL &= ~(uint32)(0x00000041U);
#endif
#endif

#if %%SYSTEM:CAN3_ENABLE%%
    /** @b Initialize @b CAN3: */

#if %%CAN3:CAN_3_PIN_MODE%%
    /** - Setup control register
    *     - Disable automatic wakeup on bus activity
    *     - Local power down mode disabled
    *     - Disable DMA request lines
    *     - Enable global Interrupt Line 0 and 1
    *     - Disable debug mode
    *     - Release from software reset
    *     - Enable/Disable parity or ECC
    *     - Enable/Disable auto bus on timer
    *     - Setup message completion before entering debug state
    *     - Setup normal operation mode
    *     - Request write access to the configuration registers
    *     - Setup automatic retransmission of messages
    *     - Disable error interrupts
    *     - Disable status interrupts
    *     - Enter initialization mode
    */
    canREG3->CTL = (uint32)%%CAN3:CAN_3_AUTO_BUS_ON%%U 
                 | (uint32)%%CAN3:CAN_3_AUTO_RETRANSMISSION%%U 
                 | (uint32)((uint32)%%CAN3:CAN_3_RAM_PARITY_ENA%%U << 10U)
                 | 0x00020043U;

    /** - Clear all pending error flags and reset current status */
    canREG3->ES |= 0xFFFFFFFFU;

    /** - Assign interrupt level for messages */
    canREG3->INTMUXx[0U] = (uint32)%%CAN3:CAN_3_MESSAGE_64_INT_LEVEL%%U
                         | (uint32)%%CAN3:CAN_3_MESSAGE_1_INT_LEVEL%%U
                         | (uint32)%%CAN3:CAN_3_MESSAGE_2_INT_LEVEL%%U
                         | (uint32)%%CAN3:CAN_3_MESSAGE_3_INT_LEVEL%%U
                         | (uint32)%%CAN3:CAN_3_MESSAGE_4_INT_LEVEL%%U
                         | (uint32)%%CAN3:CAN_3_MESSAGE_5_INT_LEVEL%%U
                         | (uint32)%%CAN3:CAN_3_MESSAGE_6_INT_LEVEL%%U
                         | (uint32)%%CAN3:CAN_3_MESSAGE_7_INT_LEVEL%%U
                         | (uint32)%%CAN3:CAN_3_MESSAGE_8_INT_LEVEL%%U
                         | (uint32)%%CAN3:CAN_3_MESSAGE_9_INT_LEVEL%%U
                         | (uint32)%%CAN3:CAN_3_MESSAGE_10_INT_LEVEL%%U
                         | (uint32)%%CAN3:CAN_3_MESSAGE_11_INT_LEVEL%%U
                         | (uint32)%%CAN3:CAN_3_MESSAGE_12_INT_LEVEL%%U
                         | (uint32)%%CAN3:CAN_3_MESSAGE_13_INT_LEVEL%%U
                         | (uint32)%%CAN3:CAN_3_MESSAGE_14_INT_LEVEL%%U
                         | (uint32)%%CAN3:CAN_3_MESSAGE_15_INT_LEVEL%%U
                         | (uint32)%%CAN3:CAN_3_MESSAGE_16_INT_LEVEL%%U
                         | (uint32)%%CAN3:CAN_3_MESSAGE_17_INT_LEVEL%%U
                         | (uint32)%%CAN3:CAN_3_MESSAGE_18_INT_LEVEL%%U
                         | (uint32)%%CAN3:CAN_3_MESSAGE_19_INT_LEVEL%%U
                         | (uint32)%%CAN3:CAN_3_MESSAGE_20_INT_LEVEL%%U
                         | (uint32)%%CAN3:CAN_3_MESSAGE_21_INT_LEVEL%%U
                         | (uint32)%%CAN3:CAN_3_MESSAGE_22_INT_LEVEL%%U
                         | (uint32)%%CAN3:CAN_3_MESSAGE_23_INT_LEVEL%%U
                         | (uint32)%%CAN3:CAN_3_MESSAGE_24_INT_LEVEL%%U
                         | (uint32)%%CAN3:CAN_3_MESSAGE_25_INT_LEVEL%%U
                         | (uint32)%%CAN3:CAN_3_MESSAGE_26_INT_LEVEL%%U
                         | (uint32)%%CAN3:CAN_3_MESSAGE_27_INT_LEVEL%%U
                         | (uint32)%%CAN3:CAN_3_MESSAGE_28_INT_LEVEL%%U
                         | (uint32)%%CAN3:CAN_3_MESSAGE_29_INT_LEVEL%%U
                         | (uint32)%%CAN3:CAN_3_MESSAGE_30_INT_LEVEL%%U
                         | (uint32)%%CAN3:CAN_3_MESSAGE_31_INT_LEVEL%%U;
	canREG3->INTMUXx[1U] = (uint32)%%CAN3:CAN_3_MESSAGE_32_INT_LEVEL%%U
                         | (uint32)%%CAN3:CAN_3_MESSAGE_33_INT_LEVEL%%U
                         | (uint32)%%CAN3:CAN_3_MESSAGE_34_INT_LEVEL%%U
                         | (uint32)%%CAN3:CAN_3_MESSAGE_35_INT_LEVEL%%U
                         | (uint32)%%CAN3:CAN_3_MESSAGE_36_INT_LEVEL%%U
                         | (uint32)%%CAN3:CAN_3_MESSAGE_37_INT_LEVEL%%U
                         | (uint32)%%CAN3:CAN_3_MESSAGE_38_INT_LEVEL%%U
                         | (uint32)%%CAN3:CAN_3_MESSAGE_39_INT_LEVEL%%U
                         | (uint32)%%CAN3:CAN_3_MESSAGE_40_INT_LEVEL%%U
                         | (uint32)%%CAN3:CAN_3_MESSAGE_41_INT_LEVEL%%U
                         | (uint32)%%CAN3:CAN_3_MESSAGE_42_INT_LEVEL%%U
                         | (uint32)%%CAN3:CAN_3_MESSAGE_43_INT_LEVEL%%U
                         | (uint32)%%CAN3:CAN_3_MESSAGE_44_INT_LEVEL%%U
                         | (uint32)%%CAN3:CAN_3_MESSAGE_45_INT_LEVEL%%U
                         | (uint32)%%CAN3:CAN_3_MESSAGE_46_INT_LEVEL%%U
                         | (uint32)%%CAN3:CAN_3_MESSAGE_47_INT_LEVEL%%U
                         | (uint32)%%CAN3:CAN_3_MESSAGE_48_INT_LEVEL%%U
                         | (uint32)%%CAN3:CAN_3_MESSAGE_49_INT_LEVEL%%U
                         | (uint32)%%CAN3:CAN_3_MESSAGE_50_INT_LEVEL%%U
                         | (uint32)%%CAN3:CAN_3_MESSAGE_51_INT_LEVEL%%U
                         | (uint32)%%CAN3:CAN_3_MESSAGE_52_INT_LEVEL%%U
                         | (uint32)%%CAN3:CAN_3_MESSAGE_53_INT_LEVEL%%U
                         | (uint32)%%CAN3:CAN_3_MESSAGE_54_INT_LEVEL%%U
                         | (uint32)%%CAN3:CAN_3_MESSAGE_55_INT_LEVEL%%U
                         | (uint32)%%CAN3:CAN_3_MESSAGE_56_INT_LEVEL%%U
                         | (uint32)%%CAN3:CAN_3_MESSAGE_57_INT_LEVEL%%U
                         | (uint32)%%CAN3:CAN_3_MESSAGE_58_INT_LEVEL%%U
                         | (uint32)%%CAN3:CAN_3_MESSAGE_59_INT_LEVEL%%U
                         | (uint32)%%CAN3:CAN_3_MESSAGE_60_INT_LEVEL%%U
                         | (uint32)%%CAN3:CAN_3_MESSAGE_61_INT_LEVEL%%U
                         | (uint32)%%CAN3:CAN_3_MESSAGE_62_INT_LEVEL%%U
                         | (uint32)%%CAN3:CAN_3_MESSAGE_63_INT_LEVEL%%U;

    /** - Setup auto bus on timer period */
    canREG3->ABOTR = (uint32)%%CAN3:CAN_3_AUTO_BUS_ON_TR%%U;

#if %%CAN3:CAN_3_MESSAGE_1_BOOL_ENA%%
    /** - Initialize message 1 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG3->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */


    canREG3->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_1_MASK%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF1ARB  = (uint32)%%CAN3:CAN_3_MESSAGE_1_ENA%%U | (uint32)%%CAN3:CAN_3_IDENTIFIER_MODE%%U | (uint32)%%CAN3:CAN_3_MESSAGE_1_DIR%%U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_1_ID%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF1MCTL = 0x00001000U | (uint32)%%CAN3:CAN_3_MESSAGE_1_INT_ENA%%U | (uint32)%%CAN3:CAN_3_MESSAGE_1_RTR%%U | (uint32)%%CAN3:CAN_3_MESSAGE_1_EOB%%U | (uint32)%%CAN3:CAN_3_MESSAGE_1_DLC%%U;
    canREG3->IF1CMD  = (uint8) 0xF8U;
    canREG3->IF1NO   = 1U;

#endif
#if %%CAN3:CAN_3_MESSAGE_2_BOOL_ENA%%
    /** - Initialize message 2 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG3->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG3->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_2_MASK%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF2ARB  = (uint32)%%CAN3:CAN_3_MESSAGE_2_ENA%%U | (uint32)%%CAN3:CAN_3_IDENTIFIER_MODE%%U | (uint32)%%CAN3:CAN_3_MESSAGE_2_DIR%%U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_2_ID%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF2MCTL = 0x00001000U | (uint32)%%CAN3:CAN_3_MESSAGE_2_INT_ENA%%U | (uint32)%%CAN3:CAN_3_MESSAGE_2_RTR%%U | (uint32)%%CAN3:CAN_3_MESSAGE_2_EOB%%U | (uint32)%%CAN3:CAN_3_MESSAGE_2_DLC%%U;
    canREG3->IF2CMD  = (uint8) 0xF8U;
    canREG3->IF2NO   = 2U;

#endif
#if %%CAN3:CAN_3_MESSAGE_3_BOOL_ENA%%
    /** - Initialize message 3 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG3->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG3->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_3_MASK%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF1ARB  = (uint32)%%CAN3:CAN_3_MESSAGE_3_ENA%%U | (uint32)%%CAN3:CAN_3_IDENTIFIER_MODE%%U | (uint32)%%CAN3:CAN_3_MESSAGE_3_DIR%%U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_3_ID%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF1MCTL = 0x00001000U | (uint32)%%CAN3:CAN_3_MESSAGE_3_INT_ENA%%U | (uint32)%%CAN3:CAN_3_MESSAGE_3_RTR%%U | (uint32)%%CAN3:CAN_3_MESSAGE_3_EOB%%U | (uint32)%%CAN3:CAN_3_MESSAGE_3_DLC%%U;
    canREG3->IF1CMD  = (uint8) 0xF8U;
    canREG3->IF1NO   = 3U;

#endif
#if %%CAN3:CAN_3_MESSAGE_4_BOOL_ENA%%
    /** - Initialize message 4 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG3->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG3->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_4_MASK%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF2ARB  = (uint32)%%CAN3:CAN_3_MESSAGE_4_ENA%%U | (uint32)%%CAN3:CAN_3_IDENTIFIER_MODE%%U | (uint32)%%CAN3:CAN_3_MESSAGE_4_DIR%%U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_4_ID%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF2MCTL = 0x00001000U | (uint32)%%CAN3:CAN_3_MESSAGE_4_INT_ENA%%U | (uint32)%%CAN3:CAN_3_MESSAGE_4_RTR%%U | (uint32)%%CAN3:CAN_3_MESSAGE_4_EOB%%U | (uint32)%%CAN3:CAN_3_MESSAGE_4_DLC%%U;
    canREG3->IF2CMD  = (uint8) 0xF8U;
    canREG3->IF2NO   = 4U;

#endif
#if %%CAN3:CAN_3_MESSAGE_5_BOOL_ENA%%
    /** - Initialize message 5 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG3->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG3->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_5_MASK%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF1ARB  = (uint32)%%CAN3:CAN_3_MESSAGE_5_ENA%%U | (uint32)%%CAN3:CAN_3_IDENTIFIER_MODE%%U | (uint32)%%CAN3:CAN_3_MESSAGE_5_DIR%%U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_5_ID%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF1MCTL = 0x00001000U | (uint32)%%CAN3:CAN_3_MESSAGE_5_INT_ENA%%U | (uint32)%%CAN3:CAN_3_MESSAGE_5_RTR%%U | (uint32)%%CAN3:CAN_3_MESSAGE_5_EOB%%U | (uint32)%%CAN3:CAN_3_MESSAGE_5_DLC%%U;
    canREG3->IF1CMD  = (uint8) 0xF8U;
    canREG3->IF1NO   = 5U;

#endif
#if %%CAN3:CAN_3_MESSAGE_6_BOOL_ENA%%
    /** - Initialize message 6 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG3->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG3->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_6_MASK%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF2ARB  = (uint32)%%CAN3:CAN_3_MESSAGE_6_ENA%%U | (uint32)%%CAN3:CAN_3_IDENTIFIER_MODE%%U | (uint32)%%CAN3:CAN_3_MESSAGE_6_DIR%%U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_6_ID%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF2MCTL = 0x00001000U | (uint32)%%CAN3:CAN_3_MESSAGE_6_INT_ENA%%U | (uint32)%%CAN3:CAN_3_MESSAGE_6_RTR%%U | (uint32)%%CAN3:CAN_3_MESSAGE_6_EOB%%U | (uint32)%%CAN3:CAN_3_MESSAGE_6_DLC%%U;
    canREG3->IF2CMD  = (uint8) 0xF8U;
    canREG3->IF2NO   = 6U;

#endif
#if %%CAN3:CAN_3_MESSAGE_7_BOOL_ENA%%
    /** - Initialize message 7 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG3->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG3->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_7_MASK%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF1ARB  = (uint32)%%CAN3:CAN_3_MESSAGE_7_ENA%%U | (uint32)%%CAN3:CAN_3_IDENTIFIER_MODE%%U | (uint32)%%CAN3:CAN_3_MESSAGE_7_DIR%%U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_7_ID%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF1MCTL = 0x00001000U | (uint32)%%CAN3:CAN_3_MESSAGE_7_INT_ENA%%U | (uint32)%%CAN3:CAN_3_MESSAGE_7_RTR%%U | (uint32)%%CAN3:CAN_3_MESSAGE_7_EOB%%U | (uint32)%%CAN3:CAN_3_MESSAGE_7_DLC%%U;
    canREG3->IF1CMD  = (uint8) 0xF8U;
    canREG3->IF1NO   = 7U;

#endif
#if %%CAN3:CAN_3_MESSAGE_8_BOOL_ENA%%
    /** - Initialize message 8 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG3->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG3->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_8_MASK%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF2ARB  = (uint32)%%CAN3:CAN_3_MESSAGE_8_ENA%%U | (uint32)%%CAN3:CAN_3_IDENTIFIER_MODE%%U | (uint32)%%CAN3:CAN_3_MESSAGE_8_DIR%%U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_8_ID%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF2MCTL = 0x00001000U | (uint32)%%CAN3:CAN_3_MESSAGE_8_INT_ENA%%U | (uint32)%%CAN3:CAN_3_MESSAGE_8_RTR%%U | (uint32)%%CAN3:CAN_3_MESSAGE_8_EOB%%U | (uint32)%%CAN3:CAN_3_MESSAGE_8_DLC%%U;
    canREG3->IF2CMD  = (uint8) 0xF8U;
    canREG3->IF2NO   = 8U;

#endif
#if %%CAN3:CAN_3_MESSAGE_9_BOOL_ENA%%
    /** - Initialize message 9 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG3->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG3->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_9_MASK%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF1ARB  = (uint32)%%CAN3:CAN_3_MESSAGE_9_ENA%%U | (uint32)%%CAN3:CAN_3_IDENTIFIER_MODE%%U | (uint32)%%CAN3:CAN_3_MESSAGE_9_DIR%%U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_9_ID%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF1MCTL = 0x00001000U | (uint32)%%CAN3:CAN_3_MESSAGE_9_INT_ENA%%U | (uint32)%%CAN3:CAN_3_MESSAGE_9_RTR%%U | (uint32)%%CAN3:CAN_3_MESSAGE_9_EOB%%U | (uint32)%%CAN3:CAN_3_MESSAGE_9_DLC%%U;
    canREG3->IF1CMD  = (uint8) 0xF8U;
    canREG3->IF1NO   = 9U;

#endif
#if %%CAN3:CAN_3_MESSAGE_10_BOOL_ENA%%
    /** - Initialize message 10 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG3->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG3->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_10_MASK%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF2ARB  = (uint32)%%CAN3:CAN_3_MESSAGE_10_ENA%%U | (uint32)%%CAN3:CAN_3_IDENTIFIER_MODE%%U | (uint32)%%CAN3:CAN_3_MESSAGE_10_DIR%%U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_10_ID%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF2MCTL = 0x00001000U | (uint32)%%CAN3:CAN_3_MESSAGE_10_INT_ENA%%U | (uint32)%%CAN3:CAN_3_MESSAGE_10_RTR%%U | (uint32)%%CAN3:CAN_3_MESSAGE_10_EOB%%U | (uint32)%%CAN3:CAN_3_MESSAGE_10_DLC%%U;
    canREG3->IF2CMD  = (uint8) 0xF8U;
    canREG3->IF2NO   = 10U;

#endif
#if %%CAN3:CAN_3_MESSAGE_11_BOOL_ENA%%
    /** - Initialize message 11 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG3->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG3->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_11_MASK%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF1ARB  = (uint32)%%CAN3:CAN_3_MESSAGE_11_ENA%%U | (uint32)%%CAN3:CAN_3_IDENTIFIER_MODE%%U | (uint32)%%CAN3:CAN_3_MESSAGE_11_DIR%%U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_11_ID%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF1MCTL = 0x00001000U | (uint32)%%CAN3:CAN_3_MESSAGE_11_INT_ENA%%U | (uint32)%%CAN3:CAN_3_MESSAGE_11_RTR%%U | (uint32)%%CAN3:CAN_3_MESSAGE_11_EOB%%U | (uint32)%%CAN3:CAN_3_MESSAGE_11_DLC%%U;
    canREG3->IF1CMD  = (uint8) 0xF8U;
    canREG3->IF1NO   = 11U;

#endif
#if %%CAN3:CAN_3_MESSAGE_12_BOOL_ENA%%
    /** - Initialize message 12 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG3->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG3->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_12_MASK%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF2ARB  = (uint32)%%CAN3:CAN_3_MESSAGE_12_ENA%%U | (uint32)%%CAN3:CAN_3_IDENTIFIER_MODE%%U | (uint32)%%CAN3:CAN_3_MESSAGE_12_DIR%%U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_12_ID%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF2MCTL = 0x00001000U | (uint32)%%CAN3:CAN_3_MESSAGE_12_INT_ENA%%U | (uint32)%%CAN3:CAN_3_MESSAGE_12_RTR%%U | (uint32)%%CAN3:CAN_3_MESSAGE_12_EOB%%U | (uint32)%%CAN3:CAN_3_MESSAGE_12_DLC%%U;
    canREG3->IF2CMD  = (uint8) 0xF8U;
    canREG3->IF2NO   = 12U;

#endif
#if %%CAN3:CAN_3_MESSAGE_13_BOOL_ENA%%
    /** - Initialize message 13 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG3->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG3->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_13_MASK%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF1ARB  = (uint32)%%CAN3:CAN_3_MESSAGE_13_ENA%%U | (uint32)%%CAN3:CAN_3_IDENTIFIER_MODE%%U | (uint32)%%CAN3:CAN_3_MESSAGE_13_DIR%%U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_13_ID%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF1MCTL = 0x00001000U | (uint32)%%CAN3:CAN_3_MESSAGE_13_INT_ENA%%U | (uint32)%%CAN3:CAN_3_MESSAGE_13_RTR%%U | (uint32)%%CAN3:CAN_3_MESSAGE_13_EOB%%U | (uint32)%%CAN3:CAN_3_MESSAGE_13_DLC%%U;
    canREG3->IF1CMD  = (uint8) 0xF8U;
    canREG3->IF1NO   = 13U;

#endif
#if %%CAN3:CAN_3_MESSAGE_14_BOOL_ENA%%
    /** - Initialize message 14 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG3->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG3->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_14_MASK%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF2ARB  = (uint32)%%CAN3:CAN_3_MESSAGE_14_ENA%%U | (uint32)%%CAN3:CAN_3_IDENTIFIER_MODE%%U | (uint32)%%CAN3:CAN_3_MESSAGE_14_DIR%%U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_14_ID%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF2MCTL = 0x00001000U | (uint32)%%CAN3:CAN_3_MESSAGE_14_INT_ENA%%U | (uint32)%%CAN3:CAN_3_MESSAGE_14_RTR%%U | (uint32)%%CAN3:CAN_3_MESSAGE_14_EOB%%U | (uint32)%%CAN3:CAN_3_MESSAGE_14_DLC%%U;
    canREG3->IF2CMD  = (uint8) 0xF8U;
    canREG3->IF2NO   = 14U;

#endif
#if %%CAN3:CAN_3_MESSAGE_15_BOOL_ENA%%
    /** - Initialize message 15 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG3->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG3->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_15_MASK%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF1ARB  = (uint32)%%CAN3:CAN_3_MESSAGE_15_ENA%%U | (uint32)%%CAN3:CAN_3_IDENTIFIER_MODE%%U | (uint32)%%CAN3:CAN_3_MESSAGE_15_DIR%%U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_15_ID%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF1MCTL = 0x00001000U | (uint32)%%CAN3:CAN_3_MESSAGE_15_INT_ENA%%U | (uint32)%%CAN3:CAN_3_MESSAGE_15_RTR%%U | (uint32)%%CAN3:CAN_3_MESSAGE_15_EOB%%U | (uint32)%%CAN3:CAN_3_MESSAGE_15_DLC%%U;
    canREG3->IF1CMD  = (uint8) 0xF8U;
    canREG3->IF1NO   = 15U;

#endif
#if %%CAN3:CAN_3_MESSAGE_16_BOOL_ENA%%
    /** - Initialize message 16 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG3->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG3->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_16_MASK%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF2ARB  = (uint32)%%CAN3:CAN_3_MESSAGE_16_ENA%%U | (uint32)%%CAN3:CAN_3_IDENTIFIER_MODE%%U | (uint32)%%CAN3:CAN_3_MESSAGE_16_DIR%%U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_16_ID%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF2MCTL = 0x00001000U | (uint32)%%CAN3:CAN_3_MESSAGE_16_INT_ENA%%U | (uint32)%%CAN3:CAN_3_MESSAGE_16_RTR%%U | (uint32)%%CAN3:CAN_3_MESSAGE_16_EOB%%U | (uint32)%%CAN3:CAN_3_MESSAGE_16_DLC%%U;
    canREG3->IF2CMD  = (uint8) 0xF8U;
    canREG3->IF2NO   = 16U;

#endif
#if %%CAN3:CAN_3_MESSAGE_17_BOOL_ENA%%
    /** - Initialize message 17 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG3->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG3->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_17_MASK%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF1ARB  = (uint32)%%CAN3:CAN_3_MESSAGE_17_ENA%%U | (uint32)%%CAN3:CAN_3_IDENTIFIER_MODE%%U | (uint32)%%CAN3:CAN_3_MESSAGE_17_DIR%%U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_17_ID%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF1MCTL = 0x00001000U | (uint32)%%CAN3:CAN_3_MESSAGE_17_INT_ENA%%U | (uint32)%%CAN3:CAN_3_MESSAGE_17_RTR%%U | (uint32)%%CAN3:CAN_3_MESSAGE_17_EOB%%U | (uint32)%%CAN3:CAN_3_MESSAGE_17_DLC%%U;
    canREG3->IF1CMD  = (uint8) 0xF8U;
    canREG3->IF1NO   = 17U;

#endif
#if %%CAN3:CAN_3_MESSAGE_18_BOOL_ENA%%
    /** - Initialize message 18 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG3->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG3->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_18_MASK%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF2ARB  = (uint32)%%CAN3:CAN_3_MESSAGE_18_ENA%%U | (uint32)%%CAN3:CAN_3_IDENTIFIER_MODE%%U | (uint32)%%CAN3:CAN_3_MESSAGE_18_DIR%%U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_18_ID%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF2MCTL = 0x00001000U | (uint32)%%CAN3:CAN_3_MESSAGE_18_INT_ENA%%U | (uint32)%%CAN3:CAN_3_MESSAGE_18_RTR%%U | (uint32)%%CAN3:CAN_3_MESSAGE_18_EOB%%U | (uint32)%%CAN3:CAN_3_MESSAGE_18_DLC%%U;
    canREG3->IF2CMD  = (uint8) 0xF8U;
    canREG3->IF2NO   = 18U;

#endif
#if %%CAN3:CAN_3_MESSAGE_19_BOOL_ENA%%
    /** - Initialize message 19 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG3->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG3->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_19_MASK%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF1ARB  = (uint32)%%CAN3:CAN_3_MESSAGE_19_ENA%%U | (uint32)%%CAN3:CAN_3_IDENTIFIER_MODE%%U | (uint32)%%CAN3:CAN_3_MESSAGE_19_DIR%%U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_19_ID%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF1MCTL = 0x00001000U | (uint32)%%CAN3:CAN_3_MESSAGE_19_INT_ENA%%U | (uint32)%%CAN3:CAN_3_MESSAGE_19_RTR%%U | (uint32)%%CAN3:CAN_3_MESSAGE_19_EOB%%U | (uint32)%%CAN3:CAN_3_MESSAGE_19_DLC%%U;
    canREG3->IF1CMD  = (uint8) 0xF8U;
    canREG3->IF1NO   = 19U;

#endif
#if %%CAN3:CAN_3_MESSAGE_20_BOOL_ENA%%
    /** - Initialize message 20 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG3->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG3->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_20_MASK%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF2ARB  = (uint32)%%CAN3:CAN_3_MESSAGE_20_ENA%%U | (uint32)%%CAN3:CAN_3_IDENTIFIER_MODE%%U | (uint32)%%CAN3:CAN_3_MESSAGE_20_DIR%%U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_20_ID%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF2MCTL = 0x00001000U | (uint32)%%CAN3:CAN_3_MESSAGE_20_INT_ENA%%U | (uint32)%%CAN3:CAN_3_MESSAGE_20_RTR%%U | (uint32)%%CAN3:CAN_3_MESSAGE_20_EOB%%U | (uint32)%%CAN3:CAN_3_MESSAGE_20_DLC%%U;
    canREG3->IF2CMD  = (uint8) 0xF8U;
    canREG3->IF2NO   = 20U;

#endif
#if %%CAN3:CAN_3_MESSAGE_21_BOOL_ENA%%
    /** - Initialize message 21 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG3->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG3->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_21_MASK%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF1ARB  = (uint32)%%CAN3:CAN_3_MESSAGE_21_ENA%%U | (uint32)%%CAN3:CAN_3_IDENTIFIER_MODE%%U | (uint32)%%CAN3:CAN_3_MESSAGE_21_DIR%%U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_21_ID%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF1MCTL = 0x00001000U | (uint32)%%CAN3:CAN_3_MESSAGE_21_INT_ENA%%U | (uint32)%%CAN3:CAN_3_MESSAGE_21_RTR%%U | (uint32)%%CAN3:CAN_3_MESSAGE_21_EOB%%U | (uint32)%%CAN3:CAN_3_MESSAGE_21_DLC%%U;
    canREG3->IF1CMD  = (uint8) 0xF8U;
    canREG3->IF1NO   = 21U;

#endif
#if %%CAN3:CAN_3_MESSAGE_22_BOOL_ENA%%
    /** - Initialize message 22 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG3->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG3->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_22_MASK%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF2ARB  = (uint32)%%CAN3:CAN_3_MESSAGE_22_ENA%%U | (uint32)%%CAN3:CAN_3_IDENTIFIER_MODE%%U | (uint32)%%CAN3:CAN_3_MESSAGE_22_DIR%%U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_22_ID%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF2MCTL = 0x00001000U | (uint32)%%CAN3:CAN_3_MESSAGE_22_INT_ENA%%U | (uint32)%%CAN3:CAN_3_MESSAGE_22_RTR%%U | (uint32)%%CAN3:CAN_3_MESSAGE_22_EOB%%U | (uint32)%%CAN3:CAN_3_MESSAGE_22_DLC%%U;
    canREG3->IF2CMD  = (uint8) 0xF8U;
    canREG3->IF2NO   = 22U;

#endif
#if %%CAN3:CAN_3_MESSAGE_23_BOOL_ENA%%
    /** - Initialize message 23 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG3->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG3->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_23_MASK%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF1ARB  = (uint32)%%CAN3:CAN_3_MESSAGE_23_ENA%%U | (uint32)%%CAN3:CAN_3_IDENTIFIER_MODE%%U | (uint32)%%CAN3:CAN_3_MESSAGE_23_DIR%%U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_23_ID%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF1MCTL = 0x00001000U | (uint32)%%CAN3:CAN_3_MESSAGE_23_INT_ENA%%U | (uint32)%%CAN3:CAN_3_MESSAGE_23_RTR%%U | (uint32)%%CAN3:CAN_3_MESSAGE_23_EOB%%U | (uint32)%%CAN3:CAN_3_MESSAGE_23_DLC%%U;
    canREG3->IF1CMD  = (uint8) 0xF8U;
    canREG3->IF1NO   = 23U;

#endif
#if %%CAN3:CAN_3_MESSAGE_24_BOOL_ENA%%
    /** - Initialize message 24 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG3->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG3->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_24_MASK%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF2ARB  = (uint32)%%CAN3:CAN_3_MESSAGE_24_ENA%%U | (uint32)%%CAN3:CAN_3_IDENTIFIER_MODE%%U | (uint32)%%CAN3:CAN_3_MESSAGE_24_DIR%%U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_24_ID%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF2MCTL = 0x00001000U | (uint32)%%CAN3:CAN_3_MESSAGE_24_INT_ENA%%U | (uint32)%%CAN3:CAN_3_MESSAGE_24_RTR%%U | (uint32)%%CAN3:CAN_3_MESSAGE_24_EOB%%U | (uint32)%%CAN3:CAN_3_MESSAGE_24_DLC%%U;
    canREG3->IF2CMD  = (uint8) 0xF8U;
    canREG3->IF2NO   = 24U;

#endif
#if %%CAN3:CAN_3_MESSAGE_25_BOOL_ENA%%
    /** - Initialize message 25 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG3->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG3->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_25_MASK%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF1ARB  = (uint32)%%CAN3:CAN_3_MESSAGE_25_ENA%%U | (uint32)%%CAN3:CAN_3_IDENTIFIER_MODE%%U | (uint32)%%CAN3:CAN_3_MESSAGE_25_DIR%%U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_25_ID%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF1MCTL = 0x00001000U | (uint32)%%CAN3:CAN_3_MESSAGE_25_INT_ENA%%U | (uint32)%%CAN3:CAN_3_MESSAGE_25_RTR%%U | (uint32)%%CAN3:CAN_3_MESSAGE_25_EOB%%U | (uint32)%%CAN3:CAN_3_MESSAGE_25_DLC%%U;
    canREG3->IF1CMD  = (uint8) 0xF8U;
    canREG3->IF1NO   = 25U;

#endif
#if %%CAN3:CAN_3_MESSAGE_26_BOOL_ENA%%
    /** - Initialize message 26 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG3->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG3->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_26_MASK%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF2ARB  = (uint32)%%CAN3:CAN_3_MESSAGE_26_ENA%%U | (uint32)%%CAN3:CAN_3_IDENTIFIER_MODE%%U | (uint32)%%CAN3:CAN_3_MESSAGE_26_DIR%%U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_26_ID%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF2MCTL = 0x00001000U | (uint32)%%CAN3:CAN_3_MESSAGE_26_INT_ENA%%U | (uint32)%%CAN3:CAN_3_MESSAGE_26_RTR%%U | (uint32)%%CAN3:CAN_3_MESSAGE_26_EOB%%U | (uint32)%%CAN3:CAN_3_MESSAGE_26_DLC%%U;
    canREG3->IF2CMD  = (uint8) 0xF8U;
    canREG3->IF2NO   = 26U;

#endif
#if %%CAN3:CAN_3_MESSAGE_27_BOOL_ENA%%
    /** - Initialize message 27 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG3->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG3->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_27_MASK%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF1ARB  = (uint32)%%CAN3:CAN_3_MESSAGE_27_ENA%%U | (uint32)%%CAN3:CAN_3_IDENTIFIER_MODE%%U | (uint32)%%CAN3:CAN_3_MESSAGE_27_DIR%%U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_27_ID%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF1MCTL = 0x00001000U | (uint32)%%CAN3:CAN_3_MESSAGE_27_INT_ENA%%U | (uint32)%%CAN3:CAN_3_MESSAGE_27_RTR%%U | (uint32)%%CAN3:CAN_3_MESSAGE_27_EOB%%U | (uint32)%%CAN3:CAN_3_MESSAGE_27_DLC%%U;
    canREG3->IF1CMD  = (uint8) 0xF8U;
    canREG3->IF1NO   = 27U;

#endif
#if %%CAN3:CAN_3_MESSAGE_28_BOOL_ENA%%
    /** - Initialize message 28 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG3->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG3->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_28_MASK%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF2ARB  = (uint32)%%CAN3:CAN_3_MESSAGE_28_ENA%%U | (uint32)%%CAN3:CAN_3_IDENTIFIER_MODE%%U | (uint32)%%CAN3:CAN_3_MESSAGE_28_DIR%%U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_28_ID%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF2MCTL = 0x00001000U | (uint32)%%CAN3:CAN_3_MESSAGE_28_INT_ENA%%U | (uint32)%%CAN3:CAN_3_MESSAGE_28_RTR%%U | (uint32)%%CAN3:CAN_3_MESSAGE_28_EOB%%U | (uint32)%%CAN3:CAN_3_MESSAGE_28_DLC%%U;
    canREG3->IF2CMD  = (uint8) 0xF8U;
    canREG3->IF2NO   = 28U;

#endif
#if %%CAN3:CAN_3_MESSAGE_29_BOOL_ENA%%
    /** - Initialize message 29 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG3->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG3->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_29_MASK%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF1ARB  = (uint32)%%CAN3:CAN_3_MESSAGE_29_ENA%%U | (uint32)%%CAN3:CAN_3_IDENTIFIER_MODE%%U | (uint32)%%CAN3:CAN_3_MESSAGE_29_DIR%%U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_29_ID%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF1MCTL = 0x00001000U | (uint32)%%CAN3:CAN_3_MESSAGE_29_INT_ENA%%U | (uint32)%%CAN3:CAN_3_MESSAGE_29_RTR%%U | (uint32)%%CAN3:CAN_3_MESSAGE_29_EOB%%U | (uint32)%%CAN3:CAN_3_MESSAGE_29_DLC%%U;
    canREG3->IF1CMD  = (uint8) 0xF8U;
    canREG3->IF1NO   = 29U;

#endif
#if %%CAN3:CAN_3_MESSAGE_30_BOOL_ENA%%
    /** - Initialize message 30 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG3->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG3->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_30_MASK%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF2ARB  = (uint32)%%CAN3:CAN_3_MESSAGE_30_ENA%%U | (uint32)%%CAN3:CAN_3_IDENTIFIER_MODE%%U | (uint32)%%CAN3:CAN_3_MESSAGE_30_DIR%%U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_30_ID%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF2MCTL = 0x00001000U | (uint32)%%CAN3:CAN_3_MESSAGE_30_INT_ENA%%U | (uint32)%%CAN3:CAN_3_MESSAGE_30_RTR%%U | (uint32)%%CAN3:CAN_3_MESSAGE_30_EOB%%U | (uint32)%%CAN3:CAN_3_MESSAGE_30_DLC%%U;
    canREG3->IF2CMD  = (uint8) 0xF8U;
    canREG3->IF2NO   = 30U;

#endif
#if %%CAN3:CAN_3_MESSAGE_31_BOOL_ENA%%
    /** - Initialize message 31 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG3->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG3->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_31_MASK%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF1ARB  = (uint32)%%CAN3:CAN_3_MESSAGE_31_ENA%%U | (uint32)%%CAN3:CAN_3_IDENTIFIER_MODE%%U | (uint32)%%CAN3:CAN_3_MESSAGE_31_DIR%%U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_31_ID%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF1MCTL = 0x00001000U | (uint32)%%CAN3:CAN_3_MESSAGE_31_INT_ENA%%U | (uint32)%%CAN3:CAN_3_MESSAGE_31_RTR%%U | (uint32)%%CAN3:CAN_3_MESSAGE_31_EOB%%U | (uint32)%%CAN3:CAN_3_MESSAGE_31_DLC%%U;
    canREG3->IF1CMD  = (uint8) 0xF8U;
    canREG3->IF1NO   = 31U;

#endif
#if %%CAN3:CAN_3_MESSAGE_32_BOOL_ENA%%
    /** - Initialize message 32 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG3->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG3->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_32_MASK%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF2ARB  = (uint32)%%CAN3:CAN_3_MESSAGE_32_ENA%%U | (uint32)%%CAN3:CAN_3_IDENTIFIER_MODE%%U | (uint32)%%CAN3:CAN_3_MESSAGE_32_DIR%%U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_32_ID%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF2MCTL = 0x00001000U | (uint32)%%CAN3:CAN_3_MESSAGE_32_INT_ENA%%U | (uint32)%%CAN3:CAN_3_MESSAGE_32_RTR%%U | (uint32)%%CAN3:CAN_3_MESSAGE_32_EOB%%U | (uint32)%%CAN3:CAN_3_MESSAGE_32_DLC%%U;
    canREG3->IF2CMD  = (uint8) 0xF8U;
    canREG3->IF2NO   = 32U;

#endif
#if %%CAN3:CAN_3_MESSAGE_33_BOOL_ENA%%
    /** - Initialize message 33 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG3->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG3->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_33_MASK%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF1ARB  = (uint32)%%CAN3:CAN_3_MESSAGE_33_ENA%%U | (uint32)%%CAN3:CAN_3_IDENTIFIER_MODE%%U | (uint32)%%CAN3:CAN_3_MESSAGE_33_DIR%%U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_33_ID%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF1MCTL = 0x00001000U | (uint32)%%CAN3:CAN_3_MESSAGE_33_INT_ENA%%U | (uint32)%%CAN3:CAN_3_MESSAGE_33_RTR%%U | (uint32)%%CAN3:CAN_3_MESSAGE_33_EOB%%U | (uint32)%%CAN3:CAN_3_MESSAGE_33_DLC%%U;
    canREG3->IF1CMD  = (uint8) 0xF8U;
    canREG3->IF1NO   = 33U;

#endif
#if %%CAN3:CAN_3_MESSAGE_34_BOOL_ENA%%
    /** - Initialize message 34 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG3->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG3->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_34_MASK%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF2ARB  = (uint32)%%CAN3:CAN_3_MESSAGE_34_ENA%%U | (uint32)%%CAN3:CAN_3_IDENTIFIER_MODE%%U | (uint32)%%CAN3:CAN_3_MESSAGE_34_DIR%%U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_34_ID%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF2MCTL = 0x00001000U | (uint32)%%CAN3:CAN_3_MESSAGE_34_INT_ENA%%U | (uint32)%%CAN3:CAN_3_MESSAGE_34_RTR%%U | (uint32)%%CAN3:CAN_3_MESSAGE_34_EOB%%U | (uint32)%%CAN3:CAN_3_MESSAGE_34_DLC%%U;
    canREG3->IF2CMD  = (uint8) 0xF8U;
    canREG3->IF2NO   = 34U;

#endif
#if %%CAN3:CAN_3_MESSAGE_35_BOOL_ENA%%
    /** - Initialize message 35 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG3->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG3->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_35_MASK%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF1ARB  = (uint32)%%CAN3:CAN_3_MESSAGE_35_ENA%%U | (uint32)%%CAN3:CAN_3_IDENTIFIER_MODE%%U | (uint32)%%CAN3:CAN_3_MESSAGE_35_DIR%%U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_35_ID%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF1MCTL = 0x00001000U | (uint32)%%CAN3:CAN_3_MESSAGE_35_INT_ENA%%U | (uint32)%%CAN3:CAN_3_MESSAGE_35_RTR%%U | (uint32)%%CAN3:CAN_3_MESSAGE_35_EOB%%U | (uint32)%%CAN3:CAN_3_MESSAGE_35_DLC%%U;
    canREG3->IF1CMD  = (uint8) 0xF8U;
    canREG3->IF1NO   = 35U;

#endif
#if %%CAN3:CAN_3_MESSAGE_36_BOOL_ENA%%
    /** - Initialize message 36 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG3->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG3->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_36_MASK%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF2ARB  = (uint32)%%CAN3:CAN_3_MESSAGE_36_ENA%%U | (uint32)%%CAN3:CAN_3_IDENTIFIER_MODE%%U | (uint32)%%CAN3:CAN_3_MESSAGE_36_DIR%%U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_36_ID%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF2MCTL = 0x00001000U | (uint32)%%CAN3:CAN_3_MESSAGE_36_INT_ENA%%U | (uint32)%%CAN3:CAN_3_MESSAGE_36_RTR%%U | (uint32)%%CAN3:CAN_3_MESSAGE_36_EOB%%U | (uint32)%%CAN3:CAN_3_MESSAGE_36_DLC%%U;
    canREG3->IF2CMD  = (uint8) 0xF8U;
    canREG3->IF2NO   = 36U;

#endif
#if %%CAN3:CAN_3_MESSAGE_37_BOOL_ENA%%
    /** - Initialize message 37 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG3->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG3->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_37_MASK%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF1ARB  = (uint32)%%CAN3:CAN_3_MESSAGE_37_ENA%%U | (uint32)%%CAN3:CAN_3_IDENTIFIER_MODE%%U | (uint32)%%CAN3:CAN_3_MESSAGE_37_DIR%%U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_37_ID%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF1MCTL = 0x00001000U | (uint32)%%CAN3:CAN_3_MESSAGE_37_INT_ENA%%U | (uint32)%%CAN3:CAN_3_MESSAGE_37_RTR%%U | (uint32)%%CAN3:CAN_3_MESSAGE_37_EOB%%U | (uint32)%%CAN3:CAN_3_MESSAGE_37_DLC%%U;
    canREG3->IF1CMD  = (uint8) 0xF8U;
    canREG3->IF1NO   = 37U;

#endif
#if %%CAN3:CAN_3_MESSAGE_38_BOOL_ENA%%
    /** - Initialize message 38 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG3->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG3->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_38_MASK%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF2ARB  = (uint32)%%CAN3:CAN_3_MESSAGE_38_ENA%%U | (uint32)%%CAN3:CAN_3_IDENTIFIER_MODE%%U | (uint32)%%CAN3:CAN_3_MESSAGE_38_DIR%%U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_38_ID%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF2MCTL = 0x00001000U | (uint32)%%CAN3:CAN_3_MESSAGE_38_INT_ENA%%U | (uint32)%%CAN3:CAN_3_MESSAGE_38_RTR%%U | (uint32)%%CAN3:CAN_3_MESSAGE_38_EOB%%U | (uint32)%%CAN3:CAN_3_MESSAGE_38_DLC%%U;
    canREG3->IF2CMD  = (uint8) 0xF8U;
    canREG3->IF2NO   = 38U;

#endif
#if %%CAN3:CAN_3_MESSAGE_39_BOOL_ENA%%
    /** - Initialize message 39 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG3->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG3->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_39_MASK%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF1ARB  = (uint32)%%CAN3:CAN_3_MESSAGE_39_ENA%%U | (uint32)%%CAN3:CAN_3_IDENTIFIER_MODE%%U | (uint32)%%CAN3:CAN_3_MESSAGE_39_DIR%%U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_39_ID%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF1MCTL = 0x00001000U | (uint32)%%CAN3:CAN_3_MESSAGE_39_INT_ENA%%U | (uint32)%%CAN3:CAN_3_MESSAGE_39_RTR%%U | (uint32)%%CAN3:CAN_3_MESSAGE_39_EOB%%U | (uint32)%%CAN3:CAN_3_MESSAGE_39_DLC%%U;
    canREG3->IF1CMD  = (uint8) 0xF8U;
    canREG3->IF1NO   = 39U;

#endif
#if %%CAN3:CAN_3_MESSAGE_40_BOOL_ENA%%
    /** - Initialize message 40 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG3->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG3->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_40_MASK%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF2ARB  = (uint32)%%CAN3:CAN_3_MESSAGE_40_ENA%%U | (uint32)%%CAN3:CAN_3_IDENTIFIER_MODE%%U | (uint32)%%CAN3:CAN_3_MESSAGE_40_DIR%%U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_40_ID%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF2MCTL = 0x00001000U | (uint32)%%CAN3:CAN_3_MESSAGE_40_INT_ENA%%U | (uint32)%%CAN3:CAN_3_MESSAGE_40_RTR%%U | (uint32)%%CAN3:CAN_3_MESSAGE_40_EOB%%U | (uint32)%%CAN3:CAN_3_MESSAGE_40_DLC%%U;
    canREG3->IF2CMD  = (uint8) 0xF8U;
    canREG3->IF2NO   = 40U;

#endif
#if %%CAN3:CAN_3_MESSAGE_41_BOOL_ENA%%
    /** - Initialize message 41 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG3->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG3->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_41_MASK%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF1ARB  = (uint32)%%CAN3:CAN_3_MESSAGE_41_ENA%%U | (uint32)%%CAN3:CAN_3_IDENTIFIER_MODE%%U | (uint32)%%CAN3:CAN_3_MESSAGE_41_DIR%%U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_41_ID%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF1MCTL = 0x00001000U | (uint32)%%CAN3:CAN_3_MESSAGE_41_INT_ENA%%U | (uint32)%%CAN3:CAN_3_MESSAGE_41_RTR%%U | (uint32)%%CAN3:CAN_3_MESSAGE_41_EOB%%U | (uint32)%%CAN3:CAN_3_MESSAGE_41_DLC%%U;
    canREG3->IF1CMD  = (uint8) 0xF8U;
    canREG3->IF1NO   = 41U;

#endif
#if %%CAN3:CAN_3_MESSAGE_42_BOOL_ENA%%
    /** - Initialize message 42 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG3->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG3->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_42_MASK%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF2ARB  = (uint32)%%CAN3:CAN_3_MESSAGE_42_ENA%%U | (uint32)%%CAN3:CAN_3_IDENTIFIER_MODE%%U | (uint32)%%CAN3:CAN_3_MESSAGE_42_DIR%%U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_42_ID%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF2MCTL = 0x00001000U | (uint32)%%CAN3:CAN_3_MESSAGE_42_INT_ENA%%U | (uint32)%%CAN3:CAN_3_MESSAGE_42_RTR%%U | (uint32)%%CAN3:CAN_3_MESSAGE_42_EOB%%U | (uint32)%%CAN3:CAN_3_MESSAGE_42_DLC%%U;
    canREG3->IF2CMD  = (uint8) 0xF8U;
    canREG3->IF2NO   = 42U;

#endif
#if %%CAN3:CAN_3_MESSAGE_43_BOOL_ENA%%
    /** - Initialize message 43 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG3->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG3->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_43_MASK%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF1ARB  = (uint32)%%CAN3:CAN_3_MESSAGE_43_ENA%%U | (uint32)%%CAN3:CAN_3_IDENTIFIER_MODE%%U | (uint32)%%CAN3:CAN_3_MESSAGE_43_DIR%%U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_43_ID%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF1MCTL = 0x00001000U | (uint32)%%CAN3:CAN_3_MESSAGE_43_INT_ENA%%U | (uint32)%%CAN3:CAN_3_MESSAGE_43_RTR%%U | (uint32)%%CAN3:CAN_3_MESSAGE_43_EOB%%U | (uint32)%%CAN3:CAN_3_MESSAGE_43_DLC%%U;
    canREG3->IF1CMD  = (uint8) 0xF8U;
    canREG3->IF1NO   = 43U;

#endif
#if %%CAN3:CAN_3_MESSAGE_44_BOOL_ENA%%
    /** - Initialize message 44 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG3->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG3->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_44_MASK%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF2ARB  = (uint32)%%CAN3:CAN_3_MESSAGE_44_ENA%%U | (uint32)%%CAN3:CAN_3_IDENTIFIER_MODE%%U | (uint32)%%CAN3:CAN_3_MESSAGE_44_DIR%%U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_44_ID%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF2MCTL = 0x00001000U | (uint32)%%CAN3:CAN_3_MESSAGE_44_INT_ENA%%U | (uint32)%%CAN3:CAN_3_MESSAGE_44_RTR%%U | (uint32)%%CAN3:CAN_3_MESSAGE_44_EOB%%U | (uint32)%%CAN3:CAN_3_MESSAGE_44_DLC%%U;
    canREG3->IF2CMD  = (uint8) 0xF8U;
    canREG3->IF2NO   = 44U;

#endif
#if %%CAN3:CAN_3_MESSAGE_45_BOOL_ENA%%
    /** - Initialize message 45 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG3->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG3->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_45_MASK%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF1ARB  = (uint32)%%CAN3:CAN_3_MESSAGE_45_ENA%%U | (uint32)%%CAN3:CAN_3_IDENTIFIER_MODE%%U | (uint32)%%CAN3:CAN_3_MESSAGE_45_DIR%%U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_45_ID%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF1MCTL = 0x00001000U | (uint32)%%CAN3:CAN_3_MESSAGE_45_INT_ENA%%U | (uint32)%%CAN3:CAN_3_MESSAGE_45_RTR%%U | (uint32)%%CAN3:CAN_3_MESSAGE_45_EOB%%U | (uint32)%%CAN3:CAN_3_MESSAGE_45_DLC%%U;
    canREG3->IF1CMD  = (uint8) 0xF8U;
    canREG3->IF1NO   = 45U;

#endif
#if %%CAN3:CAN_3_MESSAGE_46_BOOL_ENA%%
    /** - Initialize message 46 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG3->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG3->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_46_MASK%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF2ARB  = (uint32)%%CAN3:CAN_3_MESSAGE_46_ENA%%U | (uint32)%%CAN3:CAN_3_IDENTIFIER_MODE%%U | (uint32)%%CAN3:CAN_3_MESSAGE_46_DIR%%U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_46_ID%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF2MCTL = 0x00001000U | (uint32)%%CAN3:CAN_3_MESSAGE_46_INT_ENA%%U | (uint32)%%CAN3:CAN_3_MESSAGE_46_RTR%%U | (uint32)%%CAN3:CAN_3_MESSAGE_46_EOB%%U | (uint32)%%CAN3:CAN_3_MESSAGE_46_DLC%%U;
    canREG3->IF2CMD  = (uint8) 0xF8U;
    canREG3->IF2NO   = 46U;

#endif
#if %%CAN3:CAN_3_MESSAGE_47_BOOL_ENA%%
    /** - Initialize message 47 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG3->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG3->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_47_MASK%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF1ARB  = (uint32)%%CAN3:CAN_3_MESSAGE_47_ENA%%U | (uint32)%%CAN3:CAN_3_IDENTIFIER_MODE%%U | (uint32)%%CAN3:CAN_3_MESSAGE_47_DIR%%U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_47_ID%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF1MCTL = 0x00001000U | (uint32)%%CAN3:CAN_3_MESSAGE_47_INT_ENA%%U | (uint32)%%CAN3:CAN_3_MESSAGE_47_RTR%%U | (uint32)%%CAN3:CAN_3_MESSAGE_47_EOB%%U | (uint32)%%CAN3:CAN_3_MESSAGE_47_DLC%%U;
    canREG3->IF1CMD  = (uint8) 0xF8U;
    canREG3->IF1NO   = 47U;

#endif
#if %%CAN3:CAN_3_MESSAGE_48_BOOL_ENA%%
    /** - Initialize message 48 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG3->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG3->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_48_MASK%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF2ARB  = (uint32)%%CAN3:CAN_3_MESSAGE_48_ENA%%U | (uint32)%%CAN3:CAN_3_IDENTIFIER_MODE%%U | (uint32)%%CAN3:CAN_3_MESSAGE_48_DIR%%U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_48_ID%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF2MCTL = 0x00001000U | (uint32)%%CAN3:CAN_3_MESSAGE_48_INT_ENA%%U | (uint32)%%CAN3:CAN_3_MESSAGE_48_RTR%%U | (uint32)%%CAN3:CAN_3_MESSAGE_48_EOB%%U | (uint32)%%CAN3:CAN_3_MESSAGE_48_DLC%%U;
    canREG3->IF2CMD  = (uint8) 0xF8U;
    canREG3->IF2NO   = 48U;

#endif
#if %%CAN3:CAN_3_MESSAGE_49_BOOL_ENA%%
    /** - Initialize message 49 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG3->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG3->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_49_MASK%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF1ARB  = (uint32)%%CAN3:CAN_3_MESSAGE_49_ENA%%U | (uint32)%%CAN3:CAN_3_IDENTIFIER_MODE%%U | (uint32)%%CAN3:CAN_3_MESSAGE_49_DIR%%U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_49_ID%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF1MCTL = 0x00001000U | (uint32)%%CAN3:CAN_3_MESSAGE_49_INT_ENA%%U | (uint32)%%CAN3:CAN_3_MESSAGE_49_RTR%%U | (uint32)%%CAN3:CAN_3_MESSAGE_49_EOB%%U | (uint32)%%CAN3:CAN_3_MESSAGE_49_DLC%%U;
    canREG3->IF1CMD  = (uint8) 0xF8U;
    canREG3->IF1NO   = 49U;

#endif
#if %%CAN3:CAN_3_MESSAGE_50_BOOL_ENA%%
    /** - Initialize message 50 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG3->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG3->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_50_MASK%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF2ARB  = (uint32)%%CAN3:CAN_3_MESSAGE_50_ENA%%U | (uint32)%%CAN3:CAN_3_IDENTIFIER_MODE%%U | (uint32)%%CAN3:CAN_3_MESSAGE_50_DIR%%U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_50_ID%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF2MCTL = 0x00001000U | (uint32)%%CAN3:CAN_3_MESSAGE_50_INT_ENA%%U | (uint32)%%CAN3:CAN_3_MESSAGE_50_RTR%%U | (uint32)%%CAN3:CAN_3_MESSAGE_50_EOB%%U | (uint32)%%CAN3:CAN_3_MESSAGE_50_DLC%%U;
    canREG3->IF2CMD  = (uint8) 0xF8U;
    canREG3->IF2NO   = 50U;

#endif
#if %%CAN3:CAN_3_MESSAGE_51_BOOL_ENA%%
    /** - Initialize message 51 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG3->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG3->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_51_MASK%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF1ARB  = (uint32)%%CAN3:CAN_3_MESSAGE_51_ENA%%U | (uint32)%%CAN3:CAN_3_IDENTIFIER_MODE%%U | (uint32)%%CAN3:CAN_3_MESSAGE_51_DIR%%U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_51_ID%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF1MCTL = 0x00001000U | (uint32)%%CAN3:CAN_3_MESSAGE_51_INT_ENA%%U | (uint32)%%CAN3:CAN_3_MESSAGE_51_RTR%%U | (uint32)%%CAN3:CAN_3_MESSAGE_51_EOB%%U | (uint32)%%CAN3:CAN_3_MESSAGE_51_DLC%%U;
    canREG3->IF1CMD  = (uint8) 0xF8U;
    canREG3->IF1NO   = 51U;

#endif
#if %%CAN3:CAN_3_MESSAGE_52_BOOL_ENA%%
    /** - Initialize message 52 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG3->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG3->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_52_MASK%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF2ARB  = (uint32)%%CAN3:CAN_3_MESSAGE_52_ENA%%U | (uint32)%%CAN3:CAN_3_IDENTIFIER_MODE%%U | (uint32)%%CAN3:CAN_3_MESSAGE_52_DIR%%U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_52_ID%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF2MCTL = 0x00001000U | (uint32)%%CAN3:CAN_3_MESSAGE_52_INT_ENA%%U | (uint32)%%CAN3:CAN_3_MESSAGE_52_RTR%%U | (uint32)%%CAN3:CAN_3_MESSAGE_52_EOB%%U | (uint32)%%CAN3:CAN_3_MESSAGE_52_DLC%%U;
    canREG3->IF2CMD  = (uint8) 0xF8U;
    canREG3->IF2NO   = 52U;

#endif
#if %%CAN3:CAN_3_MESSAGE_53_BOOL_ENA%%
    /** - Initialize message 53 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG3->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG3->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_53_MASK%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF1ARB  = (uint32)%%CAN3:CAN_3_MESSAGE_53_ENA%%U | (uint32)%%CAN3:CAN_3_IDENTIFIER_MODE%%U | (uint32)%%CAN3:CAN_3_MESSAGE_53_DIR%%U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_53_ID%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF1MCTL = 0x00001000U | (uint32)%%CAN3:CAN_3_MESSAGE_53_INT_ENA%%U | (uint32)%%CAN3:CAN_3_MESSAGE_53_RTR%%U | (uint32)%%CAN3:CAN_3_MESSAGE_53_EOB%%U | (uint32)%%CAN3:CAN_3_MESSAGE_53_DLC%%U;
    canREG3->IF1CMD  = (uint8) 0xF8U;
    canREG3->IF1NO   = 53U;

#endif
#if %%CAN3:CAN_3_MESSAGE_54_BOOL_ENA%%
    /** - Initialize message 54 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG3->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG3->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_54_MASK%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF2ARB  = (uint32)%%CAN3:CAN_3_MESSAGE_54_ENA%%U | (uint32)%%CAN3:CAN_3_IDENTIFIER_MODE%%U | (uint32)%%CAN3:CAN_3_MESSAGE_54_DIR%%U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_54_ID%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF2MCTL = 0x00001000U | (uint32)%%CAN3:CAN_3_MESSAGE_54_INT_ENA%%U | (uint32)%%CAN3:CAN_3_MESSAGE_54_RTR%%U | (uint32)%%CAN3:CAN_3_MESSAGE_54_EOB%%U | (uint32)%%CAN3:CAN_3_MESSAGE_54_DLC%%U;
    canREG3->IF2CMD  = (uint8) 0xF8U;
    canREG3->IF2NO   = 54U;

#endif
#if %%CAN3:CAN_3_MESSAGE_55_BOOL_ENA%%
    /** - Initialize message 55 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG3->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG3->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_55_MASK%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF1ARB  = (uint32)%%CAN3:CAN_3_MESSAGE_55_ENA%%U | (uint32)%%CAN3:CAN_3_IDENTIFIER_MODE%%U | (uint32)%%CAN3:CAN_3_MESSAGE_55_DIR%%U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_55_ID%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF1MCTL = 0x00001000U | (uint32)%%CAN3:CAN_3_MESSAGE_55_INT_ENA%%U | (uint32)%%CAN3:CAN_3_MESSAGE_55_RTR%%U | (uint32)%%CAN3:CAN_3_MESSAGE_55_EOB%%U | (uint32)%%CAN3:CAN_3_MESSAGE_55_DLC%%U;
    canREG3->IF1CMD  = (uint8) 0xF8U;
    canREG3->IF1NO   = 55U;

#endif
#if %%CAN3:CAN_3_MESSAGE_56_BOOL_ENA%%
    /** - Initialize message 56 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG3->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG3->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_56_MASK%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF2ARB  = (uint32)%%CAN3:CAN_3_MESSAGE_56_ENA%%U | (uint32)%%CAN3:CAN_3_IDENTIFIER_MODE%%U | (uint32)%%CAN3:CAN_3_MESSAGE_56_DIR%%U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_56_ID%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF2MCTL = 0x00001000U | (uint32)%%CAN3:CAN_3_MESSAGE_56_INT_ENA%%U | (uint32)%%CAN3:CAN_3_MESSAGE_56_RTR%%U | (uint32)%%CAN3:CAN_3_MESSAGE_56_EOB%%U | (uint32)%%CAN3:CAN_3_MESSAGE_56_DLC%%U;
    canREG3->IF2CMD  = (uint8) 0xF8U;
    canREG3->IF2NO   = 56U;

#endif
#if %%CAN3:CAN_3_MESSAGE_57_BOOL_ENA%%
    /** - Initialize message 57 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG3->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG3->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_57_MASK%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF1ARB  = (uint32)%%CAN3:CAN_3_MESSAGE_57_ENA%%U | (uint32)%%CAN3:CAN_3_IDENTIFIER_MODE%%U | (uint32)%%CAN3:CAN_3_MESSAGE_57_DIR%%U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_57_ID%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF1MCTL = 0x00001000U | (uint32)%%CAN3:CAN_3_MESSAGE_57_INT_ENA%%U | (uint32)%%CAN3:CAN_3_MESSAGE_57_RTR%%U | (uint32)%%CAN3:CAN_3_MESSAGE_57_EOB%%U | (uint32)%%CAN3:CAN_3_MESSAGE_57_DLC%%U;
    canREG3->IF1CMD  = (uint8) 0xF8U;
    canREG3->IF1NO   = 57U;

#endif
#if %%CAN3:CAN_3_MESSAGE_58_BOOL_ENA%%
    /** - Initialize message 58 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG3->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG3->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_58_MASK%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF2ARB  = (uint32)%%CAN3:CAN_3_MESSAGE_58_ENA%%U | (uint32)%%CAN3:CAN_3_IDENTIFIER_MODE%%U | (uint32)%%CAN3:CAN_3_MESSAGE_58_DIR%%U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_58_ID%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF2MCTL = 0x00001000U | (uint32)%%CAN3:CAN_3_MESSAGE_58_INT_ENA%%U | (uint32)%%CAN3:CAN_3_MESSAGE_58_RTR%%U | (uint32)%%CAN3:CAN_3_MESSAGE_58_EOB%%U | (uint32)%%CAN3:CAN_3_MESSAGE_58_DLC%%U;
    canREG3->IF2CMD  = (uint8) 0xF8U;
    canREG3->IF2NO   = 58U;

#endif
#if %%CAN3:CAN_3_MESSAGE_59_BOOL_ENA%%
    /** - Initialize message 59 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG3->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG3->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_59_MASK%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF1ARB  = (uint32)%%CAN3:CAN_3_MESSAGE_59_ENA%%U | (uint32)%%CAN3:CAN_3_IDENTIFIER_MODE%%U | (uint32)%%CAN3:CAN_3_MESSAGE_59_DIR%%U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_59_ID%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF1MCTL = 0x00001000U | (uint32)%%CAN3:CAN_3_MESSAGE_59_INT_ENA%%U | (uint32)%%CAN3:CAN_3_MESSAGE_59_RTR%%U | (uint32)%%CAN3:CAN_3_MESSAGE_59_EOB%%U | (uint32)%%CAN3:CAN_3_MESSAGE_59_DLC%%U;
    canREG3->IF1CMD  = (uint8) 0xF8U;
    canREG3->IF1NO   = 59U;

#endif
#if %%CAN3:CAN_3_MESSAGE_60_BOOL_ENA%%
    /** - Initialize message 60 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG3->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG3->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_60_MASK%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF2ARB  = (uint32)%%CAN3:CAN_3_MESSAGE_60_ENA%%U | (uint32)%%CAN3:CAN_3_IDENTIFIER_MODE%%U | (uint32)%%CAN3:CAN_3_MESSAGE_60_DIR%%U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_60_ID%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF2MCTL = 0x00001000U | (uint32)%%CAN3:CAN_3_MESSAGE_60_INT_ENA%%U | (uint32)%%CAN3:CAN_3_MESSAGE_60_RTR%%U | (uint32)%%CAN3:CAN_3_MESSAGE_60_EOB%%U | (uint32)%%CAN3:CAN_3_MESSAGE_60_DLC%%U;
    canREG3->IF2CMD  = (uint8) 0xF8U;
    canREG3->IF2NO   = 60U;

#endif
#if %%CAN3:CAN_3_MESSAGE_61_BOOL_ENA%%
    /** - Initialize message 61 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG3->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG3->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_61_MASK%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF1ARB  = (uint32)%%CAN3:CAN_3_MESSAGE_61_ENA%%U | (uint32)%%CAN3:CAN_3_IDENTIFIER_MODE%%U | (uint32)%%CAN3:CAN_3_MESSAGE_61_DIR%%U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_61_ID%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF1MCTL = 0x00001000U | (uint32)%%CAN3:CAN_3_MESSAGE_61_INT_ENA%%U | (uint32)%%CAN3:CAN_3_MESSAGE_61_RTR%%U | (uint32)%%CAN3:CAN_3_MESSAGE_61_EOB%%U | (uint32)%%CAN3:CAN_3_MESSAGE_61_DLC%%U;
    canREG3->IF1CMD  = (uint8) 0xF8U;
    canREG3->IF1NO   = 61U;

#endif
#if %%CAN3:CAN_3_MESSAGE_62_BOOL_ENA%%
    /** - Initialize message 62 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG3->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG3->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_62_MASK%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF2ARB  = (uint32)%%CAN3:CAN_3_MESSAGE_62_ENA%%U | (uint32)%%CAN3:CAN_3_IDENTIFIER_MODE%%U | (uint32)%%CAN3:CAN_3_MESSAGE_62_DIR%%U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_62_ID%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF2MCTL = 0x00001000U | (uint32)%%CAN3:CAN_3_MESSAGE_62_INT_ENA%%U | (uint32)%%CAN3:CAN_3_MESSAGE_62_RTR%%U | (uint32)%%CAN3:CAN_3_MESSAGE_62_EOB%%U | (uint32)%%CAN3:CAN_3_MESSAGE_62_DLC%%U;
    canREG3->IF2CMD  = (uint8) 0xF8U;
    canREG3->IF2NO   = 62U;

#endif
#if %%CAN3:CAN_3_MESSAGE_63_BOOL_ENA%%
    /** - Initialize message 63 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG3->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG3->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_63_MASK%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF1ARB  = (uint32)%%CAN3:CAN_3_MESSAGE_63_ENA%%U | (uint32)%%CAN3:CAN_3_IDENTIFIER_MODE%%U | (uint32)%%CAN3:CAN_3_MESSAGE_63_DIR%%U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_63_ID%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF1MCTL = 0x00001000U | (uint32)%%CAN3:CAN_3_MESSAGE_63_INT_ENA%%U | (uint32)%%CAN3:CAN_3_MESSAGE_63_RTR%%U | (uint32)%%CAN3:CAN_3_MESSAGE_63_EOB%%U | (uint32)%%CAN3:CAN_3_MESSAGE_63_DLC%%U;
    canREG3->IF1CMD  = (uint8) 0xF8U;
    canREG3->IF1NO   = 63U;

#endif
#if %%CAN3:CAN_3_MESSAGE_64_BOOL_ENA%%
    /** - Initialize message 64 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG3->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG3->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_64_MASK%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF2ARB  = (uint32)%%CAN3:CAN_3_MESSAGE_64_ENA%%U | (uint32)%%CAN3:CAN_3_IDENTIFIER_MODE%%U | (uint32)%%CAN3:CAN_3_MESSAGE_64_DIR%%U | (uint32)((uint32)((uint32)%%CAN3:CAN_3_MESSAGE_64_ID%%U & (uint32)%%CAN3:CAN_3_MASK%%U) << (uint32)%%CAN3:CAN_3_SHIFT%%U);
    canREG3->IF2MCTL = 0x00001000U | (uint32)%%CAN3:CAN_3_MESSAGE_64_INT_ENA%%U | (uint32)%%CAN3:CAN_3_MESSAGE_64_RTR%%U | (uint32)%%CAN3:CAN_3_MESSAGE_64_EOB%%U | (uint32)%%CAN3:CAN_3_MESSAGE_64_DLC%%U;
    canREG3->IF2CMD  = (uint8) 0xF8U;
    canREG3->IF2NO   = 64U;

#endif
    /** - Setup IF1 for data transmission 
    *     - Wait until IF1 is ready for use 
    *     - Set IF1 control byte
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG3->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */
    canREG3->IF1CMD  = 0x87U;

    /** - Setup IF2 for reading data
    *     - Wait until IF1 is ready for use 
    *     - Set IF1 control byte
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG3->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */
    canREG3->IF2CMD = 0x17U;

    /** - Setup bit timing 
    *     - Setup baud rate prescaler extension
    *     - Setup TSeg2
    *     - Setup TSeg1
    *     - Setup sample jump width
    *     - Setup baud rate prescaler
    */
    canREG3->BTR = (uint32)((uint32)%%CAN3:CAN_3_BRPE%%U << 16U) |
                   (uint32)((uint32)(%%CAN3:CAN_3_PHASE_SEG%%U - 1U) << 12U) |
                   (uint32)((uint32)((%%CAN3:CAN_3_PROP_SEG%%U + %%CAN3:CAN_3_PHASE_SEG%%U) - 1U) << 8U) |
                   (uint32)((uint32)(%%CAN3:CAN_3_SJW%%U - 1U) << 6U) |
                   (uint32)(uint32)%%CAN3:CAN_3_BRP%%U;
#else
    /** - Setup control register
    *     - Enter initialization mode
    */
    canREG3->CTL = 0x00000001U;
	
    /** - CAN3 Port output values */
    canREG3->TIOC =  (uint32)((uint32)%%CAN3:CAN_3_PORT_TX_PSL%%U  << 18U )
                   | (uint32)((uint32)%%CAN3:CAN_3_PORT_TX_PULDIS%%U  << 17U )
                   | (uint32)((uint32)%%CAN3:CAN_3_PORT_TX_PDR%%U  << 16U )  
                   | (uint32)((uint32)%%CAN3:CAN_3_PORT_TX_FUN%%U  << 3U )  
                   | (uint32)((uint32)%%CAN3:CAN_3_PORT_TX_DIR%%U  << 2U )    
                   | (uint32)((uint32)%%CAN3:CAN_3_PORT_TX_DOUT%%U << 1U );
                   
    canREG3->RIOC =  (uint32)((uint32)%%CAN3:CAN_3_PORT_RX_PSL%%U  << 18U )    
                   | (uint32)((uint32)%%CAN3:CAN_3_PORT_RX_PULDIS%%U  << 17U )  
                   | (uint32)((uint32)%%CAN3:CAN_3_PORT_RX_PDR%%U  << 16U )   
                   | (uint32)((uint32)%%CAN3:CAN_3_PORT_RX_FUN%%U  << 3U )  
                   | (uint32)((uint32)%%CAN3:CAN_3_PORT_RX_DIR%%U  << 2U )
                   | (uint32)((uint32)%%CAN3:CAN_3_PORT_RX_DOUT%%U << 1U );       
#endif   

#if %%CAN3:CAN_3_PIN_MODE%%

    /** - CAN3 Port output values */
    canREG3->TIOC =  (uint32)((uint32)%%CAN3:CAN_3_PORT_TX_PSL%%U  << 18U )
                   | (uint32)((uint32)%%CAN3:CAN_3_PORT_TX_PULDIS%%U  << 17U )
                   | (uint32)((uint32)%%CAN3:CAN_3_PORT_TX_PDR%%U  << 16U )  
                   | (uint32)((uint32)%%CAN3:CAN_3_PORT_TX_FUN%%U  << 3U )  
                   | (uint32)((uint32)%%CAN3:CAN_3_PORT_TX_DIR%%U  << 2U )    
                   | (uint32)((uint32)%%CAN3:CAN_3_PORT_TX_DOUT%%U << 1U );
                   
    canREG3->RIOC =  (uint32)((uint32)%%CAN3:CAN_3_PORT_RX_PSL%%U  << 18U )    
                   | (uint32)((uint32)%%CAN3:CAN_3_PORT_RX_PULDIS%%U  << 17U )  
                   | (uint32)((uint32)%%CAN3:CAN_3_PORT_RX_PDR%%U  << 16U )   
                   | (uint32)((uint32)%%CAN3:CAN_3_PORT_RX_FUN%%U  << 3U )  
                   | (uint32)((uint32)%%CAN3:CAN_3_PORT_RX_DIR%%U  << 2U )
                   | (uint32)((uint32)%%CAN3:CAN_3_PORT_RX_DOUT%%U << 1U );       

    /** - Leave configuration and initialization mode  */
    canREG3->CTL &= ~(uint32)(0x00000041U);
#endif
#endif

#if %%SYSTEM:CAN4_ENABLE%%
    /** @b Initialize @b CAN1: */

#if %%CAN4:CAN_4_PIN_MODE%%
    /** - Setup control register
    *     - Disable automatic wakeup on bus activity
    *     - Local power down mode disabled
    *     - Disable DMA request lines
    *     - Enable global Interrupt Line 0 and 1
    *     - Disable debug mode
    *     - Release from software reset
    *     - Enable/Disable parity or ECC
    *     - Enable/Disable auto bus on timer
    *     - Setup message completion before entering debug state
    *     - Setup normal operation mode
    *     - Request write access to the configuration registers
    *     - Setup automatic retransmission of messages
    *     - Disable error interrupts
    *     - Disable status interrupts
    *     - Enter initialization mode
    */
    canREG4->CTL = (uint32)%%CAN4:CAN_4_AUTO_BUS_ON%%U 
                 | (uint32)%%CAN4:CAN_4_AUTO_RETRANSMISSION%%U 
                 | ((uint32)%%CAN4:CAN_4_RAM_PARITY_ENA%%U  << 10U)
                 | (uint32)0x00020043U;

    /** - Clear all pending error flags and reset current status */
    canREG4->ES |= 0xFFFFFFFFU;

    /** - Assign interrupt level for messages */
    canREG4->INTMUXx[0U] = (uint32)%%CAN4:CAN_4_MESSAGE_64_INT_LEVEL%%U
                         | (uint32)%%CAN4:CAN_4_MESSAGE_1_INT_LEVEL%%U
                         | (uint32)%%CAN4:CAN_4_MESSAGE_2_INT_LEVEL%%U
                         | (uint32)%%CAN4:CAN_4_MESSAGE_3_INT_LEVEL%%U
                         | (uint32)%%CAN4:CAN_4_MESSAGE_4_INT_LEVEL%%U
                         | (uint32)%%CAN4:CAN_4_MESSAGE_5_INT_LEVEL%%U
                         | (uint32)%%CAN4:CAN_4_MESSAGE_6_INT_LEVEL%%U
                         | (uint32)%%CAN4:CAN_4_MESSAGE_7_INT_LEVEL%%U
                         | (uint32)%%CAN4:CAN_4_MESSAGE_8_INT_LEVEL%%U
                         | (uint32)%%CAN4:CAN_4_MESSAGE_9_INT_LEVEL%%U
                         | (uint32)%%CAN4:CAN_4_MESSAGE_10_INT_LEVEL%%U
                         | (uint32)%%CAN4:CAN_4_MESSAGE_11_INT_LEVEL%%U
                         | (uint32)%%CAN4:CAN_4_MESSAGE_12_INT_LEVEL%%U
                         | (uint32)%%CAN4:CAN_4_MESSAGE_13_INT_LEVEL%%U
                         | (uint32)%%CAN4:CAN_4_MESSAGE_14_INT_LEVEL%%U
                         | (uint32)%%CAN4:CAN_4_MESSAGE_15_INT_LEVEL%%U
                         | (uint32)%%CAN4:CAN_4_MESSAGE_16_INT_LEVEL%%U
                         | (uint32)%%CAN4:CAN_4_MESSAGE_17_INT_LEVEL%%U
                         | (uint32)%%CAN4:CAN_4_MESSAGE_18_INT_LEVEL%%U
                         | (uint32)%%CAN4:CAN_4_MESSAGE_19_INT_LEVEL%%U
                         | (uint32)%%CAN4:CAN_4_MESSAGE_20_INT_LEVEL%%U
                         | (uint32)%%CAN4:CAN_4_MESSAGE_21_INT_LEVEL%%U
                         | (uint32)%%CAN4:CAN_4_MESSAGE_22_INT_LEVEL%%U
                         | (uint32)%%CAN4:CAN_4_MESSAGE_23_INT_LEVEL%%U
                         | (uint32)%%CAN4:CAN_4_MESSAGE_24_INT_LEVEL%%U
                         | (uint32)%%CAN4:CAN_4_MESSAGE_25_INT_LEVEL%%U
                         | (uint32)%%CAN4:CAN_4_MESSAGE_26_INT_LEVEL%%U
                         | (uint32)%%CAN4:CAN_4_MESSAGE_27_INT_LEVEL%%U
                         | (uint32)%%CAN4:CAN_4_MESSAGE_28_INT_LEVEL%%U
                         | (uint32)%%CAN4:CAN_4_MESSAGE_29_INT_LEVEL%%U
                         | (uint32)%%CAN4:CAN_4_MESSAGE_30_INT_LEVEL%%U
                         | (uint32)%%CAN4:CAN_4_MESSAGE_31_INT_LEVEL%%U;

    canREG4->INTMUXx[1U] = (uint32)%%CAN4:CAN_4_MESSAGE_32_INT_LEVEL%%U
                         | (uint32)%%CAN4:CAN_4_MESSAGE_33_INT_LEVEL%%U
                         | (uint32)%%CAN4:CAN_4_MESSAGE_34_INT_LEVEL%%U
                         | (uint32)%%CAN4:CAN_4_MESSAGE_35_INT_LEVEL%%U
                         | (uint32)%%CAN4:CAN_4_MESSAGE_36_INT_LEVEL%%U
                         | (uint32)%%CAN4:CAN_4_MESSAGE_37_INT_LEVEL%%U
                         | (uint32)%%CAN4:CAN_4_MESSAGE_38_INT_LEVEL%%U
                         | (uint32)%%CAN4:CAN_4_MESSAGE_39_INT_LEVEL%%U
                         | (uint32)%%CAN4:CAN_4_MESSAGE_40_INT_LEVEL%%U
                         | (uint32)%%CAN4:CAN_4_MESSAGE_41_INT_LEVEL%%U
                         | (uint32)%%CAN4:CAN_4_MESSAGE_42_INT_LEVEL%%U
                         | (uint32)%%CAN4:CAN_4_MESSAGE_43_INT_LEVEL%%U
                         | (uint32)%%CAN4:CAN_4_MESSAGE_44_INT_LEVEL%%U
                         | (uint32)%%CAN4:CAN_4_MESSAGE_45_INT_LEVEL%%U
                         | (uint32)%%CAN4:CAN_4_MESSAGE_46_INT_LEVEL%%U
                         | (uint32)%%CAN4:CAN_4_MESSAGE_47_INT_LEVEL%%U
                         | (uint32)%%CAN4:CAN_4_MESSAGE_48_INT_LEVEL%%U
                         | (uint32)%%CAN4:CAN_4_MESSAGE_49_INT_LEVEL%%U
                         | (uint32)%%CAN4:CAN_4_MESSAGE_50_INT_LEVEL%%U
                         | (uint32)%%CAN4:CAN_4_MESSAGE_51_INT_LEVEL%%U
                         | (uint32)%%CAN4:CAN_4_MESSAGE_52_INT_LEVEL%%U
                         | (uint32)%%CAN4:CAN_4_MESSAGE_53_INT_LEVEL%%U
                         | (uint32)%%CAN4:CAN_4_MESSAGE_54_INT_LEVEL%%U
                         | (uint32)%%CAN4:CAN_4_MESSAGE_55_INT_LEVEL%%U
                         | (uint32)%%CAN4:CAN_4_MESSAGE_56_INT_LEVEL%%U
                         | (uint32)%%CAN4:CAN_4_MESSAGE_57_INT_LEVEL%%U
                         | (uint32)%%CAN4:CAN_4_MESSAGE_58_INT_LEVEL%%U
                         | (uint32)%%CAN4:CAN_4_MESSAGE_59_INT_LEVEL%%U
                         | (uint32)%%CAN4:CAN_4_MESSAGE_60_INT_LEVEL%%U
                         | (uint32)%%CAN4:CAN_4_MESSAGE_61_INT_LEVEL%%U
                         | (uint32)%%CAN4:CAN_4_MESSAGE_62_INT_LEVEL%%U
                         | (uint32)%%CAN4:CAN_4_MESSAGE_63_INT_LEVEL%%U;

    /** - Setup auto bus on timer period */
    canREG4->ABOTR = (uint32)%%CAN4:CAN_4_AUTO_BUS_ON_TR%%U;

#if %%CAN4:CAN_4_MESSAGE_1_BOOL_ENA%%
    /** - Initialize message 1 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG4->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */


    canREG4->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_1_MASK%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF1ARB  = (uint32)%%CAN4:CAN_4_MESSAGE_1_ENA%%U | (uint32)%%CAN4:CAN_4_IDENTIFIER_MODE%%U | (uint32)%%CAN4:CAN_4_MESSAGE_1_DIR%%U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_1_ID%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF1MCTL = 0x00001000U | (uint32)%%CAN4:CAN_4_MESSAGE_1_INT_ENA%%U | (uint32)%%CAN4:CAN_4_MESSAGE_1_RTR%%U | (uint32)%%CAN4:CAN_4_MESSAGE_1_EOB%%U | (uint32)%%CAN4:CAN_4_MESSAGE_1_DLC%%U;
    canREG4->IF1CMD  = (uint8) 0xF8U;
    canREG4->IF1NO   = 1U;

#endif
#if %%CAN4:CAN_4_MESSAGE_2_BOOL_ENA%%
    /** - Initialize message 2 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG4->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG4->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_2_MASK%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF2ARB  = (uint32)%%CAN4:CAN_4_MESSAGE_2_ENA%%U | (uint32)%%CAN4:CAN_4_IDENTIFIER_MODE%%U | (uint32)%%CAN4:CAN_4_MESSAGE_2_DIR%%U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_2_ID%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF2MCTL = 0x00001000U | (uint32)%%CAN4:CAN_4_MESSAGE_2_INT_ENA%%U | (uint32)%%CAN4:CAN_4_MESSAGE_2_RTR%%U | (uint32)%%CAN4:CAN_4_MESSAGE_2_EOB%%U | (uint32)%%CAN4:CAN_4_MESSAGE_2_DLC%%U;
    canREG4->IF2CMD  = (uint8) 0xF8U;
    canREG4->IF2NO   = 2U;

#endif
#if %%CAN4:CAN_4_MESSAGE_3_BOOL_ENA%%
    /** - Initialize message 3 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG4->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG4->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_3_MASK%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF1ARB  = (uint32)%%CAN4:CAN_4_MESSAGE_3_ENA%%U | (uint32)%%CAN4:CAN_4_IDENTIFIER_MODE%%U | (uint32)%%CAN4:CAN_4_MESSAGE_3_DIR%%U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_3_ID%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF1MCTL = 0x00001000U | (uint32)%%CAN4:CAN_4_MESSAGE_3_INT_ENA%%U | (uint32)%%CAN4:CAN_4_MESSAGE_3_RTR%%U | (uint32)%%CAN4:CAN_4_MESSAGE_3_EOB%%U | (uint32)%%CAN4:CAN_4_MESSAGE_3_DLC%%U;
    canREG4->IF1CMD  = (uint8) 0xF8U;
    canREG4->IF1NO   = 3U;

#endif
#if %%CAN4:CAN_4_MESSAGE_4_BOOL_ENA%%
    /** - Initialize message 4 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG4->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG4->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_4_MASK%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF2ARB  = (uint32)%%CAN4:CAN_4_MESSAGE_4_ENA%%U | (uint32)%%CAN4:CAN_4_IDENTIFIER_MODE%%U | (uint32)%%CAN4:CAN_4_MESSAGE_4_DIR%%U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_4_ID%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF2MCTL = 0x00001000U | (uint32)%%CAN4:CAN_4_MESSAGE_4_INT_ENA%%U | (uint32)%%CAN4:CAN_4_MESSAGE_4_RTR%%U | (uint32)%%CAN4:CAN_4_MESSAGE_4_EOB%%U | (uint32)%%CAN4:CAN_4_MESSAGE_4_DLC%%U;
    canREG4->IF2CMD  = (uint8) 0xF8U;
    canREG4->IF2NO   = 4U;

#endif
#if %%CAN4:CAN_4_MESSAGE_5_BOOL_ENA%%
    /** - Initialize message 5 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG4->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG4->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_5_MASK%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF1ARB  = (uint32)%%CAN4:CAN_4_MESSAGE_5_ENA%%U | (uint32)%%CAN4:CAN_4_IDENTIFIER_MODE%%U | (uint32)%%CAN4:CAN_4_MESSAGE_5_DIR%%U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_5_ID%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF1MCTL = 0x00001000U | (uint32)%%CAN4:CAN_4_MESSAGE_5_INT_ENA%%U | (uint32)%%CAN4:CAN_4_MESSAGE_5_RTR%%U | (uint32)%%CAN4:CAN_4_MESSAGE_5_EOB%%U | (uint32)%%CAN4:CAN_4_MESSAGE_5_DLC%%U;
    canREG4->IF1CMD  = (uint8) 0xF8U;
    canREG4->IF1NO   = 5U;

#endif
#if %%CAN4:CAN_4_MESSAGE_6_BOOL_ENA%%
    /** - Initialize message 6 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG4->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG4->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_6_MASK%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF2ARB  = (uint32)%%CAN4:CAN_4_MESSAGE_6_ENA%%U | (uint32)%%CAN4:CAN_4_IDENTIFIER_MODE%%U | (uint32)%%CAN4:CAN_4_MESSAGE_6_DIR%%U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_6_ID%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF2MCTL = 0x00001000U | (uint32)%%CAN4:CAN_4_MESSAGE_6_INT_ENA%%U | (uint32)%%CAN4:CAN_4_MESSAGE_6_RTR%%U | (uint32)%%CAN4:CAN_4_MESSAGE_6_EOB%%U | (uint32)%%CAN4:CAN_4_MESSAGE_6_DLC%%U;
    canREG4->IF2CMD  = (uint8) 0xF8U;
    canREG4->IF2NO   = 6U;

#endif
#if %%CAN4:CAN_4_MESSAGE_7_BOOL_ENA%%
    /** - Initialize message 7 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG4->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG4->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_7_MASK%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF1ARB  = (uint32)%%CAN4:CAN_4_MESSAGE_7_ENA%%U | (uint32)%%CAN4:CAN_4_IDENTIFIER_MODE%%U | (uint32)%%CAN4:CAN_4_MESSAGE_7_DIR%%U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_7_ID%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF1MCTL = 0x00001000U | (uint32)%%CAN4:CAN_4_MESSAGE_7_INT_ENA%%U | (uint32)%%CAN4:CAN_4_MESSAGE_7_RTR%%U | (uint32)%%CAN4:CAN_4_MESSAGE_7_EOB%%U | (uint32)%%CAN4:CAN_4_MESSAGE_7_DLC%%U;
    canREG4->IF1CMD  = (uint8) 0xF8U;
    canREG4->IF1NO   = 7U;

#endif
#if %%CAN4:CAN_4_MESSAGE_8_BOOL_ENA%%
    /** - Initialize message 8 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG4->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG4->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_8_MASK%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF2ARB  = (uint32)%%CAN4:CAN_4_MESSAGE_8_ENA%%U | (uint32)%%CAN4:CAN_4_IDENTIFIER_MODE%%U | (uint32)%%CAN4:CAN_4_MESSAGE_8_DIR%%U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_8_ID%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF2MCTL = 0x00001000U | (uint32)%%CAN4:CAN_4_MESSAGE_8_INT_ENA%%U | (uint32)%%CAN4:CAN_4_MESSAGE_8_RTR%%U | (uint32)%%CAN4:CAN_4_MESSAGE_8_EOB%%U | (uint32)%%CAN4:CAN_4_MESSAGE_8_DLC%%U;
    canREG4->IF2CMD  = (uint8) 0xF8U;
    canREG4->IF2NO   = 8U;

#endif
#if %%CAN4:CAN_4_MESSAGE_9_BOOL_ENA%%
    /** - Initialize message 9 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG4->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG4->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_9_MASK%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF1ARB  = (uint32)%%CAN4:CAN_4_MESSAGE_9_ENA%%U | (uint32)%%CAN4:CAN_4_IDENTIFIER_MODE%%U | (uint32)%%CAN4:CAN_4_MESSAGE_9_DIR%%U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_9_ID%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF1MCTL = 0x00001000U | (uint32)%%CAN4:CAN_4_MESSAGE_9_INT_ENA%%U | (uint32)%%CAN4:CAN_4_MESSAGE_9_RTR%%U | (uint32)%%CAN4:CAN_4_MESSAGE_9_EOB%%U | (uint32)%%CAN4:CAN_4_MESSAGE_9_DLC%%U;
    canREG4->IF1CMD  = (uint8) 0xF8U;
    canREG4->IF1NO   = 9U;

#endif
#if %%CAN4:CAN_4_MESSAGE_10_BOOL_ENA%%
    /** - Initialize message 10 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG4->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG4->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_10_MASK%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF2ARB  = (uint32)%%CAN4:CAN_4_MESSAGE_10_ENA%%U | (uint32)%%CAN4:CAN_4_IDENTIFIER_MODE%%U | (uint32)%%CAN4:CAN_4_MESSAGE_10_DIR%%U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_10_ID%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF2MCTL = 0x00001000U | (uint32)%%CAN4:CAN_4_MESSAGE_10_INT_ENA%%U | (uint32)%%CAN4:CAN_4_MESSAGE_10_RTR%%U | (uint32)%%CAN4:CAN_4_MESSAGE_10_EOB%%U | (uint32)%%CAN4:CAN_4_MESSAGE_10_DLC%%U;
    canREG4->IF2CMD  = (uint8) 0xF8U;
    canREG4->IF2NO   = 10U;

#endif
#if %%CAN4:CAN_4_MESSAGE_11_BOOL_ENA%%
    /** - Initialize message 11 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG4->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG4->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_11_MASK%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF1ARB  = (uint32)%%CAN4:CAN_4_MESSAGE_11_ENA%%U | (uint32)%%CAN4:CAN_4_IDENTIFIER_MODE%%U | (uint32)%%CAN4:CAN_4_MESSAGE_11_DIR%%U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_11_ID%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF1MCTL = 0x00001000U | (uint32)%%CAN4:CAN_4_MESSAGE_11_INT_ENA%%U | (uint32)%%CAN4:CAN_4_MESSAGE_11_RTR%%U | (uint32)%%CAN4:CAN_4_MESSAGE_11_EOB%%U | (uint32)%%CAN4:CAN_4_MESSAGE_11_DLC%%U;
    canREG4->IF1CMD  = (uint8) 0xF8U;
    canREG4->IF1NO   = 11U;

#endif
#if %%CAN4:CAN_4_MESSAGE_12_BOOL_ENA%%
    /** - Initialize message 12 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG4->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG4->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_12_MASK%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF2ARB  = (uint32)%%CAN4:CAN_4_MESSAGE_12_ENA%%U | (uint32)%%CAN4:CAN_4_IDENTIFIER_MODE%%U | (uint32)%%CAN4:CAN_4_MESSAGE_12_DIR%%U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_12_ID%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF2MCTL = 0x00001000U | (uint32)%%CAN4:CAN_4_MESSAGE_12_INT_ENA%%U | (uint32)%%CAN4:CAN_4_MESSAGE_12_RTR%%U | (uint32)%%CAN4:CAN_4_MESSAGE_12_EOB%%U | (uint32)%%CAN4:CAN_4_MESSAGE_12_DLC%%U;
    canREG4->IF2CMD  = (uint8) 0xF8U;
    canREG4->IF2NO   = 12U;

#endif
#if %%CAN4:CAN_4_MESSAGE_13_BOOL_ENA%%
    /** - Initialize message 13 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG4->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG4->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_13_MASK%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF1ARB  = (uint32)%%CAN4:CAN_4_MESSAGE_13_ENA%%U | (uint32)%%CAN4:CAN_4_IDENTIFIER_MODE%%U | (uint32)%%CAN4:CAN_4_MESSAGE_13_DIR%%U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_13_ID%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF1MCTL = 0x00001000U | (uint32)%%CAN4:CAN_4_MESSAGE_13_INT_ENA%%U | (uint32)%%CAN4:CAN_4_MESSAGE_13_RTR%%U | (uint32)%%CAN4:CAN_4_MESSAGE_13_EOB%%U | (uint32)%%CAN4:CAN_4_MESSAGE_13_DLC%%U;
    canREG4->IF1CMD  = (uint8) 0xF8U;
    canREG4->IF1NO   = 13U;

#endif
#if %%CAN4:CAN_4_MESSAGE_14_BOOL_ENA%%
    /** - Initialize message 14 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG4->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG4->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_14_MASK%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF2ARB  = (uint32)%%CAN4:CAN_4_MESSAGE_14_ENA%%U | (uint32)%%CAN4:CAN_4_IDENTIFIER_MODE%%U | (uint32)%%CAN4:CAN_4_MESSAGE_14_DIR%%U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_14_ID%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF2MCTL = 0x00001000U | (uint32)%%CAN4:CAN_4_MESSAGE_14_INT_ENA%%U | (uint32)%%CAN4:CAN_4_MESSAGE_14_RTR%%U | (uint32)%%CAN4:CAN_4_MESSAGE_14_EOB%%U | (uint32)%%CAN4:CAN_4_MESSAGE_14_DLC%%U;
    canREG4->IF2CMD  = (uint8) 0xF8U;
    canREG4->IF2NO   = 14U;

#endif
#if %%CAN4:CAN_4_MESSAGE_15_BOOL_ENA%%
    /** - Initialize message 15 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG4->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG4->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_15_MASK%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF1ARB  = (uint32)%%CAN4:CAN_4_MESSAGE_15_ENA%%U | (uint32)%%CAN4:CAN_4_IDENTIFIER_MODE%%U | (uint32)%%CAN4:CAN_4_MESSAGE_15_DIR%%U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_15_ID%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF1MCTL = 0x00001000U | (uint32)%%CAN4:CAN_4_MESSAGE_15_INT_ENA%%U | (uint32)%%CAN4:CAN_4_MESSAGE_15_RTR%%U | (uint32)%%CAN4:CAN_4_MESSAGE_15_EOB%%U | (uint32)%%CAN4:CAN_4_MESSAGE_15_DLC%%U;
    canREG4->IF1CMD  = (uint8) 0xF8U;
    canREG4->IF1NO   = 15U;

#endif
#if %%CAN4:CAN_4_MESSAGE_16_BOOL_ENA%%
    /** - Initialize message 16 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG4->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG4->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_16_MASK%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF2ARB  = (uint32)%%CAN4:CAN_4_MESSAGE_16_ENA%%U | (uint32)%%CAN4:CAN_4_IDENTIFIER_MODE%%U | (uint32)%%CAN4:CAN_4_MESSAGE_16_DIR%%U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_16_ID%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF2MCTL = 0x00001000U | (uint32)%%CAN4:CAN_4_MESSAGE_16_INT_ENA%%U | (uint32)%%CAN4:CAN_4_MESSAGE_16_RTR%%U | (uint32)%%CAN4:CAN_4_MESSAGE_16_EOB%%U | (uint32)%%CAN4:CAN_4_MESSAGE_16_DLC%%U;
    canREG4->IF2CMD  = (uint8) 0xF8U;
    canREG4->IF2NO   = 16U;

#endif
#if %%CAN4:CAN_4_MESSAGE_17_BOOL_ENA%%
    /** - Initialize message 17 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG4->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG4->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_17_MASK%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF1ARB  = (uint32)%%CAN4:CAN_4_MESSAGE_17_ENA%%U | (uint32)%%CAN4:CAN_4_IDENTIFIER_MODE%%U | (uint32)%%CAN4:CAN_4_MESSAGE_17_DIR%%U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_17_ID%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF1MCTL = 0x00001000U | (uint32)%%CAN4:CAN_4_MESSAGE_17_INT_ENA%%U | (uint32)%%CAN4:CAN_4_MESSAGE_17_RTR%%U | (uint32)%%CAN4:CAN_4_MESSAGE_17_EOB%%U | (uint32)%%CAN4:CAN_4_MESSAGE_17_DLC%%U;
    canREG4->IF1CMD  = (uint8) 0xF8U;
    canREG4->IF1NO   = 17U;

#endif
#if %%CAN4:CAN_4_MESSAGE_18_BOOL_ENA%%
    /** - Initialize message 18 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG4->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG4->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_18_MASK%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF2ARB  = (uint32)%%CAN4:CAN_4_MESSAGE_18_ENA%%U | (uint32)%%CAN4:CAN_4_IDENTIFIER_MODE%%U | (uint32)%%CAN4:CAN_4_MESSAGE_18_DIR%%U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_18_ID%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF2MCTL = 0x00001000U | (uint32)%%CAN4:CAN_4_MESSAGE_18_INT_ENA%%U | (uint32)%%CAN4:CAN_4_MESSAGE_18_RTR%%U | (uint32)%%CAN4:CAN_4_MESSAGE_18_EOB%%U | (uint32)%%CAN4:CAN_4_MESSAGE_18_DLC%%U;
    canREG4->IF2CMD  = (uint8) 0xF8U;
    canREG4->IF2NO   = 18U;

#endif
#if %%CAN4:CAN_4_MESSAGE_19_BOOL_ENA%%
    /** - Initialize message 19 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG4->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG4->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_19_MASK%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF1ARB  = (uint32)%%CAN4:CAN_4_MESSAGE_19_ENA%%U | (uint32)%%CAN4:CAN_4_IDENTIFIER_MODE%%U | (uint32)%%CAN4:CAN_4_MESSAGE_19_DIR%%U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_19_ID%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF1MCTL = 0x00001000U | (uint32)%%CAN4:CAN_4_MESSAGE_19_INT_ENA%%U | (uint32)%%CAN4:CAN_4_MESSAGE_19_RTR%%U | (uint32)%%CAN4:CAN_4_MESSAGE_19_EOB%%U | (uint32)%%CAN4:CAN_4_MESSAGE_19_DLC%%U;
    canREG4->IF1CMD  = (uint8) 0xF8U;
    canREG4->IF1NO   = 19U;

#endif
#if %%CAN4:CAN_4_MESSAGE_20_BOOL_ENA%%
    /** - Initialize message 20 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG4->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG4->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_20_MASK%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF2ARB  = (uint32)%%CAN4:CAN_4_MESSAGE_20_ENA%%U | (uint32)%%CAN4:CAN_4_IDENTIFIER_MODE%%U | (uint32)%%CAN4:CAN_4_MESSAGE_20_DIR%%U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_20_ID%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF2MCTL = 0x00001000U | (uint32)%%CAN4:CAN_4_MESSAGE_20_INT_ENA%%U | (uint32)%%CAN4:CAN_4_MESSAGE_20_RTR%%U | (uint32)%%CAN4:CAN_4_MESSAGE_20_EOB%%U | (uint32)%%CAN4:CAN_4_MESSAGE_20_DLC%%U;
    canREG4->IF2CMD  = (uint8) 0xF8U;
    canREG4->IF2NO   = 20U;

#endif
#if %%CAN4:CAN_4_MESSAGE_21_BOOL_ENA%%
    /** - Initialize message 21 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG4->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG4->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_21_MASK%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF1ARB  = (uint32)%%CAN4:CAN_4_MESSAGE_21_ENA%%U | (uint32)%%CAN4:CAN_4_IDENTIFIER_MODE%%U | (uint32)%%CAN4:CAN_4_MESSAGE_21_DIR%%U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_21_ID%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF1MCTL = 0x00001000U | (uint32)%%CAN4:CAN_4_MESSAGE_21_INT_ENA%%U | (uint32)%%CAN4:CAN_4_MESSAGE_21_RTR%%U | (uint32)%%CAN4:CAN_4_MESSAGE_21_EOB%%U | (uint32)%%CAN4:CAN_4_MESSAGE_21_DLC%%U;
    canREG4->IF1CMD  = (uint8) 0xF8U;
    canREG4->IF1NO   = 21U;

#endif
#if %%CAN4:CAN_4_MESSAGE_22_BOOL_ENA%%
    /** - Initialize message 22 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG4->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG4->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_22_MASK%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF2ARB  = (uint32)%%CAN4:CAN_4_MESSAGE_22_ENA%%U | (uint32)%%CAN4:CAN_4_IDENTIFIER_MODE%%U | (uint32)%%CAN4:CAN_4_MESSAGE_22_DIR%%U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_22_ID%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF2MCTL = 0x00001000U | (uint32)%%CAN4:CAN_4_MESSAGE_22_INT_ENA%%U | (uint32)%%CAN4:CAN_4_MESSAGE_22_RTR%%U | (uint32)%%CAN4:CAN_4_MESSAGE_22_EOB%%U | (uint32)%%CAN4:CAN_4_MESSAGE_22_DLC%%U;
    canREG4->IF2CMD  = (uint8) 0xF8U;
    canREG4->IF2NO   = 22U;

#endif
#if %%CAN4:CAN_4_MESSAGE_23_BOOL_ENA%%
    /** - Initialize message 23 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG4->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG4->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_23_MASK%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF1ARB  = (uint32)%%CAN4:CAN_4_MESSAGE_23_ENA%%U | (uint32)%%CAN4:CAN_4_IDENTIFIER_MODE%%U | (uint32)%%CAN4:CAN_4_MESSAGE_23_DIR%%U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_23_ID%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF1MCTL = 0x00001000U | (uint32)%%CAN4:CAN_4_MESSAGE_23_INT_ENA%%U | (uint32)%%CAN4:CAN_4_MESSAGE_23_RTR%%U | (uint32)%%CAN4:CAN_4_MESSAGE_23_EOB%%U | (uint32)%%CAN4:CAN_4_MESSAGE_23_DLC%%U;
    canREG4->IF1CMD  = (uint8) 0xF8U;
    canREG4->IF1NO   = 23U;

#endif
#if %%CAN4:CAN_4_MESSAGE_24_BOOL_ENA%%
    /** - Initialize message 24 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG4->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG4->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_24_MASK%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF2ARB  = (uint32)%%CAN4:CAN_4_MESSAGE_24_ENA%%U | (uint32)%%CAN4:CAN_4_IDENTIFIER_MODE%%U | (uint32)%%CAN4:CAN_4_MESSAGE_24_DIR%%U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_24_ID%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF2MCTL = 0x00001000U | (uint32)%%CAN4:CAN_4_MESSAGE_24_INT_ENA%%U | (uint32)%%CAN4:CAN_4_MESSAGE_24_RTR%%U | (uint32)%%CAN4:CAN_4_MESSAGE_24_EOB%%U | (uint32)%%CAN4:CAN_4_MESSAGE_24_DLC%%U;
    canREG4->IF2CMD  = (uint8) 0xF8U;
    canREG4->IF2NO   = 24U;

#endif
#if %%CAN4:CAN_4_MESSAGE_25_BOOL_ENA%%
    /** - Initialize message 25 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG4->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG4->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_25_MASK%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF1ARB  = (uint32)%%CAN4:CAN_4_MESSAGE_25_ENA%%U | (uint32)%%CAN4:CAN_4_IDENTIFIER_MODE%%U | (uint32)%%CAN4:CAN_4_MESSAGE_25_DIR%%U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_25_ID%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF1MCTL = 0x00001000U | (uint32)%%CAN4:CAN_4_MESSAGE_25_INT_ENA%%U | (uint32)%%CAN4:CAN_4_MESSAGE_25_RTR%%U | (uint32)%%CAN4:CAN_4_MESSAGE_25_EOB%%U | (uint32)%%CAN4:CAN_4_MESSAGE_25_DLC%%U;
    canREG4->IF1CMD  = (uint8) 0xF8U;
    canREG4->IF1NO   = 25U;

#endif
#if %%CAN4:CAN_4_MESSAGE_26_BOOL_ENA%%
    /** - Initialize message 26 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG4->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG4->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_26_MASK%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF2ARB  = (uint32)%%CAN4:CAN_4_MESSAGE_26_ENA%%U | (uint32)%%CAN4:CAN_4_IDENTIFIER_MODE%%U | (uint32)%%CAN4:CAN_4_MESSAGE_26_DIR%%U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_26_ID%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF2MCTL = 0x00001000U | (uint32)%%CAN4:CAN_4_MESSAGE_26_INT_ENA%%U | (uint32)%%CAN4:CAN_4_MESSAGE_26_RTR%%U | (uint32)%%CAN4:CAN_4_MESSAGE_26_EOB%%U | (uint32)%%CAN4:CAN_4_MESSAGE_26_DLC%%U;
    canREG4->IF2CMD  = (uint8) 0xF8U;
    canREG4->IF2NO   = 26U;

#endif
#if %%CAN4:CAN_4_MESSAGE_27_BOOL_ENA%%
    /** - Initialize message 27 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG4->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG4->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_27_MASK%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF1ARB  = (uint32)%%CAN4:CAN_4_MESSAGE_27_ENA%%U | (uint32)%%CAN4:CAN_4_IDENTIFIER_MODE%%U | (uint32)%%CAN4:CAN_4_MESSAGE_27_DIR%%U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_27_ID%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF1MCTL = 0x00001000U | (uint32)%%CAN4:CAN_4_MESSAGE_27_INT_ENA%%U | (uint32)%%CAN4:CAN_4_MESSAGE_27_RTR%%U | (uint32)%%CAN4:CAN_4_MESSAGE_27_EOB%%U | (uint32)%%CAN4:CAN_4_MESSAGE_27_DLC%%U;
    canREG4->IF1CMD  = (uint8) 0xF8U;
    canREG4->IF1NO   = 27U;

#endif
#if %%CAN4:CAN_4_MESSAGE_28_BOOL_ENA%%
    /** - Initialize message 28 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG4->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG4->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_28_MASK%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF2ARB  = (uint32)%%CAN4:CAN_4_MESSAGE_28_ENA%%U | (uint32)%%CAN4:CAN_4_IDENTIFIER_MODE%%U | (uint32)%%CAN4:CAN_4_MESSAGE_28_DIR%%U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_28_ID%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF2MCTL = 0x00001000U | (uint32)%%CAN4:CAN_4_MESSAGE_28_INT_ENA%%U | (uint32)%%CAN4:CAN_4_MESSAGE_28_RTR%%U | (uint32)%%CAN4:CAN_4_MESSAGE_28_EOB%%U | (uint32)%%CAN4:CAN_4_MESSAGE_28_DLC%%U;
    canREG4->IF2CMD  = (uint8) 0xF8U;
    canREG4->IF2NO   = 28U;

#endif
#if %%CAN4:CAN_4_MESSAGE_29_BOOL_ENA%%
    /** - Initialize message 29 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG4->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG4->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_29_MASK%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF1ARB  = (uint32)%%CAN4:CAN_4_MESSAGE_29_ENA%%U | (uint32)%%CAN4:CAN_4_IDENTIFIER_MODE%%U | (uint32)%%CAN4:CAN_4_MESSAGE_29_DIR%%U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_29_ID%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF1MCTL = 0x00001000U | (uint32)%%CAN4:CAN_4_MESSAGE_29_INT_ENA%%U | (uint32)%%CAN4:CAN_4_MESSAGE_29_RTR%%U | (uint32)%%CAN4:CAN_4_MESSAGE_29_EOB%%U | (uint32)%%CAN4:CAN_4_MESSAGE_29_DLC%%U;
    canREG4->IF1CMD  = (uint8) 0xF8U;
    canREG4->IF1NO   = 29U;

#endif
#if %%CAN4:CAN_4_MESSAGE_30_BOOL_ENA%%
    /** - Initialize message 30 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG4->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG4->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_30_MASK%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF2ARB  = (uint32)%%CAN4:CAN_4_MESSAGE_30_ENA%%U | (uint32)%%CAN4:CAN_4_IDENTIFIER_MODE%%U | (uint32)%%CAN4:CAN_4_MESSAGE_30_DIR%%U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_30_ID%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF2MCTL = 0x00001000U | (uint32)%%CAN4:CAN_4_MESSAGE_30_INT_ENA%%U | (uint32)%%CAN4:CAN_4_MESSAGE_30_RTR%%U | (uint32)%%CAN4:CAN_4_MESSAGE_30_EOB%%U | (uint32)%%CAN4:CAN_4_MESSAGE_30_DLC%%U;
    canREG4->IF2CMD  = (uint8) 0xF8U;
    canREG4->IF2NO   = 30U;

#endif
#if %%CAN4:CAN_4_MESSAGE_31_BOOL_ENA%%
    /** - Initialize message 31 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG4->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG4->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_31_MASK%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF1ARB  = (uint32)%%CAN4:CAN_4_MESSAGE_31_ENA%%U | (uint32)%%CAN4:CAN_4_IDENTIFIER_MODE%%U | (uint32)%%CAN4:CAN_4_MESSAGE_31_DIR%%U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_31_ID%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF1MCTL = 0x00001000U | (uint32)%%CAN4:CAN_4_MESSAGE_31_INT_ENA%%U | (uint32)%%CAN4:CAN_4_MESSAGE_31_RTR%%U | (uint32)%%CAN4:CAN_4_MESSAGE_31_EOB%%U | (uint32)%%CAN4:CAN_4_MESSAGE_31_DLC%%U;
    canREG4->IF1CMD  = (uint8) 0xF8U;
    canREG4->IF1NO   = 31U;

#endif
#if %%CAN4:CAN_4_MESSAGE_32_BOOL_ENA%%
    /** - Initialize message 32 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG4->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG4->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_32_MASK%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF2ARB  = (uint32)%%CAN4:CAN_4_MESSAGE_32_ENA%%U | (uint32)%%CAN4:CAN_4_IDENTIFIER_MODE%%U | (uint32)%%CAN4:CAN_4_MESSAGE_32_DIR%%U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_32_ID%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF2MCTL = 0x00001000U | (uint32)%%CAN4:CAN_4_MESSAGE_32_INT_ENA%%U | (uint32)%%CAN4:CAN_4_MESSAGE_32_RTR%%U | (uint32)%%CAN4:CAN_4_MESSAGE_32_EOB%%U | (uint32)%%CAN4:CAN_4_MESSAGE_32_DLC%%U;
    canREG4->IF2CMD  = (uint8) 0xF8U;
    canREG4->IF2NO   = 32U;

#endif
#if %%CAN4:CAN_4_MESSAGE_33_BOOL_ENA%%
    /** - Initialize message 33 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG4->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG4->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_33_MASK%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF1ARB  = (uint32)%%CAN4:CAN_4_MESSAGE_33_ENA%%U | (uint32)%%CAN4:CAN_4_IDENTIFIER_MODE%%U | (uint32)%%CAN4:CAN_4_MESSAGE_33_DIR%%U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_33_ID%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF1MCTL = 0x00001000U | (uint32)%%CAN4:CAN_4_MESSAGE_33_INT_ENA%%U | (uint32)%%CAN4:CAN_4_MESSAGE_33_RTR%%U | (uint32)%%CAN4:CAN_4_MESSAGE_33_EOB%%U | (uint32)%%CAN4:CAN_4_MESSAGE_33_DLC%%U;
    canREG4->IF1CMD  = (uint8) 0xF8U;
    canREG4->IF1NO   = 33U;

#endif
#if %%CAN4:CAN_4_MESSAGE_34_BOOL_ENA%%
    /** - Initialize message 34 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG4->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG4->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_34_MASK%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF2ARB  = (uint32)%%CAN4:CAN_4_MESSAGE_34_ENA%%U | (uint32)%%CAN4:CAN_4_IDENTIFIER_MODE%%U | (uint32)%%CAN4:CAN_4_MESSAGE_34_DIR%%U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_34_ID%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF2MCTL = 0x00001000U | (uint32)%%CAN4:CAN_4_MESSAGE_34_INT_ENA%%U | (uint32)%%CAN4:CAN_4_MESSAGE_34_RTR%%U | (uint32)%%CAN4:CAN_4_MESSAGE_34_EOB%%U | (uint32)%%CAN4:CAN_4_MESSAGE_34_DLC%%U;
    canREG4->IF2CMD  = (uint8) 0xF8U;
    canREG4->IF2NO   = 34U;

#endif
#if %%CAN4:CAN_4_MESSAGE_35_BOOL_ENA%%
    /** - Initialize message 35 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG4->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG4->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_35_MASK%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF1ARB  = (uint32)%%CAN4:CAN_4_MESSAGE_35_ENA%%U | (uint32)%%CAN4:CAN_4_IDENTIFIER_MODE%%U | (uint32)%%CAN4:CAN_4_MESSAGE_35_DIR%%U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_35_ID%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF1MCTL = 0x00001000U | (uint32)%%CAN4:CAN_4_MESSAGE_35_INT_ENA%%U | (uint32)%%CAN4:CAN_4_MESSAGE_35_RTR%%U | (uint32)%%CAN4:CAN_4_MESSAGE_35_EOB%%U | (uint32)%%CAN4:CAN_4_MESSAGE_35_DLC%%U;
    canREG4->IF1CMD  = (uint8) 0xF8U;
    canREG4->IF1NO   = 35U;

#endif
#if %%CAN4:CAN_4_MESSAGE_36_BOOL_ENA%%
    /** - Initialize message 36 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG4->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG4->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_36_MASK%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF2ARB  = (uint32)%%CAN4:CAN_4_MESSAGE_36_ENA%%U | (uint32)%%CAN4:CAN_4_IDENTIFIER_MODE%%U | (uint32)%%CAN4:CAN_4_MESSAGE_36_DIR%%U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_36_ID%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF2MCTL = 0x00001000U | (uint32)%%CAN4:CAN_4_MESSAGE_36_INT_ENA%%U | (uint32)%%CAN4:CAN_4_MESSAGE_36_RTR%%U | (uint32)%%CAN4:CAN_4_MESSAGE_36_EOB%%U | (uint32)%%CAN4:CAN_4_MESSAGE_36_DLC%%U;
    canREG4->IF2CMD  = (uint8) 0xF8U;
    canREG4->IF2NO   = 36U;

#endif
#if %%CAN4:CAN_4_MESSAGE_37_BOOL_ENA%%
    /** - Initialize message 37 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG4->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG4->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_37_MASK%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF1ARB  = (uint32)%%CAN4:CAN_4_MESSAGE_37_ENA%%U | (uint32)%%CAN4:CAN_4_IDENTIFIER_MODE%%U | (uint32)%%CAN4:CAN_4_MESSAGE_37_DIR%%U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_37_ID%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF1MCTL = 0x00001000U | (uint32)%%CAN4:CAN_4_MESSAGE_37_INT_ENA%%U | (uint32)%%CAN4:CAN_4_MESSAGE_37_RTR%%U | (uint32)%%CAN4:CAN_4_MESSAGE_37_EOB%%U | (uint32)%%CAN4:CAN_4_MESSAGE_37_DLC%%U;
    canREG4->IF1CMD  = (uint8) 0xF8U;
    canREG4->IF1NO   = 37U;

#endif
#if %%CAN4:CAN_4_MESSAGE_38_BOOL_ENA%%
    /** - Initialize message 38 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG4->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG4->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_38_MASK%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF2ARB  = (uint32)%%CAN4:CAN_4_MESSAGE_38_ENA%%U | (uint32)%%CAN4:CAN_4_IDENTIFIER_MODE%%U | (uint32)%%CAN4:CAN_4_MESSAGE_38_DIR%%U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_38_ID%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF2MCTL = 0x00001000U | (uint32)%%CAN4:CAN_4_MESSAGE_38_INT_ENA%%U | (uint32)%%CAN4:CAN_4_MESSAGE_38_RTR%%U | (uint32)%%CAN4:CAN_4_MESSAGE_38_EOB%%U | (uint32)%%CAN4:CAN_4_MESSAGE_38_DLC%%U;
    canREG4->IF2CMD  = (uint8) 0xF8U;
    canREG4->IF2NO   = 38U;

#endif
#if %%CAN4:CAN_4_MESSAGE_39_BOOL_ENA%%
    /** - Initialize message 39 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG4->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG4->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_39_MASK%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF1ARB  = (uint32)%%CAN4:CAN_4_MESSAGE_39_ENA%%U | (uint32)%%CAN4:CAN_4_IDENTIFIER_MODE%%U | (uint32)%%CAN4:CAN_4_MESSAGE_39_DIR%%U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_39_ID%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF1MCTL = 0x00001000U | (uint32)%%CAN4:CAN_4_MESSAGE_39_INT_ENA%%U | (uint32)%%CAN4:CAN_4_MESSAGE_39_RTR%%U | (uint32)%%CAN4:CAN_4_MESSAGE_39_EOB%%U | (uint32)%%CAN4:CAN_4_MESSAGE_39_DLC%%U;
    canREG4->IF1CMD  = (uint8) 0xF8U;
    canREG4->IF1NO   = 39U;

#endif
#if %%CAN4:CAN_4_MESSAGE_40_BOOL_ENA%%
    /** - Initialize message 40 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG4->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG4->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_40_MASK%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF2ARB  = (uint32)%%CAN4:CAN_4_MESSAGE_40_ENA%%U | (uint32)%%CAN4:CAN_4_IDENTIFIER_MODE%%U | (uint32)%%CAN4:CAN_4_MESSAGE_40_DIR%%U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_40_ID%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF2MCTL = 0x00001000U | (uint32)%%CAN4:CAN_4_MESSAGE_40_INT_ENA%%U | (uint32)%%CAN4:CAN_4_MESSAGE_40_RTR%%U | (uint32)%%CAN4:CAN_4_MESSAGE_40_EOB%%U | (uint32)%%CAN4:CAN_4_MESSAGE_40_DLC%%U;
    canREG4->IF2CMD  = (uint8) 0xF8U;
    canREG4->IF2NO   = 40U;

#endif
#if %%CAN4:CAN_4_MESSAGE_41_BOOL_ENA%%
    /** - Initialize message 41 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG4->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG4->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_41_MASK%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF1ARB  = (uint32)%%CAN4:CAN_4_MESSAGE_41_ENA%%U | (uint32)%%CAN4:CAN_4_IDENTIFIER_MODE%%U | (uint32)%%CAN4:CAN_4_MESSAGE_41_DIR%%U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_41_ID%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF1MCTL = 0x00001000U | (uint32)%%CAN4:CAN_4_MESSAGE_41_INT_ENA%%U | (uint32)%%CAN4:CAN_4_MESSAGE_41_RTR%%U | (uint32)%%CAN4:CAN_4_MESSAGE_41_EOB%%U | (uint32)%%CAN4:CAN_4_MESSAGE_41_DLC%%U;
    canREG4->IF1CMD  = (uint8) 0xF8U;
    canREG4->IF1NO   = 41U;

#endif
#if %%CAN4:CAN_4_MESSAGE_42_BOOL_ENA%%
    /** - Initialize message 42 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG4->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG4->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_42_MASK%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF2ARB  = (uint32)%%CAN4:CAN_4_MESSAGE_42_ENA%%U | (uint32)%%CAN4:CAN_4_IDENTIFIER_MODE%%U | (uint32)%%CAN4:CAN_4_MESSAGE_42_DIR%%U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_42_ID%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF2MCTL = 0x00001000U | (uint32)%%CAN4:CAN_4_MESSAGE_42_INT_ENA%%U | (uint32)%%CAN4:CAN_4_MESSAGE_42_RTR%%U | (uint32)%%CAN4:CAN_4_MESSAGE_42_EOB%%U | (uint32)%%CAN4:CAN_4_MESSAGE_42_DLC%%U;
    canREG4->IF2CMD  = (uint8) 0xF8U;
    canREG4->IF2NO   = 42U;

#endif
#if %%CAN4:CAN_4_MESSAGE_43_BOOL_ENA%%
    /** - Initialize message 43 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG4->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG4->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_43_MASK%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF1ARB  = (uint32)%%CAN4:CAN_4_MESSAGE_43_ENA%%U | (uint32)%%CAN4:CAN_4_IDENTIFIER_MODE%%U | (uint32)%%CAN4:CAN_4_MESSAGE_43_DIR%%U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_43_ID%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF1MCTL = 0x00001000U | (uint32)%%CAN4:CAN_4_MESSAGE_43_INT_ENA%%U | (uint32)%%CAN4:CAN_4_MESSAGE_43_RTR%%U | (uint32)%%CAN4:CAN_4_MESSAGE_43_EOB%%U | (uint32)%%CAN4:CAN_4_MESSAGE_43_DLC%%U;
    canREG4->IF1CMD  = (uint8) 0xF8U;
    canREG4->IF1NO   = 43U;

#endif
#if %%CAN4:CAN_4_MESSAGE_44_BOOL_ENA%%
    /** - Initialize message 44 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG4->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG4->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_44_MASK%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF2ARB  = (uint32)%%CAN4:CAN_4_MESSAGE_44_ENA%%U | (uint32)%%CAN4:CAN_4_IDENTIFIER_MODE%%U | (uint32)%%CAN4:CAN_4_MESSAGE_44_DIR%%U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_44_ID%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF2MCTL = 0x00001000U | (uint32)%%CAN4:CAN_4_MESSAGE_44_INT_ENA%%U | (uint32)%%CAN4:CAN_4_MESSAGE_44_RTR%%U | (uint32)%%CAN4:CAN_4_MESSAGE_44_EOB%%U | (uint32)%%CAN4:CAN_4_MESSAGE_44_DLC%%U;
    canREG4->IF2CMD  = (uint8) 0xF8U;
    canREG4->IF2NO   = 44U;

#endif
#if %%CAN4:CAN_4_MESSAGE_45_BOOL_ENA%%
    /** - Initialize message 45 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG4->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG4->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_45_MASK%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF1ARB  = (uint32)%%CAN4:CAN_4_MESSAGE_45_ENA%%U | (uint32)%%CAN4:CAN_4_IDENTIFIER_MODE%%U | (uint32)%%CAN4:CAN_4_MESSAGE_45_DIR%%U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_45_ID%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF1MCTL = 0x00001000U | (uint32)%%CAN4:CAN_4_MESSAGE_45_INT_ENA%%U | (uint32)%%CAN4:CAN_4_MESSAGE_45_RTR%%U | (uint32)%%CAN4:CAN_4_MESSAGE_45_EOB%%U | (uint32)%%CAN4:CAN_4_MESSAGE_45_DLC%%U;
    canREG4->IF1CMD  = (uint8) 0xF8U;
    canREG4->IF1NO   = 45U;

#endif
#if %%CAN4:CAN_4_MESSAGE_46_BOOL_ENA%%
    /** - Initialize message 46 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG4->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG4->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_46_MASK%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF2ARB  = (uint32)%%CAN4:CAN_4_MESSAGE_46_ENA%%U | (uint32)%%CAN4:CAN_4_IDENTIFIER_MODE%%U | (uint32)%%CAN4:CAN_4_MESSAGE_46_DIR%%U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_46_ID%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF2MCTL = 0x00001000U | (uint32)%%CAN4:CAN_4_MESSAGE_46_INT_ENA%%U | (uint32)%%CAN4:CAN_4_MESSAGE_46_RTR%%U | (uint32)%%CAN4:CAN_4_MESSAGE_46_EOB%%U | (uint32)%%CAN4:CAN_4_MESSAGE_46_DLC%%U;
    canREG4->IF2CMD  = (uint8) 0xF8U;
    canREG4->IF2NO   = 46U;

#endif
#if %%CAN4:CAN_4_MESSAGE_47_BOOL_ENA%%
    /** - Initialize message 47 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG4->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG4->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_47_MASK%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF1ARB  = (uint32)%%CAN4:CAN_4_MESSAGE_47_ENA%%U | (uint32)%%CAN4:CAN_4_IDENTIFIER_MODE%%U | (uint32)%%CAN4:CAN_4_MESSAGE_47_DIR%%U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_47_ID%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF1MCTL = 0x00001000U | (uint32)%%CAN4:CAN_4_MESSAGE_47_INT_ENA%%U | (uint32)%%CAN4:CAN_4_MESSAGE_47_RTR%%U | (uint32)%%CAN4:CAN_4_MESSAGE_47_EOB%%U | (uint32)%%CAN4:CAN_4_MESSAGE_47_DLC%%U;
    canREG4->IF1CMD  = (uint8) 0xF8U;
    canREG4->IF1NO   = 47U;

#endif
#if %%CAN4:CAN_4_MESSAGE_48_BOOL_ENA%%
    /** - Initialize message 48 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG4->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG4->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_48_MASK%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF2ARB  = (uint32)%%CAN4:CAN_4_MESSAGE_48_ENA%%U | (uint32)%%CAN4:CAN_4_IDENTIFIER_MODE%%U | (uint32)%%CAN4:CAN_4_MESSAGE_48_DIR%%U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_48_ID%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF2MCTL = 0x00001000U | (uint32)%%CAN4:CAN_4_MESSAGE_48_INT_ENA%%U | (uint32)%%CAN4:CAN_4_MESSAGE_48_RTR%%U | (uint32)%%CAN4:CAN_4_MESSAGE_48_EOB%%U | (uint32)%%CAN4:CAN_4_MESSAGE_48_DLC%%U;
    canREG4->IF2CMD  = (uint8) 0xF8U;
    canREG4->IF2NO   = 48U;

#endif
#if %%CAN4:CAN_4_MESSAGE_49_BOOL_ENA%%
    /** - Initialize message 49 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG4->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG4->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_49_MASK%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF1ARB  = (uint32)%%CAN4:CAN_4_MESSAGE_49_ENA%%U | (uint32)%%CAN4:CAN_4_IDENTIFIER_MODE%%U | (uint32)%%CAN4:CAN_4_MESSAGE_49_DIR%%U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_49_ID%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF1MCTL = 0x00001000U | (uint32)%%CAN4:CAN_4_MESSAGE_49_INT_ENA%%U | (uint32)%%CAN4:CAN_4_MESSAGE_49_RTR%%U | (uint32)%%CAN4:CAN_4_MESSAGE_49_EOB%%U | (uint32)%%CAN4:CAN_4_MESSAGE_49_DLC%%U;
    canREG4->IF1CMD  = (uint8) 0xF8U;
    canREG4->IF1NO   = 49U;

#endif
#if %%CAN4:CAN_4_MESSAGE_50_BOOL_ENA%%
    /** - Initialize message 50 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG4->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG4->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_50_MASK%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF2ARB  = (uint32)%%CAN4:CAN_4_MESSAGE_50_ENA%%U | (uint32)%%CAN4:CAN_4_IDENTIFIER_MODE%%U | (uint32)%%CAN4:CAN_4_MESSAGE_50_DIR%%U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_50_ID%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF2MCTL = 0x00001000U | (uint32)%%CAN4:CAN_4_MESSAGE_50_INT_ENA%%U | (uint32)%%CAN4:CAN_4_MESSAGE_50_RTR%%U | (uint32)%%CAN4:CAN_4_MESSAGE_50_EOB%%U | (uint32)%%CAN4:CAN_4_MESSAGE_50_DLC%%U;
    canREG4->IF2CMD  = (uint8) 0xF8U;
    canREG4->IF2NO   = 50U;

#endif
#if %%CAN4:CAN_4_MESSAGE_51_BOOL_ENA%%
    /** - Initialize message 51 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG4->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG4->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_51_MASK%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF1ARB  = (uint32)%%CAN4:CAN_4_MESSAGE_51_ENA%%U | (uint32)%%CAN4:CAN_4_IDENTIFIER_MODE%%U | (uint32)%%CAN4:CAN_4_MESSAGE_51_DIR%%U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_51_ID%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF1MCTL = 0x00001000U | (uint32)%%CAN4:CAN_4_MESSAGE_51_INT_ENA%%U | (uint32)%%CAN4:CAN_4_MESSAGE_51_RTR%%U | (uint32)%%CAN4:CAN_4_MESSAGE_51_EOB%%U | (uint32)%%CAN4:CAN_4_MESSAGE_51_DLC%%U;
    canREG4->IF1CMD  = (uint8) 0xF8U;
    canREG4->IF1NO   = 51U;

#endif
#if %%CAN4:CAN_4_MESSAGE_52_BOOL_ENA%%
    /** - Initialize message 52 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG4->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG4->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_52_MASK%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF2ARB  = (uint32)%%CAN4:CAN_4_MESSAGE_52_ENA%%U | (uint32)%%CAN4:CAN_4_IDENTIFIER_MODE%%U | (uint32)%%CAN4:CAN_4_MESSAGE_52_DIR%%U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_52_ID%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF2MCTL = 0x00001000U | (uint32)%%CAN4:CAN_4_MESSAGE_52_INT_ENA%%U | (uint32)%%CAN4:CAN_4_MESSAGE_52_RTR%%U | (uint32)%%CAN4:CAN_4_MESSAGE_52_EOB%%U | (uint32)%%CAN4:CAN_4_MESSAGE_52_DLC%%U;
    canREG4->IF2CMD  = (uint8) 0xF8U;
    canREG4->IF2NO   = 52U;

#endif
#if %%CAN4:CAN_4_MESSAGE_53_BOOL_ENA%%
    /** - Initialize message 53 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG4->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG4->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_53_MASK%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF1ARB  = (uint32)%%CAN4:CAN_4_MESSAGE_53_ENA%%U | (uint32)%%CAN4:CAN_4_IDENTIFIER_MODE%%U | (uint32)%%CAN4:CAN_4_MESSAGE_53_DIR%%U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_53_ID%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF1MCTL = 0x00001000U | (uint32)%%CAN4:CAN_4_MESSAGE_53_INT_ENA%%U | (uint32)%%CAN4:CAN_4_MESSAGE_53_RTR%%U | (uint32)%%CAN4:CAN_4_MESSAGE_53_EOB%%U | (uint32)%%CAN4:CAN_4_MESSAGE_53_DLC%%U;
    canREG4->IF1CMD  = (uint8) 0xF8U;
    canREG4->IF1NO   = 53U;

#endif
#if %%CAN4:CAN_4_MESSAGE_54_BOOL_ENA%%
    /** - Initialize message 54 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG4->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG4->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_54_MASK%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF2ARB  = (uint32)%%CAN4:CAN_4_MESSAGE_54_ENA%%U | (uint32)%%CAN4:CAN_4_IDENTIFIER_MODE%%U | (uint32)%%CAN4:CAN_4_MESSAGE_54_DIR%%U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_54_ID%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF2MCTL = 0x00001000U | (uint32)%%CAN4:CAN_4_MESSAGE_54_INT_ENA%%U | (uint32)%%CAN4:CAN_4_MESSAGE_54_RTR%%U | (uint32)%%CAN4:CAN_4_MESSAGE_54_EOB%%U | (uint32)%%CAN4:CAN_4_MESSAGE_54_DLC%%U;
    canREG4->IF2CMD  = (uint8) 0xF8U;
    canREG4->IF2NO   = 54U;

#endif
#if %%CAN4:CAN_4_MESSAGE_55_BOOL_ENA%%
    /** - Initialize message 55 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG4->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG4->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_55_MASK%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF1ARB  = (uint32)%%CAN4:CAN_4_MESSAGE_55_ENA%%U | (uint32)%%CAN4:CAN_4_IDENTIFIER_MODE%%U | (uint32)%%CAN4:CAN_4_MESSAGE_55_DIR%%U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_55_ID%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF1MCTL = 0x00001000U | (uint32)%%CAN4:CAN_4_MESSAGE_55_INT_ENA%%U | (uint32)%%CAN4:CAN_4_MESSAGE_55_RTR%%U | (uint32)%%CAN4:CAN_4_MESSAGE_55_EOB%%U | (uint32)%%CAN4:CAN_4_MESSAGE_55_DLC%%U;
    canREG4->IF1CMD  = (uint8) 0xF8U;
    canREG4->IF1NO   = 55U;

#endif
#if %%CAN4:CAN_4_MESSAGE_56_BOOL_ENA%%
    /** - Initialize message 56 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG4->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG4->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_56_MASK%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF2ARB  = (uint32)%%CAN4:CAN_4_MESSAGE_56_ENA%%U | (uint32)%%CAN4:CAN_4_IDENTIFIER_MODE%%U | (uint32)%%CAN4:CAN_4_MESSAGE_56_DIR%%U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_56_ID%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF2MCTL = 0x00001000U | (uint32)%%CAN4:CAN_4_MESSAGE_56_INT_ENA%%U | (uint32)%%CAN4:CAN_4_MESSAGE_56_RTR%%U | (uint32)%%CAN4:CAN_4_MESSAGE_56_EOB%%U | (uint32)%%CAN4:CAN_4_MESSAGE_56_DLC%%U;
    canREG4->IF2CMD  = (uint8) 0xF8U;
    canREG4->IF2NO   = 56U;

#endif
#if %%CAN4:CAN_4_MESSAGE_57_BOOL_ENA%%
    /** - Initialize message 57 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG4->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG4->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_57_MASK%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF1ARB  = (uint32)%%CAN4:CAN_4_MESSAGE_57_ENA%%U | (uint32)%%CAN4:CAN_4_IDENTIFIER_MODE%%U | (uint32)%%CAN4:CAN_4_MESSAGE_57_DIR%%U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_57_ID%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF1MCTL = 0x00001000U | (uint32)%%CAN4:CAN_4_MESSAGE_57_INT_ENA%%U | (uint32)%%CAN4:CAN_4_MESSAGE_57_RTR%%U | (uint32)%%CAN4:CAN_4_MESSAGE_57_EOB%%U | (uint32)%%CAN4:CAN_4_MESSAGE_57_DLC%%U;
    canREG4->IF1CMD  = (uint8) 0xF8U;
    canREG4->IF1NO   = 57U;

#endif
#if %%CAN4:CAN_4_MESSAGE_58_BOOL_ENA%%
    /** - Initialize message 58 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG4->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG4->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_58_MASK%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF2ARB  = (uint32)%%CAN4:CAN_4_MESSAGE_58_ENA%%U | (uint32)%%CAN4:CAN_4_IDENTIFIER_MODE%%U | (uint32)%%CAN4:CAN_4_MESSAGE_58_DIR%%U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_58_ID%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF2MCTL = 0x00001000U | (uint32)%%CAN4:CAN_4_MESSAGE_58_INT_ENA%%U | (uint32)%%CAN4:CAN_4_MESSAGE_58_RTR%%U | (uint32)%%CAN4:CAN_4_MESSAGE_58_EOB%%U | (uint32)%%CAN4:CAN_4_MESSAGE_58_DLC%%U;
    canREG4->IF2CMD  = (uint8) 0xF8U;
    canREG4->IF2NO   = 58U;

#endif
#if %%CAN4:CAN_4_MESSAGE_59_BOOL_ENA%%
    /** - Initialize message 59 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG4->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG4->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_59_MASK%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF1ARB  = (uint32)%%CAN4:CAN_4_MESSAGE_59_ENA%%U | (uint32)%%CAN4:CAN_4_IDENTIFIER_MODE%%U | (uint32)%%CAN4:CAN_4_MESSAGE_59_DIR%%U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_59_ID%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF1MCTL = 0x00001000U | (uint32)%%CAN4:CAN_4_MESSAGE_59_INT_ENA%%U | (uint32)%%CAN4:CAN_4_MESSAGE_59_RTR%%U | (uint32)%%CAN4:CAN_4_MESSAGE_59_EOB%%U | (uint32)%%CAN4:CAN_4_MESSAGE_59_DLC%%U;
    canREG4->IF1CMD  = (uint8) 0xF8U;
    canREG4->IF1NO   = 59U;

#endif
#if %%CAN4:CAN_4_MESSAGE_60_BOOL_ENA%%
    /** - Initialize message 60 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG4->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG4->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_60_MASK%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF2ARB  = (uint32)%%CAN4:CAN_4_MESSAGE_60_ENA%%U | (uint32)%%CAN4:CAN_4_IDENTIFIER_MODE%%U | (uint32)%%CAN4:CAN_4_MESSAGE_60_DIR%%U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_60_ID%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF2MCTL = 0x00001000U | (uint32)%%CAN4:CAN_4_MESSAGE_60_INT_ENA%%U | (uint32)%%CAN4:CAN_4_MESSAGE_60_RTR%%U | (uint32)%%CAN4:CAN_4_MESSAGE_60_EOB%%U | (uint32)%%CAN4:CAN_4_MESSAGE_60_DLC%%U;
    canREG4->IF2CMD  = (uint8) 0xF8U;
    canREG4->IF2NO   = 60U;

#endif
#if %%CAN4:CAN_4_MESSAGE_61_BOOL_ENA%%
    /** - Initialize message 61 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG4->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG4->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_61_MASK%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF1ARB  = (uint32)%%CAN4:CAN_4_MESSAGE_61_ENA%%U | (uint32)%%CAN4:CAN_4_IDENTIFIER_MODE%%U | (uint32)%%CAN4:CAN_4_MESSAGE_61_DIR%%U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_61_ID%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF1MCTL = 0x00001000U | (uint32)%%CAN4:CAN_4_MESSAGE_61_INT_ENA%%U | (uint32)%%CAN4:CAN_4_MESSAGE_61_RTR%%U | (uint32)%%CAN4:CAN_4_MESSAGE_61_EOB%%U | (uint32)%%CAN4:CAN_4_MESSAGE_61_DLC%%U;
    canREG4->IF1CMD  = (uint8) 0xF8U;
    canREG4->IF1NO   = 61U;

#endif
#if %%CAN4:CAN_4_MESSAGE_62_BOOL_ENA%%
    /** - Initialize message 62 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG4->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG4->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_62_MASK%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF2ARB  = (uint32)%%CAN4:CAN_4_MESSAGE_62_ENA%%U | (uint32)%%CAN4:CAN_4_IDENTIFIER_MODE%%U | (uint32)%%CAN4:CAN_4_MESSAGE_62_DIR%%U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_62_ID%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF2MCTL = 0x00001000U | (uint32)%%CAN4:CAN_4_MESSAGE_62_INT_ENA%%U | (uint32)%%CAN4:CAN_4_MESSAGE_62_RTR%%U | (uint32)%%CAN4:CAN_4_MESSAGE_62_EOB%%U | (uint32)%%CAN4:CAN_4_MESSAGE_62_DLC%%U;
    canREG4->IF2CMD  = (uint8) 0xF8U;
    canREG4->IF2NO   = 62U;

#endif
#if %%CAN4:CAN_4_MESSAGE_63_BOOL_ENA%%
    /** - Initialize message 63 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG4->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG4->IF1MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_63_MASK%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF1ARB  = (uint32)%%CAN4:CAN_4_MESSAGE_63_ENA%%U | (uint32)%%CAN4:CAN_4_IDENTIFIER_MODE%%U | (uint32)%%CAN4:CAN_4_MESSAGE_63_DIR%%U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_63_ID%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF1MCTL = 0x00001000U | (uint32)%%CAN4:CAN_4_MESSAGE_63_INT_ENA%%U | (uint32)%%CAN4:CAN_4_MESSAGE_63_RTR%%U | (uint32)%%CAN4:CAN_4_MESSAGE_63_EOB%%U | (uint32)%%CAN4:CAN_4_MESSAGE_63_DLC%%U;
    canREG4->IF1CMD  = (uint8) 0xF8U;
    canREG4->IF1NO   = 63U;

#endif
#if %%CAN4:CAN_4_MESSAGE_64_BOOL_ENA%%
    /** - Initialize message 64 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG4->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG4->IF2MSK  = 0xC0000000U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_64_MASK%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF2ARB  = (uint32)%%CAN4:CAN_4_MESSAGE_64_ENA%%U | (uint32)%%CAN4:CAN_4_IDENTIFIER_MODE%%U | (uint32)%%CAN4:CAN_4_MESSAGE_64_DIR%%U | (uint32)((uint32)((uint32)%%CAN4:CAN_4_MESSAGE_64_ID%%U & (uint32)%%CAN4:CAN_4_MASK%%U) << (uint32)%%CAN4:CAN_4_SHIFT%%U);
    canREG4->IF2MCTL = 0x00001000U | (uint32)%%CAN4:CAN_4_MESSAGE_64_INT_ENA%%U | (uint32)%%CAN4:CAN_4_MESSAGE_64_RTR%%U | (uint32)%%CAN4:CAN_4_MESSAGE_64_EOB%%U | (uint32)%%CAN4:CAN_4_MESSAGE_64_DLC%%U;
    canREG4->IF2CMD  = (uint8) 0xF8U;
    canREG4->IF2NO   = 64U;

#endif
    /** - Setup IF1 for data transmission 
    *     - Wait until IF1 is ready for use 
    *     - Set IF1 control byte
    */
	/*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG4->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */
    canREG4->IF1CMD  = 0x87U;

    /** - Setup IF2 for reading data
    *     - Wait until IF1 is ready for use 
    *     - Set IF1 control byte
    */
	/*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG4->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */
    canREG4->IF2CMD = 0x17U;

    /** - Setup bit timing 
    *     - Setup baud rate prescaler extension
    *     - Setup TSeg2
    *     - Setup TSeg1
    *     - Setup sample jump width
    *     - Setup baud rate prescaler
    */
    canREG4->BTR = ((uint32)%%CAN4:CAN_4_BRPE%%U << 16U) |
                   (((uint32)%%CAN4:CAN_4_PHASE_SEG%%U - 1U) << 12U) |
                   ((((uint32)%%CAN4:CAN_4_PROP_SEG%%U + (uint32)%%CAN4:CAN_4_PHASE_SEG%%U) - 1U) << 8U) |
                   (((uint32)%%CAN4:CAN_4_SJW%%U - 1U) << 6U) |
                   (uint32)%%CAN4:CAN_4_BRP%%U;

#else
				   
    /** - CAN4 Port output values */
    canREG4->TIOC =  (uint32)((uint32)%%CAN4:CAN_4_PORT_TX_PSL%%U  << 18U )
                   | (uint32)((uint32)%%CAN4:CAN_4_PORT_TX_PULDIS%%U  << 17U )
                   | (uint32)((uint32)%%CAN4:CAN_4_PORT_TX_PDR%%U  << 16U )  
                   | (uint32)((uint32)%%CAN4:CAN_4_PORT_TX_FUN%%U  << 3U )  
                   | (uint32)((uint32)%%CAN4:CAN_4_PORT_TX_DIR%%U  << 2U )    
                   | (uint32)((uint32)%%CAN4:CAN_4_PORT_TX_DOUT%%U << 1U );
                   
    canREG4->RIOC =  (uint32)((uint32)%%CAN4:CAN_4_PORT_RX_PSL%%U  << 18U )    
                   | (uint32)((uint32)%%CAN4:CAN_4_PORT_RX_PULDIS%%U  << 17U )  
                   | (uint32)((uint32)%%CAN4:CAN_4_PORT_RX_PDR%%U  << 16U )   
                   | (uint32)((uint32)%%CAN4:CAN_4_PORT_RX_FUN%%U  << 3U )  
                   | (uint32)((uint32)%%CAN4:CAN_4_PORT_RX_DIR%%U  << 2U )
                   | (uint32)((uint32)%%CAN4:CAN_4_PORT_RX_DOUT%%U << 1U );       
#endif

#if %%CAN4:CAN_4_PIN_MODE%%

				   
    /** - CAN4 Port output values */
    canREG4->TIOC =  (uint32)((uint32)%%CAN4:CAN_4_PORT_TX_PSL%%U  << 18U )
                   | (uint32)((uint32)%%CAN4:CAN_4_PORT_TX_PULDIS%%U  << 17U )
                   | (uint32)((uint32)%%CAN4:CAN_4_PORT_TX_PDR%%U  << 16U )  
                   | (uint32)((uint32)%%CAN4:CAN_4_PORT_TX_FUN%%U  << 3U )  
                   | (uint32)((uint32)%%CAN4:CAN_4_PORT_TX_DIR%%U  << 2U )    
                   | (uint32)((uint32)%%CAN4:CAN_4_PORT_TX_DOUT%%U << 1U );
                   
    canREG4->RIOC =  (uint32)((uint32)%%CAN4:CAN_4_PORT_RX_PSL%%U  << 18U )    
                   | (uint32)((uint32)%%CAN4:CAN_4_PORT_RX_PULDIS%%U  << 17U )  
                   | (uint32)((uint32)%%CAN4:CAN_4_PORT_RX_PDR%%U  << 16U )   
                   | (uint32)((uint32)%%CAN4:CAN_4_PORT_RX_FUN%%U  << 3U )  
                   | (uint32)((uint32)%%CAN4:CAN_4_PORT_RX_DIR%%U  << 2U )
                   | (uint32)((uint32)%%CAN4:CAN_4_PORT_RX_DOUT%%U << 1U ); 
    /** - Leave configuration and initialization mode  */
    canREG4->CTL &= ~(uint32)(0x00000041U);

#endif
#endif

    /**   @note This function has to be called before the driver can be used.\n
    *           This function has to be executed in privileged mode.\n
    */

@@USERCODE
}


/** @fn uint32 canTransmit(canBASE_t *node, uint32 messageBox, const uint8 * data)
*   @brief Transmits a CAN message
*   @param[in] node Pointer to CAN node:
*              - canREG1: CAN1 node pointer
*              - canREG2: CAN2 node pointer
*              - canREG3: CAN3 node pointer
*              - canREG4: CAN4 node pointer
*   @param[in] messageBox Message box number of CAN node:
*              - canMESSAGE_BOX1: CAN message box 1
*              - canMESSAGE_BOXn: CAN message box n [n: 1-64]
*              - canMESSAGE_BOX64: CAN message box 64
*   @param[in] data Pointer to CAN TX data
*   @return The function will return:
*           - 0: When the setup of the TX message box wasn't successful   
*           - 1: When the setup of the TX message box was successful
*
*   This function writes a CAN message into a CAN message box.
*
*/

@@USERCODE

/* SourceId : CAN_SourceId_002 */
/* DesignId : CAN_DesignId_002 */
/* Requirements : HL_CONQ_CAN_SR5 */
uint32 canTransmit(canBASE_t *node, uint32 messageBox, const uint8 * data)
{
    uint32 i;
    uint32 success  = 0U;
    uint32 regIndex = (messageBox - 1U) >> 5U;
    uint32 bitIndex = 1U << ((messageBox - 1U) & 0x1FU);

@@USERCODE


    /** - Check for pending message:
    *     - pending message, return 0
    *     - no pending message, start new transmission 
    */
    if ((node->TXRQx[regIndex] & bitIndex) != 0U)
    {
        success = 0U;
    }

    else
    {
    /** - Wait until IF1 is ready for use */
	/*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((node->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    /** - Configure IF1 for
	*     - Message direction - Write
	*     - Data Update
	*     - Start Transmission
	*/	
	node->IF1CMD = 0x87U;
	
    /** - Copy TX data into IF1 */
    for (i = 0U; i < 8U; i++)
    {
#if ((__little_endian__ == 1) || (__LITTLE_ENDIAN__ == 1))
        /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are only allowed in this driver" */
        node->IF1DATx[i] = *data;
        /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are only allowed in this driver" */
        data++;
#else
        /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are only allowed in this driver" */
        node->IF1DATx[s_canByteOrder[i]] = *data;
        /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are only allowed in this driver" */
        data++;
#endif
    }

    /** - Copy TX data into message box */
	/*SAFETYMCUSW 93 S MR: 6.1,6.2,10.1,10.2,10.3,10.4 <APPROVED> "LDRA Tool issue" */
    node->IF1NO = (uint8) messageBox;

    success = 1U; 
    }
    /**   @note The function canInit has to be called before this function can be used.\n
    *           The user is responsible to initialize the message box.
    */

@@USERCODE

    return success;
}


/** @fn uint32 canGetData(canBASE_t *node, uint32 messageBox, uint8 * const data)
*   @brief Gets received a CAN message
*   @param[in] node Pointer to CAN node:
*              - canREG1: CAN1 node pointer
*              - canREG2: CAN2 node pointer
*              - canREG3: CAN3 node pointer
*              - canREG4: CAN4 node pointer
*   @param[in] messageBox Message box number of CAN node:
*              - canMESSAGE_BOX1: CAN message box 1
*              - canMESSAGE_BOXn: CAN message box n [n: 1-64]
*              - canMESSAGE_BOX64: CAN message box 64
*   @param[out] data Pointer to store CAN RX data
*   @return The function will return:
*           - 0: When RX message box hasn't received new data   
*           - 1: When RX data are stored in the data buffer   
*           - 3: When RX data are stored in the data buffer and a message was lost   
*
*   This function writes a CAN message into a CAN message box.
*
*/


@@USERCODE

/* SourceId : CAN_SourceId_003 */
/* DesignId : CAN_DesignId_003 */
/* Requirements : HL_CONQ_CAN_SR6 */
uint32 canGetData(canBASE_t *node, uint32 messageBox, uint8 * const data)
{
    uint32       i;
    uint32       size;
    uint8 * pData    = data;
    uint32       success  = 0U;
    uint32       regIndex = (messageBox - 1U) >> 5U;
    uint32       bitIndex = 1U << ((messageBox - 1U) & 0x1FU);

@@USERCODE

    /** - Check if new data have been arrived:
    *     - no new data, return 0
    *     - new data, get received message 
    */
    if ((node->NWDATx[regIndex] & bitIndex) == 0U)
    {
        success = 0U;
    }

    else
    {
    /** - Wait until IF2 is ready for use */
	/*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((node->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

		/** - Configure IF2 for
		*     - Message direction - Read
		*     - Data Read
		*     - Clears NewDat bit in the message object.
		*/	
		node->IF2CMD = 0x17U;
		
    /** - Copy data into IF2 */
	/*SAFETYMCUSW 93 S MR: 6.1,6.2,10.1,10.2,10.3,10.4 <APPROVED> "LDRA Tool issue" */
    node->IF2NO = (uint8) messageBox;

    /** - Wait until data are copied into IF2 */
	/*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((node->IF2STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    /** - Get number of received bytes */
    size = node->IF2MCTL & 0xFU;
		if(size > 0x8U)
		{
			size = 0x8U;
		}
    /** - Copy RX data into destination buffer */
    for (i = 0U; i < size; i++)
    {
#if ((__little_endian__ == 1) || (__LITTLE_ENDIAN__ == 1))
        /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are only allowed in this driver" */
        *pData = node->IF2DATx[i];
        /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are only allowed in this driver" */        
        pData++;
#else
        /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are only allowed in this driver" */
        *pData = node->IF2DATx[s_canByteOrder[i]];
        /*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are only allowed in this driver" */
        pData++;
#endif
    }

    success = 1U;
    }
    /** - Check if data have been lost:
    *     - no data lost, return 1
    *     - data lost, return 3 
    */
    if ((node->IF2MCTL & 0x4000U) == 0x4000U)
    {
        success = 3U;
    }

    /**   @note The function canInit has to be called before this function can be used.\n
    *           The user is responsible to initialize the message box.
    */

@@USERCODE

    return success;
}

/** @fn uint32 canGetID(canBASE_t *node, uint32 messageBox)
*   @brief Gets received a CAN message
*   @param[in] node Pointer to CAN node:
*              - canREG1: CAN1 node pointer
*              - canREG2: CAN2 node pointer
*              - canREG3: CAN3 node pointer
*              - canREG4: CAN4 node pointer
*   @param[in] messageBox Message box number of CAN node:
*              - canMESSAGE_BOX1: CAN message box 1
*              - canMESSAGE_BOXn: CAN message box n [n: 1-64]
*              - canMESSAGE_BOX64: CAN message box 64
*   @param[out] data Pointer to store CAN RX data
*   @return The function will return the ID of the message box.
*
*   This function gets the identifier of a CAN message box.
*
*/
/* SourceId : CAN_SourceId_026 */
/* DesignId : CAN_DesignId_020 */
/* Requirements : HL_CONQ_CAN_SR39 */
uint32 canGetID(canBASE_t *node, uint32 messageBox)
{
    uint32   msgBoxID  = 0U;

    /** - Wait until IF2 is ready for use */
    while ((node->IF2STAT & 0x80U) ==0x80U)
    {
    } /* Wait */

	/** - Configure IF2 for
	*     - Message direction - Read
	*     - Data Read
	*     - Clears NewDat bit in the message object.
	*/
	node->IF2CMD = 0x20U;

    /** - Copy message box number into IF2 */
	/*SAFETYMCUSW 93 S MR: 6.1,6.2,10.1,10.2,10.3,10.4 <APPROVED> "LDRA Tool issue" */
    node->IF2NO = (uint8) messageBox;

    /** - Wait until data are copied into IF2 */
    while ((node->IF2STAT & 0x80U) ==0x80U)
    {
    } /* Wait */

    /* Read Message Box ID from Arbitration register. */
    msgBoxID = (node->IF2ARB & 0x1FFFFFFFU);

    return msgBoxID;

}

/** @fn uint32 canUpdateID(canBASE_t *node, uint32 messageBox, uint32 msgBoxArbitVal)
*   @brief Gets received a CAN message
*   @param[in] node Pointer to CAN node:
*              - canREG1: CAN1 node pointer
*              - canREG2: CAN2 node pointer
*              - canREG3: CAN3 node pointer
*              - canREG4: CAN4 node pointer
*   @param[in] messageBox Message box number of CAN node:
*              - canMESSAGE_BOX1: CAN message box 1
*              - canMESSAGE_BOXn: CAN message box n [n: 1-64]
*              - canMESSAGE_BOX64: CAN message box 64
*	@param[in] msgBoxArbitVal (32 bit value):
*				Bit 31 - Not used.
*				Bit 30 - 0 - The 11-bit ("standard") identifier is used for this message object.
*						 1 - The 29-bit ("extended") identifier is used for this message object.
*				Bit 29 - 0 - Direction = Receive
*						 1 - Direction = Transmit
*				Bit 28:0 - Message Identifier.
*   @return 

*
*   This function changes the Identifier and other arbitration parameters of a CAN Message Box.
*
*/
/* SourceId : CAN_SourceId_027 */
/* DesignId : CAN_DesignId_021 */
/* Requirements : HL_CONQ_CAN_SR40 */
void canUpdateID(canBASE_t *node, uint32 messageBox, uint32 msgBoxArbitVal)
{

    /** - Wait until IF2 is ready for use */
    while ((node->IF2STAT & 0x80U) ==0x80U)
    {
    } /* Wait */

	/** - Configure IF2 for
	*     - Message direction - Read
	*     - Data Read
	*     - Clears NewDat bit in the message object.
	*/
	node->IF2CMD = 0xA0U;
	/* Copy passed value into the arbitration register. */
	node->IF2ARB &= 0x80000000U;
	node->IF2ARB |= (msgBoxArbitVal & 0x7FFFFFFFU);

    /** - Update message box number. */
	/*SAFETYMCUSW 93 S MR: 6.1,6.2,10.1,10.2,10.3,10.4 <APPROVED> "LDRA Tool issue" */
    node->IF2NO = (uint8) messageBox;

    /** - Wait until data are copied into IF2 */
    while ((node->IF2STAT & 0x80U) ==0x80U)
    {
    } /* Wait */

}


/** @fn uint32 canSendRemoteFrame(canBASE_t *node, uint32 messageBox)
*   @brief Transmits a CAN Remote Frame.
*   @param[in] node Pointer to CAN node:
*              - canREG1: CAN1 node pointer
*              - canREG2: CAN2 node pointer
*              - canREG3: CAN3 node pointer
*              - canREG4: CAN4 node pointer
*   @param[in] messageBox Message box number of CAN node:
*              - canMESSAGE_BOX1: CAN message box 1
*              - canMESSAGE_BOXn: CAN message box n [n: 1-64]
*              - canMESSAGE_BOX64: CAN message box 64
*   @param[in] data Pointer to CAN TX data
*   @return The function will return:
*           - 0: When the setup of Send Remote Frame from message box wasn't successful   
*           - 1: When the setup of Send Remote Frame from message box was successful
*
*   This function triggers Remote Frame Transmission from CAN message box.
*   Note : Enable RTR must be set in the Message x Configuration in the GUI( x: 1 - 64)    
*
*/
/* SourceId : CAN_SourceId_028 */
/* DesignId : CAN_DesignId_022 */
/* Requirements : HL_CONQ_CAN_SR23 */
uint32 canSendRemoteFrame(canBASE_t *node, uint32 messageBox)
{

    uint32 success  = 0U;
    uint32 regIndex = (messageBox - 1U) >> 5U;
    uint32 bitIndex = 1U << ((messageBox - 1U) & 0x1FU);

    /** - Check for pending message:
    *     - pending message, return 0
    *     - no pending message, start new transmission
    */
    if ((node->TXRQx[regIndex] & bitIndex) != 0U)
    {
        success = 0U;
    }

    else
    {
		/** - Wait until IF1 is ready for use */
		/*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
		while ((node->IF1STAT & 0x80U) ==0x80U)
		{
		} /* Wait */

		/** - Request Transmission by setting TxRqst in message box */
		node->IF1CMD  = (uint8) 0x84U;

		/** - Trigger Remote Frame Transmit from message box */
		/*SAFETYMCUSW 93 S MR: 6.1,6.2,10.1,10.2,10.3,10.4 <APPROVED> "LDRA Tool issue" */
		node->IF1NO = (uint8) messageBox;

		success = 1U;
    }
    /**   @note The function canInit has to be called before this function can be used.\n
    *           The user is responsible to initialize the message box.
    */
    return success;
}

/** @fn uint32 canFillMessageObjectData(canBASE_t *node, uint32 messageBox, const uint8 * data)
*   @brief Fills the Message Object with the data but does not initiate transmission. 
*   @param[in] node Pointer to CAN node:
*              - canREG1: CAN1 node pointer
*              - canREG2: CAN2 node pointer
*              - canREG3: CAN3 node pointer
*              - canREG4: CAN4 node pointer
*   @param[in] messageBox Message box number of CAN node:
*              - canMESSAGE_BOX1: CAN message box 1
*              - canMESSAGE_BOXn: CAN message box n [n: 1-64]
*              - canMESSAGE_BOX64: CAN message box 64
*   @return The function will return:
*           - 0: When the Fill up of the TX message box wasn't successful   
*           - 1: When the Fill up of the TX message box was successful
*
*   This function fills the Message Object with the data but does not initiate transmission. 
*
*/
/* SourceId : CAN_SourceId_029 */
/* DesignId : CAN_DesignId_023 */
/* Requirements : HL_CONQ_CAN_SR24 */
uint32 canFillMessageObjectData(canBASE_t *node, uint32 messageBox, const uint8 * data)
{
    uint32 i;
    uint32 success  = 0U;
    uint32 regIndex = (messageBox - 1U) >> 5U;
    uint32 bitIndex = 1U << ((messageBox - 1U) & 0x1FU);
    
    /** - Check for pending message:
    *     - pending message, return 0
    *     - no pending message, start new transmission 
    */
    if ((node->TXRQx[regIndex] & bitIndex) != 0U)
    {
        success = 0U;
    }
    else
    {
		/** - Wait until IF1 is ready for use */
		/*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
		while ((node->IF1STAT & 0x80U) ==0x80U)
		{ 
		} /* Wait */

		/** - Configure IF1 for 
		*     - Message direction - Write
		*     - Data Update
		*/	
		node->IF1CMD = 0x83U;
		
		/** - Copy TX data into IF1 */
		for (i = 0U; i < 8U; i++)
		{
#if ((__little_endian__ == 1) || (__LITTLE_ENDIAN__ == 1))
			/*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are only allowed in this driver" */
			node->IF1DATx[i] = *data;
			/*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are only allowed in this driver" */
			/*SAFETYMCUSW 567 S MR:17.1,17.4 <APPROVED> "Pointer increment needed" */
			data++;
#else
			/*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are only allowed in this driver" */
			node->IF1DATx[s_canByteOrder[i]] = *data;
			/*SAFETYMCUSW 45 D MR:21.1 <APPROVED> "Valid non NULL input parameters are only allowed in this driver" */
			/*SAFETYMCUSW 567 S MR:17.1,17.4 <APPROVED> "Pointer increment needed" */
			data++;
#endif
		}

		/** - Copy TX data into message box */
		/*SAFETYMCUSW 93 S MR: 6.1,6.2,10.1,10.2,10.3,10.4 <APPROVED> "LDRA Tool issue" */
		node->IF1NO = (uint8) messageBox;

		success = 1U; 
    }
    
    return success;
    
}

/** @fn uint32 canIsTxMessagePending(canBASE_t *node, uint32 messageBox)
*   @brief Gets Tx message box transmission status
*   @param[in] node Pointer to CAN node:
*              - canREG1: CAN1 node pointer
*              - canREG2: CAN2 node pointer
*              - canREG3: CAN3 node pointer
*              - canREG4: CAN4 node pointer
*   @param[in] messageBox Message box number of CAN node:
*              - canMESSAGE_BOX1: CAN message box 1
*              - canMESSAGE_BOXn: CAN message box n [n: 1-64]
*              - canMESSAGE_BOX64: CAN message box 64
*   @return The function will return the tx request flag
*
*   Checks to see if the Tx message box has a pending Tx request, returns
*   0 is flag not set otherwise will return the Tx request flag itself.
*/


@@USERCODE

/* SourceId : CAN_SourceId_004 */
/* DesignId : CAN_DesignId_004 */
/* Requirements : HL_CONQ_CAN_SR7 */
uint32 canIsTxMessagePending(canBASE_t *node, uint32 messageBox)
{
    uint32 flag;
    uint32 regIndex = (messageBox - 1U) >> 5U;
    uint32 bitIndex = 1U << ((messageBox - 1U) & 0x1FU);

@@USERCODE

    /** - Read Tx request register */
    flag = node->TXRQx[regIndex] & bitIndex;

@@USERCODE

    return flag;
}


/** @fn uint32 canIsRxMessageArrived(canBASE_t *node, uint32 messageBox)
*   @brief Gets Rx message box reception status
*   @param[in] node Pointer to CAN node:
*              - canREG1: CAN1 node pointer
*              - canREG2: CAN2 node pointer
*              - canREG3: CAN3 node pointer
*              - canREG4: CAN4 node pointer
*   @param[in] messageBox Message box number of CAN node:
*              - canMESSAGE_BOX1: CAN message box 1
*              - canMESSAGE_BOXn: CAN message box n [n: 1-64]
*              - canMESSAGE_BOX64: CAN message box 64
*   @return The function will return the new data flag
*
*   Checks to see if the Rx message box has pending Rx data, returns
*   0 is flag not set otherwise will return the Tx request flag itself.
*/


@@USERCODE

/* SourceId : CAN_SourceId_005 */
/* DesignId : CAN_DesignId_005 */
/* Requirements : HL_CONQ_CAN_SR8 */
uint32 canIsRxMessageArrived(canBASE_t *node, uint32 messageBox)
{
    uint32 flag;
    uint32 regIndex = (messageBox - 1U) >> 5U;
    uint32 bitIndex = 1U << ((messageBox - 1U) & 0x1FU);

@@USERCODE

    /** - Read Tx request register */
    flag = node->NWDATx[regIndex] & bitIndex;

@@USERCODE

    return flag;
}


/** @fn uint32 canIsMessageBoxValid(canBASE_t *node, uint32 messageBox)
*   @brief Checks if message box is valid
*   @param[in] node Pointer to CAN node:
*              - canREG1: CAN1 node pointer
*              - canREG2: CAN2 node pointer
*              - canREG3: CAN3 node pointer
*              - canREG4: CAN4 node pointer
*   @param[in] messageBox Message box number of CAN node:
*              - canMESSAGE_BOX1: CAN message box 1
*              - canMESSAGE_BOXn: CAN message box n [n: 1-64]
*              - canMESSAGE_BOX64: CAN message box 64
*   @return The function will return the new data flag
*
*   Checks to see if the message box is valid for operation, returns
*   0 is flag not set otherwise will return the validation flag itself.
*/


@@USERCODE

/* SourceId : CAN_SourceId_006 */
/* DesignId : CAN_DesignId_006 */
/* Requirements : HL_CONQ_CAN_SR9 */
uint32 canIsMessageBoxValid(canBASE_t *node, uint32 messageBox)
{
    uint32 flag;
    uint32 regIndex = (messageBox - 1U) >> 5U;
    uint32 bitIndex = 1U << ((messageBox - 1U) & 0x1FU);

@@USERCODE

    /** - Read Tx request register */
    flag = node->MSGVALx[regIndex] & bitIndex;

@@USERCODE

    return flag;
}


/** @fn uint32 canGetLastError(canBASE_t *node)
*   @brief Gets last RX/TX-Error of CAN message traffic
*   @param[in] node Pointer to CAN node:
*              - canREG1: CAN1 node pointer
*              - canREG2: CAN2 node pointer
*              - canREG3: CAN3 node pointer
*              - canREG4: CAN4 node pointer
*   @return The function will return:
*           - canERROR_OK (0): When no CAN error occurred   
*           - canERROR_STUFF (1): When a stuff error occurred on RX message    
*           - canERROR_FORMAT (2): When a form/format error occurred on RX message   
*           - canERROR_ACKNOWLEDGE (3): When a TX message wasn't acknowledged  
*           - canERROR_BIT1 (4): When a TX message monitored dominant level where recessive is expected   
*           - canERROR_BIT0 (5): When a TX message monitored recessive level where dominant is expected   
*           - canERROR_CRC (6): When a RX message has wrong CRC value   
*           - canERROR_NO (7): When no error occurred since last call of this function   
*      
*
*   This function returns the last occurred error code of an RX or TX message,
*   since the last call of this function.
*
*/


@@USERCODE

/* SourceId : CAN_SourceId_007 */
/* DesignId : CAN_DesignId_007 */
/* Requirements : HL_CONQ_CAN_SR10 */
uint32 canGetLastError(canBASE_t *node)
{
    uint32 errorCode;

@@USERCODE

    /** - Get last error code */
    errorCode = node->ES & 7U;

    /**   @note The function canInit has to be called before this function can be used. */

@@USERCODE

    return errorCode;
}


/** @fn uint32 canGetErrorLevel(canBASE_t *node)
*   @brief Gets error level of a CAN node
*   @param[in] node Pointer to CAN node:
*              - canREG1: CAN1 node pointer
*              - canREG2: CAN2 node pointer
*              - canREG3: CAN3 node pointer
*              - canREG4: CAN4 node pointer
*   @return The function will return:
*           - canLEVEL_ACTIVE (0x00): When RX- and TX error counters are below 96   
*           - canLEVEL_WARNING (0x40): When RX- or TX error counter are between 96 and 127     
*           - canLEVEL_PASSIVE (0x20): When RX- or TX error counter are between 128 and 255     
*           - canLEVEL_BUS_OFF (0x80): When RX- or TX error counter are above 255     
*
*   This function returns the current error level of a CAN node.
*
*/


@@USERCODE

/* SourceId : CAN_SourceId_008 */
/* DesignId : CAN_DesignId_008 */
/* Requirements : HL_CONQ_CAN_SR11 */
uint32 canGetErrorLevel(canBASE_t *node)
{
    uint32 errorLevel;

@@USERCODE

    /** - Get error level */
    errorLevel = node->ES & 0xE0U;

    /**   @note The function canInit has to be called before this function can be used. */

@@USERCODE

    return errorLevel;
}


/** @fn void canEnableErrorNotification(canBASE_t *node)
*   @brief Enable error notification
*   @param[in] node Pointer to CAN node:
*              - canREG1: CAN1 node pointer
*              - canREG2: CAN2 node pointer
*              - canREG3: CAN3 node pointer
*              - canREG4: CAN4 node pointer
*
*   This function will enable the notification for the reaching the error levels warning, passive and bus off.
*/

@@USERCODE

/* SourceId : CAN_SourceId_009 */
/* DesignId : CAN_DesignId_009 */
/* Requirements : HL_CONQ_CAN_SR12 */
void canEnableErrorNotification(canBASE_t *node)
{
@@USERCODE

    node->CTL |= 8U;

    /**   @note The function canInit has to be called before this function can be used. */

@@USERCODE
}

@@USERCODE

/** @fn void canEnableStatusChangeNotification(canBASE_t *node)
*   @brief Enable Status Change notification
*   @param[in] node Pointer to CAN node:
*              - canREG1: CAN1 node pointer
*              - canREG2: CAN2 node pointer
*              - canREG3: CAN3 node pointer
*              - canREG4: CAN4 node pointer
*
*   This function will enable the notification for the status change RxOK, TxOK, PDA, WakeupPnd Interrupt.
*/
/* SourceId : CAN_SourceId_030 */
/* DesignId : CAN_DesignId_024 */
/* Requirements : HL_CONQ_CAN_SR25 */
void canEnableStatusChangeNotification(canBASE_t *node)
{

    node->CTL |= 4U;

    /**   @note The function canInit has to be called before this function can be used. */

}

/** @fn void canDisableStatusChangeNotification(canBASE_t *node)
*   @brief Disable Status Change notification
*   @param[in] node Pointer to CAN node:
*              - canREG1: CAN1 node pointer
*              - canREG2: CAN2 node pointer
*              - canREG3: CAN3 node pointer
*              - canREG4: CAN4 node pointer
*
*   This function will disable the notification for the status change RxOK, TxOK, PDA, WakeupPnd Interrupt.
*/
/* SourceId : CAN_SourceId_031 */
/* DesignId : CAN_DesignId_025 */
/* Requirements : HL_CONQ_CAN_SR26 */
void canDisableStatusChangeNotification(canBASE_t *node)
{
    node->CTL &= ~(uint32)(4U);

    /**   @note The function canInit has to be called before this function can be used. */
}


/** @fn void canDisableErrorNotification(canBASE_t *node)
*   @brief Disable error notification
*   @param[in] node Pointer to CAN node:
*              - canREG1: CAN1 node pointer
*              - canREG2: CAN2 node pointer
*              - canREG3: CAN3 node pointer
*              - canREG4: CAN4 node pointer
*
*   This function will disable the notification for the reaching the error levels warning, passive and bus off.
*/

@@USERCODE

/* SourceId : CAN_SourceId_010 */
/* DesignId : CAN_DesignId_010 */
/* Requirements : HL_CONQ_CAN_SR13 */
void canDisableErrorNotification(canBASE_t *node)
{
@@USERCODE

    node->CTL &= ~(uint32)(8U);

    /**   @note The function canInit has to be called before this function can be used. */

@@USERCODE
}

/** @fn void canEnableloopback(canBASE_t *node, canloopBackType_t Loopbacktype)
*   @brief Disable error notification
*   @param[in] node Pointer to CAN node:
*              - canREG1: CAN1 node pointer
*              - canREG2: CAN2 node pointer
*              - canREG3: CAN3 node pointer
*              - canREG4: CAN4 node pointer
*   @param[in] Loopbacktype Type of Loopback:
*              - Internal_Lbk: Internal Loop Back
*              - External_Lbk: External Loop Back
*              - Internal_Silent_Lbk: Internal Loop Back with Silent mode.
*
*   This function will enable can loopback mode
*/
/* SourceId : CAN_SourceId_011 */
/* DesignId : CAN_DesignId_011 */
/* Requirements : HL_CONQ_CAN_SR21 */
void canEnableloopback(canBASE_t *node, canloopBackType_t Loopbacktype)
{
    /* Enter Test Mode */
    node->CTL |= (uint32)((uint32)1U << 7U);
    
    /* Configure Loopback */
    node->TEST |= (uint32)Loopbacktype;
    
    /**   @note The function canInit has to be called before this function can be used. */
}


/** @fn void canDisableloopback(canBASE_t *node)
*   @brief Disable error notification
*   @param[in] node Pointer to CAN node:
*              - canREG1: CAN1 node pointer
*              - canREG2: CAN2 node pointer
*              - canREG3: CAN3 node pointer
*              - canREG4: CAN4 node pointer
*
*   This function will disable can loopback mode
*/
/* SourceId : CAN_SourceId_012 */
/* DesignId : CAN_DesignId_012 */
/* Requirements : HL_CONQ_CAN_SR22 */
void canDisableloopback(canBASE_t *node)
{

   
    node->TEST &= ~(uint32)(0x00000118U);
	
	/* Exit Test Mode */
    node->CTL &= ~(uint32)((uint32)1U << 7U);
    
    /**   @note The function canInit has to be called before this function can be used. */
}


/** @fn void canIoSetDirection(canBASE_t *node,uint32 TxDir,uint32 RxDir)
*   @brief Set Port Direction
*   @param[in] node Pointer to CAN node:
*              - canREG1: CAN1 node pointer
*              - canREG2: CAN2 node pointer
*              - canREG3: CAN3 node pointer
*              - canREG4: CAN4 node pointer
*   @param[in] TxDir - TX Pin direction
*   @param[in] RxDir - RX Pin direction
*
*   Set the direction of CAN pins at runtime when configured as IO pins.
*/
/* SourceId : CAN_SourceId_013 */
/* DesignId : CAN_DesignId_013 */
/* Requirements : HL_CONQ_CAN_SR14 */
void canIoSetDirection(canBASE_t *node,uint32 TxDir,uint32 RxDir)
{
@@USERCODE

    node->TIOC = ((node->TIOC & 0xFFFFFFFBU) | (TxDir << 2U));
    node->RIOC = ((node->RIOC & 0xFFFFFFFBU) | (RxDir << 2U));    

@@USERCODE
}

/** @fn void canIoSetPort(canBASE_t *node, uint32 TxValue, uint32 RxValue)
*   @brief Write Port Value
*   @param[in] node Pointer to CAN node:
*              - canREG1: CAN1 node pointer
*              - canREG2: CAN2 node pointer
*              - canREG3: CAN3 node pointer
*              - canREG4: CAN4 node pointer
*   @param[in] TxValue - TX Pin value 0 or 1
*   @param[in] RxValue - RX Pin value 0 or 1
*   @req [HL_CONQ_CAN_SR15]
*   
*/


void canIoSetPort(canBASE_t *node, uint32 TxValue, uint32 RxValue)
{
@@USERCODE

    node->TIOC = ((node->TIOC & 0xFFFFFFFDU) | (TxValue << 1U));
    node->RIOC = ((node->RIOC & 0xFFFFFFFDU) | (RxValue << 1U));

@@USERCODE
}

/** @fn uint32 canIoTxGetBit(canBASE_t *node)
*   @brief Read TX Bit
*   @param[in] node Pointer to CAN node:
*              - canREG1: CAN1 node pointer
*              - canREG2: CAN2 node pointer
*              - canREG3: CAN3 node pointer
*
*   Reads a the current value from the TX pin of the given CAN port
*/
/* SourceId : CAN_SourceId_015 */
/* DesignId : CAN_DesignId_015 */
/* Requirements : HL_CONQ_CAN_SR16 */
uint32 canIoTxGetBit(canBASE_t *node)
{
@@USERCODE

    return (node->TIOC & 1U);
}

/** @fn uint32 canIoRxGetBit(canBASE_t *node)
*   @brief Read RX Bit
*   @param[in] node Pointer to CAN node:
*              - canREG1: CAN1 node pointer
*              - canREG2: CAN2 node pointer
*              - canREG3: CAN3 node pointer
*
*   Reads a the current value from the RX pin of the given CAN port
*/
/* SourceId : CAN_SourceId_016 */
/* DesignId : CAN_DesignId_016 */
/* Requirements : HL_CONQ_CAN_SR17 */
uint32 canIoRxGetBit(canBASE_t *node)
{
@@USERCODE

    return (node->RIOC & 1U);
}

#if %%SYSTEM:CAN1_ENABLE%%

/** @fn void can1GetConfigValue(can_config_reg_t *config_reg, config_value_type_t type)
*   @brief Get the initial or current values of the CAN1 configuration registers
*
*	@param[in] *config_reg: pointer to the struct to which the initial or current 
*                           value of the configuration registers need to be stored
*	@param[in] type: 	whether initial or current value of the configuration registers need to be stored
*						- InitialValue: initial value of the configuration registers will be stored 
*                                       in the struct pointed by config_reg
*						- CurrentValue: initial value of the configuration registers will be stored 
*                                       in the struct pointed by config_reg
*
*   This function will copy the initial or current value (depending on the parameter 'type') 
*   of the configuration registers to the struct pointed by config_reg
*
*/
/* SourceId : CAN_SourceId_017 */
/* DesignId : CAN_DesignId_017 */
/* Requirements : HL_CONQ_CAN_SR27 */
void can1GetConfigValue(can_config_reg_t *config_reg, config_value_type_t type)
{
	if (type == InitialValue)
	{
		config_reg->CONFIG_CTL     = CAN1_CTL_CONFIGVALUE;    
		config_reg->CONFIG_ES      = CAN1_ES_CONFIGVALUE;     
		config_reg->CONFIG_BTR     = CAN1_BTR_CONFIGVALUE;    
		config_reg->CONFIG_TEST    = CAN1_TEST_CONFIGVALUE;   
		config_reg->CONFIG_ABOTR   = CAN1_ABOTR_CONFIGVALUE;  
		config_reg->CONFIG_INTMUX0 = CAN1_INTMUX0_CONFIGVALUE;
		config_reg->CONFIG_INTMUX1 = CAN1_INTMUX2_CONFIGVALUE;
		config_reg->CONFIG_INTMUX2 = CAN1_INTMUX2_CONFIGVALUE;
		config_reg->CONFIG_INTMUX3 = CAN1_INTMUX3_CONFIGVALUE;
		config_reg->CONFIG_TIOC    = CAN1_TIOC_CONFIGVALUE;   
		config_reg->CONFIG_RIOC    = CAN1_RIOC_CONFIGVALUE;	
	}
	else
	{
	/*SAFETYMCUSW 134 S MR:12.2 <APPROVED> "Register read back support" */
		config_reg->CONFIG_CTL     = canREG1->CTL;   
		config_reg->CONFIG_ES      = canREG1->ES;     
		config_reg->CONFIG_BTR     = canREG1->BTR;    
		config_reg->CONFIG_TEST    = canREG1->TEST;   
		config_reg->CONFIG_ABOTR   = canREG1->ABOTR;  
		config_reg->CONFIG_INTMUX0 = canREG1->INTMUXx[0];
		config_reg->CONFIG_INTMUX1 = canREG1->INTMUXx[1];
		config_reg->CONFIG_INTMUX2 = canREG1->INTMUXx[2];
		config_reg->CONFIG_INTMUX3 = canREG1->INTMUXx[3];
		config_reg->CONFIG_TIOC    = canREG1->TIOC;
		config_reg->CONFIG_RIOC    = canREG1->RIOC;   
	}
}
#endif
#if %%SYSTEM:CAN2_ENABLE%%
/** @fn void can2GetConfigValue(can_config_reg_t *config_reg, config_value_type_t type)
*   @brief Get the initial or current values of the CAN2 configuration registers
*
*	@param[in] *config_reg: pointer to the struct to which the initial or current 
*                           value of the configuration registers need to be stored
*	@param[in] type: 	whether initial or current value of the configuration registers need to be stored
*						- InitialValue: initial value of the configuration registers will be stored 
*                                       in the struct pointed by config_reg
*						- CurrentValue: initial value of the configuration registers will be stored 
*                                       in the struct pointed by config_reg
*
*   This function will copy the initial or current value (depending on the parameter 'type') 
*   of the configuration registers to the struct pointed by config_reg
*
*/
/* SourceId : CAN_SourceId_018 */
/* DesignId : CAN_DesignId_017 */
/* Requirements : HL_CONQ_CAN_SR28 */
void can2GetConfigValue(can_config_reg_t *config_reg, config_value_type_t type)
{
	if (type == InitialValue)
	{
		config_reg->CONFIG_CTL     = CAN2_CTL_CONFIGVALUE;    
		config_reg->CONFIG_ES      = CAN2_ES_CONFIGVALUE;     
		config_reg->CONFIG_BTR     = CAN2_BTR_CONFIGVALUE;    
		config_reg->CONFIG_TEST    = CAN2_TEST_CONFIGVALUE;   
		config_reg->CONFIG_ABOTR   = CAN2_ABOTR_CONFIGVALUE;  
		config_reg->CONFIG_INTMUX0 = CAN2_INTMUX0_CONFIGVALUE;
		config_reg->CONFIG_INTMUX1 = CAN2_INTMUX2_CONFIGVALUE;
		config_reg->CONFIG_INTMUX2 = CAN2_INTMUX2_CONFIGVALUE;
		config_reg->CONFIG_INTMUX3 = CAN2_INTMUX3_CONFIGVALUE;
		config_reg->CONFIG_TIOC    = CAN2_TIOC_CONFIGVALUE;   
		config_reg->CONFIG_RIOC    = CAN2_RIOC_CONFIGVALUE;	
	}
	else
	{
	/*SAFETYMCUSW 134 S MR:12.2 <APPROVED> "Register read back support" */
		config_reg->CONFIG_CTL     = canREG2->CTL;   
		config_reg->CONFIG_ES      = canREG2->ES;     
		config_reg->CONFIG_BTR     = canREG2->BTR;    
		config_reg->CONFIG_TEST    = canREG2->TEST;   
		config_reg->CONFIG_ABOTR   = canREG2->ABOTR;  
		config_reg->CONFIG_INTMUX0 = canREG2->INTMUXx[0];
		config_reg->CONFIG_INTMUX1 = canREG2->INTMUXx[1];
		config_reg->CONFIG_INTMUX2 = canREG2->INTMUXx[2];
		config_reg->CONFIG_INTMUX3 = canREG2->INTMUXx[3];
		config_reg->CONFIG_TIOC    = canREG2->TIOC;
		config_reg->CONFIG_RIOC    = canREG2->RIOC;   
	}
}
#endif
#if %%SYSTEM:CAN3_ENABLE%%
/** @fn void can3GetConfigValue(can_config_reg_t *config_reg, config_value_type_t type)
*   @brief Get the initial or current values of the CAN3 configuration registers
*
*	@param[in] *config_reg: pointer to the struct to which the initial or current 
*                           value of the configuration registers need to be stored
*	@param[in] type: 	whether initial or current value of the configuration registers need to be stored
*						- InitialValue: initial value of the configuration registers will be stored 
*                                       in the struct pointed by config_reg
*						- CurrentValue: initial value of the configuration registers will be stored 
*                                       in the struct pointed by config_reg
*
*   This function will copy the initial or current value (depending on the parameter 'type') 
*   of the configuration registers to the struct pointed by config_reg
*
*/
/* SourceId : CAN_SourceId_019 */
/* DesignId : CAN_DesignId_017 */
/* Requirements : HL_CONQ_CAN_SR29 */
void can3GetConfigValue(can_config_reg_t *config_reg, config_value_type_t type)
{
	if (type == InitialValue)
	{
		config_reg->CONFIG_CTL     = CAN3_CTL_CONFIGVALUE;    
		config_reg->CONFIG_ES      = CAN3_ES_CONFIGVALUE;     
		config_reg->CONFIG_BTR     = CAN3_BTR_CONFIGVALUE;    
		config_reg->CONFIG_TEST    = CAN3_TEST_CONFIGVALUE;   
		config_reg->CONFIG_ABOTR   = CAN3_ABOTR_CONFIGVALUE;  
		config_reg->CONFIG_INTMUX0 = CAN3_INTMUX0_CONFIGVALUE;
		config_reg->CONFIG_INTMUX1 = CAN3_INTMUX2_CONFIGVALUE;
		config_reg->CONFIG_INTMUX2 = CAN3_INTMUX2_CONFIGVALUE;
		config_reg->CONFIG_INTMUX3 = CAN3_INTMUX3_CONFIGVALUE;
		config_reg->CONFIG_TIOC    = CAN3_TIOC_CONFIGVALUE;   
		config_reg->CONFIG_RIOC    = CAN3_RIOC_CONFIGVALUE;	
	}
	else
	{
	/*SAFETYMCUSW 134 S MR:12.2 <APPROVED> "Register read back support" */
		config_reg->CONFIG_CTL     = canREG3->CTL;   
		config_reg->CONFIG_ES      = canREG3->ES;     
		config_reg->CONFIG_BTR     = canREG3->BTR;    
		config_reg->CONFIG_TEST    = canREG3->TEST;   
		config_reg->CONFIG_ABOTR   = canREG3->ABOTR;  
		config_reg->CONFIG_INTMUX0 = canREG3->INTMUXx[0];
		config_reg->CONFIG_INTMUX1 = canREG3->INTMUXx[1];
		config_reg->CONFIG_INTMUX2 = canREG3->INTMUXx[2];
		config_reg->CONFIG_INTMUX3 = canREG3->INTMUXx[3];
		config_reg->CONFIG_TIOC    = canREG3->TIOC;
		config_reg->CONFIG_RIOC    = canREG3->RIOC;   
	}
}
#endif

#if %%SYSTEM:CAN4_ENABLE%%
/** @fn void can4GetConfigValue(can_config_reg_t *config_reg, config_value_type_t type)
*   @brief Get the initial or current values of the CAN4 configuration registers
*
*	@param[in] *config_reg: pointer to the struct to which the initial or current 
*                           value of the configuration registers need to be stored
*	@param[in] type: 	whether initial or current value of the configuration registers need to be stored
*						- InitialValue: initial value of the configuration registers will be stored 
*                                       in the struct pointed by config_reg
*						- CurrentValue: initial value of the configuration registers will be stored 
*                                       in the struct pointed by config_reg
*   
*   This function will copy the initial or current value (depending on the parameter 'type') 
*   of the configuration registers to the struct pointed by config_reg
*
*/
/* SourceId : CAN_SourceId_032 */
/* DesignId : CAN_DesignId_017 */
/* Requirements : HL_CONQ_CAN_SR30 */
void can4GetConfigValue(can_config_reg_t *config_reg, config_value_type_t type)
{
	if (type == InitialValue)
	{
		config_reg->CONFIG_CTL     = CAN4_CTL_CONFIGVALUE;    
		config_reg->CONFIG_ES      = CAN4_ES_CONFIGVALUE;     
		config_reg->CONFIG_BTR     = CAN4_BTR_CONFIGVALUE;    
		config_reg->CONFIG_TEST    = CAN4_TEST_CONFIGVALUE;   
		config_reg->CONFIG_ABOTR   = CAN4_ABOTR_CONFIGVALUE;  
		config_reg->CONFIG_INTMUX0 = CAN4_INTMUX0_CONFIGVALUE;
		config_reg->CONFIG_INTMUX1 = CAN4_INTMUX2_CONFIGVALUE;
		config_reg->CONFIG_INTMUX2 = CAN4_INTMUX2_CONFIGVALUE;
		config_reg->CONFIG_INTMUX3 = CAN4_INTMUX3_CONFIGVALUE;
		config_reg->CONFIG_TIOC    = CAN4_TIOC_CONFIGVALUE;   
		config_reg->CONFIG_RIOC    = CAN4_RIOC_CONFIGVALUE;	
	}
	else
	{
	/*SAFETYMCUSW 134 S MR:12.2 <APPROVED> "Register read back support" */
		config_reg->CONFIG_CTL     = canREG4->CTL;   
		config_reg->CONFIG_ES      = canREG4->ES;     
		config_reg->CONFIG_BTR     = canREG4->BTR;    
		config_reg->CONFIG_TEST    = canREG4->TEST;   
		config_reg->CONFIG_ABOTR   = canREG4->ABOTR;  
		config_reg->CONFIG_INTMUX0 = canREG4->INTMUXx[0];
		config_reg->CONFIG_INTMUX1 = canREG4->INTMUXx[1];
		config_reg->CONFIG_INTMUX2 = canREG4->INTMUXx[2];
		config_reg->CONFIG_INTMUX3 = canREG4->INTMUXx[3];
		config_reg->CONFIG_TIOC    = canREG4->TIOC;
		config_reg->CONFIG_RIOC    = canREG4->RIOC;   
	}
}
#endif

#if %%SYSTEM:CAN1_ENABLE%%
#if %%SYSTEM:VIM_CHANNEL_16_INT_ENABLE%%
@@USERCODE
/** @fn void %%SYSTEM:VIM_CHANNEL_16_NAME%%(void)
*   @brief CAN1 Level 0 Interrupt Handler
*/
#if %%SYSTEM:VIM_CHANNEL_16_INT_PRAGMA_ENABLE%%
#if %%TOOLS:TI%%
#pragma CODE_STATE(%%SYSTEM:VIM_CHANNEL_16_NAME%%, 32)
#pragma INTERRUPT(%%SYSTEM:VIM_CHANNEL_16_NAME%%, %%SYSTEM:VIM_CHANNEL_16_INT_TYPE%%)
#endif
#if %%TOOLS:GHS%%
%%SYSTEM:VIM_CHANNEL_16_INT_TYPE%%(%%SYSTEM:VIM_CHANNEL_16_NAME%%)
#endif
#if %%TOOLS:IAR%%
%%SYSTEM:VIM_CHANNEL_16_INT_TYPE%%
#endif
#if %%TOOLS:ARM%%
%%SYSTEM:VIM_CHANNEL_16_INT_TYPE%%
#endif
#endif

/* SourceId : CAN_SourceId_020 */
/* DesignId : CAN_DesignId_018 */
/* Requirements : HL_CONQ_CAN_SR31 */
void %%SYSTEM:VIM_CHANNEL_16_NAME%%(void)
{
    uint32 value = canREG1->INT;
	uint32 ES_value;

@@USERCODE

    if (value == 0x8000U)
    {
	    /* Read Error and Status Register*/
		ES_value = canREG1->ES;
		
        /* Check for Error (PES, Boff, EWarn & EPass) captured */
        if((ES_value & 0x1E0U) != 0U)
        {
            canErrorNotification(canREG1, ES_value & 0x1E0U);
        }
        else
        {   
		    /* Call General Can notification incase of RxOK, TxOK, PDA, WakeupPnd Interrupt */
            canStatusChangeNotification(canREG1, ES_value & 0x618U);
        }
    }
    else
    {
        /** - Setup IF1 for clear pending interrupt flag */
		/*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
        while ((canREG1->IF1STAT & 0x80U) ==0x80U)
        { 
        } /* Wait */

        canREG1->IF1CMD = 0x08U;
		/*SAFETYMCUSW 93 S MR: 6.1,6.2,10.1,10.2,10.3,10.4 <APPROVED> "LDRA Tool issue" */
        canREG1->IF1NO  = (uint8) value;
		
		/*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
        while ((canREG1->IF1STAT & 0x80U) ==0x80U)
        { 
        } /* Wait */
        canREG1->IF1CMD = 0x87U;

        canMessageNotification(canREG1, value);
    }
@@USERCODE
}
#endif

#if %%SYSTEM:VIM_CHANNEL_29_INT_ENABLE%%
@@USERCODE

/** @fn void %%SYSTEM:VIM_CHANNEL_29_NAME%%(void)
*   @brief CAN1 Level 1 Interrupt Handler
*/
#if %%SYSTEM:VIM_CHANNEL_29_INT_PRAGMA_ENABLE%%
#if %%TOOLS:TI%%
#pragma CODE_STATE(%%SYSTEM:VIM_CHANNEL_29_NAME%%, 32)
#pragma INTERRUPT(%%SYSTEM:VIM_CHANNEL_29_NAME%%, %%SYSTEM:VIM_CHANNEL_29_INT_TYPE%%)
#endif
#if %%TOOLS:GHS%%
%%SYSTEM:VIM_CHANNEL_29_INT_TYPE%%(%%SYSTEM:VIM_CHANNEL_29_NAME%%)
#endif
#if %%TOOLS:IAR%%
%%SYSTEM:VIM_CHANNEL_29_INT_TYPE%%
#endif
#if %%TOOLS:ARM%%
%%SYSTEM:VIM_CHANNEL_29_INT_TYPE%%
#endif
#endif

/* SourceId : CAN_SourceId_021 */
/* DesignId : CAN_DesignId_019 */
/* Requirements : HL_CONQ_CAN_SR32 */
void %%SYSTEM:VIM_CHANNEL_29_NAME%%(void)
{
    uint32 messageBox = canREG1->INT >> 16U;

@@USERCODE

    /** - Setup IF1 for clear pending interrupt flag */
	/*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG1->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG1->IF1CMD = 0x08U;
	/*SAFETYMCUSW 93 S MR: 6.1,6.2,10.1,10.2,10.3,10.4 <APPROVED> "LDRA Tool issue" */
    canREG1->IF1NO  = (uint8) messageBox;
	
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG1->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */
    canREG1->IF1CMD = 0x87U;

    canMessageNotification(canREG1, messageBox);

@@USERCODE
}
#endif
#endif

#if %%SYSTEM:CAN2_ENABLE%%
#if %%SYSTEM:VIM_CHANNEL_35_INT_ENABLE%%
@@USERCODE

/** @fn void %%SYSTEM:VIM_CHANNEL_35_NAME%%(void)
*   @brief CAN2 Level 0 Interrupt Handler
*/
#if %%SYSTEM:VIM_CHANNEL_35_INT_PRAGMA_ENABLE%%
#if %%TOOLS:TI%%
#pragma CODE_STATE(%%SYSTEM:VIM_CHANNEL_35_NAME%%, 32)
#pragma INTERRUPT(%%SYSTEM:VIM_CHANNEL_35_NAME%%, %%SYSTEM:VIM_CHANNEL_35_INT_TYPE%%)
#endif
#if %%TOOLS:GHS%%
%%SYSTEM:VIM_CHANNEL_35_INT_TYPE%%(%%SYSTEM:VIM_CHANNEL_35_NAME%%)
#endif
#if %%TOOLS:IAR%%
%%SYSTEM:VIM_CHANNEL_35_INT_TYPE%%
#endif
#if %%TOOLS:ARM%%
%%SYSTEM:VIM_CHANNEL_35_INT_TYPE%%
#endif
#endif

/* SourceId : CAN_SourceId_022 */
/* DesignId : CAN_DesignId_018 */
/* Requirements : HL_CONQ_CAN_SR33 */
void %%SYSTEM:VIM_CHANNEL_35_NAME%%(void)
{
    uint32 value = canREG2->INT;
	uint32 ES_value;

@@USERCODE

    if (value == 0x8000U)
    {
	    /* Read Error and Status Register*/
		ES_value = canREG2->ES;
		
        /* Check for Error (PES, Boff, EWarn & EPass) captured */
        if((ES_value & 0x1E0U) != 0U)
        {
            canErrorNotification(canREG2, ES_value & 0x1E0U);
        }
        else
        {   
		    /* Call General Can notification incase of RxOK, TxOK, PDA, WakeupPnd Interrupt */
            canStatusChangeNotification(canREG2, ES_value & 0x618U);
        }
    }
    else
    {
        /** - Setup IF1 for clear pending interrupt flag */
		/*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
        while ((canREG2->IF1STAT & 0x80U) ==0x80U)
        { 
        } /* Wait */

        canREG2->IF1CMD = 0x08U;
		/*SAFETYMCUSW 93 S MR: 6.1,6.2,10.1,10.2,10.3,10.4 <APPROVED> "LDRA Tool issue" */
        canREG2->IF1NO  = (uint8) value;
		
        /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
        while ((canREG2->IF1STAT & 0x80U) ==0x80U)
        { 
        } /* Wait */
        canREG2->IF1CMD = 0x87U;

        canMessageNotification(canREG2, value);
    }
@@USERCODE
}
#endif

#if %%SYSTEM:VIM_CHANNEL_42_INT_ENABLE%%
@@USERCODE

/** @fn void %%SYSTEM:VIM_CHANNEL_42_NAME%%(void)
*   @brief CAN2 Level 1 Interrupt Handler
*/
#if %%SYSTEM:VIM_CHANNEL_42_INT_PRAGMA_ENABLE%%
#if %%TOOLS:TI%%
#pragma CODE_STATE(%%SYSTEM:VIM_CHANNEL_42_NAME%%, 32)
#pragma INTERRUPT(%%SYSTEM:VIM_CHANNEL_42_NAME%%, %%SYSTEM:VIM_CHANNEL_42_INT_TYPE%%)
#endif
#if %%TOOLS:GHS%%
%%SYSTEM:VIM_CHANNEL_42_INT_TYPE%%(%%SYSTEM:VIM_CHANNEL_42_NAME%%)
#endif
#if %%TOOLS:IAR%%
%%SYSTEM:VIM_CHANNEL_42_INT_TYPE%%
#endif
#if %%TOOLS:ARM%%
%%SYSTEM:VIM_CHANNEL_42_INT_TYPE%%
#endif
#endif

/* SourceId : CAN_SourceId_023 */
/* DesignId : CAN_DesignId_019 */
/* Requirements : HL_CONQ_CAN_SR34 */
void %%SYSTEM:VIM_CHANNEL_42_NAME%%(void)
{
    uint32 messageBox = canREG2->INT >> 16U;

@@USERCODE

    /** - Setup IF1 for clear pending interrupt flag */
	/*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG2->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG2->IF1CMD = 0x08U;
	/*SAFETYMCUSW 93 S MR: 6.1,6.2,10.1,10.2,10.3,10.4 <APPROVED> "LDRA Tool issue" */
    canREG2->IF1NO  = (uint8) messageBox;
	
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG2->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */
    canREG2->IF1CMD = 0x87U;

    canMessageNotification(canREG2, messageBox);

@@USERCODE
}

#endif
#endif

#if %%SYSTEM:CAN3_ENABLE%%
#if %%SYSTEM:VIM_CHANNEL_45_INT_ENABLE%%
@@USERCODE

/** @fn void %%SYSTEM:VIM_CHANNEL_45_NAME%%(void)
*   @brief CAN3 Level 0 Interrupt Handler
*/
#if %%SYSTEM:VIM_CHANNEL_45_INT_PRAGMA_ENABLE%%
#if %%TOOLS:TI%%
#pragma CODE_STATE(%%SYSTEM:VIM_CHANNEL_45_NAME%%, 32)
#pragma INTERRUPT(%%SYSTEM:VIM_CHANNEL_45_NAME%%, %%SYSTEM:VIM_CHANNEL_45_INT_TYPE%%)
#endif
#if %%TOOLS:GHS%%
%%SYSTEM:VIM_CHANNEL_45_INT_TYPE%%(%%SYSTEM:VIM_CHANNEL_45_NAME%%)
#endif
#if %%TOOLS:IAR%%
%%SYSTEM:VIM_CHANNEL_45_INT_TYPE%%
#endif
#if %%TOOLS:ARM%%
%%SYSTEM:VIM_CHANNEL_45_INT_TYPE%%
#endif
#endif

/* SourceId : CAN_SourceId_024 */
/* DesignId : CAN_DesignId_018 */
/* Requirements : HL_CONQ_CAN_SR35 */
void %%SYSTEM:VIM_CHANNEL_45_NAME%%(void)
{
    uint32 value = canREG3->INT;
	uint32 ES_value;

@@USERCODE

    if (value == 0x8000U)
    {
	    /* Read Error and Status Register*/
		ES_value = canREG3->ES;
		
        /* Check for Error (PES, Boff, EWarn & EPass) captured */
        if((ES_value & 0x1E0U) != 0U)
        {
            canErrorNotification(canREG3, ES_value & 0x1E0U);
        }
        else
        {   
		    /* Call General Can notification incase of RxOK, TxOK, PDA, WakeupPnd Interrupt */
            canStatusChangeNotification(canREG3, ES_value & 0x618U);
        }
    }
    else
    {
        /** - Setup IF1 for clear pending interrupt flag */
		/*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
        while ((canREG3->IF1STAT & 0x80U) ==0x80U)
        { 
        } /* Wait */
     
        canREG3->IF1CMD = 0x08U;
		/*SAFETYMCUSW 93 S MR: 6.1,6.2,10.1,10.2,10.3,10.4 <APPROVED> "LDRA Tool issue" */
        canREG3->IF1NO  = (uint8) value;
        /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
        while ((canREG3->IF1STAT & 0x80U) ==0x80U)
        { 
         } /* Wait */
        canREG3->IF1CMD = 0x87U;
     
        canMessageNotification(canREG3, value);
    }
@@USERCODE
}
#endif

#if %%SYSTEM:VIM_CHANNEL_55_INT_ENABLE%%
/** @fn void %%SYSTEM:VIM_CHANNEL_55_NAME%%(void)
*   @brief CAN3 Level 1 Interrupt Handler
*/
#if %%SYSTEM:VIM_CHANNEL_55_INT_PRAGMA_ENABLE%%
#if %%TOOLS:TI%%
#pragma CODE_STATE(%%SYSTEM:VIM_CHANNEL_55_NAME%%, 32)
#pragma INTERRUPT(%%SYSTEM:VIM_CHANNEL_55_NAME%%, %%SYSTEM:VIM_CHANNEL_55_INT_TYPE%%)
#endif
#if %%TOOLS:GHS%%
%%SYSTEM:VIM_CHANNEL_55_INT_TYPE%%(%%SYSTEM:VIM_CHANNEL_55_NAME%%)
#endif
#if %%TOOLS:IAR%%
%%SYSTEM:VIM_CHANNEL_55_INT_TYPE%%
#endif
#if %%TOOLS:ARM%%
%%SYSTEM:VIM_CHANNEL_55_INT_TYPE%%
#endif
#endif

/* SourceId : CAN_SourceId_025 */
/* DesignId : CAN_DesignId_019 */
/* Requirements : HL_CONQ_CAN_SR36 */
void %%SYSTEM:VIM_CHANNEL_55_NAME%%(void)
{
    uint32 messageBox = canREG3->INT >> 16U;

@@USERCODE

    /** - Setup IF1 for clear pending interrupt flag */
	/*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG3->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */

    canREG3->IF1CMD = 0x08U;
	/*SAFETYMCUSW 93 S MR: 6.1,6.2,10.1,10.2,10.3,10.4 <APPROVED> "LDRA Tool issue" */
    canREG3->IF1NO  = (uint8) messageBox;
    /*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG3->IF1STAT & 0x80U) ==0x80U)
    { 
    } /* Wait */
    canREG3->IF1CMD = 0x87U;

    canMessageNotification(canREG3, messageBox);

@@USERCODE
}
#endif
#endif

#if %%SYSTEM:CAN4_ENABLE%%
#if %%SYSTEM:VIM_CHANNEL_113_INT_ENABLE%%
@@USERCODE

/** @fn void %%SYSTEM:VIM_CHANNEL_113_NAME%%(void)
*   @brief CAN4 Level 0 Interrupt Handler
*/
#if %%SYSTEM:VIM_CHANNEL_113_INT_PRAGMA_ENABLE%%
#if %%TOOLS:TI%%
#pragma CODE_STATE(%%SYSTEM:VIM_CHANNEL_113_NAME%%, 32)
#pragma INTERRUPT(%%SYSTEM:VIM_CHANNEL_113_NAME%%, %%SYSTEM:VIM_CHANNEL_113_INT_TYPE%%)
#endif
#if %%TOOLS:GHS%%
%%SYSTEM:VIM_CHANNEL_113_INT_TYPE%%(%%SYSTEM:VIM_CHANNEL_113_NAME%%)
#endif
#if %%TOOLS:IAR%%
%%SYSTEM:VIM_CHANNEL_113_INT_TYPE%%
#endif
#if %%TOOLS:ARM%%
%%SYSTEM:VIM_CHANNEL_113_INT_TYPE%%
#endif
#endif

/* SourceId : CAN_SourceId_033 */
/* DesignId : CAN_DesignId_018 */
/* Requirements : HL_CONQ_CAN_SR37 */
void %%SYSTEM:VIM_CHANNEL_113_NAME%%(void)
{
    uint32 value = canREG4->INT;
	uint32 ES_value;

@@USERCODE

    if (value == 0x8000U)
    {
	    /* Read Error and Status Register*/
		ES_value = canREG4->ES;
		
        /* Check for Error (PES, Boff, EWarn & EPass) captured */
		if((ES_value & 0x1E0U) != 0U)
        {
            canErrorNotification(canREG4, ES_value & 0x1E0U);
        }
        else
        {   
		    /* Call General Can notification incase of RxOK, TxOK, PDA, WakeupPnd Interrupt */
            canStatusChangeNotification(canREG4, ES_value & 0x618U);
        }
    }
    else
    {
        /** - Setup IF1 for clear pending interrupt flag */
		/*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
        while ((canREG4->IF1STAT & 0x80U) ==0x80U)
        { 
        } /* Wait */

        canREG4->IF1CMD = 0x08U;
		/*SAFETYMCUSW 93 S MR: 6.1,6.2,10.1,10.2,10.3,10.4 <APPROVED> "LDRA Tool issue" */
        canREG4->IF1NO  = (uint8) value;
		
		/*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
        while ((canREG4->IF1STAT & 0x80U) ==0x80U)
        { 
        } /* Wait */
        canREG4->IF1CMD = 0x87U;

        canMessageNotification(canREG4, value);
    }
@@USERCODE
}
#endif

#if %%SYSTEM:VIM_CHANNEL_117_INT_ENABLE%%
/** @fn void %%SYSTEM:VIM_CHANNEL_117_NAME%%(void)
*   @brief CAN4 Level 1 Interrupt Handler
*/
#if %%SYSTEM:VIM_CHANNEL_117_INT_PRAGMA_ENABLE%%
#if %%TOOLS:TI%%
#pragma CODE_STATE(%%SYSTEM:VIM_CHANNEL_117_NAME%%, 32)
#pragma INTERRUPT(%%SYSTEM:VIM_CHANNEL_117_NAME%%, %%SYSTEM:VIM_CHANNEL_117_INT_TYPE%%)
#endif
#if %%TOOLS:GHS%%
%%SYSTEM:VIM_CHANNEL_117_INT_TYPE%%(%%SYSTEM:VIM_CHANNEL_117_NAME%%)
#endif
#if %%TOOLS:IAR%%
%%SYSTEM:VIM_CHANNEL_117_INT_TYPE%%
#endif
#if %%TOOLS:ARM%%
%%SYSTEM:VIM_CHANNEL_117_INT_TYPE%%
#endif
#endif

/* SourceId : CAN_SourceId_034 */
/* DesignId : CAN_DesignId_019 */
/* Requirements : HL_CONQ_CAN_SR38 */
void %%SYSTEM:VIM_CHANNEL_117_NAME%%(void)
{
    uint32 messageBox = canREG4->INT >> 16U;

@@USERCODE

    /** - Setup IF1 for clear pending interrupt flag */
	/*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG4->IF1STAT & 0x80U) ==0x80U)
    { 
	} /* Wait */

    canREG4->IF1CMD = 0x08U;
    canREG4->IF1NO  = (uint8)messageBox;

	/*SAFETYMCUSW 28 D MR:NA <APPROVED> "Potentially infinite loop found - Hardware Status check for execution sequence" */
    while ((canREG4->IF1STAT & 0x80U) ==0x80U)
    { 
	} /* Wait */
    canREG4->IF1CMD = 0x87U;

    canMessageNotification(canREG4, messageBox);

@@USERCODE
}
#endif
#endif

#endif
