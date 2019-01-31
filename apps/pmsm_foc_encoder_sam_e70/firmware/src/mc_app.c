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
static inline void calc_park_angle(void);
static inline void do_control( void );
static void phase_current_offset_calib(void);
static void motor_ctrl_var_init(void);
static inline bool execute_slow_ctrl_loop(void);
static inline void slow_ctrl_loop(void);

static inline void clarke_transform(void);
static inline void park_transform(void);
static inline void inv_park_transform(void);
static inline void sin_cos(void);
static inline void calc_pi( tPIParm *pParm);
static inline void calc_times(void);
static inline void calc_svm_gen( void );
static void MCAPP_SwitchDebounce(MC_APP_STATE state);

#if(TORQUE_MODE == false)
static inline void speed_ramp(void);
#endif

/******************************************************************************/
/*                   Structures                                               */
/******************************************************************************/
/*  Motor control algorithm control structure  */
tCtrlParm ctrl_param;
tParkParm park_param;
tMC_APP_DATA mc_appData;
tSVGenParm svm_gen_param;
uint32_t dPWM1, dPWM2, dPWM3;
tSincosParm	SincosParm;

tPIParm     PIParmQ;        /* Iq PI controllers */
tPIParm     PIParmD;        /* Id PI controllers */
tPIParm     PIParmQref;     /* Speed PI controllers */

/******************************************************************************/
/*                   Global Variables                                         */
/******************************************************************************/
/* ramp angle variable for initial ramp */
float startup_angle_ramp_rads_per_sec = 0;
/* lock variable for initial ramp */
uint32_t startup_lock_count = 0;
float speed_ref_filtered = 0;
volatile uint32_t delay = 0;
volatile uint32_t dealy_cnt = 0;
uint32_t sw3_motor_start_toggle = 0;

/* counter in main loop (5ms) synchronization function */
volatile int32_t     sync_cnt = 0;

volatile float T1;
volatile float T2;
volatile float T_a;
volatile float T_b;
volatile float T_c;


float rotor_angle_rad_per_sec = 0;
volatile uint16_t elec_rotation_count = 0;
float prev_position_count = 0;
float present_position_count = 0;
int16_t encoder_pulse_count_int16_t = 0;

/******************************************************************************/
/*                   SIN Table  256  -  0.0244rad resolution                  */
/******************************************************************************/
float sineTable[TABLE_SIZE] =
{
0,
0.024541,
0.049068,
0.073565,
0.098017,
0.122411,
0.14673,
0.170962,
0.19509,
0.219101,
0.24298,
0.266713,
0.290285,
0.313682,
0.33689,
0.359895,
0.382683,
0.405241,
0.427555,
0.449611,
0.471397,
0.492898,
0.514103,
0.534998,
0.55557,
0.575808,
0.595699,
0.615232,
0.634393,
0.653173,
0.671559,
0.689541,
0.707107,
0.724247,
0.740951,
0.757209,
0.77301,
0.788346,
0.803208,
0.817585,
0.83147,
0.844854,
0.857729,
0.870087,
0.881921,
0.893224,
0.903989,
0.91421,
0.92388,
0.932993,
0.941544,
0.949528,
0.95694,
0.963776,
0.970031,
0.975702,
0.980785,
0.985278,
0.989177,
0.99248,
0.995185,
0.99729,
0.998795,
0.999699,
1,
0.999699,
0.998795,
0.99729,
0.995185,
0.99248,
0.989177,
0.985278,
0.980785,
0.975702,
0.970031,
0.963776,
0.95694,
0.949528,
0.941544,
0.932993,
0.92388,
0.91421,
0.903989,
0.893224,
0.881921,
0.870087,
0.857729,
0.844854,
0.83147,
0.817585,
0.803208,
0.788346,
0.77301,
0.757209,
0.740951,
0.724247,
0.707107,
0.689541,
0.671559,
0.653173,
0.634393,
0.615232,
0.595699,
0.575808,
0.55557,
0.534998,
0.514103,
0.492898,
0.471397,
0.449611,
0.427555,
0.405241,
0.382683,
0.359895,
0.33689,
0.313682,
0.290285,
0.266713,
0.24298,
0.219101,
0.19509,
0.170962,
0.14673,
0.122411,
0.098017,
0.073565,
0.049068,
0.024541,
0,
-0.024541,
-0.049068,
-0.073565,
-0.098017,
-0.122411,
-0.14673,
-0.170962,
-0.19509,
-0.219101,
-0.24298,
-0.266713,
-0.290285,
-0.313682,
-0.33689,
-0.359895,
-0.382683,
-0.405241,
-0.427555,
-0.449611,
-0.471397,
-0.492898,
-0.514103,
-0.534998,
-0.55557,
-0.575808,
-0.595699,
-0.615232,
-0.634393,
-0.653173,
-0.671559,
-0.689541,
-0.707107,
-0.724247,
-0.740951,
-0.757209,
-0.77301,
-0.788346,
-0.803208,
-0.817585,
-0.83147,
-0.844854,
-0.857729,
-0.870087,
-0.881921,
-0.893224,
-0.903989,
-0.91421,
-0.92388,
-0.932993,
-0.941544,
-0.949528,
-0.95694,
-0.963776,
-0.970031,
-0.975702,
-0.980785,
-0.985278,
-0.989177,
-0.99248,
-0.995185,
-0.99729,
-0.998795,
-0.999699,
-1,
-0.999699,
-0.998795,
-0.99729,
-0.995185,
-0.99248,
-0.989177,
-0.985278,
-0.980785,
-0.975702,
-0.970031,
-0.963776,
-0.95694,
-0.949528,
-0.941544,
-0.932993,
-0.92388,
-0.91421,
-0.903989,
-0.893224,
-0.881921,
-0.870087,
-0.857729,
-0.844854,
-0.83147,
-0.817585,
-0.803208,
-0.788346,
-0.77301,
-0.757209,
-0.740951,
-0.724247,
-0.707107,
-0.689541,
-0.671559,
-0.653173,
-0.634393,
-0.615232,
-0.595699,
-0.575808,
-0.55557,
-0.534998,
-0.514103,
-0.492898,
-0.471397,
-0.449611,
-0.427555,
-0.405241,
-0.382683,
-0.359895,
-0.33689,
-0.313682,
-0.290285,
-0.266713,
-0.24298,
-0.219101,
-0.19509,
-0.170962,
-0.14673,
-0.122411,
-0.098017,
-0.073565,
-0.049068,
-0.024541
};

