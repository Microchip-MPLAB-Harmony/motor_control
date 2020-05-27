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

#include "plib_adc0.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data
// *****************************************************************************
// *****************************************************************************
ADC_CALLBACK_OBJ ADC0_CallbackObject;

#define ADC0_BIASCOMP_POS  (2)
#define ADC0_BIASCOMP_Msk   (0x7 << ADC0_BIASCOMP_POS)

#define ADC0_BIASREFBUF_POS  (5)
#define ADC0_BIASREFBUF_Msk   (0x7 << ADC0_BIASREFBUF_POS)

#define ADC0_BIASR2R_POS  (8)
#define ADC0_BIASR2R_Msk   (0x7 << ADC0_BIASR2R_POS)


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

    /* Writing calibration values in BIASREFBUF, BIASCOMP and BIASR2R */
    ADC0_REGS->ADC_CALIB =(uint32_t)(ADC_CALIB_BIASCOMP((((*(uint64_t*)SW0_ADDR) & ADC0_BIASCOMP_Msk) >> ADC0_BIASCOMP_POS))) \
            | ADC_CALIB_BIASR2R((((*(uint64_t*)SW0_ADDR) & ADC0_BIASR2R_Msk) >> ADC0_BIASR2R_POS))
            | ADC_CALIB_BIASREFBUF(((*(uint64_t*)SW0_ADDR) & ADC0_BIASREFBUF_Msk)>> ADC0_BIASREFBUF_POS );

    /* prescaler */
    ADC0_REGS->ADC_CTRLA = ADC_CTRLA_PRESCALER_DIV4;

    /* Sampling length */
    ADC0_REGS->ADC_SAMPCTRL = ADC_SAMPCTRL_SAMPLEN(3U);

    /* reference */
    ADC0_REGS->ADC_REFCTRL = ADC_REFCTRL_REFSEL_INTVCC1;


    /* positive and negative input pins */
    ADC0_REGS->ADC_INPUTCTRL = (uint16_t) ADC_POSINPUT_AIN0 | (uint16_t) ADC_NEGINPUT_GND ;

    /* Resolution & Operation Mode */
    ADC0_REGS->ADC_CTRLB = ADC_CTRLB_RESSEL_12BIT | ADC_CTRLB_WINMODE(0) ;


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
    /* Configure positive and negative input pins */
    uint32_t channel;
    channel = ADC0_REGS->ADC_INPUTCTRL;
    channel &= ~(ADC_INPUTCTRL_MUXPOS_Msk | ADC_INPUTCTRL_MUXNEG_Msk);
    channel |= (uint16_t) positiveInput | (uint16_t) negativeInput;
    ADC0_REGS->ADC_INPUTCTRL = channel;

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

/* Configure window comparison threshold values */
void ADC0_ComparisonWindowSet(uint16_t low_threshold, uint16_t high_threshold)
{
    ADC0_REGS->ADC_WINLT = low_threshold;
    ADC0_REGS->ADC_WINUT = high_threshold;
    while((ADC0_REGS->ADC_SYNCBUSY))
    {
        /* Wait for Synchronization */
    }
}

void ADC0_WindowModeSet(ADC_WINMODE mode)
{
    ADC0_REGS->ADC_CTRLB &= ~ADC_CTRLB_WINMODE_Msk;
    ADC0_REGS->ADC_CTRLB |= mode << ADC_CTRLB_WINMODE_Pos;
    while((ADC0_REGS->ADC_SYNCBUSY))
    {
        /* Wait for Synchronization */
    }
}

/* Read the conversion result */
uint16_t ADC0_ConversionResultGet( void )
{
    return (uint16_t)ADC0_REGS->ADC_RESULT;
}

/* Read the last conversion result */
uint16_t ADC0_LastConversionResultGet( void )
{
    return (uint16_t)ADC0_REGS->ADC_RESS;
}

void ADC0_InterruptsClear(ADC_STATUS interruptMask)
{
    ADC0_REGS->ADC_INTFLAG = interruptMask;
}

void ADC0_InterruptsEnable(ADC_STATUS interruptMask)
{
    ADC0_REGS->ADC_INTENSET = interruptMask;
}

void ADC0_InterruptsDisable(ADC_STATUS interruptMask)
{
    ADC0_REGS->ADC_INTENCLR = interruptMask;
}

/* Register callback function */
void ADC0_CallbackRegister( ADC_CALLBACK callback, uintptr_t context )
{
    ADC0_CallbackObject.callback = callback;

    ADC0_CallbackObject.context = context;
}

void ADC0_RESRDY_InterruptHandler( void )
{
    ADC_STATUS status;
    status = (ADC_STATUS) (ADC0_REGS->ADC_INTFLAG & ADC_INTFLAG_RESRDY_Msk);
    /* Clear interrupt flag */
    ADC0_REGS->ADC_INTFLAG = ADC_INTFLAG_RESRDY_Msk;
    if (ADC0_CallbackObject.callback != NULL)
    {
        ADC0_CallbackObject.callback(status, ADC0_CallbackObject.context);
    }
}
