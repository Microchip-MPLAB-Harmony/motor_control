/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    mc_app.c

  Summary:
    This file contains the sensored FOC motor control algorithm.

  Description:
    This file contains the sensored FOC motor control algorithm
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
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


// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "definitions.h"                // SYS function prototypes
#include "mc_app.h"
#include "userparams.h"
#include "CMSIS/Core/Include/core_cm7.h"
#include "X2CScope.h"
#include "X2CScopeCommunication.h"
#include "math.h"


/******************************************************************************/
/* Local Function Prototype                                                   */
/******************************************************************************/
__STATIC_INLINE void MCAPP_MotorAngleCalc(void);
__STATIC_INLINE void MCAPP_MotorCurrentControl( void );
static void MCAPP_ADCOffsetCalibration(void);
static void MCAPP_MotorControlParamInit(void);
__STATIC_INLINE bool MCAPP_SlowLoopTimeIsFinished(void);
__STATIC_INLINE void MCAPP_SlowControlLoop(void);
static void MCAPP_SwitchDebounce(MC_APP_STATE state);

#if(TORQUE_MODE == false)
__STATIC_INLINE void MCAPP_SpeedRamp(void);
#endif

/******************************************************************************/
/*                   Structures                                               */
/******************************************************************************/
/*  Motor control algorithm control structure  */
MCAPP_CONTROL_PARAM gCtrlParam;
MCAPP_FOC_PARAM gfocParam;
MCAPP_DATA gMCAPPData;
MCAPP_POSITION_CALC gPositionCalc;


/******************************************************************************/
/*                   Global Variables                                         */
/******************************************************************************/
float speed_ref_filtered = 0.0f;
float phaseCurrentUOffset;
float phaseCurrentVOffset;

/*****************ISR Functions *******************************/

/******************************************************************************/
/* Function name: MCAPP_MotorCurrentControl                                   */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description:                                                               */
/* Executes one PI iteration for each of the three loops Id,Iq,Speed          */
/******************************************************************************/
__STATIC_INLINE void MCAPP_MotorCurrentControl( void )
{
    if( gCtrlParam.openLoop == true )
    {
        /* OPENLOOP:  force rotating angle,Vd,Vq */
        if( gCtrlParam.changeMode == true )
        {
            /* just changed to open loop */
            gCtrlParam.changeMode = false;

            /* IqRef & IdRef not used */
            gCtrlParam.iqRef = 0;
            gCtrlParam.idRef = 0;

            /* re-init vars for initial speed ramp */
            gCtrlParam.startup_lock_count = 0;
            gCtrlParam.startup_angle_ramp_rads_per_sec = 0;
        }

        /* q current reference is equal to the velocity reference
         * while d current reference is equal to 0
         * for maximum startup torque, set the q current to maximum acceptable
         * value represents the maximum peak value 	 */

        gCtrlParam.iqRef = Q_CURRENT_REF_OPENLOOP;


        /* PI control for Iq torque control loop */
        gPIParmQ.inMeas = gMCLIBCurrentDQ.iq;
        gPIParmQ.inRef  = gCtrlParam.iqRef;
        MCLIB_PIControl(&gPIParmQ);
        gMCLIBVoltageDQ.vq    = gPIParmQ.out;

        /* PI control for Id flux control loop */
        gPIParmD.inMeas = gMCLIBCurrentDQ.id;
        gPIParmD.inRef  = gCtrlParam.idRef;
        MCLIB_PIControl(&gPIParmD);
        gMCLIBVoltageDQ.vd = gPIParmD.out;
    }
    else
    {
        /* Closed Loop Vector Control */
        if( gCtrlParam.changeMode == true )
        {
            /* Just switched from open loop to close loop */
            gCtrlParam.changeMode = false;
            /* Load velocity control loop with Iq reference for smooth transition */
            gPIParmQref.dSum = gCtrlParam.iqRef;
            gPIParmD.inRef = 0.0;
            gCtrlParam.idRef = 0.0;
            gCtrlParam.sync_cnt = 0;
        }

        #if(TORQUE_MODE == true)
        /* If TORQUE MODE is enabled then skip the velocity control loop */
        gCtrlParam.iqRef = Q_CURRENT_REF_OPENLOOP;
        #endif

        /* PI control for Id flux control loop */
        gPIParmD.inMeas = gMCLIBCurrentDQ.id;          /* This is in Amps */
        gPIParmD.inRef  = gCtrlParam.idRef;       /* This is in Amps */
        MCLIB_PIControl(&gPIParmD);

        gfocParam.lastVd = gMCLIBVoltageDQ.vd;
        gMCLIBVoltageDQ.vd    = gPIParmD.out;          /* This is in %. It should be converted to volts, multiply with (DC/sqrt(3)) */

        /* PI control for Iq torque control */
        gPIParmQ.inMeas = gMCLIBCurrentDQ.iq;          /* This is in Amps */
        gPIParmQ.inRef  = gCtrlParam.iqRef;       /* This is in Amps */
        MCLIB_PIControl(&gPIParmQ);
        /* This is in %. If should be converted to volts, multiply with (VDC/sqrt(3))  */
        gMCLIBVoltageDQ.vq    = gPIParmQ.out;
    }
}

