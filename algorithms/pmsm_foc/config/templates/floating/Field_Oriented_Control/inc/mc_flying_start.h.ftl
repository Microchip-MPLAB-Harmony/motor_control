/**
 * @file mc_flying_start.h
 *
 * @brief 
 *    Header file for Flying Start
 *
 * @Company 
 *    Microchip Technology Inc.
 *
 * @Summary
 *    Header file containing variables and function prototypes for flying start.
 *
 * @Description
 *    This header file defines variables and function prototypes commonly used for
 *    implementing flying start functionality in embedded systems.
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

#ifndef MCFLY_H
#define MCFLY_H

/*******************************************************************************
 * Header inclusions
*******************************************************************************/
#include "mc_types.h"
#include "mc_hardware_abstraction.h"


/*******************************************************************************
 Configuration parameters
*******************************************************************************/

/*******************************************************************************
Type Definition
*******************************************************************************/
typedef struct
{
    float32_t dt;
    float32_t detectTime;
    float32_t minRpmForFlyingStart;
    float32_t fadeOutTime;
    float32_t fadeOutBurstTime;
    uint16_t pwmPeriodCount;
<#if true == MCPMSMFOC_ENABLE_REGEN_BRAKE>
    float32_t brakeCurrenInAmps;
    float32_t brakeCurrentRampTimeInSec;
</#if>
    void * pStatePointer;
}tmcFly_Parameters_s;

/*******************************************************************************
 * Interface variables
*******************************************************************************/

/*******************************************************************************
 Static Interface Functions
*******************************************************************************/
/**
 * @brief Set module parameters
 *
 * This function sets the parameters of the module.
 *
 * @param[in] Input structure containing parameters to be set.
 * @return None
 */
__STATIC_INLINE void mcFlyI_ParametersSet( tmcFly_Parameters_s * const pParameter )
{
    pParameter->dt = (float32_t)(${MCPMSMFOC_PWM_PERIOD});
    pParameter->detectTime = (float32_t)(${MCPMSMFOC_FLY_START_DETECTION_TIME});
    pParameter->minRpmForFlyingStart = (float32_t)(${MCPMSMFOC_FLY_START_MINIMUM_SPEED});

    pParameter->fadeOutTime = (float32_t)(${MCPMSMFOC_FLY_START_FADEOUT_TIME});
    pParameter->fadeOutBurstTime = (float32_t)(${MCPMSMFOC_FLY_START_FADEOUT_BURST_PERIOD});
    pParameter->pwmPeriodCount = (uint16_t)mcHalI_PwmPeriodGet();

<#if true == MCPMSMFOC_ENABLE_REGEN_BRAKE>
    pParameter->brakeCurrenInAmps = (float32_t)(${MCPMSMFOC_FLY_START_PEAK_BRAKE_CURRENT});
    pParameter->brakeCurrentRampTimeInSec = (float32_t)(${MCPMSMFOC_FLY_START_BRAKE_RAMP_TIME});
</#if>
}

/*******************************************************************************
 Interface Functions
*******************************************************************************/
/**
 * @brief Initialize Flying Start module
 *
 * This function initializes the Flying Start module.
 *
 * @param pParameters Pointer to the parameters structure.
 * @return None
 */
void mcFlyI_FlyingStartInit(tmcFly_Parameters_s * const pParameters);

/**
 * @brief Enable Flying Start module
 *
 * This function enables the Flying Start module.
 *
 * @param pParameters Pointer to the parameters structure.
 * @return None
 */
void mcFlyI_FlyingStartEnable(tmcFly_Parameters_s * const pParameters);

/**
 * @brief Disable Flying Start module
 *
 * This function disables the Flying Start module.
 *
 * @param pParameters Pointer to the parameters structure.
 * @return None
 */
void mcFlyI_FlyingStartDisable(tmcFly_Parameters_s * const pParameters);

/**
 * @brief Perform Flying Start
 *
 * This function performs the Flying Start operation.
 *
 * @param pParameters Pointer to the parameters structure.
 * @param speed Current speed value.
 * @param commandDirection Commanded direction value.
 * @param pIdref Pointer to the reference Id value.
 * @param pIqref Pointer to the reference Iq value.
 * @param pDutyOverride Pointer to the duty cycle override flag.
 * @param pDuty Pointer to the duty cycle value.
 * @return Standard return status indicating success or failure.
 */
tmcTypes_StdReturn_e mcFlyI_FlyingStart(tmcFly_Parameters_s * const pParameters,
                                        const float32_t speed, const float32_t commandDirection,
                                        float32_t * const pIdref, float32_t * const pIqref,
                                        bool * const pDutyOverride, int16_t * const pDuty);

/**
 * @brief Reset Flying Start module
 *
 * This function resets the Flying Start module.
 *
 * @param pParameters Pointer to the parameters structure.
 * @return None
 */
void mcFlyI_FlyingStartReset(const tmcFly_Parameters_s * const pParameters);

#endif // MCFLY_H
