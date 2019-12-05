/*******************************************************************************
  Quadrature Encoder Interface (QEI) Peripheral Library Interface Header File

  Company
    Microchip Technology Inc.

  File Name
    plib_qei_common.h

  Summary
    Data Type definition of the QEI Peripheral Interface Plib.

  Description
    This file defines the Data Types for the QEI Plib.

  Remarks:
    None.

*******************************************************************************/
// DOM-IGNORE-BEGIN
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
// DOM-IGNORE-END

#ifndef PLIB_QEI_COMMON_H    // Guards against multiple inclusion
#define PLIB_QEI_COMMON_H

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************

/*  The following data type definitions are used by the functions in this
    interface.
*/

// *****************************************************************************


typedef enum
{
    QEI_NONE = 0,
    QEI_INDEX = _QEI1STAT_IDXIEN_MASK,
    QEI_HOME = _QEI1STAT_HOMIEN_MASK,
    QEI_VELOCITY_OVERFLOW = _QEI1STAT_VELOVIEN_MASK,
    QEI_POSITION_OVERFLOW = _QEI1STAT_POSOVIEN_MASK,
    QEI_POS_INIT_COMPLETE = _QEI1STAT_PCIIEN_MASK,
    QEI_POS_LESS_EQ = _QEI1STAT_PCLEQIEN_MASK,
    QEI_POS_HIGH_EQ = _QEI1STAT_PCHEQIEN_MASK
}QEI_INTERRUPT;

typedef enum
{
    QEI_STATUS_NONE = 0,
    QEI_INDEX_STATUS = _QEI1STAT_IDXIRQ_MASK,
    QEI_HOME_STATUS = _QEI1STAT_HOMIRQ_MASK,
    QEI_VELOCITY_OVERFLOW_STATUS = _QEI1STAT_VELOVIRQ_MASK,
    QEI_POSITION_OVERFLOW_STATUS = _QEI1STAT_POSOVIRQ_MASK,
    QEI_POS_INIT_COMPLETE_STATUS = _QEI1STAT_PCIIRQ_MASK,
    QEI_POS_LESS_EQ_STATUS = _QEI1STAT_PCLEQIRQ_MASK,
    QEI_POS_HIGH_EQ_STATUS = _QEI1STAT_PCHEQIRQ_MASK,
    QEI_STATUS_MASK = QEI_INDEX_STATUS | QEI_HOME_STATUS | QEI_VELOCITY_OVERFLOW_STATUS | QEI_POSITION_OVERFLOW_STATUS
                        | QEI_POSITION_OVERFLOW_STATUS | QEI_POS_INIT_COMPLETE_STATUS | QEI_POS_LESS_EQ_STATUS | QEI_POS_HIGH_EQ_STATUS
}QEI_STATUS;

typedef void (*QEI_CALLBACK) (QEI_STATUS status, uintptr_t context);


// *****************************************************************************
// *****************************************************************************
// Section: Local: **** Do Not Use ****
// *****************************************************************************
// *****************************************************************************

typedef struct
{
    QEI_CALLBACK callback;
    uintptr_t    context;

} QEI_CH_OBJECT ;



// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
    }
#endif
// DOM-IGNORE-END
#endif // PLIB_ACC_COMMON_H
