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

/******************************************************************************
 * Constants
******************************************************************************/
#define   ENABLE_SIGN_INTEGER_SHIFT
#define   ENABLE_FLOAT_IN_WHILE

/******************************************************************************
 * User-defined data structure
******************************************************************************/
typedef struct
{
    bool inputVal;  /* read value of button input pin */
    uint16_t state;
    uint16_t cnt;
} button_response_t;


/******************************************************************************
 * Interface variables
******************************************************************************/

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

#ifdef RAM_EXECUTE
void __ramfunc__ mcUtils_SineCosineCalculation( const uint16_t ang,
                                                                  int16_t * const sine,  int16_t * const cosine );
#else
void mcUtils_SineCosineCalculation(const uint16_t ang,
                                   int16_t * const sine,  int16_t * const cosine );
#endif

/*! \brief Calculate square root value
 *
 * Details
 * Calculate square root value
 *
 * @param[in]:
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
#ifdef RAM_EXECUTE
uint32_t  __ramfunc__ mcUtils_SquareRoot(uint32_t number);
#else
uint32_t mcUtils_SquareRoot(uint32_t number );
#endif

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
#ifdef RAM_EXECUTE
 void __ramfunc__ mcUtils_LinearRamp(int32_t * const input, const int32_t stepSize, const int32_t finalValue);
#else
void mcUtils_LinearRamp(int32_t * const input, const int32_t stepSize, const int32_t finalValue);
#endif

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

/*! \brief
 *
 * Details
 *
 *
 * @param[in]:
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcUtils_FloatToValueShiftPair( float32_t input, int16_t * const value, uint16_t * const shift );

/*! \brief Right shift  for 32-bit signed integer
 *
 * Details
 * Right shift  for 32-bit signed integer
 *
 * @param[in]:
 * @param[in/out]:
 * @param[out]:
 * @return:
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

/*! \brief Left shift  for 32-bit signed integer
 *
 * Details
 * Left shift  for 32-bit signed integer
 *
 * @param[in]:
 * @param[in/out]:
 * @param[out]:
 * @return:
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

/*! \brief Right shift  for 16-bit signed short
 *
 * Details
 * Right shift  for 16-bit signed short
 *
 * @param[in]:
 * @param[in/out]:
 * @param[out]:
 * @return:
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

/*! \brief Left shift  for 16-bit signed short
 *
 * Details
 * Left shift  for 16-bit signed short
 *
 * @param[in]:
 * @param[in/out]:
 * @param[out]:
 * @return:
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

/*! \brief Left shift  for 16-bit signed short
 *
 * Details
 * Left shift  for 16-bit signed short
 *
 * @param[in]:
 * @param[in/out]:
 * @param[out]:
 * @return:
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

__STATIC_INLINE bool UTIL_AbsGreaterThanEqual(int16_t x, int16_t limit)
{
    return (x <= -limit) || (x >= limit);
}

__STATIC_INLINE bool UTIL_AbsLessThanEqual(int16_t x, int16_t limit)
{
    return (x >= -limit) && (x <= limit);
}

__STATIC_INLINE  void   UTIL_ApplyClampS16( int16_t * const input, const int16_t  max, const int16_t min )
{
    if(  *input  < min )      {
         *input  = min;
    }
    else if(  *input  > max )    {
         *input  = max;
    }
    else     {
         /** MISRA compliance */
    }
}

__STATIC_INLINE  void   UTIL_ApplyClampS32( int32_t * const input, const int32_t  max, const int32_t min )
{
    if(  *input  < min )      {
         *input  = min;
    }
    else if(  *input  > max )    {
         *input  = max;
    }
    else     {
         /** MISRA compliance */
    }
}

__STATIC_INLINE void UTIL_SubtractAndClamps32( int32_t * const minuend, const int32_t  subtrahend )
{
    int64_t result;
    result = *minuend - subtrahend;
    if ( result > INT32_MAX ) {
        *minuend = INT32_MAX;
    }
    else if ( result < INT32_MIN ) {
        *minuend = INT32_MIN;
    }
    else {
        *minuend = (int32_t)result;
    }
}

__STATIC_INLINE void UTIL_AddAndClamps32( int32_t * const addend1, const int32_t  addend2 )
{
    int64_t result;
    result = *addend1 + addend2;
    if ( result > INT32_MAX ) {
        *addend1 = INT32_MAX;
    }
    else if ( result < INT32_MIN ) {
        *addend1 = INT32_MIN;
    }
    else {
        *addend1 = (int32_t)result;
    }
}

#define IS_NEAGTIVE_S16(x)    ( uint16_t )( x & 0x8000U )
__STATIC_INLINE int16_t UTIL_Abs16(int16_t x)
{
    if(  IS_NEAGTIVE_S16(x))    {
        return -x;
    }
    return x;
}

#endif // MC_UTILS
