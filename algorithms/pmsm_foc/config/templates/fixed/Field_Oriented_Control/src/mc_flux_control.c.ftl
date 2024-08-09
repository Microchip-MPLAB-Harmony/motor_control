/**
 * @brief 
 *    Flux Control source file
 *
 * @File Name 
 *    mc_flux_control.c
 *
 * @Company 
 *   Microchip Technology Inc.
 *
 * @Summary
 *    This file contains definitions for Flux Control functions and data structures.
 *
 * @Description
 *    This file provides the implementation of functions and data structures necessary for 
 *    Flux Control, which includes controlling the flux of a motor in various operating modes.
 *    Functions include initialization, enabling/disabling, manual and automatic control modes,
 *    flux weakening, and MTPA (Maximum Torque per Ampere) control.
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
#include "mc_flux_control.h"

/*******************************************************************************
 * Local configuration options
*******************************************************************************/

/*******************************************************************************
 * Private data types
*******************************************************************************/
<#if MCPMSMFOC_ENABLE_MTPA == true >
/**
 * @brief Structure defining MTPA module state
 */
typedef struct
{
    bool enable;         /*!< Flag indicating if MTPA module is enabled */
    bool initDone;       /*!< Flag indicating if MTPA module initialization is done */

    int32_t K1;          /*!< K1 parameter */
    int32_t K2;          /*!< K2 parameter */
    int16_t mtpaIdRef;   /*!< Reference id current */
} tmcFlx_MTPA_s;
</#if>

<#if MCPMSMFOC_ENABLE_FW == true >
typedef struct {
    bool enable;
    bool initDone;
    int16_t RsValue;
    uint16_t RsShift;
    int16_t LdValue;
    uint16_t LdShift;
    int16_t KeValue;
    uint16_t KeShift;
    int16_t uqrefLimit;
    int16_t absIqRs;
    int16_t eMagnitude;
    int16_t omegaLdId;
    int16_t omegaLd;
    int16_t fluxWeakIdRef;
}tmcFlx_FieldWeakening_s;
</#if>

/**
 * @brief Structure defining flux control state
 */
typedef struct
{
    bool enable;                    /*!< Flag indicating if flux control is enabled */
    bool initDone;                  /*!< Flag indicating if flux control initialization is done */
<#if MCPMSMFOC_ENABLE_MTPA == true >
    tmcFlx_MTPA_s bMTPA;            /*!< MTPA module state structure */
</#if>
<#if MCPMSMFOC_ENABLE_FW == true >
    tmcFlx_FieldWeakening_s bFieldWeakening;  /*!< Flux weakening module state structure */
</#if>
    tmcUtils_PiControl_s bPIController; /*!< PI controller state structure */
} tmcFlx_State_s;

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
<#if MCPMSMFOC_ENABLE_MTPA == true >
/*!
 * @brief MTPA parameters initialization
 *
 *  MTPA parameters initialization
 *
 * @param[in] pParameters Pointer to module parameters structure
 * @return None
 */
void  mcFlx_MTPAInit( tmcFlx_Parameters_s * const pParameters )
{
    float32_t f32a;

    /** Get the linked state variable */
    tmcFlx_State_s * pState;
    pState = (tmcFlx_State_s *)pParameters->pStatePointer;

    /** Calculate air-gap flux */
    f32a = pParameters->pMotorParameters->KeInVrmsPerKrpm;
    float32_t airGapFlux = (float32_t)(  60.0f * f32a / ( 1.414f * 1000 * ONE_PI ));

    /** Calculate inductance difference  */
    float32_t ldLqDiff = pParameters->pMotorParameters->LdInHenry - pParameters->pMotorParameters->LqInHenry;

    /** Calculate intermediate coefficients for MTPA current calculation */
    f32a = -(float32_t)( 0.5f * airGapFlux / ldLqDiff );
    pState->bMTPA.K1 = f32a * K_CURRENT;
    pState->bMTPA.K2 = ( pState->bMTPA.K1 * pState->bMTPA.K1 ) >> 2u;

    /** Set initialization flag */
    pState->bMTPA.initDone = true;
}

