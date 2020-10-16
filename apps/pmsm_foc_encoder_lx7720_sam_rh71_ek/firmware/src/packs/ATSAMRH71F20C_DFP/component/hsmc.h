/**
 * \brief Component description for HSMC
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
#ifndef _SAMRH71_HSMC_COMPONENT_H_
#define _SAMRH71_HSMC_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR HSMC                                         */
/* ************************************************************************** */

/* -------- HSMC_SETUP0 : (HSMC Offset: 0x00) (R/W 32) HSMC Setup Register (CS_number = 0) -------- */
#define HSMC_SETUP0_NWE_SETUP_Pos             _U_(0)                                               /**< (HSMC_SETUP0) NWE Setup Length Position */
#define HSMC_SETUP0_NWE_SETUP_Msk             (_U_(0x3F) << HSMC_SETUP0_NWE_SETUP_Pos)             /**< (HSMC_SETUP0) NWE Setup Length Mask */
#define HSMC_SETUP0_NWE_SETUP(value)          (HSMC_SETUP0_NWE_SETUP_Msk & ((value) << HSMC_SETUP0_NWE_SETUP_Pos))
#define HSMC_SETUP0_NCS_WR_SETUP_Pos          _U_(8)                                               /**< (HSMC_SETUP0) NCS Setup Length in WRITE Access Position */
#define HSMC_SETUP0_NCS_WR_SETUP_Msk          (_U_(0x3F) << HSMC_SETUP0_NCS_WR_SETUP_Pos)          /**< (HSMC_SETUP0) NCS Setup Length in WRITE Access Mask */
#define HSMC_SETUP0_NCS_WR_SETUP(value)       (HSMC_SETUP0_NCS_WR_SETUP_Msk & ((value) << HSMC_SETUP0_NCS_WR_SETUP_Pos))
#define HSMC_SETUP0_NRD_SETUP_Pos             _U_(16)                                              /**< (HSMC_SETUP0) NRD Setup Length Position */
#define HSMC_SETUP0_NRD_SETUP_Msk             (_U_(0x3F) << HSMC_SETUP0_NRD_SETUP_Pos)             /**< (HSMC_SETUP0) NRD Setup Length Mask */
#define HSMC_SETUP0_NRD_SETUP(value)          (HSMC_SETUP0_NRD_SETUP_Msk & ((value) << HSMC_SETUP0_NRD_SETUP_Pos))
#define HSMC_SETUP0_NCS_RD_SETUP_Pos          _U_(24)                                              /**< (HSMC_SETUP0) NCS Setup Length in READ Access Position */
#define HSMC_SETUP0_NCS_RD_SETUP_Msk          (_U_(0x3F) << HSMC_SETUP0_NCS_RD_SETUP_Pos)          /**< (HSMC_SETUP0) NCS Setup Length in READ Access Mask */
#define HSMC_SETUP0_NCS_RD_SETUP(value)       (HSMC_SETUP0_NCS_RD_SETUP_Msk & ((value) << HSMC_SETUP0_NCS_RD_SETUP_Pos))
#define HSMC_SETUP0_Msk                       _U_(0x3F3F3F3F)                                      /**< (HSMC_SETUP0) Register Mask  */


/* -------- HSMC_PULSE0 : (HSMC Offset: 0x04) (R/W 32) HSMC Pulse Register (CS_number = 0) -------- */
#define HSMC_PULSE0_NWE_PULSE_Pos             _U_(0)                                               /**< (HSMC_PULSE0) NWE Pulse Length Position */
#define HSMC_PULSE0_NWE_PULSE_Msk             (_U_(0x7F) << HSMC_PULSE0_NWE_PULSE_Pos)             /**< (HSMC_PULSE0) NWE Pulse Length Mask */
#define HSMC_PULSE0_NWE_PULSE(value)          (HSMC_PULSE0_NWE_PULSE_Msk & ((value) << HSMC_PULSE0_NWE_PULSE_Pos))
#define HSMC_PULSE0_NCS_WR_PULSE_Pos          _U_(8)                                               /**< (HSMC_PULSE0) NCS Pulse Length in WRITE Access Position */
#define HSMC_PULSE0_NCS_WR_PULSE_Msk          (_U_(0x7F) << HSMC_PULSE0_NCS_WR_PULSE_Pos)          /**< (HSMC_PULSE0) NCS Pulse Length in WRITE Access Mask */
#define HSMC_PULSE0_NCS_WR_PULSE(value)       (HSMC_PULSE0_NCS_WR_PULSE_Msk & ((value) << HSMC_PULSE0_NCS_WR_PULSE_Pos))
#define HSMC_PULSE0_NRD_PULSE_Pos             _U_(16)                                              /**< (HSMC_PULSE0) NRD Pulse Length Position */
#define HSMC_PULSE0_NRD_PULSE_Msk             (_U_(0x7F) << HSMC_PULSE0_NRD_PULSE_Pos)             /**< (HSMC_PULSE0) NRD Pulse Length Mask */
#define HSMC_PULSE0_NRD_PULSE(value)          (HSMC_PULSE0_NRD_PULSE_Msk & ((value) << HSMC_PULSE0_NRD_PULSE_Pos))
#define HSMC_PULSE0_NCS_RD_PULSE_Pos          _U_(24)                                              /**< (HSMC_PULSE0) NCS Pulse Length in READ Access Position */
#define HSMC_PULSE0_NCS_RD_PULSE_Msk          (_U_(0x7F) << HSMC_PULSE0_NCS_RD_PULSE_Pos)          /**< (HSMC_PULSE0) NCS Pulse Length in READ Access Mask */
#define HSMC_PULSE0_NCS_RD_PULSE(value)       (HSMC_PULSE0_NCS_RD_PULSE_Msk & ((value) << HSMC_PULSE0_NCS_RD_PULSE_Pos))
#define HSMC_PULSE0_Msk                       _U_(0x7F7F7F7F)                                      /**< (HSMC_PULSE0) Register Mask  */


/* -------- HSMC_CYCLE0 : (HSMC Offset: 0x08) (R/W 32) HSMC Cycle Register (CS_number = 0) -------- */
#define HSMC_CYCLE0_NWE_CYCLE_Pos             _U_(0)                                               /**< (HSMC_CYCLE0) Total Write Cycle Length Position */
#define HSMC_CYCLE0_NWE_CYCLE_Msk             (_U_(0x1FF) << HSMC_CYCLE0_NWE_CYCLE_Pos)            /**< (HSMC_CYCLE0) Total Write Cycle Length Mask */
#define HSMC_CYCLE0_NWE_CYCLE(value)          (HSMC_CYCLE0_NWE_CYCLE_Msk & ((value) << HSMC_CYCLE0_NWE_CYCLE_Pos))
#define HSMC_CYCLE0_NRD_CYCLE_Pos             _U_(16)                                              /**< (HSMC_CYCLE0) Total Read Cycle Length Position */
#define HSMC_CYCLE0_NRD_CYCLE_Msk             (_U_(0x1FF) << HSMC_CYCLE0_NRD_CYCLE_Pos)            /**< (HSMC_CYCLE0) Total Read Cycle Length Mask */
#define HSMC_CYCLE0_NRD_CYCLE(value)          (HSMC_CYCLE0_NRD_CYCLE_Msk & ((value) << HSMC_CYCLE0_NRD_CYCLE_Pos))
#define HSMC_CYCLE0_Msk                       _U_(0x01FF01FF)                                      /**< (HSMC_CYCLE0) Register Mask  */


/* -------- HSMC_MODE0 : (HSMC Offset: 0x0C) (R/W 32) HSMC Mode Register (CS_number = 0) -------- */
#define HSMC_MODE0_READ_MODE_Pos              _U_(0)                                               /**< (HSMC_MODE0) Read Mode Position */
#define HSMC_MODE0_READ_MODE_Msk              (_U_(0x1) << HSMC_MODE0_READ_MODE_Pos)               /**< (HSMC_MODE0) Read Mode Mask */
#define HSMC_MODE0_READ_MODE(value)           (HSMC_MODE0_READ_MODE_Msk & ((value) << HSMC_MODE0_READ_MODE_Pos))
#define HSMC_MODE0_WRITE_MODE_Pos             _U_(1)                                               /**< (HSMC_MODE0) Write Mode Position */
#define HSMC_MODE0_WRITE_MODE_Msk             (_U_(0x1) << HSMC_MODE0_WRITE_MODE_Pos)              /**< (HSMC_MODE0) Write Mode Mask */
#define HSMC_MODE0_WRITE_MODE(value)          (HSMC_MODE0_WRITE_MODE_Msk & ((value) << HSMC_MODE0_WRITE_MODE_Pos))
#define HSMC_MODE0_RMW_ENABLE_Pos             _U_(2)                                               /**< (HSMC_MODE0) Read-Modify Write enable Position */
#define HSMC_MODE0_RMW_ENABLE_Msk             (_U_(0x1) << HSMC_MODE0_RMW_ENABLE_Pos)              /**< (HSMC_MODE0) Read-Modify Write enable Mask */
#define HSMC_MODE0_RMW_ENABLE(value)          (HSMC_MODE0_RMW_ENABLE_Msk & ((value) << HSMC_MODE0_RMW_ENABLE_Pos))
#define HSMC_MODE0_EXNW_MODE_Pos              _U_(4)                                               /**< (HSMC_MODE0) NWAIT Mode Position */
#define HSMC_MODE0_EXNW_MODE_Msk              (_U_(0x3) << HSMC_MODE0_EXNW_MODE_Pos)               /**< (HSMC_MODE0) NWAIT Mode Mask */
#define HSMC_MODE0_EXNW_MODE(value)           (HSMC_MODE0_EXNW_MODE_Msk & ((value) << HSMC_MODE0_EXNW_MODE_Pos))
#define   HSMC_MODE0_EXNW_MODE_DISABLED_Val   _U_(0x0)                                             /**< (HSMC_MODE0) Disabled-The NWAIT input signal is ignored on the corresponding chip select.  */
#define   HSMC_MODE0_EXNW_MODE_FROZEN_Val     _U_(0x2)                                             /**< (HSMC_MODE0) Frozen Mode-If asserted, the NWAIT signal freezes the current read or write cycle. After deassertion, the read/write cycle is resumed from the point where it was stopped.  */
#define   HSMC_MODE0_EXNW_MODE_READY_Val      _U_(0x3)                                             /**< (HSMC_MODE0) Ready Mode-The NWAIT signal indicates the availability of the external device at the end of the pulse of the controlling read or write signal, to complete the access. If high, the access normally completes. If low, the access is extended until NWAIT returns high.  */
#define HSMC_MODE0_EXNW_MODE_DISABLED         (HSMC_MODE0_EXNW_MODE_DISABLED_Val << HSMC_MODE0_EXNW_MODE_Pos) /**< (HSMC_MODE0) Disabled-The NWAIT input signal is ignored on the corresponding chip select. Position  */
#define HSMC_MODE0_EXNW_MODE_FROZEN           (HSMC_MODE0_EXNW_MODE_FROZEN_Val << HSMC_MODE0_EXNW_MODE_Pos) /**< (HSMC_MODE0) Frozen Mode-If asserted, the NWAIT signal freezes the current read or write cycle. After deassertion, the read/write cycle is resumed from the point where it was stopped. Position  */
#define HSMC_MODE0_EXNW_MODE_READY            (HSMC_MODE0_EXNW_MODE_READY_Val << HSMC_MODE0_EXNW_MODE_Pos) /**< (HSMC_MODE0) Ready Mode-The NWAIT signal indicates the availability of the external device at the end of the pulse of the controlling read or write signal, to complete the access. If high, the access normally completes. If low, the access is extended until NWAIT returns high. Position  */
#define HSMC_MODE0_DBW_Pos                    _U_(8)                                               /**< (HSMC_MODE0) Data Bus Width Position */
#define HSMC_MODE0_DBW_Msk                    (_U_(0x3) << HSMC_MODE0_DBW_Pos)                     /**< (HSMC_MODE0) Data Bus Width Mask */
#define HSMC_MODE0_DBW(value)                 (HSMC_MODE0_DBW_Msk & ((value) << HSMC_MODE0_DBW_Pos))
#define   HSMC_MODE0_DBW_8_BIT_Val            _U_(0x0)                                             /**< (HSMC_MODE0) 8-bit Data Bus  */
#define   HSMC_MODE0_DBW_16_BIT_Val           _U_(0x1)                                             /**< (HSMC_MODE0) 16-bit Data Bus  */
#define   HSMC_MODE0_DBW_32_BIT_Val           _U_(0x2)                                             /**< (HSMC_MODE0) 32-bit Data Bus  */
#define HSMC_MODE0_DBW_8_BIT                  (HSMC_MODE0_DBW_8_BIT_Val << HSMC_MODE0_DBW_Pos)     /**< (HSMC_MODE0) 8-bit Data Bus Position  */
#define HSMC_MODE0_DBW_16_BIT                 (HSMC_MODE0_DBW_16_BIT_Val << HSMC_MODE0_DBW_Pos)    /**< (HSMC_MODE0) 16-bit Data Bus Position  */
#define HSMC_MODE0_DBW_32_BIT                 (HSMC_MODE0_DBW_32_BIT_Val << HSMC_MODE0_DBW_Pos)    /**< (HSMC_MODE0) 32-bit Data Bus Position  */
#define HSMC_MODE0_Msk                        _U_(0x00000337)                                      /**< (HSMC_MODE0) Register Mask  */


