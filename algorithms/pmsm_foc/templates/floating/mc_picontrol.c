/*******************************************************************************
  PI Controller Source File

  Company:
    Microchip Technology Inc.

  File Name:
     mc_picontrol.c

  Summary:
   This file contains functions for PI control.

  Description:
    This file contains functions for PI control.

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
#include "mc_picontrol.h"


// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************


/******************************************************************************/
/* Local Function Prototype                                                   */
/******************************************************************************/

/******************************************************************************/
/*                   Global Variables                                         */
/******************************************************************************/


/******************************************************************************/
/* Function name: MCLIB_PIControl                                             */
/* Function parameters: pParm - PI parameter structure                        */
/* Function return: None                                                      */
/* Description: Execute PI control                                            */
/******************************************************************************/
void MCLIB_PIControl( tMCLIB_PICONTROLLER_S * const pParm)
{
    float err;
    float out;
    float exc;

    err  = pParm->inRef - pParm->inMeas;
    out  = pParm->dSum + pParm->kp * err;

    /* Limit checking for PI output */
    if( out > pParm->outMax )
    {
       pParm->out = pParm->outMax;
    }
    else if( out < pParm->outMin )
    {
       pParm->out = pParm->outMin;
    }
    else
    {
       pParm->out = out;
    }

    exc = out - pParm->out;
    pParm->dSum = pParm->dSum + pParm->ki * err - pParm->kc * exc;
}


/******************************************************************************/
/* Function name: MCLIB_ResetPIParameters                                     */
/* Function parameters: pParm - PI parameter structure                        */
/* Function return: None                                                      */
/* Description:                                                               */
/* Reset control parameters                                                   */
/******************************************************************************/
void MCLIB_ResetPIParameters(tMCLIB_PICONTROLLER_S * const pParm)
{
    /**************** PI D Term ***********************************************/
    pParm->dSum = 0;
    pParm->out = 0;
}
