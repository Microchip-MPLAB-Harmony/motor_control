/*******************************************************************************
 Motor Control FlyingStart interface file

  Company:
    Microchip Technology Inc.

  File Name:
    mc_flyingstart.h

  Summary:
    Motor control FlyingStart interface

  Description:
    This file contains the data structures and function prototypes of motor control flying start technique.
 *******************************************************************************/
/* ************************************************************************** */

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2020 Microchip Technology Inc. and its subsidiaries.
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

#ifndef _MC_FLYING_START_H    /* Guard against multiple inclusion */
#define _MC_FLYING_START_H


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

/* This section lists the other files that are included in this file.
 */

#include <stdbool.h>
#include <stdint.h>
#include <math.h>
#include "mc_derivedparams.h"
#include "mc_pmsm_foc_common.h"
#include "mc_userparams.h"
#include "mc_pwm.h"
#include "mc_picontrol.h"
#include "mc_speed.h"
#include "mc_rotorposition.h"
#include "mc_lib.h"


/* Provide C++ Compatibility */
#ifdef __cplusplus
extern "C" {
#endif
    
/*_______________________________  FLYING START ______________________________________________________*/
#define FLYING_START_TIME_COUNT                           (uint32_t)(FLYING_START_TIME_SEC / FAST_LOOP_TIME_SEC) 
#define MIN_FLYING_START_SPEED_RAD_PER_SEC_ELEC           (float)(((MIN_FLYING_START_SPEED_RPM/60)*2*(float)M_PI)*NUM_POLE_PAIRS)
<#if MCPMSMFOC_FLYING_START_REGENERATIVE_BRAKING_ENABLE>
#define REGENERATIVE_BRAKING_CURRENT_STEP                (float)(REGENERATIVE_BRAKING_CURRRENT_A/(REGENERATIVE_BRAKE_CURRENT_RAMP_TIME_SEC*PWM_FREQUENCY))
</#if>
#define NULL_BRAKE_TIME_COUNT                            (uint32_t)((float)(NULL_BRAKE_TIME_SEC*PWM_FREQUENCY))
#define NULL_BRAKE_BURST_COUNT                           (uint32_t)(NULL_BRAKE_TIME_COUNT/100)          
    
/******************************************************************************/
/* FlyingStart Mode PI controllers tuning values - */

/********* FlyingStart Mode D Control Loop Coefficients ****************************************/
#define     FLYING_START_D_CURRCNTR_PTERM           (float)(0.2)
#define     FLYING_START_D_CURRCNTR_ITERM           (float)(0.00099)
#define     FLYING_START_D_CURRCNTR_CTERM           (float)(0.5)

/******** FlyingStart Mode Q Control Loop Coefficients ****************************************/
#define     FLYING_START_Q_CURRCNTR_PTERM           (float)(0.2)
#define     FLYING_START_Q_CURRCNTR_ITERM           (float)(0.00099)
#define     FLYING_START_Q_CURRCNTR_CTERM           (float)(0.5)
       
// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************

 typedef struct
 {
    uint8_t     MCAPP_IDLE_State;
    uint8_t     MCAPP_FLYING_START_State;
    uint8_t     MCAPP_FLYING_START_DECIDE_State;        
    uint8_t     MCAPP_PASSIVE_BRAKE_State;
    uint8_t     MCAPP_FIELD_ALIGNMENT_State;
    uint8_t     MCAPP_OPEN_LOOP_State;
    uint8_t     MCAPP_CLOSING_LOOP_State;
    uint8_t     MCAPP_CLOSED_LOOP_State;
    uint8_t     MCAPP_ACTIVE_BRAKE_State;
    uint8_t     count;
             
 }tMCCTRL_STATE;
 
 typedef enum
{
    MC_FLYING_START_IN_PROGRESS,
    MC_FLYING_START_DETECTED,
    MC_FLYING_START_NOT_DETECTED
}tMC_FLYING_START_STATUS_E;

typedef enum
{
    MC_FLYING_START_DETECT,
    MC_FLYING_START_DECIDE,        
    MC_FLYING_START_PASSIVE_BRAKE,
    MC_FLYING_START_COMPLETED
}tMCCTRL_FLYING_START_CONTROL_STATE_E;

typedef struct
{
    uint32_t                                flying_startTimeCounter;
    uint32_t                                flying_startTimeCount;
    float                                   minFlyingStartSpeed;
    uint32_t                                passiveBrakeTimeCounter;
    bool                                    regenBrakeEnable;
    float                                   flying_startStartCurrent;
    float                                   regenBrakeCurrent;
    float                                   regenBrakeCurrentStep;
    uint32_t                                nullVectorBrakeTimeCount;
    uint32_t                                nullVectorBurstCount;
    uint32_t                                nullVectorBurstHalfCount;    
    tMCCTRL_FLYING_START_CONTROL_STATE_E     mcFlyingStartState;
}tMCCTRL_FLYING_START_STATE_SIGNALS_S;

 tMCCTRL_FLYING_START_STATE_SIGNALS_S     gMCCTRL_FlyingStartStateSignals;
/*****************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Interface Routines
// *****************************************************************************
// *****************************************************************************

tMC_FLYING_START_STATUS_E MCCTRL_FlyingStartControl( void );

/*****************************************************************************/ 
/* Function name: MCCTRL_InitilaizeFlyingStartControl                        */
/* Function parameters: None                                                 */
/* Function return: None                                                     */
/* Description: Initialize FlyingStart parameters and state                  */
/*****************************************************************************/

static __inline__ void MCCTRL_InitializeFlyingStartControl( void )
{
    /* Initialize FlyingStart parameters */
    gMCCTRL_FlyingStartStateSignals.flying_startTimeCounter = 0u;
    gMCCTRL_FlyingStartStateSignals.passiveBrakeTimeCounter = 0u;
    gMCCTRL_FlyingStartStateSignals.flying_startTimeCount = FLYING_START_TIME_COUNT;
    gMCCTRL_FlyingStartStateSignals.minFlyingStartSpeed = MIN_FLYING_START_SPEED_RAD_PER_SEC_ELEC;
    gMCCTRL_FlyingStartStateSignals.nullVectorBrakeTimeCount = NULL_BRAKE_TIME_COUNT;
    gMCCTRL_FlyingStartStateSignals.nullVectorBurstCount = NULL_BRAKE_BURST_COUNT;
    gMCCTRL_FlyingStartStateSignals.nullVectorBurstHalfCount = NULL_BRAKE_BURST_COUNT>>1;    
    gMCCTRL_FlyingStartStateSignals.flying_startStartCurrent = FLYING_START_START_CURRRENT_A;
    <#if MCPMSMFOC_FLYING_START_REGENERATIVE_BRAKING_ENABLE>
    gMCCTRL_FlyingStartStateSignals.regenBrakeEnable = true;
    gMCCTRL_FlyingStartStateSignals.regenBrakeCurrent = REGENERATIVE_BRAKING_CURRRENT_A;
    gMCCTRL_FlyingStartStateSignals.regenBrakeCurrentStep = REGENERATIVE_BRAKING_CURRENT_STEP;
    <#else>
    gMCCTRL_FlyingStartStateSignals.regenBrakeEnable = false;
    gMCCTRL_FlyingStartStateSignals.regenBrakeCurrent = 0;
    gMCCTRL_FlyingStartStateSignals.regenBrakeCurrentStep = 0;
    </#if>
    gMCCTRL_FlyingStartStateSignals.mcFlyingStartState = MC_FLYING_START_DETECT;
    
    gMCLIB_IdPIController.kp = FLYING_START_D_CURRCNTR_PTERM;
    gMCLIB_IdPIController.ki = FLYING_START_D_CURRCNTR_ITERM;
    gMCLIB_IdPIController.kc = FLYING_START_D_CURRCNTR_CTERM;
    
    gMCLIB_IqPIController.kp = FLYING_START_Q_CURRCNTR_PTERM;
    gMCLIB_IqPIController.ki = FLYING_START_Q_CURRCNTR_ITERM;
    gMCLIB_IqPIController.kc = FLYING_START_Q_CURRCNTR_CTERM;
            
    gMCPWM_SVPWM.enableSVPWM = 1;
}

/*****************************************************************************/
/* Function name: MCCTRL_ResetFlyingStartControl                             */
/* Function parameters: None                                                 */
/* Function return: None                                                     */
/* Description: Reset FlyingStart parameters                                 */
/*****************************************************************************/
static __inline__ void MCCTRL_ResetFlyingStartControl( void )
{
    /* Reset FlyingStart state */
    gMCCTRL_FlyingStartStateSignals.flying_startTimeCounter = 0u;
    gMCCTRL_FlyingStartStateSignals.passiveBrakeTimeCounter = 0u;
    gMCPWM_SVPWM.enableSVPWM = 1;
    gMCCTRL_FlyingStartStateSignals.mcFlyingStartState = MC_FLYING_START_DETECT;

    gMCLIB_IdPIController.kp = FLYING_START_D_CURRCNTR_PTERM;
    gMCLIB_IdPIController.ki = FLYING_START_D_CURRCNTR_ITERM;
    gMCLIB_IdPIController.kc = FLYING_START_D_CURRCNTR_CTERM;
    
    gMCLIB_IqPIController.kp = FLYING_START_Q_CURRCNTR_PTERM;
    gMCLIB_IqPIController.ki = FLYING_START_Q_CURRCNTR_ITERM;
    gMCLIB_IqPIController.kc = FLYING_START_Q_CURRCNTR_CTERM;
}

/*****************************************************************************/
/* Function name: MCCTRL_InitializeRunModeCurrentPIControlParam              */
/* Function parameters: None                                                 */
/* Function return: None                                                     */
/* Description: Initialize Run mode Current PI Controller parameters         */
/*****************************************************************************/

static __inline__ void MCCTRL_InitializeRunModeCurrentPIControlParam(void)
{
    gMCLIB_IdPIController.kp = D_CURRCNTR_PTERM;
    gMCLIB_IdPIController.ki = D_CURRCNTR_ITERM;
    gMCLIB_IdPIController.kc = D_CURRCNTR_CTERM;

    gMCLIB_IqPIController.kp = Q_CURRCNTR_PTERM;
    gMCLIB_IqPIController.ki = Q_CURRCNTR_ITERM;
    gMCLIB_IqPIController.kc = Q_CURRCNTR_CTERM; 
}

    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _MC_FLYING_START_H */


