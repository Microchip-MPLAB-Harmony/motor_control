/*******************************************************************************
 Pulse width modulation function

  Company:
    Microchip Technology Inc.

  File Name:
    mc_pwm.c

  Summary:
    Pulse width modulation functions.

  Description:
    This file implements functions for pulse width modulation .

 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2021 Microchip Technology Inc. and its subsidiaries.
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
#include "mc_pwm.h"

/*******************************************************************************
Local configuration options
*******************************************************************************/
#define SQRT3   (float32_t)(1.73205080756887)
#define DT_PADDING           (int16_t)12

/*******************************************************************************
 Private data types
*******************************************************************************/
typedef enum
{
   SECTOR_1,
   SECTOR_2,
   SECTOR_3,
   SECTOR_4,
   SECTOR_5,
   SECTOR_6
}tmcPwm_Sector_e;

typedef struct
{
    bool enable;
    bool initDone;
    int16_t pwmPeriodCount;
    int16_t minPeriodCount;
    int16_t maxPeriodCount;
    float32_t maxModIndex;
    float32_t uBusFactor;
}tmcPwm_State_s;

/*******************************************************************************
Private variables
*******************************************************************************/
static tmcPwm_State_s  mcPwm_State_mds;

/*******************************************************************************
Interface  variables
*******************************************************************************/

/*******************************************************************************
Macro Functions
*******************************************************************************/

/*******************************************************************************
Private Functions
*******************************************************************************/
__STATIC_INLINE int16_t mcPwm_IntegerScale( const float32_t factor, int16_t input )
{
    float32_t result = factor * (float32_t)input;
    return (int16_t)result;
}
/*******************************************************************************
 * Interface Functions
*******************************************************************************/
/*! \brief Initialize PWM modulator
 *
 * Details.
 * Initialize PWM Modulator
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
void  mcPwmI_PulseWidthModulationInit( tmcPwm_Parameters_s * const pParameters )
{
    float32_t allowedRange;

    /** Link state variable structure to the module */
    pParameters->pStatePointer = (void *)&mcPwm_State_mds;
    tmcPwm_State_s * pState = &mcPwm_State_mds;

    /** Set parameters */
    mcPwmI_ParametersSet(pParameters);

    /** Update state variables */
    pState->pwmPeriodCount = (int16_t)pParameters->pwmPeriodCount ;
    pState->minPeriodCount = (int16_t)pParameters->deadTimeCount + DT_PADDING;
    pState->maxPeriodCount = pState->pwmPeriodCount - pState->minPeriodCount;
    pState->maxModIndex = pParameters->maxModIndex;

    allowedRange = (float32_t)( (float32_t)pState->maxPeriodCount - (float32_t)pState->minPeriodCount);
    pState->uBusFactor = (float32_t)( allowedRange / (float32_t)pState->pwmPeriodCount );
}

/*! \brief Enable PWM modulator
 *
 * Details.
 * Enable PWM Modulator
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
void  mcPwmI_PulseWidthModulationEnable( tmcPwm_Parameters_s * const pParameters )
{
    /** Get the linked state variable */
    tmcPwm_State_s * pState;
    pState = (tmcPwm_State_s *)pParameters->pStatePointer;

    if( ( NULL == pState ) || ( !pState->initDone ))
    {
         /** Initialize parameters */
         mcPwmI_PulseWidthModulationInit(pParameters);
    }
    else
    {
         /** For MISRA Compliance */
    }

    /** Set enable flag as true */
    pState->enable = true;
}

/*! \brief Disable PWM modulator
 *
 * Details.
 * Disable PWM Modulator
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
void  mcPwmI_PulseWidthModulationDisable( tmcPwm_Parameters_s * const pParameters )
{
    /** Get the linked state variable */
    tmcPwm_State_s * pState;
    pState = (tmcPwm_State_s *)pParameters->pStatePointer;

    if( NULL != pState)
    {
        /** Reset state variables  */
        mcPwmI_PulseWidthModulationReset(pParameters);
    }
    else
    {
        /** For MISRA Compliance */
    }

    /** Set enable flag as true */
    pState->enable = false;

}

