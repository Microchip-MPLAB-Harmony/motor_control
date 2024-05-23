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
#include "mc_rotor_position_parameters.h"

/*******************************************************************************
 Constants
 *******************************************************************************/

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
                                                     float32_t * pAngle, float32_t * pSpeed );

/*! \brief Get the electrical angle of the motor
 *
 * Details.
 *  Get the electrical angle of the motor
 *
 * @param[in]:
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
float32_t mcRpeI_ElectricalAngleGet(  const tmcRpe_Parameters_s * const pParameters );

/*! \brief Get the electrical speed of the motor
 *
 * Details.
 *  Get the electrical speed of the motor
 *
 * @param[in]:
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
float32_t mcRpeI_ElectricalSpeedGet(  const tmcRpe_Parameters_s * const pParameters );

/*! \brief Get mechanical angle
 *
 * Details.
 * Get mechanical angle
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
float32_t mcRpeI_MechanicalAngleGet(  const tmcRpe_Parameters_s * const pParameters );

/*! \brief Get mechanical angle
 *
 * Details.
 * Get mechanical angle
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
float32_t mcRpeI_MechanicalSpeedGet(  const tmcRpe_Parameters_s * const pParameters );

/*! \brief Check if rotor position estimation is ready 
 *
 * Details.
 * Check if rotor position estimation is ready 
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
 bool mcRpeI_RotorPositionReady(  const tmcRpe_Parameters_s * const pParameters );
 
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
