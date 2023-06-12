/*******************************************************************************
 Rotor position estimation source file

  Company:
    - Microchip Technology Inc.

  File Name:
    - mc_rotor_position_estimation.c

  Summary:
    - Rotor position estimation source file

  Description:
    - This file implements functions for rotor position estimation

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
#include "mc_rotor_position_calculation.h"

<#if __PROCESSOR?matches(".*PIC32MK.*") != true>
/*******************************************************************************
Constants
*******************************************************************************/
#define QDEC_RESET_COUNT                 (uint32_t)( 65536u )
#define QDEC_UPPER_THRESHOLD         (uint16_t)( 49151u )
#define QDEC_LOWER_THRESHOLD        (uint16_t)( 16384u )

/*******************************************************************************
Local configuration options
*******************************************************************************/

/*******************************************************************************
 Private data types
*******************************************************************************/
typedef struct
{
   /** States */
   bool enable;
   bool initDone;

    uint16_t encPulsesPerElecRev;
    uint16_t velocityCountPrescaler;
    uint16_t encOverflow;
    uint16_t encUnderflow;
    uint16_t encUpperThreshold;
    uint16_t encLowerThreshold;
    float32_t encPulsesToElecVelocity;
    float32_t encPulsesToElecAngle;

    uint16_t synCounter;
    uint16_t encCount;
    uint16_t encCountForPositionLast;
    uint16_t encCountForPosition;
    uint16_t positionCompensation;
    int16_t encCountForVelocity;
    int16_t encCountForVelocityLast;

}tmcRpc_State_s;

/*******************************************************************************
Private variables
*******************************************************************************/
static tmcRpc_State_s mcRpc_State_mds;

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
/*! \brief Initialize rotor position estimation module
 *
 * Details.
 * Initialize rotor position estimation module
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
void  mcRpcI_RotorPositionCalcInit( tmcRpc_Parameters_s * const pParameters )
{
    /** Link state variable structure to the module */
    pParameters->pStatePointer = (void *)&mcRpc_State_mds;
    tmcRpc_State_s * pState = &mcRpc_State_mds;

    /** Set parameters */
    mcRpcI_ParametersSet(pParameters);

    /** Set state parameters  */
    pState->encPulsesPerElecRev =  pParameters->encPulsesPerElecRev;
    pState->velocityCountPrescaler = pParameters->velocityCountPrescaler;
    pState->encPulsesToElecAngle =  TWO_PI / (float32_t)pState->encPulsesPerElecRev;

    float32_t temp = (float32_t)pParameters->encPulsesPerElecRev * pParameters->pMotorParameters->PolePairs;
    pState->encPulsesToElecVelocity =  60.0f / ( temp * pParameters->dt * (float32_t)pParameters->velocityCountPrescaler );
    pState->encUpperThreshold = QDEC_UPPER_THRESHOLD;
    pState->encLowerThreshold = QDEC_LOWER_THRESHOLD ;
    pState->encOverflow = (uint16_t)( QDEC_RESET_COUNT % pParameters->encPulsesPerElecRev) ;
    pState->encUnderflow = pParameters->encPulsesPerElecRev - pState->encOverflow;

    /** Set initialization flag to true */
    pState->initDone = true;
}

/*! \brief Enable rotor position estimation module
 *
 * Details.
 * Enable rotor position estimation module
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
void  mcRpcI_RotorPositionCalcEnable( tmcRpc_Parameters_s * const pParameters )
{
    /** Get the linked state variable */
    tmcRpc_State_s * pState;
    pState = (tmcRpc_State_s *)pParameters->pStatePointer;

    if( ( NULL == pState ) || ( !pState->initDone ))
    {
         /** Initialize parameters */
        mcRpcI_RotorPositionCalcInit(pParameters);
    }
    else
    {
         /** For MISRA Compliance */
    }

    /** Set enable flag as true */
    pState->enable = true;
}

/*! \brief Disable rotor position estimation module
 *
 * Details.
 * Disable rotor position estimation module
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
void  mcRpcI_RotorPositionCalcDisable( tmcRpc_Parameters_s * const pParameters )
{
    /** Get the linked state variable */
    tmcRpc_State_s * pState;
    pState = (tmcRpc_State_s *)pParameters->pStatePointer;

    if( NULL != pState)
    {
        /** Reset state variables  */
        mcRpcI_RotorPositionCalcReset(pParameters);
    }
    else
    {
        /** For MISRA Compliance */
    }

    /** Set enable flag as true */
    pState->enable = false;
}

