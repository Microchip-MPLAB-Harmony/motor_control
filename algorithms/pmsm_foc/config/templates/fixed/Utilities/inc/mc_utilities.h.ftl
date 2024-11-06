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
void mcUtils_FloatToValueShiftPair( const float32_t input, int16_t * const value, uint16_t * const shift );

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
        *pValue = 0;
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
    return (int16_t)delAngle;
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


__STATIC_INLINE int16_t UTIL_Abs16(int16_t x)
{
    if(  x < 0 )    {
        return -x;
    }
    return x;
}

#endif // MC_UTILS
