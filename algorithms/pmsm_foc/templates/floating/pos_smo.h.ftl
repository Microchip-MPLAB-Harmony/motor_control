/*******************************************************************************
 Rotor Position interface file

  Company:
    Microchip Technology Inc.

  File Name:
    mc_rotor_position.h

  Summary:
    Header file for rotor position

  Description:
    This file contains the data structures and function prototypes of rotor position.
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

#ifndef MCRPO_H    // Guards against multiple inclusion
#define MCRPO_H

#include <stddef.h>
#include "mc_interface_handling.h"
#include "mc_generic_library.h"
#include "mc_userparams.h"

/*******************************************************************************
 Constants
 *******************************************************************************/
#define ROTOR_POSITION_INSTANCES 1u

/**
 * 
 */
#define CONFIG_SmoSwitchingFunctionBoundary ((float)0.5) 

/**
 * 
 */
#define CONFIG_SmoSwitchingFunctionGain ((float)8000.0)   

/**
 * 
 */
#define CONFIG_SmoEigenValuesPosition ((float)-1000.0)  

/**
 * 
 */
#define CONFIG_SmoSpeedFilterCornerFrequency ((float)200.0)  

/**
 * 
 */
#define CONFIG_SmoAlgorithmCycleTimeInSec  ((float)( 1.0f / PWM_FREQUENCY ))

/**
 * 
 */
#define CONFIG_SmoMotorPerPhaseResistanceInOhm (float)( MOTOR_PER_PHASE_RESISTANCE_IN_OHM )

/**
 * 
 */
#define CONFIG_SmoMotorPerPhaseInductanceInHenry (float)( QUADRATURE_AXIS_INDUCTANCE_IN_HENRY )

/**
 * 
 */
#define CONFIG_SmoMotorPolePairs ((float)NUM_POLE_PAIRS)  

/**
 * 
 */
#define CONFIG_SmoSpeedReferenceTimeInSec  (float)0.2

/*******************************************************************************
 Default module parameters
 *******************************************************************************/
#define ROTOR_POSITION_MODULE_A_CONFIG {\
    .Id = 0u, \
    { \
        .ialpha =  &mcMocI_FeedbackAlphaBetaCurrent_gas[0u].alpha, \
        .ibeta =  &mcMocI_FeedbackAlphaBetaCurrent_gas[0u].beta, \
        .ualpha =  &mcMocI_AlphaBetaVoltage_gas[0u].alpha, \
        .ubeta =  &mcMocI_AlphaBetaVoltage_gas[0u].beta, \
        .umax = &mcVolI_UacPeakVoltage_gaf32[0u] \
    }, \
    { \
        .angle =  &mcRpoI_ElectricalRotorPosition_gaf32[0u], \
        .speed =   &mcRpoI_ElectricalRotorSpeed_gaf32[0u], \
        .accel =  &mcRpoI_ElectricalRotorAccel_gaf32[0u]   \
    }, \
    { \
       .boundaryI        = CONFIG_SmoSwitchingFunctionBoundary, \
       .m                = CONFIG_SmoSwitchingFunctionGain, \
       .lambda           = CONFIG_SmoEigenValuesPosition, \
       .wcSpeedFil       = CONFIG_SmoSpeedFilterCornerFrequency, \
       .Ts          = CONFIG_SmoAlgorithmCycleTimeInSec, \
       .rs               = CONFIG_SmoMotorPerPhaseResistanceInOhm, \
       .ls               = CONFIG_SmoMotorPerPhaseInductanceInHenry, \
       .P                = CONFIG_SmoMotorPolePairs, \
       .speedRefTime     = CONFIG_SmoSpeedReferenceTimeInSec, \
    } \
}

