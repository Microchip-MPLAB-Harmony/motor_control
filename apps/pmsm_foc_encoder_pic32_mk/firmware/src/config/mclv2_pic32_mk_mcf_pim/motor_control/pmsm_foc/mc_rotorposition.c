/*******************************************************************************

  Rotor Position Source File

  Company:
    Microchip Technology Inc.

  File Name:
    mc_rotorposition.c

  Summary:
    This file contains functions to get the rotor position of a motor

  Description:
    This file contains functions to get the rotor position of a motor
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
#include "mc_rotorposition.h"
#include "mc_hal.h"
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

__STATIC_INLINE void MCRPOS_InitializeEncoder( void );
__STATIC_INLINE void MCRPOS_EncoderCalculations( void );

/******************************************************************************/
/*                   Global Variables                                         */
/******************************************************************************/
tMCRPOS_STATE_SIGNAL_S            gMCRPOS_StateSignals = { 0.0f };
tMCRPOS_OUTPUT_SIGNAL_S           gMCRPOS_OutputSignals = { 0.0f };
tMCRPOS_ROTOR_ALIGN_STATE_S       gMCRPOS_RotorAlignState = { MCRPOS_FORCE_ALIGN, 0U,  0U };
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
__STATIC_INLINE void MCRPOS_InitializeEncoder( void )
{
    /* Start QEI Interface */
    MCHAL_EncoderStart();
}

/******************************************************************************/
/* Function name: MCRPOS_EncoderCalculations                                  */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description:                                                               */
/* Encoder Calculations                                                       */
/******************************************************************************/
__STATIC_INLINE void MCRPOS_EncoderCalculations( void )
{
    gMCRPOS_StateSignals.synCounter++;
    /* Calculate position */
    gMCRPOS_StateSignals.position = (int32_t)MCHAL_EncoderPositionGet();

    /* Calculate velocity */
    if( gMCRPOS_StateSignals.synCounter > QEI_VELOCITY_COUNT_PRESCALER )
    {
        gMCRPOS_StateSignals.synCounter = 0;
        gMCRPOS_StateSignals.velocity = (int32_t)MCHAL_EncoderSpeedGet();
    }

    /* Write speed and position output */
    gMCRPOS_OutputSignals.speed = (float)( gMCRPOS_StateSignals.velocity * QEI_VELOCITY_COUNT_TO_RAD_PER_SEC );
    gMCRPOS_OutputSignals.angle = gMCRPOS_StateSignals.position * (float)QEI_COUNT_TO_ELECTRICAL_ANGLE;
}



/******************************************************************************/
/*                      INTERFACE FUNCTIONS                                   */
/******************************************************************************/

/******************************************************************************/
/* Function name: MCRPOS_InitialRotorPositonDetection                                        */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description: Initial rotor position alignment                              */
/******************************************************************************/
tMCAPP_STATUS_E MCRPOS_InitialRotorPositonDetection( tMCRPOS_ROTOR_ALIGN_OUTPUT_S * const alignOutput )
{
    tMCAPP_STATUS_E status = MCAPP_IN_PROGRESS ;
    switch( gMCRPOS_RotorAlignState.rotorAlignState )
    {
        case MCRPOS_FORCE_ALIGN:
        {
            status = MCRPOS_FieldAlignment( alignOutput );
            if( MCAPP_SUCCESS  ==  status )
            {
                MCRPOS_ResetPositionSensing(MCRPOS_FORCE_ALIGN);
            }
        }
        break;
        default:
        {
            /* Should never come here */
        }
    }
    gMCRPOS_RotorAlignState.status = gMCRPOS_RotorAlignState.rotorAlignState;
    return status;
}

tMCAPP_STATUS_E MCRPOS_FieldAlignment( tMCRPOS_ROTOR_ALIGN_OUTPUT_S * const alignOutput )
{
    tMCAPP_STATUS_E status = MCAPP_IN_PROGRESS ;

  #if( FORCED_ALIGNMENT == ALIGNMENT_METHOD)
    if ( gMCRPOS_RotorAlignState.startupLockCount < ( 0.5* gMCRPOS_RotorAlignParam.lockTimeCount))
    {
      #if(1U == Q_AXIS_ALIGNMENT )
        alignOutput->idRef =  0.0f;
        alignOutput->iqRef =  gMCRPOS_RotorAlignParam.lockCurrent;
        alignOutput->angle = (M_PI);
        gMCRPOS_RotorAlignState.startupLockCount++;
      #else
        alignOutput->idRef =  gMCRPOS_RotorAlignParam.lockCurrent;
        alignOutput->iqRef =  0.0f;
        alignOutput->angle =  (0.5f * M_PI_2);
        gMCRPOS_RotorAlignState.startupLockCount++;
      #endif
    }
    else if ( gMCRPOS_RotorAlignState.startupLockCount < gMCRPOS_RotorAlignParam.lockTimeCount)
    {
      #if(1U == Q_AXIS_ALIGNMENT )
        alignOutput->idRef =  0.0f;
        alignOutput->iqRef =  gMCRPOS_RotorAlignParam.lockCurrent;
        alignOutput->angle = (3*M_PI_2);
        gMCRPOS_RotorAlignState.startupLockCount++;
      #else
        alignOutput->idRef =  gMCRPOS_RotorAlignParam.lockCurrent;
        alignOutput->iqRef =  0.0f;
        alignOutput->angle =  0.0f;
        gMCRPOS_RotorAlignState.startupLockCount++;
      #endif
    }
    else
    {
        gMCRPOS_RotorAlignState.startupLockCount = 0;
        MCHAL_EncoderPositionSet(1);
        status = MCAPP_SUCCESS;
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
void MCRPOS_InitializeRotorPositionSensing( void )
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
void MCRPOS_PositionMeasurement(  )
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
void MCRPOS_ResetPositionSensing( tMCRPOS_ALIGN_STATE_E state )
{
    gMCRPOS_RotorAlignState.rotorAlignState = state;
    gMCRPOS_StateSignals.position = 0;
    gMCRPOS_StateSignals.velocity = 0;
    gMCRPOS_StateSignals.synCounter = 0;
    gMCRPOS_RotorAlignState.startupLockCount = 0;
}