/* -------- HSMC_SETUP1 : (HSMC Offset: 0x10) (R/W 32) HSMC Setup Register (CS_number = 1) -------- */
#define HSMC_SETUP1_NWE_SETUP_Pos             _U_(0)                                               /**< (HSMC_SETUP1) NWE Setup Length Position */
#define HSMC_SETUP1_NWE_SETUP_Msk             (_U_(0x3F) << HSMC_SETUP1_NWE_SETUP_Pos)             /**< (HSMC_SETUP1) NWE Setup Length Mask */
#define HSMC_SETUP1_NWE_SETUP(value)          (HSMC_SETUP1_NWE_SETUP_Msk & ((value) << HSMC_SETUP1_NWE_SETUP_Pos))
#define HSMC_SETUP1_NCS_WR_SETUP_Pos          _U_(8)                                               /**< (HSMC_SETUP1) NCS Setup Length in WRITE Access Position */
#define HSMC_SETUP1_NCS_WR_SETUP_Msk          (_U_(0x3F) << HSMC_SETUP1_NCS_WR_SETUP_Pos)          /**< (HSMC_SETUP1) NCS Setup Length in WRITE Access Mask */
#define HSMC_SETUP1_NCS_WR_SETUP(value)       (HSMC_SETUP1_NCS_WR_SETUP_Msk & ((value) << HSMC_SETUP1_NCS_WR_SETUP_Pos))
#define HSMC_SETUP1_NRD_SETUP_Pos             _U_(16)                                              /**< (HSMC_SETUP1) NRD Setup Length Position */
#define HSMC_SETUP1_NRD_SETUP_Msk             (_U_(0x3F) << HSMC_SETUP1_NRD_SETUP_Pos)             /**< (HSMC_SETUP1) NRD Setup Length Mask */
#define HSMC_SETUP1_NRD_SETUP(value)          (HSMC_SETUP1_NRD_SETUP_Msk & ((value) << HSMC_SETUP1_NRD_SETUP_Pos))
#define HSMC_SETUP1_NCS_RD_SETUP_Pos          _U_(24)                                              /**< (HSMC_SETUP1) NCS Setup Length in READ Access Position */
#define HSMC_SETUP1_NCS_RD_SETUP_Msk          (_U_(0x3F) << HSMC_SETUP1_NCS_RD_SETUP_Pos)          /**< (HSMC_SETUP1) NCS Setup Length in READ Access Mask */
#define HSMC_SETUP1_NCS_RD_SETUP(value)       (HSMC_SETUP1_NCS_RD_SETUP_Msk & ((value) << HSMC_SETUP1_NCS_RD_SETUP_Pos))
#define HSMC_SETUP1_Msk                       _U_(0x3F3F3F3F)                                      /**< (HSMC_SETUP1) Register Mask  */


/* -------- HSMC_PULSE1 : (HSMC Offset: 0x14) (R/W 32) HSMC Pulse Register (CS_number = 1) -------- */
#define HSMC_PULSE1_NWE_PULSE_Pos             _U_(0)                                               /**< (HSMC_PULSE1) NWE Pulse Length Position */
#define HSMC_PULSE1_NWE_PULSE_Msk             (_U_(0x7F) << HSMC_PULSE1_NWE_PULSE_Pos)             /**< (HSMC_PULSE1) NWE Pulse Length Mask */
#define HSMC_PULSE1_NWE_PULSE(value)          (HSMC_PULSE1_NWE_PULSE_Msk & ((value) << HSMC_PULSE1_NWE_PULSE_Pos))
#define HSMC_PULSE1_NCS_WR_PULSE_Pos          _U_(8)                                               /**< (HSMC_PULSE1) NCS Pulse Length in WRITE Access Position */
#define HSMC_PULSE1_NCS_WR_PULSE_Msk          (_U_(0x7F) << HSMC_PULSE1_NCS_WR_PULSE_Pos)          /**< (HSMC_PULSE1) NCS Pulse Length in WRITE Access Mask */
#define HSMC_PULSE1_NCS_WR_PULSE(value)       (HSMC_PULSE1_NCS_WR_PULSE_Msk & ((value) << HSMC_PULSE1_NCS_WR_PULSE_Pos))
#define HSMC_PULSE1_NRD_PULSE_Pos             _U_(16)                                              /**< (HSMC_PULSE1) NRD Pulse Length Position */
#define HSMC_PULSE1_NRD_PULSE_Msk             (_U_(0x7F) << HSMC_PULSE1_NRD_PULSE_Pos)             /**< (HSMC_PULSE1) NRD Pulse Length Mask */
#define HSMC_PULSE1_NRD_PULSE(value)          (HSMC_PULSE1_NRD_PULSE_Msk & ((value) << HSMC_PULSE1_NRD_PULSE_Pos))
#define HSMC_PULSE1_NCS_RD_PULSE_Pos          _U_(24)                                              /**< (HSMC_PULSE1) NCS Pulse Length in READ Access Position */
#define HSMC_PULSE1_NCS_RD_PULSE_Msk          (_U_(0x7F) << HSMC_PULSE1_NCS_RD_PULSE_Pos)          /**< (HSMC_PULSE1) NCS Pulse Length in READ Access Mask */
#define HSMC_PULSE1_NCS_RD_PULSE(value)       (HSMC_PULSE1_NCS_RD_PULSE_Msk & ((value) << HSMC_PULSE1_NCS_RD_PULSE_Pos))
#define HSMC_PULSE1_Msk                       _U_(0x7F7F7F7F)                                      /**< (HSMC_PULSE1) Register Mask  */


/* -------- HSMC_CYCLE1 : (HSMC Offset: 0x18) (R/W 32) HSMC Cycle Register (CS_number = 1) -------- */
#define HSMC_CYCLE1_NWE_CYCLE_Pos             _U_(0)                                               /**< (HSMC_CYCLE1) Total Write Cycle Length Position */
#define HSMC_CYCLE1_NWE_CYCLE_Msk             (_U_(0x1FF) << HSMC_CYCLE1_NWE_CYCLE_Pos)            /**< (HSMC_CYCLE1) Total Write Cycle Length Mask */
#define HSMC_CYCLE1_NWE_CYCLE(value)          (HSMC_CYCLE1_NWE_CYCLE_Msk & ((value) << HSMC_CYCLE1_NWE_CYCLE_Pos))
#define HSMC_CYCLE1_NRD_CYCLE_Pos             _U_(16)                                              /**< (HSMC_CYCLE1) Total Read Cycle Length Position */
#define HSMC_CYCLE1_NRD_CYCLE_Msk             (_U_(0x1FF) << HSMC_CYCLE1_NRD_CYCLE_Pos)            /**< (HSMC_CYCLE1) Total Read Cycle Length Mask */
#define HSMC_CYCLE1_NRD_CYCLE(value)          (HSMC_CYCLE1_NRD_CYCLE_Msk & ((value) << HSMC_CYCLE1_NRD_CYCLE_Pos))
#define HSMC_CYCLE1_Msk                       _U_(0x01FF01FF)                                      /**< (HSMC_CYCLE1) Register Mask  */


