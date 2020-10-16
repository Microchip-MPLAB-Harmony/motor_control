/**
 * \brief Component description for NMIC
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
#ifndef _SAMRH71_NMIC_COMPONENT_H_
#define _SAMRH71_NMIC_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR NMIC                                         */
/* ************************************************************************** */

/* -------- NMIC_IER : (NMIC Offset: 0x00) ( /W 32) Interrupt Enable Register -------- */
#define NMIC_IER_NMI0_Pos                     _U_(0)                                               /**< (NMIC_IER) Non-maskable Interrupt 0 Enable Position */
#define NMIC_IER_NMI0_Msk                     (_U_(0x1) << NMIC_IER_NMI0_Pos)                      /**< (NMIC_IER) Non-maskable Interrupt 0 Enable Mask */
#define NMIC_IER_NMI0(value)                  (NMIC_IER_NMI0_Msk & ((value) << NMIC_IER_NMI0_Pos))
#define NMIC_IER_NMI1_Pos                     _U_(1)                                               /**< (NMIC_IER) Non-maskable Interrupt 1 Enable Position */
#define NMIC_IER_NMI1_Msk                     (_U_(0x1) << NMIC_IER_NMI1_Pos)                      /**< (NMIC_IER) Non-maskable Interrupt 1 Enable Mask */
#define NMIC_IER_NMI1(value)                  (NMIC_IER_NMI1_Msk & ((value) << NMIC_IER_NMI1_Pos))
#define NMIC_IER_NMI2_Pos                     _U_(2)                                               /**< (NMIC_IER) Non-maskable Interrupt 2 Enable Position */
#define NMIC_IER_NMI2_Msk                     (_U_(0x1) << NMIC_IER_NMI2_Pos)                      /**< (NMIC_IER) Non-maskable Interrupt 2 Enable Mask */
#define NMIC_IER_NMI2(value)                  (NMIC_IER_NMI2_Msk & ((value) << NMIC_IER_NMI2_Pos))
#define NMIC_IER_NMI3_Pos                     _U_(3)                                               /**< (NMIC_IER) Non-maskable Interrupt 3 Enable Position */
#define NMIC_IER_NMI3_Msk                     (_U_(0x1) << NMIC_IER_NMI3_Pos)                      /**< (NMIC_IER) Non-maskable Interrupt 3 Enable Mask */
#define NMIC_IER_NMI3(value)                  (NMIC_IER_NMI3_Msk & ((value) << NMIC_IER_NMI3_Pos))
#define NMIC_IER_NMI4_Pos                     _U_(4)                                               /**< (NMIC_IER) Non-maskable Interrupt 4 Enable Position */
#define NMIC_IER_NMI4_Msk                     (_U_(0x1) << NMIC_IER_NMI4_Pos)                      /**< (NMIC_IER) Non-maskable Interrupt 4 Enable Mask */
#define NMIC_IER_NMI4(value)                  (NMIC_IER_NMI4_Msk & ((value) << NMIC_IER_NMI4_Pos))
#define NMIC_IER_NMI5_Pos                     _U_(5)                                               /**< (NMIC_IER) Non-maskable Interrupt 5 Enable Position */
#define NMIC_IER_NMI5_Msk                     (_U_(0x1) << NMIC_IER_NMI5_Pos)                      /**< (NMIC_IER) Non-maskable Interrupt 5 Enable Mask */
#define NMIC_IER_NMI5(value)                  (NMIC_IER_NMI5_Msk & ((value) << NMIC_IER_NMI5_Pos))
#define NMIC_IER_NMI6_Pos                     _U_(6)                                               /**< (NMIC_IER) Non-maskable Interrupt 6 Enable Position */
#define NMIC_IER_NMI6_Msk                     (_U_(0x1) << NMIC_IER_NMI6_Pos)                      /**< (NMIC_IER) Non-maskable Interrupt 6 Enable Mask */
#define NMIC_IER_NMI6(value)                  (NMIC_IER_NMI6_Msk & ((value) << NMIC_IER_NMI6_Pos))
#define NMIC_IER_NMI7_Pos                     _U_(7)                                               /**< (NMIC_IER) Non-maskable Interrupt 7 Enable Position */
#define NMIC_IER_NMI7_Msk                     (_U_(0x1) << NMIC_IER_NMI7_Pos)                      /**< (NMIC_IER) Non-maskable Interrupt 7 Enable Mask */
#define NMIC_IER_NMI7(value)                  (NMIC_IER_NMI7_Msk & ((value) << NMIC_IER_NMI7_Pos))
#define NMIC_IER_NMI8_Pos                     _U_(8)                                               /**< (NMIC_IER) Non-maskable Interrupt 8 Enable Position */
#define NMIC_IER_NMI8_Msk                     (_U_(0x1) << NMIC_IER_NMI8_Pos)                      /**< (NMIC_IER) Non-maskable Interrupt 8 Enable Mask */
#define NMIC_IER_NMI8(value)                  (NMIC_IER_NMI8_Msk & ((value) << NMIC_IER_NMI8_Pos))
#define NMIC_IER_Msk                          _U_(0x000001FF)                                      /**< (NMIC_IER) Register Mask  */

#define NMIC_IER_NMI_Pos                      _U_(0)                                               /**< (NMIC_IER Position) Non-maskable Interrupt 8 Enable */
#define NMIC_IER_NMI_Msk                      (_U_(0x1FF) << NMIC_IER_NMI_Pos)                     /**< (NMIC_IER Mask) NMI */
#define NMIC_IER_NMI(value)                   (NMIC_IER_NMI_Msk & ((value) << NMIC_IER_NMI_Pos))   

/* -------- NMIC_IDR : (NMIC Offset: 0x04) ( /W 32) Interrupt Disable Register -------- */
#define NMIC_IDR_NMI0_Pos                     _U_(0)                                               /**< (NMIC_IDR) Non-maskable Interrupt 0 Disable Position */
#define NMIC_IDR_NMI0_Msk                     (_U_(0x1) << NMIC_IDR_NMI0_Pos)                      /**< (NMIC_IDR) Non-maskable Interrupt 0 Disable Mask */
#define NMIC_IDR_NMI0(value)                  (NMIC_IDR_NMI0_Msk & ((value) << NMIC_IDR_NMI0_Pos))
#define NMIC_IDR_NMI1_Pos                     _U_(1)                                               /**< (NMIC_IDR) Non-maskable Interrupt 1 Disable Position */
#define NMIC_IDR_NMI1_Msk                     (_U_(0x1) << NMIC_IDR_NMI1_Pos)                      /**< (NMIC_IDR) Non-maskable Interrupt 1 Disable Mask */
#define NMIC_IDR_NMI1(value)                  (NMIC_IDR_NMI1_Msk & ((value) << NMIC_IDR_NMI1_Pos))
#define NMIC_IDR_NMI2_Pos                     _U_(2)                                               /**< (NMIC_IDR) Non-maskable Interrupt 2 Disable Position */
#define NMIC_IDR_NMI2_Msk                     (_U_(0x1) << NMIC_IDR_NMI2_Pos)                      /**< (NMIC_IDR) Non-maskable Interrupt 2 Disable Mask */
#define NMIC_IDR_NMI2(value)                  (NMIC_IDR_NMI2_Msk & ((value) << NMIC_IDR_NMI2_Pos))
#define NMIC_IDR_NMI3_Pos                     _U_(3)                                               /**< (NMIC_IDR) Non-maskable Interrupt 3 Disable Position */
#define NMIC_IDR_NMI3_Msk                     (_U_(0x1) << NMIC_IDR_NMI3_Pos)                      /**< (NMIC_IDR) Non-maskable Interrupt 3 Disable Mask */
#define NMIC_IDR_NMI3(value)                  (NMIC_IDR_NMI3_Msk & ((value) << NMIC_IDR_NMI3_Pos))
#define NMIC_IDR_NMI4_Pos                     _U_(4)                                               /**< (NMIC_IDR) Non-maskable Interrupt 4 Disable Position */
#define NMIC_IDR_NMI4_Msk                     (_U_(0x1) << NMIC_IDR_NMI4_Pos)                      /**< (NMIC_IDR) Non-maskable Interrupt 4 Disable Mask */
#define NMIC_IDR_NMI4(value)                  (NMIC_IDR_NMI4_Msk & ((value) << NMIC_IDR_NMI4_Pos))
#define NMIC_IDR_NMI5_Pos                     _U_(5)                                               /**< (NMIC_IDR) Non-maskable Interrupt 5 Disable Position */
#define NMIC_IDR_NMI5_Msk                     (_U_(0x1) << NMIC_IDR_NMI5_Pos)                      /**< (NMIC_IDR) Non-maskable Interrupt 5 Disable Mask */
#define NMIC_IDR_NMI5(value)                  (NMIC_IDR_NMI5_Msk & ((value) << NMIC_IDR_NMI5_Pos))
#define NMIC_IDR_NMI6_Pos                     _U_(6)                                               /**< (NMIC_IDR) Non-maskable Interrupt 6 Disable Position */
#define NMIC_IDR_NMI6_Msk                     (_U_(0x1) << NMIC_IDR_NMI6_Pos)                      /**< (NMIC_IDR) Non-maskable Interrupt 6 Disable Mask */
#define NMIC_IDR_NMI6(value)                  (NMIC_IDR_NMI6_Msk & ((value) << NMIC_IDR_NMI6_Pos))
#define NMIC_IDR_NMI7_Pos                     _U_(7)                                               /**< (NMIC_IDR) Non-maskable Interrupt 7 Disable Position */
#define NMIC_IDR_NMI7_Msk                     (_U_(0x1) << NMIC_IDR_NMI7_Pos)                      /**< (NMIC_IDR) Non-maskable Interrupt 7 Disable Mask */
#define NMIC_IDR_NMI7(value)                  (NMIC_IDR_NMI7_Msk & ((value) << NMIC_IDR_NMI7_Pos))
#define NMIC_IDR_NMI8_Pos                     _U_(8)                                               /**< (NMIC_IDR) Non-maskable Interrupt 8 Disable Position */
#define NMIC_IDR_NMI8_Msk                     (_U_(0x1) << NMIC_IDR_NMI8_Pos)                      /**< (NMIC_IDR) Non-maskable Interrupt 8 Disable Mask */
#define NMIC_IDR_NMI8(value)                  (NMIC_IDR_NMI8_Msk & ((value) << NMIC_IDR_NMI8_Pos))
#define NMIC_IDR_Msk                          _U_(0x000001FF)                                      /**< (NMIC_IDR) Register Mask  */

