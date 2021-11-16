/*******************************************************************************
  System Definitions

  File Name:
    mc_flying_start.h

  Summary:
    Flying start header file 
 
  Description:
    Flying start header file

 *******************************************************************************/

//DOM-IGNORE-BEGIN
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
//DOM-IGNORE-END

#ifndef MCFLY_H
#define MCFLY_H
/*******************************************************************************
 * Header inclusions 
*******************************************************************************/
#include <stdint.h>
#include <sys/attribs.h>
#include "mc_generic_library.h"
#include "mc_error_handler.h"
#include "mc_userparams.h"
#include "mc_interface_handling.h"
#include "mc_hardware_abstraction.h"
#include "mc_current_control.h"

/*******************************************************************************
 Configuration parameters
*******************************************************************************/

/*
 *  Flying start  time in seconds 
 */
#define FLYING_START_DETECTION_TIME_IN_SEC        (float)( 0.3f )

/*
 *  Flying start minimum speed in RPM
 */
#define FLYING_START_MINIMUM_SPEED_IN_RPM   (float)( 500.0f )

/*
 *  Flying start  current in amperes  
 */
#define FLYING_START_CURRENT_IN_AMP   (float)( 0.4 ) 

/*
 *  Fadeout time in seconds 
 */
#define FADE_OUT_TIME_IN_SEC  (float)( 2.0f )

/*
 *  Fadeout time in seconds 
 */
#define FADE_OUT_BURST_TIME_IN_SEC  (float)( 0.02f )

/*
 *  Flying start current  
 */
#define FLYING_START_CURRENT_IN_AMP   (float)( 0.4 )

/*
 *  Regenerative braking current 
 */
#define FLYING_START_BRAKE_CURRENT_IN_AMP   (float)( 0.4 )

/*
 * Regenerative braking current ramp rate in Amperes per second  
 */
#define FLYING_START_BRAKE_CURRENT_STEP_IN_AMP_PER_SEC  (float)(0.1 ) 

/*
 * Flying start PI controller proportional gain 
 */
#define FLYING_START_CONTROLLER_PROPORTIONAL_GAIN    (float)(0.2)

/*
 * Flying start PI controller integral gain 
 */
#define FLYING_START_CONTROLLER_INTEGRAL_GAIN    (float)(0.00099)

/*
 * Flying start PI controller back calculation anti-windup gain 
 */
#define FLYING_START_CONTROLLER_ANTI_WINDUP_GAIN    (float)(0.5)

/*
 * Flying start PI controller saturation limit
 */
#define FLYING_START_CONTROLLER_SATURATION_LIMIT    (float)(0.98)

/*******************************************************************************
 Default Module configuration parameters 
*******************************************************************************/
#define FLYING_START_MODULE_CONFIG {\
    /* Identifier */ \
    flyModuleInstance_01,\
   \
    /* Input port */ \
    {\
        &mcRpoI_ElectricalRotorSpeed_gaf32[0u], \
        &mcRpoI_ElectricalRotorPosition_gaf32[0u], \
        &mcMocI_RotationSign_gas8[0u] \
    },\
    \
    /* Output port */ \
    {\
        &mcSpeI_ReferenceIdCurrent_gaf32[0u], \
        &mcSpeI_ReferenceIqCurrent_gaf32[0u], \
        &mcMocI_SpaceVectorAngle_gaf32[0u] \
    },\
    \
    /* User parameters  */ \
    {\
        /* detectTime */ \
        FLYING_START_DETECTION_TIME_IN_SEC, \
        \
        /* minRpmForFlyingStart  */ \
        FLYING_START_MINIMUM_SPEED_IN_RPM, \
        \
          /* brakeCurrenInAmps  */ \
        FLYING_START_CURRENT_IN_AMP, \
        \
        /* brakeCurrenInAmps  */ \
        FLYING_START_BRAKE_CURRENT_IN_AMP, \
        \
        /* brakeCurrentStepInAmps  */ \
        FLYING_START_BRAKE_CURRENT_STEP_IN_AMP_PER_SEC, \
        \
        /* fadeOutTime  */ \
        FADE_OUT_TIME_IN_SEC, \
        \
        /* fadeOutBurstTime  */ \
        FADE_OUT_BURST_TIME_IN_SEC,\
    }\
}

