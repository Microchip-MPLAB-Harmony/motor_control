/*******************************************************************************
  Space Vector PWM Source File

  Company:
    Microchip Technology Inc.

  File Name:
    mc_pwm.c

  Summary:
    This file contains functions for Space Vector PWM generation.

  Description:
    This file contains functions for Space Vector PWM generation.

 *******************************************************************************/

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

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include "definitions.h"                // SYS function prototypes
#include "device.h"
#include "mc_derivedparams.h"
#include "mc_hal.h"
#include "mc_pwm.h"
#include "mc_lib.h"
#include "mc_generic_lib.h"
#include "math.h"
#include "assert.h"

// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************

/******************************************************************************/
/* Local Function Prototype                                                   */
/******************************************************************************/

__STATIC_INLINE void MCPWM_SVPWMTimeCalc(tMCPWM_SVPWM_S* svm);

/******************************************************************************/
/*                   Global Variables                                         */
/******************************************************************************/
tMCPWM_SVPWM_S    gMCPWM_SVPWM = {0.0f};


/******************************************************************************/
/*                          LOCAL FUNCTIONS                                   */
/******************************************************************************/
__STATIC_INLINE void MCPWM_SVPWMTimeCalc(tMCPWM_SVPWM_S * const svm)
{
    svm->t1 = (svm->period) * svm->t1;
    svm->t2 = (svm->period) * svm->t2;
    svm->tc = (svm->period - svm->t1 - svm->t2)/2;
    svm->tb = svm->tc + svm->t2;
    svm->ta = svm->tb + svm->t1;
}

/******************************************************************************/
/*                      INTERFACE FUNCTIONS                                   */
/******************************************************************************/

/******************************************************************************/
/* Function name: MCPWM_SVPWMGen                                              */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description: Determines sector based upon three reference                  */
/*              vectors amplitude and updates duty.                           */
/******************************************************************************/
void MCPWM_SVPWMGen( const tMCLIB_CLARK_TRANSFORM_S * const vAlphaBeta, tMCPWM_SVPWM_S * const svm )
{
    svm->vr1 = vAlphaBeta->betaAxis;
    svm->vr2 = (-vAlphaBeta->betaAxis/2 + SQRT3_BY2 * vAlphaBeta->alphaAxis);
    svm->vr3 = (-vAlphaBeta->betaAxis/2 - SQRT3_BY2 * vAlphaBeta->alphaAxis);

      if( svm->vr1 >= 0 )
      {
            // (xx1)
            if( svm->vr2 >= 0 )
            {
                  // (x11)
                  // Must be Sector 3 since Sector 7 not allowed
                  // Sector 3: (0,1,1)  0-60 degrees
                  svm->t1 = svm->vr2;
                  svm->t2 = svm->vr1;
                  MCPWM_SVPWMTimeCalc(svm);
                  svm->dPwm1 = (uint32_t)svm->ta;
                  svm->dPwm2 = (uint32_t)svm->tb;
                  svm->dPwm3 = (uint32_t)svm->tc;
            }
            else
            {
                  // (x01)
                  if( svm->vr3 >= 0 )
                  {
                        // Sector 5: (1,0,1)  120-180 degrees
                        svm->t1 = svm->vr1;
                        svm->t2 = svm->vr3;
                        MCPWM_SVPWMTimeCalc(svm);
                        svm->dPwm1 = (uint32_t)svm->tc;
                        svm->dPwm2 = (uint32_t)svm->ta;
                        svm->dPwm3 = (uint32_t)svm->tb;
                  }
                  else
                  {
                        // Sector 1: (0,0,1)  60-120 degrees
                        svm->t1 = -svm->vr2;
                        svm->t2 = -svm->vr3;
                        MCPWM_SVPWMTimeCalc(svm);
                        svm->dPwm1 = (uint32_t)svm->tb;
                        svm->dPwm2 = (uint32_t)svm->ta;
                        svm->dPwm3 = (uint32_t)svm->tc;
                  }
           }
      }
      else
      {
            // (xx0)
            if( svm->vr2 >= 0 )
            {
                  // (x10)
                  if( svm->vr3 >= 0 )
                  {
                        // Sector 6: (1,1,0)  240-300 degrees
                        svm->t1 = svm->vr3;
                        svm->t2 = svm->vr2;
                        MCPWM_SVPWMTimeCalc(svm);
                        svm->dPwm1 = (uint32_t)svm->tb;
                        svm->dPwm2 = (uint32_t)svm->tc;
                        svm->dPwm3 = (uint32_t)svm->ta;
                  }
                  else
                  {
                        // Sector 2: (0,1,0)  300-0 degrees
                        svm->t1 = -svm->vr3;
                        svm->t2 = -svm->vr1;
                        MCPWM_SVPWMTimeCalc(svm);
                        svm->dPwm1 = (uint32_t)svm->ta;
                        svm->dPwm2 = (uint32_t)svm->tc;
                        svm->dPwm3 = (uint32_t)svm->tb;
                  }
            }
            else
            {
                  // (x00)
                  // Must be Sector 4 since Sector 0 not allowed
                  // Sector 4: (1,0,0)  180-240 degrees
                  svm->t1 = -svm->vr1;
                  svm->t2 = -svm->vr2;
                  MCPWM_SVPWMTimeCalc(svm);
                  svm->dPwm1 = (uint32_t)svm->tc;
                  svm->dPwm2 = (uint32_t)svm->tb;
                  svm->dPwm3 = (uint32_t)svm->ta;
            }
      }
}