/******************************************************************************/
/*                   COS Table  -  0.0244rad resolution                       */
/******************************************************************************/
float cosineTable[TABLE_SIZE] =
{
1,
0.999699,
0.998795,
0.99729,
0.995185,
0.99248,
0.989177,
0.985278,
0.980785,
0.975702,
0.970031,
0.963776,
0.95694,
0.949528,
0.941544,
0.932993,
0.92388,
0.91421,
0.903989,
0.893224,
0.881921,
0.870087,
0.857729,
0.844854,
0.83147,
0.817585,
0.803208,
0.788346,
0.77301,
0.757209,
0.740951,
0.724247,
0.707107,
0.689541,
0.671559,
0.653173,
0.634393,
0.615232,
0.595699,
0.575808,
0.55557,
0.534998,
0.514103,
0.492898,
0.471397,
0.449611,
0.427555,
0.405241,
0.382683,
0.359895,
0.33689,
0.313682,
0.290285,
0.266713,
0.24298,
0.219101,
0.19509,
0.170962,
0.14673,
0.122411,
0.098017,
0.073565,
0.049068,
0.024541,
0,
-0.024541,
-0.049068,
-0.073565,
-0.098017,
-0.122411,
-0.14673,
-0.170962,
-0.19509,
-0.219101,
-0.24298,
-0.266713,
-0.290285,
-0.313682,
-0.33689,
-0.359895,
-0.382683,
-0.405241,
-0.427555,
-0.449611,
-0.471397,
-0.492898,
-0.514103,
-0.534998,
-0.55557,
-0.575808,
-0.595699,
-0.615232,
-0.634393,
-0.653173,
-0.671559,
-0.689541,
-0.707107,
-0.724247,
-0.740951,
-0.757209,
-0.77301,
-0.788346,
-0.803208,
-0.817585,
-0.83147,
-0.844854,
-0.857729,
-0.870087,
-0.881921,
-0.893224,
-0.903989,
-0.91421,
-0.92388,
-0.932993,
-0.941544,
-0.949528,
-0.95694,
-0.963776,
-0.970031,
-0.975702,
-0.980785,
-0.985278,
-0.989177,
-0.99248,
-0.995185,
-0.99729,
-0.998795,
-0.999699,
-1,
-0.999699,
-0.998795,
-0.99729,
-0.995185,
-0.99248,
-0.989177,
-0.985278,
-0.980785,
-0.975702,
-0.970031,
-0.963776,
-0.95694,
-0.949528,
-0.941544,
-0.932993,
-0.92388,
-0.91421,
-0.903989,
-0.893224,
-0.881921,
-0.870087,
-0.857729,
-0.844854,
-0.83147,
-0.817585,
-0.803208,
-0.788346,
-0.77301,
-0.757209,
-0.740951,
-0.724247,
-0.707107,
-0.689541,
-0.671559,
-0.653173,
-0.634393,
-0.615232,
-0.595699,
-0.575808,
-0.55557,
-0.534998,
-0.514103,
-0.492898,
-0.471397,
-0.449611,
-0.427555,
-0.405241,
-0.382683,
-0.359895,
-0.33689,
-0.313682,
-0.290285,
-0.266713,
-0.24298,
-0.219101,
-0.19509,
-0.170962,
-0.14673,
-0.122411,
-0.098017,
-0.073565,
-0.049068,
-0.024541,
0,
0.024541,
0.049068,
0.073565,
0.098017,
0.122411,
0.14673,
0.170962,
0.19509,
0.219101,
0.24298,
0.266713,
0.290285,
0.313682,
0.33689,
0.359895,
0.382683,
0.405241,
0.427555,
0.449611,
0.471397,
0.492898,
0.514103,
0.534998,
0.55557,
0.575808,
0.595699,
0.615232,
0.634393,
0.653173,
0.671559,
0.689541,
0.707107,
0.724247,
0.740951,
0.757209,
0.77301,
0.788346,
0.803208,
0.817585,
0.83147,
0.844854,
0.857729,
0.870087,
0.881921,
0.893224,
0.903989,
0.91421,
0.92388,
0.932993,
0.941544,
0.949528,
0.95694,
0.963776,
0.970031,
0.975702,
0.980785,
0.985278,
0.989177,
0.99248,
0.995185,
0.99729,
0.998795,
0.999699
};

