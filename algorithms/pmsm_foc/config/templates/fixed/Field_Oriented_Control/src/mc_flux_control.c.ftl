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
#define ONE_BY_SQRT3_FLOAT (float32_t)(0.577350269) /*!< Value of 1/sqrt(3) as a float */
#define TWO_PI_FLOAT (float32_t)(6.28318530f)     /*!< Value of 2*pi as a float */

/*******************************************************************************
 * Private data types
*******************************************************************************/
/**
 * @brief Structure defining MTPA module state
 */
typedef struct
{
    bool enable;         /*!< Flag indicating if MTPA module is enabled */
    bool initDone;       /*!< Flag indicating if MTPA module initialization is done */
    int16_t psi;         /*!< Psi parameter */
    int32_t K1;          /*!< K1 parameter */
    int32_t K2;          /*!< K2 parameter */
    int16_t idref;       /*!< Reference id current */
} tmcFlx_MTPA_s;

/**
 * @brief Structure defining flux control state
 */
typedef struct
{
    bool enable;                    /*!< Flag indicating if flux control is enabled */
    bool initDone;                  /*!< Flag indicating if flux control initialization is done */
    tmcFlx_MTPA_s bMTPA;            /*!< MTPA module state structure */
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
    float32_t Kp = pParameters->Kp;// * BASE_SPEED_IN_RPM / BASE_CURRENT_IN_AMPS;
    float32_t Ki  = pParameters->Ki;// * BASE_SPEED_IN_RPM / BASE_CURRENT_IN_AMPS;
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
}

<#if MCPMSMFOC_ENABLE_FW == true >
/*! 
 * @brief Enable flux weakening module
 *
 * Enables the flux weakening module.
 *
 * @param[in] pParameters Pointer to module parameters structure
 * @return None
 */
void  mcFlxI_FluxWeakeningEnable( tmcFlx_Parameters_s * const pParameters )
{

}

/*! 
 * @brief Disable flux weakening module
 *
 * Disables the flux weakening module.
 *
 * @param[in] pParameters Pointer to module parameters structure
 * @return None
 */
void  mcFlxI_FluxWeakeningDisable( tmcFlx_Parameters_s * const pParameters )
{

}

/*! 
 * @brief Initialize flux weakening module
 *
 * Initializes the flux weakening module.
 *
 * @param[in] pParameters Pointer to module parameters structure
 * @return None
 */
void  mcFlxI_FluxWeakeningInit( tmcFlx_Parameters_s * const pParameters )
{

}

<#if MCPMSMFOC_POSITION_CALC_ALGORITHM == 'SENSORED_ENCODER'>
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

/*! 
 * @brief Reset flux weakening module
 *
 * Resets the flux weakening module.
 *
 * @param[in] pParameters Pointer to module parameters structure
 * @return None
 */
void mcFlxI_FluxWeakeningReset( const tmcFlx_Parameters_s * const pParameters )
{

}

</#if>

<#if MCPMSMFOC_ENABLE_MTPA == true >
/*! 
 * @brief Enable MTPA module
 *
 * Enables the Maximum Torque per Ampere (MTPA) module.
 *
 * @param[in] pParameters Pointer to module parameters structure
 * @return None
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

/*! 
 * @brief Disable MTPA module
 *
 * Disables the MTPA module.
 *
 * @param[in] pParameters Pointer to module parameters structure
 * @return None
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

/*! 
 * @brief Initialize MTPA module
 *
 * Initializes the MTPA module.
 *
 * @param[in] pParameters Pointer to module parameters structure
 * @return None
 */
void  mcFlxI_MTPAInit( tmcFlx_Parameters_s * const pParameters )
{
    float32_t f32a;
    tmcFlx_MTPA_s * pState;

    /** Get the linked state variable */
    pState = &((tmcFlx_State_s *)pParameters->pStatePointer)->bMTPA;

     /** Calculate per-phase KEMF in Vpeak per Krpm */
    f32a = ONE_BY_SQRT3_FLOAT * pParameters->pMotorParameters->KeInVrmsPerKrpm;

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

/*! 
 * @brief Reset MTPA module
 *
 * Resets the MTPA module.
 *
 * @param[in] pParameters Pointer to module parameters structure
 * @return None
 */
void  mcFlxI_MTPAReset( tmcFlx_Parameters_s * const pParameters )
{

}

</#if>