/******************************************************************************/
/* Function name: MCAPP_MotorAngleCalc                                        */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description: Generate the start sin waves feeding the motor's terminals    */
/* in open loop control, forcing the motor to align and to start speeding up  */
/******************************************************************************/
__STATIC_INLINE void MCAPP_MotorAngleCalc(void)
{
    uint32_t pos;
    float position_elec;

    if(gCtrlParam.openLoop == true)
    {
        /* begin with the lock sequence, for field alignment */
        if (gCtrlParam.startup_lock_count < LOCK_COUNT_FOR_LOCK_TIME)
        {
            gCtrlParam.startup_lock_count++;
            gPositionCalc.rotor_angle_rad_per_sec = M_PI;
        }
        else
        {
            if(gCtrlParam.startup_lock_count < 2*LOCK_COUNT_FOR_LOCK_TIME)
            {
                gCtrlParam.startup_lock_count++;
                gPositionCalc.rotor_angle_rad_per_sec = (3*M_PI_2);
            }
            else
            {
            /* switch to close loop */
            gCtrlParam.changeMode = true;
            gCtrlParam.openLoop = false;
            /* Start QDEC timer */
            TC0_QuadratureStart();
            /* the angle set after alignment */
            gPositionCalc.rotor_angle_rad_per_sec = 0;
            }
        }
    }
    else
    {
        /* Switched to closed loop..*/
        gPositionCalc.encoder_pulse_count_int16_t = (int16_t)(TC0_REGS->TC_CHANNEL[0].TC_CV);
        position_elec = (float)gPositionCalc.encoder_pulse_count_int16_t;
        if(position_elec >= 0)
        {
            pos = fmod(position_elec,ENCODER_PULSES_PER_EREV);
            gPositionCalc.rotor_angle_rad_per_sec = pos * (2 * M_PI/ENCODER_PULSES_PER_EREV);
        }
        else
        {
            pos= fmod((-position_elec),ENCODER_PULSES_PER_EREV);
            gPositionCalc.rotor_angle_rad_per_sec = (ENCODER_PULSES_PER_EREV - pos) * (2 * M_PI/ENCODER_PULSES_PER_EREV);
        }

    }

    /* Limit rotor angle range to 0 to 2*M_PI for lookup table */
    if(gPositionCalc.rotor_angle_rad_per_sec > (2*M_PI))
    {
      gfocParam.angle = gPositionCalc.rotor_angle_rad_per_sec - (2*M_PI);
    }
    else if(gPositionCalc.rotor_angle_rad_per_sec < 0)
    {
      gfocParam.angle = 2*M_PI + gPositionCalc.rotor_angle_rad_per_sec;
    }
    else
    {
      gfocParam.angle = gPositionCalc.rotor_angle_rad_per_sec;
    }
}

/******************************************************************************/
/* Function name: MCAPP_ADCOffsetCalibration                                  */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description: Measures motor phase current offsets.Limits the offset if it  */
/*              exceeds the predetermined range.                              */
/******************************************************************************/

