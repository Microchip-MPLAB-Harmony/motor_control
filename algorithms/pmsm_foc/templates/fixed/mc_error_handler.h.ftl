/*******************************************************************************
  System Definitions

  File Name:
    mc_error_handler.h

  Summary:
    Header file which contains variables and function prototypes for error handling

  Description:
    This file contains variables and function prototypes which are generally
    used for error handling. It is implemented in Q2.14 fixed Point Arithmetic.

 *******************************************************************************/

//DOM-IGNORE-BEGIN
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
//DOM-IGNORE-END

#ifndef MCERR_H
#define MCERR_H

#include <stdint.h>
#include <sys/attribs.h>
#include "mc_interface_handling.h"

/*******************************************************************************
 Type Definition 
*******************************************************************************/
typedef enum
{
    NO_ERROR_LOGGED,
    SOFTWARE_PLAUSIBILITY_FAILURE,
    MCCUR_PHASE_A_CURRENT_OFFSET_OOR,
    MCCUR_PHASE_B_CURRENT_OFFSET_OOR
}tmcErr_ErrorId_e;

#define ASSERT(expression, message) if(!expression) mcErr_AssertionFailedReaction( message);

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
void mcErr_AssertionFailedReaction( const char * message );

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
void mcErr_ErrorReaction( void );

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
void mcErrI_ErrorLogging( tmcErr_ErrorId_e errorId );

#endif // _MCERR_H
