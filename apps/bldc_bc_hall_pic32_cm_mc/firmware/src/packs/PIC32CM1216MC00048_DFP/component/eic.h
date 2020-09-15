/**
 * \brief Component description for EIC
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

/* file generated from device description version 2020-08-03T13:06:13Z */
#ifndef _PIC32CMMC00_EIC_COMPONENT_H_
#define _PIC32CMMC00_EIC_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR EIC                                          */
/* ************************************************************************** */

/* -------- EIC_CTRLA : (EIC Offset: 0x00) (R/W 8) Control A -------- */
#define EIC_CTRLA_RESETVALUE                  _U_(0x00)                                            /**<  (EIC_CTRLA) Control A  Reset Value */

#define EIC_CTRLA_SWRST_Pos                   _U_(0)                                               /**< (EIC_CTRLA) Software Reset Position */
#define EIC_CTRLA_SWRST_Msk                   (_U_(0x1) << EIC_CTRLA_SWRST_Pos)                    /**< (EIC_CTRLA) Software Reset Mask */
#define EIC_CTRLA_SWRST(value)                (EIC_CTRLA_SWRST_Msk & ((value) << EIC_CTRLA_SWRST_Pos))
#define EIC_CTRLA_ENABLE_Pos                  _U_(1)                                               /**< (EIC_CTRLA) Enable Position */
#define EIC_CTRLA_ENABLE_Msk                  (_U_(0x1) << EIC_CTRLA_ENABLE_Pos)                   /**< (EIC_CTRLA) Enable Mask */
#define EIC_CTRLA_ENABLE(value)               (EIC_CTRLA_ENABLE_Msk & ((value) << EIC_CTRLA_ENABLE_Pos))
#define EIC_CTRLA_CKSEL_Pos                   _U_(4)                                               /**< (EIC_CTRLA) Clock Selection Position */
#define EIC_CTRLA_CKSEL_Msk                   (_U_(0x1) << EIC_CTRLA_CKSEL_Pos)                    /**< (EIC_CTRLA) Clock Selection Mask */
#define EIC_CTRLA_CKSEL(value)                (EIC_CTRLA_CKSEL_Msk & ((value) << EIC_CTRLA_CKSEL_Pos))
#define   EIC_CTRLA_CKSEL_CLK_GCLK_Val        _U_(0x0)                                             /**< (EIC_CTRLA) Clocked by GCLK  */
#define   EIC_CTRLA_CKSEL_CLK_ULP32K_Val      _U_(0x1)                                             /**< (EIC_CTRLA) Clocked by ULP32K  */
#define EIC_CTRLA_CKSEL_CLK_GCLK              (EIC_CTRLA_CKSEL_CLK_GCLK_Val << EIC_CTRLA_CKSEL_Pos) /**< (EIC_CTRLA) Clocked by GCLK Position  */
#define EIC_CTRLA_CKSEL_CLK_ULP32K            (EIC_CTRLA_CKSEL_CLK_ULP32K_Val << EIC_CTRLA_CKSEL_Pos) /**< (EIC_CTRLA) Clocked by ULP32K Position  */
#define EIC_CTRLA_Msk                         _U_(0x13)                                            /**< (EIC_CTRLA) Register Mask  */


/* -------- EIC_NMICTRL : (EIC Offset: 0x01) (R/W 8) Non-Maskable Interrupt Control -------- */
#define EIC_NMICTRL_RESETVALUE                _U_(0x00)                                            /**<  (EIC_NMICTRL) Non-Maskable Interrupt Control  Reset Value */

#define EIC_NMICTRL_NMISENSE_Pos              _U_(0)                                               /**< (EIC_NMICTRL) Non-Maskable Interrupt Sense Configuration Position */
#define EIC_NMICTRL_NMISENSE_Msk              (_U_(0x7) << EIC_NMICTRL_NMISENSE_Pos)               /**< (EIC_NMICTRL) Non-Maskable Interrupt Sense Configuration Mask */
#define EIC_NMICTRL_NMISENSE(value)           (EIC_NMICTRL_NMISENSE_Msk & ((value) << EIC_NMICTRL_NMISENSE_Pos))
#define   EIC_NMICTRL_NMISENSE_NONE_Val       _U_(0x0)                                             /**< (EIC_NMICTRL) No detection  */
#define   EIC_NMICTRL_NMISENSE_RISE_Val       _U_(0x1)                                             /**< (EIC_NMICTRL) Rising-edge detection  */
#define   EIC_NMICTRL_NMISENSE_FALL_Val       _U_(0x2)                                             /**< (EIC_NMICTRL) Falling-edge detection  */
#define   EIC_NMICTRL_NMISENSE_BOTH_Val       _U_(0x3)                                             /**< (EIC_NMICTRL) Both-edges detection  */
#define   EIC_NMICTRL_NMISENSE_HIGH_Val       _U_(0x4)                                             /**< (EIC_NMICTRL) High-level detection  */
#define   EIC_NMICTRL_NMISENSE_LOW_Val        _U_(0x5)                                             /**< (EIC_NMICTRL) Low-level detection  */
#define EIC_NMICTRL_NMISENSE_NONE             (EIC_NMICTRL_NMISENSE_NONE_Val << EIC_NMICTRL_NMISENSE_Pos) /**< (EIC_NMICTRL) No detection Position  */
#define EIC_NMICTRL_NMISENSE_RISE             (EIC_NMICTRL_NMISENSE_RISE_Val << EIC_NMICTRL_NMISENSE_Pos) /**< (EIC_NMICTRL) Rising-edge detection Position  */
#define EIC_NMICTRL_NMISENSE_FALL             (EIC_NMICTRL_NMISENSE_FALL_Val << EIC_NMICTRL_NMISENSE_Pos) /**< (EIC_NMICTRL) Falling-edge detection Position  */
#define EIC_NMICTRL_NMISENSE_BOTH             (EIC_NMICTRL_NMISENSE_BOTH_Val << EIC_NMICTRL_NMISENSE_Pos) /**< (EIC_NMICTRL) Both-edges detection Position  */
#define EIC_NMICTRL_NMISENSE_HIGH             (EIC_NMICTRL_NMISENSE_HIGH_Val << EIC_NMICTRL_NMISENSE_Pos) /**< (EIC_NMICTRL) High-level detection Position  */
#define EIC_NMICTRL_NMISENSE_LOW              (EIC_NMICTRL_NMISENSE_LOW_Val << EIC_NMICTRL_NMISENSE_Pos) /**< (EIC_NMICTRL) Low-level detection Position  */
#define EIC_NMICTRL_NMIFILTEN_Pos             _U_(3)                                               /**< (EIC_NMICTRL) Non-Maskable Interrupt Filter Enable Position */
#define EIC_NMICTRL_NMIFILTEN_Msk             (_U_(0x1) << EIC_NMICTRL_NMIFILTEN_Pos)              /**< (EIC_NMICTRL) Non-Maskable Interrupt Filter Enable Mask */
#define EIC_NMICTRL_NMIFILTEN(value)          (EIC_NMICTRL_NMIFILTEN_Msk & ((value) << EIC_NMICTRL_NMIFILTEN_Pos))
#define EIC_NMICTRL_NMIASYNCH_Pos             _U_(4)                                               /**< (EIC_NMICTRL) Asynchronous Edge Detection Mode Position */
#define EIC_NMICTRL_NMIASYNCH_Msk             (_U_(0x1) << EIC_NMICTRL_NMIASYNCH_Pos)              /**< (EIC_NMICTRL) Asynchronous Edge Detection Mode Mask */
#define EIC_NMICTRL_NMIASYNCH(value)          (EIC_NMICTRL_NMIASYNCH_Msk & ((value) << EIC_NMICTRL_NMIASYNCH_Pos))
#define   EIC_NMICTRL_NMIASYNCH_SYNC_Val      _U_(0x0)                                             /**< (EIC_NMICTRL) Edge detection is clock synchronously operated  */
#define   EIC_NMICTRL_NMIASYNCH_ASYNC_Val     _U_(0x1)                                             /**< (EIC_NMICTRL) Edge detection is clock asynchronously operated  */
#define EIC_NMICTRL_NMIASYNCH_SYNC            (EIC_NMICTRL_NMIASYNCH_SYNC_Val << EIC_NMICTRL_NMIASYNCH_Pos) /**< (EIC_NMICTRL) Edge detection is clock synchronously operated Position  */
#define EIC_NMICTRL_NMIASYNCH_ASYNC           (EIC_NMICTRL_NMIASYNCH_ASYNC_Val << EIC_NMICTRL_NMIASYNCH_Pos) /**< (EIC_NMICTRL) Edge detection is clock asynchronously operated Position  */
#define EIC_NMICTRL_Msk                       _U_(0x1F)                                            /**< (EIC_NMICTRL) Register Mask  */


/* -------- EIC_NMIFLAG : (EIC Offset: 0x02) (R/W 16) Non-Maskable Interrupt Flag Status and Clear -------- */
#define EIC_NMIFLAG_RESETVALUE                _U_(0x00)                                            /**<  (EIC_NMIFLAG) Non-Maskable Interrupt Flag Status and Clear  Reset Value */

#define EIC_NMIFLAG_NMI_Pos                   _U_(0)                                               /**< (EIC_NMIFLAG) Non-Maskable Interrupt Position */
#define EIC_NMIFLAG_NMI_Msk                   (_U_(0x1) << EIC_NMIFLAG_NMI_Pos)                    /**< (EIC_NMIFLAG) Non-Maskable Interrupt Mask */
#define EIC_NMIFLAG_NMI(value)                (EIC_NMIFLAG_NMI_Msk & ((value) << EIC_NMIFLAG_NMI_Pos))
#define EIC_NMIFLAG_Msk                       _U_(0x0001)                                          /**< (EIC_NMIFLAG) Register Mask  */


/* -------- EIC_SYNCBUSY : (EIC Offset: 0x04) ( R/ 32) Synchronization Busy -------- */
#define EIC_SYNCBUSY_RESETVALUE               _U_(0x00)                                            /**<  (EIC_SYNCBUSY) Synchronization Busy  Reset Value */

#define EIC_SYNCBUSY_SWRST_Pos                _U_(0)                                               /**< (EIC_SYNCBUSY) Software Reset Synchronization Busy Status Position */
#define EIC_SYNCBUSY_SWRST_Msk                (_U_(0x1) << EIC_SYNCBUSY_SWRST_Pos)                 /**< (EIC_SYNCBUSY) Software Reset Synchronization Busy Status Mask */
#define EIC_SYNCBUSY_SWRST(value)             (EIC_SYNCBUSY_SWRST_Msk & ((value) << EIC_SYNCBUSY_SWRST_Pos))
#define EIC_SYNCBUSY_ENABLE_Pos               _U_(1)                                               /**< (EIC_SYNCBUSY) Enable Synchronization Busy Status Position */
#define EIC_SYNCBUSY_ENABLE_Msk               (_U_(0x1) << EIC_SYNCBUSY_ENABLE_Pos)                /**< (EIC_SYNCBUSY) Enable Synchronization Busy Status Mask */
#define EIC_SYNCBUSY_ENABLE(value)            (EIC_SYNCBUSY_ENABLE_Msk & ((value) << EIC_SYNCBUSY_ENABLE_Pos))
#define EIC_SYNCBUSY_Msk                      _U_(0x00000003)                                      /**< (EIC_SYNCBUSY) Register Mask  */


/* -------- EIC_EVCTRL : (EIC Offset: 0x08) (R/W 32) Event Control -------- */
#define EIC_EVCTRL_RESETVALUE                 _U_(0x00)                                            /**<  (EIC_EVCTRL) Event Control  Reset Value */

#define EIC_EVCTRL_EXTINTEO0_Pos              _U_(0)                                               /**< (EIC_EVCTRL) External Interrupt 0 Event Output Enable Position */
#define EIC_EVCTRL_EXTINTEO0_Msk              (_U_(0x1) << EIC_EVCTRL_EXTINTEO0_Pos)               /**< (EIC_EVCTRL) External Interrupt 0 Event Output Enable Mask */
#define EIC_EVCTRL_EXTINTEO0(value)           (EIC_EVCTRL_EXTINTEO0_Msk & ((value) << EIC_EVCTRL_EXTINTEO0_Pos))
#define EIC_EVCTRL_EXTINTEO1_Pos              _U_(1)                                               /**< (EIC_EVCTRL) External Interrupt 1 Event Output Enable Position */
#define EIC_EVCTRL_EXTINTEO1_Msk              (_U_(0x1) << EIC_EVCTRL_EXTINTEO1_Pos)               /**< (EIC_EVCTRL) External Interrupt 1 Event Output Enable Mask */
#define EIC_EVCTRL_EXTINTEO1(value)           (EIC_EVCTRL_EXTINTEO1_Msk & ((value) << EIC_EVCTRL_EXTINTEO1_Pos))
#define EIC_EVCTRL_EXTINTEO2_Pos              _U_(2)                                               /**< (EIC_EVCTRL) External Interrupt 2 Event Output Enable Position */
#define EIC_EVCTRL_EXTINTEO2_Msk              (_U_(0x1) << EIC_EVCTRL_EXTINTEO2_Pos)               /**< (EIC_EVCTRL) External Interrupt 2 Event Output Enable Mask */
#define EIC_EVCTRL_EXTINTEO2(value)           (EIC_EVCTRL_EXTINTEO2_Msk & ((value) << EIC_EVCTRL_EXTINTEO2_Pos))
#define EIC_EVCTRL_EXTINTEO3_Pos              _U_(3)                                               /**< (EIC_EVCTRL) External Interrupt 3 Event Output Enable Position */
#define EIC_EVCTRL_EXTINTEO3_Msk              (_U_(0x1) << EIC_EVCTRL_EXTINTEO3_Pos)               /**< (EIC_EVCTRL) External Interrupt 3 Event Output Enable Mask */
#define EIC_EVCTRL_EXTINTEO3(value)           (EIC_EVCTRL_EXTINTEO3_Msk & ((value) << EIC_EVCTRL_EXTINTEO3_Pos))
#define EIC_EVCTRL_EXTINTEO4_Pos              _U_(4)                                               /**< (EIC_EVCTRL) External Interrupt 4 Event Output Enable Position */
#define EIC_EVCTRL_EXTINTEO4_Msk              (_U_(0x1) << EIC_EVCTRL_EXTINTEO4_Pos)               /**< (EIC_EVCTRL) External Interrupt 4 Event Output Enable Mask */
#define EIC_EVCTRL_EXTINTEO4(value)           (EIC_EVCTRL_EXTINTEO4_Msk & ((value) << EIC_EVCTRL_EXTINTEO4_Pos))
#define EIC_EVCTRL_EXTINTEO5_Pos              _U_(5)                                               /**< (EIC_EVCTRL) External Interrupt 5 Event Output Enable Position */
#define EIC_EVCTRL_EXTINTEO5_Msk              (_U_(0x1) << EIC_EVCTRL_EXTINTEO5_Pos)               /**< (EIC_EVCTRL) External Interrupt 5 Event Output Enable Mask */
#define EIC_EVCTRL_EXTINTEO5(value)           (EIC_EVCTRL_EXTINTEO5_Msk & ((value) << EIC_EVCTRL_EXTINTEO5_Pos))
#define EIC_EVCTRL_EXTINTEO6_Pos              _U_(6)                                               /**< (EIC_EVCTRL) External Interrupt 6 Event Output Enable Position */
#define EIC_EVCTRL_EXTINTEO6_Msk              (_U_(0x1) << EIC_EVCTRL_EXTINTEO6_Pos)               /**< (EIC_EVCTRL) External Interrupt 6 Event Output Enable Mask */
#define EIC_EVCTRL_EXTINTEO6(value)           (EIC_EVCTRL_EXTINTEO6_Msk & ((value) << EIC_EVCTRL_EXTINTEO6_Pos))
#define EIC_EVCTRL_EXTINTEO7_Pos              _U_(7)                                               /**< (EIC_EVCTRL) External Interrupt 7 Event Output Enable Position */
#define EIC_EVCTRL_EXTINTEO7_Msk              (_U_(0x1) << EIC_EVCTRL_EXTINTEO7_Pos)               /**< (EIC_EVCTRL) External Interrupt 7 Event Output Enable Mask */
#define EIC_EVCTRL_EXTINTEO7(value)           (EIC_EVCTRL_EXTINTEO7_Msk & ((value) << EIC_EVCTRL_EXTINTEO7_Pos))
#define EIC_EVCTRL_EXTINTEO8_Pos              _U_(8)                                               /**< (EIC_EVCTRL) External Interrupt 8 Event Output Enable Position */
#define EIC_EVCTRL_EXTINTEO8_Msk              (_U_(0x1) << EIC_EVCTRL_EXTINTEO8_Pos)               /**< (EIC_EVCTRL) External Interrupt 8 Event Output Enable Mask */
#define EIC_EVCTRL_EXTINTEO8(value)           (EIC_EVCTRL_EXTINTEO8_Msk & ((value) << EIC_EVCTRL_EXTINTEO8_Pos))
#define EIC_EVCTRL_EXTINTEO9_Pos              _U_(9)                                               /**< (EIC_EVCTRL) External Interrupt 9 Event Output Enable Position */
#define EIC_EVCTRL_EXTINTEO9_Msk              (_U_(0x1) << EIC_EVCTRL_EXTINTEO9_Pos)               /**< (EIC_EVCTRL) External Interrupt 9 Event Output Enable Mask */
#define EIC_EVCTRL_EXTINTEO9(value)           (EIC_EVCTRL_EXTINTEO9_Msk & ((value) << EIC_EVCTRL_EXTINTEO9_Pos))
#define EIC_EVCTRL_EXTINTEO10_Pos             _U_(10)                                              /**< (EIC_EVCTRL) External Interrupt 10 Event Output Enable Position */
#define EIC_EVCTRL_EXTINTEO10_Msk             (_U_(0x1) << EIC_EVCTRL_EXTINTEO10_Pos)              /**< (EIC_EVCTRL) External Interrupt 10 Event Output Enable Mask */
#define EIC_EVCTRL_EXTINTEO10(value)          (EIC_EVCTRL_EXTINTEO10_Msk & ((value) << EIC_EVCTRL_EXTINTEO10_Pos))
#define EIC_EVCTRL_EXTINTEO11_Pos             _U_(11)                                              /**< (EIC_EVCTRL) External Interrupt 11 Event Output Enable Position */
#define EIC_EVCTRL_EXTINTEO11_Msk             (_U_(0x1) << EIC_EVCTRL_EXTINTEO11_Pos)              /**< (EIC_EVCTRL) External Interrupt 11 Event Output Enable Mask */
#define EIC_EVCTRL_EXTINTEO11(value)          (EIC_EVCTRL_EXTINTEO11_Msk & ((value) << EIC_EVCTRL_EXTINTEO11_Pos))
#define EIC_EVCTRL_EXTINTEO12_Pos             _U_(12)                                              /**< (EIC_EVCTRL) External Interrupt 12 Event Output Enable Position */
#define EIC_EVCTRL_EXTINTEO12_Msk             (_U_(0x1) << EIC_EVCTRL_EXTINTEO12_Pos)              /**< (EIC_EVCTRL) External Interrupt 12 Event Output Enable Mask */
#define EIC_EVCTRL_EXTINTEO12(value)          (EIC_EVCTRL_EXTINTEO12_Msk & ((value) << EIC_EVCTRL_EXTINTEO12_Pos))
#define EIC_EVCTRL_EXTINTEO13_Pos             _U_(13)                                              /**< (EIC_EVCTRL) External Interrupt 13 Event Output Enable Position */
#define EIC_EVCTRL_EXTINTEO13_Msk             (_U_(0x1) << EIC_EVCTRL_EXTINTEO13_Pos)              /**< (EIC_EVCTRL) External Interrupt 13 Event Output Enable Mask */
#define EIC_EVCTRL_EXTINTEO13(value)          (EIC_EVCTRL_EXTINTEO13_Msk & ((value) << EIC_EVCTRL_EXTINTEO13_Pos))
#define EIC_EVCTRL_EXTINTEO14_Pos             _U_(14)                                              /**< (EIC_EVCTRL) External Interrupt 14 Event Output Enable Position */
#define EIC_EVCTRL_EXTINTEO14_Msk             (_U_(0x1) << EIC_EVCTRL_EXTINTEO14_Pos)              /**< (EIC_EVCTRL) External Interrupt 14 Event Output Enable Mask */
#define EIC_EVCTRL_EXTINTEO14(value)          (EIC_EVCTRL_EXTINTEO14_Msk & ((value) << EIC_EVCTRL_EXTINTEO14_Pos))
#define EIC_EVCTRL_EXTINTEO15_Pos             _U_(15)                                              /**< (EIC_EVCTRL) External Interrupt 15 Event Output Enable Position */
#define EIC_EVCTRL_EXTINTEO15_Msk             (_U_(0x1) << EIC_EVCTRL_EXTINTEO15_Pos)              /**< (EIC_EVCTRL) External Interrupt 15 Event Output Enable Mask */
#define EIC_EVCTRL_EXTINTEO15(value)          (EIC_EVCTRL_EXTINTEO15_Msk & ((value) << EIC_EVCTRL_EXTINTEO15_Pos))
#define EIC_EVCTRL_Msk                        _U_(0x0000FFFF)                                      /**< (EIC_EVCTRL) Register Mask  */