static void MCAPP_ADCOffsetCalibration(void)
{
    uint32_t AdcSampleCounter = 0;
    int32_t delayCounter = 0xFFFF;
    uint32_t phaseUOffsetBuffer = 0;
    uint32_t phaseVOffsetBuffer = 0;

    /* Disable interrupt generation */
    AFEC0_ChannelsInterruptDisable(AFEC_INTERRUPT_EOC_7_MASK);

    /* Software trigger used for ADC conversion. */
    AFEC0_REGS->AFEC_MR &= ~(AFEC_MR_TRGEN_Msk);

    for(AdcSampleCounter = 0; AdcSampleCounter < CURRENTS_OFFSET_SAMPLES; AdcSampleCounter++)
    {
        /* Software trigger for phase current measurements */
        AFEC0_ConversionStart();

        /* Delay to stabilize voltage levels on board and adc conversion to complete */
        do
        {
            asm("NOP");
            asm("NOP");
            asm("NOP");
            asm("NOP");
            asm("NOP");
            delayCounter--;
        } while (delayCounter > 0);

        /* re-load delay counter for next adc sample */
        delayCounter = 0xFFFF;

        phaseUOffsetBuffer += AFEC0_ChannelResultGet(PH_U_CURRENT_ADC_CH);
        phaseVOffsetBuffer += AFEC0_ChannelResultGet(PH_V_CURRENT_ADC_CH);
    }

    phaseCurrentUOffset = (float)(phaseUOffsetBuffer/CURRENTS_OFFSET_SAMPLES);
    phaseCurrentVOffset = (float)(phaseVOffsetBuffer/CURRENTS_OFFSET_SAMPLES);

    /* Limit motor phase A current offset calibration to configured Min/Max levels. */
    if(phaseCurrentUOffset >  (float)CURRENT_OFFSET_MAX)
    {
        phaseCurrentUOffset = (float)CURRENT_OFFSET_MAX;
    }
    else if(phaseCurrentUOffset <  (float)CURRENT_OFFSET_MIN)
    {
        phaseCurrentUOffset = (float)CURRENT_OFFSET_MIN;
    }

    /* Limit motor phase B current offset calibration to configured Min/Max levels. */
    if(phaseCurrentVOffset >  (float)CURRENT_OFFSET_MAX)
    {
        phaseCurrentVOffset = (float)CURRENT_OFFSET_MAX;
    }
    else if(phaseCurrentVOffset <  (float)CURRENT_OFFSET_MIN)
    {
        phaseCurrentVOffset = (float)CURRENT_OFFSET_MIN;
    }

    /* Enable adc end of conversion interrupt generation to execute FOC loop */
    AFEC0_ChannelsInterruptEnable(AFEC_INTERRUPT_EOC_7_MASK);
    /* Set adc trigger from PWM event lines */
    AFEC0_REGS->AFEC_MR |= (AFEC_MR_TRGEN_Msk);
}

/******************************************************************************/
/* Function name: MCAPP_PIOutputInit                                          */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description: Initialize PI structure                                       */
/******************************************************************************/
void MCAPP_PIOutputInit( MCLIB_PI *pParm)
{
    pParm->dSum = 0;
    pParm->out = 0;
}

/******************************************************************************/
/* Function name: MCAPP_MotorPIParamInit                                      */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description:                                                               */
/* Initialize control parameters: PI coefficients for D,Q and                 */
/* Velocity control loop.                                                     */
/******************************************************************************/
void MCAPP_MotorPIParamInit(void)
{
    /**************** PI D Term ***********************************************/
    gPIParmD.kp = D_CURRCNTR_PTERM;
    gPIParmD.ki = D_CURRCNTR_ITERM;
    gPIParmD.kc = D_CURRCNTR_CTERM;
    gPIParmD.outMax = D_CURRCNTR_OUTMAX;
    gPIParmD.outMin = -D_CURRCNTR_OUTMAX;

    MCAPP_PIOutputInit(&gPIParmD);

    /**************** PI Q Term ************************************************/
    gPIParmQ.kp = Q_CURRCNTR_PTERM;
    gPIParmQ.ki = Q_CURRCNTR_ITERM;
    gPIParmQ.kc = Q_CURRCNTR_CTERM;
    gPIParmQ.outMax = Q_CURRCNTR_OUTMAX;
    gPIParmQ.outMin = -Q_CURRCNTR_OUTMAX;

    MCAPP_PIOutputInit(&gPIParmQ);

    /**************** PI Velocity Control **************************************/
    gPIParmQref.kp = SPEEDCNTR_PTERM;
    gPIParmQref.ki = SPEEDCNTR_ITERM;
    gPIParmQref.kc = SPEEDCNTR_CTERM;
    gPIParmQref.outMax = SPEEDCNTR_OUTMAX;
    gPIParmQref.outMin = 0.0f;

    MCAPP_PIOutputInit(&gPIParmQref);
}

