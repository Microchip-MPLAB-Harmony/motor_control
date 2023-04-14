/*******************************************************************************
 Open loop start-up source file

  Company:
    - Microchip Technology Inc.

  File Name:
    - mc_open_loop_startup.c

  Summary:
    - Open loop start-up source file

  Description:
    - This file implements functions for open loop start-up
 
 *******************************************************************************/

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
Constants
*******************************************************************************/

/*******************************************************************************
Local configuration options
*******************************************************************************/

/*******************************************************************************
 Private data types
*******************************************************************************/
typedef enum
{
  startupState_Align,
  startupState_Ramp,
  startupState_Stabilize
}tmcSup_State_e;

typedef struct
{
    bool enable;
    bool initDone;
    tmcSup_State_e StartupState;
    uint8_t oneTimeAlignDone;
    float32_t alignmentCurrent;
    float32_t openLoopCurrent;
    float32_t currentRampRate;
    float32_t speedRampRate;
    float32_t speedToAngle;
    float32_t openLoopSpeed;
    float32_t openLoopAngle;
    float32_t openLoopFinalSpeed;
    uint32_t alignmentTimeLoopCount;
    uint32_t halfAlignmentTimeLoopCount;
    uint32_t openLoopRampTimeLoopCount;
    uint32_t openLoopStabTimeLoopCount;
    uint32_t zCounter;
}tmcSup_State_s;

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
/*! \brief Initialize open loop start-up module
 * 
 * Details.
 * Initialize open loop start-up module
 * 
 * @param[in]: None 
 * @param[in/out]: None
 * @param[out]: None 
 * @return: None
 */
void  mcSupI_OpenLoopStartupInit( tmcSup_Parameters_s * const pParameters )
{  
    float32_t temp;
    
    /** Link state variable structure to the module */
    pParameters->pStatePointer = (void *)&mcSup_State_mds;
    tmcSup_State_s * pState =  &mcSup_State_mds;

    /** Set parameters */
    mcSupI_ParametersSet(pParameters);

    /** Update state variables */
    pState->openLoopCurrent = pParameters->openLoopCurrent;

    pState->alignmentCurrent = pParameters->alignmentCurrent;
    temp = ( pParameters->alignmentTime  / pParameters->dt ) + 0.5f;
    pState->alignmentTimeLoopCount = (uint32_t)temp;

    temp = pParameters->openLoopRampTime /pParameters->dt;
    pState->speedRampRate =   pParameters->openLoopTransSpeed / temp;

    temp = (pParameters->openLoopStabTime / pParameters->dt ) + 0.5f;
    pState->openLoopStabTimeLoopCount = (uint32_t)temp;

    /** Open loop transition speed */
    pState->openLoopFinalSpeed = pParameters->openLoopTransSpeed;

    temp = TWO_PI * pParameters->pMotorParameters->PolePairs/60.0f;
    pState->speedToAngle =  temp * pParameters->dt;

    pState->openLoopAngle = 0.0f;
    pState->openLoopSpeed= 0.0f;

    /** Set the initial state of the state machine  */
    pState->StartupState = startupState_Align;

    /** Set initialization flag as true */
    pState->initDone = true;
}

