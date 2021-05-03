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
#define Q_AXIS                          (0U)
#define D_AXIS                          (1U)

/* Control Loop */
#define OPEN_LOOP                        (0U)
#define SPEED_LOOP                       (1U)
#define TORQUE_LOOP                      (2U)


/** 
 *  Defining DEVELOPER_MODE allows the programmer to monitor debug signals via X2C Scope 
 *  Note: X2C library has to be linked for the DEVELOPER_MODE to function                    
 */

#define DEVELOPER_MODE   1u

#define CONTROL_LOOP                     (${MCPMSMFOC_CONTROL})

/**
 *  Defining Q_AXIS_STARTUP causes the open loop startup by injecting current in Q axis  
 *  Un-defining Q_AXIS_STARTUP cause the open loop startup by injecting current in D axis       
 */
#define Q_AXIS_STARTUP    1u
#define ALIGNMENT_METHOD                 (${MCPMSMFOC_ALIGNMENT})  /* alignment method  */

<#if MCPMSMFOC_REF_INPUT == "Potentiometer Analog Input">
#define POTENTIOMETER_INPUT_ENABLED       ENABLE
<#else>
#define POTENTIOMETER_INPUT_ENABLED       DISABLE
</#if>

<#if MCPMSMFOC_CONTROL == "SPEED_LOOP">
#define SPEED_REF_RPM                     (float)${MCPMSMFOC_END_SPEED}   /* Speed Ref */
<#elseif MCPMSMFOC_CONTROL == "TORQUE_LOOP">
#define Q_CURRENT_REF_TORQUE              (${MCPMSMFOC_END_TORQUE})   /* Iq ref for torque mode */
#define Q_CURRENT_MIN_TORQUE              (${MCPMSMFOC_MIN_TORQUE})   /* Min Iq current */
#define Q_CURRENT_MAX_TORQUE              (${MCPMSMFOC_MAX_TORQUE})   /* Max Iq mapped to Potentiometer max */
</#if>

/**
 *  Defining RAM_EXECUTE executes key motor control functions from RAM and thereby allowing
 *  faster execution at the expense of data memory.    
 *  Un-defining RAM_EXECUTE executes key motor control functions from Flash and thereby reducing
 *  data memory consumption at the expense of time
 *  
 * Note: Instruction breakpoint will not be asserted if that particular instruction
 * is being executed from RAM          
 */
#define RAM_EXECUTE

/**
 *  Defining USE_DIVAS uses the DIVAS peripheral for division and square root operatons         
 */
#define USE_DIVAS

/**
 *  Defining BIDIRECTION_CONTROL enables bi-directional control of the motor                            
 */ 
<#if MCPMSMFOC_BOARD_SEL != "MCHV3"> 
#define BIDIRECTION_CONTROL  ENABLE
<#else>
#define BIDIRECTION_CONTROL  DISABLE
</#if>

/**
 *  Defining CONTROL_TO_PWM_1_2 sets the control to PWM ratio to 1:2                         
 */ 
#define CONTROL_TO_PWM_1_2   ENABLE

/**
 *  Defining RAMP_PROFILE sets the ramp profile of speed in UI input mode                      
 */ 
#define STEP     0u
#define LINEAR   1u
#define RAMP_PROFILE   ${MCPMSMFOC_RAMP}

/*******************************************************************************
 * System Configuration
*******************************************************************************/
/**
 *  PWM frequency in Hz                            
 */ 
#define PWM_FREQUENCY   (${MCPMSMFOC_PWM_FREQ}U)

/**
 *  Current control Frequency                           
 */ 
#ifdef CONTROL_TO_PWM_1_2
#define CURRENT_CONTROL_FREQUENCY      ( 0.5f * PWM_FREQUENCY ) 
#else 
#define CURRENT_CONTROL_FREQUENCY      ( 1.0f * PWM_FREQUENCY ) 
#endif

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
#define MINIMUM_SPEED_IN_RPM   (${MCPMSMFOC_OL_END_SPEED}) 

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
#define CURRENT_SENSE_SHUNT_RESISTANCE_IN_OHM (float)${MCPMSMFOC_IU_OPAMP_SHUNT_R} 

/**
 * Current sensing amplifier type
 */ 
#define INVERTING_CURRENT_GAIN_AMPLIFIER

/**
 * Current sensing amplifier gain
 */ 
#define CURRENT_SENSE_AMPLIFIER_GAIN (float)${MCPMSMFOC_IU_OPAMP_GAIN} 

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
#define SPEED_KP        (float)(${MCPMSMFOC_SPEED_KP} * BASE_SPEED / BASE_CURRENT)
#define SPEED_KI        (float)(${MCPMSMFOC_SPEED_KI} * CURRENT_CONTROL_SAMPLING_TIME * BASE_SPEED / BASE_CURRENT)
#define SPEED_YMAX      (float)MAXIMUM_MOTOR_CURRENT_IN_AMPERE / BASE_CURRENT

/**
 * Direct axis current PI Controller Parameters 
 */
