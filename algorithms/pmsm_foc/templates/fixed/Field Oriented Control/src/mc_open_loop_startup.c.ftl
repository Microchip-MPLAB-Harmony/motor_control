/*******************************************************************************
 Open loop start-up source file

  Company:
    - Microchip Technology Inc.

  File Name:
    - mc_torque_control.c

  Summary:
    - Open loop start-up source file

  Description:
    - This file implements functions for open loop start-up
 
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2022 Microchip Technology Inc. and its subsidiaries.
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

/*******************************************************************************
Headers inclusions
*******************************************************************************/
#include "mc_open_loop_startup.h"

/*******************************************************************************
Local configuration options
*******************************************************************************/

/*******************************************************************************
 Private data types
*******************************************************************************/
typedef enum
{
  startupState_Align,
  startupState_Ramp,
  startupState_Stabilize
}tmcSup_State_e;

typedef struct
{
    bool enable;
    bool initDone;
    tmcSup_State_e StartupState;
    int16_t alignmentCurrent;
    int16_t openLoopCurrent;
    uint16_t currentRampRateShift;
    int16_t currentRampRateVal;
    uint16_t speedRampRateShift;
    int16_t speedRampRateVal;
    uint16_t speedToAngleShift;
    int16_t speedToAngleVal;
    int16_t openLoopSpeed;
    int16_t openLoopFinalSpeed;
    uint32_t alignmentTimeLoopCount;
    uint32_t halfAlignmentTimeLoopCount;
    uint32_t openLoopRampTimeLoopCount;
    uint32_t openLoopStabTimeLoopCount;
    uint32_t zCounter;
}tmcSup_State_s;

/*******************************************************************************
Private variables
*******************************************************************************/
static tmcSup_State_s mcSup_State_mds;

/*******************************************************************************
Interface  variables
*******************************************************************************/

/*******************************************************************************
Macro Functions
*******************************************************************************/
#define MULT_SHIFT_S16     mcUtils_MultAndRightShiftS16
#define GET_VALUE_SHIFT     mcUtils_FloatToValueShiftPair

#define MULT_SHIFT_U32(x, y, shift) (uint32_t)( ((uint64_t)((x)) * (uint64_t)((y))) >> (shift) )

/*******************************************************************************
Private Functions
*******************************************************************************/

/*******************************************************************************
 * Interface Functions 
*******************************************************************************/
/*! \brief Initialize open loop start-up module
 * 
 * Details.
 * Initialize open loop start-up module
 * 
 * @param[in]: None 
 * @param[in/out]: None
 * @param[out]: None 
 * @return: None
 */
void  mcSupI_OpenLoopStartupInit( tmcSup_Parameters_s * const pParameters )
{  
    float32_t f32a;

    /** Link state variable structure to the module */
    pParameters->pStatePointer = (void *)&mcSup_State_mds;
    tmcSup_State_s * pState =  &mcSup_State_mds;

    /** Set parameters */
    mcSupI_ParametersSet(pParameters);

    /** Update state variables */
    f32a = ( K_CURRENT  * pParameters->alignmentCurrent ) + 0.5f;
    pState->alignmentCurrent = (int16_t)f32a;

    f32a = ( K_CURRENT * pParameters->openLoopCurrent ) + 0.5f;
    pState->openLoopCurrent = (int16_t)f32a;

    f32a = ( pParameters->alignmentTime  / pParameters->dt ) + 0.5f;
    pState->alignmentTimeLoopCount = (uint32_t)f32a;
    pState->halfAlignmentTimeLoopCount = pState->alignmentTimeLoopCount >> 1u;

    f32a = ( pParameters->openLoopRampTime / pParameters->dt ) + 0.5f;
    pState->openLoopRampTimeLoopCount = (uint32_t)f32a;

    f32a = ( pParameters->openLoopStabTime / pParameters->dt ) + 0.5f;
    pState->openLoopStabTimeLoopCount = (uint32_t)f32a;

    /** Determine current ramp rate */
    float32_t rampRate = (float32_t)pState->openLoopCurrent/ (float32_t)pState->halfAlignmentTimeLoopCount;
    GET_VALUE_SHIFT( rampRate, &pState->currentRampRateVal , &pState->currentRampRateShift );

    f32a = ( K_SPEED * pParameters->openLoopTransSpeed ) + 0.5f;
    pState->openLoopFinalSpeed = (int16_t)f32a;

    /** Determine open loop speed ramp rate */
    float32_t speedRampRate;
    speedRampRate  =  (float32_t)pState->openLoopFinalSpeed / (float32_t)pState->openLoopRampTimeLoopCount;
    GET_VALUE_SHIFT( speedRampRate, &pState->speedRampRateVal , &pState->speedRampRateShift );

    /** Speed to angle conversion factor calculation */
    float32_t speedToAngle = (float32_t)K_TIME;
    GET_VALUE_SHIFT( speedToAngle, &pState->speedToAngleVal, &pState->speedToAngleShift );

    /** Set the initial state of the state machine  */
    pState->StartupState = startupState_Align;

    /** Set initialization flag as true */
    pState->initDone = true;
}

