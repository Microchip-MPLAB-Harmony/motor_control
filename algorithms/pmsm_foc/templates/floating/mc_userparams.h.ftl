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

/*******************************************************************************
 * Application Configuration
*******************************************************************************/
#define ENABLE                      1u
#define DISABLE                     0u

/* Alignment methods */
#define Q_AXIS                          (0u)
#define D_AXIS                          (1u)

/* Control Loop */
#define OPEN_LOOP                        (0u)
#define SPEED_LOOP                       (1u)
#define TORQUE_LOOP                      (2u)
#define POSITION_LOOP                    (3u)



/** 
 *  Defining DEVELOPER_MODE allows the programmer to monitor debug signals via X2C Scope 
 *  Note: X2C library has to be linked for the DEVELOPER_MODE to function                    
 */

#define DEVELOPER_MODE   ENABLE

#define CONTROL_LOOP                     (${MCPMSMFOC_CONTROL_TYPE})

/**
 *  Defining Q_AXIS_STARTUP causes the open loop startup by injecting current in Q axis  
 *  Un-defining Q_AXIS_STARTUP cause the open loop startup by injecting current in D axis       
 */
#define Q_AXIS_STARTUP    1u
#define ALIGNMENT_METHOD                 (${MCPMSMFOC_ALIGN_OR_DETECT_AXIS})  /* alignment method  */

<#if MCPMSMFOC_REF_INPUT == "Potentiometer Analog Input">
#define POTENTIOMETER_INPUT_ENABLED       ENABLE
<#else>
#define POTENTIOMETER_INPUT_ENABLED       DISABLE
</#if>

<#if MCPMSMFOC_CONTROL_TYPE == "Speed control">
#define SPEED_REF_RPM                     (float)${MCPMSMFOC_OPEN_LOOP_END_SPEED}   /* Speed Ref */
<#elseif MCPMSMFOC_CONTROL_TYPE == "Torque control">
#define Q_CURRENT_REF_TORQUE             0.20   /* Iq ref for torque mode */
#define Q_CURRENT_MIN_TORQUE             0.15   /* Min Iq current */
#define Q_CURRENT_MAX_TORQUE             0.25   /* Max Iq mapped to Potentiometer max */
</#if>

/**
 *  Defining BIDIRECTION_CONTROL enables bi-directional control of the motor                            
 */ 
<#if MCPMSMFOC_BOARD_SEL != "MCHV3"> 
#define BIDIRECTION_CONTROL  ENABLE
<#else>
#define BIDIRECTION_CONTROL  DISABLE
</#if>

/**
 *  Defining RAMP_PROFILE sets the ramp profile of speed in UI input mode                      
 */ 
#define STEP     0u
#define LINEAR   1u
#define RAMP_PROFILE   ${MCPMSMFOC_RAMP_PROFILES}

/**
 *  Field Weakening                     
 */ 
#define FIELD_WEAKENING (${MCPMSMFOC_ENABLE_FW?then('ENABLED','DISABLE')})

/* Field weakening - Limit for -ve Idref */
#if(FIELD_WEAKENING == ENABLE)
#define MAX_FW_NEGATIVE_ID_REF              (float)(${MCPMSMFOC_FW_MAX_NEGATIVE_ID})
#endif

/*******************************************************************************
 * System Configuration
*******************************************************************************/
/**
 *  PWM frequency in Hz                            
 */ 
#define PWM_FREQUENCY   (${MCPMSMFOC_PWM_FREQUENCY}u)

/**
 *  Current control Frequency                           
 */ 
#define CURRENT_CONTROL_FREQUENCY      ( 1.0f * PWM_FREQUENCY ) 

/**
 * Current control sampling time                            
 */ 
#define CURRENT_CONTROL_SAMPLING_TIME    (float)(1.0f/(float)CURRENT_CONTROL_FREQUENCY)

/*******************************************************************************
 * Motor Parameters 
*******************************************************************************/
/**
 *  Winding Connection Type 
 */
#define WINDING_CONNECTION_TYPE  (${MCPMSMFOC_MOTOR_CONNECTION})

/**
  *  Check for motor isotropy                  
  */
#define NON_ISOTROPIC_MOTOR

/**
 * Rated electrical speed in RPM
 */
#define RATED_SPEED_IN_RPM   ((int16_t)${MCPMSMFOC_RATED_SPEED})

/**
 * Maximum electrical speed  with Field Weakening enabled in RPM
 */
#define MAXIMUM_SPEED_IN_RPM    ((int16_t)${MCPMSMFOC_MAX_SPEED})

/**
 * Minimum close loop electrical speed of the motor in RPM
 */
#define MINIMUM_SPEED_IN_RPM   (${MCPMSMFOC_OPEN_LOOP_END_SPEED}) 

/**
 * Number of pole pairs  
 */
#define NUM_POLE_PAIRS  ((int16_t)${MCPMSMFOC_POLE_PAIRS})  

 /**
  *  Stator resistance in Ohm                      
  */
#define MOTOR_PER_PHASE_RESISTANCE_IN_OHM   ((float)${MCPMSMFOC_R})    

 /**
  *  Direct axis inductance in Henry                 
  */