#define NMIC_IDR_NMI_Pos                      _U_(0)                                               /**< (NMIC_IDR Position) Non-maskable Interrupt 8 Disable */
#define NMIC_IDR_NMI_Msk                      (_U_(0x1FF) << NMIC_IDR_NMI_Pos)                     /**< (NMIC_IDR Mask) NMI */
#define NMIC_IDR_NMI(value)                   (NMIC_IDR_NMI_Msk & ((value) << NMIC_IDR_NMI_Pos))   

/* -------- NMIC_IAR : (NMIC Offset: 0x08) ( R/ 32) Interrupt Active Register -------- */
#define NMIC_IAR_NMI0_Pos                     _U_(0)                                               /**< (NMIC_IAR) Active Interrupt 0 Position */
#define NMIC_IAR_NMI0_Msk                     (_U_(0x1) << NMIC_IAR_NMI0_Pos)                      /**< (NMIC_IAR) Active Interrupt 0 Mask */
#define NMIC_IAR_NMI0(value)                  (NMIC_IAR_NMI0_Msk & ((value) << NMIC_IAR_NMI0_Pos))
#define NMIC_IAR_NMI1_Pos                     _U_(1)                                               /**< (NMIC_IAR) Active Interrupt 1 Position */
#define NMIC_IAR_NMI1_Msk                     (_U_(0x1) << NMIC_IAR_NMI1_Pos)                      /**< (NMIC_IAR) Active Interrupt 1 Mask */
#define NMIC_IAR_NMI1(value)                  (NMIC_IAR_NMI1_Msk & ((value) << NMIC_IAR_NMI1_Pos))
#define NMIC_IAR_NMI2_Pos                     _U_(2)                                               /**< (NMIC_IAR) Active Interrupt 2 Position */
#define NMIC_IAR_NMI2_Msk                     (_U_(0x1) << NMIC_IAR_NMI2_Pos)                      /**< (NMIC_IAR) Active Interrupt 2 Mask */
#define NMIC_IAR_NMI2(value)                  (NMIC_IAR_NMI2_Msk & ((value) << NMIC_IAR_NMI2_Pos))
#define NMIC_IAR_NMI3_Pos                     _U_(3)                                               /**< (NMIC_IAR) Active Interrupt 3 Position */
#define NMIC_IAR_NMI3_Msk                     (_U_(0x1) << NMIC_IAR_NMI3_Pos)                      /**< (NMIC_IAR) Active Interrupt 3 Mask */
#define NMIC_IAR_NMI3(value)                  (NMIC_IAR_NMI3_Msk & ((value) << NMIC_IAR_NMI3_Pos))
#define NMIC_IAR_NMI4_Pos                     _U_(4)                                               /**< (NMIC_IAR) Active Interrupt 4 Position */
#define NMIC_IAR_NMI4_Msk                     (_U_(0x1) << NMIC_IAR_NMI4_Pos)                      /**< (NMIC_IAR) Active Interrupt 4 Mask */
#define NMIC_IAR_NMI4(value)                  (NMIC_IAR_NMI4_Msk & ((value) << NMIC_IAR_NMI4_Pos))
#define NMIC_IAR_NMI5_Pos                     _U_(5)                                               /**< (NMIC_IAR) Active Interrupt 5 Position */
#define NMIC_IAR_NMI5_Msk                     (_U_(0x1) << NMIC_IAR_NMI5_Pos)                      /**< (NMIC_IAR) Active Interrupt 5 Mask */
#define NMIC_IAR_NMI5(value)                  (NMIC_IAR_NMI5_Msk & ((value) << NMIC_IAR_NMI5_Pos))
#define NMIC_IAR_NMI6_Pos                     _U_(6)                                               /**< (NMIC_IAR) Active Interrupt 6 Position */
#define NMIC_IAR_NMI6_Msk                     (_U_(0x1) << NMIC_IAR_NMI6_Pos)                      /**< (NMIC_IAR) Active Interrupt 6 Mask */
#define NMIC_IAR_NMI6(value)                  (NMIC_IAR_NMI6_Msk & ((value) << NMIC_IAR_NMI6_Pos))
#define NMIC_IAR_NMI7_Pos                     _U_(7)                                               /**< (NMIC_IAR) Active Interrupt 7 Position */
#define NMIC_IAR_NMI7_Msk                     (_U_(0x1) << NMIC_IAR_NMI7_Pos)                      /**< (NMIC_IAR) Active Interrupt 7 Mask */
#define NMIC_IAR_NMI7(value)                  (NMIC_IAR_NMI7_Msk & ((value) << NMIC_IAR_NMI7_Pos))
#define NMIC_IAR_NMI8_Pos                     _U_(8)                                               /**< (NMIC_IAR) Active Interrupt 8 Position */
#define NMIC_IAR_NMI8_Msk                     (_U_(0x1) << NMIC_IAR_NMI8_Pos)                      /**< (NMIC_IAR) Active Interrupt 8 Mask */
#define NMIC_IAR_NMI8(value)                  (NMIC_IAR_NMI8_Msk & ((value) << NMIC_IAR_NMI8_Pos))
#define NMIC_IAR_Msk                          _U_(0x000001FF)                                      /**< (NMIC_IAR) Register Mask  */

#define NMIC_IAR_NMI_Pos                      _U_(0)                                               /**< (NMIC_IAR Position) Active Interrupt 8 */
#define NMIC_IAR_NMI_Msk                      (_U_(0x1FF) << NMIC_IAR_NMI_Pos)                     /**< (NMIC_IAR Mask) NMI */
#define NMIC_IAR_NMI(value)                   (NMIC_IAR_NMI_Msk & ((value) << NMIC_IAR_NMI_Pos))   

