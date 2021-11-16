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

/*******************************************************************************
 Header File inclusions 
 *******************************************************************************/
#include <stddef.h>
#include "mc_interface_handling.h"
#include "mc_generic_library.h"
#include "mc_userparams.h"


/*******************************************************************************
 * Configuration parameters 
 *******************************************************************************/
/**
 * Number of rotor position module instances 
 */
#define ROTOR_POSITION_INSTANCES 1u

/**
 * Reduced Order Luenberger Observer gain 
 */
#define CONFIG_RoloHGain    (float)( 0.5 )

/**
 * Motor per phase resistance 
 */
#define CONFIG_MotorPerPhaseResistanceInOhm    (float) ( MOTOR_PER_PHASE_RESISTANCE_IN_OHM )

/**
 * Motor per phase inductance 
 */
#define CONFIG_MotorPerPhaseInductanceInHenry    (float) ( QUADRATURE_AXIS_INDUCTANCE_IN_HENRY )

/**
 * Speed filter corner frequency
 */
#define CONFIG_RoloSpeedFilterCornerFrequency   (float)( 200.0f )

/**
 * Sampling time 
 */
#define CONFIG_RoloAlgorithmCycleTime   (float)( 1.0f / PWM_FREQUENCY )

/*******************************************************************************
 * Default module parameters
 *******************************************************************************/
#define ROTOR_POSITION_MODULE_A_CONFIG {\
     /* Instance Id */\
    0u, \
\
    /* Input ports */ \
    {\
        &mcMocI_FeedbackAlphaBetaCurrent_gas[0u].alpha, \
        &mcMocI_FeedbackAlphaBetaCurrent_gas[0u].beta, \
        &mcMocI_AlphaBetaVoltage_gas[0u].alpha, \
        &mcMocI_AlphaBetaVoltage_gas[0u].beta, \
        &mcVolI_UacPeakVoltage_gaf32[0u] \
    }, \
\
    /* Output ports */ \
    { \
        &mcRpoI_ElectricalRotorPosition_gaf32[0u], \
        &mcRpoI_ElectricalRotorSpeed_gaf32[0u], \
        &mcRpoI_ElectricalRotorAccel_gaf32[0u]  \
    }, \
\
    /* User Parameters */ \
    { \
        CONFIG_MotorPerPhaseResistanceInOhm, \
        CONFIG_MotorPerPhaseInductanceInHenry, \
        CONFIG_RoloHGain, \
        CONFIG_RoloAlgorithmCycleTime, \
        CONFIG_RoloSpeedFilterCornerFrequency  \
    }\
}

#define ROTOR_POSITION_MODULE_B_CONFIG {\
     /* Instance Id */\
    0u, \
\
    /* Input ports */ \
    {\
        &mcMocI_FeedbackAlphaBetaCurrent_gas[1u].alpha, \
        &mcMocI_FeedbackAlphaBetaCurrent_gas[1u].beta, \
        &mcMocI_AlphaBetaVoltage_gas[1u].alpha, \
        &mcMocI_AlphaBetaVoltage_gas[1u].beta, \
        &mcVolI_UacPeakVoltage_gaf32[1u] \
    }, \
\
    /* Output ports */ \
    { \
        &mcRpoI_ElectricalRotorPosition_gaf32[1u], \
        &mcRpoI_ElectricalRotorSpeed_gaf32[1u], \
        &mcRpoI_ElectricalRotorAccel_gaf32[1u]  \
    }, \
\
    /* User Parameters */ \
    { \
        CONFIG_MotorPerPhaseResistanceInOhm, \
        CONFIG_MotorPerPhaseInductanceInHenry, \
        CONFIG_RoloHGain, \
        CONFIG_RoloAlgorithmCycleTime, \
        CONFIG_RoloSpeedFilterCornerFrequency  \
    }\
}

/*******************************************************************************
Module data types  
 *******************************************************************************/
typedef enum _tmcRpo_InstanceId_e
{
    rolModuleInstance_01,
    rolModuleInstance_02,
    rolModuleInstance_max
}tmcRpo_InstanceId_e;


/*! \brief Brief description.
 *   This structure holds value of external input required by the ROLO.
 *
 *  This structure comprises of external inputs required to execute ROLO.
 *  
 */
typedef struct _tmcRpo_InputPorts_s
{
    float * ialpha;
    float * ibeta;
    float * ualpha;
    float * ubeta;
    float * umax;
}tmcRpo_InputPorts_s;


/*! \brief Brief description.
 *         This structure holds value of external paramaters required by the ROLO.
 *
 *  This structure comprises of external parameters required to execute ROLO.
 *  
 */
typedef struct _tmcRpo_UserParameters_s
{
   float Rs;
   float Ls;
   float H;
   float Ts;      
   float Wc;
}tmcRpo_UserParameters_s;

/*! \brief Brief description.
 *         This structure holds value of output variables of ROLO.
 *
 *  This structure holds value of output variables of ROLO.
 *  
 */
typedef struct _tmcRpo_OutputPorts_s
{
    float * angle;
    float * speed;
    float * accel;
}tmcRpo_OutputPorts_s;

typedef struct _tmcRpo_ConfigParameters_s
{
    /* Instance Id */
    uint8_t Id;
    
    /* Input ports */
    tmcRpo_InputPorts_s inPort;
    
    /* Output ports */
    tmcRpo_OutputPorts_s outPort;
    
    /* User Parameters */
    tmcRpo_UserParameters_s userParam;
    
}tmcRpo_ConfigParameters_s;

/*******************************************************************************
 Interface Variables 
 *******************************************************************************/
extern tmcRpo_ConfigParameters_s  mcRpoI_ConfigParameters_gas[ROTOR_POSITION_INSTANCES];


/*******************************************************************************
 Interface Functions 
 *******************************************************************************/

/*! \brief Reduced order Luenberger observer ( ROLO ) initialization
 * 
 * Details.
 * Reduced order Luenberger observer ( ROLO ) initialization
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
tStd_ReturnType_e mcRpoI_RotorPositionCalculationInit( tmcRpo_ConfigParameters_s * const rolParam );

/*! \brief Reduced order Luenberger observer ( ROLO ) run
 * 
 * Details.
 * Reduced order Luenberger observer ( ROLO ) run
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcRpoI_RotorPositionCalculationRun( const tmcRpo_InstanceId_e Id );

/*! \brief Reduced order Luenberger observer ( ROLO ) reset
 * 
 * Details.
 * Reduced order Luenberger observer ( ROLO ) reset
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcRpoI_RotorPositionCalculationReset( const tmcRpo_InstanceId_e Id );


#endif //MCRPO_H

/**
 End of File
*/
