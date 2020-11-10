/*******************************************************************************
 Motor Control Hardware Abstraction interface file

  Company:
    Microchip Technology Inc.

  File Name:
    mc_hal.h

  Summary:
    Header file for hardware abstraction

  Description:
    This file contains the function mapping and channel mapping to provide
    hardware abstraction layer for motor control algorithm
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2020 Microchip Technology Inc. and its subsidiaries.
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

#ifndef MCHAL_H    // Guards against multiple inclusion
#define MCHAL_H


// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

/*  This section lists the other files that are included in this file.
*/

#include <stddef.h>
#include "definitions.h"


// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif

// DOM-IGNORE-END


// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************


// *****************************************************************************
// *****************************************************************************
// Section: Interface Routines
// *****************************************************************************
// *****************************************************************************

/****************************** PWM ***********************************************************/
#define MCHAL_PWM_PH_U                  TCC0_CHANNEL0
#define MCHAL_PWM_PH_V                  TCC0_CHANNEL1
#define MCHAL_PWM_PH_W                  TCC0_CHANNEL2
#define MCHAL_PWM_PH_MASK               0x7
#define MCHAL_PWMStop(mask)                 TCC0_PWMStop()
#define MCHAL_PWMStart(mask)                TCC0_PWMStart()
#define MCHAL_PWMPrimaryPeriodGet(ch)       TCC0_PWM24bitPeriodGet()
#define MCHAL_PWMDutySet(ch, duty)          TCC0_PWM24bitDutySet(ch, duty)

__STATIC_INLINE void MCHAL_DisableInverterPwm( void )
{

    /*Override all PWM outputs to low*/
    TCC0_PWMPatternSet(
            (TCC_PATT_PGE0_Msk|TCC_PATT_PGE1_Msk|TCC_PATT_PGE2_Msk
            |TCC_PATT_PGE4_Msk|TCC_PATT_PGE5_Msk|TCC_PATT_PGE6_Msk),
            (TCC_PATT_PGE0(0)|TCC_PATT_PGE1(0)|TCC_PATT_PGE2(0)|TCC_PATT_PGE4(0)
            |TCC_PATT_PGE5(0)|TCC_PATT_PGE6(0)));
}

__STATIC_INLINE void MCHAL_EnableInverterPwm( void )
{
    /*Disable PWM override*/
    TCC0_PWMPatternSet(0x00,0x00);
}

#define MCHAL_PWMOutputDisable(ch)          MCHAL_DisableInverterPwm()
#define MCHAL_PWMOutputEnable(ch)           MCHAL_EnableInverterPwm()
#define MCHAL_PWMCallbackRegister(ch, fn, context)  TCC0_PWMCallbackRegister((TCC_CALLBACK)fn, (uintptr_t)context)

/**************************************** ADC ***************************************************/
  
#define MCHAL_ADC_PH_U                                   ADC_POSINPUT_AIN0
#define MCHAL_ADC_PH_V                                   ADC_POSINPUT_AIN0
#define MCHAL_ADC_VDC                                    ADC_POSINPUT_AIN14
#define MCHAL_ADC_POT                                    ADC_POSINPUT_AIN6


#define MCHAL_ADC_RESULT_SHIFT                           (0U)
#define MCHAL_ADCCallbackRegister(ch, fn, context)       ADC0_CallbackRegister((ADC_CALLBACK)fn, (uintptr_t)context)
#define MCHAL_ADCChannelConversionStart(ch)              ADC0_ConversionStart()
#define MCHAL_ADCEnable( )                               ADC0_Enable()                      
#define MCHAL_ADCDisable( )                              ADC0_Disable()
#define MCHAL_ADCInterruptsClear(mask)                   ADC0_InterruptsClear(mask)
#define MCHAL_ADCInterruptsEnable(mask)                  ADC0_InterruptsEnable(mask)
#define MCHAL_ADCInterruptsDisable(mask)                  ADC0_InterruptsDisable(mask)

#define MCHAL_ADCPhaseUResultGet(ch)                    ADC0_ConversionResultGet()
#define MCHAL_ADCPhaseUChannelSelect(pos, neg)          ADC0_ChannelSelect( pos, neg)
#define MCHAL_ADCPhaseVResultGet(ch)                    ADC1_ConversionResultGet()
#define MCHAL_ADCPhaseVChannelSelect(pos, neg)          ADC1_ChannelSelect( pos, neg)
#define MCHAL_ADCPotResultGet(ch)                       ADC0_ConversionResultGet()
#define MCHAL_ADCPotChannelSelect(pos, neg)             ADC0_ChannelSelect( pos, neg)
#define MCHAL_ADCVdcResultGet(ch)                       ADC1_ConversionResultGet()
#define MCHAL_ADCVdcChannelSelect(pos, neg)             ADC1_ChannelSelect( pos, neg)

#define MCHAL_ADC0ChannelResultIsReady(ch)                ADC0_ConversionStatusGet()
#define MCHAL_ADC1ChannelResultIsReady(ch)                ADC1_ConversionStatusGet()


/***************************** Encoder *******************************************************/
#define MCHAL_EncoderStart()                 PDEC_QDECStart()
#define MCHAL_EncoderStop()                  PDEC_QDECStop()
#define MCHAL_EncoderPositionGet()           PDEC_QDECPositionGet()
#define MCHAL_EncoderSpeedGet()
#define MCHAL_EncoderPositionSet(count)
#define MCHAL_EncoderSpeedSet(count)

/************************************ Interrupt *********************************************/
#define MCHAL_CTRL_IRQ              (ADC0_RESRDY_IRQn)
#define MCHAL_FAULT_IRQ             (TCC0_OTHER_IRQn)

#define MCHAL_IntDisable(irq)       NVIC_DisableIRQ(irq)
#define MCHAL_IntEnable(irq)        NVIC_EnableIRQ(irq)
#define MCHAL_IntClear(irq)         NVIC_ClearPendingIRQ(irq)


/******************************* LED and Switches *******************************************/

#define MCHAL_FAULT_LED_SET()       GPIO_PB27_Set()
#define MCHAL_FAULT_LED_CLEAR()     GPIO_PB27_Clear()
#define MCHAL_FAULT_LED_TOGGLE()    GPIO_PB27_Toggle()

#define MCHAL_DIR_LED_SET()         GPIO_PB26_Set()
#define MCHAL_DIR_LED_CLEAR()       GPIO_PB26_Clear()
#define MCHAL_DIR_LED_TOGGLE()      GPIO_PB26_Toggle()

#define MCHAL_DIR_SWITCH_GET()         GPIO_PD10_Get()

#define MCHAL_START_STOP_SWITCH_GET()  GPIO_PD09_Get()

/***************************** X2CScope **************************************************/
#define MCHAL_X2C_Update()          X2CScope_Update()

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

}

#endif
// DOM-IGNORE-END

#endif //MCINF_H

/**
 End of File
*/
