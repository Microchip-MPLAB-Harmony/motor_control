/*******************************************************************************
  System Definitions

  File Name:
    mc_pmsm_foc.h

  Summary:
    Header file which contains variables and function for high level software interface
 
  Description:
    This file contains variables and function prototypes which are generally 
    used for high level software interface. It is implemented in Q2.14
    fixed Point Arithmetic.

 *******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2021 Microchip Technology Inc. and its subsidiaries.
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
//DOM-IGNORE-END

#ifndef MC_PMSM_FOC_H
#define MC_PMSM_FOC_H

#include <stdint.h>
#include <stdlib.h>
#include <sys/attribs.h>


/*******************************************************************************
 * User defined data structure 
*******************************************************************************/

typedef enum _tmcPmsm_ControllerId_e
{
    POSITION_PID,
    SPEED_PID,
    IQ_PID,
    ID_PID         
}tmcPmsm_ControllerId_e;

/*******************************************************************************
 * Interface Functions
*******************************************************************************/

/*! \brief Set motor speed 
 *  
 *  Details.
 *  Interface function to set the motor speed. 
 
 */

void PMSM_FOC_StartupParametersSet( float startCurrent, float rampTime, int16_t transSpeed );

void PMSM_FOC_PidParametersSet( tmcPmsm_ControllerId_e controllerId, float Kp, float ki, float Kd, float Kc, float outMax );

void PMSM_FOC_MaximumTorqueSet( float maxTorque );

float PMSM_FOC_MotorTorqueGet( void );

void PMSM_FOC_MotorRpmSet( const int16_t motorSpeed );

void PMSM_FOC_MotorControlInit( void );

void PMSM_FOC_MotorStart( void );

void PMSM_FOC_MotorStop( void );

int16_t PMSM_FOC_RotorSpeedGet( void );

float PMSM_FOC_RotorPositionGet( void );

void PMSM_FOC_1msCallbackRegister( void );

void PMSM_FOC_10msCallbackRegister( void );

void PMSM_FOC_100msCallbackRegister( void );

void PMSM_FOC_1000msCallbackRegister( void );


/*! \brief Motor Control functions initialization 
 *  
 *  Details.
 *  Initializes software components for PMSM motor control function 
 
 */
void PMSM_FOC_Initialize( void );

/*! \brief Main loop tasks 
 *  
 *  Details.
 *  Main Loop tasks  
 
 */
void PMSM_FOC_Tasks( void );

/******************************************************************************/


#endif // MC_PMSM_FOC_H
