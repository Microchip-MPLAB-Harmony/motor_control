/**
 * @brief
 *  Header file for motor control utility functions
 *
 * @Company
 *  Microchip Technology Inc.
 *
 * @File Name:
 *   mc_utilities.h
 *
 * @Summary:
 *   Header file which contains variables and function prototypes of utility functions.
 *
 * @Description:
 *   This file contains variables and function prototypes of utility functions which are
 *   generally used in Motor Control. Implemented in Q2.14 Fixed Point Arithmetic.
 *
 */
 
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
 * @brief Epsilon value for floating-point comparison
 */
#define EPSILON  (float32_t)(1.0e-31)

/**
 * @brief Inverse of epsilon value
 */
#define ONE_BY_EPSILON (float32_t)(1.0e31)

/**
 * @brief Value of PI
 */
#define ONE_PI  (float32_t)(3.14159265f)

/**
 * @brief Value of 2 * PI
 */
#define TWO_PI (float32_t)(6.28318530f)

/**
 * @brief Value of PI/2
 */
#define ONE_PI_BY_TWO     (float32_t)(1.57079632)

/**
 * @brief Value of 1/SQRT(2)
 */
#define ONE_BY_SQRT2  (float32_t)(0.7071067812)

/**
 * @brief Value of 1/SQRT(3)
 */
#define ONE_BY_SQRT3   (float32_t)( 0.577350269 )

/**
 * @brief Value of 2/SQRT(3)
 */
#define TWO_BY_SQRT3  (float32_t)( 1.154700538 )

/******************************************************************************
 * Macro functions
 ******************************************************************************/
/**
 * @brief Check if input is close to zero
 *
 * @param[in] input Input value to check
 * @return true if input is close to zero, false otherwise
 */
#define UTIL_IS_ZERO(input)    (((input) < EPSILON ) && ( (input) > -EPSILON ))

/******************************************************************************
 * User-defined data structures
 ******************************************************************************/
typedef struct
{
    bool inputVal;  /**< Read value of button input pin */
    uint16_t state; /**< State information */
    uint16_t cnt;   /**< Counter value */
} button_response_t;

typedef struct
{
    float32_t x; /**< X-coordinate */
    float32_t y; /**< Y-coordinate */
} tUTIL_2DPoints_s;

typedef struct
{
    uint8_t dataPoints; /**< Number of data points */
    tUTIL_2DPoints_s  points[10u]; /**< Array of 2D points */
} tUTIL_2DPlot_s;

/******************************************************************************
 * Inline functions
 ******************************************************************************/
/**
 * @brief Inline function to compute square root of a float
 *
 * @param[in] x Input value
 * @return Square root of x
 */
__STATIC_INLINE float32_t UTIL_SquareRootFloat(const float32_t x)
{
    float32_t result;

    if (x > 0.0f)
    {
        result = sqrtf(x);
    }
    else
    {
        result = 0.0f;
    }
    return result;
}

/**
 * @brief Inline function to compute magnitude of a 2D vector
 *
 * @param[in] x X-component of the vector
 * @param[in] y Y-component of the vector
 * @return Magnitude of the vector
 */
__STATIC_INLINE float32_t UTIL_MagnitudeFloat(const float32_t x, const float y)
{
    return  UTIL_SquareRootFloat( ( x * x ) + ( y * y ) );
}

/**
 * @brief Inline function to compute square of a float
 *
 * @param[in] x Input value
 * @return Square of x
 */
__STATIC_INLINE float32_t UTIL_SquareFloat(const float32_t x)
{
    return ( x * x );
}

/**
 * @brief Inline function to compute absolute value of a float
 *
 * @param[in] x Input value
 * @return Absolute value of x
 */
__STATIC_INLINE float32_t UTIL_AbsoluteFloat(const float32_t x)
{
    float32_t result;

    if (x < 0.0f)
    {
        result =  -x;
    }
    else
    {
        result = x;
    }

    return result;
}

/**
 * @brief Inline function to perform division of two floats
 *
 * @param[in] x Numerator
 * @param[in] y Denominator
 * @return Result of division
 */
__STATIC_INLINE float32_t UTIL_DivisionFloat(const float32_t x, const float32_t y)
{
    float32_t result;
    if (UTIL_AbsoluteFloat(y) > EPSILON)
    {
        result = x/y;
    }
    else
    {
        result = ONE_BY_EPSILON;
    }

    return result;
}

