/*******************************************************************************
  System Definitions

  File Name:
    mc_pwm.h

  Summary:
    Header file which contains variables and function prototypes for open loop start-up
 
  Description:
    This file contains variables and function prototypes which are generally used for open loop start-up.

 *******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2022 Microchip Technology Inc. and its subsidiaries.
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
 * Header inclusions 
*******************************************************************************/
#include "mc_types.h"
#include "mc_utilities.h"
#include "mc_userparams.h"

/*******************************************************************************
 Default Module configuration parameters 
*******************************************************************************/
/*******************************************************************************
 Parameters
 *******************************************************************************/
/**
 * Start-up algorithm cycle time
 */
#ifdef CONFIG_SamplingTimeInSec
#undef CONFIG_SamplingTimeInSec
#endif
#define CONFIG_SamplingTimeInSec  (float32_t)( 1.0f / (float32_t)PWM_FREQUENCY )

/**
 * Alignment lock time
 */
#define  CONFIG_StartupLockTimeInSec   (float32_t)START_UP_LOCK_TIME_IN_SECOND

/**
 * Alignment time in Ampere
 */
#define  CONFIG_LockCurrentInAmp  (float32_t)START_UP_CURRENT_IN_AMPERE

/**
 * Start-up time in Ampere
 */
#define  CONFIG_StartupCurrentInAmp  (float32_t)START_UP_CURRENT_IN_AMPERE

/**
 * Open loop ramp time in seconds
 */

#define CONFIG_StartupRampTimeInSec  (float32_t)START_UP_RAMP_TIME_IN_SECOND

/**
 * Open loop stabilization time in seconds
 */
#define CONFIG_StartupStabTimeInSec  (float32_t)START_UP_STAB_TIME_IN_SECOND

/**
 * Open loop transition speed in RPM
 */
#define CONFIG_StartupThresholdSpeedInRpm  (float32_t)( 500.0f )

/*******************************************************************************
 Default module parameters
 *******************************************************************************/

/*******************************************************************************
 User defined data-types
 *******************************************************************************/
typedef struct
{
    float32_t alignmentTime;
    float32_t alignmentCurrent;
    float32_t openLoopCurrent;
    float32_t openLoopRampTime;
    float32_t openLoopStabTime;
    float32_t openLoopTransSpeed;
    float32_t dt;
    void * pStatePointer;
}tmcSup_Parameters_s;

/*******************************************************************************
 Static interface functions
 *******************************************************************************/
__STATIC_INLINE void mcSupI_ParametersSet( tmcSup_Parameters_s * const pParameters )
{
    pParameters->dt = CONFIG_SamplingTimeInSec;
    pParameters->alignmentTime = CONFIG_StartupLockTimeInSec;
    pParameters->alignmentCurrent =  CONFIG_LockCurrentInAmp;
    pParameters->openLoopCurrent = CONFIG_StartupCurrentInAmp;
    pParameters->openLoopRampTime = CONFIG_StartupRampTimeInSec;
    pParameters->openLoopStabTime = CONFIG_StartupStabTimeInSec;
    pParameters->openLoopTransSpeed = CONFIG_StartupThresholdSpeedInRpm;
}

/*******************************************************************************
 * Interface variables 
*******************************************************************************/

/*******************************************************************************
 Interface Functions 
*******************************************************************************/

/*! \brief Initialize open loop start-up module
 *
 * Details.
 * Initialize open loop start-up module
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
void  mcSupI_OpenLoopStartupInit( tmcSup_Parameters_s * const pParameters );

/*! \brief Enable open loop start-up module
 *
 * Details.
 * Enable open loop start-up module
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
void  mcSupI_OpenLoopStartupEnable( tmcSup_Parameters_s * const pParameters );

/*! \brief Disable open loop start-up module
 *
 * Details.
 * Disable open loop start-up module
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
void  mcSupI_OpenLoopStartupDisable( tmcSup_Parameters_s * const pParameters );

/*! \brief Open loop start-up
 *
 * Details.
 * Open loop start-up
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
#ifdef RAM_EXECUTE
tmcTypes_StdReturn_e __ramfunc__  mcSupI_OpenLoopStartup( const tmcSup_Parameters_s * const pParameters,
                                                                        int16_t direction, int16_t * const pIQref,
                                                                        int16_t * const pIDref, uint16_t * const pAngle,
                                                                        int16_t * const pSpeed );
#else
tmcTypes_StdReturn_e mcSupI_OpenLoopStartup(  const tmcSup_Parameters_s * const pParameters,
                                                  int16_t direction, int16_t * const pIQref,
                                                  int16_t * const pIDref, uint16_t * const pAngle ,
                                                  int16_t * const pSpeed );
#endif

/*! \brief Reset Open loop start-up
 *
 * Details.
 * Reset Open loop start-up
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return:
 */
void mcSupI_OpenLoopStartupReset( const tmcSup_Parameters_s * const pParameters );

#endif // MCSUP_H