/*****************ISR Functions *******************************/
/******************************************************************************/
/* Function name: clarke_transform                                            */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description: Clarke Transformation                                         */
/******************************************************************************/
static inline void clarke_transform(void)
{
    park_param.Ialpha = park_param.Iu;
    park_param.Ibeta = (park_param.Iu * ONE_BY_SQRT3) + (park_param.Iv * TWO_BY_SQRT3);
}

/******************************************************************************/
/* Function name: park_transform                                              */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description: Park Transformation.                                          */
/******************************************************************************/
static inline void park_transform(void)
{
    park_param.Id =  park_param.Ialpha*park_param.Cos + park_param.Ibeta*park_param.Sin;
    park_param.Iq = -park_param.Ialpha*park_param.Sin + park_param.Ibeta*park_param.Cos;
}

/******************************************************************************/
/* Function name: inv_park_transform                                          */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description: Inverse Park Transformation.                                  */
/******************************************************************************/
static inline void inv_park_transform(void)
{
    park_param.Valpha =  park_param.Vd*park_param.Cos - park_param.Vq*park_param.Sin;
    park_param.Vbeta  =  park_param.Vd*park_param.Sin + park_param.Vq*park_param.Cos;
}

/******************************************************************************/
/* Function name: sin_cos                                                     */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description: Calculates the sin and cosine of angle based upon             */
/*              interpolation technique from the table.                       */
/******************************************************************************/
static inline void sin_cos(void)
{
    /* IMPORTANT:
       DO NOT PASS "SincosParm.angle" > 2*PI. There is no software check

       Since we are using "float", it is not possible to get an index of array
       directly. Almost every time, we will need to do interpolation, as per
       following equation: -
       y = y0 + (y1 - y0)*((x - x0)/(x1 - x0)) */

    uint32_t y0_Index;
    uint32_t y0_IndexNext;
    float x0, x1, y0, y1, temp;

    y0_Index = (uint32_t)(SincosParm.Angle / ANGLE_STEP);
    y0_IndexNext = y0_Index + 1;

    if(y0_IndexNext >= TABLE_SIZE )
    {
        y0_IndexNext = 0;
        x1 = TOTAL_SINE_TABLE_ANGLE;
    }
    else
    {
        x1 = ((y0_IndexNext) * ANGLE_STEP);
    }

    x0 = (y0_Index * ANGLE_STEP);

    /* Since below calculation is same for sin & cosine, we can do it once and reuse. */
    temp = ((SincosParm.Angle - x0) / (x1 - x0));
    /*==============  Find Sine now  =============================================*/
    y0 = sineTable[y0_Index];
    y1 = sineTable[y0_IndexNext];
    SincosParm.Sin = y0 + ((y1 - y0) * temp);
   /*==============  Find Cosine now  =============================================*/
    y0 = cosineTable[y0_Index];
    y1 = cosineTable[y0_IndexNext];
    SincosParm.Cos = y0 + ((y1 - y0) * temp);
}

