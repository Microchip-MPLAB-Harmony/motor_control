/*******************************************************************************
  Quadrature Encoder Interface (QEI2) Peripheral Library (PLIB)

  Company:
    Microchip Technology Inc.

  File Name:
    plib_qei2.c

  Summary:
    QEI2 Source File

  Description:
    None

*******************************************************************************/

/*******************************************************************************
* Copyright (C) 2019 Microchip Technology Inc. and its subsidiaries.
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
#include "device.h"
#include "plib_qei2.h"

// *****************************************************************************

// *****************************************************************************
// Section: QEI2 Implementation
// *****************************************************************************
// *****************************************************************************


void QEI2_Initialize (void)
{

    /* QEI2CON register  */
    /*  CCM    = 0 */
    /*  GATEN  = 0 */
    /*  CNTPOL = 0 */
    /*  INTDIV = 0 */
    /*  IMV    = 0  */
    /*  PIMOD  = 6  */
    /*  QEISIDL = 0 */
    QEI2CON = 0x1800;

    /* QEI2IOC register  */
    /*  QEAPOL    = 0 */
    /*  QEBPOL  = 0 */
    /*  IDXPOL = 0 */
    /*  HOMPOL = 0 */
    /*  SWPAB    = 0  */
    /*  OUTFNC  = 0  */
    /*  QFDIV   = 0   */
    /*  FLTREN  = 1   */
    QEI2IOC = 0x4000;

    QEI2ICC = 200U;
    QEI2CMPL = 1U;

    /* QEI2STAT register  */
    /*  IDXIEN    = false */
    /*  HOMIEN  = false */
    /*  VELOVIEN = false */
    /*  POSOVIEN = false */
    /*  PCIIEN    = false  */
    /*  PCLEQIEN  = false    */
    /*  PCHEQIEN = false     */
    QEI2STAT = 0x0;

}


void QEI2_Start()
{
    /* Enable QEI channel */
    QEI2CON |= _QEI2CON_QEIEN_MASK;
}

void QEI2_Stop()
{
    /* Disable QEI channel */
    QEI2CON &= ~_QEI2CON_QEIEN_MASK;
}

uint32_t QEI2_PulseIntervalGet()
{
    return (INT2HLD);
}

void QEI2_PositionWindowSet(uint32_t high_threshold, uint32_t low_threshold)
{
    QEI2ICC  = high_threshold;
    QEI2CMPL = low_threshold;
}


