/**
 * @brief 
 *    Motor parameters
 *
 * @File Name 
 *    mc_motor.h
 *
 * @Company 
 *    Microchip Technology Inc.
 *
 * @Summary
 *    This file contains definitions for motor data and parameters.
 *
 * @Description
 *    This file provides the implementation of structures and functions necessary for 
 *    defining and managing motor parameters. It includes the initialization and setting
 *    of motor parameters such as resistance, inductance, pole pairs, back EMF constant, 
 *    maximum and rated speeds, and motor inertia.
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

#ifndef MCMOTOR_H
#define MCMOTOR_H

/*******************************************************************************
 Header File inclusions
 *******************************************************************************/
#include <stddef.h>
#include <stdint.h>
#include "mc_userparams.h"
#include "mc_types.h"
/*******************************************************************************
 Parameters
 *******************************************************************************/

/*******************************************************************************
 Default module parameters
 *******************************************************************************/

/*******************************************************************************
 Module data type
 *******************************************************************************/
/**
 * @brief Structure defining the PMSM motor parameters.
 */
typedef struct
{
    float32_t PolePairs;           /**< Number of pole pairs */
    float32_t RsInOhms;            /**< Per phase resistance in Ohms */
    float32_t LdInHenry;           /**< Direct axis inductance in Henry */
    float32_t LqInHenry;           /**< Quadrature axis inductance in Henry */
    float32_t KeInVrmsPerKrpm;     /**< Back EMF constant in Vrms per krpm */
    float32_t IrmsMaxInAmps;       /**< Maximum RMS current in Amps */
    float32_t JmInKgPerCmSquare;   /**< Motor inertia in Kg/cm^2 */
    float32_t NmaxInRpm;           /**< Maximum speed in RPM */
    float32_t NratedInRpm;         /**< Rated speed in RPM */
} tmcMot_PMSM_s;

/*******************************************************************************
 Interface variables
 *******************************************************************************/
/** Global instance of the PMSM motor parameters structure */
extern tmcMot_PMSM_s mcMotI_PMSM_gds;

/*******************************************************************************
 Static Functions
 *******************************************************************************/
/**
 * @brief Set PMSM motor parameters
 *
 * This function sets the PMSM motor parameters.
 *
 * @param[in] pParameters Pointer to the PMSM motor parameters structure
 *
 * @note
 * - RsInOhms: Per phase resistance in Ohms
 * - LdInHenry: Direct axis inductance in Henry
 * - LqInHenry: Quadrature axis inductance in Henry
 * - PolePairs: Number of pole pairs
 * - KeInVrmsPerKrpm: Back EMF constant in Vrms per krpm
 * - IrmsMaxInAmps: Maximum RMS current in Amps
 * - NmaxInRpm: Maximum speed in RPM
 * - NratedInRpm: Rated speed in RPM
 * - JmInKgPerCmSquare: Motor inertia in Kg/cm^2
 */
static inline void mcMotI_ParametersSet(tmcMot_PMSM_s * const pParameters)
{
    pParameters->RsInOhms = (float32_t)(${MCPMSMFOC_R});
    pParameters->LdInHenry = (float32_t)(${MCPMSMFOC_LD});
    pParameters->LqInHenry = (float32_t)(${MCPMSMFOC_LQ});
    pParameters->PolePairs = (float32_t)(${MCPMSMFOC_POLE_PAIRS});
    pParameters->KeInVrmsPerKrpm = (float32_t)(${MCPMSMFOC_BEMF_CONST});
    pParameters->IrmsMaxInAmps = (float32_t)(${MCPMSMFOC_MAX_MOTOR_CURRENT});
    pParameters->NratedInRpm = (float32_t)(${MCPMSMFOC_RATED_SPEED});
    pParameters->NmaxInRpm = (float32_t)(${MCPMSMFOC_MAX_SPEED});
    pParameters->JmInKgPerCmSquare = 0.2f;
}

/*******************************************************************************
 Interface Functions
 *******************************************************************************/
/**
 * @brief Motor parameters initialization
 *
 * This function initializes the motor parameters.
 *
 * @param[in] pParameters Pointer to the PMSM motor parameters structure
 */
void mcMotI_MotorParametersInit(tmcMot_PMSM_s * const pParameters);

#endif /* MCMOTOR_H */

