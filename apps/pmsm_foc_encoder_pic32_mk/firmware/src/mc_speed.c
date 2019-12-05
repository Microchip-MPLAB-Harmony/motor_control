/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    mc_speed.c

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
#ifndef MCSPE_C
#define MCSPE_C
#include "mc_app.h"
#include "mc_speed.h"
#include "mc_infrastructure.h"
#include "mc_currMeasurement.h"
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

tMCSPE_INPUT_SIGNAL_S   gMCSPE_InputSignals;
tMCSPE_STATE_SIGNAL_S   gMCSPE_StateSignals;
tMCSPE_PARAMETERS_S     gMCSPE_Parameters = { 
                                              KFILTER_POT, 
                                              POT_ADC_COUNT_FW_SPEED_RATIO, 
                                              OPEN_LOOP_END_SPEED_RADS_PER_SEC_ELEC
                                            };
tMCSPE_OUTPUT_SIGNAL_S   gMCSPE_OutputSignals;


                                          

/******************************************************************************/
/*                          LOCAL  FUNCTIONS                                  */
/******************************************************************************/
__STATIC_INLINE void MCSPE_ReadInputSignals( void )
{
    gMCSPE_InputSignals.s_ControlStatus_e   =  gCtrlParam.s_ControlStatus_e;
    gMCSPE_InputSignals.n_openLoopSpeed_f32 =  gCtrlParam.velRef;
}

/******************************************************************************/
/*                       INTERFACE FUNCTIONS                                  */
/******************************************************************************/

/******************************************************************************/
/* Function name: MCSPE_InitializeSpeedControl                                */
/* Function parameters: None                                                  */
/* Function return: uint8_t                                                   */
/* Description: Reset speed control state variables                           */
/******************************************************************************/
void  MCSPE_InitializeSpeedControl(void)
{
    /* Initialize speed command function parameters */
    gMCSPE_Parameters.filterParam    =   KFILTER_POT;
    gMCSPE_Parameters.minSpeed       =   OPEN_LOOP_END_SPEED_RADS_PER_SEC_ELEC ; 
    gMCSPE_Parameters.pot2SpeedRatio =   POT_ADC_COUNT_FW_SPEED_RATIO; 

    /* Initialize speed command function states */   
    gMCSPE_StateSignals.potFiltered =  0.0f;                                                         
}

/******************************************************************************/
/* Function name: MCSPE_SpeedCommand                                          */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description: Determines the speed command from external source             */
/*                      or potentiometer                                      */
/******************************************************************************/
void MCSPE_SpeedCommand( void )
{
#if( 1U  == POTENTIOMETER_INPUT_ENABLED )
    MCSPE_ReadInputSignals();
    if( MCAPP_CLOSED_LOOP  == gMCSPE_InputSignals.s_ControlStatus_e )
    {                      
        gMCSPE_OutputSignals.potReading = (float)ADCHS_ChannelResultGet(ADCHS_CH15);
        gMCSPE_StateSignals.potFiltered =   gMCSPE_StateSignals.potFiltered  
                                      + ((  gMCSPE_OutputSignals.potReading -  gMCSPE_StateSignals.potFiltered ) * gMCSPE_Parameters.filterParam );

        gMCSPE_OutputSignals.commandSpeed = gMCSPE_StateSignals.potFiltered * gMCSPE_Parameters.pot2SpeedRatio;
          
        /* Restrict velocity reference so motor will be spinning in closed loop. */
        if( gMCSPE_OutputSignals.commandSpeed < gMCSPE_Parameters.minSpeed )
        {
            gMCSPE_OutputSignals.commandSpeed = gMCSPE_Parameters.minSpeed;
        }
    }
    else
    {
        gMCSPE_OutputSignals.commandSpeed = gMCSPE_InputSignals.n_openLoopSpeed_f32;
    }
             
#else
         /* External speed command  */
#endif
}

/******************************************************************************/
/* Function name: MCSPE_ResetSpeedControl                                     */
/* Function parameters: None                                                  */
/* Function return: uint8_t                                                   */
/* Description: Reset speed control state variables                           */
/******************************************************************************/
void  MCSPE_ResetSpeedControl(void)
{
    /* Reset speed command function states */   
    gMCSPE_StateSignals.potFiltered =  0.0f;            
}

#endif
#endif
