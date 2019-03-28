/*******************************************************************************
  Analog-to-Digital Converter(ADC0) PLIB

  Company
    Microchip Technology Inc.

  File Name
    plib_adc0.c

  Summary
    ADC0 PLIB Implementation File.

  Description
    This file defines the interface to the ADC peripheral library. This
    library provides access to and control of the associated peripheral
    instance.

  Remarks:
    None.

*******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2019 Microchip Technology Inc. and its subsidiaries.
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

#include "plib_adc0.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data
// *****************************************************************************
// *****************************************************************************
ADC_CALLBACK_OBJ ADC0_CallbackObject;

#define ADC0_LINEARITY_POS  (0)
#define ADC0_LINEARITY_Msk   (0x7 << ADC0_LINEARITY_POS)

#define ADC0_BIASCAL_POS  (3)
#define ADC0_BIASCAL_Msk   (0x7 << ADC0_BIASCAL_POS)


// *****************************************************************************
// *****************************************************************************
// Section: ADC0 Implementation
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Initialize ADC module */
void ADC0_Initialize( void )
{
    /* Reset ADC */
    ADC0_REGS->ADC_CTRLA = ADC_CTRLA_SWRST_Msk;

    while((ADC0_REGS->ADC_SYNCBUSY & ADC_SYNCBUSY_SWRST_Msk) == ADC_SYNCBUSY_SWRST_Msk)
    {
        /* Wait for Synchronization */
    }

    /* Write linearity calibration in BIASREFBUF and bias calibration in BIASCOMP */
    ADC0_REGS->ADC_CALIB = (uint32_t)(ADC_CALIB_BIASREFBUF(((*(uint64_t*)OTP5_ADDR) & ADC0_LINEARITY_Msk))) \
        | ADC_CALIB_BIASCOMP((((*(uint64_t*)OTP5_ADDR) & ADC0_BIASCAL_Msk) >> ADC0_BIASCAL_POS));

    /* prescaler */
    ADC0_REGS->ADC_CTRLB = ADC_CTRLB_PRESCALER_DIV4;
    /* Sampling length */
    ADC0_REGS->ADC_SAMPCTRL = ADC_SAMPCTRL_SAMPLEN(3U);

    /* reference */
    ADC0_REGS->ADC_REFCTRL = ADC_REFCTRL_REFSEL_INTVCC2;

    /* positive and negative input pins */
    ADC0_REGS->ADC_INPUTCTRL = ADC_POSINPUT_AIN2 | ADC_NEGINPUT_GND;

    /* Resolution & Operation Mode */
    ADC0_REGS->ADC_CTRLC = ADC_CTRLC_RESSEL_12BIT | ADC_CTRLC_WINMODE(0) ;


    /* Clear all interrupt flags */
    ADC0_REGS->ADC_INTFLAG = ADC_INTFLAG_Msk;
    /* Enable interrupts */
    ADC0_REGS->ADC_INTENSET = ADC_INTENSET_RESRDY_Msk;
    /* Events configuration  */
    ADC0_REGS->ADC_EVCTRL = ADC_EVCTRL_STARTEI_Msk;

    while(ADC0_REGS->ADC_SYNCBUSY)
    {
        /* Wait for Synchronization */
    }
}

/* Enable ADC module */
void ADC0_Enable( void )
{
    ADC0_REGS->ADC_CTRLA |= ADC_CTRLA_ENABLE_Msk;
    while(ADC0_REGS->ADC_SYNCBUSY)
    {
        /* Wait for Synchronization */
    }
}

/* Disable ADC module */
void ADC0_Disable( void )
{
    ADC0_REGS->ADC_CTRLA &= ~ADC_CTRLA_ENABLE_Msk;
    while(ADC0_REGS->ADC_SYNCBUSY)
    {
        /* Wait for Synchronization */
    }
}

/* Configure channel input */
void ADC0_ChannelSelect( ADC_POSINPUT positiveInput, ADC_NEGINPUT negativeInput )
{
    /* Configure pin scan mode and positive and negative input pins */
    ADC0_REGS->ADC_INPUTCTRL = positiveInput | negativeInput;

    while((ADC0_REGS->ADC_SYNCBUSY & ADC_SYNCBUSY_INPUTCTRL_Msk) == ADC_SYNCBUSY_INPUTCTRL_Msk)
    {
        /* Wait for Synchronization */
    }
}

/* Start the ADC conversion by SW */
void ADC0_ConversionStart( void )
{
    /* Start conversion */
    ADC0_REGS->ADC_SWTRIG |= ADC_SWTRIG_START_Msk;

    while((ADC0_REGS->ADC_SYNCBUSY & ADC_SYNCBUSY_SWTRIG_Msk) == ADC_SYNCBUSY_SWTRIG_Msk)
    {
        /* Wait for Synchronization */
    }
}

/* Check whether auto sequence conversion is done */
bool ADC0_ConversionSequenceIsFinished(void)
{
    bool seq_status = false;
    if ((ADC0_REGS->ADC_SEQSTATUS & ADC_SEQSTATUS_SEQBUSY_Msk) != ADC_SEQSTATUS_SEQBUSY_Msk)
    {
        seq_status = true;
    }
    return seq_status;
}


/* Read the conversion result */
uint16_t ADC0_ConversionResultGet( void )
{
    return (uint16_t)ADC0_REGS->ADC_RESULT;
}

/* Register callback function */
void ADC0_CallbackRegister( ADC_CALLBACK callback, uintptr_t context )
{
    ADC0_CallbackObject.callback = callback;

    ADC0_CallbackObject.context = context;
}


void ADC0_InterruptHandler( void )
{
    volatile ADC_STATUS status;
    status = ADC0_REGS->ADC_INTFLAG;
    /* Clear interrupt flag */
    ADC0_REGS->ADC_INTFLAG = ADC_INTENSET_RESRDY_Msk;
    if (ADC0_CallbackObject.callback != NULL)
    {
        ADC0_CallbackObject.callback(status, ADC0_CallbackObject.context);
    }
}