/******************************************************************************/
/* Function name: calc_pi                                                     */
/* Function parameters: *pParm                                                */
/* Function return: None                                                      */
/* Description: Calculates PI output based on PI parameters and reference     */
/*              and actual values of parameter                                */
/******************************************************************************/
static inline void calc_pi( tPIParm *pParm)
{
    float Err;
    float Out;
    float Exc;

    Err  = pParm->InRef - pParm->InMeas;
    Out  = pParm->dSum + pParm->Kp * Err;

    /* Limit checking for PI output */
    if( Out > pParm->OutMax )
    pParm->Out = pParm->OutMax;
    else if( Out < pParm->OutMin )
    pParm->Out = pParm->OutMin;
    else
    pParm->Out = Out;

    Exc = Out - pParm->Out;
    pParm->dSum = pParm->dSum + pParm->Ki * Err - pParm->Kc * Exc;

}

/******************************************************************************/
/* Function name: do_control                                                  */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description:                                                               */
/* Executes one PI iteration for each of the three loops Id,Iq,Speed          */
/******************************************************************************/
static inline void do_control( void )
{
    if( ctrl_param.OpenLoop == true )
    {
        /* OPENLOOP:  force rotating angle,Vd,Vq */
        if( ctrl_param.ChangeMode == true )
        {
            /* just changed to open loop */
            ctrl_param.ChangeMode = false;

            /* IqRef & IdRef not used */
            ctrl_param.IqRef = 0;
            ctrl_param.IdRef = 0;

            /* re-init vars for initial speed ramp */
            startup_lock_count = 0;
            startup_angle_ramp_rads_per_sec = 0;
        }

        /* q current reference is equal to the velocity reference
         * while d current reference is equal to 0
         * for maximum startup torque, set the q current to maximum acceptable
         * value represents the maximum peak value 	 */

        ctrl_param.IqRef = Q_CURRENT_REF_OPENLOOP;


        /* PI control for Iq torque control loop */
        PIParmQ.InMeas = park_param.Iq;
        PIParmQ.InRef  = ctrl_param.IqRef;
        calc_pi(&PIParmQ);
        park_param.Vq    = PIParmQ.Out;

        /* PI control for Id flux control loop */
        PIParmD.InMeas = park_param.Id;
        PIParmD.InRef  = ctrl_param.IdRef;
        calc_pi(&PIParmD);
        park_param.Vd = PIParmD.Out;
    }
    else
    {
        /* Closed Loop Vector Control */
        if( ctrl_param.ChangeMode == true )
        {
            /* Just switched from open loop to close loop */
            ctrl_param.ChangeMode = false;
            /* Load velocity control loop with Iq reference for smooth transition */
            PIParmQref.dSum = ctrl_param.IqRef;
            PIParmD.InRef = 0.0;
            ctrl_param.IdRef = 0.0;
            sync_cnt = 0;
        }

        #if(TORQUE_MODE == true)
        /* If TORQUE MODE is enabled then skip the velocity control loop */
        ctrl_param.IqRef = Q_CURRENT_REF_OPENLOOP;
        #endif

        /* PI control for Id flux control loop */
        PIParmD.InMeas = park_param.Id;          /* This is in Amps */
        PIParmD.InRef  = ctrl_param.IdRef;       /* This is in Amps */
        calc_pi(&PIParmD);

        park_param.LastVd = park_param.Vd;
        park_param.Vd    = PIParmD.Out;          /* This is in %. It should be converted to volts, multiply with (DC/sqrt(3)) */

        /* PI control for Iq torque control */
        PIParmQ.InMeas = park_param.Iq;          /* This is in Amps */
        PIParmQ.InRef  = ctrl_param.IqRef;       /* This is in Amps */
        calc_pi(&PIParmQ);
        /* This is in %. If should be converted to volts, multiply with (VDC/sqrt(3))  */
        park_param.Vq    = PIParmQ.Out;
    }
}

/******************************************************************************/
/* Function name: calc_park_angle                                             */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description: Generate the start sin waves feeding the motor's terminals    */
/* in open loop control, forcing the motor to align and to start speeding up  */
/******************************************************************************/
static inline void calc_park_angle(void)
{
    uint32_t pos;
    float position_elec;

    if(ctrl_param.OpenLoop == true)
    {
        /* begin with the lock sequence, for field alignment */
        if (startup_lock_count < LOCK_COUNT_FOR_LOCK_TIME)
        {
            startup_lock_count++;
            rotor_angle_rad_per_sec = M_PI;
        }
        else
        {
            if(startup_lock_count < 2*LOCK_COUNT_FOR_LOCK_TIME)
            {
                startup_lock_count++;
                rotor_angle_rad_per_sec = (3*M_PI_2);
            }
            else
            {
            /* switch to close loop */
            ctrl_param.ChangeMode = true;
            ctrl_param.OpenLoop = false;
            /* Start QDEC timer */
            TC0_QuadratureStart();
            /* the angle set after alignment */
            rotor_angle_rad_per_sec = 0;
            }
        }
    }
    else
    {
        /* Switched to closed loop..*/
        encoder_pulse_count_int16_t = (int16_t)(TC0_REGS->TC_CHANNEL[0].TC_CV);
        position_elec = (float)encoder_pulse_count_int16_t;
        if(position_elec >= 0)
        {
            pos = fmod(position_elec,ENCODER_PULSES_PER_EREV);
            rotor_angle_rad_per_sec = pos * (2 * M_PI/ENCODER_PULSES_PER_EREV);
        }
        else
        {
            pos= fmod((-position_elec),ENCODER_PULSES_PER_EREV);
            rotor_angle_rad_per_sec = (ENCODER_PULSES_PER_EREV - pos) * (2 * M_PI/ENCODER_PULSES_PER_EREV);
        }
    }

    /* Limit rotor angle range to 0 to 2*M_PI for lookup table */
    if(rotor_angle_rad_per_sec > (2*M_PI))
    {
      park_param.Angle = rotor_angle_rad_per_sec - (2*M_PI);
    }
    else if(rotor_angle_rad_per_sec < 0)
    {
      park_param.Angle = 2*M_PI + rotor_angle_rad_per_sec;
    }
    else
    {
      park_param.Angle = rotor_angle_rad_per_sec;
    }
}

