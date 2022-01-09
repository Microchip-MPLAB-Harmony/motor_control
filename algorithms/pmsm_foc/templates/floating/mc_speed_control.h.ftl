/*******************************************************************************
    Speed measurement interface file

  Company:
    Microchip Technology Inc.

  File Name:
    mc_speed_control.h

  Summary:
    Header file for speed measurement

  Description:
    This file contains the data structures and function prototypes used by
    speed measurement.
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

#ifndef MCSPE_H
#define MCSPE_H

/*******************************************************************************
 Header File inclusions 
 *******************************************************************************/
#include <stddef.h>
#include "mc_generic_library.h"
#include "mc_interface_handling.h"
#include "mc_hardware_abstraction.h"
#if ( ( CONTROL_LOOP == SPEED_LOOP ) && ( ENABLE != POTENTIOMETER_INPUT_ENABLED )  )
#include "mc_ramp_profiler.h"
#endif

/*******************************************************************************
 Parameters 
 *******************************************************************************/
#define SPEED_CONTROL_INSTANCES 1u
#define POTENTIOMETER_FILTER_PARAMETER 0.05f

/**
 * Number of pole pairs 
 */
#define CONFIG_SpeNumberOfPolePairs             NUM_POLE_PAIRS

/**
 *  Minimum close loop speed 
 */
<#if "SENSORED_ENCODER" == MCPMSMFOC_POSITION_CALC_ALGORITHM >
#define CONFIG_MinimumCloseLoopSpeed     (float)(10.0f)
<#else>
#define CONFIG_MinimumCloseLoopSpeed     (float)(${MCPMSMFOC_OPEN_LOOP_END_SPEED})
</#if>

/**
 *  Maximum close loop speed 
 */
#if(FIELD_WEAKENING == ENABLE)
#define CONFIG_MaximumCloseLoopSpeed     (float)(MAXIMUM_SPEED_IN_RPM) 
#else
#define CONFIG_MaximumCloseLoopSpeed     (float)(RATED_SPEED_IN_RPM) 
#endif

/*******************************************************************************
 Default module parameters 
 *******************************************************************************/
#define SPEED_CONTROL_MODULE_A_CONFIG  { \
        /* Instance Id */ \
        0u, \
        /* Input ports */ \
        { \
            &mcHalI_Potentiometer_gdu16, \
            &mcSpeI_ReferenceElectricalSpeed_gaf32[0u], \
            &mcRpoI_ElectricalRotorSpeed_gaf32[0u] \
        }, \
        /* Output ports */ \
        { \
            &mcSpeI_ReferenceIqCurrent_gaf32[0u], \
            &mcSpeI_ReferenceElectricalSpeed_gaf32[0u] \
        }, \
        /* User Parameters */ \
        { \
             /* Speed PI controller parameters */ \
            { \
                /* Reference Signal */ \
                0.0f, \
\
                /* Feedback signal */ \
                0.0f,\
\
                /* Proportional gain */ \
                SPEED_KP, \
\
                /* Integral gain */ \
                SPEED_KI, \
\
                /* Anti-windup back calculation gain */ \
                SPEED_KC, \
\
                /* Last integral */ \
                0.0f, \
\
                /* Positive saturation limit */ \
                SPEED_YMAX, \
\
                /* Negative saturation limit */ \
                -SPEED_YMAX, \
\
                /* Control output */ \
                0.0f  \
            }, \
            POTENTIOMETER_FILTER_PARAMETER, \
            CONFIG_MinimumCloseLoopSpeed, \
            CONFIG_MaximumCloseLoopSpeed  \
        } \
    }
        
#define SPEED_CONTROL_MODULE_B_CONFIG  { \
        /* Instance Id */ \
        1u, \
        /* Input ports */ \
        { \
            &mcHalI_Potentiometer_gdu16, \
            &mcSpeI_ReferenceElectricalSpeed_gaf32[1u], \
            &mcRpoI_ElectricalRotorSpeed_gaf32[1u] \
        }, \
        /* Output ports */ \
        { \
            &mcSpeI_ReferenceIqCurrent_gaf32[1u], \
            &mcSpeI_ReferenceElectricalSpeed_gaf32[1u] \
        }, \
        /* User Parameters */ \
        { \
             /* Speed PI controller parameters */ \
            { \
                /* Reference Signal */ \
                0.0f, \
\
                /* Feedback signal */ \
                0.0f,\
\
                /* Proportional gain */ \
                SPEED_KP, \
\
                /* Integral gain */ \
                SPEED_KI, \
\
                /* Anti-windup back calculation gain */ \
                SPEED_KC, \
\
                /* Last integral */ \
                0.0f, \
\
                /* Positive saturation limit */ \
                SPEED_YMAX, \
\
                /* Negative saturation limit */ \
                -SPEED_YMAX, \
\
                /* Control output */ \
                0.0f  \
            }, \
            POTENTIOMETER_FILTER_PARAMETER, \
            CONFIG_MinimumCloseLoopSpeed, \
            CONFIG_MaximumCloseLoopSpeed  \
        } \
    }
        
        
/*******************************************************************************
 Module data type
 *******************************************************************************/

typedef enum _tmcSpe_InstanceId_e
{
    speModuleInstance_01,
    speModuleInstance_02,
    speModuleInstance_max 
}tmcSpe_InstanceId_e;

typedef struct _tmcSpe_InputPorts_s 
{
    volatile uint16_t * potReading;
    volatile float * referenceSpeed;
    volatile float * actualSpeed;
}tmcSpe_InputPorts_s;

typedef struct _tmcSpe_OutputPorts_s
{
    float  * iqref;
    float *  referenceSpeed;
}tmcSpe_OutputPorts_s;


typedef struct _tmcSpe_UserParameters_s
{
    tmcLib_PiController_s    speedController;
    float speedFilterParam;
    float minReferenceSpeed;
    float maxReferenceSpeed;
}tmcSpe_UserParameters_s;

typedef struct _tmcSpe_ConfigParameters_s
{
    /* Instance identifier */
    uint8_t Id;
    
    /* Input ports */
    tmcSpe_InputPorts_s inPort;
    
    /* Output ports */
    tmcSpe_OutputPorts_s outPort;
    
    /* User Parameters */
    tmcSpe_UserParameters_s userParam;
    
}tmcSpe_ConfigParameters_s;


/*******************************************************************************
 Interface variables  
 *******************************************************************************/
extern tmcSpe_ConfigParameters_s  mcSpeI_ConfigParameters_gas[SPEED_CONTROL_INSTANCES];

/*******************************************************************************
 Interface Functions 
 *******************************************************************************/
/*! \brief Speed control module initialization function 
 * 
 * Details.
 *  Speed control module initialization function 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
tStd_ReturnType_e  mcSpeI_SpeedRegulationInit( const tmcSpe_ConfigParameters_s * const speParam );

/*! \brief Speed control module run function 
 * 
 * Details.
 *  Speed control module run function 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcSpeI_SpeedRegulationRun( const tmcSpe_InstanceId_e Id );


/*! \brief Set speed control control output directly 
 * 
 * Details.
 *  Set speed control output directly 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcSpeI_SpeedControlOutputSet( uint8_t Id, float value );

/*! \brief Set speed control integrator directly 
 * 
 * Details.
 *  Set speed control integrator directly
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcSpeI_SpeedControlIntegralSet( uint8_t Id, float value );

/*! \brief Speed control module reset function 
 * 
 * Details.
 *  Speed control module reset function 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcSpeI_SpeedRegulationReset( const tmcSpe_InstanceId_e Id );


#endif    /* MCSPE_H */
