/*******************************************************************************
 Flying Start source file

  Company:
    - Microchip Technology Inc.

  File Name:
    - mc_torque_control.c

  Summary:
    - Flying Start source file

  Description:
    - This file implements functions for flying Start
 
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
#include "mc_flying_start.h"

/*******************************************************************************
Local configuration options
*******************************************************************************/
#define ENABLE_ZERO_ORDER_HOLD
#define ENABLE_TUSTIN_APPROXIMATION

/*******************************************************************************
 Private data types
*******************************************************************************/

/*******************************************************************************
Private variables
*******************************************************************************/

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
/*! \brief Initialize flying Start module
 * 
 * Details.
 * Initialize flying Start module
 * 
 * @param[in]: None 
 * @param[in/out]: None
 * @param[out]: None 
 * @return: None
 */
void  mcFlyI_FlyingStartInit( tmcFly_Parameters_s * const pParameters )
{  
    /** Link state variable structure to the module */
    pParameters->pStatePointer = (void *)&mcFly_State_mds;

    /** Set parameters */
    mcFlyI_ParametersSet(pParameters);

    /** Update state variables */

}

/*! \brief Enable flying Start module
 *
 * Details.
 * Enable flying Start module
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
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

/*! \brief Disable flying Start module
 *
 * Details.
 * Disable flying Start module
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
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

/*! \brief Flying Start
 *
 * Details.
 * Flying Start
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
#ifdef RAM_EXECUTE
void __ramfunc__  mcFlyI_FlyingStart( const  tmcFly_Parameters_s * const pParameters  )
#else
void mcFlyI_FlyingStart( const tmcFly_Parameters_s * const pParameters )
#endif
{
     /** Get the linked state variable */
     tmcFly_State_s * pState;
     pState = (tmcFly_State_s *)pParameters->pStatePointer;

     if( pState->enable )
     {
         /** Execute flying start */
     }
     else
     {
         /** Reset flying start */
         mcFlyI_FlyingStartReset( &pParameters );
     }
}


/*! \brief Reset Flying Start
 * 
 * Details.
 * Reset Flying Start
 * 
 * @param[in]: None 
 * @param[in/out]: None
 * @param[out]: None 
 * @return: 
 */
void mcFlyI_FlyingStartReset( const tmcFly_Parameters_s * const pParameters )
{
    /** Reset flying start variables  */

}