/*!
 * @brief Get MTPA current
 *
 * Get MTPA current
 *
 * @param[in] pParameters Pointer to module parameters structure
 * @param[in] pUDQ Pointer to DQ axis voltage
 * @param[in] pIDQ Pointer to DQ axis current
 * @param[in] wmechRPM Mechanical speed of motor
 * @param[in] uBus Bus voltage
 * @return None
 */
#ifdef RAM_EXECUTE
int16_t __ramfunc__ mcFlx_MTPA( tmcFlx_MTPA_s * const pMTPA, tmcTypes_DQ_s * const pIDQ )
#else
int16_t mcFlx_MTPA( tmcFlx_MTPA_s * const pMTPA, tmcTypes_DQ_s * const pIDQ )
#endif
{
    if( !pMTPA->enable ) {
        return 0;
    }

    int32_t  iqSquareBy4;
    iqSquareBy4 = ((int32_t)pIDQ->q * (int32_t)pIDQ->q ) >> 2u;
    pMTPA->mtpaIdRef = (int32_t)pMTPA->K1 - ((int32_t)mcUtils_SquareRoot( (uint32_t)pMTPA->K2 + (uint32_t)iqSquareBy4 ) << 1u );

    return pMTPA->mtpaIdRef;
}

/*!
 * @brief MTPA reset
 *
 * Get MTPA current
 *
 * @param[in] pParameters Pointer to module parameters structure
 * @return None
 */
void  mcFlx_MTPAReset( const tmcFlx_Parameters_s * const pParameters )
{
    /** Get the linked state variable */
    tmcFlx_State_s * pState;
    pState = (tmcFlx_State_s *)pParameters->pStatePointer;

    /** Reset MTPA values   */
    pState->bMTPA.mtpaIdRef = 0;
}
/*!
 * @brief MTPA parameters enable
 *
 *  MTPA parameters enable
 *
 * @param[in] pParameters Pointer to module parameters structure
 * @return None
 */
void  mcFlx_MTPAEnable( tmcFlx_Parameters_s * const pParameters )
{
    /** Get the linked state variable */
    tmcFlx_State_s * pState;
    pState = (tmcFlx_State_s *)pParameters->pStatePointer;

    if( ( NULL == pState ) || ( !pState->bMTPA.initDone ))
    {
        /** Initialize parameters */
        mcFlx_MTPAInit(pParameters);
    }
    else
    {
        /** For MISRA Compliance */
    }

    /** Set enable flag as true */
    pState->bMTPA.enable = true;
}

/*!
 * @brief MTPA parameters disable
 *
 *  MTPA parameters disable
 *
 * @param[in] pParameters Pointer to module parameters structure
 * @return None
 */
void  mcFlx_MTPADisable( tmcFlx_Parameters_s * const pParameters )
{
    /** Get the linked state variable */
    tmcFlx_State_s * pState;
    pState = (tmcFlx_State_s *)pParameters->pStatePointer;

    if( NULL != pState)
    {
        /** Reset state variables  */
        mcFlx_MTPAReset(pParameters);
    }
    else
    {
        /** For MISRA Compliance */
    }

    /** Set enable flag as true */
    pState->bMTPA.enable = false;
}
</#if>

<#if MCPMSMFOC_ENABLE_FW == true >
/*!
 * @brief Field weakening parameters initialization
 *
 * Get field weakening current
 *
 * @param[in] pParameters Pointer to module parameters structure
 * @return None
 */