/* -------- HSMC_MODE1 : (HSMC Offset: 0x1C) (R/W 32) HSMC Mode Register (CS_number = 1) -------- */
#define HSMC_MODE1_READ_MODE_Pos              _U_(0)                                               /**< (HSMC_MODE1) Read Mode Position */
#define HSMC_MODE1_READ_MODE_Msk              (_U_(0x1) << HSMC_MODE1_READ_MODE_Pos)               /**< (HSMC_MODE1) Read Mode Mask */
#define HSMC_MODE1_READ_MODE(value)           (HSMC_MODE1_READ_MODE_Msk & ((value) << HSMC_MODE1_READ_MODE_Pos))
#define HSMC_MODE1_WRITE_MODE_Pos             _U_(1)                                               /**< (HSMC_MODE1) Write Mode Position */
#define HSMC_MODE1_WRITE_MODE_Msk             (_U_(0x1) << HSMC_MODE1_WRITE_MODE_Pos)              /**< (HSMC_MODE1) Write Mode Mask */
#define HSMC_MODE1_WRITE_MODE(value)          (HSMC_MODE1_WRITE_MODE_Msk & ((value) << HSMC_MODE1_WRITE_MODE_Pos))
#define HSMC_MODE1_RMW_ENABLE_Pos             _U_(2)                                               /**< (HSMC_MODE1) Read-Modify Write enable Position */
#define HSMC_MODE1_RMW_ENABLE_Msk             (_U_(0x1) << HSMC_MODE1_RMW_ENABLE_Pos)              /**< (HSMC_MODE1) Read-Modify Write enable Mask */
#define HSMC_MODE1_RMW_ENABLE(value)          (HSMC_MODE1_RMW_ENABLE_Msk & ((value) << HSMC_MODE1_RMW_ENABLE_Pos))
#define HSMC_MODE1_EXNW_MODE_Pos              _U_(4)                                               /**< (HSMC_MODE1) NWAIT Mode Position */
#define HSMC_MODE1_EXNW_MODE_Msk              (_U_(0x3) << HSMC_MODE1_EXNW_MODE_Pos)               /**< (HSMC_MODE1) NWAIT Mode Mask */
#define HSMC_MODE1_EXNW_MODE(value)           (HSMC_MODE1_EXNW_MODE_Msk & ((value) << HSMC_MODE1_EXNW_MODE_Pos))
#define   HSMC_MODE1_EXNW_MODE_DISABLED_Val   _U_(0x0)                                             /**< (HSMC_MODE1) Disabled-The NWAIT input signal is ignored on the corresponding chip select.  */
#define   HSMC_MODE1_EXNW_MODE_FROZEN_Val     _U_(0x2)                                             /**< (HSMC_MODE1) Frozen Mode-If asserted, the NWAIT signal freezes the current read or write cycle. After deassertion, the read/write cycle is resumed from the point where it was stopped.  */
#define   HSMC_MODE1_EXNW_MODE_READY_Val      _U_(0x3)                                             /**< (HSMC_MODE1) Ready Mode-The NWAIT signal indicates the availability of the external device at the end of the pulse of the controlling read or write signal, to complete the access. If high, the access normally completes. If low, the access is extended until NWAIT returns high.  */
#define HSMC_MODE1_EXNW_MODE_DISABLED         (HSMC_MODE1_EXNW_MODE_DISABLED_Val << HSMC_MODE1_EXNW_MODE_Pos) /**< (HSMC_MODE1) Disabled-The NWAIT input signal is ignored on the corresponding chip select. Position  */
#define HSMC_MODE1_EXNW_MODE_FROZEN           (HSMC_MODE1_EXNW_MODE_FROZEN_Val << HSMC_MODE1_EXNW_MODE_Pos) /**< (HSMC_MODE1) Frozen Mode-If asserted, the NWAIT signal freezes the current read or write cycle. After deassertion, the read/write cycle is resumed from the point where it was stopped. Position  */
#define HSMC_MODE1_EXNW_MODE_READY            (HSMC_MODE1_EXNW_MODE_READY_Val << HSMC_MODE1_EXNW_MODE_Pos) /**< (HSMC_MODE1) Ready Mode-The NWAIT signal indicates the availability of the external device at the end of the pulse of the controlling read or write signal, to complete the access. If high, the access normally completes. If low, the access is extended until NWAIT returns high. Position  */
#define HSMC_MODE1_DBW_Pos                    _U_(8)                                               /**< (HSMC_MODE1) Data Bus Width Position */
#define HSMC_MODE1_DBW_Msk                    (_U_(0x3) << HSMC_MODE1_DBW_Pos)                     /**< (HSMC_MODE1) Data Bus Width Mask */
#define HSMC_MODE1_DBW(value)                 (HSMC_MODE1_DBW_Msk & ((value) << HSMC_MODE1_DBW_Pos))
#define   HSMC_MODE1_DBW_8_BIT_Val            _U_(0x0)                                             /**< (HSMC_MODE1) 8-bit Data Bus  */
#define   HSMC_MODE1_DBW_16_BIT_Val           _U_(0x1)                                             /**< (HSMC_MODE1) 16-bit Data Bus  */
#define   HSMC_MODE1_DBW_32_BIT_Val           _U_(0x2)                                             /**< (HSMC_MODE1) 32-bit Data Bus  */
#define HSMC_MODE1_DBW_8_BIT                  (HSMC_MODE1_DBW_8_BIT_Val << HSMC_MODE1_DBW_Pos)     /**< (HSMC_MODE1) 8-bit Data Bus Position  */
#define HSMC_MODE1_DBW_16_BIT                 (HSMC_MODE1_DBW_16_BIT_Val << HSMC_MODE1_DBW_Pos)    /**< (HSMC_MODE1) 16-bit Data Bus Position  */
#define HSMC_MODE1_DBW_32_BIT                 (HSMC_MODE1_DBW_32_BIT_Val << HSMC_MODE1_DBW_Pos)    /**< (HSMC_MODE1) 32-bit Data Bus Position  */
#define HSMC_MODE1_Msk                        _U_(0x00000337)                                      /**< (HSMC_MODE1) Register Mask  */


/* -------- HSMC_SETUP2 : (HSMC Offset: 0x20) (R/W 32) HSMC Setup Register (CS_number = 2) -------- */
#define HSMC_SETUP2_NWE_SETUP_Pos             _U_(0)                                               /**< (HSMC_SETUP2) NWE Setup Length Position */
#define HSMC_SETUP2_NWE_SETUP_Msk             (_U_(0x3F) << HSMC_SETUP2_NWE_SETUP_Pos)             /**< (HSMC_SETUP2) NWE Setup Length Mask */
#define HSMC_SETUP2_NWE_SETUP(value)          (HSMC_SETUP2_NWE_SETUP_Msk & ((value) << HSMC_SETUP2_NWE_SETUP_Pos))
#define HSMC_SETUP2_NCS_WR_SETUP_Pos          _U_(8)                                               /**< (HSMC_SETUP2) NCS Setup Length in WRITE Access Position */
#define HSMC_SETUP2_NCS_WR_SETUP_Msk          (_U_(0x3F) << HSMC_SETUP2_NCS_WR_SETUP_Pos)          /**< (HSMC_SETUP2) NCS Setup Length in WRITE Access Mask */
#define HSMC_SETUP2_NCS_WR_SETUP(value)       (HSMC_SETUP2_NCS_WR_SETUP_Msk & ((value) << HSMC_SETUP2_NCS_WR_SETUP_Pos))
#define HSMC_SETUP2_NRD_SETUP_Pos             _U_(16)                                              /**< (HSMC_SETUP2) NRD Setup Length Position */
#define HSMC_SETUP2_NRD_SETUP_Msk             (_U_(0x3F) << HSMC_SETUP2_NRD_SETUP_Pos)             /**< (HSMC_SETUP2) NRD Setup Length Mask */
#define HSMC_SETUP2_NRD_SETUP(value)          (HSMC_SETUP2_NRD_SETUP_Msk & ((value) << HSMC_SETUP2_NRD_SETUP_Pos))
#define HSMC_SETUP2_NCS_RD_SETUP_Pos          _U_(24)                                              /**< (HSMC_SETUP2) NCS Setup Length in READ Access Position */
#define HSMC_SETUP2_NCS_RD_SETUP_Msk          (_U_(0x3F) << HSMC_SETUP2_NCS_RD_SETUP_Pos)          /**< (HSMC_SETUP2) NCS Setup Length in READ Access Mask */
#define HSMC_SETUP2_NCS_RD_SETUP(value)       (HSMC_SETUP2_NCS_RD_SETUP_Msk & ((value) << HSMC_SETUP2_NCS_RD_SETUP_Pos))
#define HSMC_SETUP2_Msk                       _U_(0x3F3F3F3F)                                      /**< (HSMC_SETUP2) Register Mask  */


/* -------- HSMC_PULSE2 : (HSMC Offset: 0x24) (R/W 32) HSMC Pulse Register (CS_number = 2) -------- */
#define HSMC_PULSE2_NWE_PULSE_Pos             _U_(0)                                               /**< (HSMC_PULSE2) NWE Pulse Length Position */
#define HSMC_PULSE2_NWE_PULSE_Msk             (_U_(0x7F) << HSMC_PULSE2_NWE_PULSE_Pos)             /**< (HSMC_PULSE2) NWE Pulse Length Mask */
#define HSMC_PULSE2_NWE_PULSE(value)          (HSMC_PULSE2_NWE_PULSE_Msk & ((value) << HSMC_PULSE2_NWE_PULSE_Pos))
#define HSMC_PULSE2_NCS_WR_PULSE_Pos          _U_(8)                                               /**< (HSMC_PULSE2) NCS Pulse Length in WRITE Access Position */
#define HSMC_PULSE2_NCS_WR_PULSE_Msk          (_U_(0x7F) << HSMC_PULSE2_NCS_WR_PULSE_Pos)          /**< (HSMC_PULSE2) NCS Pulse Length in WRITE Access Mask */
#define HSMC_PULSE2_NCS_WR_PULSE(value)       (HSMC_PULSE2_NCS_WR_PULSE_Msk & ((value) << HSMC_PULSE2_NCS_WR_PULSE_Pos))
#define HSMC_PULSE2_NRD_PULSE_Pos             _U_(16)                                              /**< (HSMC_PULSE2) NRD Pulse Length Position */
#define HSMC_PULSE2_NRD_PULSE_Msk             (_U_(0x7F) << HSMC_PULSE2_NRD_PULSE_Pos)             /**< (HSMC_PULSE2) NRD Pulse Length Mask */
#define HSMC_PULSE2_NRD_PULSE(value)          (HSMC_PULSE2_NRD_PULSE_Msk & ((value) << HSMC_PULSE2_NRD_PULSE_Pos))
#define HSMC_PULSE2_NCS_RD_PULSE_Pos          _U_(24)                                              /**< (HSMC_PULSE2) NCS Pulse Length in READ Access Position */
#define HSMC_PULSE2_NCS_RD_PULSE_Msk          (_U_(0x7F) << HSMC_PULSE2_NCS_RD_PULSE_Pos)          /**< (HSMC_PULSE2) NCS Pulse Length in READ Access Mask */
#define HSMC_PULSE2_NCS_RD_PULSE(value)       (HSMC_PULSE2_NCS_RD_PULSE_Msk & ((value) << HSMC_PULSE2_NCS_RD_PULSE_Pos))
#define HSMC_PULSE2_Msk                       _U_(0x7F7F7F7F)                                      /**< (HSMC_PULSE2) Register Mask  */


/* -------- HSMC_CYCLE2 : (HSMC Offset: 0x28) (R/W 32) HSMC Cycle Register (CS_number = 2) -------- */
#define HSMC_CYCLE2_NWE_CYCLE_Pos             _U_(0)                                               /**< (HSMC_CYCLE2) Total Write Cycle Length Position */
#define HSMC_CYCLE2_NWE_CYCLE_Msk             (_U_(0x1FF) << HSMC_CYCLE2_NWE_CYCLE_Pos)            /**< (HSMC_CYCLE2) Total Write Cycle Length Mask */
#define HSMC_CYCLE2_NWE_CYCLE(value)          (HSMC_CYCLE2_NWE_CYCLE_Msk & ((value) << HSMC_CYCLE2_NWE_CYCLE_Pos))
#define HSMC_CYCLE2_NRD_CYCLE_Pos             _U_(16)                                              /**< (HSMC_CYCLE2) Total Read Cycle Length Position */
#define HSMC_CYCLE2_NRD_CYCLE_Msk             (_U_(0x1FF) << HSMC_CYCLE2_NRD_CYCLE_Pos)            /**< (HSMC_CYCLE2) Total Read Cycle Length Mask */
#define HSMC_CYCLE2_NRD_CYCLE(value)          (HSMC_CYCLE2_NRD_CYCLE_Msk & ((value) << HSMC_CYCLE2_NRD_CYCLE_Pos))
#define HSMC_CYCLE2_Msk                       _U_(0x01FF01FF)                                      /**< (HSMC_CYCLE2) Register Mask  */


