/**
 * @file mc_flying_start.c
 *
 * @brief 
 *    Source file for Flying Start
 *
 * @Company 
 *    Microchip Technology Inc.
 *
 * @Summary
 *    Source file containing variables and function prototypes for flying start.
 *
 * @Description
 *    This Source file defines variables and function prototypes commonly used for
 *    implementing flying start functionality in embedded systems.
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
#include "mc_flying_start.h"

/*******************************************************************************
Local configuration options
*******************************************************************************/
/**
 *  Constant Pi
 */
#ifdef CONSTANT_2Pi
#undef CONSTANT_2Pi
#endif
#define CONSTANT_2Pi (float32_t)( 6.28318530718f)

/*
 * RPM to Radians per second conversion factor
 */
#define CONSTANT_RpmToRadPerSec  (float32_t)( CONSTANT_2Pi / 60.0f )

/*******************************************************************************
 Private data types
*******************************************************************************/
typedef enum tmcFly_FlyingStartState_e
{
    FlyingStart_Initialize,
    FlyingStart_Check,
#ifdef ENABLE_REGENERATIVE_BRAKING
    FlyingStart_Brake,
#endif
    FlyingStart_FadeOut,
}tmcFly_FlyingStartState_e;

typedef struct tmcFly_State_s
{
    /** Switches */
    bool enable;
    bool initDone;

    /** State variables */
    tmcFly_FlyingStartState_e flyingStartState;
    uint32_t exceedCounter;
    uint32_t detectCounter;
    uint32_t fadeOutCounter;
    uint32_t fadeOutBurstCounter;

    /** Parameters */
    uint32_t detectLoopCount;
    uint32_t exceedCounterCount;
    float32_t minSpeedForFlyingStart;
    float32_t flyingStartCurrent;
    float32_t brakeCurrent;
    float32_t brakeCurrentStep;
    uint32_t fadeOutLoopCount;
    uint32_t halfFadeOutBurstLoopCount;
    uint32_t fadeOutBurstLoopCount;
    uint16_t halfPwmPeriodCount;

}tmcFly_State_s;

/*******************************************************************************
Private variables
*******************************************************************************/
static tmcFly_State_s mcFly_State_mds;

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
 * @brief Initialize Flying Start module
 *
 * This function initializes the Flying Start module.
 *
 * @param pParameters Pointer to the parameters structure.
 * @return None
 */
void  mcFlyI_FlyingStartInit( tmcFly_Parameters_s * const pParameters )
{
     float32_t temp = 0.0f;
     tmcFly_State_s * pFlyingStart = NULL;

     /** Set state pointer */
     pParameters->pStatePointer = &mcFly_State_mds;

     /** Get state pointer */
     pFlyingStart = (tmcFly_State_s *)pParameters->pStatePointer;

     /** Set parameters  */
     mcFlyI_ParametersSet( pParameters );

     /** Update states and parameters */
     temp = ( pParameters->detectTime / pParameters->dt);
     pFlyingStart->detectLoopCount = (uint32_t)temp;

     pFlyingStart->minSpeedForFlyingStart = pParameters->minRpmForFlyingStart;

<#if true == MCPMSMFOC_ENABLE_REGEN_BRAKE>
     pFlyingStart->brakeCurrent = pParameters->brakeCurrenInAmps;

     temp = ( pParameters->brakeCurrentRampTimeInSec / pParameters->dt);
     pFlyingStart->brakeCurrentStep = pFlyingStart->brakeCurrent/ temp;
</#if>

     temp = ( pParameters->fadeOutTime / pParameters->dt);
     pFlyingStart->fadeOutLoopCount =  (uint32_t)temp;

     temp = ( pParameters->fadeOutBurstTime/ pParameters->dt);
     pFlyingStart->fadeOutBurstLoopCount =  (uint32_t)temp;

     pFlyingStart->halfFadeOutBurstLoopCount =  pFlyingStart->fadeOutBurstLoopCount >> 1u;

     /** Neutral PWM */
     pFlyingStart->halfPwmPeriodCount = pParameters->pwmPeriodCount;

     /** Set initialization flag as true */
     pFlyingStart->initDone = true;
}

/**
 * @brief Enable Flying Start module
 *
 * This function enables the Flying Start module.
 *
 * @param pParameters Pointer to the parameters structure.
 * @return None
 */
void  mcFlyI_FlyingStartEnable( tmcFly_Parameters_s * const pParameters )
{
    /** Get the linked state variable */
    tmcFly_State_s * pState;
    pState = (tmcFly_State_s *)pParameters->pStatePointer;

    if( ( NULL == pState ) || ( !pState->initDone ))
    {
         /** Initialize parameters */
        mcFlyI_FlyingStartInit(pParameters);
    }
    else
    {
         /** For MISRA Compliance */
    }

    /** Set enable flag as true */
    pState->enable = true;
}

/**
 * @brief Disable Flying Start module
 *
 * This function disables the Flying Start module.
 *
 * @param pParameters Pointer to the parameters structure.
 * @return None
 */
