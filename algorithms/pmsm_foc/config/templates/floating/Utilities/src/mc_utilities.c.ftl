/*******************************************************************************
  Utility Functions

  Company:
    - Microchip Technology Inc

  File Name:
    - mc_utilitiesc

  Summary:
    - Utility Functions

  Description:
    - Utility Functions

 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
 * Copyright (C) 2022 Microchip Technology Inc and its subsidiaries
 *
 * Subject to your compliance with these terms, you may use Microchip software
 * and any derivatives exclusively with Microchip products. It is your
 * responsibility to comply with third party license terms applicable to your
 * use of third party software (including open source software) that may
 * accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS" NO WARRANTIES, WHETHER
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
 * PARTICULAR PURPOSE.
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE TO THE
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
 * ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
 * THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *******************************************************************************/
// DOM-IGNORE-END


/*******************************************************************************
Headers inclusions
 *******************************************************************************/

#include <math.h>
#include "definitions.h"
#include "mc_utilities.h"

/*******************************************************************************
Constants
*******************************************************************************/
#define  CONSTANT_Pi                                  (float32_t)3.14159265358979323846
#define  CONSTANT_2Pi                                (float32_t)( 2.0f * CONSTANT_Pi )
#define  CONSTANT_TotalSineAngleTable     (float32_t)( CONSTANT_2Pi )
#define  CONSTANT_SineTableSize              256u
#define  CONSTANT_AngleStep                     ( CONSTANT_TotalSineAngleTable/(float)CONSTANT_SineTableSize)
#define  CONSTANT_1ByAngleStep                (1.0f /CONSTANT_AngleStep)

#define RL_500MS_10MS    200u

/******************************************************************************
Private global variables
******************************************************************************/
/* Sine table */
const static float sineTable[CONSTANT_SineTableSize] =
// <editor-fold defaultstate="collapsed" desc="Sine Table">
{
    0.000000f,  0.024541f,  0.049068f,  0.073565f,  0.098017f,  0.122411f,  0.146730f,  0.170962f,
    0.195090f,  0.219101f,  0.242980f,  0.266713f,  0.290285f,  0.313682f,  0.336890f,  0.359895f,
    0.382683f,  0.405241f,  0.427555f,  0.449611f,  0.471397f,  0.492898f,  0.514103f,  0.534998f,
    0.555570f,  0.575808f,  0.595699f,  0.615232f,  0.634393f,  0.653173f,  0.671559f,  0.689541f,
    0.707107f,  0.724247f,  0.740951f,  0.757209f,  0.773010f,  0.788346f,  0.803208f,  0.817585f,
    0.831470f,  0.844854f,  0.857729f,  0.870087f,  0.881921f,  0.893224f,  0.903989f,  0.914210f,
    0.923880f,  0.932993f,  0.941544f,  0.949528f,  0.956940f,  0.963776f,  0.970031f,  0.975702f,
    0.980785f,  0.985278f,  0.989177f,  0.992480f,  0.995185f,  0.997290f,  0.998795f,  0.999699f,
    1.000000f,  0.999699f,  0.998795f,  0.997290f,  0.995185f,  0.992480f,  0.989177f,  0.985278f,
    0.980785f,  0.975702f,  0.970031f,  0.963776f,  0.956940f,  0.949528f,  0.941544f,  0.932993f,
    0.923880f,  0.914210f,  0.903989f,  0.893224f,  0.881921f,  0.870087f,  0.857729f,  0.844854f,
    0.831470f,  0.817585f,  0.803208f,  0.788346f,  0.773010f,  0.757209f,  0.740951f,  0.724247f,
    0.707107f,  0.689541f,  0.671559f,  0.653173f,  0.634393f,  0.615232f,  0.595699f,  0.575808f,
    0.555570f,  0.534998f,  0.514103f,  0.492898f,  0.471397f,  0.449611f,  0.427555f,  0.405241f,
    0.382683f,  0.359895f,  0.336890f,  0.313682f,  0.290285f,  0.266713f,  0.242980f,  0.219101f,
    0.195090f,  0.170962f,  0.146730f,  0.122411f,  0.098017f,  0.073565f,  0.049068f,  0.024541f,
    0.000000f, -0.024541f, -0.049068f, -0.073565f, -0.098017f, -0.122411f, -0.146730f, -0.170962f,
   -0.195090f, -0.219101f, -0.242980f, -0.266713f, -0.290285f, -0.313682f, -0.336890f, -0.359895f,
   -0.382683f, -0.405241f, -0.427555f, -0.449611f, -0.471397f, -0.492898f, -0.514103f, -0.534998f,
   -0.555570f, -0.575808f, -0.595699f, -0.615232f, -0.634393f, -0.653173f, -0.671559f, -0.689541f,
   -0.707107f, -0.724247f, -0.740951f, -0.757209f, -0.773010f, -0.788346f, -0.803208f, -0.817585f,
   -0.831470f, -0.844854f, -0.857729f, -0.870087f, -0.881921f, -0.893224f, -0.903989f, -0.914210f,
   -0.923880f, -0.932993f, -0.941544f, -0.949528f, -0.956940f, -0.963776f, -0.970031f, -0.975702f,
   -0.980785f, -0.985278f, -0.989177f, -0.992480f, -0.995185f, -0.997290f, -0.998795f, -0.999699f,
   -1.000000f, -0.999699f, -0.998795f, -0.997290f, -0.995185f, -0.992480f, -0.989177f, -0.985278f,
   -0.980785f, -0.975702f, -0.970031f, -0.963776f, -0.956940f, -0.949528f, -0.941544f, -0.932993f,
   -0.923880f, -0.914210f, -0.903989f, -0.893224f, -0.881921f, -0.870087f, -0.857729f, -0.844854f,
   -0.831470f, -0.817585f, -0.803208f, -0.788346f, -0.773010f, -0.757209f, -0.740951f, -0.724247f,
   -0.707107f, -0.689541f, -0.671559f, -0.653173f, -0.634393f, -0.615232f, -0.595699f, -0.575808f,
   -0.555570f, -0.534998f, -0.514103f, -0.492898f, -0.471397f, -0.449611f, -0.427555f, -0.405241f,
   -0.382683f, -0.359895f, -0.336890f, -0.313682f, -0.290285f, -0.266713f, -0.242980f, -0.219101f,
   -0.195090f, -0.170962f, -0.146730f, -0.122411f, -0.098017f, -0.073565f, -0.049068f, -0.024541f
};
// </editor-fold>