/* -------- HSMC_MODE2 : (HSMC Offset: 0x2C) (R/W 32) HSMC Mode Register (CS_number = 2) -------- */
#define HSMC_MODE2_READ_MODE_Pos              _U_(0)                                               /**< (HSMC_MODE2) Read Mode Position */
#define HSMC_MODE2_READ_MODE_Msk              (_U_(0x1) << HSMC_MODE2_READ_MODE_Pos)               /**< (HSMC_MODE2) Read Mode Mask */
#define HSMC_MODE2_READ_MODE(value)           (HSMC_MODE2_READ_MODE_Msk & ((value) << HSMC_MODE2_READ_MODE_Pos))
#define HSMC_MODE2_WRITE_MODE_Pos             _U_(1)                                               /**< (HSMC_MODE2) Write Mode Position */
#define HSMC_MODE2_WRITE_MODE_Msk             (_U_(0x1) << HSMC_MODE2_WRITE_MODE_Pos)              /**< (HSMC_MODE2) Write Mode Mask */
#define HSMC_MODE2_WRITE_MODE(value)          (HSMC_MODE2_WRITE_MODE_Msk & ((value) << HSMC_MODE2_WRITE_MODE_Pos))
#define HSMC_MODE2_RMW_ENABLE_Pos             _U_(2)                                               /**< (HSMC_MODE2) Read-Modify Write enable Position */
#define HSMC_MODE2_RMW_ENABLE_Msk             (_U_(0x1) << HSMC_MODE2_RMW_ENABLE_Pos)              /**< (HSMC_MODE2) Read-Modify Write enable Mask */
#define HSMC_MODE2_RMW_ENABLE(value)          (HSMC_MODE2_RMW_ENABLE_Msk & ((value) << HSMC_MODE2_RMW_ENABLE_Pos))
#define HSMC_MODE2_EXNW_MODE_Pos              _U_(4)                                               /**< (HSMC_MODE2) NWAIT Mode Position */
#define HSMC_MODE2_EXNW_MODE_Msk              (_U_(0x3) << HSMC_MODE2_EXNW_MODE_Pos)               /**< (HSMC_MODE2) NWAIT Mode Mask */
#define HSMC_MODE2_EXNW_MODE(value)           (HSMC_MODE2_EXNW_MODE_Msk & ((value) << HSMC_MODE2_EXNW_MODE_Pos))
#define   HSMC_MODE2_EXNW_MODE_DISABLED_Val   _U_(0x0)                                             /**< (HSMC_MODE2) Disabled-The NWAIT input signal is ignored on the corresponding chip select.  */
#define   HSMC_MODE2_EXNW_MODE_FROZEN_Val     _U_(0x2)                                             /**< (HSMC_MODE2) Frozen Mode-If asserted, the NWAIT signal freezes the current read or write cycle. After deassertion, the read/write cycle is resumed from the point where it was stopped.  */
#define   HSMC_MODE2_EXNW_MODE_READY_Val      _U_(0x3)                                             /**< (HSMC_MODE2) Ready Mode-The NWAIT signal indicates the availability of the external device at the end of the pulse of the controlling read or write signal, to complete the access. If high, the access normally completes. If low, the access is extended until NWAIT returns high.  */
#define HSMC_MODE2_EXNW_MODE_DISABLED         (HSMC_MODE2_EXNW_MODE_DISABLED_Val << HSMC_MODE2_EXNW_MODE_Pos) /**< (HSMC_MODE2) Disabled-The NWAIT input signal is ignored on the corresponding chip select. Position  */
#define HSMC_MODE2_EXNW_MODE_FROZEN           (HSMC_MODE2_EXNW_MODE_FROZEN_Val << HSMC_MODE2_EXNW_MODE_Pos) /**< (HSMC_MODE2) Frozen Mode-If asserted, the NWAIT signal freezes the current read or write cycle. After deassertion, the read/write cycle is resumed from the point where it was stopped. Position  */
#define HSMC_MODE2_EXNW_MODE_READY            (HSMC_MODE2_EXNW_MODE_READY_Val << HSMC_MODE2_EXNW_MODE_Pos) /**< (HSMC_MODE2) Ready Mode-The NWAIT signal indicates the availability of the external device at the end of the pulse of the controlling read or write signal, to complete the access. If high, the access normally completes. If low, the access is extended until NWAIT returns high. Position  */
#define HSMC_MODE2_DBW_Pos                    _U_(8)                                               /**< (HSMC_MODE2) Data Bus Width Position */
#define HSMC_MODE2_DBW_Msk                    (_U_(0x3) << HSMC_MODE2_DBW_Pos)                     /**< (HSMC_MODE2) Data Bus Width Mask */
#define HSMC_MODE2_DBW(value)                 (HSMC_MODE2_DBW_Msk & ((value) << HSMC_MODE2_DBW_Pos))
#define   HSMC_MODE2_DBW_8_BIT_Val            _U_(0x0)                                             /**< (HSMC_MODE2) 8-bit Data Bus  */
#define   HSMC_MODE2_DBW_16_BIT_Val           _U_(0x1)                                             /**< (HSMC_MODE2) 16-bit Data Bus  */
#define   HSMC_MODE2_DBW_32_BIT_Val           _U_(0x2)                                             /**< (HSMC_MODE2) 32-bit Data Bus  */
#define HSMC_MODE2_DBW_8_BIT                  (HSMC_MODE2_DBW_8_BIT_Val << HSMC_MODE2_DBW_Pos)     /**< (HSMC_MODE2) 8-bit Data Bus Position  */
#define HSMC_MODE2_DBW_16_BIT                 (HSMC_MODE2_DBW_16_BIT_Val << HSMC_MODE2_DBW_Pos)    /**< (HSMC_MODE2) 16-bit Data Bus Position  */
#define HSMC_MODE2_DBW_32_BIT                 (HSMC_MODE2_DBW_32_BIT_Val << HSMC_MODE2_DBW_Pos)    /**< (HSMC_MODE2) 32-bit Data Bus Position  */
#define HSMC_MODE2_Msk                        _U_(0x00000337)                                      /**< (HSMC_MODE2) Register Mask  */


/* -------- HSMC_SETUP3 : (HSMC Offset: 0x30) (R/W 32) HSMC Setup Register (CS_number = 3) -------- */
#define HSMC_SETUP3_NWE_SETUP_Pos             _U_(0)                                               /**< (HSMC_SETUP3) NWE Setup Length Position */
#define HSMC_SETUP3_NWE_SETUP_Msk             (_U_(0x3F) << HSMC_SETUP3_NWE_SETUP_Pos)             /**< (HSMC_SETUP3) NWE Setup Length Mask */
#define HSMC_SETUP3_NWE_SETUP(value)          (HSMC_SETUP3_NWE_SETUP_Msk & ((value) << HSMC_SETUP3_NWE_SETUP_Pos))
#define HSMC_SETUP3_NCS_WR_SETUP_Pos          _U_(8)                                               /**< (HSMC_SETUP3) NCS Setup Length in WRITE Access Position */
#define HSMC_SETUP3_NCS_WR_SETUP_Msk          (_U_(0x3F) << HSMC_SETUP3_NCS_WR_SETUP_Pos)          /**< (HSMC_SETUP3) NCS Setup Length in WRITE Access Mask */
#define HSMC_SETUP3_NCS_WR_SETUP(value)       (HSMC_SETUP3_NCS_WR_SETUP_Msk & ((value) << HSMC_SETUP3_NCS_WR_SETUP_Pos))
#define HSMC_SETUP3_NRD_SETUP_Pos             _U_(16)                                              /**< (HSMC_SETUP3) NRD Setup Length Position */
#define HSMC_SETUP3_NRD_SETUP_Msk             (_U_(0x3F) << HSMC_SETUP3_NRD_SETUP_Pos)             /**< (HSMC_SETUP3) NRD Setup Length Mask */
#define HSMC_SETUP3_NRD_SETUP(value)          (HSMC_SETUP3_NRD_SETUP_Msk & ((value) << HSMC_SETUP3_NRD_SETUP_Pos))
#define HSMC_SETUP3_NCS_RD_SETUP_Pos          _U_(24)                                              /**< (HSMC_SETUP3) NCS Setup Length in READ Access Position */
#define HSMC_SETUP3_NCS_RD_SETUP_Msk          (_U_(0x3F) << HSMC_SETUP3_NCS_RD_SETUP_Pos)          /**< (HSMC_SETUP3) NCS Setup Length in READ Access Mask */
#define HSMC_SETUP3_NCS_RD_SETUP(value)       (HSMC_SETUP3_NCS_RD_SETUP_Msk & ((value) << HSMC_SETUP3_NCS_RD_SETUP_Pos))
#define HSMC_SETUP3_Msk                       _U_(0x3F3F3F3F)                                      /**< (HSMC_SETUP3) Register Mask  */


/* -------- HSMC_PULSE3 : (HSMC Offset: 0x34) (R/W 32) HSMC Pulse Register (CS_number = 3) -------- */
#define HSMC_PULSE3_NWE_PULSE_Pos             _U_(0)                                               /**< (HSMC_PULSE3) NWE Pulse Length Position */
#define HSMC_PULSE3_NWE_PULSE_Msk             (_U_(0x7F) << HSMC_PULSE3_NWE_PULSE_Pos)             /**< (HSMC_PULSE3) NWE Pulse Length Mask */
#define HSMC_PULSE3_NWE_PULSE(value)          (HSMC_PULSE3_NWE_PULSE_Msk & ((value) << HSMC_PULSE3_NWE_PULSE_Pos))
#define HSMC_PULSE3_NCS_WR_PULSE_Pos          _U_(8)                                               /**< (HSMC_PULSE3) NCS Pulse Length in WRITE Access Position */
#define HSMC_PULSE3_NCS_WR_PULSE_Msk          (_U_(0x7F) << HSMC_PULSE3_NCS_WR_PULSE_Pos)          /**< (HSMC_PULSE3) NCS Pulse Length in WRITE Access Mask */
#define HSMC_PULSE3_NCS_WR_PULSE(value)       (HSMC_PULSE3_NCS_WR_PULSE_Msk & ((value) << HSMC_PULSE3_NCS_WR_PULSE_Pos))
#define HSMC_PULSE3_NRD_PULSE_Pos             _U_(16)                                              /**< (HSMC_PULSE3) NRD Pulse Length Position */
#define HSMC_PULSE3_NRD_PULSE_Msk             (_U_(0x7F) << HSMC_PULSE3_NRD_PULSE_Pos)             /**< (HSMC_PULSE3) NRD Pulse Length Mask */
#define HSMC_PULSE3_NRD_PULSE(value)          (HSMC_PULSE3_NRD_PULSE_Msk & ((value) << HSMC_PULSE3_NRD_PULSE_Pos))
#define HSMC_PULSE3_NCS_RD_PULSE_Pos          _U_(24)                                              /**< (HSMC_PULSE3) NCS Pulse Length in READ Access Position */
#define HSMC_PULSE3_NCS_RD_PULSE_Msk          (_U_(0x7F) << HSMC_PULSE3_NCS_RD_PULSE_Pos)          /**< (HSMC_PULSE3) NCS Pulse Length in READ Access Mask */
#define HSMC_PULSE3_NCS_RD_PULSE(value)       (HSMC_PULSE3_NCS_RD_PULSE_Msk & ((value) << HSMC_PULSE3_NCS_RD_PULSE_Pos))
#define HSMC_PULSE3_Msk                       _U_(0x7F7F7F7F)                                      /**< (HSMC_PULSE3) Register Mask  */


