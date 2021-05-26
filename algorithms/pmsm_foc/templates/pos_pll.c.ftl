/*******************************************************************************

  Rotor Position Source File

  Company:
    Microchip Technology Inc.

  File Name:
    mc_rotorposition.c

  Summary:
    This file contains functions to get the rotor position of a motor

  Description:
    This file contains functions to get the rotor position of a motor
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2020 Microchip Technology Inc. and its subsidiaries.
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

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include "definitions.h"                // SYS function prototypes
#include "device.h"
#include "mc_derivedparams.h"
#include "mc_rotorposition.h"
#include "mc_lib.h"
#include "mc_voltagemeasurement.h"
#include "mc_generic_lib.h"
#include "math.h"
#include "assert.h"

// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************

/******************************************************************************/
/* Local Function Prototype                                                   */
/******************************************************************************/

__STATIC_INLINE void MCRPOS_ReadInputSignals( void );
static void MCRPOS_ResetPLLEstimator( void );
static void MCRPOS_InitializePLLEstimator ( void );
__STATIC_INLINE void MCRPOS_PLLEstimator( void );

/******************************************************************************/
/*                   Global Variables                                         */
/******************************************************************************/
tMCRPOS_PARAMETERS_S               gMCRPOS_Parameters = { 0.0f } ;
tMCRPOS_STATE_SIGNAL_S             gMCRPOS_StateSignals = { 0.0f };
tMCRPOS_INPUT_SIGNAL_S             gMCRPOS_InputSignals =  {0.0f };
tMCRPOS_OUTPUT_SIGNALS_S           gMCRPOS_OutputSignals = { 0.0f, 0.0f, 0.0f };
tMCRPOS_ROTOR_ALIGN_STATE_S       gMCRPOS_RotorAlignState = { MCRPOS_FORCE_ALIGN, 0U,  0U };
tMCRPOS_ROTOR_ALIGN_OUTPUT_S      gMCRPOS_RotorAlignOutput = {0U,  0U };
tMCRPOS_ROTOR_ALIGN_PARAM_S       gMCRPOS_RotorAlignParam  = {
                                                                  Q_CURRENT_REF_OPENLOOP,
                                                                  LOCK_COUNT_FOR_LOCK_TIME
                                                             };

/******************************************************************************/
/*                          LOCAL FUNCTIONS                                   */
/******************************************************************************/
/******************************************************************************/
/* Function name: MCRPOS_ReadInputSignals                                     */
/* Function parameters:   None                                                */
/* Function return: None                                                      */
/* Description:                                                               */
/* Read input variables required for PLL estimator                            */
/******************************************************************************/
__STATIC_INLINE void MCRPOS_ReadInputSignals( void )
{
    /* Initialize input pointers  */
    gMCRPOS_InputSignals.ialpha =  gMCLIB_CurrentAlphaBeta.alphaAxis;
    gMCRPOS_InputSignals.ibeta  =  gMCLIB_CurrentAlphaBeta.betaAxis;
    gMCRPOS_InputSignals.ualpha =  gMCLIB_VoltageAlphaBeta.alphaAxis;
    gMCRPOS_InputSignals.ubeta  =  gMCLIB_VoltageAlphaBeta.betaAxis;
    gMCRPOS_InputSignals.umax   =  gMCVOL_OutputSignals.umax;
}