/******************************************************************************/
/* Function name: phase_current_offset_calib                                  */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description: Measures motor phase current offsets.Limits the offset if it  */
/*              exceeds the predetermined range.                              */
/******************************************************************************/

float phaseCurrentUOffset;
float phaseCurrentVOffset;

static void phase_current_offset_calib(void)
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
/* Function name: init_pi                                                     */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description: Initialize PI structure                                       */
/******************************************************************************/
void init_pi( tPIParm *pParm)
{
    pParm->dSum = 0;
    pParm->Out = 0;
}

/******************************************************************************/
/* Function name: init_pi_ctrl_param                                          */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description:                                                               */
/* Initialize control parameters: PI coefficients for D,Q and                 */
/* Velocity control loop.                                                     */
/******************************************************************************/
void init_pi_ctrl_param(void)
{
    /**************** PI D Term ***********************************************/
    PIParmD.Kp = D_CURRCNTR_PTERM;
    PIParmD.Ki = D_CURRCNTR_ITERM;
    PIParmD.Kc = D_CURRCNTR_CTERM;
    PIParmD.OutMax = D_CURRCNTR_OUTMAX;
    PIParmD.OutMin = -D_CURRCNTR_OUTMAX;

    init_pi(&PIParmD);

    /**************** PI Q Term ************************************************/
    PIParmQ.Kp = Q_CURRCNTR_PTERM;
    PIParmQ.Ki = Q_CURRCNTR_ITERM;
    PIParmQ.Kc = Q_CURRCNTR_CTERM;
    PIParmQ.OutMax = Q_CURRCNTR_OUTMAX;
    PIParmQ.OutMin = 0;

    init_pi(&PIParmQ);

    /**************** PI Velocity Control **************************************/
    PIParmQref.Kp = SPEEDCNTR_PTERM;
    PIParmQref.Ki = SPEEDCNTR_ITERM;
    PIParmQref.Kc = SPEEDCNTR_CTERM;
    PIParmQref.OutMax = SPEEDCNTR_OUTMAX;
    PIParmQref.OutMin = -SPEEDCNTR_OUTMAX;

    init_pi(&PIParmQref);
}

/******************************************************************************/
/* Function name: motor_ctrl_var_init                                         */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description: Initialize control loop variables.                            */
/******************************************************************************/
static void motor_ctrl_var_init(void)
{
    /* Parameter initialization for FOC */
    init_pi_ctrl_param();

    ctrl_param.OpenLoop = true;
    ctrl_param.ChangeMode = false;
    startup_lock_count = 0;
    SincosParm.Angle = 0;
    svm_gen_param.PWMPeriod = MAX_DUTY;
    ctrl_param.MotorStatus = MOTOR_STATUS_STOPPED;
    park_param.Id = 0;
    park_param.Iq = 0;
    ctrl_param.RampIncStep = SPEED_RAMP_INC_SLOW_LOOP;
    init_pi(&PIParmD);
    init_pi(&PIParmQ);
    init_pi(&PIParmQref);

    rotor_angle_rad_per_sec = 0;
    elec_rotation_count = 0;
    prev_position_count = 0;
    present_position_count = 0;
    encoder_pulse_count_int16_t = 0;
}

/******************************************************************************/
/* Function name: execute_slow_ctrl_loop                                      */
/* Function parameters: None                                                  */
/* Function return: Bool( True - executes slow control loop )                 */
/* Description: To be used in a while loop; It returns true                   */
/******************************************************************************/
static inline bool execute_slow_ctrl_loop(void)
{
    uint8_t retval = false;
    if(SLOW_LOOP_TIME_PWM_COUNT <= sync_cnt)
    {
        sync_cnt = 0;
        retval = true;
    }
    return( retval );
}