/* -------- HSMC_CYCLE3 : (HSMC Offset: 0x38) (R/W 32) HSMC Cycle Register (CS_number = 3) -------- */
#define HSMC_CYCLE3_NWE_CYCLE_Pos             _U_(0)                                               /**< (HSMC_CYCLE3) Total Write Cycle Length Position */
#define HSMC_CYCLE3_NWE_CYCLE_Msk             (_U_(0x1FF) << HSMC_CYCLE3_NWE_CYCLE_Pos)            /**< (HSMC_CYCLE3) Total Write Cycle Length Mask */
#define HSMC_CYCLE3_NWE_CYCLE(value)          (HSMC_CYCLE3_NWE_CYCLE_Msk & ((value) << HSMC_CYCLE3_NWE_CYCLE_Pos))
#define HSMC_CYCLE3_NRD_CYCLE_Pos             _U_(16)                                              /**< (HSMC_CYCLE3) Total Read Cycle Length Position */
#define HSMC_CYCLE3_NRD_CYCLE_Msk             (_U_(0x1FF) << HSMC_CYCLE3_NRD_CYCLE_Pos)            /**< (HSMC_CYCLE3) Total Read Cycle Length Mask */
#define HSMC_CYCLE3_NRD_CYCLE(value)          (HSMC_CYCLE3_NRD_CYCLE_Msk & ((value) << HSMC_CYCLE3_NRD_CYCLE_Pos))
#define HSMC_CYCLE3_Msk                       _U_(0x01FF01FF)                                      /**< (HSMC_CYCLE3) Register Mask  */


/* -------- HSMC_MODE3 : (HSMC Offset: 0x3C) (R/W 32) HSMC Mode Register (CS_number = 3) -------- */
#define HSMC_MODE3_READ_MODE_Pos              _U_(0)                                               /**< (HSMC_MODE3) Read Mode Position */
#define HSMC_MODE3_READ_MODE_Msk              (_U_(0x1) << HSMC_MODE3_READ_MODE_Pos)               /**< (HSMC_MODE3) Read Mode Mask */
#define HSMC_MODE3_READ_MODE(value)           (HSMC_MODE3_READ_MODE_Msk & ((value) << HSMC_MODE3_READ_MODE_Pos))
#define HSMC_MODE3_WRITE_MODE_Pos             _U_(1)                                               /**< (HSMC_MODE3) Write Mode Position */
#define HSMC_MODE3_WRITE_MODE_Msk             (_U_(0x1) << HSMC_MODE3_WRITE_MODE_Pos)              /**< (HSMC_MODE3) Write Mode Mask */
#define HSMC_MODE3_WRITE_MODE(value)          (HSMC_MODE3_WRITE_MODE_Msk & ((value) << HSMC_MODE3_WRITE_MODE_Pos))
#define HSMC_MODE3_RMW_ENABLE_Pos             _U_(2)                                               /**< (HSMC_MODE3) Read-Modify Write enable Position */
#define HSMC_MODE3_RMW_ENABLE_Msk             (_U_(0x1) << HSMC_MODE3_RMW_ENABLE_Pos)              /**< (HSMC_MODE3) Read-Modify Write enable Mask */
#define HSMC_MODE3_RMW_ENABLE(value)          (HSMC_MODE3_RMW_ENABLE_Msk & ((value) << HSMC_MODE3_RMW_ENABLE_Pos))
#define HSMC_MODE3_EXNW_MODE_Pos              _U_(4)                                               /**< (HSMC_MODE3) NWAIT Mode Position */
#define HSMC_MODE3_EXNW_MODE_Msk              (_U_(0x3) << HSMC_MODE3_EXNW_MODE_Pos)               /**< (HSMC_MODE3) NWAIT Mode Mask */
#define HSMC_MODE3_EXNW_MODE(value)           (HSMC_MODE3_EXNW_MODE_Msk & ((value) << HSMC_MODE3_EXNW_MODE_Pos))
#define   HSMC_MODE3_EXNW_MODE_DISABLED_Val   _U_(0x0)                                             /**< (HSMC_MODE3) Disabled-The NWAIT input signal is ignored on the corresponding chip select.  */
#define   HSMC_MODE3_EXNW_MODE_FROZEN_Val     _U_(0x2)                                             /**< (HSMC_MODE3) Frozen Mode-If asserted, the NWAIT signal freezes the current read or write cycle. After deassertion, the read/write cycle is resumed from the point where it was stopped.  */
#define   HSMC_MODE3_EXNW_MODE_READY_Val      _U_(0x3)                                             /**< (HSMC_MODE3) Ready Mode-The NWAIT signal indicates the availability of the external device at the end of the pulse of the controlling read or write signal, to complete the access. If high, the access normally completes. If low, the access is extended until NWAIT returns high.  */
#define HSMC_MODE3_EXNW_MODE_DISABLED         (HSMC_MODE3_EXNW_MODE_DISABLED_Val << HSMC_MODE3_EXNW_MODE_Pos) /**< (HSMC_MODE3) Disabled-The NWAIT input signal is ignored on the corresponding chip select. Position  */
#define HSMC_MODE3_EXNW_MODE_FROZEN           (HSMC_MODE3_EXNW_MODE_FROZEN_Val << HSMC_MODE3_EXNW_MODE_Pos) /**< (HSMC_MODE3) Frozen Mode-If asserted, the NWAIT signal freezes the current read or write cycle. After deassertion, the read/write cycle is resumed from the point where it was stopped. Position  */
#define HSMC_MODE3_EXNW_MODE_READY            (HSMC_MODE3_EXNW_MODE_READY_Val << HSMC_MODE3_EXNW_MODE_Pos) /**< (HSMC_MODE3) Ready Mode-The NWAIT signal indicates the availability of the external device at the end of the pulse of the controlling read or write signal, to complete the access. If high, the access normally completes. If low, the access is extended until NWAIT returns high. Position  */
#define HSMC_MODE3_DBW_Pos                    _U_(8)                                               /**< (HSMC_MODE3) Data Bus Width Position */
#define HSMC_MODE3_DBW_Msk                    (_U_(0x3) << HSMC_MODE3_DBW_Pos)                     /**< (HSMC_MODE3) Data Bus Width Mask */
#define HSMC_MODE3_DBW(value)                 (HSMC_MODE3_DBW_Msk & ((value) << HSMC_MODE3_DBW_Pos))
#define   HSMC_MODE3_DBW_8_BIT_Val            _U_(0x0)                                             /**< (HSMC_MODE3) 8-bit Data Bus  */
#define   HSMC_MODE3_DBW_16_BIT_Val           _U_(0x1)                                             /**< (HSMC_MODE3) 16-bit Data Bus  */
#define   HSMC_MODE3_DBW_32_BIT_Val           _U_(0x2)                                             /**< (HSMC_MODE3) 32-bit Data Bus  */
#define HSMC_MODE3_DBW_8_BIT                  (HSMC_MODE3_DBW_8_BIT_Val << HSMC_MODE3_DBW_Pos)     /**< (HSMC_MODE3) 8-bit Data Bus Position  */
#define HSMC_MODE3_DBW_16_BIT                 (HSMC_MODE3_DBW_16_BIT_Val << HSMC_MODE3_DBW_Pos)    /**< (HSMC_MODE3) 16-bit Data Bus Position  */
#define HSMC_MODE3_DBW_32_BIT                 (HSMC_MODE3_DBW_32_BIT_Val << HSMC_MODE3_DBW_Pos)    /**< (HSMC_MODE3) 32-bit Data Bus Position  */
#define HSMC_MODE3_Msk                        _U_(0x00000337)                                      /**< (HSMC_MODE3) Register Mask  */


/* -------- HSMC_SETUP4 : (HSMC Offset: 0x40) (R/W 32) HSMC Setup Register (CS_number = 4) -------- */
#define HSMC_SETUP4_NWE_SETUP_Pos             _U_(0)                                               /**< (HSMC_SETUP4) NWE Setup Length Position */
#define HSMC_SETUP4_NWE_SETUP_Msk             (_U_(0x3F) << HSMC_SETUP4_NWE_SETUP_Pos)             /**< (HSMC_SETUP4) NWE Setup Length Mask */
#define HSMC_SETUP4_NWE_SETUP(value)          (HSMC_SETUP4_NWE_SETUP_Msk & ((value) << HSMC_SETUP4_NWE_SETUP_Pos))
#define HSMC_SETUP4_NCS_WR_SETUP_Pos          _U_(8)                                               /**< (HSMC_SETUP4) NCS Setup Length in WRITE Access Position */
#define HSMC_SETUP4_NCS_WR_SETUP_Msk          (_U_(0x3F) << HSMC_SETUP4_NCS_WR_SETUP_Pos)          /**< (HSMC_SETUP4) NCS Setup Length in WRITE Access Mask */
#define HSMC_SETUP4_NCS_WR_SETUP(value)       (HSMC_SETUP4_NCS_WR_SETUP_Msk & ((value) << HSMC_SETUP4_NCS_WR_SETUP_Pos))
#define HSMC_SETUP4_NRD_SETUP_Pos             _U_(16)                                              /**< (HSMC_SETUP4) NRD Setup Length Position */
#define HSMC_SETUP4_NRD_SETUP_Msk             (_U_(0x3F) << HSMC_SETUP4_NRD_SETUP_Pos)             /**< (HSMC_SETUP4) NRD Setup Length Mask */
#define HSMC_SETUP4_NRD_SETUP(value)          (HSMC_SETUP4_NRD_SETUP_Msk & ((value) << HSMC_SETUP4_NRD_SETUP_Pos))
#define HSMC_SETUP4_NCS_RD_SETUP_Pos          _U_(24)                                              /**< (HSMC_SETUP4) NCS Setup Length in READ Access Position */
#define HSMC_SETUP4_NCS_RD_SETUP_Msk          (_U_(0x3F) << HSMC_SETUP4_NCS_RD_SETUP_Pos)          /**< (HSMC_SETUP4) NCS Setup Length in READ Access Mask */
#define HSMC_SETUP4_NCS_RD_SETUP(value)       (HSMC_SETUP4_NCS_RD_SETUP_Msk & ((value) << HSMC_SETUP4_NCS_RD_SETUP_Pos))
#define HSMC_SETUP4_Msk                       _U_(0x3F3F3F3F)                                      /**< (HSMC_SETUP4) Register Mask  */


