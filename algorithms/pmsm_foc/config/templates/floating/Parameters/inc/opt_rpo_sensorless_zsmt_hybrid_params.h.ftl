/*******************************************************************************
 Rotor Position interface file

  Company:
    Microchip Technology Inc.

  File Name:
    mc_rotor_position.h

  Summary:
    Header file for rotor position

  Description:
    This file contains the data structures and function prototypes of rotor position.
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

#ifndef MCRPE_PARAMS_H    // Guards against multiple inclusion
#define MCRPE_PARAMS_H

/*******************************************************************************
 Interface Functions
 *******************************************************************************/
#include "mc_types.h"
#include "mc_motor.h"

/*******************************************************************************
 Constants
 *******************************************************************************/

/*******************************************************************************
 User defined data types
 *******************************************************************************/
 typedef struct {
    bool reinitialize;
    float32_t iHFI;
    float32_t angleFromHFIObserver;
    float32_t angleFromBEMFObserver;
 }tmcTune_HFITuning_s;

 typedef struct
 {
    float32_t foInHertz;
    float32_t Keps;
 }tmcRpe_TrackingLoopParams_s;

 typedef struct
 {
    float32_t pulseAmplitude;
 }tmcRpe_HFIParameters_s;

 typedef struct
 {
    float32_t pulseAmplitude;
    float32_t pulseDuty;
    float32_t pulseDuration;
 }tmcRpe_IPCParameters_s;
 
typedef struct
{
    /** Soft switch parameters */
    float32_t lowerThreshold;
    float32_t upperThreshold;

    tmcMot_PMSM_s  * pMotorParameters;

    /** HFI parameters */
    tmcRpe_HFIParameters_s hfiParameters;

    /** IPC Parameters */
    tmcRpe_IPCParameters_s ipcParameters;

    /** HFI tracking loop parameters */
    tmcRpe_TrackingLoopParams_s  hfiTrackingLoop;

    /** BEMF tracking loop parameters */
    tmcRpe_TrackingLoopParams_s  bemfTrackingLoop;

    /** Mechanical Gear Ratio */
    uint8_t gearRatio;

    /** Sampling time  */
    float32_t dt;

}tmcRpe_Parameters_s;

/*******************************************************************************
 Interface variables
 *******************************************************************************/
 extern tmcTune_HFITuning_s  mcRpeI_TuningSettings_gds;
 extern tmcRpe_Parameters_s  mcRpeI_Parameters_gds;

/*******************************************************************************
 Interface Variables
 *******************************************************************************/


/*******************************************************************************
 Interface Functions
 *******************************************************************************/
void mcRpeI_ParametersSet(tmcRpe_Parameters_s * const pParameters );

#endif //MCRPE_PARAMS_H

/**
 End of File
*/
