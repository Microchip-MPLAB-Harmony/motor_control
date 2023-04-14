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

/*******************************************************************************
Constants
*******************************************************************************/
#define  UTIL_RpmToElecRadPerSec(zp, RPM )  ( TWO_PI * (zp) * (RPM) / 60.0f)
#define TYPE_II_PLL
#define  ZERO_LIMIT   (float32_t)1.0e-2

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
#ifdef TYPE_II_PLL
    float32_t  KpSpeed;
    float32_t  KiSpeed;
    float32_t  YiSpeed;
    float32_t  KiAngle;
    float32_t  speed;
    float32_t  angle;
#else
    bool   rawSpeed;
    float32_t  phiEps;
    float32_t  YiTorque;
    float32_t  YiSpeed;
    float32_t  YiAngle;
    float32_t  iGain;
    float32_t  vGain;
    float32_t  KiTorque;
    float32_t  KpTorque;
    float32_t  KiSpeed;
    float32_t  KpSpeed;
    float32_t  KiAngle;
    float32_t  KpAngle;
    float32_t  angle;
    float32_t  speed;
#endif
} tmcRpe_PhaseDetector_s;

typedef struct
{
   bool enable;
   bool initDone;

   float32_t dt;
   float32_t RsInOhms;
   float32_t LsInHenry;
   float32_t PolePairs;
   float32_t oneMinusExpRsLsByTs;
   float32_t boundaryI;
   float32_t m;
   float32_t lambda;
   float32_t mdbi;
   float32_t minRPM;

   float32_t aIObs;
   float32_t b1IObs;
   float32_t b2IObs;
   float32_t b3IObs;
   float32_t a1BEMFobs;
   float32_t a2BEMFobs;
   float32_t b1BEMFobs;
   float32_t b2BEMFobs;

   float32_t iAlphaHat;
   float32_t iBetaHat;
   float32_t eAlphaHat;
   float32_t eBetaHat;
   float32_t zAlpha;
   float32_t zBeta;

   /** Angle tracking loop */
   float32_t edError;
   tmcRpe_PhaseDetector_s  phaseDetector;
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
/**
 * Low pass filter: y = y + a* ( x - y )
 */
#define LPF(x,y ,a)  (y) = (y) + (a) * ( (x) - (y))

/*******************************************************************************
Private Functions
*******************************************************************************/

__STATIC_INLINE void UTILS_LimitAngle0To2Pi( float32_t * const angle )
{
    if(*angle >= TWO_PI )
    {
        *angle -= TWO_PI;
    }
    else if( 0.0f > *angle )
    {
        *angle += TWO_PI;
    }
    else
    {
       /** For MISRA compliance*/
    }
}

/*! \brief Tustin approximation
 *
 * Details.
 * Tustin approximation
 *
 * @param[in]:
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
__STATIC_INLINE void mcRpe_TustinApply( float32_t * const Kp, float32_t * const Ki, const float32_t dt )
{
   *Ki = *Ki * dt;
   *Kp = *Kp + 0.5f * ( *Ki );
}


/*! \brief Tracking loop initialization
 *
 * Details.
 * Tracking loop initialization
 *
 * @param[in]:
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
__STATIC_INLINE void mcRpe_AngleTrackingLoopInit( tmcRpe_Parameters_s * const pParameter, tmcRpe_PhaseDetector_s * pState)
{
#if defined TYPE_II_PLL
    float32_t rho = TWO_PI * 10.0f;
    float32_t zeta = 0.7f;
    float32_t keps = 0.35f;
    float32_t zp = pParameter->pMotorParameters->PolePairs;
    float32_t radPerSecToRpm = 30.0f / ( zp * ONE_PI );

    pState->KpSpeed = zeta * radPerSecToRpm * rho/keps;
    pState->KiSpeed = radPerSecToRpm * rho * rho/(2.0f * keps);
    float32_t dt = pParameter->dt;
    mcRpe_TustinApply( &pState->KpSpeed, &pState->KiSpeed, dt );

    /** Use a factor of 4 since the frequency of PLL is four times slower than PWM frequency */
    pState->KiAngle = dt / radPerSecToRpm;

#else
    /** Calculate PLL estimator parameters */
    float32_t rho, zp, jp;
    zp = pParameter->pMotorParameters->PolePairs;
    jp = pParameter->pMotorParameters->JmInKgPerCmSquare;
    rho = TWO_PI * 10.0f;
    float32_t phi2speed    = 60.0f / ( zp * TWO_PI );
    float32_t torque2speed = 1.0f/jp;
    float32_t Keps = pParameter->Keps;

    pState->iGain =  0.5f/ Keps;
    pState->vGain =  3.0f * rho * phi2speed;

    /**
        *   Design rule for observer parameter:
        *          Kp = 3*Rho^2*Jp (integral-term of observer);
        *          Ki = Rho^3*Jp  * (double-integral-term of observer))
        */
    pState->KiTorque =  phi2speed * rho * rho * rho / torque2speed;
    pState->KpTorque = 3 * phi2speed * rho * rho / torque2speed;
    mcRpe_TustinApply( &pState->KpTorque, &pState->KiTorque, pParameter->dt  );

    pState->KiSpeed = torque2speed;
    pState->KpSpeed = 0.0f;
    mcRpe_TustinApply( &pState->KpSpeed, &pState->KiSpeed, pParameter->dt );

    pState->KiAngle = 1.0f/ phi2speed;
    pState->KpAngle = 0.0f;
    mcRpe_TustinApply( &pState->KpAngle, &pState->KiAngle, pParameter->dt );

    pState->rawSpeed = 0;

    /** Set state variables */
    pState->speed = 0;
    pState->YiTorque = 0;
    pState->YiSpeed = 0;
#endif
}

