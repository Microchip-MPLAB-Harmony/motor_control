/*******************************************************************************
 Motor Control Coordination Functions 

  Company:
    Microchip Technology Inc.

  File Name:
    mc_error_handler.c

  Summary:
    Error Handler Functions.

  Description:
    This file implements error handler functions
 
 *******************************************************************************/

// DOM-IGNORE-BEGIN
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
// DOM-IGNORE-END

/*******************************************************************************
Headers inclusions
*******************************************************************************/
#include "definitions.h"
#include "stdio.h"
#include "mc_generic_library.h"
#include "mc_error_handler.h"
#include "mc_motor_control.h"
#include "mc_hardware_abstraction.h"

/*******************************************************************************
 * Module variables 
*******************************************************************************/

/*******************************************************************************
 * Interface variables 
*******************************************************************************/
tmcErr_ErrorId_e mcErrI_ErrorLogged_gde  =  NO_ERROR_LOGGED;

/*******************************************************************************
 * Interface Functions  
*******************************************************************************/

/*! \brief Software plausibility check  
 * 
 * Details.
 * Software plausibility check 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcErr_AssertionFailedReaction( const char * message )
{ 
    /* Log software plausibility error Id and message */
    mcErrI_ErrorLogged_gde =     SOFTWARE_PLAUSIBILITY_FAILURE;
    
    /* Store passed message */
    printf("%s", message);
    
    /* Error Reaction */
    mcErr_ErrorReaction();
}

/*! \brief Error reaction function  
 * 
 * Details.
 * Error reaction function 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */

void mcErr_ErrorReaction( void )
{
    mcMocI_MotorStop();
    mcHal_FaultIndicationSet();
}

/*! \brief Logs Error 
 * 
 * Details.
 * Logs Error  
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcErrI_ErrorLogging( tmcErr_ErrorId_e errorId )
{
    mcErrI_ErrorLogged_gde = errorId;
}