#define DIRECT_AXIS_INDUCTANCE_IN_HENRY  ((float)${MCPMSMFOC_LD})     

/**
  *  Quadrature axis inductance in Henry                 
  */
#define QUADRATURE_AXIS_INDUCTANCE_IN_HENRY  ((float)${MCPMSMFOC_LQ}) 

 /** 
  * Back EMF Constant in Vpeak/kRPM                   
  */
#define MOTOR_BEMF_CONST_VOLTS_PER_KRPM_MECH  ((float)${MCPMSMFOC_BEMF_CONST})

 /** 
  * Air gap flux in Weber                   
  */
#define  AIR_GAP_FLUX    (float)(  60 * MOTOR_BEMF_CONST_VOLTS_PER_KRPM_MECH / ( 1.414 * 1000 * M_PI ))

 /** 
  * Maximum peak current of the motor in amperes                     
  */
#define MAXIMUM_MOTOR_CURRENT_IN_AMPERE   ((float)${MCPMSMFOC_MAX_MOTOR_CURRENT})     


/*******************************************************************************
 * Board Parameters 
*******************************************************************************/
/**
 * Current sensing shunt resistance in Ohms
 */ 
#define CURRENT_SENSE_SHUNT_RESISTANCE_IN_OHM (float)${MCPMSMFOC_ANALOG_FRONT_END_IA_SHUNT} 

/**
 * Current sensing amplifier type
 */ 
#define INVERTING_CURRENT_GAIN_AMPLIFIER

/**
 * Current sensing amplifier gain
 */ 
#define CURRENT_SENSE_AMPLIFIER_GAIN (float)${MCPMSMFOC_ANALOG_FRONT_END_IA_GAIN} 

/**
 * Voltage divider ratio for bus voltage measurement
 */
#define VOLTAGE_SENSE_DIVIDER_RATIO  (float)${MCPMSMFOC_DC_BUS_RATIO} 

/*******************************************************************************
 * PI Controller Parameters  
*******************************************************************************/
/**
 * Speed PI Controller Parameters 
 */
#define SPEED_TS        (float)CURRENT_CONTROL_SAMPLING_TIME
#define SPEED_KP        (float)(${MCPMSMFOC_SPEED_PID_KP})
#define SPEED_KI        (float)(${MCPMSMFOC_SPEED_PID_KI} * CURRENT_CONTROL_SAMPLING_TIME)
#define SPEED_KC        (float)(${MCPMSMFOC_SPEED_PID_KC})
#define SPEED_YMAX      (float)(${MCPMSMFOC_SPEED_PID_YMAX})

/**
 * Direct axis current PI Controller Parameters 
 */
#define D_CURRENT_TS    (float)CURRENT_CONTROL_SAMPLING_TIME
#define D_CURRENT_KP    (float)(${MCPMSMFOC_ID_PID_KP})
#define D_CURRENT_KI    (float)(${MCPMSMFOC_ID_PID_KI} * CURRENT_CONTROL_SAMPLING_TIME)
#define D_CURRENT_KC    (float)(${MCPMSMFOC_ID_PID_KC})
#define D_CURRENT_YMAX  (float)(${MCPMSMFOC_ID_PID_YMAX})

/**
 * Quadrature axis current PI Controller Parameters 
 */
#define Q_CURRENT_TS     (float)CURRENT_CONTROL_SAMPLING_TIME
#define Q_CURRENT_KP     (float)(${MCPMSMFOC_IQ_PID_KP})
#define Q_CURRENT_KI     (float)(${MCPMSMFOC_IQ_PID_KI} * CURRENT_CONTROL_SAMPLING_TIME)
#define Q_CURRENT_KC    (float)(${MCPMSMFOC_IQ_PID_KC})
#define Q_CURRENT_YMAX   (float)(${MCPMSMFOC_IQ_PID_YMAX})



/*******************************************************************************
 * Torque Mode Parameters  
*******************************************************************************/
<#--  #define TORQUE_MODE_MAXIMUM_CURRENT   (float)(${MCPMSMFOC_END_TORQUE})  -->


/*******************************************************************************
 * Start-up Parameters  
*******************************************************************************/

/**
 * Forced alignment lock time 
 */ 
#define START_UP_LOCK_TIME_IN_SECOND   (${MCPMSMFOC_STARTUP_TIME}) 

/**
  * Start-up current in amperes                          
  */
#define START_UP_CURRENT_IN_AMPERE   (${MCPMSMFOC_STARTUP_CURRENT}) 


/**
 * Start-up ramp time
 */
#define START_UP_RAMP_TIME_IN_SECOND   (${MCPMSMFOC_OPEN_LOOP_RAMP_TIME})


/**
 * Start-up stabilization time
 */
#define START_UP_STAB_TIME_IN_SECOND   (2)


/**
 * Start-up transition speed 
 */
#define START_UP_TRANS_SPEED_IN_RPM    (${MCPMSMFOC_OPEN_LOOP_END_SPEED})

#endif // USERPARAMS_H

