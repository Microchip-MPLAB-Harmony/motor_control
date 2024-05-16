/*******************************************************************************
 Reference control source file

  Company:
    - Microchip Technology Inc.

  File Name:
    - mc_reference_control.c

  Summary:
    - Reference control source file

  Description:
    - This file implements functions for reference control

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
#include "mc_reference_control.h"

/*******************************************************************************
Local configuration options
*******************************************************************************/


/*******************************************************************************
 Private data types
*******************************************************************************/
typedef struct
{
    bool enable;
    bool initDone;
    float32_t lowerLimit;
    float32_t upperLimit;
<#if MCPMSMFOC_RAMP_PROFILES == 'Linear'>
    float32_t reference;
    float32_t rampRate;
</#if>
}tmcRef_State_s;

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

/*! \brief Initialize reference control module
 *
 * Details.
 * Initialize reference control module
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
void  mcRefI_ReferenceControlInit( tmcRef_Parameters_s * const pParameters )
{
    /** Link state variable structure to the module */
    pParameters->pStatePointer = (void *)&mcRef_State_mds;

    /** Set parameters */
    mcRefI_ParametersSet(pParameters);

    /** Update state variables */
<#if ( MCPMSMFOC_CONTROL_TYPE == 'SPEED_LOOP' ) >
    mcRef_State_mds.lowerLimit = pParameters->minimumRpm;
    mcRef_State_mds.upperLimit = pParameters->maximumRpm;

<#if MCPMSMFOC_RAMP_PROFILES == 'Linear'>
    /** Calculate ramp rate per cycle   */
    mcRef_State_mds.rampRate = pParameters->rpmPerSecond * pParameters->dt;
</#if>
<#elseif ( MCPMSMFOC_CONTROL_TYPE == 'POSITION_LOOP' )>
    mcRef_State_mds.lowerLimit = pParameters->minimum;
    mcRef_State_mds.upperLimit = pParameters->maximum;

<#if MCPMSMFOC_RAMP_PROFILES == 'Linear'>
    /** Calculate ramp rate per cycle   */
    mcRef_State_mds.rampRate = pParameters->rampRate * pParameters->dt;
</#if>
</#if>

    mcRef_State_mds.initDone = true;
}

/*! \brief Enable reference control module
 *
 * Details.
 * Enable reference control module
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
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

/*! \brief Disable reference control module
 *
 * Details.
 * Disable reference control module
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
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

/*! \brief Reference control
 *
 * Details.
 * Reference control
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
void mcRefI_ReferenceControl(  tmcRef_Parameters_s * const pParameters,
                                                    const float32_t command, float32_t * const pOut )
{
     /** Get the linked state variable */
     tmcRef_State_s * pState;
     pState = (tmcRef_State_s *)pParameters->pStatePointer;

     if( pState->enable )
     {
         /** Execute reference control */
<#if MCPMSMFOC_RAMP_PROFILES == 'Step'>
         /** Clamp the reference  */
         if( command > pState->upperLimit )
         {
             *pOut = pState->upperLimit;
         }
         else if( command < pState->lowerLimit)
         {
             *pOut = pState->lowerLimit;
         }
         else
         {
             *pOut = command;
         }

<#elseif MCPMSMFOC_RAMP_PROFILES == 'Linear'>
         if( ( pState->reference + pState->rampRate ) < command )
         {
             /** Ramp-up*/
             pState->reference += pState->rampRate;
         }
         else if( ( pState->reference - pState->rampRate ) > command )
         {
             /** Ramp-down */
             pState->reference -= pState->rampRate;
         }
         else
         {
             pState->reference = command;
         }

         /** Clamp the reference  */
         if( pState->reference > pState->upperLimit )
         {
             pState->reference = pState->upperLimit;
         }
         else if( pState->reference < pState->lowerLimit)
         {
             pState->reference = pState->lowerLimit;
         }
         else
         {
             /** For MISRA Compliance */
         }

         *pOut = pState->reference;
</#if>
     }
     else
     {
         /** Reset reference control */
      }
}


/*! \brief Reset Reference control
 *
 * Details.
 * Reset Reference control
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return:
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
<#else>
    /** Reset reference control state variables  */
    pState->reference = pState->lowerLimit;
</#if>
</#if>
}
