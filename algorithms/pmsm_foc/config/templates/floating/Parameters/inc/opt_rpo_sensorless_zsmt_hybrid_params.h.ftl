/**
 * @file mc_rotor_position_parameters.h
 *
 * @brief 
 *    Rotor Position Parameters
 *
 * @Company 
 *    Microchip Technology Inc.
 *
 * @Summary
 *    Header file containing data structures and function prototypes for rotor position.
 *
 * @Description
 *    This file defines the data structures and function prototypes used for
 *    managing rotor position in motor control applications.
 */

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
 * User defined data types
 ******************************************************************************/

typedef struct {
    bool reinitialize;                     /*!< Flag to reinitialize */
    float32_t iHFI;                        /*!< High-Frequency Injection current */
    float32_t angleFromHFIObserver;        /*!< Angle from HFI observer */
    float32_t angleFromBEMFObserver;       /*!< Angle from BEMF observer */
} tmcTune_HFITuning_s;

typedef struct {
    float32_t foInHertz;                   /*!< Frequency in Hertz */
    float32_t Keps;                        /*!< Keps parameter */
} tmcRpe_TrackingLoopParams_s;

typedef struct {
    float32_t pulseAmplitude;              /*!< Pulse amplitude */
} tmcRpe_HFIParameters_s;

typedef struct {
    float32_t pulseAmplitude;              /*!< Pulse amplitude */
    float32_t pulseDuty;                   /*!< Pulse duty cycle */
    float32_t pulseDuration;               /*!< Pulse duration */
} tmcRpe_IPCParameters_s;

typedef struct {
    /** Soft switch parameters */
    float32_t lowerThreshold;              /*!< Lower threshold */
    float32_t upperThreshold;              /*!< Upper threshold */

    tmcMot_PMSM_s * pMotorParameters;      /*!< Pointer to motor parameters */

    /** HFI parameters */
    tmcRpe_HFIParameters_s hfiParameters;  /*!< HFI parameters */

    /** IPC Parameters */
    tmcRpe_IPCParameters_s ipcParameters;  /*!< IPC parameters */

    /** HFI tracking loop parameters */
    tmcRpe_TrackingLoopParams_s hfiTrackingLoop;  /*!< HFI tracking loop parameters */

    /** BEMF tracking loop parameters */
    tmcRpe_TrackingLoopParams_s bemfTrackingLoop; /*!< BEMF tracking loop parameters */

    /** Mechanical Gear Ratio */
    uint8_t gearRatio;                     /*!< Mechanical gear ratio */

    /** Sampling time */
    float32_t dt;                          /*!< Sampling time */
} tmcRpe_Parameters_s;

/*******************************************************************************
 * Interface variables
 ******************************************************************************/

extern tmcTune_HFITuning_s mcRpeI_TuningSettings_gds;  /*!< Global tuning settings */

extern tmcRpe_Parameters_s mcRpeI_Parameters_gds;     /*!< Global parameters */

/*******************************************************************************
 * Interface Functions
 ******************************************************************************/
 /** 
 * @brief Set rotor position estimation parameters
 *
 * @details 
 *   This function sets the parameters for rotor position estimation module.
 *
 * @param[in] pParameters Pointer to the parameters structure.
 * @return None
 */
void mcRpeI_ParametersSet(tmcRpe_Parameters_s * const pParameters );

#endif //MCRPE_PARAMS_H

/**
 End of File
*/