#define EIC_EVCTRL_EXTINTEO_Pos               _U_(0)                                               /**< (EIC_EVCTRL Position) External Interrupt x5 Event Output Enable */
#define EIC_EVCTRL_EXTINTEO_Msk               (_U_(0xFFFF) << EIC_EVCTRL_EXTINTEO_Pos)             /**< (EIC_EVCTRL Mask) EXTINTEO */
#define EIC_EVCTRL_EXTINTEO(value)            (EIC_EVCTRL_EXTINTEO_Msk & ((value) << EIC_EVCTRL_EXTINTEO_Pos)) 

/* -------- EIC_INTENCLR : (EIC Offset: 0x0C) (R/W 32) Interrupt Enable Clear -------- */
#define EIC_INTENCLR_RESETVALUE               _U_(0x00)                                            /**<  (EIC_INTENCLR) Interrupt Enable Clear  Reset Value */

#define EIC_INTENCLR_EXTINT0_Pos              _U_(0)                                               /**< (EIC_INTENCLR) External Interrupt 0 Enable Position */
#define EIC_INTENCLR_EXTINT0_Msk              (_U_(0x1) << EIC_INTENCLR_EXTINT0_Pos)               /**< (EIC_INTENCLR) External Interrupt 0 Enable Mask */
#define EIC_INTENCLR_EXTINT0(value)           (EIC_INTENCLR_EXTINT0_Msk & ((value) << EIC_INTENCLR_EXTINT0_Pos))
#define EIC_INTENCLR_EXTINT1_Pos              _U_(1)                                               /**< (EIC_INTENCLR) External Interrupt 1 Enable Position */
#define EIC_INTENCLR_EXTINT1_Msk              (_U_(0x1) << EIC_INTENCLR_EXTINT1_Pos)               /**< (EIC_INTENCLR) External Interrupt 1 Enable Mask */
#define EIC_INTENCLR_EXTINT1(value)           (EIC_INTENCLR_EXTINT1_Msk & ((value) << EIC_INTENCLR_EXTINT1_Pos))
#define EIC_INTENCLR_EXTINT2_Pos              _U_(2)                                               /**< (EIC_INTENCLR) External Interrupt 2 Enable Position */
#define EIC_INTENCLR_EXTINT2_Msk              (_U_(0x1) << EIC_INTENCLR_EXTINT2_Pos)               /**< (EIC_INTENCLR) External Interrupt 2 Enable Mask */
#define EIC_INTENCLR_EXTINT2(value)           (EIC_INTENCLR_EXTINT2_Msk & ((value) << EIC_INTENCLR_EXTINT2_Pos))
#define EIC_INTENCLR_EXTINT3_Pos              _U_(3)                                               /**< (EIC_INTENCLR) External Interrupt 3 Enable Position */
#define EIC_INTENCLR_EXTINT3_Msk              (_U_(0x1) << EIC_INTENCLR_EXTINT3_Pos)               /**< (EIC_INTENCLR) External Interrupt 3 Enable Mask */
#define EIC_INTENCLR_EXTINT3(value)           (EIC_INTENCLR_EXTINT3_Msk & ((value) << EIC_INTENCLR_EXTINT3_Pos))
#define EIC_INTENCLR_EXTINT4_Pos              _U_(4)                                               /**< (EIC_INTENCLR) External Interrupt 4 Enable Position */
#define EIC_INTENCLR_EXTINT4_Msk              (_U_(0x1) << EIC_INTENCLR_EXTINT4_Pos)               /**< (EIC_INTENCLR) External Interrupt 4 Enable Mask */
#define EIC_INTENCLR_EXTINT4(value)           (EIC_INTENCLR_EXTINT4_Msk & ((value) << EIC_INTENCLR_EXTINT4_Pos))
#define EIC_INTENCLR_EXTINT5_Pos              _U_(5)                                               /**< (EIC_INTENCLR) External Interrupt 5 Enable Position */
#define EIC_INTENCLR_EXTINT5_Msk              (_U_(0x1) << EIC_INTENCLR_EXTINT5_Pos)               /**< (EIC_INTENCLR) External Interrupt 5 Enable Mask */
#define EIC_INTENCLR_EXTINT5(value)           (EIC_INTENCLR_EXTINT5_Msk & ((value) << EIC_INTENCLR_EXTINT5_Pos))
#define EIC_INTENCLR_EXTINT6_Pos              _U_(6)                                               /**< (EIC_INTENCLR) External Interrupt 6 Enable Position */
#define EIC_INTENCLR_EXTINT6_Msk              (_U_(0x1) << EIC_INTENCLR_EXTINT6_Pos)               /**< (EIC_INTENCLR) External Interrupt 6 Enable Mask */
#define EIC_INTENCLR_EXTINT6(value)           (EIC_INTENCLR_EXTINT6_Msk & ((value) << EIC_INTENCLR_EXTINT6_Pos))
#define EIC_INTENCLR_EXTINT7_Pos              _U_(7)                                               /**< (EIC_INTENCLR) External Interrupt 7 Enable Position */
#define EIC_INTENCLR_EXTINT7_Msk              (_U_(0x1) << EIC_INTENCLR_EXTINT7_Pos)               /**< (EIC_INTENCLR) External Interrupt 7 Enable Mask */
#define EIC_INTENCLR_EXTINT7(value)           (EIC_INTENCLR_EXTINT7_Msk & ((value) << EIC_INTENCLR_EXTINT7_Pos))
#define EIC_INTENCLR_EXTINT8_Pos              _U_(8)                                               /**< (EIC_INTENCLR) External Interrupt 8 Enable Position */
#define EIC_INTENCLR_EXTINT8_Msk              (_U_(0x1) << EIC_INTENCLR_EXTINT8_Pos)               /**< (EIC_INTENCLR) External Interrupt 8 Enable Mask */
#define EIC_INTENCLR_EXTINT8(value)           (EIC_INTENCLR_EXTINT8_Msk & ((value) << EIC_INTENCLR_EXTINT8_Pos))
#define EIC_INTENCLR_EXTINT9_Pos              _U_(9)                                               /**< (EIC_INTENCLR) External Interrupt 9 Enable Position */
#define EIC_INTENCLR_EXTINT9_Msk              (_U_(0x1) << EIC_INTENCLR_EXTINT9_Pos)               /**< (EIC_INTENCLR) External Interrupt 9 Enable Mask */
#define EIC_INTENCLR_EXTINT9(value)           (EIC_INTENCLR_EXTINT9_Msk & ((value) << EIC_INTENCLR_EXTINT9_Pos))
#define EIC_INTENCLR_EXTINT10_Pos             _U_(10)                                              /**< (EIC_INTENCLR) External Interrupt 10 Enable Position */
#define EIC_INTENCLR_EXTINT10_Msk             (_U_(0x1) << EIC_INTENCLR_EXTINT10_Pos)              /**< (EIC_INTENCLR) External Interrupt 10 Enable Mask */
#define EIC_INTENCLR_EXTINT10(value)          (EIC_INTENCLR_EXTINT10_Msk & ((value) << EIC_INTENCLR_EXTINT10_Pos))
#define EIC_INTENCLR_EXTINT11_Pos             _U_(11)                                              /**< (EIC_INTENCLR) External Interrupt 11 Enable Position */
#define EIC_INTENCLR_EXTINT11_Msk             (_U_(0x1) << EIC_INTENCLR_EXTINT11_Pos)              /**< (EIC_INTENCLR) External Interrupt 11 Enable Mask */
#define EIC_INTENCLR_EXTINT11(value)          (EIC_INTENCLR_EXTINT11_Msk & ((value) << EIC_INTENCLR_EXTINT11_Pos))
#define EIC_INTENCLR_EXTINT12_Pos             _U_(12)                                              /**< (EIC_INTENCLR) External Interrupt 12 Enable Position */
#define EIC_INTENCLR_EXTINT12_Msk             (_U_(0x1) << EIC_INTENCLR_EXTINT12_Pos)              /**< (EIC_INTENCLR) External Interrupt 12 Enable Mask */
#define EIC_INTENCLR_EXTINT12(value)          (EIC_INTENCLR_EXTINT12_Msk & ((value) << EIC_INTENCLR_EXTINT12_Pos))
#define EIC_INTENCLR_EXTINT13_Pos             _U_(13)                                              /**< (EIC_INTENCLR) External Interrupt 13 Enable Position */
#define EIC_INTENCLR_EXTINT13_Msk             (_U_(0x1) << EIC_INTENCLR_EXTINT13_Pos)              /**< (EIC_INTENCLR) External Interrupt 13 Enable Mask */
#define EIC_INTENCLR_EXTINT13(value)          (EIC_INTENCLR_EXTINT13_Msk & ((value) << EIC_INTENCLR_EXTINT13_Pos))
#define EIC_INTENCLR_EXTINT14_Pos             _U_(14)                                              /**< (EIC_INTENCLR) External Interrupt 14 Enable Position */
#define EIC_INTENCLR_EXTINT14_Msk             (_U_(0x1) << EIC_INTENCLR_EXTINT14_Pos)              /**< (EIC_INTENCLR) External Interrupt 14 Enable Mask */
#define EIC_INTENCLR_EXTINT14(value)          (EIC_INTENCLR_EXTINT14_Msk & ((value) << EIC_INTENCLR_EXTINT14_Pos))
#define EIC_INTENCLR_EXTINT15_Pos             _U_(15)                                              /**< (EIC_INTENCLR) External Interrupt 15 Enable Position */
#define EIC_INTENCLR_EXTINT15_Msk             (_U_(0x1) << EIC_INTENCLR_EXTINT15_Pos)              /**< (EIC_INTENCLR) External Interrupt 15 Enable Mask */
#define EIC_INTENCLR_EXTINT15(value)          (EIC_INTENCLR_EXTINT15_Msk & ((value) << EIC_INTENCLR_EXTINT15_Pos))
#define EIC_INTENCLR_Msk                      _U_(0x0000FFFF)                                      /**< (EIC_INTENCLR) Register Mask  */

#define EIC_INTENCLR_EXTINT_Pos               _U_(0)                                               /**< (EIC_INTENCLR Position) External Interrupt x5 Enable */
#define EIC_INTENCLR_EXTINT_Msk               (_U_(0xFFFF) << EIC_INTENCLR_EXTINT_Pos)             /**< (EIC_INTENCLR Mask) EXTINT */
#define EIC_INTENCLR_EXTINT(value)            (EIC_INTENCLR_EXTINT_Msk & ((value) << EIC_INTENCLR_EXTINT_Pos)) 

/* -------- EIC_INTENSET : (EIC Offset: 0x10) (R/W 32) Interrupt Enable Set -------- */
#define EIC_INTENSET_RESETVALUE               _U_(0x00)                                            /**<  (EIC_INTENSET) Interrupt Enable Set  Reset Value */

