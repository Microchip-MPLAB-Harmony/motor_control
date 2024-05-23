/*******************************************************************************
 Flux control source file

  Company:
    - Microchip Technology Inc.

  File Name:
    - mc_speed_control.c

  Summary:
    - Flux control source file

  Description:
    - This file implements functions for speed control

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
#include "mc_speed_control.h"

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
}tmcSpe_State_s;

/*******************************************************************************
Private variables
*******************************************************************************/
static tmcSpe_State_s mcSpe_State_mds;

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
/*! \brief Initialize speed control module
 *
 * Details.
 * Initialize speed control module
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
void  mcSpeI_SpeedControlInit( tmcSpe_Parameters_s * const pParameters )
{
    /** Link state variable structure to the module */
    pParameters->pStatePointer = (void *)&mcSpe_State_mds;

    /** Set parameters */
    mcSpeI_ParametersSet(pParameters);

    /** Set PI controller parameters */
    mcUtils_PiControlInit( pParameters->Kp, pParameters->Ki, pParameters->dt, &mcSpe_State_mds.bPIController );

    /** Set initialization flag as true */
    mcSpe_State_mds.initDone = true;

}

/*! \brief Enable speed control module
 *
 * Details.
 * Enable speed control module
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
void  mcSpeI_SpeedControlEnable( tmcSpe_Parameters_s * const pParameters )
{
    /** Get the linked state variable */
    tmcSpe_State_s * pState;
    pState = (tmcSpe_State_s *)pParameters->pStatePointer;

    if( ( NULL == pState ) || ( !pState->initDone ))
    {
         /** Initialize parameters */
        mcSpeI_SpeedControlInit(pParameters);
    }
    else
    {
         /** For MISRA Compliance */
    }

    /** Set enable flag as true */
    pState->enable = true;
}

/*! \brief Disable speed control module
 *
 * Details.
 * Disable speed control module
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
void  mcSpeI_SpeedControlDisable( tmcSpe_Parameters_s * const pParameters )
{
    /** Get the linked state variable */
    tmcSpe_State_s * pState;
    pState = (tmcSpe_State_s *)pParameters->pStatePointer;

    if( NULL != pState)
    {
        /** Reset state variables  */
        mcSpeI_SpeedControlReset(pParameters);
    }
    else
    {
        /** For MISRA Compliance */
    }

    /** Set enable flag as true */
    pState->enable = false;

}

/*! \brief Flux control
 *
 * Details.
 * Flux control
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
void mcSpeI_SpeedControlManual(  const tmcSpe_Parameters_s * const pParameters,
                                                         const float32_t  Out )
{
    /** Get the linked state variable */
    tmcSpe_State_s * pState;
    pState = (tmcSpe_State_s *)pParameters->pStatePointer;

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
/*! \brief Flux control
 *
 * Details.
 * Flux control
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
void mcSpeI_SpeedControlAuto(  const tmcSpe_Parameters_s * const pParameters,
                                              const float32_t nref, const float32_t nact, float32_t * const pOut )
{
     /** Get the linked state variable */
     tmcSpe_State_s * pState;
     pState = (tmcSpe_State_s *)pParameters->pStatePointer;

     if( pState->enable )
     {
         /** Execute PI controller */
         float32_t error = nref - nact;

         /** ToDO: Calculate Ymax and Ymin based on the motor control states. Remove the magic numbers  */
         pState->bPIController.Ymax = pParameters->Ymax;
         pState->bPIController.Ymin = -pParameters->Ymax;

         mcUtils_PiControl( error, &pState->bPIController );
         *pOut = pState->bPIController.Yo;
     }
     else
     {
         /** Reset PI Controller */
         mcUtils_PiControlReset( 0.0f, &pState->bPIController );
     }
}


/*! \brief Reset Flux control
 *
 * Details.
 * Reset Flux control
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return:
 */
void mcSpeI_SpeedControlReset( const tmcSpe_Parameters_s * const pParameters )
{
     /** Get the linked state variable */
     tmcSpe_State_s * pState;
     pState = (tmcSpe_State_s *)pParameters->pStatePointer;

    /** Reset PI Controller */
    mcUtils_PiControlReset( 0.0f, &pState->bPIController );
}
