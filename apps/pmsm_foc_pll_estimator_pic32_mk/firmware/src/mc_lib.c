/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    mc_lib.c

  Summary:
    This file contains the motor control algorithm functions.

  Description:
    This file contains the motor control algorithm functions like clarke transform,
    park transform. This library is implemented with float data type.
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
#include "mc_currMeasurement.h"
#include "mc_lib.h"
#include "userparams.h"
#include "X2CScope.h"
#include "X2CScopeCommunication.h"
#include "math.h"
/******************************************************************************/
/* Local Function Prototype                                                   */
/******************************************************************************/

__STATIC_INLINE void MCLIB_SVPWMTimeCalc(tMCLIB_SVPWM_S* svm);

/******************************************************************************/
/*                   Global Variables                                         */
/******************************************************************************/

tMCLIB_CLARK_TRANSFORM_S            gMCLIB_CurrentAlphaBeta = {0.0f, 0.0f};
tMCLIB_PARK_TRANSFORM_S              gMCLIB_CurrentDQ = {0.0f, 0.0f};
tMCLIB_POSITION_S                            gMCLIB_Position = {0.0f, 0.0f, 1.0f };
tMCLIB_PARK_TRANSFORM_S              gMCLIB_VoltageDQ = {0.0f, 0.0f};
tMCLIB_CLARK_TRANSFORM_S            gMCLIB_VoltageAlphaBeta = {0.0f, 0.0f};
tMCLIB_SVPWM_S                                  gMCLIB_SVPWM = {0.0f};
tMCLIB_BUTTON_STATE_S                  gMCLIB_StartStopState;
tMCLIB_BUTTON_STATE_S                  gMCLIB_DirectionToggleState;