/* -------- NMIC_ISR : (NMIC Offset: 0x0C) ( R/ 32) Interrupt Status Register -------- */
#define NMIC_ISR_NMI0_Pos                     _U_(0)                                               /**< (NMIC_ISR) Non-maskable Interrupt Source 0 Pending (cleared on read) Position */
#define NMIC_ISR_NMI0_Msk                     (_U_(0x1) << NMIC_ISR_NMI0_Pos)                      /**< (NMIC_ISR) Non-maskable Interrupt Source 0 Pending (cleared on read) Mask */
#define NMIC_ISR_NMI0(value)                  (NMIC_ISR_NMI0_Msk & ((value) << NMIC_ISR_NMI0_Pos))
#define NMIC_ISR_NMI1_Pos                     _U_(1)                                               /**< (NMIC_ISR) Non-maskable Interrupt Source 1 Pending (cleared on read) Position */
#define NMIC_ISR_NMI1_Msk                     (_U_(0x1) << NMIC_ISR_NMI1_Pos)                      /**< (NMIC_ISR) Non-maskable Interrupt Source 1 Pending (cleared on read) Mask */
#define NMIC_ISR_NMI1(value)                  (NMIC_ISR_NMI1_Msk & ((value) << NMIC_ISR_NMI1_Pos))
#define NMIC_ISR_NMI2_Pos                     _U_(2)                                               /**< (NMIC_ISR) Non-maskable Interrupt Source 2 Pending (cleared on read) Position */
#define NMIC_ISR_NMI2_Msk                     (_U_(0x1) << NMIC_ISR_NMI2_Pos)                      /**< (NMIC_ISR) Non-maskable Interrupt Source 2 Pending (cleared on read) Mask */
#define NMIC_ISR_NMI2(value)                  (NMIC_ISR_NMI2_Msk & ((value) << NMIC_ISR_NMI2_Pos))
#define NMIC_ISR_NMI3_Pos                     _U_(3)                                               /**< (NMIC_ISR) Non-maskable Interrupt Source 3 Pending (cleared on read) Position */
#define NMIC_ISR_NMI3_Msk                     (_U_(0x1) << NMIC_ISR_NMI3_Pos)                      /**< (NMIC_ISR) Non-maskable Interrupt Source 3 Pending (cleared on read) Mask */
#define NMIC_ISR_NMI3(value)                  (NMIC_ISR_NMI3_Msk & ((value) << NMIC_ISR_NMI3_Pos))
#define NMIC_ISR_NMI4_Pos                     _U_(4)                                               /**< (NMIC_ISR) Non-maskable Interrupt Source 4 Pending (cleared on read) Position */
#define NMIC_ISR_NMI4_Msk                     (_U_(0x1) << NMIC_ISR_NMI4_Pos)                      /**< (NMIC_ISR) Non-maskable Interrupt Source 4 Pending (cleared on read) Mask */
#define NMIC_ISR_NMI4(value)                  (NMIC_ISR_NMI4_Msk & ((value) << NMIC_ISR_NMI4_Pos))
#define NMIC_ISR_NMI5_Pos                     _U_(5)                                               /**< (NMIC_ISR) Non-maskable Interrupt Source 5 Pending (cleared on read) Position */
#define NMIC_ISR_NMI5_Msk                     (_U_(0x1) << NMIC_ISR_NMI5_Pos)                      /**< (NMIC_ISR) Non-maskable Interrupt Source 5 Pending (cleared on read) Mask */
#define NMIC_ISR_NMI5(value)                  (NMIC_ISR_NMI5_Msk & ((value) << NMIC_ISR_NMI5_Pos))
#define NMIC_ISR_NMI6_Pos                     _U_(6)                                               /**< (NMIC_ISR) Non-maskable Interrupt Source 6 Pending (cleared on read) Position */
#define NMIC_ISR_NMI6_Msk                     (_U_(0x1) << NMIC_ISR_NMI6_Pos)                      /**< (NMIC_ISR) Non-maskable Interrupt Source 6 Pending (cleared on read) Mask */
#define NMIC_ISR_NMI6(value)                  (NMIC_ISR_NMI6_Msk & ((value) << NMIC_ISR_NMI6_Pos))
#define NMIC_ISR_NMI7_Pos                     _U_(7)                                               /**< (NMIC_ISR) Non-maskable Interrupt Source 7 Pending (cleared on read) Position */
#define NMIC_ISR_NMI7_Msk                     (_U_(0x1) << NMIC_ISR_NMI7_Pos)                      /**< (NMIC_ISR) Non-maskable Interrupt Source 7 Pending (cleared on read) Mask */
#define NMIC_ISR_NMI7(value)                  (NMIC_ISR_NMI7_Msk & ((value) << NMIC_ISR_NMI7_Pos))
#define NMIC_ISR_NMI8_Pos                     _U_(8)                                               /**< (NMIC_ISR) Non-maskable Interrupt Source 8 Pending (cleared on read) Position */
#define NMIC_ISR_NMI8_Msk                     (_U_(0x1) << NMIC_ISR_NMI8_Pos)                      /**< (NMIC_ISR) Non-maskable Interrupt Source 8 Pending (cleared on read) Mask */
#define NMIC_ISR_NMI8(value)                  (NMIC_ISR_NMI8_Msk & ((value) << NMIC_ISR_NMI8_Pos))
#define NMIC_ISR_NMI9_Pos                     _U_(9)                                               /**< (NMIC_ISR) Non-maskable Interrupt Source 9 Pending (cleared on read) Position */
#define NMIC_ISR_NMI9_Msk                     (_U_(0x1) << NMIC_ISR_NMI9_Pos)                      /**< (NMIC_ISR) Non-maskable Interrupt Source 9 Pending (cleared on read) Mask */
#define NMIC_ISR_NMI9(value)                  (NMIC_ISR_NMI9_Msk & ((value) << NMIC_ISR_NMI9_Pos))
#define NMIC_ISR_NMI10_Pos                    _U_(10)                                              /**< (NMIC_ISR) Non-maskable Interrupt Source 10 Pending (cleared on read) Position */
#define NMIC_ISR_NMI10_Msk                    (_U_(0x1) << NMIC_ISR_NMI10_Pos)                     /**< (NMIC_ISR) Non-maskable Interrupt Source 10 Pending (cleared on read) Mask */
#define NMIC_ISR_NMI10(value)                 (NMIC_ISR_NMI10_Msk & ((value) << NMIC_ISR_NMI10_Pos))
#define NMIC_ISR_NMI11_Pos                    _U_(11)                                              /**< (NMIC_ISR) Non-maskable Interrupt Source 11 Pending (cleared on read) Position */
#define NMIC_ISR_NMI11_Msk                    (_U_(0x1) << NMIC_ISR_NMI11_Pos)                     /**< (NMIC_ISR) Non-maskable Interrupt Source 11 Pending (cleared on read) Mask */
#define NMIC_ISR_NMI11(value)                 (NMIC_ISR_NMI11_Msk & ((value) << NMIC_ISR_NMI11_Pos))
#define NMIC_ISR_NMI12_Pos                    _U_(12)                                              /**< (NMIC_ISR) Non-maskable Interrupt Source 12 Pending (cleared on read) Position */
#define NMIC_ISR_NMI12_Msk                    (_U_(0x1) << NMIC_ISR_NMI12_Pos)                     /**< (NMIC_ISR) Non-maskable Interrupt Source 12 Pending (cleared on read) Mask */
#define NMIC_ISR_NMI12(value)                 (NMIC_ISR_NMI12_Msk & ((value) << NMIC_ISR_NMI12_Pos))
#define NMIC_ISR_NMI13_Pos                    _U_(13)                                              /**< (NMIC_ISR) Non-maskable Interrupt Source 13 Pending (cleared on read) Position */
#define NMIC_ISR_NMI13_Msk                    (_U_(0x1) << NMIC_ISR_NMI13_Pos)                     /**< (NMIC_ISR) Non-maskable Interrupt Source 13 Pending (cleared on read) Mask */
#define NMIC_ISR_NMI13(value)                 (NMIC_ISR_NMI13_Msk & ((value) << NMIC_ISR_NMI13_Pos))
#define NMIC_ISR_NMI14_Pos                    _U_(14)                                              /**< (NMIC_ISR) Non-maskable Interrupt Source 14 Pending (cleared on read) Position */
#define NMIC_ISR_NMI14_Msk                    (_U_(0x1) << NMIC_ISR_NMI14_Pos)                     /**< (NMIC_ISR) Non-maskable Interrupt Source 14 Pending (cleared on read) Mask */
#define NMIC_ISR_NMI14(value)                 (NMIC_ISR_NMI14_Msk & ((value) << NMIC_ISR_NMI14_Pos))
#define NMIC_ISR_NMI15_Pos                    _U_(15)                                              /**< (NMIC_ISR) Non-maskable Interrupt Source 15 Pending (cleared on read) Position */
#define NMIC_ISR_NMI15_Msk                    (_U_(0x1) << NMIC_ISR_NMI15_Pos)                     /**< (NMIC_ISR) Non-maskable Interrupt Source 15 Pending (cleared on read) Mask */
#define NMIC_ISR_NMI15(value)                 (NMIC_ISR_NMI15_Msk & ((value) << NMIC_ISR_NMI15_Pos))
#define NMIC_ISR_Msk                          _U_(0x0000FFFF)                                      /**< (NMIC_ISR) Register Mask  */

#define NMIC_ISR_NMI_Pos                      _U_(0)                                               /**< (NMIC_ISR Position) Non-maskable Interrupt Source x5 Pending (cleared on read) */
#define NMIC_ISR_NMI_Msk                      (_U_(0xFFFF) << NMIC_ISR_NMI_Pos)                    /**< (NMIC_ISR Mask) NMI */
#define NMIC_ISR_NMI(value)                   (NMIC_ISR_NMI_Msk & ((value) << NMIC_ISR_NMI_Pos))   

/* -------- NMIC_GFCS : (NMIC Offset: 0x10) ( R/ 32) Glitch Filter Configuration Status Register -------- */
#define NMIC_GFCS_RDY0_Pos                    _U_(0)                                               /**< (NMIC_GFCS) Filter 0 Configuration Ready Position */
#define NMIC_GFCS_RDY0_Msk                    (_U_(0x1) << NMIC_GFCS_RDY0_Pos)                     /**< (NMIC_GFCS) Filter 0 Configuration Ready Mask */
#define NMIC_GFCS_RDY0(value)                 (NMIC_GFCS_RDY0_Msk & ((value) << NMIC_GFCS_RDY0_Pos))
#define NMIC_GFCS_RDY1_Pos                    _U_(1)                                               /**< (NMIC_GFCS) Filter 1 Configuration Ready Position */
#define NMIC_GFCS_RDY1_Msk                    (_U_(0x1) << NMIC_GFCS_RDY1_Pos)                     /**< (NMIC_GFCS) Filter 1 Configuration Ready Mask */
#define NMIC_GFCS_RDY1(value)                 (NMIC_GFCS_RDY1_Msk & ((value) << NMIC_GFCS_RDY1_Pos))
#define NMIC_GFCS_RDY2_Pos                    _U_(2)                                               /**< (NMIC_GFCS) Filter 2 Configuration Ready Position */
#define NMIC_GFCS_RDY2_Msk                    (_U_(0x1) << NMIC_GFCS_RDY2_Pos)                     /**< (NMIC_GFCS) Filter 2 Configuration Ready Mask */
#define NMIC_GFCS_RDY2(value)                 (NMIC_GFCS_RDY2_Msk & ((value) << NMIC_GFCS_RDY2_Pos))
#define NMIC_GFCS_RDY3_Pos                    _U_(3)                                               /**< (NMIC_GFCS) Filter 3 Configuration Ready Position */
#define NMIC_GFCS_RDY3_Msk                    (_U_(0x1) << NMIC_GFCS_RDY3_Pos)                     /**< (NMIC_GFCS) Filter 3 Configuration Ready Mask */
#define NMIC_GFCS_RDY3(value)                 (NMIC_GFCS_RDY3_Msk & ((value) << NMIC_GFCS_RDY3_Pos))
#define NMIC_GFCS_RDY4_Pos                    _U_(4)                                               /**< (NMIC_GFCS) Filter 4 Configuration Ready Position */
#define NMIC_GFCS_RDY4_Msk                    (_U_(0x1) << NMIC_GFCS_RDY4_Pos)                     /**< (NMIC_GFCS) Filter 4 Configuration Ready Mask */
#define NMIC_GFCS_RDY4(value)                 (NMIC_GFCS_RDY4_Msk & ((value) << NMIC_GFCS_RDY4_Pos))
#define NMIC_GFCS_RDY5_Pos                    _U_(5)                                               /**< (NMIC_GFCS) Filter 5 Configuration Ready Position */
#define NMIC_GFCS_RDY5_Msk                    (_U_(0x1) << NMIC_GFCS_RDY5_Pos)                     /**< (NMIC_GFCS) Filter 5 Configuration Ready Mask */
#define NMIC_GFCS_RDY5(value)                 (NMIC_GFCS_RDY5_Msk & ((value) << NMIC_GFCS_RDY5_Pos))
#define NMIC_GFCS_RDY6_Pos                    _U_(6)                                               /**< (NMIC_GFCS) Filter 6 Configuration Ready Position */
#define NMIC_GFCS_RDY6_Msk                    (_U_(0x1) << NMIC_GFCS_RDY6_Pos)                     /**< (NMIC_GFCS) Filter 6 Configuration Ready Mask */
#define NMIC_GFCS_RDY6(value)                 (NMIC_GFCS_RDY6_Msk & ((value) << NMIC_GFCS_RDY6_Pos))
#define NMIC_GFCS_RDY7_Pos                    _U_(7)                                               /**< (NMIC_GFCS) Filter 7 Configuration Ready Position */
#define NMIC_GFCS_RDY7_Msk                    (_U_(0x1) << NMIC_GFCS_RDY7_Pos)                     /**< (NMIC_GFCS) Filter 7 Configuration Ready Mask */
#define NMIC_GFCS_RDY7(value)                 (NMIC_GFCS_RDY7_Msk & ((value) << NMIC_GFCS_RDY7_Pos))
#define NMIC_GFCS_RDY8_Pos                    _U_(8)                                               /**< (NMIC_GFCS) Filter 8 Configuration Ready Position */
#define NMIC_GFCS_RDY8_Msk                    (_U_(0x1) << NMIC_GFCS_RDY8_Pos)                     /**< (NMIC_GFCS) Filter 8 Configuration Ready Mask */
#define NMIC_GFCS_RDY8(value)                 (NMIC_GFCS_RDY8_Msk & ((value) << NMIC_GFCS_RDY8_Pos))
#define NMIC_GFCS_RDY9_Pos                    _U_(9)                                               /**< (NMIC_GFCS) Filter 9 Configuration Ready Position */
#define NMIC_GFCS_RDY9_Msk                    (_U_(0x1) << NMIC_GFCS_RDY9_Pos)                     /**< (NMIC_GFCS) Filter 9 Configuration Ready Mask */
#define NMIC_GFCS_RDY9(value)                 (NMIC_GFCS_RDY9_Msk & ((value) << NMIC_GFCS_RDY9_Pos))
#define NMIC_GFCS_RDY10_Pos                   _U_(10)                                              /**< (NMIC_GFCS) Filter 10 Configuration Ready Position */
#define NMIC_GFCS_RDY10_Msk                   (_U_(0x1) << NMIC_GFCS_RDY10_Pos)                    /**< (NMIC_GFCS) Filter 10 Configuration Ready Mask */
#define NMIC_GFCS_RDY10(value)                (NMIC_GFCS_RDY10_Msk & ((value) << NMIC_GFCS_RDY10_Pos))
#define NMIC_GFCS_RDY11_Pos                   _U_(11)                                              /**< (NMIC_GFCS) Filter 11 Configuration Ready Position */
#define NMIC_GFCS_RDY11_Msk                   (_U_(0x1) << NMIC_GFCS_RDY11_Pos)                    /**< (NMIC_GFCS) Filter 11 Configuration Ready Mask */
#define NMIC_GFCS_RDY11(value)                (NMIC_GFCS_RDY11_Msk & ((value) << NMIC_GFCS_RDY11_Pos))
#define NMIC_GFCS_RDY12_Pos                   _U_(12)                                              /**< (NMIC_GFCS) Filter 12 Configuration Ready Position */
#define NMIC_GFCS_RDY12_Msk                   (_U_(0x1) << NMIC_GFCS_RDY12_Pos)                    /**< (NMIC_GFCS) Filter 12 Configuration Ready Mask */
#define NMIC_GFCS_RDY12(value)                (NMIC_GFCS_RDY12_Msk & ((value) << NMIC_GFCS_RDY12_Pos))
#define NMIC_GFCS_RDY13_Pos                   _U_(13)                                              /**< (NMIC_GFCS) Filter 13 Configuration Ready Position */
#define NMIC_GFCS_RDY13_Msk                   (_U_(0x1) << NMIC_GFCS_RDY13_Pos)                    /**< (NMIC_GFCS) Filter 13 Configuration Ready Mask */
#define NMIC_GFCS_RDY13(value)                (NMIC_GFCS_RDY13_Msk & ((value) << NMIC_GFCS_RDY13_Pos))
#define NMIC_GFCS_RDY14_Pos                   _U_(14)                                              /**< (NMIC_GFCS) Filter 14 Configuration Ready Position */
#define NMIC_GFCS_RDY14_Msk                   (_U_(0x1) << NMIC_GFCS_RDY14_Pos)                    /**< (NMIC_GFCS) Filter 14 Configuration Ready Mask */
#define NMIC_GFCS_RDY14(value)                (NMIC_GFCS_RDY14_Msk & ((value) << NMIC_GFCS_RDY14_Pos))
#define NMIC_GFCS_RDY15_Pos                   _U_(15)                                              /**< (NMIC_GFCS) Filter 15 Configuration Ready Position */
#define NMIC_GFCS_RDY15_Msk                   (_U_(0x1) << NMIC_GFCS_RDY15_Pos)                    /**< (NMIC_GFCS) Filter 15 Configuration Ready Mask */
#define NMIC_GFCS_RDY15(value)                (NMIC_GFCS_RDY15_Msk & ((value) << NMIC_GFCS_RDY15_Pos))
#define NMIC_GFCS_Msk                         _U_(0x0000FFFF)                                      /**< (NMIC_GFCS) Register Mask  */