#define EIC_INTENSET_EXTINT0_Pos              _U_(0)                                               /**< (EIC_INTENSET) External Interrupt 0 Enable Position */
#define EIC_INTENSET_EXTINT0_Msk              (_U_(0x1) << EIC_INTENSET_EXTINT0_Pos)               /**< (EIC_INTENSET) External Interrupt 0 Enable Mask */
#define EIC_INTENSET_EXTINT0(value)           (EIC_INTENSET_EXTINT0_Msk & ((value) << EIC_INTENSET_EXTINT0_Pos))
#define EIC_INTENSET_EXTINT1_Pos              _U_(1)                                               /**< (EIC_INTENSET) External Interrupt 1 Enable Position */
#define EIC_INTENSET_EXTINT1_Msk              (_U_(0x1) << EIC_INTENSET_EXTINT1_Pos)               /**< (EIC_INTENSET) External Interrupt 1 Enable Mask */
#define EIC_INTENSET_EXTINT1(value)           (EIC_INTENSET_EXTINT1_Msk & ((value) << EIC_INTENSET_EXTINT1_Pos))
#define EIC_INTENSET_EXTINT2_Pos              _U_(2)                                               /**< (EIC_INTENSET) External Interrupt 2 Enable Position */
#define EIC_INTENSET_EXTINT2_Msk              (_U_(0x1) << EIC_INTENSET_EXTINT2_Pos)               /**< (EIC_INTENSET) External Interrupt 2 Enable Mask */
#define EIC_INTENSET_EXTINT2(value)           (EIC_INTENSET_EXTINT2_Msk & ((value) << EIC_INTENSET_EXTINT2_Pos))
#define EIC_INTENSET_EXTINT3_Pos              _U_(3)                                               /**< (EIC_INTENSET) External Interrupt 3 Enable Position */
#define EIC_INTENSET_EXTINT3_Msk              (_U_(0x1) << EIC_INTENSET_EXTINT3_Pos)               /**< (EIC_INTENSET) External Interrupt 3 Enable Mask */
#define EIC_INTENSET_EXTINT3(value)           (EIC_INTENSET_EXTINT3_Msk & ((value) << EIC_INTENSET_EXTINT3_Pos))
#define EIC_INTENSET_EXTINT4_Pos              _U_(4)                                               /**< (EIC_INTENSET) External Interrupt 4 Enable Position */
#define EIC_INTENSET_EXTINT4_Msk              (_U_(0x1) << EIC_INTENSET_EXTINT4_Pos)               /**< (EIC_INTENSET) External Interrupt 4 Enable Mask */
#define EIC_INTENSET_EXTINT4(value)           (EIC_INTENSET_EXTINT4_Msk & ((value) << EIC_INTENSET_EXTINT4_Pos))
#define EIC_INTENSET_EXTINT5_Pos              _U_(5)                                               /**< (EIC_INTENSET) External Interrupt 5 Enable Position */
#define EIC_INTENSET_EXTINT5_Msk              (_U_(0x1) << EIC_INTENSET_EXTINT5_Pos)               /**< (EIC_INTENSET) External Interrupt 5 Enable Mask */
#define EIC_INTENSET_EXTINT5(value)           (EIC_INTENSET_EXTINT5_Msk & ((value) << EIC_INTENSET_EXTINT5_Pos))
#define EIC_INTENSET_EXTINT6_Pos              _U_(6)                                               /**< (EIC_INTENSET) External Interrupt 6 Enable Position */
#define EIC_INTENSET_EXTINT6_Msk              (_U_(0x1) << EIC_INTENSET_EXTINT6_Pos)               /**< (EIC_INTENSET) External Interrupt 6 Enable Mask */
#define EIC_INTENSET_EXTINT6(value)           (EIC_INTENSET_EXTINT6_Msk & ((value) << EIC_INTENSET_EXTINT6_Pos))
#define EIC_INTENSET_EXTINT7_Pos              _U_(7)                                               /**< (EIC_INTENSET) External Interrupt 7 Enable Position */
#define EIC_INTENSET_EXTINT7_Msk              (_U_(0x1) << EIC_INTENSET_EXTINT7_Pos)               /**< (EIC_INTENSET) External Interrupt 7 Enable Mask */
#define EIC_INTENSET_EXTINT7(value)           (EIC_INTENSET_EXTINT7_Msk & ((value) << EIC_INTENSET_EXTINT7_Pos))
#define EIC_INTENSET_EXTINT8_Pos              _U_(8)                                               /**< (EIC_INTENSET) External Interrupt 8 Enable Position */
#define EIC_INTENSET_EXTINT8_Msk              (_U_(0x1) << EIC_INTENSET_EXTINT8_Pos)               /**< (EIC_INTENSET) External Interrupt 8 Enable Mask */
#define EIC_INTENSET_EXTINT8(value)           (EIC_INTENSET_EXTINT8_Msk & ((value) << EIC_INTENSET_EXTINT8_Pos))
#define EIC_INTENSET_EXTINT9_Pos              _U_(9)                                               /**< (EIC_INTENSET) External Interrupt 9 Enable Position */
#define EIC_INTENSET_EXTINT9_Msk              (_U_(0x1) << EIC_INTENSET_EXTINT9_Pos)               /**< (EIC_INTENSET) External Interrupt 9 Enable Mask */
#define EIC_INTENSET_EXTINT9(value)           (EIC_INTENSET_EXTINT9_Msk & ((value) << EIC_INTENSET_EXTINT9_Pos))
#define EIC_INTENSET_EXTINT10_Pos             _U_(10)                                              /**< (EIC_INTENSET) External Interrupt 10 Enable Position */
#define EIC_INTENSET_EXTINT10_Msk             (_U_(0x1) << EIC_INTENSET_EXTINT10_Pos)              /**< (EIC_INTENSET) External Interrupt 10 Enable Mask */
#define EIC_INTENSET_EXTINT10(value)          (EIC_INTENSET_EXTINT10_Msk & ((value) << EIC_INTENSET_EXTINT10_Pos))
#define EIC_INTENSET_EXTINT11_Pos             _U_(11)                                              /**< (EIC_INTENSET) External Interrupt 11 Enable Position */
#define EIC_INTENSET_EXTINT11_Msk             (_U_(0x1) << EIC_INTENSET_EXTINT11_Pos)              /**< (EIC_INTENSET) External Interrupt 11 Enable Mask */
#define EIC_INTENSET_EXTINT11(value)          (EIC_INTENSET_EXTINT11_Msk & ((value) << EIC_INTENSET_EXTINT11_Pos))
#define EIC_INTENSET_EXTINT12_Pos             _U_(12)                                              /**< (EIC_INTENSET) External Interrupt 12 Enable Position */
#define EIC_INTENSET_EXTINT12_Msk             (_U_(0x1) << EIC_INTENSET_EXTINT12_Pos)              /**< (EIC_INTENSET) External Interrupt 12 Enable Mask */
#define EIC_INTENSET_EXTINT12(value)          (EIC_INTENSET_EXTINT12_Msk & ((value) << EIC_INTENSET_EXTINT12_Pos))
#define EIC_INTENSET_EXTINT13_Pos             _U_(13)                                              /**< (EIC_INTENSET) External Interrupt 13 Enable Position */
#define EIC_INTENSET_EXTINT13_Msk             (_U_(0x1) << EIC_INTENSET_EXTINT13_Pos)              /**< (EIC_INTENSET) External Interrupt 13 Enable Mask */
#define EIC_INTENSET_EXTINT13(value)          (EIC_INTENSET_EXTINT13_Msk & ((value) << EIC_INTENSET_EXTINT13_Pos))
#define EIC_INTENSET_EXTINT14_Pos             _U_(14)                                              /**< (EIC_INTENSET) External Interrupt 14 Enable Position */
#define EIC_INTENSET_EXTINT14_Msk             (_U_(0x1) << EIC_INTENSET_EXTINT14_Pos)              /**< (EIC_INTENSET) External Interrupt 14 Enable Mask */
#define EIC_INTENSET_EXTINT14(value)          (EIC_INTENSET_EXTINT14_Msk & ((value) << EIC_INTENSET_EXTINT14_Pos))
#define EIC_INTENSET_EXTINT15_Pos             _U_(15)                                              /**< (EIC_INTENSET) External Interrupt 15 Enable Position */
#define EIC_INTENSET_EXTINT15_Msk             (_U_(0x1) << EIC_INTENSET_EXTINT15_Pos)              /**< (EIC_INTENSET) External Interrupt 15 Enable Mask */
#define EIC_INTENSET_EXTINT15(value)          (EIC_INTENSET_EXTINT15_Msk & ((value) << EIC_INTENSET_EXTINT15_Pos))
#define EIC_INTENSET_Msk                      _U_(0x0000FFFF)                                      /**< (EIC_INTENSET) Register Mask  */

#define EIC_INTENSET_EXTINT_Pos               _U_(0)                                               /**< (EIC_INTENSET Position) External Interrupt x5 Enable */
#define EIC_INTENSET_EXTINT_Msk               (_U_(0xFFFF) << EIC_INTENSET_EXTINT_Pos)             /**< (EIC_INTENSET Mask) EXTINT */
#define EIC_INTENSET_EXTINT(value)            (EIC_INTENSET_EXTINT_Msk & ((value) << EIC_INTENSET_EXTINT_Pos)) 

/* -------- EIC_INTFLAG : (EIC Offset: 0x14) (R/W 32) Interrupt Flag Status and Clear -------- */
#define EIC_INTFLAG_RESETVALUE                _U_(0x00)                                            /**<  (EIC_INTFLAG) Interrupt Flag Status and Clear  Reset Value */

#define EIC_INTFLAG_EXTINT0_Pos               _U_(0)                                               /**< (EIC_INTFLAG) External Interrupt 0 Position */
#define EIC_INTFLAG_EXTINT0_Msk               (_U_(0x1) << EIC_INTFLAG_EXTINT0_Pos)                /**< (EIC_INTFLAG) External Interrupt 0 Mask */
#define EIC_INTFLAG_EXTINT0(value)            (EIC_INTFLAG_EXTINT0_Msk & ((value) << EIC_INTFLAG_EXTINT0_Pos))
#define EIC_INTFLAG_EXTINT1_Pos               _U_(1)                                               /**< (EIC_INTFLAG) External Interrupt 1 Position */
#define EIC_INTFLAG_EXTINT1_Msk               (_U_(0x1) << EIC_INTFLAG_EXTINT1_Pos)                /**< (EIC_INTFLAG) External Interrupt 1 Mask */
#define EIC_INTFLAG_EXTINT1(value)            (EIC_INTFLAG_EXTINT1_Msk & ((value) << EIC_INTFLAG_EXTINT1_Pos))
#define EIC_INTFLAG_EXTINT2_Pos               _U_(2)                                               /**< (EIC_INTFLAG) External Interrupt 2 Position */
#define EIC_INTFLAG_EXTINT2_Msk               (_U_(0x1) << EIC_INTFLAG_EXTINT2_Pos)                /**< (EIC_INTFLAG) External Interrupt 2 Mask */
#define EIC_INTFLAG_EXTINT2(value)            (EIC_INTFLAG_EXTINT2_Msk & ((value) << EIC_INTFLAG_EXTINT2_Pos))
#define EIC_INTFLAG_EXTINT3_Pos               _U_(3)                                               /**< (EIC_INTFLAG) External Interrupt 3 Position */
#define EIC_INTFLAG_EXTINT3_Msk               (_U_(0x1) << EIC_INTFLAG_EXTINT3_Pos)                /**< (EIC_INTFLAG) External Interrupt 3 Mask */
#define EIC_INTFLAG_EXTINT3(value)            (EIC_INTFLAG_EXTINT3_Msk & ((value) << EIC_INTFLAG_EXTINT3_Pos))
#define EIC_INTFLAG_EXTINT4_Pos               _U_(4)                                               /**< (EIC_INTFLAG) External Interrupt 4 Position */
#define EIC_INTFLAG_EXTINT4_Msk               (_U_(0x1) << EIC_INTFLAG_EXTINT4_Pos)                /**< (EIC_INTFLAG) External Interrupt 4 Mask */
#define EIC_INTFLAG_EXTINT4(value)            (EIC_INTFLAG_EXTINT4_Msk & ((value) << EIC_INTFLAG_EXTINT4_Pos))
#define EIC_INTFLAG_EXTINT5_Pos               _U_(5)                                               /**< (EIC_INTFLAG) External Interrupt 5 Position */
#define EIC_INTFLAG_EXTINT5_Msk               (_U_(0x1) << EIC_INTFLAG_EXTINT5_Pos)                /**< (EIC_INTFLAG) External Interrupt 5 Mask */
#define EIC_INTFLAG_EXTINT5(value)            (EIC_INTFLAG_EXTINT5_Msk & ((value) << EIC_INTFLAG_EXTINT5_Pos))
#define EIC_INTFLAG_EXTINT6_Pos               _U_(6)                                               /**< (EIC_INTFLAG) External Interrupt 6 Position */
#define EIC_INTFLAG_EXTINT6_Msk               (_U_(0x1) << EIC_INTFLAG_EXTINT6_Pos)                /**< (EIC_INTFLAG) External Interrupt 6 Mask */
#define EIC_INTFLAG_EXTINT6(value)            (EIC_INTFLAG_EXTINT6_Msk & ((value) << EIC_INTFLAG_EXTINT6_Pos))
#define EIC_INTFLAG_EXTINT7_Pos               _U_(7)                                               /**< (EIC_INTFLAG) External Interrupt 7 Position */
#define EIC_INTFLAG_EXTINT7_Msk               (_U_(0x1) << EIC_INTFLAG_EXTINT7_Pos)                /**< (EIC_INTFLAG) External Interrupt 7 Mask */
#define EIC_INTFLAG_EXTINT7(value)            (EIC_INTFLAG_EXTINT7_Msk & ((value) << EIC_INTFLAG_EXTINT7_Pos))
#define EIC_INTFLAG_EXTINT8_Pos               _U_(8)                                               /**< (EIC_INTFLAG) External Interrupt 8 Position */
#define EIC_INTFLAG_EXTINT8_Msk               (_U_(0x1) << EIC_INTFLAG_EXTINT8_Pos)                /**< (EIC_INTFLAG) External Interrupt 8 Mask */
#define EIC_INTFLAG_EXTINT8(value)            (EIC_INTFLAG_EXTINT8_Msk & ((value) << EIC_INTFLAG_EXTINT8_Pos))
#define EIC_INTFLAG_EXTINT9_Pos               _U_(9)                                               /**< (EIC_INTFLAG) External Interrupt 9 Position */
#define EIC_INTFLAG_EXTINT9_Msk               (_U_(0x1) << EIC_INTFLAG_EXTINT9_Pos)                /**< (EIC_INTFLAG) External Interrupt 9 Mask */
#define EIC_INTFLAG_EXTINT9(value)            (EIC_INTFLAG_EXTINT9_Msk & ((value) << EIC_INTFLAG_EXTINT9_Pos))
#define EIC_INTFLAG_EXTINT10_Pos              _U_(10)                                              /**< (EIC_INTFLAG) External Interrupt 10 Position */
#define EIC_INTFLAG_EXTINT10_Msk              (_U_(0x1) << EIC_INTFLAG_EXTINT10_Pos)               /**< (EIC_INTFLAG) External Interrupt 10 Mask */
#define EIC_INTFLAG_EXTINT10(value)           (EIC_INTFLAG_EXTINT10_Msk & ((value) << EIC_INTFLAG_EXTINT10_Pos))
#define EIC_INTFLAG_EXTINT11_Pos              _U_(11)                                              /**< (EIC_INTFLAG) External Interrupt 11 Position */
#define EIC_INTFLAG_EXTINT11_Msk              (_U_(0x1) << EIC_INTFLAG_EXTINT11_Pos)               /**< (EIC_INTFLAG) External Interrupt 11 Mask */
#define EIC_INTFLAG_EXTINT11(value)           (EIC_INTFLAG_EXTINT11_Msk & ((value) << EIC_INTFLAG_EXTINT11_Pos))
#define EIC_INTFLAG_EXTINT12_Pos              _U_(12)                                              /**< (EIC_INTFLAG) External Interrupt 12 Position */
#define EIC_INTFLAG_EXTINT12_Msk              (_U_(0x1) << EIC_INTFLAG_EXTINT12_Pos)               /**< (EIC_INTFLAG) External Interrupt 12 Mask */
#define EIC_INTFLAG_EXTINT12(value)           (EIC_INTFLAG_EXTINT12_Msk & ((value) << EIC_INTFLAG_EXTINT12_Pos))
#define EIC_INTFLAG_EXTINT13_Pos              _U_(13)                                              /**< (EIC_INTFLAG) External Interrupt 13 Position */
#define EIC_INTFLAG_EXTINT13_Msk              (_U_(0x1) << EIC_INTFLAG_EXTINT13_Pos)               /**< (EIC_INTFLAG) External Interrupt 13 Mask */
#define EIC_INTFLAG_EXTINT13(value)           (EIC_INTFLAG_EXTINT13_Msk & ((value) << EIC_INTFLAG_EXTINT13_Pos))
#define EIC_INTFLAG_EXTINT14_Pos              _U_(14)                                              /**< (EIC_INTFLAG) External Interrupt 14 Position */
#define EIC_INTFLAG_EXTINT14_Msk              (_U_(0x1) << EIC_INTFLAG_EXTINT14_Pos)               /**< (EIC_INTFLAG) External Interrupt 14 Mask */
#define EIC_INTFLAG_EXTINT14(value)           (EIC_INTFLAG_EXTINT14_Msk & ((value) << EIC_INTFLAG_EXTINT14_Pos))
#define EIC_INTFLAG_EXTINT15_Pos              _U_(15)                                              /**< (EIC_INTFLAG) External Interrupt 15 Position */
#define EIC_INTFLAG_EXTINT15_Msk              (_U_(0x1) << EIC_INTFLAG_EXTINT15_Pos)               /**< (EIC_INTFLAG) External Interrupt 15 Mask */
#define EIC_INTFLAG_EXTINT15(value)           (EIC_INTFLAG_EXTINT15_Msk & ((value) << EIC_INTFLAG_EXTINT15_Pos))
#define EIC_INTFLAG_Msk                       _U_(0x0000FFFF)                                      /**< (EIC_INTFLAG) Register Mask  */

