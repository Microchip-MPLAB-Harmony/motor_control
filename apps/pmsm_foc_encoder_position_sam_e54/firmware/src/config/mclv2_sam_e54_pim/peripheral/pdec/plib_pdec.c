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
PDEC_QDEC_CALLBACK_OBJ PDEC_QDEC_CallbackObj;

// *****************************************************************************
// *****************************************************************************
// Section: PDEC Implementation
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Initialize the PDEC module in Quadrature mode */
void PDEC_QDECInitialize( void )
{
    /* Reset PDEC */
    PDEC_REGS->PDEC_CTRLA = PDEC_CTRLA_SWRST_Msk;

    while((PDEC_REGS->PDEC_SYNCBUSY & PDEC_SYNCBUSY_SWRST_Msk) == PDEC_SYNCBUSY_SWRST_Msk)
    {
        /* Wait for Write Synchronization */
    }

    /* Configure quadrature control settings */
    PDEC_REGS->PDEC_CTRLA = PDEC_CTRLA_MODE_QDEC | PDEC_CTRLA_CONF_X4
                                | PDEC_CTRLA_PINEN(0x3) | PDEC_CTRLA_PINVEN(0x0)
                                 | PDEC_CTRLA_ANGULAR(7)
                                 | PDEC_CTRLA_MAXCMP(4); 
    PDEC_REGS->PDEC_PRESC = PDEC_PRESC_PRESC_DIV1;
    PDEC_REGS->PDEC_FILTER = PDEC_FILTER_FILTER(5);
                                
    /* Configure angular and revolution period */
    PDEC_REGS->PDEC_CC[0U] = 1023U | (0U << PDEC_ANGULAR_COUNTER_BITS);
    
    /* Clear all interrupt flags */
    PDEC_REGS->PDEC_INTFLAG = PDEC_INTFLAG_Msk;
    

    PDEC_REGS->PDEC_EVCTRL = 0x0;

    while((PDEC_REGS->PDEC_SYNCBUSY))
    {
        /* Wait for Write Synchronization */
    }
}

/* Enable and start the quadrature operation */
void PDEC_QDECStart( void )
{
    PDEC_REGS->PDEC_CTRLA |= PDEC_CTRLA_ENABLE_Msk;
    PDEC_REGS->PDEC_CTRLBSET = PDEC_CTRLBSET_CMD_START;
    while((PDEC_REGS->PDEC_SYNCBUSY))
    {
        /* Wait for Write Synchronization */
    }
}

/* Disable and stop the quadrature operation */
void PDEC_QDECStop( void )
{
    PDEC_REGS->PDEC_CTRLBSET = PDEC_CTRLBSET_CMD_STOP;
    PDEC_REGS->PDEC_CTRLA &= ~PDEC_CTRLA_ENABLE_Msk;
    while((PDEC_REGS->PDEC_SYNCBUSY))
    {
        /* Wait for Write Synchronization */
    }
}

/* Read the position */
int16_t PDEC_QDECPositionGet( void )
{
    PDEC_REGS->PDEC_CTRLBSET = PDEC_CTRLBSET_CMD_READSYNC;
    while(PDEC_REGS->PDEC_SYNCBUSY)
    {
        /* Wait for read Synchronization */
    }
    return (int16_t)PDEC_REGS->PDEC_COUNT;
}

PDEC_QDEC_STATUS PDEC_QDECStatusGet( void )
{
    PDEC_QDEC_STATUS status;
    status = PDEC_REGS->PDEC_INTFLAG;
    /* Clear interrupt flags */
    PDEC_REGS->PDEC_INTFLAG = PDEC_QDEC_STATUS_MSK;
    return status;
}