#define NMIC_GFCS_RDY_Pos                     _U_(0)                                               /**< (NMIC_GFCS Position) Filter x5 Configuration Ready */
#define NMIC_GFCS_RDY_Msk                     (_U_(0xFFFF) << NMIC_GFCS_RDY_Pos)                   /**< (NMIC_GFCS Mask) RDY */
#define NMIC_GFCS_RDY(value)                  (NMIC_GFCS_RDY_Msk & ((value) << NMIC_GFCS_RDY_Pos)) 

/* -------- NMIC_SCFGxR0 : (NMIC Offset: 0x14) (R/W 32) Source Configuration Register 0 0 -------- */
#define NMIC_SCFGxR0_GFSEL_Pos                _U_(0)                                               /**< (NMIC_SCFGxR0) Glitch Filter Selector (GFSEL field is read-only in NMIC_SCFG0 to 8) Position */
#define NMIC_SCFGxR0_GFSEL_Msk                (_U_(0x3) << NMIC_SCFGxR0_GFSEL_Pos)                 /**< (NMIC_SCFGxR0) Glitch Filter Selector (GFSEL field is read-only in NMIC_SCFG0 to 8) Mask */
#define NMIC_SCFGxR0_GFSEL(value)             (NMIC_SCFGxR0_GFSEL_Msk & ((value) << NMIC_SCFGxR0_GFSEL_Pos))
#define NMIC_SCFGxR0_GFEN_Pos                 _U_(4)                                               /**< (NMIC_SCFGxR0) Glitch Filter Enable (GFEN bit is read-only in NMIC_SCFG0 to 8) Position */
#define NMIC_SCFGxR0_GFEN_Msk                 (_U_(0x1) << NMIC_SCFGxR0_GFEN_Pos)                  /**< (NMIC_SCFGxR0) Glitch Filter Enable (GFEN bit is read-only in NMIC_SCFG0 to 8) Mask */
#define NMIC_SCFGxR0_GFEN(value)              (NMIC_SCFGxR0_GFEN_Msk & ((value) << NMIC_SCFGxR0_GFEN_Pos))
#define NMIC_SCFGxR0_POL_Pos                  _U_(8)                                               /**< (NMIC_SCFGxR0) Polarity (POL bit is read-only in NMIC_SCFG0 to 8) Position */
#define NMIC_SCFGxR0_POL_Msk                  (_U_(0x1) << NMIC_SCFGxR0_POL_Pos)                   /**< (NMIC_SCFGxR0) Polarity (POL bit is read-only in NMIC_SCFG0 to 8) Mask */
#define NMIC_SCFGxR0_POL(value)               (NMIC_SCFGxR0_POL_Msk & ((value) << NMIC_SCFGxR0_POL_Pos))
#define NMIC_SCFGxR0_LVL_Pos                  _U_(9)                                               /**< (NMIC_SCFGxR0) Level Detection (LVL bit is read-only in NMIC_SCFG0 to 8) Position */
#define NMIC_SCFGxR0_LVL_Msk                  (_U_(0x1) << NMIC_SCFGxR0_LVL_Pos)                   /**< (NMIC_SCFGxR0) Level Detection (LVL bit is read-only in NMIC_SCFG0 to 8) Mask */
#define NMIC_SCFGxR0_LVL(value)               (NMIC_SCFGxR0_LVL_Msk & ((value) << NMIC_SCFGxR0_LVL_Pos))
#define NMIC_SCFGxR0_EN_Pos                   _U_(16)                                              /**< (NMIC_SCFGxR0) Source Enable Position */
#define NMIC_SCFGxR0_EN_Msk                   (_U_(0x1) << NMIC_SCFGxR0_EN_Pos)                    /**< (NMIC_SCFGxR0) Source Enable Mask */
#define NMIC_SCFGxR0_EN(value)                (NMIC_SCFGxR0_EN_Msk & ((value) << NMIC_SCFGxR0_EN_Pos))
#define NMIC_SCFGxR0_FRZ_Pos                  _U_(31)                                              /**< (NMIC_SCFGxR0) Interrupt Line Freeze Position */
#define NMIC_SCFGxR0_FRZ_Msk                  (_U_(0x1) << NMIC_SCFGxR0_FRZ_Pos)                   /**< (NMIC_SCFGxR0) Interrupt Line Freeze Mask */
#define NMIC_SCFGxR0_FRZ(value)               (NMIC_SCFGxR0_FRZ_Msk & ((value) << NMIC_SCFGxR0_FRZ_Pos))
#define NMIC_SCFGxR0_Msk                      _U_(0x80010313)                                      /**< (NMIC_SCFGxR0) Register Mask  */


