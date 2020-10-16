/**
 * \brief Peripheral I/O description for SAMRH71F20C
 *
 * Copyright (c) 2020 Microchip Technology Inc. and its subsidiaries.
 *
 * Subject to your compliance with these terms, you may use Microchip software and any derivatives
 * exclusively with Microchip products. It is your responsibility to comply with third party license
 * terms applicable to your use of third party software (including open source software) that may
 * accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY,
 * APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND
 * FITNESS FOR A PARTICULAR PURPOSE.
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL
 * LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF
 * MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE FULLEST EXTENT
 * ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT
 * EXCEED THE AMOUNT OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 */

/* file generated from device description version 2020-07-08T08:12:01Z */
#ifndef _SAMRH71F20C_GPIO_H_
#define _SAMRH71F20C_GPIO_H_

/* ========== Peripheral I/O pin numbers ========== */
#define PIN_PA0                     (  0  )  /**< Pin Number for PA0 */
#define PIN_PA1                     (  1  )  /**< Pin Number for PA1 */
#define PIN_PA2                     (  2  )  /**< Pin Number for PA2 */
#define PIN_PA3                     (  3  )  /**< Pin Number for PA3 */
#define PIN_PA4                     (  4  )  /**< Pin Number for PA4 */
#define PIN_PA5                     (  5  )  /**< Pin Number for PA5 */
#define PIN_PA6                     (  6  )  /**< Pin Number for PA6 */
#define PIN_PA7                     (  7  )  /**< Pin Number for PA7 */
#define PIN_PA8                     (  8  )  /**< Pin Number for PA8 */
#define PIN_PA9                     (  9  )  /**< Pin Number for PA9 */
#define PIN_PA10                    ( 10  )  /**< Pin Number for PA10 */
#define PIN_PA11                    ( 11  )  /**< Pin Number for PA11 */
#define PIN_PA12                    ( 12  )  /**< Pin Number for PA12 */
#define PIN_PA13                    ( 13  )  /**< Pin Number for PA13 */
#define PIN_PA16                    ( 16  )  /**< Pin Number for PA16 */
#define PIN_PA17                    ( 17  )  /**< Pin Number for PA17 */
#define PIN_PA19                    ( 19  )  /**< Pin Number for PA19 */
#define PIN_PA20                    ( 20  )  /**< Pin Number for PA20 */
#define PIN_PA21                    ( 21  )  /**< Pin Number for PA21 */
#define PIN_PA22                    ( 22  )  /**< Pin Number for PA22 */
#define PIN_PA23                    ( 23  )  /**< Pin Number for PA23 */
#define PIN_PA24                    ( 24  )  /**< Pin Number for PA24 */
#define PIN_PA25                    ( 25  )  /**< Pin Number for PA25 */
#define PIN_PA26                    ( 26  )  /**< Pin Number for PA26 */
#define PIN_PA27                    ( 27  )  /**< Pin Number for PA27 */
#define PIN_PA28                    ( 28  )  /**< Pin Number for PA28 */
#define PIN_PB0                     ( 32  )  /**< Pin Number for PB0 */
#define PIN_PB1                     ( 33  )  /**< Pin Number for PB1 */
#define PIN_PB2                     ( 34  )  /**< Pin Number for PB2 */
#define PIN_PB3                     ( 35  )  /**< Pin Number for PB3 */
#define PIN_PB4                     ( 36  )  /**< Pin Number for PB4 */
#define PIN_PB5                     ( 37  )  /**< Pin Number for PB5 */
#define PIN_PB6                     ( 38  )  /**< Pin Number for PB6 */
#define PIN_PB7                     ( 39  )  /**< Pin Number for PB7 */
#define PIN_PB8                     ( 40  )  /**< Pin Number for PB8 */
#define PIN_PB9                     ( 41  )  /**< Pin Number for PB9 */
#define PIN_PB10                    ( 42  )  /**< Pin Number for PB10 */
#define PIN_PB11                    ( 43  )  /**< Pin Number for PB11 */
#define PIN_PB12                    ( 44  )  /**< Pin Number for PB12 */
#define PIN_PB13                    ( 45  )  /**< Pin Number for PB13 */
#define PIN_PB14                    ( 46  )  /**< Pin Number for PB14 */
#define PIN_PB15                    ( 47  )  /**< Pin Number for PB15 */
#define PIN_PB16                    ( 48  )  /**< Pin Number for PB16 */
#define PIN_PB17                    ( 49  )  /**< Pin Number for PB17 */
#define PIN_PB18                    ( 50  )  /**< Pin Number for PB18 */
#define PIN_PB19                    ( 51  )  /**< Pin Number for PB19 */
#define PIN_PB20                    ( 52  )  /**< Pin Number for PB20 */
#define PIN_PB21                    ( 53  )  /**< Pin Number for PB21 */
#define PIN_PB22                    ( 54  )  /**< Pin Number for PB22 */
#define PIN_PB23                    ( 55  )  /**< Pin Number for PB23 */
#define PIN_PB24                    ( 56  )  /**< Pin Number for PB24 */
#define PIN_PB25                    ( 57  )  /**< Pin Number for PB25 */
#define PIN_PB26                    ( 58  )  /**< Pin Number for PB26 */
#define PIN_PB27                    ( 59  )  /**< Pin Number for PB27 */
#define PIN_PB28                    ( 60  )  /**< Pin Number for PB28 */
#define PIN_PB29                    ( 61  )  /**< Pin Number for PB29 */
#define PIN_PC0                     ( 64  )  /**< Pin Number for PC0 */
#define PIN_PC1                     ( 65  )  /**< Pin Number for PC1 */
#define PIN_PC2                     ( 66  )  /**< Pin Number for PC2 */
#define PIN_PC3                     ( 67  )  /**< Pin Number for PC3 */
#define PIN_PC4                     ( 68  )  /**< Pin Number for PC4 */
#define PIN_PC5                     ( 69  )  /**< Pin Number for PC5 */
#define PIN_PC6                     ( 70  )  /**< Pin Number for PC6 */
#define PIN_PC7                     ( 71  )  /**< Pin Number for PC7 */
#define PIN_PC8                     ( 72  )  /**< Pin Number for PC8 */
#define PIN_PC9                     ( 73  )  /**< Pin Number for PC9 */
#define PIN_PC10                    ( 74  )  /**< Pin Number for PC10 */
#define PIN_PC11                    ( 75  )  /**< Pin Number for PC11 */
#define PIN_PC12                    ( 76  )  /**< Pin Number for PC12 */
#define PIN_PC13                    ( 77  )  /**< Pin Number for PC13 */
#define PIN_PC14                    ( 78  )  /**< Pin Number for PC14 */
#define PIN_PC15                    ( 79  )  /**< Pin Number for PC15 */
#define PIN_PC16                    ( 80  )  /**< Pin Number for PC16 */
#define PIN_PC17                    ( 81  )  /**< Pin Number for PC17 */
#define PIN_PC18                    ( 82  )  /**< Pin Number for PC18 */
#define PIN_PC19                    ( 83  )  /**< Pin Number for PC19 */
#define PIN_PC20                    ( 84  )  /**< Pin Number for PC20 */
#define PIN_PC21                    ( 85  )  /**< Pin Number for PC21 */
#define PIN_PC22                    ( 86  )  /**< Pin Number for PC22 */
#define PIN_PC23                    ( 87  )  /**< Pin Number for PC23 */
#define PIN_PC24                    ( 88  )  /**< Pin Number for PC24 */
#define PIN_PC25                    ( 89  )  /**< Pin Number for PC25 */
#define PIN_PC26                    ( 90  )  /**< Pin Number for PC26 */
#define PIN_PC27                    ( 91  )  /**< Pin Number for PC27 */
#define PIN_PC28                    ( 92  )  /**< Pin Number for PC28 */
#define PIN_PC29                    ( 93  )  /**< Pin Number for PC29 */
#define PIN_PC30                    ( 94  )  /**< Pin Number for PC30 */
#define PIN_PC31                    ( 95  )  /**< Pin Number for PC31 */
#define PIN_PD0                     ( 96  )  /**< Pin Number for PD0 */
#define PIN_PD1                     ( 97  )  /**< Pin Number for PD1 */
#define PIN_PD2                     ( 98  )  /**< Pin Number for PD2 */
#define PIN_PD3                     ( 99  )  /**< Pin Number for PD3 */
#define PIN_PD4                     (100  )  /**< Pin Number for PD4 */
#define PIN_PD5                     (101  )  /**< Pin Number for PD5 */
#define PIN_PD6                     (102  )  /**< Pin Number for PD6 */
#define PIN_PD7                     (103  )  /**< Pin Number for PD7 */
#define PIN_PD8                     (104  )  /**< Pin Number for PD8 */
#define PIN_PD9                     (105  )  /**< Pin Number for PD9 */
#define PIN_PD10                    (106  )  /**< Pin Number for PD10 */
#define PIN_PD11                    (107  )  /**< Pin Number for PD11 */
#define PIN_PD12                    (108  )  /**< Pin Number for PD12 */
#define PIN_PD13                    (109  )  /**< Pin Number for PD13 */
#define PIN_PD14                    (110  )  /**< Pin Number for PD14 */
#define PIN_PD15                    (111  )  /**< Pin Number for PD15 */
#define PIN_PD16                    (112  )  /**< Pin Number for PD16 */
#define PIN_PD17                    (113  )  /**< Pin Number for PD17 */
#define PIN_PD18                    (114  )  /**< Pin Number for PD18 */
#define PIN_PD19                    (115  )  /**< Pin Number for PD19 */
#define PIN_PD20                    (116  )  /**< Pin Number for PD20 */
#define PIN_PD21                    (117  )  /**< Pin Number for PD21 */
#define PIN_PD22                    (118  )  /**< Pin Number for PD22 */
#define PIN_PD23                    (119  )  /**< Pin Number for PD23 */
#define PIN_PD24                    (120  )  /**< Pin Number for PD24 */
#define PIN_PD25                    (121  )  /**< Pin Number for PD25 */
#define PIN_PD26                    (122  )  /**< Pin Number for PD26 */
#define PIN_PD27                    (123  )  /**< Pin Number for PD27 */
#define PIN_PD28                    (124  )  /**< Pin Number for PD28 */
#define PIN_PD29                    (125  )  /**< Pin Number for PD29 */
#define PIN_PD30                    (126  )  /**< Pin Number for PD30 */
#define PIN_PD31                    (127  )  /**< Pin Number for PD31 */
#define PIN_PE0                     (128  )  /**< Pin Number for PE0 */
#define PIN_PE1                     (129  )  /**< Pin Number for PE1 */
#define PIN_PE2                     (130  )  /**< Pin Number for PE2 */
#define PIN_PE3                     (131  )  /**< Pin Number for PE3 */
#define PIN_PE4                     (132  )  /**< Pin Number for PE4 */
#define PIN_PE5                     (133  )  /**< Pin Number for PE5 */
#define PIN_PE6                     (134  )  /**< Pin Number for PE6 */
#define PIN_PE7                     (135  )  /**< Pin Number for PE7 */
#define PIN_PE8                     (136  )  /**< Pin Number for PE8 */
#define PIN_PE9                     (137  )  /**< Pin Number for PE9 */
#define PIN_PE10                    (138  )  /**< Pin Number for PE10 */
#define PIN_PE11                    (139  )  /**< Pin Number for PE11 */
#define PIN_PE12                    (140  )  /**< Pin Number for PE12 */
#define PIN_PF0                     (160  )  /**< Pin Number for PF0 */
#define PIN_PF1                     (161  )  /**< Pin Number for PF1 */
#define PIN_PF2                     (162  )  /**< Pin Number for PF2 */
#define PIN_PF3                     (163  )  /**< Pin Number for PF3 */
#define PIN_PF4                     (164  )  /**< Pin Number for PF4 */
#define PIN_PF5                     (165  )  /**< Pin Number for PF5 */
#define PIN_PF6                     (166  )  /**< Pin Number for PF6 */
#define PIN_PF7                     (167  )  /**< Pin Number for PF7 */
#define PIN_PF8                     (168  )  /**< Pin Number for PF8 */
#define PIN_PF9                     (169  )  /**< Pin Number for PF9 */
#define PIN_PF10                    (170  )  /**< Pin Number for PF10 */
#define PIN_PF11                    (171  )  /**< Pin Number for PF11 */
#define PIN_PF12                    (172  )  /**< Pin Number for PF12 */
#define PIN_PF13                    (173  )  /**< Pin Number for PF13 */
#define PIN_PF14                    (174  )  /**< Pin Number for PF14 */
#define PIN_PF15                    (175  )  /**< Pin Number for PF15 */
#define PIN_PF16                    (176  )  /**< Pin Number for PF16 */
#define PIN_PF17                    (177  )  /**< Pin Number for PF17 */
#define PIN_PF18                    (178  )  /**< Pin Number for PF18 */
#define PIN_PF19                    (179  )  /**< Pin Number for PF19 */
#define PIN_PF20                    (180  )  /**< Pin Number for PF20 */
#define PIN_PF21                    (181  )  /**< Pin Number for PF21 */
#define PIN_PF22                    (182  )  /**< Pin Number for PF22 */
#define PIN_PF23                    (183  )  /**< Pin Number for PF23 */
#define PIN_PF24                    (184  )  /**< Pin Number for PF24 */
#define PIN_PF25                    (185  )  /**< Pin Number for PF25 */
#define PIN_PF26                    (186  )  /**< Pin Number for PF26 */
#define PIN_PF27                    (187  )  /**< Pin Number for PF27 */
#define PIN_PF28                    (188  )  /**< Pin Number for PF28 */
#define PIN_PF29                    (189  )  /**< Pin Number for PF29 */
#define PIN_PF30                    (190  )  /**< Pin Number for PF30 */
#define PIN_PG0                     (192  )  /**< Pin Number for PG0 */
#define PIN_PG1                     (193  )  /**< Pin Number for PG1 */
#define PIN_PG2                     (194  )  /**< Pin Number for PG2 */
#define PIN_PG3                     (195  )  /**< Pin Number for PG3 */
#define PIN_PG4                     (196  )  /**< Pin Number for PG4 */
#define PIN_PG5                     (197  )  /**< Pin Number for PG5 */
#define PIN_PG6                     (198  )  /**< Pin Number for PG6 */
#define PIN_PG7                     (199  )  /**< Pin Number for PG7 */
#define PIN_PG8                     (200  )  /**< Pin Number for PG8 */
#define PIN_PG9                     (201  )  /**< Pin Number for PG9 */
#define PIN_PG10                    (202  )  /**< Pin Number for PG10 */
#define PIN_PG11                    (203  )  /**< Pin Number for PG11 */
#define PIN_PG12                    (204  )  /**< Pin Number for PG12 */
#define PIN_PG13                    (205  )  /**< Pin Number for PG13 */
#define PIN_PG14                    (206  )  /**< Pin Number for PG14 */
#define PIN_PG15                    (207  )  /**< Pin Number for PG15 */
#define PIN_PG16                    (208  )  /**< Pin Number for PG16 */
#define PIN_PG17                    (209  )  /**< Pin Number for PG17 */
#define PIN_PG18                    (210  )  /**< Pin Number for PG18 */
#define PIN_PG19                    (211  )  /**< Pin Number for PG19 */
#define PIN_PG20                    (212  )  /**< Pin Number for PG20 */
#define PIN_PG21                    (213  )  /**< Pin Number for PG21 */
#define PIN_PG22                    (214  )  /**< Pin Number for PG22 */
#define PIN_PG23                    (215  )  /**< Pin Number for PG23 */
#define PIN_PG24                    (216  )  /**< Pin Number for PG24 */
#define PIN_PG25                    (217  )  /**< Pin Number for PG25 */
#define PIN_PG26                    (218  )  /**< Pin Number for PG26 */
#define PIN_PG27                    (219  )  /**< Pin Number for PG27 */
#define PIN_PG30                    (222  )  /**< Pin Number for PG30 */
#define PIN_PG31                    (223  )  /**< Pin Number for PG31 */