/* Cosine table */
const static float cosineTable[CONSTANT_SineTableSize] =
// <editor-fold defaultstate="collapsed" desc="Cosine Table">
{
    1.000000f,  0.999699f,  0.998795f,  0.997290f,  0.995185f,  0.992480f,  0.989177f,  0.985278f,
    0.980785f,  0.975702f,  0.970031f,  0.963776f,  0.956940f,  0.949528f,  0.941544f,  0.932993f,
    0.923880f,  0.914210f,  0.903989f,  0.893224f,  0.881921f,  0.870087f,  0.857729f,  0.844854f,
    0.831470f,  0.817585f,  0.803208f,  0.788346f,  0.773010f,  0.757209f,  0.740951f,  0.724247f,
    0.707107f,  0.689541f,  0.671559f,  0.653173f,  0.634393f,  0.615232f,  0.595699f,  0.575808f,
    0.555570f,  0.534998f,  0.514103f,  0.492898f,  0.471397f,  0.449611f,  0.427555f,  0.405241f,
    0.382683f,  0.359895f,  0.336890f,  0.313682f,  0.290285f,  0.266713f,  0.242980f,  0.219101f,
    0.195090f,  0.170962f,  0.146730f,  0.122411f,  0.098017f,  0.073565f,  0.049068f,  0.024541f,
    0.000000f, -0.024541f, -0.049068f, -0.073565f, -0.098017f, -0.122411f, -0.146730f, -0.170962f,
   -0.195090f, -0.219101f, -0.242980f, -0.266713f, -0.290285f, -0.313682f, -0.336890f, -0.359895f,
   -0.382683f, -0.405241f, -0.427555f, -0.449611f, -0.471397f, -0.492898f, -0.514103f, -0.534998f,
   -0.555570f, -0.575808f, -0.595699f, -0.615232f, -0.634393f, -0.653173f, -0.671559f, -0.689541f,
   -0.707107f, -0.724247f, -0.740951f, -0.757209f, -0.773010f, -0.788346f, -0.803208f, -0.817585f,
   -0.831470f, -0.844854f, -0.857729f, -0.870087f, -0.881921f, -0.893224f, -0.903989f, -0.914210f,
   -0.923880f, -0.932993f, -0.941544f, -0.949528f, -0.956940f, -0.963776f, -0.970031f, -0.975702f,
   -0.980785f, -0.985278f, -0.989177f, -0.992480f, -0.995185f, -0.997290f, -0.998795f, -0.999699f,
   -1.000000f, -0.999699f, -0.998795f, -0.997290f, -0.995185f, -0.992480f, -0.989177f, -0.985278f,
   -0.980785f, -0.975702f, -0.970031f, -0.963776f, -0.956940f, -0.949528f, -0.941544f, -0.932993f,
   -0.923880f, -0.914210f, -0.903989f, -0.893224f, -0.881921f, -0.870087f, -0.857729f, -0.844854f,
   -0.831470f, -0.817585f, -0.803208f, -0.788346f, -0.773010f, -0.757209f, -0.740951f, -0.724247f,
   -0.707107f, -0.689541f, -0.671559f, -0.653173f, -0.634393f, -0.615232f, -0.595699f, -0.575808f,
   -0.555570f, -0.534998f, -0.514103f, -0.492898f, -0.471397f, -0.449611f, -0.427555f, -0.405241f,
   -0.382683f, -0.359895f, -0.336890f, -0.313682f, -0.290285f, -0.266713f, -0.242980f, -0.219101f,
   -0.195090f, -0.170962f, -0.146730f, -0.122411f, -0.098017f, -0.073565f, -0.049068f, -0.024541f,
    0.000000f,  0.024541f,  0.049068f,  0.073565f,  0.098017f,  0.122411f,  0.146730f,  0.170962f,
    0.195090f,  0.219101f,  0.242980f,  0.266713f,  0.290285f,  0.313682f,  0.336890f,  0.359895f,
    0.382683f,  0.405241f,  0.427555f,  0.449611f,  0.471397f,  0.492898f,  0.514103f,  0.534998f,
    0.555570f,  0.575808f,  0.595699f,  0.615232f,  0.634393f,  0.653173f,  0.671559f,  0.689541f,
    0.707107f,  0.724247f,  0.740951f,  0.757209f,  0.773010f,  0.788346f,  0.803208f,  0.817585f,
    0.831470f,  0.844854f,  0.857729f,  0.870087f,  0.881921f,  0.893224f,  0.903989f,  0.914210f,
    0.923880f,  0.932993f,  0.941544f,  0.949528f,  0.956940f,  0.963776f,  0.970031f,  0.975702f,
    0.980785f,  0.985278f,  0.989177f,  0.992480f,  0.995185f,  0.997290f,  0.998795f,  0.999699f
};
// </editor-fold>


