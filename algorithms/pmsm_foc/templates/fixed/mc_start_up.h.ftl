/*******************************************************************************
  System Definitions

  File Name:
    mc_start_up.h

  Summary:
    Header file which shares global variables and function prototypes.

  Description:
    This file contains the global variables and function prototypes for PMSM motor start up.
     Implemented in Q2.14 format..

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

#ifndef MCSUP_H
#define MCSUP_H

/*******************************************************************************
Headers inclusions
*******************************************************************************/
#include <stdint.h>
#include <stdlib.h>
#include <sys/attribs.h>
#include "mc_error_handler.h"
#include "mc_userparams.h"
#include "mc_generic_library.h"


/*******************************************************************************
 Default Module configuration parameters 
*******************************************************************************/
#define START_UP_MODULE_CONFIG {\
    /* Instance Id */\
    0,\
    /* Output ports */\
    {\
        &mcSpeI_ReferenceIdCurrent_gds16,  \
        &mcSpeI_ReferenceIqCurrent_gds16,  \
        &mcMocI_SpaceVectorPosition_gdu16  \
    },\
    /* User parameters */ \
    {\
        /* Alignment time in seconds */ \
        START_UP_LOCK_TIME_IN_SECOND, \
        \
        /* Alignment current in Amperes */\
        START_UP_CURRENT_IN_AMPERE,\
         \
        /* Open loop Current in Amperes */\
        START_UP_CURRENT_IN_AMPERE, \
         \
        /* Open loop ramp time in seconds */ \
        START_UP_RAMP_TIME_IN_SECOND,\
         \
        /* Open loop stabilization time in seconds  */\
        START_UP_STAB_TIME_IN_SECOND,\
         \
        /* Open loop transition speed in RPM */  \
         MINIMUM_SPEED_IN_RPM, \
         \
         /* Sampling time */\
         CURRENT_CONTROL_SAMPLING_TIME \
    } \
}
         
/*******************************************************************************
 Module data-types
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
    int16_t * Idref;
    int16_t * Iqref;
    uint16_t * theta;
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
extern tmcSup_ConfigParameters_s mcSupI_ConfigurationParameters_gds;

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
void mcSupI_OpenLoopStartupInit( tmcSup_ConfigParameters_s * supParam );

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

#endif //_MCSUP_H
