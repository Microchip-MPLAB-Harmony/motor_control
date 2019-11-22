/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    MCAPP_CurrentMeasurement.c

  Summary:
    This file contains functions to initialize, calibrate and measure phase
    currents for motor control application

  Description:
    This file contains functions to initialize, calibrate and measure phase
    currents for motor control application
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
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
#include "userparams.h"
#if  ( defined ( USE_FILE_INLINING )  && defined  (  MCAPP_C  ) )  ||   ( !defined ( USE_FILE_INLINING )  )
#ifndef MCRPOS_C 
#define MCRPOS_C
#include "mc_rotorPosition.h"
#include "mc_voltageMeasurement.h"
#include "mc_picontrol.h"
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

/******************************************************************************/
/*                   Global Variables                                         */
/******************************************************************************/
tMCRPO_PARAMETERS_S               gMCRPOS_Parameters = { 0.0f } ;
tMCRPO_STATE_SIGNAL_S             gMCRPOS_StateSignals = { 0.0f };
tMCRPO_INPUT_SIGNAL_S             gMCRPOS_InputSignals =  {0.0f };
tMCRPO_OUTPUT_SIGNALS_S           gMCRPOS_OutputSignals = { 0.0f, 0.0f, 0.0f };
tMCRPOS_ROTOR_ALIGN_INPUT_S       gMCRPOS_RotorAlignInput = { { 0.0f, 1U } };
tMCRPOS_ROTOR_ALIGN_STATE_S       gMCRPOS_RotorAlignState = { FORCE_ALIGN,  {0U, 0U, 0U },0U,  0U };
tMCRPOS_ROTOR_ALIGN_OUTPUT_S      gMCRPOS_RotorAlignOutput = {0U,  0U };
tMCRPOS_ROTOR_ALIGN_PARAM_S       gMCRPOS_RotorAlignParam  = {
                                                                  Q_CURRENT_REF_OPENLOOP,
                                                                  LOCK_COUNT_FOR_LOCK_TIME
                                                             };

/******************************************************************************/
/*                          LOCAL FUNCTIONS                                   */
/******************************************************************************/

/******************************************************************************/
/* Function name: MCRPO_ReadInputSignals                                      */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description:                                                               */
/* IRead input signals                                                        */
/******************************************************************************/
void MCRPO_ReadInputSignals( void )
{
    /* Initialize input pointers  */
    gMCRPOS_InputSignals.ialpha =  gMCLIB_CurrentAlphaBeta.alphaAxis;
    gMCRPOS_InputSignals.ibeta  =  gMCLIB_CurrentAlphaBeta.betaAxis;
    gMCRPOS_InputSignals.Ualpha =  gMCLIB_VoltageAlphaBeta.alphaAxis;
    gMCRPOS_InputSignals.Ubeta  =  gMCLIB_VoltageAlphaBeta.betaAxis;
    gMCRPOS_InputSignals.Umax   =  gMCVOL_OutputSignals.Umax;
}

/******************************************************************************/
/* Function name: MCRPOS_InitializePLLEstimator                               */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description:                                                               */
/* Initilaize PLL Estimator                                                   */
/******************************************************************************/
void MCRPOS_InitializePLLEstimator( void )
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
    gMCRPOS_StateSignals.ialpha_1 = 0;
    gMCRPOS_StateSignals.ibeta_1 = 0;
    gMCRPOS_StateSignals.Ualpha_1 = 0;
    gMCRPOS_StateSignals.Ubeta_1 = 0;
    gMCRPOS_StateSignals.esdf = 0;
    gMCRPOS_StateSignals.esqf = 0;
    gMCRPOS_StateSignals.rho = 0; 
    
}

