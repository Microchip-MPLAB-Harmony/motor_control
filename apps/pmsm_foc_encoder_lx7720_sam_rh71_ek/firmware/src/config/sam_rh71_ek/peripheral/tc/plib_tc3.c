/*******************************************************************************
  TC Peripheral Library Interface Source File

  Company
    Microchip Technology Inc.

  File Name
    plib_tc3.c

  Summary
    TC peripheral library source file.

  Description
    This file implements the interface to the TC peripheral library.  This
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
#include "device.h"
#include "plib_tc3.h"

 
 

 

 


/* Initialize channel in capture mode */
void TC3_CH0_CaptureInitialize (void)
{
    /* Use peripheral clock */
    TC3_REGS->TC_CHANNEL[0].TC_EMR = TC_EMR_NODIVCLK_Msk;
        /* clock selection and capture configurations */
    TC3_REGS->TC_CHANNEL[0].TC_CMR = TC_CMR_CAPTURE_LDRA_NONE | TC_CMR_CAPTURE_LDRB_NONE;



}

/* Start the capture mode */
void TC3_CH0_CaptureStart (void)
{
    TC3_REGS->TC_CHANNEL[0].TC_CCR = (TC_CCR_CLKEN_Msk | TC_CCR_SWTRG_Msk);
}

/* Stop the capture mode */
void TC3_CH0_CaptureStop (void)
{
    TC3_REGS->TC_CHANNEL[0].TC_CCR = (TC_CCR_CLKDIS_Msk);
}

uint32_t TC3_CH0_CaptureFrequencyGet( void )
{
    return (uint32_t)(50000000UL);
}

/* Read last captured value of Capture A */
uint32_t TC3_CH0_CaptureAGet (void)
{
    return TC3_REGS->TC_CHANNEL[0].TC_RA;
}

/* Read last captured value of Capture B */
uint32_t TC3_CH0_CaptureBGet (void)
{
    return TC3_REGS->TC_CHANNEL[0].TC_RB;
}

TC_CAPTURE_STATUS TC3_CH0_CaptureStatusGet(void)
{
    return (TC_CAPTURE_STATUS)(TC3_REGS->TC_CHANNEL[0].TC_SR & TC_CAPTURE_STATUS_MSK);
}
 

 

 
 

 


/* Initialize channel in capture mode */
void TC3_CH1_CaptureInitialize (void)
{
    /* Use peripheral clock */
    TC3_REGS->TC_CHANNEL[1].TC_EMR = TC_EMR_NODIVCLK_Msk;
        /* clock selection and capture configurations */
    TC3_REGS->TC_CHANNEL[1].TC_CMR = TC_CMR_CAPTURE_LDRA_NONE | TC_CMR_CAPTURE_LDRB_NONE;



}

/* Start the capture mode */
void TC3_CH1_CaptureStart (void)
{
    TC3_REGS->TC_CHANNEL[1].TC_CCR = (TC_CCR_CLKEN_Msk | TC_CCR_SWTRG_Msk);
}

/* Stop the capture mode */
void TC3_CH1_CaptureStop (void)
{
    TC3_REGS->TC_CHANNEL[1].TC_CCR = (TC_CCR_CLKDIS_Msk);
}

uint32_t TC3_CH1_CaptureFrequencyGet( void )
{
    return (uint32_t)(50000000UL);
}

/* Read last captured value of Capture A */
uint32_t TC3_CH1_CaptureAGet (void)
{
    return TC3_REGS->TC_CHANNEL[1].TC_RA;
}

/* Read last captured value of Capture B */
uint32_t TC3_CH1_CaptureBGet (void)
{
    return TC3_REGS->TC_CHANNEL[1].TC_RB;
}

TC_CAPTURE_STATUS TC3_CH1_CaptureStatusGet(void)
{
    return (TC_CAPTURE_STATUS)(TC3_REGS->TC_CHANNEL[1].TC_SR & TC_CAPTURE_STATUS_MSK);
}
 

 

 
 

 


/* Initialize channel in capture mode */
void TC3_CH2_CaptureInitialize (void)
{
    /* Use peripheral clock */
    TC3_REGS->TC_CHANNEL[2].TC_EMR = TC_EMR_NODIVCLK_Msk;
        /* clock selection and capture configurations */
    TC3_REGS->TC_CHANNEL[2].TC_CMR = TC_CMR_CAPTURE_LDRA_NONE | TC_CMR_CAPTURE_LDRB_NONE;



}

/* Start the capture mode */
void TC3_CH2_CaptureStart (void)
{
    TC3_REGS->TC_CHANNEL[2].TC_CCR = (TC_CCR_CLKEN_Msk | TC_CCR_SWTRG_Msk);
}

/* Stop the capture mode */
void TC3_CH2_CaptureStop (void)
{
    TC3_REGS->TC_CHANNEL[2].TC_CCR = (TC_CCR_CLKDIS_Msk);
}

uint32_t TC3_CH2_CaptureFrequencyGet( void )
{
    return (uint32_t)(50000000UL);
}

/* Read last captured value of Capture A */
uint32_t TC3_CH2_CaptureAGet (void)
{
    return TC3_REGS->TC_CHANNEL[2].TC_RA;
}

/* Read last captured value of Capture B */
uint32_t TC3_CH2_CaptureBGet (void)
{
    return TC3_REGS->TC_CHANNEL[2].TC_RB;
}

TC_CAPTURE_STATUS TC3_CH2_CaptureStatusGet(void)
{
    return (TC_CAPTURE_STATUS)(TC3_REGS->TC_CHANNEL[2].TC_SR & TC_CAPTURE_STATUS_MSK);
}
 

 

 

 
/**
 End of File
*/
