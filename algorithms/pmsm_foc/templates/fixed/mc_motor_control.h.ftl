/*******************************************************************************
  System Definitions

  File Name:
    mc_motor_control.h

  Summary:
    Header file which contains variables and function prototypes for motor 
     control functions

  Description:
   Header file which contains variables and function prototypes for motor 
   control functions

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

#ifndef MCMOC_H
#define MCMOC_H

/*******************************************************************************
 Header Inclusions
*******************************************************************************/
#include <stdint.h>
#include <sys/attribs.h>
#include "mc_reduced_order_luenberger.h"
#include "mc_pwm.h"
#include "mc_start_up.h"
#include "mc_generic_library.h"
#include "mc_error_handler.h"
#include "mc_current_control.h"
#include "mc_speed_control.h"
#include "mc_userparams.h"
#include "mc_interface_handling.h"



/*******************************************************************************
 Macros
*******************************************************************************/
#define MOTOR_START_STOP_FROM_BUTTON

/*******************************************************************************
Type definition
*******************************************************************************/
typedef struct 
{
   tmcMoc_ControlStates_e       appState; 
   uint8_t            runState; 
   uint16_t           stabCounter; 
   uint16_t           holdCounter;
   int32_t            ampCurrent;
   uint16_t           alignCounter; 
   uint32_t           ampPhaseAngle;
   uint32_t           ampElecSpeed;  
}tmcMoc_StateSignal_s;

/*******************************************************************************
Interface Variables
*******************************************************************************/


/*******************************************************************************
Interface Functions
*******************************************************************************/

/*! \brief Initialize Application
 * 
 * Details.
 * Initialize Application
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */   

void mcMocI_MotorControlInit( void );


/*! \brief ADC Finish ISR
 * 
 * Details.
 * ADC Finish ISR
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */   
void mcMocI_MotorControlTasksRun( void );

/*! \brief Over-current Fault ISR
 * 
 * Details.
 * Over-current Fault ISR
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */   
void mcMoc_MotorFaultReaction(uintptr_t context);


/*! \brief Motor Stop function 
 * 
 * Details.
 * Motor stop function 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcMocI_MotorStop(void);

/*! \brief Motor Start function 
 * 
 * Details.
 * Motor start function 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcMocI_MotorStart(void);

#ifdef BIDIRECTION_CONTROL
/*! \brief Motor direction toggle function 
 * 
 * Details.
 * Motor direction toggle function 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcMocI_MotorDirectionToggle(void);

#endif


/*! \brief Motor control state machine 
 * 
 * Details.
 * Motor control state machine 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
#ifdef RAM_EXECUTE
void  __ramfunc__ mcMoc_MotorControl(void);
#else
void mcMoc_MotorControl(void);
#endif


/*! \brief Button Polling function 
 * 
 * Details.
 * Button polling function
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcMocI_MotorControlCommandGet( void );

#endif // _MCMOC_H
