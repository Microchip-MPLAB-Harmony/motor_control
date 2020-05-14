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

/* PWM */
#define MCHAL_PWM_PH_U                  ${.vars["${MCPMSMFOC_PWMPLIB?lower_case}"].PWM_PH_U}
#define MCHAL_PWM_PH_V                  ${.vars["${MCPMSMFOC_PWMPLIB?lower_case}"].PWM_PH_V}
#define MCHAL_PWM_PH_W                  ${.vars["${MCPMSMFOC_PWMPLIB?lower_case}"].PWM_PH_W}
#define MCHAL_PWM_PH_MASK               0x${.vars["${MCPMSMFOC_PWMPLIB?lower_case}"].PWM_PH_MASK}
<#if __PROCESSOR?matches("PIC32M.*") == true>
#define MCHAL_PWMStop(mask)                 ${.vars["${MCPMSMFOC_PWMPLIB?lower_case}"].PWM_STOP_API}()
#define MCHAL_PWMStart(mask)                ${.vars["${MCPMSMFOC_PWMPLIB?lower_case}"].PWM_START_API}()
#define MCHAL_PWMPrimaryPeriodGet(ch)       ${.vars["${MCPMSMFOC_PWMPLIB?lower_case}"].PWM_GET_PERIOD_API}()
#define MCHAL_PWMDutySet(ch, duty)          ${.vars["${MCPMSMFOC_PWMPLIB?lower_case}"].PWM_SET_DUTY_API}(ch, duty)
#define MCHAL_PWMOutputDisable(ch)          ${.vars["${MCPMSMFOC_PWMPLIB?lower_case}"].PWM_OUTPUT_DISABLE_API}(ch)
#define MCHAL_PWMOutputEnable(ch)           ${.vars["${MCPMSMFOC_PWMPLIB?lower_case}"].PWM_OUTPUT_ENABLE_API}(ch)
#define MCHAL_PWMCallbackRegister(ch, fn, context)  ${.vars["${MCPMSMFOC_PWMPLIB?lower_case}"].PWM_CALLBACK_API}(ch, fn, context)

<#elseif __PROCESSOR?matches(".*SAME70.*") == true>
#define MCHAL_PWMStop(mask)                 ${.vars["${MCPMSMFOC_PWMPLIB?lower_case}"].PWM_STOP_API}(mask)
#define MCHAL_PWMStart(mask)                ${.vars["${MCPMSMFOC_PWMPLIB?lower_case}"].PWM_START_API}(mask)
#define MCHAL_PWMPrimaryPeriodGet(ch)       ${.vars["${MCPMSMFOC_PWMPLIB?lower_case}"].PWM_GET_PERIOD_API}(ch)
#define MCHAL_PWMDutySet(ch, duty)          ${.vars["${MCPMSMFOC_PWMPLIB?lower_case}"].PWM_SET_DUTY_API}(ch, duty)
#define MCHAL_PWMOutputDisable(ch)          ${.vars["${MCPMSMFOC_PWMPLIB?lower_case}"].PWM_OUTPUT_DISABLE_API}(ch)
#define MCHAL_PWMOutputEnable(ch)           ${.vars["${MCPMSMFOC_PWMPLIB?lower_case}"].PWM_OUTPUT_ENABLE_API}(ch)
#define MCHAL_PWMCallbackRegister(ch, fn, context)  ${.vars["${MCPMSMFOC_PWMPLIB?lower_case}"].PWM_CALLBACK_API}(fn, context)
</#if>

/* ADC */
#define MCHAL_ADC_PH_U                                   ${.vars["${MCPMSMFOC_ADCPLIB?lower_case}"].ADC_CH_PHASE_U}
#define MCHAL_ADC_PH_V                                   ${.vars["${MCPMSMFOC_ADCPLIB?lower_case}"].ADC_CH_PHASE_V}
#define MCHAL_ADC_PH_W
#define MCHAL_ADC_VDC                                    ${.vars["${MCPMSMFOC_ADCPLIB?lower_case}"].ADC_CH_VDC_BUS}
#define MCHAL_ADC_POT                                    ${.vars["${MCPMSMFOC_ADCPLIB?lower_case}"].ADC_CH_POT}

<#if __PROCESSOR?matches("PIC32M.*") == true>
#define MCHAL_ADC_RESULT_SHIFT                           ${12 - MCPMSMFOC_ADC_RESOLUTION?number}
#define MCHAL_ADCCallbackRegister(ch, fn, context)       ${.vars["${MCPMSMFOC_ADCPLIB?lower_case}"].ADC_CALLBACK_API}(ch, fn, context)
#define MCHAL_ADCChannelConversionStart(ch)              ${.vars["${MCPMSMFOC_ADCPLIB?lower_case}"].ADC_START_CONV_API}(ch)
#define MCHAL_ADCChannelResultGet(ch)                    ${.vars["${MCPMSMFOC_ADCPLIB?lower_case}"].ADC_GET_RESULT_API}(ch)
#define MCHAL_ADCChannelResultIsReady(ch)                ${.vars["${MCPMSMFOC_ADCPLIB?lower_case}"].ADC_IS_RESULT_READY_API}(ch)

