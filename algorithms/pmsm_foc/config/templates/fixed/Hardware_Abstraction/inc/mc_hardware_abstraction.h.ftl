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
<#if "TCC_U2213" == MCPMSMFOC_PWM_IP>
    return (uint16_t)${MCPMSMFOC_PWM_INSTANCE}_PWM24bitPeriodGet();
<#elseif "PWM_6343" == MCPMSMFOC_PWM_IP>
    return (uint16_t)${MCPMSMFOC_PWM_INSTANCE}_ChannelPeriodGet(PWM_CHANNEL_${MCPMSMFOC_PWM_A_CHANNEL});
<#elseif "MCPWM_01477" == MCPMSMFOC_PWM_IP>
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
<#if "TCC_U2213" == MCPMSMFOC_PWM_IP>
<#if MCPMSMFOC_FOC_X2C_ENABLE == true>
    uint8_t status;
        
    status = (uint8_t)${MCPMSMFOC_PWM_INSTANCE}_PWM24bitDutySet(${MCPMSMFOC_PWM_INSTANCE}_CHANNEL${MCPMSMFOC_PWM_A_CHANNEL}, dutyCycle[0u] );
    status &= (uint8_t)${MCPMSMFOC_PWM_INSTANCE}_PWM24bitDutySet(${MCPMSMFOC_PWM_INSTANCE}_CHANNEL${MCPMSMFOC_PWM_B_CHANNEL}, dutyCycle[1u] );
    status &= (uint8_t)${MCPMSMFOC_PWM_INSTANCE}_PWM24bitDutySet(${MCPMSMFOC_PWM_INSTANCE}_CHANNEL${MCPMSMFOC_PWM_C_CHANNEL}, dutyCycle[2u] );

    if( 0u == status )
    {
      /** ToDO: Log error */
    }
<#else>
    uint8_t status;
    uint16_t period;
    uint16_t duty[3u] = {0u};
    
    period = (uint16_t)mcHalI_PwmPeriodGet();
    duty[0u] = period - (uint16_t)dutyCycle[0u];
    duty[1u] = period - (uint16_t)dutyCycle[1u];
    duty[2u] = period - (uint16_t)dutyCycle[2u];
    
    status = (uint8_t)${MCPMSMFOC_PWM_INSTANCE}_PWM24bitDutySet(${MCPMSMFOC_PWM_INSTANCE}_CHANNEL${MCPMSMFOC_PWM_A_CHANNEL}, duty[0u] );
    status &= (uint8_t)${MCPMSMFOC_PWM_INSTANCE}_PWM24bitDutySet(${MCPMSMFOC_PWM_INSTANCE}_CHANNEL${MCPMSMFOC_PWM_B_CHANNEL}, duty[1u] );
    status &= (uint8_t)${MCPMSMFOC_PWM_INSTANCE}_PWM24bitDutySet(${MCPMSMFOC_PWM_INSTANCE}_CHANNEL${MCPMSMFOC_PWM_C_CHANNEL}, duty[2u] );

    if( 0u == status )
    {
      /** ToDO: Log error */
    }
</#if>
<#elseif "PWM_6343" == MCPMSMFOC_PWM_IP>
    uint16_t period;
    uint16_t duty[3u] = {0u};
    
    period = (uint16_t)mcHalI_PwmPeriodGet();
    duty[0u] = period - (uint16_t)dutyCycle[0u];
    duty[1u] = period - (uint16_t)dutyCycle[1u];
    duty[2u] = period - (uint16_t)dutyCycle[2u];

    ${MCPMSMFOC_PWM_INSTANCE}_ChannelDutySet(PWM_CHANNEL_${MCPMSMFOC_PWM_A_CHANNEL}, duty[0u] );
    ${MCPMSMFOC_PWM_INSTANCE}_ChannelDutySet(PWM_CHANNEL_${MCPMSMFOC_PWM_B_CHANNEL}, duty[1u] );
    ${MCPMSMFOC_PWM_INSTANCE}_ChannelDutySet(PWM_CHANNEL_${MCPMSMFOC_PWM_C_CHANNEL}, duty[2u] );
    
<#elseif "MCPWM_01477" == MCPMSMFOC_PWM_IP>
    ${MCPMSMFOC_PWM_INSTANCE}_ChannelPrimaryDutySet(${MCPMSMFOC_PWM_INSTANCE}_CH_${MCPMSMFOC_PWM_A_CHANNEL}, (uint16_t)dutyCycle[0] );
    ${MCPMSMFOC_PWM_INSTANCE}_ChannelPrimaryDutySet(${MCPMSMFOC_PWM_INSTANCE}_CH_${MCPMSMFOC_PWM_B_CHANNEL}, (uint16_t)dutyCycle[1] );
    ${MCPMSMFOC_PWM_INSTANCE}_ChannelPrimaryDutySet(${MCPMSMFOC_PWM_INSTANCE}_CH_${MCPMSMFOC_PWM_C_CHANNEL}, (uint16_t)dutyCycle[2] );
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
<#if ("ADC_U2500" == MCPMSMFOC_ADC_IP )  || ("ADC_U2247" == MCPMSMFOC_ADC_IP )>
    mcHalI_IaAdcInput_gdu16 = ${MCPMSMFOC_PHASE_CURRENT_IA_UNIT}_ConversionResultGet();
