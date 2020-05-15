/*******************************************************************************
 Motor Control current measurement interface file

  Company:
    Microchip Technology Inc.

  File Name:
    mc_currmeasurement.h

  Summary:
    Header file for current measurement

  Description:
    This file contains the data structures and function prototypes of current measurement.
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

#ifndef MCCUR_H    // Guards against multiple inclusion
#define MCCUR_H


// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

/*  This section lists the other files that are included in this file.
*/

#include <stddef.h>

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif

// DOM-IGNORE-END


/******************************************************************************/
/*                          CONFIGURATION PARAMETERS                          */
/******************************************************************************/


/* Motor phase current offset calibration limits. */
#define CURRENT_OFFSET_MAX                (2304) /* current offset max limit in terms of ADC count */
#define CURRENT_OFFSET_MIN                (1792) /* current offset min limit in terms of ADC count */
#define CURRENTS_OFFSET_SAMPLES           (128U) /* Phase Current Offset calibration samples       */


/******************************************************************************/
/*                          USER DEFINED DATATYPES                            */
/******************************************************************************/


typedef struct
{
    float iu;
    float iv;
    float iw;
}tMCCUR_PHASE_CURRENTS_S;

typedef struct
{

}tMCCUR_INPUT_SIGNAL_S;


typedef struct
{
   float minOffset;
   float maxOffset;
}tMCCUR_PARAMETERS_S;

typedef struct
{
    uint32_t  adcSampleCounter;
    uint32_t  phaseUOffsetBuffer;
    uint32_t  phaseVOffsetBuffer;

}tMCCUR_STATE_SIGNAL_S;

typedef struct
{
    tMCCUR_PHASE_CURRENTS_S phaseCurrents;
    float idc;
    float iuOffset;
    float ivOffset;
    uint8_t calibDone;
}tMCCUR_OUTPUT_SIGNAL_S;



/******************************************************************************/
/*                          INTERFACE VARIABLES                               */
/******************************************************************************/
extern tMCCUR_INPUT_SIGNAL_S   gMCCUR_InputSignals;
extern tMCCUR_OUTPUT_SIGNAL_S  gMCCUR_OutputSignals;
extern tMCCUR_STATE_SIGNAL_S   gMCCUR_StateSignals;

/******************************************************************************/
/*                          INTERFACE FUNCTIONS                               */
/******************************************************************************/

void MCCUR_InitializeCurrentMeasurement(void);
void MCCUR_CurrentMeasurement( void );
void MCCUR_OffsetCalibration(void);


// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

}

#endif
// DOM-IGNORE-END

#endif //MCCUR_H

/**
 End of File
*/
