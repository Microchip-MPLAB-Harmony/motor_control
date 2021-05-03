/*******************************************************************************
  Hardware abstraction source file

  Company:
    Microchip Technology Inc.

  File Name:
    mc_hardware_abstraction.c

  Summary:
    This file contains all the functions related to hardware abstraction

  Description:
    This file contains implementation of the hardware abstraction
 
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
#include "mc_hardware_abstraction.h"

/*******************************************************************************
 * Constants
*******************************************************************************/

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
void mcHalI_VoltageSourceInverterPwmEnable( void )
{
    ${.vars["${MCPMSMFOC_PWMPLIB?lower_case}"].PWM_OUTPUT_DISABLE_API}(0x00,0x00);  /*Disable PWM override*/
}

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
void mcHalI_VoltageSourceInverterPwmDisable( void )
{
    /*Override all PWM outputs to low*/
    ${.vars["${MCPMSMFOC_PWMPLIB?lower_case}"].PWM_OUTPUT_DISABLE_API}((TCC_PATT_PGE0_Msk|TCC_PATT_PGE1_Msk|TCC_PATT_PGE2_Msk
            |TCC_PATT_PGE4_Msk|TCC_PATT_PGE5_Msk|TCC_PATT_PGE6_Msk),
            (TCC_PATT_PGE0(0)|TCC_PATT_PGE1(0)|TCC_PATT_PGE2(0)|TCC_PATT_PGE4(0)
            |TCC_PATT_PGE5(0)|TCC_PATT_PGE6(0)));
}

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
uint32_t mcHalI_StartStopButtonGet( void )
{
    return GPIO_${MCPMSMFOC_START_BUTTON}_Get();
}
<#if "MCLV2" == MCPMSMFOC_BOARD_SEL>   
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
uint32_t mcHalI_DirectionButtonGet( void )
{
    return GPIO_${MCPMSMFOC_DIRECTION_BUTTON}_Get();
}

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
void mcHal_DirectionIndicationSet( void )
{
    GPIO_${MCPMSMFOC_DIRECTION_LED}_Toggle();
}
</#if>


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
void mcHal_FaultIndicationSet( void )
{
    GPIO_${MCPMSMFOC_FAULT_LED}_Set();
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
    ${.vars["${MCPMSMFOC_ADCPLIB?lower_case}"].ADC_START_API}();
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
    ${.vars["${MCPMSMFOC_PWMPLIB?lower_case}"].PWM_START_API}();
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
void mcHalI_AdcCallBackRegister( ADC_CALLBACK callback, uintptr_t context )
{
    ${.vars["${MCPMSMFOC_ADCPLIB?lower_case}"].ADC_CALLBACK_API}(callback, context);
}


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
void mcHalI_PwmCallBackRegister( TCC_CALLBACK callback, uintptr_t context )
{
    ${.vars["${MCPMSMFOC_PWMPLIB?lower_case}"].PWM_CALLBACK_API}(callback, context);
}