/*******************************************************************************
 Power Factor Correction App interface file

  Company:
    Microchip Technology Inc.

  File Name:
    pfc_app.h

  Summary:
    Power factor correction algorithm interface

  Description:
    This file contains the data structures and function prototypes of power factor correction loop.
 *******************************************************************************/


 // DOM-IGNORE-BEGIN
 /*******************************************************************************
 * Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
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

#ifndef _PFC_APP_H    /* Guard against multiple inclusion */
#define _PFC_APP_H


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

/*    This section lists the other files that are included in this file.      */

#include <stddef.h>
#include "mclib_generic_float.h"

/* Provide C++ Compatibility */
#ifdef __cplusplus
extern "C" {
#endif


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Constants                                                         */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */


/* ************************************************************************** */
/** Descriptive Constant Name

  @Summary
    Brief one-line summary of the constant.

  @Description
    Full description, explaining the purpose and usage of the constant.
    <p>
    Additional description in consecutive paragraphs separated by HTML
    paragraph breaks, as necessary.
    <p>
    Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.

  @Remarks
    Any additional remarks
 */
#define DISABLE   0
#define ENABLE    1


// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************

/*  A brief description of a section can be given directly below the section
        banner.
*/

// *****************************************************************************

/* Motor state enum

  Summary:
    Identifies pfc states

  Description:
    Enum for the pfc states

  Remarks:
    None.
*/
typedef enum
{
	PFCAPP_STATE_INIT = 0U,
    PFCAPP_STATE_START,
	PFCAPP_STATE_RUNNING,
    PFCAPP_STATE_STOP,
}PFCAPP_STATE;

/** Descriptive Data Type Name

      @Summary
        contains AC voltage signal data.

      @Description
        The structure data-type comprises of AC voltage signals needed for
        power factor correction.

      @Remarks
        None
*/
typedef struct
{
 	float avgOutput;
 	float avgSquare;
 	float measured;
}PFCAPP_AC_VOLTAGE;

/** Descriptive Data Type Name

  @Summary
    contains AC current signal data.

  @Description
    The structure data-type comprises of AC current signals needed for
    power factor correction.

  @Remarks
    None
*/

typedef struct
{
	float avgOutput;
	float measured;
	float corrected;
}PFCAPP_AC_CURRENT;

/** Descriptive Data Type Name

  @Summary
    contains DC bus voltage signal data.

  @Description
    The structure data-type comprises of DC bus voltage signals needed for
    power factor correction.

  @Remarks
    None
*/
typedef struct
{
	float measured;
	float filtered;
	float filterCoeff;
}PFCAPP_DC_BUS_VOLTAGE;

/** Descriptive Data Type Name

  @Summary
    contains state variables for average filter.

  @Description
    The structure contains the state variables for the average filter.

  @Remarks
    None
*/

typedef struct
{
	float B0;
	float B1;
	float B2;
	float A1;
	float A2;
	float y_n;
	float y_n_1;
	float y_n_2;
	float x_n;
	float x_n_1;
	float x_n_2;
} PFCAPP_AVG_FILTER_STATE;

/** Descriptive Data Type Name

  @Summary
    contains control parameters for PFC .

  @Description
    The structure comprises of control parameters for PFC.

  @Remarks
    None
*/
typedef struct
{
	PFCAPP_STATE state;
    float sampleCorrection;
	float kmul;
	uint16_t duty;
	uint16_t samplePoint;
	uint16_t rampRate;
	uint16_t overcurrent_faultCount;
	uint16_t overvoltage_faultCount;
	uint16_t ac_voltage_faultCount;
	uint16_t voltLoopExeRate;
	uint8_t softStart;
	uint8_t pfc_good;
	uint8_t firstPass;
	uint8_t faultBit;
	uint8_t pfcStart;
}PFCAPP_CONTROL_PARAM;


// *****************************************************************************
// *****************************************************************************
// Section: Interface Functions
// *****************************************************************************
// *****************************************************************************

/*  A brief description of a section can be given directly below the section
        banner.
*/

// *****************************************************************************
extern void PFCAPP_init(void);
extern void PFCAPP_Enable(void);
extern void PFCAPP_Disable(void);
extern void PFCAPP_AvgFilter(PFCAPP_AVG_FILTER_STATE *pParam);
extern void PFCAPP_Tasks(void);


    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _PFC_APP_H */

/* *****************************************************************************
 End of File
 */