#define EIC_INTFLAG_EXTINT_Pos                _U_(0)                                               /**< (EIC_INTFLAG Position) External Interrupt x5 */
#define EIC_INTFLAG_EXTINT_Msk                (_U_(0xFFFF) << EIC_INTFLAG_EXTINT_Pos)              /**< (EIC_INTFLAG Mask) EXTINT */
#define EIC_INTFLAG_EXTINT(value)             (EIC_INTFLAG_EXTINT_Msk & ((value) << EIC_INTFLAG_EXTINT_Pos)) 

/* -------- EIC_ASYNCH : (EIC Offset: 0x18) (R/W 32) External Interrupt Asynchronous Mode -------- */
#define EIC_ASYNCH_RESETVALUE                 _U_(0x00)                                            /**<  (EIC_ASYNCH) External Interrupt Asynchronous Mode  Reset Value */

#define EIC_ASYNCH_ASYNCH0_Pos                _U_(0)                                               /**< (EIC_ASYNCH) Asynchronous Edge Detection Mode of EXTINT0 Position */
#define EIC_ASYNCH_ASYNCH0_Msk                (_U_(0x1) << EIC_ASYNCH_ASYNCH0_Pos)                 /**< (EIC_ASYNCH) Asynchronous Edge Detection Mode of EXTINT0 Mask */
#define EIC_ASYNCH_ASYNCH0(value)             (EIC_ASYNCH_ASYNCH0_Msk & ((value) << EIC_ASYNCH_ASYNCH0_Pos))
#define   EIC_ASYNCH_ASYNCH0_SYNC_Val         _U_(0x0)                                             /**< (EIC_ASYNCH) Edge detection is clock synchronously operated  */
#define   EIC_ASYNCH_ASYNCH0_ASYNC_Val        _U_(0x1)                                             /**< (EIC_ASYNCH) Edge detection is clock asynchronously operated  */
#define EIC_ASYNCH_ASYNCH0_SYNC               (EIC_ASYNCH_ASYNCH0_SYNC_Val << EIC_ASYNCH_ASYNCH0_Pos) /**< (EIC_ASYNCH) Edge detection is clock synchronously operated Position  */
#define EIC_ASYNCH_ASYNCH0_ASYNC              (EIC_ASYNCH_ASYNCH0_ASYNC_Val << EIC_ASYNCH_ASYNCH0_Pos) /**< (EIC_ASYNCH) Edge detection is clock asynchronously operated Position  */
#define EIC_ASYNCH_ASYNCH1_Pos                _U_(1)                                               /**< (EIC_ASYNCH) Asynchronous Edge Detection Mode of EXTINT1 Position */
#define EIC_ASYNCH_ASYNCH1_Msk                (_U_(0x1) << EIC_ASYNCH_ASYNCH1_Pos)                 /**< (EIC_ASYNCH) Asynchronous Edge Detection Mode of EXTINT1 Mask */
#define EIC_ASYNCH_ASYNCH1(value)             (EIC_ASYNCH_ASYNCH1_Msk & ((value) << EIC_ASYNCH_ASYNCH1_Pos))
#define   EIC_ASYNCH_ASYNCH1_SYNC_Val         _U_(0x0)                                             /**< (EIC_ASYNCH) Edge detection is clock synchronously operated  */
#define   EIC_ASYNCH_ASYNCH1_ASYNC_Val        _U_(0x1)                                             /**< (EIC_ASYNCH) Edge detection is clock asynchronously operated  */
#define EIC_ASYNCH_ASYNCH1_SYNC               (EIC_ASYNCH_ASYNCH1_SYNC_Val << EIC_ASYNCH_ASYNCH1_Pos) /**< (EIC_ASYNCH) Edge detection is clock synchronously operated Position  */
#define EIC_ASYNCH_ASYNCH1_ASYNC              (EIC_ASYNCH_ASYNCH1_ASYNC_Val << EIC_ASYNCH_ASYNCH1_Pos) /**< (EIC_ASYNCH) Edge detection is clock asynchronously operated Position  */
#define EIC_ASYNCH_ASYNCH2_Pos                _U_(2)                                               /**< (EIC_ASYNCH) Asynchronous Edge Detection Mode of EXTINT2 Position */
#define EIC_ASYNCH_ASYNCH2_Msk                (_U_(0x1) << EIC_ASYNCH_ASYNCH2_Pos)                 /**< (EIC_ASYNCH) Asynchronous Edge Detection Mode of EXTINT2 Mask */
#define EIC_ASYNCH_ASYNCH2(value)             (EIC_ASYNCH_ASYNCH2_Msk & ((value) << EIC_ASYNCH_ASYNCH2_Pos))
#define   EIC_ASYNCH_ASYNCH2_SYNC_Val         _U_(0x0)                                             /**< (EIC_ASYNCH) Edge detection is clock synchronously operated  */
#define   EIC_ASYNCH_ASYNCH2_ASYNC_Val        _U_(0x1)                                             /**< (EIC_ASYNCH) Edge detection is clock asynchronously operated  */
#define EIC_ASYNCH_ASYNCH2_SYNC               (EIC_ASYNCH_ASYNCH2_SYNC_Val << EIC_ASYNCH_ASYNCH2_Pos) /**< (EIC_ASYNCH) Edge detection is clock synchronously operated Position  */
#define EIC_ASYNCH_ASYNCH2_ASYNC              (EIC_ASYNCH_ASYNCH2_ASYNC_Val << EIC_ASYNCH_ASYNCH2_Pos) /**< (EIC_ASYNCH) Edge detection is clock asynchronously operated Position  */
#define EIC_ASYNCH_ASYNCH3_Pos                _U_(3)                                               /**< (EIC_ASYNCH) Asynchronous Edge Detection Mode of EXTINT3 Position */
#define EIC_ASYNCH_ASYNCH3_Msk                (_U_(0x1) << EIC_ASYNCH_ASYNCH3_Pos)                 /**< (EIC_ASYNCH) Asynchronous Edge Detection Mode of EXTINT3 Mask */
#define EIC_ASYNCH_ASYNCH3(value)             (EIC_ASYNCH_ASYNCH3_Msk & ((value) << EIC_ASYNCH_ASYNCH3_Pos))
#define   EIC_ASYNCH_ASYNCH3_SYNC_Val         _U_(0x0)                                             /**< (EIC_ASYNCH) Edge detection is clock synchronously operated  */
#define   EIC_ASYNCH_ASYNCH3_ASYNC_Val        _U_(0x1)                                             /**< (EIC_ASYNCH) Edge detection is clock asynchronously operated  */
#define EIC_ASYNCH_ASYNCH3_SYNC               (EIC_ASYNCH_ASYNCH3_SYNC_Val << EIC_ASYNCH_ASYNCH3_Pos) /**< (EIC_ASYNCH) Edge detection is clock synchronously operated Position  */
#define EIC_ASYNCH_ASYNCH3_ASYNC              (EIC_ASYNCH_ASYNCH3_ASYNC_Val << EIC_ASYNCH_ASYNCH3_Pos) /**< (EIC_ASYNCH) Edge detection is clock asynchronously operated Position  */
#define EIC_ASYNCH_ASYNCH4_Pos                _U_(4)                                               /**< (EIC_ASYNCH) Asynchronous Edge Detection Mode of EXTINT4 Position */
#define EIC_ASYNCH_ASYNCH4_Msk                (_U_(0x1) << EIC_ASYNCH_ASYNCH4_Pos)                 /**< (EIC_ASYNCH) Asynchronous Edge Detection Mode of EXTINT4 Mask */
#define EIC_ASYNCH_ASYNCH4(value)             (EIC_ASYNCH_ASYNCH4_Msk & ((value) << EIC_ASYNCH_ASYNCH4_Pos))
#define   EIC_ASYNCH_ASYNCH4_SYNC_Val         _U_(0x0)                                             /**< (EIC_ASYNCH) Edge detection is clock synchronously operated  */
#define   EIC_ASYNCH_ASYNCH4_ASYNC_Val        _U_(0x1)                                             /**< (EIC_ASYNCH) Edge detection is clock asynchronously operated  */
#define EIC_ASYNCH_ASYNCH4_SYNC               (EIC_ASYNCH_ASYNCH4_SYNC_Val << EIC_ASYNCH_ASYNCH4_Pos) /**< (EIC_ASYNCH) Edge detection is clock synchronously operated Position  */
#define EIC_ASYNCH_ASYNCH4_ASYNC              (EIC_ASYNCH_ASYNCH4_ASYNC_Val << EIC_ASYNCH_ASYNCH4_Pos) /**< (EIC_ASYNCH) Edge detection is clock asynchronously operated Position  */
#define EIC_ASYNCH_ASYNCH5_Pos                _U_(5)                                               /**< (EIC_ASYNCH) Asynchronous Edge Detection Mode of EXTINT5 Position */
#define EIC_ASYNCH_ASYNCH5_Msk                (_U_(0x1) << EIC_ASYNCH_ASYNCH5_Pos)                 /**< (EIC_ASYNCH) Asynchronous Edge Detection Mode of EXTINT5 Mask */
#define EIC_ASYNCH_ASYNCH5(value)             (EIC_ASYNCH_ASYNCH5_Msk & ((value) << EIC_ASYNCH_ASYNCH5_Pos))
#define   EIC_ASYNCH_ASYNCH5_SYNC_Val         _U_(0x0)                                             /**< (EIC_ASYNCH) Edge detection is clock synchronously operated  */
#define   EIC_ASYNCH_ASYNCH5_ASYNC_Val        _U_(0x1)                                             /**< (EIC_ASYNCH) Edge detection is clock asynchronously operated  */
#define EIC_ASYNCH_ASYNCH5_SYNC               (EIC_ASYNCH_ASYNCH5_SYNC_Val << EIC_ASYNCH_ASYNCH5_Pos) /**< (EIC_ASYNCH) Edge detection is clock synchronously operated Position  */
#define EIC_ASYNCH_ASYNCH5_ASYNC              (EIC_ASYNCH_ASYNCH5_ASYNC_Val << EIC_ASYNCH_ASYNCH5_Pos) /**< (EIC_ASYNCH) Edge detection is clock asynchronously operated Position  */
#define EIC_ASYNCH_ASYNCH6_Pos                _U_(6)                                               /**< (EIC_ASYNCH) Asynchronous Edge Detection Mode of EXTINT6 Position */
#define EIC_ASYNCH_ASYNCH6_Msk                (_U_(0x1) << EIC_ASYNCH_ASYNCH6_Pos)                 /**< (EIC_ASYNCH) Asynchronous Edge Detection Mode of EXTINT6 Mask */
#define EIC_ASYNCH_ASYNCH6(value)             (EIC_ASYNCH_ASYNCH6_Msk & ((value) << EIC_ASYNCH_ASYNCH6_Pos))
#define   EIC_ASYNCH_ASYNCH6_SYNC_Val         _U_(0x0)                                             /**< (EIC_ASYNCH) Edge detection is clock synchronously operated  */
#define   EIC_ASYNCH_ASYNCH6_ASYNC_Val        _U_(0x1)                                             /**< (EIC_ASYNCH) Edge detection is clock asynchronously operated  */
#define EIC_ASYNCH_ASYNCH6_SYNC               (EIC_ASYNCH_ASYNCH6_SYNC_Val << EIC_ASYNCH_ASYNCH6_Pos) /**< (EIC_ASYNCH) Edge detection is clock synchronously operated Position  */
#define EIC_ASYNCH_ASYNCH6_ASYNC              (EIC_ASYNCH_ASYNCH6_ASYNC_Val << EIC_ASYNCH_ASYNCH6_Pos) /**< (EIC_ASYNCH) Edge detection is clock asynchronously operated Position  */
#define EIC_ASYNCH_ASYNCH7_Pos                _U_(7)                                               /**< (EIC_ASYNCH) Asynchronous Edge Detection Mode of EXTINT7 Position */
#define EIC_ASYNCH_ASYNCH7_Msk                (_U_(0x1) << EIC_ASYNCH_ASYNCH7_Pos)                 /**< (EIC_ASYNCH) Asynchronous Edge Detection Mode of EXTINT7 Mask */
#define EIC_ASYNCH_ASYNCH7(value)             (EIC_ASYNCH_ASYNCH7_Msk & ((value) << EIC_ASYNCH_ASYNCH7_Pos))
#define   EIC_ASYNCH_ASYNCH7_SYNC_Val         _U_(0x0)                                             /**< (EIC_ASYNCH) Edge detection is clock synchronously operated  */
#define   EIC_ASYNCH_ASYNCH7_ASYNC_Val        _U_(0x1)                                             /**< (EIC_ASYNCH) Edge detection is clock asynchronously operated  */
#define EIC_ASYNCH_ASYNCH7_SYNC               (EIC_ASYNCH_ASYNCH7_SYNC_Val << EIC_ASYNCH_ASYNCH7_Pos) /**< (EIC_ASYNCH) Edge detection is clock synchronously operated Position  */
#define EIC_ASYNCH_ASYNCH7_ASYNC              (EIC_ASYNCH_ASYNCH7_ASYNC_Val << EIC_ASYNCH_ASYNCH7_Pos) /**< (EIC_ASYNCH) Edge detection is clock asynchronously operated Position  */
#define EIC_ASYNCH_ASYNCH8_Pos                _U_(8)                                               /**< (EIC_ASYNCH) Asynchronous Edge Detection Mode of EXTINT8 Position */
#define EIC_ASYNCH_ASYNCH8_Msk                (_U_(0x1) << EIC_ASYNCH_ASYNCH8_Pos)                 /**< (EIC_ASYNCH) Asynchronous Edge Detection Mode of EXTINT8 Mask */
#define EIC_ASYNCH_ASYNCH8(value)             (EIC_ASYNCH_ASYNCH8_Msk & ((value) << EIC_ASYNCH_ASYNCH8_Pos))
#define   EIC_ASYNCH_ASYNCH8_SYNC_Val         _U_(0x0)                                             /**< (EIC_ASYNCH) Edge detection is clock synchronously operated  */
#define   EIC_ASYNCH_ASYNCH8_ASYNC_Val        _U_(0x1)                                             /**< (EIC_ASYNCH) Edge detection is clock asynchronously operated  */
#define EIC_ASYNCH_ASYNCH8_SYNC               (EIC_ASYNCH_ASYNCH8_SYNC_Val << EIC_ASYNCH_ASYNCH8_Pos) /**< (EIC_ASYNCH) Edge detection is clock synchronously operated Position  */
#define EIC_ASYNCH_ASYNCH8_ASYNC              (EIC_ASYNCH_ASYNCH8_ASYNC_Val << EIC_ASYNCH_ASYNCH8_Pos) /**< (EIC_ASYNCH) Edge detection is clock asynchronously operated Position  */
#define EIC_ASYNCH_ASYNCH9_Pos                _U_(9)                                               /**< (EIC_ASYNCH) Asynchronous Edge Detection Mode of EXTINT9 Position */
#define EIC_ASYNCH_ASYNCH9_Msk                (_U_(0x1) << EIC_ASYNCH_ASYNCH9_Pos)                 /**< (EIC_ASYNCH) Asynchronous Edge Detection Mode of EXTINT9 Mask */
#define EIC_ASYNCH_ASYNCH9(value)             (EIC_ASYNCH_ASYNCH9_Msk & ((value) << EIC_ASYNCH_ASYNCH9_Pos))
#define   EIC_ASYNCH_ASYNCH9_SYNC_Val         _U_(0x0)                                             /**< (EIC_ASYNCH) Edge detection is clock synchronously operated  */
#define   EIC_ASYNCH_ASYNCH9_ASYNC_Val        _U_(0x1)                                             /**< (EIC_ASYNCH) Edge detection is clock asynchronously operated  */
#define EIC_ASYNCH_ASYNCH9_SYNC               (EIC_ASYNCH_ASYNCH9_SYNC_Val << EIC_ASYNCH_ASYNCH9_Pos) /**< (EIC_ASYNCH) Edge detection is clock synchronously operated Position  */
#define EIC_ASYNCH_ASYNCH9_ASYNC              (EIC_ASYNCH_ASYNCH9_ASYNC_Val << EIC_ASYNCH_ASYNCH9_Pos) /**< (EIC_ASYNCH) Edge detection is clock asynchronously operated Position  */
#define EIC_ASYNCH_ASYNCH10_Pos               _U_(10)                                              /**< (EIC_ASYNCH) Asynchronous Edge Detection Mode of EXTINT10 Position */
#define EIC_ASYNCH_ASYNCH10_Msk               (_U_(0x1) << EIC_ASYNCH_ASYNCH10_Pos)                /**< (EIC_ASYNCH) Asynchronous Edge Detection Mode of EXTINT10 Mask */
#define EIC_ASYNCH_ASYNCH10(value)            (EIC_ASYNCH_ASYNCH10_Msk & ((value) << EIC_ASYNCH_ASYNCH10_Pos))
#define   EIC_ASYNCH_ASYNCH10_SYNC_Val        _U_(0x0)                                             /**< (EIC_ASYNCH) Edge detection is clock synchronously operated  */
#define   EIC_ASYNCH_ASYNCH10_ASYNC_Val       _U_(0x1)                                             /**< (EIC_ASYNCH) Edge detection is clock asynchronously operated  */
#define EIC_ASYNCH_ASYNCH10_SYNC              (EIC_ASYNCH_ASYNCH10_SYNC_Val << EIC_ASYNCH_ASYNCH10_Pos) /**< (EIC_ASYNCH) Edge detection is clock synchronously operated Position  */
#define EIC_ASYNCH_ASYNCH10_ASYNC             (EIC_ASYNCH_ASYNCH10_ASYNC_Val << EIC_ASYNCH_ASYNCH10_Pos) /**< (EIC_ASYNCH) Edge detection is clock asynchronously operated Position  */
#define EIC_ASYNCH_ASYNCH11_Pos               _U_(11)                                              /**< (EIC_ASYNCH) Asynchronous Edge Detection Mode of EXTINT11 Position */
#define EIC_ASYNCH_ASYNCH11_Msk               (_U_(0x1) << EIC_ASYNCH_ASYNCH11_Pos)                /**< (EIC_ASYNCH) Asynchronous Edge Detection Mode of EXTINT11 Mask */
#define EIC_ASYNCH_ASYNCH11(value)            (EIC_ASYNCH_ASYNCH11_Msk & ((value) << EIC_ASYNCH_ASYNCH11_Pos))
#define   EIC_ASYNCH_ASYNCH11_SYNC_Val        _U_(0x0)                                             /**< (EIC_ASYNCH) Edge detection is clock synchronously operated  */
#define   EIC_ASYNCH_ASYNCH11_ASYNC_Val       _U_(0x1)                                             /**< (EIC_ASYNCH) Edge detection is clock asynchronously operated  */
#define EIC_ASYNCH_ASYNCH11_SYNC              (EIC_ASYNCH_ASYNCH11_SYNC_Val << EIC_ASYNCH_ASYNCH11_Pos) /**< (EIC_ASYNCH) Edge detection is clock synchronously operated Position  */
#define EIC_ASYNCH_ASYNCH11_ASYNC             (EIC_ASYNCH_ASYNCH11_ASYNC_Val << EIC_ASYNCH_ASYNCH11_Pos) /**< (EIC_ASYNCH) Edge detection is clock asynchronously operated Position  */
#define EIC_ASYNCH_ASYNCH12_Pos               _U_(12)                                              /**< (EIC_ASYNCH) Asynchronous Edge Detection Mode of EXTINT12 Position */
#define EIC_ASYNCH_ASYNCH12_Msk               (_U_(0x1) << EIC_ASYNCH_ASYNCH12_Pos)                /**< (EIC_ASYNCH) Asynchronous Edge Detection Mode of EXTINT12 Mask */
#define EIC_ASYNCH_ASYNCH12(value)            (EIC_ASYNCH_ASYNCH12_Msk & ((value) << EIC_ASYNCH_ASYNCH12_Pos))
#define   EIC_ASYNCH_ASYNCH12_SYNC_Val        _U_(0x0)                                             /**< (EIC_ASYNCH) Edge detection is clock synchronously operated  */
#define   EIC_ASYNCH_ASYNCH12_ASYNC_Val       _U_(0x1)                                             /**< (EIC_ASYNCH) Edge detection is clock asynchronously operated  */
#define EIC_ASYNCH_ASYNCH12_SYNC              (EIC_ASYNCH_ASYNCH12_SYNC_Val << EIC_ASYNCH_ASYNCH12_Pos) /**< (EIC_ASYNCH) Edge detection is clock synchronously operated Position  */
#define EIC_ASYNCH_ASYNCH12_ASYNC             (EIC_ASYNCH_ASYNCH12_ASYNC_Val << EIC_ASYNCH_ASYNCH12_Pos) /**< (EIC_ASYNCH) Edge detection is clock asynchronously operated Position  */
#define EIC_ASYNCH_ASYNCH13_Pos               _U_(13)                                              /**< (EIC_ASYNCH) Asynchronous Edge Detection Mode of EXTINT13 Position */
#define EIC_ASYNCH_ASYNCH13_Msk               (_U_(0x1) << EIC_ASYNCH_ASYNCH13_Pos)                /**< (EIC_ASYNCH) Asynchronous Edge Detection Mode of EXTINT13 Mask */
#define EIC_ASYNCH_ASYNCH13(value)            (EIC_ASYNCH_ASYNCH13_Msk & ((value) << EIC_ASYNCH_ASYNCH13_Pos))
#define   EIC_ASYNCH_ASYNCH13_SYNC_Val        _U_(0x0)                                             /**< (EIC_ASYNCH) Edge detection is clock synchronously operated  */
#define   EIC_ASYNCH_ASYNCH13_ASYNC_Val       _U_(0x1)                                             /**< (EIC_ASYNCH) Edge detection is clock asynchronously operated  */
#define EIC_ASYNCH_ASYNCH13_SYNC              (EIC_ASYNCH_ASYNCH13_SYNC_Val << EIC_ASYNCH_ASYNCH13_Pos) /**< (EIC_ASYNCH) Edge detection is clock synchronously operated Position  */
#define EIC_ASYNCH_ASYNCH13_ASYNC             (EIC_ASYNCH_ASYNCH13_ASYNC_Val << EIC_ASYNCH_ASYNCH13_Pos) /**< (EIC_ASYNCH) Edge detection is clock asynchronously operated Position  */
#define EIC_ASYNCH_ASYNCH14_Pos               _U_(14)                                              /**< (EIC_ASYNCH) Asynchronous Edge Detection Mode of EXTINT14 Position */
#define EIC_ASYNCH_ASYNCH14_Msk               (_U_(0x1) << EIC_ASYNCH_ASYNCH14_Pos)                /**< (EIC_ASYNCH) Asynchronous Edge Detection Mode of EXTINT14 Mask */
#define EIC_ASYNCH_ASYNCH14(value)            (EIC_ASYNCH_ASYNCH14_Msk & ((value) << EIC_ASYNCH_ASYNCH14_Pos))
#define   EIC_ASYNCH_ASYNCH14_SYNC_Val        _U_(0x0)                                             /**< (EIC_ASYNCH) Edge detection is clock synchronously operated  */
#define   EIC_ASYNCH_ASYNCH14_ASYNC_Val       _U_(0x1)                                             /**< (EIC_ASYNCH) Edge detection is clock asynchronously operated  */
#define EIC_ASYNCH_ASYNCH14_SYNC              (EIC_ASYNCH_ASYNCH14_SYNC_Val << EIC_ASYNCH_ASYNCH14_Pos) /**< (EIC_ASYNCH) Edge detection is clock synchronously operated Position  */
#define EIC_ASYNCH_ASYNCH14_ASYNC             (EIC_ASYNCH_ASYNCH14_ASYNC_Val << EIC_ASYNCH_ASYNCH14_Pos) /**< (EIC_ASYNCH) Edge detection is clock asynchronously operated Position  */
#define EIC_ASYNCH_ASYNCH15_Pos               _U_(15)                                              /**< (EIC_ASYNCH) Asynchronous Edge Detection Mode of EXTINT15 Position */
#define EIC_ASYNCH_ASYNCH15_Msk               (_U_(0x1) << EIC_ASYNCH_ASYNCH15_Pos)                /**< (EIC_ASYNCH) Asynchronous Edge Detection Mode of EXTINT15 Mask */
#define EIC_ASYNCH_ASYNCH15(value)            (EIC_ASYNCH_ASYNCH15_Msk & ((value) << EIC_ASYNCH_ASYNCH15_Pos))
#define   EIC_ASYNCH_ASYNCH15_SYNC_Val        _U_(0x0)                                             /**< (EIC_ASYNCH) Edge detection is clock synchronously operated  */
#define   EIC_ASYNCH_ASYNCH15_ASYNC_Val       _U_(0x1)                                             /**< (EIC_ASYNCH) Edge detection is clock asynchronously operated  */
#define EIC_ASYNCH_ASYNCH15_SYNC              (EIC_ASYNCH_ASYNCH15_SYNC_Val << EIC_ASYNCH_ASYNCH15_Pos) /**< (EIC_ASYNCH) Edge detection is clock synchronously operated Position  */
#define EIC_ASYNCH_ASYNCH15_ASYNC             (EIC_ASYNCH_ASYNCH15_ASYNC_Val << EIC_ASYNCH_ASYNCH15_Pos) /**< (EIC_ASYNCH) Edge detection is clock asynchronously operated Position  */
#define EIC_ASYNCH_Msk                        _U_(0x0000FFFF)                                      /**< (EIC_ASYNCH) Register Mask  */

