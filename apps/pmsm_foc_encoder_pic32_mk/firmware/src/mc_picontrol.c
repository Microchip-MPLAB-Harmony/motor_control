/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
     mc_picontrol.c

  Summary:
   This file contains functions for motor current control. 

  Description:
    This file contains functions for motor current control. 

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
#ifndef MCCON_C
#define MCCON_C
#include "mc_picontrol.h"
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
tMCCON_PICONTROLLER_S                gMCCON_IqController;           /* Iq PI controllers */
tMCCON_PICONTROLLER_S                gMCCON_IdController;           /* Id PI controllers */
tMCCON_PICONTROLLER_S                gMCCON_SpeedController;        /* Speed PI controllers */

/******************************************************************************/
/* Function name: MCAPP_InitializePIParameters                                */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description:                                                               */
/* Initialize control parameters: PI coefficients for D,Q and                 */
/* Velocity control loop.                                                     */
/******************************************************************************/
void MCCON_InitializePIParameters(void)
{
    /**************** PI D Term ***********************************************/
    gMCCON_IdController.kp = D_CURRCNTR_PTERM;
    gMCCON_IdController.ki = D_CURRCNTR_ITERM;
    gMCCON_IdController.kc = D_CURRCNTR_CTERM;
    gMCCON_IdController.outMax = D_CURRCNTR_OUTMAX;
    gMCCON_IdController.outMin = -gMCCON_IdController.outMax;
    gMCCON_IdController.dSum = 0;
    gMCCON_IdController.out = 0;

    /**************** PI Q Term ************************************************/
    gMCCON_IqController.kp = Q_CURRCNTR_PTERM;
    gMCCON_IqController.ki = Q_CURRCNTR_ITERM;
    gMCCON_IqController.kc = Q_CURRCNTR_CTERM;
    gMCCON_IqController.outMax = Q_CURRCNTR_OUTMAX;
    gMCCON_IqController.outMin = -gMCCON_IqController.outMax;
    gMCCON_IqController.dSum = 0;
    gMCCON_IqController.out = 0;

    /**************** PI Velocity Control **************************************/
    gMCCON_SpeedController.kp = SPEEDCNTR_PTERM;
    gMCCON_SpeedController.ki = SPEEDCNTR_ITERM;
    gMCCON_SpeedController.kc = SPEEDCNTR_CTERM;
    gMCCON_SpeedController.outMax = SPEEDCNTR_OUTMAX;
    gMCCON_SpeedController.outMin = -gMCCON_SpeedController.outMax;
    gMCCON_SpeedController.dSum = 0;
    gMCCON_SpeedController.out = 0;
}

/******************************************************************************/
/* Function name: MCCON_PIControl                                             */
/* Function parameters: pParm - PI parameter structure                        */
/* Function return: None                                                      */
/* Description: Execute PI control                                            */
/******************************************************************************/
void MCCON_PIControl( tMCCON_PICONTROLLER_S * const pParm)
{
    float Err;
    float Out;
    float Exc;

    Err  = pParm->inRef - pParm->inMeas;
    Out  = pParm->dSum + pParm->kp * Err;

    /* Limit checking for PI output */
    if( Out > pParm->outMax )
    {
       pParm->out = pParm->outMax;
    }
    else if( Out < pParm->outMin )
    {
       pParm->out = pParm->outMin;
    }
    else
    {
       pParm->out = Out;
    }

    Exc = Out - pParm->out;
    pParm->dSum = pParm->dSum + pParm->ki * Err - pParm->kc * Exc;
}


/******************************************************************************/
/* Function name: MCAPP_ResetPIParameters                                     */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description:                                                               */
/* Reset control parameters                                                   */
/******************************************************************************/
void MCCON_ResetPIParameters(void)
{
    /**************** PI D Term ***********************************************/
    gMCCON_IdController.dSum = 0;
    gMCCON_IdController.out = 0;

    /**************** PI Q Term ************************************************/
    gMCCON_IqController.dSum = 0;
    gMCCON_IqController.out = 0;

    /**************** PI Velocity Control **************************************/
    gMCCON_SpeedController.dSum = 0;
    gMCCON_SpeedController.out = 0;
}

#endif
#endif

