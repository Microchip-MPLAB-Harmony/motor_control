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
#define ENABLE_STEP_REFERENCE ENABLE

/*******************************************************************************
 Private data types
*******************************************************************************/
typedef struct
{
    bool enable;
    bool initDone;
#if ( ENABLE == ENABLE_RAMP_REFERENCE )
    int16_t reference;
    int16_t rampRate;
    int16_t lowerLimit;
    int16_t upperLimit;
#endif
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
#if( ENABLE == ENABLE_SPEED_CONTROL )
    mcRef_State_mds.lowerLimit = K_SPEED * pParameters->minimumRpm;
    mcRef_State_mds.upperLimit = K_SPEED * pParameters->maximumRpm;

    /** ToDO: To calculate based on fed parameters  */
    mcRef_State_mds.rampRate = 1;

#endif

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
#if ( ENABLE == ENABLE_STEP_REFERENCE )
         *pOut = command;
#endif

#if ( ENABLE == ENABLE_RAMP_REFERENCE )
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
#endif
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
    /** Reset reference control state variables  */
}