void  mcFlyI_FlyingStartDisable( tmcFly_Parameters_s * const pParameters )
{
    /** Get the linked state variable */
    tmcFly_State_s * pState;
    pState = (tmcFly_State_s *)pParameters->pStatePointer;

    if( NULL != pState)
    {
        /** Reset state variables  */
        mcFlyI_FlyingStartReset(pParameters);
    }
    else
    {
        /** For MISRA Compliance */
    }

    /** Set enable flag as true */
    pState->enable = false;

}

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
tmcTypes_StdReturn_e  mcFlyI_FlyingStart( tmcFly_Parameters_s * const pParameters,
                                   const float32_t speed, const float32_t commandDirection,
                                   float32_t * const pIdref, float32_t * const pIqref,
                                   bool * const pDutyOverride, int16_t * const pDuty )
{
    /** Flying start status  */
    tmcTypes_StdReturn_e status = StdReturn_Progress;

    /** Get the linked state variable */
    tmcFly_State_s * pFlyingStart;
    pFlyingStart = (tmcFly_State_s *)pParameters->pStatePointer;

    if( pFlyingStart->enable )
    {
        /** Flying start state machine  */
        switch( pFlyingStart->flyingStartState )
        {
            case FlyingStart_Check:
            {
                /** Check if the rotor speed is above threshold for switching to close loop */
                if(  ( commandDirection * speed )  > pFlyingStart->minSpeedForFlyingStart )
                {
                    pFlyingStart->exceedCounter++;

                    /** ToDO: Compute the exceed counter threshold. Remove the magic number */
                    if( pFlyingStart->exceedCounter > 200u )
                    {
                        status = StdReturn_Success;
                    }
                    else
                    {

                    }
                }
                else
                {
                    pFlyingStart->exceedCounter = 0u;
                }

                if( pFlyingStart->detectCounter > pFlyingStart->detectLoopCount )
                {
<#if true == MCPMSMFOC_ENABLE_REGEN_BRAKE>
                    pFlyingStart->flyingStartState = FlyingStart_Brake;
<#else>
                    pFlyingStart->flyingStartState = FlyingStart_FadeOut;
</#if>
                    pFlyingStart->detectCounter = 0u;
                }
                else
                {
                pFlyingStart->detectCounter++;
                }

                /** Apply NULL current vector */
                *pIdref = 0.0f;
                *pIqref = 0.0f;

                break;
            }

<#if true == MCPMSMFOC_ENABLE_REGEN_BRAKE>
            case FlyingStart_Brake:
            {
                if( speed > pFlyingStart->minSpeedForFlyingStart )
                {
                    if( *pIqref < pFlyingStart->brakeCurrent )
                    {
                        *pIqref += pFlyingStart->brakeCurrentStep;
                    }
                }
                else if( speed < -pFlyingStart->minSpeedForFlyingStart )
                {
                    if( *pIqref > -pFlyingStart->brakeCurrent )
                    {
                        *pIqref -= pFlyingStart->brakeCurrentStep;
                    }
                }
                else
                {
                    pFlyingStart->FlyingStartState = FlyingStart_FadeOut;
                }
                break;
            }
</#if>

            case FlyingStart_FadeOut:
            {
                /** Set 50% duty ratio for the PWM inverter for active short */
                *pDutyOverride = true;
                pDuty[0u] = pDuty[1u] = pDuty[2u] = (int16_t)pFlyingStart->halfPwmPeriodCount;

                if( pFlyingStart->fadeOutCounter < pFlyingStart->fadeOutLoopCount )
                {
                    pFlyingStart->fadeOutCounter++;
                    pFlyingStart->fadeOutBurstCounter++;
                    if( pFlyingStart->fadeOutBurstCounter < pFlyingStart->halfFadeOutBurstLoopCount )
                    {
                        /** ToDO: Enable PWM output */
                    }
                    else if( pFlyingStart->fadeOutBurstCounter < pFlyingStart->fadeOutBurstLoopCount )
                    {
                        /** ToDO: Disable PWM output */
                    }
                    else
                    {
                        pFlyingStart->fadeOutBurstCounter = 0u;
                    }

                }
                else
                {
                    /** ToDO: Enable PWM output */
                    pFlyingStart->fadeOutCounter  = 0u;

                    /** ToDO: Remove later */
                    pFlyingStart->flyingStartState = FlyingStart_Check;

                    status = StdReturn_Fail;
                }
                break;
            }

            default:
            {
                /** Should not come here */
            }
            break;

        }
    }
    else
    {
        mcFlyI_FlyingStartReset( pParameters);
    }

    return status;
}

/**
 * @brief Reset Flying Start module
 *
 * This function resets the Flying Start module.
 *
 * @param pParameters Pointer to the parameters structure.
 * @return None
 */
void mcFlyI_FlyingStartReset( const tmcFly_Parameters_s * const pParameters )
{
    /** Get the linked state variable */
    tmcFly_State_s * pFlyingStart;
    pFlyingStart = (tmcFly_State_s *)pParameters->pStatePointer;

    /** Reset flying start variables  */
    pFlyingStart->flyingStartState = FlyingStart_Check;
    pFlyingStart->exceedCounter = 0u;
    pFlyingStart->detectCounter = 0u;
    pFlyingStart->fadeOutCounter = 0u;
    pFlyingStart->fadeOutBurstCounter = 0u;

}
