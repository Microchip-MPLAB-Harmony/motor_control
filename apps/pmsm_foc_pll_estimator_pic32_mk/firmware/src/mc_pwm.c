/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    mc_pwm.c

  Summary:
    This file contains functions to functions to control the PWM module.

  Description:
    This file contains functions to functions to control the PWM module.

 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
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

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include "definitions.h"                // SYS function prototypes
#include "device.h"
#include "userparams.h"
#if  ( defined ( USE_FILE_INLINING )  && defined  (  MCAPP_C  ) )  ||   ( !defined ( USE_FILE_INLINING )  )
#ifndef MCPWM_C
#define MCPWM_C
#include "mc_pwm.h"
#include "math.h"
#include "assert.h"

// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************

/* Motor phase current offset calibration limits. */

/******************************************************************************/
/* Local Function Prototype                                                   */
/******************************************************************************/

/******************************************************************************/
/*                   Global Variables                                         */
/******************************************************************************/



/******************************************************************************/
/* Function name: MCPWM_PWMModulator                                          */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description: PWM Modulator                                                 */
/******************************************************************************/
void MCPWM_PWMModulator( void )
{
    /* Calculate qSin,qCos from qAngle  */
    MCLIB_SinCosCalc(&gMCLIB_Position );

    /* Calculate qValpha, qVbeta from qSin,qCos,qVd,qVq */
    MCLIB_InvParkTransform(&gMCLIB_VoltageDQ, &gMCLIB_Position, &gMCLIB_VoltageAlphaBeta);

    /* Calculate and set PWM duty cycles from Vr1,Vr2,Vr3 */
    MCLIB_SVPWMGen(&gMCLIB_VoltageAlphaBeta, &gMCLIB_SVPWM);
    MCPWM_PWMDutyUpdate(gMCLIB_SVPWM.dPWM1, gMCLIB_SVPWM.dPWM2, gMCLIB_SVPWM.dPWM3);
}

/*****************************************************************************/
/* Function name: MCPWM_PWMDutyUpdate                                        */
/* Function parameters: None                                                 */
/* Function return: None                                                     */
/* Description:                                                              */
/* interface to update duty ratio in PWM timers                              */
/*****************************************************************************/
INLINE_FUNCTION void MCPWM_PWMDutyUpdate(uint16_t duty_PhU, uint16_t duty_PhV, uint16_t duty_PhW)
{
    MCPWM_ChannelPrimaryDutySet(MCPWM_CH_1, duty_PhU);
    MCPWM_ChannelPrimaryDutySet(MCPWM_CH_2, duty_PhV);
    MCPWM_ChannelPrimaryDutySet(MCPWM_CH_3, duty_PhW);
}

/*****************************************************************************/
/* Function name: MCPWM_AdjustDutyRatio                                      */
/* Function parameters: None                                                 */
/* Function return: None                                                     */
/* Description:                                                              */
/* modifies PWM duty  ratio for current measurement. In case of dual         */
/* shunt measurement, it limits PWM ratios, while in case of single          */
/* shunt measurement it re-adjusts PWM                                       */
/*****************************************************************************/
INLINE_FUNCTION void MCPWM_AdjustDutyRatio( void )
{
    /* Function to be developed */
}

/*****************************************************************************/
/* Function name: MCPWM_DeadTimeCompensation                                 */
/* Function parameters: None                                                 */
/* Function return: None                                                     */
/* Description:                                                              */
/* modifies PWM duty  ratio for dead time compensation                       */
/*****************************************************************************/
INLINE_FUNCTION void MCPWM_DeadTimeCompensation( void )
{
    /* Function to be developed */
}

#endif
#endif
