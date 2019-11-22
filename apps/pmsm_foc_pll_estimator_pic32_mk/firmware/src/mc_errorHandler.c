/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    McErrorHandler.c

  Summary:
    This file contains functions to functions to initialize the motor control
    peripherals.

  Description:
    This file contains functions to functions to initialize the motor control
    peripherals.

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
#ifndef MCERR_C
#define MCERR_C
#include "mc_errorHandler.h"
#include "mc_infrastructure.h"
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
tMCERR_STATE_SIGNAL_S    gMCERR_StateSignals;

/******************************************************************************/
/* Function name: MCERR_ErrorLogging                                          */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description: Logs error                                                    */
/******************************************************************************/
void MCERR_ErrorLogging( void )
{
    /* ToDo: Conceptualize error logging mechanism */
}



/******************************************************************************/
/*  Function name: MCERR_FaultControlISR                                      */
/*  Function parameters: None                                                 */
/*  Function return: None                                                     */
/*  Description: Fault ISR when the external failure at                       */
/*                       FLT15 pin detects failure                            */
/******************************************************************************/

void MCERR_FaultControlISR(uint32_t status, uintptr_t context)
{
    /* Stop the motor */
    MCINF_MotorStop();

    /* Indicate the failure status by glowing LED D2 */
    FAULT_INDICATOR_Set();
}

/******************************************************************************/
/*  Function name: MCERR_StartupCheck                                         */
/*  Function parameters: None                                                 */
/*  Function return: None                                                     */
/*  Description: Start up check                                               */
/******************************************************************************/
void MCERR_StartupCheck( void )
{
    /* Check for unintentional reset */
    if(RCON & 0x0003)
    {
        gMCERR_StateSignals.resetSource = ( 1 << MCERR_POWER_ON_RESET );
        gMCERR_StateSignals.errorSource = MCERR_NORMAL;
    }
    if(RCON & 0x0002)
    {
        gMCERR_StateSignals.resetSource |=  ( 1 << MCERR_BROWN_OUT_RESET );
        gMCERR_StateSignals.errorSource = MCERR_UNINTENTIONAL_RESET;
    }
    if(RCON & 0x0080)
    {
        gMCERR_StateSignals.resetSource |=  ( 1 << MCERR_MASTER_CLR_RESET );
        gMCERR_StateSignals.errorSource = MCERR_UNINTENTIONAL_RESET;
    }
    if(RCON & 0x0040)
    {
        gMCERR_StateSignals.resetSource |=  ( 1 << MCERR_SOFTWARE_RESET );
        gMCERR_StateSignals.errorSource = MCERR_UNINTENTIONAL_RESET;
    }
    if (RCON & 0x0200)
    {
        gMCERR_StateSignals.resetSource |=  ( 1 << MCERR_CONFIG_MISMATCH_RESET );
        gMCERR_StateSignals.errorSource = MCERR_UNINTENTIONAL_RESET;
    }
    if (RCON & 0x0010)
    {
        gMCERR_StateSignals.resetSource |=  ( 1 << MCERR_WATCHDOG_RESET );
        gMCERR_StateSignals.errorSource = MCERR_UNINTENTIONAL_RESET;
    }
    if (RCON & 0x0020)
    {
        gMCERR_StateSignals.resetSource |=  ( 1 << MCERR_DEADMAN_RESET  );
        gMCERR_StateSignals.errorSource = MCERR_UNINTENTIONAL_RESET;
    } 

    /* Reset RCON status  */
    RCON =  0x0000;
}
#endif
#endif
