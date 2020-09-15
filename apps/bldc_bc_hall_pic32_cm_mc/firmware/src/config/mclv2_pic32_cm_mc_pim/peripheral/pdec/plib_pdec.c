/*******************************************************************************
  Position Decoder(PDEC) PLIB

  Company
    Microchip Technology Inc.

  File Name
    plib_pdec.c

  Summary
    PDEC PLIB Implementation File.

  Description
    This file defines the interface to the PDEC peripheral library. This
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

#include "plib_pdec.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data
// *****************************************************************************
// *****************************************************************************
/* Object to hold callback function and context */
PDEC_HALL_CALLBACK_OBJ PDEC_HALL_CallbackObj;

// *****************************************************************************
// *****************************************************************************
// Section: PDEC Implementation
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Initialize the PDEC module in Quadrature mode */
void PDEC_HALLInitialize( void )
{
    /* Reset PDEC */
    PDEC_REGS->PDEC_CTRLA = PDEC_CTRLA_SWRST_Msk;

    while((PDEC_REGS->PDEC_SYNCBUSY & PDEC_SYNCBUSY_SWRST_Msk) == PDEC_SYNCBUSY_SWRST_Msk)
    {
        /* Wait for Write Synchronization */
    }

    /* Configure quadrature control settings */
    PDEC_REGS->PDEC_CTRLA = PDEC_CTRLA_MODE_HALL
                  | PDEC_CTRLA_PINEN(0x7) | PDEC_CTRLA_PINVEN(0x0); 
    PDEC_REGS->PDEC_PRESC = PDEC_PRESC_PRESC_DIV1;
    PDEC_REGS->PDEC_FILTER = PDEC_FILTER_FILTER(2);

    /* Clear all interrupt flags */
    PDEC_REGS->PDEC_INTFLAG = PDEC_INTFLAG_Msk;

    PDEC_REGS->PDEC_INTENSET = 0x8;
    PDEC_HALL_CallbackObj.callback = NULL;

    PDEC_REGS->PDEC_EVCTRL = 0x0;

    while((PDEC_REGS->PDEC_SYNCBUSY))
    {
        /* Wait for Write Synchronization */
    }
}

/* Enable and start the hall operation */
void PDEC_HALLStart( void )
{
    PDEC_REGS->PDEC_CTRLA |= PDEC_CTRLA_ENABLE_Msk;
    PDEC_REGS->PDEC_CTRLBSET = PDEC_CTRLBSET_CMD_START;
    while((PDEC_REGS->PDEC_SYNCBUSY))
    {
        /* Wait for Write Synchronization */
    }
}

/* Disable and stop the hall operation */
void PDEC_HALLStop( void )
{
    PDEC_REGS->PDEC_CTRLBSET = PDEC_CTRLBSET_CMD_STOP;
    PDEC_REGS->PDEC_CTRLA &= ~PDEC_CTRLA_ENABLE_Msk;
    while((PDEC_REGS->PDEC_SYNCBUSY))
    {
        /* Wait for Write Synchronization */
    }
}

/* Read the hall pattern */
uint8_t PDEC_HALLPatternGet( void )
{
    PDEC_REGS->PDEC_CTRLBSET = PDEC_CTRLBSET_CMD_READSYNC;
    while(PDEC_REGS->PDEC_SYNCBUSY)
    {
        /* Wait for read Synchronization */
    }
    while((PDEC_REGS->PDEC_CTRLBSET & PDEC_CTRLBSET_CMD_Msk) != PDEC_CTRLBSET_CMD_NONE)
    {
        /* Wait for CMD to become zero */
    }
    return (uint8_t)(PDEC_REGS->PDEC_COUNT & 0x07);
}


/* Set the hall pattern */
void PDEC_HALLPatternSet( uint8_t pattern )
{
    PDEC_REGS->PDEC_CCBUF[0] = (pattern & 0x07);
    while(PDEC_REGS->PDEC_SYNCBUSY)
    {
        /* Wait for write Synchronization */
    }
}

void PDEC_HALLTimeWindowSet(uint16_t low_window, uint16_t high_window)
{
    PDEC_REGS->PDEC_CCBUF[0] = low_window << 16;
    PDEC_REGS->PDEC_CCBUF[1] = high_window << 16;
    while(PDEC_REGS->PDEC_SYNCBUSY)
    {
        /* Wait for write Synchronization */
    }
}


void PDEC_HALLCallbackRegister( PDEC_HALL_CALLBACK callback, uintptr_t context )
{
    PDEC_HALL_CallbackObj.callback = callback;
    PDEC_HALL_CallbackObj.context = context;
}

void PDEC_InterruptHandler( void )
{
    PDEC_HALL_STATUS status;
    status = (PDEC_HALL_STATUS) PDEC_REGS->PDEC_INTFLAG;
    /* Clear interrupt flags */
    PDEC_REGS->PDEC_INTFLAG = 0xFF;
    if (PDEC_HALL_CallbackObj.callback != NULL)
    {
        PDEC_HALL_CallbackObj.callback(status, PDEC_HALL_CallbackObj.context);
    }

}


