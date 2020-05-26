/*******************************************************************************
  Speed Source File

  Company:
    Microchip Technology Inc.

  File Name:
    mc_speed.c

  Summary:
    This file contains functions to get the reference motor speed.

  Description:
    This file contains functions to get the reference motor speed.

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
#include "mc_speed.h"
#include "mc_pmsm_foc_common.h"
#include "mc_hal.h"


/******************************************************************************/
/* Local Function Prototype                                                   */
/******************************************************************************/

/******************************************************************************/
/*                   Global Variables                                         */
/******************************************************************************/

tMCSPE_STATE_SIGNAL_S   gMCSPE_StateSignals;
<#if MCPMSMFOC_SPEED_REF_INPUT != "Potentiometer Analog Input">
tMCSPE_INPUT_SIGNAL_S   gMCSPE_InputSignals = {SPEED_REF_RAD_PER_SEC_ELEC};
</#if>
tMCSPE_PARAMETERS_S     gMCSPE_Parameters = {
                                              KFILTER_POT,
                                              POT_ADC_COUNT_FW_SPEED_RATIO,
                                              <#if MCPMSMFOC_POSITION_FB != "SENSORED_ENCODER">
                                              OPEN_LOOP_END_SPEED_RADS_PER_SEC_ELEC
                                              <#else>
                                              0
                                              </#if>
                                            };
tMCSPE_OUTPUT_SIGNAL_S   gMCSPE_OutputSignals;




/******************************************************************************/
/*                          LOCAL  FUNCTIONS                                  */
/******************************************************************************/

/******************************************************************************/
/*                       INTERFACE FUNCTIONS                                  */
/******************************************************************************/
/*****************************************************************************/
/* Function name: MCSPE_InitializeSpeedControl                                    */
/* Function parameters: None                                                 */
/* Function return: None                                                     */
/* Description:                                                              */
/* initialize speed control variables                                             */
/*****************************************************************************/
void  MCSPE_InitializeSpeedControl(void)
{
    /* Initialize speed command function parameters */
    gMCSPE_Parameters.filterParam    =   KFILTER_POT;
    <#if MCPMSMFOC_POSITION_FB == "SENSORED_ENCODER">
    gMCSPE_Parameters.minSpeed       =   0;
    <#else>
    gMCSPE_Parameters.minSpeed       =   OPEN_LOOP_END_SPEED_RADS_PER_SEC_ELEC ;
    </#if>
    gMCSPE_Parameters.pot2SpeedRatio =   POT_ADC_COUNT_FW_SPEED_RATIO;

    /* Initialize speed command function states */
    gMCSPE_StateSignals.potFiltered =  0.0f;
<#if MCPMSMFOC_SPEED_REF_INPUT != "Potentiometer Analog Input">
    gMCSPE_InputSignals.speedRef = SPEED_REF_RAD_PER_SEC_ELEC;
</#if>

}

/*****************************************************************************/
/* Function name: MCSPE_SpeedCommand                                    */
/* Function parameters: None                                                 */
/* Function return: None                                                     */
/* Description:                                                              */
/* Calculate reference speed                                                 */
/*****************************************************************************/
void MCSPE_SpeedCommand( void )
{
<#if MCPMSMFOC_SPEED_REF_INPUT == "Potentiometer Analog Input">

    gMCSPE_OutputSignals.potReading = (float)(MCHAL_ADCChannelResultGet(MCHAL_ADC_POT) >> MCHAL_ADC_RESULT_SHIFT);
    gMCSPE_StateSignals.potFiltered =   gMCSPE_StateSignals.potFiltered
                                  + ((  gMCSPE_OutputSignals.potReading -  gMCSPE_StateSignals.potFiltered ) * gMCSPE_Parameters.filterParam );

    gMCSPE_OutputSignals.commandSpeed = gMCSPE_StateSignals.potFiltered * gMCSPE_Parameters.pot2SpeedRatio;

<#else>
    /* External speed command  */
    gMCSPE_OutputSignals.commandSpeed = gMCSPE_InputSignals.speedRef;

</#if>
<#if MCPMSMFOC_POSITION_FB != "SENSORED_ENCODER">
    /* Restrict velocity reference so motor will be spinning in closed loop. */
    if( gMCSPE_OutputSignals.commandSpeed < gMCSPE_Parameters.minSpeed )
    {
        gMCSPE_OutputSignals.commandSpeed = gMCSPE_Parameters.minSpeed;
    }
</#if>
}


/*****************************************************************************/
/* Function name: MCSPE_ResetSpeedControl                                    */
/* Function parameters: None                                                 */
/* Function return: None                                                     */
/* Description:                                                              */
/* Reset speed control variables                                             */
/*****************************************************************************/
void  MCSPE_ResetSpeedControl(void)
{
    /* Reset speed command function states */
    gMCSPE_StateSignals.potFiltered =  0.0f;
}
