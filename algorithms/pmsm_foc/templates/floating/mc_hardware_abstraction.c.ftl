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
    </#if>
}

</#if>