#define FLYING_START_CONTOLLER_PARAMETERS_CONFIG    {  \
    /* Proportional gain */ \
    FLYING_START_CONTROLLER_PROPORTIONAL_GAIN,   \
    \
    /* Integral gain */ \
    FLYING_START_CONTROLLER_INTEGRAL_GAIN,   \
    \
    /* Anti-windup back calculation gain */ \
    FLYING_START_CONTROLLER_ANTI_WINDUP_GAIN,   \
    \
    /* Positive saturation limit */ \
    FLYING_START_CONTROLLER_SATURATION_LIMIT,  \
    \
    /* Negative saturation limit */ \
    -FLYING_START_CONTROLLER_SATURATION_LIMIT \
}

#define CURRENT_CONTOLLER_PARAMETERS_CONFIG    {  \
    /* Proportional gain */ \
    Q_CURRENT_KP,   \
    \
    /* Integral gain */ \
    Q_CURRENT_KI,   \
    \
    /* Anti-windup back calculation gain */ \
    Q_CURRENT_KC,   \
    \
    /* Positive saturation limit */ \
    Q_CURRENT_YMAX,  \
    \
    /* Negative saturation limit */ \
    -Q_CURRENT_YMAX \
}
   
/*******************************************************************************
Type Definition
*******************************************************************************/
typedef enum _tmcFly_InstanceId_e
{
    flyModuleInstance_01,
    flyModuleInstance_02,
    flyModuleInstance_max 
}tmcFly_InstanceId_e;

typedef struct 
{
    volatile float  * observedElecVelocity;
    volatile float * observedElecTheta;
    volatile int8_t  * rotationSign;
}tmcFly_InputPorts_s;

typedef struct _tmcFly_UserParameters_s 
{
    float detectTime;
    float minRpmForFlyingStart;
    float flyingStartCurrentInAmps;
    float brakeCurrenInAmps;
    float brakeCurrentStepInAmps;
    float fadeOutTime;
    float fadeOutBurstTime;   
}tmcFly_UserParameters_s;

typedef struct 
{
    float * idRef;
    float * iqRef;
    float * observedElecTheta;
}tmcFly_OutputPorts_s;


typedef struct _tmcFly_ConfigParameters_s 
{
    /* Instance Id */
    tmcFly_InstanceId_e Id; 
    
    /* Input port */
    tmcFly_InputPorts_s     inPort;
    
    /* Output port */
    tmcFly_OutputPorts_s     outPort;
    
    /* User Parameter */
    tmcFly_UserParameters_s   userParam;
        
}tmcFly_ConfigParameters_s;

/*******************************************************************************
 * Interface variables 
*******************************************************************************/
extern tmcFly_ConfigParameters_s mcFlyI_ConfigParameters_gas[1u];

/*******************************************************************************
 Interface Functions 
*******************************************************************************/

/* !\brief Initialize flying start  
 * 
 * Details.
 * Initialize flying start  
 * 
 * @param[in]: None 
 * @param[in/out]: None
 * @param[out]: None 
 * @return: 
 */
tStd_ReturnType_e mcFlyI_FlyingStartInit(const tmcFly_ConfigParameters_s * const flyConfigParam);


/* !\brief  Run flying start 
 * 
 * Details.
 * Run flying start
 * 
 * @param[in]: None 
 * @param[in/out]: None
 * @param[out]: None 
 * @return: 
 */
#ifdef RAM_EXECUTE
tStd_ReturnType_e  __ramfunc__ mcFlyI_FlyingStartRun(const tmcFly_InstanceId_e Id);
#else
tStd_ReturnType_e mcFlyI_FlyingStartRun( const tmcFly_InstanceId_e Id);
#endif

/* !\brief Reset flying reset   
 * 
 * Details.
 * Reset flying start
 * 
 * @param[in]: None 
 * @param[in/out]: None
 * @param[out]: None 
 * @return: 
 */
void mcFlyI_FlyingStartReset(const tmcFly_InstanceId_e Id);



#endif // _MCPWM_H
