/**
 * @file application.h
 *
 * @brief 
 *   Application Header file
 *
 * @Company 
 *    Microchip Technology Inc.
 *
 * @Summary
 *   Header file defining application-specific details.
 *
 * @Description
 *   This header file provides definitions and structures specific to the application,
 *   including configuration settings, function prototypes, and any other necessary details.
 */

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
#include "mc_motor.h"
#include "mc_field_oriented_control.h"
<#if MCPMSMFOC_FOC_X2C_ENABLE == false>
<#if 'IPD' == MCPMSMFOC_ALIGN_OR_DETECT_AXIS >
#include "mc_initial_position_detection.h"
</#if>
</#if>

<#if ('IPD' == MCPMSMFOC_ALIGN_OR_DETECT_AXIS )  ||  ('SENSORLESS_ZSMT_HYBRID' == MCPMSMFOC_POSITION_CALC_ALGORITHM )>
#include "mc_key_manager.h"
</#if>

<#if ( MCPMSMFOC_POSITION_CALC_ALGORITHM == 'SENSORED_ENCODER' )>
#include "mc_rotor_position_calculation.h"
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

/**
 * @brief Application initialization
 *
 * @details Initializes the application.
 *
 * @param[in] None
 * @param[in/out] None
 * @param[out] None
 *
 * @return None
 */
void mcAppI_ApplicationInit( void );

/**
 * @brief Over current reaction ISR
 *
 * @details Interrupt service routine for over current reaction.
 *
 * @param[in] status Status information
 * @param[in/out] context Interrupt context
 * @param[out] None
 *
 * @return None
 */
<#if "TCC_U2213" == MCPMSMFOC_PWM_IP>
void mcAppI_OverCurrentReactionIsr( uint32_t status,  uintptr_t context );
<#elseif "PWM_6343" == MCPMSMFOC_PWM_IP>
void mcAppI_OverCurrentReactionIsr( uint32_t status,  uintptr_t context );
<#elseif "MCPWM_01477" == MCPMSMFOC_PWM_IP>
void mcAppI_OverCurrentReactionIsr( MCPWM_CH_STATUS status, uintptr_t context );
</#if>

/**
 * @brief Motor control application calibration ISR
 *
 * @details Interrupt service routine for motor control application calibration.
 *
 * @param[in] status ADC status information
 * @param[in/out] context Interrupt context
 * @param[out] None
 *
 * @return None
 */
<#if ("ADC_U2500" == MCPMSMFOC_ADC_IP )  || ("ADC_U2247" == MCPMSMFOC_ADC_IP )>
void mcAppI_AdcCalibrationIsr(ADC_STATUS status, uintptr_t context );
<#elseif ("ADC_44073" == MCPMSMFOC_ADC_IP )>
void mcAppI_AdcCalibrationIsr(uint32_t status, uintptr_t context );
<#elseif "AFEC_11147" == MCPMSMFOC_ADC_IP>
void mcAppI_AdcCalibrationIsr( uint32_t status, uintptr_t context );
<#elseif "ADCHS_02508" == MCPMSMFOC_ADC_IP>
void mcAppI_AdcCalibrationIsr( ADCHS_CHANNEL_NUM channel, uintptr_t context );
</#if>

<#if MCPMSMFOC_FOC_X2C_ENABLE == false>
<#if 'IPD' == MCPMSMFOC_ALIGN_OR_DETECT_AXIS >
/**
 * @brief ADC finished ISR
 *
 * @details Interrupt service routine for ADC finished IPD tasks.
 *
 * @param[in] status ADC status information
 * @param[in/out] context Interrupt context
 * @param[out] None
 *
 * @return None
 */
<#if ("ADC_U2500" == MCPMSMFOC_ADC_IP )  || ("ADC_U2247" == MCPMSMFOC_ADC_IP )>
void mcAppI_InitialPositionDetectIsr(ADC_STATUS status, uintptr_t context );
<#elseif "AFEC_11147" == MCPMSMFOC_ADC_IP>
void mcAppI_InitialPositionDetectIsr( uint32_t status, uintptr_t context );
<#elseif ("ADC_44073" == MCPMSMFOC_ADC_IP )>
void mcAppI_InitialPositionDetectIsr(uint32_t status, uintptr_t context );
<#elseif "ADCHS_02508" == MCPMSMFOC_ADC_IP>
void mcAppI_InitialPositionDetectIsr( ADCHS_CHANNEL_NUM channel, uintptr_t context );
</#if>
</#if>
</#if>

/**
 * @brief ADC finished ISR
 *
 * @details Interrupt service routine for ADC finished tasks.
 *
 * @param[in] status ADC status information
 * @param[in/out] context Interrupt context
 * @param[out] None
 *
 * @return None
 */
<#if ("ADC_U2500" == MCPMSMFOC_ADC_IP )  || ("ADC_U2247" == MCPMSMFOC_ADC_IP )>
void mcAppI_AdcFinishedIsr(ADC_STATUS status, uintptr_t context );
<#elseif ("ADC_44073" == MCPMSMFOC_ADC_IP )>
void mcAppI_AdcFinishedIsr(uint32_t status, uintptr_t context );
<#elseif "AFEC_11147" == MCPMSMFOC_ADC_IP>
void mcAppI_AdcFinishedIsr( uint32_t status, uintptr_t context );
<#elseif "ADCHS_02508" == MCPMSMFOC_ADC_IP>
void mcAppI_AdcFinishedIsr( ADCHS_CHANNEL_NUM channel, uintptr_t context );
</#if>

/**
 * @brief Non-ISR tasks execution
 *
 * @details Executes non-interrupt service routine tasks.
 *
 * @param[in] None
 * @param[in/out] None
 * @param[out] None
 *
 * @return None
 */
void mcAppI_NonISRTasks( void );

/**
 * @brief Application reset
 *
 * @details Resets the application.
 *
 * @param[in] None
 * @param[in/out] None
 * @param[out] None
 *
 * @return None
 */
void mcAppI_ApplicationReset( void );

#endif //MCAPP_H

/**
 End of File
*/
