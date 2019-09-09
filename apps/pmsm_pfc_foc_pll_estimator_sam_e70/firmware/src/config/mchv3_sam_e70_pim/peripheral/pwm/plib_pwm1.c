/*******************************************************************************
  PWM Peripheral Library Interface Source File

  Company
    Microchip Technology Inc.

  File Name
    plib_PWM1.c

  Summary
    PWM1 peripheral library source file.

  Description
    This file implements the interface to the PWM peripheral library.  This
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
#include "plib_pwm1.h"



/* Initialize enabled PWM channels */
void PWM1_Initialize (void)
{


    /************** Channel 0 *************************/
    /* PWM channel mode configurations */
    PWM1_REGS->PWM_CH_NUM[0].PWM_CMR = PWM_CMR_CPRE_MCK | PWM_CMR_CALG_CENTER_ALIGNED
                    | PWM_CMR_CPOL_LOW_POLARITY | PWM_CMR_UPDS_UPDATE_AT_PERIOD \
                    | PWM_CMR_CES_SINGLE_EVENT ;

    /* PWM period */
    PWM1_REGS->PWM_CH_NUM[0].PWM_CPRD = 1875U;

    /* PWM duty cycle */
    PWM1_REGS->PWM_CH_NUM[0].PWM_CDTY = 0U;
 
     
 
 
 


    /************* Compare Unit 0 **************************/
    /* Compare unit configurations */
    PWM1_REGS->PWM_CMP[0].PWM_CMPM = PWM_CMPM_CEN_Msk | PWM_CMPM_CTR(0U) | PWM_CMPM_CPR(0U)
                    | PWM_CMPM_CUPR(0U);
    PWM1_REGS->PWM_CMP[0].PWM_CMPV = PWM_CMPV_CV(10U) | PWM_CMPV_CVM_COMPARE_AT_INCREMENT;

    PWM1_REGS->PWM_ELMR[1] = PWM_ELMR_CSEL0_Msk;
}

/* Start the PWM generation */
void PWM1_ChannelsStart (PWM_CHANNEL_MASK channelMask)
{
    PWM1_REGS->PWM_ENA = channelMask;
}

/* Stop the PWM generation */
void PWM1_ChannelsStop (PWM_CHANNEL_MASK channelMask)
{
    PWM1_REGS->PWM_DIS = channelMask;
}

/* configure PWM period */
void PWM1_ChannelPeriodSet (PWM_CHANNEL_NUM channel, uint16_t period)
{
    PWM1_REGS->PWM_CH_NUM[channel].PWM_CPRDUPD = period;
}

/* Read PWM period */
uint16_t PWM1_ChannelPeriodGet (PWM_CHANNEL_NUM channel)
{
    return (uint16_t)PWM1_REGS->PWM_CH_NUM[channel].PWM_CPRD;
}

/* Configure dead time */
void PWM1_ChannelDeadTimeSet (PWM_CHANNEL_NUM channel, uint16_t deadtime_high, uint16_t deadtime_low)
{
    PWM1_REGS->PWM_CH_NUM[channel].PWM_DTUPD = ((deadtime_low << PWM_DT_DTL_Pos) | deadtime_high);
}

/* Configure compare unit value */
void PWM1_CompareValueSet (PWM_COMPARE cmp_unit, uint16_t cmp_value)
{
    PWM1_REGS->PWM_CMP[cmp_unit].PWM_CMPVUPD = cmp_value;
}

/* Enable counter event */
void PWM1_ChannelCounterEventEnable (PWM_CHANNEL_MASK channelMask)
{
    PWM1_REGS->PWM_IER1 = channelMask;
}

/* Disable counter event */
void PWM1_ChannelCounterEventDisable (PWM_CHANNEL_MASK channelMask)
{
    PWM1_REGS->PWM_IDR1 = channelMask;
}


/* Enable synchronous update */
void PWM1_SyncUpdateEnable (void)
{
    PWM1_REGS->PWM_SCUC = PWM_SCUC_UPDULOCK_Msk;
}

/* Clear the fault status */
void PWM1_FaultStatusClear(PWM_FAULT_ID fault_id)
{
    PWM1_REGS->PWM_FCR = 0x1U << fault_id;
}


/* Check the status of counter event */
bool PWM1_ChannelCounterEventStatusGet (PWM_CHANNEL_NUM channel)
{
    bool status;
    status = (PWM1_REGS->PWM_ISR1 >> channel) & 0x1U;
    return status;
}

/**
 End of File
*/