#define ROTOR_POSITION_MODULE_B_CONFIG {\
    .Id = 1u, \
    { \
        .ialpha =  &mcMocI_FeedbackAlphaBetaCurrent_gas[1u].alpha, \
        .ibeta =  &mcMocI_FeedbackAlphaBetaCurrent_gas[1u].beta, \
        .ualpha =  &mcMocI_AlphaBetaVoltage_gas[1u].alpha, \
        .ubeta =  &mcMocI_AlphaBetaVoltage_gas[1u].beta, \
        .umax = &mcVolI_UacPeakVoltage_gaf32[1u] \
    }, \
    { \
        .angle =  &mcRpoI_ElectricalRotorPosition_gaf32[1u], \
        .speed =   &mcRpoI_ElectricalRotorSpeed_gaf32[1u], \
        .accel =  &mcRpoI_ElectricalRotorAccel_gaf32[1u]   \
    }, \
    { \
       .boundaryI        = CONFIG_SmoSwitchingFunctionBoundary, \
       .m                = CONFIG_SmoSwitchingFunctionGain, \
       .lambda           = CONFIG_SmoEigenValuesPosition, \
       .wcSpeedFil       = CONFIG_SmoSpeedFilterCornerFrequency, \
       .Ts          = CONFIG_SmoAlgorithmCycleTimeInSec, \
       .rs               = CONFIG_SmoMotorPerPhaseResistanceInOhm, \
       .ls               = CONFIG_SmoMotorPerPhaseInductanceInHenry, \
       .P                = CONFIG_SmoMotorPolePairs, \
       .speedRefTime     = CONFIG_SmoSpeedReferenceTimeInSec, \
    } \
}

/*******************************************************************************
 Module data type 
 *******************************************************************************/
typedef struct _tmcRpo_InputPorts_s
{
    float * ialpha;
    float * ibeta;
    float * ualpha;
    float * ubeta;
    float * umax;
}tmcRpo_InputPorts_s;

typedef struct _tmcRpo_OutputPorts_s
{
    float * angle;
    float * speed;
    float * accel;
}tmcRpo_OutputPorts_s;

typedef struct _tmcRpo_UserParameters_s
{
    float boundaryI;
    float m;
    float lambda;
    float wcSpeedFil;
    float Ts;
    float rs;
    float ls;
    float P;
    float speedRefTime;
}tmcRpo_UserParameters_s;

typedef struct _tmcRpo_ConfigParameters_s
{
    /* Instance Id */
    uint8_t Id;

    /* Input ports */
    tmcRpo_InputPorts_s inPort;
    
    /* Output ports */
    tmcRpo_OutputPorts_s outPort;
    
    /* User parameters */
    tmcRpo_UserParameters_s userParam;
    
}tmcRpo_ConfigParameters_s;


/*******************************************************************************
 Interface Variables  
 *******************************************************************************/
extern tmcRpo_ConfigParameters_s mcRpoI_ConfigParameters_gas[ROTOR_POSITION_INSTANCES];

/*******************************************************************************
 Interface Functions 
 *******************************************************************************/
/*! \brief Sliding mode observer ( SMO ) initialization
 * 
 * Details.
 * Sliding mode observer ( SMO )  initialization
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
tStd_ReturnType_e mcRpoI_RotorPositionCalculationInit( tmcRpo_ConfigParameters_s * const smoParam );


/*! \brief Sliding mode observer ( SMO ) trigger
 * 
 * Details.
 * Sliding mode observer ( SMO )  trigger
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcRpoI_RotorPositionCalculationTrigger( uint8_t  Id  );

/*! \brief Sliding mode observer ( SMO ) execution
 * 
 * Details.
 * Sliding mode observer ( SMO )  execution
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcRpoI_RotorPositionCalculationRun( uint8_t  mcInstance );


/*! \brief Sliding mode observer ( SMO ) reset
 * 
 * Details.
 * Sliding mode observer ( SMO )  reset
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void     mcRpoI_RotorPositionCalculationReset( uint8_t  mcInstance );


#endif  /* MCRPO_H */

