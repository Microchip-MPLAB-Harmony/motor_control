/*******************************************************************************
 Motor Control Application Source file 

  Company:
    Microchip Technology Inc.

  File Name:
    mc_app.c

  Summary:
    This file contains all the functions related to motor control application

  Description:
    This file contains implementation of the application state machine
 
 *******************************************************************************/

// DOM-IGNORE-BEGIN
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
// DOM-IGNORE-END


/*******************************************************************************
Headers inclusions
*******************************************************************************/
#include "q14_generic_mcLib.h"
#include "device.h"
#include "mc_app.h"
#include "definitions.h"
#include <sys/attribs.h>
#include "userparams.h"
#include "X2CScope.h"

/*******************************************************************************
Variables
*******************************************************************************/
motor_bc_params_t       Motor_BCParams;
motor_hall_params_t     Motor_HallParams;
motor_state_params_t    Motor_StateParams;
picontrol_type          Motor_Speed_PIParams;

/* Hall Pattern 
 first 8 entries are for clockwise direction and later 8 for anti-clockwise direction
 */
const uint16_t HALL_ARRAY[16] = { 0, 5, 3, 1, 6, 4, 2, 0, 0, 3, 6, 2, 5, 1, 4, 0 };  

/* Commutation Pattern as per Hall Pattern
 first 8 entries are for clockwise direction and later 8 for anti-clockwise direction
 */
const uint16_t COMMUTATION_ARRAY[16] = {
    0,    
    /* to achieve B+ C-, put the following in Pattern register H1H2H3: 001 */
    0x4075, //0x4075, HS //0x0237U, LS
    /* to achieve A+ B-, put the following in Pattern register H1H2H3: 010 */
    0x2076, //0x2076, HS //0x0157U, LS
    /* to achieve A+ C-, put the following in Pattern register H1H2H3: 011 */
    0x4076, //0x4076, HS //0x0137U, LS
    /* to achieve C+ A-, put the following in Pattern register H1H2H3: 100 */
    0x1073, //0x1073, HS //0x0467U, LS
    /* to achieve B+ A-, put the following in Pattern register H1H2H3: 101 */
    0x1075, //0x1075, HS //0x0267U, LS
    /* to achieve C+ B-, put the following in Pattern register H1H2H3: 110 */
    0x2073, //0x2073, HS //0x0457U, LS
    /* Not a valid pattern */
    0,
    0,
    0x2073,
    0x1075,
    0x1073,
    0x4076,
    0x2076,
    0x4075,
    0
};


/*******************************************************************************
Function Prototypes
*******************************************************************************/
#ifdef RAM_EXECUTE
void __ramfunc__ ADC_ISR(ADC_STATUS status, uintptr_t context);
void __ramfunc__ OC_FAULT_ISR(uintptr_t context);
void __ramfunc__ TC4_1ms_ISR(TC_TIMER_STATUS status, uintptr_t context);
void __ramfunc__ Hall_UpdateCommutation_ISR(void);

#else
void ADC_ISR(ADC_STATUS status, uintptr_t context);
void OC_FAULT_ISR(uintptr_t context);
void TC4_1ms_ISR(TC_TIMER_STATUS status, uintptr_t context);
void Hall_UpdateCommutation_ISR(void);
#endif
/*******************************************************************************
Functions
*******************************************************************************/

/******************************************************************************
Function:     MCAPP_MotorControlVarsInit
Description:  motor control variable initialization
Input:        nothing (uses some global variables)
Output:       nothing (modifies some global variables)
Note:         to be called once before starting the control functions              
******************************************************************************/
void MCAPP_MotorControlVarsInit(void)
{
    Motor_StateParams.state_run = 0;
    Motor_StateParams.motor_stop_source = NO_START_CMD;
    Motor_StateParams.direction_offset = 0;
    Motor_StateParams.switch_state = 0;
    Motor_StateParams.direction = 0;
    
    Motor_HallParams.curpattern = 1;
    Motor_HallParams.nextpattern = 3;
        
    Motor_Speed_PIParams.error = 0;
    Motor_Speed_PIParams.kp = (int32_t)SPEED_KP_DEFAULT;
    Motor_Speed_PIParams.ki = (int32_t)SPEED_KI_DEFAULT;
    Motor_Speed_PIParams.maxlimit = SPEED_MAX_LIMIT;
    Motor_Speed_PIParams.minlimit = SPEED_MIN_LIMIT;
    Motor_Speed_PIParams.outputvalue = 0;
    Motor_Speed_PIParams.integratorBuf = 0;
    
    Motor_BCParams.speed_constant = (TC3_TimerFrequencyGet() * 10) / MOTOR_POLE_PAIRS;
    Motor_BCParams.speed_pi_enable = 0;
    
}