/******************************************************************************/
/* Function name: MCAPP_MotorControlParamInit                                 */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description: Initialize control loop variables.                            */
/******************************************************************************/
static void MCAPP_MotorControlParamInit(void)
{
    /* Parameter initialization for FOC */
    MCAPP_MotorPIParamInit();

    gCtrlParam.openLoop = true;
    gCtrlParam.changeMode = false;
    gCtrlParam.startup_lock_count = 0;
    gMCLIBPosition.angle = 0;
    gMCLIBSVPWM.period = MAX_DUTY;
    gCtrlParam.motorStatus = MOTOR_STATUS_STOPPED;
    gMCLIBCurrentDQ.id = 0;
    gMCLIBCurrentDQ.iq = 0;
    gCtrlParam.rampIncStep = SPEED_RAMP_INC_SLOW_LOOP;
    MCAPP_PIOutputInit(&gPIParmD);
    MCAPP_PIOutputInit(&gPIParmQ);
    MCAPP_PIOutputInit(&gPIParmQref);

    gPositionCalc.rotor_angle_rad_per_sec = 0;
    gPositionCalc.elec_rotation_count = 0;
    gPositionCalc.prev_position_count = 0;
    gPositionCalc.present_position_count = 0;
    gPositionCalc.encoder_pulse_count_int16_t = 0;
}

/******************************************************************************/
/* Function name: MCAPP_SlowLoopTimeIsFinished                                */
/* Function parameters: None                                                  */
/* Function return: Bool( True - executes slow control loop )                 */
/* Description: To be used in a while loop; It returns true                   */
/******************************************************************************/
__STATIC_INLINE bool MCAPP_SlowLoopTimeIsFinished(void)
{
    uint8_t retval = false;
    if(SLOW_LOOP_TIME_PWM_COUNT <= gCtrlParam.sync_cnt)
    {
        gCtrlParam.sync_cnt = 0;
        retval = true;
    }
    return( retval );
}

#if(TORQUE_MODE == false)
/******************************************************************************/
/* Function name: MCAPP_Spee                                                  */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description: Increment/Decrements speed reference based upon ramp          */
/*              configuration in "userparams.h" file.                         */
/******************************************************************************/
__STATIC_INLINE void MCAPP_SpeedRamp(void)
{
   if(gCtrlParam.endSpeed > (gCtrlParam.velRef + gCtrlParam.rampIncStep))
   {
      gCtrlParam.velRef += gCtrlParam.rampIncStep;
   }
   else if(gCtrlParam.endSpeed < (gCtrlParam.velRef - gCtrlParam.rampIncStep))
   {
      gCtrlParam.velRef -= gCtrlParam.rampIncStep;
   }
   else
   {
      gCtrlParam.velRef = gCtrlParam.endSpeed;
   }
}
#endif

/******************************************************************************/
/* Function name: MCAPP_PWMDutyUpdate                                         */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description: Configure duty cycle of WPM channels based on control loop    */
/******************************************************************************/
__STATIC_INLINE void MCAPP_PWMDutyUpdate(uint32_t duty_PhU, uint32_t duty_PhV, uint32_t duty_PhW)
{
    PWM0_ChannelDutySet(PWM_CHANNEL_0, duty_PhU);
    PWM0_ChannelDutySet(PWM_CHANNEL_1, duty_PhV);
    PWM0_ChannelDutySet(PWM_CHANNEL_2, duty_PhW);
}

/******************************************************************************/
/* Function name: MCAPP_ControlLoopISR                                        */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description: ADC end of conversion interrupt is used for executing fast    */
/*              control loop. Angle is obtained from quadrature encoder.      */
/* ISR Timings -                                                              */
/*               Flash + Cache       - 2.84us  - Optimization -O1             */
/******************************************************************************/

