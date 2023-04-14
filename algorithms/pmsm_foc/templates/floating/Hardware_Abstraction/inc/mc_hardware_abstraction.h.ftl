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
 * Interface variables
*******************************************************************************/
/** Analog interfaces */
extern uint16_t mcHalI_IaAdcInput_gdu16;
extern uint16_t mcHalI_IbAdcInput_gdu16;
extern uint16_t mcHalI_UbusAdcInput_gdu16;
extern uint16_t mcHalI_Potentiometer_gdu16;
extern int16_t mcPwmI_Duty_gau16[3u];

/*******************************************************************************
 * User defined data structure 
*******************************************************************************/

/*******************************************************************************
 * Static interface Functions
*******************************************************************************/

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
__STATIC_INLINE uint16_t mcHalI_PwmPeriodGet( void )
{
<#if __PROCESSOR?matches(".*SAME54.*") == true>
    return (uint16_t)${MCPMSMFOC_PWM_INSTANCE}_PWM24bitPeriodGet();
<#elseif __PROCESSOR?matches(".*SAME70.*") == true>
    return (uint16_t)${MCPMSMFOC_PWM_INSTANCE}_ChannelPeriodGet(PWM_CHANNEL_${MCPMSMFOC_PWM_INSTANCE_PWM_A_FINAL});
<#elseif __PROCESSOR?matches(".*PIC32MK.*") == true>
    return (uint16_t)${MCPMSMFOC_PWM_INSTANCE}_PrimaryPeriodGet();
</#if>
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
<#if __PROCESSOR?matches(".*SAME54.*") == true>
    uint8_t status;
    uint16_t period;
    uint16_t duty[3u] = {0u};
    
    period = (uint16_t)mcHalI_PwmPeriodGet();
    duty[0u] = period - (uint16_t)dutyCycle[0u];
    duty[1u] = period - (uint16_t)dutyCycle[1u];
    duty[2u] = period - (uint16_t)dutyCycle[2u];
    
    status = (uint8_t)${MCPMSMFOC_PWM_INSTANCE}_PWM24bitDutySet(${MCPMSMFOC_PWM_INSTANCE}_CHANNEL${MCPMSMFOC_PWM_INSTANCE_PWM_A_FINAL}, duty[0u] );
    status &= (uint8_t)${MCPMSMFOC_PWM_INSTANCE}_PWM24bitDutySet(${MCPMSMFOC_PWM_INSTANCE}_CHANNEL${MCPMSMFOC_PWM_INSTANCE_PWM_B_FINAL}, duty[1u] );
    status &= (uint8_t)${MCPMSMFOC_PWM_INSTANCE}_PWM24bitDutySet(${MCPMSMFOC_PWM_INSTANCE}_CHANNEL${MCPMSMFOC_PWM_INSTANCE_PWM_C_FINAL}, duty[2u] );

    if( 0u == status )
    {
      /** ToDO: Log error */
    }
<#elseif __PROCESSOR?matches(".*SAME70.*") == true>
    uint16_t period;
    uint16_t duty[3u] = {0u};
    
    period = (uint16_t)mcHalI_PwmPeriodGet();
    duty[0u] = period - (uint16_t)dutyCycle[0u];
    duty[1u] = period - (uint16_t)dutyCycle[1u];
    duty[2u] = period - (uint16_t)dutyCycle[2u];

    ${MCPMSMFOC_PWM_INSTANCE}_ChannelDutySet(PWM_CHANNEL_${MCPMSMFOC_PWM_INSTANCE_PWM_A_FINAL}, duty[0u] );
    ${MCPMSMFOC_PWM_INSTANCE}_ChannelDutySet(PWM_CHANNEL_${MCPMSMFOC_PWM_INSTANCE_PWM_B_FINAL}, duty[1u] );
    ${MCPMSMFOC_PWM_INSTANCE}_ChannelDutySet(PWM_CHANNEL_${MCPMSMFOC_PWM_INSTANCE_PWM_C_FINAL}, duty[2u] );
    
<#elseif __PROCESSOR?matches(".*PIC32MK.*") == true>
    ${MCPMSMFOC_PWM_INSTANCE}_ChannelPrimaryDutySet(${MCPMSMFOC_PWM_INSTANCE}_CH_${MCPMSMFOC_PWM_INSTANCE_PWM_A_FINAL}, (uint16_t)dutyCycle[0] );
    ${MCPMSMFOC_PWM_INSTANCE}_ChannelPrimaryDutySet(${MCPMSMFOC_PWM_INSTANCE}_CH_${MCPMSMFOC_PWM_INSTANCE_PWM_B_FINAL}, (uint16_t)dutyCycle[1] );
    ${MCPMSMFOC_PWM_INSTANCE}_ChannelPrimaryDutySet(${MCPMSMFOC_PWM_INSTANCE}_CH_${MCPMSMFOC_PWM_INSTANCE_PWM_C_FINAL}, (uint16_t)dutyCycle[2] );
</#if>
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
<#if __PROCESSOR?matches(".*SAME54.*") == true>
    mcHalI_IaAdcInput_gdu16 = ${MCPMSMFOC_PHASE_CURRENT_IA_UNIT}_ConversionResultGet();
<#elseif __PROCESSOR?matches(".*SAME70.*") == true>
    mcHalI_IaAdcInput_gdu16 = ${MCPMSMFOC_PHASE_CURRENT_IA_UNIT}_ChannelResultGet(AFEC_CH${MCPMSMFOC_PHASE_CURRENT_IA_UNIT_PHASE_CURRENT_IA_FINAL});
<#elseif __PROCESSOR?matches(".*PIC32MK.*") == true>
  <#if MCPMSMFOC_PHASE_CURRENT_IA_UNIT == "ADC7" >
    mcHalI_IaAdcInput_gdu16 = ${MCPMSMFOC_PHASE_CURRENT_IA_UNIT}_ChannelResultGet(AFEC_CH${MCPMSMFOC_PHASE_CURRENT_IA_UNIT_PHASE_CURRENT_IA_FINAL});
  <#elseif MCPMSMFOC_PHASE_CURRENT_IA_UNIT == "ADC0"> 
    mcHalI_IaAdcInput_gdu16 = ADCHS_ChannelResultGet(ADCHS_CH0);
  <#elseif MCPMSMFOC_PHASE_CURRENT_IA_UNIT == "ADC1"> 
    mcHalI_IaAdcInput_gdu16 = ADCHS_ChannelResultGet(ADCHS_CH1);
  <#elseif MCPMSMFOC_PHASE_CURRENT_IA_UNIT == "ADC2"> 
    mcHalI_IaAdcInput_gdu16 = ADCHS_ChannelResultGet(ADCHS_CH2);
  <#elseif MCPMSMFOC_PHASE_CURRENT_IA_UNIT == "ADC3"> 
    mcHalI_IaAdcInput_gdu16 = ADCHS_ChannelResultGet(ADCHS_CH3);
  <#elseif MCPMSMFOC_PHASE_CURRENT_IA_UNIT == "ADC4"> 
    mcHalI_IaAdcInput_gdu16 = ADCHS_ChannelResultGet(ADCHS_CH4);
  <#elseif MCPMSMFOC_PHASE_CURRENT_IA_UNIT == "ADC5"> 
    mcHalI_IaAdcInput_gdu16 = ADCHS_ChannelResultGet(ADCHS_CH5);
  </#if> 
</#if>    
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
<#if __PROCESSOR?matches(".*SAME54.*") == true>
    mcHalI_IbAdcInput_gdu16 =  ${MCPMSMFOC_PHASE_CURRENT_IB_UNIT}_ConversionResultGet();   
<#elseif __PROCESSOR?matches(".*SAME70.*") == true>
    mcHalI_IbAdcInput_gdu16 =  ${MCPMSMFOC_PHASE_CURRENT_IB_UNIT}_ChannelResultGet(AFEC_CH${MCPMSMFOC_PHASE_CURRENT_IB_UNIT_PHASE_CURRENT_IB_FINAL});
<#elseif __PROCESSOR?matches(".*PIC32MK.*") == true>
  <#if MCPMSMFOC_PHASE_CURRENT_IB_UNIT == "ADC7" >
    mcHalI_IbAdcInput_gdu16 =  ADCHS_ChannelResultGet(ADCHS_CH${MCPMSMFOC_PHASE_CURRENT_IB_UNIT_PHASE_CURRENT_IB_FINAL});
  <#elseif MCPMSMFOC_PHASE_CURRENT_IB_UNIT == "ADC0"> 
    mcHalI_IbAdcInput_gdu16 =  ADCHS_ChannelResultGet(ADCHS_CH0);
  <#elseif MCPMSMFOC_PHASE_CURRENT_IB_UNIT == "ADC1"> 
    mcHalI_IbAdcInput_gdu16 =  ADCHS_ChannelResultGet(ADCHS_CH1);
  <#elseif MCPMSMFOC_PHASE_CURRENT_IB_UNIT == "ADC2"> 
    mcHalI_IbAdcInput_gdu16 =  ADCHS_ChannelResultGet(ADCHS_CH2);
  <#elseif MCPMSMFOC_PHASE_CURRENT_IB_UNIT == "ADC3"> 
    mcHalI_IbAdcInput_gdu16 =  ADCHS_ChannelResultGet(ADCHS_CH3);
  <#elseif MCPMSMFOC_PHASE_CURRENT_IB_UNIT == "ADC4"> 
    mcHalI_IbAdcInput_gdu16 =  ADCHS_ChannelResultGet(ADCHS_CH4);
  <#elseif MCPMSMFOC_PHASE_CURRENT_IB_UNIT == "ADC5"> 
    mcHalI_IbAdcInput_gdu16 =  ADCHS_ChannelResultGet(ADCHS_CH5);
  </#if>
</#if>
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
    /** Get ADC value for DC bus voltage */
<#if __PROCESSOR?matches(".*SAME54.*") == true>
    mcHalI_UbusAdcInput_gdu16 = ADC1_ConversionResultGet();
<#elseif __PROCESSOR?matches(".*SAME70.*") == true>
    mcHalI_UbusAdcInput_gdu16 = AFEC0_ChannelResultGet(AFEC_CH${MCPMSMFOC_BUS_VOLTAGE_VDC_UNIT_BUS_VOLTAGE_VDC_FINAL});
<#elseif __PROCESSOR?matches(".*PIC32MK.*") == true>  
  <#if MCPMSMFOC_POTENTIOMETER_VPOT_UNIT == "ADC7" >
    mcHalI_UbusAdcInput_gdu16 = ADCHS_ChannelResultGet(ADCHS_CH${MCPMSMFOC_BUS_VOLTAGE_VDC_UNIT_BUS_VOLTAGE_VDC_FINAL});
  <#elseif MCPMSMFOC_BUS_VOLTAGE_VDC_UNIT == "ADC0"> 
    mcHalI_UbusAdcInput_gdu16 = ADCHS_ChannelResultGet(ADCHS_CH0);
  <#elseif MCPMSMFOC_BUS_VOLTAGE_VDC_UNIT == "ADC1"> 
    mcHalI_UbusAdcInput_gdu16 = ADCHS_ChannelResultGet(ADCHS_CH1);
  <#elseif MCPMSMFOC_BUS_VOLTAGE_VDC_UNIT == "ADC2"> 
    mcHalI_UbusAdcInput_gdu16 = ADCHS_ChannelResultGet(ADCHS_CH2);
  <#elseif MCPMSMFOC_BUS_VOLTAGE_VDC_UNIT == "ADC3"> 
    mcHalI_UbusAdcInput_gdu16 = ADCHS_ChannelResultGet(ADCHS_CH3);
  <#elseif MCPMSMFOC_BUS_VOLTAGE_VDC_UNIT == "ADC4"> 
    mcHalI_UbusAdcInput_gdu16 = ADCHS_ChannelResultGet(ADCHS_CH4);
  <#elseif MCPMSMFOC_BUS_VOLTAGE_VDC_UNIT == "ADC5"> 
    mcHalI_UbusAdcInput_gdu16 = ADCHS_ChannelResultGet(ADCHS_CH5);
  </#if> 
</#if>
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
    /** Get ADC value for DC bus voltage */
<#if __PROCESSOR?matches(".*SAME54.*") == true>
    mcHalI_Potentiometer_gdu16 = ${MCPMSMFOC_POTENTIOMETER_VPOT_UNIT}_ConversionResultGet();
<#elseif __PROCESSOR?matches(".*SAME70.*") == true>
    mcHalI_Potentiometer_gdu16 = ${MCPMSMFOC_POTENTIOMETER_VPOT_UNIT}_ChannelResultGet(AFEC_CH${MCPMSMFOC_POTENTIOMETER_VPOT_UNIT_POTENTIOMETER_VPOT_FINAL});
<#elseif __PROCESSOR?matches(".*PIC32MK.*") == true>
  <#if MCPMSMFOC_POTENTIOMETER_VPOT_UNIT == "ADC7" >
    mcHalI_Potentiometer_gdu16 = ADCHS_ChannelResultGet(ADCHS_CH${MCPMSMFOC_POTENTIOMETER_VPOT_UNIT_POTENTIOMETER_VPOT_FINAL});
  <#elseif MCPMSMFOC_POTENTIOMETER_VPOT_UNIT == "ADC0"> 
    mcHalI_Potentiometer_gdu16 = ADCHS_ChannelResultGet(ADCHS_CH0);
  <#elseif MCPMSMFOC_POTENTIOMETER_VPOT_UNIT == "ADC1"> 
    mcHalI_Potentiometer_gdu16 = ADCHS_ChannelResultGet(ADCHS_CH1);
  <#elseif MCPMSMFOC_POTENTIOMETER_VPOT_UNIT == "ADC2"> 
    mcHalI_Potentiometer_gdu16 = ADCHS_ChannelResultGet(ADCHS_CH2);
  <#elseif MCPMSMFOC_POTENTIOMETER_VPOT_UNIT == "ADC3"> 
    mcHalI_Potentiometer_gdu16 = ADCHS_ChannelResultGet(ADCHS_CH3);
  <#elseif MCPMSMFOC_POTENTIOMETER_VPOT_UNIT == "ADC4"> 
    mcHalI_Potentiometer_gdu16 = ADCHS_ChannelResultGet(ADCHS_CH4);
  <#elseif MCPMSMFOC_POTENTIOMETER_VPOT_UNIT == "ADC5"> 
    mcHalI_Potentiometer_gdu16 = ADCHS_ChannelResultGet(ADCHS_CH5);
  </#if> 
</#if>
}