/*! \brief Enable open loop start-up module
 *
 * Details.
 * Enable open loop start-up module
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
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

/*! \brief Disable open loop start-up module
 *
 * Details.
 * Disable open loop start-up module
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
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

/*! \brief Open loop start-up
 *
 * Details.
 * Open loop start-up
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
tmcTypes_StdReturn_e mcSupI_OpenLoopStartup( const tmcSup_Parameters_s * const pParameters,
                                          float32_t direction, float32_t * const pIQref,
                                          float32_t * const pIDref, float32_t * const pAngle,
                                          float32_t * const pSpeed )
{
    /** Status variable */
    tmcTypes_StdReturn_e openLoopStatus  = StdReturn_Progress;

    /** Get the linked state variable */
    tmcSup_State_s * pState;
    pState = (tmcSup_State_s *)pParameters->pStatePointer;

    if( pState->enable )
    {
 <#if MCPMSMFOC_POSITION_CALC_ALGORITHM == 'SENSORED_ENCODER'>
         if( 1u == pState->oneTimeAlignDone )
         {
             return StdReturn_Complete;
         }
</#if>
        /** Execute open loop start-up */
        switch(pState->StartupState)
        {
            case startupState_Align:
            {
                ++pState->zCounter;

                if( pState->zCounter <= ( pState->alignmentTimeLoopCount >> 1u ) )
                {
 <#if 'Q_AXIS' == MCPMSMFOC_ALIGN_OR_DETECT_AXIS >
                *pIQref = direction * pState->alignmentCurrent;
                *pIDref = 0.0f;

                pState->openLoopAngle = ONE_PI;
 <#elseif 'D_AXIS' ==  MCPMSMFOC_ALIGN_OR_DETECT_AXIS >
                *pIQref = 0.0f;
                *pIDref = pState->alignmentCurrent;

                 pState->openLoopAngle = ONE_PI_BY_TWO;
 </#if>                    
                }
                else if( pState->zCounter <= pState->alignmentTimeLoopCount )
                {    
<#if 'Q_AXIS' == MCPMSMFOC_ALIGN_OR_DETECT_AXIS >
                *pIQref = direction * pState->alignmentCurrent;
                *pIDref = 0.0f;

                 pState->openLoopAngle = -direction * ONE_PI_BY_TWO;
<#elseif  'D_AXIS' ==  MCPMSMFOC_ALIGN_OR_DETECT_AXIS >
                *pIQref = 0.0f;
                *pIDref = pState->alignmentCurrent;

                pState->openLoopAngle = 0.0f;
</#if>               
                }
                else 
                {
<#if MCPMSMFOC_POSITION_CALC_ALGORITHM == 'SENSORED_ENCODER'>
<#if ( MCPMSMFOC_CONTROL_TYPE == 'OPEN_LOOP' ) >
                    pState->StartupState = startupState_Ramp; 
<#else>
                    pState->oneTimeAlignDone = 1u;
                    openLoopStatus = StdReturn_Complete;
</#if>
                    /** Start encoder */
                    mcHalI_EncoderStart();
<#else>
                    pState->StartupState = startupState_Ramp; 
</#if>
                    
                    /** Reset counter */
                    pState->zCounter = 0u;
                }
                
                /** Truncate angle from 0 to 2Pi */
                mcUtils_TruncateAngle0To2Pi(&pState->openLoopAngle);
                   
                break;
            }

            case startupState_Ramp:
            {
                ++pState->zCounter;

                pState->openLoopSpeed = (float32_t)pState->zCounter * pState->speedRampRate;

                if( pState->openLoopFinalSpeed <= pState->openLoopSpeed )
                {
                    pState->zCounter = 0u;
                    pState->StartupState = startupState_Stabilize;
                }

                pState->openLoopSpeed = direction * pState->openLoopSpeed;
                pState->openLoopAngle += ( pState->openLoopSpeed * pState->speedToAngle );

                /** Truncate angle from 0 to 2Pi */
                mcUtils_TruncateAngle0To2Pi(&pState->openLoopAngle);

                *pIDref = 0.0f;
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
                pState->openLoopAngle += (pState->openLoopSpeed * pState->speedToAngle );

                /** Truncate angle from 0 to 2Pi */
                mcUtils_TruncateAngle0To2Pi(&pState->openLoopAngle);
                *pIDref = 0.0f;
                *pIQref = direction * pState->alignmentCurrent;

                break;
            }

            default:
            {
                /** For MISRA Compliance */
            }
            break;
        }

        *pAngle = pState->openLoopAngle;
        *pSpeed = pState->openLoopSpeed;

    }
    else
    {
        /** Reset pen loop start-up */
        mcSupI_OpenLoopStartupReset( pParameters );

        *pAngle = 0.0f;
        *pSpeed = 0.0f;
    }

    return openLoopStatus;
}


/*! \brief Reset Open loop start-up
 * 
 * Details.
 * Reset Open loop start-up
 * 
 * @param[in]: None 
 * @param[in/out]: None
 * @param[out]: None 
 * @return: 
 */
void mcSupI_OpenLoopStartupReset( const tmcSup_Parameters_s * const pParameters )
{
    /** Get the linked state variable */
    tmcSup_State_s * pState;
    pState = (tmcSup_State_s *)pParameters->pStatePointer;

    /** Reset open loop startup state variables  */
    pState->StartupState = startupState_Align;
    pState->openLoopSpeed = 0.0f;
    pState->openLoopAngle = 0.0f;
    pState->zCounter = 0u;
}
