/*******************************************************************************
  Field Oriented Control ( FOC ) header file

  File Name:
    mc_pwm.h

  Summary:
    Header file which contains variables and function prototypes for Field Oriented Control ( FOC )

  Description:
    This file contains variables and function prototypes which are generally used for Field Oriented
    Control ( FOC ).

 *******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2022 Microchip Technology Inc. and its subsidiaries.
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
//DOM-IGNORE-END

#ifndef MCFOC_H
#define MCFOC_H

/*******************************************************************************
 * Header inclusions
*******************************************************************************/
#include "mc_types.h"
#include "mc_pwm.h"
#include "mc_open_loop_startup.h"
<#if ( MCPMSMFOC_POSITION_CALC_ALGORITHM != 'SENSORED_ENCODER' ) && ( MCPMSMFOC_ENABLE_FLYING_START == true ) >
#include "mc_flying_start.h"
</#if>
#include "mc_flux_control.h"
#include "mc_torque_control.h"
#include "mc_speed_control.h"
<#if MCPMSMFOC_CONTROL_TYPE == 'POSITION_LOOP' >
#include "mc_position_control.h"
</#if>
#include "mc_reference_control.h"
#include "mc_rotor_position_calculation.h"
<#if 'IPD' == MCPMSMFOC_ALIGN_OR_DETECT_AXIS >
#include "mc_initial_position_detection.h"
</#if>
#include "mc_utilities.h"
#include "mc_hardware_abstraction.h"
#include "mc_current_calculation.h"
#include "mc_voltage_measurement.h"

/*******************************************************************************
 Default Module configuration parameters
*******************************************************************************/

/*******************************************************************************
Type Definition
*******************************************************************************/
typedef struct
{
    tmcTypes_ABC_s iABC;
<#if ( MCPMSMFOC_POSITION_CALC_ALGORITHM == 'SENSORED_ENCODER' )>
    float32_t elecAngle;
    float32_t elecSpeed;
</#if>
<#if ( MCPMSMFOC_CONTROL_TYPE == 'POSITION_LOOP' ) >
    float32_t mechanicalAngle;
</#if>
    float32_t uBus;
    float32_t reference;
<#if 'IPD' == MCPMSMFOC_ALIGN_OR_DETECT_AXIS >
    float32_t initialAngle;
</#if>
}tmcFoc_Input_s;

typedef struct
{
    tmcTypes_AlphaBeta_s  iAlphaBeta;
    tmcTypes_AlphaBeta_s  uAlphaBeta;
    tmcTypes_DQ_s  iDQ;
<#if ( MCPMSMFOC_POSITION_CALC_ALGORITHM != 'SENSORED_ENCODER' )>
    float32_t elecAngle;
    float32_t elecSpeed;
</#if>
    int16_t duty[3u];
}tmcFoc_Output_s;

typedef struct
{
   tmcMot_PMSM_s * pMotorParameters;
   float32_t potInputToRef;
}tmcFoc_Parameters_s;

typedef struct
{
  tmcFoc_Input_s dInput;
  tmcFoc_Output_s dOutput;
  tmcFoc_Parameters_s dParameters;
  void * pStatePointer;
}tmcFocI_ModuleData_s;

/*******************************************************************************
 * Interface variables
*******************************************************************************/
extern tmcFocI_ModuleData_s mcFocI_ModuleData_gds;

