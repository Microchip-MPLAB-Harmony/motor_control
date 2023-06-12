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

#ifndef MCRPE_H    // Guards against multiple inclusion
#define MCRPE_H

/*******************************************************************************
 Interface Functions
 *******************************************************************************/
#include "mc_types.h"
#include "mc_motor.h"
#include "mc_utilities.h"
#include "mc_key_manager.h"

/*******************************************************************************
 Constants
 *******************************************************************************/

/*******************************************************************************
 User defined data types
 *******************************************************************************/
typedef struct
{
    /** Soft switch parameters */
    float32_t lowerThreshold;
    float32_t upperThreshold;

    tmcMot_PMSM_s  * pMotorParameters;

    /** HFI parameters */
    float32_t pulseAmplitude;
    float32_t foInHertz;
    float32_t Keps;

    /** Sampling time  */
    float32_t dt;

    void * pStatePointer;
}tmcRpe_Parameters_s;

/*******************************************************************************
 Interface variables
 *******************************************************************************/
__STATIC_INLINE void mcRpe_ParametersSet(tmcRpe_Parameters_s * const pParameters )
{
    /** Soft switch parameters */
    pParameters->lowerThreshold = (float32_t)${MCPMSMFOC_ZSMT_HYB_LOWER_TH};
    pParameters->upperThreshold = (float32_t)${MCPMSMFOC_ZSMT_HYB_UPPER_TH};

    pParameters->pMotorParameters = &mcMotI_PMSM_gds;

    /** HFI parameters */
    pParameters->pulseAmplitude = (float32_t)${MCPMSMFOC_ZSMT_HYB_HFI_MAGNITUDE};
    pParameters->foInHertz = (float32_t)${MCPMSMFOC_ZSMT_HYB_ANGLE_TRACK_F0};
    pParameters->Keps = (float32_t)${MCPMSMFOC_ZSMT_HYB_HFI_KEPS};

    /** Sampling time */
    pParameters->dt = (float32_t)(${MCPMSMFOC_PWM_PERIOD});

}

/*******************************************************************************
 Interface Variables
 *******************************************************************************/

/*******************************************************************************
 Interface Functions
 *******************************************************************************/

/*! \brief Initialize rotor position estimation module
 *
 * Details.
 * Initialize rotor position estimation module
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
void  mcRpeI_RotorPositionEstimInit( tmcRpe_Parameters_s * const pParameters );

/*! \brief Enable rotor position estimation module
 *
 * Details.
 * Enable rotor position estimation module
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
void  mcRpeI_RotorPositionEstimEnable( tmcRpe_Parameters_s * const pParameters );

/*! \brief Disable rotor position estimation module
 *
 * Details.
 * Disable rotor position estimation module
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
void  mcRpeI_RotorPositionEstimDisable( tmcRpe_Parameters_s * const pParameters );

/*! \brief Rotor position estimation
 *
 * Details.
 * Rotor position estimation
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
void mcRpeI_RotorPositionEstim(  const tmcRpe_Parameters_s * const pParameters,
                                                     tmcTypes_AlphaBeta_s * pIAlphaBeta,
                                                     tmcTypes_AlphaBeta_s * pUAlphaBeta,
                                                     tmcTypes_AlphaBeta_s * pEAlphaBeta,
                                                     float32_t initialPosition,
                                                     float32_t * pAngle, float32_t * pSpeed );

/*! \brief Carrier Signal Injection
 *
 * Details.
 * Carrier Signal Injection
 *
 * @param[in]:
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcRpeI_CarrierSignalInjection(tmcRpe_Parameters_s * pParameters, tmcTypes_DQ_s * const pUdq );

/*! \brief Reset Rotor position estimation
 *
 * Details.
 * Reset Rotor position estimation
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return:
 */
void mcRpeI_RotorPositionEstimReset( const tmcRpe_Parameters_s * const pParameters );

#endif //MCRPE_H

/**
 End of File
*/
