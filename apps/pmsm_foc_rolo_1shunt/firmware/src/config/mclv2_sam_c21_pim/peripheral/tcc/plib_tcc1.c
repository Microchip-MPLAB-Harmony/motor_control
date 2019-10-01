/*******************************************************************************
  TCC Peripheral Library Interface Source File

  Company
    Microchip Technology Inc.

  File Name
    plib_tcc1.c

  Summary
    TCC1 peripheral library source file.

  Description
    This file implements the interface to the TCC peripheral library.  This
    library provides access to and control of the associated peripheral
    instance.

*******************************************************************************/

// DOM-IGNORE-BEGIN
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
// DOM-IGNORE-END


// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

/*  This section lists the other files that are included in this file.
*/

#include "plib_tcc1.h"



/* Initialize TCC module */
void TCC1_PWMInitialize(void)
{
    /* Reset TCC */
    TCC1_REGS->TCC_CTRLA = TCC_CTRLA_SWRST_Msk;
    while (TCC1_REGS->TCC_SYNCBUSY & (TCC_SYNCBUSY_SWRST_Msk))
    {
        /* Wait for sync */
    }
    /* Clock prescaler */
    TCC1_REGS->TCC_CTRLA = TCC_CTRLA_PRESCALER_DIV1 ;

    TCC1_REGS->TCC_WAVE = TCC_WAVE_WAVEGEN_DSBOTTOM;

    /* Configure duty cycle values */
    TCC1_REGS->TCC_CC[0] = 1000U;
    TCC1_REGS->TCC_CC[1] = 2000U;
    TCC1_REGS->TCC_PER = 6000U;




    TCC1_REGS->TCC_EVCTRL |= TCC_EVCTRL_MCEO0_Msk | TCC_EVCTRL_MCEO1_Msk;
    while (TCC1_REGS->TCC_SYNCBUSY)
    {
        /* Wait for sync */
    }
}


/* Start the PWM generation */
void TCC1_PWMStart(void)
{
    TCC1_REGS->TCC_CTRLA |= TCC_CTRLA_ENABLE_Msk;
    while (TCC1_REGS->TCC_SYNCBUSY & (TCC_SYNCBUSY_ENABLE_Msk))
    {
        /* Wait for sync */
    }
}

/* Stop the PWM generation */
void TCC1_PWMStop (void)
{
    TCC1_REGS->TCC_CTRLA &= ~TCC_CTRLA_ENABLE_Msk;
    while (TCC1_REGS->TCC_SYNCBUSY & (TCC_SYNCBUSY_ENABLE_Msk))
    {
        /* Wait for sync */
    }
}

/* Configure PWM period */
void TCC1_PWM24bitPeriodSet (uint32_t period)
{
    TCC1_REGS->TCC_PERBUF = period & 0xFFFFFF;
}

/* Read TCC period */
uint32_t TCC1_PWM24bitPeriodGet (void)
{
    while (TCC1_REGS->TCC_SYNCBUSY & (TCC_SYNCBUSY_PER_Msk))
    {
        /* Wait for sync */
    }
    return (TCC1_REGS->TCC_PER & 0xFFFFFF);
}


void TCC1_PWMPatternSet(uint8_t pattern_enable, uint8_t pattern_output)
{
    TCC1_REGS->TCC_PATTBUF = (uint16_t)(pattern_enable | (pattern_output << 8));
}

/* Set the counter*/
void TCC1_PWM24bitCounterSet (uint32_t count_value)
{
    TCC1_REGS->TCC_COUNT = count_value & 0xFFFFFF;
    while (TCC1_REGS->TCC_SYNCBUSY & (TCC_SYNCBUSY_COUNT_Msk))
    {
        /* Wait for sync */
    }
}

/* Enable forced synchronous update */
void TCC1_PWMForceUpdate(void)
{
    TCC1_REGS->TCC_CTRLBSET |= TCC_CTRLBCLR_CMD_UPDATE;
    while (TCC1_REGS->TCC_SYNCBUSY & (TCC_SYNCBUSY_CTRLB_Msk))
    {
        /* Wait for sync */
    }
}

/* Enable the period interrupt - overflow or underflow interrupt */
void TCC1_PWMPeriodInterruptEnable(void)
{
    TCC1_REGS->TCC_INTENSET = TCC_INTENSET_OVF_Msk;
}

/* Disable the period interrupt - overflow or underflow interrupt */
void TCC1_PWMPeriodInterruptDisable(void)
{
    TCC1_REGS->TCC_INTENCLR = TCC_INTENCLR_OVF_Msk;
}

/* Read interrupt flags */
uint32_t TCC1_PWMInterruptStatusGet(void)
{
    uint32_t interrupt_status;
    interrupt_status = TCC1_REGS->TCC_INTFLAG;
    /* Clear interrupt flags */
    TCC1_REGS->TCC_INTFLAG = interrupt_status;
    return interrupt_status;
}


/**
 End of File
*/