/******************************************************************************/
/* Function name: MCRPOS_PLLEstimator                                         */
/* Function parameters:   None                                                */
/* Function return: None                                                      */
/* Description:                                                               */
/* PLL Estimator                                                              */
/******************************************************************************/
void MCRPOS_PLLEstimator( void )
{
    float tempqVelEstim;
    tMCLIB_POSITION_S position;
  #if(FIELD_WEAKENING == true)
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

    gMCRPOS_StateSignals.esa	= 	( gMCRPOS_StateSignals.Ualpha_1 )
                                -   ( gMCRPOS_Parameters.rs  * gMCRPOS_InputSignals.ialpha )
                                -   ( gMCRPOS_Parameters.lsDt  * ( gMCRPOS_InputSignals.ialpha - gMCRPOS_StateSignals.ialpha_1 ) );

    /*  Stator voltage equations along beta axis :  Ebeta = Ubeta - Rs ibeta - Ls dibeta/dt      */
    gMCRPOS_StateSignals.esb		= 	( gMCRPOS_StateSignals.Ubeta_1 )
                                  -   ( gMCRPOS_Parameters.rs  * gMCRPOS_InputSignals.ibeta )
                                  -   ( gMCRPOS_Parameters.lsDt* ( gMCRPOS_InputSignals.ibeta - gMCRPOS_StateSignals.ibeta_1 ) );

  #if ( 1U == FIELD_WEAKENING )
    /* In field weakening BEMF amplitude is estimated to calculate Id_ref */
    bemfAmp = sqrtf((gMCRPOS_StateSignals.esa * gMCRPOS_StateSignals.esa) + (gMCRPOS_StateSignals.esb * gMCRPOS_StateSignals.esb));
         
    /* Filter first order for BEMF amplitude;        BEMFFilter = 1/TFilterd * Intergal{ (BEMF-BEMFFilter).dt } */
    gMCRPOS_StateSignals.bemfFilt = gMCRPOS_StateSignals.bemfFilt +
                                    ((bemfAmp - gMCRPOS_StateSignals.bemfFilt) * gMCRPOS_Parameters.kFilterEsdq) ;

    gMCRPOS_OutputSignals.Esfilt =  gMCRPOS_StateSignals.bemfFilt;

  #endif

    /* Calculate Sin(Angle) and Cos(Angle) */
    position.angle 	=	gMCRPOS_StateSignals.rho + gMCRPOS_StateSignals.rhoOffset;
         
    MCLIB_WrapAngle( &position.angle);

    /* Determine sin and cos values of the angle from the lookup table. */
    MCLIB_SinCosCalc(&position);

    /*    Esd =  Esa*cos(Angle) + Esb*sin(Angle) */
    gMCRPOS_StateSignals.esd		=	(( gMCRPOS_StateSignals.esa * position.cosAngle ))
                                                                       +	(( gMCRPOS_StateSignals.esb * position.sineAngle ));

    /*   Esq = -Esa*sin(Angle) + Esb*cos(Rho)  */ 
    gMCRPOS_StateSignals.esq		=	(( gMCRPOS_StateSignals.esb * position.cosAngle ))
                            -     (( gMCRPOS_StateSignals.esa * position.sineAngle ));

    /* Filter first order for Esd and Esq
    EsdFilter = 1/TFilterd * Intergal{ (Esd-EsdFilter).dt } */
    gMCRPOS_StateSignals.esdf		=gMCRPOS_StateSignals.esdf +
                  ( (gMCRPOS_StateSignals.esd - gMCRPOS_StateSignals.esdf) * gMCRPOS_Parameters.kFilterEsdq) ;

    gMCRPOS_StateSignals.esqf		= gMCRPOS_StateSignals.esqf +
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
            gMCRPOS_StateSignals.omegaMr	=	(( gMCRPOS_Parameters.invKFi * (gMCRPOS_StateSignals.esqf - gMCRPOS_StateSignals.esdf))) ;
        }
        else
        {
            gMCRPOS_StateSignals.omegaMr	=	(( gMCRPOS_Parameters.invKFi * (gMCRPOS_StateSignals.esqf + gMCRPOS_StateSignals.esdf))) ;
        }
    }

         
    /* the integral of the estimated speed(OmegaMr) is the estimated angle */
    gMCRPOS_StateSignals.rho	= 	gMCRPOS_StateSignals.rho + (gMCRPOS_StateSignals.omegaMr) * (gMCRPOS_Parameters.deltaT);

    MCLIB_WrapAngle( &gMCRPOS_StateSignals.rho);

    /* the estimated speed is a filter value of the above calculated OmegaMr. The filter implementation */
    /* is the same as for BEMF d-q components filtering */
    gMCRPOS_StateSignals.velEstim =   gMCRPOS_StateSignals.velEstim
                                  +	(  ( gMCRPOS_StateSignals.omegaMr - gMCRPOS_StateSignals.velEstim)
                                     * ( gMCRPOS_Parameters.velEstimFilterK ) );

    /* Update output signals */ 
    gMCRPOS_OutputSignals.Angle = gMCRPOS_StateSignals.rho;
    gMCRPOS_OutputSignals.Speed = gMCRPOS_StateSignals.velEstim;

    /* Update  state variables for next loop  */
    gMCRPOS_StateSignals.ialpha_1	=  gMCRPOS_InputSignals.ialpha;
    gMCRPOS_StateSignals.ibeta_1 	=  gMCRPOS_InputSignals.ibeta;
    gMCRPOS_StateSignals.Ualpha_1 =  gMCRPOS_InputSignals.Umax * gMCRPOS_InputSignals.Ualpha;
    gMCRPOS_StateSignals.Ubeta_1  =  gMCRPOS_InputSignals.Umax * gMCRPOS_InputSignals.Ubeta;
}

/******************************************************************************/
/* Function name: MCRPOS_ResetPLLEstimator                                    */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description:                                                               */
/* Reset PLL Estimator                                                        */
/******************************************************************************/
void MCRPOS_ResetPLLEstimator( void )
{
    /* Reset state variables */
    gMCRPOS_StateSignals.omegaMr = 0;
    gMCRPOS_StateSignals.bemfFilt = 0;
    gMCRPOS_StateSignals.velEstim = 0;
    gMCRPOS_StateSignals.ialpha_1 = 0;
    gMCRPOS_StateSignals.ibeta_1 = 0;
    gMCRPOS_StateSignals.Ualpha_1 = 0;
    gMCRPOS_StateSignals.Ubeta_1 = 0;
    gMCRPOS_StateSignals.esdf = 0;
    gMCRPOS_StateSignals.esqf = 0;
    gMCRPOS_StateSignals.rho = 0;
}   