/******************************************************************************/
/*                   SIN Table  256  -  0.0244rad resolution                            */
/******************************************************************************/
float sineTable[TABLE_SIZE] =
// <editor-fold defaultstate="collapsed" desc="Sine Table">
{
    0.000000,  0.024541,  0.049068,  0.073565,  0.098017,  0.122411,  0.146730,  0.170962,
    0.195090,  0.219101,  0.242980,  0.266713,  0.290285,  0.313682,  0.336890,  0.359895,
    0.382683,  0.405241,  0.427555,  0.449611,  0.471397,  0.492898,  0.514103,  0.534998,
    0.555570,  0.575808,  0.595699,  0.615232,  0.634393,  0.653173,  0.671559,  0.689541,
    0.707107,  0.724247,  0.740951,  0.757209,  0.773010,  0.788346,  0.803208,  0.817585,
    0.831470,  0.844854,  0.857729,  0.870087,  0.881921,  0.893224,  0.903989,  0.914210,
    0.923880,  0.932993,  0.941544,  0.949528,  0.956940,  0.963776,  0.970031,  0.975702,
    0.980785,  0.985278,  0.989177,  0.992480,  0.995185,  0.997290,  0.998795,  0.999699,
    1.000000,  0.999699,  0.998795,  0.997290,  0.995185,  0.992480,  0.989177,  0.985278,
    0.980785,  0.975702,  0.970031,  0.963776,  0.956940,  0.949528,  0.941544,  0.932993,
    0.923880,  0.914210,  0.903989,  0.893224,  0.881921,  0.870087,  0.857729,  0.844854,
    0.831470,  0.817585,  0.803208,  0.788346,  0.773010,  0.757209,  0.740951,  0.724247,
    0.707107,  0.689541,  0.671559,  0.653173,  0.634393,  0.615232,  0.595699,  0.575808,
    0.555570,  0.534998,  0.514103,  0.492898,  0.471397,  0.449611,  0.427555,  0.405241,
    0.382683,  0.359895,  0.336890,  0.313682,  0.290285,  0.266713,  0.242980,  0.219101,
    0.195090,  0.170962,  0.146730,  0.122411,  0.098017,  0.073565,  0.049068,  0.024541,
    0.000000, -0.024541, -0.049068, -0.073565, -0.098017, -0.122411, -0.146730, -0.170962,
   -0.195090, -0.219101, -0.242980, -0.266713, -0.290285, -0.313682, -0.336890, -0.359895,
   -0.382683, -0.405241, -0.427555, -0.449611, -0.471397, -0.492898, -0.514103, -0.534998,
   -0.555570, -0.575808, -0.595699, -0.615232, -0.634393, -0.653173, -0.671559, -0.689541,
   -0.707107, -0.724247, -0.740951, -0.757209, -0.773010, -0.788346, -0.803208, -0.817585,
   -0.831470, -0.844854, -0.857729, -0.870087, -0.881921, -0.893224, -0.903989, -0.914210,
   -0.923880, -0.932993, -0.941544, -0.949528, -0.956940, -0.963776, -0.970031, -0.975702,
   -0.980785, -0.985278, -0.989177, -0.992480, -0.995185, -0.997290, -0.998795, -0.999699,
   -1.000000, -0.999699, -0.998795, -0.997290, -0.995185, -0.992480, -0.989177, -0.985278,
   -0.980785, -0.975702, -0.970031, -0.963776, -0.956940, -0.949528, -0.941544, -0.932993,
   -0.923880, -0.914210, -0.903989, -0.893224, -0.881921, -0.870087, -0.857729, -0.844854,
   -0.831470, -0.817585, -0.803208, -0.788346, -0.773010, -0.757209, -0.740951, -0.724247,
   -0.707107, -0.689541, -0.671559, -0.653173, -0.634393, -0.615232, -0.595699, -0.575808,
   -0.555570, -0.534998, -0.514103, -0.492898, -0.471397, -0.449611, -0.427555, -0.405241,
   -0.382683, -0.359895, -0.336890, -0.313682, -0.290285, -0.266713, -0.242980, -0.219101,
   -0.195090, -0.170962, -0.146730, -0.122411, -0.098017, -0.073565, -0.049068, -0.024541
};
// </editor-fold>
/******************************************************************************/
/*                   COS Table  -  0.0244rad resolution                                     */
/******************************************************************************/
float cosineTable[TABLE_SIZE] =
// <editor-fold defaultstate="collapsed" desc="Cosine Table">
{
    1.000000,  0.999699,  0.998795,  0.997290,  0.995185,  0.992480,  0.989177,  0.985278,
    0.980785,  0.975702,  0.970031,  0.963776,  0.956940,  0.949528,  0.941544,  0.932993,
    0.923880,  0.914210,  0.903989,  0.893224,  0.881921,  0.870087,  0.857729,  0.844854,
    0.831470,  0.817585,  0.803208,  0.788346,  0.773010,  0.757209,  0.740951,  0.724247,
    0.707107,  0.689541,  0.671559,  0.653173,  0.634393,  0.615232,  0.595699,  0.575808,
    0.555570,  0.534998,  0.514103,  0.492898,  0.471397,  0.449611,  0.427555,  0.405241,
    0.382683,  0.359895,  0.336890,  0.313682,  0.290285,  0.266713,  0.242980,  0.219101,
    0.195090,  0.170962,  0.146730,  0.122411,  0.098017,  0.073565,  0.049068,  0.024541,
    0.000000, -0.024541, -0.049068, -0.073565, -0.098017, -0.122411, -0.146730, -0.170962,
   -0.195090, -0.219101, -0.242980, -0.266713, -0.290285, -0.313682, -0.336890, -0.359895,
   -0.382683, -0.405241, -0.427555, -0.449611, -0.471397, -0.492898, -0.514103, -0.534998,
   -0.555570, -0.575808, -0.595699, -0.615232, -0.634393, -0.653173, -0.671559, -0.689541,
   -0.707107, -0.724247, -0.740951, -0.757209, -0.773010, -0.788346, -0.803208, -0.817585,
   -0.831470, -0.844854, -0.857729, -0.870087, -0.881921, -0.893224, -0.903989, -0.914210,
   -0.923880, -0.932993, -0.941544, -0.949528, -0.956940, -0.963776, -0.970031, -0.975702,
   -0.980785, -0.985278, -0.989177, -0.992480, -0.995185, -0.997290, -0.998795, -0.999699,
   -1.000000, -0.999699, -0.998795, -0.997290, -0.995185, -0.992480, -0.989177, -0.985278,
   -0.980785, -0.975702, -0.970031, -0.963776, -0.956940, -0.949528, -0.941544, -0.932993,
   -0.923880, -0.914210, -0.903989, -0.893224, -0.881921, -0.870087, -0.857729, -0.844854,
   -0.831470, -0.817585, -0.803208, -0.788346, -0.773010, -0.757209, -0.740951, -0.724247,
   -0.707107, -0.689541, -0.671559, -0.653173, -0.634393, -0.615232, -0.595699, -0.575808,
   -0.555570, -0.534998, -0.514103, -0.492898, -0.471397, -0.449611, -0.427555, -0.405241,
   -0.382683, -0.359895, -0.336890, -0.313682, -0.290285, -0.266713, -0.242980, -0.219101,
   -0.195090, -0.170962, -0.146730, -0.122411, -0.098017, -0.073565, -0.049068, -0.024541,
    0.000000,  0.024541,  0.049068,  0.073565,  0.098017,  0.122411,  0.146730,  0.170962,
    0.195090,  0.219101,  0.242980,  0.266713,  0.290285,  0.313682,  0.336890,  0.359895,
    0.382683,  0.405241,  0.427555,  0.449611,  0.471397,  0.492898,  0.514103,  0.534998,
    0.555570,  0.575808,  0.595699,  0.615232,  0.634393,  0.653173,  0.671559,  0.689541,
    0.707107,  0.724247,  0.740951,  0.757209,  0.773010,  0.788346,  0.803208,  0.817585,
    0.831470,  0.844854,  0.857729,  0.870087,  0.881921,  0.893224,  0.903989,  0.914210,
    0.923880,  0.932993,  0.941544,  0.949528,  0.956940,  0.963776,  0.970031,  0.975702,
    0.980785,  0.985278,  0.989177,  0.992480,  0.995185,  0.997290,  0.998795,  0.999699
};
// </editor-fold>
/******************************************************************************/
/* Function name: MCLIB_ClarkeTransform                                       */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description: Clarke Transformation                                         */
/******************************************************************************/
 void MCLIB_ClarkeTransform(const tPHASE_CURRENTS_S * const  input, tMCLIB_CLARK_TRANSFORM_S * const output)
{
    output->alphaAxis = input->iu;
    output->betaAxis = (input->iu * ONE_BY_SQRT3) + (input->iv * TWO_BY_SQRT3);
}