/*******************************************************************************
 Static Interface Functions
*******************************************************************************/
/*! \brief Read input ports
 *
 * Details.
 * Read input ports
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
__STATIC_INLINE void mcFocI_InputsRead( tmcFocI_ModuleData_s * const pModule )
{
    tmcFoc_Input_s * pInput = &pModule->dInput;

    pInput->iABC.a = (float32_t)mcCurI_ModuleData_gds.dOutput.iABC.a;
    pInput->iABC.b = (float32_t)mcCurI_ModuleData_gds.dOutput.iABC.b;

<#if ( MCPMSMFOC_POSITION_CALC_ALGORITHM == 'SENSORED_ENCODER' )>
    pInput->elecAngle = (float32_t)mcRpcI_ModuleData_gds.dOutput.elecAngle;
    pInput->elecSpeed = (float32_t)mcRpcI_ModuleData_gds.dOutput.elecSpeed;

<#if MCPMSMFOC_CONTROL_TYPE == 'POSITION_LOOP' >
    pInput->mechanicalAngle = mcRpcI_MechanicalAngleGet(&mcRpcI_ModuleData_gds);
</#if>
</#if>

    pInput->uBus = (float32_t)mcVolI_ModuleData_gds.dOutput.uBus;

<#if MCPMSMFOC_CONTROL_TYPE == 'POSITION_LOOP' >
    pInput->reference =  (float32_t)mcHalI_Potentiometer_gdu16 * TWO_PI / 4095.0f;
<#elseif ( MCPMSMFOC_CONTROL_TYPE == 'SPEED_LOOP' ) >
<#if ( MCPMSMFOC_POSITION_CALC_ALGORITHM == 'SENSORLESS_ZSMT_HYBRID' )>
    pInput->reference = ((float32_t)mcHalI_Potentiometer_gdu16 - 2048.0f ) * pModule->dParameters.potInputToRef;
<#else>
    pInput->reference = ((float32_t)mcHalI_Potentiometer_gdu16 ) * pModule->dParameters.potInputToRef;
</#if>
<#elseif ( MCPMSMFOC_CONTROL_TYPE == 'TORQUE_LOOP' ) >
    pInput->reference =  (float32_t)mcHalI_Potentiometer_gdu16;
</#if>

<#if 'IPD' == MCPMSMFOC_ALIGN_OR_DETECT_AXIS >
    pInput->initialAngle = mcIpdI_ModuleData_gds.dOutput.phi;
</#if>
}


/*! \brief Set module parameters
 *
 * Details.
 * Set module parameters
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
__STATIC_INLINE void mcFocI_ParametersSet( tmcFoc_Parameters_s * const pParameters )
{
   pParameters->pMotorParameters = &mcMotI_PMSM_gds;

<#if ( MCPMSMFOC_POSITION_CALC_ALGORITHM == 'SENSORLESS_ZSMT_HYBRID' )>
<#if ( MCPMSMFOC_ENABLE_FW == true ) >
   pParameters->potInputToRef = mcMotI_PMSM_gds.NmaxInRpm / 2048.0f;
<#else>
   pParameters->potInputToRef = mcMotI_PMSM_gds.NratedInRpm  / 2048.0f;
</#if>
<#else>
<#if ( MCPMSMFOC_ENABLE_FW == true ) >
   pParameters->potInputToRef = mcMotI_PMSM_gds.NmaxInRpm / 4095.0f;
<#else>
   pParameters->potInputToRef = mcMotI_PMSM_gds.NratedInRpm  / 4095.0f;
</#if>
</#if>
}

/*! \brief Set module parameters
 *
 * Details.
 * Set module parameters
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
__STATIC_INLINE void mcFocI_OutputPortWrite( tmcFoc_Output_s * const pOutput )
{
    mcPwmI_Duty_gau16[0u] = pOutput->duty[0u];
    mcPwmI_Duty_gau16[1u] = pOutput->duty[1u];
    mcPwmI_Duty_gau16[2u] = pOutput->duty[2u];
}

/*******************************************************************************
 Interface Functions
*******************************************************************************/
/*! \brief Initialize Field Oriented Control ( FOC ) module
 *
 * Details.
 * Initialize Field Oriented Control ( FOC ) module
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
void  mcFocI_FieldOrientedControlInit( tmcFocI_ModuleData_s * const pModule );

/*! \brief Enable Field Oriented Control ( FOC ) module
 *
 * Details.
 * Enable Field Oriented Control ( FOC ) module
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
void  mcFocI_FieldOrientedControlEnable( tmcFocI_ModuleData_s * const pParameters );

/*! \brief Disable Field Oriented Control ( FOC ) module
 *
 * Details.
 * Disable Field Oriented Control ( FOC ) module
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
void  mcFocI_FieldOrientedControlDisable( tmcFocI_ModuleData_s * const pParameters );

/*! \brief Field Oriented Control ( FOC )
 *
 * Details.
 * Field Oriented Control ( FOC )
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
void mcFocI_FieldOrientedControlFast(  tmcFocI_ModuleData_s * const pModule );

/*! \brief Field Oriented Control ( FOC )
 *
 * Details.
 * Field Oriented Control ( FOC )
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
void mcFocI_FieldOrientedControlSlow( const tmcFocI_ModuleData_s * const pParameters );

/*! \brief Field Oriented Control ( FOC )
 *
 * Details.
 * Field Oriented Control ( FOC )
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
void mcFocI_MotorDirectionChange(const tmcFocI_ModuleData_s * const pParameters);

/*! \brief Reset Field Oriented Control ( FOC )
 *
 * Details.
 * Reset Field Oriented Control ( FOC )
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return:
 */
void mcFocI_FieldOrientedControlReset( const tmcFocI_ModuleData_s * const pParameters );

#endif // MCFOC_H
