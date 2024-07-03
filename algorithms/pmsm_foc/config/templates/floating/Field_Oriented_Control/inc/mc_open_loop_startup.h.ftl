/**
 * @brief 
 *    Open loop start-up header file
 *
 * @File Name 
 *    mc_open_loop_startup.h
 *
 * @Company 
 *    Microchip Technology Inc.
 *
 * @Summary
 *    This file contains definitions for open loop start-up functions and parameters.
 *
 * @Description
 *    This file provides the definitions of structures and functions necessary for open loop 
 *    start-up of a motor. It includes declarations for initialization and control routines 
 *    to start the motor in an open loop manner before transitioning to closed loop control.
 */

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

#ifndef MCSUP_H
#define MCSUP_H

/*******************************************************************************
 * Header inclusions
*******************************************************************************/
#include "mc_types.h"
#include "mc_utilities.h"
#include "mc_motor.h"
<#if MCPMSMFOC_POSITION_CALC_ALGORITHM == 'SENSORED_ENCODER'>
#include "mc_hardware_abstraction.h"
</#if>

/*******************************************************************************
 Default Module configuration parameters
*******************************************************************************/
/*******************************************************************************
 Parameters
 *******************************************************************************/

/*******************************************************************************
 Default module parameters
 *******************************************************************************/

/*******************************************************************************
 User defined data-types
 *******************************************************************************/
typedef struct
{
    tmcMot_PMSM_s * pMotorParameters;
    float32_t alignmentTime;
    float32_t alignmentCurrent;
    float32_t openLoopCurrent;
    float32_t openLoopRampTime;
    float32_t openLoopStabTime;
    float32_t openLoopTransSpeed;
    float32_t dt;
    void * pStatePointer;
}tmcSup_Parameters_s;

/*******************************************************************************
 Static interface functions
 *******************************************************************************/
 /**
 * @brief Set the parameters for the open loop start-up
 *
 * This function sets the parameters for the open loop start-up.
 *
 * @param[in] pParameters Pointer to the open loop start-up parameters structure
 */
__STATIC_INLINE void mcSupI_ParametersSet( tmcSup_Parameters_s * const pParameters )
{
    pParameters->pMotorParameters = &mcMotI_PMSM_gds;
    pParameters->dt = (float32_t)(${MCPMSMFOC_PWM_PERIOD});
    pParameters->alignmentTime = (float32_t)(${MCPMSMFOC_STARTUP_TIME});
    pParameters->alignmentCurrent = (float32_t)(${MCPMSMFOC_STARTUP_CURRENT});
    pParameters->openLoopCurrent = (float32_t)(${MCPMSMFOC_STARTUP_CURRENT});
    pParameters->openLoopRampTime = (float32_t)(${MCPMSMFOC_OPEN_LOOP_RAMP_TIME});
    pParameters->openLoopStabTime = (float32_t)(${MCPMSMFOC_OPEN_LOOP_STAB_TIME});
    pParameters->openLoopTransSpeed = (float32_t)(${MCPMSMFOC_OPEN_LOOP_END_SPEED});
}

/*******************************************************************************
 * Interface variables
*******************************************************************************/

/*******************************************************************************
 Interface Functions
*******************************************************************************/

/**
 * @brief Initialize open loop start-up module
 *
 * This function initializes the open loop start-up module.
 *
 * @param[in] pParameters Pointer to the open loop start-up parameters structure
 */
void  mcSupI_OpenLoopStartupInit( tmcSup_Parameters_s * const pParameters );

/**
 * @brief Enable open loop start-up module
 *
 * This function enables the open loop start-up module.
 *
 * @param[in] pParameters Pointer to the open loop start-up parameters structure
 */
void  mcSupI_OpenLoopStartupEnable( tmcSup_Parameters_s * const pParameters );

/**
 * @brief Disable open loop start-up module
 *
 * This function disables the open loop start-up module.
 *
 * @param[in] pParameters Pointer to the open loop start-up parameters structure
 */
void  mcSupI_OpenLoopStartupDisable( tmcSup_Parameters_s * const pParameters );

/**
 * @brief Perform open loop start-up
 *
 * This function performs the open loop start-up of the motor.
 *
 * @param[in] pParameters Pointer to the open loop start-up parameters structure
 * @param[in] direction Motor rotation direction
 * @param[out] pIQref Pointer to the q-axis current reference
 * @param[out] pIDref Pointer to the d-axis current reference
 * @param[out] pAngle Pointer to the rotor angle
 * @param[out] pSpeed Pointer to the rotor speed
 *
 * @return Standard return type indicating success or failure
 */
tmcTypes_StdReturn_e mcSupI_OpenLoopStartup( const tmcSup_Parameters_s * const pParameters,
                                          float32_t direction, float32_t * const pIQref,
                                          float32_t * const pIDref, float32_t * const pAngle,
                                          float32_t * const pSpeed );

/**
 * @brief Reset open loop start-up
 *
 * This function resets the open loop start-up parameters.
 *
 * @param[in] pParameters Pointer to the open loop start-up parameters structure
 */
void mcSupI_OpenLoopStartupReset( const tmcSup_Parameters_s * const pParameters );

#endif // MCSUP_H
