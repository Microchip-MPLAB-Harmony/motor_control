/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    mclib_generic_float.c

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
#include "mclib_generic_float.h"
#include "userparams.h"
#include "X2CScope.h"
#include "X2CScopeCommunication.h"
#include "math.h"
/******************************************************************************/
/* Local Function Prototype                                                   */
/******************************************************************************/

__STATIC_INLINE void MCLIB_SVPWMTimeCalc(MCLIB_SVPWM* svm);

/******************************************************************************/
/*                   Global Variables                                         */
/******************************************************************************/

MCLIB_PI                gPIParmQ;        /* Iq PI controllers */
MCLIB_PI                gPIParmD;        /* Id PI controllers */
MCLIB_PI                gPIParmQref;     /* Speed PI controllers */
MCLIB_I_ABC             gMCLIBCurrentABC;
MCLIB_I_ALPHA_BETA      gMCLIBCurrentAlphaBeta;
MCLIB_I_DQ              gMCLIBCurrentDQ;
MCLIB_POSITION          gMCLIBPosition;
MCLIB_V_DQ              gMCLIBVoltageDQ;
MCLIB_V_ALPHA_BETA      gMCLIBVoltageAlphaBeta;
MCLIB_SVPWM             gMCLIBSVPWM;

/******************************************************************************/
/*                   SIN Table  256  -  0.0244rad resolution                  */
/******************************************************************************/
float sineTable[TABLE_SIZE] =
// <editor-fold defaultstate="collapsed" desc="Sine Table">
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
// </editor-fold>
/******************************************************************************/
/*                   COS Table  -  0.0244rad resolution                       */
/******************************************************************************/
float cosineTable[TABLE_SIZE] =
// <editor-fold defaultstate="collapsed" desc="Cosine Table">
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

/******************************************************************************/
/* Function name: MCLIB_ClarkeTransform                                                      */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description: Clarke Transformation                                         */
/******************************************************************************/
 void MCLIB_ClarkeTransform(MCLIB_I_ABC* input, MCLIB_I_ALPHA_BETA* output)
{
    output->iAlpha = input->ia;
    output->iBeta = (input->ia * ONE_BY_SQRT3) + (input->ib * TWO_BY_SQRT3);
}

/******************************************************************************/
/* Function name: MCLIB_ParkTransform                                                        */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description: Park Transformation.                                          */
/******************************************************************************/
 void MCLIB_ParkTransform(MCLIB_I_ALPHA_BETA* input, MCLIB_POSITION* position, MCLIB_I_DQ* output)
{
    output->id =  gMCLIBCurrentAlphaBeta.iAlpha * position->cosAngle
                        + gMCLIBCurrentAlphaBeta.iBeta * position->sineAngle;
  	output->iq = -gMCLIBCurrentAlphaBeta.iAlpha * position->sineAngle
                        + gMCLIBCurrentAlphaBeta.iBeta * position->cosAngle;
}

/******************************************************************************/
/* Function name: MCLIB_InvParkTransform                                                     */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description: Inverse Park Transformation.                                  */
/******************************************************************************/
void MCLIB_InvParkTransform(MCLIB_V_DQ* input, MCLIB_POSITION* position, MCLIB_V_ALPHA_BETA* output)
{
    output->vAlpha =  input->vd * position->cosAngle - input->vq * position->sineAngle;
    output->vBeta  =  input->vd * position->sineAngle + input->vq * position->cosAngle;
}

/******************************************************************************/
/* Function name: MCLIB_SinCosCalc                                                      */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description: Calculates the sin and cosine of angle based upon             */
/*              interpolation technique from the table.                       */
/******************************************************************************/
 void MCLIB_SinCosCalc(MCLIB_POSITION* position )
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

    y0_Index = (uint32_t)(position->angle / ANGLE_STEP);
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
    temp = ((position->angle - x0) / (x1 - x0));
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
/* Function name: MCLIB_PIControl                                                   */
/* Function parameters: pParm - PI parameter structure                                                  */
/* Function return: None                                                      */
/* Description:                                                               */
/* Execute PI control                                                         */
/******************************************************************************/
 void MCLIB_PIControl( MCLIB_PI *pParm)
{
	float Err;
	float Out;
	float Exc;

	Err  = pParm->inRef - pParm->inMeas;
	Out  = pParm->dSum + pParm->kp * Err;

	/* Limit checking for PI output */
	if( Out > pParm->outMax )
        pParm->out = pParm->outMax;
	else if( Out < pParm->outMin )
        pParm->out = pParm->outMin;
	else
        pParm->out = Out;

	Exc = Out - pParm->out;
	pParm->dSum = pParm->dSum + pParm->ki * Err - pParm->kc * Exc;
}

/******************************************************************************/
/* Function name: MCLIB_SVPWMTimeCalc                                                   */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description: Calculates time to apply vector a,b,c                         */
/******************************************************************************/
__STATIC_INLINE void MCLIB_SVPWMTimeCalc(MCLIB_SVPWM* svm)
{
    svm->t1 = (gMCLIBSVPWM.period) * svm->t1;
    svm->t2 = (gMCLIBSVPWM.period) * svm->t2;
    svm->t_c = (gMCLIBSVPWM.period - svm->t1 - svm->t2)/2;
    svm->t_b = svm->t_c + svm->t2;
    svm->t_a = svm->t_b + svm->t1;
}

/******************************************************************************/
/* Function name: MCLIB_SVPWMGen                                                   */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description: Determines sector based upon three reference vectors amplitude*/
/*              and updates duty.                                             */
/******************************************************************************/
 void MCLIB_SVPWMGen( MCLIB_V_ALPHA_BETA* vAlphaBeta, MCLIB_SVPWM* svm )
{
    svm->vr1 = vAlphaBeta->vBeta;
    svm->vr2 = (-vAlphaBeta->vBeta/2 + SQRT3_BY2 * vAlphaBeta->vAlpha);
    svm->vr3 = (-vAlphaBeta->vBeta/2 - SQRT3_BY2 * vAlphaBeta->vAlpha);

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


/*******************************************************************************
 End of File
*/