/*! \brief Rotor position estimation
 *
 * Details.
 * Rotor position estimation
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
void mcRpcI_RotorPositionCalc(  const tmcRpc_Parameters_s * const pParameters,
                                                  float32_t * const pAngle, float32_t * const pSpeed )
{
     /** Get the linked state variable */
     tmcRpc_State_s * pState;
     pState = (tmcRpc_State_s *)pParameters->pStatePointer;

     if( pState->enable )
     {

         tmcRpc_Input_s dInput = { 0u };

         pState->synCounter++;

         /** Read input ports */
         mcRpcI_PositionCounterRead( &dInput );

        /* Calculate position */
        pState->encCount = (uint16_t)dInput.encPulseCount;

        if(       ( pState->encCount > pState->encUpperThreshold )
                      && ( pState->encCountForPositionLast < pState->encLowerThreshold))
        {
            pState->positionCompensation += pState->encUnderflow;
        }
        else if(( pState->encCountForPositionLast > pState->encUpperThreshold)
                      && ( pState->encCount < pState->encLowerThreshold))
        {
            pState->positionCompensation += pState->encOverflow;
        }
        else
        {
               /* Do nothing */
        }

        pState->positionCompensation %=  pState->encPulsesPerElecRev;
        pState->encCountForPosition  =  ( pState->encCount + pState->positionCompensation) % pState->encPulsesPerElecRev;
        pState->encCountForPositionLast =  pState->encCount;

        /* Calculate velocity */
        if( pState->synCounter > pState->velocityCountPrescaler )
        {
            pState->synCounter = 0u;
            pState->encCountForVelocity = ( int16_t )pState->encCount -  ( int16_t )pState->encCountForVelocityLast;
            pState->encCountForVelocityLast = (int16_t)pState->encCount;
        }

        /* Write speed and position output */
        *pSpeed = (float32_t)pState->encCountForVelocity * pState->encPulsesToElecVelocity;
        *pAngle  = (float32_t)pState->encCountForPosition * pState->encPulsesToElecAngle;

        /* Limit rotor angle range to 0 to 2*M_PI for lookup table */
        mcUtils_TruncateAngle0To2Pi( pAngle );
     }
     else
     {
         /** Rotor position estimation */
         mcRpcI_RotorPositionCalcReset( pParameters );

         /** Update output */
         *pSpeed = 0.0f;
         *pAngle = 0.0f;
     }
}


/*! \brief Reset Rotor position estimation
 *
 * Details.
 * Reset Rotor position estimation
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return:
 */
void mcRpcI_RotorPositionCalcReset( const tmcRpc_Parameters_s * const pParameters )
{
    /** Get the linked state variable */
    tmcRpc_State_s * pState;
    pState = (tmcRpc_State_s *)pParameters->pStatePointer;

    /* Reset state variables */
    pState->synCounter = 0u;
    pState->encCount  = 0u;
    pState->encCountForPositionLast = 0u;
    pState->encCountForPosition = 0u;
    pState->positionCompensation = 0u;
    pState->encCountForVelocity = 0;
    pState->encCountForVelocityLast = 0;
}

<#else>
/*******************************************************************************
Constants
*******************************************************************************/

/*******************************************************************************
Local configuration options
*******************************************************************************/

/*******************************************************************************
 Private data types
*******************************************************************************/
typedef struct
{
   /** States */
   bool enable;
   bool initDone;

    uint16_t encPulsesPerElecRev;
    uint16_t velocityCountPrescaler;
    float32_t encPulsesToElecVelocity;
    float32_t encPulsesToElecAngle;

    uint16_t synCounter;
    uint16_t encPulsesForPosition;
    int16_t encPulsesForVelocity;

}tmcRpc_State_s;

