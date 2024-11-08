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
#include "mc_motor.h"

/*******************************************************************************
Local configuration options
*******************************************************************************/

/*******************************************************************************
 Private data types
*******************************************************************************/
<#if ( MCPMSMFOC_ENABLE_FW == true ) >
typedef struct
{
    bool enable;
    bool initDone;
    bool feedForwardEnable;
    bool feedbackEnable;
    float32_t rs;
    float32_t ld;
    float32_t ke;
    float32_t welLdId;
    float32_t welLd;
    float32_t idmax;
    float32_t mechRpmToElecRadPerSec;
    tmcUtils_PiControl_s bPIController;
    float32_t feedForwardTerm;
    float32_t feedbackTerm;
    float32_t fluxWeakIdRef;
}tmcFlx_FluxWeakening_s;
</#if>

<#if ( MCPMSMFOC_ENABLE_MTPA == true ) >
typedef struct
{
    bool enable;
    bool initDone;

    tUTIL_2DPlot_s LdLqDiffPlot;

    float32_t psi;
    float32_t ldMinusLq;
    float32_t   mtpaIdRef;
}tmcFlx_MTPA_s;
</#if>

typedef struct
{
    bool enable;
    bool initDone;
<#if ( MCPMSMFOC_ENABLE_FW == true ) >
    tmcFlx_FluxWeakening_s bFluxWeakening;
</#if>

<#if ( MCPMSMFOC_ENABLE_MTPA == true ) >
    tmcFlx_MTPA_s bMTPA;
</#if>
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


<#if ( MCPMSMFOC_ENABLE_FW == true ) >

/*! 
 * @brief Initialize flux weakening module
 *
 * Initializes the flux weakening module.
 *
 * @param[in] pParameters Pointer to module parameters structure
 * @return None
 */
void  mcFlx_FluxWeakeningInit( tmcFlx_Parameters_s * const pParameters )
{
    /** Get the linked state variable */
    tmcFlx_FluxWeakening_s * pState;
    pState = &((tmcFlx_State_s *)pParameters->pStatePointer)->bFluxWeakening;

    /** Set parameters */
    mcFlxI_ParametersSet(pParameters);

    pState->rs = pParameters->pMotorParameters->RsInOhms ;
    pState->ld = pParameters->pMotorParameters->LdInHenry;

    float32_t zp = pParameters->pMotorParameters->PolePairs ;
    pState->mechRpmToElecRadPerSec = TWO_PI * zp / 60.0f;

    /** ToDO: Recheck the formula */
    float32_t ke = pParameters->pMotorParameters->KeInVrmsPerKrpm * ONE_BY_SQRT3/ 1000.0f;
    pState->ke = ke;

    /** ToDO: Revisit. Set the maximum field weakening current to 50 % of maximum motor current */
    pState->idmax = -0.5f * pParameters->pMotorParameters->IrmsMaxInAmps;


    /** Enable feed-forward term */
    pState->feedForwardEnable = true;

    /** ToDO: Compute Kp and Ki value from linear PMSM model */
    float32_t Kp = 0.0001f;
    float32_t Ki = 0.000001f;

    /** Set PI controller parameters */
    mcUtils_PiControlInit( Kp, Ki, pParameters->dt, &pState->bPIController );

    /** Set initialization flag as true */
    pState->initDone = true;

}

/*! 
 * @brief Reset flux weakening module
 *
 * Resets the flux weakening module.
 *
 * @param[in] pParameters Pointer to module parameters structure
 * @return None
 */
void mcFlx_FluxWeakeningReset( const tmcFlx_Parameters_s * const pParameters )
{
    /** Get the linked state variable */
    tmcFlx_FluxWeakening_s * pState;
    pState = &((tmcFlx_State_s *)pParameters->pStatePointer)->bFluxWeakening;

    /** Reset PI Controller */
    mcUtils_PiControlReset( 0.0f, &pState->bPIController );
}

/*! 
 * @brief Enable flux weakening module
 *
 * Enables the flux weakening module.
 *
 * @param[in] pParameters Pointer to module parameters structure
 * @return None
 */
void  mcFlx_FluxWeakeningEnable( tmcFlx_Parameters_s * const pParameters )
{
    /** Get the linked state variable */
    tmcFlx_FluxWeakening_s * pState;
    pState = &((tmcFlx_State_s *)pParameters->pStatePointer)->bFluxWeakening;

    if( ( NULL == pState ) || ( !pState->initDone ))
    {
         /** Initialize parameters */
        mcFlx_FluxWeakeningInit(pParameters);
    }
    else
    {
         /** For MISRA Compliance */
    }

    /** Set enable flag as true */
    pState->enable = true;
}

/*! 
 * @brief Disable flux weakening module
 *
 * Disables the flux weakening module.
 *
 * @param[in] pParameters Pointer to module parameters structure
 * @return None
 */
void  mcFlx_FluxWeakeningDisable( tmcFlx_Parameters_s * const pParameters )
{
    /** Get the linked state variable */
    tmcFlx_FluxWeakening_s * pState;
    pState = &((tmcFlx_State_s *)pParameters->pStatePointer)->bFluxWeakening;

    if( NULL != pState)
    {
        /** Reset state variables  */
        mcFlx_FluxWeakeningReset(pParameters);
    }
    else
    {
        /** For MISRA Compliance */
    }

    /** Set enable flag as true */
    pState->enable = false;

}


<#if MCPMSMFOC_POSITION_CALC_ALGORITHM == 'SENSORED_ENCODER'>
/*! 
 * @brief Flux weakening control
 *
 * Performs flux weakening control using other algorithms.
 *
 * @param[in] pParameters Pointer to module parameters structure
 * @param[in] pUDQ Pointer to DQ voltage vector
 * @param[in] uBus DC bus voltage
 * @param[in] wmechRPM Mechanical speed in RPM
 * @param[out] pIDQ Pointer to output DQ current vector
 * @param[out] pIdref Pointer to output reference ID current
 * @return None
 */
float32_t mcFlx_FluxWeakening(  tmcFlx_FluxWeakening_s * const pFieldWeakening,
                                               const tmcTypes_DQ_s * const pUDQ,
                                               const tmcTypes_DQ_s * const pIDQ,
                                               const float32_t wmechRPM,
                                               const float32_t uBus )
{
    float32_t uQref;
    float32_t umax = ONE_BY_SQRT3 * uBus;

    if( !pFieldWeakening->enable )    {
        return 0.0f;
    }

    if( pUDQ->d  <= umax )
    {
        uQref = UTIL_SquareRootFloat( UTIL_SquareFloat( umax ) - UTIL_SquareFloat( pUDQ->d ) );
    }
    else
    {
        uQref = 0.0f;
    }

    /** Compute feed-forward term */
    if( pFieldWeakening->feedForwardEnable )
    {
        float32_t eMag;

        /** Calculate back-EMF magnitude from mechanical speed of the motor */
        eMag = pFieldWeakening->ke * wmechRPM;

        pFieldWeakening->welLdId = uQref - UTIL_AbsoluteFloat( pIDQ->q  * pFieldWeakening->rs ) - eMag;
        pFieldWeakening->welLd = UTIL_AbsoluteFloat( wmechRPM ) * pFieldWeakening->mechRpmToElecRadPerSec * pFieldWeakening->ld;

        /** Compute the reference flux weakening current */
        pFieldWeakening->feedForwardTerm = UTIL_DivisionFloat( pFieldWeakening->welLdId, pFieldWeakening->welLd );

        /** Saturate d-axis current  */
        UTIL_SaturateFloat( &pFieldWeakening->feedForwardTerm, pFieldWeakening->idmax, 0.0f );
    }
    else
    {
        pFieldWeakening->feedForwardTerm = 0.0f;
    }

    /** Compute feed-forward term */
    if( pFieldWeakening->feedbackEnable )
    {
        float32_t error = uQref - pUDQ->q;

        /** Limit update for PI controller */
        mcUtils_PiLimitUpdate( pFieldWeakening->idmax, 0.0f, &pFieldWeakening->bPIController );

        /** Execute PI controller */
        mcUtils_PiControl( error, &pFieldWeakening->bPIController );
        pFieldWeakening->feedbackTerm = pFieldWeakening->bPIController.Yo;
    }
    else
    {
        pFieldWeakening->feedbackTerm = 0.0f;
    }

    /** Compute reference d-axis current */
    pFieldWeakening->fluxWeakIdRef = pFieldWeakening->feedForwardTerm + pFieldWeakening->feedbackTerm;


    return  pFieldWeakening->fluxWeakIdRef;
}
<#else>
/*! 
 * @brief Flux weakening control
 *
 * Performs flux weakening control using other algorithms.
 *
 * @param[in] pParameters Pointer to module parameters structure
 * @param[in] pUDQ Pointer to DQ voltage vector
 * @param[in] pEAlphaBeta Pointer to Alpha-Beta voltage vector
 * @param[in] uBus DC bus voltage
 * @param[in] wmechRPM Mechanical speed in RPM
 * @param[out] pIDQ Pointer to output DQ current vector
 * @param[out] pIdref Pointer to output reference ID current
 * @return None
 */
float32_t mcFlx_FluxWeakening(  tmcFlx_FluxWeakening_s * const pFieldWeakening,
                                               const tmcTypes_DQ_s * const pUDQ,
                                               const tmcTypes_DQ_s * const pIDQ,
                                               const tmcTypes_AlphaBeta_s * const pEAlphaBeta,
                                               const float32_t wmechRPM,
                                               const float32_t uBus )
{
    float32_t uQref;
    float32_t umax = ONE_BY_SQRT3 * uBus;

    if( !pFieldWeakening->enable )    {
        return 0.0f;
    }

    if( pUDQ->d  <= umax )
    {
        uQref = UTIL_SquareRootFloat( UTIL_SquareFloat( umax ) - UTIL_SquareFloat( pUDQ->d ) );
    }
    else
    {
        uQref = 0.0f;
    }

    /** Compute feed-forward term */
    if( pFieldWeakening->feedForwardEnable )
    {
        float32_t eMag;

        eMag = UTIL_MagnitudeFloat( pEAlphaBeta->alpha, pEAlphaBeta->beta );

        pFieldWeakening->welLdId = uQref - UTIL_AbsoluteFloat( pIDQ->q  * pFieldWeakening->rs ) - eMag;
        pFieldWeakening->welLd = UTIL_AbsoluteFloat( wmechRPM ) * pFieldWeakening->mechRpmToElecRadPerSec * pFieldWeakening->ld;

        /** Compute the reference flux weakening current */
        pFieldWeakening->feedForwardTerm = UTIL_DivisionFloat( pFieldWeakening->welLdId, pFieldWeakening->welLd );

        /** Saturate d-axis current  */
        UTIL_SaturateFloat( &pFieldWeakening->feedForwardTerm, pFieldWeakening->idmax, 0.0f );
    }
    else
    {
        pFieldWeakening->feedForwardTerm = 0.0f;
    }

    /** Compute feed-forward term */
    if( pFieldWeakening->feedbackEnable )
    {
        float32_t error = uQref - pUDQ->q;

        /** Limit update for PI controller */
        mcUtils_PiLimitUpdate( pFieldWeakening->idmax, 0.0f, &pFieldWeakening->bPIController );

        /** Execute PI controller */
        mcUtils_PiControl( error, &pFieldWeakening->bPIController );
        pFieldWeakening->feedbackTerm = pFieldWeakening->bPIController.Yo;
    }
    else
    {
        pFieldWeakening->feedbackTerm = 0.0f;
    }

    /** Compute reference d-axis current */
    pFieldWeakening->fluxWeakIdRef = pFieldWeakening->feedForwardTerm + pFieldWeakening->feedbackTerm;

    return  pFieldWeakening->fluxWeakIdRef;
}
</#if>

</#if>

<#if MCPMSMFOC_ENABLE_MTPA == true >


/*! 
 * @brief Initialize MTPA module
 *
 * Initializes the MTPA module.
 *
 * @param[in] pParameters Pointer to module parameters structure
 * @return None
 */
void  mcFlx_MTPAInit( tmcFlx_Parameters_s * const pParameters )
{
    /** Declare intermediate variables */
    float32_t temp;
    uint8_t  samplePoints;
    tmcFlx_MTPA_s * pState;

    /** Initialize plots */
    tUTIL_2DPoints_s LdLqDiffArray[] = LDMINUSLQ_VS_IS;

    /** Get the linked state variable */
    pState = &((tmcFlx_State_s *)pParameters->pStatePointer)->bMTPA;

    /** Initialize Ld plot */
    samplePoints = (uint8_t)(sizeof(LdLqDiffArray)/ sizeof(LdLqDiffArray[0u] ));
    UTIL_2DPlotInitialize(&pState->LdLqDiffPlot, samplePoints, LdLqDiffArray );

    /** Set parameters */
    mcFlxI_ParametersSet(pParameters);

    /** Calculate per phase KEMF */
    temp = ONE_BY_SQRT3 * pParameters->pMotorParameters->KeInVrmsPerKrpm;

    /** Calculate in radian/s */
    temp = temp * 60.0f / ( TWO_PI * 1000.0f );
    pState->psi = temp * pParameters->pMotorParameters->PolePairs;

    /** Set enable flag as true */
    pState->initDone = true;
}

/*! 
 * @brief Reset MTPA module
 *
 * Resets the MTPA module.
 *
 * @param[in] pParameters Pointer to module parameters structure
 * @return None
 */
void  mcFlx_MTPAReset( const tmcFlx_Parameters_s * const pParameters )
{

}

/*! 
 * @brief Enable MTPA module
 *
 * Enables the Maximum Torque per Ampere (MTPA) module.
 *
 * @param[in] pParameters Pointer to module parameters structure
 * @return None
 */
void  mcFlx_MTPAEnable( tmcFlx_Parameters_s * const pParameters )
{
    /** Get the linked state variable */
     tmcFlx_MTPA_s * pState;
     pState = &((tmcFlx_State_s *)pParameters->pStatePointer)->bMTPA;

     if( ( NULL == pState ) || ( !pState->initDone ))
     {
          /** Initialize parameters */
         mcFlx_MTPAInit(pParameters);
     }
     else
     {
          /** For MISRA Compliance */
     }

     /** Set enable flag as true */
     pState->enable = true;
}

/*! 
 * @brief Disable MTPA module
 *
 * Disables the MTPA module.
 *
 * @param[in] pParameters Pointer to module parameters structure
 * @return None
 */
void  mcFlx_MTPADisable( tmcFlx_Parameters_s * const pParameters )
{
     /** Get the linked state variable */
     tmcFlx_MTPA_s * pState;
     pState = &((tmcFlx_State_s *)pParameters->pStatePointer)->bMTPA;

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
     pState->enable = false;
}

/*! 
 * @brief MTPA control
 *
 * Performs Maximum Torque per Ampere (MTPA) control.
 *
 * @param[in] pParameters Pointer to module parameters structure
 * @param[in] pIdq Pointer to DQ current vector
 * @param[out] pIdref Pointer to output reference ID current
 * @return None
 */
float32_t  mcFlx_MTPA( tmcFlx_MTPA_s * const pMTPA,
                   const tmcTypes_DQ_s * const pIdq )
{
     /** Intermediate variables */
     float32_t Is;
     float32_t temp;
     float32_t LdLqDiff;

    if( !pMTPA->enable ) {
        return 0.0f;
    }

    /** Get the stator current magnitude */
    Is = UTIL_MagnitudeFloat( pIdq->d, pIdq->q );

    /** Get Ld value from characteristic curve  */
    LdLqDiff =UTIL_2DPlotRead( &pMTPA->LdLqDiffPlot, Is );

    /** Determine intermediate value of MTPA equation */
    temp = 0.5f * pMTPA->psi/ LdLqDiff;

    /** Calculate d-axis reference current for MTPA */
    pMTPA->mtpaIdRef = temp - UTIL_SquareRootFloat(( temp * temp ) + (  pIdq->q *  pIdq->q ));

     return pMTPA->mtpaIdRef;
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
    mcUtils_PiControlInit( pParameters->Kp, pParameters->Ki, pParameters->dt, &mcFlx_State_mds.bPIController );

<#if MCPMSMFOC_ENABLE_FW == true >
    /** Enable flux weakening by default */
    mcFlx_FluxWeakeningEnable( pParameters );
</#if>

<#if MCPMSMFOC_ENABLE_MTPA == true >
    /** Enable MTPA by default */
    mcFlx_MTPAEnable( pParameters );
</#if>

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
void mcFlxI_FluxControlManual(  const tmcFlx_Parameters_s * const pParameters,
                                                         const float32_t  Out )
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
        mcUtils_PiControlReset( 0.0f, &pState->bPIController );
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
void mcFlxI_FluxControlAuto(  const tmcFlx_Parameters_s * const pParameters,
                                              const float32_t iDref, const float32_t iDact, const float32_t iDmax, float32_t * const pOut )
{
    /** Get the linked state variable */
    tmcFlx_State_s * pState;
    pState = (tmcFlx_State_s *)pParameters->pStatePointer;


    if( pState->enable )
    {
        /** Calculate the error */
        float32_t error = iDref - iDact;

        /** ToDO: Calculate Ymax and Ymin based on the motor control states. Remove the magic numbers  */
        /** Limit update for PI controller */
        mcUtils_PiLimitUpdate( -iDmax, iDmax, &pState->bPIController );

        /** Excecute PI controller */
        mcUtils_PiControl( error, &pState->bPIController );

        *pOut = pState->bPIController.Yo;
    }
    else
    {
        /** Reset PI Controller */
        mcUtils_PiControlReset( 0.0f, &pState->bPIController );
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
    mcUtils_PiControlReset( 0.0f, &pState->bPIController );

<#if MCPMSMFOC_ENABLE_MTPA == true >
    /** Reset max-torque per ampere ( MTPA ) */
    mcFlx_MTPAReset( pParameters );
</#if>

<#if MCPMSMFOC_ENABLE_FW == true >
    /** Reset Flux weakening */
    mcFlx_FluxWeakeningReset( pParameters );
</#if>
}

<#if ( MCPMSMFOC_ENABLE_MTPA == true ) || ( MCPMSMFOC_ENABLE_FW == true ) >
<#if MCPMSMFOC_POSITION_CALC_ALGORITHM != 'SENSORED_ENCODER'>
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
                                        const float32_t wmechRPM,
                                        const float32_t uBus,
                                        float32_t * const pIdref )
#else
void  mcFlxI_FluxReferenceGet(  const tmcFlx_Parameters_s * const pParameters,
                                        const tmcTypes_DQ_s * const pUDQ,
                                        tmcTypes_DQ_s * const pIDQ,
                                        tmcTypes_AlphaBeta_s * const pEAlphaBeta,
                                        const float32_t wmechRPM,
                                        const float32_t uBus,
                                        float32_t * const pIdref )
#endif
{
    /** Get the linked state variable */
    tmcFlx_State_s * pState;
    pState = (tmcFlx_State_s *)pParameters->pStatePointer;

<#if ( MCPMSMFOC_ENABLE_MTPA == true ) && ( MCPMSMFOC_ENABLE_FW == true ) >
  <#if MCPMSMFOC_POSITION_CALC_ALGORITHM != 'SENSORED_ENCODER'>
    float32_t idrefFW = mcFlx_FluxWeakening( &pState->bFluxWeakening, pUDQ, pIDQ, pEAlphaBeta, wmechRPM, uBus );
  <#else>
    float32_t idrefFW = mcFlx_FluxWeakening( &pState->bFluxWeakening, pUDQ, pIDQ, wmechRPM, uBus );
  </#if>
    float32_t idrefMTPA = mcFlx_MTPA(&pState->bMTPA, pIDQ );

    if( idrefFW < idrefMTPA ) {
        *pIdref = idrefFW;
    }
    else {
        *pIdref = idrefMTPA;
    }
<#elseif MCPMSMFOC_ENABLE_MTPA == true >
    *pIdref = mcFlx_MTPA(&pState->bMTPA, pIDQ );
<#else>
    *pIdref = mcFlx_FluxWeakening( &pState->bFluxWeakening, pUDQ, pIDQ, pEAlphaBeta, wmechRPM, uBus );
</#if>
}
<#else>
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
                                        const float32_t wmechRPM,
                                        const float32_t uBus,
                                        float32_t * const pIdref )
#else
void  mcFlxI_FluxReferenceGet(  const tmcFlx_Parameters_s * const pParameters,
                                        const tmcTypes_DQ_s * const pUDQ,
                                        tmcTypes_DQ_s * const pIDQ,
                                        const float32_t wmechRPM,
                                        const float32_t uBus,
                                        float32_t * const pIdref )
#endif
{
    /** Get the linked state variable */
    tmcFlx_State_s * pState;
    pState = (tmcFlx_State_s *)pParameters->pStatePointer;

<#if ( MCPMSMFOC_ENABLE_MTPA == true ) && ( MCPMSMFOC_ENABLE_FW == true ) >
  <#if MCPMSMFOC_POSITION_CALC_ALGORITHM != 'SENSORED_ENCODER'>
    float32_t idrefFW = mcFlx_FluxWeakening( &pState->bFluxWeakening, pUDQ, pIDQ, pEAlphaBeta, wmechRPM, uBus );
  <#else>
    float32_t idrefFW = mcFlx_FluxWeakening( &pState->bFluxWeakening, pUDQ, pIDQ, wmechRPM, uBus );
  </#if>
    float32_t idrefMTPA = mcFlx_MTPA(&pState->bMTPA, pIDQ );

    if( idrefFW < idrefMTPA ) {
        *pIdref = idrefFW;
    }
    else {
        *pIdref = idrefMTPA;
    }
<#elseif MCPMSMFOC_ENABLE_MTPA == true >
    *pIdref = mcFlx_MTPA(&pState->bMTPA, pIDQ );
<#else>
    *pIdref = mcFlx_FluxWeakening( &pState->bFluxWeakening, pUDQ, pIDQ, wmechRPM, uBus );
</#if>
}
</#if>
</#if>