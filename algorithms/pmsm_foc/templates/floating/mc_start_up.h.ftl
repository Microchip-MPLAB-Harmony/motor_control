/*******************************************************************************
  Motor open loop start-up  

  Company:
    Microchip Technology Inc.

  File Name:
    mc_start_up.h

  Summary:
   Motor open loop start up header file 

  Description:
  Motor open loop start up header file 
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

#ifndef MCSUP_H_    // Guards against multiple inclusion
#define MCSUP_H_

/*******************************************************************************
 Header files inclusions
 *******************************************************************************/
#include <stddef.h>
#include "mc_interface_handling.h"
#include "mc_rotor_position.h"
#include "mc_generic_library.h"
#include "mc_userparams.h"


/*******************************************************************************
 Parameters 
 *******************************************************************************/
/**
 * Number of module instances 
 */
#define START_UP_INSTANCES 2u

/**
 * Start-up algorithm cycle time 
 */
#define CONFIG_StartUpAlgoCycleTime  (float)( 1.0f / PWM_FREQUENCY )

/**
 * Alignment lock time 
 */
#define  CONFIG_StartupLockTimeInSec  START_UP_LOCK_TIME_IN_SECOND

/**
 * Alignment time in Ampere 
 */
#define  CONFIG_LockCurrentInAmp START_UP_CURRENT_IN_AMPERE

/**
 * Start-up time in Ampere 
 */
#define  CONFIG_StartupCurrentInAmp START_UP_CURRENT_IN_AMPERE

/**
 * Open loop ramp time in seconds 
 */

#define CONFIG_StartupRampTimeInSec START_UP_RAMP_TIME_IN_SECOND

/**
 * Open loop stabilization time in seconds 
 */
#define CONFIG_StartupStabTimeInSec START_UP_STAB_TIME_IN_SECOND

/**
 * Open loop transition speed in RPM
 */
#define CONFIG_StartupThresholdSpeedInRpm  MINIMUM_SPEED_IN_RPM

/*******************************************************************************
 Default module parameters 
 *******************************************************************************/
#define START_UP_MODULE_A_CONFIG  { \
        /* Instance Id */ \
        0u, \
        /* Output ports */ \
        { \
            &mcSpeI_ReferenceIdCurrent_gaf32[0u], \
            &mcSpeI_ReferenceIqCurrent_gaf32[0u], \
            &mcMocI_SpaceVectorAngle_gaf32[0u]  \
        }, \
        /* User parameters */ \
        { \
            /* Alignment time in seconds */ \
            CONFIG_StartupLockTimeInSec, \
\
            /* Alignment current in Amperes */ \
            CONFIG_LockCurrentInAmp, \
\
            /* Open loop Current in Amperes */ \
            CONFIG_StartupCurrentInAmp, \
\
            /* Open loop ramp time in seconds */ \
            CONFIG_StartupRampTimeInSec, \
\
            /* Open loop stabilization time in seconds  */ \
            CONFIG_StartupStabTimeInSec, \
\
            /* Open loop transition speed in RPM */ \
            CONFIG_StartupThresholdSpeedInRpm, \
\
             /* Sampling time */ \
            CONFIG_StartUpAlgoCycleTime \
        } \
    }

#define START_UP_MODULE_B_CONFIG  { \
        /* Instance Id */ \
        1u, \
        /* Output ports */ \
        { \
            &mcSpeI_ReferenceIdCurrent_gaf32[1u], \
            &mcSpeI_ReferenceIqCurrent_gaf32[1u], \
            &mcMocI_SpaceVectorAngle_gaf32[1u]  \
        }, \
        /* User parameters */ \
        { \
            /* Alignment time in seconds */ \
            CONFIG_StartupLockTimeInSec, \
\
            /* Alignment current in Amperes */ \
            CONFIG_LockCurrentInAmp, \
\
            /* Open loop Current in Amperes */ \
            CONFIG_StartupCurrentInAmp, \
\
            /* Open loop ramp time in seconds */ \
            CONFIG_StartupRampTimeInSec, \
\
            /* Open loop stabilization time in seconds  */ \
            CONFIG_StartupStabTimeInSec, \
\
            /* Open loop transition speed in RPM */ \
            CONFIG_StartupThresholdSpeedInRpm, \
\
             /* Sampling time */ \
            CONFIG_StartUpAlgoCycleTime \
        } \
    }

/*******************************************************************************
 User defined data-types
 *******************************************************************************/

typedef enum _tmcSup_InstanceId_e
{
    supModuleInstance_01,
    supModuleInstance_02,
    supModuleInstance_max 
}tmcSup_InstanceId_e;

typedef struct _tmcSup_InputPorts_s
{
 
}tmcSup_InputPorts_s;


typedef struct _tmcSup_OutputPorts_s
{
    float * Idref;
    float * Iqref;
    float * theta;
}tmcSup_OutputPorts_s;


typedef struct _tmcSup_UserParameters_s
{
    float alignmentTime;
    float alignmentCurrent;
    float openLoopCurrent;
    float openLoopRampTime;
    float openLoopStabTime;
    float openLoopTransSpeed;
    float Ts;
}tmcSup_UserParameters_s;

typedef struct _tmcSup_Dependencies_s
{
    
}tmcSup_Dependencies_s;


typedef struct _tmcSup_ConfigParameters_s
{
    /* Instance Identifier */
    uint8_t Id;
       
    /* Output ports */
    tmcSup_OutputPorts_s outPort;
    
    /* User Parameters */
    tmcSup_UserParameters_s userParam;
       
}tmcSup_ConfigParameters_s;

/*******************************************************************************
 Interface variables 
 *******************************************************************************/
extern tmcSup_ConfigParameters_s mcSupI_ConfigurationParameters_gas[START_UP_INSTANCES];

/*******************************************************************************
 Interface Functions 
 *******************************************************************************/
/*! \brief Open loop start up initialization function 
 * 
 * Details.
 *  Open loop start up initialization function 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
tStd_ReturnType_e mcSupI_OpenLoopStartupInit( tmcSup_ConfigParameters_s * supParam );

/*! \brief Open loop start up execution function 
 * 
 * Details.
 *  Open loop start up execution function 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
uint8_t mcSupI_OpenLoopStartupRun( const tmcSup_InstanceId_e Id );

/*! \brief Open loop start up reset function 
 * 
 * Details.
 *  Open loop start up  reset function 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcSupI_OpenLoopStartupReset( const tmcSup_InstanceId_e Id );

#endif //MCREG_H

/**
 End of File
*/