/******************************************************************************/
/* Function name: MCRPOS_InitializePLLEstimator                               */
/* Function parameters:   None                                                */
/* Function return: None                                                      */
/* Description:                                                               */
/* Initialize PLL Estimator variables                                         */
/******************************************************************************/
static void MCRPOS_InitializePLLEstimator( void )
{
    /*  Observer state and parameters initialization */
    gMCRPOS_Parameters.lsDt = (float)(MOTOR_PER_PHASE_INDUCTANCE / FAST_LOOP_TIME_SEC);
    gMCRPOS_Parameters.rs = MOTOR_PER_PHASE_RESISTANCE;
    gMCRPOS_Parameters.invKFi = (float)(1.0 / MOTOR_BEMF_CONST_V_PEAK_PHASE_RAD_PER_SEC_ELEC);
    gMCRPOS_Parameters.kFilterEsdq = KFILTER_ESDQ;
    gMCRPOS_Parameters.kFilterBEMFAmp = KFILTER_BEMF_AMPLITUDE;
    gMCRPOS_Parameters.velEstimFilterK = KFILTER_VELESTIM;
    gMCRPOS_Parameters.deltaT = FAST_LOOP_TIME_SEC;
    gMCRPOS_Parameters.decimateRotorSpeed = DECIMATE_RATED_SPEED;

    /* Reset state variables */
    gMCRPOS_StateSignals.omegaMr = 0;
    gMCRPOS_StateSignals.bemfFilt = 0;
    gMCRPOS_StateSignals.velEstim = 0;
    gMCRPOS_StateSignals.ialphaLast = 0;
    gMCRPOS_StateSignals.ibetaLast = 0;
    gMCRPOS_StateSignals.ualphaLast = 0;
    gMCRPOS_StateSignals.ubetaLast = 0;
    gMCRPOS_StateSignals.esdf = 0;
    gMCRPOS_StateSignals.esqf = 0;
    gMCRPOS_StateSignals.rho = 0;

}

