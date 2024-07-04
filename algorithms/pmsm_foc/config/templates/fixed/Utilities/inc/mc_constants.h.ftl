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

#define  Q14_FORMAT        0U
#define  Q15_FORMAT        1U

#define  GLOBAL_Q_FORMAT           Q15_FORMAT
#define Q15_SCALE_FACTOR            (1 << 15)
#define Q14_SCALE_FACTOR            (1 << 14)


#define   Q15_MULTIPLY(x, y )   (int16_t)(( (int32_t)(x)  * (int32_t)(y)) >> 15U )
#define   Q15_RIGHT_SHIFT( x, y)   (int16_t)( x  >> y )
#define   Q15_SCALE(value)         (int16_t)( value * (float32_t)Q15_SCALE_FACTOR)

#define   Q14_SCALE(value)         (int16_t)( value * (float32_t)Q14_SCALE_FACTOR)
#define   Q14_MULTIPLY(x, y )   (int16_t)(( (int32_t)(x)  * (int32_t)(y)) >> 14U )
#define   Q14_RIGHT_SHIFT( x, y)   (int16_t)( x  >> y )

#define   Q15_ANGLE(value)         (int16_t)( value * (float32_t)Q15_SCALE_FACTOR / (float32_t)ONE_PI)

#if ( GLOBAL_Q_FORMAT == Q15_FORMAT )
#define  Q_SCALE_FACTOR                   Q15_SCALE_FACTOR
#define  Q_MULTIPLY                            Q15_MULTIPLY
#define  Q_SCALE                                  Q15_SCALE
#define  Q_RIGHT_SHIFT                     Q15_RIGHT_SHIFT
#define  Qx_NORMALIZE( x, value )       (int16_t)( value << ( 15U - x ))
#elif  ( GLOBAL_Q_FORMAT == Q14_FORMAT )
#define  Q_SCALE_FACTOR                   Q14_SCALE_FACTOR
#define  Q_MULTIPLY                            Q14_MULTIPLY
#define  Q_SCALE                                  Q14_SCALE
#define  Q_RIGHT_SHIFT                     Q14_RIGHT_SHIFT
#define  Qx_NORMALIZE( x, value )       (int16_t)( value << ( 14U - x ))
#endif

#endif // MC_CONSTANTS_H
