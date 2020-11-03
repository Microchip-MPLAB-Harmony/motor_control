/*******************************************************************************
  motor control current measurement source File

  Company:
    Microchip Technology Inc.

  File Name:
    mc_currentmeasurement.c

  Summary:
    This file contains functions to initilaize, calibrate and measure phase
    currents for motor control application

  Description:
    This file contains functions to initilaize, calibrate and measure phase
    currents for motor control application
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
#include "mc_currmeasurement.h"
#include "mc_generic_lib.h"
#include "assert.h"
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

tMCCUR_INPUT_SIGNAL_S   gMCCUR_InputSignals;
tMCCUR_PARAMETERS_S     gMCCUR_Parameters = {CURRENT_OFFSET_MIN, CURRENT_OFFSET_MAX};
tMCCUR_STATE_SIGNAL_S   gMCCUR_StateSignals;
tMCCUR_OUTPUT_SIGNAL_S  gMCCUR_OutputSignals;


/******************************************************************************/
/*                        LOCAL FUNCTIONS                                     */
/******************************************************************************/

/******************************************************************************/
/* Function name: MCCUR_InitializeCurrentMeasurement                          */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description:                                                               */
/* Performs peripheral initialization for current measurement                 */
/******************************************************************************/
void MCCUR_InitializeCurrentMeasurement( void )
{
    /* Initialize parameters and state variables  */
    gMCCUR_Parameters.maxOffset     = CURRENT_OFFSET_MAX;
    gMCCUR_Parameters.minOffset     = CURRENT_OFFSET_MIN;

    /* Initialize state variables */
    gMCCUR_OutputSignals.calibDone = 0U;
}

/******************************************************************************/
/* Function name: MCCUR_offsetCalibration                                     */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description:                                                               */
/* Calculates current sensors offset                                          */
/******************************************************************************/
void MCCUR_OffsetCalibration( void )
{
  float     phaseCurrentUOffset = 0.0f;
  float     phaseCurrentVOffset = 0.0f;

  if (gMCCUR_StateSignals.adcSampleCounter < CURRENTS_OFFSET_SAMPLES)
  {
      gMCCUR_StateSignals.phaseUOffsetBuffer += (MCHAL_ADCPhaseUResultGet(MCHAL_ADC_PH_U) >> MCHAL_ADC_RESULT_SHIFT);
      gMCCUR_StateSignals.phaseVOffsetBuffer += (MCHAL_ADCPhaseVResultGet(MCHAL_ADC_PH_V) >> MCHAL_ADC_RESULT_SHIFT);
      gMCCUR_StateSignals.adcSampleCounter++;
  }
  else
  {

      phaseCurrentUOffset = (float)(gMCCUR_StateSignals.phaseUOffsetBuffer/CURRENTS_OFFSET_SAMPLES);
      phaseCurrentVOffset = (float)(gMCCUR_StateSignals.phaseVOffsetBuffer/CURRENTS_OFFSET_SAMPLES);

      /* Limit motor phase current offset calibration to configured Min/Max levels. */
      MCLIB_ImposeLimits(&phaseCurrentUOffset, gMCCUR_Parameters.minOffset, gMCCUR_Parameters.maxOffset );
      MCLIB_ImposeLimits(&phaseCurrentVOffset, gMCCUR_Parameters.minOffset, gMCCUR_Parameters.maxOffset );

      gMCCUR_OutputSignals.iuOffset = phaseCurrentUOffset;
      gMCCUR_OutputSignals.ivOffset = phaseCurrentVOffset;

      /*Set ADC Calibration Done Flag*/
      gMCCUR_OutputSignals.calibDone = 1U;

  }
}

/******************************************************************************/
/* Function name: MCCUR_currMeasurement                                       */
/* Function parameters: none                                                  */
/* Function return: None                                                      */
/* Description:                                                               */
/* Measures current fron current sensors                                      */
/******************************************************************************/
void MCCUR_CurrentMeasurement( void )
{
    float iu;
    float iv;
  #if( DUAL_SHUNT == CURRENT_MEASUREMENT )

    /* Get motor currents  */
    iu = MCHAL_ADCPhaseUResultGet(MCHAL_ADC_PH_U) >> MCHAL_ADC_RESULT_SHIFT;
    iv = MCHAL_ADCPhaseVResultGet(MCHAL_ADC_PH_V) >> MCHAL_ADC_RESULT_SHIFT;

    /* Current sensor offset correction */
    gMCCUR_OutputSignals.phaseCurrents.iu = ADC_CURRENT_SCALE * ( gMCCUR_OutputSignals.iuOffset - iu );
    gMCCUR_OutputSignals.phaseCurrents.iv = ADC_CURRENT_SCALE * ( gMCCUR_OutputSignals.ivOffset - iv );

    /* Calculate phase W current by Kirchoff's principle  */
    gMCCUR_OutputSignals.phaseCurrents.iw = -gMCCUR_OutputSignals.phaseCurrents.iu -gMCCUR_OutputSignals.phaseCurrents.iv;

  #else
    assert( ("CURRENT MEASUREMENT TECHNIQUE HAS NOT BEEN SELECTED" , 0 ));
  #endif
}