<#elseif __PROCESSOR?matches(".*SAME70.*") == true>
#define MCHAL_ADC_RESULT_SHIFT                           (0U)
#define MCHAL_ADCCallbackRegister(ch, fn, context)       ${.vars["${MCPMSMFOC_ADCPLIB?lower_case}"].ADC_CALLBACK_API}(fn, context)
#define MCHAL_ADCChannelConversionStart(ch)              ${.vars["${MCPMSMFOC_ADCPLIB?lower_case}"].ADC_START_CONV_API}()
#define MCHAL_ADCChannelResultGet(ch)                    ${.vars["${MCPMSMFOC_ADCPLIB?lower_case}"].ADC_GET_RESULT_API}(ch)
#define MCHAL_ADCChannelResultIsReady(ch)                ${.vars["${MCPMSMFOC_ADCPLIB?lower_case}"].ADC_IS_RESULT_READY_API}(ch)
</#if>


<#if MCPMSMFOC_POSITION_FB == "SENSORED_ENCODER">
/*Encoder*/
#define MCHAL_EncoderStart()                 ${.vars["${MCPMSMFOC_ENCODERPLIB?lower_case}"].ENCODER_START_API}()
#define MCHAL_EncoderStop()                  ${.vars["${MCPMSMFOC_ENCODERPLIB?lower_case}"].ENCODER_STOP_API}()
#define MCHAL_EncoderPositionGet()           ${.vars["${MCPMSMFOC_ENCODERPLIB?lower_case}"].ENCODER_POS_GET_API}()
<#if __PROCESSOR?matches("PIC32M.*") == true>
#define MCHAL_EncoderSpeedGet()              ${.vars["${MCPMSMFOC_ENCODERPLIB?lower_case}"].ENCODER_SPEED_GET_API}()
#define MCHAL_EncoderPositionSet(count)      ${.vars["${MCPMSMFOC_ENCODERPLIB?lower_case}"].ENCODER_POS_SET_API}(count)
#define MCHAL_EncoderSpeedSet(count)         ${.vars["${MCPMSMFOC_ENCODERPLIB?lower_case}"].ENCODER_SPEED_SET_API}(count)
<#else>
#define MCHAL_EncoderSpeedGet()
#define MCHAL_EncoderPositionSet(count)
#define MCHAL_EncoderSpeedSet(count)
</#if>
</#if>

/* Interrupt */
#define MCHAL_CTRL_IRQ              (${.vars["${MCPMSMFOC_ADCPLIB?lower_case}"].INTERRUPT_ADC_RESULT})
#define MCHAL_FAULT_IRQ             (${.vars["${MCPMSMFOC_PWMPLIB?lower_case}"].INTR_PWM_FAULT})

<#if __PROCESSOR?matches("PIC32M.*") == true>
#define MCHAL_IntDisable(irq)       EVIC_SourceDisable(irq)
#define MCHAL_IntEnable(irq)        EVIC_SourceEnable(irq)
#define MCHAL_IntClear(irq)         EVIC_SourceStatusClear(irq)
<#else>
#define MCHAL_IntDisable(irq)       NVIC_DisableIRQ(irq)
#define MCHAL_IntEnable(irq)        NVIC_EnableIRQ(irq)
#define MCHAL_IntClear(irq)         NVIC_ClearPendingIRQ(irq)
</#if>


/* LED and Switches */

#define MCHAL_FAULT_LED_SET()       GPIO_${MCPMSMFOC_FAULT_LED}_Set()
#define MCHAL_FAULT_LED_CLEAR()     GPIO_${MCPMSMFOC_FAULT_LED}_Clear()
#define MCHAL_FAULT_LED_TOGGLE()    GPIO_${MCPMSMFOC_FAULT_LED}_Toggle()

#define MCHAL_DIR_LED_SET()         GPIO_${MCPMSMFOC_DIRECTION_LED}_Set()
#define MCHAL_DIR_LED_CLEAR()       GPIO_${MCPMSMFOC_DIRECTION_LED}_Clear()
#define MCHAL_DIR_LED_TOGGLE()      GPIO_${MCPMSMFOC_DIRECTION_LED}_Toggle()

#define MCHAL_START_STOP_SWITCH_GET()  GPIO_${MCPMSMFOC_START_BUTTON}_Get()

#define MCHAL_DIR_SWITCH_GET()         GPIO_${MCPMSMFOC_DIRECTION_BUTTON}_Get()

<#if MCPMSMFOC_X2CScope != "None">
#define MCHAL_X2C_Update()          X2CScope_Update()
<#else>
#define MCHAL_X2C_Update()
</#if>

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

}

#endif
// DOM-IGNORE-END

#endif //MCINF_H

/**
 End of File
*/