<#if __PROCESSOR?matches(".*SAME54.*") == true>

/*! \brief Potentiometer input software trigger 
 * 
 * Details.
 *  Potentiometer input software trigger 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
__STATIC_FORCEINLINE void mcHalI_PotentiometerChannelSelect( void )
{
    ${MCPMSMFOC_POTENTIOMETER_VPOT_UNIT}_ChannelSelect( ADC_POSINPUT_AIN${MCPMSMFOC_POTENTIOMETER_VPOT_UNIT_POTENTIOMETER_VPOT_FINAL}, ADC_NEGINPUT_GND);
}

/*! \brief DC bus input software trigger 
 * 
 * Details.
 *  DC bus input software trigger 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
__STATIC_FORCEINLINE void mcHalI_DcLinkVoltageChannelSelect( void  )
{
    ${MCPMSMFOC_BUS_VOLTAGE_VDC_UNIT}_ChannelSelect( ADC_POSINPUT_AIN${MCPMSMFOC_BUS_VOLTAGE_VDC_UNIT_BUS_VOLTAGE_VDC_FINAL}, ADC_NEGINPUT_GND);
}


__STATIC_FORCEINLINE void mcHalI_AdcSoftwareConversionStart( void )
{
    /* Enable software  trigger */
    ${MCPMSMFOC_PHASE_CURRENT_IA_UNIT}_InterruptsClear(ADC_STATUS_MASK);
    ${MCPMSMFOC_PHASE_CURRENT_IA_UNIT}_InterruptsDisable( ADC_STATUS_RESRDY );
    ${MCPMSMFOC_PHASE_CURRENT_IA_UNIT}_ConversionStart(); 
}

