/**
 * @Brief 
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
 *    generally used in Motor Control. Implemented in Q2.14 Fixed Point Arithmetic.
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

/******************************************************************************
 * Constants
******************************************************************************/

/******************************************************************************
 * Constants
******************************************************************************/
/**
 * @brief Base value used in calculations (2^14)
 */
#define BASE_VALUE (1 << 14u)

/**
 * @brief Base value casted to float32_t
 */
#define BASE_VALUE_FL ((float32_t)(BASE_VALUE))

/**
 * @brief Floating-point value of pi (3.141592654f)
 */
#define FLOAT_PI (3.141592654f)

/**
 * @brief Constant for converting angles (2 * pi / 65536)
 */
#define K_ANGLE ((float32_t)(TWOPI / (2.0 * FLOAT_PI)))

/**
 * @brief Angle definitions in fixed-point representation [0, 65535]
 */
#define PIFOURTHS (8192U)
#define PIHALVES (16384U)
#define THREEPIFOURTHS (24576U)
#define PI (32768U)
#define FIVEPIFOURTHS (40960U)
#define THREEPIHALVES (49152U)

/**
 * @brief Enables signed integer shift operations
 */
#define ENABLE_SIGN_INTEGER_SHIFT

/**
 * @brief Enables floating-point operations within a while loop
 */
#define ENABLE_FLOAT_IN_WHILE


/******************************************************************************
 * User-defined data structure
******************************************************************************/
/**
 * @brief Structure representing button response data
 *
 * @details This structure holds data related to button input, including the current
 *          input value, state, and count.
 */
typedef struct
{
    bool inputVal;  /**< Read value of the button input pin */
    uint16_t state; /**< State of the button */
    uint16_t cnt;   /**< Count associated with button events */
} button_response_t;


/******************************************************************************
 * Interface variables
******************************************************************************/

/******************************************************************************
 * Inline functions
******************************************************************************/

/**
 * @brief Right shift operation for 32-bit signed integer
 *
 * @details Perform a right shift operation on a 32-bit signed integer.
 *
 * @param[in] operand 32-bit signed integer value to be shifted.
 * @param[in] shift Shift amount.
 * @return Shifted value.
 */
__STATIC_FORCEINLINE int32_t mcUtils_RightShiftS32(int32_t operand, uint16_t shift )
{
#if defined ENABLE_SIGN_INTEGER_SHIFT
    /* MISRAC 2012 deviation block start */
    /* MISRA C-2012 Rule 10.1 deviated in this function. Deviation record ID -  H3_MISRAC_2012_R_2_2_DR_1  */
    return ( operand >> shift );
    /* MISRAC 2012 deviation block end */
#else
    int32_t result;
    uint32_t u32a;

    if( 0 > operand )
    {
        u32a = ((uint32_t)(-operand ) >> shift );
        result = -(int32_t)u32a;
    }
    else
    {
        u32a = ((uint32_t)operand >> shift);
        result = (int32_t)u32a;
    }
    return result;
#endif
}

/**
 * @brief Left shift operation for 32-bit signed integer
 *
 * @details Perform a left shift operation on a 32-bit signed integer.
 *
 * @param[in] operand 32-bit signed integer value to be shifted.
 * @param[in] shift Shift amount.
 * @return Shifted value.
 */
__STATIC_FORCEINLINE int32_t mcUtils_LeftShiftS32(int32_t operand, uint16_t shift )
{
#if defined ENABLE_SIGN_INTEGER_SHIFT
    /* MISRAC 2012 deviation block start */
    /* MISRA C-2012 Rule 10.1 deviated in this function. Deviation record ID -  H3_MISRAC_2012_R_2_2_DR_1  */
    return ( operand << shift );
    /* MISRAC 2012 deviation block end */
#else
    int32_t result;
    uint32_t u32a;

    if(0 > operand )
    {
        u32a = ((uint32_t)(-operand ) << shift );
        result = -(int32_t)u32a;
    }
    else
    {
        u32a = ((uint32_t)operand << shift);
        result = (int32_t)u32a;
    }
    return (result);
#endif
}