<#elseif "AFEC_11147" == MCPMSMFOC_ADC_IP>
    mcHalI_IaAdcInput_gdu16 = ${MCPMSMFOC_PHASE_CURRENT_IA_UNIT}_ChannelResultGet(AFEC_CH${MCPMSMFOC_PHASE_CURRENT_IA_CHANNEL});
<#elseif "ADCHS_02508" == MCPMSMFOC_ADC_IP>
  <#if MCPMSMFOC_PHASE_CURRENT_IA_UNIT == "ADC7" >
    mcHalI_IaAdcInput_gdu16 = ${MCPMSMFOC_PHASE_CURRENT_IA_UNIT}_ChannelResultGet(AFEC_CH${MCPMSMFOC_PHASE_CURRENT_IA_CHANNEL});
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
<#if ("ADC_U2500" == MCPMSMFOC_ADC_IP )  || ("ADC_U2247" == MCPMSMFOC_ADC_IP )>
    mcHalI_IbAdcInput_gdu16 =  ${MCPMSMFOC_PHASE_CURRENT_IB_UNIT}_ConversionResultGet();   
<#elseif "AFEC_11147" == MCPMSMFOC_ADC_IP>
    mcHalI_IbAdcInput_gdu16 =  ${MCPMSMFOC_PHASE_CURRENT_IB_UNIT}_ChannelResultGet(AFEC_CH${MCPMSMFOC_PHASE_CURRENT_IB_CHANNEL});
<#elseif "ADCHS_02508" == MCPMSMFOC_ADC_IP>
  <#if MCPMSMFOC_PHASE_CURRENT_IB_UNIT == "ADC7" >
    mcHalI_IbAdcInput_gdu16 =  ADCHS_ChannelResultGet(ADCHS_CH${MCPMSMFOC_PHASE_CURRENT_IB_CHANNEL});
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
<#if ("ADC_U2500" == MCPMSMFOC_ADC_IP )  || ("ADC_U2247" == MCPMSMFOC_ADC_IP )>
    mcHalI_UbusAdcInput_gdu16 = ${MCPMSMFOC_BUS_VOLTAGE_VDC_UNIT}_ConversionResultGet();
<#elseif "AFEC_11147" == MCPMSMFOC_ADC_IP>
    mcHalI_UbusAdcInput_gdu16 = ${MCPMSMFOC_BUS_VOLTAGE_VDC_UNIT}_ChannelResultGet(AFEC_CH${MCPMSMFOC_BUS_VOLTAGE_VDC_CHANNEL});
<#elseif "ADCHS_02508" == MCPMSMFOC_ADC_IP>
  <#if MCPMSMFOC_POTENTIOMETER_VPOT_UNIT == "ADC7" >
    mcHalI_UbusAdcInput_gdu16 = ADCHS_ChannelResultGet(ADCHS_CH${MCPMSMFOC_BUS_VOLTAGE_VDC_CHANNEL});
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
<#if ("ADC_U2500" == MCPMSMFOC_ADC_IP )  || ("ADC_U2247" == MCPMSMFOC_ADC_IP )>
    mcHalI_Potentiometer_gdu16 = ${MCPMSMFOC_POTENTIOMETER_VPOT_UNIT}_ConversionResultGet();
<#elseif "AFEC_11147" == MCPMSMFOC_ADC_IP>
    mcHalI_Potentiometer_gdu16 = ${MCPMSMFOC_POTENTIOMETER_VPOT_UNIT}_ChannelResultGet(AFEC_CH${MCPMSMFOC_POTENTIOMETER_VPOT_CHANNEL});
<#elseif "ADCHS_02508" == MCPMSMFOC_ADC_IP>
  <#if MCPMSMFOC_POTENTIOMETER_VPOT_UNIT == "ADC7" >
    mcHalI_Potentiometer_gdu16 = ADCHS_ChannelResultGet(ADCHS_CH${MCPMSMFOC_POTENTIOMETER_VPOT_CHANNEL});
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