/******************************************************************************/
/* Function name: MCRPOS_PLLEstimator                                         */
/* Function parameters:   None                                                */
/* Function return: None                                                      */
/* Description:                                                               */
/* PLL Estimator to get the position and speed                                */
/******************************************************************************/
__STATIC_INLINE void MCRPOS_PLLEstimator( void )
{
    float tempqVelEstim;
    tMCLIB_POSITION_S position;
  #if(FIELD_WEAKENING == ENABLED)
      float bemfAmp;
  #endif

    if( gMCRPOS_StateSignals.velEstim < 0 )
    {
        tempqVelEstim = gMCRPOS_StateSignals.velEstim * (-1);
    }
    else
    {
        tempqVelEstim = gMCRPOS_StateSignals.velEstim;
    }

    /* Stator voltage equations along alpha axis : Ealpha = Ualpha - Rs ialpha - Ls dialpha/dt    */

    gMCRPOS_StateSignals.esa    =     ( gMCRPOS_StateSignals.ualphaLast )
                                -   ( gMCRPOS_Parameters.rs  * gMCRPOS_InputSignals.ialpha )
                                -   ( gMCRPOS_Parameters.lsDt  * ( gMCRPOS_InputSignals.ialpha - gMCRPOS_StateSignals.ialphaLast ) );

    /*  Stator voltage equations along beta axis :  Ebeta = Ubeta - Rs ibeta - Ls dibeta/dt      */
    gMCRPOS_StateSignals.esb        =     ( gMCRPOS_StateSignals.ubetaLast )
                                  -   ( gMCRPOS_Parameters.rs  * gMCRPOS_InputSignals.ibeta )
                                  -   ( gMCRPOS_Parameters.lsDt* ( gMCRPOS_InputSignals.ibeta - gMCRPOS_StateSignals.ibetaLast ) );

  #if (ENABLED == FIELD_WEAKENING )
    /* In field weakening BEMF amplitude is estimated to calculate Id_ref */
    bemfAmp = sqrtf((gMCRPOS_StateSignals.esa * gMCRPOS_StateSignals.esa) + (gMCRPOS_StateSignals.esb * gMCRPOS_StateSignals.esb));

    /* Filter first order for BEMF amplitude;        BEMFFilter = 1/TFilterd * Intergal{ (BEMF-BEMFFilter).dt } */
    gMCRPOS_StateSignals.bemfFilt = gMCRPOS_StateSignals.bemfFilt +
                                    ((bemfAmp - gMCRPOS_StateSignals.bemfFilt) * gMCRPOS_Parameters.kFilterEsdq) ;

    gMCRPOS_OutputSignals.esfilt =  gMCRPOS_StateSignals.bemfFilt;

  #endif

    /* Calculate Sin(Angle) and Cos(Angle) */
    position.angle     =    gMCRPOS_StateSignals.rho + gMCRPOS_StateSignals.rhoOffset;

    MCLIB_WrapAngle( &position.angle);

    /* Determine sin and cos values of the angle from the lookup table. */
    MCLIB_SinCosCalc(position.angle, &position.sineAngle, &position.cosAngle);

    /*    Esd =  Esa*cos(Angle) + Esb*sin(Angle) */
    gMCRPOS_StateSignals.esd        =    (( gMCRPOS_StateSignals.esa * position.cosAngle ))
                                                                       +    (( gMCRPOS_StateSignals.esb * position.sineAngle ));

    /*   Esq = -Esa*sin(Angle) + Esb*cos(Rho)  */
    gMCRPOS_StateSignals.esq        =    (( gMCRPOS_StateSignals.esb * position.cosAngle ))
                            -     (( gMCRPOS_StateSignals.esa * position.sineAngle ));

    /* Filter first order for Esd and Esq
    EsdFilter = 1/TFilterd * Intergal{ (Esd-EsdFilter).dt } */
    gMCRPOS_StateSignals.esdf        =gMCRPOS_StateSignals.esdf +
                  ( (gMCRPOS_StateSignals.esd - gMCRPOS_StateSignals.esdf) * gMCRPOS_Parameters.kFilterEsdq) ;

    gMCRPOS_StateSignals.esqf        = gMCRPOS_StateSignals.esqf +
                  ( (gMCRPOS_StateSignals.esq - gMCRPOS_StateSignals.esqf) * gMCRPOS_Parameters.kFilterEsdq) ;

    /* OmegaMr= InvKfi * (Esqf -sgn(Esqf) * Esdf) */
    /* For stability the condition for low speed */
    if (tempqVelEstim > gMCRPOS_Parameters.decimateRotorSpeed )
    {
        /* Estimated speed is greater than 10% of rated speed */
        if( gMCRPOS_StateSignals.esqf > 0)
        {
            gMCRPOS_StateSignals.omegaMr = gMCRPOS_Parameters.invKFi * (gMCRPOS_StateSignals.esqf - gMCRPOS_StateSignals.esdf);
        }
        else
        {
            gMCRPOS_StateSignals.omegaMr = gMCRPOS_Parameters.invKFi * (gMCRPOS_StateSignals.esqf + gMCRPOS_StateSignals.esdf);
        }
    }
    else
    {
        /* Estimated speed is less than 10% of rated speed */
        if( gMCRPOS_StateSignals.velEstim > 0)
        {
            gMCRPOS_StateSignals.omegaMr    =    (( gMCRPOS_Parameters.invKFi * (gMCRPOS_StateSignals.esqf - gMCRPOS_StateSignals.esdf))) ;
        }
        else
        {
            gMCRPOS_StateSignals.omegaMr    =    (( gMCRPOS_Parameters.invKFi * (gMCRPOS_StateSignals.esqf + gMCRPOS_StateSignals.esdf))) ;
        }
    }


    /* the integral of the estimated speed(OmegaMr) is the estimated angle */
    gMCRPOS_StateSignals.rho    =     gMCRPOS_StateSignals.rho + (gMCRPOS_StateSignals.omegaMr) * (gMCRPOS_Parameters.deltaT);

    MCLIB_WrapAngle( &gMCRPOS_StateSignals.rho);

    /* the estimated speed is a filter value of the above calculated OmegaMr. The filter implementation */
    /* is the same as for BEMF d-q components filtering */
    gMCRPOS_StateSignals.velEstim =   gMCRPOS_StateSignals.velEstim
                                  +    (  ( gMCRPOS_StateSignals.omegaMr - gMCRPOS_StateSignals.velEstim)
                                     * ( gMCRPOS_Parameters.velEstimFilterK ) );

    /* Update output signals */
    gMCRPOS_OutputSignals.angle = gMCRPOS_StateSignals.rho;
    gMCRPOS_OutputSignals.speed = gMCRPOS_StateSignals.velEstim;
    gMCRPOS_OutputSignals.mechSpeedRPM = (float)(gMCRPOS_OutputSignals.speed * ELE_TO_MECH_RPM_SPEED);    

    /* Update  state variables for next loop  */
    gMCRPOS_StateSignals.ialphaLast    =  gMCRPOS_InputSignals.ialpha;
    gMCRPOS_StateSignals.ibetaLast     =  gMCRPOS_InputSignals.ibeta;
    gMCRPOS_StateSignals.ualphaLast =  gMCRPOS_InputSignals.umax * gMCRPOS_InputSignals.ualpha;
    gMCRPOS_StateSignals.ubetaLast  =  gMCRPOS_InputSignals.umax * gMCRPOS_InputSignals.ubeta;
}

