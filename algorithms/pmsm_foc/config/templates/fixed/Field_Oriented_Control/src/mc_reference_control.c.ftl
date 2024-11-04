/**
 * @brief 
 *    Source file for reference control
 *
 * @File Name 
 *    mc_reference_control.c
 *
 * @Company 
 *    Microchip Technology Inc.
 *
 * @Summary
 *    Source file which contains variables and function implementations for reference control.
 *
 * @Description
 *    This file contains variables and function implementations which are generally used for reference
 *    control in pulse width modulation. 
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

/*******************************************************************************
Headers inclusions
*******************************************************************************/
#include "mc_reference_control.h"

/*******************************************************************************
Local configuration options
*******************************************************************************/

/*******************************************************************************
 Private data types
*******************************************************************************/
/**
 * @brief Structure defining the state of the reference control module.
 */
typedef struct
{
    bool enable;                /**< Flag indicating if the module is enabled */
    bool initDone;              /**< Flag indicating if initialization is done */
    int16_t lowerLimit;         /**< Lower limit for the reference value */
    int16_t upperLimit;         /**< Upper limit for the reference value */
    int32_t scaledLowerLimit;   /**< Scaled lower limit for the reference value */
    int32_t scaledUpperLimit;   /**< Scaled upper limit for the reference value */
<#if MCPMSMFOC_RAMP_PROFILES == 'Linear'>
    int32_t scaledReference;    /**< Scaled reference value */
    int32_t scaledRampRate;     /**< Scaled ramp rate       */
</#if>
    int16_t reference;          /**< Reference value */
} tmcRef_State_s;

/*******************************************************************************
Private variables
*******************************************************************************/
static tmcRef_State_s mcRef_State_mds;

/*******************************************************************************
Interface  variables
*******************************************************************************/

/*******************************************************************************
Macro Functions
*******************************************************************************/

/*******************************************************************************
Private Functions
*******************************************************************************/

/*******************************************************************************
 * Interface Functions
*******************************************************************************/

/**
 * @brief Initialize reference control module
 *
 * This function initializes the reference control module.
 *
 * @param[in] pParameters Pointer to the reference parameters structure
 */
void  mcRefI_ReferenceControlInit( tmcRef_Parameters_s * const pParameters )
{
    /** Link state variable structure to the module */
    pParameters->pStatePointer = (void *)&mcRef_State_mds;

    /** Set parameters */
    mcRefI_ParametersSet(pParameters);

<#if ( MCPMSMFOC_CONTROL_TYPE == 'SPEED_LOOP' ) >
    mcRef_State_mds.lowerLimit = K_SPEED * pParameters->minimumRpm;
    mcRef_State_mds.upperLimit = K_SPEED * pParameters->maximumRpm;
<#if MCPMSMFOC_RAMP_PROFILES == 'Linear'>
    mcRef_State_mds.scaledLowerLimit = mcRef_State_mds.lowerLimit << 15U;
    mcRef_State_mds.scaledUpperLimit = mcRef_State_mds.upperLimit << 15U;


    /** Update state variables */
    float32_t f32a = (float32_t)( (float32_t)Q_SCALE( pParameters->rpmPerSecond / BASE_SPEED_IN_RPM ) ) /  PWM_FREQUENCY;
    mcRef_State_mds.scaledRampRate =  Q_SCALE( f32a );
</#if>
</#if>
    mcRef_State_mds.initDone = true;
}

/**
 * @brief Enable reference control module
 *
 * This function enables the reference control module.
 *
 * @param[in] pParameters Pointer to the reference parameters structure
 */
void  mcRefI_ReferenceControlEnable( tmcRef_Parameters_s * const pParameters )
{
    /** Get the linked state variable */
    tmcRef_State_s * pState;
    pState = (tmcRef_State_s *)pParameters->pStatePointer;

    if( ( NULL == pState ) || ( !pState->initDone ))
    {
        /** Initialize parameters */
        mcRefI_ReferenceControlInit(pParameters);
    }
    else
    {
        /** For MISRA Compliance */
    }

    /** Set enable flag as true */
    pState->enable = true;
}

