/*******************************************************************************
    PMSM_FOC APP common interface file

  Company:
    Microchip Technology Inc.

  File Name:
    mc_pmsm_foc_common.h

  Summary:
    PMSM_FOC common interface file

  Description:
    This file contains the common data structures of motor control algorithm.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2020 Microchip Technology Inc. and its subsidiaries.
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

#ifndef MC_PMSMFOC_COMMON_H    // Guards against multiple inclusion
#define MC_PMSMFOC_COMMON_H


// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

/*  This section lists the other files that are included in this file.
*/

#include <stddef.h>

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
/* Alignment methods */
#define FORCED_ALIGNMENT                (0U)

/* Position feedback methods */
#define SENSORLESS_PLL                  (0U)
#define SENSORED_ENCODER                (1U)

/* Current measurement methods */
#define DUAL_SHUNT                      (0U)

#define ENABLED                          (1U)
#define DISABLED                         (0U)

/* Control inverter board */
#define CUSTOM                           (0U)
#define MCLV2                            (1U)
#define MCHV3                            (2U)


typedef enum
{
    MCAPP_SUCCESS,
    MCAPP_IN_PROGRESS,
    MCAPP_ERROR
}tMCAPP_STATUS_E;

/* Motor control FOC parameter structure

  Summary:
    Motor Control FOC Parameters

  Description:
    Structure contains run time variables of FOC

  Remarks:
    None.
*/

typedef enum
{
    MCAPP_IDLE,
<#if MCPMSMFOC_INTERM_FLYING_START>    
    MCAPP_FLYING_START,
</#if>
    MCAPP_FIELD_ALIGNMENT,
    MCAPP_OPEN_LOOP,
    MCAPP_CLOSING_LOOP,
    MCAPP_CLOSED_LOOP
}tMCAPP_CONTROL_STATE_E;


/* Motor control parameter structure

  Summary:
    Motor Control Parameters

  Description:
    Structure contains run time variables used in control loop

  Remarks:
    None.
*/
typedef struct
{
    float             velRef;                                    /*   Reference velocity from Ramp           */
    float             idRef;                                     /*   Vd flux reference value                */
    float             iqRef;                                     /*   Vq torque reference value              */
    int16_t           rotationSign;                              /*   Motor direction switch                 */
    bool              firstStart;                                /*  Start after reset                     */
    tMCAPP_CONTROL_STATE_E mcState;                             /*   Controller state                      */
    tMCAPP_CONTROL_STATE_E mcStateLast;                         /*   Controller state of previous cycle    */
} tMCAPP_CONTROL_PARAM_S;


extern tMCAPP_CONTROL_PARAM_S gMCCTRL_CtrlParam;

#endif     //MC_PMSMFOC_COMMON_H
