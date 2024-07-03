/**
 * @file mc_position_control.h
 *
 * @brief 
 *    System Definitions for Position Control
 *
 * @Company 
 *    Microchip Technology Inc.
 *
 * @Summary
 *    Header file containing variables and function prototypes for position control.
 *
 * @Description
 *    This file defines variables and function prototypes typically used for
 *    implementing position control implementations.
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

#ifndef MCSPE_H
#define MCSPE_H

/*******************************************************************************
 * Header inclusions
*******************************************************************************/
#include "mc_types.h"
#include "mc_pi_control.h"

/*******************************************************************************
 Default Module configuration parameters
*******************************************************************************/

/*******************************************************************************
Type Definition
*******************************************************************************/
typedef struct
{
    float32_t Kp;               /**< Proportional gain */
    float32_t Ki;               /**< Integral gain */
    float32_t Ymax;             /**< Maximum motor current */
    float32_t dt;               /**< PWM period */
    void * pStatePointer;       /**< Pointer to state information */
} tmcSpe_Parameters_s;

/*******************************************************************************
 * Interface variables
*******************************************************************************/

/*******************************************************************************
 Static Interface Functions
*******************************************************************************/
/**
 * @brief Set module parameters
 *
 * @details
 * Set module parameters for the speed control.
 *
 * @param[in] pParameters Pointer to the speed control parameters structure.
 */
__STATIC_INLINE void mcSpeI_ParametersSet( tmcSpe_Parameters_s * const pParameters )
{
   pParameters->Kp = (float32_t)${MCPMSMFOC_SPEED_PID_KP};
   pParameters->Ki = (float32_t)${MCPMSMFOC_SPEED_PID_KI};
   pParameters->dt = (float32_t)(${MCPMSMFOC_PWM_PERIOD});
   pParameters->Ymax = (float32_t)(${MCPMSMFOC_MAX_MOTOR_CURRENT});
}

/*******************************************************************************
 Interface Functions
*******************************************************************************/
/**
 * @brief Initialize speed control module
 *
 * @details
 * Initialize speed control module.
 *
 * @param[in] pParameters Pointer to the speed control parameters structure.
 */
void  mcSpeI_SpeedControlInit( tmcSpe_Parameters_s * const pParameters );

/**
 * @brief Enable speed control module
 *
 * @details
 * Enable speed control module.
 *
 * @param[in] pParameters Pointer to the speed control parameters structure.
 */
void  mcSpeI_SpeedControlEnable( tmcSpe_Parameters_s * const pParameters );

/**
 * @brief Disable speed control module
 *
 * @details
 * Disable speed control module.
 *
 * @param[in] pParameters Pointer to the speed control parameters structure.
 */
void  mcSpeI_SpeedControlDisable( tmcSpe_Parameters_s * const pParameters );

/**
 * @brief Manual speed control
 *
 * @details
 * Perform manual speed control.
 *
 * @param[in] pParameters Pointer to the speed control parameters structure.
 * @param[in] Out Output value for speed control.
 */
void mcSpeI_SpeedControlManual(  const tmcSpe_Parameters_s * const pParameters,
                                                         const float32_t  Out );

/**
 * @brief Automatic speed control
 *
 * @details
 * Perform automatic speed control.
 *
 * @param[in] pParameters Pointer to the speed control parameters structure.
 * @param[in] nref Reference speed value.
 * @param[in] nact Actual speed value.
 * @param[out] pOut Pointer to the output speed control value.
 */
void mcSpeI_SpeedControlAuto(  const tmcSpe_Parameters_s * const pParameters,
                                              const float32_t nref, const  float32_t nact, float32_t * const pOut );

/**
 * @brief Reset speed control
 *
 * @details
 * Reset speed control module.
 *
 * @param[in] pParameters Pointer to the speed control parameters structure.
 */
void mcSpeI_SpeedControlReset( const tmcSpe_Parameters_s * const pParameters );

#endif // MCSPE_H
