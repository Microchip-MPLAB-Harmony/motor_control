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

#define  BASE_VALUE                   ( 1 << 14u )
#define   BASE_VALUE_FL             (float32_t)( BASE_VALUE   )
#define   FLOAT_PI	                ( 3.141592654f )
#define   K_ANGLE		      (float32_t)(TWOPI / (2.0 * FLOAT_PI))

/* Angle definitions [0, 65535 ] */
#define   PIFOURTHS		      (  8192U    )		
#define   PIHALVES		      ( 16384U   )		
#define   THREEPIFOURTHS	      ( 24576U  )		
#define   PI				      ( 32768U  )		
#define   FIVEPIFOURTHS	      ( 40960U  )		

#define ENABLE_SIGN_INTEGER_SHIFT
#define ENABLE_FLOAT_IN_WHILE

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

#endif // MC_UTILS