void MCAPP_ControlLoopISR(uint32_t status, uintptr_t context)
{
    float phaseCurrentU;
    float phaseCurrentV;
    float dcBusVoltage;
    X2CScope_Update();
    /* PC23 GPIO is used for timing measurement. - Set High*/
    /* D17 LED on MCLV-2 */
    PIOC_REGS->PIO_SODR = 1 << (23 & 0x1F);

 	/* Dummy reading for ADC currents. Later it will be replaced by actual motor currents */
    phaseCurrentU = AFEC0_ChannelResultGet(PH_U_CURRENT_ADC_CH);
    phaseCurrentV = AFEC0_ChannelResultGet(PH_V_CURRENT_ADC_CH);

   /* Remove the offset from measured motor currents */
    phaseCurrentU = phaseCurrentU - phaseCurrentUOffset;
    phaseCurrentV = phaseCurrentV - phaseCurrentVOffset;

    /* Non Inverting amplifiers for current sensing */
    #if(MOTOR_DIRECTION == MOTOR_DIRECTION_POSITIVE)
    gMCLIBCurrentABC.ia  = phaseCurrentU * ADC_CURRENT_SCALE;
    gMCLIBCurrentABC.ib  = phaseCurrentV * ADC_CURRENT_SCALE;
    #else
    gMCLIBCurrentABC.ib  = phaseCurrentU * ADC_CURRENT_SCALE;
    gMCLIBCurrentABC.ia  = phaseCurrentV * ADC_CURRENT_SCALE;
    #endif

    /* Clarke transform */
    MCLIB_ClarkeTransform(&gMCLIBCurrentABC, &gMCLIBCurrentAlphaBeta);

	  /* Park transform */
    MCLIB_ParkTransform(&gMCLIBCurrentAlphaBeta, &gMCLIBPosition, &gMCLIBCurrentDQ);

    /* Read DC bus voltage */
    dcBusVoltage = AFEC0_ChannelResultGet(DC_BUS_VOLTAGE_ADC_CH);
	  gfocParam.dcBusVoltage = (float)(dcBusVoltage) * VOLTAGE_ADC_TO_PHY_RATIO;
    gfocParam.dcBusVoltageBySqrt3 = (float)(gfocParam.dcBusVoltage/SQRT3);

    /* Calculate control values  */
    MCAPP_MotorCurrentControl();

    /* Calculate park angle */
    MCAPP_MotorAngleCalc();

    gMCLIBPosition.angle = gfocParam.angle;

    /* Calculate qSin,qCos from qAngle  */
    MCLIB_SinCosCalc( &gMCLIBPosition );

    /* Calculate qValpha, qVbeta from qSin,qCos,qVd,qVq */
    MCLIB_InvParkTransform(&gMCLIBVoltageDQ, &gMCLIBPosition, &gMCLIBVoltageAlphaBeta);

    /* Calculate and set PWM duty cycles from Vr1,Vr2,Vr3 */
    MCLIB_SVPWMGen(&gMCLIBVoltageAlphaBeta, &gMCLIBSVPWM);

  #if(MOTOR_DIRECTION == MOTOR_DIRECTION_POSITIVE)
    MCAPP_PWMDutyUpdate(gMCLIBSVPWM.dPWM1, gMCLIBSVPWM.dPWM2, gMCLIBSVPWM.dPWM3);
  #else
    MCAPP_PWMDutyUpdate(gMCLIBSVPWM.dPWM2, gMCLIBSVPWM.dPWM1, gMCLIBSVPWM.dPWM3);
  #endif

    /* sync count for slow control loop execution */
    gCtrlParam.sync_cnt++;

    /* PC23 GPIO is used for timing measurement. - Set Low*/
    PIOC_REGS->PIO_CODR = 1 << (23 & 0x1F);
}

/******************************************************************************/
/* Function name: TC0_CH0_InterruptHandler                                    *
 * Function parameters: None                                                  *
 * Function return: None                                                      *
 * Description: Interrupt handler of TC0_CH0 period event. This tracks the    *
 *              number of revolutions.                                        *
 ******************************************************************************/
