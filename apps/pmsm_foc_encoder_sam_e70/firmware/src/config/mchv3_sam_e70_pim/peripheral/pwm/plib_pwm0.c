/*******************************************************************************
  PWM Peripheral Library Interface Source File

  Company
    Microchip Technology Inc.

  File Name
    plib_PWM0.c

  Summary
    PWM0 peripheral library source file.

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
#include "plib_pwm0.h"


/* Object to hold callback function and context */
PWM_CALLBACK_OBJECT PWM0_CallbackObj;

/* Initialize enabled PWM channels */
void PWM0_Initialize (void)
{

    /* Synchronous channels configuration */
    PWM0_REGS->PWM_SCM = PWM_SCM_SYNC0_Msk | PWM_SCM_SYNC1_Msk| PWM_SCM_SYNC2_Msk | PWM_SCM_UPDM_MODE1;
    PWM0_REGS->PWM_SCUP = PWM_SCUP_UPR(0U);

    /************** Channel 0 *************************/
    /* PWM channel mode configurations */
    PWM0_REGS->PWM_CH_NUM[0].PWM_CMR = PWM_CMR_CPRE_MCK | PWM_CMR_CALG_CENTER_ALIGNED
                    | PWM_CMR_CPOL_LOW_POLARITY | PWM_CMR_UPDS_UPDATE_AT_PERIOD \
                    | PWM_CMR_CES_SINGLE_EVENT | (PWM_CMR_DTE_Msk);

    /* PWM period */
    PWM0_REGS->PWM_CH_NUM[0].PWM_CPRD = 3750U;

    /* PWM duty cycle */
    PWM0_REGS->PWM_CH_NUM[0].PWM_CDTY = 0U;
    /* Dead time */
    PWM0_REGS->PWM_CH_NUM[0].PWM_DT = (150U << PWM_DT_DTL_Pos) | (150U);
         
    /* Enable counter event */
    PWM0_REGS->PWM_IER1 = 0x10000;
    PWM0_CallbackObj.callback_fn = NULL;
     

    /************** Channel 1 *************************/

    /* PWM duty cycle */
    PWM0_REGS->PWM_CH_NUM[1].PWM_CDTY = 0U;
    PWM0_REGS->PWM_CH_NUM[1].PWM_CMR = PWM_CMR_DTE_Msk;
    /* Dead time */
    PWM0_REGS->PWM_CH_NUM[1].PWM_DT = (150U << PWM_DT_DTL_Pos) | (150U);
         
    /* Enable counter event */
    PWM0_REGS->PWM_IER1 = 0x10000;
    PWM0_CallbackObj.callback_fn = NULL;
     

    /************** Channel 2 *************************/

    /* PWM duty cycle */
    PWM0_REGS->PWM_CH_NUM[2].PWM_CDTY = 0U;
    PWM0_REGS->PWM_CH_NUM[2].PWM_CMR = PWM_CMR_DTE_Msk;
    /* Dead time */
    PWM0_REGS->PWM_CH_NUM[2].PWM_DT = (150U << PWM_DT_DTL_Pos) | (150U);
         
    /* Enable counter event */
    PWM0_REGS->PWM_IER1 = 0x10000;
    PWM0_CallbackObj.callback_fn = NULL;
     
 

    /*************************** Fault ************************/
    /* Enable fault input */
    PWM0_REGS->PWM_FPE = (0x1U << (0x2U + (PWM_FPE_FPE0_Pos))) | 
		 (0x1U << (0x2U + (PWM_FPE_FPE1_Pos))) | 
		 (0x1U << (0x2U + (PWM_FPE_FPE2_Pos)));
    PWM0_REGS->PWM_FPV1 = (0 << PWM_FPV1_FPVH0_Pos) | (1 << PWM_FPV1_FPVL0_Pos)
		 | (0 << PWM_FPV1_FPVH1_Pos) | (1 << PWM_FPV1_FPVL1_Pos)
		 | (0 << PWM_FPV1_FPVH2_Pos) | (1 << PWM_FPV1_FPVL2_Pos);
    PWM0_REGS->PWM_FPV2 = 0x0;
    /* Fault mode configuration */
    PWM0_REGS->PWM_FMR = PWM_FMR_FFIL(0x0) | PWM_FMR_FPOL(0xF8) | PWM_FMR_FMOD(0xFB);

    /************* Compare Unit 0 **************************/
    /* Compare unit configurations */
    PWM0_REGS->PWM_CMP[0].PWM_CMPM = PWM_CMPM_CEN_Msk | PWM_CMPM_CTR(0U) | PWM_CMPM_CPR(0U)
                    | PWM_CMPM_CUPR(0U);
    PWM0_REGS->PWM_CMP[0].PWM_CMPV = PWM_CMPV_CV(10U) | PWM_CMPV_CVM_COMPARE_AT_INCREMENT;

    PWM0_REGS->PWM_ELMR[0] = PWM_ELMR_CSEL0_Msk;
}

