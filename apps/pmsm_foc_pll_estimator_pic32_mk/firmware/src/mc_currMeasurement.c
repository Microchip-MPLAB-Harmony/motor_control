/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    MCAPP_CurrentMeasurement.c

  Summary:
    This file contains functions to initilaize, calibrate and measure phase
    currents for motor control application

  Description:
    This file contains functions to initilaize, calibrate and measure phase
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
#if      ( defined ( USE_FILE_INLINING )  &&  defined  (  MCAPP_C  ) )  ||   ( !defined ( USE_FILE_INLINING )  )
#ifndef MCCUR_C
#define MCCUR_C
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
tPHASE_CURRENTS_OFFSET_S    gMCCUR_PhaseCurrentOffset = { 0U, 0.0f, 0.0f };
tPHASE_CURRENTS_S                     gMCCUR_PhaseCurrent = { 0.0f, 0.0f, 0.0f, 0.0f };

/******************************************************************************/
/* Function name: MCCUR_initialization                    v                   */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description:                                                               */
/* Performs peripheral initialization for current measurement                 */
/******************************************************************************/
void MCCUR_initialization( void )
{
         /* Not in use as of now */
}


/******************************************************************************/
/* Function name: MCCUR_offsetCalibration                                     */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description:                                                               */
/* Calculates current sensors offset                                          */
/******************************************************************************/
void MCCUR_offsetCalibration( void )
{
         uint32_t AdcSampleCounter = 0.0f;
         int32_t delayCounter = 0xFFFF;
         float phaseCurrentUOffset = 0.0f;
         float phaseCurrentVOffset = 0.0f;
         uint32_t phaseUOffsetBuffer = 0.0f;
         uint32_t phaseVOffsetBuffer = 0.0f;

         /* Software trigger used for ADC conversion. Note: MCPWM timer should be disabled before */
         ADCHS_ChannelConversionStart(PHASE_CURRENT_U);
         ADCHS_ChannelConversionStart(PHASE_CURRENT_V);

         for(AdcSampleCounter = 0; AdcSampleCounter < CURRENTS_OFFSET_SAMPLES; AdcSampleCounter++)
         {
                  /* Software trigger for phase current measurements */
                  ADCHS_ChannelConversionStart(PHASE_CURRENT_U);
                  ADCHS_ChannelConversionStart(PHASE_CURRENT_V);

                  /* Delay to stabilize voltage levels on board and adc conversion to complete */
                  do
                  {
                           asm("NOP");
                           asm("NOP");
                           asm("NOP");
                           asm("NOP");
                           asm("NOP");
                           delayCounter--;
                  } while (delayCounter > 0);

                  /* re-load delay counter for next adc sample */
                  delayCounter = 0xFFFF;

                  phaseUOffsetBuffer += ADCHS_ChannelResultGet(PHASE_CURRENT_U);
                  phaseVOffsetBuffer += ADCHS_ChannelResultGet(PHASE_CURRENT_V);
         }

         phaseCurrentUOffset = (float)(phaseUOffsetBuffer/CURRENTS_OFFSET_SAMPLES);
         phaseCurrentVOffset = (float)(phaseVOffsetBuffer/CURRENTS_OFFSET_SAMPLES);

         /* Limit motor phase A current offset calibration to configured Min/Max levels. */
         if( phaseCurrentUOffset >  (float)CURRENT_OFFSET_MAX)
         {
                  phaseCurrentUOffset = (float)CURRENT_OFFSET_MAX;
         }
         else if( phaseCurrentUOffset <  (float)CURRENT_OFFSET_MIN)
         {
                  phaseCurrentUOffset = (float)CURRENT_OFFSET_MIN;
         }

         /* Limit motor phase B current offset calibration to configured Min/Max levels. */
         if( phaseCurrentVOffset >  (float)CURRENT_OFFSET_MAX)
         {
                  phaseCurrentVOffset = (float)CURRENT_OFFSET_MAX;
         }
         else if(phaseCurrentVOffset <  (float)CURRENT_OFFSET_MIN)
         {
                  phaseCurrentVOffset = (float)CURRENT_OFFSET_MIN;
         }

         gMCCUR_PhaseCurrentOffset.iu_offset = phaseCurrentUOffset;
         gMCCUR_PhaseCurrentOffset.iv_offset = phaseCurrentVOffset;

         /*Set ADC Calibration Done Flag*/
         gMCCUR_PhaseCurrentOffset.Calib_done = 1U;
}


/******************************************************************************/
/* Function name: MCCUR_currMeasurement                                       */
/* Function parameters: none                                                  */
/* Function return: None                                                      */
/* Description:                                                               */
/* Measures current fron current sensors                                      */
/******************************************************************************/
void MCCUR_CurrentMeasurement( tPHASE_CURRENTS_S * const phaseCurrents )
{
         float iu;
         float iv;
      #if( 1U == DUAL_SHUNT )

         /* Get motor currents  */
         iu = ADCHS_ChannelResultGet(PHASE_CURRENT_U);
         iv = ADCHS_ChannelResultGet(PHASE_CURRENT_V);

         /* Current sensor offset correction */
         phaseCurrents->iu = ADC_CURRENT_SCALE * ( gMCCUR_PhaseCurrentOffset.iu_offset - iu );
         phaseCurrents->iv = ADC_CURRENT_SCALE * ( gMCCUR_PhaseCurrentOffset.iv_offset - iv );

         /* Calculate phase W current by Kirchoff's principle  */
         phaseCurrents->iw = -phaseCurrents->iu - phaseCurrents->iv;

      #elif( 1U == SINGLE_SHUNT )
      #else
         assert( ("CURRENT MEASUREMENT TECHNIQUE HAS NOT BEEN SELECTED" , 0 ));
      #endif
}

#endif
#endif
