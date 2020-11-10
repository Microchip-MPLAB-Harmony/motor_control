/*******************************************************************************
  Motor Control Library Source File

  Company:
    Microchip Technology Inc.

  File Name:
    mc_lib.c

  Summary:
    This file contains the motor control algorithm functions.

  Description:
    This file contains the motor control algorithm functions like clarke transform,
    park transform. This library is implemented with float data type.
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
#include "mc_lib.h"
#include "mc_derivedparams.h"

/******************************************************************************/
/* Local Function Prototype                                                   */
/******************************************************************************/



/******************************************************************************/
/*                   Global Variables                                         */
/******************************************************************************/

tMCLIB_CLARK_TRANSFORM_S            gMCLIB_CurrentAlphaBeta = {0.0f, 0.0f};
tMCLIB_PARK_TRANSFORM_S              gMCLIB_CurrentDQ = {0.0f, 0.0f};
tMCLIB_POSITION_S                    gMCLIB_Position = {0.0f, 0.0f, 1.0f };
tMCLIB_PARK_TRANSFORM_S              gMCLIB_VoltageDQ = {0.0f, 0.0f};
tMCLIB_CLARK_TRANSFORM_S            gMCLIB_VoltageAlphaBeta = {0.0f, 0.0f};




/******************************************************************************/
/* Function name: MCLIB_ClarkeTransform                                       */
/* Function parameters: input - phase currents                                */
/*                      output - clarke transform output                      */
/* Function return: None                                                      */
/* Description: Clarke Transformation                                         */
/******************************************************************************/
 void MCLIB_ClarkeTransform(const tMCCUR_PHASE_CURRENTS_S * const  input, tMCLIB_CLARK_TRANSFORM_S * const output)
{
    output->alphaAxis = input->iu;
    output->betaAxis = (input->iu * ONE_BY_SQRT3) + (input->iv * TWO_BY_SQRT3);
}

/*****************************************************************************/
/* Function name: MCLIB_ParkTransform                                        */
/* Function parameters: input - clarke transform input                       */
/*                      output - park transform output                       */
/*                      position - rotor angle                               */
/* Function return: None                                                     */
/* Description: Park Transformation.                                         */
/******************************************************************************/
void MCLIB_ParkTransform( const tMCLIB_CLARK_TRANSFORM_S * const input, const tMCLIB_POSITION_S * const position, tMCLIB_PARK_TRANSFORM_S * const output)
{
    output->directAxis =  input->alphaAxis * position->cosAngle
                        + input->betaAxis * position->sineAngle;
    output->quadratureAxis = -input->alphaAxis * position->sineAngle
                        + input->betaAxis * position->cosAngle;
}

/******************************************************************************/
/* Function name: MCLIB_InvParkTransform                                      */
/* Function parameters: input - park transform inputs                         */
/*                      output - clarke transform output                      */
/*                      position - rotor angle                                */
/* Function return: None                                                      */
/* Description: Inverse Park Transformation.                                  */
/******************************************************************************/
 void MCLIB_InvParkTransform(const tMCLIB_PARK_TRANSFORM_S * const input, const tMCLIB_POSITION_S * const position, tMCLIB_CLARK_TRANSFORM_S * const output)
{
    output->alphaAxis =  input->directAxis * position->cosAngle - input->quadratureAxis * position->sineAngle;
    output->betaAxis  =  input->directAxis * position->sineAngle + input->quadratureAxis * position->cosAngle;
}

/*******************************************************************************
 End of File
*/