/* -------- HSMC_PULSE4 : (HSMC Offset: 0x44) (R/W 32) HSMC Pulse Register (CS_number = 4) -------- */
#define HSMC_PULSE4_NWE_PULSE_Pos             _U_(0)                                               /**< (HSMC_PULSE4) NWE Pulse Length Position */
#define HSMC_PULSE4_NWE_PULSE_Msk             (_U_(0x7F) << HSMC_PULSE4_NWE_PULSE_Pos)             /**< (HSMC_PULSE4) NWE Pulse Length Mask */
#define HSMC_PULSE4_NWE_PULSE(value)          (HSMC_PULSE4_NWE_PULSE_Msk & ((value) << HSMC_PULSE4_NWE_PULSE_Pos))
#define HSMC_PULSE4_NCS_WR_PULSE_Pos          _U_(8)                                               /**< (HSMC_PULSE4) NCS Pulse Length in WRITE Access Position */
#define HSMC_PULSE4_NCS_WR_PULSE_Msk          (_U_(0x7F) << HSMC_PULSE4_NCS_WR_PULSE_Pos)          /**< (HSMC_PULSE4) NCS Pulse Length in WRITE Access Mask */
#define HSMC_PULSE4_NCS_WR_PULSE(value)       (HSMC_PULSE4_NCS_WR_PULSE_Msk & ((value) << HSMC_PULSE4_NCS_WR_PULSE_Pos))
#define HSMC_PULSE4_NRD_PULSE_Pos             _U_(16)                                              /**< (HSMC_PULSE4) NRD Pulse Length Position */
#define HSMC_PULSE4_NRD_PULSE_Msk             (_U_(0x7F) << HSMC_PULSE4_NRD_PULSE_Pos)             /**< (HSMC_PULSE4) NRD Pulse Length Mask */
#define HSMC_PULSE4_NRD_PULSE(value)          (HSMC_PULSE4_NRD_PULSE_Msk & ((value) << HSMC_PULSE4_NRD_PULSE_Pos))
#define HSMC_PULSE4_NCS_RD_PULSE_Pos          _U_(24)                                              /**< (HSMC_PULSE4) NCS Pulse Length in READ Access Position */
#define HSMC_PULSE4_NCS_RD_PULSE_Msk          (_U_(0x7F) << HSMC_PULSE4_NCS_RD_PULSE_Pos)          /**< (HSMC_PULSE4) NCS Pulse Length in READ Access Mask */
#define HSMC_PULSE4_NCS_RD_PULSE(value)       (HSMC_PULSE4_NCS_RD_PULSE_Msk & ((value) << HSMC_PULSE4_NCS_RD_PULSE_Pos))
#define HSMC_PULSE4_Msk                       _U_(0x7F7F7F7F)                                      /**< (HSMC_PULSE4) Register Mask  */


/* -------- HSMC_CYCLE4 : (HSMC Offset: 0x48) (R/W 32) HSMC Cycle Register (CS_number = 4) -------- */
#define HSMC_CYCLE4_NWE_CYCLE_Pos             _U_(0)                                               /**< (HSMC_CYCLE4) Total Write Cycle Length Position */
#define HSMC_CYCLE4_NWE_CYCLE_Msk             (_U_(0x1FF) << HSMC_CYCLE4_NWE_CYCLE_Pos)            /**< (HSMC_CYCLE4) Total Write Cycle Length Mask */
#define HSMC_CYCLE4_NWE_CYCLE(value)          (HSMC_CYCLE4_NWE_CYCLE_Msk & ((value) << HSMC_CYCLE4_NWE_CYCLE_Pos))
#define HSMC_CYCLE4_NRD_CYCLE_Pos             _U_(16)                                              /**< (HSMC_CYCLE4) Total Read Cycle Length Position */
#define HSMC_CYCLE4_NRD_CYCLE_Msk             (_U_(0x1FF) << HSMC_CYCLE4_NRD_CYCLE_Pos)            /**< (HSMC_CYCLE4) Total Read Cycle Length Mask */
#define HSMC_CYCLE4_NRD_CYCLE(value)          (HSMC_CYCLE4_NRD_CYCLE_Msk & ((value) << HSMC_CYCLE4_NRD_CYCLE_Pos))
#define HSMC_CYCLE4_Msk                       _U_(0x01FF01FF)                                      /**< (HSMC_CYCLE4) Register Mask  */


/* -------- HSMC_MODE4 : (HSMC Offset: 0x4C) (R/W 32) HSMC Mode Register (CS_number = 4) -------- */
#define HSMC_MODE4_READ_MODE_Pos              _U_(0)                                               /**< (HSMC_MODE4) Read Mode Position */
#define HSMC_MODE4_READ_MODE_Msk              (_U_(0x1) << HSMC_MODE4_READ_MODE_Pos)               /**< (HSMC_MODE4) Read Mode Mask */
#define HSMC_MODE4_READ_MODE(value)           (HSMC_MODE4_READ_MODE_Msk & ((value) << HSMC_MODE4_READ_MODE_Pos))
#define HSMC_MODE4_WRITE_MODE_Pos             _U_(1)                                               /**< (HSMC_MODE4) Write Mode Position */
#define HSMC_MODE4_WRITE_MODE_Msk             (_U_(0x1) << HSMC_MODE4_WRITE_MODE_Pos)              /**< (HSMC_MODE4) Write Mode Mask */
#define HSMC_MODE4_WRITE_MODE(value)          (HSMC_MODE4_WRITE_MODE_Msk & ((value) << HSMC_MODE4_WRITE_MODE_Pos))
#define HSMC_MODE4_RMW_ENABLE_Pos             _U_(2)                                               /**< (HSMC_MODE4) Read-Modify Write enable Position */
#define HSMC_MODE4_RMW_ENABLE_Msk             (_U_(0x1) << HSMC_MODE4_RMW_ENABLE_Pos)              /**< (HSMC_MODE4) Read-Modify Write enable Mask */
#define HSMC_MODE4_RMW_ENABLE(value)          (HSMC_MODE4_RMW_ENABLE_Msk & ((value) << HSMC_MODE4_RMW_ENABLE_Pos))
#define HSMC_MODE4_EXNW_MODE_Pos              _U_(4)                                               /**< (HSMC_MODE4) NWAIT Mode Position */
#define HSMC_MODE4_EXNW_MODE_Msk              (_U_(0x3) << HSMC_MODE4_EXNW_MODE_Pos)               /**< (HSMC_MODE4) NWAIT Mode Mask */
#define HSMC_MODE4_EXNW_MODE(value)           (HSMC_MODE4_EXNW_MODE_Msk & ((value) << HSMC_MODE4_EXNW_MODE_Pos))
#define   HSMC_MODE4_EXNW_MODE_DISABLED_Val   _U_(0x0)                                             /**< (HSMC_MODE4) Disabled-The NWAIT input signal is ignored on the corresponding chip select.  */
#define   HSMC_MODE4_EXNW_MODE_FROZEN_Val     _U_(0x2)                                             /**< (HSMC_MODE4) Frozen Mode-If asserted, the NWAIT signal freezes the current read or write cycle. After deassertion, the read/write cycle is resumed from the point where it was stopped.  */
#define   HSMC_MODE4_EXNW_MODE_READY_Val      _U_(0x3)                                             /**< (HSMC_MODE4) Ready Mode-The NWAIT signal indicates the availability of the external device at the end of the pulse of the controlling read or write signal, to complete the access. If high, the access normally completes. If low, the access is extended until NWAIT returns high.  */
#define HSMC_MODE4_EXNW_MODE_DISABLED         (HSMC_MODE4_EXNW_MODE_DISABLED_Val << HSMC_MODE4_EXNW_MODE_Pos) /**< (HSMC_MODE4) Disabled-The NWAIT input signal is ignored on the corresponding chip select. Position  */
#define HSMC_MODE4_EXNW_MODE_FROZEN           (HSMC_MODE4_EXNW_MODE_FROZEN_Val << HSMC_MODE4_EXNW_MODE_Pos) /**< (HSMC_MODE4) Frozen Mode-If asserted, the NWAIT signal freezes the current read or write cycle. After deassertion, the read/write cycle is resumed from the point where it was stopped. Position  */
#define HSMC_MODE4_EXNW_MODE_READY            (HSMC_MODE4_EXNW_MODE_READY_Val << HSMC_MODE4_EXNW_MODE_Pos) /**< (HSMC_MODE4) Ready Mode-The NWAIT signal indicates the availability of the external device at the end of the pulse of the controlling read or write signal, to complete the access. If high, the access normally completes. If low, the access is extended until NWAIT returns high. Position  */
#define HSMC_MODE4_DBW_Pos                    _U_(8)                                               /**< (HSMC_MODE4) Data Bus Width Position */
#define HSMC_MODE4_DBW_Msk                    (_U_(0x3) << HSMC_MODE4_DBW_Pos)                     /**< (HSMC_MODE4) Data Bus Width Mask */
#define HSMC_MODE4_DBW(value)                 (HSMC_MODE4_DBW_Msk & ((value) << HSMC_MODE4_DBW_Pos))
#define   HSMC_MODE4_DBW_8_BIT_Val            _U_(0x0)                                             /**< (HSMC_MODE4) 8-bit Data Bus  */
#define   HSMC_MODE4_DBW_16_BIT_Val           _U_(0x1)                                             /**< (HSMC_MODE4) 16-bit Data Bus  */
#define   HSMC_MODE4_DBW_32_BIT_Val           _U_(0x2)                                             /**< (HSMC_MODE4) 32-bit Data Bus  */
#define HSMC_MODE4_DBW_8_BIT                  (HSMC_MODE4_DBW_8_BIT_Val << HSMC_MODE4_DBW_Pos)     /**< (HSMC_MODE4) 8-bit Data Bus Position  */
#define HSMC_MODE4_DBW_16_BIT                 (HSMC_MODE4_DBW_16_BIT_Val << HSMC_MODE4_DBW_Pos)    /**< (HSMC_MODE4) 16-bit Data Bus Position  */
#define HSMC_MODE4_DBW_32_BIT                 (HSMC_MODE4_DBW_32_BIT_Val << HSMC_MODE4_DBW_Pos)    /**< (HSMC_MODE4) 32-bit Data Bus Position  */
#define HSMC_MODE4_Msk                        _U_(0x00000337)                                      /**< (HSMC_MODE4) Register Mask  */


/* -------- HSMC_SETUP5 : (HSMC Offset: 0x50) (R/W 32) HSMC Setup Register (CS_number = 5) -------- */
#define HSMC_SETUP5_NWE_SETUP_Pos             _U_(0)                                               /**< (HSMC_SETUP5) NWE Setup Length Position */
#define HSMC_SETUP5_NWE_SETUP_Msk             (_U_(0x3F) << HSMC_SETUP5_NWE_SETUP_Pos)             /**< (HSMC_SETUP5) NWE Setup Length Mask */
#define HSMC_SETUP5_NWE_SETUP(value)          (HSMC_SETUP5_NWE_SETUP_Msk & ((value) << HSMC_SETUP5_NWE_SETUP_Pos))
#define HSMC_SETUP5_NCS_WR_SETUP_Pos          _U_(8)                                               /**< (HSMC_SETUP5) NCS Setup Length in WRITE Access Position */
#define HSMC_SETUP5_NCS_WR_SETUP_Msk          (_U_(0x3F) << HSMC_SETUP5_NCS_WR_SETUP_Pos)          /**< (HSMC_SETUP5) NCS Setup Length in WRITE Access Mask */
#define HSMC_SETUP5_NCS_WR_SETUP(value)       (HSMC_SETUP5_NCS_WR_SETUP_Msk & ((value) << HSMC_SETUP5_NCS_WR_SETUP_Pos))
#define HSMC_SETUP5_NRD_SETUP_Pos             _U_(16)                                              /**< (HSMC_SETUP5) NRD Setup Length Position */
#define HSMC_SETUP5_NRD_SETUP_Msk             (_U_(0x3F) << HSMC_SETUP5_NRD_SETUP_Pos)             /**< (HSMC_SETUP5) NRD Setup Length Mask */
#define HSMC_SETUP5_NRD_SETUP(value)          (HSMC_SETUP5_NRD_SETUP_Msk & ((value) << HSMC_SETUP5_NRD_SETUP_Pos))
#define HSMC_SETUP5_NCS_RD_SETUP_Pos          _U_(24)                                              /**< (HSMC_SETUP5) NCS Setup Length in READ Access Position */
#define HSMC_SETUP5_NCS_RD_SETUP_Msk          (_U_(0x3F) << HSMC_SETUP5_NCS_RD_SETUP_Pos)          /**< (HSMC_SETUP5) NCS Setup Length in READ Access Mask */
#define HSMC_SETUP5_NCS_RD_SETUP(value)       (HSMC_SETUP5_NCS_RD_SETUP_Msk & ((value) << HSMC_SETUP5_NCS_RD_SETUP_Pos))
#define HSMC_SETUP5_Msk                       _U_(0x3F3F3F3F)                                      /**< (HSMC_SETUP5) Register Mask  */