<#if ("ADC_U2500" == MCPMSMFOC_ADC_IP )  || ("ADC_U2247" == MCPMSMFOC_ADC_IP )>
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
    ${MCPMSMFOC_POTENTIOMETER_VPOT_UNIT}_ChannelSelect( ADC_POSINPUT_AIN${MCPMSMFOC_POTENTIOMETER_VPOT_CHANNEL}, ADC_NEGINPUT_GND);
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
    ${MCPMSMFOC_BUS_VOLTAGE_VDC_UNIT}_ChannelSelect( ADC_POSINPUT_AIN${MCPMSMFOC_BUS_VOLTAGE_VDC_CHANNEL}, ADC_NEGINPUT_GND);
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
__STATIC_FORCEINLINE void mcHalI_AdcSoftwareConversionStart( void )
{
    /* Enable software  trigger */
    ${MCPMSMFOC_PHASE_CURRENT_IA_UNIT}_ConversionStart(); 
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
    while(${MCPMSMFOC_PHASE_CURRENT_IA_UNIT}_REGS->ADC_INTFLAG != ADC_INTFLAG_RESRDY_Msk)
    {
        __NOP();
    }
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
    ${MCPMSMFOC_PHASE_CURRENT_IA_UNIT}_ChannelSelect( ADC_POSINPUT_AIN${MCPMSMFOC_PHASE_CURRENT_IA_CHANNEL}, ADC_NEGINPUT_GND);
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
    ${MCPMSMFOC_PHASE_CURRENT_IB_UNIT}_ChannelSelect( ADC_POSINPUT_AIN${MCPMSMFOC_PHASE_CURRENT_IB_CHANNEL}, ADC_NEGINPUT_GND);   
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
<#if ("ADC_U2500" == MCPMSMFOC_ADC_IP )  || ("ADC_U2247" == MCPMSMFOC_ADC_IP )>
    ADC0_InterruptsClear(ADC_STATUS_MASK);
<#elseif "AFEC_11147" == MCPMSMFOC_ADC_IP>
    NVIC_ClearPendingIRQ(AFEC0_IRQn);
<#elseif "ADCHS_02508" == MCPMSMFOC_ADC_IP>
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
<#if ("ADC_U2500" == MCPMSMFOC_ADC_IP )  || ("ADC_U2247" == MCPMSMFOC_ADC_IP )>
    ADC0_InterruptsDisable( ADC_STATUS_RESRDY );
<#elseif "AFEC_11147" == MCPMSMFOC_ADC_IP>
    NVIC_DisableIRQ(AFEC0_IRQn);
<#elseif "ADCHS_02508" == MCPMSMFOC_ADC_IP>
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
<#if ("ADC_U2500" == MCPMSMFOC_ADC_IP )  || ("ADC_U2247" == MCPMSMFOC_ADC_IP )>
    ADC0_InterruptsEnable( ADC_STATUS_RESRDY );  
<#elseif "AFEC_11147" == MCPMSMFOC_ADC_IP>
    NVIC_EnableIRQ(AFEC0_IRQn); 
<#elseif "ADCHS_02508" == MCPMSMFOC_ADC_IP>
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
<#if "PDEC_U2263" == MCPMSMFOC_QEI_IP>
    return (uint16_t)${MCPMSMFOC_ENCODER_PERIPHERAL}_QDECPositionGet();
<#elseif "TC_6082" == MCPMSMFOC_QEI_IP>
        return (uint16_t)${MCPMSMFOC_ENCODER_PERIPHERAL}_QuadraturePositionGet();
<#elseif "QEI_01494" == MCPMSMFOC_QEI_IP>
        return (uint16_t)${MCPMSMFOC_ENCODER_PERIPHERAL}_PositionGet();
</#if>
}

<#if "QEI_01494" == MCPMSMFOC_QEI_IP>
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
        <#if "Direction Indication" == ledFunction(index)>
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
<#elseif "Fault Indication" == ledFunction(index)>
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
<#if ("ADC_U2500" == MCPMSMFOC_ADC_IP )  || ("ADC_U2247" == MCPMSMFOC_ADC_IP )>
void mcHalI_AdcCallBackRegister( ADC_CALLBACK callback, uintptr_t context );
<#elseif "TC_6082" == MCPMSMFOC_QEI_IP>
void mcHalI_AdcCallBackRegister( AFEC_CALLBACK callback, uintptr_t context );
<#elseif "QEI_01494" == MCPMSMFOC_QEI_IP>
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
<#if "TCC_U2213" == MCPMSMFOC_PWM_IP>
void mcHalI_PwmCallbackRegister( TCC_CALLBACK callback, uintptr_t context );
<#elseif "PWM_6343" == MCPMSMFOC_PWM_IP>
void mcHalI_PwmCallbackRegister( PWM_CALLBACK callback, uintptr_t context );
<#elseif "MCPWM_01477" == MCPMSMFOC_PWM_IP>
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
<#list 0..( MCPMSMFOC_BUTTONS_AVAILABLE - 1 ) as index>
<#if "Start/Stop" == buttonFunction(index)>
/*! \brief Start stop button state
 *
 * Details.
 * Start stop button state
 *
 * @param[in]:
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
bool mcHalI_StartStopButtonState( void );
<#break>
</#if>
</#list>
</#if>


<#if MCPMSMFOC_BUTTONS_AVAILABLE != 0 >
<#list 0..( MCPMSMFOC_BUTTONS_AVAILABLE - 1 ) as index>
<#if "Direction Toggle" == buttonFunction(index)>
/*! \brief Direction button state
 *
 * Details.
 * Direction button state
 *
 * @param[in]:
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
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
