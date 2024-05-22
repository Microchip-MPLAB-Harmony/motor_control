/*******************************************************************************
 Flux control source file

  Company:
    - Microchip Technology Inc.

  File Name:
    - mc_flux_control.c

  Summary:
    - Flux control source file

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
#include "mc_flux_control.h"

/*******************************************************************************
Local configuration options
*******************************************************************************/
#define ONE_BY_SQRT3_FLOAT (float32_t)( 0.577350269 )
#define TWO_PI_FLOAT (float32_t)(6.28318530f)


/*******************************************************************************
 Private data types
*******************************************************************************/
typedef struct
{
    bool enable;
    bool initDone;
    int16_t psi;
    int32_t K1;
    int32_t K2;
    int16_t idref;
}tmcFlx_MTPA_s;

typedef struct
{
    bool enable;
    bool initDone;
    tmcFlx_MTPA_s bMTPA;
    tmcUtils_PiControl_s bPIController;
}tmcFlx_State_s;

/*******************************************************************************
Private variables
*******************************************************************************/
static tmcFlx_State_s mcFlx_State_mds;

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
void  mcFlxI_FluxControlInit( tmcFlx_Parameters_s * const pParameters )
{
    /** Link state variable structure to the module */
    pParameters->pStatePointer = (void *)&mcFlx_State_mds;

    /** Set parameters */
    mcFlxI_ParametersSet(pParameters);

    /** Set PI controller parameters */
    float32_t Kp = pParameters->Kp;// * BASE_SPEED_IN_RPM / BASE_CURRENT_IN_AMPS;
    float32_t Ki  = pParameters->Ki;// * BASE_SPEED_IN_RPM / BASE_CURRENT_IN_AMPS;
    mcUtils_PiControlInit( Kp, Ki, pParameters->dt, &mcFlx_State_mds.bPIController );

    /** Set initialization flag as true */
    mcFlx_State_mds.initDone = true;

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
void  mcFlxI_FluxControlEnable( tmcFlx_Parameters_s * const pParameters )
{
    /** Get the linked state variable */
    tmcFlx_State_s * pState;
    pState = (tmcFlx_State_s *)pParameters->pStatePointer;

    if( ( NULL == pState ) || ( !pState->initDone ))
    {
         /** Initialize parameters */
        mcFlxI_FluxControlInit(pParameters);
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
void  mcFlxI_FluxControlDisable( tmcFlx_Parameters_s * const pParameters )
{
    /** Get the linked state variable */
    tmcFlx_State_s * pState;
    pState = (tmcFlx_State_s *)pParameters->pStatePointer;

    if( NULL != pState)
    {
        /** Reset state variables  */
        mcFlxI_FluxControlReset(pParameters);
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
#ifdef RAM_EXECUTE
void __ramfunc__  mcFlxI_FluxControlManual( const tmcFlx_Parameters_s * const pParameters,
                                                                   const int16_t Out   )
#else
void mcFlxI_FluxControlManual(  const tmcFlx_Parameters_s * const pParameters,
                                                         const int16_t  Out )
#endif
{
    /** Get the linked state variable */
    tmcFlx_State_s * pState;
    pState = (tmcFlx_State_s *)pParameters->pStatePointer;

    if( pState->enable )
    {
        /** Execute PI controller */
        mcUtils_PiControlReset( Out, &pState->bPIController );
    }
    else
    {
        /** Reset PI Controller */
        mcUtils_PiControlReset( 0, &pState->bPIController );
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
#ifdef RAM_EXECUTE
void __ramfunc__  mcFlxI_FluxControlAuto( const tmcFlx_Parameters_s * const pParameters,
                                        const int16_t iDref, const int16_t iDact, int16_t * const pOut   )
#else
void mcFlxI_FluxControlAuto(  const tmcFlx_Parameters_s * const pParameters,
                           const int16_t iDref, const int16_t iDact, int16_t * const pOut )
#endif
{
    /** Get the linked state variable */
    tmcFlx_State_s * pState;
    pState = (tmcFlx_State_s *)pParameters->pStatePointer;

    if( pState->enable )
    {
        /** Calculate the error */
        int16_t error = iDref - iDact;

        /** Limit update for PI controller */
        mcUtils_PiLimitUpdate( -16384, 16383, &pState->bPIController );

        /** Excecute PI controller */
        mcUtils_PiControl( error, &pState->bPIController );

        *pOut = pState->bPIController.Yo;
    }
    else
    {
        /** Reset PI Controller */
        mcUtils_PiControlReset( 0, &pState->bPIController );
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
void mcFlxI_FluxControlReset( const tmcFlx_Parameters_s * const pParameters )
{
    /** Get the linked state variable */
    tmcFlx_State_s * pState;
    pState = (tmcFlx_State_s *)pParameters->pStatePointer;

    /** Reset PI Controller */
    mcUtils_PiControlReset( 0, &pState->bPIController );
}

<#if MCPMSMFOC_ENABLE_FW == true >
/*! \brief Enable flux weakening module
 *
 * Details.
 * Enable flux weakening module
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
void  mcFlxI_FluxWeakeningEnable( tmcFlx_Parameters_s * const pParameters )
{

}

/*! \brief Disable flux weakening module
 *
 * Details.
 * Disable flux weakening module
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
void  mcFlxI_FluxWeakeningDisable( tmcFlx_Parameters_s * const pParameters )
{

}

/*! \brief Initialize flux weakening module
 *
 * Details.
 * Initialize flux weakening module
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
void  mcFlxI_FluxWeakeningInit( tmcFlx_Parameters_s * const pParameters )
{

}

<#if MCPMSMFOC_POSITION_CALC_ALGORITHM == 'SENSORED_ENCODER'>
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
#ifdef RAM_EXECUTE
void __ramfunc__ mcFlxI_FluxWeakening(  const tmcFlx_Parameters_s * const pParameters,
                                        const tmcTypes_DQ_s * const pUDQ,
                                        const float32_t uBus,
                                        const float32_t wmechRPM,
                                        tmcTypes_DQ_s * const pIDQ,
                                        float32_t * const pIdref )
#else
void mcFlxI_FluxWeakening(  const tmcFlx_Parameters_s * const pParameters,
                            const tmcTypes_DQ_s * const pUDQ,
                            const float32_t uBus,
                            const float32_t wmechRPM,
                            tmcTypes_DQ_s * const pIDQ,
                            float32_t * const pIdref )
#endif
{

}

<#else>
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
#ifdef RAM_EXECUTE
void __ramfunc__ mcFlxI_FluxWeakening(  const tmcFlx_Parameters_s * const pParameters,
                                        const tmcTypes_DQ_s * const pUDQ,
                                        const tmcTypes_AlphaBeta_s * const pEAlphaBeta,
                                        const int16_t uBus,
                                        const int16_t wmechRPM,
                                        tmcTypes_DQ_s * const pIDQ,
                                        int16_t * const pIdref )
#else
void mcFlxI_FluxWeakening(  const tmcFlx_Parameters_s * const pParameters,
                            const tmcTypes_DQ_s * const pUDQ,
                            const tmcTypes_AlphaBeta_s * const pEAlphaBeta,
                            const int16_t uBus,
                            const int16_t wmechRPM,
                            tmcTypes_DQ_s * const pIDQ,
                            int16_t * const pIdref )

#endif
{

}
</#if>

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
void mcFlxI_FluxWeakeningReset( const tmcFlx_Parameters_s * const pParameters )
{

}

</#if>

<#if MCPMSMFOC_ENABLE_MTPA == true >
/*! \brief Enable MTPA module
 *
 * Details.
 * Enable MTPA module
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
void  mcFlxI_MTPAEnable( tmcFlx_Parameters_s * const pParameters )
{
    /** Get the linked state variable */
    tmcFlx_MTPA_s * pState;
    pState = &((tmcFlx_State_s *)pParameters->pStatePointer)->bMTPA;

    if( ( NULL == pState ) || ( !pState->initDone ))
    {
        /** Initialize parameters */
        mcFlxI_MTPAInit(pParameters);
    }
    else
    {
        /** For MISRA Compliance */
    }

    /** Set enable flag as true */
    pState->enable = true;
}

/*! \brief Disable MTPA module
 *
 * Details.
 * Disable MTPA module
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
void  mcFlxI_MTPADisable( tmcFlx_Parameters_s * const pParameters )
{
    /** Get the linked state variable */
    tmcFlx_MTPA_s * pState;
    pState = &((tmcFlx_State_s *)pParameters->pStatePointer)->bMTPA;

    if( NULL != pState)
    {
        /** Reset state variables  */
        mcFlxI_MTPAReset(pParameters);
    }
    else
    {
        /** For MISRA Compliance */
    }

    /** Set enable flag as true */
    pState->enable = false;
}

/*! \brief Disable MTPA module
 *
 * Details.
 * Disable MTPA module
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
void  mcFlxI_MTPAInit( tmcFlx_Parameters_s * const pParameters )
{
    float32_t f32a;
    tmcFlx_MTPA_s * pState;

    /** Get the linked state variable */
    pState = &((tmcFlx_State_s *)pParameters->pStatePointer)->bMTPA;

     /** Calculate per-phase KEMF in Vpeak per Krpm */
    f32a = ONE_BY_SQRT3_FLOAT * pParameters->pMotorParameters->KeInVpeakPerKrpm;

    // Calculate in radian/s
    f32a = f32a * 60.0f / (TWO_PI_FLOAT * 1000.0f);
    pState->psi = f32a * pParameters->pMotorParameters->PolePairs;

     /** Calculate intermediate value */
    float32_t LdDiff = pParameters->pMotorParameters->LdInHenry - pParameters->pMotorParameters->LdInHenry;
    f32a = 0.5f * pState->psi / LdDiff;

     /** Determine constant values */
    pState->K1 = (int32_t)(K_CURRENT * f32a + 0.5f);
    pState->K2 = pState->K1 * pState->K1;

     /** Set enable flag as true */
    pState->initDone = true;
}

/*! \brief Disable MTPA module
 *
 * Details.
 * Disable MTPA module
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
#ifdef RAM_EXECUTE
void __ramfunc__  mcFlxI_MTPA( tmcFlx_Parameters_s * const pParameters,
                   const tmcTypes_DQ_s * const pIdq, int16_t * const pIdref )
#else
void mcFlxI_MTPA( tmcFlx_Parameters_s * const pParameters,
                   const tmcTypes_DQ_s * const pIdq, int16_t * const pIdref )
#endif
{
    tmcFlx_MTPA_s * pState =&( (tmcFlx_State_s *)pParameters->pStatePointer)->bMTPA;

    if( pState->enable )
    {
        /** Determine second term of MTPA equation */
        int32_t s32a = ((int32_t)pIdq->q * (int32_t)pIdq->q) + pState->K2;

        /** Calculate d-axis reference current for MTPA */
        *pIdref = pState->K1 - mcUtils_SquareRoot(s32a);
    }
    else
    {
        mcFlxI_MTPAReset(pParameters);
    }

}


/*! \brief Disable MTPA module
 *
 * Details.
 * Disable MTPA module
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
void  mcFlxI_MTPAReset( tmcFlx_Parameters_s * const pParameters )
{

}

</#if>

