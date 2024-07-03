/**
 * @brief 
 *    Header file for rotor position estimation
 *
 * @File Name 
 *    mc_rotor_position_estimation.h
 *
 * @Company 
 *    Microchip Technology Inc.
 *
 * @Summary
 *    Header file containing variables and function prototypes for rotor position estimation.
 *
 * @Description
 *    This file contains variables and function prototypes which are generally used for rotor
 *    position estimation in pulse width modulation. It is implemented in Q2.14 fixed point arithmetic.
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
/*! 
 * @brief Initialize rotor position estimation module
 *
 * @details
 * Initialize rotor position estimation module
 *
 * @param[in] pParameters - Pointer to parameters structure
 *
 * @return None
 */
void  mcRpeI_RotorPositionEstimInit( tmcRpe_Parameters_s * const pParameters );

/*! 
 * @brief Enable rotor position estimation module
 *
 * @details
 * Enable rotor position estimation module
 *
 * @param[in] pParameters - Pointer to parameters structure
 *
 * @return None
 */
void  mcRpeI_RotorPositionEstimEnable( tmcRpe_Parameters_s * const pParameters );

/*! 
 * @brief Disable rotor position estimation module
 *
 * @details
 * Disable rotor position estimation module
 *
 * @param[in] pParameters - Pointer to parameters structure
 *
 * @return None
 */
void  mcRpeI_RotorPositionEstimDisable( tmcRpe_Parameters_s * const pParameters );

/*! 
 * @brief Perform rotor position estimation
 *
 * @details
 * Perform rotor position estimation
 *
 * @param[in] pParameters - Pointer to parameters structure
 * @param[in] pIAlphaBeta - Pointer to input alpha-beta voltages
 * @param[in] pUAlphaBeta - Pointer to input alpha-beta currents
 * @param[out] pEAlphaBeta - Pointer to store estimated alpha-beta bemf
 * @param[out] pAngle - Pointer to store estimated rotor angle
 * @param[out] pSpeed - Pointer to store estimated rotor speed
 *
 * @return None
 */
void mcRpeI_RotorPositionEstim(  const tmcRpe_Parameters_s * const pParameters,
                                                     tmcTypes_AlphaBeta_s * pIAlphaBeta,
                                                     tmcTypes_AlphaBeta_s * pUAlphaBeta,
                                                     tmcTypes_AlphaBeta_s * pEAlphaBeta,
                                                     float32_t * pAngle, float32_t * pSpeed );

 /*! 
 * @brief Get electrical angle
 *
 * @details
 * Get electrical angle
 *
 * @param[in] pParameters - Pointer to parameters structure
 *
 * @return Electrical angle of the motor
 */
float32_t mcRpeI_ElectricalAngleGet(  const tmcRpe_Parameters_s * const pParameters );

 /*! 
 * @brief Get electrical speed
 *
 * @details
 * Get electrical speed
 *
 * @param[in] pParameters - Pointer to parameters structure
 *
 * @return Electrical speed of the motor
 */
float32_t mcRpeI_ElectricalSpeedGet(  const tmcRpe_Parameters_s * const pParameters );

 /*! 
 * @brief Get mechanical angle
 *
 * @details
 * Get mechanical angle
 *
 * @param[in] pParameters - Pointer to parameters structure
 *
 * @return Mechanical angle of the motor
 */
float32_t mcRpeI_MechanicalAngleGet(  const tmcRpe_Parameters_s * const pParameters );

/*! 
 * @brief Get mechanical speed
 *
 * @details
 * Get mechanical speed
 *
 * @param[in] pParameters - Pointer to parameters structure
 *
 * @return Mechanical speed of the motor
 */
float32_t mcRpeI_MechanicalSpeedGet(  const tmcRpe_Parameters_s * const pParameters );

/*! 
 * @brief Check if rotor position estimation is ready 
 *
 * @details
 * Check if rotor position estimation is ready 
 *
 * @param[in] pParameters - Pointer to parameters structure
 *
 * @return True if rotor position is ready. False if rotor position is not ready
 */
 bool mcRpeI_RotorPositionReady(  const tmcRpe_Parameters_s * const pParameters );
 
/*! 
 * @brief Inject HF pulse to the DQ axis voltage
 *
 * @details
 * Inject HF pulse to the DQ axis voltage
 *
 * @param[in] pParameters - Pointer to parameters structure
 * @param[out] pUdq - DQ axis voltage with HF injection
 *
 * @return None
 */
void mcRpeI_CarrierSignalInjection(tmcRpe_Parameters_s * pParameters, tmcTypes_DQ_s * const pUdq );

/*! 
 * @brief Reset rotor position estimation module
 *
 * @details
 * Reset rotor position estimation module
 *
 * @param[in] pParameters - Pointer to parameters structure
 *
 * @return None
 */
void mcRpeI_RotorPositionEstimReset( const tmcRpe_Parameters_s * const pParameters );

#endif //MCRPE_H

/**
 End of File
*/