/*! \brief Phase A current input hardware trigger 
 * 
 * Details.
 *  Phase A current input hardware trigger 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
__STATIC_FORCEINLINE void mcHalI_PhaseACurrentChannelSelect( void  )
{
    ${MCPMSMFOC_PHASE_CURRENT_IA_UNIT}_ChannelSelect( ADC_POSINPUT_AIN${MCPMSMFOC_PHASE_CURRENT_IA_UNIT_PHASE_CURRENT_IA_FINAL}, ADC_NEGINPUT_GND);
}

/*! \brief Phase B current input hardware trigger 
 * 
 * Details.
 *  Phase B current input hardware trigger 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
__STATIC_FORCEINLINE void mcHalI_PhaseBCurrentChannelSelect( void  )
{
    ${MCPMSMFOC_PHASE_CURRENT_IB_UNIT}_ChannelSelect( ADC_POSINPUT_AIN${MCPMSMFOC_PHASE_CURRENT_IB_UNIT_PHASE_CURRENT_IB_FINAL}, ADC_NEGINPUT_GND);   
}

__STATIC_FORCEINLINE void mcHalI_AdcHardwareTriggerRenable( void )
{
    /* Re-enable hardware trigger */
    ${MCPMSMFOC_PHASE_CURRENT_IA_UNIT}_InterruptsClear(ADC_STATUS_MASK);
    ${MCPMSMFOC_PHASE_CURRENT_IA_UNIT}_InterruptsEnable( ADC_STATUS_RESRDY );
}
</#if>

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
<#if __PROCESSOR?matches(".*SAME54.*") == true>
    ADC0_InterruptsClear(ADC_STATUS_MASK);
