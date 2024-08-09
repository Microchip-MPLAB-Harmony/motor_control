/**
 * @file mc_torque_control.h
 *
 * @brief 
 *    System Definitions for Torque Control
 *
 * @Company 
 *    Microchip Technology Inc.
 *
 * @Summary
 *    Header file containing variables and function prototypes for torque control.
 *
 * @Description
 *    This file defines variables and function prototypes typically used for
 *    implementing torque control in motor control applications.
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

#ifndef MCTOR_H
#define MCTOR_H

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
/**
 * @brief 
 *    Type Definition for Torque Control Parameters
 *
 * @details
 *    Defines the structure for storing parameters used in torque control.
 */
typedef struct
{
    float32_t Kp;             /**< Proportional gain for torque control */
    float32_t Ki;             /**< Integral gain for torque control */
    float32_t dt;             /**< Time step for torque control */
    void * pStatePointer;     /**< Pointer to state information for torque control */
} tmcTor_Parameters_s;

/*******************************************************************************
 * Interface variables
*******************************************************************************/

/*******************************************************************************
 Static Interface Functions
*******************************************************************************/
/**
 * @brief 
 *    Set module parameters
 *
 * @details
 *    Sets the module parameters based on configuration.
 *
 * @param[in] pParameters - Pointer to the parameters structure.
 */
__STATIC_INLINE void mcTorI_ParametersSet( tmcTor_Parameters_s * const pParameters )
{
   pParameters->Kp = (float32_t)${MCPMSMFOC_IQ_PID_KP};
   pParameters->Ki =  (float32_t)${MCPMSMFOC_IQ_PID_KI};
   pParameters->dt =  (float32_t)(${MCPMSMFOC_PWM_PERIOD});
}

/*******************************************************************************
 Interface Functions
*******************************************************************************/
/**
 * @brief 
 *    Initialize torque control module
 *
 * @details
 *    Initializes the torque control module.
 *
 * @param[in] pParameters - Pointer to the parameters structure.
 */
void  mcTorI_TorqueControlInit( tmcTor_Parameters_s * const pParameters );

/**
 * @brief 
 *    Enable torque control module
 *
 * @details
 *    Enables the torque control module.
 *
 * @param[in] pParameters - Pointer to the parameters structure.
 */
void  mcTorI_TorqueControlEnable( tmcTor_Parameters_s * const pParameters );

/**
 * @brief 
 *    Disable torque control module
 *
 * @details
 *    Disables the torque control module.
 *
 * @param[in] pParameters - Pointer to the parameters structure.
 */
void  mcTorI_TorqueControlDisable( tmcTor_Parameters_s * const pParameters );

/**
 * @brief 
 *    Manual torque control
 *
 * @details
 *    Implements manual torque control.
 *
 * @param[in] pParameters - Pointer to the parameters structure.
 * @param[in] Out - Output torque value.
 */
void mcTorI_TorqueControlManual(  const tmcTor_Parameters_s * const pParameters,
                                                         const float32_t  Out );

/**
 * @brief 
 *    Automatic torque control
 *
 * @details
 *    Implements automatic torque control.
 *
 * @param[in] pParameters - Pointer to the parameters structure.
 * @param[in] iQref - Reference current.
 * @param[in] iQact - Actual current.
 * @param[out] pOut - Pointer to the output torque value.
 */
void mcTorI_TorqueControlAuto(  const tmcTor_Parameters_s * const pParameters,
                                              const float32_t iQref, const float32_t iQact, const float32_t iQmax, float32_t * const pOut );

/**
 * @brief 
 *    Reset torque control
 *
 * @details
 *    Resets the torque control module.
 *
 * @param[in] pParameters - Pointer to the parameters structure.
 */
void mcTorI_TorqueControlReset( const tmcTor_Parameters_s * const pParameters );

#endif // MCTOR_H
