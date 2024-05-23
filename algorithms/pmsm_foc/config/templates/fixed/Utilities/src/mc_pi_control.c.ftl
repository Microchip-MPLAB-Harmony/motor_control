/*******************************************************************************
  Utility Functions

  Company:
    - Microchip Technology Inc

  File Name:
    - mc_utilitiesc

  Summary:
    - Utility Functions

  Description:
    - Utility Functions

 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
 * Copyright (C) 2022 Microchip Technology Inc and its subsidiaries
 *
 * Subject to your compliance with these terms, you may use Microchip software
 * and any derivatives exclusively with Microchip products. It is your
 * responsibility to comply with third party license terms applicable to your
 * use of third party software (including open source software) that may
 * accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS" NO WARRANTIES, WHETHER
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
 * PARTICULAR PURPOSE.
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE TO THE
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
 * ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
 * THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *******************************************************************************/
// DOM-IGNORE-END


/*******************************************************************************
Headers inclusions
 *******************************************************************************/
#include "mc_pi_control.h"

/*******************************************************************************
Macro definitions
 *******************************************************************************/
#define GET_VALUE_SHIFT     mcUtils_FloatToValueShiftPair

/******************************************************************************
Private global variables
******************************************************************************/

/*******************************************************************************
Functions
 *******************************************************************************/
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
void mcUtils_PiControlInit( float32_t Kp, float32_t Ki, float32_t dt,  tmcUtils_PiControl_s  * const pControl)
{
  float32_t f32a;
#if defined ENABLE_TUSTIN_APPROXIMATION
    /** */
#else
#endif
     GET_VALUE_SHIFT( Kp, &pControl->KpVal, &pControl->KpShift);

     f32a = Ki * (float32_t)( 1u << pControl->KpShift ) * dt;
     GET_VALUE_SHIFT(f32a, &pControl->KiVal, &pControl->KiShift);
}

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
void __ramfunc__ mcUtils_PiLimitUpdate( const int16_t Ymin, const int16_t Ymax, tmcUtils_PiControl_s  * const pControl )
#else
void mcUtils_PiLimitUpdate( const int16_t Ymin, const int16_t Ymax, tmcUtils_PiControl_s  * const pControl  )
#endif
{
    pControl->Ymin = Ymin;
    pControl->Ymax = Ymax;
}

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
void __ramfunc__ mcUtils_PiIntegralUpdate( const int16_t value, tmcUtils_PiControl_s  * const pControl )
#else
void mcUtils_PiIntegralUpdate( const int16_t value, tmcUtils_PiControl_s  * const pControl )
#endif
{
    pControl->Yint = mcUtils_LeftShiftS16( value, pControl->KpShift );
}

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
void __ramfunc__ mcUtils_PiControl( const int16_t error, tmcUtils_PiControl_s  * const pControl )
#else
void mcUtils_PiControl(const int16_t error, tmcUtils_PiControl_s  * const pControl  )
#endif
{
     int32_t y, yp;
     
     /** Update error */
     pControl->error = error;

     /** Proportional term */
     yp  = ((int32_t)pControl->KpVal * (int32_t) error);
     pControl->Yp = yp;

     /** Sum */
     y = mcUtils_RightShiftS32(( yp +  pControl->Yint ), pControl->KpShift );

     /** Output limitation and anti wind-up */
     if ( y > pControl->Ymax )
     {
          /** Limitation of output to upper boundary */
          y = pControl->Ymax;

          /** Limitation of integral part */
          if (yp > pControl->Ymax)
          {
              yp = pControl->Ymax;
          }
          pControl->Yint = mcUtils_LeftShiftS32((int32_t)pControl->Ymax, pControl->KpShift) - yp;
     }
     else if (y < pControl->Ymin )
     {
          /** Limitation of output to lower boundary */
          y = pControl->Ymin;

          /** Limitation of integral part */
          if (yp < pControl->Ymin)
          {
               yp = pControl->Ymin;
          }
          pControl->Yint = mcUtils_LeftShiftS32((int32_t)-pControl->Ymax, pControl->KpShift) - yp;
     }
     else
     {
          /** No output limitation -> no limitation of integral term */
          pControl->Yint += mcUtils_RightShiftS32(((int32_t)pControl->KiVal * (int32_t) error ), pControl->KiShift);
     }

     pControl->Yo = (int16_t)y;
}

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
void mcUtils_PiControlReset(const int32_t out, tmcUtils_PiControl_s  * const pControl)
{
    pControl->Yint = mcUtils_LeftShiftS32( out, pControl->KpShift );
}