#if(TORQUE_MODE == false)
/******************************************************************************/
/* Function name: speed_ramp                                                  */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description: Increment/Decrements speed reference based upon ramp          */
/*              configuration in "userparams.h" file.                         */
/******************************************************************************/
static inline void speed_ramp(void)
{
    if(ctrl_param.EndSpeed > (ctrl_param.VelRef + ctrl_param.RampIncStep))
    {
        ctrl_param.VelRef += ctrl_param.RampIncStep;
    }
    else if(ctrl_param.EndSpeed < (ctrl_param.VelRef - ctrl_param.RampIncStep))
    {
        ctrl_param.VelRef -= ctrl_param.RampIncStep;
    }
    else
    {
        ctrl_param.VelRef = ctrl_param.EndSpeed;
    }
}
#endif

/******************************************************************************/
/* Function name: calc_times                                                  */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description: Calculates time to apply vector a,b,c                         */
/******************************************************************************/
static inline void calc_times(void)
{
    T1 = (svm_gen_param.PWMPeriod) * T1;
    T2 = (svm_gen_param.PWMPeriod) * T2;
    T_c = (svm_gen_param.PWMPeriod - T1-T2)/2;
    T_b = T_c + T2;
    T_a = T_b + T1;
}

/******************************************************************************/
/* Function name: calc_svm_gen                                                */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description: Determines sector based upon three reference vectors amplitude*/
/*              and updates duty.                                             */
/******************************************************************************/
static inline void calc_svm_gen( void )
{
    if( svm_gen_param.Vr1 >= 0 )
    {
        // (xx1)
        if( svm_gen_param.Vr2 >= 0 )
        {
            // (x11)
            // Must be Sector 3 since Sector 7 not allowed
            // Sector 3: (0,1,1)  0-60 degrees
            T1 = svm_gen_param.Vr2;
            T2 = svm_gen_param.Vr1;
            calc_times();
            dPWM1 = (uint32_t)T_a;
            dPWM2 = (uint32_t)T_b;
            dPWM3 = (uint32_t)T_c;
        }
        else
        {
            // (x01)
            if( svm_gen_param.Vr3 >= 0 )
            {
                // Sector 5: (1,0,1)  120-180 degrees
                T1 = svm_gen_param.Vr1;
                T2 = svm_gen_param.Vr3;
                calc_times();
                dPWM1 = (uint32_t)T_c;
                dPWM2 = (uint32_t)T_a;
                dPWM3 = (uint32_t)T_b;

            }
            else
            {
                // Sector 1: (0,0,1)  60-120 degrees
                T1 = -svm_gen_param.Vr2;
                T2 = -svm_gen_param.Vr3;
                calc_times();
                dPWM1 = (uint32_t)T_b;
                dPWM2 = (uint32_t)T_a;
                dPWM3 = (uint32_t)T_c;
            }
        }
    }
    else
    {
        // (xx0)
        if( svm_gen_param.Vr2 >= 0 )
        {
            // (x10)
            if( svm_gen_param.Vr3 >= 0 )
            {
                // Sector 6: (1,1,0)  240-300 degrees
                T1 = svm_gen_param.Vr3;
                T2 = svm_gen_param.Vr2;
                calc_times();
                dPWM1 = (uint32_t)T_b;
                dPWM2 = (uint32_t)T_c;
                dPWM3 = (uint32_t)T_a;
            }
            else
            {
                // Sector 2: (0,1,0)  300-0 degrees
                T1 = -svm_gen_param.Vr3;
                T2 = -svm_gen_param.Vr1;
                calc_times();
                dPWM1 = (uint32_t)T_a;
                dPWM2 = (uint32_t)T_c;
                dPWM3 = (uint32_t)T_b;
            }
        }
        else
        {
            // (x00)
            // Must be Sector 4 since Sector 0 not allowed
            // Sector 4: (1,0,0)  180-240 degrees
            T1 = -svm_gen_param.Vr1;
            T2 = -svm_gen_param.Vr2;
            calc_times();
            dPWM1 = (uint32_t)T_c;
            dPWM2 = (uint32_t)T_b;
            dPWM3 = (uint32_t)T_a;
        }
    }
}

/******************************************************************************/
/* Function name: calc_ref_vector                                             */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description: Inverse Clarke Transformation                                 */
/******************************************************************************/
static inline void calc_ref_vector(void)
{
    svm_gen_param.Vr1 = park_param.Vbeta;
    svm_gen_param.Vr2 = (-park_param.Vbeta/2 + SQRT3_BY2 * park_param.Valpha);
    svm_gen_param.Vr3 = (-park_param.Vbeta/2 - SQRT3_BY2 * park_param.Valpha);
}

