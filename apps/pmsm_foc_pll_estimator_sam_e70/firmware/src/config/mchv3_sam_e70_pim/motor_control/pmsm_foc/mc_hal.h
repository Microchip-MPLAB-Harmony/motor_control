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
#define MCHAL_PWM_PH_U                  PWM_CHANNEL_0
#define MCHAL_PWM_PH_V                  PWM_CHANNEL_1
#define MCHAL_PWM_PH_W                  PWM_CHANNEL_2
#define MCHAL_PWM_PH_MASK               0x7
#define MCHAL_PWMStop(mask)                 PWM0_ChannelsStop(mask)
#define MCHAL_PWMStart(mask)                PWM0_ChannelsStart(mask)
#define MCHAL_PWMPrimaryPeriodGet(ch)       PWM0_ChannelPeriodGet(ch)
#define MCHAL_PWMDutySet(ch, duty)          PWM0_ChannelDutySet(ch, duty)
#define MCHAL_PWMOutputDisable(ch)          PWM0_ChannelOverrideDisable(ch)
#define MCHAL_PWMOutputEnable(ch)           PWM0_ChannelOverrideEnable(ch)
#define MCHAL_PWMCallbackRegister(ch, fn, context)  PWM0_CallbackRegister(fn, context)

/* ADC */
#define MCHAL_ADC_PH_U                                   AFEC_CH0
#define MCHAL_ADC_PH_V                                   AFEC_CH6
#define MCHAL_ADC_PH_W
#define MCHAL_ADC_VDC                                    AFEC_CH7
#define MCHAL_ADC_POT                                    AFEC_CH10

#define MCHAL_ADC_RESULT_SHIFT                           (0U)
#define MCHAL_ADCCallbackRegister(ch, fn, context)       AFEC0_CallbackRegister(fn, context)
#define MCHAL_ADCChannelConversionStart(ch)              AFEC0_ConversionStart()
#define MCHAL_ADCChannelResultGet(ch)                    AFEC0_ChannelResultGet(ch)
#define MCHAL_ADCChannelResultIsReady(ch)                AFEC0_ChannelResultIsReady(ch)



/* Interrupt */
#define MCHAL_CTRL_IRQ              (AFEC0_IRQn)
#define MCHAL_FAULT_IRQ             (PWM0_IRQn)

#define MCHAL_IntDisable(irq)       NVIC_DisableIRQ(irq)
#define MCHAL_IntEnable(irq)        NVIC_EnableIRQ(irq)
#define MCHAL_IntClear(irq)         NVIC_ClearPendingIRQ(irq)


/* LED and Switches */

#define MCHAL_FAULT_LED_SET()       GPIO_PC23_Set()
#define MCHAL_FAULT_LED_CLEAR()     GPIO_PC23_Clear()
#define MCHAL_FAULT_LED_TOGGLE()    GPIO_PC23_Toggle()


#define MCHAL_START_STOP_SWITCH_GET()  GPIO_PE2_Get()

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
