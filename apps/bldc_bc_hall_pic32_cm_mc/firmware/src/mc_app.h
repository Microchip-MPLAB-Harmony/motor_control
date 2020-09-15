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
    STOP_CMD,          
    OC_FAULT_STOP
} stop_source_t;


typedef struct
{
    uint16_t speed_ref_pot;
    uint16_t set_speed_target;
    uint16_t speed_reference_target;
    uint16_t speed_reference_rpm;
    uint32_t avgtimestorage;
    uint32_t avgcycletime;
    uint16_t actual_speed;
    uint16_t actual_speed_target;
    uint16_t avgctr;  
    uint16_t motor_current;    
    uint32_t speed_constant;
    uint8_t  speed_pi_enable;
}motor_bc_params_t;


typedef struct
{
    stop_source_t motor_stop_source;
    uint8_t  state_run; 
    uint8_t  switch_state;
    uint8_t  direction;
    uint8_t  direction_offset;
    uint8_t  var_time_10ms;
    uint8_t  var_cnt_10ms;
}motor_state_params_t;



typedef struct 
{
    uint8_t curpattern;
    uint8_t nextpattern;
    uint8_t patt_enable;
    uint8_t patt_value;
    uint16_t pattern_commutation;
    uint8_t curhall1;
    uint8_t curhall2;
    uint8_t curhall3;  
}motor_hall_params_t;


extern picontrol_type  speedpi;
/*******************************************************************************
Public variables definition
*******************************************************************************/

//extern stop_source_t motor_stop_source; 

extern uint8_t var_time_10ms;


/*******************************************************************************
Private functions prototypes
*******************************************************************************/


/*******************************************************************************
Public functions prototypes
*******************************************************************************/


/******************************************************************************
Function:     MCAPP_MotorControlVarsInit
Description:  motor control variable initialization
Input:        nothing (uses some global variables)
Output:       nothing (modifies some global variables)
Note:         to be called once before starting the control functions              
******************************************************************************/
void MCAPP_MotorControlVarsInit(void);



void Motor_Start(void);
void Motor_Stop(void);
void MCAPP_Start(void);

#endif // MC_APP_H