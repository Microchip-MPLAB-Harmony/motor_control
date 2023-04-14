/*******************************************************************************
 Rotor position estimation source file

  Company:
    - Microchip Technology Inc.

  File Name:
    - mc_torque_control.c

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
#include "mc_rotor_position_estimation2.h"

/*******************************************************************************
Local configuration options
*******************************************************************************/
#undef CROSS_COUPLING_ENABLED
#undef ENABLE_CLASSICAL_PLL

/*******************************************************************************
 Private data types
*******************************************************************************/
typedef struct
{
     bool enable;
     bool initDone;
     
     float32_t Kgain;
     float32_t C1;
     int16_t l11Val;
     uint16_t l11Shift;
     int16_t m11Val;
     uint16_t m11Shift;
     int16_t n11Val;
     uint16_t n11Shift;
     int16_t k11Val;
     uint16_t k11Shift;
#ifdef  CROSS_COUPLING_ENABLED
     int16_t hhhVal;
     uint16_t hhhShift;
     int16_t lllVal;
     uint16_t lllShift;
     int16_t xxxVal;
     uint16_t xxxShift;
     int16_t m21Val;
     uint16_t m21Shift;
     int16_t n21Val;
     uint16_t n21Shift;
     int16_t k21Val;
     uint16_t k21Shift;
#endif
     int16_t uAlpha;
     int16_t uBeta;
     int16_t zAlpha;
     int16_t zBeta;
     int16_t eAlpha;
     int16_t eBeta;

#if defined  ENABLE_CLASSICAL_PLL
     int16_t eD;
     int16_t eQ;
     int16_t oneByKeVal;
     uint16_t oneByKeShift;
     int16_t speedToAngleVal;
     uint16_t speedToAngleShift;
#elif defined  ENABLE_MODIFIED_PLL
     /** ToDO: */
#elif defined  ENABLE_SRF_PLL
     /** ToDO: */
#elif defined ENABLE_ARC_TANGENT
        /** ToDO: */
#endif

     int16_t speed;
     uint16_t phi;
     int16_t minSpeed;
     int16_t direction;
}tmcRpe_State_s;

/*******************************************************************************
Private variables
*******************************************************************************/
static tmcRpe_State_s mcRpe_State_mds;

/*******************************************************************************
Interface  variables
*******************************************************************************/

