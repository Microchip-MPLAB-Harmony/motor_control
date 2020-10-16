/*******************************************************************************
  PIO PLIB

  Company:
    Microchip Technology Inc.

  File Name:
    plib_pio.h

  Summary:
    PIO PLIB Header File

  Description:
    This library provides an interface to control and interact with Parallel
    Input/Output controller (PIO) module.

*******************************************************************************/

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

#ifndef PLIB_PIO_H
#define PLIB_PIO_H

#include "device.h"
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Data types and constants
// *****************************************************************************
// *****************************************************************************

#define PIOA_REGS       ((pio_group_registers_t*)(&(PIO_REGS->PIO_GROUP[0])))
#define PIOB_REGS       ((pio_group_registers_t*)(&(PIO_REGS->PIO_GROUP[1])))
#define PIOC_REGS       ((pio_group_registers_t*)(&(PIO_REGS->PIO_GROUP[2])))
#define PIOD_REGS       ((pio_group_registers_t*)(&(PIO_REGS->PIO_GROUP[3])))
#define PIOE_REGS       ((pio_group_registers_t*)(&(PIO_REGS->PIO_GROUP[4])))

#define PIOF_REGS       ((pio_group_registers_t*)(&(PIO_REGS->PIO_GROUP[5])))

#define PIOG_REGS       ((pio_group_registers_t*)(&(PIO_REGS->PIO_GROUP[6])))




/*** Macros for SWITCH_RESET pin ***/
#define SWITCH_RESET_Set()               (PIOA_REGS->PIO_SODR = (1<<20))
#define SWITCH_RESET_Clear()             (PIOA_REGS->PIO_CODR = (1<<20))
#define SWITCH_RESET_Toggle()            do {\
                                            PIOA_REGS->PIO_MSKR = (1<<20); \
                                            PIOA_REGS->PIO_ODSR ^= (1<<20);\
                                        } while (0)
#define SWITCH_RESET_OutputEnable()      do {\
                                            PIOA_REGS->PIO_MSKR = (1<<20); \
                                            PIOA_REGS->PIO_CFGR |=(1 << PIO_CFGR_DIR_Pos);\
                                        }while(0)
#define SWITCH_RESET_InputEnable()       do { \
                                            PIOA_REGS->PIO_MSKR = (1<<20); \
                                            PIOA_REGS->PIO_CFGR &= ~(1 << PIO_CFGR_DIR_Pos);\
                                        } while (0)
#define SWITCH_RESET_Get()               ((PIOA_REGS->PIO_PDSR >> 20) & 0x1)
#define SWITCH_RESET_PIN                  PIO_PIN_PA20

/*** Macros for SWITCH_DIRECTION pin ***/
#define SWITCH_DIRECTION_Set()               (PIOA_REGS->PIO_SODR = (1<<21))
#define SWITCH_DIRECTION_Clear()             (PIOA_REGS->PIO_CODR = (1<<21))
#define SWITCH_DIRECTION_Toggle()            do {\
                                            PIOA_REGS->PIO_MSKR = (1<<21); \
                                            PIOA_REGS->PIO_ODSR ^= (1<<21);\
                                        } while (0)
#define SWITCH_DIRECTION_OutputEnable()      do {\
                                            PIOA_REGS->PIO_MSKR = (1<<21); \
                                            PIOA_REGS->PIO_CFGR |=(1 << PIO_CFGR_DIR_Pos);\
                                        }while(0)
#define SWITCH_DIRECTION_InputEnable()       do { \
                                            PIOA_REGS->PIO_MSKR = (1<<21); \
                                            PIOA_REGS->PIO_CFGR &= ~(1 << PIO_CFGR_DIR_Pos);\
                                        } while (0)
#define SWITCH_DIRECTION_Get()               ((PIOA_REGS->PIO_PDSR >> 21) & 0x1)
#define SWITCH_DIRECTION_PIN                  PIO_PIN_PA21

/*** Macros for SWITCH_START pin ***/
#define SWITCH_START_Set()               (PIOA_REGS->PIO_SODR = (1<<22))
#define SWITCH_START_Clear()             (PIOA_REGS->PIO_CODR = (1<<22))
#define SWITCH_START_Toggle()            do {\
                                            PIOA_REGS->PIO_MSKR = (1<<22); \
                                            PIOA_REGS->PIO_ODSR ^= (1<<22);\
                                        } while (0)
#define SWITCH_START_OutputEnable()      do {\
                                            PIOA_REGS->PIO_MSKR = (1<<22); \
                                            PIOA_REGS->PIO_CFGR |=(1 << PIO_CFGR_DIR_Pos);\
                                        }while(0)
#define SWITCH_START_InputEnable()       do { \
                                            PIOA_REGS->PIO_MSKR = (1<<22); \
                                            PIOA_REGS->PIO_CFGR &= ~(1 << PIO_CFGR_DIR_Pos);\
                                        } while (0)
#define SWITCH_START_Get()               ((PIOA_REGS->PIO_PDSR >> 22) & 0x1)
#define SWITCH_START_PIN                  PIO_PIN_PA22

/*** Macros for SWITCH_INCR pin ***/
#define SWITCH_INCR_Set()               (PIOA_REGS->PIO_SODR = (1<<23))
#define SWITCH_INCR_Clear()             (PIOA_REGS->PIO_CODR = (1<<23))
#define SWITCH_INCR_Toggle()            do {\
                                            PIOA_REGS->PIO_MSKR = (1<<23); \
                                            PIOA_REGS->PIO_ODSR ^= (1<<23);\
                                        } while (0)