/******************************************************************************/
/* Function name: update_duty                                                 */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description: Configure duty cycle of WPM channels based on control loop    */
/******************************************************************************/
static inline void update_duty(uint32_t duty_PhU,uint32_t duty_PhV,uint32_t duty_PhW)
{
    PWM0_ChannelDutySet(PWM_CHANNEL_0, duty_PhU);
    PWM0_ChannelDutySet(PWM_CHANNEL_1, duty_PhV);
    PWM0_ChannelDutySet(PWM_CHANNEL_2, duty_PhW);
}

/******************************************************************************/
/* Function name: afec_eoc_isr                                                *
 * Function parameters: None                                                  *
 * Function return: None                                                      *
 * Description: ADC end of conversion interrupt is used for executing fast    *
 *              control loop. Angle is obtained from quadrature encoder.      *
 * ISR Timings -                                                              *
 *               Flash + Cache       - 2.84us  - Optimization -O1             *
 ******************************************************************************/

void afec_eoc_isr(uintptr_t context)
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
    park_param.Iu = phaseCurrentU * ADC_CURRENT_SCALE;
    park_param.Iv = phaseCurrentV * ADC_CURRENT_SCALE;
    #else
    park_param.Iv = phaseCurrentU * ADC_CURRENT_SCALE;
    park_param.Iu = phaseCurrentV * ADC_CURRENT_SCALE;
    #endif

    /* Clarke transform */
    clarke_transform();

    /* Park transform */
    park_transform();

    /* Read DC bus voltage */
    dcBusVoltage = AFEC0_ChannelResultGet(DC_BUS_VOLTAGE_ADC_CH);
    park_param.DCBusVoltage = (float)(dcBusVoltage) * VOLTAGE_ADC_TO_PHY_RATIO;
    park_param.DCBusVoltageBySqrt3 = (float)(park_param.DCBusVoltage/SQRT3);

    /* Calculate control values  */
    do_control();

    /* Calculate park angle */
    calc_park_angle();

    SincosParm.Angle = park_param.Angle;

    /* Calculate qSin,qCos from qAngle  */
    sin_cos();

    park_param.Sin = SincosParm.Sin;
    park_param.Cos = SincosParm.Cos;

    /* Calculate qValpha, qVbeta from qSin,qCos,qVd,qVq */
    inv_park_transform();

    /* Calculate Vr1,Vr2,Vr3 from qValpha, qVbeta */
    calc_ref_vector();

    /* Calculate and set PWM duty cycles from Vr1,Vr2,Vr3 */
    calc_svm_gen();

    #if(MOTOR_DIRECTION == MOTOR_DIRECTION_POSITIVE)
    update_duty(dPWM1, dPWM2, dPWM3);
    #else
    update_duty(dPWM2, dPWM1, dPWM3);
    #endif

    /* sync count for slow control loop execution */
    sync_cnt++;

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
void encoder_revolutions_isr(TC_QUADRATURE_STATUS quad_status, uintptr_t context)
{
    uint32_t status;
    elec_rotation_count++;
    status = TC0_REGS->TC_CHANNEL[0].TC_SR;
    (void)status;
}
/******************************************************************************/
/* Function name: slow_ctrl_loop                                              */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description: Slow control loop is in sync with fast control loop           */
/*              ADCEOCInterruptHandler().Slow loop execution frequency should */
/*              be in multiple of PWM frequency and be configured by          */
/*              "SLOW_LOOP_TIME_SEC" MACRO in "userparms.h file.              */
/*               Speed ramp and speed control loop is executed from this loop */
/******************************************************************************/
static inline void slow_ctrl_loop(void)
{

    #if(TORQUE_MODE == false)
    uint16_t rotations = 0;
    float pos_count_diff;
    float speed_elec_rad_per_sec;

    if(ctrl_param.OpenLoop == false)
    {
        /* Velocity reference will be taken from potentiometer. */
        float PotReading;
        PotReading = AFEC0_ChannelResultGet(POT_ADC_CH);
        speed_ref_filtered = speed_ref_filtered + ((PotReading - speed_ref_filtered) * KFILTER_POT );

        ctrl_param.EndSpeed = (float)((float)speed_ref_filtered * POT_ADC_COUNT_FW_SPEED_RATIO);

        /* Speed Ramp */
        speed_ramp();

        /* Speed Calculation from Encoder */
        present_position_count = (TC0_REGS->TC_CHANNEL[0].TC_CV);
        rotations = elec_rotation_count;
        elec_rotation_count = 0;
        pos_count_diff = present_position_count - prev_position_count;

        if(rotations > 0)
        pos_count_diff += rotations*ENCODER_PULSES_PER_EREV;

        prev_position_count = present_position_count;

        speed_elec_rad_per_sec = (pos_count_diff * 2*M_PI)/(ENCODER_PULSES_PER_EREV *SLOW_LOOP_TIME_SEC );

        /* Execute the velocity control loop */
        PIParmQref.InMeas = speed_elec_rad_per_sec;
        PIParmQref.InRef  = ctrl_param.VelRef;
        calc_pi(&PIParmQref);
        ctrl_param.IqRef = PIParmQref.Out;

    }
#endif	// End of #if(TORQUE_MODE == false)
}