/******************************************************************************/
/*                      INTERFACE FUNCTIONS                                   */
/******************************************************************************/                                                                                                                 

/******************************************************************************/
/* Function name: MCRPOS_initialization                                       */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description:                                                               */
/* initializes parameters and state variables for rotor position sensing      */
/******************************************************************************/
INLINE_FUNCTION  void MCRPOS_InitializeRotorPositionSensing( void )
{    
    /* Initialize PLL Estimator */
    MCRPOS_InitializePLLEstimator( );
  
}

/******************************************************************************/
/* Function name: MCAPP_FieldAlignment                                        */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description: Initial rotor position alignment                              */
/******************************************************************************/
INLINE_FUNCTION tMCRPOS_STATUS_E MCRPOS_InitialRotorPositonDetection(   const tMCRPOS_ROTOR_ALIGN_INPUT_S * const alignInput,
                                                                              tMCRPOS_ROTOR_ALIGN_OUTPUT_S * const alignOutput )
{
    tMCRPOS_STATUS_E status = RUNNING ;
    switch( gMCRPOS_RotorAlignState.rotorAlignState )
    {
        case FORCE_ALIGN:
        { 
            status = MCAPP_FieldAlignment( alignOutput );
            if( COMPLETE  ==  status )
            {
                /* PLL initialization */
                MCRPOS_InitializeRotorPositionSensing(  );
                MCCON_ResetPIParameters();
                MCRPOS_OffsetCalibration(gCtrlParam.rotationSign);            
                gMCRPOS_RotorAlignState.rotorAlignState = FORCE_ALIGN;
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
/* Function name: MCAPP_FieldAlignment                                        */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description: Initial rotor position alignment                              */
/******************************************************************************/
INLINE_FUNCTION tMCRPOS_STATUS_E MCAPP_FieldAlignment( tMCRPOS_ROTOR_ALIGN_OUTPUT_S * const alignOutput )
{
    tMCRPOS_STATUS_E status = RUNNING ;

  #if( 1U == FORCED_ALIGNMENT )
    if ( gMCRPOS_RotorAlignState.startup_lock_count < ( gMCRPOS_RotorAlignParam.lockTimeCount >> 1))
    {
      #if(1U == Q_AXIS_ALIGNMENT )
        alignOutput->idRef =  0.0f;
        alignOutput->iqRef +=  ( gMCRPOS_RotorAlignParam.lockCurrent/ (float) ( gMCRPOS_RotorAlignParam.lockTimeCount >> 1));
        alignOutput->angle = (3*M_PI_2);
        gMCRPOS_RotorAlignState.startup_lock_count++;
      #else 
        alignOutput->idRef =  gMCRPOS_RotorAlignParam.lockCurrent;
        alignOutput->iqRef =  0.0f;
        alignOutput->angle =  0.0f;
        gMCRPOS_RotorAlignState.startup_lock_count++;
      #endif
    }
    else if ( gMCRPOS_RotorAlignState.startup_lock_count < gMCRPOS_RotorAlignParam.lockTimeCount)
    {
      #if(1U == Q_AXIS_ALIGNMENT )
        alignOutput->idRef =  0.0f;
        alignOutput->iqRef =  gMCRPOS_RotorAlignParam.lockCurrent;
        alignOutput->angle = (3*M_PI_2);
        gMCRPOS_RotorAlignState.startup_lock_count++;
      #else 
        alignOutput->idRef =  gMCRPOS_RotorAlignParam.lockCurrent;
        alignOutput->iqRef =  0.0f;
        alignOutput->angle =  0.0f;
        gMCRPOS_RotorAlignState.startup_lock_count++;
      #endif
       
    }
    else
    {
        gMCRPOS_RotorAlignState.startup_lock_count = 0;
        status = COMPLETE;
    }
  #else
    assert(0, SELECT A ROTOR ALIGNMENT ALGORITHM );
  #endif

    return status;
}

/******************************************************************************/
/* Function name: MCRPOS_offsetCalibration                                    */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description:                                                               */
/* Determines rotor position offset calibration value                         */
/******************************************************************************/
INLINE_FUNCTION void MCRPOS_OffsetCalibration( const int16_t direction )
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
/* Function name: MCRPOS_PositionMeasurement                                  */
/* Function parameters: none                                                  */
/* Function return: None                                                      */
/* Description:                                                               */
/* Determines the rotor position                                              */
/******************************************************************************/
INLINE_FUNCTION void MCRPOS_PositionMeasurement( void )
{
    MCRPO_ReadInputSignals( );
    MCRPOS_PLLEstimator( );
}

/******************************************************************************/
/* Function name: MCRPOS_ResetPositionSensing                                 */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description:                                                               */
/* reset state variables for rotor position sensing                           */
/******************************************************************************/
INLINE_FUNCTION  void MCRPOS_ResetPositionSensing( void )
{
    MCRPOS_ResetPLLEstimator( );
}

#endif
#endif