<#elseif __PROCESSOR?matches(".*SAME70.*") == true>
    NVIC_ClearPendingIRQ(AFEC0_IRQn);
<#elseif __PROCESSOR?matches(".*PIC32MK.*") == true>
    EVIC_SourceStatusClear(${.vars["${MCPMSMFOC_ADC_MODULE_01?lower_case}"].INTERRUPT_ADC_RESULT});
</#if>
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
<#if __PROCESSOR?matches(".*SAME54.*") == true>
    ADC0_InterruptsDisable( ADC_STATUS_RESRDY );
<#elseif __PROCESSOR?matches(".*SAME70.*") == true>
    NVIC_DisableIRQ(AFEC0_IRQn);
<#elseif __PROCESSOR?matches(".*PIC32MK.*") == true>
    EVIC_SourceDisable(${.vars["${MCPMSMFOC_ADC_MODULE_01?lower_case}"].INTERRUPT_ADC_RESULT});
</#if>
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
<#if __PROCESSOR?matches(".*SAME54.*") == true>
    ADC0_InterruptsEnable( ADC_STATUS_RESRDY );  
<#elseif __PROCESSOR?matches(".*SAME70.*") == true>
    NVIC_EnableIRQ(AFEC0_IRQn); 
<#elseif __PROCESSOR?matches(".*PIC32MK.*") == true>
    EVIC_SourceEnable(${.vars["${MCPMSMFOC_ADC_MODULE_01?lower_case}"].INTERRUPT_ADC_RESULT});