#define EIC_ASYNCH_ASYNCH_Pos                 _U_(0)                                               /**< (EIC_ASYNCH Position) Asynchronous Edge Detection Mode of EXTINTx5 */
#define EIC_ASYNCH_ASYNCH_Msk                 (_U_(0xFFFF) << EIC_ASYNCH_ASYNCH_Pos)               /**< (EIC_ASYNCH Mask) ASYNCH */
#define EIC_ASYNCH_ASYNCH(value)              (EIC_ASYNCH_ASYNCH_Msk & ((value) << EIC_ASYNCH_ASYNCH_Pos)) 

/* -------- EIC_CONFIG0 : (EIC Offset: 0x1C) (R/W 32) External Interrupt Sense Configuration -------- */
#define EIC_CONFIG0_RESETVALUE                _U_(0x00)                                            /**<  (EIC_CONFIG0) External Interrupt Sense Configuration  Reset Value */

#define EIC_CONFIG0_SENSE0_Pos                _U_(0)                                               /**< (EIC_CONFIG0) Input Sense Configuration 0 Position */
#define EIC_CONFIG0_SENSE0_Msk                (_U_(0x7) << EIC_CONFIG0_SENSE0_Pos)                 /**< (EIC_CONFIG0) Input Sense Configuration 0 Mask */
#define EIC_CONFIG0_SENSE0(value)             (EIC_CONFIG0_SENSE0_Msk & ((value) << EIC_CONFIG0_SENSE0_Pos))
#define   EIC_CONFIG0_SENSE0_NONE_Val         _U_(0x0)                                             /**< (EIC_CONFIG0) No detection  */
#define   EIC_CONFIG0_SENSE0_RISE_Val         _U_(0x1)                                             /**< (EIC_CONFIG0) Rising edge detection  */
#define   EIC_CONFIG0_SENSE0_FALL_Val         _U_(0x2)                                             /**< (EIC_CONFIG0) Falling edge detection  */
#define   EIC_CONFIG0_SENSE0_BOTH_Val         _U_(0x3)                                             /**< (EIC_CONFIG0) Both edges detection  */
#define   EIC_CONFIG0_SENSE0_HIGH_Val         _U_(0x4)                                             /**< (EIC_CONFIG0) High level detection  */
#define   EIC_CONFIG0_SENSE0_LOW_Val          _U_(0x5)                                             /**< (EIC_CONFIG0) Low level detection  */
#define EIC_CONFIG0_SENSE0_NONE               (EIC_CONFIG0_SENSE0_NONE_Val << EIC_CONFIG0_SENSE0_Pos) /**< (EIC_CONFIG0) No detection Position  */
#define EIC_CONFIG0_SENSE0_RISE               (EIC_CONFIG0_SENSE0_RISE_Val << EIC_CONFIG0_SENSE0_Pos) /**< (EIC_CONFIG0) Rising edge detection Position  */
#define EIC_CONFIG0_SENSE0_FALL               (EIC_CONFIG0_SENSE0_FALL_Val << EIC_CONFIG0_SENSE0_Pos) /**< (EIC_CONFIG0) Falling edge detection Position  */
#define EIC_CONFIG0_SENSE0_BOTH               (EIC_CONFIG0_SENSE0_BOTH_Val << EIC_CONFIG0_SENSE0_Pos) /**< (EIC_CONFIG0) Both edges detection Position  */
#define EIC_CONFIG0_SENSE0_HIGH               (EIC_CONFIG0_SENSE0_HIGH_Val << EIC_CONFIG0_SENSE0_Pos) /**< (EIC_CONFIG0) High level detection Position  */
#define EIC_CONFIG0_SENSE0_LOW                (EIC_CONFIG0_SENSE0_LOW_Val << EIC_CONFIG0_SENSE0_Pos) /**< (EIC_CONFIG0) Low level detection Position  */
#define EIC_CONFIG0_FILTEN0_Pos               _U_(3)                                               /**< (EIC_CONFIG0) Filter Enable 0 Position */
#define EIC_CONFIG0_FILTEN0_Msk               (_U_(0x1) << EIC_CONFIG0_FILTEN0_Pos)                /**< (EIC_CONFIG0) Filter Enable 0 Mask */
#define EIC_CONFIG0_FILTEN0(value)            (EIC_CONFIG0_FILTEN0_Msk & ((value) << EIC_CONFIG0_FILTEN0_Pos))
#define EIC_CONFIG0_SENSE1_Pos                _U_(4)                                               /**< (EIC_CONFIG0) Input Sense Configuration 1 Position */
#define EIC_CONFIG0_SENSE1_Msk                (_U_(0x7) << EIC_CONFIG0_SENSE1_Pos)                 /**< (EIC_CONFIG0) Input Sense Configuration 1 Mask */
#define EIC_CONFIG0_SENSE1(value)             (EIC_CONFIG0_SENSE1_Msk & ((value) << EIC_CONFIG0_SENSE1_Pos))
#define   EIC_CONFIG0_SENSE1_NONE_Val         _U_(0x0)                                             /**< (EIC_CONFIG0) No detection  */
#define   EIC_CONFIG0_SENSE1_RISE_Val         _U_(0x1)                                             /**< (EIC_CONFIG0) Rising edge detection  */
#define   EIC_CONFIG0_SENSE1_FALL_Val         _U_(0x2)                                             /**< (EIC_CONFIG0) Falling edge detection  */
#define   EIC_CONFIG0_SENSE1_BOTH_Val         _U_(0x3)                                             /**< (EIC_CONFIG0) Both edges detection  */
#define   EIC_CONFIG0_SENSE1_HIGH_Val         _U_(0x4)                                             /**< (EIC_CONFIG0) High level detection  */
#define   EIC_CONFIG0_SENSE1_LOW_Val          _U_(0x5)                                             /**< (EIC_CONFIG0) Low level detection  */
#define EIC_CONFIG0_SENSE1_NONE               (EIC_CONFIG0_SENSE1_NONE_Val << EIC_CONFIG0_SENSE1_Pos) /**< (EIC_CONFIG0) No detection Position  */
#define EIC_CONFIG0_SENSE1_RISE               (EIC_CONFIG0_SENSE1_RISE_Val << EIC_CONFIG0_SENSE1_Pos) /**< (EIC_CONFIG0) Rising edge detection Position  */
#define EIC_CONFIG0_SENSE1_FALL               (EIC_CONFIG0_SENSE1_FALL_Val << EIC_CONFIG0_SENSE1_Pos) /**< (EIC_CONFIG0) Falling edge detection Position  */
#define EIC_CONFIG0_SENSE1_BOTH               (EIC_CONFIG0_SENSE1_BOTH_Val << EIC_CONFIG0_SENSE1_Pos) /**< (EIC_CONFIG0) Both edges detection Position  */
#define EIC_CONFIG0_SENSE1_HIGH               (EIC_CONFIG0_SENSE1_HIGH_Val << EIC_CONFIG0_SENSE1_Pos) /**< (EIC_CONFIG0) High level detection Position  */
#define EIC_CONFIG0_SENSE1_LOW                (EIC_CONFIG0_SENSE1_LOW_Val << EIC_CONFIG0_SENSE1_Pos) /**< (EIC_CONFIG0) Low level detection Position  */
#define EIC_CONFIG0_FILTEN1_Pos               _U_(7)                                               /**< (EIC_CONFIG0) Filter Enable 1 Position */
#define EIC_CONFIG0_FILTEN1_Msk               (_U_(0x1) << EIC_CONFIG0_FILTEN1_Pos)                /**< (EIC_CONFIG0) Filter Enable 1 Mask */
#define EIC_CONFIG0_FILTEN1(value)            (EIC_CONFIG0_FILTEN1_Msk & ((value) << EIC_CONFIG0_FILTEN1_Pos))
#define EIC_CONFIG0_SENSE2_Pos                _U_(8)                                               /**< (EIC_CONFIG0) Input Sense Configuration 2 Position */
#define EIC_CONFIG0_SENSE2_Msk                (_U_(0x7) << EIC_CONFIG0_SENSE2_Pos)                 /**< (EIC_CONFIG0) Input Sense Configuration 2 Mask */
#define EIC_CONFIG0_SENSE2(value)             (EIC_CONFIG0_SENSE2_Msk & ((value) << EIC_CONFIG0_SENSE2_Pos))
#define   EIC_CONFIG0_SENSE2_NONE_Val         _U_(0x0)                                             /**< (EIC_CONFIG0) No detection  */
#define   EIC_CONFIG0_SENSE2_RISE_Val         _U_(0x1)                                             /**< (EIC_CONFIG0) Rising edge detection  */
#define   EIC_CONFIG0_SENSE2_FALL_Val         _U_(0x2)                                             /**< (EIC_CONFIG0) Falling edge detection  */
#define   EIC_CONFIG0_SENSE2_BOTH_Val         _U_(0x3)                                             /**< (EIC_CONFIG0) Both edges detection  */
#define   EIC_CONFIG0_SENSE2_HIGH_Val         _U_(0x4)                                             /**< (EIC_CONFIG0) High level detection  */
#define   EIC_CONFIG0_SENSE2_LOW_Val          _U_(0x5)                                             /**< (EIC_CONFIG0) Low level detection  */
#define EIC_CONFIG0_SENSE2_NONE               (EIC_CONFIG0_SENSE2_NONE_Val << EIC_CONFIG0_SENSE2_Pos) /**< (EIC_CONFIG0) No detection Position  */
#define EIC_CONFIG0_SENSE2_RISE               (EIC_CONFIG0_SENSE2_RISE_Val << EIC_CONFIG0_SENSE2_Pos) /**< (EIC_CONFIG0) Rising edge detection Position  */
#define EIC_CONFIG0_SENSE2_FALL               (EIC_CONFIG0_SENSE2_FALL_Val << EIC_CONFIG0_SENSE2_Pos) /**< (EIC_CONFIG0) Falling edge detection Position  */
#define EIC_CONFIG0_SENSE2_BOTH               (EIC_CONFIG0_SENSE2_BOTH_Val << EIC_CONFIG0_SENSE2_Pos) /**< (EIC_CONFIG0) Both edges detection Position  */
#define EIC_CONFIG0_SENSE2_HIGH               (EIC_CONFIG0_SENSE2_HIGH_Val << EIC_CONFIG0_SENSE2_Pos) /**< (EIC_CONFIG0) High level detection Position  */
#define EIC_CONFIG0_SENSE2_LOW                (EIC_CONFIG0_SENSE2_LOW_Val << EIC_CONFIG0_SENSE2_Pos) /**< (EIC_CONFIG0) Low level detection Position  */
#define EIC_CONFIG0_FILTEN2_Pos               _U_(11)                                              /**< (EIC_CONFIG0) Filter Enable 2 Position */
#define EIC_CONFIG0_FILTEN2_Msk               (_U_(0x1) << EIC_CONFIG0_FILTEN2_Pos)                /**< (EIC_CONFIG0) Filter Enable 2 Mask */
#define EIC_CONFIG0_FILTEN2(value)            (EIC_CONFIG0_FILTEN2_Msk & ((value) << EIC_CONFIG0_FILTEN2_Pos))
#define EIC_CONFIG0_SENSE3_Pos                _U_(12)                                              /**< (EIC_CONFIG0) Input Sense Configuration 3 Position */
#define EIC_CONFIG0_SENSE3_Msk                (_U_(0x7) << EIC_CONFIG0_SENSE3_Pos)                 /**< (EIC_CONFIG0) Input Sense Configuration 3 Mask */
#define EIC_CONFIG0_SENSE3(value)             (EIC_CONFIG0_SENSE3_Msk & ((value) << EIC_CONFIG0_SENSE3_Pos))
#define   EIC_CONFIG0_SENSE3_NONE_Val         _U_(0x0)                                             /**< (EIC_CONFIG0) No detection  */
#define   EIC_CONFIG0_SENSE3_RISE_Val         _U_(0x1)                                             /**< (EIC_CONFIG0) Rising edge detection  */
#define   EIC_CONFIG0_SENSE3_FALL_Val         _U_(0x2)                                             /**< (EIC_CONFIG0) Falling edge detection  */
#define   EIC_CONFIG0_SENSE3_BOTH_Val         _U_(0x3)                                             /**< (EIC_CONFIG0) Both edges detection  */
#define   EIC_CONFIG0_SENSE3_HIGH_Val         _U_(0x4)                                             /**< (EIC_CONFIG0) High level detection  */
#define   EIC_CONFIG0_SENSE3_LOW_Val          _U_(0x5)                                             /**< (EIC_CONFIG0) Low level detection  */
#define EIC_CONFIG0_SENSE3_NONE               (EIC_CONFIG0_SENSE3_NONE_Val << EIC_CONFIG0_SENSE3_Pos) /**< (EIC_CONFIG0) No detection Position  */
#define EIC_CONFIG0_SENSE3_RISE               (EIC_CONFIG0_SENSE3_RISE_Val << EIC_CONFIG0_SENSE3_Pos) /**< (EIC_CONFIG0) Rising edge detection Position  */
#define EIC_CONFIG0_SENSE3_FALL               (EIC_CONFIG0_SENSE3_FALL_Val << EIC_CONFIG0_SENSE3_Pos) /**< (EIC_CONFIG0) Falling edge detection Position  */
#define EIC_CONFIG0_SENSE3_BOTH               (EIC_CONFIG0_SENSE3_BOTH_Val << EIC_CONFIG0_SENSE3_Pos) /**< (EIC_CONFIG0) Both edges detection Position  */
#define EIC_CONFIG0_SENSE3_HIGH               (EIC_CONFIG0_SENSE3_HIGH_Val << EIC_CONFIG0_SENSE3_Pos) /**< (EIC_CONFIG0) High level detection Position  */
#define EIC_CONFIG0_SENSE3_LOW                (EIC_CONFIG0_SENSE3_LOW_Val << EIC_CONFIG0_SENSE3_Pos) /**< (EIC_CONFIG0) Low level detection Position  */
#define EIC_CONFIG0_FILTEN3_Pos               _U_(15)                                              /**< (EIC_CONFIG0) Filter Enable 3 Position */
#define EIC_CONFIG0_FILTEN3_Msk               (_U_(0x1) << EIC_CONFIG0_FILTEN3_Pos)                /**< (EIC_CONFIG0) Filter Enable 3 Mask */
#define EIC_CONFIG0_FILTEN3(value)            (EIC_CONFIG0_FILTEN3_Msk & ((value) << EIC_CONFIG0_FILTEN3_Pos))
#define EIC_CONFIG0_SENSE4_Pos                _U_(16)                                              /**< (EIC_CONFIG0) Input Sense Configuration 4 Position */
#define EIC_CONFIG0_SENSE4_Msk                (_U_(0x7) << EIC_CONFIG0_SENSE4_Pos)                 /**< (EIC_CONFIG0) Input Sense Configuration 4 Mask */
#define EIC_CONFIG0_SENSE4(value)             (EIC_CONFIG0_SENSE4_Msk & ((value) << EIC_CONFIG0_SENSE4_Pos))
#define   EIC_CONFIG0_SENSE4_NONE_Val         _U_(0x0)                                             /**< (EIC_CONFIG0) No detection  */
#define   EIC_CONFIG0_SENSE4_RISE_Val         _U_(0x1)                                             /**< (EIC_CONFIG0) Rising edge detection  */
#define   EIC_CONFIG0_SENSE4_FALL_Val         _U_(0x2)                                             /**< (EIC_CONFIG0) Falling edge detection  */
#define   EIC_CONFIG0_SENSE4_BOTH_Val         _U_(0x3)                                             /**< (EIC_CONFIG0) Both edges detection  */
#define   EIC_CONFIG0_SENSE4_HIGH_Val         _U_(0x4)                                             /**< (EIC_CONFIG0) High level detection  */
#define   EIC_CONFIG0_SENSE4_LOW_Val          _U_(0x5)                                             /**< (EIC_CONFIG0) Low level detection  */
#define EIC_CONFIG0_SENSE4_NONE               (EIC_CONFIG0_SENSE4_NONE_Val << EIC_CONFIG0_SENSE4_Pos) /**< (EIC_CONFIG0) No detection Position  */
#define EIC_CONFIG0_SENSE4_RISE               (EIC_CONFIG0_SENSE4_RISE_Val << EIC_CONFIG0_SENSE4_Pos) /**< (EIC_CONFIG0) Rising edge detection Position  */
#define EIC_CONFIG0_SENSE4_FALL               (EIC_CONFIG0_SENSE4_FALL_Val << EIC_CONFIG0_SENSE4_Pos) /**< (EIC_CONFIG0) Falling edge detection Position  */
#define EIC_CONFIG0_SENSE4_BOTH               (EIC_CONFIG0_SENSE4_BOTH_Val << EIC_CONFIG0_SENSE4_Pos) /**< (EIC_CONFIG0) Both edges detection Position  */
#define EIC_CONFIG0_SENSE4_HIGH               (EIC_CONFIG0_SENSE4_HIGH_Val << EIC_CONFIG0_SENSE4_Pos) /**< (EIC_CONFIG0) High level detection Position  */
#define EIC_CONFIG0_SENSE4_LOW                (EIC_CONFIG0_SENSE4_LOW_Val << EIC_CONFIG0_SENSE4_Pos) /**< (EIC_CONFIG0) Low level detection Position  */
#define EIC_CONFIG0_FILTEN4_Pos               _U_(19)                                              /**< (EIC_CONFIG0) Filter Enable 4 Position */
#define EIC_CONFIG0_FILTEN4_Msk               (_U_(0x1) << EIC_CONFIG0_FILTEN4_Pos)                /**< (EIC_CONFIG0) Filter Enable 4 Mask */
#define EIC_CONFIG0_FILTEN4(value)            (EIC_CONFIG0_FILTEN4_Msk & ((value) << EIC_CONFIG0_FILTEN4_Pos))
#define EIC_CONFIG0_SENSE5_Pos                _U_(20)                                              /**< (EIC_CONFIG0) Input Sense Configuration 5 Position */
#define EIC_CONFIG0_SENSE5_Msk                (_U_(0x7) << EIC_CONFIG0_SENSE5_Pos)                 /**< (EIC_CONFIG0) Input Sense Configuration 5 Mask */
#define EIC_CONFIG0_SENSE5(value)             (EIC_CONFIG0_SENSE5_Msk & ((value) << EIC_CONFIG0_SENSE5_Pos))
#define   EIC_CONFIG0_SENSE5_NONE_Val         _U_(0x0)                                             /**< (EIC_CONFIG0) No detection  */
#define   EIC_CONFIG0_SENSE5_RISE_Val         _U_(0x1)                                             /**< (EIC_CONFIG0) Rising edge detection  */
#define   EIC_CONFIG0_SENSE5_FALL_Val         _U_(0x2)                                             /**< (EIC_CONFIG0) Falling edge detection  */
#define   EIC_CONFIG0_SENSE5_BOTH_Val         _U_(0x3)                                             /**< (EIC_CONFIG0) Both edges detection  */
#define   EIC_CONFIG0_SENSE5_HIGH_Val         _U_(0x4)                                             /**< (EIC_CONFIG0) High level detection  */
#define   EIC_CONFIG0_SENSE5_LOW_Val          _U_(0x5)                                             /**< (EIC_CONFIG0) Low level detection  */
#define EIC_CONFIG0_SENSE5_NONE               (EIC_CONFIG0_SENSE5_NONE_Val << EIC_CONFIG0_SENSE5_Pos) /**< (EIC_CONFIG0) No detection Position  */
#define EIC_CONFIG0_SENSE5_RISE               (EIC_CONFIG0_SENSE5_RISE_Val << EIC_CONFIG0_SENSE5_Pos) /**< (EIC_CONFIG0) Rising edge detection Position  */
#define EIC_CONFIG0_SENSE5_FALL               (EIC_CONFIG0_SENSE5_FALL_Val << EIC_CONFIG0_SENSE5_Pos) /**< (EIC_CONFIG0) Falling edge detection Position  */
#define EIC_CONFIG0_SENSE5_BOTH               (EIC_CONFIG0_SENSE5_BOTH_Val << EIC_CONFIG0_SENSE5_Pos) /**< (EIC_CONFIG0) Both edges detection Position  */
#define EIC_CONFIG0_SENSE5_HIGH               (EIC_CONFIG0_SENSE5_HIGH_Val << EIC_CONFIG0_SENSE5_Pos) /**< (EIC_CONFIG0) High level detection Position  */
#define EIC_CONFIG0_SENSE5_LOW                (EIC_CONFIG0_SENSE5_LOW_Val << EIC_CONFIG0_SENSE5_Pos) /**< (EIC_CONFIG0) Low level detection Position  */
#define EIC_CONFIG0_FILTEN5_Pos               _U_(23)                                              /**< (EIC_CONFIG0) Filter Enable 5 Position */
#define EIC_CONFIG0_FILTEN5_Msk               (_U_(0x1) << EIC_CONFIG0_FILTEN5_Pos)                /**< (EIC_CONFIG0) Filter Enable 5 Mask */
#define EIC_CONFIG0_FILTEN5(value)            (EIC_CONFIG0_FILTEN5_Msk & ((value) << EIC_CONFIG0_FILTEN5_Pos))
#define EIC_CONFIG0_SENSE6_Pos                _U_(24)                                              /**< (EIC_CONFIG0) Input Sense Configuration 6 Position */
#define EIC_CONFIG0_SENSE6_Msk                (_U_(0x7) << EIC_CONFIG0_SENSE6_Pos)                 /**< (EIC_CONFIG0) Input Sense Configuration 6 Mask */
#define EIC_CONFIG0_SENSE6(value)             (EIC_CONFIG0_SENSE6_Msk & ((value) << EIC_CONFIG0_SENSE6_Pos))
#define   EIC_CONFIG0_SENSE6_NONE_Val         _U_(0x0)                                             /**< (EIC_CONFIG0) No detection  */
#define   EIC_CONFIG0_SENSE6_RISE_Val         _U_(0x1)                                             /**< (EIC_CONFIG0) Rising edge detection  */
#define   EIC_CONFIG0_SENSE6_FALL_Val         _U_(0x2)                                             /**< (EIC_CONFIG0) Falling edge detection  */
#define   EIC_CONFIG0_SENSE6_BOTH_Val         _U_(0x3)                                             /**< (EIC_CONFIG0) Both edges detection  */
#define   EIC_CONFIG0_SENSE6_HIGH_Val         _U_(0x4)                                             /**< (EIC_CONFIG0) High level detection  */
#define   EIC_CONFIG0_SENSE6_LOW_Val          _U_(0x5)                                             /**< (EIC_CONFIG0) Low level detection  */
#define EIC_CONFIG0_SENSE6_NONE               (EIC_CONFIG0_SENSE6_NONE_Val << EIC_CONFIG0_SENSE6_Pos) /**< (EIC_CONFIG0) No detection Position  */
#define EIC_CONFIG0_SENSE6_RISE               (EIC_CONFIG0_SENSE6_RISE_Val << EIC_CONFIG0_SENSE6_Pos) /**< (EIC_CONFIG0) Rising edge detection Position  */
#define EIC_CONFIG0_SENSE6_FALL               (EIC_CONFIG0_SENSE6_FALL_Val << EIC_CONFIG0_SENSE6_Pos) /**< (EIC_CONFIG0) Falling edge detection Position  */
#define EIC_CONFIG0_SENSE6_BOTH               (EIC_CONFIG0_SENSE6_BOTH_Val << EIC_CONFIG0_SENSE6_Pos) /**< (EIC_CONFIG0) Both edges detection Position  */
#define EIC_CONFIG0_SENSE6_HIGH               (EIC_CONFIG0_SENSE6_HIGH_Val << EIC_CONFIG0_SENSE6_Pos) /**< (EIC_CONFIG0) High level detection Position  */
#define EIC_CONFIG0_SENSE6_LOW                (EIC_CONFIG0_SENSE6_LOW_Val << EIC_CONFIG0_SENSE6_Pos) /**< (EIC_CONFIG0) Low level detection Position  */
#define EIC_CONFIG0_FILTEN6_Pos               _U_(27)                                              /**< (EIC_CONFIG0) Filter Enable 6 Position */
#define EIC_CONFIG0_FILTEN6_Msk               (_U_(0x1) << EIC_CONFIG0_FILTEN6_Pos)                /**< (EIC_CONFIG0) Filter Enable 6 Mask */
#define EIC_CONFIG0_FILTEN6(value)            (EIC_CONFIG0_FILTEN6_Msk & ((value) << EIC_CONFIG0_FILTEN6_Pos))
#define EIC_CONFIG0_SENSE7_Pos                _U_(28)                                              /**< (EIC_CONFIG0) Input Sense Configuration 7 Position */
#define EIC_CONFIG0_SENSE7_Msk                (_U_(0x7) << EIC_CONFIG0_SENSE7_Pos)                 /**< (EIC_CONFIG0) Input Sense Configuration 7 Mask */
#define EIC_CONFIG0_SENSE7(value)             (EIC_CONFIG0_SENSE7_Msk & ((value) << EIC_CONFIG0_SENSE7_Pos))
#define   EIC_CONFIG0_SENSE7_NONE_Val         _U_(0x0)                                             /**< (EIC_CONFIG0) No detection  */
#define   EIC_CONFIG0_SENSE7_RISE_Val         _U_(0x1)                                             /**< (EIC_CONFIG0) Rising edge detection  */
#define   EIC_CONFIG0_SENSE7_FALL_Val         _U_(0x2)                                             /**< (EIC_CONFIG0) Falling edge detection  */
#define   EIC_CONFIG0_SENSE7_BOTH_Val         _U_(0x3)                                             /**< (EIC_CONFIG0) Both edges detection  */
#define   EIC_CONFIG0_SENSE7_HIGH_Val         _U_(0x4)                                             /**< (EIC_CONFIG0) High level detection  */
#define   EIC_CONFIG0_SENSE7_LOW_Val          _U_(0x5)                                             /**< (EIC_CONFIG0) Low level detection  */
#define EIC_CONFIG0_SENSE7_NONE               (EIC_CONFIG0_SENSE7_NONE_Val << EIC_CONFIG0_SENSE7_Pos) /**< (EIC_CONFIG0) No detection Position  */
#define EIC_CONFIG0_SENSE7_RISE               (EIC_CONFIG0_SENSE7_RISE_Val << EIC_CONFIG0_SENSE7_Pos) /**< (EIC_CONFIG0) Rising edge detection Position  */
#define EIC_CONFIG0_SENSE7_FALL               (EIC_CONFIG0_SENSE7_FALL_Val << EIC_CONFIG0_SENSE7_Pos) /**< (EIC_CONFIG0) Falling edge detection Position  */
#define EIC_CONFIG0_SENSE7_BOTH               (EIC_CONFIG0_SENSE7_BOTH_Val << EIC_CONFIG0_SENSE7_Pos) /**< (EIC_CONFIG0) Both edges detection Position  */
#define EIC_CONFIG0_SENSE7_HIGH               (EIC_CONFIG0_SENSE7_HIGH_Val << EIC_CONFIG0_SENSE7_Pos) /**< (EIC_CONFIG0) High level detection Position  */
#define EIC_CONFIG0_SENSE7_LOW                (EIC_CONFIG0_SENSE7_LOW_Val << EIC_CONFIG0_SENSE7_Pos) /**< (EIC_CONFIG0) Low level detection Position  */
#define EIC_CONFIG0_FILTEN7_Pos               _U_(31)                                              /**< (EIC_CONFIG0) Filter Enable 7 Position */
#define EIC_CONFIG0_FILTEN7_Msk               (_U_(0x1) << EIC_CONFIG0_FILTEN7_Pos)                /**< (EIC_CONFIG0) Filter Enable 7 Mask */
#define EIC_CONFIG0_FILTEN7(value)            (EIC_CONFIG0_FILTEN7_Msk & ((value) << EIC_CONFIG0_FILTEN7_Pos))
#define EIC_CONFIG0_Msk                       _U_(0xFFFFFFFF)                                      /**< (EIC_CONFIG0) Register Mask  */