/******************************************************************************/
/* Function name: MCRPOS_ResetPLLEstimator                                    */
/* Function parameters:   None                                                */
/* Function return: None                                                      */
/* Description:                                                               */
/* Reset PLL Estimator variables                                              */
/******************************************************************************/
static void MCRPOS_ResetPLLEstimator( void )
{
    /* Reset state variables */
    gMCRPOS_StateSignals.omegaMr = 0;
    gMCRPOS_StateSignals.bemfFilt = 0;
    gMCRPOS_StateSignals.velEstim = 0;
    gMCRPOS_StateSignals.ialphaLast = 0;
    gMCRPOS_StateSignals.ibetaLast = 0;
    gMCRPOS_StateSignals.ualphaLast = 0;
    gMCRPOS_StateSignals.ubetaLast = 0;
    gMCRPOS_StateSignals.esdf = 0;
    gMCRPOS_StateSignals.esqf = 0;
    gMCRPOS_StateSignals.rho = 0;
}

/******************************************************************************/
/*                      INTERFACE FUNCTIONS                                   */
/******************************************************************************/

/******************************************************************************/
/* Function name: MCRPOS_InitializeRotorPositionSensing                       */
/* Function parameters:   None                                                */
/* Function return: None                                                      */
/* Description:                                                               */
/* Initialize rotor position variables                                         */
/******************************************************************************/
void MCRPOS_InitializeRotorPositionSensing( void )
{
    /* Initialize PLL Estimator */
    MCRPOS_InitializePLLEstimator( );

}

/******************************************************************************/
/* Function name: MCRPOS_InitialRotorPositonDetection                         */
/* Function parameters:   None                                                */
/* Function return: None                                                      */
/* Description:                                                               */
/* Initial rotor position detection                                           */
/******************************************************************************/
tMCAPP_STATUS_E MCRPOS_InitialRotorPositonDetection(tMCRPOS_ROTOR_ALIGN_OUTPUT_S * const alignOutput )
{
    tMCAPP_STATUS_E status = MCAPP_IN_PROGRESS ;
    switch( gMCRPOS_RotorAlignState.rotorAlignState )
    {
        case MCRPOS_FORCE_ALIGN:
        {
            status = MCRPOS_FieldAlignment( alignOutput );
            if( MCAPP_SUCCESS  ==  status )
            {
                /* PLL initialization */
                MCRPOS_InitializeRotorPositionSensing(  );
                MCRPOS_OffsetCalibration(gMCCTRL_CtrlParam.rotationSign);
                gMCRPOS_RotorAlignState.rotorAlignState = MCRPOS_FORCE_ALIGN;
            }
        }
        break;
        default:
        {
            /* Should never come here */
        }
    }
    gMCRPOS_RotorAlignState.status = gMCRPOS_RotorAlignState.rotorAlignState;
    return status;
}