</#if>
}

<#if MCPMSMFOC_POSITION_CALC_ALGORITHM == 'SENSORED_ENCODER'>
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
__STATIC_FORCEINLINE uint16_t mcHalI_EncoderPositionGet( void  )
{
    <#if __PROCESSOR?matches(".*SAME54.*") == true>
        return (uint16_t)${MCPMSMFOC_ENCODER_PERIPHERAL}_QDECPositionGet();
    <#elseif __PROCESSOR?matches(".*SAME70.*") == true>
        return (uint16_t)${MCPMSMFOC_ENCODER_PERIPHERAL}_QuadraturePositionGet();
    <#elseif __PROCESSOR?matches(".*PIC32MK.*") == true>
        return (uint16_t)${MCPMSMFOC_ENCODER_PERIPHERAL}_PositionGet();
    </#if>
}

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
__STATIC_FORCEINLINE int16_t mcHalI_EncoderVelocityGet( void  )
{
    return (int16_t)${MCPMSMFOC_ENCODER_PERIPHERAL}_VelocityGet();
}
</#if>
</#if>

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

<#--  Get led function  -->
<#function ledFunction index>
   <#if 0 == index>
    <#return MCPMSMFOC_LED_0_FUNCTION>
  <#elseif 1 == index>
    <#return MCPMSMFOC_LED_1_FUNCTION>
  <#else>
    <#return "Error">
  </#if>