void  mcFlx_FieldWeakeningInit( tmcFlx_Parameters_s * const pParameters )
{
    float32_t f32a;

    /** Get the linked state variable */
    tmcFlx_State_s * pState;
    pState = (tmcFlx_State_s *)pParameters->pStatePointer;

    /** Calculate scaled values  */
    f32a = pParameters->pMotorParameters->RsInOhms/ BASE_IMPEDENCE_IN_OHMS;
    mcUtils_FloatToValueShiftPair( f32a, &pState->bFieldWeakening.RsValue, &pState->bFieldWeakening.RsShift );

    f32a = pParameters->pMotorParameters->LdInHenry * BASE_SPEED_IN_RPM / ( pParameters->fwTuneFactor * BASE_IMPEDENCE_IN_OHMS );
    mcUtils_FloatToValueShiftPair( f32a, &pState->bFieldWeakening.LdValue, &pState->bFieldWeakening.LdShift );

    /** BEMF constant values  */
    f32a = pParameters->pMotorParameters->KeInVrmsPerKrpm / ( 1225.0f * (BASE_VOLTAGE_IN_VOLTS/ BASE_SPEED_IN_RPM ));
    mcUtils_FloatToValueShiftPair( f32a, &pState->bFieldWeakening.KeValue, &pState->bFieldWeakening.KeShift );

    /** Set initialization flag */
    pState->bFieldWeakening.initDone = true;
}

/*!
 * @brief Get field weakening current
 *
 * Get field weakening current
 *
 * @param[in] pParameters Pointer to module parameters structure
 * @param[in] pUDQ Pointer to DQ axis voltage
 * @param[in] pIDQ Pointer to DQ axis current
 * @param[in] wmechRPM Mechanical speed of motor
 * @param[in] uBus Bus voltage
 * @return None
 */
#ifdef RAM_EXECUTE
int16_t __ramfunc__ mcFlx_FieldWeakening( tmcFlx_FieldWeakening_s * const pFieldWeakening,
                                        const tmcTypes_DQ_s * const pUDQ,
                                        tmcTypes_DQ_s * const pIDQ,
                                        tmcTypes_AlphaBeta_s * const pEAlphaBeta,
                                        const int16_t wmechRPM,
                                        const int16_t uBus )
#else
int16_t  mcFlx_FieldWeakening(  tmcFlx_FieldWeakening_s * const pFieldWeakening,
                                        const tmcTypes_DQ_s * const pUDQ,
                                        tmcTypes_DQ_s * const pIDQ,
                                        tmcTypes_AlphaBeta_s * const pEAlphaBeta,
                                        const int16_t wmechRPM,
                                        const int16_t uBus )
#endif
{
    int16_t absIq;
    int16_t absRPM;

    if( !pFieldWeakening->enable )    {
        return 0;
    }

    int32_t uqrefLimitSquare;

    /** Calculate maximum q-axis reference voltage */
    uqrefLimitSquare = ( (int32_t)uBus * (int32_t)uBus) - ((int32_t)pUDQ->d * (int32_t)pUDQ->d);
    pFieldWeakening->uqrefLimit = mcUtils_SquareRoot( uqrefLimitSquare );

    /** Calculate BEMF voltage magnitude from mechanical RPM */
    pFieldWeakening->eMagnitude = mcUtils_SquareRoot(( pEAlphaBeta->alpha * pEAlphaBeta->alpha ) + ( pEAlphaBeta->beta * pEAlphaBeta->beta ));

    /** Calculate resistive drop  */
    absIq = UTIL_Abs16( pIDQ->q );
    pFieldWeakening->absIqRs =  ((int32_t)pFieldWeakening->RsValue *  (int32_t)absIq ) >> pFieldWeakening->RsShift;

    /** Calculate numerator */
    pFieldWeakening->omegaLdId = pFieldWeakening->uqrefLimit - pFieldWeakening->absIqRs - pFieldWeakening->eMagnitude;

    /** Calculate numerator */
    absRPM = UTIL_Abs16( wmechRPM );
    pFieldWeakening->omegaLd = ( (int32_t)absRPM *  (int32_t)pFieldWeakening->LdValue ) >>  pFieldWeakening->LdShift;

    /** Calculate reference */
    if( pFieldWeakening->omegaLdId < 0 && pFieldWeakening->omegaLd != 0)
    {
        pFieldWeakening->fluxWeakIdRef = Q_DIVISION( pFieldWeakening->omegaLdId, pFieldWeakening->omegaLd );
    }
    else
    {
        pFieldWeakening->fluxWeakIdRef = 0;
    }

    return pFieldWeakening->fluxWeakIdRef;
}