/******************************************************************************/
/* Function name: motor_start                                                 */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description: Enables fast control loop and starts the PWM's.               */
/******************************************************************************/
void motor_start(void)
{
    /* Stop QDEC Timer */
    /* Initialize motor control variables */
    motor_ctrl_var_init();
    /* ADC end of conversion interrupt generation for FOC control */
    NVIC_DisableIRQ(AFEC0_IRQn);
    NVIC_ClearPendingIRQ(AFEC0_IRQn);
    NVIC_SetPriority(AFEC0_IRQn, 0);
    AFEC0_CallbackRegister(afec_eoc_isr, (uintptr_t)NULL);
    NVIC_EnableIRQ(AFEC0_IRQn);
    AFEC0_ChannelsInterruptEnable(AFEC_INTERRUPT_EOC_7_MASK);
    ((pio_registers_t*)PIO_PORT_D)->PIO_PDR = PIO_PDR_P24_Msk|PIO_PDR_P25_Msk|PIO_PDR_P26_Msk;                      // Enable PWML output.
    TC0_QuadratureCallbackRegister(encoder_revolutions_isr, (uintptr_t) NULL);
    ctrl_param.MotorStatus = MOTOR_STATUS_RUNNING;
    /* Clear fault before start */
    PWM0_FaultStatusClear(PWM_FAULT_ID_2);

    /* Enable PWM channels. */
    PWM0_ChannelsStart(PWM_CHANNEL_0_MASK);

    mc_appData.mcState = MC_APP_STATE_RUNNING;
}

/******************************************************************************/
/* Function name: motor_stop                                                  */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description: Stop's PWM and disables fast control loop.                    */
/******************************************************************************/
void motor_stop(void)
{

    ((pio_registers_t*)PIO_PORT_D)->PIO_PER = PIO_PER_P24_Msk|PIO_PER_P25_Msk|PIO_PER_P26_Msk;                            // Disable PWML output.

    /* Disables PWM channels. */
    PWM0_ChannelsStop(PWM_CHANNEL_0_MASK | PWM_CHANNEL_1_MASK | PWM_CHANNEL_2_MASK);

    /* Reset algorithm specific variables for next iteration.*/
    motor_ctrl_var_init();
    /* ADC end of conversion interrupt generation disabled */
    AFEC0_ChannelsInterruptDisable(AFEC_INTERRUPT_EOC_7_MASK);
    NVIC_DisableIRQ(AFEC0_IRQn);
    NVIC_ClearPendingIRQ(AFEC0_IRQn);
    TC0_QuadratureStop();
    ctrl_param.EndSpeed = 0;
    ctrl_param.VelRef = 0;
    ctrl_param.MotorStatus = MOTOR_STATUS_STOPPED;
    park_param.Angle = 0;
    mc_appData.mcState = MC_APP_STATE_STOP;
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
        mc_appData.switchCount++;
        if (mc_appData.switchCount >= 0xFF)
        {
           mc_appData.switchCount = 0;
           mc_appData.switchState = MC_APP_SWITCH_PRESSED;
        }
    }
    if (mc_appData.switchState == MC_APP_SWITCH_PRESSED)
    {
        if (SWITCH_Get())
        {
            mc_appData.switchCount = 0;
            mc_appData.switchState = MC_APP_SWITCH_RELEASED;
            mc_appData.mcState = state;

        }
    }

}


/******************************************************************************/
/* Function name: app_tasks                                                   */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description: Motor application state machine                               */
/******************************************************************************/
void app_tasks()
{
  switch (mc_appData.mcState)
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
          phase_current_offset_calib();
          mc_appData.switchCount = 0xFF;
          MCAPP_SwitchDebounce(MC_APP_STATE_START);
          break;

      case MC_APP_STATE_START:
          motor_start();
          mc_appData.mcState = MC_APP_STATE_RUNNING;
          break;

      case MC_APP_STATE_RUNNING:
          if(execute_slow_ctrl_loop())
          {
            slow_ctrl_loop();
          }
          MCAPP_SwitchDebounce(MC_APP_STATE_STOP);
          break;

      case MC_APP_STATE_STOP:
          motor_stop();
          MCAPP_SwitchDebounce(MC_APP_STATE_START);
          break;

      default:
          break;
  }


}

