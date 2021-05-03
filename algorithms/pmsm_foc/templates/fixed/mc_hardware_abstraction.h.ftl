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
#include <stdint.h>
#include <sys/attribs.h>
#include "definitions.h"
#include "mc_interface_handling.h"

/*******************************************************************************
 * User defined data structure 
*******************************************************************************/

typedef enum
{
    ADC_PHASE_CURRENT_U,
    ADC_PHASE_CURRENT_V,
    ADC_DC_LINK_VOLTAGE,
    ADC_RECTIFIED_CURRENT,
    ADC_RECTIFIED_VOLTAGE,
    ADC_POTENTIOMETER,
    ADC_INPUT_SIGNALS_MAX
}tMCSMA_ADC_SIGNAL_E;

/*******************************************************************************
 * Interface variables 
*******************************************************************************/

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
void mcHalI_VoltageSourceInverterPwmEnable( void );

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
void mcHalI_VoltageSourceInverterPwmDisable( void );


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
void mcHalI_ADCEnable( void );


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
 void mcHalI_PwmCallBackRegister( TCC_CALLBACK callback, uintptr_t context );

/*! \brief Get Inverter input DC  current 
 * 
 * Details.
 *  Get Inverter input DC  current 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcHal_InverterInputCurrentGet( void );

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
__STATIC_INLINE uint32_t mcHal_InverterPwmPeriodGet( void )
{
    return ${.vars["${MCPMSMFOC_PWMPLIB?lower_case}"].PWM_GET_PERIOD_API}();
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
__STATIC_INLINE void mcHal_InverterDutySet( const uint32_t * const dutyCycle )
{
    ${.vars["${MCPMSMFOC_PWMPLIB?lower_case}"].PWM_SET_DUTY_API}(${.vars["${MCPMSMFOC_PWMPLIB?lower_case}"].PWM_PH_U}, dutyCycle[0] );
    ${.vars["${MCPMSMFOC_PWMPLIB?lower_case}"].PWM_SET_DUTY_API}(${.vars["${MCPMSMFOC_PWMPLIB?lower_case}"].PWM_PH_V}, dutyCycle[1] );
    ${.vars["${MCPMSMFOC_PWMPLIB?lower_case}"].PWM_SET_DUTY_API}(${.vars["${MCPMSMFOC_PWMPLIB?lower_case}"].PWM_PH_W}, dutyCycle[2] );  
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
__STATIC_INLINE void mcHalI_PhaseACurrentChannelSet( void )
{   
    /* Re-assign the ADC Channel  */
    ${.vars["${MCPMSMFOC_ADCPLIB?lower_case}"].ADC_CHANNEL_SELECT_API}( ${.vars["${MCPMSMFOC_ADCPLIB?lower_case}"].ADC_CH_PHASE_U}, ADC_NEGINPUT_GND); 
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
__STATIC_INLINE void mcHalI_PhaseACurrentGet( void )
{
    mcHalI_PhaseACurrent_gdu16 =   ${.vars["${MCPMSMFOC_ADCPLIB?lower_case}"].ADC_GET_RESULT_API}();
    
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
__STATIC_INLINE void mcHalI_PhaseBCurrentChannelSet( void )
{   
    /* Re-assign the ADC Channel  */
    ${.vars["${MCPMSMFOC_ADCPLIB1?lower_case}"].ADC_CHANNEL_SELECT_API}( ADC_POSINPUT_AIN${MCPMSMFOC_PHASEV_CH}, ADC_NEGINPUT_GND);
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
__STATIC_INLINE void mcHalI_PhaseBCurrentGet( void )
{
    mcHalI_PhaseBCurrent_gdu16 = ${.vars["${MCPMSMFOC_ADCPLIB1?lower_case}"].ADC_GET_RESULT_API}();
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
__STATIC_INLINE void mcHalI_DcLinkVoltageChannelSet( void )
{      
    /* Re-assign the ADC Channel  */
    ${.vars["${MCPMSMFOC_ADCPLIB?lower_case}"].ADC_CHANNEL_SELECT_API}( ${.vars["${MCPMSMFOC_ADCPLIB?lower_case}"].ADC_CH_VDC_BUS}, ADC_NEGINPUT_GND); 
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
__STATIC_INLINE void mcHalI_DcLinkVoltageGet( void )
{
    /* Get ADC value for DC bus voltage */
    mcHalI_DcBusVoltage_gdu16 = ${.vars["${MCPMSMFOC_ADCPLIB?lower_case}"].ADC_GET_RESULT_API}();
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
__STATIC_INLINE void mcHalI_PotentiometerChannelSet( void )
{    
    /* Re-assign the ADC Channel  */
    ${.vars["${MCPMSMFOC_ADCPLIB1?lower_case}"].ADC_CHANNEL_SELECT_API}( ${.vars["${MCPMSMFOC_ADCPLIB1?lower_case}"].ADC_CH_POT}, ADC_NEGINPUT_GND); 
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
__STATIC_INLINE void mcHalI_PotentiometerInputGet( void )
{
    /* Get ADC value for DC bus voltage */
    mcHalI_Potentiometer_gdu16 = ${.vars["${MCPMSMFOC_ADCPLIB1?lower_case}"].ADC_GET_RESULT_API}();
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
__STATIC_INLINE void mcHalI_AdcInterruptClear( void )
{
   ${.vars["${MCPMSMFOC_ADCPLIB?lower_case}"].ADC_INT_CLEAR_API}(ADC_INTFLAG_Msk);   
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
__STATIC_INLINE void mcHalI_AdcInterruptDisable( void )
{
    ${.vars["${MCPMSMFOC_ADCPLIB?lower_case}"].ADC_INT_DISABLE_API}(ADC_INTFLAG_RESRDY_Msk);     
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
__STATIC_INLINE void mcHalI_AdcInterruptEnable( void )
{
    ${.vars["${MCPMSMFOC_ADCPLIB?lower_case}"].ADC_INT_ENABLE_API}(ADC_INTFLAG_RESRDY_Msk);     
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
__STATIC_INLINE void mcHalI_AdcConversionTrigger( void )
{
    ${.vars["${MCPMSMFOC_ADCPLIB?lower_case}"].ADC_START_CONV_API}();     
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
__STATIC_INLINE void mcHalI_AdcConversionWait( void )
{
    while(ADC0_REGS->ADC_INTFLAG != ADC_INTFLAG_RESRDY_Msk);    
} 
#endif // MCHAL_H