/* -------- HSMC_PULSE5 : (HSMC Offset: 0x54) (R/W 32) HSMC Pulse Register (CS_number = 5) -------- */
#define HSMC_PULSE5_NWE_PULSE_Pos             _U_(0)                                               /**< (HSMC_PULSE5) NWE Pulse Length Position */
#define HSMC_PULSE5_NWE_PULSE_Msk             (_U_(0x7F) << HSMC_PULSE5_NWE_PULSE_Pos)             /**< (HSMC_PULSE5) NWE Pulse Length Mask */
#define HSMC_PULSE5_NWE_PULSE(value)          (HSMC_PULSE5_NWE_PULSE_Msk & ((value) << HSMC_PULSE5_NWE_PULSE_Pos))
#define HSMC_PULSE5_NCS_WR_PULSE_Pos          _U_(8)                                               /**< (HSMC_PULSE5) NCS Pulse Length in WRITE Access Position */
#define HSMC_PULSE5_NCS_WR_PULSE_Msk          (_U_(0x7F) << HSMC_PULSE5_NCS_WR_PULSE_Pos)          /**< (HSMC_PULSE5) NCS Pulse Length in WRITE Access Mask */
#define HSMC_PULSE5_NCS_WR_PULSE(value)       (HSMC_PULSE5_NCS_WR_PULSE_Msk & ((value) << HSMC_PULSE5_NCS_WR_PULSE_Pos))
#define HSMC_PULSE5_NRD_PULSE_Pos             _U_(16)                                              /**< (HSMC_PULSE5) NRD Pulse Length Position */
#define HSMC_PULSE5_NRD_PULSE_Msk             (_U_(0x7F) << HSMC_PULSE5_NRD_PULSE_Pos)             /**< (HSMC_PULSE5) NRD Pulse Length Mask */
#define HSMC_PULSE5_NRD_PULSE(value)          (HSMC_PULSE5_NRD_PULSE_Msk & ((value) << HSMC_PULSE5_NRD_PULSE_Pos))
#define HSMC_PULSE5_NCS_RD_PULSE_Pos          _U_(24)                                              /**< (HSMC_PULSE5) NCS Pulse Length in READ Access Position */
#define HSMC_PULSE5_NCS_RD_PULSE_Msk          (_U_(0x7F) << HSMC_PULSE5_NCS_RD_PULSE_Pos)          /**< (HSMC_PULSE5) NCS Pulse Length in READ Access Mask */
#define HSMC_PULSE5_NCS_RD_PULSE(value)       (HSMC_PULSE5_NCS_RD_PULSE_Msk & ((value) << HSMC_PULSE5_NCS_RD_PULSE_Pos))
#define HSMC_PULSE5_Msk                       _U_(0x7F7F7F7F)                                      /**< (HSMC_PULSE5) Register Mask  */


/* -------- HSMC_CYCLE5 : (HSMC Offset: 0x58) (R/W 32) HSMC Cycle Register (CS_number = 5) -------- */
#define HSMC_CYCLE5_NWE_CYCLE_Pos             _U_(0)                                               /**< (HSMC_CYCLE5) Total Write Cycle Length Position */
#define HSMC_CYCLE5_NWE_CYCLE_Msk             (_U_(0x1FF) << HSMC_CYCLE5_NWE_CYCLE_Pos)            /**< (HSMC_CYCLE5) Total Write Cycle Length Mask */
#define HSMC_CYCLE5_NWE_CYCLE(value)          (HSMC_CYCLE5_NWE_CYCLE_Msk & ((value) << HSMC_CYCLE5_NWE_CYCLE_Pos))
#define HSMC_CYCLE5_NRD_CYCLE_Pos             _U_(16)                                              /**< (HSMC_CYCLE5) Total Read Cycle Length Position */
#define HSMC_CYCLE5_NRD_CYCLE_Msk             (_U_(0x1FF) << HSMC_CYCLE5_NRD_CYCLE_Pos)            /**< (HSMC_CYCLE5) Total Read Cycle Length Mask */
#define HSMC_CYCLE5_NRD_CYCLE(value)          (HSMC_CYCLE5_NRD_CYCLE_Msk & ((value) << HSMC_CYCLE5_NRD_CYCLE_Pos))
#define HSMC_CYCLE5_Msk                       _U_(0x01FF01FF)                                      /**< (HSMC_CYCLE5) Register Mask  */


/* -------- HSMC_MODE5 : (HSMC Offset: 0x5C) (R/W 32) HSMC Mode Register (CS_number = 5) -------- */
#define HSMC_MODE5_READ_MODE_Pos              _U_(0)                                               /**< (HSMC_MODE5) Read Mode Position */
#define HSMC_MODE5_READ_MODE_Msk              (_U_(0x1) << HSMC_MODE5_READ_MODE_Pos)               /**< (HSMC_MODE5) Read Mode Mask */
#define HSMC_MODE5_READ_MODE(value)           (HSMC_MODE5_READ_MODE_Msk & ((value) << HSMC_MODE5_READ_MODE_Pos))
#define HSMC_MODE5_WRITE_MODE_Pos             _U_(1)                                               /**< (HSMC_MODE5) Write Mode Position */
#define HSMC_MODE5_WRITE_MODE_Msk             (_U_(0x1) << HSMC_MODE5_WRITE_MODE_Pos)              /**< (HSMC_MODE5) Write Mode Mask */
#define HSMC_MODE5_WRITE_MODE(value)          (HSMC_MODE5_WRITE_MODE_Msk & ((value) << HSMC_MODE5_WRITE_MODE_Pos))
#define HSMC_MODE5_RMW_ENABLE_Pos             _U_(2)                                               /**< (HSMC_MODE5) Read-Modify Write enable Position */
#define HSMC_MODE5_RMW_ENABLE_Msk             (_U_(0x1) << HSMC_MODE5_RMW_ENABLE_Pos)              /**< (HSMC_MODE5) Read-Modify Write enable Mask */
#define HSMC_MODE5_RMW_ENABLE(value)          (HSMC_MODE5_RMW_ENABLE_Msk & ((value) << HSMC_MODE5_RMW_ENABLE_Pos))
#define HSMC_MODE5_EXNW_MODE_Pos              _U_(4)                                               /**< (HSMC_MODE5) NWAIT Mode Position */
#define HSMC_MODE5_EXNW_MODE_Msk              (_U_(0x3) << HSMC_MODE5_EXNW_MODE_Pos)               /**< (HSMC_MODE5) NWAIT Mode Mask */
#define HSMC_MODE5_EXNW_MODE(value)           (HSMC_MODE5_EXNW_MODE_Msk & ((value) << HSMC_MODE5_EXNW_MODE_Pos))
#define   HSMC_MODE5_EXNW_MODE_DISABLED_Val   _U_(0x0)                                             /**< (HSMC_MODE5) Disabled-The NWAIT input signal is ignored on the corresponding chip select.  */
#define   HSMC_MODE5_EXNW_MODE_FROZEN_Val     _U_(0x2)                                             /**< (HSMC_MODE5) Frozen Mode-If asserted, the NWAIT signal freezes the current read or write cycle. After deassertion, the read/write cycle is resumed from the point where it was stopped.  */
#define   HSMC_MODE5_EXNW_MODE_READY_Val      _U_(0x3)                                             /**< (HSMC_MODE5) Ready Mode-The NWAIT signal indicates the availability of the external device at the end of the pulse of the controlling read or write signal, to complete the access. If high, the access normally completes. If low, the access is extended until NWAIT returns high.  */
#define HSMC_MODE5_EXNW_MODE_DISABLED         (HSMC_MODE5_EXNW_MODE_DISABLED_Val << HSMC_MODE5_EXNW_MODE_Pos) /**< (HSMC_MODE5) Disabled-The NWAIT input signal is ignored on the corresponding chip select. Position  */
#define HSMC_MODE5_EXNW_MODE_FROZEN           (HSMC_MODE5_EXNW_MODE_FROZEN_Val << HSMC_MODE5_EXNW_MODE_Pos) /**< (HSMC_MODE5) Frozen Mode-If asserted, the NWAIT signal freezes the current read or write cycle. After deassertion, the read/write cycle is resumed from the point where it was stopped. Position  */
#define HSMC_MODE5_EXNW_MODE_READY            (HSMC_MODE5_EXNW_MODE_READY_Val << HSMC_MODE5_EXNW_MODE_Pos) /**< (HSMC_MODE5) Ready Mode-The NWAIT signal indicates the availability of the external device at the end of the pulse of the controlling read or write signal, to complete the access. If high, the access normally completes. If low, the access is extended until NWAIT returns high. Position  */
#define HSMC_MODE5_DBW_Pos                    _U_(8)                                               /**< (HSMC_MODE5) Data Bus Width Position */
#define HSMC_MODE5_DBW_Msk                    (_U_(0x3) << HSMC_MODE5_DBW_Pos)                     /**< (HSMC_MODE5) Data Bus Width Mask */
#define HSMC_MODE5_DBW(value)                 (HSMC_MODE5_DBW_Msk & ((value) << HSMC_MODE5_DBW_Pos))
#define   HSMC_MODE5_DBW_8_BIT_Val            _U_(0x0)                                             /**< (HSMC_MODE5) 8-bit Data Bus  */
#define   HSMC_MODE5_DBW_16_BIT_Val           _U_(0x1)                                             /**< (HSMC_MODE5) 16-bit Data Bus  */
#define   HSMC_MODE5_DBW_32_BIT_Val           _U_(0x2)                                             /**< (HSMC_MODE5) 32-bit Data Bus  */
#define HSMC_MODE5_DBW_8_BIT                  (HSMC_MODE5_DBW_8_BIT_Val << HSMC_MODE5_DBW_Pos)     /**< (HSMC_MODE5) 8-bit Data Bus Position  */
#define HSMC_MODE5_DBW_16_BIT                 (HSMC_MODE5_DBW_16_BIT_Val << HSMC_MODE5_DBW_Pos)    /**< (HSMC_MODE5) 16-bit Data Bus Position  */
#define HSMC_MODE5_DBW_32_BIT                 (HSMC_MODE5_DBW_32_BIT_Val << HSMC_MODE5_DBW_Pos)    /**< (HSMC_MODE5) 32-bit Data Bus Position  */
#define HSMC_MODE5_Msk                        _U_(0x00000337)                                      /**< (HSMC_MODE5) Register Mask  */