void MCAPP_EncoderRevolutionsISR(TC_QUADRATURE_STATUS quad_status, uintptr_t context)
{
    uint32_t status;
    gPositionCalc.elec_rotation_count++;
    status = TC0_REGS->TC_CHANNEL[0].TC_SR;
    (void)status;
}
/******************************************************************************/
/* Function name: MCAPP_SlowControlLoop                                       */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description: Slow control loop is in sync with fast control loop           */
/*              ADCEOCInterruptHandler().Slow loop execution frequency should */
/*              be in multiple of PWM frequency and be configured by          */
/*              "SLOW_LOOP_TIME_SEC" MACRO in "userparms.h file.              */
/*               Speed ramp and speed control loop is executed from this loop */
/******************************************************************************/
__STATIC_INLINE void MCAPP_SlowControlLoop(void)
{

    #if(TORQUE_MODE == false)
    uint16_t rotations = 0;
    float pos_count_diff;
    float speed_elec_rad_per_sec;

    if(gCtrlParam.openLoop == false)
    {
        /* Velocity reference will be taken from potentiometer. */
        float PotReading;
        PotReading = (float)AFEC0_ChannelResultGet(POT_ADC_CH);
        speed_ref_filtered = speed_ref_filtered + ((PotReading - speed_ref_filtered) * KFILTER_POT );

        gCtrlParam.endSpeed = (float)((float)speed_ref_filtered * POT_ADC_COUNT_FW_SPEED_RATIO);

        /* Speed Ramp */
        MCAPP_SpeedRamp();

        /* Speed Calculation from Encoder */
        gPositionCalc.present_position_count = (TC0_REGS->TC_CHANNEL[0].TC_CV);
        rotations = gPositionCalc.elec_rotation_count;
        gPositionCalc.elec_rotation_count = 0;
        pos_count_diff = gPositionCalc.present_position_count - gPositionCalc.prev_position_count;

        if(rotations > 0)
        pos_count_diff += rotations*ENCODER_PULSES_PER_EREV;

        gPositionCalc.prev_position_count = gPositionCalc.present_position_count;

        speed_elec_rad_per_sec = (pos_count_diff * 2*M_PI)/(ENCODER_PULSES_PER_EREV *SLOW_LOOP_TIME_SEC );

        /* Execute the velocity control loop */
        gPIParmQref.inMeas = speed_elec_rad_per_sec;
        gPIParmQref.inRef  = gCtrlParam.velRef;
        MCLIB_PIControl(&gPIParmQref);
        gCtrlParam.iqRef = gPIParmQref.out;

    }
#endif	// End of #if(TORQUE_MODE == false)
}

/******************************************************************************/
/* Function name: MCAPP_Motor                                                 */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description: Enables fast control loop and starts the PWM's.               */
/******************************************************************************/
void MCAPP_MotorStart(void)
{
    /* Stop QDEC Timer */
    /* Initialize motor control variables */
    MCAPP_MotorControlParamInit();
    /* ADC end of conversion interrupt generation for FOC control */
    NVIC_DisableIRQ(AFEC0_IRQn);
    NVIC_ClearPendingIRQ(AFEC0_IRQn);
    NVIC_SetPriority(AFEC0_IRQn, 0);
    AFEC0_CallbackRegister(MCAPP_ControlLoopISR, (uintptr_t)NULL);
    NVIC_EnableIRQ(AFEC0_IRQn);
    AFEC0_ChannelsInterruptEnable(AFEC_INTERRUPT_EOC_7_MASK);
    ((pio_registers_t*)PIO_PORT_D)->PIO_PDR = PIO_PDR_P24_Msk|PIO_PDR_P25_Msk|PIO_PDR_P26_Msk;                      // Enable PWML output.
    TC0_QuadratureCallbackRegister(MCAPP_EncoderRevolutionsISR, (uintptr_t) NULL);
    gCtrlParam.motorStatus = MOTOR_STATUS_RUNNING;
    /* Clear fault before start */
    PWM0_FaultStatusClear(PWM_FAULT_ID_2);

    /* Enable PWM channels. */
    PWM0_ChannelsStart(PWM_CHANNEL_0_MASK);

    gMCAPPData.mcState = MC_APP_STATE_RUNNING;
}

