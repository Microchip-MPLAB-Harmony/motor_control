/*******************************************************************************
 Motor Control Library Filee - PLL Estimator

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

#include "mc_Lib.h"
#include <math.h>
extern mcParam_PIController     			mcApp_Q_PIParam;        						/* Parameters for Q axis Currrent PI Controller */
extern mcParam_PIController     			mcApp_D_PIParam;        						/* Parameters for D axis Currrent PI Controller */
extern mcParam_PIController     			mcApp_Speed_PIParam;     						/* Parameters for Speed PI Controller */
extern mcParam_FOC                          mcApp_focParam;   
extern mcParam_SinCos						mcApp_SincosParam;
extern mcParam_SVPWM 						mcApp_SVGenParam;
extern mcParam_ControlRef 					mcApp_ControlParam;

const float sineTable[TABLE_SIZE] = 
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
const float cosineTable[TABLE_SIZE] = 
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
// </editor-fold>


inline void mcLib_ClarkeTransform(mcParam_ABC *abcParam, mcParam_AlphaBeta *alphabetaParam)
{
    alphabetaParam->alpha = abcParam->a;
    alphabetaParam->beta = (abcParam->a * ONE_BY_SQRT3) + (abcParam->b * 2 * ONE_BY_SQRT3);
}

inline void mcLib_ParkTransform(mcParam_AlphaBeta *alphabetaParam , mcParam_SinCos *scParam, mcParam_DQ *dqParam)
{
    dqParam->d =  alphabetaParam->alpha*scParam->Cos + alphabetaParam->beta*scParam->Sin;
    dqParam->q = -alphabetaParam->alpha*scParam->Sin + alphabetaParam->beta*scParam->Cos;
}


// *****************************************************************************
// *****************************************************************************
// Section: MC Inverse Park Transform
// *****************************************************************************
// *****************************************************************************

inline void mcLib_InvParkTransform(mcParam_DQ *dqParam, mcParam_SinCos *scParam,mcParam_AlphaBeta *alphabetaParam)
{
    alphabetaParam->alpha =  dqParam->d*scParam->Cos - dqParam->q*scParam->Sin;
    alphabetaParam->beta  =  dqParam->d*scParam->Sin + dqParam->q*scParam->Cos;       
}

inline void mcLib_InitPI( mcParam_PIController *pParam)
{
    pParam->qdSum = 0;
    pParam->qOut = 0;
}

inline void mcLib_CalcPI( mcParam_PIController *pParam)
{
    float Err;
    float U;
    float Exc;
    
    Err  = pParam->qInRef - pParam->qInMeas;
    pParam->qErr =  Err; 
    U  = pParam->qdSum + pParam->qKp * Err;
   
    if( U > pParam->qOutMax )
    {
        pParam->qOut = pParam->qOutMax;
    }    
    else if( U < pParam->qOutMin )
    {
        pParam->qOut = pParam->qOutMin;
    }
    else        
    {
        pParam->qOut = U;  
    }
     
    Exc = U - pParam->qOut;
    pParam->qdSum = pParam->qdSum + pParam->qKi * Err - pParam->qKc * Exc;

}

// *****************************************************************************
// *****************************************************************************
// Section: MC Sine Cosine Functions
// *****************************************************************************
// *****************************************************************************

inline void mcLib_SinCosGen(mcParam_SinCos *scParam)
{
   
    // Since we are using "float", it is not possible to get an index of array
    // directly. Almost every time, we will need to do interpolation, as per
    // following equation: -
    // y = y0 + (y1 - y0)*((x - x0)/(x1 - x0))
    
    uint32_t y0_Index;
    uint32_t y0_IndexNext;
    float x0, y0, y1, temp;
    
    // Software check to ensure  0 <= Angle < 2*PI
     if(scParam->Angle <  0) 
        scParam->Angle = scParam->Angle + ANGLE_2PI; 
    if(scParam->Angle >= ANGLE_2PI)
        scParam->Angle = scParam->Angle - ANGLE_2PI; 
    
    y0_Index = (uint32_t)(scParam->Angle/ANGLE_STEP);
    
	//Added this condition which detects if y0_Index is >=256.
    //Earlier the only check was for y0_IndexNext. 
    //We observed y0_Index > = 256 when the code to reverse the direction of the motor was added
    if(y0_Index>=TABLE_SIZE)
    {
        y0_Index = 0;
        y0_IndexNext = 1;
        x0 = ANGLE_2PI;
        temp = 0;
    }
    else
    {
        y0_IndexNext = y0_Index + 1;
        if(y0_IndexNext >= TABLE_SIZE )
        {
            y0_IndexNext = 0;
        }
        else
        {

        }

        x0 = (y0_Index * ANGLE_STEP);  
    
    
    // Since below calculation is same for sin & cosine, we can do it once and reuse
    
	temp = ((scParam->Angle - x0)*ONE_BY_ANGLE_STEP);
    }
    
	// Find Sine now
    y0 = sineTable[y0_Index];
    y1 = sineTable[y0_IndexNext];     
   scParam->Sin = y0 + ((y1 - y0)*temp);
	
    // Find Cosine now
    y0 = cosineTable[y0_Index];
    y1 = cosineTable[y0_IndexNext];
    scParam->Cos = y0 + ((y1 - y0)*temp);
}

