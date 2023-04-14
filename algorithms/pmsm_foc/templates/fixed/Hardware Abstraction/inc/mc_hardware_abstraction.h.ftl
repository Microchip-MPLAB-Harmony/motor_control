/*******************************************************************************
  System Definitions

  File Name:
    mc_hardware_abstraction.h

  Summary:
    Header file which shares global variables and function prototypes.

  Description:
    This file contains the global variables and function prototypes for hardware abstraction.

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

#ifndef MCHAL_H
#define MCHAL_H


/*******************************************************************************
  Header inclusions  
*******************************************************************************/
#include "mc_types.h"
#include "definitions.h"

/*******************************************************************************
 * User defined data structure 
*******************************************************************************/

/*******************************************************************************
 * Interface variables 
*******************************************************************************/
extern uint16_t mcHalI_IaAdcInput_gdu16;
extern uint16_t mcHalI_IbAdcInput_gdu16;
extern uint16_t mcHalI_UbusAdcInput_gdu16;
extern uint16_t mcHalI_Potentiometer_gdu16;

extern int16_t mcPwmI_Duty_gau16[3u];

/*******************************************************************************
 * Interface Functions
*******************************************************************************/

/*! \brief Enable PWM inverter 
 * 
 * Details.
 * Enable PWM inverter
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcHalI_InverterPwmEnable( void );

/*! \brief Disable PWM inverter 
 * 
 * Details.
 * Disable PWM inverter
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcHalI_InverterPwmDisable( void );


/*! \brief Get start stop input status 
 * 
 * Details.
 * Get start stop button status
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
uint32_t mcHalI_StartStopButtonGet( void );


/*! \brief Get direction input status
 * 
 * Details.
 * Get direction input status
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
uint32_t mcHalI_DirectionButtonGet( void );


/*! \brief Set direction indicator
 * 
 * Details.
 * Set direction indicator
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcHal_DirectionIndicationSet( void );


/*! \brief Set fault indicator
 * 
 * Details.
 * Set fault indicator
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcHal_FaultIndicationSet( void );

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
void mcHalI_AdcEnable( void );


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
void mcHalI_AdcCallBackRegister( ADC_CALLBACK callback, uintptr_t context );

/*! \brief PWM fault callback function
 * 
 * Details.
 * PWM fault callback function
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
 void mcHalI_PwmCallbackRegister( TCC_CALLBACK callback, uintptr_t context );

 /*! \brief PWM interrupt enable
  *
  * Details.
  * PWM interrupt enable
  *
  * @param[in]:
  * @param[in/out]:
  * @param[out]:
  * @return:
  */
 void mcHalI_PwmInterruptEnable( void );

/*! \brief Get inverter PWM period 
 * 
 * Details.
 * Get inverter PWM period
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
 __STATIC_FORCEINLINE uint32_t mcHal_InverterPwmPeriodGet( void )
{
    return TCC0_PWM24bitPeriodGet();
}

/*! \brief Inverter Duty Set
 * 
 * Details.
 * Sets the PWM inverter duty
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
__STATIC_FORCEINLINE void mcHalI_InverterPwmSet( const int16_t * const dutyCycle )
{
    uint8_t status;
    status = (uint8_t)TCC0_PWM24bitDutySet(TCC0_CHANNEL0, (uint32_t)dutyCycle[0] );
    status &= (uint8_t)TCC0_PWM24bitDutySet(TCC0_CHANNEL1, (uint32_t)dutyCycle[1] );
    status &= (uint8_t)TCC0_PWM24bitDutySet(TCC0_CHANNEL2, (uint32_t)dutyCycle[2] );

    if( 0u == status )
    {
       /** ToDO: Log error */
    }
}


/*! \brief Set analog channel for phase A current
 * 
 * Details.
 * Set analog channel for phase A current
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
__STATIC_FORCEINLINE void mcHalI_PhaseACurrentChannelSet( void )
{   
    /* Re-assign the ADC Channel  */
    ADC0_ChannelSelect( ADC_POSINPUT_AIN2, ADC_NEGINPUT_GND); 
}

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
__STATIC_FORCEINLINE void mcHalI_PhaseACurrentGet( void )
{
     mcHalI_IaAdcInput_gdu16 =   ADC0_ConversionResultGet();
}

/*! \brief Set analog channel for phase B current
 * 
 * Details.
 * Set analog channel for phase B current
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
__STATIC_FORCEINLINE void mcHalI_PhaseBCurrentChannelSet( void )
{   
    /* Re-assign the ADC Channel  */
    ADC1_ChannelSelect( ADC_POSINPUT_AIN5, ADC_NEGINPUT_GND);
}

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
__STATIC_FORCEINLINE void mcHalI_PhaseBCurrentGet( void )
{
   mcHalI_IbAdcInput_gdu16 = ADC1_ConversionResultGet();
}


/*! \brief Set analog channel for DC link voltage
 * 
 * Details.
 * Set analog channel for DC link voltage
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
__STATIC_FORCEINLINE void mcHalI_DcLinkVoltageChannelSet( void )
{      
    /* Re-assign the ADC Channel  */
    ADC0_ChannelSelect( ADC_POSINPUT_AIN9, ADC_NEGINPUT_GND); 
}

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
__STATIC_FORCEINLINE void mcHalI_DcLinkVoltageGet( void )
{
    /* Get ADC value for DC bus voltage */
    mcHalI_UbusAdcInput_gdu16 = ADC0_ConversionResultGet();
}

/*! \brief Set analog signals for potentiometer 
 * 
 * Details.
 * Get analog signals from ADC peripheral
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
__STATIC_FORCEINLINE void mcHalI_PotentiometerChannelSet( void )
{    
    /* Re-assign the ADC Channel  */
    ADC1_ChannelSelect( ADC_POSINPUT_AIN0, ADC_NEGINPUT_GND); 
}

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
__STATIC_FORCEINLINE void mcHalI_PotentiometerInputGet( void )
{
    /* Get ADC value for DC bus voltage */
    mcHalI_Potentiometer_gdu16 = ADC1_ConversionResultGet();
}

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
__STATIC_FORCEINLINE void mcHalI_AdcInterruptClear( void )
{
   ADC0_InterruptsClear(ADC_INTFLAG_Msk);   
} 

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
__STATIC_FORCEINLINE void mcHalI_AdcInterruptDisable( void )
{
    ADC0_InterruptsDisable(ADC_INTFLAG_RESRDY_Msk);     
} 

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
__STATIC_FORCEINLINE void mcHalI_AdcInterruptEnable( void )
{
    ADC0_InterruptsEnable(ADC_INTFLAG_RESRDY_Msk);     
} 

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
__STATIC_FORCEINLINE void mcHalI_AdcConversionTrigger( void )
{
    ADC0_ConversionStart();     
} 

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
__STATIC_FORCEINLINE void mcHalI_AdcConversionWait( void )
{
    while(ADC0_REGS->ADC_INTFLAG != ADC_INTFLAG_RESRDY_Msk)
    {
        __NOP();
    }
} 

bool mcHalI_StartStopButtonState( void );
bool mcHalI_DirectionButtonState( void );
#endif // MCHAL_H
