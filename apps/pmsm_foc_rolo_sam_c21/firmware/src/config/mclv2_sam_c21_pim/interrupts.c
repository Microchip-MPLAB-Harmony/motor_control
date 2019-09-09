/*******************************************************************************
 System Interrupts File

  Company:
    Microchip Technology Inc.

  File Name:
    interrupt.c

  Summary:
    Interrupt vectors mapping

  Description:
    This file maps all the interrupt vectors to their corresponding
    implementations. If a particular module interrupt is used, then its ISR
    definition can be found in corresponding PLIB source file. If a module
    interrupt is not used, then its ISR implementation is mapped to dummy
    handler.
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

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "definitions.h"

// *****************************************************************************
// *****************************************************************************
// Section: System Interrupt Vector Functions
// *****************************************************************************
// *****************************************************************************

extern uint32_t _stack;

/* Brief default interrupt handler for unused IRQs.*/
void __attribute__((optimize("-O1"),section(".text.Dummy_Handler"),long_call))Dummy_Handler(void)
{
    while (1)
    {
    }
}
/* Device vectors list dummy definition*/
void Reset_Handler              ( void ) __attribute__((weak, alias("Dummy_Handler")));
void NonMaskableInt_Handler     ( void ) __attribute__((weak, alias("Dummy_Handler")));
void HardFault_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
void SVCall_Handler             ( void ) __attribute__((weak, alias("Dummy_Handler")));
void PendSV_Handler             ( void ) __attribute__((weak, alias("Dummy_Handler")));
void SysTick_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
void SYSTEM_Handler             ( void ) __attribute__((weak, alias("Dummy_Handler")));
void WDT_Handler                ( void ) __attribute__((weak, alias("Dummy_Handler")));
void RTC_Handler                ( void ) __attribute__((weak, alias("Dummy_Handler")));
void EIC_InterruptHandler       ( void ) __attribute__((weak, alias("Dummy_Handler")));
void FREQM_Handler              ( void ) __attribute__((weak, alias("Dummy_Handler")));
void TSENS_Handler              ( void ) __attribute__((weak, alias("Dummy_Handler")));
void NVMCTRL_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
void DMAC_Handler               ( void ) __attribute__((weak, alias("Dummy_Handler")));
void EVSYS_Handler              ( void ) __attribute__((weak, alias("Dummy_Handler")));
void SERCOM0_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
void SERCOM1_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
void SERCOM2_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
void SERCOM3_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
void SERCOM4_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
void SERCOM5_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
void CAN0_Handler               ( void ) __attribute__((weak, alias("Dummy_Handler")));
void CAN1_Handler               ( void ) __attribute__((weak, alias("Dummy_Handler")));
void TCC0_Handler               ( void ) __attribute__((weak, alias("Dummy_Handler")));
void TCC1_Handler               ( void ) __attribute__((weak, alias("Dummy_Handler")));
void TCC2_Handler               ( void ) __attribute__((weak, alias("Dummy_Handler")));
void TC0_Handler                ( void ) __attribute__((weak, alias("Dummy_Handler")));
void TC1_Handler                ( void ) __attribute__((weak, alias("Dummy_Handler")));
void TC2_Handler                ( void ) __attribute__((weak, alias("Dummy_Handler")));
void TC3_Handler                ( void ) __attribute__((weak, alias("Dummy_Handler")));
void TC4_Handler                ( void ) __attribute__((weak, alias("Dummy_Handler")));
void ADC0_InterruptHandler      ( void ) __attribute__((weak, alias("Dummy_Handler")));
void ADC1_Handler               ( void ) __attribute__((weak, alias("Dummy_Handler")));
void AC_Handler                 ( void ) __attribute__((weak, alias("Dummy_Handler")));
void DAC_Handler                ( void ) __attribute__((weak, alias("Dummy_Handler")));
void SDADC_Handler              ( void ) __attribute__((weak, alias("Dummy_Handler")));
void PTC_Handler                ( void ) __attribute__((weak, alias("Dummy_Handler")));



/* Mutiple handlers for vector */



__attribute__ ((section(".vectors")))
const DeviceVectors exception_table=
{
    /* Configure Initial Stack Pointer, using linker-generated symbols */
    .pvStack = (void*) (&_stack),

    .pfnReset_Handler              = ( void * ) Reset_Handler,
    .pfnNonMaskableInt_Handler     = ( void * ) NonMaskableInt_Handler,
    .pfnHardFault_Handler          = ( void * ) HardFault_Handler,
    .pfnSVCall_Handler             = ( void * ) SVCall_Handler,
    .pfnPendSV_Handler             = ( void * ) PendSV_Handler,
    .pfnSysTick_Handler            = ( void * ) SysTick_Handler,
    .pfnSYSTEM_Handler             = ( void * ) SYSTEM_Handler,
    .pfnWDT_Handler                = ( void * ) WDT_Handler,
    .pfnRTC_Handler                = ( void * ) RTC_Handler,
    .pfnEIC_Handler                = ( void * ) EIC_InterruptHandler,
    .pfnFREQM_Handler              = ( void * ) FREQM_Handler,
    .pfnTSENS_Handler              = ( void * ) TSENS_Handler,
    .pfnNVMCTRL_Handler            = ( void * ) NVMCTRL_Handler,
    .pfnDMAC_Handler               = ( void * ) DMAC_Handler,
    .pfnEVSYS_Handler              = ( void * ) EVSYS_Handler,
    .pfnSERCOM0_Handler            = ( void * ) SERCOM0_Handler,
    .pfnSERCOM1_Handler            = ( void * ) SERCOM1_Handler,
    .pfnSERCOM2_Handler            = ( void * ) SERCOM2_Handler,
    .pfnSERCOM3_Handler            = ( void * ) SERCOM3_Handler,
    .pfnSERCOM4_Handler            = ( void * ) SERCOM4_Handler,
    .pfnSERCOM5_Handler            = ( void * ) SERCOM5_Handler,
    .pfnCAN0_Handler               = ( void * ) CAN0_Handler,
    .pfnCAN1_Handler               = ( void * ) CAN1_Handler,
    .pfnTCC0_Handler               = ( void * ) TCC0_Handler,
    .pfnTCC1_Handler               = ( void * ) TCC1_Handler,
    .pfnTCC2_Handler               = ( void * ) TCC2_Handler,
    .pfnTC0_Handler                = ( void * ) TC0_Handler,
    .pfnTC1_Handler                = ( void * ) TC1_Handler,
    .pfnTC2_Handler                = ( void * ) TC2_Handler,
    .pfnTC3_Handler                = ( void * ) TC3_Handler,
    .pfnTC4_Handler                = ( void * ) TC4_Handler,
    .pfnADC0_Handler               = ( void * ) ADC0_InterruptHandler,
    .pfnADC1_Handler               = ( void * ) ADC1_Handler,
    .pfnAC_Handler                 = ( void * ) AC_Handler,
    .pfnDAC_Handler                = ( void * ) DAC_Handler,
    .pfnSDADC_Handler              = ( void * ) SDADC_Handler,
    .pfnPTC_Handler                = ( void * ) PTC_Handler,


};

/*******************************************************************************
 End of File
*/
