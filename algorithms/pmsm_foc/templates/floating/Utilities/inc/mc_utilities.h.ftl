/*******************************************************************************
  System Definitions

  File Name:
    mc_generic_library.h

  Summary:
    Header file which contains variables and function prototypes of  generic library functions.

  Description:
    This file contains variables and function prototypes of generic library functions
    which are generally used in Motor Control. Implemented in Q2.14 Fixed Point Arithmetic.
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

#ifndef MC_UTILS
#define MC_UTILS

#include "mc_types.h"
#include "math.h"

/******************************************************************************
 * Constants
******************************************************************************/
/**
  * Epsilon
  */
#define EPSILON  (float32_t)(1.0e-31)

/**
  * Inverse of epsilon
  */
#define ONE_BY_EPSILON (float32_t)(1.0e31)

/**
  * PI
  */
#define ONE_PI  (float32_t)(3.14159265f)

/**
  * 2PI
  */
#define TWO_PI (float32_t)(6.28318530f)

/**
  * PI/2
  */
#define ONE_PI_BY_TWO     (float32_t)(1.57079632)

/**
  * 1/ SQUARE_ROOT( 2 )
  */
#define ONE_BY_SQRT2  (float32_t)(0.7071067812)

/**
  * 1/ SQUARE_ROOT( 3 )
  */
#define ONE_BY_SQRT3   (float32_t)( 0.577350269 )

/**
  * 2/ SQUARE_ROOT( 2 )
  */
#define TWO_BY_SQRT3  (float32_t)( 1.154700538 )

/******************************************************************************
 * Macro functions
******************************************************************************/
#define UTIL_IS_ZERO(input)    (((input) < EPSILON ) && ( (input) > -EPSILON ))

/******************************************************************************
 * User-defined data structure
******************************************************************************/
typedef struct
{
    bool inputVal;  /* read value of button input pin */
    uint16_t state;
    uint16_t cnt;
} button_response_t;

typedef struct
{
    float32_t x;
    float32_t y;
}tUTIL_2DPoints_s;

typedef struct
{
    uint8_t dataPoints;
    tUTIL_2DPoints_s  points[10u];
}tUTIL_2DPlot_s;


/******************************************************************************
 * Interface variables
******************************************************************************/

__STATIC_INLINE float32_t UTIL_SquareRootFloat( const float32_t x  )
{
    float32_t result;

    if( x > 0.0f )
    {
        result = sqrtf(x);
    }
    else
    {
        result = 0.0f;
    }
    return result;
}

__STATIC_INLINE float32_t UTIL_MagnitudeFloat( const float32_t x, const float y )
{
    /** ToDO: Clarify. */
    //return ONE_BY_SQRT2 * UTIL_SquareRootFloat( ( x * x ) + ( y * y ) );
    return  UTIL_SquareRootFloat( ( x * x ) + ( y * y ) );
}

__STATIC_INLINE float32_t UTIL_SquareFloat( const float32_t x  )
{
    return ( x * x );
}

__STATIC_INLINE float32_t UTIL_AbsoluteFloat( const float32_t x  )
{
    float32_t result;

    if( x < 0.0f )
    {
        result =  -x;
    }
    else
    {
        result = x;
    }

    return result;
}

__STATIC_INLINE float32_t UTIL_DivisionFloat( const float32_t x, const float32_t y  )
{
    float32_t result;
    if( UTIL_AbsoluteFloat(y) > EPSILON )
    {
        result = x/y;
    }
    else
    {
        result = ONE_BY_EPSILON;
    }

    return result;
}

__STATIC_INLINE void UTIL_SaturateFloat( float32_t * const input, const float32_t min, const float32_t max  )
{
    if( max < (*input ) )
    {
        *input = max;
    }
    else if( min > (*input ))
    {
        *input = min;
    }
    else
    {
        /** For MISRA Compliance */
    }
}

__STATIC_INLINE void UTIL_SaturateS16( int16_t * const input, const int16_t min, const int16_t max  )
{
    if( max < (*input ) )
    {
        *input = max;
    }
    else if( min > (*input ))
    {
        *input = min;
    }
    else
    {
        /** For MISRA Compliance */
    }
}


__STATIC_INLINE float32_t UTIL_AngleDifferenceCalc( const float32_t plus, const float32_t minus )
{
     float32_t diff = plus - minus;

     if( diff > ONE_PI )
     {
         diff -= TWO_PI;
     }
     else if( diff < -ONE_PI )
     {
         diff += TWO_PI;
     }
     else
     {
        /** Do nothing */
     }

     return diff;
}

__STATIC_INLINE void UTIL_LinearRampFloat( float32_t * pValue, const float32_t rampRate, const float32_t final )
{
     if( ( *pValue + rampRate ) < final )
     {
         *pValue += rampRate;
     }
     else if( ( *pValue - rampRate ) > final )
     {
         *pValue -= rampRate;
     }
     else
     {
         *pValue = final;
     }
}



/******************************************************************************
 * Interface functions
******************************************************************************/
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
                                float32_t * const sine,  float32_t * const cosine );

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
void mcUtils_LinearRamp(int32_t * const input, const int32_t stepSize, const int32_t finalValue);

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
void mcUtils_ButtonResponse(button_response_t * buttonResData, void (* buttonJob)(void));

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
void mcUtils_TruncateAngle0To2Pi( float32_t * const angle );

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
                                            const tUTIL_2DPoints_s points[] );

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
float32_t UTIL_2DPlotRead( tUTIL_2DPlot_s * const p2DPlot,  const float32_t xPoint );

#endif // MC_UTILS
