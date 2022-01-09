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
#include "mc_error_handler.h"
  
/*******************************************************************************
 Private variables 
 *******************************************************************************/
tMCERR_STATE_SIGNAL_S    gMCERR_StateSignals;
MCERR_CALLBACK_OBJECT    MCERR_CallbackObj;

/*******************************************************************************
 Interface variables 
 *******************************************************************************/

/*******************************************************************************
 Private Functions 
 *******************************************************************************/

/*******************************************************************************
 Interface Functions 
 *******************************************************************************/

/*! \brief Register the callback function which is called when fault is detected
 * 
 * Details.
 * Register the callback function which is called when fault is detected
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */

void mcErr_FaultCallbackRegister(MCERR_FAULT_CALLBACK callback, uintptr_t context)
{
    MCERR_CallbackObj.callback_fn = callback;
    MCERR_CallbackObj.context = context;
}


/*! \brief Clear the error status 
 * 
 * Details.
 * Clear the error status 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcErr_ErrorClear( void )
{
    gMCERR_StateSignals.errorCode = 0;
<#if MCPMSMFOC_LEDS_AVAILABLE != 0 >
  <#if "Fault indication" == MCPMSMFOC_LED_0_FUNCTION >
    ${MCPMSMFOC_LED_0_NAME}_Clear();
  <#elseif "Fault indication" == MCPMSMFOC_LED_1_FUNCTION >
    ${MCPMSMFOC_LED_1_NAME}_Clear();   
  </#if>
</#if>
}


/*! \brief Fault ISR when the overcurrent is detected at external pin 
 * 
 * Details.
 * Fault ISR when the overcurrent is detected at external pin 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcErr_FaultControlISR(uint32_t status, uintptr_t context)
{
  <#if MCPMSMFOC_LEDS_AVAILABLE != 0 >
    /* Indicate the failure status by glowing LED D2 */
    <#if "Fault indication" == MCPMSMFOC_LED_0_FUNCTION >
        ${MCPMSMFOC_LED_0_NAME}_Set();
    <#elseif "Fault indication" == MCPMSMFOC_LED_1_FUNCTION >
        ${MCPMSMFOC_LED_1_NAME}_Set();   
    </#if>
  </#if>

    gMCERR_StateSignals.errorCode |= (1 << MCERR_OVERCURRENT);
    PMSM_FOC_MotorStop();

    if (MCERR_CallbackObj.callback_fn != NULL)
    {
        MCERR_CallbackObj.callback_fn(MCERR_OVERCURRENT, MCERR_CallbackObj.context);
    }
}