/******************************************************************************/
/* Function name: MCRPOS_FieldAlignment                               */
/* Function parameters:   None                                                */
/* Function return: None                                                      */
/* Description:                                                               */
/* Initial field alignment to known position                                  */
/******************************************************************************/
tMCAPP_STATUS_E MCRPOS_FieldAlignment( tMCRPOS_ROTOR_ALIGN_OUTPUT_S * const alignOutput )
{
    tMCAPP_STATUS_E status = MCAPP_IN_PROGRESS ;

  #if( ALIGNMENT_METHOD == Q_AXIS || ALIGNMENT_METHOD == D_AXIS)
    if ( gMCRPOS_RotorAlignState.startupLockCount < ( gMCRPOS_RotorAlignParam.lockTimeCount >> 1))
    {
      #if(ALIGNMENT_METHOD == Q_AXIS )
        alignOutput->idRef =  0.0f;
        alignOutput->iqRef +=  ( gMCRPOS_RotorAlignParam.lockCurrent/ (float) ( gMCRPOS_RotorAlignParam.lockTimeCount >> 1));
        alignOutput->angle = (3*M_PI_2);
        gMCRPOS_RotorAlignState.startupLockCount++;
      #else
        alignOutput->idRef =  gMCRPOS_RotorAlignParam.lockCurrent;
        alignOutput->iqRef =  0.0f;
        alignOutput->angle =  0.0f;
        gMCRPOS_RotorAlignState.startupLockCount++;
      #endif
    }
    else if ( gMCRPOS_RotorAlignState.startupLockCount < gMCRPOS_RotorAlignParam.lockTimeCount)
    {
      #if(ALIGNMENT_METHOD == Q_AXIS )
        alignOutput->idRef =  0.0f;
        alignOutput->iqRef =  gMCRPOS_RotorAlignParam.lockCurrent;
        alignOutput->angle = (3*M_PI_2);
        gMCRPOS_RotorAlignState.startupLockCount++;
      #else
        alignOutput->idRef =  gMCRPOS_RotorAlignParam.lockCurrent;
        alignOutput->iqRef =  0.0f;
        alignOutput->angle =  0.0f;
        gMCRPOS_RotorAlignState.startupLockCount++;
      #endif

    }
    else
    {
        gMCRPOS_RotorAlignState.startupLockCount = 0;
        status = MCAPP_SUCCESS;
    }
  #else
    assert(0, SELECT A ROTOR ALIGNMENT ALGORITHM );
  #endif

    return status;
}

/******************************************************************************/
/* Function name: MCRPOS_OffsetCalibration                               */
/* Function parameters:   None                                                */
/* Function return: None                                                      */
/* Description:                                                               */
/* Angle offset calibration while switching to closed loop                    */
/******************************************************************************/
void MCRPOS_OffsetCalibration( const int16_t direction )
{
    if( 1 == direction)
    {
        gMCRPOS_StateSignals.rhoOffset = ANGLE_OFFSET_DEG * ((float)M_PI/180);
    }
    else
    {
        gMCRPOS_StateSignals.rhoOffset = -ANGLE_OFFSET_DEG * ((float)M_PI/180);
    }
}

/******************************************************************************/
/* Function name: MCRPOS_PositionMeasurement                               */
/* Function parameters:   None                                                */
/* Function return: None                                                      */
/* Description:                                                               */
/* Get the position using PLL estimator                                         */
/******************************************************************************/
void MCRPOS_PositionMeasurement( void )
{
    MCRPOS_ReadInputSignals( );
    MCRPOS_PLLEstimator( );
}

/******************************************************************************/
/* Function name: MCRPOS_ResetPositionSensing                               */
/* Function parameters:   None                                                */
/* Function return: None                                                      */
/* Description:                                                               */
/* Reset PLL Estimator variables                                         */
/******************************************************************************/
void MCRPOS_ResetPositionSensing( tMCRPOS_ALIGN_STATE_E state )
{
    gMCRPOS_RotorAlignState.rotorAlignState = state;
    MCRPOS_ResetPLLEstimator( );
}