/*****************************************************************************/
/* Function name: MCLIB_ParkTransform                                        */
/* Function parameters: None                                                 */
/* Function return: None                                                     */
/* Description: Park Transformation.                                         */
/******************************************************************************/
void MCLIB_ParkTransform( const tMCLIB_CLARK_TRANSFORM_S * const input, const tMCLIB_POSITION_S * const position, tMCLIB_PARK_TRANSFORM_S * const output)
{
    output->directAxis =  gMCLIB_CurrentAlphaBeta.alphaAxis * position->cosAngle
                        + gMCLIB_CurrentAlphaBeta.betaAxis * position->sineAngle;
    output->quadratureAxis = -gMCLIB_CurrentAlphaBeta.alphaAxis * position->sineAngle
                        + gMCLIB_CurrentAlphaBeta.betaAxis * position->cosAngle;
}

/******************************************************************************/
/* Function name: MCLIB_InvParkTransform                                      */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description: Inverse Park Transformation.                                  */
/******************************************************************************/
 void MCLIB_InvParkTransform(const tMCLIB_PARK_TRANSFORM_S * const input, const tMCLIB_POSITION_S * const position, tMCLIB_CLARK_TRANSFORM_S * const output)
{
    output->alphaAxis =  input->directAxis * position->cosAngle - input->quadratureAxis * position->sineAngle;
    output->betaAxis  =  input->directAxis * position->sineAngle + input->quadratureAxis * position->cosAngle;
}