/* -------- NMIC_SCFGxR1 : (NMIC Offset: 0x18) (R/W 32) Source Configuration Register 0 1 -------- */
#define NMIC_SCFGxR1_GFSEL_Pos                _U_(0)                                               /**< (NMIC_SCFGxR1) Glitch Filter Selector (GFSEL field is read-only in NMIC_SCFG0 to 8) Position */
#define NMIC_SCFGxR1_GFSEL_Msk                (_U_(0x3) << NMIC_SCFGxR1_GFSEL_Pos)                 /**< (NMIC_SCFGxR1) Glitch Filter Selector (GFSEL field is read-only in NMIC_SCFG0 to 8) Mask */
#define NMIC_SCFGxR1_GFSEL(value)             (NMIC_SCFGxR1_GFSEL_Msk & ((value) << NMIC_SCFGxR1_GFSEL_Pos))
#define NMIC_SCFGxR1_GFEN_Pos                 _U_(4)                                               /**< (NMIC_SCFGxR1) Glitch Filter Enable (GFEN bit is read-only in NMIC_SCFG0 to 8) Position */
#define NMIC_SCFGxR1_GFEN_Msk                 (_U_(0x1) << NMIC_SCFGxR1_GFEN_Pos)                  /**< (NMIC_SCFGxR1) Glitch Filter Enable (GFEN bit is read-only in NMIC_SCFG0 to 8) Mask */
#define NMIC_SCFGxR1_GFEN(value)              (NMIC_SCFGxR1_GFEN_Msk & ((value) << NMIC_SCFGxR1_GFEN_Pos))
#define NMIC_SCFGxR1_POL_Pos                  _U_(8)                                               /**< (NMIC_SCFGxR1) Polarity (POL bit is read-only in NMIC_SCFG0 to 8) Position */
#define NMIC_SCFGxR1_POL_Msk                  (_U_(0x1) << NMIC_SCFGxR1_POL_Pos)                   /**< (NMIC_SCFGxR1) Polarity (POL bit is read-only in NMIC_SCFG0 to 8) Mask */
#define NMIC_SCFGxR1_POL(value)               (NMIC_SCFGxR1_POL_Msk & ((value) << NMIC_SCFGxR1_POL_Pos))
#define NMIC_SCFGxR1_LVL_Pos                  _U_(9)                                               /**< (NMIC_SCFGxR1) Level Detection (LVL bit is read-only in NMIC_SCFG0 to 8) Position */
#define NMIC_SCFGxR1_LVL_Msk                  (_U_(0x1) << NMIC_SCFGxR1_LVL_Pos)                   /**< (NMIC_SCFGxR1) Level Detection (LVL bit is read-only in NMIC_SCFG0 to 8) Mask */
#define NMIC_SCFGxR1_LVL(value)               (NMIC_SCFGxR1_LVL_Msk & ((value) << NMIC_SCFGxR1_LVL_Pos))
#define NMIC_SCFGxR1_EN_Pos                   _U_(16)                                              /**< (NMIC_SCFGxR1) Source Enable Position */
#define NMIC_SCFGxR1_EN_Msk                   (_U_(0x1) << NMIC_SCFGxR1_EN_Pos)                    /**< (NMIC_SCFGxR1) Source Enable Mask */
#define NMIC_SCFGxR1_EN(value)                (NMIC_SCFGxR1_EN_Msk & ((value) << NMIC_SCFGxR1_EN_Pos))
#define NMIC_SCFGxR1_FRZ_Pos                  _U_(31)                                              /**< (NMIC_SCFGxR1) Interrupt Line Freeze Position */
#define NMIC_SCFGxR1_FRZ_Msk                  (_U_(0x1) << NMIC_SCFGxR1_FRZ_Pos)                   /**< (NMIC_SCFGxR1) Interrupt Line Freeze Mask */
#define NMIC_SCFGxR1_FRZ(value)               (NMIC_SCFGxR1_FRZ_Msk & ((value) << NMIC_SCFGxR1_FRZ_Pos))
#define NMIC_SCFGxR1_Msk                      _U_(0x80010313)                                      /**< (NMIC_SCFGxR1) Register Mask  */


/* -------- NMIC_SCFGxR2 : (NMIC Offset: 0x1C) (R/W 32) Source Configuration Register 0 2 -------- */
#define NMIC_SCFGxR2_GFSEL_Pos                _U_(0)                                               /**< (NMIC_SCFGxR2) Glitch Filter Selector (GFSEL field is read-only in NMIC_SCFG0 to 8) Position */
#define NMIC_SCFGxR2_GFSEL_Msk                (_U_(0x3) << NMIC_SCFGxR2_GFSEL_Pos)                 /**< (NMIC_SCFGxR2) Glitch Filter Selector (GFSEL field is read-only in NMIC_SCFG0 to 8) Mask */
#define NMIC_SCFGxR2_GFSEL(value)             (NMIC_SCFGxR2_GFSEL_Msk & ((value) << NMIC_SCFGxR2_GFSEL_Pos))
#define NMIC_SCFGxR2_GFEN_Pos                 _U_(4)                                               /**< (NMIC_SCFGxR2) Glitch Filter Enable (GFEN bit is read-only in NMIC_SCFG0 to 8) Position */
#define NMIC_SCFGxR2_GFEN_Msk                 (_U_(0x1) << NMIC_SCFGxR2_GFEN_Pos)                  /**< (NMIC_SCFGxR2) Glitch Filter Enable (GFEN bit is read-only in NMIC_SCFG0 to 8) Mask */
#define NMIC_SCFGxR2_GFEN(value)              (NMIC_SCFGxR2_GFEN_Msk & ((value) << NMIC_SCFGxR2_GFEN_Pos))
#define NMIC_SCFGxR2_POL_Pos                  _U_(8)                                               /**< (NMIC_SCFGxR2) Polarity (POL bit is read-only in NMIC_SCFG0 to 8) Position */
#define NMIC_SCFGxR2_POL_Msk                  (_U_(0x1) << NMIC_SCFGxR2_POL_Pos)                   /**< (NMIC_SCFGxR2) Polarity (POL bit is read-only in NMIC_SCFG0 to 8) Mask */
#define NMIC_SCFGxR2_POL(value)               (NMIC_SCFGxR2_POL_Msk & ((value) << NMIC_SCFGxR2_POL_Pos))
#define NMIC_SCFGxR2_LVL_Pos                  _U_(9)                                               /**< (NMIC_SCFGxR2) Level Detection (LVL bit is read-only in NMIC_SCFG0 to 8) Position */
#define NMIC_SCFGxR2_LVL_Msk                  (_U_(0x1) << NMIC_SCFGxR2_LVL_Pos)                   /**< (NMIC_SCFGxR2) Level Detection (LVL bit is read-only in NMIC_SCFG0 to 8) Mask */
#define NMIC_SCFGxR2_LVL(value)               (NMIC_SCFGxR2_LVL_Msk & ((value) << NMIC_SCFGxR2_LVL_Pos))
#define NMIC_SCFGxR2_EN_Pos                   _U_(16)                                              /**< (NMIC_SCFGxR2) Source Enable Position */
#define NMIC_SCFGxR2_EN_Msk                   (_U_(0x1) << NMIC_SCFGxR2_EN_Pos)                    /**< (NMIC_SCFGxR2) Source Enable Mask */
#define NMIC_SCFGxR2_EN(value)                (NMIC_SCFGxR2_EN_Msk & ((value) << NMIC_SCFGxR2_EN_Pos))
#define NMIC_SCFGxR2_FRZ_Pos                  _U_(31)                                              /**< (NMIC_SCFGxR2) Interrupt Line Freeze Position */
#define NMIC_SCFGxR2_FRZ_Msk                  (_U_(0x1) << NMIC_SCFGxR2_FRZ_Pos)                   /**< (NMIC_SCFGxR2) Interrupt Line Freeze Mask */
#define NMIC_SCFGxR2_FRZ(value)               (NMIC_SCFGxR2_FRZ_Msk & ((value) << NMIC_SCFGxR2_FRZ_Pos))
#define NMIC_SCFGxR2_Msk                      _U_(0x80010313)                                      /**< (NMIC_SCFGxR2) Register Mask  */


/* -------- NMIC_SCFGxR3 : (NMIC Offset: 0x20) (R/W 32) Source Configuration Register 0 3 -------- */
#define NMIC_SCFGxR3_GFSEL_Pos                _U_(0)                                               /**< (NMIC_SCFGxR3) Glitch Filter Selector (GFSEL field is read-only in NMIC_SCFG0 to 8) Position */
#define NMIC_SCFGxR3_GFSEL_Msk                (_U_(0x3) << NMIC_SCFGxR3_GFSEL_Pos)                 /**< (NMIC_SCFGxR3) Glitch Filter Selector (GFSEL field is read-only in NMIC_SCFG0 to 8) Mask */
#define NMIC_SCFGxR3_GFSEL(value)             (NMIC_SCFGxR3_GFSEL_Msk & ((value) << NMIC_SCFGxR3_GFSEL_Pos))
#define NMIC_SCFGxR3_GFEN_Pos                 _U_(4)                                               /**< (NMIC_SCFGxR3) Glitch Filter Enable (GFEN bit is read-only in NMIC_SCFG0 to 8) Position */
#define NMIC_SCFGxR3_GFEN_Msk                 (_U_(0x1) << NMIC_SCFGxR3_GFEN_Pos)                  /**< (NMIC_SCFGxR3) Glitch Filter Enable (GFEN bit is read-only in NMIC_SCFG0 to 8) Mask */
#define NMIC_SCFGxR3_GFEN(value)              (NMIC_SCFGxR3_GFEN_Msk & ((value) << NMIC_SCFGxR3_GFEN_Pos))
#define NMIC_SCFGxR3_POL_Pos                  _U_(8)                                               /**< (NMIC_SCFGxR3) Polarity (POL bit is read-only in NMIC_SCFG0 to 8) Position */
#define NMIC_SCFGxR3_POL_Msk                  (_U_(0x1) << NMIC_SCFGxR3_POL_Pos)                   /**< (NMIC_SCFGxR3) Polarity (POL bit is read-only in NMIC_SCFG0 to 8) Mask */
#define NMIC_SCFGxR3_POL(value)               (NMIC_SCFGxR3_POL_Msk & ((value) << NMIC_SCFGxR3_POL_Pos))
#define NMIC_SCFGxR3_LVL_Pos                  _U_(9)                                               /**< (NMIC_SCFGxR3) Level Detection (LVL bit is read-only in NMIC_SCFG0 to 8) Position */
#define NMIC_SCFGxR3_LVL_Msk                  (_U_(0x1) << NMIC_SCFGxR3_LVL_Pos)                   /**< (NMIC_SCFGxR3) Level Detection (LVL bit is read-only in NMIC_SCFG0 to 8) Mask */
#define NMIC_SCFGxR3_LVL(value)               (NMIC_SCFGxR3_LVL_Msk & ((value) << NMIC_SCFGxR3_LVL_Pos))
#define NMIC_SCFGxR3_EN_Pos                   _U_(16)                                              /**< (NMIC_SCFGxR3) Source Enable Position */
#define NMIC_SCFGxR3_EN_Msk                   (_U_(0x1) << NMIC_SCFGxR3_EN_Pos)                    /**< (NMIC_SCFGxR3) Source Enable Mask */
#define NMIC_SCFGxR3_EN(value)                (NMIC_SCFGxR3_EN_Msk & ((value) << NMIC_SCFGxR3_EN_Pos))
#define NMIC_SCFGxR3_FRZ_Pos                  _U_(31)                                              /**< (NMIC_SCFGxR3) Interrupt Line Freeze Position */
#define NMIC_SCFGxR3_FRZ_Msk                  (_U_(0x1) << NMIC_SCFGxR3_FRZ_Pos)                   /**< (NMIC_SCFGxR3) Interrupt Line Freeze Mask */
#define NMIC_SCFGxR3_FRZ(value)               (NMIC_SCFGxR3_FRZ_Msk & ((value) << NMIC_SCFGxR3_FRZ_Pos))
#define NMIC_SCFGxR3_Msk                      _U_(0x80010313)                                      /**< (NMIC_SCFGxR3) Register Mask  */


