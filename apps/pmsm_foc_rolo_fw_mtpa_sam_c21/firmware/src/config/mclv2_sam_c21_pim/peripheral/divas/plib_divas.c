/*******************************************************************************
  Divide Square Root Accelerator (DIVAS) PLIB

  Company:
    Microchip Technology Inc.

  File Name:
    plib_divas.c

  Summary:
    DIVAS PLIB Implementation File

  Description:
    This file defines the interface to the DIVAS peripheral library. This
    library provides access to and control of the associated peripheral
    instance.

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


#include "plib_divas.h"
#include "device.h"


void DIVAS_Initialize(void)
{
    /* Leading Zero optimization is by default enabled*/
}

#define _DIVAS_CRITICAL_ENTER()                        \
    do {                                               \
        volatile uint32_t globalInterruptState;        \
        globalInterruptState = __get_PRIMASK();        \
        __disable_irq()
#define _DIVAS_CRITICAL_LEAVE()                        \
        __set_PRIMASK(globalInterruptState);           \
    }                                                  \
    while (0)

/* Return 32 bit result, the result only. */
#define _divas_result32() (DIVAS_REGS->DIVAS_RESULT)

/* Return 64 bit result, the result and remainder. */
#define _divas_result64() (*((uint64_t *)(&DIVAS_REGS->DIVAS_RESULT)))

static inline void _divas_div(const uint8_t sign, const uint32_t dividend, const uint32_t divisor)
{
    DIVAS_REGS->DIVAS_CTRLA = (DIVAS_REGS->DIVAS_CTRLA & ~DIVAS_CTRLA_SIGNED_Msk) | sign ;
    DIVAS_REGS->DIVAS_DIVIDEND = dividend;
    DIVAS_REGS->DIVAS_DIVISOR  = divisor;
    while((DIVAS_REGS->DIVAS_STATUS & DIVAS_STATUS_BUSY_Msk) == DIVAS_STATUS_BUSY_Msk)
    {
        /* Wait for the square root to complete */
    }
}

/* Do signed division, return result */
int32_t __aeabi_idiv(int32_t numerator, int32_t denominator)
{
    int32_t res;
    _DIVAS_CRITICAL_ENTER();
    _divas_div(1, numerator, denominator);
    res = _divas_result32();
    _DIVAS_CRITICAL_LEAVE();
    return res;
}

/* Do unsigned division, return result */
uint32_t __aeabi_uidiv(uint32_t numerator, uint32_t denominator)
{
    uint32_t res;
    _DIVAS_CRITICAL_ENTER();
    _divas_div(0, numerator, denominator);
    res = _divas_result32();
    _DIVAS_CRITICAL_LEAVE();
    return res;
}

/* Do signed division, return result and remainder */
uint64_t __aeabi_idivmod(int32_t numerator, int32_t denominator)
{
    uint64_t res;
    _DIVAS_CRITICAL_ENTER();
    _divas_div(1, numerator, denominator);
    res = _divas_result64();
    _DIVAS_CRITICAL_LEAVE();
    return res;
}

/* Do unsigned division, return result and remainder */
uint64_t __aeabi_uidivmod(uint32_t numerator, uint32_t denominator)
{
    uint64_t res;
    _DIVAS_CRITICAL_ENTER();
    _divas_div(0, numerator, denominator);
    res = _divas_result64();
    _DIVAS_CRITICAL_LEAVE();
    return res;
}

uint32_t DIVAS_SquareRoot(uint32_t number)
{
    uint32_t res = 0;

    _DIVAS_CRITICAL_ENTER();
    DIVAS_REGS->DIVAS_SQRNUM = number;
    while((DIVAS_REGS->DIVAS_STATUS & DIVAS_STATUS_BUSY_Msk) == DIVAS_STATUS_BUSY_Msk)
    {
        /* Wait for the square root to complete */
    }
    res = DIVAS_REGS->DIVAS_RESULT;
    _DIVAS_CRITICAL_LEAVE();


    return res;
}