</#function>

<#if MCPMSMFOC_LEDS_AVAILABLE != 0 >
    <#list 0..10 as index>
        <#if "Direction indication" == ledFunction(index)>
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
         void mcHal_DirectionIndication( void );
         
         <#elseif "Fault indication" == ledFunction(index)>
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
        
        </#if>
       
        <#if index == ( MCPMSMFOC_LEDS_AVAILABLE -1 )>
            <#break>
        </#if>
    </#list>
</#if>


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
<#if __PROCESSOR?matches(".*SAME54.*") == true>
void mcHalI_AdcCallBackRegister( ADC_CALLBACK callback, uintptr_t context );
<#elseif __PROCESSOR?matches(".*SAME70.*") == true>
void mcHalI_AdcCallBackRegister( AFEC_CALLBACK callback, uintptr_t context );
<#elseif __PROCESSOR?matches(".*PIC32MK.*") == true>
void mcHalI_AdcCallBackRegister( ADCHS_CALLBACK callback, uintptr_t context );
</#if>

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
<#if __PROCESSOR?matches(".*SAME54.*") == true>
void mcHalI_PwmCallbackRegister( TCC_CALLBACK callback, uintptr_t context );
<#elseif __PROCESSOR?matches(".*SAME70.*") == true>
void mcHalI_PwmCallbackRegister( PWM_CALLBACK callback, uintptr_t context );
<#elseif __PROCESSOR?matches(".*PIC32MK.*") == true>
void mcHalI_PwmCallbackRegister( MCPWM_CH_CALLBACK callback, uintptr_t context );
</#if>


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

<#--  Get button function  -->
<#function buttonFunction index>
   <#if 0 == index>
    <#return MCPMSMFOC_BUTTON_0_FUNCTION>
  <#elseif 1 == index>
    <#return MCPMSMFOC_BUTTON_1_FUNCTION>
  <#else>
    <#return "Error">
  </#if>
</#function>

<#if MCPMSMFOC_BUTTONS_AVAILABLE != 0 >
    <#list 0..10 as index>
        <#if "Start/Stop" == buttonFunction(index)>
bool mcHalI_StartStopButtonState( void );
           <#break>
        </#if>
    </#list>
</#if>


<#if MCPMSMFOC_BUTTONS_AVAILABLE != 0 >
    <#list 0..10 as index>
        <#if "Direction Toggle" == buttonFunction(index)>
bool mcHalI_DirectionButtonState( void );
           <#break>
        </#if>
    </#list>
</#if>  

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
void mcHalI_EncoderStart( void  );
</#if>

#endif // MCHAL_H