/**
 * @brief Right shift operation for 16-bit signed short
 *
 * @details Perform a right shift operation on a 16-bit signed short integer.
 *
 * @param[in] operand 16-bit signed short integer value to be shifted.
 * @param[in] shift Shift amount.
 * @return Shifted value.
 */
__STATIC_FORCEINLINE int16_t mcUtils_RightShiftS16(int16_t operand, uint16_t shift )
{
#if defined ENABLE_SIGN_INTEGER_SHIFT
    /* MISRAC 2012 deviation block start */
    /* MISRA C-2012 Rule 10.1 deviated in this function. Deviation record ID -  H3_MISRAC_2012_R_2_2_DR_1  */
    return ( operand >> shift );
    /* MISRAC 2012 deviation block end */
#else
    int16_t result;
    uint16_t u16a;

    if( 0 > operand )
    {
        u16a = ((uint16_t)(-operand ) >> shift );
        result = -(int16_t)u16a;
    }
    else
    {
        u16a = ((uint16_t)operand >> shift);
        result = (int16_t)u16a;
    }
    return (result);
#endif
}

/**
 * @brief Left shift operation for 16-bit signed short
 *
 * @details Perform a left shift operation on a 16-bit signed short integer.
 *
 * @param[in] operand 16-bit signed short integer value to be shifted.
 * @param[in] shift Shift amount.
 * @return Shifted value.
 */
__STATIC_FORCEINLINE int16_t mcUtils_LeftShiftS16(int16_t operand, uint16_t shift )
{
#if defined ENABLE_SIGN_INTEGER_SHIFT
    /* MISRAC 2012 deviation block start */
    /* MISRA C-2012 Rule 10.1 deviated in this function. Deviation record ID -  H3_MISRAC_2012_R_2_2_DR_1  */
    return ( operand << shift );
    /* MISRAC 2012 deviation block end */
#else
    int16_t result;
    uint16_t u16a;

    if( 0 > operand )
    {
        u16a = ((uint16_t)(-operand ) << shift );
        result = -(int16_t)u16a;
    }
    else
    {
        u16a = ((uint16_t)operand << shift);
        result = (int16_t)u16a;
    }
    return (result);
#endif
}

/**
 * @brief Multiply and right shift operation for 16-bit signed short
 *
 * @details Perform multiplication of two 16-bit signed short integers and then perform a right shift operation.
 *
 * @param[in] operand1 First operand for multiplication.
 * @param[in] operand2 Second operand for multiplication.
 * @param[in] shift Shift amount after multiplication.
 * @return Result of the multiplication and right shift operation.
 */
__STATIC_FORCEINLINE int16_t mcUtils_MultAndRightShiftS16(int16_t operand1, int16_t operand2, uint16_t shift )
{
#if defined ENABLE_SIGN_INTEGER_SHIFT
    /* MISRAC 2012 deviation block start */
    /* MISRA C-2012 Rule 10.1 deviated in this function. Deviation record ID -  H3_MISRAC_2012_R_2_2_DR_1  */
    return (int16_t)(( (int32_t)operand1 * (int32_t)operand2)  >> shift );
    /* MISRAC 2012 deviation block end */
#else
    return (int16_t)mcUtils_RightShiftS32((int32_t)((int32_t)operand1 * (int32_t)operand2 ), shift );
#endif
}

/**
 * @brief Perform a linear ramp operation on a 16-bit value
 *
 * @details Perform a linear ramp operation on a 16-bit value towards zero based on the step size.
 *
 * @param[in,out] pValue Pointer to the value to be ramped.
 * @param[in] step Step size of the ramp.
 * @param[in] final Final value towards which the value will ramp.
 */
__STATIC_FORCEINLINE void UTILS_LinearRamp( int16_t * pValue, int16_t step, int16_t final)
{
    if( *pValue > step )
    {
        *pValue -= step;
    }
    else if (*pValue < -step )
    {
        *pValue += step;
    }
    else
    {
        *pValue = 0u;
    }
}