/******************************************************************************/
/* Function name: MCPWM_PWMModulator                                          */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description: PWM Modulator                                                 */
/******************************************************************************/
void MCPWM_PWMModulator( void )
{
    /* Calculate and set PWM duty cycles from Vr1,Vr2,Vr3 */
    MCPWM_SVPWMGen(&gMCLIB_VoltageAlphaBeta, &gMCPWM_SVPWM);
    MCPWM_PWMDutyUpdate(&gMCPWM_SVPWM);
}

/*****************************************************************************/
/* Function name: MCPWM_PWMOutputDisable                                        */
/* Function parameters: None                                                 */
/* Function return: None                                                     */
/* Description:                                                              */
/* Disable three phase PWM outputs                                           */
/*****************************************************************************/
void MCPWM_PWMOutputDisable(void)
{
    MCHAL_PWMOutputDisable(MCHAL_PWM_PH_U);
    MCHAL_PWMOutputDisable(MCHAL_PWM_PH_V);
    MCHAL_PWMOutputDisable(MCHAL_PWM_PH_W);
}

/*****************************************************************************/
/* Function name: MCPWM_PWMOutputEnable                                        */
/* Function parameters: None                                                 */
/* Function return: None                                                     */
/* Description:                                                              */
/* Enable three phase PWM outputs                                           */
/*****************************************************************************/
void MCPWM_PWMOutputEnable(void)
{
    MCHAL_PWMOutputEnable(MCHAL_PWM_PH_U);
    MCHAL_PWMOutputEnable(MCHAL_PWM_PH_V);
    MCHAL_PWMOutputEnable(MCHAL_PWM_PH_W);
}

/*****************************************************************************/
/* Function name: MCPWM_PWMDutyUpdate                                        */
/* Function parameters: None                                                 */
/* Function return: None                                                     */
/* Description:                                                              */
/* interface to update duty ratio in PWM timers                              */
/*****************************************************************************/
void MCPWM_PWMDutyUpdate(tMCPWM_SVPWM_S * const svm)
{
    MCHAL_PWMDutySet(MCHAL_PWM_PH_U, svm->dPwm1);
    MCHAL_PWMDutySet(MCHAL_PWM_PH_V, svm->dPwm2);
    MCHAL_PWMDutySet(MCHAL_PWM_PH_W, svm->dPwm3);
}