/*! \brief Tracking loop initialization
 *
 * Details.
 * Tracking loop initialization
 *
 * @param[in]:
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
__STATIC_INLINE void mcRpe_AngleTrackingLoop( const float32_t initialAngle, const float32_t error )
{
#ifdef TYPE_II_PLL
    float32_t yp;
    tmcRpe_PhaseDetector_s * pState;
    pState = &mcRpe_State_mds.phaseDetector;

    if( !pState->initDone )
    {
        pState->angle = initialAngle;

        /** Preset integrator values */
        pState->YiSpeed = 0.0f;

        pState->initDone = true;
    }

    /** PI Compensator stage */
    yp = ((float32_t)pState->KpSpeed * (float32_t)error );
    pState->speed = (float32_t)yp + (float32_t)(pState->YiSpeed);
    pState->YiSpeed += ((float32_t)pState->KiSpeed * error );

    /** Calculate angle  */
    pState->angle  = pState->angle + pState->speed * pState->KiAngle;
    UTILS_LimitAngle0To2Pi(&pState->angle);
#else
    float32_t y, yp;
    float32_t temp, tempSpeed;
    tmcRpe_PhaseDetector_s * pState;
    pState = &mcRpe_State_mds.phaseDetector;

    if( !pState->initDone )
    {
        pState->angle = initialAngle;

        /** Preset integrator values */
        pState->YiTorque = 0.0f;
        pState->YiSpeed = 0.0f;
        pState->YiAngle = initialAngle;

        /** Preset outputs */
        pState->speed = 0.0f;
        pState->initDone = true;

    }

    /** Current error to angle error */
    pState->phiEps = pState->iGain * iEps;

    /** PI Compensator stage */
    yp = ((float32_t)pState->KpTorque * (float32_t)pState->phiEps);
    y = (float32_t)yp + (float32_t)(pState->YiTorque);
    pState->YiTorque += ((float32_t)pState->KiTorque * (float32_t)pState->phiEps);

    /** Feed-forward term */
    tempSpeed = ((float32_t)pState->vGain * pState->phiEps);

    /** First stage integrator */
    yp = ((float32_t)pState->KpSpeed * (float32_t)y ) ;
    temp = (yp + (float32_t)(pState->YiSpeed));
    tempSpeed += temp;
    pState->YiSpeed += ((float32_t)pState->KiSpeed * (float32_t)y );

    /** Second stage integrator */
    yp   = ((float32_t)(pState->KpAngle ) * (float32_t)tempSpeed);
    pState->angle  = yp + (float32_t)(pState->YiAngle);
    UTILS_LimitAngle0To2Pi(&pState->angle);
    pState->YiAngle += ((float32_t)pState->KiAngle * (float32_t)tempSpeed);
    UTILS_LimitAngle0To2Pi(&pState->YiAngle);

    /** Calculate angular speed estimate */
    if (pState->rawSpeed)
    {
        pState->speed = (float32_t)(tempSpeed);
    }
    else
    {
        pState->speed = (float32_t)(temp);
    }