/* -------- EIC_CONFIG1 : (EIC Offset: 0x20) (R/W 32) External Interrupt Sense Configuration -------- */
#define EIC_CONFIG1_RESETVALUE                _U_(0x00)                                            /**<  (EIC_CONFIG1) External Interrupt Sense Configuration  Reset Value */

#define EIC_CONFIG1_SENSE8_Pos                _U_(0)                                               /**< (EIC_CONFIG1) Input Sense Configuration 8 Position */
#define EIC_CONFIG1_SENSE8_Msk                (_U_(0x7) << EIC_CONFIG1_SENSE8_Pos)                 /**< (EIC_CONFIG1) Input Sense Configuration 8 Mask */
#define EIC_CONFIG1_SENSE8(value)             (EIC_CONFIG1_SENSE8_Msk & ((value) << EIC_CONFIG1_SENSE8_Pos))
#define   EIC_CONFIG1_SENSE8_NONE_Val         _U_(0x0)                                             /**< (EIC_CONFIG1) No detection  */
#define   EIC_CONFIG1_SENSE8_RISE_Val         _U_(0x1)                                             /**< (EIC_CONFIG1) Rising edge detection  */
#define   EIC_CONFIG1_SENSE8_FALL_Val         _U_(0x2)                                             /**< (EIC_CONFIG1) Falling edge detection  */
#define   EIC_CONFIG1_SENSE8_BOTH_Val         _U_(0x3)                                             /**< (EIC_CONFIG1) Both edges detection  */
#define   EIC_CONFIG1_SENSE8_HIGH_Val         _U_(0x4)                                             /**< (EIC_CONFIG1) High level detection  */
#define   EIC_CONFIG1_SENSE8_LOW_Val          _U_(0x5)                                             /**< (EIC_CONFIG1) Low level detection  */
#define EIC_CONFIG1_SENSE8_NONE               (EIC_CONFIG1_SENSE8_NONE_Val << EIC_CONFIG1_SENSE8_Pos) /**< (EIC_CONFIG1) No detection Position  */
#define EIC_CONFIG1_SENSE8_RISE               (EIC_CONFIG1_SENSE8_RISE_Val << EIC_CONFIG1_SENSE8_Pos) /**< (EIC_CONFIG1) Rising edge detection Position  */
#define EIC_CONFIG1_SENSE8_FALL               (EIC_CONFIG1_SENSE8_FALL_Val << EIC_CONFIG1_SENSE8_Pos) /**< (EIC_CONFIG1) Falling edge detection Position  */
#define EIC_CONFIG1_SENSE8_BOTH               (EIC_CONFIG1_SENSE8_BOTH_Val << EIC_CONFIG1_SENSE8_Pos) /**< (EIC_CONFIG1) Both edges detection Position  */
#define EIC_CONFIG1_SENSE8_HIGH               (EIC_CONFIG1_SENSE8_HIGH_Val << EIC_CONFIG1_SENSE8_Pos) /**< (EIC_CONFIG1) High level detection Position  */
#define EIC_CONFIG1_SENSE8_LOW                (EIC_CONFIG1_SENSE8_LOW_Val << EIC_CONFIG1_SENSE8_Pos) /**< (EIC_CONFIG1) Low level detection Position  */
#define EIC_CONFIG1_FILTEN8_Pos               _U_(3)                                               /**< (EIC_CONFIG1) Filter Enable 8 Position */
#define EIC_CONFIG1_FILTEN8_Msk               (_U_(0x1) << EIC_CONFIG1_FILTEN8_Pos)                /**< (EIC_CONFIG1) Filter Enable 8 Mask */
#define EIC_CONFIG1_FILTEN8(value)            (EIC_CONFIG1_FILTEN8_Msk & ((value) << EIC_CONFIG1_FILTEN8_Pos))
#define EIC_CONFIG1_SENSE9_Pos                _U_(4)                                               /**< (EIC_CONFIG1) Input Sense Configuration 9 Position */
#define EIC_CONFIG1_SENSE9_Msk                (_U_(0x7) << EIC_CONFIG1_SENSE9_Pos)                 /**< (EIC_CONFIG1) Input Sense Configuration 9 Mask */
#define EIC_CONFIG1_SENSE9(value)             (EIC_CONFIG1_SENSE9_Msk & ((value) << EIC_CONFIG1_SENSE9_Pos))
#define   EIC_CONFIG1_SENSE9_NONE_Val         _U_(0x0)                                             /**< (EIC_CONFIG1) No detection  */
#define   EIC_CONFIG1_SENSE9_RISE_Val         _U_(0x1)                                             /**< (EIC_CONFIG1) Rising edge detection  */
#define   EIC_CONFIG1_SENSE9_FALL_Val         _U_(0x2)                                             /**< (EIC_CONFIG1) Falling edge detection  */
#define   EIC_CONFIG1_SENSE9_BOTH_Val         _U_(0x3)                                             /**< (EIC_CONFIG1) Both edges detection  */
#define   EIC_CONFIG1_SENSE9_HIGH_Val         _U_(0x4)                                             /**< (EIC_CONFIG1) High level detection  */
#define   EIC_CONFIG1_SENSE9_LOW_Val          _U_(0x5)                                             /**< (EIC_CONFIG1) Low level detection  */
#define EIC_CONFIG1_SENSE9_NONE               (EIC_CONFIG1_SENSE9_NONE_Val << EIC_CONFIG1_SENSE9_Pos) /**< (EIC_CONFIG1) No detection Position  */
#define EIC_CONFIG1_SENSE9_RISE               (EIC_CONFIG1_SENSE9_RISE_Val << EIC_CONFIG1_SENSE9_Pos) /**< (EIC_CONFIG1) Rising edge detection Position  */
#define EIC_CONFIG1_SENSE9_FALL               (EIC_CONFIG1_SENSE9_FALL_Val << EIC_CONFIG1_SENSE9_Pos) /**< (EIC_CONFIG1) Falling edge detection Position  */
#define EIC_CONFIG1_SENSE9_BOTH               (EIC_CONFIG1_SENSE9_BOTH_Val << EIC_CONFIG1_SENSE9_Pos) /**< (EIC_CONFIG1) Both edges detection Position  */
#define EIC_CONFIG1_SENSE9_HIGH               (EIC_CONFIG1_SENSE9_HIGH_Val << EIC_CONFIG1_SENSE9_Pos) /**< (EIC_CONFIG1) High level detection Position  */
#define EIC_CONFIG1_SENSE9_LOW                (EIC_CONFIG1_SENSE9_LOW_Val << EIC_CONFIG1_SENSE9_Pos) /**< (EIC_CONFIG1) Low level detection Position  */
#define EIC_CONFIG1_FILTEN9_Pos               _U_(7)                                               /**< (EIC_CONFIG1) Filter Enable 9 Position */
#define EIC_CONFIG1_FILTEN9_Msk               (_U_(0x1) << EIC_CONFIG1_FILTEN9_Pos)                /**< (EIC_CONFIG1) Filter Enable 9 Mask */
#define EIC_CONFIG1_FILTEN9(value)            (EIC_CONFIG1_FILTEN9_Msk & ((value) << EIC_CONFIG1_FILTEN9_Pos))
#define EIC_CONFIG1_SENSE10_Pos               _U_(8)                                               /**< (EIC_CONFIG1) Input Sense Configuration 10 Position */
#define EIC_CONFIG1_SENSE10_Msk               (_U_(0x7) << EIC_CONFIG1_SENSE10_Pos)                /**< (EIC_CONFIG1) Input Sense Configuration 10 Mask */
#define EIC_CONFIG1_SENSE10(value)            (EIC_CONFIG1_SENSE10_Msk & ((value) << EIC_CONFIG1_SENSE10_Pos))
#define   EIC_CONFIG1_SENSE10_NONE_Val        _U_(0x0)                                             /**< (EIC_CONFIG1) No detection  */
#define   EIC_CONFIG1_SENSE10_RISE_Val        _U_(0x1)                                             /**< (EIC_CONFIG1) Rising edge detection  */
#define   EIC_CONFIG1_SENSE10_FALL_Val        _U_(0x2)                                             /**< (EIC_CONFIG1) Falling edge detection  */
#define   EIC_CONFIG1_SENSE10_BOTH_Val        _U_(0x3)                                             /**< (EIC_CONFIG1) Both edges detection  */
#define   EIC_CONFIG1_SENSE10_HIGH_Val        _U_(0x4)                                             /**< (EIC_CONFIG1) High level detection  */
#define   EIC_CONFIG1_SENSE10_LOW_Val         _U_(0x5)                                             /**< (EIC_CONFIG1) Low level detection  */
#define EIC_CONFIG1_SENSE10_NONE              (EIC_CONFIG1_SENSE10_NONE_Val << EIC_CONFIG1_SENSE10_Pos) /**< (EIC_CONFIG1) No detection Position  */
#define EIC_CONFIG1_SENSE10_RISE              (EIC_CONFIG1_SENSE10_RISE_Val << EIC_CONFIG1_SENSE10_Pos) /**< (EIC_CONFIG1) Rising edge detection Position  */
#define EIC_CONFIG1_SENSE10_FALL              (EIC_CONFIG1_SENSE10_FALL_Val << EIC_CONFIG1_SENSE10_Pos) /**< (EIC_CONFIG1) Falling edge detection Position  */
#define EIC_CONFIG1_SENSE10_BOTH              (EIC_CONFIG1_SENSE10_BOTH_Val << EIC_CONFIG1_SENSE10_Pos) /**< (EIC_CONFIG1) Both edges detection Position  */
#define EIC_CONFIG1_SENSE10_HIGH              (EIC_CONFIG1_SENSE10_HIGH_Val << EIC_CONFIG1_SENSE10_Pos) /**< (EIC_CONFIG1) High level detection Position  */
#define EIC_CONFIG1_SENSE10_LOW               (EIC_CONFIG1_SENSE10_LOW_Val << EIC_CONFIG1_SENSE10_Pos) /**< (EIC_CONFIG1) Low level detection Position  */
#define EIC_CONFIG1_FILTEN10_Pos              _U_(11)                                              /**< (EIC_CONFIG1) Filter Enable 10 Position */
#define EIC_CONFIG1_FILTEN10_Msk              (_U_(0x1) << EIC_CONFIG1_FILTEN10_Pos)               /**< (EIC_CONFIG1) Filter Enable 10 Mask */
#define EIC_CONFIG1_FILTEN10(value)           (EIC_CONFIG1_FILTEN10_Msk & ((value) << EIC_CONFIG1_FILTEN10_Pos))
#define EIC_CONFIG1_SENSE11_Pos               _U_(12)                                              /**< (EIC_CONFIG1) Input Sense Configuration 11 Position */
#define EIC_CONFIG1_SENSE11_Msk               (_U_(0x7) << EIC_CONFIG1_SENSE11_Pos)                /**< (EIC_CONFIG1) Input Sense Configuration 11 Mask */
#define EIC_CONFIG1_SENSE11(value)            (EIC_CONFIG1_SENSE11_Msk & ((value) << EIC_CONFIG1_SENSE11_Pos))
#define   EIC_CONFIG1_SENSE11_NONE_Val        _U_(0x0)                                             /**< (EIC_CONFIG1) No detection  */
#define   EIC_CONFIG1_SENSE11_RISE_Val        _U_(0x1)                                             /**< (EIC_CONFIG1) Rising edge detection  */
#define   EIC_CONFIG1_SENSE11_FALL_Val        _U_(0x2)                                             /**< (EIC_CONFIG1) Falling edge detection  */
#define   EIC_CONFIG1_SENSE11_BOTH_Val        _U_(0x3)                                             /**< (EIC_CONFIG1) Both edges detection  */
#define   EIC_CONFIG1_SENSE11_HIGH_Val        _U_(0x4)                                             /**< (EIC_CONFIG1) High level detection  */
#define   EIC_CONFIG1_SENSE11_LOW_Val         _U_(0x5)                                             /**< (EIC_CONFIG1) Low level detection  */
#define EIC_CONFIG1_SENSE11_NONE              (EIC_CONFIG1_SENSE11_NONE_Val << EIC_CONFIG1_SENSE11_Pos) /**< (EIC_CONFIG1) No detection Position  */
#define EIC_CONFIG1_SENSE11_RISE              (EIC_CONFIG1_SENSE11_RISE_Val << EIC_CONFIG1_SENSE11_Pos) /**< (EIC_CONFIG1) Rising edge detection Position  */
#define EIC_CONFIG1_SENSE11_FALL              (EIC_CONFIG1_SENSE11_FALL_Val << EIC_CONFIG1_SENSE11_Pos) /**< (EIC_CONFIG1) Falling edge detection Position  */
#define EIC_CONFIG1_SENSE11_BOTH              (EIC_CONFIG1_SENSE11_BOTH_Val << EIC_CONFIG1_SENSE11_Pos) /**< (EIC_CONFIG1) Both edges detection Position  */
#define EIC_CONFIG1_SENSE11_HIGH              (EIC_CONFIG1_SENSE11_HIGH_Val << EIC_CONFIG1_SENSE11_Pos) /**< (EIC_CONFIG1) High level detection Position  */
#define EIC_CONFIG1_SENSE11_LOW               (EIC_CONFIG1_SENSE11_LOW_Val << EIC_CONFIG1_SENSE11_Pos) /**< (EIC_CONFIG1) Low level detection Position  */
#define EIC_CONFIG1_FILTEN11_Pos              _U_(15)                                              /**< (EIC_CONFIG1) Filter Enable 11 Position */
#define EIC_CONFIG1_FILTEN11_Msk              (_U_(0x1) << EIC_CONFIG1_FILTEN11_Pos)               /**< (EIC_CONFIG1) Filter Enable 11 Mask */
#define EIC_CONFIG1_FILTEN11(value)           (EIC_CONFIG1_FILTEN11_Msk & ((value) << EIC_CONFIG1_FILTEN11_Pos))
#define EIC_CONFIG1_SENSE12_Pos               _U_(16)                                              /**< (EIC_CONFIG1) Input Sense Configuration 12 Position */
#define EIC_CONFIG1_SENSE12_Msk               (_U_(0x7) << EIC_CONFIG1_SENSE12_Pos)                /**< (EIC_CONFIG1) Input Sense Configuration 12 Mask */
#define EIC_CONFIG1_SENSE12(value)            (EIC_CONFIG1_SENSE12_Msk & ((value) << EIC_CONFIG1_SENSE12_Pos))
#define   EIC_CONFIG1_SENSE12_NONE_Val        _U_(0x0)                                             /**< (EIC_CONFIG1) No detection  */
#define   EIC_CONFIG1_SENSE12_RISE_Val        _U_(0x1)                                             /**< (EIC_CONFIG1) Rising edge detection  */
#define   EIC_CONFIG1_SENSE12_FALL_Val        _U_(0x2)                                             /**< (EIC_CONFIG1) Falling edge detection  */
#define   EIC_CONFIG1_SENSE12_BOTH_Val        _U_(0x3)                                             /**< (EIC_CONFIG1) Both edges detection  */
#define   EIC_CONFIG1_SENSE12_HIGH_Val        _U_(0x4)                                             /**< (EIC_CONFIG1) High level detection  */
#define   EIC_CONFIG1_SENSE12_LOW_Val         _U_(0x5)                                             /**< (EIC_CONFIG1) Low level detection  */
#define EIC_CONFIG1_SENSE12_NONE              (EIC_CONFIG1_SENSE12_NONE_Val << EIC_CONFIG1_SENSE12_Pos) /**< (EIC_CONFIG1) No detection Position  */
#define EIC_CONFIG1_SENSE12_RISE              (EIC_CONFIG1_SENSE12_RISE_Val << EIC_CONFIG1_SENSE12_Pos) /**< (EIC_CONFIG1) Rising edge detection Position  */
#define EIC_CONFIG1_SENSE12_FALL              (EIC_CONFIG1_SENSE12_FALL_Val << EIC_CONFIG1_SENSE12_Pos) /**< (EIC_CONFIG1) Falling edge detection Position  */
#define EIC_CONFIG1_SENSE12_BOTH              (EIC_CONFIG1_SENSE12_BOTH_Val << EIC_CONFIG1_SENSE12_Pos) /**< (EIC_CONFIG1) Both edges detection Position  */
#define EIC_CONFIG1_SENSE12_HIGH              (EIC_CONFIG1_SENSE12_HIGH_Val << EIC_CONFIG1_SENSE12_Pos) /**< (EIC_CONFIG1) High level detection Position  */
#define EIC_CONFIG1_SENSE12_LOW               (EIC_CONFIG1_SENSE12_LOW_Val << EIC_CONFIG1_SENSE12_Pos) /**< (EIC_CONFIG1) Low level detection Position  */
#define EIC_CONFIG1_FILTEN12_Pos              _U_(19)                                              /**< (EIC_CONFIG1) Filter Enable 12 Position */
#define EIC_CONFIG1_FILTEN12_Msk              (_U_(0x1) << EIC_CONFIG1_FILTEN12_Pos)               /**< (EIC_CONFIG1) Filter Enable 12 Mask */
#define EIC_CONFIG1_FILTEN12(value)           (EIC_CONFIG1_FILTEN12_Msk & ((value) << EIC_CONFIG1_FILTEN12_Pos))
#define EIC_CONFIG1_SENSE13_Pos               _U_(20)                                              /**< (EIC_CONFIG1) Input Sense Configuration 13 Position */
#define EIC_CONFIG1_SENSE13_Msk               (_U_(0x7) << EIC_CONFIG1_SENSE13_Pos)                /**< (EIC_CONFIG1) Input Sense Configuration 13 Mask */
#define EIC_CONFIG1_SENSE13(value)            (EIC_CONFIG1_SENSE13_Msk & ((value) << EIC_CONFIG1_SENSE13_Pos))
#define   EIC_CONFIG1_SENSE13_NONE_Val        _U_(0x0)                                             /**< (EIC_CONFIG1) No detection  */
#define   EIC_CONFIG1_SENSE13_RISE_Val        _U_(0x1)                                             /**< (EIC_CONFIG1) Rising edge detection  */
#define   EIC_CONFIG1_SENSE13_FALL_Val        _U_(0x2)                                             /**< (EIC_CONFIG1) Falling edge detection  */
#define   EIC_CONFIG1_SENSE13_BOTH_Val        _U_(0x3)                                             /**< (EIC_CONFIG1) Both edges detection  */
#define   EIC_CONFIG1_SENSE13_HIGH_Val        _U_(0x4)                                             /**< (EIC_CONFIG1) High level detection  */
#define   EIC_CONFIG1_SENSE13_LOW_Val         _U_(0x5)                                             /**< (EIC_CONFIG1) Low level detection  */
#define EIC_CONFIG1_SENSE13_NONE              (EIC_CONFIG1_SENSE13_NONE_Val << EIC_CONFIG1_SENSE13_Pos) /**< (EIC_CONFIG1) No detection Position  */
#define EIC_CONFIG1_SENSE13_RISE              (EIC_CONFIG1_SENSE13_RISE_Val << EIC_CONFIG1_SENSE13_Pos) /**< (EIC_CONFIG1) Rising edge detection Position  */
#define EIC_CONFIG1_SENSE13_FALL              (EIC_CONFIG1_SENSE13_FALL_Val << EIC_CONFIG1_SENSE13_Pos) /**< (EIC_CONFIG1) Falling edge detection Position  */
#define EIC_CONFIG1_SENSE13_BOTH              (EIC_CONFIG1_SENSE13_BOTH_Val << EIC_CONFIG1_SENSE13_Pos) /**< (EIC_CONFIG1) Both edges detection Position  */
#define EIC_CONFIG1_SENSE13_HIGH              (EIC_CONFIG1_SENSE13_HIGH_Val << EIC_CONFIG1_SENSE13_Pos) /**< (EIC_CONFIG1) High level detection Position  */
#define EIC_CONFIG1_SENSE13_LOW               (EIC_CONFIG1_SENSE13_LOW_Val << EIC_CONFIG1_SENSE13_Pos) /**< (EIC_CONFIG1) Low level detection Position  */
#define EIC_CONFIG1_FILTEN13_Pos              _U_(23)                                              /**< (EIC_CONFIG1) Filter Enable 13 Position */
#define EIC_CONFIG1_FILTEN13_Msk              (_U_(0x1) << EIC_CONFIG1_FILTEN13_Pos)               /**< (EIC_CONFIG1) Filter Enable 13 Mask */
#define EIC_CONFIG1_FILTEN13(value)           (EIC_CONFIG1_FILTEN13_Msk & ((value) << EIC_CONFIG1_FILTEN13_Pos))
#define EIC_CONFIG1_SENSE14_Pos               _U_(24)                                              /**< (EIC_CONFIG1) Input Sense Configuration 14 Position */
#define EIC_CONFIG1_SENSE14_Msk               (_U_(0x7) << EIC_CONFIG1_SENSE14_Pos)                /**< (EIC_CONFIG1) Input Sense Configuration 14 Mask */
#define EIC_CONFIG1_SENSE14(value)            (EIC_CONFIG1_SENSE14_Msk & ((value) << EIC_CONFIG1_SENSE14_Pos))
#define   EIC_CONFIG1_SENSE14_NONE_Val        _U_(0x0)                                             /**< (EIC_CONFIG1) No detection  */
#define   EIC_CONFIG1_SENSE14_RISE_Val        _U_(0x1)                                             /**< (EIC_CONFIG1) Rising edge detection  */
#define   EIC_CONFIG1_SENSE14_FALL_Val        _U_(0x2)                                             /**< (EIC_CONFIG1) Falling edge detection  */
#define   EIC_CONFIG1_SENSE14_BOTH_Val        _U_(0x3)                                             /**< (EIC_CONFIG1) Both edges detection  */
#define   EIC_CONFIG1_SENSE14_HIGH_Val        _U_(0x4)                                             /**< (EIC_CONFIG1) High level detection  */
#define   EIC_CONFIG1_SENSE14_LOW_Val         _U_(0x5)                                             /**< (EIC_CONFIG1) Low level detection  */
#define EIC_CONFIG1_SENSE14_NONE              (EIC_CONFIG1_SENSE14_NONE_Val << EIC_CONFIG1_SENSE14_Pos) /**< (EIC_CONFIG1) No detection Position  */
#define EIC_CONFIG1_SENSE14_RISE              (EIC_CONFIG1_SENSE14_RISE_Val << EIC_CONFIG1_SENSE14_Pos) /**< (EIC_CONFIG1) Rising edge detection Position  */
#define EIC_CONFIG1_SENSE14_FALL              (EIC_CONFIG1_SENSE14_FALL_Val << EIC_CONFIG1_SENSE14_Pos) /**< (EIC_CONFIG1) Falling edge detection Position  */
#define EIC_CONFIG1_SENSE14_BOTH              (EIC_CONFIG1_SENSE14_BOTH_Val << EIC_CONFIG1_SENSE14_Pos) /**< (EIC_CONFIG1) Both edges detection Position  */
#define EIC_CONFIG1_SENSE14_HIGH              (EIC_CONFIG1_SENSE14_HIGH_Val << EIC_CONFIG1_SENSE14_Pos) /**< (EIC_CONFIG1) High level detection Position  */
#define EIC_CONFIG1_SENSE14_LOW               (EIC_CONFIG1_SENSE14_LOW_Val << EIC_CONFIG1_SENSE14_Pos) /**< (EIC_CONFIG1) Low level detection Position  */
#define EIC_CONFIG1_FILTEN14_Pos              _U_(27)                                              /**< (EIC_CONFIG1) Filter Enable 14 Position */
#define EIC_CONFIG1_FILTEN14_Msk              (_U_(0x1) << EIC_CONFIG1_FILTEN14_Pos)               /**< (EIC_CONFIG1) Filter Enable 14 Mask */
#define EIC_CONFIG1_FILTEN14(value)           (EIC_CONFIG1_FILTEN14_Msk & ((value) << EIC_CONFIG1_FILTEN14_Pos))
#define EIC_CONFIG1_SENSE15_Pos               _U_(28)                                              /**< (EIC_CONFIG1) Input Sense Configuration 15 Position */
#define EIC_CONFIG1_SENSE15_Msk               (_U_(0x7) << EIC_CONFIG1_SENSE15_Pos)                /**< (EIC_CONFIG1) Input Sense Configuration 15 Mask */
#define EIC_CONFIG1_SENSE15(value)            (EIC_CONFIG1_SENSE15_Msk & ((value) << EIC_CONFIG1_SENSE15_Pos))
#define   EIC_CONFIG1_SENSE15_NONE_Val        _U_(0x0)                                             /**< (EIC_CONFIG1) No detection  */
#define   EIC_CONFIG1_SENSE15_RISE_Val        _U_(0x1)                                             /**< (EIC_CONFIG1) Rising edge detection  */
#define   EIC_CONFIG1_SENSE15_FALL_Val        _U_(0x2)                                             /**< (EIC_CONFIG1) Falling edge detection  */
#define   EIC_CONFIG1_SENSE15_BOTH_Val        _U_(0x3)                                             /**< (EIC_CONFIG1) Both edges detection  */
#define   EIC_CONFIG1_SENSE15_HIGH_Val        _U_(0x4)                                             /**< (EIC_CONFIG1) High level detection  */
#define   EIC_CONFIG1_SENSE15_LOW_Val         _U_(0x5)                                             /**< (EIC_CONFIG1) Low level detection  */
#define EIC_CONFIG1_SENSE15_NONE              (EIC_CONFIG1_SENSE15_NONE_Val << EIC_CONFIG1_SENSE15_Pos) /**< (EIC_CONFIG1) No detection Position  */
#define EIC_CONFIG1_SENSE15_RISE              (EIC_CONFIG1_SENSE15_RISE_Val << EIC_CONFIG1_SENSE15_Pos) /**< (EIC_CONFIG1) Rising edge detection Position  */
#define EIC_CONFIG1_SENSE15_FALL              (EIC_CONFIG1_SENSE15_FALL_Val << EIC_CONFIG1_SENSE15_Pos) /**< (EIC_CONFIG1) Falling edge detection Position  */
#define EIC_CONFIG1_SENSE15_BOTH              (EIC_CONFIG1_SENSE15_BOTH_Val << EIC_CONFIG1_SENSE15_Pos) /**< (EIC_CONFIG1) Both edges detection Position  */
#define EIC_CONFIG1_SENSE15_HIGH              (EIC_CONFIG1_SENSE15_HIGH_Val << EIC_CONFIG1_SENSE15_Pos) /**< (EIC_CONFIG1) High level detection Position  */
#define EIC_CONFIG1_SENSE15_LOW               (EIC_CONFIG1_SENSE15_LOW_Val << EIC_CONFIG1_SENSE15_Pos) /**< (EIC_CONFIG1) Low level detection Position  */
#define EIC_CONFIG1_FILTEN15_Pos              _U_(31)                                              /**< (EIC_CONFIG1) Filter Enable 15 Position */
#define EIC_CONFIG1_FILTEN15_Msk              (_U_(0x1) << EIC_CONFIG1_FILTEN15_Pos)               /**< (EIC_CONFIG1) Filter Enable 15 Mask */
#define EIC_CONFIG1_FILTEN15(value)           (EIC_CONFIG1_FILTEN15_Msk & ((value) << EIC_CONFIG1_FILTEN15_Pos))
#define EIC_CONFIG1_Msk                       _U_(0xFFFFFFFF)                                      /**< (EIC_CONFIG1) Register Mask  */