/*!
 * @brief Field weakening reset
 *
 * Get field weakening current
 *
 * @param[in] pParameters Pointer to module parameters structure
 * @return None
 */
void  mcFlx_FieldWeakeningReset( const tmcFlx_Parameters_s * const pParameters )
{
    /** Get the linked state variable */
    tmcFlx_State_s * pState;
    pState = (tmcFlx_State_s *)pParameters->pStatePointer;

    /** Calculate scaled values  */
    pState->bFieldWeakening.fluxWeakIdRef = 0;
}


/*!
 * @brief Field weakening enable
 *
 *  Field weakening enable
 *
 * @param[in] pParameters Pointer to module parameters structure
 * @return None
 */
void  mcFlx_FieldWeakeningEnable( tmcFlx_Parameters_s * const pParameters )
{
    /** Get the linked state variable */
    tmcFlx_State_s * pState;
    pState = (tmcFlx_State_s *)pParameters->pStatePointer;

    if( ( NULL == pState ) || ( !pState->bFieldWeakening.initDone ))
    {
        /** Initialize parameters */
        mcFlx_FieldWeakeningInit(pParameters);
    }
    else
    {
        /** For MISRA Compliance */
    }

    /** Set enable flag as true */
    pState->bFieldWeakening.enable = true;
}

/*!
 * @brief Field weakening disable
 *
 *  Field weakening disable
 *
 * @param[in] pParameters Pointer to module parameters structure
 * @return None
 */
void  mcFlx_FieldWeakeningDisable( tmcFlx_Parameters_s * const pParameters )
{
    /** Get the linked state variable */
    tmcFlx_State_s * pState;
    pState = (tmcFlx_State_s *)pParameters->pStatePointer;

    if( NULL != pState)
    {
        /** Reset state variables  */
        mcFlx_FieldWeakeningReset(pParameters);
    }
    else
    {
        /** For MISRA Compliance */
    }

    /** Set enable flag as true */
    pState->bFieldWeakening.enable = false;
}
</#if>

/*******************************************************************************
 * Interface Functions
*******************************************************************************/
/*! 
 * @brief Initialize flux control module
 *
 * Initializes the flux control module.
 *
 * @param[in] pParameters Pointer to module parameters structure
 * @return None
 */
void  mcFlxI_FluxControlInit( tmcFlx_Parameters_s * const pParameters )
{
    /** Link state variable structure to the module */
    pParameters->pStatePointer = (void *)&mcFlx_State_mds;

    /** Set parameters */
    mcFlxI_ParametersSet(pParameters);

    /** Set PI controller parameters */
    float32_t Kp = pParameters->Kp * BASE_CURRENT_IN_AMPS / BASE_VOLTAGE_IN_VOLTS;
    float32_t Ki  = pParameters->Ki * BASE_CURRENT_IN_AMPS / BASE_VOLTAGE_IN_VOLTS;
    mcUtils_PiControlInit( Kp, Ki, pParameters->dt, &mcFlx_State_mds.bPIController );

    /** Set initialization flag as true */
    mcFlx_State_mds.initDone = true;
}

/*! 
 * @brief Enable flux control module
 *
 * Enables the flux control module.
 *
 * @param[in] pParameters Pointer to module parameters structure
 * @return None
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

<#if MCPMSMFOC_ENABLE_FW == true >
    /** Enable flux weakening by default */
    mcFlx_FieldWeakeningEnable( pParameters );
</#if>

<#if MCPMSMFOC_ENABLE_MTPA == true >
    /** Enable MTPA by default */
    mcFlx_MTPAEnable( pParameters );
</#if>

    /** Set enable flag as true */
    pState->enable = true;
}