#define D_CURRENT_TS    (float)CURRENT_CONTROL_SAMPLING_TIME
#define D_CURRENT_KP    (float)(${MCPMSMFOC_ID_KP} * BASE_CURRENT / BASE_VOLTAGE)
#define D_CURRENT_KI    (float)(${MCPMSMFOC_ID_KI} * CURRENT_CONTROL_SAMPLING_TIME * BASE_CURRENT / BASE_VOLTAGE)
#define D_CURRENT_YMAX  (float)(${MCPMSMFOC_ID_OUT_MAX})

/**
 * Quadrature axis current PI Controller Parameters 
 */
#define Q_CURRENT_TS     (float)CURRENT_CONTROL_SAMPLING_TIME
#define Q_CURRENT_KP     (float)(${MCPMSMFOC_IQ_KP} * BASE_CURRENT / BASE_VOLTAGE)
#define Q_CURRENT_KI     (float)(${MCPMSMFOC_IQ_KI} * CURRENT_CONTROL_SAMPLING_TIME * BASE_CURRENT / BASE_VOLTAGE)
#define Q_CURRENT_YMAX   (float)(${MCPMSMFOC_IQ_OUT_MAX})



/*******************************************************************************
 * Torque Mode Parameters  
*******************************************************************************/
#define TORQUE_MODE_MAXIMUM_CURRENT   (float)(${MCPMSMFOC_END_TORQUE})


/*******************************************************************************
 * Start-up Parameters  
*******************************************************************************/

/**
 * Forced alignment lock time 
 */ 
#define START_UP_LOCK_TIME_IN_SECOND   (${MCPMSMFOC_LOCK_TIME}) 

/**
  * Start-up current in amperes                          
  */
#define START_UP_CURRENT_IN_AMPERE   (${MCPMSMFOC_OL_IQ_REF}) 


/**
 * Start-up ramp time
 */
#define START_UP_RAMP_TIME_IN_SECOND   (${MCPMSMFOC_OL_RAMP_TIME})


/**
 * Start-up stabilization time
 */
#define START_UP_STAB_TIME_IN_SECOND   (2)


/**
 * Start-up transition speed 
 */
#define START_UP_TRANS_SPEED_IN_RPM    (${MCPMSMFOC_OL_END_SPEED})

/*******************************************************************************
 * Q14 constants 
*******************************************************************************/
/* Base values */
#define BASE_VALUE                                   (16384)
#define SH_BASE_VALUE                                ( 14U )

/**
 * Base voltage 
 */ 
#define BASE_VOLTAGE   (float)( 3.30 / VOLTAGE_SENSE_DIVIDER_RATIO )

/**
 * Base current
 */ 
#define BASE_CURRENT  (float)( 1.65 / ( CURRENT_SENSE_AMPLIFIER_GAIN * CURRENT_SENSE_SHUNT_RESISTANCE_IN_OHM ))

/**
 * Base speed
 */ 
#define BASE_SPEED  (float)(2.0f * FLOAT_PI * ( (float)NUM_POLE_PAIRS * (float)RATED_SPEED_IN_RPM / 60.0f  ))


/**
 * Base impedence = Base voltage / Base current
 */  
#define BASE_IMPEDENCE    (float)(BASE_VOLTAGE/BASE_CURRENT)

/**
 * Base inductance = Base Impedence / Base speed
 */ 
#define BASE_INDUCTANCE   (float)(BASE_IMPEDENCE/BASE_SPEED)

/**
 * 
 */ 
#define K_TIME    (float)CURRENT_CONTROL_FREQUENCY

/**
 *  Real voltage to scaled voltage conversion factor
 */ 
#define K_VOLTAGE  (float)(BASE_VALUE_FL / BASE_VOLTAGE)  

/**
 * Real current to scaled current conversion factor
 */ 
#define K_CURRENT  (float)(BASE_VALUE_FL / BASE_CURRENT)

/**
 * Real impedence to scaled impedence conversion factor
 */ 
#define K_IMPEDENCE  (float)BASE_CURRENT / BASE_VOLTAGE 


/**
 * Real inductance to scaled inductance conversion factor
 */ 
#define K_INDUCTANCE  (float)BASE_CURRENT / ( BASE_VOLTAGE * BASE_SPEED )


/**
 * Real speed to scaled speed conversion factor
 */ 
#define K_SPEED  (float)(BASE_VALUE_FL / BASE_SPEED)  

/**
 * Real speed to scaled speed conversion factor for angle calculation
 */ 
#define K_SPEED_L  (uint16_t)(BASE_SPEED * (32768.0f / FLOAT_PI) / K_TIME)

/**
 * ADC count to scaled voltage conversion factor 
 */ 
#define KAD_VOL  (uint16_t)(4)  

/**
 *  ADC count to scaled voltage conversion shift
 */ 
#define SH_KAD_VOL  (  0 )

/**
 * ADC count to scaled current conversion factor 
 */ 
#ifdef INVERTING_CURRENT_GAIN_AMPLIFIER
#define KAD_CUR  (uint16_t)(  -8 )  
#else   
#define KAD_CUR  (uint16_t)( 8 )  
#endif  

/**
 * ADC count to scaled voltage conversion shift 
 */  
#define SH_KAD_CUR  (  0 )

#endif // USERPARAMS_H

