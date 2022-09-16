/*******************************************************************************
 Motor Control application interface file 

  Company:
    Microchip Technology Inc.

  File Name:
    mc_motor_control.h

  Summary:
    Motor control algorithm interface

  Description:
    This file contains the data structures and function prototypes of motor control loop.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
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
// DOM-IGNORE-END

#ifndef MC_MOC_H    // Guards against multiple inclusion
#define MC_MOC_H


/*******************************************************************************
 Header files inclusions
 *******************************************************************************/

#include <stddef.h>
#include "mc_interface_handling.h"
#include "mc_generic_library.h"
#include "mc_current_calculation.h"
#include "mc_voltage_measurement.h"
#include "mc_pwm.h"
#include "mc_current_control.h"
#include "mc_start_up.h"
#include "mc_rotor_position.h"
#include "mc_speed_control.h"
#if ( ENABLE == ENABLE_FLYING_START )
#include "mc_flying_start.h"
#endif
#if ( ENABLE == ENABLE_FLUX_WEAKENING )
#include "mc_flux_control.h"
#endif

/*******************************************************************************
 User defined data-types
 *******************************************************************************/

/*******************************************************************************
 Interface variables
 *******************************************************************************/


/*******************************************************************************
 * Interface Functions
 *******************************************************************************/

/*! \brief Motor A control application initialization 
 * 
 * Details.
 *  Motor A Control application initialization 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
 void mcMocI_M1ControlApplicationInit( void );
 
 /*! \brief Motor B control application initialization 
 * 
 * Details.
 *  Motor B Control application initialization 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
 void mcMocI_M2ControlApplicationInit( void );
 
 
/*! \brief Motor control application calibration
 * 
 * Details.
 *  Motor Control application calibration 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcFcoI_M1PhaseCurrentSensorCalib( uint32_t status, uintptr_t context );

/*! \brief Motor start stop function 
 * 
 * Details.
 * Motor start stop function  
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcMocI_M1StartStop(void);

/*! \brief Motor start function 
 * 
 * Details.
 * Motor start function  
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcMocI_M1Start(void);

/*! \brief Motor stop function 
 * 
 * Details.
 * Motor stop function  
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcMocI_M1Stop(void);

/*! \brief Motor direction toggle 
 * 
 * Details.
 * Motor direction toggle
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcMocI_M1DirectionToggle(void);


/*! \brief Motor A control application ISR tasks
 * Details.
 *  Motor A Control application ISR tasks  
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcMocI_M1ControlTasksRun( void );

/*! \brief Motor B control application ISR tasks
 * 
 * Details.
 *  Motor B Control application ISR tasks  
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcMocI_M2ControlTasksRun( void );

/*! \brief Motor A control application reset
 * 
 * Details.
 *  Motor A Control application reset 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
 void mcMocI_M1ControlReset( void );
 
 /*! \brief Motor B control application reset
 * 
 * Details.
 *  Motor B Control application reset 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
 void mcMocI_M2ControlReset( void );
 
#endif //MC_MOC_H

/**
 End of File
*/