#define SWITCH_INCR_OutputEnable()      do {\
                                            PIOA_REGS->PIO_MSKR = (1<<23); \
                                            PIOA_REGS->PIO_CFGR |=(1 << PIO_CFGR_DIR_Pos);\
                                        }while(0)
#define SWITCH_INCR_InputEnable()       do { \
                                            PIOA_REGS->PIO_MSKR = (1<<23); \
                                            PIOA_REGS->PIO_CFGR &= ~(1 << PIO_CFGR_DIR_Pos);\
                                        } while (0)
#define SWITCH_INCR_Get()               ((PIOA_REGS->PIO_PDSR >> 23) & 0x1)
#define SWITCH_INCR_PIN                  PIO_PIN_PA23

/*** Macros for SWITCH_DECR pin ***/
#define SWITCH_DECR_Set()               (PIOA_REGS->PIO_SODR = (1<<24))
#define SWITCH_DECR_Clear()             (PIOA_REGS->PIO_CODR = (1<<24))
#define SWITCH_DECR_Toggle()            do {\
                                            PIOA_REGS->PIO_MSKR = (1<<24); \
                                            PIOA_REGS->PIO_ODSR ^= (1<<24);\
                                        } while (0)
#define SWITCH_DECR_OutputEnable()      do {\
                                            PIOA_REGS->PIO_MSKR = (1<<24); \
                                            PIOA_REGS->PIO_CFGR |=(1 << PIO_CFGR_DIR_Pos);\
                                        }while(0)
#define SWITCH_DECR_InputEnable()       do { \
                                            PIOA_REGS->PIO_MSKR = (1<<24); \
                                            PIOA_REGS->PIO_CFGR &= ~(1 << PIO_CFGR_DIR_Pos);\
                                        } while (0)
#define SWITCH_DECR_Get()               ((PIOA_REGS->PIO_PDSR >> 24) & 0x1)
#define SWITCH_DECR_PIN                  PIO_PIN_PA24

/*** Macros for LED_BI_GREEN pin ***/
#define LED_BI_GREEN_Set()               (PIOB_REGS->PIO_SODR = (1<<15))
#define LED_BI_GREEN_Clear()             (PIOB_REGS->PIO_CODR = (1<<15))
#define LED_BI_GREEN_Toggle()            do {\
                                            PIOB_REGS->PIO_MSKR = (1<<15); \
                                            PIOB_REGS->PIO_ODSR ^= (1<<15);\
                                        } while (0)
#define LED_BI_GREEN_OutputEnable()      do {\
                                            PIOB_REGS->PIO_MSKR = (1<<15); \
                                            PIOB_REGS->PIO_CFGR |=(1 << PIO_CFGR_DIR_Pos);\
                                        }while(0)
#define LED_BI_GREEN_InputEnable()       do { \
                                            PIOB_REGS->PIO_MSKR = (1<<15); \
                                            PIOB_REGS->PIO_CFGR &= ~(1 << PIO_CFGR_DIR_Pos);\
                                        } while (0)
#define LED_BI_GREEN_Get()               ((PIOB_REGS->PIO_PDSR >> 15) & 0x1)
#define LED_BI_GREEN_PIN                  PIO_PIN_PB15

/*** Macros for LED_BI_RED pin ***/
#define LED_BI_RED_Set()               (PIOB_REGS->PIO_SODR = (1<<16))
#define LED_BI_RED_Clear()             (PIOB_REGS->PIO_CODR = (1<<16))
#define LED_BI_RED_Toggle()            do {\
                                            PIOB_REGS->PIO_MSKR = (1<<16); \
                                            PIOB_REGS->PIO_ODSR ^= (1<<16);\
                                        } while (0)
#define LED_BI_RED_OutputEnable()      do {\
                                            PIOB_REGS->PIO_MSKR = (1<<16); \
                                            PIOB_REGS->PIO_CFGR |=(1 << PIO_CFGR_DIR_Pos);\
                                        }while(0)
#define LED_BI_RED_InputEnable()       do { \
                                            PIOB_REGS->PIO_MSKR = (1<<16); \
                                            PIOB_REGS->PIO_CFGR &= ~(1 << PIO_CFGR_DIR_Pos);\
                                        } while (0)
#define LED_BI_RED_Get()               ((PIOB_REGS->PIO_PDSR >> 16) & 0x1)
#define LED_BI_RED_PIN                  PIO_PIN_PB16

/*** Macros for GPIO_PB17 pin ***/
#define GPIO_PB17_Set()               (PIOB_REGS->PIO_SODR = (1<<17))
#define GPIO_PB17_Clear()             (PIOB_REGS->PIO_CODR = (1<<17))
#define GPIO_PB17_Toggle()            do {\
                                            PIOB_REGS->PIO_MSKR = (1<<17); \
                                            PIOB_REGS->PIO_ODSR ^= (1<<17);\
                                        } while (0)
#define GPIO_PB17_OutputEnable()      do {\
                                            PIOB_REGS->PIO_MSKR = (1<<17); \
                                            PIOB_REGS->PIO_CFGR |=(1 << PIO_CFGR_DIR_Pos);\
                                        }while(0)
#define GPIO_PB17_InputEnable()       do { \
                                            PIOB_REGS->PIO_MSKR = (1<<17); \
                                            PIOB_REGS->PIO_CFGR &= ~(1 << PIO_CFGR_DIR_Pos);\
                                        } while (0)
#define GPIO_PB17_Get()               ((PIOB_REGS->PIO_PDSR >> 17) & 0x1)
#define GPIO_PB17_PIN                  PIO_PIN_PB17