/******************************************************************************
Function:     MCAPP_Start
Description:  motor control start function 
Input:        nothing (uses some global variables)
Output:       nothing (modifies some global variables)
Note:         called when start button is pressed             
******************************************************************************/
void MCAPP_Start(void)
{
    /* ADC result ready interrupt handler to read Ishunt and Potentiometer value */
    ADC0_CallbackRegister((ADC_CALLBACK) ADC_ISR, (uintptr_t)NULL);
    
    /* Fault interrupt handler */
    EIC_CallbackRegister ((EIC_PIN)EIC_PIN_2, (EIC_CALLBACK) OC_FAULT_ISR,(uintptr_t)NULL);
    
    /* Hall A interrupt handler */
    EIC_CallbackRegister ((EIC_PIN)EIC_PIN_11, (EIC_CALLBACK) Hall_UpdateCommutation_ISR,(uintptr_t)NULL); 
    /* Hall B interrupt handler */
    EIC_CallbackRegister ((EIC_PIN)EIC_PIN_4, (EIC_CALLBACK) Hall_UpdateCommutation_ISR,(uintptr_t)NULL); 
    /* Hall C interrupt handler */
    EIC_CallbackRegister ((EIC_PIN)EIC_PIN_8, (EIC_CALLBACK) Hall_UpdateCommutation_ISR,(uintptr_t)NULL);
    
    /* 1ms timer interrupt handler for speed calculation */
    TC4_TimerCallbackRegister(TC4_1ms_ISR, (uintptr_t)NULL);
    
    MCAPP_MotorControlVarsInit();
    
    /* Enable ADC0 and thus it's slave ADC1 */
    ADC0_Enable();
    
    TCC0_PWMStart(); 
    
    /* Disable all PWM outputs */
    TCC0_PWMPatternSet(0x77, 0x00);
    
    

    /* Start 1 mS timer */
    TC4_TimerStart();    
}


/******************************************************************************
Function:     Motor_Start
Description:  motor control start function 
Input:        nothing (uses some global variables)
Output:       nothing (modifies some global variables)
Note:         called when start button is pressed             
******************************************************************************/
void Motor_Start(void)
{
    Motor_Speed_PIParams.integratorBuf = 0;    
    Motor_Speed_PIParams.outputvalue = 0;
    
    Motor_BCParams.actual_speed = 0;
    Motor_BCParams.avgtimestorage = 0;
    Motor_BCParams.avgcycletime = 0;
    Motor_BCParams.avgctr = (uint16_t) MOTOR_SPEED_CALCFACTOR;
    Motor_BCParams.actual_speed_target = 0;
    Motor_BCParams.speed_pi_enable = 0;
  
    /* Initialize duty cycle */
    TCC0_PWM24bitDutySet(TCC0_CHANNEL0, DEFAULT_DUTY);
    Motor_BCParams.speed_reference_target = DEFAULT_SPEED_TARGET; 

    Motor_HallParams.curhall1 = PORT_PinRead(PORT_PIN_PB11);     // HALL A
    Motor_HallParams.curhall2 = PORT_PinRead(PORT_PIN_PB04);     // HALL B
    Motor_HallParams.curhall3 = PORT_PinRead(PORT_PIN_PA28);     // HALL C
        
    Motor_HallParams.curpattern = ((Motor_HallParams.curhall1 << 2)|(Motor_HallParams.curhall2 << 1) | Motor_HallParams.curhall3);  

    if((Motor_HallParams.curpattern != 0U) && (Motor_HallParams.curpattern != 7U))
    {
        Motor_HallParams.pattern_commutation = COMMUTATION_ARRAY[Motor_HallParams.curpattern + (Motor_StateParams.direction_offset)];
        /* PWM should be applied only at high side switches */
        Motor_HallParams.patt_enable = (uint8_t)(Motor_HallParams.pattern_commutation & 0x00FF);
        Motor_HallParams.patt_value  = (uint8_t)(Motor_HallParams.pattern_commutation >> 8) & 0x00FF;
            
        TCC0_PWMPatternSet(Motor_HallParams.patt_enable, Motor_HallParams.patt_value);
        
        Motor_HallParams.nextpattern = HALL_ARRAY[Motor_HallParams.curpattern+(Motor_StateParams.direction_offset)];
    }
    
    TC3_TimerStart();
}