/* ========== Peripheral I/O masks ========== */
#define PIO_PA0                     (_U_(1) << 0)   /**< PIO mask for PA0 */
#define PIO_PA1                     (_U_(1) << 1)   /**< PIO mask for PA1 */
#define PIO_PA2                     (_U_(1) << 2)   /**< PIO mask for PA2 */
#define PIO_PA3                     (_U_(1) << 3)   /**< PIO mask for PA3 */
#define PIO_PA4                     (_U_(1) << 4)   /**< PIO mask for PA4 */
#define PIO_PA5                     (_U_(1) << 5)   /**< PIO mask for PA5 */
#define PIO_PA6                     (_U_(1) << 6)   /**< PIO mask for PA6 */
#define PIO_PA7                     (_U_(1) << 7)   /**< PIO mask for PA7 */
#define PIO_PA8                     (_U_(1) << 8)   /**< PIO mask for PA8 */
#define PIO_PA9                     (_U_(1) << 9)   /**< PIO mask for PA9 */
#define PIO_PA10                    (_U_(1) << 10)  /**< PIO mask for PA10 */
#define PIO_PA11                    (_U_(1) << 11)  /**< PIO mask for PA11 */
#define PIO_PA12                    (_U_(1) << 12)  /**< PIO mask for PA12 */
#define PIO_PA13                    (_U_(1) << 13)  /**< PIO mask for PA13 */
#define PIO_PA16                    (_U_(1) << 16)  /**< PIO mask for PA16 */
#define PIO_PA17                    (_U_(1) << 17)  /**< PIO mask for PA17 */
#define PIO_PA19                    (_U_(1) << 19)  /**< PIO mask for PA19 */
#define PIO_PA20                    (_U_(1) << 20)  /**< PIO mask for PA20 */
#define PIO_PA21                    (_U_(1) << 21)  /**< PIO mask for PA21 */
#define PIO_PA22                    (_U_(1) << 22)  /**< PIO mask for PA22 */
#define PIO_PA23                    (_U_(1) << 23)  /**< PIO mask for PA23 */
#define PIO_PA24                    (_U_(1) << 24)  /**< PIO mask for PA24 */
#define PIO_PA25                    (_U_(1) << 25)  /**< PIO mask for PA25 */
#define PIO_PA26                    (_U_(1) << 26)  /**< PIO mask for PA26 */
#define PIO_PA27                    (_U_(1) << 27)  /**< PIO mask for PA27 */
#define PIO_PA28                    (_U_(1) << 28)  /**< PIO mask for PA28 */
#define PIO_PB0                     (_U_(1) << 0)   /**< PIO mask for PB0 */
#define PIO_PB1                     (_U_(1) << 1)   /**< PIO mask for PB1 */
#define PIO_PB2                     (_U_(1) << 2)   /**< PIO mask for PB2 */
#define PIO_PB3                     (_U_(1) << 3)   /**< PIO mask for PB3 */
#define PIO_PB4                     (_U_(1) << 4)   /**< PIO mask for PB4 */
#define PIO_PB5                     (_U_(1) << 5)   /**< PIO mask for PB5 */
#define PIO_PB6                     (_U_(1) << 6)   /**< PIO mask for PB6 */
#define PIO_PB7                     (_U_(1) << 7)   /**< PIO mask for PB7 */
#define PIO_PB8                     (_U_(1) << 8)   /**< PIO mask for PB8 */
#define PIO_PB9                     (_U_(1) << 9)   /**< PIO mask for PB9 */
#define PIO_PB10                    (_U_(1) << 10)  /**< PIO mask for PB10 */
#define PIO_PB11                    (_U_(1) << 11)  /**< PIO mask for PB11 */
#define PIO_PB12                    (_U_(1) << 12)  /**< PIO mask for PB12 */
#define PIO_PB13                    (_U_(1) << 13)  /**< PIO mask for PB13 */
#define PIO_PB14                    (_U_(1) << 14)  /**< PIO mask for PB14 */
#define PIO_PB15                    (_U_(1) << 15)  /**< PIO mask for PB15 */
#define PIO_PB16                    (_U_(1) << 16)  /**< PIO mask for PB16 */
#define PIO_PB17                    (_U_(1) << 17)  /**< PIO mask for PB17 */
#define PIO_PB18                    (_U_(1) << 18)  /**< PIO mask for PB18 */
#define PIO_PB19                    (_U_(1) << 19)  /**< PIO mask for PB19 */
#define PIO_PB20                    (_U_(1) << 20)  /**< PIO mask for PB20 */
#define PIO_PB21                    (_U_(1) << 21)  /**< PIO mask for PB21 */
#define PIO_PB22                    (_U_(1) << 22)  /**< PIO mask for PB22 */
#define PIO_PB23                    (_U_(1) << 23)  /**< PIO mask for PB23 */
#define PIO_PB24                    (_U_(1) << 24)  /**< PIO mask for PB24 */
#define PIO_PB25                    (_U_(1) << 25)  /**< PIO mask for PB25 */
#define PIO_PB26                    (_U_(1) << 26)  /**< PIO mask for PB26 */
#define PIO_PB27                    (_U_(1) << 27)  /**< PIO mask for PB27 */
#define PIO_PB28                    (_U_(1) << 28)  /**< PIO mask for PB28 */
#define PIO_PB29                    (_U_(1) << 29)  /**< PIO mask for PB29 */
#define PIO_PC0                     (_U_(1) << 0)   /**< PIO mask for PC0 */
#define PIO_PC1                     (_U_(1) << 1)   /**< PIO mask for PC1 */
#define PIO_PC2                     (_U_(1) << 2)   /**< PIO mask for PC2 */
#define PIO_PC3                     (_U_(1) << 3)   /**< PIO mask for PC3 */
#define PIO_PC4                     (_U_(1) << 4)   /**< PIO mask for PC4 */
#define PIO_PC5                     (_U_(1) << 5)   /**< PIO mask for PC5 */
#define PIO_PC6                     (_U_(1) << 6)   /**< PIO mask for PC6 */
#define PIO_PC7                     (_U_(1) << 7)   /**< PIO mask for PC7 */
#define PIO_PC8                     (_U_(1) << 8)   /**< PIO mask for PC8 */
#define PIO_PC9                     (_U_(1) << 9)   /**< PIO mask for PC9 */
#define PIO_PC10                    (_U_(1) << 10)  /**< PIO mask for PC10 */
#define PIO_PC11                    (_U_(1) << 11)  /**< PIO mask for PC11 */
#define PIO_PC12                    (_U_(1) << 12)  /**< PIO mask for PC12 */
#define PIO_PC13                    (_U_(1) << 13)  /**< PIO mask for PC13 */
#define PIO_PC14                    (_U_(1) << 14)  /**< PIO mask for PC14 */
#define PIO_PC15                    (_U_(1) << 15)  /**< PIO mask for PC15 */
#define PIO_PC16                    (_U_(1) << 16)  /**< PIO mask for PC16 */
#define PIO_PC17                    (_U_(1) << 17)  /**< PIO mask for PC17 */
#define PIO_PC18                    (_U_(1) << 18)  /**< PIO mask for PC18 */
#define PIO_PC19                    (_U_(1) << 19)  /**< PIO mask for PC19 */
#define PIO_PC20                    (_U_(1) << 20)  /**< PIO mask for PC20 */
#define PIO_PC21                    (_U_(1) << 21)  /**< PIO mask for PC21 */
#define PIO_PC22                    (_U_(1) << 22)  /**< PIO mask for PC22 */
#define PIO_PC23                    (_U_(1) << 23)  /**< PIO mask for PC23 */
#define PIO_PC24                    (_U_(1) << 24)  /**< PIO mask for PC24 */
#define PIO_PC25                    (_U_(1) << 25)  /**< PIO mask for PC25 */
#define PIO_PC26                    (_U_(1) << 26)  /**< PIO mask for PC26 */
#define PIO_PC27                    (_U_(1) << 27)  /**< PIO mask for PC27 */
#define PIO_PC28                    (_U_(1) << 28)  /**< PIO mask for PC28 */
#define PIO_PC29                    (_U_(1) << 29)  /**< PIO mask for PC29 */
#define PIO_PC30                    (_U_(1) << 30)  /**< PIO mask for PC30 */
#define PIO_PC31                    (_U_(1) << 31)  /**< PIO mask for PC31 */
#define PIO_PD0                     (_U_(1) << 0)   /**< PIO mask for PD0 */
#define PIO_PD1                     (_U_(1) << 1)   /**< PIO mask for PD1 */
#define PIO_PD2                     (_U_(1) << 2)   /**< PIO mask for PD2 */
#define PIO_PD3                     (_U_(1) << 3)   /**< PIO mask for PD3 */
#define PIO_PD4                     (_U_(1) << 4)   /**< PIO mask for PD4 */
#define PIO_PD5                     (_U_(1) << 5)   /**< PIO mask for PD5 */
#define PIO_PD6                     (_U_(1) << 6)   /**< PIO mask for PD6 */
#define PIO_PD7                     (_U_(1) << 7)   /**< PIO mask for PD7 */
#define PIO_PD8                     (_U_(1) << 8)   /**< PIO mask for PD8 */
#define PIO_PD9                     (_U_(1) << 9)   /**< PIO mask for PD9 */
#define PIO_PD10                    (_U_(1) << 10)  /**< PIO mask for PD10 */
#define PIO_PD11                    (_U_(1) << 11)  /**< PIO mask for PD11 */
#define PIO_PD12                    (_U_(1) << 12)  /**< PIO mask for PD12 */
#define PIO_PD13                    (_U_(1) << 13)  /**< PIO mask for PD13 */
#define PIO_PD14                    (_U_(1) << 14)  /**< PIO mask for PD14 */
#define PIO_PD15                    (_U_(1) << 15)  /**< PIO mask for PD15 */
#define PIO_PD16                    (_U_(1) << 16)  /**< PIO mask for PD16 */
#define PIO_PD17                    (_U_(1) << 17)  /**< PIO mask for PD17 */
#define PIO_PD18                    (_U_(1) << 18)  /**< PIO mask for PD18 */
#define PIO_PD19                    (_U_(1) << 19)  /**< PIO mask for PD19 */
#define PIO_PD20                    (_U_(1) << 20)  /**< PIO mask for PD20 */
#define PIO_PD21                    (_U_(1) << 21)  /**< PIO mask for PD21 */
#define PIO_PD22                    (_U_(1) << 22)  /**< PIO mask for PD22 */
#define PIO_PD23                    (_U_(1) << 23)  /**< PIO mask for PD23 */
#define PIO_PD24                    (_U_(1) << 24)  /**< PIO mask for PD24 */
#define PIO_PD25                    (_U_(1) << 25)  /**< PIO mask for PD25 */
#define PIO_PD26                    (_U_(1) << 26)  /**< PIO mask for PD26 */
#define PIO_PD27                    (_U_(1) << 27)  /**< PIO mask for PD27 */
#define PIO_PD28                    (_U_(1) << 28)  /**< PIO mask for PD28 */
#define PIO_PD29                    (_U_(1) << 29)  /**< PIO mask for PD29 */
#define PIO_PD30                    (_U_(1) << 30)  /**< PIO mask for PD30 */
#define PIO_PD31                    (_U_(1) << 31)  /**< PIO mask for PD31 */
#define PIO_PE0                     (_U_(1) << 0)   /**< PIO mask for PE0 */
#define PIO_PE1                     (_U_(1) << 1)   /**< PIO mask for PE1 */
#define PIO_PE2                     (_U_(1) << 2)   /**< PIO mask for PE2 */
#define PIO_PE3                     (_U_(1) << 3)   /**< PIO mask for PE3 */
#define PIO_PE4                     (_U_(1) << 4)   /**< PIO mask for PE4 */
#define PIO_PE5                     (_U_(1) << 5)   /**< PIO mask for PE5 */
#define PIO_PE6                     (_U_(1) << 6)   /**< PIO mask for PE6 */
#define PIO_PE7                     (_U_(1) << 7)   /**< PIO mask for PE7 */
#define PIO_PE8                     (_U_(1) << 8)   /**< PIO mask for PE8 */
#define PIO_PE9                     (_U_(1) << 9)   /**< PIO mask for PE9 */
#define PIO_PE10                    (_U_(1) << 10)  /**< PIO mask for PE10 */
#define PIO_PE11                    (_U_(1) << 11)  /**< PIO mask for PE11 */
#define PIO_PE12                    (_U_(1) << 12)  /**< PIO mask for PE12 */
#define PIO_PF0                     (_U_(1) << 0)   /**< PIO mask for PF0 */
#define PIO_PF1                     (_U_(1) << 1)   /**< PIO mask for PF1 */
#define PIO_PF2                     (_U_(1) << 2)   /**< PIO mask for PF2 */
#define PIO_PF3                     (_U_(1) << 3)   /**< PIO mask for PF3 */
#define PIO_PF4                     (_U_(1) << 4)   /**< PIO mask for PF4 */
#define PIO_PF5                     (_U_(1) << 5)   /**< PIO mask for PF5 */
#define PIO_PF6                     (_U_(1) << 6)   /**< PIO mask for PF6 */
#define PIO_PF7                     (_U_(1) << 7)   /**< PIO mask for PF7 */
#define PIO_PF8                     (_U_(1) << 8)   /**< PIO mask for PF8 */
#define PIO_PF9                     (_U_(1) << 9)   /**< PIO mask for PF9 */
#define PIO_PF10                    (_U_(1) << 10)  /**< PIO mask for PF10 */
#define PIO_PF11                    (_U_(1) << 11)  /**< PIO mask for PF11 */
#define PIO_PF12                    (_U_(1) << 12)  /**< PIO mask for PF12 */
#define PIO_PF13                    (_U_(1) << 13)  /**< PIO mask for PF13 */
#define PIO_PF14                    (_U_(1) << 14)  /**< PIO mask for PF14 */
#define PIO_PF15                    (_U_(1) << 15)  /**< PIO mask for PF15 */
#define PIO_PF16                    (_U_(1) << 16)  /**< PIO mask for PF16 */
#define PIO_PF17                    (_U_(1) << 17)  /**< PIO mask for PF17 */
#define PIO_PF18                    (_U_(1) << 18)  /**< PIO mask for PF18 */
#define PIO_PF19                    (_U_(1) << 19)  /**< PIO mask for PF19 */
#define PIO_PF20                    (_U_(1) << 20)  /**< PIO mask for PF20 */
#define PIO_PF21                    (_U_(1) << 21)  /**< PIO mask for PF21 */
#define PIO_PF22                    (_U_(1) << 22)  /**< PIO mask for PF22 */
#define PIO_PF23                    (_U_(1) << 23)  /**< PIO mask for PF23 */
#define PIO_PF24                    (_U_(1) << 24)  /**< PIO mask for PF24 */
#define PIO_PF25                    (_U_(1) << 25)  /**< PIO mask for PF25 */
#define PIO_PF26                    (_U_(1) << 26)  /**< PIO mask for PF26 */
#define PIO_PF27                    (_U_(1) << 27)  /**< PIO mask for PF27 */
#define PIO_PF28                    (_U_(1) << 28)  /**< PIO mask for PF28 */
#define PIO_PF29                    (_U_(1) << 29)  /**< PIO mask for PF29 */
#define PIO_PF30                    (_U_(1) << 30)  /**< PIO mask for PF30 */
#define PIO_PG0                     (_U_(1) << 0)   /**< PIO mask for PG0 */
#define PIO_PG1                     (_U_(1) << 1)   /**< PIO mask for PG1 */
#define PIO_PG2                     (_U_(1) << 2)   /**< PIO mask for PG2 */
#define PIO_PG3                     (_U_(1) << 3)   /**< PIO mask for PG3 */
#define PIO_PG4                     (_U_(1) << 4)   /**< PIO mask for PG4 */
#define PIO_PG5                     (_U_(1) << 5)   /**< PIO mask for PG5 */
#define PIO_PG6                     (_U_(1) << 6)   /**< PIO mask for PG6 */
#define PIO_PG7                     (_U_(1) << 7)   /**< PIO mask for PG7 */
#define PIO_PG8                     (_U_(1) << 8)   /**< PIO mask for PG8 */
#define PIO_PG9                     (_U_(1) << 9)   /**< PIO mask for PG9 */
#define PIO_PG10                    (_U_(1) << 10)  /**< PIO mask for PG10 */
#define PIO_PG11                    (_U_(1) << 11)  /**< PIO mask for PG11 */
#define PIO_PG12                    (_U_(1) << 12)  /**< PIO mask for PG12 */
#define PIO_PG13                    (_U_(1) << 13)  /**< PIO mask for PG13 */
#define PIO_PG14                    (_U_(1) << 14)  /**< PIO mask for PG14 */
#define PIO_PG15                    (_U_(1) << 15)  /**< PIO mask for PG15 */
#define PIO_PG16                    (_U_(1) << 16)  /**< PIO mask for PG16 */
#define PIO_PG17                    (_U_(1) << 17)  /**< PIO mask for PG17 */
#define PIO_PG18                    (_U_(1) << 18)  /**< PIO mask for PG18 */
#define PIO_PG19                    (_U_(1) << 19)  /**< PIO mask for PG19 */
#define PIO_PG20                    (_U_(1) << 20)  /**< PIO mask for PG20 */
#define PIO_PG21                    (_U_(1) << 21)  /**< PIO mask for PG21 */
#define PIO_PG22                    (_U_(1) << 22)  /**< PIO mask for PG22 */
#define PIO_PG23                    (_U_(1) << 23)  /**< PIO mask for PG23 */
#define PIO_PG24                    (_U_(1) << 24)  /**< PIO mask for PG24 */
#define PIO_PG25                    (_U_(1) << 25)  /**< PIO mask for PG25 */
#define PIO_PG26                    (_U_(1) << 26)  /**< PIO mask for PG26 */
#define PIO_PG27                    (_U_(1) << 27)  /**< PIO mask for PG27 */
#define PIO_PG30                    (_U_(1) << 30)  /**< PIO mask for PG30 */
#define PIO_PG31                    (_U_(1) << 31)  /**< PIO mask for PG31 */