/*** Macros for GPIO_PB18 pin ***/
#define GPIO_PB18_Set()               (PIOB_REGS->PIO_SODR = (1<<18))
#define GPIO_PB18_Clear()             (PIOB_REGS->PIO_CODR = (1<<18))
#define GPIO_PB18_Toggle()            do {\
                                            PIOB_REGS->PIO_MSKR = (1<<18); \
                                            PIOB_REGS->PIO_ODSR ^= (1<<18);\
                                        } while (0)
#define GPIO_PB18_OutputEnable()      do {\
                                            PIOB_REGS->PIO_MSKR = (1<<18); \
                                            PIOB_REGS->PIO_CFGR |=(1 << PIO_CFGR_DIR_Pos);\
                                        }while(0)
#define GPIO_PB18_InputEnable()       do { \
                                            PIOB_REGS->PIO_MSKR = (1<<18); \
                                            PIOB_REGS->PIO_CFGR &= ~(1 << PIO_CFGR_DIR_Pos);\
                                        } while (0)
#define GPIO_PB18_Get()               ((PIOB_REGS->PIO_PDSR >> 18) & 0x1)
#define GPIO_PB18_PIN                  PIO_PIN_PB18

/*** Macros for LED0 pin ***/
#define LED0_Set()               (PIOB_REGS->PIO_SODR = (1<<19))
#define LED0_Clear()             (PIOB_REGS->PIO_CODR = (1<<19))
#define LED0_Toggle()            do {\
                                            PIOB_REGS->PIO_MSKR = (1<<19); \
                                            PIOB_REGS->PIO_ODSR ^= (1<<19);\
                                        } while (0)
#define LED0_OutputEnable()      do {\
                                            PIOB_REGS->PIO_MSKR = (1<<19); \
                                            PIOB_REGS->PIO_CFGR |=(1 << PIO_CFGR_DIR_Pos);\
                                        }while(0)
#define LED0_InputEnable()       do { \
                                            PIOB_REGS->PIO_MSKR = (1<<19); \
                                            PIOB_REGS->PIO_CFGR &= ~(1 << PIO_CFGR_DIR_Pos);\
                                        } while (0)
#define LED0_Get()               ((PIOB_REGS->PIO_PDSR >> 19) & 0x1)
#define LED0_PIN                  PIO_PIN_PB19

/*** Macros for LED1 pin ***/
#define LED1_Set()               (PIOB_REGS->PIO_SODR = (1<<23))
#define LED1_Clear()             (PIOB_REGS->PIO_CODR = (1<<23))
#define LED1_Toggle()            do {\
                                            PIOB_REGS->PIO_MSKR = (1<<23); \
                                            PIOB_REGS->PIO_ODSR ^= (1<<23);\
                                        } while (0)
#define LED1_OutputEnable()      do {\
                                            PIOB_REGS->PIO_MSKR = (1<<23); \
                                            PIOB_REGS->PIO_CFGR |=(1 << PIO_CFGR_DIR_Pos);\
                                        }while(0)
#define LED1_InputEnable()       do { \
                                            PIOB_REGS->PIO_MSKR = (1<<23); \
                                            PIOB_REGS->PIO_CFGR &= ~(1 << PIO_CFGR_DIR_Pos);\
                                        } while (0)
#define LED1_Get()               ((PIOB_REGS->PIO_PDSR >> 23) & 0x1)
#define LED1_PIN                  PIO_PIN_PB23

/*** Macros for GPIO_PB24 pin ***/
#define GPIO_PB24_Set()               (PIOB_REGS->PIO_SODR = (1<<24))
#define GPIO_PB24_Clear()             (PIOB_REGS->PIO_CODR = (1<<24))
#define GPIO_PB24_Toggle()            do {\
                                            PIOB_REGS->PIO_MSKR = (1<<24); \
                                            PIOB_REGS->PIO_ODSR ^= (1<<24);\
                                        } while (0)
#define GPIO_PB24_OutputEnable()      do {\
                                            PIOB_REGS->PIO_MSKR = (1<<24); \
                                            PIOB_REGS->PIO_CFGR |=(1 << PIO_CFGR_DIR_Pos);\
                                        }while(0)
#define GPIO_PB24_InputEnable()       do { \
                                            PIOB_REGS->PIO_MSKR = (1<<24); \
                                            PIOB_REGS->PIO_CFGR &= ~(1 << PIO_CFGR_DIR_Pos);\
                                        } while (0)
#define GPIO_PB24_Get()               ((PIOB_REGS->PIO_PDSR >> 24) & 0x1)
#define GPIO_PB24_PIN                  PIO_PIN_PB24

/*** Macros for GPIO_PB28 pin ***/
#define GPIO_PB28_Set()               (PIOB_REGS->PIO_SODR = (1<<28))
#define GPIO_PB28_Clear()             (PIOB_REGS->PIO_CODR = (1<<28))
#define GPIO_PB28_Toggle()            do {\
                                            PIOB_REGS->PIO_MSKR = (1<<28); \
                                            PIOB_REGS->PIO_ODSR ^= (1<<28);\
                                        } while (0)
#define GPIO_PB28_OutputEnable()      do {\
                                            PIOB_REGS->PIO_MSKR = (1<<28); \
                                            PIOB_REGS->PIO_CFGR |=(1 << PIO_CFGR_DIR_Pos);\
                                        }while(0)
#define GPIO_PB28_InputEnable()       do { \
                                            PIOB_REGS->PIO_MSKR = (1<<28); \
                                            PIOB_REGS->PIO_CFGR &= ~(1 << PIO_CFGR_DIR_Pos);\
                                        } while (0)
#define GPIO_PB28_Get()               ((PIOB_REGS->PIO_PDSR >> 28) & 0x1)
#define GPIO_PB28_PIN                  PIO_PIN_PB28