/******************************************************************************
Function:     Motor_Stop
Description:  motor control start function 
Input:        nothing (uses some global variables)
Output:       nothing (modifies some global variables)
Note:         called when stop button is pressed             
******************************************************************************/
void Motor_Stop(void)
{
    TCC0_PWMPatternSet(0x77, 0x00);
    TCC0_PWM24bitDutySet(TCC0_CHANNEL0, 0);
    Motor_BCParams.set_speed_target = 0;
    Motor_BCParams.speed_reference_rpm = 0;
    Motor_BCParams.actual_speed = 0;
    Motor_BCParams.actual_speed_target = 0;
    Motor_BCParams.speed_pi_enable = 0;
    Motor_Speed_PIParams.integratorBuf = 0;        
    TC3_TimerStop();  
    Motor_StateParams.motor_stop_source = STOP_CMD;
}



/******************************************************************************
Function:     OC_FAULT_ISR
Description:  Fault interrupt handler 
Input:        nothing (uses some global variables)
Output:       nothing (modifies some global variables)
Note:         called when overcurrent is detected             
******************************************************************************/
#ifdef RAM_EXECUTE
void __ramfunc__ OC_FAULT_ISR(uintptr_t context)
#else
void OC_FAULT_ISR(uintptr_t context)
#endif
{
    Motor_StateParams.motor_stop_source = OC_FAULT_STOP;
    Motor_StateParams.state_run = 0;
    LED1_OC_FAULT_Set();
    while(1);   
}

/******************************************************************************
Function:     ADC_ISR
Description:  ADC result ready interrupt. This reads shunt current and potentiometer. 
Input:        nothing (uses some global variables)
Output:       nothing (modifies some global variables)
Note:         called when shunt current measurement is finished.             
******************************************************************************/
#ifdef RAM_EXECUTE
void __ramfunc__ ADC_ISR(ADC_STATUS status, uintptr_t context)
#else
void ADC_ISR(ADC_STATUS status, uintptr_t context)
#endif
{
    X2CScope_Update();
    /* Read the ADC result value */
    Motor_BCParams.speed_ref_pot = ADC1_ConversionResultGet();
    Motor_BCParams.motor_current = ADC0_ConversionResultGet();
 
    if(!Motor_StateParams.var_time_10ms)
    {
        Motor_StateParams.var_cnt_10ms++;
    }
    
    if(Motor_StateParams.var_cnt_10ms == COUNT_10_MS)
    {
        Motor_StateParams.var_time_10ms = 1;
        Motor_StateParams.var_cnt_10ms = 0;
    }  
    /* Clear all interrupt flags */
    ADC0_REGS->ADC_INTFLAG = ADC_INTFLAG_Msk;       
    
    return;
}

