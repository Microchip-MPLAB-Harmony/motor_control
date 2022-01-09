/*******************************************************************************
 Hardware abstraction functions 

  Company:
    Microchip Technology Inc.

  File Name:
    mc_hardware_abstraction.c

  Summary:
   Hardware abstraction layer 

  Description:
  Hardware abstraction layer 
 
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


/*******************************************************************************
Headers inclusions
 *******************************************************************************/
#include <stdint.h>
#include "mc_hardware_abstraction.h"

/*******************************************************************************
 * Constants 
 *******************************************************************************/

/*******************************************************************************
 Private variables 
 *******************************************************************************/
static tmcHal_ButtonState_s     mcHal_PressButtonState_mds;

/*******************************************************************************
 Private variables 
 *******************************************************************************/

/*******************************************************************************
 Interface variables 
 *******************************************************************************/

/*******************************************************************************
 Private Functions 
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
void mcHalI_VoltageSourceInverterPwmSet( tmcHal_InverterInstanceId_e Id, uint16_t * duty )
{
    if( Id == 0u )
    {

    <#if __PROCESSOR?matches(".*SAME54.*") == true>
        ${MCPMSMFOC_PWM_INSTANCE}_PWM24bitDutySet(${MCPMSMFOC_PWM_INSTANCE}_CHANNEL${MCPMSMFOC_PWM_INSTANCE_PWM_A_FINAL}, duty[0] );
        ${MCPMSMFOC_PWM_INSTANCE}_PWM24bitDutySet(${MCPMSMFOC_PWM_INSTANCE}_CHANNEL${MCPMSMFOC_PWM_INSTANCE_PWM_B_FINAL}, duty[1] );
        ${MCPMSMFOC_PWM_INSTANCE}_PWM24bitDutySet(${MCPMSMFOC_PWM_INSTANCE}_CHANNEL${MCPMSMFOC_PWM_INSTANCE_PWM_C_FINAL}, duty[2] );
    <#elseif __PROCESSOR?matches(".*SAME70.*") == true>
        ${MCPMSMFOC_PWM_INSTANCE}_ChannelDutySet(PWM_CHANNEL_${MCPMSMFOC_PWM_INSTANCE_PWM_A_FINAL}, duty[0] );
        ${MCPMSMFOC_PWM_INSTANCE}_ChannelDutySet(PWM_CHANNEL_${MCPMSMFOC_PWM_INSTANCE_PWM_B_FINAL}, duty[1] );
        ${MCPMSMFOC_PWM_INSTANCE}_ChannelDutySet(PWM_CHANNEL_${MCPMSMFOC_PWM_INSTANCE_PWM_C_FINAL}, duty[2] );
    <#elseif __PROCESSOR?matches(".*PIC32MK.*") == true>
        ${MCPMSMFOC_PWM_INSTANCE}_ChannelPrimaryDutySet(${MCPMSMFOC_PWM_INSTANCE}_CH_${MCPMSMFOC_PWM_INSTANCE_PWM_A_FINAL}, duty[0] );
        ${MCPMSMFOC_PWM_INSTANCE}_ChannelPrimaryDutySet(${MCPMSMFOC_PWM_INSTANCE}_CH_${MCPMSMFOC_PWM_INSTANCE_PWM_B_FINAL}, duty[1] );
        ${MCPMSMFOC_PWM_INSTANCE}_ChannelPrimaryDutySet(${MCPMSMFOC_PWM_INSTANCE}_CH_${MCPMSMFOC_PWM_INSTANCE_PWM_C_FINAL}, duty[2] );
    </#if>
    }
    else 
     {
         
     }
}


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
void mcHalI_VoltageSourceInverterPwmDisable(void)
{
<#if __PROCESSOR?matches(".*SAME54.*") == true>
   /*Override all PWM outputs to low*/
    while ((${MCPMSMFOC_PWM_INSTANCE}_REGS->TCC_SYNCBUSY & (TCC_SYNCBUSY_PATT_Msk)) == TCC_SYNCBUSY_PATT_Msk)
    {
        /* Wait for sync */
    }
    ${MCPMSMFOC_PWM_INSTANCE}_REGS->TCC_PATT = 0x00FF;
<#elseif __PROCESSOR?matches(".*SAME70.*") == true>
    ${MCPMSMFOC_PWM_INSTANCE}_ChannelOverrideDisable( PWM_CHANNEL_${MCPMSMFOC_PWM_INSTANCE_PWM_A_FINAL} );
    ${MCPMSMFOC_PWM_INSTANCE}_ChannelOverrideDisable( PWM_CHANNEL_${MCPMSMFOC_PWM_INSTANCE_PWM_B_FINAL} );
    ${MCPMSMFOC_PWM_INSTANCE}_ChannelOverrideDisable( PWM_CHANNEL_${MCPMSMFOC_PWM_INSTANCE_PWM_C_FINAL} );
