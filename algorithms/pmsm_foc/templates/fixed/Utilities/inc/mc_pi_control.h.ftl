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

#ifndef MC_PI
#define MC_PI

#include "mc_types.h"
#include "mc_utilities.h"

/******************************************************************************
 * Constants 
******************************************************************************/

/******************************************************************************
 * User-defined data structure  
******************************************************************************/
typedef struct
{
    int16_t error;
    int16_t KpVal;
    uint16_t KpShift;
    int16_t KiVal;
    uint16_t KiShift;
    int32_t Yint;
    int16_t Ymin;
    int16_t Ymax;
    int16_t Yo;
}tmcUtils_PiControl_s;

/******************************************************************************
 * Interface variables 
******************************************************************************/

/******************************************************************************
 * Interface functions  
******************************************************************************/
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
void mcUtils_PiControlInit( float32_t Kp, float32_t Ki, float32_t dt,  tmcUtils_PiControl_s  * const pControl);

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

#ifdef RAM_EXECUTE
void __ramfunc__ mcUtils_PiLimitUpdate( const int16_t Ymin, const int16_t Ymax, tmcUtils_PiControl_s  * const pControl );
#else
void mcUtils_PiLimitUpdate( const int16_t Ymin, const int16_t Ymax, tmcUtils_PiControl_s  * const pControl );
#endif

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

#ifdef RAM_EXECUTE
void __ramfunc__ mcUtils_PiIntegralUpdate( const int16_t value, tmcUtils_PiControl_s  * const pControl );
#else
void mcUtils_PiIntegralUpdate( const int16_t value, tmcUtils_PiControl_s  * const pControl );
#endif

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

#ifdef RAM_EXECUTE
void __ramfunc__ mcUtils_PiControl( const int16_t error, tmcUtils_PiControl_s  * const pControl );
#else
void mcUtils_PiControl(const int16_t error, tmcUtils_PiControl_s  * const pControl  );
#endif

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
void mcUtils_PiControlReset(const int32_t integral, tmcUtils_PiControl_s  * const pControl);

#endif // MC_PI