/*! \brief PWM Modulator
 *
 * Details.
 * PWM Modulator
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
void mcPwmI_PulseWidthModulation( const tmcPwm_Parameters_s * const pParameters,
                                                           const float32_t uBus,
                                                           const tmcTypes_AlphaBeta_s * const pUalphaBeta,
                                                           int16_t * const pDuty )
{
    tmcPwm_Sector_e bSector;
    float32_t uRef;
    float32_t uMax;
    float32_t uA, uB, uC;
    float32_t uAlphaNorm, uBetaNorm;
    float32_t modIndex;


    /** Get the linked state variable */
    tmcPwm_State_s * pState;
    pState = (tmcPwm_State_s *)pParameters->pStatePointer;

    if( pState->enable )
    {
        /** Apply bus voltage based circle limitation */;
        uRef = UTIL_MagnitudeFloat(pUalphaBeta->alpha, pUalphaBeta->beta);
        uMax = pState->uBusFactor * uBus / SQRT3;

        modIndex = uRef/ uMax;

        if( modIndex > pState->maxModIndex  )       {
            /** Overmodulation condition */
            modIndex = pState->maxModIndex;
        }

        uAlphaNorm = modIndex * pUalphaBeta->alpha/ uMax;
        uBetaNorm = modIndex * pUalphaBeta->beta/uMax;

        /** Calculate abc voltage from alpha-beta voltage  */
        uA = uBetaNorm;
        uB = 0.5f * ( -uBetaNorm + ( uAlphaNorm * SQRT3 ) );
        uC =-uA -uB;

        /** Determine space vector sector */
        if (uB < 0.0f)
        {
            if (uC < 0.0f)
            {
                bSector = SECTOR_6;
            }
            else // uC >= 0
            {
                if (uA <= 0.0f )
                {
                      bSector = SECTOR_3;
                }
                else // uA > 0
                {
                    bSector = SECTOR_2;
                }
            }
        }
        else // uB > 0
        {
            if (uC >= 0.0f)
            {
                bSector = SECTOR_1;
            }
            else // uC < 0
            {
                if (uA <= 0.0f)
                {
                    bSector = SECTOR_5;
                }
                else // uA > 0
                {
                    bSector = SECTOR_4;
                }
            }
        }

        switch(bSector)
        {
            case SECTOR_1:
            {
                /** Active vector times */
                int16_t t1 = mcPwm_IntegerScale(-uB, pState->pwmPeriodCount);
                int16_t t2 = mcPwm_IntegerScale(-uC, pState->pwmPeriodCount);

                /** PWM timings */
                pDuty[2u] = mcPwm_IntegerScale( 0.5f, ( pState->pwmPeriodCount  - t1 - t2 ));
                pDuty[0u] = pDuty[2u] + t2;
                pDuty[1u] = pDuty[0u] + t1;

                break;
            }

            case SECTOR_2:
            {
                /** Active vector times */
                int16_t t1 = mcPwm_IntegerScale(-uC, pState->pwmPeriodCount);
                int16_t t2 = mcPwm_IntegerScale(-uA, pState->pwmPeriodCount);

                /** PWM timings */
                pDuty[1u] = mcPwm_IntegerScale( 0.5f, (pState->pwmPeriodCount  - t1 - t2 ));
                pDuty[2u] = pDuty[1u] + t2;
                pDuty[0u] = pDuty[2u] + t1;

                break;
            }

            case SECTOR_3:
            {
                /** Active vector times */
                int16_t t1 = mcPwm_IntegerScale(uB, pState->pwmPeriodCount);
                int16_t t2 = mcPwm_IntegerScale(uA, pState->pwmPeriodCount);

                /** PWM timings */
                pDuty[2u] = mcPwm_IntegerScale( 0.5f, (pState->pwmPeriodCount  - t1 - t2 ));
                pDuty[1u] = pDuty[2u] + t2;
                pDuty[0u] = pDuty[1u] + t1;

                break;
            }

            case SECTOR_4:
            {
                /** Active vector times */
                int16_t t1 =  mcPwm_IntegerScale(-uA, pState->pwmPeriodCount);
                int16_t t2 =  mcPwm_IntegerScale(-uB, pState->pwmPeriodCount);

                /** PWM timings */
                pDuty[0u] = mcPwm_IntegerScale(0.5f, ( pState->pwmPeriodCount  - t1 - t2 ));
                pDuty[1u] = pDuty[0u] + t2;
                pDuty[2u] = pDuty[1u] + t1;

                break;
            }

            case SECTOR_5:
            {
                /** Active vector times */
                int16_t t1 = mcPwm_IntegerScale(uA, pState->pwmPeriodCount);
                int16_t t2 = mcPwm_IntegerScale(uC, pState->pwmPeriodCount);

                /** PWM timings */
                pDuty[0u] = mcPwm_IntegerScale( 0.5f, (pState->pwmPeriodCount  - t1 - t2 ));
                pDuty[2u] = pDuty[0u] + t2;
                pDuty[1u] = pDuty[2u] + t1;

                break;
            }

            case SECTOR_6:
            {
                /** Active vector times */
                int16_t  t1 = mcPwm_IntegerScale(uC, pState->pwmPeriodCount);
                int16_t  t2 = mcPwm_IntegerScale(uB, pState->pwmPeriodCount);

                /** PWM timings */
                pDuty[1u] = mcPwm_IntegerScale( 0.5f, ( pState->pwmPeriodCount  - t1 - t2 ));
                pDuty[0u] = pDuty[1u] + t2;
                pDuty[2u] = pDuty[0u] + t1;

                break;
            }
            default:
            {
                   /** For MISRA Compliance */
            }
            break;
         }

        /** Limit the duty cycle values */
        UTIL_SaturateS16(&pDuty[0u], pState->minPeriodCount, pState->maxPeriodCount );
        UTIL_SaturateS16(&pDuty[1u], pState->minPeriodCount, pState->maxPeriodCount );
        UTIL_SaturateS16(&pDuty[2u], pState->minPeriodCount, pState->maxPeriodCount );
    }
    else
    {

    }
}

/*! \brief Reset PWM Modulator
 *
 * Details.
 * Reset PWM Modulator
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return:
 */
void mcPwmI_PulseWidthModulationReset( const tmcPwm_Parameters_s * const pParameters )
{

}