/*** Macros for LED2 pin ***/
#define LED2_Set()               (PIOF_REGS->PIO_SODR = (1<<19))
#define LED2_Clear()             (PIOF_REGS->PIO_CODR = (1<<19))
#define LED2_Toggle()            do {\
                                            PIOF_REGS->PIO_MSKR = (1<<19); \
                                            PIOF_REGS->PIO_ODSR ^= (1<<19);\
                                        } while (0)
#define LED2_OutputEnable()      do {\
                                            PIOF_REGS->PIO_MSKR = (1<<19); \
                                            PIOF_REGS->PIO_CFGR |=(1 << PIO_CFGR_DIR_Pos);\
                                        }while(0)
#define LED2_InputEnable()       do { \
                                            PIOF_REGS->PIO_MSKR = (1<<19); \
                                            PIOF_REGS->PIO_CFGR &= ~(1 << PIO_CFGR_DIR_Pos);\
                                        } while (0)
#define LED2_Get()               ((PIOF_REGS->PIO_PDSR >> 19) & 0x1)
#define LED2_PIN                  PIO_PIN_PF19

/*** Macros for LED3 pin ***/
#define LED3_Set()               (PIOF_REGS->PIO_SODR = (1<<20))
#define LED3_Clear()             (PIOF_REGS->PIO_CODR = (1<<20))
#define LED3_Toggle()            do {\
                                            PIOF_REGS->PIO_MSKR = (1<<20); \
                                            PIOF_REGS->PIO_ODSR ^= (1<<20);\
                                        } while (0)
#define LED3_OutputEnable()      do {\
                                            PIOF_REGS->PIO_MSKR = (1<<20); \
                                            PIOF_REGS->PIO_CFGR |=(1 << PIO_CFGR_DIR_Pos);\
                                        }while(0)
#define LED3_InputEnable()       do { \
                                            PIOF_REGS->PIO_MSKR = (1<<20); \
                                            PIOF_REGS->PIO_CFGR &= ~(1 << PIO_CFGR_DIR_Pos);\
                                        } while (0)
#define LED3_Get()               ((PIOF_REGS->PIO_PDSR >> 20) & 0x1)
#define LED3_PIN                  PIO_PIN_PF20



// *****************************************************************************
/* PIO Port

  Summary:
    Identifies the available PIO Ports.

  Description:
    This enumeration identifies the available PIO Ports.

  Remarks:
    The caller should not rely on the specific numbers assigned to any of
    these values as they may change from one processor to the next.

    Not all ports are available on all devices.  Refer to the specific
    device data sheet to determine which ports are supported.
*/

typedef enum
{
    /* Port A Pins */
    PIO_PORT_A = (uint32_t)&(PIO_REGS->PIO_GROUP[0]),

    /* Port B Pins */
    PIO_PORT_B = (uint32_t)&(PIO_REGS->PIO_GROUP[1]),

    /* Port C Pins */
    PIO_PORT_C = (uint32_t)&(PIO_REGS->PIO_GROUP[2]),

    /* Port D Pins */
    PIO_PORT_D = (uint32_t)&(PIO_REGS->PIO_GROUP[3]),

    /* Port E Pins */
    PIO_PORT_E = (uint32_t)&(PIO_REGS->PIO_GROUP[4]),

    /* Port F Pins */
    PIO_PORT_F = (uint32_t)&(PIO_REGS->PIO_GROUP[5]),

    /* Port G Pins */
    PIO_PORT_G = (uint32_t)&(PIO_REGS->PIO_GROUP[6])

} PIO_PORT;

// *****************************************************************************
/* PIO Port Pins

  Summary:
    Identifies the available PIO port pins.

  Description:
    This enumeration identifies the available PIO port pins.

  Remarks:
    The caller should not rely on the specific numbers assigned to any of
    these values as they may change from one processor to the next.

    Not all pins are available on all devices.  Refer to the specific
    device data sheet to determine which pins are supported.
*/

