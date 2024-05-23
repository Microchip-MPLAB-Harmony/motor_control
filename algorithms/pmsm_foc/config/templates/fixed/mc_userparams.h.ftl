/*******************************************************************************
  System Definitions

  File Name:
    userparams.h

  Summary:
    Header file which defines Motor Specific and Board Specific constants

  Description:
    This file contains the motor and board specific constants. It also defines
 * switches which allows algorithm to be run in debug modes like Open Loop Mode,
 * Torque mode, etc.

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

#ifndef USERPARAMS_H
#define USERPARAMS_H

#include "mc_types.h"

/*******************************************************************************
 * Per unit scaling
*******************************************************************************/
#define BASE_SPEED_IN_RPM                   (float32_t)(2804 )
#define BASE_CURRENT_IN_AMPS                (float32_t)(2048 * ${MCPMSMFOC_CURRENT_SCALING_FACTORT})

#define VOLTAGE_DIVIDER_RATIO               (float32_t)(${MCPMSMFOC_DC_BUS_RATIO})
#define BASE_VOLTAGE_IN_VOLTS               (float32_t)(3.30f/ VOLTAGE_DIVIDER_RATIO )
#define BASE_IMPEDENCE_IN_OHMS              (float32_t)( BASE_VOLTAGE_IN_VOLTS / BASE_CURRENT_IN_AMPS )


#define UNIT_VALUE (float32_t)( 16384 )
#define K_SPEED   (float32_t)( UNIT_VALUE / BASE_SPEED_IN_RPM )
#define K_CURRENT   (float32_t)( UNIT_VALUE / BASE_CURRENT_IN_AMPS )


/** ToDO: Reverify the formula.
 * theta_scaled = omega_rpm_scaled * 65535 * BASE_SPEED * Pz / ( 16384 * 60 * Fs )
 * Therefore, K_TIME = 65535 * BASE_SPEED * Pz / ( 16384 * 60 * Fs )
 * */
#define K_TIME  (float32_t)( BASE_SPEED_IN_RPM * 5.0f * 4.0f/ (60.0f * ${MCPMSMFOC_PWM_FREQUENCY} ))

#endif // USERPARAMS_H
