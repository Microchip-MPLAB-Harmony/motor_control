/**
 * @brief 
 *    Header file for rotor position calculation
 *
 * @File Name 
 *    mc_rotor_position_calculation.h
 *
 * @Company 
 *    Microchip Technology Inc.
 *
 * @Summary
 *    Header file containing variables and function prototypes for rotor position calculation.
 *
 * @Description
 *    This file contains variables and function prototypes which are generally used for rotor
 *    position estimation in pulse width modulation. 
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

#ifndef MCRPC_H
#define MCRPC_H

/*******************************************************************************
 * Header inclusions
*******************************************************************************/
#include "mc_types.h"
#include "mc_motor.h"
#include "mc_utilities.h"
<#if MCPMSMFOC_POSITION_CALC_ALGORITHM == 'SENSORED_ENCODER'>
#include "mc_hardware_abstraction.h"
</#if>


/*******************************************************************************
 Default Module configuration parameters
*******************************************************************************/

/*******************************************************************************
Type Definition
*******************************************************************************/
typedef struct
{
    uint16_t encPulseCount;
<#if __PROCESSOR?matches(".*PIC32MK.*") == true>
    int16_t encVelocityCount;
</#if>
}tmcRpc_Input_s;

typedef struct
{
    float32_t elecAngle;
    float32_t elecSpeed;
}tmcRpc_Output_s;

typedef struct
{
    /** Motor parameters */
    tmcMot_PMSM_s  * pMotorParameters;

    float32_t dt;
<#if MCPMSMFOC_CONTROL_TYPE == 'POSITION_LOOP' >
    uint8_t gearRatio;
</#if>
    uint16_t velocityCountPrescaler;

    /** Encoder parameters */
    uint16_t encPulsesPerElecRev;
    uint16_t encPulsePerMechRev;

    void * pStatePointer;
}tmcRpc_Parameters_s;

typedef struct
{
    tmcRpc_Input_s dInput;
    tmcRpc_Output_s dOutput;
    tmcRpc_Parameters_s dParameters;
}tmcRpc_ModuleData_s;

/*******************************************************************************
 * Interface variables
*******************************************************************************/
extern tmcRpc_ModuleData_s mcRpcI_ModuleData_gds;

/*******************************************************************************
 * Static Interface Functions
 ******************************************************************************/

/*! \brief Read position counter from encoder
 *
 * This function reads the position counter from the encoder and stores it
 * in the provided input structure.
 *
 * @param[in/out] pInput Pointer to input structure where encoder pulse count will be stored.
 * @return None
 */
__STATIC_INLINE void mcRpcI_PositionCounterRead( tmcRpc_Input_s * const pInput )
{
    pInput->encPulseCount = mcHalI_EncoderPositionGet();
}

<#if __PROCESSOR?matches(".*PIC32MK.*") == true>
/*! \brief Read speed counter from encoder
 *
 * This function reads the speed counter from the encoder and stores it
 * in the provided input structure.
 *
 * @param[in/out] pInput Pointer to input structure where encoder velocity count will be stored.
 * @return None
 */
__STATIC_INLINE void mcRpcI_SpeedCounterRead( tmcRpc_Input_s * const pInput )
{
    pInput->encVelocityCount = mcHalI_EncoderVelocityGet();
}
</#if>

/*******************************************************************************
 * Interface Functions
 ******************************************************************************/

/*! 
 * @brief Set module parameters for rotor position estimation
 *
 * @detailsThis function initializes module parameters for rotor position estimation.
 *
 * @param[in/out] pParameters Pointer to parameters structure to be initialized.
 * @return None
 */
__STATIC_INLINE void mcRpcI_ParametersSet( tmcRpc_Parameters_s * const pParameters )
{
    /** Motor parameters */
    pParameters->pMotorParameters = &mcMotI_PMSM_gds;

    /** Prescaler for velocity count */
    pParameters->velocityCountPrescaler = 100u;

    /** PWM period */
    pParameters->dt = (float32_t)(${MCPMSMFOC_PWM_PERIOD});

    <#if MCPMSMFOC_CONTROL_TYPE == 'POSITION_LOOP' >
    /** Mechanical Gear Ratio */
    pParameters->gearRatio = (uint8_t)1;
    </#if>

    /** Encoder parameters */
    pParameters->encPulsesPerElecRev = (uint16_t)${MCPMSMFOC_ENCODER_QDEC_PULSE_PER_EREV};
    pParameters->encPulsePerMechRev = pParameters->encPulsesPerElecRev * (uint16_t)mcMotI_PMSM_gds.PolePairs;
}

/*******************************************************************************
 * Interface Functions
 ******************************************************************************/
/**
 * @brief Initialize rotor position calculation module
 *
 * @param[in] pModule Pointer to module data structure
 */
void  mcRpcI_RotorPositionCalcInit( tmcRpc_ModuleData_s * const pModule );

/**
 * @brief Enable rotor position calculation module
 *
 * @param[in] pModule Pointer to module data structure
 */
void  mcRpcI_RotorPositionCalcEnable( tmcRpc_ModuleData_s * const pModule );

/**
 * @brief Disable rotor position calculation module
 *
 * @param[in] pModule Pointer to module data structure
 */
void  mcRpcI_RotorPositionCalcDisable( tmcRpc_ModuleData_s * const pModule );

/**
 * @brief Perform rotor position calculation
 *
 * @param[in] pModule Pointer to module data structure
 */
void mcRpcI_RotorPositionCalc( tmcRpc_ModuleData_s * const pModule );

<#if MCPMSMFOC_CONTROL_TYPE == 'POSITION_LOOP' >
/**
 * @brief Get mechanical angle
 *
 * @param[in] pModule Pointer to module data structure
 * @return Mechanical angle
 */
float32_t mcRpcI_MechanicalAngleGet( const tmcRpc_ModuleData_s * const pModule );
</#if>

/**
 * @brief Reset rotor position calculation module
 *
 * @param[in] pModule Pointer to module data structure
 */
void mcRpcI_RotorPositionCalcReset( tmcRpc_ModuleData_s * const pModule );

#endif // MCRPC_H