typedef enum
{
    PIO_PIN_PA0 = 0,
    PIO_PIN_PA1 = 1,
    PIO_PIN_PA2 = 2,
    PIO_PIN_PA3 = 3,
    PIO_PIN_PA4 = 4,
    PIO_PIN_PA5 = 5,
    PIO_PIN_PA6 = 6,
    PIO_PIN_PA7 = 7,
    PIO_PIN_PA8 = 8,
    PIO_PIN_PA9 = 9,
    PIO_PIN_PA10 = 10,
    PIO_PIN_PA11 = 11,
    PIO_PIN_PA12 = 12,
    PIO_PIN_PA13 = 13,
    PIO_PIN_PA16 = 16,
    PIO_PIN_PA17 = 17,
    PIO_PIN_PA19 = 19,
    PIO_PIN_PA20 = 20,
    PIO_PIN_PA21 = 21,
    PIO_PIN_PA22 = 22,
    PIO_PIN_PA23 = 23,
    PIO_PIN_PA24 = 24,
    PIO_PIN_PA25 = 25,
    PIO_PIN_PA26 = 26,
    PIO_PIN_PA27 = 27,
    PIO_PIN_PA28 = 28,
    PIO_PIN_PB0 = 32,
    PIO_PIN_PB1 = 33,
    PIO_PIN_PB2 = 34,
    PIO_PIN_PB3 = 35,
    PIO_PIN_PB4 = 36,
    PIO_PIN_PB5 = 37,
    PIO_PIN_PB6 = 38,
    PIO_PIN_PB7 = 39,
    PIO_PIN_PB8 = 40,
    PIO_PIN_PB9 = 41,
    PIO_PIN_PB10 = 42,
    PIO_PIN_PB11 = 43,
    PIO_PIN_PB12 = 44,
    PIO_PIN_PB13 = 45,
    PIO_PIN_PB14 = 46,
    PIO_PIN_PB15 = 47,
    PIO_PIN_PB16 = 48,
    PIO_PIN_PB17 = 49,
    PIO_PIN_PB18 = 50,
    PIO_PIN_PB19 = 51,
    PIO_PIN_PB20 = 52,
    PIO_PIN_PB21 = 53,
    PIO_PIN_PB22 = 54,
    PIO_PIN_PB23 = 55,
    PIO_PIN_PB24 = 56,
    PIO_PIN_PB25 = 57,
    PIO_PIN_PB26 = 58,
    PIO_PIN_PB27 = 59,
    PIO_PIN_PB28 = 60,
    PIO_PIN_PB29 = 61,
    PIO_PIN_PC0 = 64,
    PIO_PIN_PC1 = 65,
    PIO_PIN_PC2 = 66,
    PIO_PIN_PC3 = 67,
    PIO_PIN_PC4 = 68,
    PIO_PIN_PC5 = 69,
    PIO_PIN_PC6 = 70,
    PIO_PIN_PC7 = 71,
    PIO_PIN_PC8 = 72,
    PIO_PIN_PC9 = 73,
    PIO_PIN_PC10 = 74,
    PIO_PIN_PC11 = 75,
    PIO_PIN_PC12 = 76,
    PIO_PIN_PC13 = 77,
    PIO_PIN_PC14 = 78,
    PIO_PIN_PC15 = 79,
    PIO_PIN_PC16 = 80,
    PIO_PIN_PC17 = 81,
    PIO_PIN_PC18 = 82,
    PIO_PIN_PC19 = 83,
    PIO_PIN_PC20 = 84,
    PIO_PIN_PC21 = 85,
    PIO_PIN_PC22 = 86,
    PIO_PIN_PC23 = 87,
    PIO_PIN_PC24 = 88,
    PIO_PIN_PC25 = 89,
    PIO_PIN_PC26 = 90,
    PIO_PIN_PC27 = 91,
    PIO_PIN_PC28 = 92,
    PIO_PIN_PC29 = 93,
    PIO_PIN_PC30 = 94,
    PIO_PIN_PC31 = 95,
    PIO_PIN_PD0 = 96,
    PIO_PIN_PD1 = 97,
    PIO_PIN_PD2 = 98,
    PIO_PIN_PD3 = 99,
    PIO_PIN_PD4 = 100,
    PIO_PIN_PD5 = 101,
    PIO_PIN_PD6 = 102,
    PIO_PIN_PD7 = 103,
    PIO_PIN_PD8 = 104,
    PIO_PIN_PD9 = 105,
    PIO_PIN_PD10 = 106,
    PIO_PIN_PD11 = 107,
    PIO_PIN_PD12 = 108,
    PIO_PIN_PD13 = 109,
    PIO_PIN_PD14 = 110,
    PIO_PIN_PD15 = 111,
    PIO_PIN_PD16 = 112,
    PIO_PIN_PD17 = 113,
    PIO_PIN_PD18 = 114,
    PIO_PIN_PD19 = 115,
    PIO_PIN_PD20 = 116,
    PIO_PIN_PD21 = 117,
    PIO_PIN_PD22 = 118,
    PIO_PIN_PD23 = 119,
    PIO_PIN_PD24 = 120,
    PIO_PIN_PD25 = 121,
    PIO_PIN_PD26 = 122,
    PIO_PIN_PD27 = 123,
    PIO_PIN_PD28 = 124,
    PIO_PIN_PD29 = 125,
    PIO_PIN_PD30 = 126,
    PIO_PIN_PD31 = 127,
    PIO_PIN_PE0 = 128,
    PIO_PIN_PE1 = 129,
    PIO_PIN_PE2 = 130,
    PIO_PIN_PE3 = 131,
    PIO_PIN_PE4 = 132,
    PIO_PIN_PE5 = 133,
    PIO_PIN_PE6 = 134,
    PIO_PIN_PE7 = 135,
    PIO_PIN_PE8 = 136,
    PIO_PIN_PE9 = 137,
    PIO_PIN_PE10 = 138,
    PIO_PIN_PE11 = 139,
    PIO_PIN_PE12 = 140,
    PIO_PIN_PF0 = 160,
    PIO_PIN_PF1 = 161,
    PIO_PIN_PF2 = 162,
    PIO_PIN_PF3 = 163,
    PIO_PIN_PF4 = 164,
    PIO_PIN_PF5 = 165,
    PIO_PIN_PF6 = 166,
    PIO_PIN_PF7 = 167,
    PIO_PIN_PF8 = 168,
    PIO_PIN_PF9 = 169,
    PIO_PIN_PF10 = 170,
    PIO_PIN_PF11 = 171,
    PIO_PIN_PF12 = 172,
    PIO_PIN_PF13 = 173,
    PIO_PIN_PF14 = 174,
    PIO_PIN_PF15 = 175,
    PIO_PIN_PF16 = 176,
    PIO_PIN_PF17 = 177,
    PIO_PIN_PF18 = 178,
    PIO_PIN_PF19 = 179,
    PIO_PIN_PF20 = 180,
    PIO_PIN_PF21 = 181,
    PIO_PIN_PF22 = 182,
    PIO_PIN_PF23 = 183,
    PIO_PIN_PF24 = 184,
    PIO_PIN_PF25 = 185,
    PIO_PIN_PF26 = 186,
    PIO_PIN_PF27 = 187,
    PIO_PIN_PF28 = 188,
    PIO_PIN_PF29 = 189,
    PIO_PIN_PF30 = 190,
    PIO_PIN_PG0 = 192,
    PIO_PIN_PG1 = 193,
    PIO_PIN_PG2 = 194,
    PIO_PIN_PG3 = 195,
    PIO_PIN_PG4 = 196,
    PIO_PIN_PG5 = 197,
    PIO_PIN_PG6 = 198,
    PIO_PIN_PG7 = 199,
    PIO_PIN_PG8 = 200,
    PIO_PIN_PG9 = 201,
    PIO_PIN_PG10 = 202,
    PIO_PIN_PG11 = 203,
    PIO_PIN_PG12 = 204,
    PIO_PIN_PG13 = 205,
    PIO_PIN_PG14 = 206,
    PIO_PIN_PG15 = 207,
    PIO_PIN_PG16 = 208,
    PIO_PIN_PG17 = 209,
    PIO_PIN_PG18 = 210,
    PIO_PIN_PG19 = 211,
    PIO_PIN_PG20 = 212,
    PIO_PIN_PG21 = 213,
    PIO_PIN_PG22 = 214,
    PIO_PIN_PG23 = 215,
    PIO_PIN_PG24 = 216,
    PIO_PIN_PG25 = 217,
    PIO_PIN_PG26 = 218,
    PIO_PIN_PG27 = 219,
    PIO_PIN_PG30 = 222,
    PIO_PIN_PG31 = 223,

    /* This element should not be used in any of the PIO APIs.
       It will be used by other modules or application to denote that none of the PIO Pin is used */
    PIO_PIN_NONE = -1

} PIO_PIN;