/*! 
 * @brief Disable flux control module
 *
 * Disables the flux control module.
 *
 * @param[in] pParameters Pointer to module parameters structure
 * @return None
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

/*! 
 * @brief Flux control - Manual/ Tracking mode
 *
 * Performs Flux control - Manual/ Tracking mode
 *
 * @param[in] pParameters Pointer to module parameters structure
 * @param[in] Out Output value for manual control
 * @return None
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

/*! 
 * @brief Flux control
 *
 * Performs flux control.
 *
 * @param[in] pParameters Pointer to module parameters structure
 * @param[in] iDref Reference d-axis current
 * @param[in] iDact Actual d-axis current
 * @param[out] pOut Pointer to output variable for automatic control
 * @return None
 */
#ifdef RAM_EXECUTE
void __ramfunc__  mcFlxI_FluxControlAuto( const tmcFlx_Parameters_s * const pParameters,
                                        const int16_t iDref, const int16_t iDact, int16_t iDmax, int16_t * const pOut   )
#else
void __ramfunc__  mcFlxI_FluxControlAuto( const tmcFlx_Parameters_s * const pParameters,
                                        const int16_t iDref, const int16_t iDact, int16_t iDmax, int16_t * const pOut   )
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
        mcUtils_PiLimitUpdate( -iDmax, iDmax, &pState->bPIController );

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


/*! 
 * @brief Reset flux control
 *
 * Resets the flux control module.
 *
 * @param[in] pParameters Pointer to module parameters structure
 * @return None
 */
void mcFlxI_FluxControlReset( const tmcFlx_Parameters_s * const pParameters )
{
    /** Get the linked state variable */
    tmcFlx_State_s * pState;
    pState = (tmcFlx_State_s *)pParameters->pStatePointer;

    /** Reset PI Controller */
    mcUtils_PiControlReset( 0, &pState->bPIController );

<#if MCPMSMFOC_ENABLE_MTPA == true >
    /** Reset max-torque per ampere ( MTPA ) */
    mcFlx_MTPAReset( pParameters );
</#if>
}

<#if ( MCPMSMFOC_ENABLE_MTPA == true ) || ( MCPMSMFOC_ENABLE_FW == true ) >
/*!
 * @brief Get reference flux
 *
 * Get reference flux
 *
 * @param[in] pParameters Pointer to module parameters structure
 * @return None
 */
#ifdef RAM_EXECUTE
void __ramfunc__ mcFlxI_FluxReferenceGet(  const tmcFlx_Parameters_s * const pParameters,
                                        const tmcTypes_DQ_s * const pUDQ,
                                        tmcTypes_DQ_s * const pIDQ,
                                        tmcTypes_AlphaBeta_s * const pEAlphaBeta,
                                        const int16_t wmechRPM,
                                        const int16_t uBus,
                                        int16_t * const pIdref )
#else
void  mcFlxI_FluxReferenceGet(  const tmcFlx_Parameters_s * const pParameters,
                                        const tmcTypes_DQ_s * const pUDQ,
                                        tmcTypes_DQ_s * const pIDQ,
                                        tmcTypes_AlphaBeta_s * const pEAlphaBeta,
                                        const int16_t wmechRPM,
                                        const int16_t uBus,
                                        int16_t * const pIdref )
#endif
{
    /** Get the linked state variable */
    tmcFlx_State_s * pState;
    pState = (tmcFlx_State_s *)pParameters->pStatePointer;

<#if ( MCPMSMFOC_ENABLE_MTPA == true ) && ( MCPMSMFOC_ENABLE_FW == true ) >
    int16_t idrefFW = mcFlx_FieldWeakening( &pState->bFieldWeakening, pUDQ, pIDQ, pEAlphaBeta, wmechRPM, uBus );
    int16_t idrefMTPA = mcFlx_MTPA(&pState->bMTPA, pIDQ );

    if( idrefFW < idrefMTPA ) {
        *pIdref = idrefFW;
    }
    else {
        *pIdref = idrefMTPA;
    }
<#elseif MCPMSMFOC_ENABLE_MTPA == true >
    *pIdref = mcFlx_MTPA(&pState->bMTPA, pIDQ );
<#else>
    *pIdref = mcFlx_FieldWeakening( &pState->bFieldWeakening, pUDQ, pIDQ, pEAlphaBeta, wmechRPM, uBus );
</#if>
}
</#if>