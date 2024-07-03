/**
 * @brief 
 *    Motor data
 *
 * @File Name 
 *    mc_motor.c
 *
 * @Company 
 *    Microchip Technology Inc.
 *
 * @Summary
 *    This file contains definitions for motor data and parameters.
 *
 * @Description
 *    This file provides the implementation of structures and functions necessary for 
 *    defining and managing motor parameters. It includes the initialization and setting
 *    of motor parameters such as resistance, inductance, pole pairs, back EMF constant, 
 *    maximum and rated speeds, and motor inertia.
 */
 
// DOM-IGNORE-BEGIN
/*******************************************************************************
 * Copyright (C) 2023 Microchip Technology Inc. and its subsidiaries.
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
#include <stdlib.h>
#include "mc_motor.h"

/*******************************************************************************
 * Constants
 *******************************************************************************/

/*******************************************************************************
 Private variables
 *******************************************************************************/

/*******************************************************************************
 Private variables
 *******************************************************************************/

/*******************************************************************************
 Interface variables
 *******************************************************************************/
tmcMot_PMSM_s mcMotI_PMSM_gds;


/*******************************************************************************
 Private Functions
 *******************************************************************************/

/*******************************************************************************
 Interface Functions
 *******************************************************************************/
/**
 * @brief Motor parameters initialization
 *
 * This function initializes the motor parameters.
 *
 * @param[in] pParameters Pointer to the PMSM motor parameters structure
 */
void mcMotI_MotorParametersInit( tmcMot_PMSM_s * const pParameters )
{

    /** Initialize intermediate parameters */
    mcMotI_ParametersSet( pParameters );

    /** Scale motor parameters based on the set base current, voltage and speed */
}