// *****************************************************************************
// *****************************************************************************
// Section: Generated API based on pin configurations done in Pin Manager
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    void PIO_Initialize(void)

  Summary:
    Initialize the PIO library.

  Description:
    This function initializes the PIO library and all ports and pins configured
    in the MCC Pin Manager.

  Precondition:
    None.

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>

    PIO_Initialize();

    </code>

  Remarks:
    None.
*/
void PIO_Initialize(void);

// *****************************************************************************
// *****************************************************************************
// Section: PIO Functions which operates on multiple pins of a port
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    uint32_t PIO_PortRead(PIO_PORT port)

  Summary:
    Read all the I/O lines of the selected port port.

  Description:
    This function reads the live data values on all the I/O lines of the
    selected port.  Bit values returned in each position indicate corresponding
    pin levels.
    1 = Pin is high.
    0 = Pin is low.
    This function reads the value regardless of pin configuration, whether it is
    set as as an input, driven by the PIO Controller, or driven by a peripheral.

  Precondition:
    Reading the I/O line levels requires the clock of the PIO Controller to be
    enabled, otherwise this API reads the levels present on the I/O line at the
    time the clock was disabled.

  Parameters:
    port       - One of the IO ports from the enum PIO_PORT

  Returns:
    Returns the read value of all the I/O lines of the selected port port.

  Example:
    <code>

    uint32_t value;
    value = PIO_PortRead(PIO_PORT_C);

    </code>

  Remarks:
    If the port has less than 32-bits, unimplemented pins will read as
    low (0).
    Implemented pins are Right aligned in the 32-bit return value.
*/
uint32_t PIO_PortRead(PIO_PORT port);

// *****************************************************************************
/* Function:
    void PIO_PortWrite(PIO_PORT port, uint32_t mask, uint32_t value);

  Summary:
    Write the value on the masked I/O lines of the selected port.

  Description:
    This function writes the data values driven on selected output lines of the
    selected port.  Bit values in each position indicate corresponding pin
    levels.
    1 = Pin is driven high.
    0 = Pin is driven low.

  Precondition:
    The desired pins lines of the selected port must be setup as output(s).

  Parameters:
    port       - One of the IO ports from the enum PIO_PORT
    mask       - A 32 bit value in which positions of 0s and 1s decide
                 which IO pins of the selected port will be written.
                 1's - Will write to corresponding IO pins.
                 0's - Will remain unchanged.
    value      - Value which has to be written/driven on the I/O
                 lines of the selected port for which mask bits are '1'.
                 Values for the corresponding mask bit '0' will be ignored.
  Returns:
    None.

  Example:
    <code>
    // Write binary value 0011 to the pins PC3, PC2, PC1 and PC0 respectively.
    PIO_PortWrite(PIO_PORT_C, 0x0F, 0xF563D453);

    </code>

  Remarks:
    If the port has less than 32-bits, unimplemented pins will be ignored.

    Implemented pins are Right aligned in the 32-bit value.
*/
void PIO_PortWrite(PIO_PORT port, uint32_t mask, uint32_t value);

// *****************************************************************************
/* Function:
    uint32_t PIO_PortLatchRead ( PIO_PORT port )

  Summary:
    Read the latched value on all the I/O lines of the selected port.

  Description:
    This function reads the latched data values on all the I/O lines of the
    selected port.  Bit values returned in each position indicate corresponding
    pin levels.
    1 = Pin is high.
    0 = Pin is low.

  Precondition:
    None.

  Parameters:
    port       - One of the IO ports from the enum PIO_PORT

  Returns:
    Returns the data driven on all the I/O lines of the selected port.

  Example:
    <code>

    uint32_t value;
    value = PIO_PortLatchRead(PIO_PORT_C);

    </code>

  Remarks:
    If the port has less than 32-bits, unimplemented pins will read as
    low (0).
    Implemented pins are Right aligned in the 32-bit return value.
*/
uint32_t PIO_PortLatchRead ( PIO_PORT port );