/**
 * @brief Inline function to saturate a float value within a specified range
 *
 * @param[in,out] input Pointer to input value to be saturated
 * @param[in] min Minimum allowed value
 * @param[in] max Maximum allowed value
 */
__STATIC_INLINE void UTIL_SaturateFloat(float32_t * const input, const float32_t min, const float32_t max)
{
    if (max < (*input))
    {
        *input = max;
    }
    else if (min > (*input))
    {
        *input = min;
    }
    else
    {
        /** For MISRA Compliance */
    }
}

/**
 * @brief Inline function to saturate a signed 16-bit integer value within a specified range
 *
 * @param[in,out] input Pointer to input value to be saturated
 * @param[in] min Minimum allowed value
 * @param[in] max Maximum allowed value
 */
__STATIC_INLINE void UTIL_SaturateS16(int16_t * const input, const int16_t min, const int16_t max)
{
    if (max < (*input))
    {
        *input = max;
    }
    else if (min > (*input))
    {
        *input = min;
    }
    else
    {
        /** For MISRA Compliance */
    }
}

/**
 * @brief Inline function to calculate angular difference between two angles
 *
 * @param[in] plus First angle
 * @param[in] minus Second angle
 * @return Angular difference between plus and minus
 */
__STATIC_INLINE float32_t UTIL_AngleDifferenceCalc(const float32_t plus, const float32_t minus)
{
    float32_t diff = plus - minus;

    if (diff > ONE_PI)
    {
        diff -= TWO_PI;
    }
    else if (diff < -ONE_PI)
    {
        diff += TWO_PI;
    }
    else
    {
        /** Do nothing */
    }

    return diff;
}

/**
 * @brief Inline function to perform linear ramping of a float value towards a final value
 *
 * @param[in,out] pValue Pointer to the value to be ramped
 * @param[in] rampRate Rate of ramping
 * @param[in] final Final value to reach
 */
__STATIC_INLINE void UTIL_LinearRampFloat(float32_t * pValue, const float32_t rampRate, const float32_t final)
{
    if ((*pValue + rampRate) < final)
    {
        *pValue += rampRate;
    }
    else if ((*pValue - rampRate) > final)
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
/**
 * @brief Calculate sine and cosine values of an angle
 *
 * @param[in] angle Input angle in radians
 * @param[out] sine Pointer to store sine value
 * @param[out] cosine Pointer to store cosine value
 */
void mcUtils_SineCosineCalculation(const float32_t angle,
                                float32_t * const sine,  float32_t * const cosine );

/**
 * @brief Perform linear ramping of an integer value towards a final value
 *
 * @param[in,out] input Pointer to the value to be ramped
 * @param[in] stepSize Increment size for ramping
 * @param[in] finalValue Final value to reach
 */
void mcUtils_LinearRamp(int32_t * const input, const int32_t stepSize, const int32_t finalValue);

/**
 * @brief Execute button response function based on button state
 *
 * @param[in,out] buttonResData Pointer to button response data structure
 * @param[in] buttonJob Function pointer to button job function
 */
void mcUtils_ButtonResponse(button_response_t * buttonResData, void (* buttonJob)(void));

/**
 * @brief Truncate angle to the range 0 to 2*PI
 *
 * @param[in,out] angle Pointer to angle value to be truncated
 */
void mcUtils_TruncateAngle0To2Pi(float32_t * const angle);

/**
 * @brief Initialize a 2D plot structure with given data points and points array
 *
 * @param[in,out] p2DPlot Pointer to 2D plot structure to initialize
 * @param[in] dataPoints Number of data points to initialize
 * @param[in] points Array of 2D points to initialize the plot with
 */
void UTIL_2DPlotInitialize(tUTIL_2DPlot_s * const p2DPlot, const uint8_t dataPoints,
                                            const tUTIL_2DPoints_s points[] );

/**
 * @brief Read interpolated value from a 2D plot based on given x-coordinate
 *
 * @param[in,out] p2DPlot Pointer to 2D plot structure to read from
 * @param[in] xPoint X-coordinate to read interpolated value from the plot
 * @return Interpolated value at xPoint from the 2D plot
 */
float32_t UTIL_2DPlotRead(tUTIL_2DPlot_s * const p2DPlot,  const float32_t xPoint );


#endif // MC_UTILS