/* -------- NMIC_SCFGxR4 : (NMIC Offset: 0x24) (R/W 32) Source Configuration Register 0 4 -------- */
#define NMIC_SCFGxR4_GFSEL_Pos                _U_(0)                                               /**< (NMIC_SCFGxR4) Glitch Filter Selector (GFSEL field is read-only in NMIC_SCFG0 to 8) Position */
#define NMIC_SCFGxR4_GFSEL_Msk                (_U_(0x3) << NMIC_SCFGxR4_GFSEL_Pos)                 /**< (NMIC_SCFGxR4) Glitch Filter Selector (GFSEL field is read-only in NMIC_SCFG0 to 8) Mask */
#define NMIC_SCFGxR4_GFSEL(value)             (NMIC_SCFGxR4_GFSEL_Msk & ((value) << NMIC_SCFGxR4_GFSEL_Pos))
#define NMIC_SCFGxR4_GFEN_Pos                 _U_(4)                                               /**< (NMIC_SCFGxR4) Glitch Filter Enable (GFEN bit is read-only in NMIC_SCFG0 to 8) Position */
#define NMIC_SCFGxR4_GFEN_Msk                 (_U_(0x1) << NMIC_SCFGxR4_GFEN_Pos)                  /**< (NMIC_SCFGxR4) Glitch Filter Enable (GFEN bit is read-only in NMIC_SCFG0 to 8) Mask */
#define NMIC_SCFGxR4_GFEN(value)              (NMIC_SCFGxR4_GFEN_Msk & ((value) << NMIC_SCFGxR4_GFEN_Pos))
#define NMIC_SCFGxR4_POL_Pos                  _U_(8)                                               /**< (NMIC_SCFGxR4) Polarity (POL bit is read-only in NMIC_SCFG0 to 8) Position */
#define NMIC_SCFGxR4_POL_Msk                  (_U_(0x1) << NMIC_SCFGxR4_POL_Pos)                   /**< (NMIC_SCFGxR4) Polarity (POL bit is read-only in NMIC_SCFG0 to 8) Mask */
#define NMIC_SCFGxR4_POL(value)               (NMIC_SCFGxR4_POL_Msk & ((value) << NMIC_SCFGxR4_POL_Pos))
#define NMIC_SCFGxR4_LVL_Pos                  _U_(9)                                               /**< (NMIC_SCFGxR4) Level Detection (LVL bit is read-only in NMIC_SCFG0 to 8) Position */
#define NMIC_SCFGxR4_LVL_Msk                  (_U_(0x1) << NMIC_SCFGxR4_LVL_Pos)                   /**< (NMIC_SCFGxR4) Level Detection (LVL bit is read-only in NMIC_SCFG0 to 8) Mask */
#define NMIC_SCFGxR4_LVL(value)               (NMIC_SCFGxR4_LVL_Msk & ((value) << NMIC_SCFGxR4_LVL_Pos))
#define NMIC_SCFGxR4_EN_Pos                   _U_(16)                                              /**< (NMIC_SCFGxR4) Source Enable Position */
#define NMIC_SCFGxR4_EN_Msk                   (_U_(0x1) << NMIC_SCFGxR4_EN_Pos)                    /**< (NMIC_SCFGxR4) Source Enable Mask */
#define NMIC_SCFGxR4_EN(value)                (NMIC_SCFGxR4_EN_Msk & ((value) << NMIC_SCFGxR4_EN_Pos))
#define NMIC_SCFGxR4_FRZ_Pos                  _U_(31)                                              /**< (NMIC_SCFGxR4) Interrupt Line Freeze Position */
#define NMIC_SCFGxR4_FRZ_Msk                  (_U_(0x1) << NMIC_SCFGxR4_FRZ_Pos)                   /**< (NMIC_SCFGxR4) Interrupt Line Freeze Mask */
#define NMIC_SCFGxR4_FRZ(value)               (NMIC_SCFGxR4_FRZ_Msk & ((value) << NMIC_SCFGxR4_FRZ_Pos))
#define NMIC_SCFGxR4_Msk                      _U_(0x80010313)                                      /**< (NMIC_SCFGxR4) Register Mask  */


/* -------- NMIC_SCFGxR5 : (NMIC Offset: 0x28) (R/W 32) Source Configuration Register 0 5 -------- */
#define NMIC_SCFGxR5_GFSEL_Pos                _U_(0)                                               /**< (NMIC_SCFGxR5) Glitch Filter Selector (GFSEL field is read-only in NMIC_SCFG0 to 8) Position */
#define NMIC_SCFGxR5_GFSEL_Msk                (_U_(0x3) << NMIC_SCFGxR5_GFSEL_Pos)                 /**< (NMIC_SCFGxR5) Glitch Filter Selector (GFSEL field is read-only in NMIC_SCFG0 to 8) Mask */
#define NMIC_SCFGxR5_GFSEL(value)             (NMIC_SCFGxR5_GFSEL_Msk & ((value) << NMIC_SCFGxR5_GFSEL_Pos))
#define NMIC_SCFGxR5_GFEN_Pos                 _U_(4)                                               /**< (NMIC_SCFGxR5) Glitch Filter Enable (GFEN bit is read-only in NMIC_SCFG0 to 8) Position */
#define NMIC_SCFGxR5_GFEN_Msk                 (_U_(0x1) << NMIC_SCFGxR5_GFEN_Pos)                  /**< (NMIC_SCFGxR5) Glitch Filter Enable (GFEN bit is read-only in NMIC_SCFG0 to 8) Mask */
#define NMIC_SCFGxR5_GFEN(value)              (NMIC_SCFGxR5_GFEN_Msk & ((value) << NMIC_SCFGxR5_GFEN_Pos))
#define NMIC_SCFGxR5_POL_Pos                  _U_(8)                                               /**< (NMIC_SCFGxR5) Polarity (POL bit is read-only in NMIC_SCFG0 to 8) Position */
#define NMIC_SCFGxR5_POL_Msk                  (_U_(0x1) << NMIC_SCFGxR5_POL_Pos)                   /**< (NMIC_SCFGxR5) Polarity (POL bit is read-only in NMIC_SCFG0 to 8) Mask */
#define NMIC_SCFGxR5_POL(value)               (NMIC_SCFGxR5_POL_Msk & ((value) << NMIC_SCFGxR5_POL_Pos))
#define NMIC_SCFGxR5_LVL_Pos                  _U_(9)                                               /**< (NMIC_SCFGxR5) Level Detection (LVL bit is read-only in NMIC_SCFG0 to 8) Position */
#define NMIC_SCFGxR5_LVL_Msk                  (_U_(0x1) << NMIC_SCFGxR5_LVL_Pos)                   /**< (NMIC_SCFGxR5) Level Detection (LVL bit is read-only in NMIC_SCFG0 to 8) Mask */
#define NMIC_SCFGxR5_LVL(value)               (NMIC_SCFGxR5_LVL_Msk & ((value) << NMIC_SCFGxR5_LVL_Pos))
#define NMIC_SCFGxR5_EN_Pos                   _U_(16)                                              /**< (NMIC_SCFGxR5) Source Enable Position */
#define NMIC_SCFGxR5_EN_Msk                   (_U_(0x1) << NMIC_SCFGxR5_EN_Pos)                    /**< (NMIC_SCFGxR5) Source Enable Mask */
#define NMIC_SCFGxR5_EN(value)                (NMIC_SCFGxR5_EN_Msk & ((value) << NMIC_SCFGxR5_EN_Pos))
#define NMIC_SCFGxR5_FRZ_Pos                  _U_(31)                                              /**< (NMIC_SCFGxR5) Interrupt Line Freeze Position */
#define NMIC_SCFGxR5_FRZ_Msk                  (_U_(0x1) << NMIC_SCFGxR5_FRZ_Pos)                   /**< (NMIC_SCFGxR5) Interrupt Line Freeze Mask */
#define NMIC_SCFGxR5_FRZ(value)               (NMIC_SCFGxR5_FRZ_Msk & ((value) << NMIC_SCFGxR5_FRZ_Pos))
#define NMIC_SCFGxR5_Msk                      _U_(0x80010313)                                      /**< (NMIC_SCFGxR5) Register Mask  */