// *****************************************************************************
/* Function:
    void PIO_PortSet(PIO_PORT port, uint32_t mask)

  Summary:
    Set the selected IO pins of a port.

  Description:
    This function sets (to '1') the selected IO pins of a port.

  Precondition:
    None.

  Parameters:
    port       - One of the IO ports from the enum PIO_PORT
    mask       - A 32 bit value in which positions of 0s and 1s decide
                 which IO pins of the selected port will be set.
                 1's - Will set corresponding IO pins to high (to 1).
                 0's - Will remain unchanged.
  Returns:
    None.

  Example:
    <code>

    // Set PC5 and PC7 pins to 1
    PIO_PortSet(PIO_PORT_C, 0x00A0);

    </code>

  Remarks:
    If the port has less than 32-bits, unimplemented pins will be ignored.

    Implemented pins are Right aligned in the 32-bit value.
*/
void PIO_PortSet(PIO_PORT port, uint32_t mask);

// *****************************************************************************
/* Function:
    void PIO_PortClear(PIO_PORT port, uint32_t mask)

  Summary:
    Clear the selected IO pins of a port.

  Description:
    This function clears (to '0') the selected IO pins of a port.

  Precondition:
    None.

  Parameters:
    port       - One of the IO ports from the enum PIO_PORT
    mask       - A 32 bit value in which positions of 0s and 1s decide
                 which IO pins of the selected port will be cleared.
                 1's - Will clear corresponding IO pins to low (to 0).
                 0's - Will remain unchanged.
  Returns:
    None.

  Example:
    <code>

    // Clear PC5 and PC7 pins to 0
    PIO_PortClear(PIO_PORT_C, 0x00A0);

    </code>

  Remarks:
    If the port has less than 32-bits, unimplemented pins will be ignored.

    Implemented pins are Right aligned in the 32-bit value.
*/
void PIO_PortClear(PIO_PORT port, uint32_t mask);

// *****************************************************************************
/* Function:
    void PIO_PortToggle(PIO_PORT port, uint32_t mask)

  Summary:
    Toggles the selected IO pins of a port.

  Description:
    This function toggles (or invert) the selected IO pins of a port.

  Precondition:
    None.

  Parameters:
    port       - One of the IO ports from the enum PIO_PORT
    mask       - A 32 bit value in which positions of 0s and 1s decide
                 which IO pins of the selected port will be toggled.
                 1's - Will toggle (invert) corresponding IO pins.
                 0's - Will remain unchanged.
  Returns:
    None.

  Example:
    <code>

    // Toggles PC5 and PC7 pins
    PIO_PortToggle(PIO_PORT_C, 0x00A0);

    </code>

  Remarks:
    If the port has less than 32-bits, unimplemented pins will be ignored.

    Implemented pins are Right aligned in the 32-bit value.
*/
void PIO_PortToggle(PIO_PORT port, uint32_t mask);

// *****************************************************************************
/* Function:
    void PIO_PortInputEnable(PIO_PORT port, uint32_t mask)

  Summary:
    Enables selected IO pins of a port as input.

  Description:
    This function enables selected IO pins of a port as input.

  Precondition:
    None.

  Parameters:
    port          - One or more of the of the IO ports from the enum PIO_PORT.
    mask          - A 32 bit value in which positions of 0s and 1s decide
                    which IO pins of the selected port will be setup as inputs.
                    1's - Will set corresponding IO pins as input(s).
                    0's - Will cause the direction of the corresponding IO pins
                          to remain unchanged.
  Returns:
    None.

  Example:
    <code>

    // Make PC5 and PC7 pins as input
    PIO_PortInputEnable(PIO_PORT_C, 0x00A0);

    </code>

  Remarks:
    None.
*/
void PIO_PortInputEnable(PIO_PORT port, uint32_t mask);

// *****************************************************************************
/* Function:
    void PIO_PortOutputEnable(PIO_PORT port, uint32_t mask)

  Summary:
    Enables selected IO pins of a port as output(s).

  Description:
    This function enables selected IO pins of the given port as output(s).

  Precondition:
    None.

  Parameters:
    port       - One of the IO ports from the enum PIO_PORT
    mask       - A 32 bit value in which positions of 0s and 1s decide
                 which IO pins of the selected port will be setup as outputs.
                 1's - Will set corresponding IO pins as output(s).
                 0's - Will cause the direction of the corresponding IO pins
                       to remain unchanged.
  Returns:
    None.

  Example:
    <code>

    // Make PC5 and PC7 pins as output
    PIO_PortOutputEnable(PIO_PORT_C, 0x00A0);

    </code>

  Remarks:
    None.
*/
void PIO_PortOutputEnable(PIO_PORT port, uint32_t mask);


// *****************************************************************************
// *****************************************************************************
// Section: PIO Functions which operates on one pin at a time
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    void PIO_PinWrite(PIO_PIN pin, bool value)

  Summary:
    Writes the selected pin.

  Description:
    This function writes/drives the "value" on the selected I/O line/pin.

  Precondition:
    None.

  Parameters:
    pin       - One of the IO pins from the enum PIO_PIN
    value     - value to be written on the selected pin:
                true  = set pin to high (1).
                false = clear pin to low (0).

  Returns:
    None.

  Example:
    <code>
    PIO_PinWrite(PIO_PIN_PB3, true);
    </code>

  Remarks:
    None.
*/
static inline void PIO_PinWrite(PIO_PIN pin, bool value)
{
    PIO_PortWrite((PIO_PORT)(PIO_BASE_ADDRESS + (0x40 * (pin>>5))), (uint32_t)(0x1) << (pin & 0x1f), (uint32_t)(value) << (pin & 0x1f));
}

