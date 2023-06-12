/*******************************************************************************
 Application

  Company:
    Microchip Technology Inc.

  File Name:
    mc_tasks.h

  Summary:
 Application

  Description:
   Application
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2021 Microchip Technology Inc. and its subsidiaries.
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

#ifndef MCAPP_H    // Guards against multiple inclusion
#define MCAPP_H

/*******************************************************************************
 Header files inclusions
 *******************************************************************************/
#include "mc_types.h"
#include "definitions.h"
#include "mc_hardware_abstraction.h"
#include "mc_current_calculation.h"
#include "mc_voltage_measurement.h"
<#if MCPMSMFOC_FOC_X2C_ENABLE == false>
#include "mc_motor.h"
</#if>
#include "mc_field_oriented_control.h"
<#if MCPMSMFOC_FOC_X2C_ENABLE == false>
<#if 'IPD' == MCPMSMFOC_ALIGN_OR_DETECT_AXIS >
#include "mc_initial_position_detection.h"
</#if>
</#if>
<#if 'IPD' == MCPMSMFOC_ALIGN_OR_DETECT_AXIS >
#include "mc_key_manager.h"
</#if>

/*******************************************************************************
 Private data-types
 *******************************************************************************/

/*******************************************************************************
 * Interface variables
 *******************************************************************************/


/*******************************************************************************
 Interface Functions
 *******************************************************************************/

/*! \brief Application initialization
 *
 * Details.
 * Application initialization
 *
 * @param[in]:
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcAppI_ApplicationInit( void );

/*! \brief Over current reaction ISR
 *
 * Details.
 * Fault reaction ISR
 *
 * @param[in]:
 * @param[in/out]:
 * @param[out]:
 * @return:
 */

<#if __PROCESSOR?matches(".*SAME54.*") == true>
void mcAppI_OverCurrentReactionIsr( uint32_t status,  uintptr_t context );
<#elseif __PROCESSOR?matches(".*SAME70.*") == true>
void mcAppI_OverCurrentReactionIsr( uint32_t status,  uintptr_t context );
<#elseif __PROCESSOR?matches(".*PIC32MK.*") == true>
void mcAppI_OverCurrentReactionIsr( MCPWM_CH_STATUS status, uintptr_t context );
</#if>


/*! \brief Motor control application calibration
 *
 * Details.
 *  Motor Control application calibration
 *
 * @param[in]:
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
<#if __PROCESSOR?matches(".*SAME54.*") == true>
void mcAppI_AdcCalibrationIsr(ADC_STATUS status, uintptr_t context );
<#elseif __PROCESSOR?matches(".*SAME70.*") == true>
void mcAppI_AdcCalibrationIsr( uint32_t status, uintptr_t context );
<#elseif __PROCESSOR?matches(".*PIC32MK.*") == true>
void mcAppI_AdcCalibrationIsr( ADCHS_CHANNEL_NUM channel, uintptr_t context );
</#if>

<#if MCPMSMFOC_FOC_X2C_ENABLE == false>
<#if 'IPD' == MCPMSMFOC_ALIGN_OR_DETECT_AXIS >
/*! \brief Initial position detection ISR
 *
 * Details.
 *  Initial position detection ISR
 *
 * @param[in]:
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
<#if __PROCESSOR?matches(".*SAME54.*") == true>
void mcAppI_InitialPositionDetectIsr(ADC_STATUS status, uintptr_t context );
<#elseif __PROCESSOR?matches(".*SAME70.*") == true>
void mcAppI_InitialPositionDetectIsr( uint32_t status, uintptr_t context );
<#elseif __PROCESSOR?matches(".*PIC32MK.*") == true>
void mcAppI_InitialPositionDetectIsr( ADCHS_CHANNEL_NUM channel, uintptr_t context );
</#if>
</#if>
</#if>

/*! \brief Interrupt tasks execution
 *
 * Details.
 *  Interrupt tasks execution
 *
 * @param[in]:
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
<#if __PROCESSOR?matches(".*SAME54.*") == true>
void mcAppI_AdcFinishedIsr(ADC_STATUS status, uintptr_t context );
<#elseif __PROCESSOR?matches(".*SAME70.*") == true>
void mcAppI_AdcFinishedIsr( uint32_t status, uintptr_t context );
<#elseif __PROCESSOR?matches(".*PIC32MK.*") == true>
void mcAppI_AdcFinishedIsr( ADCHS_CHANNEL_NUM channel, uintptr_t context );
</#if>

/*! \brief Non-ISR tasks
 *
 * Details.
 * Non-ISR tasks
 *
 * @param[in]:
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcAppI_NonISRTasks( void );

/*! \brief Application reset
 *
 * Details.
 * Application reset
 *
 * @param[in]:
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcAppI_ApplicationReset( void );

#endif //MCAPP_H

/**
 End of File
*/