// *****************************************************************************
// *****************************************************************************
// Section: MC Space Vector Modulation Routines
// *****************************************************************************
// *****************************************************************************



inline void mcLib_SVPWMGen(mcParam_AlphaBeta *alphabetaParam, mcParam_SVPWM *svParam)
{

    //Modified inverse clarke transform which allows using instantaneous phase 
    // value to be used directly to calculate vector times.
    svParam->Vr1 = alphabetaParam->beta;
    svParam->Vr2 = (-alphabetaParam->beta/2 + SQRT3_BY2 * alphabetaParam->alpha);
    svParam->Vr3 = (-alphabetaParam->beta/2 - SQRT3_BY2 * alphabetaParam->alpha);     
    
    if( svParam->Vr1 >= 0 )
    {       
		// (xx1)
        if( svParam->Vr2 >= 0 )
        {
            // (x11)
            // Must be Sector 3 since Sector 7 not allowed
            // Sector 3: (0,1,1)  0-60 degrees
           svParam->T1 = svParam->Vr2;
            svParam->T2 = svParam->Vr1;
            mcLib_CalcTimes(svParam);
            svParam->dPWM_A = svParam->Ta;
            svParam->dPWM_B = svParam->Tb;
            svParam->dPWM_C = svParam->Tc;
        }
        else
        {            
            // (x01)
            if( svParam->Vr3 >= 0 )
            {
                // Sector 5: (1,0,1)  120-180 degrees
               svParam->T1 = svParam->Vr1;
               svParam->T2 = svParam->Vr3;
                mcLib_CalcTimes(svParam);
                svParam->dPWM_A = svParam->Tc;
                svParam->dPWM_B = svParam->Ta;
                svParam->dPWM_C = svParam->Tb;
            }
            else
            {
                // Sector 1: (0,0,1)  60-120 degrees
                svParam->T1 = -svParam->Vr2;
                svParam->T2 = -svParam->Vr3;
                mcLib_CalcTimes(svParam);
                svParam->dPWM_A = svParam->Tb;
                svParam->dPWM_B = svParam->Ta;
                svParam->dPWM_C = svParam->Tc;
            }
        }
    }
    else
    {
        // (xx0)
        if( svParam->Vr2 >= 0 )
        {
			// (x10)
            if( svParam->Vr3 >= 0 )
            {
                // Sector 6: (1,1,0)  240-300 degrees
                svParam->T1 = svParam->Vr3;
                svParam->T2 = svParam->Vr2;
                mcLib_CalcTimes(svParam);
                svParam->dPWM_A = svParam->Tb;
                svParam->dPWM_B = svParam->Tc;
                svParam->dPWM_C = svParam->Ta;
            }
            else
            {
                // Sector 2: (0,1,0)  300-0 degrees
                svParam->T1 = -svParam->Vr3;
                svParam->T2 = -svParam->Vr1;
                mcLib_CalcTimes(svParam);
                svParam->dPWM_A = svParam->Ta;
                svParam->dPWM_B = svParam->Tc;
                svParam-> dPWM_C = svParam->Tb;
            }
        }
        else
        {            
            // (x00)
            // Must be Sector 4 since Sector 0 not allowed
            // Sector 4: (1,0,0)  180-240 degrees
            svParam->T1 = -svParam->Vr1;
            svParam->T2 = -svParam->Vr2;
            mcLib_CalcTimes(svParam);
            svParam->dPWM_A = svParam->Tc;
            svParam->dPWM_B = svParam->Tb;
            svParam->dPWM_C = svParam->Ta;

        }
    }
}

inline void mcLib_CalcTimes(mcParam_SVPWM *svParam)
{
    svParam->T1 = svParam->PWMPeriod * svParam->T1;
    svParam->T2 = svParam->PWMPeriod * svParam->T2;
    svParam->Tc = (svParam->PWMPeriod- svParam->T1 - svParam->T2)/2;
    svParam->Tb = svParam->Tc + svParam->T2;
    svParam->Ta = svParam->Tb + svParam->T1;    
}  