/*******************************************************************************
Macro Functions
*******************************************************************************/
#define RIGHT_SHIFT_S32     mcUtils_RightShiftS32
#define MULT_SHIFT_S16     mcUtils_MultAndRightShiftS16
#define GET_VALUE_SHIFT     mcUtils_FloatToValueShiftPair

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
void  mcRpeI_RotorPositionEstimInit( tmcRpe_Parameters_s * const pParameters )
{
    float32_t f32a;
    float32_t voltAmpsFactor;

    tmcMotor_PmsmParameters_s  * pMotorParameters;

    /** Link state data-structure */
    tmcRpe_State_s * pState;
    pParameters->pStatePointer = (void *)&mcRpe_State_mds;
    pState = (tmcRpe_State_s *)&mcRpe_State_mds;

    /** Read parameters */
    mcRpeI_ParametersSet( pParameters );

    /** Get motor parameters */
    pMotorParameters = pParameters->pMotorParameters;

    /** Internal useful conversion constants calculation */
    voltAmpsFactor = 1.0f / ( BASE_VOLTAGE_IN_VOLTS * BASE_CURRENT_IN_AMPS );

    /** Determine observer coefficients */
    pState->Kgain = OBS_H_GAIN * pMotorParameters->LdInHenry/ pParameters->dt;
    pState->C1 = pState->Kgain - pMotorParameters->RsInOhms;

    /** l11 calculation  */
    f32a = 1.0f - OBS_H_GAIN;
    GET_VALUE_SHIFT( f32a, &pState->l11Val, &pState->l11Shift );

    /** m11 calculation  */
    f32a = pState->C1 * voltAmpsFactor * OBS_H_GAIN;
    GET_VALUE_SHIFT( f32a, &pState->m11Val, &pState->m11Shift );

    /** n11 calculation  */
    f32a = OBS_H_GAIN;
    GET_VALUE_SHIFT( f32a,  &pState->n11Val, &pState->n11Shift );

    /** k11 calculation  */
    f32a = pState->Kgain * voltAmpsFactor;
    GET_VALUE_SHIFT( f32a, &pState->k11Val, &pState->k11Shift );

#ifdef  CROSS_COUPLING_ENABLED
    /** Intermediate coefficients for cross coupling parameters */
    /** hhh calculation */
    f32a = pState->C1 * voltAmpsFactor;
    GET_VALUE_SHIFT( f32a, &pState->hhhVal, &pState->hhhShift );

     /** lll calculation  */
     float32_t speedFactor = (BASE_VALUE_FL) / BASE_SPEED_IN_RPM;
     f32a = pMotorParameters->LdInHenry * voltAmpsFactor / speedFactor;
     GET_VALUE_SHIFT( f32a, &pState->lllVal, &pState->lllShift );

     /** xxx calculation  */
     f32a = pParameters->dt / speedFactor;
     GET_VALUE_SHIFT( f32a, &pState->xxxVal, &pState->xxxShift );

#endif


#if defined ENABLE_CLASSICAL_PLL
     /** ToDO: Remove hard coded numeric value */
     pState->oneByKeShift  = 0u;
     f32a = 1.73f * (BASE_VOLTAGE_IN_VOLTS/ BASE_SPEED_IN_RPM )/ pParameters->Ke;
     GET_VALUE_SHIFT( f32a, &pState->oneByKeVal, &pState->oneByKeShift);

     /** Speed to angle conversion factor calculation */
     f32a = (float32_t)K_TIME;

     pState->speedToAngleShift = 0u;
     GET_VALUE_SHIFT( f32a, &pState->speedToAngleVal, &pState->speedToAngleShift);
#endif

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
void  mcRpeI_RotorPositionEstimEnable( tmcRpe_Parameters_s * const pParameters )
{
    /** Get the linked state variable */
    tmcRpe_State_s * pState;
    pState = (tmcRpe_State_s *)pParameters->pStatePointer;

    if( ( NULL == pState ) || ( !pState->initDone ))
    {
         /** Initialize parameters */
        mcRpeI_RotorPositionEstimInit(pParameters);
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
void  mcRpeI_RotorPositionEstimDisable( tmcRpe_Parameters_s * const pParameters )
{
    /** Get the linked state variable */
    tmcRpe_State_s * pState;
    pState = (tmcRpe_State_s *)pParameters->pStatePointer;

    if( NULL != pState)
    {
        /** Reset state variables  */
        mcRpeI_RotorPositionEstimReset(pParameters);
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
#ifdef RAM_EXECUTE
void __ramfunc__  mcRpeI_RotorPositionEstim( tmcRpe_Parameters_s * const pParameters,
                                                                         tmcTypes_AlphaBeta_s * pIAlphaBeta,
                                                                         tmcTypes_AlphaBeta_s * pUAlphaBeta,
                                                                         uint16_t * pAngle, int16_t * pSpeed  )
#else
void mcRpeI_RotorPositionEstim(  tmcRpe_Parameters_s * const pParameters,
                                                     tmcTypes_AlphaBeta_s * pIAlphaBeta,
                                                     tmcTypes_AlphaBeta_s * pUAlphaBeta,
                                                     uint16_t * pAngle, int16_t * pSpeed )
#endif
{
     /** Get the linked state variable */
     tmcRpe_State_s * pState;
     pState = (tmcRpe_State_s *)pParameters->pStatePointer;

     if( pState->enable )
     {
        int32_t s32a;
        int32_t s32b;

#ifdef  CROSS_COUPLING_ENABLED
        int16_t spabs;

        /** Speed clamp */
        if( ( pState->minSpeed > (int16_t)pState->speed ) && ( -pState->minSpeed < (int16_t)pState->speed ))
        {
            spabs = pState->minSpeed;
        }
        else
        {
            spabs = pState->speed;
        }

        s32a = ((int32_t)(pState->xxxVal )) * ((int32_t)spabs );
        pState->n21Shift = pState->xxxShift;
        while( (32767 < s32a) || (OBS_MAXSHIFTS < pState->n21Shift ))
        {
            s32a >>= 1;
            pState->n21Shift--;
        }
        pState->n21Val= (int16_t)s32a;

        while((0 == ( pState->n21Val & 0x0001 )) && ( 0u < pState->n21Shift ))
        {
            pState->n21Val >>= 1;
            pState->n21Shift--;
        }

        s32a = ((int32_t)(pState->hhhVal)) * ((int32_t)(pState->n21Val));
        pState->m21Shift = pState->n21Shift + pState->hhhShift;
        while(((32767 < s32a) || (-32767 > s32a)) || (OBS_MAXSHIFTS < pState->m21Shift))
        {
            s32a >>= 1;
            pState->m21Shift--;
        }
        pState->m21Val= (int16_t)s32a;
        while((0 == ( pState->m21Val & 0x0001 )) && ( 0u < pState->m21Shift ))
        {
            pState->m21Val >>= 1;
            pState->m21Shift--;
        }

        s32a = ( (int32_t)(pState->lllVal )) * ((int32_t)spabs );
        pState->k21Shift = pState->lllShift;
        while((32767 < s32a) || (OBS_MAXSHIFTS < pState->k21Shift))
        {
            s32a >>= 1;
            pState->k21Shift--;
        }
        pState->k21Val= (int16_t)s32a;
        while((0 == (pState->k21Val& 0x0001)) && (0u < pState->k21Shift))
        {
            pState->k21Val>>= 1;
            pState->k21Shift--;
        }

        /* Coefficients sign management */
        if(0 > pState->direction )
        {
            pState->n21Val = -pState->n21Val;
            pState->m21Val = -pState->m21Val;
            pState->k21Val = -pState->k21Val;
        }

#endif
        s32a =   MULT_SHIFT_S16( pState->zAlpha, pState->l11Val, pState->l11Shift );
        s32a +=  MULT_SHIFT_S16( pIAlphaBeta->alpha, pState->m11Val, pState->m11Shift );
#ifdef  CROSS_COUPLING_ENABLED
        s32a -= MULT_SHIFT_S16( pIAlphaBeta->beta, pState->m21Val, pState->m21Shift );
#endif
        s32a +=  MULT_SHIFT_S16( pState->uAlpha, pState->n11Val, pState->n11Shift );

#ifdef  CROSS_COUPLING_ENABLED
        s32a -= MULT_SHIFT_S16( pState->uBeta, pState->n21Val, pState->n21Shift );
#endif
        s32b = MULT_SHIFT_S16( pState->zBeta, pState->l11Val, pState->l11Shift );

#ifdef  CROSS_COUPLING_ENABLED
        s32b += MULT_SHIFT_S16( pIAlphaBeta->alpha, pState->m21Val, pState->m21Shift );
#endif
        s32b += MULT_SHIFT_S16( pIAlphaBeta->beta, pState->m11Val, pState->m11Shift );
#ifdef  CROSS_COUPLING_ENABLED
        s32b += MULT_SHIFT_S16( pState->uAlpha, pState->n21Val, pState->n21Shift );
#endif
        s32b += MULT_SHIFT_S16( pState->uBeta, pState->n11Val, pState->n11Shift );


        pState->zAlpha = (int16_t)s32a;
        pState->zBeta = (int16_t)s32b;

        s32a -= MULT_SHIFT_S16(  pIAlphaBeta->alpha, pState->k11Val, pState->k11Shift );
#ifdef  CROSS_COUPLING_ENABLED
        s32a += MULT_SHIFT_S16( pIAlphaBeta->beta, pState->k21Val, pState->k21Shift );
#endif

#ifdef  CROSS_COUPLING_ENABLED
        s32b -= MULT_SHIFT_S16( pIAlphaBeta->alpha, pState->k21Val, pState->k21Shift );
#endif
        s32b -=  MULT_SHIFT_S16( pIAlphaBeta->beta, pState->k11Val, pState->k11Shift );

        pState->eAlpha = (int16_t)s32a;
        pState->eBeta = (int16_t)s32b;

        pState->uAlpha = pUAlphaBeta->alpha;
        pState->uBeta = pUAlphaBeta->beta;

#if defined ENABLE_CLASSICAL_PLL
        int16_t sine = 0;
        int16_t cosine = 0;
        int s16a = 0;

        /** Calculate sine and cosine values */
        mcUtils_SineCosineCalculation( pState->phi, &sine, &cosine );

        /** Calculate d-axis back EMF */
        pState->eD = (int16_t)RIGHT_SHIFT_S32( (int32_t)( ( pState->eAlpha * cosine )  + ( pState->eBeta * sine ) ), 14u );

        /** Calculate q-axis back EMF */
        pState->eQ = (int16_t)RIGHT_SHIFT_S32( (int32_t)( ( pState->eBeta * cosine )  - ( pState->eAlpha * sine) ), 14u );

        /** Calculate speed */
        if( 0 < pState->eQ )   {
                   s16a = pState->eQ - pState->eD;
        }else
        {
                   s16a = pState->eQ + pState->eD;
        }

        pState->speed = MULT_SHIFT_S16( s16a, pState->oneByKeVal, pState->oneByKeShift );

        /** Calculate angle from speed */
        pState->phi += (uint16_t)MULT_SHIFT_S16( pState->speed, pState->speedToAngleVal, pState->speedToAngleShift);

        /** Update output */
       *pSpeed = pState->speed;
       *pAngle = pState->phi;
#elif defined ENABLE_MODIFIED_PLL
        /** ToDO: */
#elif defined ENABLE_SRF_PLL
        int16_t sine = 0;
        int16_t cosine = 0;

        /** Calculate sine and cosine values */
        mcUtils_SineCosineCalculation( pState->phi, &sine, &cosine );

        /** Calculate d-axis back EMF */
        pState->eD = RIGHT_SHIFT( ( pState->eAlpha * cosine  + pState->eBeta * sine ), 14u );

        pState->eDError = RIGHT_SHIFT(  (pState->eDError - pState->eD ), 1u );

        pState->kpOut = MULT_SHIFT_S16( pState->eDError, pState->kpVal, pState->kpShift );
        pState->kiOut += MULT_SHIFT_S16( pState->eDError, pState->kiVal, pState->kiShift );

        pState->wel = pState->kpOut + pState->kiOut;
        pState->phi += (uint16_t)MULT_SHIFT( pState->speed, pState->SpeedToAngleVal, pState->SpeedToAngleShift);

        /** Filter the speed for outer loop */
        pState->welFilt = pState->wel;

#elif defined ENABLE_ARC_TANGENT
        /** ToDO: */
#endif
    }
    else
    {
        /** Rotor position estimation */
        mcRpeI_RotorPositionEstimReset( pParameters );
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
void mcRpeI_RotorPositionEstimReset( tmcRpe_Parameters_s * const pParameters )
{
    /** Get the linked state variable */
//    tmcRpe_State_s * pState;
//    pState = (tmcRpe_State_s *)pParameters->pStatePointer;

    /** Reset state variables  */

}