/*******************************************************************************
Private variables
*******************************************************************************/
static tmcRpc_State_s mcRpc_State_mds;

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
/*! \brief Initialize rotor position estimation module
 *
 * Details.
 * Initialize rotor position estimation module
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
void  mcRpcI_RotorPositionCalcInit( tmcRpc_Parameters_s * const pParameters )
{
    /** Link state variable structure to the module */
    pParameters->pStatePointer = (void *)&mcRpc_State_mds;
    tmcRpc_State_s * pState = &mcRpc_State_mds;

    /** Set parameters */
    mcRpcI_ParametersSet(pParameters);

    /** Set state parameters  */
    pState->encPulsesPerElecRev =  pParameters->encPulsesPerElecRev;
    pState->velocityCountPrescaler = pParameters->velocityCountPrescaler;
    pState->encPulsesToElecAngle =  TWO_PI / (float32_t)pState->encPulsesPerElecRev;

    float32_t temp = (float32_t)pParameters->encPulsesPerElecRev * pParameters->pMotorParameters->PolePairs;
    pState->encPulsesToElecVelocity =  60.0f / ( temp * pParameters->dt * (float32_t)pParameters->velocityCountPrescaler );

    /** Set initialization flag to true */
    pState->initDone = true;
}

/*! \brief Enable rotor position estimation module
 *
 * Details.
 * Enable rotor position estimation module
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
void  mcRpcI_RotorPositionCalcEnable( tmcRpc_Parameters_s * const pParameters )
{
    /** Get the linked state variable */
    tmcRpc_State_s * pState;
    pState = (tmcRpc_State_s *)pParameters->pStatePointer;

    if( ( NULL == pState ) || ( !pState->initDone ))
    {
         /** Initialize parameters */
        mcRpcI_RotorPositionCalcInit(pParameters);
    }
    else
    {
         /** For MISRA Compliance */
    }

    /** Set enable flag as true */
    pState->enable = true;
}

/*! \brief Disable rotor position estimation module
 *
 * Details.
 * Disable rotor position estimation module
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
void  mcRpcI_RotorPositionCalcDisable( tmcRpc_Parameters_s * const pParameters )
{
    /** Get the linked state variable */
    tmcRpc_State_s * pState;
    pState = (tmcRpc_State_s *)pParameters->pStatePointer;

    if( NULL != pState)
    {
        /** Reset state variables  */
        mcRpcI_RotorPositionCalcReset(pParameters);
    }
    else
    {
        /** For MISRA Compliance */
    }

    /** Set enable flag as true */
    pState->enable = false;
}

/*! \brief Rotor position estimation
 *
 * Details.
 * Rotor position estimation
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
void mcRpcI_RotorPositionCalc(  const tmcRpc_Parameters_s * const pParameters,
                                                  float32_t * const pAngle, float32_t * const pSpeed )
{
     /** Get the linked state variable */
     tmcRpc_State_s * pState;
     pState = (tmcRpc_State_s *)pParameters->pStatePointer;

     if( pState->enable )
     {

         tmcRpc_Input_s dInput = { 0u };

         pState->synCounter++;

         /** Read input ports */
         mcRpcI_PositionCounterRead( &dInput );

        /* Get position pulse count */
        pState->encPulsesForPosition = (uint16_t)dInput.encPulseCount;

        /* Calculate velocity */
        if( pState->synCounter > pState->velocityCountPrescaler )
        {
            pState->synCounter = 0u;
            mcRpcI_SpeedCounterRead( &dInput );
            pState->encPulsesForVelocity = (int16_t)dInput.encVelocityCount;
        }

        /* Write speed and position output */
        *pSpeed = (float32_t)pState->encPulsesForVelocity * pState->encPulsesToElecVelocity;
        *pAngle  = (float32_t)pState->encPulsesForPosition * pState->encPulsesToElecAngle;

        /* Limit rotor angle range to 0 to 2*M_PI for lookup table */
        mcUtils_TruncateAngle0To2Pi( pAngle );
     }
     else
     {
         /** Rotor position estimation */
         mcRpcI_RotorPositionCalcReset( pParameters );

         /** Update output */
         *pSpeed = 0.0f;
         *pAngle = 0.0f;
     }
}


/*! \brief Reset Rotor position estimation
 *
 * Details.
 * Reset Rotor position estimation
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return:
 */
void mcRpcI_RotorPositionCalcReset( const tmcRpc_Parameters_s * const pParameters )
{
    /** Get the linked state variable */
    tmcRpc_State_s * pState;
    pState = (tmcRpc_State_s *)pParameters->pStatePointer;

    /* Reset state variables */
    pState->synCounter = 0u;
    pState->encPulsesForPosition  = 0u;
    pState->encPulsesForVelocity = 0;
}
</#if>
