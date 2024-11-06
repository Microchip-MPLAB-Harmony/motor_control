/*******************************************************************************
  System Definitions

  File Name:
    mc_constants.h

  Summary:
    Header file which contains common constant values used in motor control applications.

  Description:
    This file contains common constant values that are frequently used in motor control 
    applications, including mathematical constants, physical constants, and system-specific
    parameters.
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

#ifndef MC_CONSTANTS_H
#define MC_CONSTANTS_H


/**   Mathematical Constants */
#define ONE_PI                          3.14159265358979323846f
#define TWO_PI                      6.28318530717958647692f
#define HALF_PI                     1.57079632679489661923f
#define QUARTER_PI                  0.78539816339744830962f
#define THREE_HALVES_PI             4.71238898038468985769f
#define THREE_QUARTERS_PI           2.35619449019234492885f
#define FIVE_QUARTERS_PI           3.92699081698724f

#define PI_OVER_TWO                 HALF_PI
#define PI_OVER_THREE               1.04719755119659774615f
#define PI_OVER_FOUR                QUARTER_PI
#define PI_OVER_SIX                 0.52359877559829887308f

/**   Electrical Constants */
#define ONE_OVER_TWO       0.5000000000000000000f
#define SQRT_2                      1.41421356237309504880f
#define SQRT_3                      1.73205080756887729352f
#define ONE_OVER_SQRT_3             0.57735026918962576451f
#define TWO_OVER_SQRT_3            1.15470053837925152902f
#define SQRT_3_OVER_2               0.86602540378443864676f

/** Fixed-Point Conversion Constants  */
#define Q1   1U
#define Q2   2U
#define Q3   3U
#define Q4   4U
#define Q5   5U
#define Q6   6U
#define Q7   7U
#define Q8   8U
#define Q9   9U
#define Q10  10U
#define Q11  11U
#define Q12  12U
#define Q13  13U
#define Q14  14U
#define Q15  15U
#define Q16  16U

#define Q17  17U
#define Q18  18U
#define Q19  19U
#define Q20  20U
#define Q21  21U
#define Q22  22U
#define Q23  23U
#define Q24  24U
#define Q25  25U
#define Q26  26U
#define Q27  27U
#define Q28  28U
#define Q29  29U
#define Q30  30U
#define Q31  31U
#define Q32  32U

#define Q_SCALE_FACTOR            32767

static inline int32_t Q_RIGHT_SHIFT( int32_t operand, uint16_t shift )
{
#if defined ENABLE_SIGN_INTEGER_SHIFT
    /* MISRA C-2012 Rule 10.1 deviated:3 Deviation record ID -  H3_MISRAC_2012_R_10_1_DR_1 */
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wunknown-pragmas"
    #pragma coverity compliance block deviate:3 "MISRA C-2012 Rule 10.1" H3_MISRAC_2012_R_10_1_DR_1
    return ( operand >> shift );
    #pragma coverity compliance end_block "MISRA C-2012 Rule 10.1"
    #pragma GCC diagnostic pop
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

static inline int32_t Q_LEFT_SHIFT(int32_t operand, uint16_t shift )
{
#if defined ENABLE_SIGN_INTEGER_SHIFT
    /* MISRA C-2012 Rule 10.1 deviated:3 Deviation record ID -  H3_MISRAC_2012_R_10_1_DR_1 */
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wunknown-pragmas"
    #pragma coverity compliance block deviate:3 "MISRA C-2012 Rule 10.1" H3_MISRAC_2012_R_10_1_DR_1
    return ( operand << shift );
    #pragma coverity compliance end_block "MISRA C-2012 Rule 10.1"
    #pragma GCC diagnostic pop
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

static inline uint16_t Q15_ANGLE( float radians )
{
    float result = radians * (float)Q_SCALE_FACTOR / (float)ONE_PI;
    return (uint16_t)result;
}


static inline int16_t Q_MULTIPLY( int32_t operand1, int32_t operand2  )
{
#if defined ENABLE_SIGN_INTEGER_SHIFT
    /* MISRAC 2012 deviation block start */
    /* MISRA C-2012 Rule 10.1 deviated:3 Deviation record ID -  H3_MISRAC_2012_R_10_1_DR_1 */
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wunknown-pragmas"
    #pragma coverity compliance block deviate:3 "MISRA C-2012 Rule 10.1" H3_MISRAC_2012_R_10_1_DR_1
    return (int16_t)(( (int32_t)operand1 * (int32_t)operand2)  >> 15u );
    #pragma coverity compliance end_block "MISRA C-2012 Rule 10.1"
    #pragma GCC diagnostic pop
    /* MISRAC 2012 deviation block end */
#else
    return (int16_t)Q_RIGHT_SHIFT((int32_t)((int32_t)operand1 * (int32_t)operand2 ), 15u );
#endif
}

static inline int16_t Q_DIVISION( int32_t x, int32_t y )
{
    return (int16_t)(((int32_t)x * (int32_t)Q_SCALE_FACTOR) / y );
}


/**
 * @brief Scales the given value by the Q_SCALE_FACTOR.
 *
 * @param value The value to be scaled.
 * @return The scaled value as an int16_t.
 */
static inline int16_t Q_SCALE(float value) {
    float temp = value * (float)Q_SCALE_FACTOR;
    return (int16_t)temp;
}

/**
 * @brief Normalizes the given value by shifting it left by (15 - x) bits.
 *
 * @param x The number of bits to shift.
 * @param value The value to be normalized.
 * @return The normalized value as an int16_t.
 */
static inline int16_t Qx_NORMALIZE(uint8_t x, uint16_t value) {
    return (int16_t)Q_LEFT_SHIFT( (int32_t)value, (uint16_t)(15u - (uint16_t)x));
}

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
    /* MISRA C-2012 Rule 10.1 deviated:3 Deviation record ID -  H3_MISRAC_2012_R_10_1_DR_1 */
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wunknown-pragmas"
    #pragma coverity compliance block deviate:3 "MISRA C-2012 Rule 10.1" H3_MISRAC_2012_R_10_1_DR_1
    return ( operand >> shift );
    #pragma coverity compliance end_block "MISRA C-2012 Rule 10.1"
    #pragma GCC diagnostic pop
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
    /* MISRA C-2012 Rule 10.1 deviated:3 Deviation record ID -  H3_MISRAC_2012_R_10_1_DR_1 */
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wunknown-pragmas"
    #pragma coverity compliance block deviate:3 "MISRA C-2012 Rule 10.1" H3_MISRAC_2012_R_10_1_DR_1 

    return (int16_t)(( (int32_t)operand1 * (int32_t)operand2)  >> shift );

    #pragma coverity compliance end_block "MISRA C-2012 Rule 10.1"
    #pragma GCC diagnostic pop
    /* MISRAC 2012 deviation block end */
#else
    return (int16_t)mcUtils_RightShiftS32((int32_t)((int32_t)operand1 * (int32_t)operand2 ), shift );
#endif
}


#endif // MC_CONSTANTS_H