/* -------- HSMC_WPMR : (HSMC Offset: 0x70) (R/W 32) HSMC Write Protection Mode Register -------- */
#define HSMC_WPMR_WPEN_Pos                    _U_(0)                                               /**< (HSMC_WPMR) Write Protect Enable Position */
#define HSMC_WPMR_WPEN_Msk                    (_U_(0x1) << HSMC_WPMR_WPEN_Pos)                     /**< (HSMC_WPMR) Write Protect Enable Mask */
#define HSMC_WPMR_WPEN(value)                 (HSMC_WPMR_WPEN_Msk & ((value) << HSMC_WPMR_WPEN_Pos))
#define HSMC_WPMR_WPKEY_Pos                   _U_(8)                                               /**< (HSMC_WPMR) Write Protection Key Position */
#define HSMC_WPMR_WPKEY_Msk                   (_U_(0xFFFFFF) << HSMC_WPMR_WPKEY_Pos)               /**< (HSMC_WPMR) Write Protection Key Mask */
#define HSMC_WPMR_WPKEY(value)                (HSMC_WPMR_WPKEY_Msk & ((value) << HSMC_WPMR_WPKEY_Pos))
#define   HSMC_WPMR_WPKEY_PASSWD_Val          _U_(0x534D43)                                        /**< (HSMC_WPMR) Writing any other value in this field aborts the write operation of the WPEN bit. Always reads as 0.  */
#define HSMC_WPMR_WPKEY_PASSWD                (HSMC_WPMR_WPKEY_PASSWD_Val << HSMC_WPMR_WPKEY_Pos)  /**< (HSMC_WPMR) Writing any other value in this field aborts the write operation of the WPEN bit. Always reads as 0. Position  */
#define HSMC_WPMR_Msk                         _U_(0xFFFFFF01)                                      /**< (HSMC_WPMR) Register Mask  */


/* -------- HSMC_WPSR : (HSMC Offset: 0x74) ( R/ 32) HSMC Write Protection Status Register -------- */
#define HSMC_WPSR_WPVS_Pos                    _U_(0)                                               /**< (HSMC_WPSR) Write Protection Violation Status Position */
#define HSMC_WPSR_WPVS_Msk                    (_U_(0x1) << HSMC_WPSR_WPVS_Pos)                     /**< (HSMC_WPSR) Write Protection Violation Status Mask */
#define HSMC_WPSR_WPVS(value)                 (HSMC_WPSR_WPVS_Msk & ((value) << HSMC_WPSR_WPVS_Pos))
#define HSMC_WPSR_WPVSRC_Pos                  _U_(8)                                               /**< (HSMC_WPSR) Write Protection Violation Source Position */
#define HSMC_WPSR_WPVSRC_Msk                  (_U_(0xFFFF) << HSMC_WPSR_WPVSRC_Pos)                /**< (HSMC_WPSR) Write Protection Violation Source Mask */
#define HSMC_WPSR_WPVSRC(value)               (HSMC_WPSR_WPVSRC_Msk & ((value) << HSMC_WPSR_WPVSRC_Pos))
#define HSMC_WPSR_Msk                         _U_(0x00FFFF01)                                      /**< (HSMC_WPSR) Register Mask  */


/** \brief HSMC register offsets definitions */
#define HSMC_SETUP0_REG_OFST           (0x00)              /**< (HSMC_SETUP0) HSMC Setup Register (CS_number = 0) Offset */
#define HSMC_PULSE0_REG_OFST           (0x04)              /**< (HSMC_PULSE0) HSMC Pulse Register (CS_number = 0) Offset */
#define HSMC_CYCLE0_REG_OFST           (0x08)              /**< (HSMC_CYCLE0) HSMC Cycle Register (CS_number = 0) Offset */
#define HSMC_MODE0_REG_OFST            (0x0C)              /**< (HSMC_MODE0) HSMC Mode Register (CS_number = 0) Offset */
#define HSMC_SETUP1_REG_OFST           (0x10)              /**< (HSMC_SETUP1) HSMC Setup Register (CS_number = 1) Offset */
#define HSMC_PULSE1_REG_OFST           (0x14)              /**< (HSMC_PULSE1) HSMC Pulse Register (CS_number = 1) Offset */
#define HSMC_CYCLE1_REG_OFST           (0x18)              /**< (HSMC_CYCLE1) HSMC Cycle Register (CS_number = 1) Offset */
#define HSMC_MODE1_REG_OFST            (0x1C)              /**< (HSMC_MODE1) HSMC Mode Register (CS_number = 1) Offset */
#define HSMC_SETUP2_REG_OFST           (0x20)              /**< (HSMC_SETUP2) HSMC Setup Register (CS_number = 2) Offset */
#define HSMC_PULSE2_REG_OFST           (0x24)              /**< (HSMC_PULSE2) HSMC Pulse Register (CS_number = 2) Offset */
#define HSMC_CYCLE2_REG_OFST           (0x28)              /**< (HSMC_CYCLE2) HSMC Cycle Register (CS_number = 2) Offset */
#define HSMC_MODE2_REG_OFST            (0x2C)              /**< (HSMC_MODE2) HSMC Mode Register (CS_number = 2) Offset */
#define HSMC_SETUP3_REG_OFST           (0x30)              /**< (HSMC_SETUP3) HSMC Setup Register (CS_number = 3) Offset */
#define HSMC_PULSE3_REG_OFST           (0x34)              /**< (HSMC_PULSE3) HSMC Pulse Register (CS_number = 3) Offset */
#define HSMC_CYCLE3_REG_OFST           (0x38)              /**< (HSMC_CYCLE3) HSMC Cycle Register (CS_number = 3) Offset */
#define HSMC_MODE3_REG_OFST            (0x3C)              /**< (HSMC_MODE3) HSMC Mode Register (CS_number = 3) Offset */
#define HSMC_SETUP4_REG_OFST           (0x40)              /**< (HSMC_SETUP4) HSMC Setup Register (CS_number = 4) Offset */
#define HSMC_PULSE4_REG_OFST           (0x44)              /**< (HSMC_PULSE4) HSMC Pulse Register (CS_number = 4) Offset */
#define HSMC_CYCLE4_REG_OFST           (0x48)              /**< (HSMC_CYCLE4) HSMC Cycle Register (CS_number = 4) Offset */
#define HSMC_MODE4_REG_OFST            (0x4C)              /**< (HSMC_MODE4) HSMC Mode Register (CS_number = 4) Offset */
#define HSMC_SETUP5_REG_OFST           (0x50)              /**< (HSMC_SETUP5) HSMC Setup Register (CS_number = 5) Offset */
#define HSMC_PULSE5_REG_OFST           (0x54)              /**< (HSMC_PULSE5) HSMC Pulse Register (CS_number = 5) Offset */
#define HSMC_CYCLE5_REG_OFST           (0x58)              /**< (HSMC_CYCLE5) HSMC Cycle Register (CS_number = 5) Offset */
#define HSMC_MODE5_REG_OFST            (0x5C)              /**< (HSMC_MODE5) HSMC Mode Register (CS_number = 5) Offset */
#define HSMC_WPMR_REG_OFST             (0x70)              /**< (HSMC_WPMR) HSMC Write Protection Mode Register Offset */
#define HSMC_WPSR_REG_OFST             (0x74)              /**< (HSMC_WPSR) HSMC Write Protection Status Register Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief HSMC register API structure */
typedef struct
{
  __IO  uint32_t                       HSMC_SETUP0;        /**< Offset: 0x00 (R/W  32) HSMC Setup Register (CS_number = 0) */
  __IO  uint32_t                       HSMC_PULSE0;        /**< Offset: 0x04 (R/W  32) HSMC Pulse Register (CS_number = 0) */
  __IO  uint32_t                       HSMC_CYCLE0;        /**< Offset: 0x08 (R/W  32) HSMC Cycle Register (CS_number = 0) */
  __IO  uint32_t                       HSMC_MODE0;         /**< Offset: 0x0C (R/W  32) HSMC Mode Register (CS_number = 0) */
  __IO  uint32_t                       HSMC_SETUP1;        /**< Offset: 0x10 (R/W  32) HSMC Setup Register (CS_number = 1) */
  __IO  uint32_t                       HSMC_PULSE1;        /**< Offset: 0x14 (R/W  32) HSMC Pulse Register (CS_number = 1) */
  __IO  uint32_t                       HSMC_CYCLE1;        /**< Offset: 0x18 (R/W  32) HSMC Cycle Register (CS_number = 1) */
  __IO  uint32_t                       HSMC_MODE1;         /**< Offset: 0x1C (R/W  32) HSMC Mode Register (CS_number = 1) */
  __IO  uint32_t                       HSMC_SETUP2;        /**< Offset: 0x20 (R/W  32) HSMC Setup Register (CS_number = 2) */
  __IO  uint32_t                       HSMC_PULSE2;        /**< Offset: 0x24 (R/W  32) HSMC Pulse Register (CS_number = 2) */
  __IO  uint32_t                       HSMC_CYCLE2;        /**< Offset: 0x28 (R/W  32) HSMC Cycle Register (CS_number = 2) */
  __IO  uint32_t                       HSMC_MODE2;         /**< Offset: 0x2C (R/W  32) HSMC Mode Register (CS_number = 2) */
  __IO  uint32_t                       HSMC_SETUP3;        /**< Offset: 0x30 (R/W  32) HSMC Setup Register (CS_number = 3) */
  __IO  uint32_t                       HSMC_PULSE3;        /**< Offset: 0x34 (R/W  32) HSMC Pulse Register (CS_number = 3) */
  __IO  uint32_t                       HSMC_CYCLE3;        /**< Offset: 0x38 (R/W  32) HSMC Cycle Register (CS_number = 3) */
  __IO  uint32_t                       HSMC_MODE3;         /**< Offset: 0x3C (R/W  32) HSMC Mode Register (CS_number = 3) */
  __IO  uint32_t                       HSMC_SETUP4;        /**< Offset: 0x40 (R/W  32) HSMC Setup Register (CS_number = 4) */
  __IO  uint32_t                       HSMC_PULSE4;        /**< Offset: 0x44 (R/W  32) HSMC Pulse Register (CS_number = 4) */
  __IO  uint32_t                       HSMC_CYCLE4;        /**< Offset: 0x48 (R/W  32) HSMC Cycle Register (CS_number = 4) */
  __IO  uint32_t                       HSMC_MODE4;         /**< Offset: 0x4C (R/W  32) HSMC Mode Register (CS_number = 4) */
  __IO  uint32_t                       HSMC_SETUP5;        /**< Offset: 0x50 (R/W  32) HSMC Setup Register (CS_number = 5) */
  __IO  uint32_t                       HSMC_PULSE5;        /**< Offset: 0x54 (R/W  32) HSMC Pulse Register (CS_number = 5) */
  __IO  uint32_t                       HSMC_CYCLE5;        /**< Offset: 0x58 (R/W  32) HSMC Cycle Register (CS_number = 5) */
  __IO  uint32_t                       HSMC_MODE5;         /**< Offset: 0x5C (R/W  32) HSMC Mode Register (CS_number = 5) */
  __I   uint8_t                        Reserved1[0x10];
  __IO  uint32_t                       HSMC_WPMR;          /**< Offset: 0x70 (R/W  32) HSMC Write Protection Mode Register */
  __I   uint32_t                       HSMC_WPSR;          /**< Offset: 0x74 (R/   32) HSMC Write Protection Status Register */
} hsmc_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _SAMRH71_HSMC_COMPONENT_H_ */
