/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    MCAPP_CurrentMeasurement.c

  Summary:
    This file contains functions to initialize, calibrate and measure phase
    currents for motor control application

  Description:
    This file contains functions to initialize, calibrate and measure phase
    currents for motor control application
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
#ifndef MCRPOS_C 
#define MCRPOS_C
#include "mc_rotorPosition.h"
#include "mc_voltageMeasurement.h"
#include "math.h"
#include "assert.h"

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
tMCRPO_STATE_SIGNAL_S            gMCRPOS_StateSignals = { 0.0f };
tMCRPO_OUTPUT_SIGNAL_S            gMCRPOS_OutputSignals = { 0.0f };
tMCRPOS_ROTOR_ALIGN_STATE_S       gMCRPOS_RotorAlignState = { FORCE_ALIGN, 0U,  0U };
tMCRPOS_ROTOR_ALIGN_OUTPUT_S      gMCRPOS_RotorAlignOutput = {0U,  0U };
tMCRPOS_ROTOR_ALIGN_PARAM_S       gMCRPOS_RotorAlignParam  = {
                                                                  Q_CURRENT_REF_OPENLOOP,
                                                                  LOCK_COUNT_FOR_LOCK_TIME
                                                             };

/******************************************************************************/
/*                          LOCAL FUNCTIONS                                   */
/******************************************************************************/ 

/******************************************************************************/
/* Function name: MCRPOS_InitializeEncoder                                    */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description:                                                               */
/* Initilaize Encoder                                                         */
/******************************************************************************/
void MCRPOS_InitializeEncoder( void )
{
    /* Start QEI Interface */
    QEI2_Start();   
}

/******************************************************************************/
/* Function name: MCRPOS_EncoderCalculations                                  */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description:                                                               */
/* Encoder Calculations                                                       */
/******************************************************************************/
void MCRPOS_EncoderCalculations( void )
{   
    gMCRPOS_StateSignals.SynCounter++;
    /* Calculate position */
    gMCRPOS_StateSignals.position = (int32_t)QEI2_PositionGet();
     
    /* Calculate velocity */
    if( gMCRPOS_StateSignals.SynCounter > QEI_VELOCITY_COUNT_PRESCALER )
    { 
        gMCRPOS_StateSignals.SynCounter = 0;
        gMCRPOS_StateSignals.velocity = (int32_t)QEI2_VelocityGet() ;
    } 

    /* Write speed and position output */   
    gMCRPOS_OutputSignals.Speed = (float)( gMCRPOS_StateSignals.velocity * QEI_VELOCITY_COUNT_TO_RAD_PER_SEC );
    gMCRPOS_OutputSignals.Angle = gMCRPOS_StateSignals.position * (float)QEI_COUNT_TO_ELECTRICAL_ANGLE;
}

/******************************************************************************/
/* Function name: MCRPOS_ResetEncoder                                         */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description:                                                               */
/* Reset Encoder                                                              */
/******************************************************************************/
void MCRPOS_ResetEncoder( void )
{
   /* Reset State variables if any */
    gMCRPOS_OutputSignals.Speed = 0.0f; 
    gMCRPOS_OutputSignals.Angle = 0.0f;

    /* Reset Encoder counters */
    POS2CNT = 1;
    VEL2CNT = 0;

}   

/******************************************************************************/
/*                      INTERFACE FUNCTIONS                                   */
/******************************************************************************/                                                                                                                 

/******************************************************************************/
/* Function name: MCAPP_FieldAlignment                                        */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description: Initial rotor position alignment                              */
/******************************************************************************/
INLINE_FUNCTION tMCRPOS_STATUS_E MCRPO_InitialRotorPositonDetection( tMCRPOS_ROTOR_ALIGN_OUTPUT_S * const alignOutput )
{
    tMCRPOS_STATUS_E status = RUNNING ;

  #if( 1U == FORCED_ALIGNMENT )
    if ( gMCRPOS_RotorAlignState.startup_lock_count < ( 0.5* gMCRPOS_RotorAlignParam.lockTimeCount))
    {
      #if(1U == Q_AXIS_ALIGNMENT )
        alignOutput->idRef =  0.0f;
        alignOutput->iqRef =  gMCRPOS_RotorAlignParam.lockCurrent;
        alignOutput->angle = (M_PI);
        gMCRPOS_RotorAlignState.startup_lock_count++;
      #else 
        alignOutput->idRef =  gMCRPOS_RotorAlignParam.lockCurrent;
        alignOutput->iqRef =  0.0f;
        alignOutput->angle =  (0.5f * M_PI_2);
        gMCRPOS_RotorAlignState.startup_lock_count++;
      #endif
    }
    else if ( gMCRPOS_RotorAlignState.startup_lock_count < gMCRPOS_RotorAlignParam.lockTimeCount)
    {
      #if(1U == Q_AXIS_ALIGNMENT )
        alignOutput->idRef =  0.0f;
        alignOutput->iqRef =  gMCRPOS_RotorAlignParam.lockCurrent;
        alignOutput->angle = (3*M_PI_2);
        gMCRPOS_RotorAlignState.startup_lock_count++;
      #else 
        alignOutput->idRef =  gMCRPOS_RotorAlignParam.lockCurrent;
        alignOutput->iqRef =  0.0f;
        alignOutput->angle =  0.0f;
        gMCRPOS_RotorAlignState.startup_lock_count++;
      #endif
    }
    else
    {
        MCRPOS_ResetPositionSensing();
        status = COMPLETE;
    }
  #else
    assert(0, SELECT A ROTOR ALIGNMENT ALGORITHM );
  #endif

    return status;
}

/******************************************************************************/
/* Function name: MCRPOS_initialization                                       */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description:                                                               */
/* initializes parameters and state variables for rotor position sensing      */
/******************************************************************************/
INLINE_FUNCTION  void MCRPO_InitializeRotorPositionSensing( void )
{
    MCRPOS_InitializeEncoder(); 
}

/******************************************************************************/
/* Function name: MCRPOS_PositionMeasurement                                  */
/* Function parameters: none                                                  */
/* Function return: None                                                      */
/* Description:                                                               */
/* Determines the rotor position                                              */
/******************************************************************************/
INLINE_FUNCTION void MCRPO_PositionMeasurement(  )
{
    MCRPOS_EncoderCalculations( );
}

/******************************************************************************/
/* Function name: MCRPOS_ResetPositionSensing                                 */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description:                                                               */
/* reset state variables for rotor position sensing                           */
/******************************************************************************/
INLINE_FUNCTION  void MCRPOS_ResetPositionSensing( void )
{
    MCRPOS_ResetEncoder();
    gMCRPOS_StateSignals.position = 0;
    gMCRPOS_StateSignals.velocity = 0;
    gMCRPOS_StateSignals.SynCounter = 0;
    gMCRPOS_RotorAlignState.startup_lock_count = 0;
}

#endif
#endif
