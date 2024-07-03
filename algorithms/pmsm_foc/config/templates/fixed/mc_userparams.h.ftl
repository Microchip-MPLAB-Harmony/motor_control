/**
 * @file userparams.h
 *
 * @brief
 *    Header file defining Motor Specific and Board Specific constants
 *
 * @Company
 *    Microchip Technology Inc.
 *
 * @Summary
 *    This file contains constants and scaling factors specific to the motor and
 *    board configuration. It also includes switches for debug modes like Open Loop Mode
 *    and Torque mode.
 *
 * @Description
 *    This header file defines various constants and scaling factors used in motor
 *    control algorithms. It includes definitions for base speed, current, voltage
 *    divider ratio, and impedance. Constants like K_SPEED and K_CURRENT are defined
 *    for per unit scaling. Additionally, the file provides a calculation for K_TIME
 *    used in time scaling based on motor parameters and PWM frequency.
 */

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
/**
 * @defgroup per_unit_scaling Per Unit Scaling Constants
 * @{
 */
#define BASE_SPEED_IN_RPM                   (float32_t)(2804) /**< Base speed in RPM */
#define BASE_CURRENT_IN_AMPS                (float32_t)(2048 * ${MCPMSMFOC_CURRENT_SCALING_FACTORT}) /**< Base current in Amperes */

#define VOLTAGE_DIVIDER_RATIO               (float32_t)(${MCPMSMFOC_DC_BUS_RATIO}) /**< Voltage divider ratio */
#define BASE_VOLTAGE_IN_VOLTS               (float32_t)(3.30f / VOLTAGE_DIVIDER_RATIO) /**< Base voltage in Volts */
#define BASE_IMPEDENCE_IN_OHMS              (float32_t)(BASE_VOLTAGE_IN_VOLTS / BASE_CURRENT_IN_AMPS) /**< Base impedance in Ohms */

#define UNIT_VALUE                          (float32_t)(16384) /**< Unit value for scaling */
#define K_SPEED                             (float32_t)(UNIT_VALUE / BASE_SPEED_IN_RPM) /**< Scaling factor for speed */
#define K_CURRENT                           (float32_t)(UNIT_VALUE / BASE_CURRENT_IN_AMPS) /**< Scaling factor for current */

/** 
 * @brief Scaling factor for time based on motor parameters and PWM frequency
 *
 * K_TIME is calculated using the formula:
 * K_TIME = BASE_SPEED_IN_RPM * 5.0f * 4.0f / (60.0f * ${MCPMSMFOC_PWM_FREQUENCY})
 */
 
#define K_TIME                              (float32_t)(BASE_SPEED_IN_RPM * 5.0f * 4.0f / (60.0f * ${MCPMSMFOC_PWM_FREQUENCY}))

#endif // USERPARAMS_H
