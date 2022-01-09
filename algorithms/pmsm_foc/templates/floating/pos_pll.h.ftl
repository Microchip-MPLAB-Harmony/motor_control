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
 Interface Functions 
 *******************************************************************************/
#include <stddef.h>
#include "mc_interface_handling.h"
#include "mc_userparams.h"

/*******************************************************************************
 Constants
 *******************************************************************************/
/*
 * Number of rotor position module instances 
 */
#define ROTOR_POSITION_INSTANCES 1u  

/*
 * Motor per phase resistance 
 */
 #define CONFIG_PllMotorPerPhaseResistanceInOhm  (float)MOTOR_PER_PHASE_RESISTANCE_IN_OHM
/*
 * Number of rotor position module instances 
 */
#define  CONFIG_PllMotorPerPhaseInductanceInHenry  (float)QUADRATURE_AXIS_INDUCTANCE_IN_HENRY
/*
 * Number of rotor position module instances 
 */
#define CONFIG_PllMotorBemfConstInVrmsPerKrpm  MOTOR_BEMF_CONST_VOLTS_PER_KRPM_MECH

/*
 * Fast loop time in seconds 
 */
#define CONFIG_PllAlgorithmCycleTimeInSec   (float)(1/(float)PWM_FREQUENCY) 
 

/*
 * Open loop end speed in RPM
 */
#define CONFIG_SpeedThresholdForCloseLoopInRpm       (float)(500.0f)


/*
 * Q-axis back EMF filter parameter 
 */
#define CONFIG_PllEdFilterParameter      (float)(${MCPMSMFOC_ED_FILTER_PARAMETER})

/*
 * D-axis back EMF filter parameter 
 */
#define CONFIG_PllEqFilterParameter  (float)(${MCPMSMFOC_EQ_FILTER_PARAMETER})


/*
 * Open loop end speed in RPM
 */
#define CONFIG_PllSpeedFilterParameter        (float)(${MCPMSMFOC_SPEED_FILTER_PARAMETER})

/*******************************************************************************
 Default module parameters 
 *******************************************************************************/
#define ROTOR_POSITION_MODULE_A_CONFIG { \
        /* Instance Id */ \
        0u, \
        /* Input ports */ \
        { \
            &mcMocI_FeedbackAlphaBetaCurrent_gas[0u].alpha, \
            &mcMocI_FeedbackAlphaBetaCurrent_gas[0u].beta, \
            &mcMocI_AlphaBetaVoltage_gas[0u].alpha, \
            &mcMocI_AlphaBetaVoltage_gas[0u].beta, \
            &mcVolI_UacPeakVoltage_gaf32[0u]  \
        }, \
        /* Output ports */ \
        { \
            &mcRpoI_ElectricalRotorPosition_gaf32[0u], \
            &mcRpoI_ElectricalRotorSpeed_gaf32[0u], \
            &mcRpoI_ElectricalRotorAccel_gaf32[0u] \
        }, \
        /* User Parameters */ \
        { \
            CONFIG_PllMotorPerPhaseResistanceInOhm, \
            CONFIG_PllMotorPerPhaseInductanceInHenry, \
            CONFIG_PllMotorBemfConstInVrmsPerKrpm, \
            CONFIG_SpeedThresholdForCloseLoopInRpm, \
            CONFIG_PllAlgorithmCycleTimeInSec, \
            CONFIG_PllEqFilterParameter, \
            CONFIG_PllSpeedFilterParameter \
        } \
    }

#define ROTOR_POSITION_MODULE_B_CONFIG { \
        /* Instance Id */ \
        1u, \
        /* Input ports */ \
        { \
            &mcMocI_FeedbackAlphaBetaCurrent_gas[1u].alpha, \
            &mcMocI_FeedbackAlphaBetaCurrent_gas[1u].beta, \
            &mcMocI_AlphaBetaVoltage_gas[1u].alpha, \
            &mcMocI_AlphaBetaVoltage_gas[1u].beta, \
            &mcVolI_UacPeakVoltage_gaf32[1u]  \
        }, \
        /* Output ports */ \
        { \
            &mcRpoI_ElectricalRotorPosition_gaf32[1u], \
            &mcRpoI_ElectricalRotorSpeed_gaf32[1u], \
            &mcRpoI_ElectricalRotorAccel_gaf32[1u] \
        }, \
        /* User Parameters */ \
        { \
            CONFIG_PllMotorPerPhaseResistanceInOhm, \
            CONFIG_PllMotorPerPhaseInductanceInHenry, \
            CONFIG_PllMotorBemfConstInVrmsPerKrpm, \
            CONFIG_SpeedThresholdForCloseLoopInRpm, \
            CONFIG_PllAlgorithmCycleTimeInSec, \
            CONFIG_PllEqFilterParameter, \
            CONFIG_PllSpeedFilterParameter \
        } \
    }

/*******************************************************************************
 User defined data types  
 *******************************************************************************/

typedef enum _tmcRpo_InstanceId_e
{
    rpoModuleInstance_01,
    rpoModuleInstance_02,
    rpoModuleInstance_max 
}tmcRpo_InstanceId_e;


typedef struct _tmcRpo_InputPorts_s 
{
    volatile float * ialpha;
    volatile float * ibeta;
    volatile float * ualpha;
    volatile float * ubeta;
    volatile float * umax;
}tmcRpo_InputPorts_s;

typedef struct _tmcRpo_OutputPorts_s
{
    float  * theta;
    float  * Wre;
    float  * accel;
}tmcRpo_OutputPorts_s;

typedef struct _tmcRpo_UserParameters_s
{
    float  Rs;
    float  Ls;
    float  Ke;
    float Wrmin;
    float Ts;
    float EdqFilterBandwidth;
    float WrFilterBandwidth;
}tmcRpo_UserParameters_s;

typedef struct _tmcRpo_ConfigParameters_s
{
    /* Instance identifier */
    uint8_t Id;
    
    /* Input ports */
    tmcRpo_InputPorts_s inPort;
    
    /* Output ports */
    tmcRpo_OutputPorts_s outPort;
    
    /* User Parameters */
    tmcRpo_UserParameters_s userParam;
    
}tmcRpo_ConfigParameters_s;


/*******************************************************************************
 Interface variables  
 *******************************************************************************/
extern tmcRpo_ConfigParameters_s  mcRpoI_ConfigParameters_gas[ROTOR_POSITION_INSTANCES];

/*******************************************************************************
 Interface Functions 
 *******************************************************************************/

/*! \brief Rotor position calculation initialization function 
 * 
 * Details.
 *  Rotor position calculation initialization function 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
tStd_ReturnType_e mcRpoI_RotorPositionCalculationInit( const tmcRpo_ConfigParameters_s * const rpoParam );

/*! \brief Rotor position calculation execution  function 
 * 
 * Details.
 *  Rotor position calculation execution function 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcRpoI_RotorPositionCalculationRun( const tmcRpo_InstanceId_e Id );

/*! \brief Rotor position calculation reset function 
 * 
 * Details.
 *  Rotor position calculation reset function 
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