/**
 * @brief Disable reference control module
 *
 * This function disables the reference control module.
 *
 * @param[in] pParameters Pointer to the reference parameters structure
 */
void  mcRefI_ReferenceControlDisable( tmcRef_Parameters_s * const pParameters )
{
    /** Get the linked state variable */
    tmcRef_State_s * pState;
    pState = (tmcRef_State_s *)pParameters->pStatePointer;

    if( NULL != pState)
    {
        /** Reset state variables  */
        mcRefI_ReferenceControlReset(pParameters);
    }
    else
    {
        /** For MISRA Compliance */
    }

    /** Set enable flag as true */
    pState->enable = false;
}

/**
 * @brief Reference control
 *
 * This function performs the reference control.
 *
 * @param[in] pParameters Pointer to the reference parameters structure
 * @param[in] command The command input
 * @param[out] pOut Pointer to the output
 */
#ifdef RAM_EXECUTE
void __ramfunc__  mcRefI_ReferenceControl( tmcRef_Parameters_s * const pParameters,
                                                                       const int16_t command, int16_t * const pOut   )
#else
void mcRefI_ReferenceControl(  tmcRef_Parameters_s * const pParameters,
                                                    const int16_t command, int16_t * const pOut )
#endif
{
    /** Get the linked state variable */
    tmcRef_State_s * pState;
    pState = (tmcRef_State_s *)pParameters->pStatePointer;

    if( pState->enable )
    {
        /** Execute reference control */
<#if MCPMSMFOC_RAMP_PROFILES == 'Step'>
        *pOut = command;

        /** Clamp the reference  */
        if( *pOut > pState->upperLimit )
        {
            *pOut = pState->upperLimit;
        }
        else if( *pOut < pState->lowerLimit)
        {
            *pOut = pState->lowerLimit;
        }
        else
        {
            /** For MISRA Compliance */
        }
</#if>

<#if MCPMSMFOC_RAMP_PROFILES == 'Linear'>
        /** Execute reference control */
        int32_t scaledCommand = (int32_t)command << 15U;
        if( (  pState->scaledReference + pState->scaledRampRate )  < scaledCommand )
        {
            pState->scaledReference += pState->scaledRampRate;
        }
        else if(  (  pState->scaledReference - pState->scaledRampRate )  > scaledCommand )
        {
            pState->scaledReference -= pState->scaledRampRate;
        }
        else
        {
            pState->scaledReference = scaledCommand;
        }

        UTIL_ApplyClampS32( &pState->scaledReference, pState->scaledUpperLimit, pState->scaledLowerLimit);
        pState->reference = pState->scaledReference >> 15U;
        *pOut = pState->reference;
</#if>
    }
    else
    {
        /** Reset reference control */
        mcRefI_ReferenceControlReset(pParameters);
    }
}

/**
 * @brief Reset reference control
 *
 * This function resets the reference control.
 *
 * @param[in] pParameters Pointer to the reference parameters structure
 */
void mcRefI_ReferenceControlReset( tmcRef_Parameters_s * const pParameters )
{
<#if MCPMSMFOC_RAMP_PROFILES == 'Linear'>
    /** Get the linked state variable */
    tmcRef_State_s * pState;
    pState = (tmcRef_State_s *)pParameters->pStatePointer;

<#if MCPMSMFOC_POSITION_CALC_ALGORITHM == 'SENSORLESS_ZSMT_HYBRID'>
    /** Reset reference control state variables  */
    pState->reference = 0.0f;
    pState->scaledReference = 0u;
<#else>
    /** Reset reference control state variables  */
    pState->reference = pState->lowerLimit;
    pState->scaledReference = pState->lowerLimit << 15u;
</#if>
</#if>
}