/*! \brief Enable open loop start-up module
 *
 * Details.
 * Enable open loop start-up module
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
void  mcSupI_OpenLoopStartupEnable( tmcSup_Parameters_s * const pParameters )
{
    /** Get the linked state variable */
    tmcSup_State_s * pState;
    pState = (tmcSup_State_s *)pParameters->pStatePointer;

    if( ( NULL == pState ) || ( !pState->initDone ))
    {
         /** Initialize parameters */
        mcSupI_OpenLoopStartupInit(pParameters);
    }
    else
    {
         /** For MISRA Compliance */
    }

    /** Set enable flag as true */
    pState->enable = true;
}

/*! \brief Disable open loop start-up module
 *
 * Details.
 * Disable open loop start-up module
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
void  mcSupI_OpenLoopStartupDisable( tmcSup_Parameters_s * const pParameters )
{
    /** Get the linked state variable */
    tmcSup_State_s * pState;
    pState = (tmcSup_State_s *)pParameters->pStatePointer;

    if( NULL != pState)
    {
        /** Reset state variables  */
        mcSupI_OpenLoopStartupReset(pParameters);
    }
    else
    {
        /** For MISRA Compliance */
    }

    /** Set enable flag as true */
    pState->enable = false;

}

/*! \brief Open loop start-up
 *
 * Details.
 * Open loop start-up
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
#ifdef RAM_EXECUTE
tmcTypes_StdReturn_e __ramfunc__  mcSupI_OpenLoopStartup( const tmcSup_Parameters_s * const pParameters,
                                                            int16_t direction, int16_t * const pIQref,
                                                            int16_t * const pIDref, uint16_t * const pAngle,
                                                            int16_t * const pSpeed )
#else
tmcTypes_StdReturn_e mcSupI_OpenLoopStartup( const tmcSup_Parameters_s * const pParameters,
                                          int16_t direction, int16_t * const pIQref,
                                          int16_t * const pIDref, uint16_t * const pAngle,
                                          int16_t * const pSpeed )
#endif
{
      /** Status variable */
       tmcTypes_StdReturn_e openLoopStatus  = StdReturn_Progress;

     /** Get the linked state variable */
     tmcSup_State_s * pState;
     pState = (tmcSup_State_s *)pParameters->pStatePointer;

     if( pState->enable )
     {
         /** Execute open loop start-up */
         switch(pState->StartupState)
         {
             case startupState_Align:
             {
                 ++pState->zCounter;

                 if( pState->zCounter >= pState->alignmentTimeLoopCount )
                 {
                     pState->StartupState = startupState_Ramp;
                     pState->zCounter = 0u;
                 }

#if ( ENABLE ==  ENABLE_Q_AXIS_ALIGNMENT )
                *pIQref = pState->alignmentCurrent;
                *pIDref = 0;

                *pAngle = -direction * CONSTANT_PiBy2;
#elif ( ENABLE ==  ENABLE_D_AXIS_ALIGNMENT )
                *pIQref = 0;
                *pIDref = pState->alignmentCurrent;

                *pAngle = 0;
#endif
                 break;
             }
             case startupState_Ramp:
             {
                  ++pState->zCounter;

                  pState->openLoopSpeed = (int16_t)MULT_SHIFT_U32( pState->zCounter, pState->speedRampRateVal, pState->speedRampRateShift);

                  if( pState->openLoopFinalSpeed < pState->openLoopSpeed )
                  {
                      pState->zCounter = 0u;
                      pState->StartupState = startupState_Stabilize;
                  }
                  uint16_t delAngle = (uint16_t)MULT_SHIFT_S16(pState->openLoopSpeed, pState->speedToAngleVal, pState->speedToAngleShift );
                  *pAngle += delAngle;

                  *pIDref = 0;
                  *pIQref = pState->alignmentCurrent;

                  break;
             }

             case startupState_Stabilize:
             {
#if ( ENABLE !=  ENABLE_OPEN_LOOP_CONTROL )
                  if( pState->openLoopStabTimeLoopCount <= ++pState->zCounter )
                  {
                      pState->zCounter = 0u;
                      openLoopStatus = StdReturn_Complete;
                  }
#endif
                  uint16_t delAngle = (uint16_t)MULT_SHIFT_S16(pState->openLoopSpeed, pState->speedToAngleVal, pState->speedToAngleShift );
                 *pAngle += delAngle;
                 *pIDref = 0;
                 *pIQref = pState->alignmentCurrent;

                  break;
             }

             default:
             {
                 /** For MISRA Compliance */
             }
             break;
         }

         *pSpeed = pState->openLoopSpeed;

     }
     else
     {
         /** Reset pen loop start-up */
         mcSupI_OpenLoopStartupReset( pParameters );

         *pAngle = 0;
         *pSpeed = 0;
     }

     return openLoopStatus;
}


/*! \brief Reset Open loop start-up
 * 
 * Details.
 * Reset Open loop start-up
 * 
 * @param[in]: None 
 * @param[in/out]: None
 * @param[out]: None 
 * @return: 
 */
void mcSupI_OpenLoopStartupReset( const tmcSup_Parameters_s * const pParameters )
{
    /** Get the linked state variable */
    tmcSup_State_s * pState;
    pState = (tmcSup_State_s *)pParameters->pStatePointer;

    /** Reset open loop startup state variables  */
    pState->StartupState = startupState_Align;
    pState->openLoopSpeed = 0;
    pState->zCounter = 0u;
}
