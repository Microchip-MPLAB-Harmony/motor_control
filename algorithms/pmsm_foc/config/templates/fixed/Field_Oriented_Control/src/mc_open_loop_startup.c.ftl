/**
 * @brief 
 *    Open loop start-up source file
 *
 * @File Name 
 *    mc_open_loop_startup.c
 *
 * @Company 
 *    Microchip Technology Inc.
 *
 * @Summary
 *    This file implements functions for open loop start-up.
 *
 * @Description
 *    This file provides the implementation of functions necessary for open loop start-up
 *    of a motor. It includes the initialization and control routines to start the motor 
 *    in an open loop manner before transitioning to closed loop control.
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
#include "mc_open_loop_startup.h"

/*******************************************************************************
Local configuration options
*******************************************************************************/

/*******************************************************************************
 Private data types
*******************************************************************************/
/**
 * @brief Enumeration for the open loop start-up states.
 */
typedef enum
{
    startupState_Align,      /**< Alignment state */
    startupState_Ramp,       /**< Ramp state */
    startupState_Stabilize   /**< Stabilize state */
} tmcSup_State_e;

/**
 * @brief Structure defining the state parameters for open loop start-up.
 */
typedef struct
{
    bool enable;                           /**< Flag indicating if the start-up is enabled */
    bool initDone;                         /**< Flag indicating if initialization is done */
    tmcSup_State_e StartupState;           /**< Current state of the start-up process */
    int16_t alignmentCurrent;              /**< Current for the alignment phase */
    int16_t openLoopCurrent;               /**< Current for the open loop phase */
    int16_t currentRampRate;            /**< Value for current ramp rate */
    int16_t speedRampRate;              /**< Value for speed ramp rate */
    int16_t speedToAngle;               /**< Value for speed to angle conversion */
    int16_t openLoopSpeed;                 /**< Current open loop speed */
    int16_t openLoopFinalSpeed;            /**< Final open loop speed */
    uint32_t alignmentTimeLoopCount;       /**< Loop count for the alignment phase */
    uint32_t halfAlignmentTimeLoopCount;   /**< Half of the loop count for the alignment phase */
    uint32_t openLoopRampTimeLoopCount;    /**< Loop count for the ramp phase */
    uint32_t openLoopStabTimeLoopCount;    /**< Loop count for the stabilization phase */
    uint32_t zCounter;                     /**< Zero crossing counter or general purpose counter */
} tmcSup_State_s;

/*******************************************************************************
Private variables
*******************************************************************************/
static tmcSup_State_s mcSup_State_mds;

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
 * @brief Initialize open loop start-up module
 *
 * This function initializes the open loop start-up module.
 *
 * @param[in] pParameters Pointer to the open loop start-up parameters structure
 */
void  mcSupI_OpenLoopStartupInit( tmcSup_Parameters_s * const pParameters )
{
    float32_t f32a;

    /** Link state variable structure to the module */
    pParameters->pStatePointer = (void *)&mcSup_State_mds;
    tmcSup_State_s * pState =  &mcSup_State_mds;

    /** Set parameters */
    mcSupI_ParametersSet(pParameters);

    /** Update state variables */
    f32a = ( K_CURRENT  * pParameters->alignmentCurrent ) + 0.5f;
    pState->alignmentCurrent = (int16_t)f32a;

    f32a = ( K_CURRENT * pParameters->openLoopCurrent ) + 0.5f;
    pState->openLoopCurrent = (int16_t)f32a;

    f32a = ( pParameters->alignmentTime  / pParameters->dt ) + 0.5f;
    pState->alignmentTimeLoopCount = (uint32_t)f32a;
    pState->halfAlignmentTimeLoopCount = pState->alignmentTimeLoopCount >> 1u;

    f32a = ( pParameters->openLoopRampTime / pParameters->dt ) + 0.5f;
    pState->openLoopRampTimeLoopCount = (uint32_t)f32a;

    f32a = ( pParameters->openLoopStabTime / pParameters->dt ) + 0.5f;
    pState->openLoopStabTimeLoopCount = (uint32_t)f32a;

    /** Determine current ramp rate */
    float32_t rampRate = (float32_t)pState->openLoopCurrent/ (float32_t)pState->halfAlignmentTimeLoopCount;
    pState->currentRampRate = Q_SCALE( rampRate);

    f32a = ( K_SPEED * pParameters->openLoopTransSpeed ) + 0.5f;
    pState->openLoopFinalSpeed = (int16_t)f32a;

    /** Determine open loop speed ramp rate */
    float32_t speedRampRate;
    speedRampRate  =  (float32_t)pState->openLoopFinalSpeed / (float32_t)pState->openLoopRampTimeLoopCount;
    pState->speedRampRate = Q_SCALE( speedRampRate );

    /** Speed to angle conversion factor calculation */
    float32_t speedToAngle = (float32_t)K_TIME;
    pState->speedToAngle = Q_SCALE( speedToAngle );

    /** Set the initial state of the state machine  */
    pState->StartupState = startupState_Align;

    /** Set initialization flag as true */
    pState->initDone = true;
}

/**
 * @brief Enable open loop start-up module
 *
 * This function enables the open loop start-up module.
 *
 * @param[in] pParameters Pointer to the open loop start-up parameters structure
 */
void  mcSupI_OpenLoopStartupEnable( tmcSup_Parameters_s * const pParameters )
{
    /** Get the linked state variable */
    tmcSup_State_s * pState;
    pState = (tmcSup_State_s *)pParameters->pStatePointer;

    if( ( NULL == pState ) || ( !pState->initDone ))
    {
         /** Initialize parameters */
        mcSupI_OpenLoopStartupInit(pParameters);
    }
    else
    {
         /** For MISRA Compliance */
    }

    /** Set enable flag as true */
    pState->enable = true;
}

