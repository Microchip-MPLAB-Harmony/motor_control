/*******************************************************************************
  System Definitions

  File Name:
    mc_app.h

  Summary:
    Header file which shares global variables and function prototypes.

  Description:
    This file contains the global variables and function prototypes for a motor control project.

 *******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2019 Microchip Technology Inc. and its subsidiaries.
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

#ifndef MC_APP_H
#define MC_APP_H

#include "userparams.h"
#include "q14_generic_mcLib.h"


/*******************************************************************************
Public typedefs
*******************************************************************************/


typedef enum
{
    NO_START_CMD,
    ALARM_STOP,
    CUR_PI_NO_START_CMD,
    CUR_PI_END,
    POS_LOST_STOP,
    PHASE_U_LOSS,
    PHASE_V_LOSS,
    PHASE_W_LOSS,            
    OC_FAULT_STOP
} stop_source_t;

extern uint16_t     acc_ramp;
extern uint16_t     dec_ramp;

extern int16_t      ext_speed_ref_rpm;

extern uint16_t     ref_abs; 

extern uint16_t   speed_ref_filter;

/*******************************************************************************
Public variables definition
*******************************************************************************/

extern stop_source_t
    motor_stop_source; 

extern uint8_t state_run;
extern uint8_t  direction;
extern uint16_t set_speed;
extern uint16_t speed_ref_pot;
extern uint8_t  switch_state;
extern uint8_t  state_halt; 

/*******************************************************************************
Private functions prototypes
*******************************************************************************/


/*******************************************************************************
Public functions prototypes
*******************************************************************************/


/******************************************************************************
Function:     motorcontrol_vars_init
Description:  motor control variable initialization
Input:        nothing (uses some global variables)
Output:       nothing (modifies some global variables)
Note:         to be called once before starting the control functions              
******************************************************************************/
void motorcontrol_vars_init(void);


/******************************************************************************
Function:     motorcontrol
Description:  motor control implementation
Input:        nothing (uses many global variables)
Output:       nothing (modifies many global variables, mainly the pwm timer compare values)
Note:         Finds the direction based on the Potentiometer reference value;
              Calculate the speed reference value from the Potentiometer ADC reading;
              Finds the direction change based on dynamic potentiometer adjustment;
              Compute the speed reference value in internal units;
              Accelerate or Decelerate the Ramp reference based on the Internal speed reference;
              then manages the V/Hz profile to find duty cycle to generate SVPWM for voltages 
              as follows:
                 Finds the angle to be incremented each time
                 Compute the instantaneous angle
                 Find the voltage magnitude required
                 Execute the Inverse part transform
                 Execute the Inverse Clarke transform
                 Execute the PWM modulation method for SVPWM generation
                 Update the duty cycle values to the TCC compare channels based on the direction
******************************************************************************/
#ifdef RAM_EXECUTE
void  __ramfunc__ motorcontrol(void);
#else
void motorcontrol(void);
#endif

extern void PWM_Output_Disable( void );
extern void PWM_Output_Enable( void);


#endif // MC_APP_H