/** \brief EIC register offsets definitions */
#define EIC_CTRLA_REG_OFST             (0x00)              /**< (EIC_CTRLA) Control A Offset */
#define EIC_NMICTRL_REG_OFST           (0x01)              /**< (EIC_NMICTRL) Non-Maskable Interrupt Control Offset */
#define EIC_NMIFLAG_REG_OFST           (0x02)              /**< (EIC_NMIFLAG) Non-Maskable Interrupt Flag Status and Clear Offset */
#define EIC_SYNCBUSY_REG_OFST          (0x04)              /**< (EIC_SYNCBUSY) Synchronization Busy Offset */
#define EIC_EVCTRL_REG_OFST            (0x08)              /**< (EIC_EVCTRL) Event Control Offset */
#define EIC_INTENCLR_REG_OFST          (0x0C)              /**< (EIC_INTENCLR) Interrupt Enable Clear Offset */
#define EIC_INTENSET_REG_OFST          (0x10)              /**< (EIC_INTENSET) Interrupt Enable Set Offset */
#define EIC_INTFLAG_REG_OFST           (0x14)              /**< (EIC_INTFLAG) Interrupt Flag Status and Clear Offset */
#define EIC_ASYNCH_REG_OFST            (0x18)              /**< (EIC_ASYNCH) External Interrupt Asynchronous Mode Offset */
#define EIC_CONFIG0_REG_OFST           (0x1C)              /**< (EIC_CONFIG0) External Interrupt Sense Configuration Offset */
#define EIC_CONFIG1_REG_OFST           (0x20)              /**< (EIC_CONFIG1) External Interrupt Sense Configuration Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief EIC register API structure */
typedef struct
{  /* External Interrupt Controller */
  __IO  uint8_t                        EIC_CTRLA;          /**< Offset: 0x00 (R/W  8) Control A */
  __IO  uint8_t                        EIC_NMICTRL;        /**< Offset: 0x01 (R/W  8) Non-Maskable Interrupt Control */
  __IO  uint16_t                       EIC_NMIFLAG;        /**< Offset: 0x02 (R/W  16) Non-Maskable Interrupt Flag Status and Clear */
  __I   uint32_t                       EIC_SYNCBUSY;       /**< Offset: 0x04 (R/   32) Synchronization Busy */
  __IO  uint32_t                       EIC_EVCTRL;         /**< Offset: 0x08 (R/W  32) Event Control */
  __IO  uint32_t                       EIC_INTENCLR;       /**< Offset: 0x0C (R/W  32) Interrupt Enable Clear */
  __IO  uint32_t                       EIC_INTENSET;       /**< Offset: 0x10 (R/W  32) Interrupt Enable Set */
  __IO  uint32_t                       EIC_INTFLAG;        /**< Offset: 0x14 (R/W  32) Interrupt Flag Status and Clear */
  __IO  uint32_t                       EIC_ASYNCH;         /**< Offset: 0x18 (R/W  32) External Interrupt Asynchronous Mode */
  __IO  uint32_t                       EIC_CONFIG0;        /**< Offset: 0x1C (R/W  32) External Interrupt Sense Configuration */
  __IO  uint32_t                       EIC_CONFIG1;        /**< Offset: 0x20 (R/W  32) External Interrupt Sense Configuration */
} eic_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _PIC32CMMC00_EIC_COMPONENT_H_ */
