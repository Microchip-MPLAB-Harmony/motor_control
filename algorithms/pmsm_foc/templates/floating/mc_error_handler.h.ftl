/*******************************************************************************
 * Error Handler interface file

  Company:
    Microchip Technology Inc.

  File Name:
    mc_errorHandler.h

  Summary:
    Header file for error handler functions

  Description:
    This file contains the data structures and function prototypes used by
     Error handler module.
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

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#ifndef MC_ERRORHANDLER_H
#define MC_ERRORHANDLER_H

#include <stddef.h>
#include "mc_hardware_abstraction.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif

// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************

typedef enum
{
    MCERR_OVERCURRENT,
    MCERR_UNDEROVERVOLTAGE,
    MCERR_STALL,
}tMCERR_ERROR_CODE_E;

typedef struct
{
    uint32_t errorCode;
}tMCERR_STATE_SIGNAL_S;

typedef void (*MCERR_FAULT_CALLBACK)(tMCERR_ERROR_CODE_E error, uintptr_t context);
// *****************************************************************************

typedef struct
{
    MCERR_FAULT_CALLBACK callback_fn;
    uintptr_t context;
}MCERR_CALLBACK_OBJECT;

extern tMCERR_STATE_SIGNAL_S    gMCERR_StateSignals;

// *****************************************************************************
// *****************************************************************************
// Section: Interface Routines
// *****************************************************************************
// *****************************************************************************

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
void mcErr_FaultCallbackRegister(MCERR_FAULT_CALLBACK callback, uintptr_t context);


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
void mcErr_ErrorClear( void );

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
void mcErr_FaultControlISR(uint32_t status, uintptr_t context);

#ifdef    __cplusplus
extern "C" {
#endif



#ifdef    __cplusplus
}
#endif

#endif    /* MC_ERRORHANDLER_H */
