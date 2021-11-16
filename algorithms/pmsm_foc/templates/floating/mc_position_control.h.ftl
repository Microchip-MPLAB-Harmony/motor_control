/*******************************************************************************
    Speed measurement interface file

  Company:
    Microchip Technology Inc.

  File Name:
    mc_position_control.h

  Summary:
    Header file for Position regulation

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

#ifndef MCPOS_H
#define MCPOS_H

/*******************************************************************************
 Header File inclusions 
 *******************************************************************************/
#include <stddef.h>
#include "mc_interface_handling.h"
#include "mc_hardware_abstraction.h"
#include "mc_userparams.h"
#if(( POSITION_LOOP == CONTROL_LOOP ) && ( DISABLE == POTENTIOMETER_INPUT_ENABLED ))
#include "mc_ramp_profiler.h"
#endif

/*******************************************************************************
 Parameters 
 *******************************************************************************/
#define POSITION_CONTROL_INSTANCES 1u

/**
 * Position Controller PI propotional gain
 */
#define CONFIG_PosProportionalGain    (float)(25.0f)

/**
 * Position Controller PI integral gain
 */
#define CONFIG_PosIntegralGain     (float)(0.001f)

/**
 * Position Controller PI anti-windup gain
 */
#define CONFIG_PosAntiWindupGain   (float)(0.5f)

/**
 * Position Controller PI maximum output
 */
#define CONFIG_PosMaximumOutput    (float)( 1000.0f )

/**
 * Position Controller PI minimum output
 */
#define CONFIG_PosMinimumOutput    (float)( -1000.0f )

/**
 * Position Controller angular range 
 */
#define CONFIG_AngularRangeInDegrees (float)(360)



/*******************************************************************************
 Default module parameters 
 *******************************************************************************/
#define POSITION_CONTROL_MODULE_A_CONFIG  { \
        /* Instance Id */ \
        0u, \
        /* Input ports */ \
        { \
            &mcHalI_Potentiometer_gdu16, \
            &mcRpoI_MechanicalRotorPosition_gaf32[0u],\
        }, \
        /* Output ports */ \
        { \
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
                CONFIG_PosProportionalGain, \
\
                /* Integral gain */ \
                CONFIG_PosIntegralGain, \
\
                /* Anti-windup back calculation gain */ \
                CONFIG_PosAntiWindupGain, \
\
                /* Last integral */ \
                0.0f, \
\
                /* Positive saturation limit */ \
                CONFIG_PosMaximumOutput, \
\
                /* Negative saturation limit */ \
                CONFIG_PosMinimumOutput, \
\
                /* Control output */ \
                0.0f  \
            }, \
            CONFIG_AngularRangeInDegrees  \
        } \
    }
        
#define POSITION_CONTROL_MODULE_B_CONFIG  { \
        /* Instance Id */ \
        1u, \
        /* Input ports */ \
        { \
            &mcHalI_Potentiometer_gdu16, \
            &mcRpoI_MechanicalRotorPosition_gaf32[1u],\
        }, \
        /* Output ports */ \
        { \
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
                CONFIG_PosProportionalGain, \
\
                /* Integral gain */ \
                CONFIG_PosIntegralGain, \
\
                /* Anti-windup back calculation gain */ \
                CONFIG_PosAntiWindupGain, \
\
                /* Last integral */ \
                0.0f, \
\
                /* Positive saturation limit */ \
                CONFIG_PosMaximumOutput, \
\
                /* Negative saturation limit */ \
                CONFIG_PosMinimumOutput, \
\
                /* Control output */ \
                0.0f  \
            }, \
            CONFIG_AngularRangeInDegrees  \
        } \
    }
        
        
/*******************************************************************************
 Module data type
 *******************************************************************************/

typedef enum _tmcPos_InstanceId_e
{
    posModuleInstance_01,
    posModuleInstance_02,
    posModuleInstance_max 
}tmcPos_InstanceId_e;

typedef struct _tmcPos_RampProfiler_s
{
    float newSpeed;
    float filtSpeed;
    float filtParam;
}tmcPos_RampProfiler_s;


typedef struct _tmcPos_InputPorts_s 
{
    uint16_t * potReading;
    float * actualPosition;
}tmcPos_InputPorts_s;

typedef struct _tmcPos_OutputPorts_s
{
    float *  commandSpeed;
}tmcPos_OutputPorts_s;



typedef struct tmcPos_PiController_s
{
    /* Reference Signal */
    float reference;
    
    /* Feedback signal */
    float feedback;
    
    /* Proportional gain */
    float Kp;
    
    /* Integral gain */
    float Ki;
    
    /* Anti-windup back calculation gain */
    float Kc;
    
    /* Last integral */
    float Yi;
    
    /* Positive saturation limit */
    float Ymax;
    
    /* Negative saturation limit */
    float Ymin;
    
    /* Control output */
    float Yout;
    
}tmcPos_PiController_s;


typedef struct _tmcPos_UserParameters_s
{
    tmcPos_PiController_s    positionController;
    uint16_t maximumReferenceAngle;
}tmcPos_UserParameters_s;

typedef struct _tmcPos_ConfigParameters_s
{
    /* Instance identifier */
    uint8_t Id;
    
    /* Input ports */
    tmcPos_InputPorts_s inPort;
    
    /* Output ports */
    tmcPos_OutputPorts_s outPort;
    
    /* User Parameters */
    tmcPos_UserParameters_s userParam;
    
}tmcPos_ConfigParameters_s;


/*******************************************************************************
 Interface variables  
 *******************************************************************************/
extern tmcPos_ConfigParameters_s  mcPosI_ConfigParameters_gas[POSITION_CONTROL_INSTANCES];

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
tStd_ReturnType_e  mcPosI_PositionRegulationInit( const tmcPos_ConfigParameters_s * const speParam );

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
void mcPosI_PositionRegulationRun( const tmcPos_InstanceId_e Id );


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
void mcPosI_PositionControlOutputSet( uint8_t Id, float value );

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
void mcPosI_PositionControlIntegralSet( uint8_t Id, float value );

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
void mcPosI_PositionRegulationReset( const tmcPos_InstanceId_e Id );


#endif    /* MCPOS_H */
