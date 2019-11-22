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

#ifndef MC_ERRORHANDLER_H
#define	MC_ERRORHANDLER_H

typedef enum 
{
    MCERR_POWER_ON_RESET,
    MCERR_BROWN_OUT_RESET,
    MCERR_MASTER_CLR_RESET,
    MCERR_CONFIG_MISMATCH_RESET,
    MCERR_SOFTWARE_RESET,
    MCERR_WATCHDOG_RESET,
    MCERR_DEADMAN_RESET
}tMCERR_RESET_SOURCE_E;

typedef enum 
{
    MCERR_NORMAL,
    MCERR_UNINTENTIONAL_RESET,
    MCERR_WATCHDOG_ERROR,
    MCERR_DEADMAN_TIMER_ERROR,
    MCERR_POSITION_LOSS,
    MCERR_PHASE_CURRENT_OOR,
    MCERR_UNDER_VOLTAGE,
    MCERR_OVER_VOLTAGE
}tMCERR_ERROR_SOURCE_E;



typedef struct 
{
    tMCERR_RESET_SOURCE_E     resetSource;
    tMCERR_ERROR_SOURCE_E     errorSource;
}tMCERR_STATE_SIGNAL_S;


extern void MCERR_ErrorLogging( void );
extern void MCERR_StartupCheck( void );

#ifdef	__cplusplus
extern "C" {
#endif



#ifdef	__cplusplus
}
#endif

#endif	/* MC_ERRORHANDLER_H */

