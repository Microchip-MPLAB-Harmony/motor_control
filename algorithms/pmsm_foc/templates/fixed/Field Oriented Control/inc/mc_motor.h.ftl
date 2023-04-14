/*******************************************************************************
   Motor data

  Company:
    Microchip Technology Inc.

  File Name:
    mc_motor.h

  Summary:
  Motor data

  Description:
  Motor data

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

#ifndef MCMOTOR_H
#define MCMOTOR_H

/*******************************************************************************
 Header File inclusions 
 *******************************************************************************/
#include <stddef.h>
#include <stdint.h>
#include "mc_userparams.h"
#include "mc_Types.h"

/*******************************************************************************
 Parameters 
 *******************************************************************************/

/*******************************************************************************
 Default module parameters 
 *******************************************************************************/
/**
 *  Constant Pi
 */
#ifdef CONSTANT_Pi
#undef CONSTANT_Pi
#endif
#define CONSTANT_Pi (float32_t)( 3.14159265f )

/**
 *  Winding Connection Type
 */
#define WINDING_CONNECTION_TYPE  (STAR)

/**
  *  Check for motor isotropy
  */
#define NON_ISOTROPIC_MOTOR

/**
 * Rated electrical speed in RPM
 */
#define RATED_SPEED_IN_RPM  ((float32_t)(4000))

/**
 * Maximum electrical speed  with Field Weakening enabled in RPM
 */
#define MAXIMUM_SPEED_IN_RPM    ((float32_t)(4500))

/**
 * Minimum close loop electrical speed of the motor in RPM
 */
#define MINIMUM_SPEED_IN_RPM   ((float32_t)(500))

/**
 * Number of pole pairs
 */
#define NUM_POLE_PAIRS  ((float32_t)4)

 /**
  *  Stator resistance in Ohm
  */
#define MOTOR_PER_PHASE_RESISTANCE_IN_OHM   ((float32_t)0.07)

 /**
  *  Direct axis inductance in Henry
  */
#define DIRECT_AXIS_INDUCTANCE_IN_HENRY  ((float32_t)0.13e-3)

/**
  *  Quadrature axis inductance in Henry
  */
#define QUADRATURE_AXIS_INDUCTANCE_IN_HENRY  ((float32_t)0.13)


 /**
  * Back EMF Constant in Vpeak/kRPM
  */
#define MOTOR_BEMF_CONST_VOLTS_PER_KRPM_MECH  ((float32_t)41.4)
#define MOTOR_BEMF_CONST_VOLTS_S_PER_RAD_MECH  ((float32_t)0.0414)

 /**
  * Air gap flux in Weber
  */
#define  AIR_GAP_FLUX    (float32_t)( MOTOR_BEMF_CONST_VOLTS_S_PER_RAD_MECH )

 /**
  * Maximum peak current of the motor in amperes
  */
#define MAXIMUM_MOTOR_CURRENT_IN_AMPERE   ((float32_t)8.5)


/*******************************************************************************
 Module data type
 *******************************************************************************/
typedef struct
{
    float32_t PolePairs;
    float32_t RsInOhms;
    float32_t LdInHenry;
    float32_t LqInHenry;
    float32_t PsiInWeber;
    float32_t IrmsMaxInAmps;
    float32_t JmInKgPerCmSquare;
    float32_t NmaxInRpm;
    float32_t NratedInRpm;
}tmcMotor_PmsmParameters_s;

/*******************************************************************************
 Interface variables
 *******************************************************************************/
extern tmcMotor_PmsmParameters_s mcMotor_MotorParameters_gds;

/*******************************************************************************
 Static Functions
 *******************************************************************************/
/*! \brief Set PMSM motor parameters
 *
 * Details.
 * Set PMSM motor parameters
 *
 * @param[in]: Configuration parameters
 * @param[in/out]: None
 * @param[out]: PMSM motor parameters structure
 *                           - RsInOhms:    Per phase resistance in Ohms
 *                           - LdInHenry: Direct axis inductance in Henry
 *                           - LqInHenry: Quadrature axis inductance in Henry
 *                           - PolePairs: Number of pole pairs
 *                           - KeInRmsVoltSecPerRad: Back EMF constant in RMS volts-sec / rad
 *                           - NratedInRadPerSec: Rated speed in rad/sec
 *                           - NmaxInRadPerSec: Maximum speed in rad/sec
 *                           - JmInKgPerCmSquare: Motor inertia in Kg/cm^2
 * @return: None
 */
static inline void mcMotorI_ParametersSet(tmcMotor_PmsmParameters_s * const pParameters )
{
    pParameters->RsInOhms = MOTOR_PER_PHASE_RESISTANCE_IN_OHM;
    pParameters->LdInHenry = DIRECT_AXIS_INDUCTANCE_IN_HENRY;
    pParameters->LqInHenry = QUADRATURE_AXIS_INDUCTANCE_IN_HENRY;
    pParameters->PolePairs = NUM_POLE_PAIRS;
    pParameters->PsiInWeber = AIR_GAP_FLUX;
    pParameters->IrmsMaxInAmps = MAXIMUM_MOTOR_CURRENT_IN_AMPERE;
    pParameters->NratedInRpm = RATED_SPEED_IN_RPM;
    pParameters->NmaxInRpm = MAXIMUM_SPEED_IN_RPM;
    pParameters->JmInKgPerCmSquare = 0.2f;
}

/*******************************************************************************
 Interface Functions 
 *******************************************************************************/

/*! \brief Motor parameters initialization
 *
 * Details.
 * Motor parameters initialization
 *
 * @param[in]:
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcMotorI_MotorParametersInit( tmcMotor_PmsmParameters_s * const pParameters );

#endif    /* MCMOTOR_H */