/*******************************************************************************
 *  Functions
 *******************************************************************************/

/*! \brief Calculate sine and cosine value
 *
 * Details
 * Calculate sine value
 *
 * @param[in]:
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcUtils_SineCosineCalculation(const float32_t angle,
                                   float32_t * const sine,  float32_t * const cosine )
{
     float temp;

     uint32_t y0_Index;
     uint32_t y0_IndexNext;
     float x0, y0, y1;

     temp = angle;
     mcUtils_TruncateAngle0To2Pi(&temp);

     temp = ( temp * CONSTANT_1ByAngleStep );
     y0_Index = (uint32_t)temp;
     y0_IndexNext = y0_Index + 1u;

     if( y0_IndexNext >= CONSTANT_SineTableSize )
     {
          y0_IndexNext = 0u;
     }

     x0 = ( (float)y0_Index * CONSTANT_AngleStep);

     /** Since below calculation is same for sin & cosine, we can do it once and reuse. */
     temp = ((angle - x0) * CONSTANT_1ByAngleStep );

     /** Find sine value  */
     y0 = sineTable[y0_Index];
     y1 = sineTable[y0_IndexNext];
     *sine = y0 + ((y1 - y0) * temp);

     /** Find cosine value  */
     y0 = cosineTable[y0_Index];
     y1 = cosineTable[y0_IndexNext];
     *cosine = y0 + ((y1 - y0) * temp);
}