/* -------- NMIC_SCFGxR6 : (NMIC Offset: 0x2C) (R/W 32) Source Configuration Register 0 6 -------- */
#define NMIC_SCFGxR6_GFSEL_Pos                _U_(0)                                               /**< (NMIC_SCFGxR6) Glitch Filter Selector (GFSEL field is read-only in NMIC_SCFG0 to 8) Position */
#define NMIC_SCFGxR6_GFSEL_Msk                (_U_(0x3) << NMIC_SCFGxR6_GFSEL_Pos)                 /**< (NMIC_SCFGxR6) Glitch Filter Selector (GFSEL field is read-only in NMIC_SCFG0 to 8) Mask */
#define NMIC_SCFGxR6_GFSEL(value)             (NMIC_SCFGxR6_GFSEL_Msk & ((value) << NMIC_SCFGxR6_GFSEL_Pos))
#define NMIC_SCFGxR6_GFEN_Pos                 _U_(4)                                               /**< (NMIC_SCFGxR6) Glitch Filter Enable (GFEN bit is read-only in NMIC_SCFG0 to 8) Position */
#define NMIC_SCFGxR6_GFEN_Msk                 (_U_(0x1) << NMIC_SCFGxR6_GFEN_Pos)                  /**< (NMIC_SCFGxR6) Glitch Filter Enable (GFEN bit is read-only in NMIC_SCFG0 to 8) Mask */
#define NMIC_SCFGxR6_GFEN(value)              (NMIC_SCFGxR6_GFEN_Msk & ((value) << NMIC_SCFGxR6_GFEN_Pos))
#define NMIC_SCFGxR6_POL_Pos                  _U_(8)                                               /**< (NMIC_SCFGxR6) Polarity (POL bit is read-only in NMIC_SCFG0 to 8) Position */
#define NMIC_SCFGxR6_POL_Msk                  (_U_(0x1) << NMIC_SCFGxR6_POL_Pos)                   /**< (NMIC_SCFGxR6) Polarity (POL bit is read-only in NMIC_SCFG0 to 8) Mask */
#define NMIC_SCFGxR6_POL(value)               (NMIC_SCFGxR6_POL_Msk & ((value) << NMIC_SCFGxR6_POL_Pos))
#define NMIC_SCFGxR6_LVL_Pos                  _U_(9)                                               /**< (NMIC_SCFGxR6) Level Detection (LVL bit is read-only in NMIC_SCFG0 to 8) Position */
#define NMIC_SCFGxR6_LVL_Msk                  (_U_(0x1) << NMIC_SCFGxR6_LVL_Pos)                   /**< (NMIC_SCFGxR6) Level Detection (LVL bit is read-only in NMIC_SCFG0 to 8) Mask */
#define NMIC_SCFGxR6_LVL(value)               (NMIC_SCFGxR6_LVL_Msk & ((value) << NMIC_SCFGxR6_LVL_Pos))
#define NMIC_SCFGxR6_EN_Pos                   _U_(16)                                              /**< (NMIC_SCFGxR6) Source Enable Position */
#define NMIC_SCFGxR6_EN_Msk                   (_U_(0x1) << NMIC_SCFGxR6_EN_Pos)                    /**< (NMIC_SCFGxR6) Source Enable Mask */
#define NMIC_SCFGxR6_EN(value)                (NMIC_SCFGxR6_EN_Msk & ((value) << NMIC_SCFGxR6_EN_Pos))
#define NMIC_SCFGxR6_FRZ_Pos                  _U_(31)                                              /**< (NMIC_SCFGxR6) Interrupt Line Freeze Position */
#define NMIC_SCFGxR6_FRZ_Msk                  (_U_(0x1) << NMIC_SCFGxR6_FRZ_Pos)                   /**< (NMIC_SCFGxR6) Interrupt Line Freeze Mask */
#define NMIC_SCFGxR6_FRZ(value)               (NMIC_SCFGxR6_FRZ_Msk & ((value) << NMIC_SCFGxR6_FRZ_Pos))
#define NMIC_SCFGxR6_Msk                      _U_(0x80010313)                                      /**< (NMIC_SCFGxR6) Register Mask  */


/* -------- NMIC_SCFGxR7 : (NMIC Offset: 0x30) (R/W 32) Source Configuration Register 0 7 -------- */
#define NMIC_SCFGxR7_GFSEL_Pos                _U_(0)                                               /**< (NMIC_SCFGxR7) Glitch Filter Selector (GFSEL field is read-only in NMIC_SCFG0 to 8) Position */
#define NMIC_SCFGxR7_GFSEL_Msk                (_U_(0x3) << NMIC_SCFGxR7_GFSEL_Pos)                 /**< (NMIC_SCFGxR7) Glitch Filter Selector (GFSEL field is read-only in NMIC_SCFG0 to 8) Mask */
#define NMIC_SCFGxR7_GFSEL(value)             (NMIC_SCFGxR7_GFSEL_Msk & ((value) << NMIC_SCFGxR7_GFSEL_Pos))
#define NMIC_SCFGxR7_GFEN_Pos                 _U_(4)                                               /**< (NMIC_SCFGxR7) Glitch Filter Enable (GFEN bit is read-only in NMIC_SCFG0 to 8) Position */
#define NMIC_SCFGxR7_GFEN_Msk                 (_U_(0x1) << NMIC_SCFGxR7_GFEN_Pos)                  /**< (NMIC_SCFGxR7) Glitch Filter Enable (GFEN bit is read-only in NMIC_SCFG0 to 8) Mask */
#define NMIC_SCFGxR7_GFEN(value)              (NMIC_SCFGxR7_GFEN_Msk & ((value) << NMIC_SCFGxR7_GFEN_Pos))
#define NMIC_SCFGxR7_POL_Pos                  _U_(8)                                               /**< (NMIC_SCFGxR7) Polarity (POL bit is read-only in NMIC_SCFG0 to 8) Position */
#define NMIC_SCFGxR7_POL_Msk                  (_U_(0x1) << NMIC_SCFGxR7_POL_Pos)                   /**< (NMIC_SCFGxR7) Polarity (POL bit is read-only in NMIC_SCFG0 to 8) Mask */
#define NMIC_SCFGxR7_POL(value)               (NMIC_SCFGxR7_POL_Msk & ((value) << NMIC_SCFGxR7_POL_Pos))
#define NMIC_SCFGxR7_LVL_Pos                  _U_(9)                                               /**< (NMIC_SCFGxR7) Level Detection (LVL bit is read-only in NMIC_SCFG0 to 8) Position */
#define NMIC_SCFGxR7_LVL_Msk                  (_U_(0x1) << NMIC_SCFGxR7_LVL_Pos)                   /**< (NMIC_SCFGxR7) Level Detection (LVL bit is read-only in NMIC_SCFG0 to 8) Mask */
#define NMIC_SCFGxR7_LVL(value)               (NMIC_SCFGxR7_LVL_Msk & ((value) << NMIC_SCFGxR7_LVL_Pos))
#define NMIC_SCFGxR7_EN_Pos                   _U_(16)                                              /**< (NMIC_SCFGxR7) Source Enable Position */
#define NMIC_SCFGxR7_EN_Msk                   (_U_(0x1) << NMIC_SCFGxR7_EN_Pos)                    /**< (NMIC_SCFGxR7) Source Enable Mask */
#define NMIC_SCFGxR7_EN(value)                (NMIC_SCFGxR7_EN_Msk & ((value) << NMIC_SCFGxR7_EN_Pos))
#define NMIC_SCFGxR7_FRZ_Pos                  _U_(31)                                              /**< (NMIC_SCFGxR7) Interrupt Line Freeze Position */
#define NMIC_SCFGxR7_FRZ_Msk                  (_U_(0x1) << NMIC_SCFGxR7_FRZ_Pos)                   /**< (NMIC_SCFGxR7) Interrupt Line Freeze Mask */
#define NMIC_SCFGxR7_FRZ(value)               (NMIC_SCFGxR7_FRZ_Msk & ((value) << NMIC_SCFGxR7_FRZ_Pos))
#define NMIC_SCFGxR7_Msk                      _U_(0x80010313)                                      /**< (NMIC_SCFGxR7) Register Mask  */


/* -------- NMIC_SCFGxR8 : (NMIC Offset: 0x34) (R/W 32) Source Configuration Register 0 8 -------- */
#define NMIC_SCFGxR8_GFSEL_Pos                _U_(0)                                               /**< (NMIC_SCFGxR8) Glitch Filter Selector (GFSEL field is read-only in NMIC_SCFG0 to 8) Position */
#define NMIC_SCFGxR8_GFSEL_Msk                (_U_(0x3) << NMIC_SCFGxR8_GFSEL_Pos)                 /**< (NMIC_SCFGxR8) Glitch Filter Selector (GFSEL field is read-only in NMIC_SCFG0 to 8) Mask */
#define NMIC_SCFGxR8_GFSEL(value)             (NMIC_SCFGxR8_GFSEL_Msk & ((value) << NMIC_SCFGxR8_GFSEL_Pos))
#define NMIC_SCFGxR8_GFEN_Pos                 _U_(4)                                               /**< (NMIC_SCFGxR8) Glitch Filter Enable (GFEN bit is read-only in NMIC_SCFG0 to 8) Position */
#define NMIC_SCFGxR8_GFEN_Msk                 (_U_(0x1) << NMIC_SCFGxR8_GFEN_Pos)                  /**< (NMIC_SCFGxR8) Glitch Filter Enable (GFEN bit is read-only in NMIC_SCFG0 to 8) Mask */
#define NMIC_SCFGxR8_GFEN(value)              (NMIC_SCFGxR8_GFEN_Msk & ((value) << NMIC_SCFGxR8_GFEN_Pos))
#define NMIC_SCFGxR8_POL_Pos                  _U_(8)                                               /**< (NMIC_SCFGxR8) Polarity (POL bit is read-only in NMIC_SCFG0 to 8) Position */
#define NMIC_SCFGxR8_POL_Msk                  (_U_(0x1) << NMIC_SCFGxR8_POL_Pos)                   /**< (NMIC_SCFGxR8) Polarity (POL bit is read-only in NMIC_SCFG0 to 8) Mask */
#define NMIC_SCFGxR8_POL(value)               (NMIC_SCFGxR8_POL_Msk & ((value) << NMIC_SCFGxR8_POL_Pos))
#define NMIC_SCFGxR8_LVL_Pos                  _U_(9)                                               /**< (NMIC_SCFGxR8) Level Detection (LVL bit is read-only in NMIC_SCFG0 to 8) Position */
#define NMIC_SCFGxR8_LVL_Msk                  (_U_(0x1) << NMIC_SCFGxR8_LVL_Pos)                   /**< (NMIC_SCFGxR8) Level Detection (LVL bit is read-only in NMIC_SCFG0 to 8) Mask */
#define NMIC_SCFGxR8_LVL(value)               (NMIC_SCFGxR8_LVL_Msk & ((value) << NMIC_SCFGxR8_LVL_Pos))
#define NMIC_SCFGxR8_EN_Pos                   _U_(16)                                              /**< (NMIC_SCFGxR8) Source Enable Position */
#define NMIC_SCFGxR8_EN_Msk                   (_U_(0x1) << NMIC_SCFGxR8_EN_Pos)                    /**< (NMIC_SCFGxR8) Source Enable Mask */
#define NMIC_SCFGxR8_EN(value)                (NMIC_SCFGxR8_EN_Msk & ((value) << NMIC_SCFGxR8_EN_Pos))
#define NMIC_SCFGxR8_FRZ_Pos                  _U_(31)                                              /**< (NMIC_SCFGxR8) Interrupt Line Freeze Position */
#define NMIC_SCFGxR8_FRZ_Msk                  (_U_(0x1) << NMIC_SCFGxR8_FRZ_Pos)                   /**< (NMIC_SCFGxR8) Interrupt Line Freeze Mask */
#define NMIC_SCFGxR8_FRZ(value)               (NMIC_SCFGxR8_FRZ_Msk & ((value) << NMIC_SCFGxR8_FRZ_Pos))
#define NMIC_SCFGxR8_Msk                      _U_(0x80010313)                                      /**< (NMIC_SCFGxR8) Register Mask  */


