/*******************************************************************************
 Motor Control Generic Library interface file

  Company:
    Microchip Technology Inc.

  File Name:
    mclib_generic_float.h

  Summary:
    Motor control generic library interface

  Description:
    This file contains the data structures and function prototypes of
    motor control library.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
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
// DOM-IGNORE-END

#ifndef MCLIB_GENERIC_LIB_H    // Guards against multiple inclusion
#define MCLIB_GENERIC_LIB_H

/*******************************************************************************
 Header inclusions
 *******************************************************************************/

#include <stddef.h>
#include "mc_interface_handling.h"

/*******************************************************************************
 Constants
 *******************************************************************************/
#define     M_PI                             (float)3.14159265358979323846
#define     M_PI_2                           (float)1.57079632679489661923
#define     M_2_PI                           (float)( 2.0f * M_PI )
#define     SINGLE_ELEC_ROT_RADS_PER_SEC     (float)((float)(2.0) * (float)M_PI)

#define     SQRT3                            (float)( 1.732)
#define     SQRT3_BY2                        (float)(0.866025403788)

#define     ONE_BY_SQRT3                     (float)(0.5773502691)
#define     TWO_BY_SQRT3                     (float)(1.1547005384)
#define     TOTAL_SINE_TABLE_ANGLE           (float)(2.0f * (float)M_PI)
#define     TABLE_SIZE                       256
#define     ANGLE_STEP                       (TOTAL_SINE_TABLE_ANGLE/(float)TABLE_SIZE)
#define     ONE_BY_ANGLE_STEP                (1/ANGLE_STEP)


/*******************************************************************************
 User defined data-types  
 *******************************************************************************/

typedef struct _tmcLib_PiControllerParameter_s
{
     /* Proportional gain */
    float Kp;
    
    /* Integral gain */
    float Ki;
    
    /* Anti-windup back calculation gain */
    float Kc;
        
    /* Positive saturation limit */
    float Ymax;
    
    /* Negative saturation limit */
    float Ymin;
    
}tmcLib_PiControllerParameter_s;


typedef struct _tmcLib_PiController_s
{
    /* Reference Signal */
    float reference;
    
    /* Feedback signal */
    float feedback;
    
    /* Proportional gain */
    float Kp;
    
    /* Integral gain */
    float Ki;
    
    /* Anti-windup back calculation gain */
    float Kc;
    
    /* Last integral */
    float Yi;
    
    /* Positive saturation limit */
    float Ymax;
    
    /* Negative saturation limit */
    float Ymin;
    
    /* Control output */
    float Yout;
    
}tmcLib_PiController_s;


/*******************************************************************************
 Interface variables 
 *******************************************************************************/


/*******************************************************************************
 Interface functions 
 *******************************************************************************/

/*! \brief Sine and Cosine calculation 
 * 
 * Details.
 *  Sine and Cosine calculation 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcLib_SinCosCalc( float const rotor_angle, float* sineAngle, float* cosAngle );


/*! \brief Wrap angle to  0 to 2pi
 * 
 * Details.
 * Wrap angle to 0 to 2pi
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcLib_WrapAngleTo2Pi( float * const angle );

/*! \brief Impose lower and upper limit
 * 
 * Details.
 * Impose lower and upper limit 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcLib_ImposeLimits( float * const input, const float lowerLimit, const float upperLimit );

/*! \brief Calculate square root 
 * 
 * Details.
 *  Calculate square root 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
float  mcLib_SquareRootCalculate( float square );

/*! \brief Clarke Transform 
 * 
 * Details.
 * Clarke Transform
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
 void mcLib_ClarkeTransform(const tmcInf_ThreePhaseQuantity_s * const  input,
                                               tmcLib_ClarkTransform_s * const output);
 
/*! \brief Park Transform 
 * 
 * Details.
 *  Park Transform 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcLib_ParkTransform( const tmcLib_ClarkTransform_s * const input,
                                           const float theta, tmcLib_ParkTransform_s * const output);

/*! \brief Inverse park transform 
 * 
 * Details.
 *  Inverse park transform 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
 void mcLib_InvParkTransform(const tmcLib_ParkTransform_s * const input, 
                                                const float theta, tmcLib_ClarkTransform_s * const output);

 /*! \brief PI controller parameter set 
 * 
 * Details.
 *  PI controller parameter set
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */ 
void mcLib_PiControllerParametersSet( tmcLib_PiController_s * piController, tmcLib_PiControllerParameter_s * piParam );

/*! \brief PI controller run
 * 
 * Details.
 *  PI controller run
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */ 
void mcLib_PiControllerRun( tmcLib_PiController_s * piController );

/*! \brief PI controller reset
 * 
 * Details.
 *  PI controller reset
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcLib_PiControllerReset( tmcLib_PiController_s * piController );

#endif //MCLIB_GENERIC_LIB_H