/**
 * @brief Disable open loop start-up module
 *
 * This function disables the open loop start-up module.
 *
 * @param[in] pParameters Pointer to the open loop start-up parameters structure
 */
void  mcSupI_OpenLoopStartupDisable( tmcSup_Parameters_s * const pParameters )
{
    /** Get the linked state variable */
    tmcSup_State_s * pState;
    pState = (tmcSup_State_s *)pParameters->pStatePointer;

    if( NULL != pState)
    {
        /** Reset state variables  */
        mcSupI_OpenLoopStartupReset(pParameters);
    }
    else
    {
        /** For MISRA Compliance */
    }

    /** Set enable flag as true */
    pState->enable = false;
}

/**
 * @brief Perform open loop start-up
 *
 * This function performs the open loop start-up of the motor.
 *
 * @param[in] pParameters Pointer to the open loop start-up parameters structure
 * @param[in] direction Motor rotation direction
 * @param[out] pIQref Pointer to the q-axis current reference
 * @param[out] pIDref Pointer to the d-axis current reference
 * @param[out] pAngle Pointer to the rotor angle
 * @param[out] pSpeed Pointer to the rotor speed
 *
 * @return Standard return type indicating success or failure
 */
#ifdef RAM_EXECUTE
tmcTypes_StdReturn_e __ramfunc__  mcSupI_OpenLoopStartup( const tmcSup_Parameters_s * const pParameters,
                                                        int16_t direction, int16_t * const pIQref,
                                                        int16_t * const pIDref, uint16_t * const pAngle,
                                                        int16_t * const pSpeed )
#else
tmcTypes_StdReturn_e mcSupI_OpenLoopStartup( const tmcSup_Parameters_s * const pParameters,
                                          int16_t direction, int16_t * const pIQref,
                                          int16_t * const pIDref, uint16_t * const pAngle,
                                          int16_t * const pSpeed )
#endif
{
    /** Status variable */
    tmcTypes_StdReturn_e openLoopStatus  = StdReturn_Progress;

    /** Get the linked state variable */
    tmcSup_State_s * pState;
    pState = (tmcSup_State_s *)pParameters->pStatePointer;

    if( pState->enable )
    {
        /** Execute open loop start-up */
        switch(pState->StartupState)
        {
            case startupState_Align:
            {
                ++pState->zCounter;

                if( pState->zCounter >= pState->alignmentTimeLoopCount )
                {
                    pState->StartupState = startupState_Ramp;
                    pState->zCounter = 0u;
                }

<#if 'Q_AXIS' == MCPMSMFOC_ALIGN_OR_DETECT_AXIS >
                *pIQref = direction * pState->alignmentCurrent;
                *pIDref = 0;
                if( direction < 0)
                {
                    *pAngle = Q15_ANGLE( HALF_PI  );
                }
                else
                {
                    *pAngle = Q15_ANGLE( THREE_HALVES_PI  );
                }

<#elseif 'D_AXIS' == MCPMSMFOC_ALIGN_OR_DETECT_AXIS >
                *pIQref = 0;
                *pIDref = pState->alignmentCurrent;

                *pAngle = 0u;
</#if>
                break;
            }
            case startupState_Ramp:
            {
                ++pState->zCounter;

                pState->openLoopSpeed = (int16_t)Q_MULTIPLY( (int32_t)pState->zCounter, pState->speedRampRate );

                if( pState->openLoopFinalSpeed < pState->openLoopSpeed )
                {
                    pState->zCounter = 0u;
                    pState->StartupState = startupState_Stabilize;
                }
                 int16_t delAngle = direction * (int16_t)Q_MULTIPLY( pState->openLoopSpeed, pState->speedToAngle );
                *pAngle += (uint16_t)delAngle;

                *pIDref = 0;
                *pIQref = direction * pState->alignmentCurrent;

                break;
            }

            case startupState_Stabilize:
            {
<#if ( MCPMSMFOC_CONTROL_TYPE != 'OPEN_LOOP' ) >
                if( pState->openLoopStabTimeLoopCount <= ++pState->zCounter )
                {
                    pState->zCounter = 0u;
                    openLoopStatus = StdReturn_Complete;
                }
</#if>
                int16_t delAngle =  direction *  (int16_t)Q_MULTIPLY(pState->openLoopSpeed, pState->speedToAngle );
                *pAngle += (uint16_t)delAngle;
                *pIDref = 0;
                *pIQref = direction * pState->alignmentCurrent;

                break;
            }

            default:
            {
                /** For MISRA Compliance */
            }
            break;
        }

        *pSpeed = direction * pState->openLoopSpeed;
    }
    else
    {
        /** Reset pen loop start-up */
        mcSupI_OpenLoopStartupReset( pParameters );

        *pAngle = 0u;
        *pSpeed = 0;
    }

    return openLoopStatus;
}

/**
 * @brief Reset open loop start-up
 *
 * This function resets the open loop start-up parameters.
 *
 * @param[in] pParameters Pointer to the open loop start-up parameters structure
 */
void mcSupI_OpenLoopStartupReset( const tmcSup_Parameters_s * const pParameters )
{
    /** Get the linked state variable */
    tmcSup_State_s * pState;
    pState = (tmcSup_State_s *)pParameters->pStatePointer;

    /** Reset open loop startup state variables  */
    pState->StartupState = startupState_Align;
    pState->openLoopSpeed = 0;
    pState->zCounter = 0u;
}
