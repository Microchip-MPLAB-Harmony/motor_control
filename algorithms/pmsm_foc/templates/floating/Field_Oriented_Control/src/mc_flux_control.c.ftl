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
    float32_t idref;
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
    float32_t idref;
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
    mcUtils_PiControlInit( pParameters->Kp, pParameters->Ki, pParameters->dt, &mcFlx_State_mds.bPIController );

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
void mcFlxI_FluxControlAuto(  const tmcFlx_Parameters_s * const pParameters,
                                              const float32_t iDref, const float32_t iDact, const float32_t yLimit, float32_t * const pOut )
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
        mcUtils_PiLimitUpdate( -yLimit, yLimit, &pState->bPIController );

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
    mcUtils_PiControlReset( 0.0f, &pState->bPIController );
}

<#if ( MCPMSMFOC_ENABLE_FW == true ) >

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
    /** Get the linked state variable */
    tmcFlx_FluxWeakening_s * pState;
    pState = &((tmcFlx_State_s *)pParameters->pStatePointer)->bFluxWeakening;

    if( ( NULL == pState ) || ( !pState->initDone ))
    {
         /** Initialize parameters */
        mcFlxI_FluxWeakeningInit(pParameters);
    }
    else
    {
         /** For MISRA Compliance */
    }

    /** Set enable flag as true */
    pState->enable = true;
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
    /** Get the linked state variable */
    tmcFlx_FluxWeakening_s * pState;
    pState = &((tmcFlx_State_s *)pParameters->pStatePointer)->bFluxWeakening;

    if( NULL != pState)
    {
        /** Reset state variables  */
        mcFlxI_FluxWeakeningReset(pParameters);
    }
    else
    {
        /** For MISRA Compliance */
    }

    /** Set enable flag as true */
    pState->enable = false;

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
    float32_t ke = pParameters->pMotorParameters->KeInVpeakPerKrpm * ONE_BY_SQRT3/ 1000.0f;
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
void mcFlxI_FluxWeakening(  const tmcFlx_Parameters_s * const pParameters,
                                               const tmcTypes_DQ_s * const pUDQ,
                                               const float32_t uBus,
                                               const float32_t wmechRPM,
                                               tmcTypes_DQ_s * const pIDQ,
                                               float32_t * const pIdref )
{
    /** Get the linked state variable */
    tmcFlx_FluxWeakening_s * pState;
    pState = &((tmcFlx_State_s *)pParameters->pStatePointer)->bFluxWeakening;

    float32_t uQref;
    float32_t umax = ONE_BY_SQRT3 * uBus;

    if( pUDQ->d  <= umax )
    {
        uQref = UTIL_SquareRootFloat( UTIL_SquareFloat( umax ) - UTIL_SquareFloat( pUDQ->d ) );
    }
    else
    {
        uQref = 0.0f;
    }

    /** Compute feed-forward term */
    if( pState->feedForwardEnable )
    {
        float32_t eMag;

        /** Calculate back-EMF magnitude from mechanical speed of the motor */
        eMag = pState->ke * wmechRPM;

        pState->welLdId = uQref - UTIL_AbsoluteFloat( pIDQ->q  * pState->rs ) - eMag;
        pState->welLd = UTIL_AbsoluteFloat( wmechRPM ) * pState->mechRpmToElecRadPerSec * pState->ld;

        /** Compute the reference flux weakening current */
        pState->feedForwardTerm = UTIL_DivisionFloat( pState->welLdId, pState->welLd );

        /** Saturate d-axis current  */
        UTIL_SaturateFloat( &pState->feedForwardTerm, pState->idmax, 0.0f );
    }
    else
    {
        pState->feedForwardTerm = 0.0f;
    }

    /** Compute feed-forward term */
    if( pState->feedbackEnable )
    {
        float32_t error = uQref - pUDQ->q;

        /** Limit update for PI controller */
        mcUtils_PiLimitUpdate( pState->idmax, 0.0f, &pState->bPIController );

        /** Execute PI controller */
        mcUtils_PiControl( error, &pState->bPIController );
        pState->feedbackTerm = pState->bPIController.Yo;
    }
    else
    {
        pState->feedbackTerm = 0.0f;
    }

    /** Compute reference d-axis current */
    *pIdref = pState->feedForwardTerm + pState->feedbackTerm;

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
void mcFlxI_FluxWeakening(  const tmcFlx_Parameters_s * const pParameters,
                                               const tmcTypes_DQ_s * const pUDQ,
                                               const tmcTypes_AlphaBeta_s * const pEAlphaBeta,
                                               const float32_t uBus,
                                               const float32_t wmechRPM,
                                               tmcTypes_DQ_s * const pIDQ,
                                               float32_t * const pIdref )
{
    /** Get the linked state variable */
    tmcFlx_FluxWeakening_s * pState;
    pState = &((tmcFlx_State_s *)pParameters->pStatePointer)->bFluxWeakening;

    float32_t uQref;
    float32_t umax = ONE_BY_SQRT3 * uBus;

    if( pUDQ->d  <= umax )
    {
        uQref = UTIL_SquareRootFloat( UTIL_SquareFloat( umax ) - UTIL_SquareFloat( pUDQ->d ) );
    }
    else
    {
        uQref = 0.0f;
    }

    /** Compute feed-forward term */
    if( pState->feedForwardEnable )
    {
        float32_t eMag;

        eMag = UTIL_MagnitudeFloat( pEAlphaBeta->alpha, pEAlphaBeta->beta );

        pState->welLdId = uQref - UTIL_AbsoluteFloat( pIDQ->q  * pState->rs ) - eMag;
        pState->welLd = UTIL_AbsoluteFloat( wmechRPM ) * pState->mechRpmToElecRadPerSec * pState->ld;

        /** Compute the reference flux weakening current */
        pState->feedForwardTerm = UTIL_DivisionFloat( pState->welLdId, pState->welLd );

        /** Saturate d-axis current  */
        UTIL_SaturateFloat( &pState->feedForwardTerm, pState->idmax, 0.0f );
    }
    else
    {
        pState->feedForwardTerm = 0.0f;
    }

    /** Compute feed-forward term */
    if( pState->feedbackEnable )
    {
        float32_t error = uQref - pUDQ->q;

        /** Limit update for PI controller */
        mcUtils_PiLimitUpdate( pState->idmax, 0.0f, &pState->bPIController );

        /** Execute PI controller */
        mcUtils_PiControl( error, &pState->bPIController );
        pState->feedbackTerm = pState->bPIController.Yo;
    }
    else
    {
        pState->feedbackTerm = 0.0f;
    }

    /** Compute reference d-axis current */
    *pIdref = pState->feedForwardTerm + pState->feedbackTerm;

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
    /** Get the linked state variable */
    tmcFlx_FluxWeakening_s * pState;
    pState = &((tmcFlx_State_s *)pParameters->pStatePointer)->bFluxWeakening;

    /** Reset PI Controller */
    mcUtils_PiControlReset( 0.0f, &pState->bPIController );
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
    temp = ONE_BY_SQRT3 * pParameters->pMotorParameters->KeInVpeakPerKrpm;

    /** Calculate in radian/s */
    temp = temp * 60.0f / ( TWO_PI * 1000.0f );
    pState->psi = temp * pParameters->pMotorParameters->PolePairs;

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
void  mcFlxI_MTPA( tmcFlx_Parameters_s * const pParameters,
                   const tmcTypes_DQ_s * const pIdq, float32_t * const pIdref )
{
     /** Intermediate variables */
     float32_t Is;
     float32_t temp;
     float32_t LdLqDiff;

     /** Get the linked state variable */
     tmcFlx_MTPA_s * pState;
     pState = &((tmcFlx_State_s *)pParameters->pStatePointer)->bMTPA;

     if( pState->enable )
     {
         /** Get the stator current magnitude */
         Is = UTIL_MagnitudeFloat( pIdq->d, pIdq->q );

         /** Get Ld value from characteristic curve  */
         LdLqDiff =UTIL_2DPlotRead( &pState->LdLqDiffPlot, Is );

         /** Determine intermediate value of MTPA equation */
         temp = 0.5f * pState->psi/ LdLqDiff;

         /** Calculate d-axis reference current for MTPA */
         *pIdref = temp - UTIL_SquareRootFloat(( temp * temp ) + (  pIdq->q *  pIdq->q ));
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