/******************************************************************************/
/* Function name: MCLIB_SinCosCalc                                            */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description: Calculates the sin and cosine of angle based upon             */
/*              interpolation technique from the table.                       */
/******************************************************************************/
void MCLIB_SinCosCalc( tMCLIB_POSITION_S * const position )
{
    /*
       Since we are using "float", it is not possible to get an index of array
       directly. Almost every time, we will need to do interpolation, as per
       following equation: -
       y = y0 + (y1 - y0)*((x - x0)/(x1 - x0)) */

    uint32_t y0_Index;
    uint32_t y0_IndexNext;
    float x0, y0, y1, temp;

    // Software check to ensure  0 <= Angle < 2*PI
    if( position->angle <  0 )
    {
        position->angle = position->angle + TOTAL_SINE_TABLE_ANGLE;
    }

    if( position->angle >= TOTAL_SINE_TABLE_ANGLE  )
    {
        position->angle = position->angle - TOTAL_SINE_TABLE_ANGLE;
    }


    y0_Index = (uint32_t)(position->angle / ANGLE_STEP);
    y0_IndexNext = y0_Index + 1;

    if(y0_IndexNext >= TABLE_SIZE )
    {
        y0_IndexNext = 0;
    }

    x0 = (y0_Index * ANGLE_STEP);

    /* Since below calculation is same for sin & cosine, we can do it once and reuse. */
    temp = ((position->angle - x0) * ONE_BY_ANGLE_STEP);

    /*==============  Find Sine now  =============================================*/
    y0 = sineTable[y0_Index];
    y1 = sineTable[y0_IndexNext];
    position->sineAngle = y0 + ((y1 - y0) * temp);

   /*==============  Find Cosine now  =============================================*/
    y0 = cosineTable[y0_Index];
    y1 = cosineTable[y0_IndexNext];
    position->cosAngle = y0 + ((y1 - y0) * temp);

}

/******************************************************************************/
/* Function name: MCLIB_SVPWMTimeCalc                                         */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description: Calculates time to apply vector a,b,c                         */
/******************************************************************************/
__STATIC_INLINE void MCLIB_SVPWMTimeCalc(tMCLIB_SVPWM_S * const svm)
{
    svm->t1 = (gMCLIB_SVPWM.period) * svm->t1;
    svm->t2 = (gMCLIB_SVPWM.period) * svm->t2;
    svm->t_c = (gMCLIB_SVPWM.period - svm->t1 - svm->t2)/2;
    svm->t_b = svm->t_c + svm->t2;
    svm->t_a = svm->t_b + svm->t1;
}

/******************************************************************************/
/* Function name: MCLIB_SVPWMGen                                              */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description: Determines sector based upon three reference                  */
/*              vectors amplitude and updates duty.                           */
/******************************************************************************/
void MCLIB_SVPWMGen( const tMCLIB_CLARK_TRANSFORM_S * const vAlphaBeta, tMCLIB_SVPWM_S * const svm )
{
    svm->vr1 = vAlphaBeta->betaAxis;
    svm->vr2 = (-vAlphaBeta->betaAxis/2 + SQRT3_BY2 * vAlphaBeta->alphaAxis);
    svm->vr3 = (-vAlphaBeta->betaAxis/2 - SQRT3_BY2 * vAlphaBeta->alphaAxis);

  	if( svm->vr1 >= 0 )
  	{
    		// (xx1)
    		if( svm->vr2 >= 0 )
    		{
      			// (x11)
      			// Must be Sector 3 since Sector 7 not allowed
      			// Sector 3: (0,1,1)  0-60 degrees
      			svm->t1 = svm->vr2;
      			svm->t2 = svm->vr1;
      			MCLIB_SVPWMTimeCalc(svm);
      			svm->dPWM1 = (uint32_t)svm->t_a;
      			svm->dPWM2 = (uint32_t)svm->t_b;
      			svm->dPWM3 = (uint32_t)svm->t_c;
    		}
    		else
    		{
      			// (x01)
      			if( svm->vr3 >= 0 )
      			{
        				// Sector 5: (1,0,1)  120-180 degrees
        				svm->t1 = svm->vr1;
        				svm->t2 = svm->vr3;
        				MCLIB_SVPWMTimeCalc(svm);
        				svm->dPWM1 = (uint32_t)svm->t_c;
        				svm->dPWM2 = (uint32_t)svm->t_a;
        				svm->dPWM3 = (uint32_t)svm->t_b;
    		  	}
      			else
      			{
        				// Sector 1: (0,0,1)  60-120 degrees
        				svm->t1 = -svm->vr2;
        				svm->t2 = -svm->vr3;
        				MCLIB_SVPWMTimeCalc(svm);
        				svm->dPWM1 = (uint32_t)svm->t_b;
        				svm->dPWM2 = (uint32_t)svm->t_a;
        				svm->dPWM3 = (uint32_t)svm->t_c;
      			}
  	     }
  	}
  	else
  	{
    		// (xx0)
    		if( svm->vr2 >= 0 )
    		{
      			// (x10)
      			if( svm->vr3 >= 0 )
      			{
        				// Sector 6: (1,1,0)  240-300 degrees
        				svm->t1 = svm->vr3;
        				svm->t2 = svm->vr2;
        				MCLIB_SVPWMTimeCalc(svm);
        				svm->dPWM1 = (uint32_t)svm->t_b;
        				svm->dPWM2 = (uint32_t)svm->t_c;
        				svm->dPWM3 = (uint32_t)svm->t_a;
      			}
      			else
      			{
        				// Sector 2: (0,1,0)  300-0 degrees
        				svm->t1 = -svm->vr3;
        				svm->t2 = -svm->vr1;
        				MCLIB_SVPWMTimeCalc(svm);
        				svm->dPWM1 = (uint32_t)svm->t_a;
        				svm->dPWM2 = (uint32_t)svm->t_c;
        				svm->dPWM3 = (uint32_t)svm->t_b;
      			}
  	  	}
    		else
    		{
      			// (x00)
      			// Must be Sector 4 since Sector 0 not allowed
      			// Sector 4: (1,0,0)  180-240 degrees
      			svm->t1 = -svm->vr1;
      			svm->t2 = -svm->vr2;
      			MCLIB_SVPWMTimeCalc(svm);
      			svm->dPWM1 = (uint32_t)svm->t_c;
      			svm->dPWM2 = (uint32_t)svm->t_b;
      			svm->dPWM3 = (uint32_t)svm->t_a;
    		}
  	}
}