#endif
}

/*! \brief Tracking loop reset
 *
 * Details.
 * Tracking loop reset
 *
 * @param[in]:
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
__STATIC_INLINE void mcRpe_AngleTrackingLoopReset( tmcRpe_PhaseDetector_s * pState )
{
#if defined TYPE_II_PLL
    pState->initDone = false;
    pState->YiSpeed = 0.0f;
    pState->angle = 0.0f;
    pState->speed = 0.0f;
#else
    pState->rawSpeed = 0;

    /** Set initial rotor position */
    pState->angle = 0.0f;
    pState->YiAngle = 0.0f;

    /** Set state variables */
    pState->speed = 0;
    pState->YiTorque = 0;
    pState->YiSpeed = 0;
#endif
}

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
    float temp;
    
    /** Link state variable structure to the module */
    pParameters->pStatePointer = (void *)&mcRpe_State_mds;
    tmcRpe_State_s * pState = &mcRpe_State_mds;

    /** Set parameters */
    mcRpeI_ParametersSet(pParameters);

    /** Set state parameters  */
    pState->RsInOhms = pParameters->pMotorParameters->RsInOhms;
    pState->LsInHenry = pParameters->pMotorParameters->LqInHenry;
    pState->PolePairs = pParameters->pMotorParameters->PolePairs;

    pState->dt = pParameters->dt;
    pState->oneMinusExpRsLsByTs = (float32_t)( expf( -( pState->RsInOhms * pState->dt ) /  pState->LsInHenry ));

    pState->boundaryI  = pParameters->boundaryI;
    pState->m  = pParameters->m;
    pState->lambda  = pParameters->lambda;

    pState->mdbi  =  (float32_t)(pState->m /pState->boundaryI);
    pState->minRPM = pParameters->minRPM;

    temp  =  pState->oneMinusExpRsLsByTs;
    pState->aIObs   =  temp;
    pState->b1IObs  =  (temp - 1.0f) /pState->RsInOhms;
    pState->b2IObs  = -pState->b1IObs;
    pState->b3IObs  = pState->LsInHenry * pState->b2IObs;

    /** Angle tracking loop */
    mcRpe_AngleTrackingLoopInit(pParameters, &pState->phaseDetector );

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


