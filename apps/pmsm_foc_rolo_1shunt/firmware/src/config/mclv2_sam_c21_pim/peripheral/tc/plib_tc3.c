/*******************************************************************************
  Timer/Counter(TC3) PLIB

  Company
    Microchip Technology Inc.

  File Name
    plib_tc3.c

  Summary
    TC3 PLIB Implementation File.

  Description
    This file defines the interface to the TC peripheral library. This
    library provides access to and control of the associated peripheral
    instance.

  Remarks:
    None.

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
/* This section lists the other files that are included in this file.
*/

#include "plib_tc3.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data
// *****************************************************************************
// *****************************************************************************


// *****************************************************************************
// *****************************************************************************
// Section: TC3 Implementation
// *****************************************************************************
// *****************************************************************************

/* Initialize TC module in Compare Mode */
void TC3_CompareInitialize( void )
{
    /* Reset TC */
    TC3_REGS->COUNT16.TC_CTRLA = TC_CTRLA_SWRST_Msk;

    while((TC3_REGS->COUNT16.TC_SYNCBUSY & TC_SYNCBUSY_SWRST_Msk) == TC_SYNCBUSY_SWRST_Msk)
    {
        /* Wait for Write Synchronization */
    }

    /* Configure counter mode & prescaler */
    TC3_REGS->COUNT16.TC_CTRLA = TC_CTRLA_MODE_COUNT16 | TC_CTRLA_PRESCALER_DIV1 | TC_CTRLA_PRESCSYNC_PRESC ;

    /* Configure waveform generation mode */
    TC3_REGS->COUNT16.TC_WAVE = TC_WAVE_WAVEGEN_MPWM;


    TC3_REGS->COUNT16.TC_CC[0] = 48U;
    TC3_REGS->COUNT16.TC_CC[1] = 24U;

    /* Clear all interrupt flags */
    TC3_REGS->COUNT16.TC_INTFLAG = TC_INTFLAG_Msk;


    while((TC3_REGS->COUNT16.TC_SYNCBUSY))
    {
        /* Wait for Write Synchronization */
    }
}

/* Enable the counter */
void TC3_CompareStart( void )
{
    TC3_REGS->COUNT16.TC_CTRLA |= TC_CTRLA_ENABLE_Msk;
    while((TC3_REGS->COUNT16.TC_SYNCBUSY & TC_SYNCBUSY_ENABLE_Msk) == TC_SYNCBUSY_ENABLE_Msk)
    {
        /* Wait for Write Synchronization */
    }
}

/* Disable the counter */
void TC3_CompareStop( void )
{
    TC3_REGS->COUNT16.TC_CTRLA &= ~TC_CTRLA_ENABLE_Msk;
    while((TC3_REGS->COUNT16.TC_SYNCBUSY & TC_SYNCBUSY_ENABLE_Msk) == TC_SYNCBUSY_ENABLE_Msk)
    {
        /* Wait for Write Synchronization */
    }
}

uint32_t TC3_CompareFrequencyGet( void )
{
    return (uint32_t)(48000000UL);
}

/* Get the current counter value */
uint16_t TC3_Compare16bitCounterGet( void )
{
    /* Write command to force COUNT register read synchronization */
    TC3_REGS->COUNT16.TC_CTRLBSET |= TC_CTRLBSET_CMD_READSYNC;

    while((TC3_REGS->COUNT16.TC_SYNCBUSY & TC_SYNCBUSY_CTRLB_Msk) == TC_SYNCBUSY_CTRLB_Msk)
    {
        /* Wait for Write Synchronization */
    }

    /* Read current count value */
    return (uint16_t)TC3_REGS->COUNT16.TC_COUNT;
}

/* Configure counter value */
void TC3_Compare16bitCounterSet( uint16_t count )
{
    TC3_REGS->COUNT16.TC_COUNT = count;

    while((TC3_REGS->COUNT16.TC_SYNCBUSY & TC_SYNCBUSY_COUNT_Msk) == TC_SYNCBUSY_COUNT_Msk)
    {
        /* Wait for Write Synchronization */
    }
}

/* Configure period value */
void TC3_Compare16bitPeriodSet( uint16_t period )
{
    /* Configure period value */
    TC3_REGS->COUNT16.TC_CCBUF[0] = period;
}

/* Read period value */
uint16_t TC3_Compare16bitPeriodGet( void )
{
    /* Get period value */
    return (uint16_t)TC3_REGS->COUNT16.TC_CC[0];
}


/* Configure duty cycle value */
void TC3_Compare16bitSet( uint16_t compareValue )
{
    /* Set new compare value for compare channel 1 */
    TC3_REGS->COUNT16.TC_CCBUF[1] = compareValue;
}




/* Check if period interrupt flag is set */
TC_COMPARE_STATUS TC3_CompareStatusGet( void )
{
    TC_COMPARE_STATUS compare_status;
    compare_status = ((TC3_REGS->COUNT16.TC_INTFLAG) & TC_COMPARE_STATUS_MSK);
    /* Clear timer overflow interrupt */
    TC3_REGS->COUNT16.TC_INTFLAG = compare_status;
    return compare_status;
}
