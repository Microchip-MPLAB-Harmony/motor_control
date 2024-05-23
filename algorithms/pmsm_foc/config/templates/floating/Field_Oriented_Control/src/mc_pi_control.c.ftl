/*******************************************************************************
  Utility Functions

  Company:
    - Microchip Technology Inc

  File Name:
    - mc_pi_control.c

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
#if defined ENABLE_TUSTIN_APPROXIMATION
    /** */
#else
#endif
     pControl->Kp = Kp;
     pControl->Ki = Ki * dt;
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
void mcUtils_PiLimitUpdate( const float32_t Ymin, const float32_t Ymax, tmcUtils_PiControl_s  * const pControl  )
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
void mcUtils_PiIntegralUpdate( const float32_t value, tmcUtils_PiControl_s  * const pControl )
{
    pControl->Yint = value;
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
void mcUtils_PiControl(const float32_t error, tmcUtils_PiControl_s  * const pControl  )
{
     float32_t  y, yp;

     /** Proportional term */
     yp  = pControl->Kp * error;
     pControl->error = error;

     /** Sum */
     y = yp +  pControl->Yint;

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
          pControl->Yint = pControl->Ymax - yp;
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
          pControl->Yint = pControl->Ymin - yp;
     }
     else
     {
          /** No output limitation -> no limitation of integral term */
          pControl->Yint += pControl->Ki * error;
     }

     pControl->Yo = y;
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
void mcUtils_PiControlReset(const float32_t integral, tmcUtils_PiControl_s  * const pControl)
{
    pControl->Yint = integral;
}

