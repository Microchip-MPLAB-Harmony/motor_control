/*******************************************************************************
 Motor Control App interface file

  Company:
    Microchip Technology Inc.

  File Name:
    mc_infrastructure.h

  Summary:
    Header file for infrastructure

  Description:
    This file contains the data structures and function prototypes used by
    infrastructure module.
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

#ifndef MCINF_H    // Guards against multiple inclusion
#define MCINF_H


// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

/*  This section lists the other files that are included in this file.
*/

#include <stddef.h>
#include "mc_lib.h"


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
#define POSITION_LOOP_PWM_COUNT   (uint32_t)( 100*SPEED_LOOP_PWM_COUNT )
typedef enum 
{
         LOOP_INACTIVE,
         LOOP_ACTIVE
}tMCINF_LOOP_STATE_E;

typedef struct 
{ 
         tMCINF_LOOP_STATE_E  SpeedLoopActive;
         tMCINF_LOOP_STATE_E  PositionLoopActive;
}tMCINF_STATE_S;

typedef struct 
{
         uint32_t  SpeedLoopCount;
         uint32_t  PositionLoopCount;
}tMCINF_PARAM_S;

// *****************************************************************************
// *****************************************************************************
// Section: Interface Routines
// *****************************************************************************
// *****************************************************************************

extern void  MCINF_Tasks();
extern void MCINF_InitializeControl(void);
extern void MCINF_InitializeInfrastructure(void);
extern void MCINF_ResetInfrastructure(void);
extern void MCINF_StartAdcInterrupt( void );
extern void MCINF_MotorStart( void );
extern void MCINF_MotorStop( void );
extern void MCINF_DirectionToggle(void);
extern tMCINF_LOOP_STATE_E  MCINF_IsSpeedLoopActive( void );
extern tMCINF_LOOP_STATE_E MCINF_IsPositionLoopActive( void );

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

}

#endif
// DOM-IGNORE-END

#endif //MCINF_H

/**
 End of File
*/