/* ========== PIO definition for FLEXCOM0 peripheral ========== */
#define PIN_PC21A_FLEXCOM0_IO0                     _L_(85)      /**< FLEXCOM0 signal: FLEXCOM0_IO0 on PC21 mux A */
#define MUX_PC21A_FLEXCOM0_IO0                     _L_(0)       /**< FLEXCOM0 signal line function value: FLEXCOM0_IO0 */
#define PIO_PC21A_FLEXCOM0_IO0                     (_U_(1) << 21) /**< FLEXCOM0 signal: FLEXCOM0_IO0 */
#define PIN_PC22A_FLEXCOM0_IO1                     _L_(86)      /**< FLEXCOM0 signal: FLEXCOM0_IO1 on PC22 mux A */
#define MUX_PC22A_FLEXCOM0_IO1                     _L_(0)       /**< FLEXCOM0 signal line function value: FLEXCOM0_IO1 */
#define PIO_PC22A_FLEXCOM0_IO1                     (_U_(1) << 22) /**< FLEXCOM0 signal: FLEXCOM0_IO1 */
#define PIN_PC23A_FLEXCOM0_IO2                     _L_(87)      /**< FLEXCOM0 signal: FLEXCOM0_IO2 on PC23 mux A */
#define MUX_PC23A_FLEXCOM0_IO2                     _L_(0)       /**< FLEXCOM0 signal line function value: FLEXCOM0_IO2 */
#define PIO_PC23A_FLEXCOM0_IO2                     (_U_(1) << 23) /**< FLEXCOM0 signal: FLEXCOM0_IO2 */
#define PIN_PC24A_FLEXCOM0_IO3                     _L_(88)      /**< FLEXCOM0 signal: FLEXCOM0_IO3 on PC24 mux A */
#define MUX_PC24A_FLEXCOM0_IO3                     _L_(0)       /**< FLEXCOM0 signal line function value: FLEXCOM0_IO3 */
#define PIO_PC24A_FLEXCOM0_IO3                     (_U_(1) << 24) /**< FLEXCOM0 signal: FLEXCOM0_IO3 */
#define PIN_PC25A_FLEXCOM0_IO4                     _L_(89)      /**< FLEXCOM0 signal: FLEXCOM0_IO4 on PC25 mux A */
#define MUX_PC25A_FLEXCOM0_IO4                     _L_(0)       /**< FLEXCOM0 signal line function value: FLEXCOM0_IO4 */
#define PIO_PC25A_FLEXCOM0_IO4                     (_U_(1) << 25) /**< FLEXCOM0 signal: FLEXCOM0_IO4 */
#define PIN_PC26A_FLEXCOM0_IO5                     _L_(90)      /**< FLEXCOM0 signal: FLEXCOM0_IO5 on PC26 mux A */
#define MUX_PC26A_FLEXCOM0_IO5                     _L_(0)       /**< FLEXCOM0 signal line function value: FLEXCOM0_IO5 */
#define PIO_PC26A_FLEXCOM0_IO5                     (_U_(1) << 26) /**< FLEXCOM0 signal: FLEXCOM0_IO5 */
#define PIN_PC27A_FLEXCOM0_IO6                     _L_(91)      /**< FLEXCOM0 signal: FLEXCOM0_IO6 on PC27 mux A */
#define MUX_PC27A_FLEXCOM0_IO6                     _L_(0)       /**< FLEXCOM0 signal line function value: FLEXCOM0_IO6 */
#define PIO_PC27A_FLEXCOM0_IO6                     (_U_(1) << 27) /**< FLEXCOM0 signal: FLEXCOM0_IO6 */
#define PIN_PC28A_FLEXCOM0_IO7                     _L_(92)      /**< FLEXCOM0 signal: FLEXCOM0_IO7 on PC28 mux A */
#define MUX_PC28A_FLEXCOM0_IO7                     _L_(0)       /**< FLEXCOM0 signal line function value: FLEXCOM0_IO7 */
#define PIO_PC28A_FLEXCOM0_IO7                     (_U_(1) << 28) /**< FLEXCOM0 signal: FLEXCOM0_IO7 */
/* ========== PIO definition for FLEXCOM1 peripheral ========== */
#define PIN_PF30A_FLEXCOM1_IO0                     _L_(190)     /**< FLEXCOM1 signal: FLEXCOM1_IO0 on PF30 mux A */
#define MUX_PF30A_FLEXCOM1_IO0                     _L_(0)       /**< FLEXCOM1 signal line function value: FLEXCOM1_IO0 */
#define PIO_PF30A_FLEXCOM1_IO0                     (_U_(1) << 30) /**< FLEXCOM1 signal: FLEXCOM1_IO0 */
#define PIN_PF29A_FLEXCOM1_IO1                     _L_(189)     /**< FLEXCOM1 signal: FLEXCOM1_IO1 on PF29 mux A */
#define MUX_PF29A_FLEXCOM1_IO1                     _L_(0)       /**< FLEXCOM1 signal line function value: FLEXCOM1_IO1 */
#define PIO_PF29A_FLEXCOM1_IO1                     (_U_(1) << 29) /**< FLEXCOM1 signal: FLEXCOM1_IO1 */
#define PIN_PF28A_FLEXCOM1_IO2                     _L_(188)     /**< FLEXCOM1 signal: FLEXCOM1_IO2 on PF28 mux A */
#define MUX_PF28A_FLEXCOM1_IO2                     _L_(0)       /**< FLEXCOM1 signal line function value: FLEXCOM1_IO2 */
#define PIO_PF28A_FLEXCOM1_IO2                     (_U_(1) << 28) /**< FLEXCOM1 signal: FLEXCOM1_IO2 */
#define PIN_PF27A_FLEXCOM1_IO3                     _L_(187)     /**< FLEXCOM1 signal: FLEXCOM1_IO3 on PF27 mux A */
#define MUX_PF27A_FLEXCOM1_IO3                     _L_(0)       /**< FLEXCOM1 signal line function value: FLEXCOM1_IO3 */
#define PIO_PF27A_FLEXCOM1_IO3                     (_U_(1) << 27) /**< FLEXCOM1 signal: FLEXCOM1_IO3 */
#define PIN_PF26A_FLEXCOM1_IO4                     _L_(186)     /**< FLEXCOM1 signal: FLEXCOM1_IO4 on PF26 mux A */
#define MUX_PF26A_FLEXCOM1_IO4                     _L_(0)       /**< FLEXCOM1 signal line function value: FLEXCOM1_IO4 */
#define PIO_PF26A_FLEXCOM1_IO4                     (_U_(1) << 26) /**< FLEXCOM1 signal: FLEXCOM1_IO4 */
/* ========== PIO definition for FLEXCOM2 peripheral ========== */
#define PIN_PA2A_FLEXCOM2_IO0                      _L_(2)       /**< FLEXCOM2 signal: FLEXCOM2_IO0 on PA2 mux A */
#define MUX_PA2A_FLEXCOM2_IO0                      _L_(0)       /**< FLEXCOM2 signal line function value: FLEXCOM2_IO0 */
#define PIO_PA2A_FLEXCOM2_IO0                      (_U_(1) << 2) /**< FLEXCOM2 signal: FLEXCOM2_IO0 */
#define PIN_PA6A_FLEXCOM2_IO1                      _L_(6)       /**< FLEXCOM2 signal: FLEXCOM2_IO1 on PA6 mux A */
#define MUX_PA6A_FLEXCOM2_IO1                      _L_(0)       /**< FLEXCOM2 signal line function value: FLEXCOM2_IO1 */
#define PIO_PA6A_FLEXCOM2_IO1                      (_U_(1) << 6) /**< FLEXCOM2 signal: FLEXCOM2_IO1 */
#define PIN_PA8A_FLEXCOM2_IO2                      _L_(8)       /**< FLEXCOM2 signal: FLEXCOM2_IO2 on PA8 mux A */
#define MUX_PA8A_FLEXCOM2_IO2                      _L_(0)       /**< FLEXCOM2 signal line function value: FLEXCOM2_IO2 */
#define PIO_PA8A_FLEXCOM2_IO2                      (_U_(1) << 8) /**< FLEXCOM2 signal: FLEXCOM2_IO2 */
#define PIN_PA7A_FLEXCOM2_IO3                      _L_(7)       /**< FLEXCOM2 signal: FLEXCOM2_IO3 on PA7 mux A */
#define MUX_PA7A_FLEXCOM2_IO3                      _L_(0)       /**< FLEXCOM2 signal line function value: FLEXCOM2_IO3 */
#define PIO_PA7A_FLEXCOM2_IO3                      (_U_(1) << 7) /**< FLEXCOM2 signal: FLEXCOM2_IO3 */
#define PIN_PA3A_FLEXCOM2_IO4                      _L_(3)       /**< FLEXCOM2 signal: FLEXCOM2_IO4 on PA3 mux A */
#define MUX_PA3A_FLEXCOM2_IO4                      _L_(0)       /**< FLEXCOM2 signal line function value: FLEXCOM2_IO4 */
#define PIO_PA3A_FLEXCOM2_IO4                      (_U_(1) << 3) /**< FLEXCOM2 signal: FLEXCOM2_IO4 */
/* ========== PIO definition for FLEXCOM3 peripheral ========== */
#define PIN_PA20A_FLEXCOM3_IO0                     _L_(20)      /**< FLEXCOM3 signal: FLEXCOM3_IO0 on PA20 mux A */
#define MUX_PA20A_FLEXCOM3_IO0                     _L_(0)       /**< FLEXCOM3 signal line function value: FLEXCOM3_IO0 */
#define PIO_PA20A_FLEXCOM3_IO0                     (_U_(1) << 20) /**< FLEXCOM3 signal: FLEXCOM3_IO0 */
#define PIN_PA19A_FLEXCOM3_IO1                     _L_(19)      /**< FLEXCOM3 signal: FLEXCOM3_IO1 on PA19 mux A */
#define MUX_PA19A_FLEXCOM3_IO1                     _L_(0)       /**< FLEXCOM3 signal line function value: FLEXCOM3_IO1 */
#define PIO_PA19A_FLEXCOM3_IO1                     (_U_(1) << 19) /**< FLEXCOM3 signal: FLEXCOM3_IO1 */
#define PIN_PA23A_FLEXCOM3_IO2                     _L_(23)      /**< FLEXCOM3 signal: FLEXCOM3_IO2 on PA23 mux A */
#define MUX_PA23A_FLEXCOM3_IO2                     _L_(0)       /**< FLEXCOM3 signal line function value: FLEXCOM3_IO2 */
#define PIO_PA23A_FLEXCOM3_IO2                     (_U_(1) << 23) /**< FLEXCOM3 signal: FLEXCOM3_IO2 */
#define PIN_PA24A_FLEXCOM3_IO3                     _L_(24)      /**< FLEXCOM3 signal: FLEXCOM3_IO3 on PA24 mux A */
#define MUX_PA24A_FLEXCOM3_IO3                     _L_(0)       /**< FLEXCOM3 signal line function value: FLEXCOM3_IO3 */
#define PIO_PA24A_FLEXCOM3_IO3                     (_U_(1) << 24) /**< FLEXCOM3 signal: FLEXCOM3_IO3 */
#define PIN_PA21A_FLEXCOM3_IO4                     _L_(21)      /**< FLEXCOM3 signal: FLEXCOM3_IO4 on PA21 mux A */
#define MUX_PA21A_FLEXCOM3_IO4                     _L_(0)       /**< FLEXCOM3 signal line function value: FLEXCOM3_IO4 */
#define PIO_PA21A_FLEXCOM3_IO4                     (_U_(1) << 21) /**< FLEXCOM3 signal: FLEXCOM3_IO4 */
#define PIN_PA22A_FLEXCOM3_IO5                     _L_(22)      /**< FLEXCOM3 signal: FLEXCOM3_IO5 on PA22 mux A */
#define MUX_PA22A_FLEXCOM3_IO5                     _L_(0)       /**< FLEXCOM3 signal line function value: FLEXCOM3_IO5 */
#define PIO_PA22A_FLEXCOM3_IO5                     (_U_(1) << 22) /**< FLEXCOM3 signal: FLEXCOM3_IO5 */
#define PIN_PA12A_FLEXCOM3_IO6                     _L_(12)      /**< FLEXCOM3 signal: FLEXCOM3_IO6 on PA12 mux A */
#define MUX_PA12A_FLEXCOM3_IO6                     _L_(0)       /**< FLEXCOM3 signal line function value: FLEXCOM3_IO6 */
#define PIO_PA12A_FLEXCOM3_IO6                     (_U_(1) << 12) /**< FLEXCOM3 signal: FLEXCOM3_IO6 */
/* ========== PIO definition for FLEXCOM4 peripheral ========== */
#define PIN_PC0A_FLEXCOM4_IO0                      _L_(64)      /**< FLEXCOM4 signal: FLEXCOM4_IO0 on PC0 mux A */
#define MUX_PC0A_FLEXCOM4_IO0                      _L_(0)       /**< FLEXCOM4 signal line function value: FLEXCOM4_IO0 */
#define PIO_PC0A_FLEXCOM4_IO0                      (_U_(1) << 0) /**< FLEXCOM4 signal: FLEXCOM4_IO0 */
#define PIN_PC1A_FLEXCOM4_IO1                      _L_(65)      /**< FLEXCOM4 signal: FLEXCOM4_IO1 on PC1 mux A */
#define MUX_PC1A_FLEXCOM4_IO1                      _L_(0)       /**< FLEXCOM4 signal line function value: FLEXCOM4_IO1 */
#define PIO_PC1A_FLEXCOM4_IO1                      (_U_(1) << 1) /**< FLEXCOM4 signal: FLEXCOM4_IO1 */
#define PIN_PC2A_FLEXCOM4_IO2                      _L_(66)      /**< FLEXCOM4 signal: FLEXCOM4_IO2 on PC2 mux A */
#define MUX_PC2A_FLEXCOM4_IO2                      _L_(0)       /**< FLEXCOM4 signal line function value: FLEXCOM4_IO2 */
#define PIO_PC2A_FLEXCOM4_IO2                      (_U_(1) << 2) /**< FLEXCOM4 signal: FLEXCOM4_IO2 */
#define PIN_PC3A_FLEXCOM4_IO3                      _L_(67)      /**< FLEXCOM4 signal: FLEXCOM4_IO3 on PC3 mux A */
#define MUX_PC3A_FLEXCOM4_IO3                      _L_(0)       /**< FLEXCOM4 signal line function value: FLEXCOM4_IO3 */
#define PIO_PC3A_FLEXCOM4_IO3                      (_U_(1) << 3) /**< FLEXCOM4 signal: FLEXCOM4_IO3 */
#define PIN_PC4A_FLEXCOM4_IO4                      _L_(68)      /**< FLEXCOM4 signal: FLEXCOM4_IO4 on PC4 mux A */
#define MUX_PC4A_FLEXCOM4_IO4                      _L_(0)       /**< FLEXCOM4 signal line function value: FLEXCOM4_IO4 */
#define PIO_PC4A_FLEXCOM4_IO4                      (_U_(1) << 4) /**< FLEXCOM4 signal: FLEXCOM4_IO4 */
#define PIN_PC5A_FLEXCOM4_IO5                      _L_(69)      /**< FLEXCOM4 signal: FLEXCOM4_IO5 on PC5 mux A */
#define MUX_PC5A_FLEXCOM4_IO5                      _L_(0)       /**< FLEXCOM4 signal line function value: FLEXCOM4_IO5 */
#define PIO_PC5A_FLEXCOM4_IO5                      (_U_(1) << 5) /**< FLEXCOM4 signal: FLEXCOM4_IO5 */
#define PIN_PC6A_FLEXCOM4_IO6                      _L_(70)      /**< FLEXCOM4 signal: FLEXCOM4_IO6 on PC6 mux A */
#define MUX_PC6A_FLEXCOM4_IO6                      _L_(0)       /**< FLEXCOM4 signal line function value: FLEXCOM4_IO6 */
#define PIO_PC6A_FLEXCOM4_IO6                      (_U_(1) << 6) /**< FLEXCOM4 signal: FLEXCOM4_IO6 */
/* ========== PIO definition for FLEXCOM5 peripheral ========== */
#define PIN_PC9A_FLEXCOM5_IO0                      _L_(73)      /**< FLEXCOM5 signal: FLEXCOM5_IO0 on PC9 mux A */
#define MUX_PC9A_FLEXCOM5_IO0                      _L_(0)       /**< FLEXCOM5 signal line function value: FLEXCOM5_IO0 */
#define PIO_PC9A_FLEXCOM5_IO0                      (_U_(1) << 9) /**< FLEXCOM5 signal: FLEXCOM5_IO0 */
#define PIN_PC10A_FLEXCOM5_IO1                     _L_(74)      /**< FLEXCOM5 signal: FLEXCOM5_IO1 on PC10 mux A */
#define MUX_PC10A_FLEXCOM5_IO1                     _L_(0)       /**< FLEXCOM5 signal line function value: FLEXCOM5_IO1 */
#define PIO_PC10A_FLEXCOM5_IO1                     (_U_(1) << 10) /**< FLEXCOM5 signal: FLEXCOM5_IO1 */
#define PIN_PA9A_FLEXCOM5_IO2                      _L_(9)       /**< FLEXCOM5 signal: FLEXCOM5_IO2 on PA9 mux A */
#define MUX_PA9A_FLEXCOM5_IO2                      _L_(0)       /**< FLEXCOM5 signal line function value: FLEXCOM5_IO2 */
#define PIO_PA9A_FLEXCOM5_IO2                      (_U_(1) << 9) /**< FLEXCOM5 signal: FLEXCOM5_IO2 */
#define PIN_PA10A_FLEXCOM5_IO3                     _L_(10)      /**< FLEXCOM5 signal: FLEXCOM5_IO3 on PA10 mux A */
#define MUX_PA10A_FLEXCOM5_IO3                     _L_(0)       /**< FLEXCOM5 signal line function value: FLEXCOM5_IO3 */
#define PIO_PA10A_FLEXCOM5_IO3                     (_U_(1) << 10) /**< FLEXCOM5 signal: FLEXCOM5_IO3 */
#define PIN_PA11A_FLEXCOM5_IO4                     _L_(11)      /**< FLEXCOM5 signal: FLEXCOM5_IO4 on PA11 mux A */
#define MUX_PA11A_FLEXCOM5_IO4                     _L_(0)       /**< FLEXCOM5 signal line function value: FLEXCOM5_IO4 */
#define PIO_PA11A_FLEXCOM5_IO4                     (_U_(1) << 11) /**< FLEXCOM5 signal: FLEXCOM5_IO4 */
/* ========== PIO definition for FLEXCOM6 peripheral ========== */
#define PIN_PB6A_FLEXCOM6_IO0                      _L_(38)      /**< FLEXCOM6 signal: FLEXCOM6_IO0 on PB6 mux A */
#define MUX_PB6A_FLEXCOM6_IO0                      _L_(0)       /**< FLEXCOM6 signal line function value: FLEXCOM6_IO0 */
#define PIO_PB6A_FLEXCOM6_IO0                      (_U_(1) << 6) /**< FLEXCOM6 signal: FLEXCOM6_IO0 */
#define PIN_PB7A_FLEXCOM6_IO1                      _L_(39)      /**< FLEXCOM6 signal: FLEXCOM6_IO1 on PB7 mux A */
#define MUX_PB7A_FLEXCOM6_IO1                      _L_(0)       /**< FLEXCOM6 signal line function value: FLEXCOM6_IO1 */
#define PIO_PB7A_FLEXCOM6_IO1                      (_U_(1) << 7) /**< FLEXCOM6 signal: FLEXCOM6_IO1 */
/* ========== PIO definition for FLEXCOM7 peripheral ========== */
#define PIN_PB4A_FLEXCOM7_IO0                      _L_(36)      /**< FLEXCOM7 signal: FLEXCOM7_IO0 on PB4 mux A */
#define MUX_PB4A_FLEXCOM7_IO0                      _L_(0)       /**< FLEXCOM7 signal line function value: FLEXCOM7_IO0 */
#define PIO_PB4A_FLEXCOM7_IO0                      (_U_(1) << 4) /**< FLEXCOM7 signal: FLEXCOM7_IO0 */
#define PIN_PB5A_FLEXCOM7_IO1                      _L_(37)      /**< FLEXCOM7 signal: FLEXCOM7_IO1 on PB5 mux A */
#define MUX_PB5A_FLEXCOM7_IO1                      _L_(0)       /**< FLEXCOM7 signal line function value: FLEXCOM7_IO1 */
#define PIO_PB5A_FLEXCOM7_IO1                      (_U_(1) << 5) /**< FLEXCOM7 signal: FLEXCOM7_IO1 */
/* ========== PIO definition for FLEXCOM8 peripheral ========== */
#define PIN_PA27A_FLEXCOM8_IO0                     _L_(27)      /**< FLEXCOM8 signal: FLEXCOM8_IO0 on PA27 mux A */
#define MUX_PA27A_FLEXCOM8_IO0                     _L_(0)       /**< FLEXCOM8 signal line function value: FLEXCOM8_IO0 */
#define PIO_PA27A_FLEXCOM8_IO0                     (_U_(1) << 27) /**< FLEXCOM8 signal: FLEXCOM8_IO0 */
#define PIN_PA28A_FLEXCOM8_IO1                     _L_(28)      /**< FLEXCOM8 signal: FLEXCOM8_IO1 on PA28 mux A */
#define MUX_PA28A_FLEXCOM8_IO1                     _L_(0)       /**< FLEXCOM8 signal line function value: FLEXCOM8_IO1 */
#define PIO_PA28A_FLEXCOM8_IO1                     (_U_(1) << 28) /**< FLEXCOM8 signal: FLEXCOM8_IO1 */
/* ========== PIO definition for FLEXCOM9 peripheral ========== */
#define PIN_PA25A_FLEXCOM9_IO0                     _L_(25)      /**< FLEXCOM9 signal: FLEXCOM9_IO0 on PA25 mux A */
#define MUX_PA25A_FLEXCOM9_IO0                     _L_(0)       /**< FLEXCOM9 signal line function value: FLEXCOM9_IO0 */
#define PIO_PA25A_FLEXCOM9_IO0                     (_U_(1) << 25) /**< FLEXCOM9 signal: FLEXCOM9_IO0 */
#define PIN_PA26A_FLEXCOM9_IO1                     _L_(26)      /**< FLEXCOM9 signal: FLEXCOM9_IO1 on PA26 mux A */
#define MUX_PA26A_FLEXCOM9_IO1                     _L_(0)       /**< FLEXCOM9 signal line function value: FLEXCOM9_IO1 */
#define PIO_PA26A_FLEXCOM9_IO1                     (_U_(1) << 26) /**< FLEXCOM9 signal: FLEXCOM9_IO1 */
/* ========== PIO definition for GMAC peripheral ========== */
#define PIN_PC26B_GMAC_GCOL                        _L_(90)      /**< GMAC signal: GMAC_GCOL on PC26 mux B */
#define MUX_PC26B_GMAC_GCOL                        _L_(1)       /**< GMAC signal line function value: GMAC_GCOL */
#define PIO_PC26B_GMAC_GCOL                        (_U_(1) << 26) /**< GMAC signal: GMAC_GCOL */
#define PIN_PC27B_GMAC_GCRS                        _L_(91)      /**< GMAC signal: GMAC_GCRS on PC27 mux B */
#define MUX_PC27B_GMAC_GCRS                        _L_(1)       /**< GMAC signal line function value: GMAC_GCRS */
#define PIO_PC27B_GMAC_GCRS                        (_U_(1) << 27) /**< GMAC signal: GMAC_GCRS */
#define PIN_PC20B_GMAC_GMDC                        _L_(84)      /**< GMAC signal: GMAC_GMDC on PC20 mux B */
#define MUX_PC20B_GMAC_GMDC                        _L_(1)       /**< GMAC signal line function value: GMAC_GMDC */
#define PIO_PC20B_GMAC_GMDC                        (_U_(1) << 20) /**< GMAC signal: GMAC_GMDC */
#define PIN_PC19B_GMAC_GMDIO                       _L_(83)      /**< GMAC signal: GMAC_GMDIO on PC19 mux B */
#define MUX_PC19B_GMAC_GMDIO                       _L_(1)       /**< GMAC signal line function value: GMAC_GMDIO */
#define PIO_PC19B_GMAC_GMDIO                       (_U_(1) << 19) /**< GMAC signal: GMAC_GMDIO */
#define PIN_PC12B_GMAC_GRX0                        _L_(76)      /**< GMAC signal: GMAC_GRX0 on PC12 mux B */
#define MUX_PC12B_GMAC_GRX0                        _L_(1)       /**< GMAC signal line function value: GMAC_GRX0 */
#define PIO_PC12B_GMAC_GRX0                        (_U_(1) << 12) /**< GMAC signal: GMAC_GRX0 */
#define PIN_PC11B_GMAC_GRX1                        _L_(75)      /**< GMAC signal: GMAC_GRX1 on PC11 mux B */
#define MUX_PC11B_GMAC_GRX1                        _L_(1)       /**< GMAC signal line function value: GMAC_GRX1 */
#define PIO_PC11B_GMAC_GRX1                        (_U_(1) << 11) /**< GMAC signal: GMAC_GRX1 */
#define PIN_PC30B_GMAC_GRX2                        _L_(94)      /**< GMAC signal: GMAC_GRX2 on PC30 mux B */
#define MUX_PC30B_GMAC_GRX2                        _L_(1)       /**< GMAC signal line function value: GMAC_GRX2 */
#define PIO_PC30B_GMAC_GRX2                        (_U_(1) << 30) /**< GMAC signal: GMAC_GRX2 */
#define PIN_PC29B_GMAC_GRX3                        _L_(93)      /**< GMAC signal: GMAC_GRX3 on PC29 mux B */
#define MUX_PC29B_GMAC_GRX3                        _L_(1)       /**< GMAC signal line function value: GMAC_GRX3 */
#define PIO_PC29B_GMAC_GRX3                        (_U_(1) << 29) /**< GMAC signal: GMAC_GRX3 */
#define PIN_PC28B_GMAC_GRXCK                       _L_(92)      /**< GMAC signal: GMAC_GRXCK on PC28 mux B */
#define MUX_PC28B_GMAC_GRXCK                       _L_(1)       /**< GMAC signal line function value: GMAC_GRXCK */
#define PIO_PC28B_GMAC_GRXCK                       (_U_(1) << 28) /**< GMAC signal: GMAC_GRXCK */
#define PIN_PC16B_GMAC_GRXDV                       _L_(80)      /**< GMAC signal: GMAC_GRXDV on PC16 mux B */
#define MUX_PC16B_GMAC_GRXDV                       _L_(1)       /**< GMAC signal line function value: GMAC_GRXDV */
#define PIO_PC16B_GMAC_GRXDV                       (_U_(1) << 16) /**< GMAC signal: GMAC_GRXDV */
#define PIN_PC15B_GMAC_GRXER                       _L_(79)      /**< GMAC signal: GMAC_GRXER on PC15 mux B */
#define MUX_PC15B_GMAC_GRXER                       _L_(1)       /**< GMAC signal line function value: GMAC_GRXER */
#define PIO_PC15B_GMAC_GRXER                       (_U_(1) << 15) /**< GMAC signal: GMAC_GRXER */
#define PIN_PC31B_GMAC_GTSUCOMP                    _L_(95)      /**< GMAC signal: GMAC_GTSUCOMP on PC31 mux B */
#define MUX_PC31B_GMAC_GTSUCOMP                    _L_(1)       /**< GMAC signal line function value: GMAC_GTSUCOMP */
#define PIO_PC31B_GMAC_GTSUCOMP                    (_U_(1) << 31) /**< GMAC signal: GMAC_GTSUCOMP */
#define PIN_PC14B_GMAC_GTX0                        _L_(78)      /**< GMAC signal: GMAC_GTX0 on PC14 mux B */
#define MUX_PC14B_GMAC_GTX0                        _L_(1)       /**< GMAC signal line function value: GMAC_GTX0 */
#define PIO_PC14B_GMAC_GTX0                        (_U_(1) << 14) /**< GMAC signal: GMAC_GTX0 */
#define PIN_PC13B_GMAC_GTX1                        _L_(77)      /**< GMAC signal: GMAC_GTX1 on PC13 mux B */
#define MUX_PC13B_GMAC_GTX1                        _L_(1)       /**< GMAC signal line function value: GMAC_GTX1 */
#define PIO_PC13B_GMAC_GTX1                        (_U_(1) << 13) /**< GMAC signal: GMAC_GTX1 */
#define PIN_PC24B_GMAC_GTX2                        _L_(88)      /**< GMAC signal: GMAC_GTX2 on PC24 mux B */
#define MUX_PC24B_GMAC_GTX2                        _L_(1)       /**< GMAC signal line function value: GMAC_GTX2 */
#define PIO_PC24B_GMAC_GTX2                        (_U_(1) << 24) /**< GMAC signal: GMAC_GTX2 */
#define PIN_PC25B_GMAC_GTX3                        _L_(89)      /**< GMAC signal: GMAC_GTX3 on PC25 mux B */
#define MUX_PC25B_GMAC_GTX3                        _L_(1)       /**< GMAC signal line function value: GMAC_GTX3 */
#define PIO_PC25B_GMAC_GTX3                        (_U_(1) << 25) /**< GMAC signal: GMAC_GTX3 */
#define PIN_PC18B_GMAC_GTXCK                       _L_(82)      /**< GMAC signal: GMAC_GTXCK on PC18 mux B */
#define MUX_PC18B_GMAC_GTXCK                       _L_(1)       /**< GMAC signal line function value: GMAC_GTXCK */
#define PIO_PC18B_GMAC_GTXCK                       (_U_(1) << 18) /**< GMAC signal: GMAC_GTXCK */
#define PIN_PC17B_GMAC_GTXEN                       _L_(81)      /**< GMAC signal: GMAC_GTXEN on PC17 mux B */
#define MUX_PC17B_GMAC_GTXEN                       _L_(1)       /**< GMAC signal line function value: GMAC_GTXEN */
#define PIO_PC17B_GMAC_GTXEN                       (_U_(1) << 17) /**< GMAC signal: GMAC_GTXEN */
#define PIN_PC23B_GMAC_GTXER                       _L_(87)      /**< GMAC signal: GMAC_GTXER on PC23 mux B */
#define MUX_PC23B_GMAC_GTXER                       _L_(1)       /**< GMAC signal line function value: GMAC_GTXER */
#define PIO_PC23B_GMAC_GTXER                       (_U_(1) << 23) /**< GMAC signal: GMAC_GTXER */
/* ========== PIO definition for HEMC peripheral ========== */
#define PIN_PG0A_HEMC_A0                           _L_(192)     /**< HEMC signal: HEMC_A0 on PG0 mux A */
#define MUX_PG0A_HEMC_A0                           _L_(0)       /**< HEMC signal line function value: HEMC_A0 */
#define PIO_PG0A_HEMC_A0                           (_U_(1) << 0) /**< HEMC signal: HEMC_A0 */
#define PIN_PG1A_HEMC_A1                           _L_(193)     /**< HEMC signal: HEMC_A1 on PG1 mux A */
#define MUX_PG1A_HEMC_A1                           _L_(0)       /**< HEMC signal line function value: HEMC_A1 */
#define PIO_PG1A_HEMC_A1                           (_U_(1) << 1) /**< HEMC signal: HEMC_A1 */
#define PIN_PG2A_HEMC_A2                           _L_(194)     /**< HEMC signal: HEMC_A2 on PG2 mux A */
#define MUX_PG2A_HEMC_A2                           _L_(0)       /**< HEMC signal line function value: HEMC_A2 */
#define PIO_PG2A_HEMC_A2                           (_U_(1) << 2) /**< HEMC signal: HEMC_A2 */
#define PIN_PG3A_HEMC_A3                           _L_(195)     /**< HEMC signal: HEMC_A3 on PG3 mux A */
#define MUX_PG3A_HEMC_A3                           _L_(0)       /**< HEMC signal line function value: HEMC_A3 */
#define PIO_PG3A_HEMC_A3                           (_U_(1) << 3) /**< HEMC signal: HEMC_A3 */
#define PIN_PG4A_HEMC_A4                           _L_(196)     /**< HEMC signal: HEMC_A4 on PG4 mux A */
#define MUX_PG4A_HEMC_A4                           _L_(0)       /**< HEMC signal line function value: HEMC_A4 */
#define PIO_PG4A_HEMC_A4                           (_U_(1) << 4) /**< HEMC signal: HEMC_A4 */
#define PIN_PG5A_HEMC_A5                           _L_(197)     /**< HEMC signal: HEMC_A5 on PG5 mux A */
#define MUX_PG5A_HEMC_A5                           _L_(0)       /**< HEMC signal line function value: HEMC_A5 */
#define PIO_PG5A_HEMC_A5                           (_U_(1) << 5) /**< HEMC signal: HEMC_A5 */
#define PIN_PG6A_HEMC_A6                           _L_(198)     /**< HEMC signal: HEMC_A6 on PG6 mux A */
#define MUX_PG6A_HEMC_A6                           _L_(0)       /**< HEMC signal line function value: HEMC_A6 */
#define PIO_PG6A_HEMC_A6                           (_U_(1) << 6) /**< HEMC signal: HEMC_A6 */
#define PIN_PG7A_HEMC_A7                           _L_(199)     /**< HEMC signal: HEMC_A7 on PG7 mux A */
#define MUX_PG7A_HEMC_A7                           _L_(0)       /**< HEMC signal line function value: HEMC_A7 */
#define PIO_PG7A_HEMC_A7                           (_U_(1) << 7) /**< HEMC signal: HEMC_A7 */
#define PIN_PG8A_HEMC_A8                           _L_(200)     /**< HEMC signal: HEMC_A8 on PG8 mux A */
#define MUX_PG8A_HEMC_A8                           _L_(0)       /**< HEMC signal line function value: HEMC_A8 */
#define PIO_PG8A_HEMC_A8                           (_U_(1) << 8) /**< HEMC signal: HEMC_A8 */
#define PIN_PG9A_HEMC_A9                           _L_(201)     /**< HEMC signal: HEMC_A9 on PG9 mux A */
#define MUX_PG9A_HEMC_A9                           _L_(0)       /**< HEMC signal line function value: HEMC_A9 */
#define PIO_PG9A_HEMC_A9                           (_U_(1) << 9) /**< HEMC signal: HEMC_A9 */
#define PIN_PG10A_HEMC_A10                         _L_(202)     /**< HEMC signal: HEMC_A10 on PG10 mux A */
#define MUX_PG10A_HEMC_A10                         _L_(0)       /**< HEMC signal line function value: HEMC_A10 */
#define PIO_PG10A_HEMC_A10                         (_U_(1) << 10) /**< HEMC signal: HEMC_A10 */
#define PIN_PG11A_HEMC_A11                         _L_(203)     /**< HEMC signal: HEMC_A11 on PG11 mux A */
#define MUX_PG11A_HEMC_A11                         _L_(0)       /**< HEMC signal line function value: HEMC_A11 */
#define PIO_PG11A_HEMC_A11                         (_U_(1) << 11) /**< HEMC signal: HEMC_A11 */
#define PIN_PG12A_HEMC_A12                         _L_(204)     /**< HEMC signal: HEMC_A12 on PG12 mux A */
#define MUX_PG12A_HEMC_A12                         _L_(0)       /**< HEMC signal line function value: HEMC_A12 */
#define PIO_PG12A_HEMC_A12                         (_U_(1) << 12) /**< HEMC signal: HEMC_A12 */
#define PIN_PG13A_HEMC_A13                         _L_(205)     /**< HEMC signal: HEMC_A13 on PG13 mux A */
#define MUX_PG13A_HEMC_A13                         _L_(0)       /**< HEMC signal line function value: HEMC_A13 */
#define PIO_PG13A_HEMC_A13                         (_U_(1) << 13) /**< HEMC signal: HEMC_A13 */
#define PIN_PG14A_HEMC_A14                         _L_(206)     /**< HEMC signal: HEMC_A14 on PG14 mux A */
#define MUX_PG14A_HEMC_A14                         _L_(0)       /**< HEMC signal line function value: HEMC_A14 */
#define PIO_PG14A_HEMC_A14                         (_U_(1) << 14) /**< HEMC signal: HEMC_A14 */
#define PIN_PG15A_HEMC_A15                         _L_(207)     /**< HEMC signal: HEMC_A15 on PG15 mux A */
#define MUX_PG15A_HEMC_A15                         _L_(0)       /**< HEMC signal line function value: HEMC_A15 */
#define PIO_PG15A_HEMC_A15                         (_U_(1) << 15) /**< HEMC signal: HEMC_A15 */
#define PIN_PG16A_HEMC_A16                         _L_(208)     /**< HEMC signal: HEMC_A16 on PG16 mux A */
#define MUX_PG16A_HEMC_A16                         _L_(0)       /**< HEMC signal line function value: HEMC_A16 */
#define PIO_PG16A_HEMC_A16                         (_U_(1) << 16) /**< HEMC signal: HEMC_A16 */
#define PIN_PG17A_HEMC_A17                         _L_(209)     /**< HEMC signal: HEMC_A17 on PG17 mux A */
#define MUX_PG17A_HEMC_A17                         _L_(0)       /**< HEMC signal line function value: HEMC_A17 */
#define PIO_PG17A_HEMC_A17                         (_U_(1) << 17) /**< HEMC signal: HEMC_A17 */
#define PIN_PG18A_HEMC_A18                         _L_(210)     /**< HEMC signal: HEMC_A18 on PG18 mux A */
#define MUX_PG18A_HEMC_A18                         _L_(0)       /**< HEMC signal line function value: HEMC_A18 */
#define PIO_PG18A_HEMC_A18                         (_U_(1) << 18) /**< HEMC signal: HEMC_A18 */
#define PIN_PG19A_HEMC_A19                         _L_(211)     /**< HEMC signal: HEMC_A19 on PG19 mux A */
#define MUX_PG19A_HEMC_A19                         _L_(0)       /**< HEMC signal line function value: HEMC_A19 */
#define PIO_PG19A_HEMC_A19                         (_U_(1) << 19) /**< HEMC signal: HEMC_A19 */
#define PIN_PG20A_HEMC_A20                         _L_(212)     /**< HEMC signal: HEMC_A20 on PG20 mux A */
#define MUX_PG20A_HEMC_A20                         _L_(0)       /**< HEMC signal line function value: HEMC_A20 */
#define PIO_PG20A_HEMC_A20                         (_U_(1) << 20) /**< HEMC signal: HEMC_A20 */
#define PIN_PG21A_HEMC_A21                         _L_(213)     /**< HEMC signal: HEMC_A21 on PG21 mux A */
#define MUX_PG21A_HEMC_A21                         _L_(0)       /**< HEMC signal line function value: HEMC_A21 */
#define PIO_PG21A_HEMC_A21                         (_U_(1) << 21) /**< HEMC signal: HEMC_A21 */
#define PIN_PG22A_HEMC_A22                         _L_(214)     /**< HEMC signal: HEMC_A22 on PG22 mux A */
#define MUX_PG22A_HEMC_A22                         _L_(0)       /**< HEMC signal line function value: HEMC_A22 */
#define PIO_PG22A_HEMC_A22                         (_U_(1) << 22) /**< HEMC signal: HEMC_A22 */
#define PIN_PG23A_HEMC_A23                         _L_(215)     /**< HEMC signal: HEMC_A23 on PG23 mux A */
#define MUX_PG23A_HEMC_A23                         _L_(0)       /**< HEMC signal line function value: HEMC_A23 */
#define PIO_PG23A_HEMC_A23                         (_U_(1) << 23) /**< HEMC signal: HEMC_A23 */
#define PIN_PG24A_HEMC_A24                         _L_(216)     /**< HEMC signal: HEMC_A24 on PG24 mux A */
#define MUX_PG24A_HEMC_A24                         _L_(0)       /**< HEMC signal line function value: HEMC_A24 */
#define PIO_PG24A_HEMC_A24                         (_U_(1) << 24) /**< HEMC signal: HEMC_A24 */
#define PIN_PG25A_HEMC_A25                         _L_(217)     /**< HEMC signal: HEMC_A25 on PG25 mux A */
#define MUX_PG25A_HEMC_A25                         _L_(0)       /**< HEMC signal line function value: HEMC_A25 */
#define PIO_PG25A_HEMC_A25                         (_U_(1) << 25) /**< HEMC signal: HEMC_A25 */
#define PIN_PG26A_HEMC_A26                         _L_(218)     /**< HEMC signal: HEMC_A26 on PG26 mux A */
#define MUX_PG26A_HEMC_A26                         _L_(0)       /**< HEMC signal line function value: HEMC_A26 */
#define PIO_PG26A_HEMC_A26                         (_U_(1) << 26) /**< HEMC signal: HEMC_A26 */
#define PIN_PG27A_HEMC_A27                         _L_(219)     /**< HEMC signal: HEMC_A27 on PG27 mux A */
#define MUX_PG27A_HEMC_A27                         _L_(0)       /**< HEMC signal line function value: HEMC_A27 */
#define PIO_PG27A_HEMC_A27                         (_U_(1) << 27) /**< HEMC signal: HEMC_A27 */
#define PIN_PG15A_HEMC_BA0                         _L_(207)     /**< HEMC signal: HEMC_BA0 on PG15 mux A */
#define MUX_PG15A_HEMC_BA0                         _L_(0)       /**< HEMC signal line function value: HEMC_BA0 */
#define PIO_PG15A_HEMC_BA0                         (_U_(1) << 15) /**< HEMC signal: HEMC_BA0 */
#define PIN_PG16A_HEMC_BA1                         _L_(208)     /**< HEMC signal: HEMC_BA1 on PG16 mux A */
#define MUX_PG16A_HEMC_BA1                         _L_(0)       /**< HEMC signal line function value: HEMC_BA1 */
#define PIO_PG16A_HEMC_BA1                         (_U_(1) << 16) /**< HEMC signal: HEMC_BA1 */
#define PIN_PF24X1_HEMC_BOOT_MODE                  _L_(184)     /**< HEMC signal: HEMC_BOOT_MODE on PF24 mux X1 */
#define PIO_PF24X1_HEMC_BOOT_MODE                  (_U_(1) << 24) /**< HEMC signal: HEMC_BOOT_MODE */
#define PIN_PF10A_HEMC_CAS                         _L_(170)     /**< HEMC signal: HEMC_CAS on PF10 mux A */
#define MUX_PF10A_HEMC_CAS                         _L_(0)       /**< HEMC signal line function value: HEMC_CAS */
#define PIO_PF10A_HEMC_CAS                         (_U_(1) << 10) /**< HEMC signal: HEMC_CAS */
#define PIN_PE0A_HEMC_CB0                          _L_(128)     /**< HEMC signal: HEMC_CB0 on PE0 mux A */
#define MUX_PE0A_HEMC_CB0                          _L_(0)       /**< HEMC signal line function value: HEMC_CB0 */
#define PIO_PE0A_HEMC_CB0                          (_U_(1) << 0) /**< HEMC signal: HEMC_CB0 */
#define PIN_PE1A_HEMC_CB1                          _L_(129)     /**< HEMC signal: HEMC_CB1 on PE1 mux A */
#define MUX_PE1A_HEMC_CB1                          _L_(0)       /**< HEMC signal line function value: HEMC_CB1 */
#define PIO_PE1A_HEMC_CB1                          (_U_(1) << 1) /**< HEMC signal: HEMC_CB1 */
#define PIN_PE2A_HEMC_CB2                          _L_(130)     /**< HEMC signal: HEMC_CB2 on PE2 mux A */
#define MUX_PE2A_HEMC_CB2                          _L_(0)       /**< HEMC signal line function value: HEMC_CB2 */
#define PIO_PE2A_HEMC_CB2                          (_U_(1) << 2) /**< HEMC signal: HEMC_CB2 */
#define PIN_PE3A_HEMC_CB3                          _L_(131)     /**< HEMC signal: HEMC_CB3 on PE3 mux A */
#define MUX_PE3A_HEMC_CB3                          _L_(0)       /**< HEMC signal line function value: HEMC_CB3 */
#define PIO_PE3A_HEMC_CB3                          (_U_(1) << 3) /**< HEMC signal: HEMC_CB3 */
#define PIN_PE4A_HEMC_CB4                          _L_(132)     /**< HEMC signal: HEMC_CB4 on PE4 mux A */
#define MUX_PE4A_HEMC_CB4                          _L_(0)       /**< HEMC signal line function value: HEMC_CB4 */
#define PIO_PE4A_HEMC_CB4                          (_U_(1) << 4) /**< HEMC signal: HEMC_CB4 */
#define PIN_PE5A_HEMC_CB5                          _L_(133)     /**< HEMC signal: HEMC_CB5 on PE5 mux A */
#define MUX_PE5A_HEMC_CB5                          _L_(0)       /**< HEMC signal line function value: HEMC_CB5 */
#define PIO_PE5A_HEMC_CB5                          (_U_(1) << 5) /**< HEMC signal: HEMC_CB5 */
#define PIN_PE6A_HEMC_CB6                          _L_(134)     /**< HEMC signal: HEMC_CB6 on PE6 mux A */
#define MUX_PE6A_HEMC_CB6                          _L_(0)       /**< HEMC signal line function value: HEMC_CB6 */
#define PIO_PE6A_HEMC_CB6                          (_U_(1) << 6) /**< HEMC signal: HEMC_CB6 */
#define PIN_PE7A_HEMC_CB7                          _L_(135)     /**< HEMC signal: HEMC_CB7 on PE7 mux A */
#define MUX_PE7A_HEMC_CB7                          _L_(0)       /**< HEMC signal line function value: HEMC_CB7 */
#define PIO_PE7A_HEMC_CB7                          (_U_(1) << 7) /**< HEMC signal: HEMC_CB7 */
#define PIN_PE8A_HEMC_CB8                          _L_(136)     /**< HEMC signal: HEMC_CB8 on PE8 mux A */
#define MUX_PE8A_HEMC_CB8                          _L_(0)       /**< HEMC signal line function value: HEMC_CB8 */
#define PIO_PE8A_HEMC_CB8                          (_U_(1) << 8) /**< HEMC signal: HEMC_CB8 */
#define PIN_PE9A_HEMC_CB9                          _L_(137)     /**< HEMC signal: HEMC_CB9 on PE9 mux A */
#define MUX_PE9A_HEMC_CB9                          _L_(0)       /**< HEMC signal line function value: HEMC_CB9 */
#define PIO_PE9A_HEMC_CB9                          (_U_(1) << 9) /**< HEMC signal: HEMC_CB9 */
#define PIN_PE10A_HEMC_CB10                        _L_(138)     /**< HEMC signal: HEMC_CB10 on PE10 mux A */
#define MUX_PE10A_HEMC_CB10                        _L_(0)       /**< HEMC signal line function value: HEMC_CB10 */
#define PIO_PE10A_HEMC_CB10                        (_U_(1) << 10) /**< HEMC signal: HEMC_CB10 */
#define PIN_PE11A_HEMC_CB11                        _L_(139)     /**< HEMC signal: HEMC_CB11 on PE11 mux A */
#define MUX_PE11A_HEMC_CB11                        _L_(0)       /**< HEMC signal line function value: HEMC_CB11 */
#define PIO_PE11A_HEMC_CB11                        (_U_(1) << 11) /**< HEMC signal: HEMC_CB11 */
#define PIN_PE12A_HEMC_CB12                        _L_(140)     /**< HEMC signal: HEMC_CB12 on PE12 mux A */
#define MUX_PE12A_HEMC_CB12                        _L_(0)       /**< HEMC signal line function value: HEMC_CB12 */
#define PIO_PE12A_HEMC_CB12                        (_U_(1) << 12) /**< HEMC signal: HEMC_CB12 */
#define PIN_PC31A_HEMC_CB13                        _L_(95)      /**< HEMC signal: HEMC_CB13 on PC31 mux A */
#define MUX_PC31A_HEMC_CB13                        _L_(0)       /**< HEMC signal line function value: HEMC_CB13 */
#define PIO_PC31A_HEMC_CB13                        (_U_(1) << 31) /**< HEMC signal: HEMC_CB13 */
#define PIN_PC30A_HEMC_CB14                        _L_(94)      /**< HEMC signal: HEMC_CB14 on PC30 mux A */
#define MUX_PC30A_HEMC_CB14                        _L_(0)       /**< HEMC signal line function value: HEMC_CB14 */
#define PIO_PC30A_HEMC_CB14                        (_U_(1) << 30) /**< HEMC signal: HEMC_CB14 */
#define PIN_PC29A_HEMC_CB15                        _L_(93)      /**< HEMC signal: HEMC_CB15 on PC29 mux A */
#define MUX_PC29A_HEMC_CB15                        _L_(0)       /**< HEMC signal line function value: HEMC_CB15 */
#define PIO_PC29A_HEMC_CB15                        (_U_(1) << 29) /**< HEMC signal: HEMC_CB15 */
#define PIN_PG24X1_HEMC_CFG0                       _L_(216)     /**< HEMC signal: HEMC_CFG0 on PG24 mux X1 */
#define PIO_PG24X1_HEMC_CFG0                       (_U_(1) << 24) /**< HEMC signal: HEMC_CFG0 */
#define PIN_PG25X1_HEMC_CFG1                       _L_(217)     /**< HEMC signal: HEMC_CFG1 on PG25 mux X1 */
#define PIO_PG25X1_HEMC_CFG1                       (_U_(1) << 25) /**< HEMC signal: HEMC_CFG1 */
#define PIN_PG26X1_HEMC_CFG2                       _L_(218)     /**< HEMC signal: HEMC_CFG2 on PG26 mux X1 */
#define PIO_PG26X1_HEMC_CFG2                       (_U_(1) << 26) /**< HEMC signal: HEMC_CFG2 */
#define PIN_PG27X1_HEMC_CFG3                       _L_(219)     /**< HEMC signal: HEMC_CFG3 on PG27 mux X1 */
#define PIO_PG27X1_HEMC_CFG3                       (_U_(1) << 27) /**< HEMC signal: HEMC_CFG3 */
#define PIN_PD0A_HEMC_D0                           _L_(96)      /**< HEMC signal: HEMC_D0 on PD0 mux A */
#define MUX_PD0A_HEMC_D0                           _L_(0)       /**< HEMC signal line function value: HEMC_D0 */
#define PIO_PD0A_HEMC_D0                           (_U_(1) << 0) /**< HEMC signal: HEMC_D0 */
#define PIN_PD1A_HEMC_D1                           _L_(97)      /**< HEMC signal: HEMC_D1 on PD1 mux A */
#define MUX_PD1A_HEMC_D1                           _L_(0)       /**< HEMC signal line function value: HEMC_D1 */
#define PIO_PD1A_HEMC_D1                           (_U_(1) << 1) /**< HEMC signal: HEMC_D1 */
#define PIN_PD2A_HEMC_D2                           _L_(98)      /**< HEMC signal: HEMC_D2 on PD2 mux A */
#define MUX_PD2A_HEMC_D2                           _L_(0)       /**< HEMC signal line function value: HEMC_D2 */
#define PIO_PD2A_HEMC_D2                           (_U_(1) << 2) /**< HEMC signal: HEMC_D2 */
#define PIN_PD3A_HEMC_D3                           _L_(99)      /**< HEMC signal: HEMC_D3 on PD3 mux A */
#define MUX_PD3A_HEMC_D3                           _L_(0)       /**< HEMC signal line function value: HEMC_D3 */
#define PIO_PD3A_HEMC_D3                           (_U_(1) << 3) /**< HEMC signal: HEMC_D3 */
#define PIN_PD4A_HEMC_D4                           _L_(100)     /**< HEMC signal: HEMC_D4 on PD4 mux A */
#define MUX_PD4A_HEMC_D4                           _L_(0)       /**< HEMC signal line function value: HEMC_D4 */
#define PIO_PD4A_HEMC_D4                           (_U_(1) << 4) /**< HEMC signal: HEMC_D4 */
#define PIN_PD5A_HEMC_D5                           _L_(101)     /**< HEMC signal: HEMC_D5 on PD5 mux A */
#define MUX_PD5A_HEMC_D5                           _L_(0)       /**< HEMC signal line function value: HEMC_D5 */
#define PIO_PD5A_HEMC_D5                           (_U_(1) << 5) /**< HEMC signal: HEMC_D5 */
#define PIN_PD6A_HEMC_D6                           _L_(102)     /**< HEMC signal: HEMC_D6 on PD6 mux A */
#define MUX_PD6A_HEMC_D6                           _L_(0)       /**< HEMC signal line function value: HEMC_D6 */
#define PIO_PD6A_HEMC_D6                           (_U_(1) << 6) /**< HEMC signal: HEMC_D6 */
#define PIN_PD7A_HEMC_D7                           _L_(103)     /**< HEMC signal: HEMC_D7 on PD7 mux A */
#define MUX_PD7A_HEMC_D7                           _L_(0)       /**< HEMC signal line function value: HEMC_D7 */
#define PIO_PD7A_HEMC_D7                           (_U_(1) << 7) /**< HEMC signal: HEMC_D7 */
#define PIN_PD8A_HEMC_D8                           _L_(104)     /**< HEMC signal: HEMC_D8 on PD8 mux A */
#define MUX_PD8A_HEMC_D8                           _L_(0)       /**< HEMC signal line function value: HEMC_D8 */
#define PIO_PD8A_HEMC_D8                           (_U_(1) << 8) /**< HEMC signal: HEMC_D8 */
#define PIN_PD9A_HEMC_D9                           _L_(105)     /**< HEMC signal: HEMC_D9 on PD9 mux A */
#define MUX_PD9A_HEMC_D9                           _L_(0)       /**< HEMC signal line function value: HEMC_D9 */
#define PIO_PD9A_HEMC_D9                           (_U_(1) << 9) /**< HEMC signal: HEMC_D9 */
#define PIN_PD10A_HEMC_D10                         _L_(106)     /**< HEMC signal: HEMC_D10 on PD10 mux A */
#define MUX_PD10A_HEMC_D10                         _L_(0)       /**< HEMC signal line function value: HEMC_D10 */
#define PIO_PD10A_HEMC_D10                         (_U_(1) << 10) /**< HEMC signal: HEMC_D10 */
#define PIN_PD11A_HEMC_D11                         _L_(107)     /**< HEMC signal: HEMC_D11 on PD11 mux A */
#define MUX_PD11A_HEMC_D11                         _L_(0)       /**< HEMC signal line function value: HEMC_D11 */
#define PIO_PD11A_HEMC_D11                         (_U_(1) << 11) /**< HEMC signal: HEMC_D11 */
#define PIN_PD12A_HEMC_D12                         _L_(108)     /**< HEMC signal: HEMC_D12 on PD12 mux A */
#define MUX_PD12A_HEMC_D12                         _L_(0)       /**< HEMC signal line function value: HEMC_D12 */
#define PIO_PD12A_HEMC_D12                         (_U_(1) << 12) /**< HEMC signal: HEMC_D12 */
#define PIN_PD13A_HEMC_D13                         _L_(109)     /**< HEMC signal: HEMC_D13 on PD13 mux A */
#define MUX_PD13A_HEMC_D13                         _L_(0)       /**< HEMC signal line function value: HEMC_D13 */
#define PIO_PD13A_HEMC_D13                         (_U_(1) << 13) /**< HEMC signal: HEMC_D13 */
#define PIN_PD14A_HEMC_D14                         _L_(110)     /**< HEMC signal: HEMC_D14 on PD14 mux A */
#define MUX_PD14A_HEMC_D14                         _L_(0)       /**< HEMC signal line function value: HEMC_D14 */
#define PIO_PD14A_HEMC_D14                         (_U_(1) << 14) /**< HEMC signal: HEMC_D14 */
#define PIN_PD15A_HEMC_D15                         _L_(111)     /**< HEMC signal: HEMC_D15 on PD15 mux A */
#define MUX_PD15A_HEMC_D15                         _L_(0)       /**< HEMC signal line function value: HEMC_D15 */
#define PIO_PD15A_HEMC_D15                         (_U_(1) << 15) /**< HEMC signal: HEMC_D15 */
#define PIN_PD16A_HEMC_D16                         _L_(112)     /**< HEMC signal: HEMC_D16 on PD16 mux A */
#define MUX_PD16A_HEMC_D16                         _L_(0)       /**< HEMC signal line function value: HEMC_D16 */
#define PIO_PD16A_HEMC_D16                         (_U_(1) << 16) /**< HEMC signal: HEMC_D16 */
#define PIN_PD17A_HEMC_D17                         _L_(113)     /**< HEMC signal: HEMC_D17 on PD17 mux A */
#define MUX_PD17A_HEMC_D17                         _L_(0)       /**< HEMC signal line function value: HEMC_D17 */
#define PIO_PD17A_HEMC_D17                         (_U_(1) << 17) /**< HEMC signal: HEMC_D17 */
#define PIN_PD18A_HEMC_D18                         _L_(114)     /**< HEMC signal: HEMC_D18 on PD18 mux A */
#define MUX_PD18A_HEMC_D18                         _L_(0)       /**< HEMC signal line function value: HEMC_D18 */
#define PIO_PD18A_HEMC_D18                         (_U_(1) << 18) /**< HEMC signal: HEMC_D18 */
#define PIN_PD19A_HEMC_D19                         _L_(115)     /**< HEMC signal: HEMC_D19 on PD19 mux A */
#define MUX_PD19A_HEMC_D19                         _L_(0)       /**< HEMC signal line function value: HEMC_D19 */
#define PIO_PD19A_HEMC_D19                         (_U_(1) << 19) /**< HEMC signal: HEMC_D19 */
#define PIN_PD20A_HEMC_D20                         _L_(116)     /**< HEMC signal: HEMC_D20 on PD20 mux A */
#define MUX_PD20A_HEMC_D20                         _L_(0)       /**< HEMC signal line function value: HEMC_D20 */
#define PIO_PD20A_HEMC_D20                         (_U_(1) << 20) /**< HEMC signal: HEMC_D20 */
#define PIN_PD21A_HEMC_D21                         _L_(117)     /**< HEMC signal: HEMC_D21 on PD21 mux A */
#define MUX_PD21A_HEMC_D21                         _L_(0)       /**< HEMC signal line function value: HEMC_D21 */
#define PIO_PD21A_HEMC_D21                         (_U_(1) << 21) /**< HEMC signal: HEMC_D21 */
#define PIN_PD22A_HEMC_D22                         _L_(118)     /**< HEMC signal: HEMC_D22 on PD22 mux A */
#define MUX_PD22A_HEMC_D22                         _L_(0)       /**< HEMC signal line function value: HEMC_D22 */
#define PIO_PD22A_HEMC_D22                         (_U_(1) << 22) /**< HEMC signal: HEMC_D22 */
#define PIN_PD23A_HEMC_D23                         _L_(119)     /**< HEMC signal: HEMC_D23 on PD23 mux A */
#define MUX_PD23A_HEMC_D23                         _L_(0)       /**< HEMC signal line function value: HEMC_D23 */
#define PIO_PD23A_HEMC_D23                         (_U_(1) << 23) /**< HEMC signal: HEMC_D23 */
#define PIN_PD24A_HEMC_D24                         _L_(120)     /**< HEMC signal: HEMC_D24 on PD24 mux A */
#define MUX_PD24A_HEMC_D24                         _L_(0)       /**< HEMC signal line function value: HEMC_D24 */
#define PIO_PD24A_HEMC_D24                         (_U_(1) << 24) /**< HEMC signal: HEMC_D24 */
#define PIN_PD25A_HEMC_D25                         _L_(121)     /**< HEMC signal: HEMC_D25 on PD25 mux A */
#define MUX_PD25A_HEMC_D25                         _L_(0)       /**< HEMC signal line function value: HEMC_D25 */
#define PIO_PD25A_HEMC_D25                         (_U_(1) << 25) /**< HEMC signal: HEMC_D25 */
#define PIN_PD26A_HEMC_D26                         _L_(122)     /**< HEMC signal: HEMC_D26 on PD26 mux A */
#define MUX_PD26A_HEMC_D26                         _L_(0)       /**< HEMC signal line function value: HEMC_D26 */
#define PIO_PD26A_HEMC_D26                         (_U_(1) << 26) /**< HEMC signal: HEMC_D26 */
#define PIN_PD27A_HEMC_D27                         _L_(123)     /**< HEMC signal: HEMC_D27 on PD27 mux A */
#define MUX_PD27A_HEMC_D27                         _L_(0)       /**< HEMC signal line function value: HEMC_D27 */
#define PIO_PD27A_HEMC_D27                         (_U_(1) << 27) /**< HEMC signal: HEMC_D27 */
#define PIN_PD28A_HEMC_D28                         _L_(124)     /**< HEMC signal: HEMC_D28 on PD28 mux A */
#define MUX_PD28A_HEMC_D28                         _L_(0)       /**< HEMC signal line function value: HEMC_D28 */
#define PIO_PD28A_HEMC_D28                         (_U_(1) << 28) /**< HEMC signal: HEMC_D28 */
#define PIN_PD29A_HEMC_D29                         _L_(125)     /**< HEMC signal: HEMC_D29 on PD29 mux A */
#define MUX_PD29A_HEMC_D29                         _L_(0)       /**< HEMC signal line function value: HEMC_D29 */
#define PIO_PD29A_HEMC_D29                         (_U_(1) << 29) /**< HEMC signal: HEMC_D29 */
#define PIN_PD30A_HEMC_D30                         _L_(126)     /**< HEMC signal: HEMC_D30 on PD30 mux A */
#define MUX_PD30A_HEMC_D30                         _L_(0)       /**< HEMC signal line function value: HEMC_D30 */
#define PIO_PD30A_HEMC_D30                         (_U_(1) << 30) /**< HEMC signal: HEMC_D30 */
#define PIN_PD31A_HEMC_D31                         _L_(127)     /**< HEMC signal: HEMC_D31 on PD31 mux A */
#define MUX_PD31A_HEMC_D31                         _L_(0)       /**< HEMC signal line function value: HEMC_D31 */
#define PIO_PD31A_HEMC_D31                         (_U_(1) << 31) /**< HEMC signal: HEMC_D31 */
#define PIN_PF25A_HEMC_EXT_CTRL_BUFFER             _L_(185)     /**< HEMC signal: HEMC_EXT_CTRL_BUFFER on PF25 mux A */
#define MUX_PF25A_HEMC_EXT_CTRL_BUFFER             _L_(0)       /**< HEMC signal line function value: HEMC_EXT_CTRL_BUFFER */
#define PIO_PF25A_HEMC_EXT_CTRL_BUFFER             (_U_(1) << 25) /**< HEMC signal: HEMC_EXT_CTRL_BUFFER */
#define PIN_PF11A_HEMC_NCS0                        _L_(171)     /**< HEMC signal: HEMC_NCS0 on PF11 mux A */
#define MUX_PF11A_HEMC_NCS0                        _L_(0)       /**< HEMC signal line function value: HEMC_NCS0 */
#define PIO_PF11A_HEMC_NCS0                        (_U_(1) << 11) /**< HEMC signal: HEMC_NCS0 */
#define PIN_PF12A_HEMC_NCS1                        _L_(172)     /**< HEMC signal: HEMC_NCS1 on PF12 mux A */
#define MUX_PF12A_HEMC_NCS1                        _L_(0)       /**< HEMC signal line function value: HEMC_NCS1 */
#define PIO_PF12A_HEMC_NCS1                        (_U_(1) << 12) /**< HEMC signal: HEMC_NCS1 */
#define PIN_PF13A_HEMC_NCS2                        _L_(173)     /**< HEMC signal: HEMC_NCS2 on PF13 mux A */
#define MUX_PF13A_HEMC_NCS2                        _L_(0)       /**< HEMC signal line function value: HEMC_NCS2 */
#define PIO_PF13A_HEMC_NCS2                        (_U_(1) << 13) /**< HEMC signal: HEMC_NCS2 */
#define PIN_PF14A_HEMC_NCS3                        _L_(174)     /**< HEMC signal: HEMC_NCS3 on PF14 mux A */
#define MUX_PF14A_HEMC_NCS3                        _L_(0)       /**< HEMC signal line function value: HEMC_NCS3 */
#define PIO_PF14A_HEMC_NCS3                        (_U_(1) << 14) /**< HEMC signal: HEMC_NCS3 */
#define PIN_PF15A_HEMC_NCS4                        _L_(175)     /**< HEMC signal: HEMC_NCS4 on PF15 mux A */
#define MUX_PF15A_HEMC_NCS4                        _L_(0)       /**< HEMC signal line function value: HEMC_NCS4 */
#define PIO_PF15A_HEMC_NCS4                        (_U_(1) << 15) /**< HEMC signal: HEMC_NCS4 */
#define PIN_PF16A_HEMC_NCS5                        _L_(176)     /**< HEMC signal: HEMC_NCS5 on PF16 mux A */
#define MUX_PF16A_HEMC_NCS5                        _L_(0)       /**< HEMC signal line function value: HEMC_NCS5 */
#define PIO_PF16A_HEMC_NCS5                        (_U_(1) << 16) /**< HEMC signal: HEMC_NCS5 */
#define PIN_PF17A_HEMC_NRD                         _L_(177)     /**< HEMC signal: HEMC_NRD on PF17 mux A */
#define MUX_PF17A_HEMC_NRD                         _L_(0)       /**< HEMC signal line function value: HEMC_NRD */
#define PIO_PF17A_HEMC_NRD                         (_U_(1) << 17) /**< HEMC signal: HEMC_NRD */
#define PIN_PF24A_HEMC_NWAIT                       _L_(184)     /**< HEMC signal: HEMC_NWAIT on PF24 mux A */
#define MUX_PF24A_HEMC_NWAIT                       _L_(0)       /**< HEMC signal line function value: HEMC_NWAIT */
#define PIO_PF24A_HEMC_NWAIT                       (_U_(1) << 24) /**< HEMC signal: HEMC_NWAIT */
#define PIN_PF18A_HEMC_NWE                         _L_(178)     /**< HEMC signal: HEMC_NWE on PF18 mux A */
#define MUX_PF18A_HEMC_NWE                         _L_(0)       /**< HEMC signal line function value: HEMC_NWE */
#define PIO_PF18A_HEMC_NWE                         (_U_(1) << 18) /**< HEMC signal: HEMC_NWE */
#define PIN_PF19A_HEMC_NWR0                        _L_(179)     /**< HEMC signal: HEMC_NWR0 on PF19 mux A */
#define MUX_PF19A_HEMC_NWR0                        _L_(0)       /**< HEMC signal line function value: HEMC_NWR0 */
#define PIO_PF19A_HEMC_NWR0                        (_U_(1) << 19) /**< HEMC signal: HEMC_NWR0 */
#define PIN_PF20A_HEMC_NWR1                        _L_(180)     /**< HEMC signal: HEMC_NWR1 on PF20 mux A */
#define MUX_PF20A_HEMC_NWR1                        _L_(0)       /**< HEMC signal line function value: HEMC_NWR1 */
#define PIO_PF20A_HEMC_NWR1                        (_U_(1) << 20) /**< HEMC signal: HEMC_NWR1 */
#define PIN_PF21A_HEMC_NWR2                        _L_(181)     /**< HEMC signal: HEMC_NWR2 on PF21 mux A */
#define MUX_PF21A_HEMC_NWR2                        _L_(0)       /**< HEMC signal line function value: HEMC_NWR2 */
#define PIO_PF21A_HEMC_NWR2                        (_U_(1) << 21) /**< HEMC signal: HEMC_NWR2 */
#define PIN_PF22A_HEMC_NWR3                        _L_(182)     /**< HEMC signal: HEMC_NWR3 on PF22 mux A */
#define MUX_PF22A_HEMC_NWR3                        _L_(0)       /**< HEMC signal line function value: HEMC_NWR3 */
#define PIO_PF22A_HEMC_NWR3                        (_U_(1) << 22) /**< HEMC signal: HEMC_NWR3 */
#define PIN_PF23A_HEMC_NWR4                        _L_(183)     /**< HEMC signal: HEMC_NWR4 on PF23 mux A */
#define MUX_PF23A_HEMC_NWR4                        _L_(0)       /**< HEMC signal line function value: HEMC_NWR4 */
#define PIO_PF23A_HEMC_NWR4                        (_U_(1) << 23) /**< HEMC signal: HEMC_NWR4 */
#define PIN_PF0A_HEMC_RAS                          _L_(160)     /**< HEMC signal: HEMC_RAS on PF0 mux A */
#define MUX_PF0A_HEMC_RAS                          _L_(0)       /**< HEMC signal line function value: HEMC_RAS */
#define PIO_PF0A_HEMC_RAS                          (_U_(1) << 0) /**< HEMC signal: HEMC_RAS */
#define PIN_PF1A_HEMC_SDA10                        _L_(161)     /**< HEMC signal: HEMC_SDA10 on PF1 mux A */
#define MUX_PF1A_HEMC_SDA10                        _L_(0)       /**< HEMC signal line function value: HEMC_SDA10 */
#define PIO_PF1A_HEMC_SDA10                        (_U_(1) << 1) /**< HEMC signal: HEMC_SDA10 */
#define PIN_PF2A_HEMC_SDCK                         _L_(162)     /**< HEMC signal: HEMC_SDCK on PF2 mux A */
#define MUX_PF2A_HEMC_SDCK                         _L_(0)       /**< HEMC signal line function value: HEMC_SDCK */
#define PIO_PF2A_HEMC_SDCK                         (_U_(1) << 2) /**< HEMC signal: HEMC_SDCK */
#define PIN_PF3A_HEMC_SDCKE                        _L_(163)     /**< HEMC signal: HEMC_SDCKE on PF3 mux A */
#define MUX_PF3A_HEMC_SDCKE                        _L_(0)       /**< HEMC signal line function value: HEMC_SDCKE */
#define PIO_PF3A_HEMC_SDCKE                        (_U_(1) << 3) /**< HEMC signal: HEMC_SDCKE */
#define PIN_PF4A_HEMC_SDNBS0                       _L_(164)     /**< HEMC signal: HEMC_SDNBS0 on PF4 mux A */
#define MUX_PF4A_HEMC_SDNBS0                       _L_(0)       /**< HEMC signal line function value: HEMC_SDNBS0 */
#define PIO_PF4A_HEMC_SDNBS0                       (_U_(1) << 4) /**< HEMC signal: HEMC_SDNBS0 */
#define PIN_PF5A_HEMC_SDNBS1                       _L_(165)     /**< HEMC signal: HEMC_SDNBS1 on PF5 mux A */
#define MUX_PF5A_HEMC_SDNBS1                       _L_(0)       /**< HEMC signal line function value: HEMC_SDNBS1 */
#define PIO_PF5A_HEMC_SDNBS1                       (_U_(1) << 5) /**< HEMC signal: HEMC_SDNBS1 */
#define PIN_PF6A_HEMC_SDNBS2                       _L_(166)     /**< HEMC signal: HEMC_SDNBS2 on PF6 mux A */
#define MUX_PF6A_HEMC_SDNBS2                       _L_(0)       /**< HEMC signal line function value: HEMC_SDNBS2 */
#define PIO_PF6A_HEMC_SDNBS2                       (_U_(1) << 6) /**< HEMC signal: HEMC_SDNBS2 */
#define PIN_PF7A_HEMC_SDNBS3                       _L_(167)     /**< HEMC signal: HEMC_SDNBS3 on PF7 mux A */
#define MUX_PF7A_HEMC_SDNBS3                       _L_(0)       /**< HEMC signal line function value: HEMC_SDNBS3 */
#define PIO_PF7A_HEMC_SDNBS3                       (_U_(1) << 7) /**< HEMC signal: HEMC_SDNBS3 */
#define PIN_PF8A_HEMC_SDNBS4                       _L_(168)     /**< HEMC signal: HEMC_SDNBS4 on PF8 mux A */
#define MUX_PF8A_HEMC_SDNBS4                       _L_(0)       /**< HEMC signal line function value: HEMC_SDNBS4 */
#define PIO_PF8A_HEMC_SDNBS4                       (_U_(1) << 8) /**< HEMC signal: HEMC_SDNBS4 */
#define PIN_PF9A_HEMC_SDWE                         _L_(169)     /**< HEMC signal: HEMC_SDWE on PF9 mux A */
#define MUX_PF9A_HEMC_SDWE                         _L_(0)       /**< HEMC signal line function value: HEMC_SDWE */
#define PIO_PF9A_HEMC_SDWE                         (_U_(1) << 9) /**< HEMC signal: HEMC_SDWE */
/* ========== PIO definition for MCAN0 peripheral ========== */
#define PIN_PB7C_MCAN0_CANRX0                      _L_(39)      /**< MCAN0 signal: MCAN0_CANRX0 on PB7 mux C */
#define MUX_PB7C_MCAN0_CANRX0                      _L_(2)       /**< MCAN0 signal line function value: MCAN0_CANRX0 */
#define PIO_PB7C_MCAN0_CANRX0                      (_U_(1) << 7) /**< MCAN0 signal: MCAN0_CANRX0 */
#define PIN_PE8C_MCAN0_CANRX0                      _L_(136)     /**< MCAN0 signal: MCAN0_CANRX0 on PE8 mux C */
#define MUX_PE8C_MCAN0_CANRX0                      _L_(2)       /**< MCAN0 signal line function value: MCAN0_CANRX0 */
#define PIO_PE8C_MCAN0_CANRX0                      (_U_(1) << 8) /**< MCAN0 signal: MCAN0_CANRX0 */
#define PIN_PB6C_MCAN0_CANTX0                      _L_(38)      /**< MCAN0 signal: MCAN0_CANTX0 on PB6 mux C */
#define MUX_PB6C_MCAN0_CANTX0                      _L_(2)       /**< MCAN0 signal line function value: MCAN0_CANTX0 */
#define PIO_PB6C_MCAN0_CANTX0                      (_U_(1) << 6) /**< MCAN0 signal: MCAN0_CANTX0 */
#define PIN_PE9C_MCAN0_CANTX0                      _L_(137)     /**< MCAN0 signal: MCAN0_CANTX0 on PE9 mux C */
#define MUX_PE9C_MCAN0_CANTX0                      _L_(2)       /**< MCAN0 signal line function value: MCAN0_CANTX0 */
#define PIO_PE9C_MCAN0_CANTX0                      (_U_(1) << 9) /**< MCAN0 signal: MCAN0_CANTX0 */
/* ========== PIO definition for MCAN1 peripheral ========== */
#define PIN_PB5C_MCAN1_CANRX1                      _L_(37)      /**< MCAN1 signal: MCAN1_CANRX1 on PB5 mux C */
#define MUX_PB5C_MCAN1_CANRX1                      _L_(2)       /**< MCAN1 signal line function value: MCAN1_CANRX1 */
#define PIO_PB5C_MCAN1_CANRX1                      (_U_(1) << 5) /**< MCAN1 signal: MCAN1_CANRX1 */
#define PIN_PE10C_MCAN1_CANRX1                     _L_(138)     /**< MCAN1 signal: MCAN1_CANRX1 on PE10 mux C */
#define MUX_PE10C_MCAN1_CANRX1                     _L_(2)       /**< MCAN1 signal line function value: MCAN1_CANRX1 */
#define PIO_PE10C_MCAN1_CANRX1                     (_U_(1) << 10) /**< MCAN1 signal: MCAN1_CANRX1 */
#define PIN_PB4C_MCAN1_CANTX1                      _L_(36)      /**< MCAN1 signal: MCAN1_CANTX1 on PB4 mux C */
#define MUX_PB4C_MCAN1_CANTX1                      _L_(2)       /**< MCAN1 signal line function value: MCAN1_CANTX1 */
#define PIO_PB4C_MCAN1_CANTX1                      (_U_(1) << 4) /**< MCAN1 signal: MCAN1_CANTX1 */
#define PIN_PE11C_MCAN1_CANTX1                     _L_(139)     /**< MCAN1 signal: MCAN1_CANTX1 on PE11 mux C */
#define MUX_PE11C_MCAN1_CANTX1                     _L_(2)       /**< MCAN1 signal line function value: MCAN1_CANTX1 */
#define PIO_PE11C_MCAN1_CANTX1                     (_U_(1) << 11) /**< MCAN1 signal: MCAN1_CANTX1 */
/* ========== PIO definition for PMC peripheral ========== */
#define PIN_PA11B_PMC_PCK0                         _L_(11)      /**< PMC signal: PMC_PCK0 on PA11 mux B */
#define MUX_PA11B_PMC_PCK0                         _L_(1)       /**< PMC signal line function value: PMC_PCK0 */
#define PIO_PA11B_PMC_PCK0                         (_U_(1) << 11) /**< PMC signal: PMC_PCK0 */
#define PIN_PC7A_PMC_PCK0                          _L_(71)      /**< PMC signal: PMC_PCK0 on PC7 mux A */
#define MUX_PC7A_PMC_PCK0                          _L_(0)       /**< PMC signal line function value: PMC_PCK0 */
#define PIO_PC7A_PMC_PCK0                          (_U_(1) << 7) /**< PMC signal: PMC_PCK0 */
#define PIN_PC8A_PMC_PCK1                          _L_(72)      /**< PMC signal: PMC_PCK1 on PC8 mux A */
#define MUX_PC8A_PMC_PCK1                          _L_(0)       /**< PMC signal line function value: PMC_PCK1 */
#define PIO_PC8A_PMC_PCK1                          (_U_(1) << 8) /**< PMC signal: PMC_PCK1 */
#define PIN_PE12B_PMC_PCK1                         _L_(140)     /**< PMC signal: PMC_PCK1 on PE12 mux B */
#define MUX_PE12B_PMC_PCK1                         _L_(1)       /**< PMC signal line function value: PMC_PCK1 */
#define PIO_PE12B_PMC_PCK1                         (_U_(1) << 12) /**< PMC signal: PMC_PCK1 */
#define PIN_PA10B_PMC_PCK2                         _L_(10)      /**< PMC signal: PMC_PCK2 on PA10 mux B */
#define MUX_PA10B_PMC_PCK2                         _L_(1)       /**< PMC signal line function value: PMC_PCK2 */
#define PIO_PA10B_PMC_PCK2                         (_U_(1) << 10) /**< PMC signal: PMC_PCK2 */
/* ========== PIO definition for PWM0 peripheral ========== */
#define PIN_PA10C_PWM0_PWMC0_PWMEXTRG0             _L_(10)      /**< PWM0 signal: PWM0_PWMC0_PWMEXTRG0 on PA10 mux C */
#define MUX_PA10C_PWM0_PWMC0_PWMEXTRG0             _L_(2)       /**< PWM0 signal line function value: PWM0_PWMC0_PWMEXTRG0 */
#define PIO_PA10C_PWM0_PWMC0_PWMEXTRG0             (_U_(1) << 10) /**< PWM0 signal: PWM0_PWMC0_PWMEXTRG0 */
#define PIN_PA11C_PWM0_PWMC0_PWMEXTRG1             _L_(11)      /**< PWM0 signal: PWM0_PWMC0_PWMEXTRG1 on PA11 mux C */
#define MUX_PA11C_PWM0_PWMC0_PWMEXTRG1             _L_(2)       /**< PWM0 signal line function value: PWM0_PWMC0_PWMEXTRG1 */
#define PIO_PA11C_PWM0_PWMC0_PWMEXTRG1             (_U_(1) << 11) /**< PWM0 signal: PWM0_PWMC0_PWMEXTRG1 */
#define PIN_PA8C_PWM0_PWMC0_PWMFI0                 _L_(8)       /**< PWM0 signal: PWM0_PWMC0_PWMFI0 on PA8 mux C */
#define MUX_PA8C_PWM0_PWMC0_PWMFI0                 _L_(2)       /**< PWM0 signal line function value: PWM0_PWMC0_PWMFI0 */
#define PIO_PA8C_PWM0_PWMC0_PWMFI0                 (_U_(1) << 8) /**< PWM0 signal: PWM0_PWMC0_PWMFI0 */
#define PIN_PA9C_PWM0_PWMC0_PWMFI1                 _L_(9)       /**< PWM0 signal: PWM0_PWMC0_PWMFI1 on PA9 mux C */
#define MUX_PA9C_PWM0_PWMC0_PWMFI1                 _L_(2)       /**< PWM0 signal line function value: PWM0_PWMC0_PWMFI1 */
#define PIO_PA9C_PWM0_PWMC0_PWMFI1                 (_U_(1) << 9) /**< PWM0 signal: PWM0_PWMC0_PWMFI1 */
#define PIN_PA12C_PWM0_PWMC0_PWMFI2                _L_(12)      /**< PWM0 signal: PWM0_PWMC0_PWMFI2 on PA12 mux C */
#define MUX_PA12C_PWM0_PWMC0_PWMFI2                _L_(2)       /**< PWM0 signal line function value: PWM0_PWMC0_PWMFI2 */
#define PIO_PA12C_PWM0_PWMC0_PWMFI2                (_U_(1) << 12) /**< PWM0 signal: PWM0_PWMC0_PWMFI2 */
#define PIN_PA0C_PWM0_PWMC0_PWMH0                  _L_(0)       /**< PWM0 signal: PWM0_PWMC0_PWMH0 on PA0 mux C */
#define MUX_PA0C_PWM0_PWMC0_PWMH0                  _L_(2)       /**< PWM0 signal line function value: PWM0_PWMC0_PWMH0 */
#define PIO_PA0C_PWM0_PWMC0_PWMH0                  (_U_(1) << 0) /**< PWM0 signal: PWM0_PWMC0_PWMH0 */
#define PIN_PA1C_PWM0_PWMC0_PWMH1                  _L_(1)       /**< PWM0 signal: PWM0_PWMC0_PWMH1 on PA1 mux C */
#define MUX_PA1C_PWM0_PWMC0_PWMH1                  _L_(2)       /**< PWM0 signal line function value: PWM0_PWMC0_PWMH1 */
#define PIO_PA1C_PWM0_PWMC0_PWMH1                  (_U_(1) << 1) /**< PWM0 signal: PWM0_PWMC0_PWMH1 */
#define PIN_PA2C_PWM0_PWMC0_PWMH2                  _L_(2)       /**< PWM0 signal: PWM0_PWMC0_PWMH2 on PA2 mux C */
#define MUX_PA2C_PWM0_PWMC0_PWMH2                  _L_(2)       /**< PWM0 signal line function value: PWM0_PWMC0_PWMH2 */
#define PIO_PA2C_PWM0_PWMC0_PWMH2                  (_U_(1) << 2) /**< PWM0 signal: PWM0_PWMC0_PWMH2 */
#define PIN_PA3C_PWM0_PWMC0_PWMH3                  _L_(3)       /**< PWM0 signal: PWM0_PWMC0_PWMH3 on PA3 mux C */
#define MUX_PA3C_PWM0_PWMC0_PWMH3                  _L_(2)       /**< PWM0 signal line function value: PWM0_PWMC0_PWMH3 */
#define PIO_PA3C_PWM0_PWMC0_PWMH3                  (_U_(1) << 3) /**< PWM0 signal: PWM0_PWMC0_PWMH3 */
#define PIN_PA4C_PWM0_PWMC0_PWML0                  _L_(4)       /**< PWM0 signal: PWM0_PWMC0_PWML0 on PA4 mux C */
#define MUX_PA4C_PWM0_PWMC0_PWML0                  _L_(2)       /**< PWM0 signal line function value: PWM0_PWMC0_PWML0 */
#define PIO_PA4C_PWM0_PWMC0_PWML0                  (_U_(1) << 4) /**< PWM0 signal: PWM0_PWMC0_PWML0 */
#define PIN_PA5C_PWM0_PWMC0_PWML1                  _L_(5)       /**< PWM0 signal: PWM0_PWMC0_PWML1 on PA5 mux C */
#define MUX_PA5C_PWM0_PWMC0_PWML1                  _L_(2)       /**< PWM0 signal line function value: PWM0_PWMC0_PWML1 */
#define PIO_PA5C_PWM0_PWMC0_PWML1                  (_U_(1) << 5) /**< PWM0 signal: PWM0_PWMC0_PWML1 */
#define PIN_PA6C_PWM0_PWMC0_PWML2                  _L_(6)       /**< PWM0 signal: PWM0_PWMC0_PWML2 on PA6 mux C */
#define MUX_PA6C_PWM0_PWMC0_PWML2                  _L_(2)       /**< PWM0 signal line function value: PWM0_PWMC0_PWML2 */
#define PIO_PA6C_PWM0_PWMC0_PWML2                  (_U_(1) << 6) /**< PWM0 signal: PWM0_PWMC0_PWML2 */
#define PIN_PA7C_PWM0_PWMC0_PWML3                  _L_(7)       /**< PWM0 signal: PWM0_PWMC0_PWML3 on PA7 mux C */
#define MUX_PA7C_PWM0_PWMC0_PWML3                  _L_(2)       /**< PWM0 signal line function value: PWM0_PWMC0_PWML3 */
#define PIO_PA7C_PWM0_PWMC0_PWML3                  (_U_(1) << 7) /**< PWM0 signal: PWM0_PWMC0_PWML3 */
/* ========== PIO definition for PWM1 peripheral ========== */
#define PIN_PB17A_PWM1_PWMC1_PWMEXTRG0             _L_(49)      /**< PWM1 signal: PWM1_PWMC1_PWMEXTRG0 on PB17 mux A */
#define MUX_PB17A_PWM1_PWMC1_PWMEXTRG0             _L_(0)       /**< PWM1 signal line function value: PWM1_PWMC1_PWMEXTRG0 */
#define PIO_PB17A_PWM1_PWMC1_PWMEXTRG0             (_U_(1) << 17) /**< PWM1 signal: PWM1_PWMC1_PWMEXTRG0 */
#define PIN_PB18A_PWM1_PWMC1_PWMEXTRG1             _L_(50)      /**< PWM1 signal: PWM1_PWMC1_PWMEXTRG1 on PB18 mux A */
#define MUX_PB18A_PWM1_PWMC1_PWMEXTRG1             _L_(0)       /**< PWM1 signal line function value: PWM1_PWMC1_PWMEXTRG1 */
#define PIO_PB18A_PWM1_PWMC1_PWMEXTRG1             (_U_(1) << 18) /**< PWM1 signal: PWM1_PWMC1_PWMEXTRG1 */
#define PIN_PB27A_PWM1_PWMC1_PWMFI0                _L_(59)      /**< PWM1 signal: PWM1_PWMC1_PWMFI0 on PB27 mux A */
#define MUX_PB27A_PWM1_PWMC1_PWMFI0                _L_(0)       /**< PWM1 signal line function value: PWM1_PWMC1_PWMFI0 */
#define PIO_PB27A_PWM1_PWMC1_PWMFI0                (_U_(1) << 27) /**< PWM1 signal: PWM1_PWMC1_PWMFI0 */
#define PIN_PB28A_PWM1_PWMC1_PWMFI1                _L_(60)      /**< PWM1 signal: PWM1_PWMC1_PWMFI1 on PB28 mux A */
#define MUX_PB28A_PWM1_PWMC1_PWMFI1                _L_(0)       /**< PWM1 signal line function value: PWM1_PWMC1_PWMFI1 */
#define PIO_PB28A_PWM1_PWMC1_PWMFI1                (_U_(1) << 28) /**< PWM1 signal: PWM1_PWMC1_PWMFI1 */
#define PIN_PB29A_PWM1_PWMC1_PWMFI2                _L_(61)      /**< PWM1 signal: PWM1_PWMC1_PWMFI2 on PB29 mux A */
#define MUX_PB29A_PWM1_PWMC1_PWMFI2                _L_(0)       /**< PWM1 signal line function value: PWM1_PWMC1_PWMFI2 */
#define PIO_PB29A_PWM1_PWMC1_PWMFI2                (_U_(1) << 29) /**< PWM1 signal: PWM1_PWMC1_PWMFI2 */
#define PIN_PB19A_PWM1_PWMC1_PWMH0                 _L_(51)      /**< PWM1 signal: PWM1_PWMC1_PWMH0 on PB19 mux A */
#define MUX_PB19A_PWM1_PWMC1_PWMH0                 _L_(0)       /**< PWM1 signal line function value: PWM1_PWMC1_PWMH0 */
#define PIO_PB19A_PWM1_PWMC1_PWMH0                 (_U_(1) << 19) /**< PWM1 signal: PWM1_PWMC1_PWMH0 */
#define PIN_PB20A_PWM1_PWMC1_PWMH1                 _L_(52)      /**< PWM1 signal: PWM1_PWMC1_PWMH1 on PB20 mux A */
#define MUX_PB20A_PWM1_PWMC1_PWMH1                 _L_(0)       /**< PWM1 signal line function value: PWM1_PWMC1_PWMH1 */
#define PIO_PB20A_PWM1_PWMC1_PWMH1                 (_U_(1) << 20) /**< PWM1 signal: PWM1_PWMC1_PWMH1 */
#define PIN_PB21A_PWM1_PWMC1_PWMH2                 _L_(53)      /**< PWM1 signal: PWM1_PWMC1_PWMH2 on PB21 mux A */
#define MUX_PB21A_PWM1_PWMC1_PWMH2                 _L_(0)       /**< PWM1 signal line function value: PWM1_PWMC1_PWMH2 */
#define PIO_PB21A_PWM1_PWMC1_PWMH2                 (_U_(1) << 21) /**< PWM1 signal: PWM1_PWMC1_PWMH2 */
#define PIN_PB22A_PWM1_PWMC1_PWMH3                 _L_(54)      /**< PWM1 signal: PWM1_PWMC1_PWMH3 on PB22 mux A */
#define MUX_PB22A_PWM1_PWMC1_PWMH3                 _L_(0)       /**< PWM1 signal line function value: PWM1_PWMC1_PWMH3 */
#define PIO_PB22A_PWM1_PWMC1_PWMH3                 (_U_(1) << 22) /**< PWM1 signal: PWM1_PWMC1_PWMH3 */
#define PIN_PB23A_PWM1_PWMC1_PWML0                 _L_(55)      /**< PWM1 signal: PWM1_PWMC1_PWML0 on PB23 mux A */
#define MUX_PB23A_PWM1_PWMC1_PWML0                 _L_(0)       /**< PWM1 signal line function value: PWM1_PWMC1_PWML0 */
#define PIO_PB23A_PWM1_PWMC1_PWML0                 (_U_(1) << 23) /**< PWM1 signal: PWM1_PWMC1_PWML0 */
#define PIN_PB24A_PWM1_PWMC1_PWML1                 _L_(56)      /**< PWM1 signal: PWM1_PWMC1_PWML1 on PB24 mux A */
#define MUX_PB24A_PWM1_PWMC1_PWML1                 _L_(0)       /**< PWM1 signal line function value: PWM1_PWMC1_PWML1 */
#define PIO_PB24A_PWM1_PWMC1_PWML1                 (_U_(1) << 24) /**< PWM1 signal: PWM1_PWMC1_PWML1 */
#define PIN_PB25A_PWM1_PWMC1_PWML2                 _L_(57)      /**< PWM1 signal: PWM1_PWMC1_PWML2 on PB25 mux A */
#define MUX_PB25A_PWM1_PWMC1_PWML2                 _L_(0)       /**< PWM1 signal line function value: PWM1_PWMC1_PWML2 */
#define PIO_PB25A_PWM1_PWMC1_PWML2                 (_U_(1) << 25) /**< PWM1 signal: PWM1_PWMC1_PWML2 */
#define PIN_PB26A_PWM1_PWMC1_PWML3                 _L_(58)      /**< PWM1 signal: PWM1_PWMC1_PWML3 on PB26 mux A */
#define MUX_PB26A_PWM1_PWMC1_PWML3                 _L_(0)       /**< PWM1 signal line function value: PWM1_PWMC1_PWML3 */
#define PIO_PB26A_PWM1_PWMC1_PWML3                 (_U_(1) << 26) /**< PWM1 signal: PWM1_PWMC1_PWML3 */
/* ========== PIO definition for QSPI peripheral ========== */
#define PIN_PA22C_QSPI_QCS                         _L_(22)      /**< QSPI signal: QSPI_QCS on PA22 mux C */
#define MUX_PA22C_QSPI_QCS                         _L_(2)       /**< QSPI signal line function value: QSPI_QCS */
#define PIO_PA22C_QSPI_QCS                         (_U_(1) << 22) /**< QSPI signal: QSPI_QCS */
#define PIN_PA24C_QSPI_QIO0                        _L_(24)      /**< QSPI signal: QSPI_QIO0 on PA24 mux C */
#define MUX_PA24C_QSPI_QIO0                        _L_(2)       /**< QSPI signal line function value: QSPI_QIO0 */
#define PIO_PA24C_QSPI_QIO0                        (_U_(1) << 24) /**< QSPI signal: QSPI_QIO0 */
#define PIN_PA23C_QSPI_QIO1                        _L_(23)      /**< QSPI signal: QSPI_QIO1 on PA23 mux C */
#define MUX_PA23C_QSPI_QIO1                        _L_(2)       /**< QSPI signal line function value: QSPI_QIO1 */
#define PIO_PA23C_QSPI_QIO1                        (_U_(1) << 23) /**< QSPI signal: QSPI_QIO1 */
#define PIN_PA20C_QSPI_QIO2                        _L_(20)      /**< QSPI signal: QSPI_QIO2 on PA20 mux C */
#define MUX_PA20C_QSPI_QIO2                        _L_(2)       /**< QSPI signal line function value: QSPI_QIO2 */
#define PIO_PA20C_QSPI_QIO2                        (_U_(1) << 20) /**< QSPI signal: QSPI_QIO2 */
#define PIN_PA19C_QSPI_QIO3                        _L_(19)      /**< QSPI signal: QSPI_QIO3 on PA19 mux C */
#define MUX_PA19C_QSPI_QIO3                        _L_(2)       /**< QSPI signal line function value: QSPI_QIO3 */
#define PIO_PA19C_QSPI_QIO3                        (_U_(1) << 19) /**< QSPI signal: QSPI_QIO3 */
#define PIN_PA21C_QSPI_QSCK                        _L_(21)      /**< QSPI signal: QSPI_QSCK on PA21 mux C */
#define MUX_PA21C_QSPI_QSCK                        _L_(2)       /**< QSPI signal line function value: QSPI_QSCK */
#define PIO_PA21C_QSPI_QSCK                        (_U_(1) << 21) /**< QSPI signal: QSPI_QSCK */
/* ========== PIO definition for RTC peripheral ========== */
#define PIN_PG30A_RTC_RTCOUT0                      _L_(222)     /**< RTC signal: RTC_RTCOUT0 on PG30 mux A */
#define MUX_PG30A_RTC_RTCOUT0                      _L_(0)       /**< RTC signal line function value: RTC_RTCOUT0 */
#define PIO_PG30A_RTC_RTCOUT0                      (_U_(1) << 30) /**< RTC signal: RTC_RTCOUT0 */
#define PIN_PG31A_RTC_RTCOUT1                      _L_(223)     /**< RTC signal: RTC_RTCOUT1 on PG31 mux A */
#define MUX_PG31A_RTC_RTCOUT1                      _L_(0)       /**< RTC signal line function value: RTC_RTCOUT1 */
#define PIO_PG31A_RTC_RTCOUT1                      (_U_(1) << 31) /**< RTC signal: RTC_RTCOUT1 */
/* ========== PIO definition for TC0 peripheral ========== */
#define PIN_PA0B_TC0_TCLK0                         _L_(0)       /**< TC0 signal: TC0_TCLK0 on PA0 mux B */
#define MUX_PA0B_TC0_TCLK0                         _L_(1)       /**< TC0 signal line function value: TC0_TCLK0 */
#define PIO_PA0B_TC0_TCLK0                         (_U_(1) << 0) /**< TC0 signal: TC0_TCLK0 */
#define PIN_PA3B_TC0_TCLK1                         _L_(3)       /**< TC0 signal: TC0_TCLK1 on PA3 mux B */
#define MUX_PA3B_TC0_TCLK1                         _L_(1)       /**< TC0 signal line function value: TC0_TCLK1 */
#define PIO_PA3B_TC0_TCLK1                         (_U_(1) << 3) /**< TC0 signal: TC0_TCLK1 */
#define PIN_PA6B_TC0_TCLK2                         _L_(6)       /**< TC0 signal: TC0_TCLK2 on PA6 mux B */
#define MUX_PA6B_TC0_TCLK2                         _L_(1)       /**< TC0 signal line function value: TC0_TCLK2 */
#define PIO_PA6B_TC0_TCLK2                         (_U_(1) << 6) /**< TC0 signal: TC0_TCLK2 */
#define PIN_PA1B_TC0_TIOA0                         _L_(1)       /**< TC0 signal: TC0_TIOA0 on PA1 mux B */
#define MUX_PA1B_TC0_TIOA0                         _L_(1)       /**< TC0 signal line function value: TC0_TIOA0 */
#define PIO_PA1B_TC0_TIOA0                         (_U_(1) << 1) /**< TC0 signal: TC0_TIOA0 */
#define PIN_PA4B_TC0_TIOA1                         _L_(4)       /**< TC0 signal: TC0_TIOA1 on PA4 mux B */
#define MUX_PA4B_TC0_TIOA1                         _L_(1)       /**< TC0 signal line function value: TC0_TIOA1 */
#define PIO_PA4B_TC0_TIOA1                         (_U_(1) << 4) /**< TC0 signal: TC0_TIOA1 */
#define PIN_PA7B_TC0_TIOA2                         _L_(7)       /**< TC0 signal: TC0_TIOA2 on PA7 mux B */
#define MUX_PA7B_TC0_TIOA2                         _L_(1)       /**< TC0 signal line function value: TC0_TIOA2 */
#define PIO_PA7B_TC0_TIOA2                         (_U_(1) << 7) /**< TC0 signal: TC0_TIOA2 */
#define PIN_PA2B_TC0_TIOB0                         _L_(2)       /**< TC0 signal: TC0_TIOB0 on PA2 mux B */
#define MUX_PA2B_TC0_TIOB0                         _L_(1)       /**< TC0 signal line function value: TC0_TIOB0 */
#define PIO_PA2B_TC0_TIOB0                         (_U_(1) << 2) /**< TC0 signal: TC0_TIOB0 */
#define PIN_PA5B_TC0_TIOB1                         _L_(5)       /**< TC0 signal: TC0_TIOB1 on PA5 mux B */
#define MUX_PA5B_TC0_TIOB1                         _L_(1)       /**< TC0 signal line function value: TC0_TIOB1 */
#define PIO_PA5B_TC0_TIOB1                         (_U_(1) << 5) /**< TC0 signal: TC0_TIOB1 */
#define PIN_PA8B_TC0_TIOB2                         _L_(8)       /**< TC0 signal: TC0_TIOB2 on PA8 mux B */
#define MUX_PA8B_TC0_TIOB2                         _L_(1)       /**< TC0 signal line function value: TC0_TIOB2 */
#define PIO_PA8B_TC0_TIOB2                         (_U_(1) << 8) /**< TC0 signal: TC0_TIOB2 */
/* ========== PIO definition for TC1 peripheral ========== */
#define PIN_PB8A_TC1_TCLK3                         _L_(40)      /**< TC1 signal: TC1_TCLK3 on PB8 mux A */
#define MUX_PB8A_TC1_TCLK3                         _L_(0)       /**< TC1 signal line function value: TC1_TCLK3 */
#define PIO_PB8A_TC1_TCLK3                         (_U_(1) << 8) /**< TC1 signal: TC1_TCLK3 */
#define PIN_PB11A_TC1_TCLK4                        _L_(43)      /**< TC1 signal: TC1_TCLK4 on PB11 mux A */
#define MUX_PB11A_TC1_TCLK4                        _L_(0)       /**< TC1 signal line function value: TC1_TCLK4 */
#define PIO_PB11A_TC1_TCLK4                        (_U_(1) << 11) /**< TC1 signal: TC1_TCLK4 */
#define PIN_PB14A_TC1_TCLK5                        _L_(46)      /**< TC1 signal: TC1_TCLK5 on PB14 mux A */
#define MUX_PB14A_TC1_TCLK5                        _L_(0)       /**< TC1 signal line function value: TC1_TCLK5 */
#define PIO_PB14A_TC1_TCLK5                        (_U_(1) << 14) /**< TC1 signal: TC1_TCLK5 */
#define PIN_PB9A_TC1_TIOA3                         _L_(41)      /**< TC1 signal: TC1_TIOA3 on PB9 mux A */
#define MUX_PB9A_TC1_TIOA3                         _L_(0)       /**< TC1 signal line function value: TC1_TIOA3 */
#define PIO_PB9A_TC1_TIOA3                         (_U_(1) << 9) /**< TC1 signal: TC1_TIOA3 */
#define PIN_PB12A_TC1_TIOA4                        _L_(44)      /**< TC1 signal: TC1_TIOA4 on PB12 mux A */
#define MUX_PB12A_TC1_TIOA4                        _L_(0)       /**< TC1 signal line function value: TC1_TIOA4 */
#define PIO_PB12A_TC1_TIOA4                        (_U_(1) << 12) /**< TC1 signal: TC1_TIOA4 */
#define PIN_PB15A_TC1_TIOA5                        _L_(47)      /**< TC1 signal: TC1_TIOA5 on PB15 mux A */
#define MUX_PB15A_TC1_TIOA5                        _L_(0)       /**< TC1 signal line function value: TC1_TIOA5 */
#define PIO_PB15A_TC1_TIOA5                        (_U_(1) << 15) /**< TC1 signal: TC1_TIOA5 */
#define PIN_PB10A_TC1_TIOB3                        _L_(42)      /**< TC1 signal: TC1_TIOB3 on PB10 mux A */
#define MUX_PB10A_TC1_TIOB3                        _L_(0)       /**< TC1 signal line function value: TC1_TIOB3 */
#define PIO_PB10A_TC1_TIOB3                        (_U_(1) << 10) /**< TC1 signal: TC1_TIOB3 */
#define PIN_PB13A_TC1_TIOB4                        _L_(45)      /**< TC1 signal: TC1_TIOB4 on PB13 mux A */
#define MUX_PB13A_TC1_TIOB4                        _L_(0)       /**< TC1 signal line function value: TC1_TIOB4 */
#define PIO_PB13A_TC1_TIOB4                        (_U_(1) << 13) /**< TC1 signal: TC1_TIOB4 */
#define PIN_PB16A_TC1_TIOB5                        _L_(48)      /**< TC1 signal: TC1_TIOB5 on PB16 mux A */
#define MUX_PB16A_TC1_TIOB5                        _L_(0)       /**< TC1 signal line function value: TC1_TIOB5 */
#define PIO_PB16A_TC1_TIOB5                        (_U_(1) << 16) /**< TC1 signal: TC1_TIOB5 */
/* ========== PIO definition for TC2 peripheral ========== */
#define PIN_PC11A_TC2_TCLK6                        _L_(75)      /**< TC2 signal: TC2_TCLK6 on PC11 mux A */
#define MUX_PC11A_TC2_TCLK6                        _L_(0)       /**< TC2 signal line function value: TC2_TCLK6 */
#define PIO_PC11A_TC2_TCLK6                        (_U_(1) << 11) /**< TC2 signal: TC2_TCLK6 */
#define PIN_PC14A_TC2_TCLK7                        _L_(78)      /**< TC2 signal: TC2_TCLK7 on PC14 mux A */
#define MUX_PC14A_TC2_TCLK7                        _L_(0)       /**< TC2 signal line function value: TC2_TCLK7 */
#define PIO_PC14A_TC2_TCLK7                        (_U_(1) << 14) /**< TC2 signal: TC2_TCLK7 */
#define PIN_PC17A_TC2_TCLK8                        _L_(81)      /**< TC2 signal: TC2_TCLK8 on PC17 mux A */
#define MUX_PC17A_TC2_TCLK8                        _L_(0)       /**< TC2 signal line function value: TC2_TCLK8 */
#define PIO_PC17A_TC2_TCLK8                        (_U_(1) << 17) /**< TC2 signal: TC2_TCLK8 */
#define PIN_PC12A_TC2_TIOA6                        _L_(76)      /**< TC2 signal: TC2_TIOA6 on PC12 mux A */
#define MUX_PC12A_TC2_TIOA6                        _L_(0)       /**< TC2 signal line function value: TC2_TIOA6 */
#define PIO_PC12A_TC2_TIOA6                        (_U_(1) << 12) /**< TC2 signal: TC2_TIOA6 */
#define PIN_PC15A_TC2_TIOA7                        _L_(79)      /**< TC2 signal: TC2_TIOA7 on PC15 mux A */
#define MUX_PC15A_TC2_TIOA7                        _L_(0)       /**< TC2 signal line function value: TC2_TIOA7 */
#define PIO_PC15A_TC2_TIOA7                        (_U_(1) << 15) /**< TC2 signal: TC2_TIOA7 */
#define PIN_PC18A_TC2_TIOA8                        _L_(82)      /**< TC2 signal: TC2_TIOA8 on PC18 mux A */
#define MUX_PC18A_TC2_TIOA8                        _L_(0)       /**< TC2 signal line function value: TC2_TIOA8 */
#define PIO_PC18A_TC2_TIOA8                        (_U_(1) << 18) /**< TC2 signal: TC2_TIOA8 */
#define PIN_PC13A_TC2_TIOB6                        _L_(77)      /**< TC2 signal: TC2_TIOB6 on PC13 mux A */
#define MUX_PC13A_TC2_TIOB6                        _L_(0)       /**< TC2 signal line function value: TC2_TIOB6 */
#define PIO_PC13A_TC2_TIOB6                        (_U_(1) << 13) /**< TC2 signal: TC2_TIOB6 */
#define PIN_PC16A_TC2_TIOB7                        _L_(80)      /**< TC2 signal: TC2_TIOB7 on PC16 mux A */
#define MUX_PC16A_TC2_TIOB7                        _L_(0)       /**< TC2 signal line function value: TC2_TIOB7 */
#define PIO_PC16A_TC2_TIOB7                        (_U_(1) << 16) /**< TC2 signal: TC2_TIOB7 */
#define PIN_PC19A_TC2_TIOB8                        _L_(83)      /**< TC2 signal: TC2_TIOB8 on PC19 mux A */
#define MUX_PC19A_TC2_TIOB8                        _L_(0)       /**< TC2 signal line function value: TC2_TIOB8 */
#define PIO_PC19A_TC2_TIOB8                        (_U_(1) << 19) /**< TC2 signal: TC2_TIOB8 */
/* ========== PIO definition for TC3 peripheral ========== */
#define PIN_PC21D_TC3_TCLK9                        _L_(85)      /**< TC3 signal: TC3_TCLK9 on PC21 mux D */
#define MUX_PC21D_TC3_TCLK9                        _L_(3)       /**< TC3 signal line function value: TC3_TCLK9 */
#define PIO_PC21D_TC3_TCLK9                        (_U_(1) << 21) /**< TC3 signal: TC3_TCLK9 */
#define PIN_PC28D_TC3_TCLK10                       _L_(92)      /**< TC3 signal: TC3_TCLK10 on PC28 mux D */
#define MUX_PC28D_TC3_TCLK10                       _L_(3)       /**< TC3 signal line function value: TC3_TCLK10 */
#define PIO_PC28D_TC3_TCLK10                       (_U_(1) << 28) /**< TC3 signal: TC3_TCLK10 */
#define PIN_PC25D_TC3_TCLK11                       _L_(89)      /**< TC3 signal: TC3_TCLK11 on PC25 mux D */
#define MUX_PC25D_TC3_TCLK11                       _L_(3)       /**< TC3 signal line function value: TC3_TCLK11 */
#define PIO_PC25D_TC3_TCLK11                       (_U_(1) << 25) /**< TC3 signal: TC3_TCLK11 */
#define PIN_PC22D_TC3_TIOA9                        _L_(86)      /**< TC3 signal: TC3_TIOA9 on PC22 mux D */
#define MUX_PC22D_TC3_TIOA9                        _L_(3)       /**< TC3 signal line function value: TC3_TIOA9 */
#define PIO_PC22D_TC3_TIOA9                        (_U_(1) << 22) /**< TC3 signal: TC3_TIOA9 */
#define PIN_PC29D_TC3_TIOA10                       _L_(93)      /**< TC3 signal: TC3_TIOA10 on PC29 mux D */
#define MUX_PC29D_TC3_TIOA10                       _L_(3)       /**< TC3 signal line function value: TC3_TIOA10 */
#define PIO_PC29D_TC3_TIOA10                       (_U_(1) << 29) /**< TC3 signal: TC3_TIOA10 */
#define PIN_PC26D_TC3_TIOA11                       _L_(90)      /**< TC3 signal: TC3_TIOA11 on PC26 mux D */
#define MUX_PC26D_TC3_TIOA11                       _L_(3)       /**< TC3 signal line function value: TC3_TIOA11 */
#define PIO_PC26D_TC3_TIOA11                       (_U_(1) << 26) /**< TC3 signal: TC3_TIOA11 */
#define PIN_PC24D_TC3_TIOB9                        _L_(88)      /**< TC3 signal: TC3_TIOB9 on PC24 mux D */
#define MUX_PC24D_TC3_TIOB9                        _L_(3)       /**< TC3 signal line function value: TC3_TIOB9 */
#define PIO_PC24D_TC3_TIOB9                        (_U_(1) << 24) /**< TC3 signal: TC3_TIOB9 */
#define PIN_PC30D_TC3_TIOB10                       _L_(94)      /**< TC3 signal: TC3_TIOB10 on PC30 mux D */
#define MUX_PC30D_TC3_TIOB10                       _L_(3)       /**< TC3 signal line function value: TC3_TIOB10 */
#define PIO_PC30D_TC3_TIOB10                       (_U_(1) << 30) /**< TC3 signal: TC3_TIOB10 */
#define PIN_PC27D_TC3_TIOB11                       _L_(91)      /**< TC3 signal: TC3_TIOB11 on PC27 mux D */
#define MUX_PC27D_TC3_TIOB11                       _L_(3)       /**< TC3 signal line function value: TC3_TIOB11 */
#define PIO_PC27D_TC3_TIOB11                       (_U_(1) << 27) /**< TC3 signal: TC3_TIOB11 */

#endif /* _SAMRH71F20C_GPIO_H_ */

