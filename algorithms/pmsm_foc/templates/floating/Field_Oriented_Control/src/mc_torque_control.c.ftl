/*******************************************************************************
 Torque control source file

  Company:
    - Microchip Technology Inc.

  File Name:
    - mc_flux_control.c

  Summary:
    - Torque control source file

  Description:
    - This file implements functions for flux control

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
#include "mc_torque_control.h"

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
    tmcUtils_PiControl_s bPIController;
}tmcTor_State_s;

/*******************************************************************************
Private variables
*******************************************************************************/
static tmcTor_State_s mcTor_State_mds;

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
/*! \brief Initialize flux control module
 *
 * Details.
 * Initialize flux control module
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
void  mcTorI_TorqueControlInit( tmcTor_Parameters_s * const pParameters )
{
     /** Link state variable structure to the module */
     pParameters->pStatePointer = (void *)&mcTor_State_mds;

     /** Set parameters */
     mcTorI_ParametersSet(pParameters);

     /** Set PI controller parameters */
     mcUtils_PiControlInit( pParameters->Kp, pParameters->Ki, pParameters->dt, &mcTor_State_mds.bPIController );

     /** Set initialization flag as true */
     mcTor_State_mds.initDone = true;
}

/*! \brief Enable flux control module
 *
 * Details.
 * Enable flux control module
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
void  mcTorI_TorqueControlEnable( tmcTor_Parameters_s * const pParameters )
{
    /** Get the linked state variable */
    tmcTor_State_s * pState;
    pState = (tmcTor_State_s *)pParameters->pStatePointer;

    if( ( NULL == pState ) || ( !pState->initDone ))
    {
         /** Initialize parameters */
        mcTorI_TorqueControlInit(pParameters);
    }
    else
    {
         /** For MISRA Compliance */
    }

    /** Set enable flag as true */
    pState->enable = true;
}

/*! \brief Disable flux control module
 *
 * Details.
 * Disable flux control module
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
void  mcTorI_TorqueControlDisable( tmcTor_Parameters_s * const pParameters )
{
    /** Get the linked state variable */
    tmcTor_State_s * pState;
    pState = (tmcTor_State_s *)pParameters->pStatePointer;

    if( NULL != pState)
    {
        /** Reset state variables  */
        mcTorI_TorqueControlReset(pParameters);
    }
    else
    {
        /** For MISRA Compliance */
    }

    /** Set enable flag as true */
    pState->enable = false;

}

/*! \brief Torque control
 *
 * Details.
 * Torque control
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
void mcTorI_TorqueControlManual(  const tmcTor_Parameters_s * const pParameters,
                                                         const float32_t  Out )
{
     /** Get the linked state variable */
     tmcTor_State_s * pState;
     pState = (tmcTor_State_s *)pParameters->pStatePointer;

     if( pState->enable )
     {
          /** Execute PI controller */
          mcUtils_PiControlReset( Out, &pState->bPIController );
     }
     else
     {
         /** Reset PI Controller */
         mcUtils_PiControlReset( 0.0f, &pState->bPIController );
     }
}
/*! \brief Torque control
 *
 * Details.
 * Torque control
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
void mcTorI_TorqueControlAuto(  const tmcTor_Parameters_s * const pParameters,
                                              const float32_t iQref, const float32_t iQact, const float32_t yLimit,
                                              float32_t * const pOut )
{
     /** Get the linked state variable */
     tmcTor_State_s * pState;
     pState = (tmcTor_State_s *)pParameters->pStatePointer;

     if( pState->enable )
     {
         /** Calculate tracking error */
         float32_t error = iQref - iQact;

         /** ToDO: Calculate Ymax and Ymin based on the motor control states. Remove the magic numbers  */
         /** Limit update for PI controller */
         mcUtils_PiLimitUpdate( -yLimit, yLimit, &pState->bPIController );

         /** Execute PI controller */
         mcUtils_PiControl( error, &pState->bPIController );
         *pOut = pState->bPIController.Yo;
     }
     else
     {
         /** Reset PI Controller */
         mcUtils_PiControlReset( 0.0f, &pState->bPIController );
     }
}


/*! \brief Reset Torque control
 *
 * Details.
 * Reset Torque control
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return:
 */
void mcTorI_TorqueControlReset( const tmcTor_Parameters_s * const pParameters )
{
    /** Get the linked state variable */
    tmcTor_State_s * pState;
    pState = (tmcTor_State_s *)pParameters->pStatePointer;

    /** Reset PI Controller */
    mcUtils_PiControlReset( 0.0f, &pState->bPIController );
}