void mcRpeI_RotorPositionEstim(  const tmcRpe_Parameters_s * const pParameters,
                                                     const float32_t refSpeed,
                                                     const tmcTypes_AlphaBeta_s * pIAlphaBeta,
                                                     const tmcTypes_AlphaBeta_s * pUAlphaBeta,
                                                     tmcTypes_AlphaBeta_s * pEAlphaBeta,
                                                     float32_t * pAngle, float32_t * pSpeed )
{

     /** Temporary variables */
     float32_t wel;
     float32_t itilde;
     float32_t tmp1, tmp2;
     float32_t weTs, sine, cosine;

     /** Get the linked state variable */
     tmcRpe_State_s * pState;
     pState = (tmcRpe_State_s *)pParameters->pStatePointer;

     if( pState->enable )
     {
         float32_t zEalphaHat;

         itilde = pIAlphaBeta->alpha - pState->iAlphaHat;

         if(pState->boundaryI < itilde)       {
              /** Itilde is above boundary layer. */
              pState->zAlpha = pState->m;
         }
         else if(-pState->boundaryI > itilde)     {
              /** Itilde is below boundary layer. */
              pState->zAlpha = -pState->m;
         }
         else    {
              /** Itilde is inside boundary layer. */
              pState->zAlpha = itilde * pState->mdbi;
         }

         pState->iAlphaHat =  ( pUAlphaBeta->alpha * pState->b2IObs ) + ( pState->aIObs * pState->iAlphaHat)
                             + ( pState->b1IObs * pState->eAlphaHat ) + ( pState->b3IObs * pState->zAlpha);

         itilde = pIAlphaBeta->beta - pState->iBetaHat;

         if(pState->boundaryI < itilde)     {
             /** Itilde is above boundary layer. */
             pState->zBeta = pState->m;
         }
         else if(-pState->boundaryI > itilde )       {
             /** Itilde is below boundary layer. */
             pState->zBeta = -pState->m;
         }
         else      {
              /** Itilde is inside boundary layer. */
              pState->zBeta = itilde * pState->mdbi;
         }

         pState->iBetaHat =  ( pUAlphaBeta->beta *  pState->b2IObs ) +  ( pState->aIObs * pState->iBetaHat)
                            +  ( pState->b1IObs * pState->eBetaHat ) + ( pState->b3IObs * pState->zBeta);

         /** Determine speed dependent back EMF observer coefficients */
         wel = UTIL_RpmToElecRadPerSec( pState->PolePairs, refSpeed );

         /** ToDO: Workaround. Removing this code is crashing the algorithm. Investigate later */
         if(!(( ZERO_LIMIT < wel) || ( -ZERO_LIMIT > wel)))    {
             if( ZERO_LIMIT > wel )       {
                 wel = ZERO_LIMIT;
             }
             else      {
                 wel = -ZERO_LIMIT;
             }
         }

         weTs = wel * pState->dt;
         UTILS_LimitAngle0To2Pi(&weTs);

         mcUtils_SineCosineCalculation( weTs, &pState->a2BEMFobs, &pState->a1BEMFobs);

         tmp1 = 1.0f -  pState->a1BEMFobs;
         tmp2 = pState->lambda/ wel;
         pState->b1BEMFobs = ((tmp2 * pState->a2BEMFobs) + tmp1) * pState->LsInHenry;
         pState->b2BEMFobs = ( pState->a2BEMFobs - (tmp2 * tmp1)) * pState->LsInHenry;

         /** Latch last eAlphaHat for BEMF observation */
         zEalphaHat = pState->eAlphaHat;

         pState->eAlphaHat =  ( pState->a1BEMFobs *  pState->eAlphaHat) - ( pState->a2BEMFobs * pState->eBetaHat )
                                  + ( pState->b1BEMFobs * pState->zAlpha ) + ( pState->b2BEMFobs * pState->zBeta );


         pState->eBetaHat =  ( pState->a1BEMFobs *  pState->eBetaHat) + ( pState->a2BEMFobs * zEalphaHat )
                                + ( pState->b1BEMFobs * pState->zBeta ) - ( pState->b2BEMFobs * pState->zAlpha );


         /** Determine tracking error */
         mcUtils_SineCosineCalculation( pState->phaseDetector.angle, &sine, &cosine);

         if( wel < 0.0f )      {
             /** Tracking error */
             pState->edError = (  pState->eAlphaHat * cosine ) + ( pState->eBetaHat * sine );
         }
         else      {
              /** Tracking error */
              pState->edError = - ( pState->eAlphaHat * cosine ) - ( pState->eBetaHat * sine );
         }

         mcRpe_AngleTrackingLoop( 0.0f, pState->edError );

         /** Update output */
         *pSpeed = pState->phaseDetector.speed;
         *pAngle = pState->phaseDetector.angle;
     }
     else
     {
         /** Rotor position estimation */
         mcRpeI_RotorPositionEstimReset( pParameters );

         /** Update output */
         *pSpeed = 0.0f;
         *pAngle = 0.0f;
     }

     pEAlphaBeta->alpha = pState->eAlphaHat;
     pEAlphaBeta->beta = pState->eBetaHat;
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
void mcRpeI_RotorPositionEstimReset( const tmcRpe_Parameters_s * const pParameters )
{
    /** Get the linked state variable */
    tmcRpe_State_s * pState;
    pState = (tmcRpe_State_s *)pParameters->pStatePointer;

    /** Reset state variables  */
    pState->iAlphaHat = 0.0f;
    pState->iBetaHat = 0.0f;
    pState->eAlphaHat = 0.0f;
    pState->eBetaHat = 0.0f;
    pState->zAlpha = 0.0f;
    pState->zBeta = 0.0f;

    /** Reset phase detector */
    mcRpe_AngleTrackingLoopReset(&pState->phaseDetector);

}
