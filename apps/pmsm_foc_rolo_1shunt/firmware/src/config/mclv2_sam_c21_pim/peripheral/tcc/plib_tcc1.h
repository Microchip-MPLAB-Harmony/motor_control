/*******************************************************************************
  Data Type definition of Timer/Counter(TCC) PLIB

  Company:
    Microchip Technology Inc.

  File Name:
    plib_tcc1.h

  Summary:
    Data Type definition of the TCC Peripheral Interface Plib.

  Description:
    This file defines the Data Types for the TCC Plib.

  Remarks:
    None.

*******************************************************************************/

/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/

#ifndef PLIB_TCC1_H
#define PLIB_TCC1_H

#include "device.h"
#include "plib_tcc_common.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************
/*  The following data type definitions are used by the functions in this
    interface and should be considered part it.
*/

/* Total number of TCC channels in a module */
#define TCC1_NUM_CHANNELS    (2U)

/* TCC Channel numbers

   Summary:
    Identifies channel number within TCC module

   Description:
    This enumeration identifies TCC channel number.

   Remarks:
    None.
*/
typedef enum
{
    TCC1_CHANNEL0,
    TCC1_CHANNEL1,
}TCC1_CHANNEL_NUM;

// *****************************************************************************

/* TCC Channel interrupt status

   Summary:
    Identifies TCC PWM interrupt status flags

   Description:
    This enumeration identifies TCC PWM interrupt status falgs

   Remarks:
    None.
*/
typedef enum
{
    TCC1_PWM_STATUS_OVF = TCC_INTFLAG_OVF_Msk,
    TCC1_PWM_STATUS_FAULT_0 = TCC_INTFLAG_FAULT0_Msk,
    TCC1_PWM_STATUS_FAULT_1 = TCC_INTFLAG_FAULT1_Msk,
    TCC1_PWM_STATUS_MC_0 = TCC_INTFLAG_MC0_Msk,
    TCC1_PWM_STATUS_MC_1 = TCC_INTFLAG_MC1_Msk,
}TCC1_PWM_STATUS;

// *****************************************************************************
// *****************************************************************************
// Section: Interface Routines
// *****************************************************************************
// *****************************************************************************
/* The following functions make up the methods (set of possible operations) of
   this interface.
*/

// *****************************************************************************
void TCC1_PWMInitialize(void);

void TCC1_PWMStart(void);

void TCC1_PWMStop(void);


void TCC1_PWMForceUpdate(void);

void TCC1_PWMPatternSet(uint8_t pattern_enable, uint8_t pattern_output);

void TCC1_PWMPeriodInterruptEnable(void);

void TCC1_PWMPeriodInterruptDisable(void);

uint32_t TCC1_PWMInterruptStatusGet(void);

void TCC1_PWM24bitPeriodSet(uint32_t period);

uint32_t TCC1_PWM24bitPeriodGet(void);

void TCC1_PWM24bitCounterSet(uint32_t count);

__STATIC_INLINE void TCC1_PWM24bitDutySet(TCC1_CHANNEL_NUM channel, uint32_t duty)
{
    TCC1_REGS->TCC_CCBUF[channel] = duty & 0xFFFFFF;
}

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

    }
#endif
// DOM-IGNORE-END

#endif /* PLIB_TCC1_H */
