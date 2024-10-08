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
 *    position estimation in pulse width modulation. 
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
#include "mc_pi_control.h"
#include "mc_userparams.h"

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
    float32_t Ke;              /**< BEMF observer gain */
    float32_t dt;              /**< Sampling time */

    /** PLL observer parameters */
    float32_t calibTimeInSec;  /**< Offset calibration time */
    float32_t foInHertz;  /**< PLL cut-off frequency */
    void * pStatePointer;      /**< Pointer to module state */
} tmcRpe_Parameters_s;

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
    pParameters->Ke = (float32_t)${MCPMSMFOC_BEMF_CONST};
    pParameters->dt = (float32_t)${MCPMSMFOC_PWM_PERIOD};
    pParameters->calibTimeInSec = (float32_t)(1.0);

    /** PLL parameters */
    pParameters->foInHertz = (float32_t)40;
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
void mcRpeI_RotorPositionEstimInit( tmcRpe_Parameters_s * const pParameters );

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
void mcRpeI_RotorPositionEstimEnable( tmcRpe_Parameters_s * const pParameters );

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
void mcRpeI_RotorPositionEstimDisable( tmcRpe_Parameters_s * const pParameters );

/*! 
 * @brief Perform rotor position estimation
 *
 * @details
 * Perform rotor position estimation
 *
 * @param[in] pParameters - Pointer to parameters structure
 * @param[in] pIAlphaBeta - Pointer to input alpha-beta voltages
 * @param[in] pUAlphaBeta - Pointer to input alpha-beta currents
 * @param[out] pAngle - Pointer to store estimated rotor angle
 * @param[out] pSpeed - Pointer to store estimated rotor speed
 *
 * @return None
 */
#ifdef RAM_EXECUTE
void __ramfunc__  mcRpeI_RotorPositionEstim( const tmcRpe_Parameters_s * const pParameters,
                                          const tmcTypes_AlphaBeta_s * pIAlphaBeta,
                                          const tmcTypes_AlphaBeta_s * pUAlphaBeta,
                                          tmcTypes_AlphaBeta_s * const pEAlphaBeta,
                                          uint16_t * pAngle, int16_t * pSpeed  );
#else
void mcRpeI_RotorPositionEstim(  const tmcRpe_Parameters_s * const pParameters,
                              const tmcTypes_AlphaBeta_s * pIAlphaBeta,
                              const tmcTypes_AlphaBeta_s * pUAlphaBeta,
                              tmcTypes_AlphaBeta_s * const pEAlphaBeta,
                              uint16_t * pAngle, int16_t * pSpeed );
#endif

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