/* Start the PWM generation */
void PWM0_ChannelsStart (PWM_CHANNEL_MASK channelMask)
{
    PWM0_REGS->PWM_ENA = channelMask;
}

/* Stop the PWM generation */
void PWM0_ChannelsStop (PWM_CHANNEL_MASK channelMask)
{
    PWM0_REGS->PWM_DIS = channelMask;
}

/* configure PWM period */
void PWM0_ChannelPeriodSet (PWM_CHANNEL_NUM channel, uint16_t period)
{
    PWM0_REGS->PWM_CH_NUM[channel].PWM_CPRDUPD = period;
}

/* Read PWM period */
uint16_t PWM0_ChannelPeriodGet (PWM_CHANNEL_NUM channel)
{
    return (uint16_t)PWM0_REGS->PWM_CH_NUM[channel].PWM_CPRD;
}

/* Configure dead time */
void PWM0_ChannelDeadTimeSet (PWM_CHANNEL_NUM channel, uint16_t deadtime_high, uint16_t deadtime_low)
{
    PWM0_REGS->PWM_CH_NUM[channel].PWM_DTUPD = ((deadtime_low << PWM_DT_DTL_Pos) | deadtime_high);
}

/* Configure compare unit value */
void PWM0_CompareValueSet (PWM_COMPARE cmp_unit, uint16_t cmp_value)
{
    PWM0_REGS->PWM_CMP[cmp_unit].PWM_CMPVUPD = cmp_value;
}

/* Enable counter event */
void PWM0_ChannelCounterEventEnable (PWM_CHANNEL_MASK channelMask)
{
    PWM0_REGS->PWM_IER1 = channelMask;
}

/* Disable counter event */
void PWM0_ChannelCounterEventDisable (PWM_CHANNEL_MASK channelMask)
{
    PWM0_REGS->PWM_IDR1 = channelMask;
}


/* Enable synchronous update */
void PWM0_SyncUpdateEnable (void)
{
    PWM0_REGS->PWM_SCUC = PWM_SCUC_UPDULOCK_Msk;
}

/* Clear the fault status */
void PWM0_FaultStatusClear(PWM_FAULT_ID fault_id)
{
    PWM0_REGS->PWM_FCR = 0x1U << fault_id;
}

/* Override PWM outputs */
void PWM0_ChannelOverrideEnable(PWM_CHANNEL_NUM channel)
{
    PWM0_REGS->PWM_OS &= ~((1 << channel) | (1 << (channel + 16)));
    PWM0_REGS->PWM_OS |= ((0 << channel) | (0 << (channel + 16)));
}

/* Disable override of PWM outputs */
void PWM0_ChannelOverrideDisable(PWM_CHANNEL_NUM channel)
{
    PWM0_REGS->PWM_OS |= ((1 << channel) | (1 << (channel + 16)));
}

 /* Register callback function */
void PWM0_CallbackRegister(PWM_CALLBACK callback, uintptr_t context)
{
    PWM0_CallbackObj.callback_fn = callback;
    PWM0_CallbackObj.context = context;
}

/* Interrupt Handler */
void PWM0_InterruptHandler(void)
{
    uint32_t status;
    status = PWM0_REGS->PWM_ISR1;
    if (PWM0_CallbackObj.callback_fn != NULL)
    {
        PWM0_CallbackObj.callback_fn(status, PWM0_CallbackObj.context);
    }
}


/**
 End of File
*/
