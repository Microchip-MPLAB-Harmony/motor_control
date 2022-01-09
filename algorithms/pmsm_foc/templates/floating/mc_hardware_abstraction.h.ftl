/*******************************************************************************
 Space Vector PWM interface file

  Company:
    Microchip Technology Inc.

  File Name:
    mc_pwm.h

  Summary:
    Header file for mc_pwm.c

  Description:
    This file contains the data structures and function prototypes used by
    PWM module
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

#ifndef MCHAL_H_    // Guards against multiple inclusion
#define MCHAL_H_


// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

/*  This section lists the other files that are included in this file.
*/

#include <stddef.h>
#include "definitions.h"
#include "mc_interface_handling.h"

/*******************************************************************************
 Constants
 *******************************************************************************/
#define     SW_DEBOUNCE_DLY_500MS      (uint32_t)( 500 )


/*******************************************************************************
 Private data-types
 *******************************************************************************/
typedef enum
{
    ButtonState_Released,
    buttonState_Pressed
}tmcHal_ButtonState_e;

typedef enum
{
    buttonStateMachine_Ready,
    buttonStateMachine_Wait
}tmcHal_ButtonStateMachine_e;

typedef struct
{
    tmcHal_ButtonStateMachine_e state;
    uint32_t debounceCounter;
}tmcHal_ButtonState_s;

typedef enum _tmcHal_InverterInstanceId_e
{
    inverterInstance_01,
    inverterInstance_02,
    inverterInstance_max 
}tmcHal_InverterInstanceId_e;

/*******************************************************************************
 * Interface variables 
 *******************************************************************************/


/*******************************************************************************
 Function macros 
 *******************************************************************************/

/*******************************************************************************
 Interface Functions 
 *******************************************************************************/
/*! \brief Set PWM Channels of the voltage source inverter
 * 
 * Details.
 * Set PWM Channels of the voltage source inverter
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcHalI_VoltageSourceInverterPwmSet( tmcHal_InverterInstanceId_e Id,  uint16_t * duty );


/*! \brief Disable PWM Channels of the voltage source inverter
 * 
 * Details.
 * Disable PWM Channels of the voltage source inverter
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcHalI_VoltageSourceInverterPwmDisable(void);


/*! \brief Enable PWM Channels of the voltage source inverter
 * 
 * Details.
 * Enable PWM Channels of the voltage source inverter
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcHalI_VoltageSourceInverterPwmEnable(void);

/*! \brief Get voltage signal from ADC port
 * 
 * Details.
 * Get voltage signal from ADC port
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
uint16_t mcHalI_VoltageSignalGet( void );


/*! \brief Get phase A current from ADC port 
 * 
 * Details.
 * Get phase A current from ADC port 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
uint16_t mcHalI_PhaseACurrentSignalGet( uint8_t Id  );


/*! \brief Get voltage signal from ADC port
 * 
 * Details.
 * Get voltage signal from ADC port
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
uint16_t mcHalI_PhaseBCurrentSignalGet( uint8_t Id  );

/*! \brief Get potentiometer signal from ADC port
 * 
 * Details.
 * Get potentiometer signal from ADC port
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
uint16_t mcHalI_PotentiometerSignalGet( void );


/*! \brief Button Polling 
 * 
 * Details.
 * Button polling 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcHal_ButtonResponse( const tmcHal_ButtonState_e  buttonState,  void (*buttonFunction)(void) );

/*! \brief ADC Enable
 * 
 * Details.
 * ADC Enable
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcHalI_ADCEnable( void );

/*! \brief Get analog signals from ADC peripheral
 * 
 * Details.
 * Get analog signals from ADC peripheral
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcHalI_AdcInterruptDisable( void );

/*! \brief Get analog signals from ADC peripheral
 * 
 * Details.
 * Get analog signals from ADC peripheral
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcHalI_AdcInterruptEnable( void );

/*! \brief Get analog signals from ADC peripheral
 * 
 * Details.
 * Get analog signals from ADC peripheral
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcHalI_AdcInterruptClear( void );


/*! \brief ADC callback function
 * 
 * Details.
 * ADC callback function
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcHalI_AdcCallBackRegister( ADC_CALLBACK  callback, uintptr_t context );

/*! \brief PWM timer Start
 * 
 * Details.
 * PWM timer Start
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcHalI_PwmTimerStart( void );

/*! \brief Get analog signals from ADC peripheral
 * 
 * Details.
 * Get analog signals from ADC peripheral
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcHalI_PwmInterruptDisable( void );

/*! \brief Get analog signals from ADC peripheral
 * 
 * Details.
 * Get analog signals from ADC peripheral
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcHalI_PwmInterruptEnable( void );


/*! \brief Get analog signals from ADC peripheral
 * 
 * Details.
 * Get analog signals from ADC peripheral
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcHalI_PwmInterruptClear( void );

/*! \brief Get analog signals from ADC peripheral
 * 
 * Details.
 * Get analog signals from ADC peripheral
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcHalI_PwmEnable( void );

/*! \brief Get PWM period
 * 
 * Details.
 * Get PWM period
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
uint16_t mcHalI_PwmPeriodGet( void );

/*! \brief PWM callback function
 * 
 * Details.
 * PWM callback function
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcHalI_PwmCallbackRegister( TCC_CALLBACK  callback, uintptr_t context );

/*! \brief Read Group 01 signal 
 * 
 * Details.
 * Read Group 01 signal
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcHalI_Group01SignalRead( uint16_t Id  );

/*! \brief Read Group 02 signal 
 * 
 * Details.
 * Read Group 02 signal
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcHalI_Group02SignalRead( uint16_t Id  );

/*! \brief Re-assign ADC channels for  Group 01 signals and enable hardware trigger 
 * 
 * Details.
 * Re-assign ADC channels for  Group 01 signals and enable hardware trigger
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcHalI_Group01SignalHardwareTrigger( uint16_t Id  );


/*! \brief Re-assign ADC channels for  Group 02 signals and enable software trigger 
 * 
 * Details.
 * Re-assign ADC channels for  Group 02 signals and enable software trigger 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcHalI_Group02SignalSoftwareTrigger( uint16_t Id  );


<#if MCPMSMFOC_POSITION_CALC_ALGORITHM == 'SENSORED_ENCODER'>
/*! \brief Start the encoder peripheral
 * 
 * Details.
 * Start the encoder peripheral
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcHalI_EncoderStart( uint16_t Id  );

/*! \brief Get the encoder count
 * 
 * Details.
 * Get the encoder count
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
int32_t mcHalI_EncoderPositionGet( uint16_t Id  );

<#if __PROCESSOR?matches(".*PIC32MK.*") == true>
/*! \brief Get the encoder velocity count
 * 
 * Details.
 * Get the encoder count
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
int32_t mcHalI_EncoderVelocityGet( uint16_t Id  );

</#if>

</#if>

#endif //MCHAL_H

/**
 End of File
*/
