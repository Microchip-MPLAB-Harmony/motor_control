/*******************************************************************************
  Rotor Position Source File

  Company:
    Microchip Technology Inc.

  File Name:
    mc_rotor_position.c

  Summary:
    This file contains functions to get the rotor position of a motor

  Description:
    This file contains functions to get the rotor position of a motor
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2022 Microchip Technology Inc. and its subsidiaries.
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
#include "mc_rotor_position_parameters.h"

/*******************************************************************************
 Configuration parameters
 *******************************************************************************/

/*******************************************************************************
 Private data-types
 *******************************************************************************/
 
/*******************************************************************************
 Constants
 *******************************************************************************/

/*******************************************************************************
 Function macros
 *******************************************************************************/

/*******************************************************************************
 Private variables
 *******************************************************************************/
tmcRpe_Parameters_s  mcRpeI_Parameters_gds;
tmcTune_HFITuning_s  mcRpeI_TuningSettings_gds;

/*******************************************************************************
 Interface Variables
 *******************************************************************************/
void mcRpeI_ParametersSet(tmcRpe_Parameters_s * const pParameters )
{
    /** Soft switch parameters */
    pParameters->lowerThreshold = (float32_t)${MCPMSMFOC_ZSMT_HYB_LOWER_TH};
    pParameters->upperThreshold = (float32_t)${MCPMSMFOC_ZSMT_HYB_UPPER_TH};

    pParameters->pMotorParameters = &mcMotI_PMSM_gds;

    /** HFI parameters */
    pParameters->hfiParameters.pulseAmplitude = (float32_t)${MCPMSMFOC_ZSMT_HYB_HFI_MAGNITUDE};

    /** IPC parameters */
    pParameters->ipcParameters.pulseAmplitude = (float32_t)${MCPMSMFOC_IPC_PULSE_MAGNITUDE};
    pParameters->ipcParameters.pulseDuty = (float32_t)${MCPMSMFOC_IPC_PULSE_DUTY};
    pParameters->ipcParameters.pulseDuration = (float32_t)${MCPMSMFOC_IPC_PULSE_DURATION};

    /** HFI Tracking loop parameters */
    pParameters->hfiTrackingLoop.foInHertz = (float32_t)${MCPMSMFOC_ZSMT_HYB_ANGLE_TRACK_F0};
    pParameters->hfiTrackingLoop.Keps = (float32_t)${MCPMSMFOC_ZSMT_HYB_HFI_KEPS};

    /** BEMF Tracking loop parameters */
    pParameters->bemfTrackingLoop.foInHertz = (float32_t)${MCPMSMFOC_BEMF_ANGLE_TRACK_F0};
    pParameters->bemfTrackingLoop.Keps = (float32_t)${MCPMSMFOC_BEMF_KEPS};

    /** Sampling time */
    pParameters->dt = (float32_t)(${MCPMSMFOC_PWM_PERIOD});

    /** Mechanical Gear Ratio */
    pParameters->gearRatio = (uint8_t)2;
}
