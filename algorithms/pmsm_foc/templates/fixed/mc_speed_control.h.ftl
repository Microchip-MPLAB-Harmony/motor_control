/*******************************************************************************
  System Definitions

  File Name:
    mc_speed_control.h

  Summary:
    Header file which contains variables and function prototypes for motor speed control.

  Description:
    This file contains variables and function prototypes which are generally used for motor
     speed control. It is implemented in Q2.14 fixed Point Arithmetic.

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

#ifndef MCSPE_H
#define MCSPE_H

#include <stdint.h>
#include <stdlib.h>
#include <sys/attribs.h>
#include "mc_generic_library.h"
#include "mc_error_handler.h"
#include "mc_userparams.h"
#include "mc_ramp_profiler.h"

/*******************************************************************************
 * Macros
*******************************************************************************/
/**
 */

#define MAXIMUM_SPEED_FROM_POT_IN_RPM  RATED_SPEED_IN_RPM


/**
 *  Potentiometer first order filter parameter ( 0.0 -  1.0 )
 */
#define POTENTIOMETER_FILTER_PARAMETER    (float)( 0.05f )

/*******************************************************************************
 Default Module configuration parameters 
*******************************************************************************/
#define SPEED_CONTROL_MODULE_CONFIG {\
    /* Instance Id */\
    0u, \
    /* Input ports */ \
    {\
        &mcHalI_Potentiometer_gdu16, \
        &mcSpeI_ReferenceElectricalSpeed_gds16, \
        &mcRpoI_ElectricalRotorSpeed_gds16, \
        &mcMocI_RotationSign_gds8 \
    },\
    /* Output ports */ \
    {\
        &mcSpeI_ReferenceIqCurrent_gds16, \
        &mcSpeI_ReferenceElectricalSpeed_gds16 \
    }, \
    /* User Parameters */ \
    { \
         /* Speed PI controller parameters */ \
        {\
            /* Proportional gain */\
            SPEED_KP, \
           \
            /* Integral gain */\
            SPEED_KI, \
           \
            /* Anti-windup back calculation gain */\
            SPEED_YMAX \
        },        \
        0.0005f,   \
        MINIMUM_SPEED_IN_RPM,   \
        MAXIMUM_SPEED_FROM_POT_IN_RPM,  \
        TORQUE_MODE_MAXIMUM_CURRENT \
    }\
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

typedef struct _tmcSpe_RampProfiler_s
{
    float newSpeed;
    float filtSpeed;
    float filtParam;
}tmcSpe_RampProfiler_s;


typedef struct _tmcSpe_InputPorts_s 
{
    volatile uint16_t * potReading;
    volatile int16_t * referenceSpeed;
    volatile int16_t * actualSpeed;
    volatile int8_t * rotationSign;
}tmcSpe_InputPorts_s;

typedef struct _tmcSpe_OutputPorts_s
{
    int16_t * iqref;
    int16_t *  referenceSpeed;
}tmcSpe_OutputPorts_s;



typedef struct tmcSpe_PiController_s
{   
    /* Proportional gain */
    float Kp;
    
    /* Integral gain */
    float Ki;
            
    /* Positive saturation limit */
    float Ymax;
        
}tmcSpe_PiController_s;


typedef struct _tmcSpe_UserParameters_s
{
    tmcSpe_PiController_s    speedController;
    float speedFilterParam;
    float minReferenceSpeed;
    float maxReferenceSpeed;
    float maxTorqueCurrent;
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
extern tmcSpe_ConfigParameters_s  mcSpeI_ConfigParameters_gds;


/*******************************************************************************
 * Interface Functions
*******************************************************************************/

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
void  mcSpeI_SpeedRegulationInit( const tmcSpe_ConfigParameters_s * const speParam );

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
#ifdef RAM_EXECUTE
void __ramfunc__ mcSpeI_SpeedRegulationRun( const tmcSpe_InstanceId_e Id );
#else
void mcSpeI_SpeedRegulationRun( const tmcSpe_InstanceId_e Id );
#endif


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

/*! \brief Speed PI controller integral setting 
 * 
 * Details.
 * Speed PI controller integral setting 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */ 
void mcSpeI_SpeedControlIntegralSet( uint8_t Id  );

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


#endif // _MCSPE_H
