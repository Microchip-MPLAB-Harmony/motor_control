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

//DOM-IGNORE-BEGIN
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
//DOM-IGNORE-END

#ifndef MCRPE_H
#define MCRPE_H

/*******************************************************************************
 * Header inclusions
*******************************************************************************/
#include "mc_types.h"
#include "mc_motor.h"
#include "mc_utilities.h"

/*******************************************************************************
 Default Module configuration parameters
*******************************************************************************/

/*******************************************************************************
Type Definition
*******************************************************************************/
typedef struct
{
/** Motor parameters */
    tmcMot_PMSM_s  * pMotorParameters;

    /** BEMF observer parameters */
    float32_t lambda;
    float32_t f0InHertz;
    float32_t minRPM;
    float32_t dt;

    void * pStatePointer;
}tmcRpe_Parameters_s;

/*******************************************************************************
 * Interface variables
*******************************************************************************/

/*******************************************************************************
 Static Interface Functions
*******************************************************************************/
/*! 
 * @brief Set module parameters
 *
 * @details
 * Set module parameters
 *
 * @param[in] pParameters - Pointer to parameters structure
 *
 * @return None
 */
__STATIC_INLINE void mcRpeI_ParametersSet( tmcRpe_Parameters_s * const pParameters )
{
    /** Motor parameters */
    pParameters->pMotorParameters = &mcMotI_PMSM_gds;

    /** BEMF observer parameters */
    pParameters->dt = (float32_t)${MCPMSMFOC_PWM_PERIOD};
    pParameters->lambda = (float32_t)${MCPMSMFOC_BEMF_OBSERVER_ROLO_POLE};
    pParameters->f0InHertz = (float32_t)${MCPMSMFOC_ROLO_PHASE_DETECTION_F0};
    pParameters->minRPM = (float32_t)(${MCPMSMFOC_OPEN_LOOP_END_SPEED});
}

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
                                                     const float32_t refSpeed,
                                                     const tmcTypes_AlphaBeta_s * pIAlphaBeta,
                                                     const tmcTypes_AlphaBeta_s * pUAlphaBeta,
                                                     tmcTypes_AlphaBeta_s * pEAlphaBeta,
                                                     float32_t * pAngle, float32_t * pSpeed );

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

#endif // MCRPE_H
