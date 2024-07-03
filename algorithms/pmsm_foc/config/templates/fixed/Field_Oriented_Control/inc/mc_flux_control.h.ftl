/**
 * @brief 
 *    Flux Control header file
 *
 * @File Name 
 *    mc_flux_control.h
 *
 * @Company 
 *   Microchip Technology Inc.
 *
 * @Summary
 *    This file contains declarations for flux control functions.
 *
 * @Description
 *    This file provides the function prototypes and data structures necessary for flux 
 *    control in motor control applications. Functions include initialization, enabling,
 *    disabling, and various control functions for manual and automatic flux control.
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

#ifndef MCFLX_H
#define MCFLX_H

/*******************************************************************************
 * Header Inclusions
*******************************************************************************/
#include "mc_types.h"
#include "mc_pi_control.h"
#include "mc_userparams.h"
#include "mc_motor.h"

/*******************************************************************************
 * Default Module Configuration Parameters
*******************************************************************************/

/*******************************************************************************
 * Type Definitions
*******************************************************************************/
typedef struct
{
    float32_t Kp;                    /**< Proportional gain for PI controller */
    float32_t Ki;                    /**< Integral gain for PI controller */
    float32_t dt;                    /**< Sampling time */
<#if ( MCPMSMFOC_ENABLE_MTPA == true ) || ( MCPMSMFOC_ENABLE_FW == true) >
    tmcMot_PMSM_s * pMotorParameters; /**< Pointer to motor parameters */
</#if>
    void * pStatePointer;            /**< Pointer to the state structure */
} tmcFlx_Parameters_s;

/*******************************************************************************
 * Interface Variables
*******************************************************************************/
//#define RAM_EXECUTE
/*******************************************************************************
 * Static Interface Functions
*******************************************************************************/
/*! 
 * @brief Set module parameters
 *
 * This function sets the parameters for the flux control module.
 *
 * @param[in] pParameters Pointer to module parameters structure
 * @return None
 */
__STATIC_INLINE void mcFlxI_ParametersSet(tmcFlx_Parameters_s * const pParameters)
{
    pParameters->Kp = (float32_t)${MCPMSMFOC_ID_PID_KP};
    pParameters->Ki = (float32_t)${MCPMSMFOC_ID_PID_KI};
    pParameters->dt = (float32_t)${MCPMSMFOC_PWM_PERIOD};

<#if MCPMSMFOC_ENABLE_MTPA == true >
    pParameters->pMotorParameters = &mcMotI_PMSM_gds;
</#if>

<#if MCPMSMFOC_ENABLE_FW == true >
    pParameters->pMotorParameters = &mcMotI_PMSM_gds;
    pParameters->maxNegativeCurrentInAmps = (float)(${MCPMSMFOC_FW_MAX_NEGATIVE_ID});
</#if>
}

/*******************************************************************************
 * Interface Functions
*******************************************************************************/
/*! 
 * @brief Initialize flux control module
 *
 * Initializes the flux control module.
 *
 * @param[in] pParameters Pointer to module parameters structure
 * @return None
 */
void mcFlxI_FluxControlInit(tmcFlx_Parameters_s * const pParameters);

/*! 
 * @brief Enable flux control module
 *
 * Enables the flux control module.
 *
 * @param[in] pParameters Pointer to module parameters structure
 * @return None
 */
void mcFlxI_FluxControlEnable(tmcFlx_Parameters_s * const pParameters);

/*! 
 * @brief Disable flux control module
 *
 * Disables the flux control module.
 *
 * @param[in] pParameters Pointer to module parameters structure
 * @return None
 */
void mcFlxI_FluxControlDisable(tmcFlx_Parameters_s * const pParameters);

/*! 
 * @brief Manual flux control
 *
 * Performs manual flux control.
 *
 * @param[in] pParameters Pointer to module parameters structure
 * @param[in] Out Output value for manual control
 * @return None
 */
#ifdef RAM_EXECUTE
void __ramfunc__ mcFlxI_FluxControlManual(const tmcFlx_Parameters_s * const pParameters, const int16_t Out);
#else
void mcFlxI_FluxControlManual(const tmcFlx_Parameters_s * const pParameters, const int16_t Out);
#endif

/*! 
 * @brief Automatic flux control
 *
 * Performs automatic flux control.
 *
 * @param[in] pParameters Pointer to module parameters structure
 * @param[in] iDref Reference d-axis current
 * @param[in] iDact Actual d-axis current
 * @param[out] pOut Pointer to output variable for automatic control
 * @return None
 */
#ifdef RAM_EXECUTE
void __ramfunc__ mcFlxI_FluxControlAuto(const tmcFlx_Parameters_s * const pParameters, const int16_t iDref, const int16_t iDact, int16_t * const pOut);
#else
void mcFlxI_FluxControlAuto(const tmcFlx_Parameters_s * const pParameters, const int16_t iDref, const int16_t iDact, int16_t * const pOut);
#endif

/*! 
 * @brief Reset flux control
 *
 * Resets the flux control module.
 *
 * @param[in] pParameters Pointer to module parameters structure
 * @return None
 */
void mcFlxI_FluxControlReset(const tmcFlx_Parameters_s * const pParameters);

<#if MCPMSMFOC_ENABLE_FW == true >
/*! 
 * @brief Enable flux weakening module
 *
 * Enables the flux weakening module.
 *
 * @param[in] pParameters Pointer to module parameters structure
 * @return None
 */