/******************************************************************************
Function:     Hall_UpdateCommutation_ISR
Description:  Hall pin edge detect interrupt. 
 Next commutation pattern is updated in buffer register. And speed is calculated based on
 time captured by the timer TC3. 
Input:        nothing (uses some global variables)
Output:       nothing (modifies some global variables)
Note:         called when edge is detected on any hall pin            
******************************************************************************/
#ifdef RAM_EXECUTE
void __ramfunc__ Hall_UpdateCommutation_ISR(void)
#else
void Hall_UpdateCommutation_ISR(void)
#endif
{
    uint16_t timeelapsed;
    
    if(Motor_StateParams.state_run)
    {        
        Motor_HallParams.curhall1 = PORT_PinRead(PORT_PIN_PB11);     // HALL A
        Motor_HallParams.curhall2 = PORT_PinRead(PORT_PIN_PB04);     // HALL B
        Motor_HallParams.curhall3 = PORT_PinRead(PORT_PIN_PA28);     // HALL C
        
        Motor_HallParams.curpattern = ((Motor_HallParams.curhall1 << 2)|(Motor_HallParams.curhall2 << 1)| Motor_HallParams.curhall3);  // HAHBHC
    
        if((Motor_HallParams.curpattern == Motor_HallParams.nextpattern) && 
                (Motor_HallParams.curpattern != 0 && Motor_HallParams.curpattern != 7))
        {
            Motor_HallParams.pattern_commutation = COMMUTATION_ARRAY[Motor_HallParams.curpattern +
                                                                    (Motor_StateParams.direction_offset)];
            
            Motor_HallParams.patt_enable = (uint8_t) (Motor_HallParams.pattern_commutation & 0x00FF);
            Motor_HallParams.patt_value  = (uint8_t) (Motor_HallParams.pattern_commutation >> 8) & 0x00FF;
            
            TCC0_PWMPatternSet(Motor_HallParams.patt_enable, Motor_HallParams.patt_value);
            
            Motor_HallParams.nextpattern = HALL_ARRAY[Motor_HallParams.curpattern + (Motor_StateParams.direction_offset)];

            /* Read the time elapsed from last hall pattern */
            timeelapsed = TC3_Timer16bitCounterGet();
            TC3_TimerStop();
            TC3_TimerStart();
        
            if (Motor_BCParams.avgctr == 0)
            {
                Motor_BCParams.avgcycletime = Motor_BCParams.avgtimestorage / MOTOR_SPEED_CALCFACTOR;
                Motor_BCParams.avgtimestorage -= Motor_BCParams.avgcycletime;
                Motor_BCParams.speed_pi_enable = 1;
               
            }        
            else
            {
                Motor_BCParams.avgctr--;
                Motor_BCParams.speed_reference_target = DEFAULT_SPEED_TARGET;
                Motor_Speed_PIParams.integratorBuf = PI_BUF_INIT;
                
            }
    
            Motor_BCParams.avgtimestorage += timeelapsed;

            if(Motor_BCParams.speed_pi_enable)
            {
                if (Motor_BCParams.avgcycletime != 0)
                {
                    Motor_BCParams.actual_speed = Motor_BCParams.speed_constant / (Motor_BCParams.avgcycletime);        
                }
            }

            Motor_BCParams.actual_speed_target = (Motor_BCParams.actual_speed << 14) / MAX_MOTOR_SPEED;    
        }
            
    }

}

/******************************************************************************
Function:     TC4_1ms_ISR
Description:  1 mS interrupt handler  Speed Control loop
Input:        nothing (uses some global variables)
Output:       nothing (modifies some global variables)
Note:         called every 1 mS            
******************************************************************************/
#ifdef RAM_EXECUTE
void __ramfunc__ TC4_1ms_ISR(TC_TIMER_STATUS status, uintptr_t context)
#else
void TC4_1ms_ISR(TC_TIMER_STATUS status, uintptr_t context)
#endif
{  
    uint16_t duty_pwm;
    uint16_t speed_target;
   
    if (Motor_BCParams.speed_pi_enable == 1U) 
    {
        speed_target = (Motor_BCParams.speed_ref_pot << 14) / MAX_POT_REF;
        
        if(speed_target < SPEED_MIN_TARGET)
        {
            Motor_BCParams.set_speed_target = SPEED_MIN_TARGET;
        }
        else
        {
            Motor_BCParams.set_speed_target = speed_target;
        }

        if (MOTOR_RAMPUP_SPEED_PER_MS == 0U)
        {
            Motor_BCParams.speed_reference_target = Motor_BCParams.set_speed_target;
        }
        else
        {
            if(Motor_BCParams.set_speed_target > (Motor_BCParams.speed_reference_target + MOTOR_RAMPUP_SPEED_PER_MS) )
            {
                Motor_BCParams.speed_reference_target += MOTOR_RAMPUP_SPEED_PER_MS;
            }
            else if(Motor_BCParams.set_speed_target < (Motor_BCParams.speed_reference_target - MOTOR_RAMPUP_SPEED_PER_MS))
            {
                Motor_BCParams.speed_reference_target -= MOTOR_RAMPUP_SPEED_PER_MS;
            }
            else
            {
                Motor_BCParams.speed_reference_target = Motor_BCParams.set_speed_target;
            }                
        }  
     
        Motor_BCParams.speed_reference_rpm = (Motor_BCParams.speed_reference_target * MAX_MOTOR_SPEED) >> 14;         
                      
        /*    Error Calculation   Error = Reference - Actual    */
        Motor_Speed_PIParams.error    = (int32_t)Motor_BCParams.speed_reference_target - (int32_t)Motor_BCParams.actual_speed_target;
        duty_pwm = pi_lib_calculate(&Motor_Speed_PIParams);             
        TCC0_PWM24bitDutySet(TCC0_CHANNEL0, duty_pwm);             

    } 
}




/* EOF motor_control.c */

