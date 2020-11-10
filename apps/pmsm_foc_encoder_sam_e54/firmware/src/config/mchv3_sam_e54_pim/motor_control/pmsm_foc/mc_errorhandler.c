/*******************************************************************************
  Error Handler Source File

  Company:
    Microchip Technology Inc.

  File Name:
    mc_errorhandler.c

  Summary:
    This file contains error handler interrupt serive routine

  Description:
    This file contains error handler interrupt serive routine

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
#include "mc_errorhandler.h"
#include "mc_pmsm_foc.h"
#include "mc_hal.h"

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
tMCERR_STATE_SIGNAL_S    gMCERR_StateSignals;
MCERR_CALLBACK_OBJECT    MCERR_CallbackObj;

/******************************************************************************/
/*  Function name: MCERR_FaultCallbackRegister                                */
/*  Function parameters: callback function, context                           */
/*  Function return: None                                                     */
/*  Description: Register the callback function which is called when fault is detected */
/******************************************************************************/
void MCERR_FaultCallbackRegister(MCERR_FAULT_CALLBACK callback, uintptr_t context)
{
    MCERR_CallbackObj.callback_fn = callback;
    MCERR_CallbackObj.context = context;
}

/******************************************************************************/
/*  Function name: MCERR_ErrorClear                                           */
/*  Function parameters: None                                                 */
/*  Function return: None                                                     */
/*  Description: Clear the error status                                      */
/******************************************************************************/
void MCERR_ErrorClear( void )
{
    gMCERR_StateSignals.errorCode = 0;
    MCHAL_FAULT_LED_CLEAR();
}


/******************************************************************************/
/*  Function name: MCERR_FaultControlISR                                      */
/*  Function parameters: status, context                                      */
/*  Function return: None                                                     */
/*  Description: Fault ISR when the overcurrent is detected at external pin   */
/***************************************************************************/

void MCERR_FaultControlISR(uint32_t status, uintptr_t context)
{
   /* Indicate the failure status by glowing LED D2 */
    MCHAL_FAULT_LED_SET();
    gMCERR_StateSignals.errorCode |= (1 << MCERR_OVERCURRENT);
    PMSM_FOC_MotorStop();

    if (MCERR_CallbackObj.callback_fn != NULL)
    {
        MCERR_CallbackObj.callback_fn(MCERR_OVERCURRENT, MCERR_CallbackObj.context);
    }
}