void mcFlxI_FluxWeakeningEnable(tmcFlx_Parameters_s * const pParameters);

/*! 
 * @brief Disable flux weakening module
 *
 * Disables the flux weakening module.
 *
 * @param[in] pParameters Pointer to module parameters structure
 * @return None
 */
void mcFlxI_FluxWeakeningDisable(tmcFlx_Parameters_s * const pParameters);

/*! 
 * @brief Initialize flux weakening module
 *
 * Initializes the flux weakening module.
 *
 * @param[in] pParameters Pointer to module parameters structure
 * @return None
 */
void mcFlxI_FluxWeakeningInit(tmcFlx_Parameters_s * const pParameters);

<#if MCPMSMFOC_POSITION_CALC_ALGORITHM == 'SENSORED_ENCODER'>
/*! 
 * @brief Flux weakening control
 *
 * Performs flux weakening control using sensorless encoder algorithm.
 *
 * @param[in] pParameters Pointer to module parameters structure
 * @param[in] pUDQ Pointer to DQ voltage vector
 * @param[in] uBus DC bus voltage
 * @param[in] wmechRPM Mechanical speed in RPM
 * @param[out] pIDQ Pointer to output DQ current vector
 * @param[out] pIdref Pointer to output reference ID current
 * @return None
 */
#ifdef RAM_EXECUTE
void __ramfunc__ mcFlxI_FluxWeakening(const tmcFlx_Parameters_s * const pParameters, const tmcTypes_DQ_s * const pUDQ, const float32_t uBus, const float32_t wmechRPM, tmcTypes_DQ_s * const pIDQ, float32_t * const pIdref);
#else
void mcFlxI_FluxWeakening(const tmcFlx_Parameters_s * const pParameters, const tmcTypes_DQ_s * const pUDQ, const float32_t uBus, const float32_t wmechRPM, tmcTypes_DQ_s * const pIDQ, float32_t * const pIdref);
#endif
<#else>
/*! 
 * @brief Flux weakening control
 *
 * Performs flux weakening control using other algorithms.
 *
 * @param[in] pParameters Pointer to module parameters structure
 * @param[in] pUDQ Pointer to DQ voltage vector
 * @param[in] pEAlphaBeta Pointer to Alpha-Beta voltage vector
 * @param[in] uBus DC bus voltage
 * @param[in] wmechRPM Mechanical speed in RPM
 * @param[out] pIDQ Pointer to output DQ current vector
 * @param[out] pIdref Pointer to output reference ID current
 * @return None
 */
#ifdef RAM_EXECUTE
void __ramfunc__ mcFlxI_FluxWeakening(const tmcFlx_Parameters_s * const pParameters, const tmcTypes_DQ_s * const pUDQ, const tmcTypes_AlphaBeta_s * const pEAlphaBeta, const int16_t uBus, const int16_t wmechRPM, tmcTypes_DQ_s * const pIDQ, int16_t * const pIdref);
#else
void mcFlxI_FluxWeakening(const tmcFlx_Parameters_s * const pParameters, const tmcTypes_DQ_s * const pUDQ, const tmcTypes_AlphaBeta_s * const pEAlphaBeta, const int16_t uBus, const int16_t wmechRPM, tmcTypes_DQ_s * const pIDQ, int16_t * const pIdref);
#endif
</#if>

/*! 
 * @brief Reset flux weakening module
 *
 * Resets the flux weakening module.
 *
 * @param[in] pParameters Pointer to module parameters structure
 * @return None
 */
void mcFlxI_FluxWeakeningReset(const tmcFlx_Parameters_s * const pParameters);
</#if>

<#if MCPMSMFOC_ENABLE_MTPA == true >
/*! 
 * @brief Enable MTPA module
 *
 * Enables the Maximum Torque per Ampere (MTPA) module.
 *
 * @param[in] pParameters Pointer to module parameters structure
 * @return None
 */
void mcFlxI_MTPAEnable(tmcFlx_Parameters_s * const pParameters);

/*! 
 * @brief Disable MTPA module
 *
 * Disables the MTPA module.
 *
 * @param[in] pParameters Pointer to module parameters structure
 * @return None
 */
void mcFlxI_MTPADisable(tmcFlx_Parameters_s * const pParameters);

/*! 
 * @brief Initialize MTPA module
 *
 * Initializes the MTPA module.
 *
 * @param[in] pParameters Pointer to module parameters structure
 * @return None
 */
void mcFlxI_MTPAInit(tmcFlx_Parameters_s * const pParameters);

/*! 
 * @brief MTPA control
 *
 * Performs Maximum Torque per Ampere (MTPA) control.
 *
 * @param[in] pParameters Pointer to module parameters structure
 * @param[in] pIdq Pointer to DQ current vector
 * @param[out] pIdref Pointer to output reference ID current
 * @return None
 */
#ifdef RAM_EXECUTE
void __ramfunc__ mcFlxI_MTPA(tmcFlx_Parameters_s * const pParameters, const tmcTypes_DQ_s * const pIdq, int16_t * const pIdref);
#else
void mcFlxI_MTPA(tmcFlx_Parameters_s * const pParameters, const tmcTypes_DQ_s * const pIdq, int16_t * const pIdref);
#endif

/*! 
 * @brief Reset MTPA module
 *
 * Resets the MTPA module.
 *
 * @param[in] pParameters Pointer to module parameters structure
 * @return None
 */
void mcFlxI_MTPAReset(tmcFlx_Parameters_s * const pParameters);
</#if>

#endif // MCFLX_H