/*! \brief Linear ramp
 *
 * Details
 * Linear ramp
 *
 * @param[in]:
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcUtils_LinearRamp(int32_t * const input, const int32_t stepSize, const int32_t finalValue)
{
    if ((*input + stepSize) < finalValue)
    {
        *input = *input + stepSize;
    }
    else if ((*input - stepSize) > finalValue)
    {
        *input = *input - stepSize;
    }
    else
    {
        *input = finalValue;
    }
}

/*! \brief Button response Function
 *
 * Details
 * Button response function
 *
 * @param[in]:
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcUtils_ButtonResponse(button_response_t * buttonResData, void (* buttonJob)(void))
{
    switch (buttonResData->state)
    {
        case 0u: /** Detect if button is pressed */
        {
            if (false == buttonResData->inputVal )
            {
                buttonJob();
                buttonResData->cnt = 0u;
                buttonResData->state = 1u;
            }
            break;
        }
        case 1u: /** Stay idle for 500ms, and then return to detect */
        {
            buttonResData->cnt++;
            if (buttonResData->cnt >= RL_500MS_10MS)
            {
                buttonResData->cnt = 0u;
                buttonResData->state = 0u;
            }
            break;
        }
        default:
        {
            /** For MISRA Compliance */
        }
        break;
    }
}

/*! \brief Truncate angle to  0 to 2pi
 *
 * Details.
 * Truncate angle to 0 to 2pi
 *
 * @param[in]:
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcUtils_TruncateAngle0To2Pi( float32_t * const angle )
{
    if(*angle >= CONSTANT_2Pi )
    {
        *angle -= CONSTANT_2Pi;
    }
    else if( 0.0f > *angle )
    {
        *angle += CONSTANT_2Pi;
    }
    else
    {
       /* Do nothing */
    }
}

/*! \brief Initialize 2D plot
 *
 * Details.
 * Initialize 2D plot
 *
 * @param[in]:
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void UTIL_2DPlotInitialize( tUTIL_2DPlot_s * const p2DPlot, const uint8_t dataPoints,
                                            const tUTIL_2DPoints_s points[] )
{
     p2DPlot->dataPoints = dataPoints;

     for( uint8_t index = 0u; index < 10u; index++ )
     {
         if( index < dataPoints )
         {
             p2DPlot->points[index] = points[index];
         }
         else
         {
             p2DPlot->points[index].x = 0.0f;
             p2DPlot->points[index].y = 0.0f;
         }
     }
}

/*! \brief Read from 2D plot
 *
 * Details.
 * Read from 2D plot
 *
 * @param[in]:
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
float32_t UTIL_2DPlotRead( tUTIL_2DPlot_s * const p2DPlot,  const float32_t xPoint )
{
     float32_t slope = 0.0f;
     float32_t yValue = 0.0f;
     tUTIL_2DPoints_s * pPoint;

     pPoint = p2DPlot->points;

     if( xPoint <= pPoint[0u].x)
     {
         yValue = pPoint[0u].y;
     }
     else if( xPoint >= pPoint[p2DPlot->dataPoints - 1u].x)
     {
         yValue = pPoint[p2DPlot->dataPoints - 1u].y;
     }
     else
     {
         for( uint8_t index = 0u; index < p2DPlot->dataPoints; index++ )
         {
             if( pPoint[index].x < xPoint )
             {
                 slope = UTIL_DivisionFloat(( pPoint[index + 1u].y  - pPoint[index].y ),
                             ( pPoint[index + 1u].x  - pPoint[index].x ));

                 /** Interpolate values between index and ( index - 1u )*/
                 yValue = pPoint[index].y + slope * ( xPoint - pPoint[index].x );
                 break;
             }
         }
     }

     return yValue;
}