/* -------- NMIC_WPMR : (NMIC Offset: 0xE4) (R/W 32) Write Protection Mode Register -------- */
#define NMIC_WPMR_WPCFEN_Pos                  _U_(0)                                               /**< (NMIC_WPMR) Write Protection Configuration Enable Position */
#define NMIC_WPMR_WPCFEN_Msk                  (_U_(0x1) << NMIC_WPMR_WPCFEN_Pos)                   /**< (NMIC_WPMR) Write Protection Configuration Enable Mask */
#define NMIC_WPMR_WPCFEN(value)               (NMIC_WPMR_WPCFEN_Msk & ((value) << NMIC_WPMR_WPCFEN_Pos))
#define NMIC_WPMR_WPITEN_Pos                  _U_(1)                                               /**< (NMIC_WPMR) Write Protection Interrupt Enable Position */
#define NMIC_WPMR_WPITEN_Msk                  (_U_(0x1) << NMIC_WPMR_WPITEN_Pos)                   /**< (NMIC_WPMR) Write Protection Interrupt Enable Mask */
#define NMIC_WPMR_WPITEN(value)               (NMIC_WPMR_WPITEN_Msk & ((value) << NMIC_WPMR_WPITEN_Pos))
#define NMIC_WPMR_WPKEY_Pos                   _U_(8)                                               /**< (NMIC_WPMR) Write Protection Key Position */
#define NMIC_WPMR_WPKEY_Msk                   (_U_(0xFFFFFF) << NMIC_WPMR_WPKEY_Pos)               /**< (NMIC_WPMR) Write Protection Key Mask */
#define NMIC_WPMR_WPKEY(value)                (NMIC_WPMR_WPKEY_Msk & ((value) << NMIC_WPMR_WPKEY_Pos))
#define   NMIC_WPMR_WPKEY_PASSWD_Val          _U_(0x4E4D49)                                        /**< (NMIC_WPMR) Writing any other value in this field aborts the write operation of the WPCFEN and WPITEN bit. Always reads as 0.  */
#define NMIC_WPMR_WPKEY_PASSWD                (NMIC_WPMR_WPKEY_PASSWD_Val << NMIC_WPMR_WPKEY_Pos)  /**< (NMIC_WPMR) Writing any other value in this field aborts the write operation of the WPCFEN and WPITEN bit. Always reads as 0. Position  */
#define NMIC_WPMR_Msk                         _U_(0xFFFFFF03)                                      /**< (NMIC_WPMR) Register Mask  */


/* -------- NMIC_WPSR : (NMIC Offset: 0xE8) ( R/ 32) Write Protection Status Register -------- */
#define NMIC_WPSR_WPVS_Pos                    _U_(0)                                               /**< (NMIC_WPSR) Write Protection Register Violation Status Position */
#define NMIC_WPSR_WPVS_Msk                    (_U_(0x1) << NMIC_WPSR_WPVS_Pos)                     /**< (NMIC_WPSR) Write Protection Register Violation Status Mask */
#define NMIC_WPSR_WPVS(value)                 (NMIC_WPSR_WPVS_Msk & ((value) << NMIC_WPSR_WPVS_Pos))
#define NMIC_WPSR_FZWVS_Pos                   _U_(1)                                               /**< (NMIC_WPSR) Frozen Register Write Violation Status Position */
#define NMIC_WPSR_FZWVS_Msk                   (_U_(0x1) << NMIC_WPSR_FZWVS_Pos)                    /**< (NMIC_WPSR) Frozen Register Write Violation Status Mask */
#define NMIC_WPSR_FZWVS(value)                (NMIC_WPSR_FZWVS_Msk & ((value) << NMIC_WPSR_FZWVS_Pos))
#define NMIC_WPSR_BSWVS_Pos                   _U_(2)                                               /**< (NMIC_WPSR) Busy Register Write Violation Status Position */
#define NMIC_WPSR_BSWVS_Msk                   (_U_(0x1) << NMIC_WPSR_BSWVS_Pos)                    /**< (NMIC_WPSR) Busy Register Write Violation Status Mask */
#define NMIC_WPSR_BSWVS(value)                (NMIC_WPSR_BSWVS_Msk & ((value) << NMIC_WPSR_BSWVS_Pos))
#define NMIC_WPSR_WVSRC_Pos                   _U_(8)                                               /**< (NMIC_WPSR) Write Violation Source Position */
#define NMIC_WPSR_WVSRC_Msk                   (_U_(0xFF) << NMIC_WPSR_WVSRC_Pos)                   /**< (NMIC_WPSR) Write Violation Source Mask */
#define NMIC_WPSR_WVSRC(value)                (NMIC_WPSR_WVSRC_Msk & ((value) << NMIC_WPSR_WVSRC_Pos))
#define NMIC_WPSR_Msk                         _U_(0x0000FF07)                                      /**< (NMIC_WPSR) Register Mask  */


/** \brief NMIC register offsets definitions */
#define NMIC_IER_REG_OFST              (0x00)              /**< (NMIC_IER) Interrupt Enable Register Offset */
#define NMIC_IDR_REG_OFST              (0x04)              /**< (NMIC_IDR) Interrupt Disable Register Offset */
#define NMIC_IAR_REG_OFST              (0x08)              /**< (NMIC_IAR) Interrupt Active Register Offset */
#define NMIC_ISR_REG_OFST              (0x0C)              /**< (NMIC_ISR) Interrupt Status Register Offset */
#define NMIC_GFCS_REG_OFST             (0x10)              /**< (NMIC_GFCS) Glitch Filter Configuration Status Register Offset */
#define NMIC_SCFGxR0_REG_OFST          (0x14)              /**< (NMIC_SCFGxR0) Source Configuration Register 0 0 Offset */
#define NMIC_SCFGxR1_REG_OFST          (0x18)              /**< (NMIC_SCFGxR1) Source Configuration Register 0 1 Offset */
#define NMIC_SCFGxR2_REG_OFST          (0x1C)              /**< (NMIC_SCFGxR2) Source Configuration Register 0 2 Offset */
#define NMIC_SCFGxR3_REG_OFST          (0x20)              /**< (NMIC_SCFGxR3) Source Configuration Register 0 3 Offset */
#define NMIC_SCFGxR4_REG_OFST          (0x24)              /**< (NMIC_SCFGxR4) Source Configuration Register 0 4 Offset */
#define NMIC_SCFGxR5_REG_OFST          (0x28)              /**< (NMIC_SCFGxR5) Source Configuration Register 0 5 Offset */
#define NMIC_SCFGxR6_REG_OFST          (0x2C)              /**< (NMIC_SCFGxR6) Source Configuration Register 0 6 Offset */
#define NMIC_SCFGxR7_REG_OFST          (0x30)              /**< (NMIC_SCFGxR7) Source Configuration Register 0 7 Offset */
#define NMIC_SCFGxR8_REG_OFST          (0x34)              /**< (NMIC_SCFGxR8) Source Configuration Register 0 8 Offset */
#define NMIC_WPMR_REG_OFST             (0xE4)              /**< (NMIC_WPMR) Write Protection Mode Register Offset */
#define NMIC_WPSR_REG_OFST             (0xE8)              /**< (NMIC_WPSR) Write Protection Status Register Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief NMIC register API structure */
typedef struct
{
  __O   uint32_t                       NMIC_IER;           /**< Offset: 0x00 ( /W  32) Interrupt Enable Register */
  __O   uint32_t                       NMIC_IDR;           /**< Offset: 0x04 ( /W  32) Interrupt Disable Register */
  __I   uint32_t                       NMIC_IAR;           /**< Offset: 0x08 (R/   32) Interrupt Active Register */
  __I   uint32_t                       NMIC_ISR;           /**< Offset: 0x0C (R/   32) Interrupt Status Register */
  __I   uint32_t                       NMIC_GFCS;          /**< Offset: 0x10 (R/   32) Glitch Filter Configuration Status Register */
  __IO  uint32_t                       NMIC_SCFGxR0;       /**< Offset: 0x14 (R/W  32) Source Configuration Register 0 0 */
  __IO  uint32_t                       NMIC_SCFGxR1;       /**< Offset: 0x18 (R/W  32) Source Configuration Register 0 1 */
  __IO  uint32_t                       NMIC_SCFGxR2;       /**< Offset: 0x1C (R/W  32) Source Configuration Register 0 2 */
  __IO  uint32_t                       NMIC_SCFGxR3;       /**< Offset: 0x20 (R/W  32) Source Configuration Register 0 3 */
  __IO  uint32_t                       NMIC_SCFGxR4;       /**< Offset: 0x24 (R/W  32) Source Configuration Register 0 4 */
  __IO  uint32_t                       NMIC_SCFGxR5;       /**< Offset: 0x28 (R/W  32) Source Configuration Register 0 5 */
  __IO  uint32_t                       NMIC_SCFGxR6;       /**< Offset: 0x2C (R/W  32) Source Configuration Register 0 6 */
  __IO  uint32_t                       NMIC_SCFGxR7;       /**< Offset: 0x30 (R/W  32) Source Configuration Register 0 7 */
  __IO  uint32_t                       NMIC_SCFGxR8;       /**< Offset: 0x34 (R/W  32) Source Configuration Register 0 8 */
  __I   uint8_t                        Reserved1[0xAC];
  __IO  uint32_t                       NMIC_WPMR;          /**< Offset: 0xE4 (R/W  32) Write Protection Mode Register */
  __I   uint32_t                       NMIC_WPSR;          /**< Offset: 0xE8 (R/   32) Write Protection Status Register */
} nmic_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _SAMRH71_NMIC_COMPONENT_H_ */
