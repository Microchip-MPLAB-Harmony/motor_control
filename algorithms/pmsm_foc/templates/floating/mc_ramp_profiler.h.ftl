/*******************************************************************************
  System Definitions

  File Name:
    mc_ramp_profiler.h

  Summary:
    Header file which contains variables and function prototypes for angle and speed estimation
    with  PLL observer 
 
  Description:
    This file contains variables and function prototypes which are generally used for angle and 
    speed estimation with PLL observer .  Implemented in Q2.14 Fixed
     Point Arithmetic.
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

#ifndef MCRMP_H
#define MCRMP_H

#include <stdint.h>
#include <sys/attribs.h>
#include "mc_generic_library.h"
#include "mc_interface_handling.h"
#include "mc_userparams.h"

/*******************************************************************************
 * Configuration Parameters 
*******************************************************************************/
/**
 * Number of pole pairs  
 */
#define CONFIG_RmpNumberOfPolePairs    NUM_POLE_PAIRS

/**
 * Ramp profile type 
 */
#define CONFIG_RampProfileType        referenceProfile_Linear 

/**
 * Final Speed for Ramp Profiler 
 */
#define CONFIG_RampProfileRampPerSec   (float)(${MCPMSMFOC_RAMP_PROFILER_MAX_SPEED } )


/**
 * Default Speed for Ramp Profiler 
 */
#define CONFIG_RampProfileDefaultValue    (float)( ${MCPMSMFOC_OPEN_LOOP_END_SPEED }  )

/**
 * Ramp Profiler sampling time 
 */
#define CONFIG_RampProfilerSamplingTime      (float)( 1.0f / PWM_FREQUENCY )

/*******************************************************************************
 Default Module configuration parameters 
*******************************************************************************/
#define RAMP_PROFILER_MODULE_CONFIG_A {\
    CONFIG_RampProfileType, \
    CONFIG_RampProfileRampPerSec, \
    CONFIG_RampProfilerSamplingTime, \
    CONFIG_RampProfileDefaultValue, \
}

/*******************************************************************************
Type definitions
*******************************************************************************/

typedef enum _tmcRmp_ReferenceProfile_e
{
    referenceProfile_Step,
    referenceProfile_Linear,
    referenceProfile_Sigmoid
}tmcRmp_ReferenceProfile_e;
  
typedef struct _tmcRmp_ReferenceSpeed_s
{
    tmcRmp_ReferenceProfile_e profileType;
    float rampPerSec;
    float samplingTimeInSec;
    float defaultValue;
}tmcRmp_RampProfilerConfig_s;


/*******************************************************************************
 * Interface variables 
*******************************************************************************/
extern tmcRmp_RampProfilerConfig_s mcRmpI_RampProfilerConfig_mds;

/*******************************************************************************
 * Interface functions
*******************************************************************************/

/* !\brief Initialize ramp profiler
 * 
 * Details.
 * Initialize ramp profiler
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return: None
 */
void mcRmpI_ReferenceProfileInit( tmcRmp_RampProfilerConfig_s * rampProfile);

/* !\brief Set new input
 * 
 * Details.
 * Set new input
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return: None
 */
void mcRmpI_ReferenceProfileInputCommand( int16_t commandRpm);

/* !\brief Generate ramp profile
 * 
 * Details.
 * Set new input
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return: None
 */
int16_t mcRmpI_ReferenceProfileGenerate( void );

/* !\brief Reset ramp profiler
 * 
 * Details.
 * Reset ramp profiler
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return: None
 */

void mcRmpI_ReferenceProfileReset( void );

#endif // MCRMP_H