/******************************************************************************/
/* Function name: MCLIB_WrapAngle                                             */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description:  Maps angle to [ 0, 2pi ] range                               */
/******************************************************************************/
void MCLIB_WrapAngle( float * const angle )
{
    if(*angle >= SINGLE_ELEC_ROT_RADS_PER_SEC)
    {
        *angle -= SINGLE_ELEC_ROT_RADS_PER_SEC;
    }
    else if( 0.0f > *angle )
    {
        *angle += SINGLE_ELEC_ROT_RADS_PER_SEC;
    }
    else
    {
       /* Do nothing */
    }
}

/******************************************************************************/
/* Function name: MCLIB_linearRamp                                            */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description:  linearly ramps input to final value                          */
/******************************************************************************/
void MCLIB_linearRamp(float * const input, const float stepSize, const float finalValue )
{
    if( (*input + stepSize ) <= finalValue )
    {
        *input += stepSize;
    }
    else if( (*input - stepSize ) >= finalValue )
    {
        *input -= stepSize;
    }
    else
    {
      *input = 0;
    }
}

/******************************************************************************/
/* Function name: MCLIB_ImposeLimits                                          */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description:  impose lower and upper limits                                */
/******************************************************************************/
void MCLIB_ImposeLimits( float * const input, const float lowerLimit, const float upperLimit )
{
    if( *input > upperLimit )
    {
        *input  = upperLimit;
    }
    else if( *input < lowerLimit )
    {
        *input  = lowerLimit;
    }
    else
    {
       /* Do nothing */ 
    }
   
}

/******************************************************************************/
/* Function name: MCLIB_ButtonResponse                                        */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description: Push button debounce function                                 */
/******************************************************************************/
void MCLIB_ButtonResponse( const tMCLIB_SWITCH_STATE_E  buttonState,  void (*buttonFunction)(void) )
{
    switch(gMCLIB_StartStopState.State)
    {
        case BUTTON_READY:
        {
            if( SWITCH_PRESSED == buttonState )
            {
                buttonFunction();
                gMCLIB_StartStopState.DebounceCounter = 0;
                gMCLIB_StartStopState.State = BUTTON_WAIT;
            }
        }
        break;
        
        case BUTTON_WAIT:
        {
            if( SW_DEBOUNCE_DLY_500MS <= gMCLIB_StartStopState.DebounceCounter)
            {
                gMCLIB_StartStopState.State = BUTTON_READY;
                gMCLIB_StartStopState.DebounceCounter = 0;
            }
            else 
            {
                gMCLIB_StartStopState.DebounceCounter++;
            }
        }
        break;
        default:
        {
              /* Should never come here */ 
        }
    }
}

/*******************************************************************************
 End of File
*/