/**
 * @brief Calculate the difference between two angles
 *
 * @details Calculate the signed difference between two angles given in degrees (0 to 65535).
 *
 * @param[in] angle1 First angle.
 * @param[in] angle2 Second angle.
 * @return Signed difference between the angles.
 */
__STATIC_INLINE int16_t UTIL_AngleDifferenceGet(const uint16_t angle1, const uint16_t angle2)
{
    /** Calculate the signed difference between the angles */
    int32_t delAngle = (int32_t)angle1 - (int32_t)angle2;

    /** Handle wrap-around case if the difference is greater than 32767 */
    if ( delAngle > 32767 )
    {
        delAngle -= 65535;
    }

    /** Return angle difference */
    return delAngle;
}

/**
 * @brief Check if absolute value of x is greater than or equal to the limit
 *
 * @details Check if the absolute value of x is greater than or equal to the specified limit.
 *
 * @param[in] x Value to check.
 * @param[in] limit Limit value.
 * @return true if |x| >= limit, false otherwise.
 */
__STATIC_INLINE bool UTIL_AbsGreaterThanEqual(int16_t x, int16_t limit)
{
    return (x <= -limit) || (x >= limit);
}

/**
 * @brief Check if absolute value of x is less than or equal to the limit
 *
 * @details Check if the absolute value of x is less than or equal to the specified limit.
 *
 * @param[in] x Value to check.
 * @param[in] limit Limit value.
 * @return true if |x| <= limit, false otherwise.
 */
__STATIC_INLINE bool UTIL_AbsLessThanEqual(int16_t x, int16_t limit)
{
    return (x >= -limit) && (x <= limit);
}

/******************************************************************************
 * Interface functions
******************************************************************************/
/**
 * @brief Calculate sine and cosine value
 *
 * @details Calculate sine and cosine values for a given angle.
 *
 * @param[in] ang Angle in degrees (0 to 65535).
 * @param[out] sine Pointer to store the calculated sine value.
 * @param[out] cosine Pointer to store the calculated cosine value.
 */
#ifdef RAM_EXECUTE
void __ramfunc__ mcUtils_SineCosineCalculation( const uint16_t ang,
                                                                  int16_t * const sine,  int16_t * const cosine );
#else
void mcUtils_SineCosineCalculation(const uint16_t ang,
                                   int16_t * const sine,  int16_t * const cosine );
#endif

/**
 * @brief Calculate square root value
 *
 * @details Calculate the square root of a given number.
 *
 * @param[in] number Number for which square root needs to be calculated.
 * @return Calculated square root value.
 */
#ifdef RAM_EXECUTE
uint32_t  __ramfunc__ mcUtils_SquareRoot(uint32_t number);
#else
uint32_t mcUtils_SquareRoot(uint32_t number );
#endif

/**
 * @brief Perform a linear ramp operation
 *
 * @details Perform a linear ramp operation on the input value towards a final value.
 *
 * @param[in,out] input Pointer to the input value to be ramped.
 * @param[in] stepSize Step size of the ramp.
 * @param[in] finalValue Final value towards which the input value will ramp.
 */
#ifdef RAM_EXECUTE
 void __ramfunc__ mcUtils_LinearRamp(int32_t * const input, const int32_t stepSize, const int32_t finalValue);
#else
void mcUtils_LinearRamp(int32_t * const input, const int32_t stepSize, const int32_t finalValue);
#endif

/**
 * @brief Button response function
 *
 * @details Execute a function based on the button response.
 *
 * @param[in,out] buttonResData Pointer to the button response data structure.
 * @param[in] buttonJob Pointer to the function to execute on button press.
 */
void mcUtils_ButtonResponse(button_response_t * buttonResData, void (* buttonJob)(void));

/**
 * @brief Convert float to value and shift pair
 *
 * @details Convert a float value to a fixed-point integer value and its corresponding shift amount.
 *
 * @param[in] input Float value to convert.
 * @param[out] value Pointer to store the converted integer value.
 * @param[out] shift Pointer to store the shift amount.
 */
void mcUtils_FloatToValueShiftPair( float32_t input, int16_t * const value, uint16_t * const shift );


#endif // MC_UTILS