/******************************************************************************/
/* Function name: MCAPP_MotorStop                                             */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description: Stop's PWM and disables fast control loop.                    */
/******************************************************************************/
void MCAPP_MotorStop(void)
{

    ((pio_registers_t*)PIO_PORT_D)->PIO_PER = PIO_PER_P24_Msk|PIO_PER_P25_Msk|PIO_PER_P26_Msk;    // Disable PWML output.

    /* Disables PWM channels. */
    PWM0_ChannelsStop(PWM_CHANNEL_0_MASK | PWM_CHANNEL_1_MASK | PWM_CHANNEL_2_MASK);

    /* Reset algorithm specific variables for next iteration.*/
    MCAPP_MotorControlParamInit();
    /* ADC end of conversion interrupt generation disabled */
    AFEC0_ChannelsInterruptDisable(AFEC_INTERRUPT_EOC_7_MASK);
    NVIC_DisableIRQ(AFEC0_IRQn);
    NVIC_ClearPendingIRQ(AFEC0_IRQn);
    TC0_QuadratureStop();
    gCtrlParam.endSpeed = 0;
    gCtrlParam.velRef = 0;
    gCtrlParam.motorStatus = MOTOR_STATUS_STOPPED;
    gfocParam.angle = 0;
    gMCAPPData.mcState = MC_APP_STATE_STOP;
}

/******************************************************************************/
/* Function name: MCAPP_SwitchDebounce                                        */
/* Function parameters: state                                                 */
/* Function return: None                                                      */
/* Description: Switch button debounce logic                                  */
/******************************************************************************/
static void MCAPP_SwitchDebounce(MC_APP_STATE state)
{
    if (!SWITCH_Get())
    {
        gMCAPPData.switchCount++;
        if (gMCAPPData.switchCount >= 0xFF)
        {
           gMCAPPData.switchCount = 0;
           gMCAPPData.switchState = MC_APP_SWITCH_PRESSED;
        }
    }
    if (gMCAPPData.switchState == MC_APP_SWITCH_PRESSED)
    {
        if (SWITCH_Get())
        {
            gMCAPPData.switchCount = 0;
            gMCAPPData.switchState = MC_APP_SWITCH_RELEASED;
            gMCAPPData.mcState = state;

        }
    }

}


/******************************************************************************/
/* Function name: MCAP_Tasks                                                  */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description: Motor application state machine                               */
/******************************************************************************/
void MCAPP_Tasks()
{
  switch (gMCAPPData.mcState)
  {
      case MC_APP_STATE_INIT:
          ((pio_registers_t*)PIO_PORT_D)->PIO_PER = PIO_PER_P24_Msk|PIO_PER_P25_Msk|PIO_PER_P26_Msk;                   // Disable PWML output.
          NVIC_DisableIRQ(AFEC0_IRQn);
          NVIC_ClearPendingIRQ(AFEC0_IRQn);
          AFEC0_ChannelsInterruptDisable(AFEC_INTERRUPT_EOC_7_MASK);
     #if(MOTOR_DIRECTION == MOTOR_DIRECTION_NEGATIVE)
          TC0_REGS->TC_BMR |= TC_BMR_SWAP_Msk;
     #else
          TC0_REGS->TC_BMR &= ~(TC_BMR_SWAP_Msk);
     #endif
          MCAPP_ADCOffsetCalibration();
          gMCAPPData.switchCount = 0xFF;
          MCAPP_SwitchDebounce(MC_APP_STATE_START);
          break;

      case MC_APP_STATE_START:
          MCAPP_MotorStart();
          gMCAPPData.mcState = MC_APP_STATE_RUNNING;
          break;

      case MC_APP_STATE_RUNNING:
          if(MCAPP_SlowLoopTimeIsFinished())
          {
            MCAPP_SlowControlLoop();
          }
          MCAPP_SwitchDebounce(MC_APP_STATE_STOP);
          break;

      case MC_APP_STATE_STOP:
          MCAPP_MotorStop();
          MCAPP_SwitchDebounce(MC_APP_STATE_START);
          break;

      default:
          break;
  }
}
