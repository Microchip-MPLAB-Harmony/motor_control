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
MCCON_PI                gPIParmQ;          /* Iq PI controllers */
MCCON_PI                gPIParmD;           /* Id PI controllers */
MCCON_PI                gPIParmQref;     /* Speed PI controllers */

/******************************************************************************/
/* Function name: MCAPP_InitializePIParameters                                     */
/* Function parameters: None                                                                     */
/* Function return: None                                                                             */
/* Description:                                                                                             */
/* Initialize control parameters: PI coefficients for D,Q and                  */
/* Velocity control loop.                                                                               */
/******************************************************************************/
void MCCON_InitializePIParameters(void)
{
  	/**************** PI D Term ***********************************************/
  	gPIParmD.kp = D_CURRCNTR_PTERM;
  	gPIParmD.ki = D_CURRCNTR_ITERM;
  	gPIParmD.kc = D_CURRCNTR_CTERM;
  	gPIParmD.outMax = D_CURRCNTR_OUTMAX;
  	gPIParmD.outMin = -gPIParmD.outMax;
         gPIParmD.dSum = 0;
         gPIParmD.out = 0;

  	/**************** PI Q Term ************************************************/
  	gPIParmQ.kp = Q_CURRCNTR_PTERM;
  	gPIParmQ.ki = Q_CURRCNTR_ITERM;
  	gPIParmQ.kc = Q_CURRCNTR_CTERM;
  	gPIParmQ.outMax = Q_CURRCNTR_OUTMAX;
  	gPIParmQ.outMin = -gPIParmQ.outMax;
         gPIParmQ.dSum = 0;
         gPIParmQ.out = 0;

  	/**************** PI Velocity Control **************************************/
  	gPIParmQref.kp = SPEEDCNTR_PTERM;
  	gPIParmQref.ki = SPEEDCNTR_ITERM;
  	gPIParmQref.kc = SPEEDCNTR_CTERM;
  	gPIParmQref.outMax = SPEEDCNTR_OUTMAX;
  	gPIParmQref.outMin = -gPIParmQref.outMax;
         gPIParmQref.dSum = 0;
         gPIParmQref.out = 0;
}

/******************************************************************************/
/* Function name: MCCON_PIControl                                                         */
/* Function parameters: pParm - PI parameter structure                        */
/* Function return: None                                                                            */
/* Description: Execute PI control                                                            */
/******************************************************************************/
void MCCON_PIControl( MCCON_PI * const pParm)
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
/* Function name: MCAPP_ResetPIParameters                                          */
/* Function parameters: None                                                                     */
/* Function return: None                                                                             */
/* Description:                                                                                             */
/* Reset control parameters                                                                      */
/******************************************************************************/
void MCCON_ResetPIParameters(void)
{
  	/**************** PI D Term ***********************************************/
         gPIParmD.dSum = 0;
         gPIParmD.out = 0;

  	/**************** PI Q Term ************************************************/
         gPIParmQ.dSum = 0;
         gPIParmQ.out = 0;

  	/**************** PI Velocity Control **************************************/
         gPIParmQref.dSum = 0;
         gPIParmQref.out = 0;
}

#endif
#endif