<#elseif __PROCESSOR?matches(".*PIC32MK.*") == true>
    ${MCPMSMFOC_PWM_INSTANCE}_ChannelPinsOwnershipDisable( ${MCPMSMFOC_PWM_INSTANCE}_CH_1 );
    ${MCPMSMFOC_PWM_INSTANCE}_ChannelPinsOwnershipDisable( ${MCPMSMFOC_PWM_INSTANCE}_CH_2 );
    ${MCPMSMFOC_PWM_INSTANCE}_ChannelPinsOwnershipDisable( ${MCPMSMFOC_PWM_INSTANCE}_CH_3 );
</#if>

}

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
void mcHalI_VoltageSourceInverterPwmEnable(void)
{
<#if __PROCESSOR?matches(".*SAME54.*") == true>
    /*Disable PWM override*/
    while ((${MCPMSMFOC_PWM_INSTANCE}_REGS->TCC_SYNCBUSY & (TCC_SYNCBUSY_PATT_Msk)) == TCC_SYNCBUSY_PATT_Msk)
    {
        /* Wait for sync */
    }
    ${MCPMSMFOC_PWM_INSTANCE}_REGS->TCC_PATT = 0x0000;
<#elseif __PROCESSOR?matches(".*SAME70.*") == true>
    ${MCPMSMFOC_PWM_INSTANCE}_ChannelOverrideEnable( PWM_CHANNEL_${MCPMSMFOC_PWM_INSTANCE_PWM_A_FINAL} );
    ${MCPMSMFOC_PWM_INSTANCE}_ChannelOverrideEnable( PWM_CHANNEL_${MCPMSMFOC_PWM_INSTANCE_PWM_B_FINAL} );
    ${MCPMSMFOC_PWM_INSTANCE}_ChannelOverrideEnable( PWM_CHANNEL_${MCPMSMFOC_PWM_INSTANCE_PWM_C_FINAL} );
<#elseif __PROCESSOR?matches(".*PIC32MK.*") == true>
    ${MCPMSMFOC_PWM_INSTANCE}_ChannelPinsOwnershipEnable( ${MCPMSMFOC_PWM_INSTANCE}_CH_1 );
    ${MCPMSMFOC_PWM_INSTANCE}_ChannelPinsOwnershipEnable( ${MCPMSMFOC_PWM_INSTANCE}_CH_2 );
    ${MCPMSMFOC_PWM_INSTANCE}_ChannelPinsOwnershipEnable( ${MCPMSMFOC_PWM_INSTANCE}_CH_3 );
</#if>
   
}

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
uint16_t mcHalI_VoltageSignalGet( void )
{
<#if __PROCESSOR?matches(".*SAME54.*") == true>
    return ADC1_ConversionResultGet();
<#elseif __PROCESSOR?matches(".*SAME70.*") == true>
    return AFEC0_ChannelResultGet(AFEC_CH${MCPMSMFOC_BUS_VOLTAGE_VDC_UNIT_BUS_VOLTAGE_VDC_FINAL});
<#elseif __PROCESSOR?matches(".*PIC32MK.*") == true>  
  <#if MCPMSMFOC_POTENTIOMETER_VPOT_UNIT == "ADC7" >
    return ADCHS_ChannelResultGet(ADCHS_CH${MCPMSMFOC_BUS_VOLTAGE_VDC_UNIT_BUS_VOLTAGE_VDC_FINAL});
  <#elseif MCPMSMFOC_BUS_VOLTAGE_VDC_UNIT == "ADC0"> 
    return ADCHS_ChannelResultGet(ADCHS_CH0);
  <#elseif MCPMSMFOC_BUS_VOLTAGE_VDC_UNIT == "ADC1"> 
    return ADCHS_ChannelResultGet(ADCHS_CH1);
  <#elseif MCPMSMFOC_BUS_VOLTAGE_VDC_UNIT == "ADC2"> 
    return ADCHS_ChannelResultGet(ADCHS_CH2);
  <#elseif MCPMSMFOC_BUS_VOLTAGE_VDC_UNIT == "ADC3"> 
    return ADCHS_ChannelResultGet(ADCHS_CH3);
  <#elseif MCPMSMFOC_BUS_VOLTAGE_VDC_UNIT == "ADC4"> 
    return  = ADCHS_ChannelResultGet(ADCHS_CH4);
  <#elseif MCPMSMFOC_BUS_VOLTAGE_VDC_UNIT == "ADC5"> 
    return ADCHS_ChannelResultGet(ADCHS_CH5);
  </#if> 
</#if>
}


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
uint16_t mcHalI_PhaseACurrentSignalGet( uint8_t Id )
{
<#if __PROCESSOR?matches(".*SAME54.*") == true>
    if ( 0u == Id)
    {
        return ${MCPMSMFOC_PHASE_CURRENT_IA_UNIT}_ConversionResultGet();
    }
    else 
    {
        return 0;
    }
<#elseif __PROCESSOR?matches(".*SAME70.*") == true>
    return ${MCPMSMFOC_PHASE_CURRENT_IA_UNIT}_ChannelResultGet(AFEC_CH${MCPMSMFOC_PHASE_CURRENT_IA_UNIT_PHASE_CURRENT_IA_FINAL});
<#elseif __PROCESSOR?matches(".*PIC32MK.*") == true>
    <#if MCPMSMFOC_PHASE_CURRENT_IA_UNIT == "ADC7" >
        return ${MCPMSMFOC_PHASE_CURRENT_IA_UNIT}_ChannelResultGet(AFEC_CH${MCPMSMFOC_PHASE_CURRENT_IA_UNIT_PHASE_CURRENT_IA_FINAL});
    <#elseif MCPMSMFOC_PHASE_CURRENT_IA_UNIT == "ADC0"> 
        return ADCHS_ChannelResultGet(ADCHS_CH0);
    <#elseif MCPMSMFOC_PHASE_CURRENT_IA_UNIT == "ADC1"> 
        return ADCHS_ChannelResultGet(ADCHS_CH1);
    <#elseif MCPMSMFOC_PHASE_CURRENT_IA_UNIT == "ADC2"> 
        return ADCHS_ChannelResultGet(ADCHS_CH2);
    <#elseif MCPMSMFOC_PHASE_CURRENT_IA_UNIT == "ADC3"> 
        return ADCHS_ChannelResultGet(ADCHS_CH3);
    <#elseif MCPMSMFOC_PHASE_CURRENT_IA_UNIT == "ADC4"> 
        return ADCHS_ChannelResultGet(ADCHS_CH4);
    <#elseif MCPMSMFOC_PHASE_CURRENT_IA_UNIT == "ADC5"> 
        return ADCHS_ChannelResultGet(ADCHS_CH5);
    </#if> 
</#if>    
}



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
uint16_t mcHalI_PhaseBCurrentSignalGet( uint8_t Id )
{
<#if __PROCESSOR?matches(".*SAME54.*") == true>
    return ${MCPMSMFOC_PHASE_CURRENT_IB_UNIT}_ConversionResultGet();   
<#elseif __PROCESSOR?matches(".*SAME70.*") == true>
    return ${MCPMSMFOC_PHASE_CURRENT_IB_UNIT}_ChannelResultGet(AFEC_CH${MCPMSMFOC_PHASE_CURRENT_IB_UNIT_PHASE_CURRENT_IB_FINAL});
<#elseif __PROCESSOR?matches(".*PIC32MK.*") == true>
<#if MCPMSMFOC_PHASE_CURRENT_IB_UNIT == "ADC7" >
    return ADCHS_ChannelResultGet(ADCHS_CH${MCPMSMFOC_PHASE_CURRENT_IB_UNIT_PHASE_CURRENT_IB_FINAL});
<#elseif MCPMSMFOC_PHASE_CURRENT_IB_UNIT == "ADC0"> 
    return ADCHS_ChannelResultGet(ADCHS_CH0);
<#elseif MCPMSMFOC_PHASE_CURRENT_IB_UNIT == "ADC1"> 
    return ADCHS_ChannelResultGet(ADCHS_CH1);
<#elseif MCPMSMFOC_PHASE_CURRENT_IB_UNIT == "ADC2"> 
    return ADCHS_ChannelResultGet(ADCHS_CH2);
<#elseif MCPMSMFOC_PHASE_CURRENT_IB_UNIT == "ADC3"> 
    return ADCHS_ChannelResultGet(ADCHS_CH3);
<#elseif MCPMSMFOC_PHASE_CURRENT_IB_UNIT == "ADC4"> 
    return ADCHS_ChannelResultGet(ADCHS_CH4);
<#elseif MCPMSMFOC_PHASE_CURRENT_IB_UNIT == "ADC5"> 
    return ADCHS_ChannelResultGet(ADCHS_CH5);
</#if>
</#if>
   
}



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
uint16_t mcHalI_PotentiometerSignalGet( void )
{
<#if __PROCESSOR?matches(".*SAME54.*") == true>
    return ${MCPMSMFOC_POTENTIOMETER_VPOT_UNIT}_ConversionResultGet();
<#elseif __PROCESSOR?matches(".*SAME70.*") == true>
    return ${MCPMSMFOC_POTENTIOMETER_VPOT_UNIT}_ChannelResultGet(AFEC_CH${MCPMSMFOC_POTENTIOMETER_VPOT_UNIT_POTENTIOMETER_VPOT_FINAL});
<#elseif __PROCESSOR?matches(".*PIC32MK.*") == true>
   <#if MCPMSMFOC_BUS_VOLTAGE_VDC_UNIT == "ADC7" >
     return ADCHS_ChannelResultGet(ADCHS_CH${MCPMSMFOC_BUS_VOLTAGE_VDC_UNIT_BUS_VOLTAGE_VDC_FINAL});
   <#elseif MCPMSMFOC_BUS_VOLTAGE_VDC_UNIT == "ADC0"> 
    return ADCHS_ChannelResultGet(ADCHS_CH0);
   <#elseif MCPMSMFOC_BUS_VOLTAGE_VDC_UNIT == "ADC1"> 
    return ADCHS_ChannelResultGet(ADCHS_CH1);
   <#elseif MCPMSMFOC_BUS_VOLTAGE_VDC_UNIT == "ADC2"> 
    return ADCHS_ChannelResultGet(ADCHS_CH2);
   <#elseif MCPMSMFOC_BUS_VOLTAGE_VDC_UNIT == "ADC3"> 
    return ADCHS_ChannelResultGet(ADCHS_CH3);
   <#elseif MCPMSMFOC_BUS_VOLTAGE_VDC_UNIT == "ADC4"> 
    return ADCHS_ChannelResultGet(ADCHS_CH4);
   <#elseif MCPMSMFOC_BUS_VOLTAGE_VDC_UNIT == "ADC5"> 
    return ADCHS_ChannelResultGet(ADCHS_CH5);
   </#if> 

</#if>
}


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
void mcHal_ButtonResponse( const tmcHal_ButtonState_e  buttonState,  void (*buttonFunction)(void) )
{
    switch(mcHal_PressButtonState_mds.state)
    {
        case buttonStateMachine_Ready:
        {
            if( buttonState_Pressed == buttonState )
            {
                buttonFunction();
                mcHal_PressButtonState_mds.debounceCounter = 0;
                mcHal_PressButtonState_mds.state = buttonStateMachine_Wait;
            }
        }
        break;

        case buttonStateMachine_Wait:
        {
            if( SW_DEBOUNCE_DLY_500MS <= mcHal_PressButtonState_mds.debounceCounter)
            {
                mcHal_PressButtonState_mds.state = buttonStateMachine_Ready;
                mcHal_PressButtonState_mds.debounceCounter = 0;
            }
            else
            {
                mcHal_PressButtonState_mds.debounceCounter++;
            }
        }
        break;
        default:
        {
              /* Should never come here */
        }
    }
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
void mcHalI_AdcInterruptDisable( void )
{
<#if __PROCESSOR?matches(".*SAME54.*") == true>
    ADC0_InterruptsDisable( ADC_STATUS_RESRDY );
<#elseif __PROCESSOR?matches(".*SAME70.*") == true>
    NVIC_DisableIRQ(AFEC0_IRQn);
<#elseif __PROCESSOR?matches(".*PIC32MK.*") == true>
    EVIC_SourceDisable(INT_SOURCE_ADC_DATA0);
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
void mcHalI_AdcInterruptEnable( void )
{
<#if __PROCESSOR?matches(".*SAME54.*") == true>
    ADC0_InterruptsEnable( ADC_STATUS_RESRDY );  
<#elseif __PROCESSOR?matches(".*SAME70.*") == true>
    NVIC_EnableIRQ(AFEC0_IRQn); 
<#elseif __PROCESSOR?matches(".*PIC32MK.*") == true>
    EVIC_SourceEnable(INT_SOURCE_ADC_DATA0);
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
void mcHalI_AdcInterruptClear( void )
{
<#if __PROCESSOR?matches(".*SAME54.*") == true>
    ADC0_InterruptsClear(ADC_STATUS_MASK);
<#elseif __PROCESSOR?matches(".*SAME70.*") == true>
    NVIC_ClearPendingIRQ(AFEC0_IRQn);
<#elseif __PROCESSOR?matches(".*PIC32MK.*") == true>
    EVIC_SourceStatusClear(INT_SOURCE_ADC_DATA0);
</#if>
}


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
void mcHalI_ADCEnable( void )
{
<#if __PROCESSOR?matches(".*SAME54.*") == true>
    ADC0_Enable();
<#elseif __PROCESSOR?matches(".*SAME70.*") == true>

<#elseif __PROCESSOR?matches(".*PIC32MK.*") == true>

</#if>
}

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
void mcHalI_AdcCallBackRegister(ADC_CALLBACK  callback, uintptr_t context)
{
<#if __PROCESSOR?matches(".*SAME54.*") == true>
    ADC0_CallbackRegister( callback, context);
<#elseif __PROCESSOR?matches(".*SAME70.*") == true>
    AFEC0_CallbackRegister( callback, context);
<#elseif __PROCESSOR?matches(".*PIC32MK.*") == true>
    ADCHS_CallbackRegister(ADCHS_CH0, callback, context);
</#if>
}


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
void mcHalI_PwmTimerStart( void )
{
<#if __PROCESSOR?matches(".*SAME54.*") == true>
    ${MCPMSMFOC_PWM_INSTANCE}_PWMStart( );  
<#elseif __PROCESSOR?matches(".*SAME70.*") == true>
    ${MCPMSMFOC_PWM_INSTANCE}_ChannelsStart(0x7); 
<#elseif __PROCESSOR?matches(".*PIC32MK.*") == true>
    ${MCPMSMFOC_PWM_INSTANCE}_Start();
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
void mcHalI_PwmInterruptDisable( void )
{
<#if __PROCESSOR?matches(".*SAME54.*") == true>
    NVIC_DisableIRQ(${MCPMSMFOC_PWM_INSTANCE}_OTHER_IRQn);
<#elseif __PROCESSOR?matches(".*SAME70.*") == true>
    NVIC_DisableIRQ(${MCPMSMFOC_PWM_INSTANCE}_IRQn);
<#elseif __PROCESSOR?matches(".*PIC32MK.*") == true>
    EVIC_SourceDisable( INT_SOURCE_PWM1 );
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
void mcHalI_PwmInterruptEnable( void )
{
<#if __PROCESSOR?matches(".*SAME54.*") == true>
    NVIC_EnableIRQ(${MCPMSMFOC_PWM_INSTANCE}_OTHER_IRQn);  
<#elseif __PROCESSOR?matches(".*SAME70.*") == true>
    NVIC_EnableIRQ(${MCPMSMFOC_PWM_INSTANCE}_IRQn);

<#elseif __PROCESSOR?matches(".*PIC32MK.*") == true>
    EVIC_SourceEnable( INT_SOURCE_PWM1 );
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
void mcHalI_PwmInterruptClear( void )
{
<#if __PROCESSOR?matches(".*SAME54.*") == true>
    NVIC_ClearPendingIRQ(${MCPMSMFOC_PWM_INSTANCE}_OTHER_IRQn);
<#elseif __PROCESSOR?matches(".*SAME70.*") == true>
    NVIC_ClearPendingIRQ(${MCPMSMFOC_PWM_INSTANCE}_IRQn);
<#elseif __PROCESSOR?matches(".*PIC32MK.*") == true>
    EVIC_SourceStatusClear(INT_SOURCE_PWM1);
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
void mcHalI_PwmEnable( void )
{
<#if __PROCESSOR?matches(".*SAME54.*") == true>
<#elseif __PROCESSOR?matches(".*SAME70.*") == true>

<#elseif __PROCESSOR?matches(".*PIC32MK.*") == true>

</#if>
   
}

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
uint16_t mcHalI_PwmPeriodGet( void )
{
<#if __PROCESSOR?matches(".*SAME54.*") == true>
    return ${MCPMSMFOC_PWM_INSTANCE}_PWM24bitPeriodGet( );
<#elseif __PROCESSOR?matches(".*SAME70.*") == true>
    return ${MCPMSMFOC_PWM_INSTANCE}_ChannelPeriodGet( PWM_CHANNEL_0 );
<#elseif __PROCESSOR?matches(".*PIC32MK.*") == true>
    return ${MCPMSMFOC_PWM_INSTANCE}_PrimaryPeriodGet();
</#if>
}

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
void mcHalI_PwmCallbackRegister( TCC_CALLBACK  callback, uintptr_t context )
{
<#if __PROCESSOR?matches(".*SAME54.*") == true>
    ${MCPMSMFOC_PWM_INSTANCE}_PWMCallbackRegister( callback, (uintptr_t)context);
<#elseif __PROCESSOR?matches(".*SAME70.*") == true>
    ${MCPMSMFOC_PWM_INSTANCE}_CallbackRegister( callback, (uintptr_t)context);

<#elseif __PROCESSOR?matches(".*PIC32MK.*") == true>
    ${MCPMSMFOC_PWM_INSTANCE}_CallbackRegister(${MCPMSMFOC_PWM_INSTANCE}_CH_1, callback, (uintptr_t)context);
</#if>

}

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
void mcHalI_Group01SignalRead( uint16_t Id  )
{
<#if __PROCESSOR?matches(".*SAME54.*") == true>
    mcHalI_PhaseACurrent_gdu16 = mcHalI_PhaseACurrentSignalGet( Id );
    mcHalI_PhaseBCurrent_gdu16  = mcHalI_PhaseBCurrentSignalGet( Id );

<#elseif __PROCESSOR?matches(".*SAME70.*") == true>
    mcHalI_PhaseACurrent_gdu16 = ${MCPMSMFOC_PHASE_CURRENT_IA_UNIT}_ChannelResultGet(AFEC_CH${MCPMSMFOC_PHASE_CURRENT_IA_UNIT_PHASE_CURRENT_IA_FINAL});
    mcHalI_PhaseBCurrent_gdu16 = ${MCPMSMFOC_PHASE_CURRENT_IB_UNIT}_ChannelResultGet(AFEC_CH${MCPMSMFOC_PHASE_CURRENT_IB_UNIT_PHASE_CURRENT_IB_FINAL});

<#elseif __PROCESSOR?matches(".*PIC32MK.*") == true>
  <#if MCPMSMFOC_PHASE_CURRENT_IA_UNIT == "ADC7" >
    mcHalI_PhaseACurrent_gdu16 = ${MCPMSMFOC_PHASE_CURRENT_IA_UNIT}_ChannelResultGet(AFEC_CH${MCPMSMFOC_PHASE_CURRENT_IA_UNIT_PHASE_CURRENT_IA_FINAL});
  <#elseif MCPMSMFOC_PHASE_CURRENT_IA_UNIT == "ADC0"> 
    mcHalI_PhaseACurrent_gdu16  = ADCHS_ChannelResultGet(ADCHS_CH0);
  <#elseif MCPMSMFOC_PHASE_CURRENT_IA_UNIT == "ADC1"> 
    mcHalI_PhaseACurrent_gdu16  = ADCHS_ChannelResultGet(ADCHS_CH1);
  <#elseif MCPMSMFOC_PHASE_CURRENT_IA_UNIT == "ADC2"> 
    mcHalI_PhaseACurrent_gdu16  = ADCHS_ChannelResultGet(ADCHS_CH2);
  <#elseif MCPMSMFOC_PHASE_CURRENT_IA_UNIT == "ADC3"> 
    mcHalI_PhaseACurrent_gdu16  = ADCHS_ChannelResultGet(ADCHS_CH3);
  <#elseif MCPMSMFOC_PHASE_CURRENT_IA_UNIT == "ADC4"> 
    mcHalI_PhaseACurrent_gdu16  = ADCHS_ChannelResultGet(ADCHS_CH4);
  <#elseif MCPMSMFOC_PHASE_CURRENT_IA_UNIT == "ADC5"> 
    mcHalI_PhaseACurrent_gdu16  = ADCHS_ChannelResultGet(ADCHS_CH5);
  </#if> 

  <#if MCPMSMFOC_PHASE_CURRENT_IB_UNIT == "ADC7" >
    mcHalI_PhaseBCurrent_gdu16 = ADCHS_ChannelResultGet(ADCHS_CH${MCPMSMFOC_PHASE_CURRENT_IB_UNIT_PHASE_CURRENT_IB_FINAL});
  <#elseif MCPMSMFOC_PHASE_CURRENT_IB_UNIT == "ADC0"> 
    mcHalI_PhaseBCurrent_gdu16  = ADCHS_ChannelResultGet(ADCHS_CH0);
  <#elseif MCPMSMFOC_PHASE_CURRENT_IB_UNIT == "ADC1"> 
    mcHalI_PhaseBCurrent_gdu16  = ADCHS_ChannelResultGet(ADCHS_CH1);
  <#elseif MCPMSMFOC_PHASE_CURRENT_IB_UNIT == "ADC2"> 
    mcHalI_PhaseBCurrent_gdu16  = ADCHS_ChannelResultGet(ADCHS_CH2);
  <#elseif MCPMSMFOC_PHASE_CURRENT_IB_UNIT == "ADC3"> 
    mcHalI_PhaseBCurrent_gdu16  = ADCHS_ChannelResultGet(ADCHS_CH3);
  <#elseif MCPMSMFOC_PHASE_CURRENT_IB_UNIT == "ADC4"> 
    mcHalI_PhaseBCurrent_gdu16  = ADCHS_ChannelResultGet(ADCHS_CH4);
  <#elseif MCPMSMFOC_PHASE_CURRENT_IB_UNIT == "ADC5"> 
    mcHalI_PhaseBCurrent_gdu16  = ADCHS_ChannelResultGet(ADCHS_CH5);
  </#if> 
</#if>
}

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
void mcHalI_Group02SignalRead( uint16_t Id  )
{
<#if __PROCESSOR?matches(".*SAME54.*") == true>
    mcHalI_DcBusVoltage_gdu16  = mcHalI_VoltageSignalGet();
    mcHalI_Potentiometer_gdu16 = mcHalI_PotentiometerSignalGet();
<#elseif __PROCESSOR?matches(".*SAME70.*") == true>
    mcHalI_DcBusVoltage_gdu16  = ${MCPMSMFOC_BUS_VOLTAGE_VDC_UNIT}_ChannelResultGet(AFEC_CH${MCPMSMFOC_BUS_VOLTAGE_VDC_UNIT_BUS_VOLTAGE_VDC_FINAL});
    mcHalI_Potentiometer_gdu16 = ${MCPMSMFOC_POTENTIOMETER_VPOT_UNIT}_ChannelResultGet(AFEC_CH${MCPMSMFOC_POTENTIOMETER_VPOT_UNIT_POTENTIOMETER_VPOT_FINAL});

<#elseif __PROCESSOR?matches(".*PIC32MK.*") == true>
  <#if MCPMSMFOC_BUS_VOLTAGE_VDC_UNIT == "ADC7" >
    mcHalI_DcBusVoltage_gdu16  = ADCHS_ChannelResultGet(ADCHS_CH${MCPMSMFOC_BUS_VOLTAGE_VDC_UNIT_BUS_VOLTAGE_VDC_FINAL});
  <#elseif MCPMSMFOC_BUS_VOLTAGE_VDC_UNIT == "ADC0"> 
    mcHalI_DcBusVoltage_gdu16  = ADCHS_ChannelResultGet(ADCHS_CH0);
  <#elseif MCPMSMFOC_BUS_VOLTAGE_VDC_UNIT == "ADC1"> 
    mcHalI_DcBusVoltage_gdu16  = ADCHS_ChannelResultGet(ADCHS_CH1);
  <#elseif MCPMSMFOC_BUS_VOLTAGE_VDC_UNIT == "ADC2"> 
    mcHalI_DcBusVoltage_gdu16  = ADCHS_ChannelResultGet(ADCHS_CH2);
  <#elseif MCPMSMFOC_BUS_VOLTAGE_VDC_UNIT == "ADC3"> 
    mcHalI_DcBusVoltage_gdu16  = ADCHS_ChannelResultGet(ADCHS_CH3);
  <#elseif MCPMSMFOC_BUS_VOLTAGE_VDC_UNIT == "ADC4"> 
    mcHalI_DcBusVoltage_gdu16  = ADCHS_ChannelResultGet(ADCHS_CH4);
  <#elseif MCPMSMFOC_BUS_VOLTAGE_VDC_UNIT == "ADC5"> 
    mcHalI_DcBusVoltage_gdu16  = ADCHS_ChannelResultGet(ADCHS_CH5);
  </#if> 

  <#if MCPMSMFOC_POTENTIOMETER_VPOT_UNIT == "ADC7" >
   mcHalI_Potentiometer_gdu16 = ADCHS_ChannelResultGet(ADCHS_CH${MCPMSMFOC_POTENTIOMETER_VPOT_UNIT_POTENTIOMETER_VPOT_FINAL});
  <#elseif MCPMSMFOC_BUS_VOLTAGE_VDC_UNIT == "ADC0"> 
    mcHalI_Potentiometer_gdu16  = ADCHS_ChannelResultGet(ADCHS_CH0);
  <#elseif MCPMSMFOC_BUS_VOLTAGE_VDC_UNIT == "ADC1"> 
    mcHalI_Potentiometer_gdu16  = ADCHS_ChannelResultGet(ADCHS_CH1);
  <#elseif MCPMSMFOC_BUS_VOLTAGE_VDC_UNIT == "ADC2"> 
    mcHalI_Potentiometer_gdu16  = ADCHS_ChannelResultGet(ADCHS_CH2);
  <#elseif MCPMSMFOC_BUS_VOLTAGE_VDC_UNIT == "ADC3"> 
    mcHalI_Potentiometer_gdu16  = ADCHS_ChannelResultGet(ADCHS_CH3);
  <#elseif MCPMSMFOC_BUS_VOLTAGE_VDC_UNIT == "ADC4"> 
    mcHalI_Potentiometer_gdu16  = ADCHS_ChannelResultGet(ADCHS_CH4);
  <#elseif MCPMSMFOC_BUS_VOLTAGE_VDC_UNIT == "ADC5"> 
    mcHalI_Potentiometer_gdu16  = ADCHS_ChannelResultGet(ADCHS_CH5);
  </#if> 
</#if>
    
}

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
void mcHalI_Group01SignalHardwareTrigger( uint16_t Id  )
{
<#if __PROCESSOR?matches(".*SAME54.*") == true>
    /* Select channels for Group 01 signals */
    ${MCPMSMFOC_PHASE_CURRENT_IA_UNIT}_ChannelSelect( ADC_POSINPUT_AIN${MCPMSMFOC_PHASE_CURRENT_IA_UNIT_PHASE_CURRENT_IA_FINAL}, ADC_NEGINPUT_GND);
    ${MCPMSMFOC_PHASE_CURRENT_IB_UNIT}_ChannelSelect( ADC_POSINPUT_AIN${MCPMSMFOC_PHASE_CURRENT_IB_UNIT_PHASE_CURRENT_IB_FINAL}, ADC_NEGINPUT_GND);
    
    /* Enable hardware trigger */
    ${MCPMSMFOC_PHASE_CURRENT_IA_UNIT}_InterruptsClear(ADC_STATUS_MASK);
    ${MCPMSMFOC_PHASE_CURRENT_IA_UNIT}_InterruptsEnable( ADC_STATUS_RESRDY );
<#elseif __PROCESSOR?matches(".*SAME70.*") == true>

<#elseif __PROCESSOR?matches(".*PIC32MK.*") == true>

</#if>    
}

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
void mcHalI_Group02SignalSoftwareTrigger( uint16_t Id  )
{
<#if __PROCESSOR?matches(".*SAME54.*") == true>
    /* Select channels for Group 02 signals */
    ${MCPMSMFOC_POTENTIOMETER_VPOT_UNIT}_ChannelSelect( ADC_POSINPUT_AIN${MCPMSMFOC_POTENTIOMETER_VPOT_UNIT_POTENTIOMETER_VPOT_FINAL}, ADC_NEGINPUT_GND);
    ${MCPMSMFOC_BUS_VOLTAGE_VDC_UNIT}_ChannelSelect( ADC_POSINPUT_AIN${MCPMSMFOC_BUS_VOLTAGE_VDC_UNIT_BUS_VOLTAGE_VDC_FINAL}, ADC_NEGINPUT_GND);
    
    /* Enable software  trigger */
    ${MCPMSMFOC_PHASE_CURRENT_IA_UNIT}_InterruptsClear(ADC_STATUS_MASK);
    ${MCPMSMFOC_PHASE_CURRENT_IA_UNIT}_InterruptsDisable( ADC_STATUS_RESRDY );
    ${MCPMSMFOC_PHASE_CURRENT_IA_UNIT}_ConversionStart(); 

<#elseif __PROCESSOR?matches(".*SAME70.*") == true>

<#elseif __PROCESSOR?matches(".*PIC32MK.*") == true>

</#if>

}

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
void mcHalI_EncoderStart( uint16_t Id  )
{
<#if __PROCESSOR?matches(".*SAME54.*") == true>
    ${MCPMSMFOC_ENCODER_PERIPHERAL}_QDECStart();
<#elseif __PROCESSOR?matches(".*SAME70.*") == true>
   ${MCPMSMFOC_ENCODER_PERIPHERAL}_QuadratureStart();
<#elseif __PROCESSOR?matches(".*PIC32MK.*") == true>
    ${MCPMSMFOC_ENCODER_PERIPHERAL}_Start();
</#if>
}

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
int32_t mcHalI_EncoderPositionGet( uint16_t Id  )
{
    <#if __PROCESSOR?matches(".*SAME54.*") == true>
        return ${MCPMSMFOC_ENCODER_PERIPHERAL}_QDECPositionGet();
    <#elseif __PROCESSOR?matches(".*SAME70.*") == true>
        return ${MCPMSMFOC_ENCODER_PERIPHERAL}_QuadraturePositionGet();
    <#elseif __PROCESSOR?matches(".*PIC32MK.*") == true>
        return ${MCPMSMFOC_ENCODER_PERIPHERAL}_PositionGet();
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
int32_t mcHalI_EncoderVelocityGet( uint16_t Id  )
{
    return ${MCPMSMFOC_ENCODER_PERIPHERAL}_VelocityGet();
}
</#if>
</#if>