// *****************************************************************************
/* Function:
    bool PIO_PinRead(PIO_PIN pin)

  Summary:
    Read the selected pin value.

  Description:
    This function reads the selected pin value.
    it reads the value regardless of pin configuration, whether uniquely as an
    input, or driven by the PIO Controller, or driven by peripheral.

  Precondition:
    Reading the I/O line levels requires the clock of the PIO Controller to be
    enabled, otherwise this API reads the levels present on the I/O line at the
    time the clock was disabled.

  Parameters:
    pin       - One of the IO pins from the enum PIO_PIN

  Returns:
    Returns the read value of the selected I/O pin.

  Example:
    <code>

    bool value;
    value = PIO_PinRead(PIO_PIN_PB3);

    </code>

  Remarks:
       To read the latched value on this pin, PIO_PinLatchRead API should be used.
*/

static inline bool PIO_PinRead(PIO_PIN pin)
{
    return (bool)((PIO_PortRead((PIO_PORT)(PIO_BASE_ADDRESS + (0x40 * (pin>>5)))) >> (pin & 0x1F)) & 0x1);
}


// *****************************************************************************
/* Function:
    bool PIO_PinLatchRead ( PIO_PIN pin )

  Summary:
    Read the value driven on the selected pin.

  Description:
    This function reads the data driven on the selected I/O line/pin.
    Whatever data is written/driven on I/O line by using any of the PIO PLIB
    APIs, will be read by this API.

  Precondition:
    None.

  Parameters:
    pin       - One of the IO pins from the enum PIO_PIN

  Returns:
    Returns the value driven on the selected I/O pin.

  Example:
    <code>

    bool value;
    value = PIO_PinLatchRead(PIO_PIN_PB3);

    </code>

  Remarks:
    To read actual pin value, PIO_PinRead API should be used.
*/
static inline bool PIO_PinLatchRead(PIO_PIN pin)
{
    return (bool)((PIO_PortLatchRead((PIO_PORT)(PIO_BASE_ADDRESS + (0x40 * (pin>>5)))) >> (pin & 0x1F)) & 0x1);
}

// *****************************************************************************
/* Function:
    void PIO_PinToggle(PIO_PIN pin)

  Summary:
    Toggles the selected pin.

  Description:
    This function toggles/inverts the value on the selected I/O line/pin.

  Precondition:
    None.

  Parameters:
    pin       - One of the IO pins from the enum PIO_PIN

  Returns:
    None.

  Example:
    <code>

    PIO_PinToggle(PIO_PIN_PB3);

    </code>

  Remarks:
    None.
*/
static inline void PIO_PinToggle(PIO_PIN pin)
{
    PIO_PortToggle((PIO_PORT)(PIO_BASE_ADDRESS + (0x40 * (pin>>5))), 0x1 << (pin & 0x1F));
}

// *****************************************************************************
/* Function:
    void PIO_PinSet(PIO_PIN pin)

  Summary:
    Sets the selected pin.

  Description:
    This function drives '1' on the selected I/O line/pin.

  Precondition:
    None.

  Parameters:
    pin       - One of the IO pins from the enum PIO_PIN

  Returns:
    None.

  Example:
    <code>

    PIO_PinSet(PIO_PIN_PB3);

    </code>

  Remarks:
    None.
*/
static inline void PIO_PinSet(PIO_PIN pin)
{
    PIO_PortSet((PIO_PORT)(PIO_BASE_ADDRESS + (0x40 * (pin>>5))), 0x1 << (pin & 0x1F));
}

// *****************************************************************************
/* Function:
    void PIO_PinClear(PIO_PIN pin)

  Summary:
    Clears the selected pin.

  Description:
    This function drives '0' on the selected I/O line/pin.

  Precondition:
    None.

  Parameters:
    pin       - One of the IO pins from the enum PIO_PIN

  Returns:
    None.

  Example:
    <code>

    PIO_PinClear(PIO_PIN_PB3);

    </code>

  Remarks:
    None.
*/
static inline void PIO_PinClear(PIO_PIN pin)
{
    PIO_PortClear((PIO_PORT)(PIO_BASE_ADDRESS + (0x40 * (pin>>5))), 0x1 << (pin & 0x1F));
}

// *****************************************************************************
/* Function:
    void PIO_PinInputEnable(PIO_PIN pin)

  Summary:
    Enables selected IO pin as input.

  Description:
    This function enables selected IO pin as input.

  Precondition:
    None.

  Parameters:
    pin       - One of the IO pins from the enum PIO_PIN

  Returns:
    None.

  Example:
    <code>

    PIO_PinInputEnable(PIO_PIN_PB3);

    </code>

  Remarks:
    None.
*/
static inline void PIO_PinInputEnable(PIO_PIN pin)
{
    PIO_PortInputEnable((PIO_PORT)(PIO_BASE_ADDRESS + (0x40 * (pin>>5))), 0x1 << (pin & 0x1F));
}

// *****************************************************************************
/* Function:
    void PIO_PinOutputEnable(PIO_PIN pin)

  Summary:
    Enables selected IO pin as output.

  Description:
    This function enables selected IO pin as output.

  Precondition:
    None.

  Parameters:
    pin       - One of the IO pins from the enum PIO_PIN

  Returns:
    None.

  Example:
    <code>

    PIO_PinOutputEnable(PIO_PIN_PB3);

    </code>

  Remarks:
    None.
*/
static inline void PIO_PinOutputEnable(PIO_PIN pin)
{
    PIO_PortOutputEnable((PIO_PORT)(PIO_BASE_ADDRESS + (0x40 * (pin>>5))), 0x1 << (pin & 0x1F));
}


// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

}

#endif
// DOM-IGNORE-END
#endif // PLIB_PIO_H
