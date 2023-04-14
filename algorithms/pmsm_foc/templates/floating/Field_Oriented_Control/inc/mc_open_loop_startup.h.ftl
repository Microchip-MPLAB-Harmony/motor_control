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
#include "mc_motor.h"
<#if MCPMSMFOC_POSITION_CALC_ALGORITHM == 'SENSORED_ENCODER'>
#include "mc_hardware_abstraction.h"
</#if>

/*******************************************************************************
 Default Module configuration parameters 
*******************************************************************************/
/*******************************************************************************
 Parameters
 *******************************************************************************/

/*******************************************************************************
 Default module parameters
 *******************************************************************************/

/*******************************************************************************
 User defined data-types
 *******************************************************************************/
typedef struct
{
    tmcMot_PMSM_s * pMotorParameters;
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
    pParameters->pMotorParameters = &mcMotI_PMSM_gds;
    pParameters->dt = (float32_t)(${MCPMSMFOC_PWM_PERIOD});
    pParameters->alignmentTime = (float32_t)(${MCPMSMFOC_STARTUP_TIME});
    pParameters->alignmentCurrent = (float32_t)(${MCPMSMFOC_STARTUP_CURRENT});
    pParameters->openLoopCurrent = (float32_t)(${MCPMSMFOC_STARTUP_CURRENT});
    pParameters->openLoopRampTime = (float32_t)(${MCPMSMFOC_OPEN_LOOP_RAMP_TIME});
    pParameters->openLoopStabTime = (float32_t)(${MCPMSMFOC_OPEN_LOOP_STAB_TIME});
    pParameters->openLoopTransSpeed = (float32_t)(${MCPMSMFOC_OPEN_LOOP_END_SPEED});
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
tmcTypes_StdReturn_e mcSupI_OpenLoopStartup( const tmcSup_Parameters_s * const pParameters,
                                          float32_t direction, float32_t * const pIQref,
                                          float32_t * const pIDref, float32_t * const pAngle,
                                          float32_t * const pSpeed );

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
