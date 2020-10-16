/**
 * \brief Component description for PMC
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
#ifndef _SAMRH71_PMC_COMPONENT_H_
#define _SAMRH71_PMC_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR PMC                                          */
/* ************************************************************************** */

/* -------- PMC_SCER : (PMC Offset: 0x00) ( /W 32) System Clock Enable Register -------- */
#define PMC_SCER_PCK0_Pos                     _U_(8)                                               /**< (PMC_SCER) Programmable Clock 0 Output Enable Position */
#define PMC_SCER_PCK0_Msk                     (_U_(0x1) << PMC_SCER_PCK0_Pos)                      /**< (PMC_SCER) Programmable Clock 0 Output Enable Mask */
#define PMC_SCER_PCK0(value)                  (PMC_SCER_PCK0_Msk & ((value) << PMC_SCER_PCK0_Pos))
#define PMC_SCER_PCK1_Pos                     _U_(9)                                               /**< (PMC_SCER) Programmable Clock 1 Output Enable Position */
#define PMC_SCER_PCK1_Msk                     (_U_(0x1) << PMC_SCER_PCK1_Pos)                      /**< (PMC_SCER) Programmable Clock 1 Output Enable Mask */
#define PMC_SCER_PCK1(value)                  (PMC_SCER_PCK1_Msk & ((value) << PMC_SCER_PCK1_Pos))
#define PMC_SCER_PCK2_Pos                     _U_(10)                                              /**< (PMC_SCER) Programmable Clock 2 Output Enable Position */
#define PMC_SCER_PCK2_Msk                     (_U_(0x1) << PMC_SCER_PCK2_Pos)                      /**< (PMC_SCER) Programmable Clock 2 Output Enable Mask */
#define PMC_SCER_PCK2(value)                  (PMC_SCER_PCK2_Msk & ((value) << PMC_SCER_PCK2_Pos))
#define PMC_SCER_PCK3_Pos                     _U_(11)                                              /**< (PMC_SCER) Programmable Clock 3 Output Enable Position */
#define PMC_SCER_PCK3_Msk                     (_U_(0x1) << PMC_SCER_PCK3_Pos)                      /**< (PMC_SCER) Programmable Clock 3 Output Enable Mask */
#define PMC_SCER_PCK3(value)                  (PMC_SCER_PCK3_Msk & ((value) << PMC_SCER_PCK3_Pos))
#define PMC_SCER_Msk                          _U_(0x00000F00)                                      /**< (PMC_SCER) Register Mask  */

#define PMC_SCER_PCK_Pos                      _U_(8)                                               /**< (PMC_SCER Position) Programmable Clock 3 Output Enable */
#define PMC_SCER_PCK_Msk                      (_U_(0xF) << PMC_SCER_PCK_Pos)                       /**< (PMC_SCER Mask) PCK */
#define PMC_SCER_PCK(value)                   (PMC_SCER_PCK_Msk & ((value) << PMC_SCER_PCK_Pos))   

/* -------- PMC_SCDR : (PMC Offset: 0x04) ( /W 32) System Clock Disable Register -------- */
#define PMC_SCDR_PCK0_Pos                     _U_(8)                                               /**< (PMC_SCDR) Programmable Clock 0 Output Disable Position */
#define PMC_SCDR_PCK0_Msk                     (_U_(0x1) << PMC_SCDR_PCK0_Pos)                      /**< (PMC_SCDR) Programmable Clock 0 Output Disable Mask */
#define PMC_SCDR_PCK0(value)                  (PMC_SCDR_PCK0_Msk & ((value) << PMC_SCDR_PCK0_Pos))
#define PMC_SCDR_PCK1_Pos                     _U_(9)                                               /**< (PMC_SCDR) Programmable Clock 1 Output Disable Position */
#define PMC_SCDR_PCK1_Msk                     (_U_(0x1) << PMC_SCDR_PCK1_Pos)                      /**< (PMC_SCDR) Programmable Clock 1 Output Disable Mask */
#define PMC_SCDR_PCK1(value)                  (PMC_SCDR_PCK1_Msk & ((value) << PMC_SCDR_PCK1_Pos))
#define PMC_SCDR_PCK2_Pos                     _U_(10)                                              /**< (PMC_SCDR) Programmable Clock 2 Output Disable Position */
#define PMC_SCDR_PCK2_Msk                     (_U_(0x1) << PMC_SCDR_PCK2_Pos)                      /**< (PMC_SCDR) Programmable Clock 2 Output Disable Mask */
#define PMC_SCDR_PCK2(value)                  (PMC_SCDR_PCK2_Msk & ((value) << PMC_SCDR_PCK2_Pos))
#define PMC_SCDR_PCK3_Pos                     _U_(11)                                              /**< (PMC_SCDR) Programmable Clock 3 Output Disable Position */
#define PMC_SCDR_PCK3_Msk                     (_U_(0x1) << PMC_SCDR_PCK3_Pos)                      /**< (PMC_SCDR) Programmable Clock 3 Output Disable Mask */
#define PMC_SCDR_PCK3(value)                  (PMC_SCDR_PCK3_Msk & ((value) << PMC_SCDR_PCK3_Pos))
#define PMC_SCDR_Msk                          _U_(0x00000F00)                                      /**< (PMC_SCDR) Register Mask  */

#define PMC_SCDR_PCK_Pos                      _U_(8)                                               /**< (PMC_SCDR Position) Programmable Clock 3 Output Disable */
#define PMC_SCDR_PCK_Msk                      (_U_(0xF) << PMC_SCDR_PCK_Pos)                       /**< (PMC_SCDR Mask) PCK */
#define PMC_SCDR_PCK(value)                   (PMC_SCDR_PCK_Msk & ((value) << PMC_SCDR_PCK_Pos))   

/* -------- PMC_SCSR : (PMC Offset: 0x08) ( R/ 32) System Clock Status Register -------- */
#define PMC_SCSR_PCK0_Pos                     _U_(8)                                               /**< (PMC_SCSR) Programmable Clock 0 Output Status Position */
#define PMC_SCSR_PCK0_Msk                     (_U_(0x1) << PMC_SCSR_PCK0_Pos)                      /**< (PMC_SCSR) Programmable Clock 0 Output Status Mask */
#define PMC_SCSR_PCK0(value)                  (PMC_SCSR_PCK0_Msk & ((value) << PMC_SCSR_PCK0_Pos))
#define PMC_SCSR_PCK1_Pos                     _U_(9)                                               /**< (PMC_SCSR) Programmable Clock 1 Output Status Position */
#define PMC_SCSR_PCK1_Msk                     (_U_(0x1) << PMC_SCSR_PCK1_Pos)                      /**< (PMC_SCSR) Programmable Clock 1 Output Status Mask */
#define PMC_SCSR_PCK1(value)                  (PMC_SCSR_PCK1_Msk & ((value) << PMC_SCSR_PCK1_Pos))
#define PMC_SCSR_PCK2_Pos                     _U_(10)                                              /**< (PMC_SCSR) Programmable Clock 2 Output Status Position */
#define PMC_SCSR_PCK2_Msk                     (_U_(0x1) << PMC_SCSR_PCK2_Pos)                      /**< (PMC_SCSR) Programmable Clock 2 Output Status Mask */
#define PMC_SCSR_PCK2(value)                  (PMC_SCSR_PCK2_Msk & ((value) << PMC_SCSR_PCK2_Pos))
#define PMC_SCSR_PCK3_Pos                     _U_(11)                                              /**< (PMC_SCSR) Programmable Clock 3 Output Status Position */
#define PMC_SCSR_PCK3_Msk                     (_U_(0x1) << PMC_SCSR_PCK3_Pos)                      /**< (PMC_SCSR) Programmable Clock 3 Output Status Mask */
#define PMC_SCSR_PCK3(value)                  (PMC_SCSR_PCK3_Msk & ((value) << PMC_SCSR_PCK3_Pos))
#define PMC_SCSR_Msk                          _U_(0x00000F00)                                      /**< (PMC_SCSR) Register Mask  */

#define PMC_SCSR_PCK_Pos                      _U_(8)                                               /**< (PMC_SCSR Position) Programmable Clock 3 Output Status */
#define PMC_SCSR_PCK_Msk                      (_U_(0xF) << PMC_SCSR_PCK_Pos)                       /**< (PMC_SCSR Mask) PCK */
#define PMC_SCSR_PCK(value)                   (PMC_SCSR_PCK_Msk & ((value) << PMC_SCSR_PCK_Pos))   

/* -------- CKGR_MOR : (PMC Offset: 0x20) (R/W 32) Main Oscillator Register -------- */
#define CKGR_MOR_MOSCXTEN_Pos                 _U_(0)                                               /**< (CKGR_MOR) Main Crystal Oscillator Enable Position */
#define CKGR_MOR_MOSCXTEN_Msk                 (_U_(0x1) << CKGR_MOR_MOSCXTEN_Pos)                  /**< (CKGR_MOR) Main Crystal Oscillator Enable Mask */
#define CKGR_MOR_MOSCXTEN(value)              (CKGR_MOR_MOSCXTEN_Msk & ((value) << CKGR_MOR_MOSCXTEN_Pos))
#define CKGR_MOR_MOSCXTBY_Pos                 _U_(1)                                               /**< (CKGR_MOR) Main Crystal Oscillator Bypass Position */
#define CKGR_MOR_MOSCXTBY_Msk                 (_U_(0x1) << CKGR_MOR_MOSCXTBY_Pos)                  /**< (CKGR_MOR) Main Crystal Oscillator Bypass Mask */
#define CKGR_MOR_MOSCXTBY(value)              (CKGR_MOR_MOSCXTBY_Msk & ((value) << CKGR_MOR_MOSCXTBY_Pos))
#define CKGR_MOR_MOSCRCEN_Pos                 _U_(3)                                               /**< (CKGR_MOR) Main RC Oscillator Enable Position */
#define CKGR_MOR_MOSCRCEN_Msk                 (_U_(0x1) << CKGR_MOR_MOSCRCEN_Pos)                  /**< (CKGR_MOR) Main RC Oscillator Enable Mask */
#define CKGR_MOR_MOSCRCEN(value)              (CKGR_MOR_MOSCRCEN_Msk & ((value) << CKGR_MOR_MOSCRCEN_Pos))
#define CKGR_MOR_MOSCRCF_Pos                  _U_(4)                                               /**< (CKGR_MOR) Main RC Oscillator Frequency Selection Position */
#define CKGR_MOR_MOSCRCF_Msk                  (_U_(0x7) << CKGR_MOR_MOSCRCF_Pos)                   /**< (CKGR_MOR) Main RC Oscillator Frequency Selection Mask */
#define CKGR_MOR_MOSCRCF(value)               (CKGR_MOR_MOSCRCF_Msk & ((value) << CKGR_MOR_MOSCRCF_Pos))
#define   CKGR_MOR_MOSCRCF_4_MHZ_Val          _U_(0x0)                                             /**< (CKGR_MOR) The RC oscillator frequency is at 4 MHz  */
#define   CKGR_MOR_MOSCRCF_8_MHZ_Val          _U_(0x1)                                             /**< (CKGR_MOR) The RC oscillator frequency is at 8 MHz  */
#define   CKGR_MOR_MOSCRCF_10_MHZ_Val         _U_(0x2)                                             /**< (CKGR_MOR) The RC oscillator frequency is at 10 MHz  */
#define   CKGR_MOR_MOSCRCF_12_MHZ_Val         _U_(0x3)                                             /**< (CKGR_MOR) The RC oscillator frequency is at 12 MHz  */
#define CKGR_MOR_MOSCRCF_4_MHZ                (CKGR_MOR_MOSCRCF_4_MHZ_Val << CKGR_MOR_MOSCRCF_Pos) /**< (CKGR_MOR) The RC oscillator frequency is at 4 MHz Position  */
#define CKGR_MOR_MOSCRCF_8_MHZ                (CKGR_MOR_MOSCRCF_8_MHZ_Val << CKGR_MOR_MOSCRCF_Pos) /**< (CKGR_MOR) The RC oscillator frequency is at 8 MHz Position  */
#define CKGR_MOR_MOSCRCF_10_MHZ               (CKGR_MOR_MOSCRCF_10_MHZ_Val << CKGR_MOR_MOSCRCF_Pos) /**< (CKGR_MOR) The RC oscillator frequency is at 10 MHz Position  */
#define CKGR_MOR_MOSCRCF_12_MHZ               (CKGR_MOR_MOSCRCF_12_MHZ_Val << CKGR_MOR_MOSCRCF_Pos) /**< (CKGR_MOR) The RC oscillator frequency is at 12 MHz Position  */
#define CKGR_MOR_MOSCXTST_Pos                 _U_(8)                                               /**< (CKGR_MOR) Main Crystal Oscillator Startup Time Position */
#define CKGR_MOR_MOSCXTST_Msk                 (_U_(0xFF) << CKGR_MOR_MOSCXTST_Pos)                 /**< (CKGR_MOR) Main Crystal Oscillator Startup Time Mask */
#define CKGR_MOR_MOSCXTST(value)              (CKGR_MOR_MOSCXTST_Msk & ((value) << CKGR_MOR_MOSCXTST_Pos))
#define CKGR_MOR_KEY_Pos                      _U_(16)                                              /**< (CKGR_MOR) Write Access Password Position */
#define CKGR_MOR_KEY_Msk                      (_U_(0xFF) << CKGR_MOR_KEY_Pos)                      /**< (CKGR_MOR) Write Access Password Mask */
#define CKGR_MOR_KEY(value)                   (CKGR_MOR_KEY_Msk & ((value) << CKGR_MOR_KEY_Pos))  
#define   CKGR_MOR_KEY_PASSWD_Val             _U_(0x37)                                            /**< (CKGR_MOR) Writing any other value in this field aborts the write operation.Always reads as 0.  */
#define CKGR_MOR_KEY_PASSWD                   (CKGR_MOR_KEY_PASSWD_Val << CKGR_MOR_KEY_Pos)        /**< (CKGR_MOR) Writing any other value in this field aborts the write operation.Always reads as 0. Position  */
#define CKGR_MOR_MOSCSEL_Pos                  _U_(24)                                              /**< (CKGR_MOR) Main Clock Oscillator Selection Position */
#define CKGR_MOR_MOSCSEL_Msk                  (_U_(0x1) << CKGR_MOR_MOSCSEL_Pos)                   /**< (CKGR_MOR) Main Clock Oscillator Selection Mask */
#define CKGR_MOR_MOSCSEL(value)               (CKGR_MOR_MOSCSEL_Msk & ((value) << CKGR_MOR_MOSCSEL_Pos))
#define CKGR_MOR_CFDEN_Pos                    _U_(25)                                              /**< (CKGR_MOR) Clock Failure Detector Enable Position */
#define CKGR_MOR_CFDEN_Msk                    (_U_(0x1) << CKGR_MOR_CFDEN_Pos)                     /**< (CKGR_MOR) Clock Failure Detector Enable Mask */
#define CKGR_MOR_CFDEN(value)                 (CKGR_MOR_CFDEN_Msk & ((value) << CKGR_MOR_CFDEN_Pos))
#define CKGR_MOR_EXT32KFME_Pos                _U_(26)                                              /**< (CKGR_MOR) 32.768 kHz Crystal Oscillator Frequency Monitoring Enable Position */
#define CKGR_MOR_EXT32KFME_Msk                (_U_(0x1) << CKGR_MOR_EXT32KFME_Pos)                 /**< (CKGR_MOR) 32.768 kHz Crystal Oscillator Frequency Monitoring Enable Mask */
#define CKGR_MOR_EXT32KFME(value)             (CKGR_MOR_EXT32KFME_Msk & ((value) << CKGR_MOR_EXT32KFME_Pos))
#define CKGR_MOR_BCPURST_Pos                  _U_(27)                                              /**< (CKGR_MOR) Bad CPU Clock Reset Enable Position */
#define CKGR_MOR_BCPURST_Msk                  (_U_(0x1) << CKGR_MOR_BCPURST_Pos)                   /**< (CKGR_MOR) Bad CPU Clock Reset Enable Mask */
#define CKGR_MOR_BCPURST(value)               (CKGR_MOR_BCPURST_Msk & ((value) << CKGR_MOR_BCPURST_Pos))
#define CKGR_MOR_BCPUNMIC_Pos                 _U_(28)                                              /**< (CKGR_MOR) Bad CPU Clock Interrupt to NMIC Enable Position */
#define CKGR_MOR_BCPUNMIC_Msk                 (_U_(0x1) << CKGR_MOR_BCPUNMIC_Pos)                  /**< (CKGR_MOR) Bad CPU Clock Interrupt to NMIC Enable Mask */
#define CKGR_MOR_BCPUNMIC(value)              (CKGR_MOR_BCPUNMIC_Msk & ((value) << CKGR_MOR_BCPUNMIC_Pos))
#define CKGR_MOR_Msk                          _U_(0x1FFFFF7B)                                      /**< (CKGR_MOR) Register Mask  */


/* -------- CKGR_MCFR : (PMC Offset: 0x24) (R/W 32) Main Clock Frequency Register -------- */
#define CKGR_MCFR_MAINF_Pos                   _U_(0)                                               /**< (CKGR_MCFR) Main Clock Frequency Position */
#define CKGR_MCFR_MAINF_Msk                   (_U_(0xFFFF) << CKGR_MCFR_MAINF_Pos)                 /**< (CKGR_MCFR) Main Clock Frequency Mask */
#define CKGR_MCFR_MAINF(value)                (CKGR_MCFR_MAINF_Msk & ((value) << CKGR_MCFR_MAINF_Pos))
#define CKGR_MCFR_MAINFRDY_Pos                _U_(16)                                              /**< (CKGR_MCFR) Main Clock Frequency Measure Ready Position */
#define CKGR_MCFR_MAINFRDY_Msk                (_U_(0x1) << CKGR_MCFR_MAINFRDY_Pos)                 /**< (CKGR_MCFR) Main Clock Frequency Measure Ready Mask */
#define CKGR_MCFR_MAINFRDY(value)             (CKGR_MCFR_MAINFRDY_Msk & ((value) << CKGR_MCFR_MAINFRDY_Pos))
#define CKGR_MCFR_RCMEAS_Pos                  _U_(20)                                              /**< (CKGR_MCFR) RC Oscillator Frequency Measure (write-only) Position */
#define CKGR_MCFR_RCMEAS_Msk                  (_U_(0x1) << CKGR_MCFR_RCMEAS_Pos)                   /**< (CKGR_MCFR) RC Oscillator Frequency Measure (write-only) Mask */
#define CKGR_MCFR_RCMEAS(value)               (CKGR_MCFR_RCMEAS_Msk & ((value) << CKGR_MCFR_RCMEAS_Pos))
#define CKGR_MCFR_CCSS_Pos                    _U_(24)                                              /**< (CKGR_MCFR) Counter Clock Source Selection Position */
#define CKGR_MCFR_CCSS_Msk                    (_U_(0x1) << CKGR_MCFR_CCSS_Pos)                     /**< (CKGR_MCFR) Counter Clock Source Selection Mask */
#define CKGR_MCFR_CCSS(value)                 (CKGR_MCFR_CCSS_Msk & ((value) << CKGR_MCFR_CCSS_Pos))
#define CKGR_MCFR_Msk                         _U_(0x0111FFFF)                                      /**< (CKGR_MCFR) Register Mask  */


/* -------- CKGR_PLLAR : (PMC Offset: 0x28) (R/W 32) PLLA Register -------- */
#define CKGR_PLLAR_DIVA_Pos                   _U_(0)                                               /**< (CKGR_PLLAR) PLLA Front End Divider Position */
#define CKGR_PLLAR_DIVA_Msk                   (_U_(0xFF) << CKGR_PLLAR_DIVA_Pos)                   /**< (CKGR_PLLAR) PLLA Front End Divider Mask */
#define CKGR_PLLAR_DIVA(value)                (CKGR_PLLAR_DIVA_Msk & ((value) << CKGR_PLLAR_DIVA_Pos))
#define   CKGR_PLLAR_DIVA_0_Val               _U_(0x0)                                             /**< (CKGR_PLLAR) PLLA is disabled.  */
#define   CKGR_PLLAR_DIVA_BYPASS_Val          _U_(0x1)                                             /**< (CKGR_PLLAR) Divider is bypassed (divide by 1) and PLLA is enabled.  */
#define CKGR_PLLAR_DIVA_0                     (CKGR_PLLAR_DIVA_0_Val << CKGR_PLLAR_DIVA_Pos)       /**< (CKGR_PLLAR) PLLA is disabled. Position  */
#define CKGR_PLLAR_DIVA_BYPASS                (CKGR_PLLAR_DIVA_BYPASS_Val << CKGR_PLLAR_DIVA_Pos)  /**< (CKGR_PLLAR) Divider is bypassed (divide by 1) and PLLA is enabled. Position  */
#define CKGR_PLLAR_PLLACOUNT_Pos              _U_(8)                                               /**< (CKGR_PLLAR) PLLA Counter Position */
#define CKGR_PLLAR_PLLACOUNT_Msk              (_U_(0x3F) << CKGR_PLLAR_PLLACOUNT_Pos)              /**< (CKGR_PLLAR) PLLA Counter Mask */
#define CKGR_PLLAR_PLLACOUNT(value)           (CKGR_PLLAR_PLLACOUNT_Msk & ((value) << CKGR_PLLAR_PLLACOUNT_Pos))
#define CKGR_PLLAR_FREQ_VCO_Pos               _U_(14)                                              /**< (CKGR_PLLAR) VCO Frequency Configuratio Position */
#define CKGR_PLLAR_FREQ_VCO_Msk               (_U_(0x3) << CKGR_PLLAR_FREQ_VCO_Pos)                /**< (CKGR_PLLAR) VCO Frequency Configuratio Mask */
#define CKGR_PLLAR_FREQ_VCO(value)            (CKGR_PLLAR_FREQ_VCO_Msk & ((value) << CKGR_PLLAR_FREQ_VCO_Pos))
#define   CKGR_PLLAR_FREQ_VCO_VCO0_Val        _U_(0x0)                                             /**< (CKGR_PLLAR) Frequency range: 40-80 MHz  */
#define   CKGR_PLLAR_FREQ_VCO_VCO1_Val        _U_(0x1)                                             /**< (CKGR_PLLAR) Frequency range: 70-150 MHz  */
#define   CKGR_PLLAR_FREQ_VCO_VCO2_Val        _U_(0x2)                                             /**< (CKGR_PLLAR) Frequency range: 125-275 MHz  */
#define   CKGR_PLLAR_FREQ_VCO_VCO3_Val        _U_(0x3)                                             /**< (CKGR_PLLAR) Frequency range: 250-450 MHz  */
#define CKGR_PLLAR_FREQ_VCO_VCO0              (CKGR_PLLAR_FREQ_VCO_VCO0_Val << CKGR_PLLAR_FREQ_VCO_Pos) /**< (CKGR_PLLAR) Frequency range: 40-80 MHz Position  */
#define CKGR_PLLAR_FREQ_VCO_VCO1              (CKGR_PLLAR_FREQ_VCO_VCO1_Val << CKGR_PLLAR_FREQ_VCO_Pos) /**< (CKGR_PLLAR) Frequency range: 70-150 MHz Position  */
#define CKGR_PLLAR_FREQ_VCO_VCO2              (CKGR_PLLAR_FREQ_VCO_VCO2_Val << CKGR_PLLAR_FREQ_VCO_Pos) /**< (CKGR_PLLAR) Frequency range: 125-275 MHz Position  */
#define CKGR_PLLAR_FREQ_VCO_VCO3              (CKGR_PLLAR_FREQ_VCO_VCO3_Val << CKGR_PLLAR_FREQ_VCO_Pos) /**< (CKGR_PLLAR) Frequency range: 250-450 MHz Position  */
#define CKGR_PLLAR_MULA_Pos                   _U_(16)                                              /**< (CKGR_PLLAR) PLLA Multiplier Position */
#define CKGR_PLLAR_MULA_Msk                   (_U_(0x7FF) << CKGR_PLLAR_MULA_Pos)                  /**< (CKGR_PLLAR) PLLA Multiplier Mask */
#define CKGR_PLLAR_MULA(value)                (CKGR_PLLAR_MULA_Msk & ((value) << CKGR_PLLAR_MULA_Pos))
#define CKGR_PLLAR_ONE_Pos                    _U_(29)                                              /**< (CKGR_PLLAR) Must Be Set to 1 Position */
#define CKGR_PLLAR_ONE_Msk                    (_U_(0x1) << CKGR_PLLAR_ONE_Pos)                     /**< (CKGR_PLLAR) Must Be Set to 1 Mask */
#define CKGR_PLLAR_ONE(value)                 (CKGR_PLLAR_ONE_Msk & ((value) << CKGR_PLLAR_ONE_Pos))
#define CKGR_PLLAR_Msk                        _U_(0x27FFFFFF)                                      /**< (CKGR_PLLAR) Register Mask  */


/* -------- CKGR_PLLBR : (PMC Offset: 0x2C) (R/W 32) PLLB Register -------- */
#define CKGR_PLLBR_DIVB_Pos                   _U_(0)                                               /**< (CKGR_PLLBR) PLLB Front End Divider Position */
#define CKGR_PLLBR_DIVB_Msk                   (_U_(0xFF) << CKGR_PLLBR_DIVB_Pos)                   /**< (CKGR_PLLBR) PLLB Front End Divider Mask */
#define CKGR_PLLBR_DIVB(value)                (CKGR_PLLBR_DIVB_Msk & ((value) << CKGR_PLLBR_DIVB_Pos))
#define   CKGR_PLLBR_DIVB_0_Val               _U_(0x0)                                             /**< (CKGR_PLLBR) PLLBis disabled.  */
#define   CKGR_PLLBR_DIVB_BYPASS_Val          _U_(0x1)                                             /**< (CKGR_PLLBR) Divider is bypassed (divide by 1) and PLLB is enabled.  */
#define CKGR_PLLBR_DIVB_0                     (CKGR_PLLBR_DIVB_0_Val << CKGR_PLLBR_DIVB_Pos)       /**< (CKGR_PLLBR) PLLBis disabled. Position  */
#define CKGR_PLLBR_DIVB_BYPASS                (CKGR_PLLBR_DIVB_BYPASS_Val << CKGR_PLLBR_DIVB_Pos)  /**< (CKGR_PLLBR) Divider is bypassed (divide by 1) and PLLB is enabled. Position  */
#define CKGR_PLLBR_PLLBCOUNT_Pos              _U_(8)                                               /**< (CKGR_PLLBR) PLLB Counter Position */
#define CKGR_PLLBR_PLLBCOUNT_Msk              (_U_(0x3F) << CKGR_PLLBR_PLLBCOUNT_Pos)              /**< (CKGR_PLLBR) PLLB Counter Mask */
#define CKGR_PLLBR_PLLBCOUNT(value)           (CKGR_PLLBR_PLLBCOUNT_Msk & ((value) << CKGR_PLLBR_PLLBCOUNT_Pos))
#define CKGR_PLLBR_FREQ_VCO_Pos               _U_(14)                                              /**< (CKGR_PLLBR) VCO Frequency Configuration Position */
#define CKGR_PLLBR_FREQ_VCO_Msk               (_U_(0x3) << CKGR_PLLBR_FREQ_VCO_Pos)                /**< (CKGR_PLLBR) VCO Frequency Configuration Mask */
#define CKGR_PLLBR_FREQ_VCO(value)            (CKGR_PLLBR_FREQ_VCO_Msk & ((value) << CKGR_PLLBR_FREQ_VCO_Pos))
#define   CKGR_PLLBR_FREQ_VCO_VCO0_Val        _U_(0x0)                                             /**< (CKGR_PLLBR) Frequency range: 40-80 MHz  */
#define   CKGR_PLLBR_FREQ_VCO_VCO1_Val        _U_(0x1)                                             /**< (CKGR_PLLBR) Frequency range: 70-150 MHz  */
#define   CKGR_PLLBR_FREQ_VCO_VCO2_Val        _U_(0x2)                                             /**< (CKGR_PLLBR) Frequency range: 125-275 MHz  */
#define   CKGR_PLLBR_FREQ_VCO_VCO3_Val        _U_(0x3)                                             /**< (CKGR_PLLBR) Frequency range: 250-450 MHz  */
#define CKGR_PLLBR_FREQ_VCO_VCO0              (CKGR_PLLBR_FREQ_VCO_VCO0_Val << CKGR_PLLBR_FREQ_VCO_Pos) /**< (CKGR_PLLBR) Frequency range: 40-80 MHz Position  */
#define CKGR_PLLBR_FREQ_VCO_VCO1              (CKGR_PLLBR_FREQ_VCO_VCO1_Val << CKGR_PLLBR_FREQ_VCO_Pos) /**< (CKGR_PLLBR) Frequency range: 70-150 MHz Position  */
#define CKGR_PLLBR_FREQ_VCO_VCO2              (CKGR_PLLBR_FREQ_VCO_VCO2_Val << CKGR_PLLBR_FREQ_VCO_Pos) /**< (CKGR_PLLBR) Frequency range: 125-275 MHz Position  */
#define CKGR_PLLBR_FREQ_VCO_VCO3              (CKGR_PLLBR_FREQ_VCO_VCO3_Val << CKGR_PLLBR_FREQ_VCO_Pos) /**< (CKGR_PLLBR) Frequency range: 250-450 MHz Position  */
#define CKGR_PLLBR_MULB_Pos                   _U_(16)                                              /**< (CKGR_PLLBR) PLLB Multiplier Position */
#define CKGR_PLLBR_MULB_Msk                   (_U_(0x7FF) << CKGR_PLLBR_MULB_Pos)                  /**< (CKGR_PLLBR) PLLB Multiplier Mask */
#define CKGR_PLLBR_MULB(value)                (CKGR_PLLBR_MULB_Msk & ((value) << CKGR_PLLBR_MULB_Pos))
#define CKGR_PLLBR_SRCB_Pos                   _U_(29)                                              /**< (CKGR_PLLBR) PLLB Source Clock Selection Position */
#define CKGR_PLLBR_SRCB_Msk                   (_U_(0x3) << CKGR_PLLBR_SRCB_Pos)                    /**< (CKGR_PLLBR) PLLB Source Clock Selection Mask */
#define CKGR_PLLBR_SRCB(value)                (CKGR_PLLBR_SRCB_Msk & ((value) << CKGR_PLLBR_SRCB_Pos))
#define   CKGR_PLLBR_SRCB_MAINCK_Val          _U_(0x0)                                             /**< (CKGR_PLLBR) MAINCK is the source clock of PLLB.  */
#define   CKGR_PLLBR_SRCB_RC2CK_Val           _U_(0x2)                                             /**< (CKGR_PLLBR) RC2CK is the source clock of PLLB.  */
#define CKGR_PLLBR_SRCB_MAINCK                (CKGR_PLLBR_SRCB_MAINCK_Val << CKGR_PLLBR_SRCB_Pos)  /**< (CKGR_PLLBR) MAINCK is the source clock of PLLB. Position  */
#define CKGR_PLLBR_SRCB_RC2CK                 (CKGR_PLLBR_SRCB_RC2CK_Val << CKGR_PLLBR_SRCB_Pos)   /**< (CKGR_PLLBR) RC2CK is the source clock of PLLB. Position  */
#define CKGR_PLLBR_Msk                        _U_(0x67FFFFFF)                                      /**< (CKGR_PLLBR) Register Mask  */


/* -------- PMC_MCKR : (PMC Offset: 0x30) (R/W 32) Master Clock Register -------- */
#define PMC_MCKR_CSS_Pos                      _U_(0)                                               /**< (PMC_MCKR) Master Clock Source Selection Position */
#define PMC_MCKR_CSS_Msk                      (_U_(0x3) << PMC_MCKR_CSS_Pos)                       /**< (PMC_MCKR) Master Clock Source Selection Mask */
#define PMC_MCKR_CSS(value)                   (PMC_MCKR_CSS_Msk & ((value) << PMC_MCKR_CSS_Pos))  
#define   PMC_MCKR_CSS_SLOW_CLK_Val           _U_(0x0)                                             /**< (PMC_MCKR) MD_SLCK is selected  */
#define   PMC_MCKR_CSS_MAIN_CLK_Val           _U_(0x1)                                             /**< (PMC_MCKR) MAINCK is selected  */
#define   PMC_MCKR_CSS_PLLA_CLK_Val           _U_(0x2)                                             /**< (PMC_MCKR) PLLACK is selected  */
#define PMC_MCKR_CSS_SLOW_CLK                 (PMC_MCKR_CSS_SLOW_CLK_Val << PMC_MCKR_CSS_Pos)      /**< (PMC_MCKR) MD_SLCK is selected Position  */
#define PMC_MCKR_CSS_MAIN_CLK                 (PMC_MCKR_CSS_MAIN_CLK_Val << PMC_MCKR_CSS_Pos)      /**< (PMC_MCKR) MAINCK is selected Position  */
#define PMC_MCKR_CSS_PLLA_CLK                 (PMC_MCKR_CSS_PLLA_CLK_Val << PMC_MCKR_CSS_Pos)      /**< (PMC_MCKR) PLLACK is selected Position  */
#define PMC_MCKR_PRES_Pos                     _U_(4)                                               /**< (PMC_MCKR) Processor Clock Prescaler Position */
#define PMC_MCKR_PRES_Msk                     (_U_(0x7) << PMC_MCKR_PRES_Pos)                      /**< (PMC_MCKR) Processor Clock Prescaler Mask */
#define PMC_MCKR_PRES(value)                  (PMC_MCKR_PRES_Msk & ((value) << PMC_MCKR_PRES_Pos))
#define   PMC_MCKR_PRES_CLK_1_Val             _U_(0x0)                                             /**< (PMC_MCKR) Selected clock  */
#define   PMC_MCKR_PRES_CLK_2_Val             _U_(0x1)                                             /**< (PMC_MCKR) Selected clock divided by 2  */
#define   PMC_MCKR_PRES_CLK_4_Val             _U_(0x2)                                             /**< (PMC_MCKR) Selected clock divided by 4  */
#define   PMC_MCKR_PRES_CLK_8_Val             _U_(0x3)                                             /**< (PMC_MCKR) Selected clock divided by 8  */
#define   PMC_MCKR_PRES_CLK_16_Val            _U_(0x4)                                             /**< (PMC_MCKR) Selected clock divided by 16  */
#define   PMC_MCKR_PRES_CLK_32_Val            _U_(0x5)                                             /**< (PMC_MCKR) Selected clock divided by 32  */
#define   PMC_MCKR_PRES_CLK_64_Val            _U_(0x6)                                             /**< (PMC_MCKR) Selected clock divided by 64  */
#define PMC_MCKR_PRES_CLK_1                   (PMC_MCKR_PRES_CLK_1_Val << PMC_MCKR_PRES_Pos)       /**< (PMC_MCKR) Selected clock Position  */
#define PMC_MCKR_PRES_CLK_2                   (PMC_MCKR_PRES_CLK_2_Val << PMC_MCKR_PRES_Pos)       /**< (PMC_MCKR) Selected clock divided by 2 Position  */
#define PMC_MCKR_PRES_CLK_4                   (PMC_MCKR_PRES_CLK_4_Val << PMC_MCKR_PRES_Pos)       /**< (PMC_MCKR) Selected clock divided by 4 Position  */
#define PMC_MCKR_PRES_CLK_8                   (PMC_MCKR_PRES_CLK_8_Val << PMC_MCKR_PRES_Pos)       /**< (PMC_MCKR) Selected clock divided by 8 Position  */
#define PMC_MCKR_PRES_CLK_16                  (PMC_MCKR_PRES_CLK_16_Val << PMC_MCKR_PRES_Pos)      /**< (PMC_MCKR) Selected clock divided by 16 Position  */
#define PMC_MCKR_PRES_CLK_32                  (PMC_MCKR_PRES_CLK_32_Val << PMC_MCKR_PRES_Pos)      /**< (PMC_MCKR) Selected clock divided by 32 Position  */
#define PMC_MCKR_PRES_CLK_64                  (PMC_MCKR_PRES_CLK_64_Val << PMC_MCKR_PRES_Pos)      /**< (PMC_MCKR) Selected clock divided by 64 Position  */
#define PMC_MCKR_MDIV_Pos                     _U_(8)                                               /**< (PMC_MCKR) Master Clock Division Position */
#define PMC_MCKR_MDIV_Msk                     (_U_(0x1) << PMC_MCKR_MDIV_Pos)                      /**< (PMC_MCKR) Master Clock Division Mask */
#define PMC_MCKR_MDIV(value)                  (PMC_MCKR_MDIV_Msk & ((value) << PMC_MCKR_MDIV_Pos))
#define   PMC_MCKR_MDIV_EQ_PCK_Val            _U_(0x0)                                             /**< (PMC_MCKR) MCK is FCLK divided by 1.  */
#define   PMC_MCKR_MDIV_PCK_DIV2_Val          _U_(0x1)                                             /**< (PMC_MCKR) MCK is FCLK divided by 2.  */
#define PMC_MCKR_MDIV_EQ_PCK                  (PMC_MCKR_MDIV_EQ_PCK_Val << PMC_MCKR_MDIV_Pos)      /**< (PMC_MCKR) MCK is FCLK divided by 1. Position  */
#define PMC_MCKR_MDIV_PCK_DIV2                (PMC_MCKR_MDIV_PCK_DIV2_Val << PMC_MCKR_MDIV_Pos)    /**< (PMC_MCKR) MCK is FCLK divided by 2. Position  */
#define PMC_MCKR_Msk                          _U_(0x00000173)                                      /**< (PMC_MCKR) Register Mask  */


/* -------- PMC_PCK : (PMC Offset: 0x40) (R/W 32) Programmable Clock Register -------- */
#define PMC_PCK_CSS_Pos                       _U_(0)                                               /**< (PMC_PCK) Programmable Clock Source Selection Position */
#define PMC_PCK_CSS_Msk                       (_U_(0x7) << PMC_PCK_CSS_Pos)                        /**< (PMC_PCK) Programmable Clock Source Selection Mask */
#define PMC_PCK_CSS(value)                    (PMC_PCK_CSS_Msk & ((value) << PMC_PCK_CSS_Pos))    
#define   PMC_PCK_CSS_SLOW_CLK_Val            _U_(0x0)                                             /**< (PMC_PCK) MD_SLCK is selected  */
#define   PMC_PCK_CSS_MAIN_CLK_Val            _U_(0x1)                                             /**< (PMC_PCK) MAINCK is selected  */
#define   PMC_PCK_CSS_PLLA_CLK_Val            _U_(0x2)                                             /**< (PMC_PCK) PLLACK is selected  */
#define   PMC_PCK_CSS_PLLB_CLK_Val            _U_(0x3)                                             /**< (PMC_PCK) PLLBCKDIV is selected  */
#define   PMC_PCK_CSS_MCK_Val                 _U_(0x4)                                             /**< (PMC_PCK) MCK is selected  */
#define PMC_PCK_CSS_SLOW_CLK                  (PMC_PCK_CSS_SLOW_CLK_Val << PMC_PCK_CSS_Pos)        /**< (PMC_PCK) MD_SLCK is selected Position  */
#define PMC_PCK_CSS_MAIN_CLK                  (PMC_PCK_CSS_MAIN_CLK_Val << PMC_PCK_CSS_Pos)        /**< (PMC_PCK) MAINCK is selected Position  */
#define PMC_PCK_CSS_PLLA_CLK                  (PMC_PCK_CSS_PLLA_CLK_Val << PMC_PCK_CSS_Pos)        /**< (PMC_PCK) PLLACK is selected Position  */
#define PMC_PCK_CSS_PLLB_CLK                  (PMC_PCK_CSS_PLLB_CLK_Val << PMC_PCK_CSS_Pos)        /**< (PMC_PCK) PLLBCKDIV is selected Position  */
#define PMC_PCK_CSS_MCK                       (PMC_PCK_CSS_MCK_Val << PMC_PCK_CSS_Pos)             /**< (PMC_PCK) MCK is selected Position  */
#define PMC_PCK_PRES_Pos                      _U_(4)                                               /**< (PMC_PCK) Programmable Clock Prescaler Position */
#define PMC_PCK_PRES_Msk                      (_U_(0xFF) << PMC_PCK_PRES_Pos)                      /**< (PMC_PCK) Programmable Clock Prescaler Mask */
#define PMC_PCK_PRES(value)                   (PMC_PCK_PRES_Msk & ((value) << PMC_PCK_PRES_Pos))  
#define PMC_PCK_Msk                           _U_(0x00000FF7)                                      /**< (PMC_PCK) Register Mask  */


/* -------- PMC_IER : (PMC Offset: 0x60) ( /W 32) Interrupt Enable Register -------- */
#define PMC_IER_MOSCXTS_Pos                   _U_(0)                                               /**< (PMC_IER) Main Crystal Oscillator Status Interrupt Enable Position */
#define PMC_IER_MOSCXTS_Msk                   (_U_(0x1) << PMC_IER_MOSCXTS_Pos)                    /**< (PMC_IER) Main Crystal Oscillator Status Interrupt Enable Mask */
#define PMC_IER_MOSCXTS(value)                (PMC_IER_MOSCXTS_Msk & ((value) << PMC_IER_MOSCXTS_Pos))
#define PMC_IER_LOCKA_Pos                     _U_(1)                                               /**< (PMC_IER) PLLA Lock Interrupt Enable Position */
#define PMC_IER_LOCKA_Msk                     (_U_(0x1) << PMC_IER_LOCKA_Pos)                      /**< (PMC_IER) PLLA Lock Interrupt Enable Mask */
#define PMC_IER_LOCKA(value)                  (PMC_IER_LOCKA_Msk & ((value) << PMC_IER_LOCKA_Pos))
#define PMC_IER_LOCKB_Pos                     _U_(2)                                               /**< (PMC_IER) PLLB Lock Interrupt Enable Position */
#define PMC_IER_LOCKB_Msk                     (_U_(0x1) << PMC_IER_LOCKB_Pos)                      /**< (PMC_IER) PLLB Lock Interrupt Enable Mask */
#define PMC_IER_LOCKB(value)                  (PMC_IER_LOCKB_Msk & ((value) << PMC_IER_LOCKB_Pos))
#define PMC_IER_MCKRDY_Pos                    _U_(3)                                               /**< (PMC_IER) Master Clock Ready Interrupt Enable Position */
#define PMC_IER_MCKRDY_Msk                    (_U_(0x1) << PMC_IER_MCKRDY_Pos)                     /**< (PMC_IER) Master Clock Ready Interrupt Enable Mask */
#define PMC_IER_MCKRDY(value)                 (PMC_IER_MCKRDY_Msk & ((value) << PMC_IER_MCKRDY_Pos))
#define PMC_IER_PCKRDY0_Pos                   _U_(8)                                               /**< (PMC_IER) Programmable Clock Ready 0 Interrupt Enable Position */
#define PMC_IER_PCKRDY0_Msk                   (_U_(0x1) << PMC_IER_PCKRDY0_Pos)                    /**< (PMC_IER) Programmable Clock Ready 0 Interrupt Enable Mask */
#define PMC_IER_PCKRDY0(value)                (PMC_IER_PCKRDY0_Msk & ((value) << PMC_IER_PCKRDY0_Pos))
#define PMC_IER_PCKRDY1_Pos                   _U_(9)                                               /**< (PMC_IER) Programmable Clock Ready 1 Interrupt Enable Position */
#define PMC_IER_PCKRDY1_Msk                   (_U_(0x1) << PMC_IER_PCKRDY1_Pos)                    /**< (PMC_IER) Programmable Clock Ready 1 Interrupt Enable Mask */
#define PMC_IER_PCKRDY1(value)                (PMC_IER_PCKRDY1_Msk & ((value) << PMC_IER_PCKRDY1_Pos))
#define PMC_IER_PCKRDY2_Pos                   _U_(10)                                              /**< (PMC_IER) Programmable Clock Ready 2 Interrupt Enable Position */
#define PMC_IER_PCKRDY2_Msk                   (_U_(0x1) << PMC_IER_PCKRDY2_Pos)                    /**< (PMC_IER) Programmable Clock Ready 2 Interrupt Enable Mask */
#define PMC_IER_PCKRDY2(value)                (PMC_IER_PCKRDY2_Msk & ((value) << PMC_IER_PCKRDY2_Pos))
#define PMC_IER_PCKRDY3_Pos                   _U_(11)                                              /**< (PMC_IER) Programmable Clock Ready 3 Interrupt Enable Position */
#define PMC_IER_PCKRDY3_Msk                   (_U_(0x1) << PMC_IER_PCKRDY3_Pos)                    /**< (PMC_IER) Programmable Clock Ready 3 Interrupt Enable Mask */
#define PMC_IER_PCKRDY3(value)                (PMC_IER_PCKRDY3_Msk & ((value) << PMC_IER_PCKRDY3_Pos))
#define PMC_IER_MOSCSELS_Pos                  _U_(16)                                              /**< (PMC_IER) Main Clock Source Oscillator Selection Status Interrupt Enable Position */
#define PMC_IER_MOSCSELS_Msk                  (_U_(0x1) << PMC_IER_MOSCSELS_Pos)                   /**< (PMC_IER) Main Clock Source Oscillator Selection Status Interrupt Enable Mask */
#define PMC_IER_MOSCSELS(value)               (PMC_IER_MOSCSELS_Msk & ((value) << PMC_IER_MOSCSELS_Pos))
#define PMC_IER_MOSCRCS_Pos                   _U_(17)                                              /**< (PMC_IER) Main RC Oscillator Status Interrupt Enable Position */
#define PMC_IER_MOSCRCS_Msk                   (_U_(0x1) << PMC_IER_MOSCRCS_Pos)                    /**< (PMC_IER) Main RC Oscillator Status Interrupt Enable Mask */
#define PMC_IER_MOSCRCS(value)                (PMC_IER_MOSCRCS_Msk & ((value) << PMC_IER_MOSCRCS_Pos))
#define PMC_IER_CFDEV_Pos                     _U_(18)                                              /**< (PMC_IER) Clock Failure Detector Event Interrupt Enable Position */
#define PMC_IER_CFDEV_Msk                     (_U_(0x1) << PMC_IER_CFDEV_Pos)                      /**< (PMC_IER) Clock Failure Detector Event Interrupt Enable Mask */
#define PMC_IER_CFDEV(value)                  (PMC_IER_CFDEV_Msk & ((value) << PMC_IER_CFDEV_Pos))
#define PMC_IER_EXT32KERR_Pos                 _U_(21)                                              /**< (PMC_IER) 32.768 kHz Crystal Oscillator Error Interrupt Enable Position */
#define PMC_IER_EXT32KERR_Msk                 (_U_(0x1) << PMC_IER_EXT32KERR_Pos)                  /**< (PMC_IER) 32.768 kHz Crystal Oscillator Error Interrupt Enable Mask */
#define PMC_IER_EXT32KERR(value)              (PMC_IER_EXT32KERR_Msk & ((value) << PMC_IER_EXT32KERR_Pos))
#define PMC_IER_CPUMON_Pos                    _U_(23)                                              /**< (PMC_IER) CPU Clock Monitor Interrupt Enable Position */
#define PMC_IER_CPUMON_Msk                    (_U_(0x1) << PMC_IER_CPUMON_Pos)                     /**< (PMC_IER) CPU Clock Monitor Interrupt Enable Mask */
#define PMC_IER_CPUMON(value)                 (PMC_IER_CPUMON_Msk & ((value) << PMC_IER_CPUMON_Pos))
#define PMC_IER_Msk                           _U_(0x00A70F0F)                                      /**< (PMC_IER) Register Mask  */

#define PMC_IER_PCKRDY_Pos                    _U_(8)                                               /**< (PMC_IER Position) Programmable Clock Ready x Interrupt Enable */
#define PMC_IER_PCKRDY_Msk                    (_U_(0xF) << PMC_IER_PCKRDY_Pos)                     /**< (PMC_IER Mask) PCKRDY */
#define PMC_IER_PCKRDY(value)                 (PMC_IER_PCKRDY_Msk & ((value) << PMC_IER_PCKRDY_Pos)) 

/* -------- PMC_IDR : (PMC Offset: 0x64) ( /W 32) Interrupt Disable Register -------- */
#define PMC_IDR_MOSCXTS_Pos                   _U_(0)                                               /**< (PMC_IDR) Main Crystal Oscillator Status Interrupt Disable Position */
#define PMC_IDR_MOSCXTS_Msk                   (_U_(0x1) << PMC_IDR_MOSCXTS_Pos)                    /**< (PMC_IDR) Main Crystal Oscillator Status Interrupt Disable Mask */
#define PMC_IDR_MOSCXTS(value)                (PMC_IDR_MOSCXTS_Msk & ((value) << PMC_IDR_MOSCXTS_Pos))
#define PMC_IDR_LOCKA_Pos                     _U_(1)                                               /**< (PMC_IDR) PLLA Lock Interrupt Disable Position */
#define PMC_IDR_LOCKA_Msk                     (_U_(0x1) << PMC_IDR_LOCKA_Pos)                      /**< (PMC_IDR) PLLA Lock Interrupt Disable Mask */
#define PMC_IDR_LOCKA(value)                  (PMC_IDR_LOCKA_Msk & ((value) << PMC_IDR_LOCKA_Pos))
#define PMC_IDR_LOCKB_Pos                     _U_(2)                                               /**< (PMC_IDR) PLLB Lock Interrupt Disable Position */
#define PMC_IDR_LOCKB_Msk                     (_U_(0x1) << PMC_IDR_LOCKB_Pos)                      /**< (PMC_IDR) PLLB Lock Interrupt Disable Mask */
#define PMC_IDR_LOCKB(value)                  (PMC_IDR_LOCKB_Msk & ((value) << PMC_IDR_LOCKB_Pos))
#define PMC_IDR_MCKRDY_Pos                    _U_(3)                                               /**< (PMC_IDR) Master Clock Ready Interrupt Disable Position */
#define PMC_IDR_MCKRDY_Msk                    (_U_(0x1) << PMC_IDR_MCKRDY_Pos)                     /**< (PMC_IDR) Master Clock Ready Interrupt Disable Mask */
#define PMC_IDR_MCKRDY(value)                 (PMC_IDR_MCKRDY_Msk & ((value) << PMC_IDR_MCKRDY_Pos))
#define PMC_IDR_PCKRDY0_Pos                   _U_(8)                                               /**< (PMC_IDR) Programmable Clock Ready 0 Interrupt Disable Position */
#define PMC_IDR_PCKRDY0_Msk                   (_U_(0x1) << PMC_IDR_PCKRDY0_Pos)                    /**< (PMC_IDR) Programmable Clock Ready 0 Interrupt Disable Mask */
#define PMC_IDR_PCKRDY0(value)                (PMC_IDR_PCKRDY0_Msk & ((value) << PMC_IDR_PCKRDY0_Pos))
#define PMC_IDR_PCKRDY1_Pos                   _U_(9)                                               /**< (PMC_IDR) Programmable Clock Ready 1 Interrupt Disable Position */
#define PMC_IDR_PCKRDY1_Msk                   (_U_(0x1) << PMC_IDR_PCKRDY1_Pos)                    /**< (PMC_IDR) Programmable Clock Ready 1 Interrupt Disable Mask */
#define PMC_IDR_PCKRDY1(value)                (PMC_IDR_PCKRDY1_Msk & ((value) << PMC_IDR_PCKRDY1_Pos))
#define PMC_IDR_PCKRDY2_Pos                   _U_(10)                                              /**< (PMC_IDR) Programmable Clock Ready 2 Interrupt Disable Position */
#define PMC_IDR_PCKRDY2_Msk                   (_U_(0x1) << PMC_IDR_PCKRDY2_Pos)                    /**< (PMC_IDR) Programmable Clock Ready 2 Interrupt Disable Mask */
#define PMC_IDR_PCKRDY2(value)                (PMC_IDR_PCKRDY2_Msk & ((value) << PMC_IDR_PCKRDY2_Pos))
#define PMC_IDR_PCKRDY3_Pos                   _U_(11)                                              /**< (PMC_IDR) Programmable Clock Ready 3 Interrupt Disable Position */
#define PMC_IDR_PCKRDY3_Msk                   (_U_(0x1) << PMC_IDR_PCKRDY3_Pos)                    /**< (PMC_IDR) Programmable Clock Ready 3 Interrupt Disable Mask */
#define PMC_IDR_PCKRDY3(value)                (PMC_IDR_PCKRDY3_Msk & ((value) << PMC_IDR_PCKRDY3_Pos))
#define PMC_IDR_MOSCSELS_Pos                  _U_(16)                                              /**< (PMC_IDR) Main Clock Source Oscillator Selection Status Interrupt Disable Position */
#define PMC_IDR_MOSCSELS_Msk                  (_U_(0x1) << PMC_IDR_MOSCSELS_Pos)                   /**< (PMC_IDR) Main Clock Source Oscillator Selection Status Interrupt Disable Mask */
#define PMC_IDR_MOSCSELS(value)               (PMC_IDR_MOSCSELS_Msk & ((value) << PMC_IDR_MOSCSELS_Pos))
#define PMC_IDR_MOSCRCS_Pos                   _U_(17)                                              /**< (PMC_IDR) Main RC Status Interrupt Disable Position */
#define PMC_IDR_MOSCRCS_Msk                   (_U_(0x1) << PMC_IDR_MOSCRCS_Pos)                    /**< (PMC_IDR) Main RC Status Interrupt Disable Mask */
#define PMC_IDR_MOSCRCS(value)                (PMC_IDR_MOSCRCS_Msk & ((value) << PMC_IDR_MOSCRCS_Pos))
#define PMC_IDR_CFDEV_Pos                     _U_(18)                                              /**< (PMC_IDR) Clock Failure Detector Event Interrupt Disable Position */
#define PMC_IDR_CFDEV_Msk                     (_U_(0x1) << PMC_IDR_CFDEV_Pos)                      /**< (PMC_IDR) Clock Failure Detector Event Interrupt Disable Mask */
#define PMC_IDR_CFDEV(value)                  (PMC_IDR_CFDEV_Msk & ((value) << PMC_IDR_CFDEV_Pos))
#define PMC_IDR_EXT32KERR_Pos                 _U_(21)                                              /**< (PMC_IDR) 32.768 kHz Crystal Oscillator Error Interrupt Disable Position */
#define PMC_IDR_EXT32KERR_Msk                 (_U_(0x1) << PMC_IDR_EXT32KERR_Pos)                  /**< (PMC_IDR) 32.768 kHz Crystal Oscillator Error Interrupt Disable Mask */
#define PMC_IDR_EXT32KERR(value)              (PMC_IDR_EXT32KERR_Msk & ((value) << PMC_IDR_EXT32KERR_Pos))
#define PMC_IDR_CPUMON_Pos                    _U_(23)                                              /**< (PMC_IDR) CPU Clock Monitor Interrupt Disable Position */
#define PMC_IDR_CPUMON_Msk                    (_U_(0x1) << PMC_IDR_CPUMON_Pos)                     /**< (PMC_IDR) CPU Clock Monitor Interrupt Disable Mask */
#define PMC_IDR_CPUMON(value)                 (PMC_IDR_CPUMON_Msk & ((value) << PMC_IDR_CPUMON_Pos))
#define PMC_IDR_Msk                           _U_(0x00A70F0F)                                      /**< (PMC_IDR) Register Mask  */

#define PMC_IDR_PCKRDY_Pos                    _U_(8)                                               /**< (PMC_IDR Position) Programmable Clock Ready x Interrupt Disable */
#define PMC_IDR_PCKRDY_Msk                    (_U_(0xF) << PMC_IDR_PCKRDY_Pos)                     /**< (PMC_IDR Mask) PCKRDY */
#define PMC_IDR_PCKRDY(value)                 (PMC_IDR_PCKRDY_Msk & ((value) << PMC_IDR_PCKRDY_Pos)) 

/* -------- PMC_SR : (PMC Offset: 0x68) ( R/ 32) Status Register -------- */
#define PMC_SR_MOSCXTS_Pos                    _U_(0)                                               /**< (PMC_SR) Main Crystal Oscillator Status Position */
#define PMC_SR_MOSCXTS_Msk                    (_U_(0x1) << PMC_SR_MOSCXTS_Pos)                     /**< (PMC_SR) Main Crystal Oscillator Status Mask */
#define PMC_SR_MOSCXTS(value)                 (PMC_SR_MOSCXTS_Msk & ((value) << PMC_SR_MOSCXTS_Pos))
#define PMC_SR_LOCKA_Pos                      _U_(1)                                               /**< (PMC_SR) PLLA Lock Status Position */
#define PMC_SR_LOCKA_Msk                      (_U_(0x1) << PMC_SR_LOCKA_Pos)                       /**< (PMC_SR) PLLA Lock Status Mask */
#define PMC_SR_LOCKA(value)                   (PMC_SR_LOCKA_Msk & ((value) << PMC_SR_LOCKA_Pos))  
#define PMC_SR_LOCKB_Pos                      _U_(2)                                               /**< (PMC_SR) PLLB Lock Status Position */
#define PMC_SR_LOCKB_Msk                      (_U_(0x1) << PMC_SR_LOCKB_Pos)                       /**< (PMC_SR) PLLB Lock Status Mask */
#define PMC_SR_LOCKB(value)                   (PMC_SR_LOCKB_Msk & ((value) << PMC_SR_LOCKB_Pos))  
#define PMC_SR_MCKRDY_Pos                     _U_(3)                                               /**< (PMC_SR) Master Clock Status Position */
#define PMC_SR_MCKRDY_Msk                     (_U_(0x1) << PMC_SR_MCKRDY_Pos)                      /**< (PMC_SR) Master Clock Status Mask */
#define PMC_SR_MCKRDY(value)                  (PMC_SR_MCKRDY_Msk & ((value) << PMC_SR_MCKRDY_Pos))
#define PMC_SR_OSCSELS_Pos                    _U_(7)                                               /**< (PMC_SR) Monitoring Domain Slow Clock Source Oscillator Selection Position */
#define PMC_SR_OSCSELS_Msk                    (_U_(0x1) << PMC_SR_OSCSELS_Pos)                     /**< (PMC_SR) Monitoring Domain Slow Clock Source Oscillator Selection Mask */
#define PMC_SR_OSCSELS(value)                 (PMC_SR_OSCSELS_Msk & ((value) << PMC_SR_OSCSELS_Pos))
#define PMC_SR_PCKRDY0_Pos                    _U_(8)                                               /**< (PMC_SR) Programmable Clock Ready Status Position */
#define PMC_SR_PCKRDY0_Msk                    (_U_(0x1) << PMC_SR_PCKRDY0_Pos)                     /**< (PMC_SR) Programmable Clock Ready Status Mask */
#define PMC_SR_PCKRDY0(value)                 (PMC_SR_PCKRDY0_Msk & ((value) << PMC_SR_PCKRDY0_Pos))
#define PMC_SR_PCKRDY1_Pos                    _U_(9)                                               /**< (PMC_SR) Programmable Clock Ready Status Position */
#define PMC_SR_PCKRDY1_Msk                    (_U_(0x1) << PMC_SR_PCKRDY1_Pos)                     /**< (PMC_SR) Programmable Clock Ready Status Mask */
#define PMC_SR_PCKRDY1(value)                 (PMC_SR_PCKRDY1_Msk & ((value) << PMC_SR_PCKRDY1_Pos))
#define PMC_SR_PCKRDY2_Pos                    _U_(10)                                              /**< (PMC_SR) Programmable Clock Ready Status Position */
#define PMC_SR_PCKRDY2_Msk                    (_U_(0x1) << PMC_SR_PCKRDY2_Pos)                     /**< (PMC_SR) Programmable Clock Ready Status Mask */
#define PMC_SR_PCKRDY2(value)                 (PMC_SR_PCKRDY2_Msk & ((value) << PMC_SR_PCKRDY2_Pos))
#define PMC_SR_PCKRDY3_Pos                    _U_(11)                                              /**< (PMC_SR) Programmable Clock Ready Status Position */
#define PMC_SR_PCKRDY3_Msk                    (_U_(0x1) << PMC_SR_PCKRDY3_Pos)                     /**< (PMC_SR) Programmable Clock Ready Status Mask */
#define PMC_SR_PCKRDY3(value)                 (PMC_SR_PCKRDY3_Msk & ((value) << PMC_SR_PCKRDY3_Pos))
#define PMC_SR_MOSCSELS_Pos                   _U_(16)                                              /**< (PMC_SR) Main Clock Source Oscillator Selection Status Position */
#define PMC_SR_MOSCSELS_Msk                   (_U_(0x1) << PMC_SR_MOSCSELS_Pos)                    /**< (PMC_SR) Main Clock Source Oscillator Selection Status Mask */
#define PMC_SR_MOSCSELS(value)                (PMC_SR_MOSCSELS_Msk & ((value) << PMC_SR_MOSCSELS_Pos))
#define PMC_SR_MOSCRCS_Pos                    _U_(17)                                              /**< (PMC_SR) Main RC Oscillator Status Position */
#define PMC_SR_MOSCRCS_Msk                    (_U_(0x1) << PMC_SR_MOSCRCS_Pos)                     /**< (PMC_SR) Main RC Oscillator Status Mask */
#define PMC_SR_MOSCRCS(value)                 (PMC_SR_MOSCRCS_Msk & ((value) << PMC_SR_MOSCRCS_Pos))
#define PMC_SR_CFDEV_Pos                      _U_(18)                                              /**< (PMC_SR) Clock Failure Detector Event Position */
#define PMC_SR_CFDEV_Msk                      (_U_(0x1) << PMC_SR_CFDEV_Pos)                       /**< (PMC_SR) Clock Failure Detector Event Mask */
#define PMC_SR_CFDEV(value)                   (PMC_SR_CFDEV_Msk & ((value) << PMC_SR_CFDEV_Pos))  
#define PMC_SR_CFDS_Pos                       _U_(19)                                              /**< (PMC_SR) Clock Failure Detector Status Position */
#define PMC_SR_CFDS_Msk                       (_U_(0x1) << PMC_SR_CFDS_Pos)                        /**< (PMC_SR) Clock Failure Detector Status Mask */
#define PMC_SR_CFDS(value)                    (PMC_SR_CFDS_Msk & ((value) << PMC_SR_CFDS_Pos))    
#define PMC_SR_FOS_Pos                        _U_(20)                                              /**< (PMC_SR) Clock Failure Detector Fault Output Status Position */
#define PMC_SR_FOS_Msk                        (_U_(0x1) << PMC_SR_FOS_Pos)                         /**< (PMC_SR) Clock Failure Detector Fault Output Status Mask */
#define PMC_SR_FOS(value)                     (PMC_SR_FOS_Msk & ((value) << PMC_SR_FOS_Pos))      
#define PMC_SR_EXT32KERR_Pos                  _U_(21)                                              /**< (PMC_SR) Slow Crystal Oscillator Error Position */
#define PMC_SR_EXT32KERR_Msk                  (_U_(0x1) << PMC_SR_EXT32KERR_Pos)                   /**< (PMC_SR) Slow Crystal Oscillator Error Mask */
#define PMC_SR_EXT32KERR(value)               (PMC_SR_EXT32KERR_Msk & ((value) << PMC_SR_EXT32KERR_Pos))
#define PMC_SR_CPUMON_Pos                     _U_(23)                                              /**< (PMC_SR) CPU Clock Monitor Error Position */
#define PMC_SR_CPUMON_Msk                     (_U_(0x1) << PMC_SR_CPUMON_Pos)                      /**< (PMC_SR) CPU Clock Monitor Error Mask */
#define PMC_SR_CPUMON(value)                  (PMC_SR_CPUMON_Msk & ((value) << PMC_SR_CPUMON_Pos))
#define PMC_SR_Msk                            _U_(0x00BF0F8F)                                      /**< (PMC_SR) Register Mask  */

#define PMC_SR_PCKRDY_Pos                     _U_(8)                                               /**< (PMC_SR Position) Programmable Clock Ready Status */
#define PMC_SR_PCKRDY_Msk                     (_U_(0xF) << PMC_SR_PCKRDY_Pos)                      /**< (PMC_SR Mask) PCKRDY */
#define PMC_SR_PCKRDY(value)                  (PMC_SR_PCKRDY_Msk & ((value) << PMC_SR_PCKRDY_Pos)) 

/* -------- PMC_IMR : (PMC Offset: 0x6C) ( R/ 32) Interrupt Mask Register -------- */
#define PMC_IMR_MOSCXTS_Pos                   _U_(0)                                               /**< (PMC_IMR) Main Crystal Oscillator Status Interrupt Mask Position */
#define PMC_IMR_MOSCXTS_Msk                   (_U_(0x1) << PMC_IMR_MOSCXTS_Pos)                    /**< (PMC_IMR) Main Crystal Oscillator Status Interrupt Mask Mask */
#define PMC_IMR_MOSCXTS(value)                (PMC_IMR_MOSCXTS_Msk & ((value) << PMC_IMR_MOSCXTS_Pos))
#define PMC_IMR_LOCKA_Pos                     _U_(1)                                               /**< (PMC_IMR) PLLA Lock Interrupt Mask Position */
#define PMC_IMR_LOCKA_Msk                     (_U_(0x1) << PMC_IMR_LOCKA_Pos)                      /**< (PMC_IMR) PLLA Lock Interrupt Mask Mask */
#define PMC_IMR_LOCKA(value)                  (PMC_IMR_LOCKA_Msk & ((value) << PMC_IMR_LOCKA_Pos))
#define PMC_IMR_LOCKB_Pos                     _U_(2)                                               /**< (PMC_IMR) PLLB Lock Interrupt Mask Position */
#define PMC_IMR_LOCKB_Msk                     (_U_(0x1) << PMC_IMR_LOCKB_Pos)                      /**< (PMC_IMR) PLLB Lock Interrupt Mask Mask */
#define PMC_IMR_LOCKB(value)                  (PMC_IMR_LOCKB_Msk & ((value) << PMC_IMR_LOCKB_Pos))
#define PMC_IMR_MCKRDY_Pos                    _U_(3)                                               /**< (PMC_IMR) Master Clock Ready Interrupt Mask Position */
#define PMC_IMR_MCKRDY_Msk                    (_U_(0x1) << PMC_IMR_MCKRDY_Pos)                     /**< (PMC_IMR) Master Clock Ready Interrupt Mask Mask */
#define PMC_IMR_MCKRDY(value)                 (PMC_IMR_MCKRDY_Msk & ((value) << PMC_IMR_MCKRDY_Pos))
#define PMC_IMR_PCKRDY0_Pos                   _U_(8)                                               /**< (PMC_IMR) Programmable Clock Ready 0 Interrupt Mask Position */
#define PMC_IMR_PCKRDY0_Msk                   (_U_(0x1) << PMC_IMR_PCKRDY0_Pos)                    /**< (PMC_IMR) Programmable Clock Ready 0 Interrupt Mask Mask */
#define PMC_IMR_PCKRDY0(value)                (PMC_IMR_PCKRDY0_Msk & ((value) << PMC_IMR_PCKRDY0_Pos))
#define PMC_IMR_PCKRDY1_Pos                   _U_(9)                                               /**< (PMC_IMR) Programmable Clock Ready 1 Interrupt Mask Position */
#define PMC_IMR_PCKRDY1_Msk                   (_U_(0x1) << PMC_IMR_PCKRDY1_Pos)                    /**< (PMC_IMR) Programmable Clock Ready 1 Interrupt Mask Mask */
#define PMC_IMR_PCKRDY1(value)                (PMC_IMR_PCKRDY1_Msk & ((value) << PMC_IMR_PCKRDY1_Pos))
#define PMC_IMR_PCKRDY2_Pos                   _U_(10)                                              /**< (PMC_IMR) Programmable Clock Ready 2 Interrupt Mask Position */
#define PMC_IMR_PCKRDY2_Msk                   (_U_(0x1) << PMC_IMR_PCKRDY2_Pos)                    /**< (PMC_IMR) Programmable Clock Ready 2 Interrupt Mask Mask */
#define PMC_IMR_PCKRDY2(value)                (PMC_IMR_PCKRDY2_Msk & ((value) << PMC_IMR_PCKRDY2_Pos))
#define PMC_IMR_PCKRDY3_Pos                   _U_(11)                                              /**< (PMC_IMR) Programmable Clock Ready 3 Interrupt Mask Position */
#define PMC_IMR_PCKRDY3_Msk                   (_U_(0x1) << PMC_IMR_PCKRDY3_Pos)                    /**< (PMC_IMR) Programmable Clock Ready 3 Interrupt Mask Mask */
#define PMC_IMR_PCKRDY3(value)                (PMC_IMR_PCKRDY3_Msk & ((value) << PMC_IMR_PCKRDY3_Pos))
#define PMC_IMR_MOSCSELS_Pos                  _U_(16)                                              /**< (PMC_IMR) Main Clock Source Oscillator Selection Status Interrupt Mask Position */
#define PMC_IMR_MOSCSELS_Msk                  (_U_(0x1) << PMC_IMR_MOSCSELS_Pos)                   /**< (PMC_IMR) Main Clock Source Oscillator Selection Status Interrupt Mask Mask */
#define PMC_IMR_MOSCSELS(value)               (PMC_IMR_MOSCSELS_Msk & ((value) << PMC_IMR_MOSCSELS_Pos))
#define PMC_IMR_MOSCRCS_Pos                   _U_(17)                                              /**< (PMC_IMR) Main RC Status Interrupt Mask Position */
#define PMC_IMR_MOSCRCS_Msk                   (_U_(0x1) << PMC_IMR_MOSCRCS_Pos)                    /**< (PMC_IMR) Main RC Status Interrupt Mask Mask */
#define PMC_IMR_MOSCRCS(value)                (PMC_IMR_MOSCRCS_Msk & ((value) << PMC_IMR_MOSCRCS_Pos))
#define PMC_IMR_CFDEV_Pos                     _U_(18)                                              /**< (PMC_IMR) Clock Failure Detector Event Interrupt Mask Position */
#define PMC_IMR_CFDEV_Msk                     (_U_(0x1) << PMC_IMR_CFDEV_Pos)                      /**< (PMC_IMR) Clock Failure Detector Event Interrupt Mask Mask */
#define PMC_IMR_CFDEV(value)                  (PMC_IMR_CFDEV_Msk & ((value) << PMC_IMR_CFDEV_Pos))
#define PMC_IMR_EXT32KERR_Pos                 _U_(21)                                              /**< (PMC_IMR) 32.768 kHz Crystal Oscillator Error Interrupt Mask Position */
#define PMC_IMR_EXT32KERR_Msk                 (_U_(0x1) << PMC_IMR_EXT32KERR_Pos)                  /**< (PMC_IMR) 32.768 kHz Crystal Oscillator Error Interrupt Mask Mask */
#define PMC_IMR_EXT32KERR(value)              (PMC_IMR_EXT32KERR_Msk & ((value) << PMC_IMR_EXT32KERR_Pos))
#define PMC_IMR_CPUMON_Pos                    _U_(23)                                              /**< (PMC_IMR) CPU Clock Monitor Error Interrupt Mask Position */
#define PMC_IMR_CPUMON_Msk                    (_U_(0x1) << PMC_IMR_CPUMON_Pos)                     /**< (PMC_IMR) CPU Clock Monitor Error Interrupt Mask Mask */
#define PMC_IMR_CPUMON(value)                 (PMC_IMR_CPUMON_Msk & ((value) << PMC_IMR_CPUMON_Pos))
#define PMC_IMR_Msk                           _U_(0x00A70F0F)                                      /**< (PMC_IMR) Register Mask  */

#define PMC_IMR_PCKRDY_Pos                    _U_(8)                                               /**< (PMC_IMR Position) Programmable Clock Ready x Interrupt Mask */
#define PMC_IMR_PCKRDY_Msk                    (_U_(0xF) << PMC_IMR_PCKRDY_Pos)                     /**< (PMC_IMR Mask) PCKRDY */
#define PMC_IMR_PCKRDY(value)                 (PMC_IMR_PCKRDY_Msk & ((value) << PMC_IMR_PCKRDY_Pos)) 

/* -------- PMC_FOCR : (PMC Offset: 0x78) ( /W 32) Fault Output Clear Register -------- */
#define PMC_FOCR_FOCLR_Pos                    _U_(0)                                               /**< (PMC_FOCR) Fault Output Clear Position */
#define PMC_FOCR_FOCLR_Msk                    (_U_(0x1) << PMC_FOCR_FOCLR_Pos)                     /**< (PMC_FOCR) Fault Output Clear Mask */
#define PMC_FOCR_FOCLR(value)                 (PMC_FOCR_FOCLR_Msk & ((value) << PMC_FOCR_FOCLR_Pos))
#define PMC_FOCR_Msk                          _U_(0x00000001)                                      /**< (PMC_FOCR) Register Mask  */


/* -------- PMC_PLL_CFG : (PMC Offset: 0x80) (R/W 32) PLL Configuration Register -------- */
#define PMC_PLL_CFG_OUTCUR_PLLA_Pos           _U_(0)                                               /**< (PMC_PLL_CFG) PLLA Output Current Position */
#define PMC_PLL_CFG_OUTCUR_PLLA_Msk           (_U_(0xF) << PMC_PLL_CFG_OUTCUR_PLLA_Pos)            /**< (PMC_PLL_CFG) PLLA Output Current Mask */
#define PMC_PLL_CFG_OUTCUR_PLLA(value)        (PMC_PLL_CFG_OUTCUR_PLLA_Msk & ((value) << PMC_PLL_CFG_OUTCUR_PLLA_Pos))
#define   PMC_PLL_CFG_OUTCUR_PLLA_ICP0_Val    _U_(0x0)                                             /**< (PMC_PLL_CFG) 0.5 mA  */
#define   PMC_PLL_CFG_OUTCUR_PLLA_ICP1_Val    _U_(0x1)                                             /**< (PMC_PLL_CFG) 0.75 mA  */
#define   PMC_PLL_CFG_OUTCUR_PLLA_ICP2_Val    _U_(0x2)                                             /**< (PMC_PLL_CFG) 1 mA  */
#define   PMC_PLL_CFG_OUTCUR_PLLA_ICP3_Val    _U_(0x3)                                             /**< (PMC_PLL_CFG) 1.25 mA  */
#define PMC_PLL_CFG_OUTCUR_PLLA_ICP0          (PMC_PLL_CFG_OUTCUR_PLLA_ICP0_Val << PMC_PLL_CFG_OUTCUR_PLLA_Pos) /**< (PMC_PLL_CFG) 0.5 mA Position  */
#define PMC_PLL_CFG_OUTCUR_PLLA_ICP1          (PMC_PLL_CFG_OUTCUR_PLLA_ICP1_Val << PMC_PLL_CFG_OUTCUR_PLLA_Pos) /**< (PMC_PLL_CFG) 0.75 mA Position  */
#define PMC_PLL_CFG_OUTCUR_PLLA_ICP2          (PMC_PLL_CFG_OUTCUR_PLLA_ICP2_Val << PMC_PLL_CFG_OUTCUR_PLLA_Pos) /**< (PMC_PLL_CFG) 1 mA Position  */
#define PMC_PLL_CFG_OUTCUR_PLLA_ICP3          (PMC_PLL_CFG_OUTCUR_PLLA_ICP3_Val << PMC_PLL_CFG_OUTCUR_PLLA_Pos) /**< (PMC_PLL_CFG) 1.25 mA Position  */
#define PMC_PLL_CFG_SCA_Pos                   _U_(12)                                              /**< (PMC_PLL_CFG) Internal Filter PLL - Select Internal Capaticance Value Position */
#define PMC_PLL_CFG_SCA_Msk                   (_U_(0x3) << PMC_PLL_CFG_SCA_Pos)                    /**< (PMC_PLL_CFG) Internal Filter PLL - Select Internal Capaticance Value Mask */
#define PMC_PLL_CFG_SCA(value)                (PMC_PLL_CFG_SCA_Msk & ((value) << PMC_PLL_CFG_SCA_Pos))
#define   PMC_PLL_CFG_SCA_SC_VAL_20p_Val      _U_(0x0)                                             /**< (PMC_PLL_CFG) 20 pF  */
#define   PMC_PLL_CFG_SCA_SC_VAL_40p_Val      _U_(0x1)                                             /**< (PMC_PLL_CFG) 40 pF  */
#define   PMC_PLL_CFG_SCA_SC_VAL_30p_Val      _U_(0x2)                                             /**< (PMC_PLL_CFG) 30 pF  */
#define   PMC_PLL_CFG_SCA_SC_VAL_60p_Val      _U_(0x3)                                             /**< (PMC_PLL_CFG) 60 pF  */
#define PMC_PLL_CFG_SCA_SC_VAL_20p            (PMC_PLL_CFG_SCA_SC_VAL_20p_Val << PMC_PLL_CFG_SCA_Pos) /**< (PMC_PLL_CFG) 20 pF Position  */
#define PMC_PLL_CFG_SCA_SC_VAL_40p            (PMC_PLL_CFG_SCA_SC_VAL_40p_Val << PMC_PLL_CFG_SCA_Pos) /**< (PMC_PLL_CFG) 40 pF Position  */
#define PMC_PLL_CFG_SCA_SC_VAL_30p            (PMC_PLL_CFG_SCA_SC_VAL_30p_Val << PMC_PLL_CFG_SCA_Pos) /**< (PMC_PLL_CFG) 30 pF Position  */
#define PMC_PLL_CFG_SCA_SC_VAL_60p            (PMC_PLL_CFG_SCA_SC_VAL_60p_Val << PMC_PLL_CFG_SCA_Pos) /**< (PMC_PLL_CFG) 60 pF Position  */
#define PMC_PLL_CFG_SRA_Pos                   _U_(14)                                              /**< (PMC_PLL_CFG) Internal Filter PLL - Select Internal Resistor Value Position */
#define PMC_PLL_CFG_SRA_Msk                   (_U_(0x3) << PMC_PLL_CFG_SRA_Pos)                    /**< (PMC_PLL_CFG) Internal Filter PLL - Select Internal Resistor Value Mask */
#define PMC_PLL_CFG_SRA(value)                (PMC_PLL_CFG_SRA_Msk & ((value) << PMC_PLL_CFG_SRA_Pos))
#define   PMC_PLL_CFG_SRA_SR_VAL_24K_Val      _U_(0x0)                                             /**< (PMC_PLL_CFG) 24 Ohms  */
#define   PMC_PLL_CFG_SRA_SR_VAL_6K_Val       _U_(0x1)                                             /**< (PMC_PLL_CFG) 6 Ohms  */
#define   PMC_PLL_CFG_SRA_SR_VAL_3K_Val       _U_(0x2)                                             /**< (PMC_PLL_CFG) 3 Ohms  */
#define   PMC_PLL_CFG_SRA_SR_VAL_12K_Val      _U_(0x3)                                             /**< (PMC_PLL_CFG) 12 Ohms  */
#define PMC_PLL_CFG_SRA_SR_VAL_24K            (PMC_PLL_CFG_SRA_SR_VAL_24K_Val << PMC_PLL_CFG_SRA_Pos) /**< (PMC_PLL_CFG) 24 Ohms Position  */
#define PMC_PLL_CFG_SRA_SR_VAL_6K             (PMC_PLL_CFG_SRA_SR_VAL_6K_Val << PMC_PLL_CFG_SRA_Pos) /**< (PMC_PLL_CFG) 6 Ohms Position  */
#define PMC_PLL_CFG_SRA_SR_VAL_3K             (PMC_PLL_CFG_SRA_SR_VAL_3K_Val << PMC_PLL_CFG_SRA_Pos) /**< (PMC_PLL_CFG) 3 Ohms Position  */
#define PMC_PLL_CFG_SRA_SR_VAL_12K            (PMC_PLL_CFG_SRA_SR_VAL_12K_Val << PMC_PLL_CFG_SRA_Pos) /**< (PMC_PLL_CFG) 12 Ohms Position  */
#define PMC_PLL_CFG_OUTCUR_PLLB_Pos           _U_(16)                                              /**< (PMC_PLL_CFG) PLLB Output Current Position */
#define PMC_PLL_CFG_OUTCUR_PLLB_Msk           (_U_(0xF) << PMC_PLL_CFG_OUTCUR_PLLB_Pos)            /**< (PMC_PLL_CFG) PLLB Output Current Mask */
#define PMC_PLL_CFG_OUTCUR_PLLB(value)        (PMC_PLL_CFG_OUTCUR_PLLB_Msk & ((value) << PMC_PLL_CFG_OUTCUR_PLLB_Pos))
#define   PMC_PLL_CFG_OUTCUR_PLLB_ICP0_Val    _U_(0x0)                                             /**< (PMC_PLL_CFG) 0.5 mA  */
#define   PMC_PLL_CFG_OUTCUR_PLLB_ICP1_Val    _U_(0x1)                                             /**< (PMC_PLL_CFG) 0.75 mA  */
#define   PMC_PLL_CFG_OUTCUR_PLLB_ICP2_Val    _U_(0x2)                                             /**< (PMC_PLL_CFG) 1 mA  */
#define   PMC_PLL_CFG_OUTCUR_PLLB_ICP3_Val    _U_(0x3)                                             /**< (PMC_PLL_CFG) 1.25 mA  */
#define PMC_PLL_CFG_OUTCUR_PLLB_ICP0          (PMC_PLL_CFG_OUTCUR_PLLB_ICP0_Val << PMC_PLL_CFG_OUTCUR_PLLB_Pos) /**< (PMC_PLL_CFG) 0.5 mA Position  */
#define PMC_PLL_CFG_OUTCUR_PLLB_ICP1          (PMC_PLL_CFG_OUTCUR_PLLB_ICP1_Val << PMC_PLL_CFG_OUTCUR_PLLB_Pos) /**< (PMC_PLL_CFG) 0.75 mA Position  */
#define PMC_PLL_CFG_OUTCUR_PLLB_ICP2          (PMC_PLL_CFG_OUTCUR_PLLB_ICP2_Val << PMC_PLL_CFG_OUTCUR_PLLB_Pos) /**< (PMC_PLL_CFG) 1 mA Position  */
#define PMC_PLL_CFG_OUTCUR_PLLB_ICP3          (PMC_PLL_CFG_OUTCUR_PLLB_ICP3_Val << PMC_PLL_CFG_OUTCUR_PLLB_Pos) /**< (PMC_PLL_CFG) 1.25 mA Position  */
#define PMC_PLL_CFG_SCB_Pos                   _U_(28)                                              /**< (PMC_PLL_CFG) Internal Filter PLL - Select Internal Capaticance Value Position */
#define PMC_PLL_CFG_SCB_Msk                   (_U_(0x3) << PMC_PLL_CFG_SCB_Pos)                    /**< (PMC_PLL_CFG) Internal Filter PLL - Select Internal Capaticance Value Mask */
#define PMC_PLL_CFG_SCB(value)                (PMC_PLL_CFG_SCB_Msk & ((value) << PMC_PLL_CFG_SCB_Pos))
#define   PMC_PLL_CFG_SCB_SC_VAL_20p_Val      _U_(0x0)                                             /**< (PMC_PLL_CFG) 20 pF  */
#define   PMC_PLL_CFG_SCB_SC_VAL_40p_Val      _U_(0x1)                                             /**< (PMC_PLL_CFG) 40 pF  */
#define   PMC_PLL_CFG_SCB_SC_VAL_30p_Val      _U_(0x2)                                             /**< (PMC_PLL_CFG) 30 pF  */
#define   PMC_PLL_CFG_SCB_SC_VAL_60p_Val      _U_(0x3)                                             /**< (PMC_PLL_CFG) 60 pF  */
#define PMC_PLL_CFG_SCB_SC_VAL_20p            (PMC_PLL_CFG_SCB_SC_VAL_20p_Val << PMC_PLL_CFG_SCB_Pos) /**< (PMC_PLL_CFG) 20 pF Position  */
#define PMC_PLL_CFG_SCB_SC_VAL_40p            (PMC_PLL_CFG_SCB_SC_VAL_40p_Val << PMC_PLL_CFG_SCB_Pos) /**< (PMC_PLL_CFG) 40 pF Position  */
#define PMC_PLL_CFG_SCB_SC_VAL_30p            (PMC_PLL_CFG_SCB_SC_VAL_30p_Val << PMC_PLL_CFG_SCB_Pos) /**< (PMC_PLL_CFG) 30 pF Position  */
#define PMC_PLL_CFG_SCB_SC_VAL_60p            (PMC_PLL_CFG_SCB_SC_VAL_60p_Val << PMC_PLL_CFG_SCB_Pos) /**< (PMC_PLL_CFG) 60 pF Position  */
#define PMC_PLL_CFG_SRB_Pos                   _U_(30)                                              /**< (PMC_PLL_CFG) Internal Filter PLL - Select Internal Resistor Value Position */
#define PMC_PLL_CFG_SRB_Msk                   (_U_(0x3) << PMC_PLL_CFG_SRB_Pos)                    /**< (PMC_PLL_CFG) Internal Filter PLL - Select Internal Resistor Value Mask */
#define PMC_PLL_CFG_SRB(value)                (PMC_PLL_CFG_SRB_Msk & ((value) << PMC_PLL_CFG_SRB_Pos))
#define   PMC_PLL_CFG_SRB_SR_VAL_24K_Val      _U_(0x0)                                             /**< (PMC_PLL_CFG) 24 Ohms  */
#define   PMC_PLL_CFG_SRB_SR_VAL_6K_Val       _U_(0x1)                                             /**< (PMC_PLL_CFG) 6 Ohms  */
#define   PMC_PLL_CFG_SRB_SR_VAL_3K_Val       _U_(0x2)                                             /**< (PMC_PLL_CFG) 3 Ohms  */
#define   PMC_PLL_CFG_SRB_SR_VAL_12K_Val      _U_(0x3)                                             /**< (PMC_PLL_CFG) 12 Ohms  */
#define PMC_PLL_CFG_SRB_SR_VAL_24K            (PMC_PLL_CFG_SRB_SR_VAL_24K_Val << PMC_PLL_CFG_SRB_Pos) /**< (PMC_PLL_CFG) 24 Ohms Position  */
#define PMC_PLL_CFG_SRB_SR_VAL_6K             (PMC_PLL_CFG_SRB_SR_VAL_6K_Val << PMC_PLL_CFG_SRB_Pos) /**< (PMC_PLL_CFG) 6 Ohms Position  */
#define PMC_PLL_CFG_SRB_SR_VAL_3K             (PMC_PLL_CFG_SRB_SR_VAL_3K_Val << PMC_PLL_CFG_SRB_Pos) /**< (PMC_PLL_CFG) 3 Ohms Position  */
#define PMC_PLL_CFG_SRB_SR_VAL_12K            (PMC_PLL_CFG_SRB_SR_VAL_12K_Val << PMC_PLL_CFG_SRB_Pos) /**< (PMC_PLL_CFG) 12 Ohms Position  */
#define PMC_PLL_CFG_Msk                       _U_(0xF00FF00F)                                      /**< (PMC_PLL_CFG) Register Mask  */


/* -------- PMC_WPMR : (PMC Offset: 0xE4) (R/W 32) Write Protection Mode Register -------- */
#define PMC_WPMR_WPEN_Pos                     _U_(0)                                               /**< (PMC_WPMR) Write Protection Enable Position */
#define PMC_WPMR_WPEN_Msk                     (_U_(0x1) << PMC_WPMR_WPEN_Pos)                      /**< (PMC_WPMR) Write Protection Enable Mask */
#define PMC_WPMR_WPEN(value)                  (PMC_WPMR_WPEN_Msk & ((value) << PMC_WPMR_WPEN_Pos))
#define PMC_WPMR_WPITEN_Pos                   _U_(1)                                               /**< (PMC_WPMR) Write Protection Interrupt Enable Position */
#define PMC_WPMR_WPITEN_Msk                   (_U_(0x1) << PMC_WPMR_WPITEN_Pos)                    /**< (PMC_WPMR) Write Protection Interrupt Enable Mask */
#define PMC_WPMR_WPITEN(value)                (PMC_WPMR_WPITEN_Msk & ((value) << PMC_WPMR_WPITEN_Pos))
#define PMC_WPMR_WPKEY_Pos                    _U_(8)                                               /**< (PMC_WPMR) Write Protection Key Position */
#define PMC_WPMR_WPKEY_Msk                    (_U_(0xFFFFFF) << PMC_WPMR_WPKEY_Pos)                /**< (PMC_WPMR) Write Protection Key Mask */
#define PMC_WPMR_WPKEY(value)                 (PMC_WPMR_WPKEY_Msk & ((value) << PMC_WPMR_WPKEY_Pos))
#define   PMC_WPMR_WPKEY_PASSWD_Val           _U_(0x504D43)                                        /**< (PMC_WPMR) Writing any other value in this field aborts the write operation of the WPEN bit. Always reads as 0.  */
#define PMC_WPMR_WPKEY_PASSWD                 (PMC_WPMR_WPKEY_PASSWD_Val << PMC_WPMR_WPKEY_Pos)    /**< (PMC_WPMR) Writing any other value in this field aborts the write operation of the WPEN bit. Always reads as 0. Position  */
#define PMC_WPMR_Msk                          _U_(0xFFFFFF03)                                      /**< (PMC_WPMR) Register Mask  */


/* -------- PMC_WPSR : (PMC Offset: 0xE8) ( R/ 32) Write Protection Status Register -------- */
#define PMC_WPSR_WPVS_Pos                     _U_(0)                                               /**< (PMC_WPSR) Write Protection Violation Status Position */
#define PMC_WPSR_WPVS_Msk                     (_U_(0x1) << PMC_WPSR_WPVS_Pos)                      /**< (PMC_WPSR) Write Protection Violation Status Mask */
#define PMC_WPSR_WPVS(value)                  (PMC_WPSR_WPVS_Msk & ((value) << PMC_WPSR_WPVS_Pos))
#define PMC_WPSR_WPVSRC_Pos                   _U_(8)                                               /**< (PMC_WPSR) Write Protection Violation Source Position */
#define PMC_WPSR_WPVSRC_Msk                   (_U_(0xFFFF) << PMC_WPSR_WPVSRC_Pos)                 /**< (PMC_WPSR) Write Protection Violation Source Mask */
#define PMC_WPSR_WPVSRC(value)                (PMC_WPSR_WPVSRC_Msk & ((value) << PMC_WPSR_WPVSRC_Pos))
#define PMC_WPSR_Msk                          _U_(0x00FFFF01)                                      /**< (PMC_WPSR) Register Mask  */


/* -------- PMC_PCR : (PMC Offset: 0x10C) (R/W 32) Peripheral Control Register -------- */
#define PMC_PCR_PID_Pos                       _U_(0)                                               /**< (PMC_PCR) Peripheral ID Position */
#define PMC_PCR_PID_Msk                       (_U_(0x7F) << PMC_PCR_PID_Pos)                       /**< (PMC_PCR) Peripheral ID Mask */
#define PMC_PCR_PID(value)                    (PMC_PCR_PID_Msk & ((value) << PMC_PCR_PID_Pos))    
#define PMC_PCR_GCLKCSS_Pos                   _U_(8)                                               /**< (PMC_PCR) Generic Clock Source Selection Position */
#define PMC_PCR_GCLKCSS_Msk                   (_U_(0x7) << PMC_PCR_GCLKCSS_Pos)                    /**< (PMC_PCR) Generic Clock Source Selection Mask */
#define PMC_PCR_GCLKCSS(value)                (PMC_PCR_GCLKCSS_Msk & ((value) << PMC_PCR_GCLKCSS_Pos))
#define   PMC_PCR_GCLKCSS_SLOW_CLK_Val        _U_(0x0)                                             /**< (PMC_PCR) MD_SLCK is selected  */
#define   PMC_PCR_GCLKCSS_MAIN_CLK_Val        _U_(0x1)                                             /**< (PMC_PCR) MAINCK is selected  */
#define   PMC_PCR_GCLKCSS_PLLA_CLK_Val        _U_(0x2)                                             /**< (PMC_PCR) PLLACK is selected  */
#define   PMC_PCR_GCLKCSS_PLLB_CLK_Val        _U_(0x3)                                             /**< (PMC_PCR) PLLBCK is selected  */
#define   PMC_PCR_GCLKCSS_MCK_CLK_Val         _U_(0x4)                                             /**< (PMC_PCR) MCK is selected  */
#define   PMC_PCR_GCLKCSS_MCK_RC2_Val         _U_(0x5)                                             /**< (PMC_PCR) RC2 is selected  */
#define PMC_PCR_GCLKCSS_SLOW_CLK              (PMC_PCR_GCLKCSS_SLOW_CLK_Val << PMC_PCR_GCLKCSS_Pos) /**< (PMC_PCR) MD_SLCK is selected Position  */
#define PMC_PCR_GCLKCSS_MAIN_CLK              (PMC_PCR_GCLKCSS_MAIN_CLK_Val << PMC_PCR_GCLKCSS_Pos) /**< (PMC_PCR) MAINCK is selected Position  */
#define PMC_PCR_GCLKCSS_PLLA_CLK              (PMC_PCR_GCLKCSS_PLLA_CLK_Val << PMC_PCR_GCLKCSS_Pos) /**< (PMC_PCR) PLLACK is selected Position  */
#define PMC_PCR_GCLKCSS_PLLB_CLK              (PMC_PCR_GCLKCSS_PLLB_CLK_Val << PMC_PCR_GCLKCSS_Pos) /**< (PMC_PCR) PLLBCK is selected Position  */
#define PMC_PCR_GCLKCSS_MCK_CLK               (PMC_PCR_GCLKCSS_MCK_CLK_Val << PMC_PCR_GCLKCSS_Pos) /**< (PMC_PCR) MCK is selected Position  */
#define PMC_PCR_GCLKCSS_MCK_RC2               (PMC_PCR_GCLKCSS_MCK_RC2_Val << PMC_PCR_GCLKCSS_Pos) /**< (PMC_PCR) RC2 is selected Position  */
#define PMC_PCR_CMD_Pos                       _U_(12)                                              /**< (PMC_PCR) Command Position */
#define PMC_PCR_CMD_Msk                       (_U_(0x1) << PMC_PCR_CMD_Pos)                        /**< (PMC_PCR) Command Mask */
#define PMC_PCR_CMD(value)                    (PMC_PCR_CMD_Msk & ((value) << PMC_PCR_CMD_Pos))    
#define PMC_PCR_GCLKDIV_Pos                   _U_(20)                                              /**< (PMC_PCR) Generic Clock Division Ratio Position */
#define PMC_PCR_GCLKDIV_Msk                   (_U_(0xFF) << PMC_PCR_GCLKDIV_Pos)                   /**< (PMC_PCR) Generic Clock Division Ratio Mask */
#define PMC_PCR_GCLKDIV(value)                (PMC_PCR_GCLKDIV_Msk & ((value) << PMC_PCR_GCLKDIV_Pos))
#define PMC_PCR_EN_Pos                        _U_(28)                                              /**< (PMC_PCR) Enable Position */
#define PMC_PCR_EN_Msk                        (_U_(0x1) << PMC_PCR_EN_Pos)                         /**< (PMC_PCR) Enable Mask */
#define PMC_PCR_EN(value)                     (PMC_PCR_EN_Msk & ((value) << PMC_PCR_EN_Pos))      
#define PMC_PCR_GCLKEN_Pos                    _U_(29)                                              /**< (PMC_PCR) Generic Clock Enable Position */
#define PMC_PCR_GCLKEN_Msk                    (_U_(0x1) << PMC_PCR_GCLKEN_Pos)                     /**< (PMC_PCR) Generic Clock Enable Mask */
#define PMC_PCR_GCLKEN(value)                 (PMC_PCR_GCLKEN_Msk & ((value) << PMC_PCR_GCLKEN_Pos))
#define PMC_PCR_Msk                           _U_(0x3FF0177F)                                      /**< (PMC_PCR) Register Mask  */


/* -------- PMC_OCR1 : (PMC Offset: 0x110) (R/W 32) Oscillator Calibration Register -------- */
#define PMC_OCR1_CAL4_Pos                     _U_(0)                                               /**< (PMC_OCR1) Main RC Oscillator Calibration Bits for 4 MHz Position */
#define PMC_OCR1_CAL4_Msk                     (_U_(0x7F) << PMC_OCR1_CAL4_Pos)                     /**< (PMC_OCR1) Main RC Oscillator Calibration Bits for 4 MHz Mask */
#define PMC_OCR1_CAL4(value)                  (PMC_OCR1_CAL4_Msk & ((value) << PMC_OCR1_CAL4_Pos))
#define PMC_OCR1_SEL4_Pos                     _U_(7)                                               /**< (PMC_OCR1) Selection of Main RC Oscillator Calibration Bits for 4 MHz Position */
#define PMC_OCR1_SEL4_Msk                     (_U_(0x1) << PMC_OCR1_SEL4_Pos)                      /**< (PMC_OCR1) Selection of Main RC Oscillator Calibration Bits for 4 MHz Mask */
#define PMC_OCR1_SEL4(value)                  (PMC_OCR1_SEL4_Msk & ((value) << PMC_OCR1_SEL4_Pos))
#define PMC_OCR1_CAL8_Pos                     _U_(8)                                               /**< (PMC_OCR1) Main RC Oscillator Calibration Bits for 8 MHz Position */
#define PMC_OCR1_CAL8_Msk                     (_U_(0x7F) << PMC_OCR1_CAL8_Pos)                     /**< (PMC_OCR1) Main RC Oscillator Calibration Bits for 8 MHz Mask */
#define PMC_OCR1_CAL8(value)                  (PMC_OCR1_CAL8_Msk & ((value) << PMC_OCR1_CAL8_Pos))
#define PMC_OCR1_SEL8_Pos                     _U_(15)                                              /**< (PMC_OCR1) Selection of Main RC Oscillator Calibration Bits for 8 MHz Position */
#define PMC_OCR1_SEL8_Msk                     (_U_(0x1) << PMC_OCR1_SEL8_Pos)                      /**< (PMC_OCR1) Selection of Main RC Oscillator Calibration Bits for 8 MHz Mask */
#define PMC_OCR1_SEL8(value)                  (PMC_OCR1_SEL8_Msk & ((value) << PMC_OCR1_SEL8_Pos))
#define PMC_OCR1_CAL10_Pos                    _U_(16)                                              /**< (PMC_OCR1) Main RC Oscillator Calibration Bits for 10 MHz Position */
#define PMC_OCR1_CAL10_Msk                    (_U_(0x7F) << PMC_OCR1_CAL10_Pos)                    /**< (PMC_OCR1) Main RC Oscillator Calibration Bits for 10 MHz Mask */
#define PMC_OCR1_CAL10(value)                 (PMC_OCR1_CAL10_Msk & ((value) << PMC_OCR1_CAL10_Pos))
#define PMC_OCR1_SEL10_Pos                    _U_(23)                                              /**< (PMC_OCR1) Selection of Main RC Oscillator Calibration Bits for 10 MHz Position */
#define PMC_OCR1_SEL10_Msk                    (_U_(0x1) << PMC_OCR1_SEL10_Pos)                     /**< (PMC_OCR1) Selection of Main RC Oscillator Calibration Bits for 10 MHz Mask */
#define PMC_OCR1_SEL10(value)                 (PMC_OCR1_SEL10_Msk & ((value) << PMC_OCR1_SEL10_Pos))
#define PMC_OCR1_CAL12_Pos                    _U_(24)                                              /**< (PMC_OCR1) Main RC Oscillator Calibration Bits for 12 MHz Position */
#define PMC_OCR1_CAL12_Msk                    (_U_(0x7F) << PMC_OCR1_CAL12_Pos)                    /**< (PMC_OCR1) Main RC Oscillator Calibration Bits for 12 MHz Mask */
#define PMC_OCR1_CAL12(value)                 (PMC_OCR1_CAL12_Msk & ((value) << PMC_OCR1_CAL12_Pos))
#define PMC_OCR1_SEL12_Pos                    _U_(31)                                              /**< (PMC_OCR1) Selection of Main RC Oscillator Calibration Bits for 12 MHz Position */
#define PMC_OCR1_SEL12_Msk                    (_U_(0x1) << PMC_OCR1_SEL12_Pos)                     /**< (PMC_OCR1) Selection of Main RC Oscillator Calibration Bits for 12 MHz Mask */
#define PMC_OCR1_SEL12(value)                 (PMC_OCR1_SEL12_Msk & ((value) << PMC_OCR1_SEL12_Pos))
#define PMC_OCR1_Msk                          _U_(0xFFFFFFFF)                                      /**< (PMC_OCR1) Register Mask  */


/* -------- PMC_PMMR : (PMC Offset: 0x130) (R/W 32) PLL Maximum Multiplier Value Register -------- */
#define PMC_PMMR_PLLA_MMAX_Pos                _U_(0)                                               /**< (PMC_PMMR) PLLA Maximum Allowed Multiplier Value Position */
#define PMC_PMMR_PLLA_MMAX_Msk                (_U_(0x7FF) << PMC_PMMR_PLLA_MMAX_Pos)               /**< (PMC_PMMR) PLLA Maximum Allowed Multiplier Value Mask */
#define PMC_PMMR_PLLA_MMAX(value)             (PMC_PMMR_PLLA_MMAX_Msk & ((value) << PMC_PMMR_PLLA_MMAX_Pos))
#define PMC_PMMR_PLLB_MMAX_Pos                _U_(16)                                              /**< (PMC_PMMR) PLLB Maximum Allowed Multiplier Value Position */
#define PMC_PMMR_PLLB_MMAX_Msk                (_U_(0x7FF) << PMC_PMMR_PLLB_MMAX_Pos)               /**< (PMC_PMMR) PLLB Maximum Allowed Multiplier Value Mask */
#define PMC_PMMR_PLLB_MMAX(value)             (PMC_PMMR_PLLB_MMAX_Msk & ((value) << PMC_PMMR_PLLB_MMAX_Pos))
#define PMC_PMMR_Msk                          _U_(0x07FF07FF)                                      /**< (PMC_PMMR) Register Mask  */


/* -------- PMC_CPULIM : (PMC Offset: 0x160) (R/W 32) CPU Monitor Limits Register -------- */
#define PMC_CPULIM_CPU_LOW_IT_Pos             _U_(0)                                               /**< (PMC_CPULIM) CPU Monitoring Low IT Limit Position */
#define PMC_CPULIM_CPU_LOW_IT_Msk             (_U_(0xFF) << PMC_CPULIM_CPU_LOW_IT_Pos)             /**< (PMC_CPULIM) CPU Monitoring Low IT Limit Mask */
#define PMC_CPULIM_CPU_LOW_IT(value)          (PMC_CPULIM_CPU_LOW_IT_Msk & ((value) << PMC_CPULIM_CPU_LOW_IT_Pos))
#define PMC_CPULIM_CPU_HIGH_IT_Pos            _U_(8)                                               /**< (PMC_CPULIM) CPU Monitoring High IT Limit Position */
#define PMC_CPULIM_CPU_HIGH_IT_Msk            (_U_(0xFF) << PMC_CPULIM_CPU_HIGH_IT_Pos)            /**< (PMC_CPULIM) CPU Monitoring High IT Limit Mask */
#define PMC_CPULIM_CPU_HIGH_IT(value)         (PMC_CPULIM_CPU_HIGH_IT_Msk & ((value) << PMC_CPULIM_CPU_HIGH_IT_Pos))
#define PMC_CPULIM_CPU_LOW_RES_Pos            _U_(16)                                              /**< (PMC_CPULIM) CPU Monitoring Low RESET Limit Position */
#define PMC_CPULIM_CPU_LOW_RES_Msk            (_U_(0xFF) << PMC_CPULIM_CPU_LOW_RES_Pos)            /**< (PMC_CPULIM) CPU Monitoring Low RESET Limit Mask */
#define PMC_CPULIM_CPU_LOW_RES(value)         (PMC_CPULIM_CPU_LOW_RES_Msk & ((value) << PMC_CPULIM_CPU_LOW_RES_Pos))
#define PMC_CPULIM_CPU_HIGH_RES_Pos           _U_(24)                                              /**< (PMC_CPULIM) CPU Monitoring High Reset Limit Position */
#define PMC_CPULIM_CPU_HIGH_RES_Msk           (_U_(0xFF) << PMC_CPULIM_CPU_HIGH_RES_Pos)           /**< (PMC_CPULIM) CPU Monitoring High Reset Limit Mask */
#define PMC_CPULIM_CPU_HIGH_RES(value)        (PMC_CPULIM_CPU_HIGH_RES_Msk & ((value) << PMC_CPULIM_CPU_HIGH_RES_Pos))
#define PMC_CPULIM_Msk                        _U_(0xFFFFFFFF)                                      /**< (PMC_CPULIM) Register Mask  */


/* -------- PMC_CSR0 : (PMC Offset: 0x170) ( R/ 32) Peripheral Clock Status Register 0 -------- */
#define PMC_CSR0_PID0_Pos                     _U_(0)                                               /**< (PMC_CSR0) Peripheral Clock 0 Status Position */
#define PMC_CSR0_PID0_Msk                     (_U_(0x1) << PMC_CSR0_PID0_Pos)                      /**< (PMC_CSR0) Peripheral Clock 0 Status Mask */
#define PMC_CSR0_PID0(value)                  (PMC_CSR0_PID0_Msk & ((value) << PMC_CSR0_PID0_Pos))
#define PMC_CSR0_PID1_Pos                     _U_(1)                                               /**< (PMC_CSR0) Peripheral Clock 1 Status Position */
#define PMC_CSR0_PID1_Msk                     (_U_(0x1) << PMC_CSR0_PID1_Pos)                      /**< (PMC_CSR0) Peripheral Clock 1 Status Mask */
#define PMC_CSR0_PID1(value)                  (PMC_CSR0_PID1_Msk & ((value) << PMC_CSR0_PID1_Pos))
#define PMC_CSR0_PID2_Pos                     _U_(2)                                               /**< (PMC_CSR0) Peripheral Clock 2 Status Position */
#define PMC_CSR0_PID2_Msk                     (_U_(0x1) << PMC_CSR0_PID2_Pos)                      /**< (PMC_CSR0) Peripheral Clock 2 Status Mask */
#define PMC_CSR0_PID2(value)                  (PMC_CSR0_PID2_Msk & ((value) << PMC_CSR0_PID2_Pos))
#define PMC_CSR0_PID3_Pos                     _U_(3)                                               /**< (PMC_CSR0) Peripheral Clock 3 Status Position */
#define PMC_CSR0_PID3_Msk                     (_U_(0x1) << PMC_CSR0_PID3_Pos)                      /**< (PMC_CSR0) Peripheral Clock 3 Status Mask */
#define PMC_CSR0_PID3(value)                  (PMC_CSR0_PID3_Msk & ((value) << PMC_CSR0_PID3_Pos))
#define PMC_CSR0_PID4_Pos                     _U_(4)                                               /**< (PMC_CSR0) Peripheral Clock 4 Status Position */
#define PMC_CSR0_PID4_Msk                     (_U_(0x1) << PMC_CSR0_PID4_Pos)                      /**< (PMC_CSR0) Peripheral Clock 4 Status Mask */
#define PMC_CSR0_PID4(value)                  (PMC_CSR0_PID4_Msk & ((value) << PMC_CSR0_PID4_Pos))
#define PMC_CSR0_PID5_Pos                     _U_(5)                                               /**< (PMC_CSR0) Peripheral Clock 5 Status Position */
#define PMC_CSR0_PID5_Msk                     (_U_(0x1) << PMC_CSR0_PID5_Pos)                      /**< (PMC_CSR0) Peripheral Clock 5 Status Mask */
#define PMC_CSR0_PID5(value)                  (PMC_CSR0_PID5_Msk & ((value) << PMC_CSR0_PID5_Pos))
#define PMC_CSR0_PID6_Pos                     _U_(6)                                               /**< (PMC_CSR0) Peripheral Clock 6 Status Position */
#define PMC_CSR0_PID6_Msk                     (_U_(0x1) << PMC_CSR0_PID6_Pos)                      /**< (PMC_CSR0) Peripheral Clock 6 Status Mask */
#define PMC_CSR0_PID6(value)                  (PMC_CSR0_PID6_Msk & ((value) << PMC_CSR0_PID6_Pos))
#define PMC_CSR0_PID7_Pos                     _U_(7)                                               /**< (PMC_CSR0) Peripheral Clock 7 Status Position */
#define PMC_CSR0_PID7_Msk                     (_U_(0x1) << PMC_CSR0_PID7_Pos)                      /**< (PMC_CSR0) Peripheral Clock 7 Status Mask */
#define PMC_CSR0_PID7(value)                  (PMC_CSR0_PID7_Msk & ((value) << PMC_CSR0_PID7_Pos))
#define PMC_CSR0_PID8_Pos                     _U_(8)                                               /**< (PMC_CSR0) Peripheral Clock 8 Status Position */
#define PMC_CSR0_PID8_Msk                     (_U_(0x1) << PMC_CSR0_PID8_Pos)                      /**< (PMC_CSR0) Peripheral Clock 8 Status Mask */
#define PMC_CSR0_PID8(value)                  (PMC_CSR0_PID8_Msk & ((value) << PMC_CSR0_PID8_Pos))
#define PMC_CSR0_PID9_Pos                     _U_(9)                                               /**< (PMC_CSR0) Peripheral Clock 9 Status Position */
#define PMC_CSR0_PID9_Msk                     (_U_(0x1) << PMC_CSR0_PID9_Pos)                      /**< (PMC_CSR0) Peripheral Clock 9 Status Mask */
#define PMC_CSR0_PID9(value)                  (PMC_CSR0_PID9_Msk & ((value) << PMC_CSR0_PID9_Pos))
#define PMC_CSR0_PID10_Pos                    _U_(10)                                              /**< (PMC_CSR0) Peripheral Clock 10 Status Position */
#define PMC_CSR0_PID10_Msk                    (_U_(0x1) << PMC_CSR0_PID10_Pos)                     /**< (PMC_CSR0) Peripheral Clock 10 Status Mask */
#define PMC_CSR0_PID10(value)                 (PMC_CSR0_PID10_Msk & ((value) << PMC_CSR0_PID10_Pos))
#define PMC_CSR0_PID11_Pos                    _U_(11)                                              /**< (PMC_CSR0) Peripheral Clock 11 Status Position */
#define PMC_CSR0_PID11_Msk                    (_U_(0x1) << PMC_CSR0_PID11_Pos)                     /**< (PMC_CSR0) Peripheral Clock 11 Status Mask */
#define PMC_CSR0_PID11(value)                 (PMC_CSR0_PID11_Msk & ((value) << PMC_CSR0_PID11_Pos))
#define PMC_CSR0_PID12_Pos                    _U_(12)                                              /**< (PMC_CSR0) Peripheral Clock 12 Status Position */
#define PMC_CSR0_PID12_Msk                    (_U_(0x1) << PMC_CSR0_PID12_Pos)                     /**< (PMC_CSR0) Peripheral Clock 12 Status Mask */
#define PMC_CSR0_PID12(value)                 (PMC_CSR0_PID12_Msk & ((value) << PMC_CSR0_PID12_Pos))
#define PMC_CSR0_PID13_Pos                    _U_(13)                                              /**< (PMC_CSR0) Peripheral Clock 13 Status Position */
#define PMC_CSR0_PID13_Msk                    (_U_(0x1) << PMC_CSR0_PID13_Pos)                     /**< (PMC_CSR0) Peripheral Clock 13 Status Mask */
#define PMC_CSR0_PID13(value)                 (PMC_CSR0_PID13_Msk & ((value) << PMC_CSR0_PID13_Pos))
#define PMC_CSR0_PID14_Pos                    _U_(14)                                              /**< (PMC_CSR0) Peripheral Clock 14 Status Position */
#define PMC_CSR0_PID14_Msk                    (_U_(0x1) << PMC_CSR0_PID14_Pos)                     /**< (PMC_CSR0) Peripheral Clock 14 Status Mask */
#define PMC_CSR0_PID14(value)                 (PMC_CSR0_PID14_Msk & ((value) << PMC_CSR0_PID14_Pos))
#define PMC_CSR0_PID15_Pos                    _U_(15)                                              /**< (PMC_CSR0) Peripheral Clock 15 Status Position */
#define PMC_CSR0_PID15_Msk                    (_U_(0x1) << PMC_CSR0_PID15_Pos)                     /**< (PMC_CSR0) Peripheral Clock 15 Status Mask */
#define PMC_CSR0_PID15(value)                 (PMC_CSR0_PID15_Msk & ((value) << PMC_CSR0_PID15_Pos))
#define PMC_CSR0_PID16_Pos                    _U_(16)                                              /**< (PMC_CSR0) Peripheral Clock 16 Status Position */
#define PMC_CSR0_PID16_Msk                    (_U_(0x1) << PMC_CSR0_PID16_Pos)                     /**< (PMC_CSR0) Peripheral Clock 16 Status Mask */
#define PMC_CSR0_PID16(value)                 (PMC_CSR0_PID16_Msk & ((value) << PMC_CSR0_PID16_Pos))
#define PMC_CSR0_PID17_Pos                    _U_(17)                                              /**< (PMC_CSR0) Peripheral Clock 17 Status Position */
#define PMC_CSR0_PID17_Msk                    (_U_(0x1) << PMC_CSR0_PID17_Pos)                     /**< (PMC_CSR0) Peripheral Clock 17 Status Mask */
#define PMC_CSR0_PID17(value)                 (PMC_CSR0_PID17_Msk & ((value) << PMC_CSR0_PID17_Pos))
#define PMC_CSR0_PID18_Pos                    _U_(18)                                              /**< (PMC_CSR0) Peripheral Clock 18 Status Position */
#define PMC_CSR0_PID18_Msk                    (_U_(0x1) << PMC_CSR0_PID18_Pos)                     /**< (PMC_CSR0) Peripheral Clock 18 Status Mask */
#define PMC_CSR0_PID18(value)                 (PMC_CSR0_PID18_Msk & ((value) << PMC_CSR0_PID18_Pos))
#define PMC_CSR0_PID19_Pos                    _U_(19)                                              /**< (PMC_CSR0) Peripheral Clock 19 Status Position */
#define PMC_CSR0_PID19_Msk                    (_U_(0x1) << PMC_CSR0_PID19_Pos)                     /**< (PMC_CSR0) Peripheral Clock 19 Status Mask */
#define PMC_CSR0_PID19(value)                 (PMC_CSR0_PID19_Msk & ((value) << PMC_CSR0_PID19_Pos))
#define PMC_CSR0_PID20_Pos                    _U_(20)                                              /**< (PMC_CSR0) Peripheral Clock 20 Status Position */
#define PMC_CSR0_PID20_Msk                    (_U_(0x1) << PMC_CSR0_PID20_Pos)                     /**< (PMC_CSR0) Peripheral Clock 20 Status Mask */
#define PMC_CSR0_PID20(value)                 (PMC_CSR0_PID20_Msk & ((value) << PMC_CSR0_PID20_Pos))
#define PMC_CSR0_PID21_Pos                    _U_(21)                                              /**< (PMC_CSR0) Peripheral Clock 21 Status Position */
#define PMC_CSR0_PID21_Msk                    (_U_(0x1) << PMC_CSR0_PID21_Pos)                     /**< (PMC_CSR0) Peripheral Clock 21 Status Mask */
#define PMC_CSR0_PID21(value)                 (PMC_CSR0_PID21_Msk & ((value) << PMC_CSR0_PID21_Pos))
#define PMC_CSR0_PID22_Pos                    _U_(22)                                              /**< (PMC_CSR0) Peripheral Clock 22 Status Position */
#define PMC_CSR0_PID22_Msk                    (_U_(0x1) << PMC_CSR0_PID22_Pos)                     /**< (PMC_CSR0) Peripheral Clock 22 Status Mask */
#define PMC_CSR0_PID22(value)                 (PMC_CSR0_PID22_Msk & ((value) << PMC_CSR0_PID22_Pos))
#define PMC_CSR0_PID23_Pos                    _U_(23)                                              /**< (PMC_CSR0) Peripheral Clock 23 Status Position */
#define PMC_CSR0_PID23_Msk                    (_U_(0x1) << PMC_CSR0_PID23_Pos)                     /**< (PMC_CSR0) Peripheral Clock 23 Status Mask */
#define PMC_CSR0_PID23(value)                 (PMC_CSR0_PID23_Msk & ((value) << PMC_CSR0_PID23_Pos))
#define PMC_CSR0_PID24_Pos                    _U_(24)                                              /**< (PMC_CSR0) Peripheral Clock 24 Status Position */
#define PMC_CSR0_PID24_Msk                    (_U_(0x1) << PMC_CSR0_PID24_Pos)                     /**< (PMC_CSR0) Peripheral Clock 24 Status Mask */
#define PMC_CSR0_PID24(value)                 (PMC_CSR0_PID24_Msk & ((value) << PMC_CSR0_PID24_Pos))
#define PMC_CSR0_PID25_Pos                    _U_(25)                                              /**< (PMC_CSR0) Peripheral Clock 25 Status Position */
#define PMC_CSR0_PID25_Msk                    (_U_(0x1) << PMC_CSR0_PID25_Pos)                     /**< (PMC_CSR0) Peripheral Clock 25 Status Mask */
#define PMC_CSR0_PID25(value)                 (PMC_CSR0_PID25_Msk & ((value) << PMC_CSR0_PID25_Pos))
#define PMC_CSR0_PID26_Pos                    _U_(26)                                              /**< (PMC_CSR0) Peripheral Clock 26 Status Position */
#define PMC_CSR0_PID26_Msk                    (_U_(0x1) << PMC_CSR0_PID26_Pos)                     /**< (PMC_CSR0) Peripheral Clock 26 Status Mask */
#define PMC_CSR0_PID26(value)                 (PMC_CSR0_PID26_Msk & ((value) << PMC_CSR0_PID26_Pos))
#define PMC_CSR0_PID27_Pos                    _U_(27)                                              /**< (PMC_CSR0) Peripheral Clock 27 Status Position */
#define PMC_CSR0_PID27_Msk                    (_U_(0x1) << PMC_CSR0_PID27_Pos)                     /**< (PMC_CSR0) Peripheral Clock 27 Status Mask */
#define PMC_CSR0_PID27(value)                 (PMC_CSR0_PID27_Msk & ((value) << PMC_CSR0_PID27_Pos))
#define PMC_CSR0_PID28_Pos                    _U_(28)                                              /**< (PMC_CSR0) Peripheral Clock 28 Status Position */
#define PMC_CSR0_PID28_Msk                    (_U_(0x1) << PMC_CSR0_PID28_Pos)                     /**< (PMC_CSR0) Peripheral Clock 28 Status Mask */
#define PMC_CSR0_PID28(value)                 (PMC_CSR0_PID28_Msk & ((value) << PMC_CSR0_PID28_Pos))
#define PMC_CSR0_PID29_Pos                    _U_(29)                                              /**< (PMC_CSR0) Peripheral Clock 29 Status Position */
#define PMC_CSR0_PID29_Msk                    (_U_(0x1) << PMC_CSR0_PID29_Pos)                     /**< (PMC_CSR0) Peripheral Clock 29 Status Mask */
#define PMC_CSR0_PID29(value)                 (PMC_CSR0_PID29_Msk & ((value) << PMC_CSR0_PID29_Pos))
#define PMC_CSR0_PID30_Pos                    _U_(30)                                              /**< (PMC_CSR0) Peripheral Clock 30 Status Position */
#define PMC_CSR0_PID30_Msk                    (_U_(0x1) << PMC_CSR0_PID30_Pos)                     /**< (PMC_CSR0) Peripheral Clock 30 Status Mask */
#define PMC_CSR0_PID30(value)                 (PMC_CSR0_PID30_Msk & ((value) << PMC_CSR0_PID30_Pos))
#define PMC_CSR0_PID31_Pos                    _U_(31)                                              /**< (PMC_CSR0) Peripheral Clock 31 Status Position */
#define PMC_CSR0_PID31_Msk                    (_U_(0x1) << PMC_CSR0_PID31_Pos)                     /**< (PMC_CSR0) Peripheral Clock 31 Status Mask */
#define PMC_CSR0_PID31(value)                 (PMC_CSR0_PID31_Msk & ((value) << PMC_CSR0_PID31_Pos))
#define PMC_CSR0_Msk                          _U_(0xFFFFFFFF)                                      /**< (PMC_CSR0) Register Mask  */

#define PMC_CSR0_PID_Pos                      _U_(0)                                               /**< (PMC_CSR0 Position) Peripheral Clock 3x Status */
#define PMC_CSR0_PID_Msk                      (_U_(0xFFFFFFFF) << PMC_CSR0_PID_Pos)                /**< (PMC_CSR0 Mask) PID */
#define PMC_CSR0_PID(value)                   (PMC_CSR0_PID_Msk & ((value) << PMC_CSR0_PID_Pos))   

/* -------- PMC_CSR1 : (PMC Offset: 0x174) ( R/ 32) Peripheral Clock Status Register 1 -------- */
#define PMC_CSR1_PID32_Pos                    _U_(0)                                               /**< (PMC_CSR1) Peripheral Clock 32 Status Position */
#define PMC_CSR1_PID32_Msk                    (_U_(0x1) << PMC_CSR1_PID32_Pos)                     /**< (PMC_CSR1) Peripheral Clock 32 Status Mask */
#define PMC_CSR1_PID32(value)                 (PMC_CSR1_PID32_Msk & ((value) << PMC_CSR1_PID32_Pos))
#define PMC_CSR1_PID33_Pos                    _U_(1)                                               /**< (PMC_CSR1) Peripheral Clock 33 Status Position */
#define PMC_CSR1_PID33_Msk                    (_U_(0x1) << PMC_CSR1_PID33_Pos)                     /**< (PMC_CSR1) Peripheral Clock 33 Status Mask */
#define PMC_CSR1_PID33(value)                 (PMC_CSR1_PID33_Msk & ((value) << PMC_CSR1_PID33_Pos))
#define PMC_CSR1_PID34_Pos                    _U_(2)                                               /**< (PMC_CSR1) Peripheral Clock 34 Status Position */
#define PMC_CSR1_PID34_Msk                    (_U_(0x1) << PMC_CSR1_PID34_Pos)                     /**< (PMC_CSR1) Peripheral Clock 34 Status Mask */
#define PMC_CSR1_PID34(value)                 (PMC_CSR1_PID34_Msk & ((value) << PMC_CSR1_PID34_Pos))
#define PMC_CSR1_PID35_Pos                    _U_(3)                                               /**< (PMC_CSR1) Peripheral Clock 35 Status Position */
#define PMC_CSR1_PID35_Msk                    (_U_(0x1) << PMC_CSR1_PID35_Pos)                     /**< (PMC_CSR1) Peripheral Clock 35 Status Mask */
#define PMC_CSR1_PID35(value)                 (PMC_CSR1_PID35_Msk & ((value) << PMC_CSR1_PID35_Pos))
#define PMC_CSR1_PID36_Pos                    _U_(4)                                               /**< (PMC_CSR1) Peripheral Clock 36 Status Position */
#define PMC_CSR1_PID36_Msk                    (_U_(0x1) << PMC_CSR1_PID36_Pos)                     /**< (PMC_CSR1) Peripheral Clock 36 Status Mask */
#define PMC_CSR1_PID36(value)                 (PMC_CSR1_PID36_Msk & ((value) << PMC_CSR1_PID36_Pos))
#define PMC_CSR1_PID37_Pos                    _U_(5)                                               /**< (PMC_CSR1) Peripheral Clock 37 Status Position */
#define PMC_CSR1_PID37_Msk                    (_U_(0x1) << PMC_CSR1_PID37_Pos)                     /**< (PMC_CSR1) Peripheral Clock 37 Status Mask */
#define PMC_CSR1_PID37(value)                 (PMC_CSR1_PID37_Msk & ((value) << PMC_CSR1_PID37_Pos))
#define PMC_CSR1_PID38_Pos                    _U_(6)                                               /**< (PMC_CSR1) Peripheral Clock 38 Status Position */
#define PMC_CSR1_PID38_Msk                    (_U_(0x1) << PMC_CSR1_PID38_Pos)                     /**< (PMC_CSR1) Peripheral Clock 38 Status Mask */
#define PMC_CSR1_PID38(value)                 (PMC_CSR1_PID38_Msk & ((value) << PMC_CSR1_PID38_Pos))
#define PMC_CSR1_PID39_Pos                    _U_(7)                                               /**< (PMC_CSR1) Peripheral Clock 39 Status Position */
#define PMC_CSR1_PID39_Msk                    (_U_(0x1) << PMC_CSR1_PID39_Pos)                     /**< (PMC_CSR1) Peripheral Clock 39 Status Mask */
#define PMC_CSR1_PID39(value)                 (PMC_CSR1_PID39_Msk & ((value) << PMC_CSR1_PID39_Pos))
#define PMC_CSR1_PID40_Pos                    _U_(8)                                               /**< (PMC_CSR1) Peripheral Clock 40 Status Position */
#define PMC_CSR1_PID40_Msk                    (_U_(0x1) << PMC_CSR1_PID40_Pos)                     /**< (PMC_CSR1) Peripheral Clock 40 Status Mask */
#define PMC_CSR1_PID40(value)                 (PMC_CSR1_PID40_Msk & ((value) << PMC_CSR1_PID40_Pos))
#define PMC_CSR1_PID41_Pos                    _U_(9)                                               /**< (PMC_CSR1) Peripheral Clock 41 Status Position */
#define PMC_CSR1_PID41_Msk                    (_U_(0x1) << PMC_CSR1_PID41_Pos)                     /**< (PMC_CSR1) Peripheral Clock 41 Status Mask */
#define PMC_CSR1_PID41(value)                 (PMC_CSR1_PID41_Msk & ((value) << PMC_CSR1_PID41_Pos))
#define PMC_CSR1_PID42_Pos                    _U_(10)                                              /**< (PMC_CSR1) Peripheral Clock 42 Status Position */
#define PMC_CSR1_PID42_Msk                    (_U_(0x1) << PMC_CSR1_PID42_Pos)                     /**< (PMC_CSR1) Peripheral Clock 42 Status Mask */
#define PMC_CSR1_PID42(value)                 (PMC_CSR1_PID42_Msk & ((value) << PMC_CSR1_PID42_Pos))
#define PMC_CSR1_PID43_Pos                    _U_(11)                                              /**< (PMC_CSR1) Peripheral Clock 43 Status Position */
#define PMC_CSR1_PID43_Msk                    (_U_(0x1) << PMC_CSR1_PID43_Pos)                     /**< (PMC_CSR1) Peripheral Clock 43 Status Mask */
#define PMC_CSR1_PID43(value)                 (PMC_CSR1_PID43_Msk & ((value) << PMC_CSR1_PID43_Pos))
#define PMC_CSR1_PID44_Pos                    _U_(12)                                              /**< (PMC_CSR1) Peripheral Clock 44 Status Position */
#define PMC_CSR1_PID44_Msk                    (_U_(0x1) << PMC_CSR1_PID44_Pos)                     /**< (PMC_CSR1) Peripheral Clock 44 Status Mask */
#define PMC_CSR1_PID44(value)                 (PMC_CSR1_PID44_Msk & ((value) << PMC_CSR1_PID44_Pos))
#define PMC_CSR1_PID45_Pos                    _U_(13)                                              /**< (PMC_CSR1) Peripheral Clock 45 Status Position */
#define PMC_CSR1_PID45_Msk                    (_U_(0x1) << PMC_CSR1_PID45_Pos)                     /**< (PMC_CSR1) Peripheral Clock 45 Status Mask */
#define PMC_CSR1_PID45(value)                 (PMC_CSR1_PID45_Msk & ((value) << PMC_CSR1_PID45_Pos))
#define PMC_CSR1_PID46_Pos                    _U_(14)                                              /**< (PMC_CSR1) Peripheral Clock 46 Status Position */
#define PMC_CSR1_PID46_Msk                    (_U_(0x1) << PMC_CSR1_PID46_Pos)                     /**< (PMC_CSR1) Peripheral Clock 46 Status Mask */
#define PMC_CSR1_PID46(value)                 (PMC_CSR1_PID46_Msk & ((value) << PMC_CSR1_PID46_Pos))
#define PMC_CSR1_PID47_Pos                    _U_(15)                                              /**< (PMC_CSR1) Peripheral Clock 47 Status Position */
#define PMC_CSR1_PID47_Msk                    (_U_(0x1) << PMC_CSR1_PID47_Pos)                     /**< (PMC_CSR1) Peripheral Clock 47 Status Mask */
#define PMC_CSR1_PID47(value)                 (PMC_CSR1_PID47_Msk & ((value) << PMC_CSR1_PID47_Pos))
#define PMC_CSR1_PID48_Pos                    _U_(16)                                              /**< (PMC_CSR1) Peripheral Clock 48 Status Position */
#define PMC_CSR1_PID48_Msk                    (_U_(0x1) << PMC_CSR1_PID48_Pos)                     /**< (PMC_CSR1) Peripheral Clock 48 Status Mask */
#define PMC_CSR1_PID48(value)                 (PMC_CSR1_PID48_Msk & ((value) << PMC_CSR1_PID48_Pos))
#define PMC_CSR1_PID49_Pos                    _U_(17)                                              /**< (PMC_CSR1) Peripheral Clock 49 Status Position */
#define PMC_CSR1_PID49_Msk                    (_U_(0x1) << PMC_CSR1_PID49_Pos)                     /**< (PMC_CSR1) Peripheral Clock 49 Status Mask */
#define PMC_CSR1_PID49(value)                 (PMC_CSR1_PID49_Msk & ((value) << PMC_CSR1_PID49_Pos))
#define PMC_CSR1_PID50_Pos                    _U_(18)                                              /**< (PMC_CSR1) Peripheral Clock 50 Status Position */
#define PMC_CSR1_PID50_Msk                    (_U_(0x1) << PMC_CSR1_PID50_Pos)                     /**< (PMC_CSR1) Peripheral Clock 50 Status Mask */
#define PMC_CSR1_PID50(value)                 (PMC_CSR1_PID50_Msk & ((value) << PMC_CSR1_PID50_Pos))
#define PMC_CSR1_PID51_Pos                    _U_(19)                                              /**< (PMC_CSR1) Peripheral Clock 51 Status Position */
#define PMC_CSR1_PID51_Msk                    (_U_(0x1) << PMC_CSR1_PID51_Pos)                     /**< (PMC_CSR1) Peripheral Clock 51 Status Mask */
#define PMC_CSR1_PID51(value)                 (PMC_CSR1_PID51_Msk & ((value) << PMC_CSR1_PID51_Pos))
#define PMC_CSR1_PID52_Pos                    _U_(20)                                              /**< (PMC_CSR1) Peripheral Clock 52 Status Position */
#define PMC_CSR1_PID52_Msk                    (_U_(0x1) << PMC_CSR1_PID52_Pos)                     /**< (PMC_CSR1) Peripheral Clock 52 Status Mask */
#define PMC_CSR1_PID52(value)                 (PMC_CSR1_PID52_Msk & ((value) << PMC_CSR1_PID52_Pos))
#define PMC_CSR1_PID53_Pos                    _U_(21)                                              /**< (PMC_CSR1) Peripheral Clock 53 Status Position */
#define PMC_CSR1_PID53_Msk                    (_U_(0x1) << PMC_CSR1_PID53_Pos)                     /**< (PMC_CSR1) Peripheral Clock 53 Status Mask */
#define PMC_CSR1_PID53(value)                 (PMC_CSR1_PID53_Msk & ((value) << PMC_CSR1_PID53_Pos))
#define PMC_CSR1_PID54_Pos                    _U_(22)                                              /**< (PMC_CSR1) Peripheral Clock 54 Status Position */
#define PMC_CSR1_PID54_Msk                    (_U_(0x1) << PMC_CSR1_PID54_Pos)                     /**< (PMC_CSR1) Peripheral Clock 54 Status Mask */
#define PMC_CSR1_PID54(value)                 (PMC_CSR1_PID54_Msk & ((value) << PMC_CSR1_PID54_Pos))
#define PMC_CSR1_PID55_Pos                    _U_(23)                                              /**< (PMC_CSR1) Peripheral Clock 55 Status Position */
#define PMC_CSR1_PID55_Msk                    (_U_(0x1) << PMC_CSR1_PID55_Pos)                     /**< (PMC_CSR1) Peripheral Clock 55 Status Mask */
#define PMC_CSR1_PID55(value)                 (PMC_CSR1_PID55_Msk & ((value) << PMC_CSR1_PID55_Pos))
#define PMC_CSR1_PID56_Pos                    _U_(24)                                              /**< (PMC_CSR1) Peripheral Clock 56 Status Position */
#define PMC_CSR1_PID56_Msk                    (_U_(0x1) << PMC_CSR1_PID56_Pos)                     /**< (PMC_CSR1) Peripheral Clock 56 Status Mask */
#define PMC_CSR1_PID56(value)                 (PMC_CSR1_PID56_Msk & ((value) << PMC_CSR1_PID56_Pos))
#define PMC_CSR1_PID57_Pos                    _U_(25)                                              /**< (PMC_CSR1) Peripheral Clock 57 Status Position */
#define PMC_CSR1_PID57_Msk                    (_U_(0x1) << PMC_CSR1_PID57_Pos)                     /**< (PMC_CSR1) Peripheral Clock 57 Status Mask */
#define PMC_CSR1_PID57(value)                 (PMC_CSR1_PID57_Msk & ((value) << PMC_CSR1_PID57_Pos))
#define PMC_CSR1_PID58_Pos                    _U_(26)                                              /**< (PMC_CSR1) Peripheral Clock 58 Status Position */
#define PMC_CSR1_PID58_Msk                    (_U_(0x1) << PMC_CSR1_PID58_Pos)                     /**< (PMC_CSR1) Peripheral Clock 58 Status Mask */
#define PMC_CSR1_PID58(value)                 (PMC_CSR1_PID58_Msk & ((value) << PMC_CSR1_PID58_Pos))
#define PMC_CSR1_PID59_Pos                    _U_(27)                                              /**< (PMC_CSR1) Peripheral Clock 59 Status Position */
#define PMC_CSR1_PID59_Msk                    (_U_(0x1) << PMC_CSR1_PID59_Pos)                     /**< (PMC_CSR1) Peripheral Clock 59 Status Mask */
#define PMC_CSR1_PID59(value)                 (PMC_CSR1_PID59_Msk & ((value) << PMC_CSR1_PID59_Pos))
#define PMC_CSR1_PID60_Pos                    _U_(28)                                              /**< (PMC_CSR1) Peripheral Clock 60 Status Position */
#define PMC_CSR1_PID60_Msk                    (_U_(0x1) << PMC_CSR1_PID60_Pos)                     /**< (PMC_CSR1) Peripheral Clock 60 Status Mask */
#define PMC_CSR1_PID60(value)                 (PMC_CSR1_PID60_Msk & ((value) << PMC_CSR1_PID60_Pos))
#define PMC_CSR1_PID61_Pos                    _U_(29)                                              /**< (PMC_CSR1) Peripheral Clock 61 Status Position */
#define PMC_CSR1_PID61_Msk                    (_U_(0x1) << PMC_CSR1_PID61_Pos)                     /**< (PMC_CSR1) Peripheral Clock 61 Status Mask */
#define PMC_CSR1_PID61(value)                 (PMC_CSR1_PID61_Msk & ((value) << PMC_CSR1_PID61_Pos))
#define PMC_CSR1_PID62_Pos                    _U_(30)                                              /**< (PMC_CSR1) Peripheral Clock 62 Status Position */
#define PMC_CSR1_PID62_Msk                    (_U_(0x1) << PMC_CSR1_PID62_Pos)                     /**< (PMC_CSR1) Peripheral Clock 62 Status Mask */
#define PMC_CSR1_PID62(value)                 (PMC_CSR1_PID62_Msk & ((value) << PMC_CSR1_PID62_Pos))
#define PMC_CSR1_PID63_Pos                    _U_(31)                                              /**< (PMC_CSR1) Peripheral Clock 63 Status Position */
#define PMC_CSR1_PID63_Msk                    (_U_(0x1) << PMC_CSR1_PID63_Pos)                     /**< (PMC_CSR1) Peripheral Clock 63 Status Mask */
#define PMC_CSR1_PID63(value)                 (PMC_CSR1_PID63_Msk & ((value) << PMC_CSR1_PID63_Pos))
#define PMC_CSR1_Msk                          _U_(0xFFFFFFFF)                                      /**< (PMC_CSR1) Register Mask  */

#define PMC_CSR1_PID_Pos                      _U_(0)                                               /**< (PMC_CSR1 Position) Peripheral Clock 63 Status */
#define PMC_CSR1_PID_Msk                      (_U_(0xFFFFFFFF) << PMC_CSR1_PID_Pos)                /**< (PMC_CSR1 Mask) PID */
#define PMC_CSR1_PID(value)                   (PMC_CSR1_PID_Msk & ((value) << PMC_CSR1_PID_Pos))   

/* -------- PMC_CSR2 : (PMC Offset: 0x178) ( R/ 32) Peripheral Clock Status Register 2 -------- */
#define PMC_CSR2_PID64_Pos                    _U_(0)                                               /**< (PMC_CSR2) Peripheral Clock 64 Status Position */
#define PMC_CSR2_PID64_Msk                    (_U_(0x1) << PMC_CSR2_PID64_Pos)                     /**< (PMC_CSR2) Peripheral Clock 64 Status Mask */
#define PMC_CSR2_PID64(value)                 (PMC_CSR2_PID64_Msk & ((value) << PMC_CSR2_PID64_Pos))
#define PMC_CSR2_PID65_Pos                    _U_(1)                                               /**< (PMC_CSR2) Peripheral Clock 65 Status Position */
#define PMC_CSR2_PID65_Msk                    (_U_(0x1) << PMC_CSR2_PID65_Pos)                     /**< (PMC_CSR2) Peripheral Clock 65 Status Mask */
#define PMC_CSR2_PID65(value)                 (PMC_CSR2_PID65_Msk & ((value) << PMC_CSR2_PID65_Pos))
#define PMC_CSR2_PID66_Pos                    _U_(2)                                               /**< (PMC_CSR2) Peripheral Clock 66 Status Position */
#define PMC_CSR2_PID66_Msk                    (_U_(0x1) << PMC_CSR2_PID66_Pos)                     /**< (PMC_CSR2) Peripheral Clock 66 Status Mask */
#define PMC_CSR2_PID66(value)                 (PMC_CSR2_PID66_Msk & ((value) << PMC_CSR2_PID66_Pos))
#define PMC_CSR2_PID67_Pos                    _U_(3)                                               /**< (PMC_CSR2) Peripheral Clock 67 Status Position */
#define PMC_CSR2_PID67_Msk                    (_U_(0x1) << PMC_CSR2_PID67_Pos)                     /**< (PMC_CSR2) Peripheral Clock 67 Status Mask */
#define PMC_CSR2_PID67(value)                 (PMC_CSR2_PID67_Msk & ((value) << PMC_CSR2_PID67_Pos))
#define PMC_CSR2_PID68_Pos                    _U_(4)                                               /**< (PMC_CSR2) Peripheral Clock 68 Status Position */
#define PMC_CSR2_PID68_Msk                    (_U_(0x1) << PMC_CSR2_PID68_Pos)                     /**< (PMC_CSR2) Peripheral Clock 68 Status Mask */
#define PMC_CSR2_PID68(value)                 (PMC_CSR2_PID68_Msk & ((value) << PMC_CSR2_PID68_Pos))
#define PMC_CSR2_PID69_Pos                    _U_(5)                                               /**< (PMC_CSR2) Peripheral Clock 69 Status Position */
#define PMC_CSR2_PID69_Msk                    (_U_(0x1) << PMC_CSR2_PID69_Pos)                     /**< (PMC_CSR2) Peripheral Clock 69 Status Mask */
#define PMC_CSR2_PID69(value)                 (PMC_CSR2_PID69_Msk & ((value) << PMC_CSR2_PID69_Pos))
#define PMC_CSR2_PID70_Pos                    _U_(6)                                               /**< (PMC_CSR2) Peripheral Clock 70 Status Position */
#define PMC_CSR2_PID70_Msk                    (_U_(0x1) << PMC_CSR2_PID70_Pos)                     /**< (PMC_CSR2) Peripheral Clock 70 Status Mask */
#define PMC_CSR2_PID70(value)                 (PMC_CSR2_PID70_Msk & ((value) << PMC_CSR2_PID70_Pos))
#define PMC_CSR2_PID71_Pos                    _U_(7)                                               /**< (PMC_CSR2) Peripheral Clock 71 Status Position */
#define PMC_CSR2_PID71_Msk                    (_U_(0x1) << PMC_CSR2_PID71_Pos)                     /**< (PMC_CSR2) Peripheral Clock 71 Status Mask */
#define PMC_CSR2_PID71(value)                 (PMC_CSR2_PID71_Msk & ((value) << PMC_CSR2_PID71_Pos))
#define PMC_CSR2_PID72_Pos                    _U_(8)                                               /**< (PMC_CSR2) Peripheral Clock 72 Status Position */
#define PMC_CSR2_PID72_Msk                    (_U_(0x1) << PMC_CSR2_PID72_Pos)                     /**< (PMC_CSR2) Peripheral Clock 72 Status Mask */
#define PMC_CSR2_PID72(value)                 (PMC_CSR2_PID72_Msk & ((value) << PMC_CSR2_PID72_Pos))
#define PMC_CSR2_PID73_Pos                    _U_(9)                                               /**< (PMC_CSR2) Peripheral Clock 73 Status Position */
#define PMC_CSR2_PID73_Msk                    (_U_(0x1) << PMC_CSR2_PID73_Pos)                     /**< (PMC_CSR2) Peripheral Clock 73 Status Mask */
#define PMC_CSR2_PID73(value)                 (PMC_CSR2_PID73_Msk & ((value) << PMC_CSR2_PID73_Pos))
#define PMC_CSR2_PID74_Pos                    _U_(10)                                              /**< (PMC_CSR2) Peripheral Clock 74 Status Position */
#define PMC_CSR2_PID74_Msk                    (_U_(0x1) << PMC_CSR2_PID74_Pos)                     /**< (PMC_CSR2) Peripheral Clock 74 Status Mask */
#define PMC_CSR2_PID74(value)                 (PMC_CSR2_PID74_Msk & ((value) << PMC_CSR2_PID74_Pos))
#define PMC_CSR2_PID75_Pos                    _U_(11)                                              /**< (PMC_CSR2) Peripheral Clock 75 Status Position */
#define PMC_CSR2_PID75_Msk                    (_U_(0x1) << PMC_CSR2_PID75_Pos)                     /**< (PMC_CSR2) Peripheral Clock 75 Status Mask */
#define PMC_CSR2_PID75(value)                 (PMC_CSR2_PID75_Msk & ((value) << PMC_CSR2_PID75_Pos))
#define PMC_CSR2_PID76_Pos                    _U_(12)                                              /**< (PMC_CSR2) Peripheral Clock 76 Status Position */
#define PMC_CSR2_PID76_Msk                    (_U_(0x1) << PMC_CSR2_PID76_Pos)                     /**< (PMC_CSR2) Peripheral Clock 76 Status Mask */
#define PMC_CSR2_PID76(value)                 (PMC_CSR2_PID76_Msk & ((value) << PMC_CSR2_PID76_Pos))
#define PMC_CSR2_PID77_Pos                    _U_(13)                                              /**< (PMC_CSR2) Peripheral Clock 77 Status Position */
#define PMC_CSR2_PID77_Msk                    (_U_(0x1) << PMC_CSR2_PID77_Pos)                     /**< (PMC_CSR2) Peripheral Clock 77 Status Mask */
#define PMC_CSR2_PID77(value)                 (PMC_CSR2_PID77_Msk & ((value) << PMC_CSR2_PID77_Pos))
#define PMC_CSR2_PID78_Pos                    _U_(14)                                              /**< (PMC_CSR2) Peripheral Clock 78 Status Position */
#define PMC_CSR2_PID78_Msk                    (_U_(0x1) << PMC_CSR2_PID78_Pos)                     /**< (PMC_CSR2) Peripheral Clock 78 Status Mask */
#define PMC_CSR2_PID78(value)                 (PMC_CSR2_PID78_Msk & ((value) << PMC_CSR2_PID78_Pos))
#define PMC_CSR2_PID79_Pos                    _U_(15)                                              /**< (PMC_CSR2) Peripheral Clock 79 Status Position */
#define PMC_CSR2_PID79_Msk                    (_U_(0x1) << PMC_CSR2_PID79_Pos)                     /**< (PMC_CSR2) Peripheral Clock 79 Status Mask */
#define PMC_CSR2_PID79(value)                 (PMC_CSR2_PID79_Msk & ((value) << PMC_CSR2_PID79_Pos))
#define PMC_CSR2_PID80_Pos                    _U_(16)                                              /**< (PMC_CSR2) Peripheral Clock 80 Status Position */
#define PMC_CSR2_PID80_Msk                    (_U_(0x1) << PMC_CSR2_PID80_Pos)                     /**< (PMC_CSR2) Peripheral Clock 80 Status Mask */
#define PMC_CSR2_PID80(value)                 (PMC_CSR2_PID80_Msk & ((value) << PMC_CSR2_PID80_Pos))
#define PMC_CSR2_PID81_Pos                    _U_(17)                                              /**< (PMC_CSR2) Peripheral Clock 81 Status Position */
#define PMC_CSR2_PID81_Msk                    (_U_(0x1) << PMC_CSR2_PID81_Pos)                     /**< (PMC_CSR2) Peripheral Clock 81 Status Mask */
#define PMC_CSR2_PID81(value)                 (PMC_CSR2_PID81_Msk & ((value) << PMC_CSR2_PID81_Pos))
#define PMC_CSR2_PID82_Pos                    _U_(18)                                              /**< (PMC_CSR2) Peripheral Clock 82 Status Position */
#define PMC_CSR2_PID82_Msk                    (_U_(0x1) << PMC_CSR2_PID82_Pos)                     /**< (PMC_CSR2) Peripheral Clock 82 Status Mask */
#define PMC_CSR2_PID82(value)                 (PMC_CSR2_PID82_Msk & ((value) << PMC_CSR2_PID82_Pos))
#define PMC_CSR2_PID83_Pos                    _U_(19)                                              /**< (PMC_CSR2) Peripheral Clock 83 Status Position */
#define PMC_CSR2_PID83_Msk                    (_U_(0x1) << PMC_CSR2_PID83_Pos)                     /**< (PMC_CSR2) Peripheral Clock 83 Status Mask */
#define PMC_CSR2_PID83(value)                 (PMC_CSR2_PID83_Msk & ((value) << PMC_CSR2_PID83_Pos))
#define PMC_CSR2_PID84_Pos                    _U_(20)                                              /**< (PMC_CSR2) Peripheral Clock 84 Status Position */
#define PMC_CSR2_PID84_Msk                    (_U_(0x1) << PMC_CSR2_PID84_Pos)                     /**< (PMC_CSR2) Peripheral Clock 84 Status Mask */
#define PMC_CSR2_PID84(value)                 (PMC_CSR2_PID84_Msk & ((value) << PMC_CSR2_PID84_Pos))
#define PMC_CSR2_PID85_Pos                    _U_(21)                                              /**< (PMC_CSR2) Peripheral Clock 85 Status Position */
#define PMC_CSR2_PID85_Msk                    (_U_(0x1) << PMC_CSR2_PID85_Pos)                     /**< (PMC_CSR2) Peripheral Clock 85 Status Mask */
#define PMC_CSR2_PID85(value)                 (PMC_CSR2_PID85_Msk & ((value) << PMC_CSR2_PID85_Pos))
#define PMC_CSR2_PID86_Pos                    _U_(22)                                              /**< (PMC_CSR2) Peripheral Clock 86 Status Position */
#define PMC_CSR2_PID86_Msk                    (_U_(0x1) << PMC_CSR2_PID86_Pos)                     /**< (PMC_CSR2) Peripheral Clock 86 Status Mask */
#define PMC_CSR2_PID86(value)                 (PMC_CSR2_PID86_Msk & ((value) << PMC_CSR2_PID86_Pos))
#define PMC_CSR2_PID87_Pos                    _U_(23)                                              /**< (PMC_CSR2) Peripheral Clock 87 Status Position */
#define PMC_CSR2_PID87_Msk                    (_U_(0x1) << PMC_CSR2_PID87_Pos)                     /**< (PMC_CSR2) Peripheral Clock 87 Status Mask */
#define PMC_CSR2_PID87(value)                 (PMC_CSR2_PID87_Msk & ((value) << PMC_CSR2_PID87_Pos))
#define PMC_CSR2_PID88_Pos                    _U_(24)                                              /**< (PMC_CSR2) Peripheral Clock 88 Status Position */
#define PMC_CSR2_PID88_Msk                    (_U_(0x1) << PMC_CSR2_PID88_Pos)                     /**< (PMC_CSR2) Peripheral Clock 88 Status Mask */
#define PMC_CSR2_PID88(value)                 (PMC_CSR2_PID88_Msk & ((value) << PMC_CSR2_PID88_Pos))
#define PMC_CSR2_PID89_Pos                    _U_(25)                                              /**< (PMC_CSR2) Peripheral Clock 89 Status Position */
#define PMC_CSR2_PID89_Msk                    (_U_(0x1) << PMC_CSR2_PID89_Pos)                     /**< (PMC_CSR2) Peripheral Clock 89 Status Mask */
#define PMC_CSR2_PID89(value)                 (PMC_CSR2_PID89_Msk & ((value) << PMC_CSR2_PID89_Pos))
#define PMC_CSR2_PID90_Pos                    _U_(26)                                              /**< (PMC_CSR2) Peripheral Clock 90 Status Position */
#define PMC_CSR2_PID90_Msk                    (_U_(0x1) << PMC_CSR2_PID90_Pos)                     /**< (PMC_CSR2) Peripheral Clock 90 Status Mask */
#define PMC_CSR2_PID90(value)                 (PMC_CSR2_PID90_Msk & ((value) << PMC_CSR2_PID90_Pos))
#define PMC_CSR2_PID91_Pos                    _U_(27)                                              /**< (PMC_CSR2) Peripheral Clock 91 Status Position */
#define PMC_CSR2_PID91_Msk                    (_U_(0x1) << PMC_CSR2_PID91_Pos)                     /**< (PMC_CSR2) Peripheral Clock 91 Status Mask */
#define PMC_CSR2_PID91(value)                 (PMC_CSR2_PID91_Msk & ((value) << PMC_CSR2_PID91_Pos))
#define PMC_CSR2_PID92_Pos                    _U_(28)                                              /**< (PMC_CSR2) Peripheral Clock 92 Status Position */
#define PMC_CSR2_PID92_Msk                    (_U_(0x1) << PMC_CSR2_PID92_Pos)                     /**< (PMC_CSR2) Peripheral Clock 92 Status Mask */
#define PMC_CSR2_PID92(value)                 (PMC_CSR2_PID92_Msk & ((value) << PMC_CSR2_PID92_Pos))
#define PMC_CSR2_PID93_Pos                    _U_(29)                                              /**< (PMC_CSR2) Peripheral Clock 93 Status Position */
#define PMC_CSR2_PID93_Msk                    (_U_(0x1) << PMC_CSR2_PID93_Pos)                     /**< (PMC_CSR2) Peripheral Clock 93 Status Mask */
#define PMC_CSR2_PID93(value)                 (PMC_CSR2_PID93_Msk & ((value) << PMC_CSR2_PID93_Pos))
#define PMC_CSR2_PID94_Pos                    _U_(30)                                              /**< (PMC_CSR2) Peripheral Clock 94 Status Position */
#define PMC_CSR2_PID94_Msk                    (_U_(0x1) << PMC_CSR2_PID94_Pos)                     /**< (PMC_CSR2) Peripheral Clock 94 Status Mask */
#define PMC_CSR2_PID94(value)                 (PMC_CSR2_PID94_Msk & ((value) << PMC_CSR2_PID94_Pos))
#define PMC_CSR2_PID95_Pos                    _U_(31)                                              /**< (PMC_CSR2) Peripheral Clock 95 Status Position */
#define PMC_CSR2_PID95_Msk                    (_U_(0x1) << PMC_CSR2_PID95_Pos)                     /**< (PMC_CSR2) Peripheral Clock 95 Status Mask */
#define PMC_CSR2_PID95(value)                 (PMC_CSR2_PID95_Msk & ((value) << PMC_CSR2_PID95_Pos))
#define PMC_CSR2_Msk                          _U_(0xFFFFFFFF)                                      /**< (PMC_CSR2) Register Mask  */

#define PMC_CSR2_PID_Pos                      _U_(0)                                               /**< (PMC_CSR2 Position) Peripheral Clock 95 Status */
#define PMC_CSR2_PID_Msk                      (_U_(0xFFFFFFFF) << PMC_CSR2_PID_Pos)                /**< (PMC_CSR2 Mask) PID */
#define PMC_CSR2_PID(value)                   (PMC_CSR2_PID_Msk & ((value) << PMC_CSR2_PID_Pos))   

/* -------- PMC_CSR3 : (PMC Offset: 0x17C) ( R/ 32) Peripheral Clock Status Register 3 -------- */
#define PMC_CSR3_PID96_Pos                    _U_(0)                                               /**< (PMC_CSR3) Peripheral Clock 96 Status Position */
#define PMC_CSR3_PID96_Msk                    (_U_(0x1) << PMC_CSR3_PID96_Pos)                     /**< (PMC_CSR3) Peripheral Clock 96 Status Mask */
#define PMC_CSR3_PID96(value)                 (PMC_CSR3_PID96_Msk & ((value) << PMC_CSR3_PID96_Pos))
#define PMC_CSR3_PID97_Pos                    _U_(1)                                               /**< (PMC_CSR3) Peripheral Clock 97 Status Position */
#define PMC_CSR3_PID97_Msk                    (_U_(0x1) << PMC_CSR3_PID97_Pos)                     /**< (PMC_CSR3) Peripheral Clock 97 Status Mask */
#define PMC_CSR3_PID97(value)                 (PMC_CSR3_PID97_Msk & ((value) << PMC_CSR3_PID97_Pos))
#define PMC_CSR3_PID98_Pos                    _U_(2)                                               /**< (PMC_CSR3) Peripheral Clock 98 Status Position */
#define PMC_CSR3_PID98_Msk                    (_U_(0x1) << PMC_CSR3_PID98_Pos)                     /**< (PMC_CSR3) Peripheral Clock 98 Status Mask */
#define PMC_CSR3_PID98(value)                 (PMC_CSR3_PID98_Msk & ((value) << PMC_CSR3_PID98_Pos))
#define PMC_CSR3_PID99_Pos                    _U_(3)                                               /**< (PMC_CSR3) Peripheral Clock 99 Status Position */
#define PMC_CSR3_PID99_Msk                    (_U_(0x1) << PMC_CSR3_PID99_Pos)                     /**< (PMC_CSR3) Peripheral Clock 99 Status Mask */
#define PMC_CSR3_PID99(value)                 (PMC_CSR3_PID99_Msk & ((value) << PMC_CSR3_PID99_Pos))
#define PMC_CSR3_PID100_Pos                   _U_(4)                                               /**< (PMC_CSR3) Peripheral Clock 100 Status Position */
#define PMC_CSR3_PID100_Msk                   (_U_(0x1) << PMC_CSR3_PID100_Pos)                    /**< (PMC_CSR3) Peripheral Clock 100 Status Mask */
#define PMC_CSR3_PID100(value)                (PMC_CSR3_PID100_Msk & ((value) << PMC_CSR3_PID100_Pos))
#define PMC_CSR3_PID101_Pos                   _U_(5)                                               /**< (PMC_CSR3) Peripheral Clock 101 Status Position */
#define PMC_CSR3_PID101_Msk                   (_U_(0x1) << PMC_CSR3_PID101_Pos)                    /**< (PMC_CSR3) Peripheral Clock 101 Status Mask */
#define PMC_CSR3_PID101(value)                (PMC_CSR3_PID101_Msk & ((value) << PMC_CSR3_PID101_Pos))
#define PMC_CSR3_PID102_Pos                   _U_(6)                                               /**< (PMC_CSR3) Peripheral Clock 102 Status Position */
#define PMC_CSR3_PID102_Msk                   (_U_(0x1) << PMC_CSR3_PID102_Pos)                    /**< (PMC_CSR3) Peripheral Clock 102 Status Mask */
#define PMC_CSR3_PID102(value)                (PMC_CSR3_PID102_Msk & ((value) << PMC_CSR3_PID102_Pos))
#define PMC_CSR3_PID103_Pos                   _U_(7)                                               /**< (PMC_CSR3) Peripheral Clock 103 Status Position */
#define PMC_CSR3_PID103_Msk                   (_U_(0x1) << PMC_CSR3_PID103_Pos)                    /**< (PMC_CSR3) Peripheral Clock 103 Status Mask */
#define PMC_CSR3_PID103(value)                (PMC_CSR3_PID103_Msk & ((value) << PMC_CSR3_PID103_Pos))
#define PMC_CSR3_PID104_Pos                   _U_(8)                                               /**< (PMC_CSR3) Peripheral Clock 104 Status Position */
#define PMC_CSR3_PID104_Msk                   (_U_(0x1) << PMC_CSR3_PID104_Pos)                    /**< (PMC_CSR3) Peripheral Clock 104 Status Mask */
#define PMC_CSR3_PID104(value)                (PMC_CSR3_PID104_Msk & ((value) << PMC_CSR3_PID104_Pos))
#define PMC_CSR3_PID105_Pos                   _U_(9)                                               /**< (PMC_CSR3) Peripheral Clock 105 Status Position */
#define PMC_CSR3_PID105_Msk                   (_U_(0x1) << PMC_CSR3_PID105_Pos)                    /**< (PMC_CSR3) Peripheral Clock 105 Status Mask */
#define PMC_CSR3_PID105(value)                (PMC_CSR3_PID105_Msk & ((value) << PMC_CSR3_PID105_Pos))
#define PMC_CSR3_PID106_Pos                   _U_(10)                                              /**< (PMC_CSR3) Peripheral Clock 106 Status Position */
#define PMC_CSR3_PID106_Msk                   (_U_(0x1) << PMC_CSR3_PID106_Pos)                    /**< (PMC_CSR3) Peripheral Clock 106 Status Mask */
#define PMC_CSR3_PID106(value)                (PMC_CSR3_PID106_Msk & ((value) << PMC_CSR3_PID106_Pos))
#define PMC_CSR3_PID107_Pos                   _U_(11)                                              /**< (PMC_CSR3) Peripheral Clock 107 Status Position */
#define PMC_CSR3_PID107_Msk                   (_U_(0x1) << PMC_CSR3_PID107_Pos)                    /**< (PMC_CSR3) Peripheral Clock 107 Status Mask */
#define PMC_CSR3_PID107(value)                (PMC_CSR3_PID107_Msk & ((value) << PMC_CSR3_PID107_Pos))
#define PMC_CSR3_PID108_Pos                   _U_(12)                                              /**< (PMC_CSR3) Peripheral Clock 108 Status Position */
#define PMC_CSR3_PID108_Msk                   (_U_(0x1) << PMC_CSR3_PID108_Pos)                    /**< (PMC_CSR3) Peripheral Clock 108 Status Mask */
#define PMC_CSR3_PID108(value)                (PMC_CSR3_PID108_Msk & ((value) << PMC_CSR3_PID108_Pos))
#define PMC_CSR3_PID109_Pos                   _U_(13)                                              /**< (PMC_CSR3) Peripheral Clock 109 Status Position */
#define PMC_CSR3_PID109_Msk                   (_U_(0x1) << PMC_CSR3_PID109_Pos)                    /**< (PMC_CSR3) Peripheral Clock 109 Status Mask */
#define PMC_CSR3_PID109(value)                (PMC_CSR3_PID109_Msk & ((value) << PMC_CSR3_PID109_Pos))
#define PMC_CSR3_PID110_Pos                   _U_(14)                                              /**< (PMC_CSR3) Peripheral Clock 110 Status Position */
#define PMC_CSR3_PID110_Msk                   (_U_(0x1) << PMC_CSR3_PID110_Pos)                    /**< (PMC_CSR3) Peripheral Clock 110 Status Mask */
#define PMC_CSR3_PID110(value)                (PMC_CSR3_PID110_Msk & ((value) << PMC_CSR3_PID110_Pos))
#define PMC_CSR3_PID111_Pos                   _U_(15)                                              /**< (PMC_CSR3) Peripheral Clock 111 Status Position */
#define PMC_CSR3_PID111_Msk                   (_U_(0x1) << PMC_CSR3_PID111_Pos)                    /**< (PMC_CSR3) Peripheral Clock 111 Status Mask */
#define PMC_CSR3_PID111(value)                (PMC_CSR3_PID111_Msk & ((value) << PMC_CSR3_PID111_Pos))
#define PMC_CSR3_PID112_Pos                   _U_(16)                                              /**< (PMC_CSR3) Peripheral Clock 112 Status Position */
#define PMC_CSR3_PID112_Msk                   (_U_(0x1) << PMC_CSR3_PID112_Pos)                    /**< (PMC_CSR3) Peripheral Clock 112 Status Mask */
#define PMC_CSR3_PID112(value)                (PMC_CSR3_PID112_Msk & ((value) << PMC_CSR3_PID112_Pos))
#define PMC_CSR3_PID113_Pos                   _U_(17)                                              /**< (PMC_CSR3) Peripheral Clock 113 Status Position */
#define PMC_CSR3_PID113_Msk                   (_U_(0x1) << PMC_CSR3_PID113_Pos)                    /**< (PMC_CSR3) Peripheral Clock 113 Status Mask */
#define PMC_CSR3_PID113(value)                (PMC_CSR3_PID113_Msk & ((value) << PMC_CSR3_PID113_Pos))
#define PMC_CSR3_PID114_Pos                   _U_(18)                                              /**< (PMC_CSR3) Peripheral Clock 114 Status Position */
#define PMC_CSR3_PID114_Msk                   (_U_(0x1) << PMC_CSR3_PID114_Pos)                    /**< (PMC_CSR3) Peripheral Clock 114 Status Mask */
#define PMC_CSR3_PID114(value)                (PMC_CSR3_PID114_Msk & ((value) << PMC_CSR3_PID114_Pos))
#define PMC_CSR3_PID115_Pos                   _U_(19)                                              /**< (PMC_CSR3) Peripheral Clock 115 Status Position */
#define PMC_CSR3_PID115_Msk                   (_U_(0x1) << PMC_CSR3_PID115_Pos)                    /**< (PMC_CSR3) Peripheral Clock 115 Status Mask */
#define PMC_CSR3_PID115(value)                (PMC_CSR3_PID115_Msk & ((value) << PMC_CSR3_PID115_Pos))
#define PMC_CSR3_PID116_Pos                   _U_(20)                                              /**< (PMC_CSR3) Peripheral Clock 116 Status Position */
#define PMC_CSR3_PID116_Msk                   (_U_(0x1) << PMC_CSR3_PID116_Pos)                    /**< (PMC_CSR3) Peripheral Clock 116 Status Mask */
#define PMC_CSR3_PID116(value)                (PMC_CSR3_PID116_Msk & ((value) << PMC_CSR3_PID116_Pos))
#define PMC_CSR3_PID117_Pos                   _U_(21)                                              /**< (PMC_CSR3) Peripheral Clock 117 Status Position */
#define PMC_CSR3_PID117_Msk                   (_U_(0x1) << PMC_CSR3_PID117_Pos)                    /**< (PMC_CSR3) Peripheral Clock 117 Status Mask */
#define PMC_CSR3_PID117(value)                (PMC_CSR3_PID117_Msk & ((value) << PMC_CSR3_PID117_Pos))
#define PMC_CSR3_PID118_Pos                   _U_(22)                                              /**< (PMC_CSR3) Peripheral Clock 118 Status Position */
#define PMC_CSR3_PID118_Msk                   (_U_(0x1) << PMC_CSR3_PID118_Pos)                    /**< (PMC_CSR3) Peripheral Clock 118 Status Mask */
#define PMC_CSR3_PID118(value)                (PMC_CSR3_PID118_Msk & ((value) << PMC_CSR3_PID118_Pos))
#define PMC_CSR3_PID119_Pos                   _U_(23)                                              /**< (PMC_CSR3) Peripheral Clock 119 Status Position */
#define PMC_CSR3_PID119_Msk                   (_U_(0x1) << PMC_CSR3_PID119_Pos)                    /**< (PMC_CSR3) Peripheral Clock 119 Status Mask */
#define PMC_CSR3_PID119(value)                (PMC_CSR3_PID119_Msk & ((value) << PMC_CSR3_PID119_Pos))
#define PMC_CSR3_PID120_Pos                   _U_(24)                                              /**< (PMC_CSR3) Peripheral Clock 120 Status Position */
#define PMC_CSR3_PID120_Msk                   (_U_(0x1) << PMC_CSR3_PID120_Pos)                    /**< (PMC_CSR3) Peripheral Clock 120 Status Mask */
#define PMC_CSR3_PID120(value)                (PMC_CSR3_PID120_Msk & ((value) << PMC_CSR3_PID120_Pos))
#define PMC_CSR3_PID121_Pos                   _U_(25)                                              /**< (PMC_CSR3) Peripheral Clock 121 Status Position */
#define PMC_CSR3_PID121_Msk                   (_U_(0x1) << PMC_CSR3_PID121_Pos)                    /**< (PMC_CSR3) Peripheral Clock 121 Status Mask */
#define PMC_CSR3_PID121(value)                (PMC_CSR3_PID121_Msk & ((value) << PMC_CSR3_PID121_Pos))
#define PMC_CSR3_PID122_Pos                   _U_(26)                                              /**< (PMC_CSR3) Peripheral Clock 122 Status Position */
#define PMC_CSR3_PID122_Msk                   (_U_(0x1) << PMC_CSR3_PID122_Pos)                    /**< (PMC_CSR3) Peripheral Clock 122 Status Mask */
#define PMC_CSR3_PID122(value)                (PMC_CSR3_PID122_Msk & ((value) << PMC_CSR3_PID122_Pos))
#define PMC_CSR3_PID123_Pos                   _U_(27)                                              /**< (PMC_CSR3) Peripheral Clock 123 Status Position */
#define PMC_CSR3_PID123_Msk                   (_U_(0x1) << PMC_CSR3_PID123_Pos)                    /**< (PMC_CSR3) Peripheral Clock 123 Status Mask */
#define PMC_CSR3_PID123(value)                (PMC_CSR3_PID123_Msk & ((value) << PMC_CSR3_PID123_Pos))
#define PMC_CSR3_PID124_Pos                   _U_(28)                                              /**< (PMC_CSR3) Peripheral Clock 124 Status Position */
#define PMC_CSR3_PID124_Msk                   (_U_(0x1) << PMC_CSR3_PID124_Pos)                    /**< (PMC_CSR3) Peripheral Clock 124 Status Mask */
#define PMC_CSR3_PID124(value)                (PMC_CSR3_PID124_Msk & ((value) << PMC_CSR3_PID124_Pos))
#define PMC_CSR3_PID125_Pos                   _U_(29)                                              /**< (PMC_CSR3) Peripheral Clock 125 Status Position */
#define PMC_CSR3_PID125_Msk                   (_U_(0x1) << PMC_CSR3_PID125_Pos)                    /**< (PMC_CSR3) Peripheral Clock 125 Status Mask */
#define PMC_CSR3_PID125(value)                (PMC_CSR3_PID125_Msk & ((value) << PMC_CSR3_PID125_Pos))
#define PMC_CSR3_PID126_Pos                   _U_(30)                                              /**< (PMC_CSR3) Peripheral Clock 126 Status Position */
#define PMC_CSR3_PID126_Msk                   (_U_(0x1) << PMC_CSR3_PID126_Pos)                    /**< (PMC_CSR3) Peripheral Clock 126 Status Mask */
#define PMC_CSR3_PID126(value)                (PMC_CSR3_PID126_Msk & ((value) << PMC_CSR3_PID126_Pos))
#define PMC_CSR3_PID127_Pos                   _U_(31)                                              /**< (PMC_CSR3) Peripheral Clock 127 Status Position */
#define PMC_CSR3_PID127_Msk                   (_U_(0x1) << PMC_CSR3_PID127_Pos)                    /**< (PMC_CSR3) Peripheral Clock 127 Status Mask */
#define PMC_CSR3_PID127(value)                (PMC_CSR3_PID127_Msk & ((value) << PMC_CSR3_PID127_Pos))
#define PMC_CSR3_Msk                          _U_(0xFFFFFFFF)                                      /**< (PMC_CSR3) Register Mask  */

#define PMC_CSR3_PID_Pos                      _U_(0)                                               /**< (PMC_CSR3 Position) Peripheral Clock x27 Status */
#define PMC_CSR3_PID_Msk                      (_U_(0xFFFFFFFF) << PMC_CSR3_PID_Pos)                /**< (PMC_CSR3 Mask) PID */
#define PMC_CSR3_PID(value)                   (PMC_CSR3_PID_Msk & ((value) << PMC_CSR3_PID_Pos))   

/* -------- PMC_GCSR0 : (PMC Offset: 0x190) ( R/ 32) Generic Clock Status Register 0 -------- */
#define PMC_GCSR0_GPID0_Pos                   _U_(0)                                               /**< (PMC_GCSR0) Generic Clock 0 Status Position */
#define PMC_GCSR0_GPID0_Msk                   (_U_(0x1) << PMC_GCSR0_GPID0_Pos)                    /**< (PMC_GCSR0) Generic Clock 0 Status Mask */
#define PMC_GCSR0_GPID0(value)                (PMC_GCSR0_GPID0_Msk & ((value) << PMC_GCSR0_GPID0_Pos))
#define PMC_GCSR0_GPID1_Pos                   _U_(1)                                               /**< (PMC_GCSR0) Generic Clock 1 Status Position */
#define PMC_GCSR0_GPID1_Msk                   (_U_(0x1) << PMC_GCSR0_GPID1_Pos)                    /**< (PMC_GCSR0) Generic Clock 1 Status Mask */
#define PMC_GCSR0_GPID1(value)                (PMC_GCSR0_GPID1_Msk & ((value) << PMC_GCSR0_GPID1_Pos))
#define PMC_GCSR0_GPID2_Pos                   _U_(2)                                               /**< (PMC_GCSR0) Generic Clock 2 Status Position */
#define PMC_GCSR0_GPID2_Msk                   (_U_(0x1) << PMC_GCSR0_GPID2_Pos)                    /**< (PMC_GCSR0) Generic Clock 2 Status Mask */
#define PMC_GCSR0_GPID2(value)                (PMC_GCSR0_GPID2_Msk & ((value) << PMC_GCSR0_GPID2_Pos))
#define PMC_GCSR0_GPID3_Pos                   _U_(3)                                               /**< (PMC_GCSR0) Generic Clock 3 Status Position */
#define PMC_GCSR0_GPID3_Msk                   (_U_(0x1) << PMC_GCSR0_GPID3_Pos)                    /**< (PMC_GCSR0) Generic Clock 3 Status Mask */
#define PMC_GCSR0_GPID3(value)                (PMC_GCSR0_GPID3_Msk & ((value) << PMC_GCSR0_GPID3_Pos))
#define PMC_GCSR0_GPID4_Pos                   _U_(4)                                               /**< (PMC_GCSR0) Generic Clock 4 Status Position */
#define PMC_GCSR0_GPID4_Msk                   (_U_(0x1) << PMC_GCSR0_GPID4_Pos)                    /**< (PMC_GCSR0) Generic Clock 4 Status Mask */
#define PMC_GCSR0_GPID4(value)                (PMC_GCSR0_GPID4_Msk & ((value) << PMC_GCSR0_GPID4_Pos))
#define PMC_GCSR0_GPID5_Pos                   _U_(5)                                               /**< (PMC_GCSR0) Generic Clock 5 Status Position */
#define PMC_GCSR0_GPID5_Msk                   (_U_(0x1) << PMC_GCSR0_GPID5_Pos)                    /**< (PMC_GCSR0) Generic Clock 5 Status Mask */
#define PMC_GCSR0_GPID5(value)                (PMC_GCSR0_GPID5_Msk & ((value) << PMC_GCSR0_GPID5_Pos))
#define PMC_GCSR0_GPID6_Pos                   _U_(6)                                               /**< (PMC_GCSR0) Generic Clock 6 Status Position */
#define PMC_GCSR0_GPID6_Msk                   (_U_(0x1) << PMC_GCSR0_GPID6_Pos)                    /**< (PMC_GCSR0) Generic Clock 6 Status Mask */
#define PMC_GCSR0_GPID6(value)                (PMC_GCSR0_GPID6_Msk & ((value) << PMC_GCSR0_GPID6_Pos))
#define PMC_GCSR0_GPID7_Pos                   _U_(7)                                               /**< (PMC_GCSR0) Generic Clock 7 Status Position */
#define PMC_GCSR0_GPID7_Msk                   (_U_(0x1) << PMC_GCSR0_GPID7_Pos)                    /**< (PMC_GCSR0) Generic Clock 7 Status Mask */
#define PMC_GCSR0_GPID7(value)                (PMC_GCSR0_GPID7_Msk & ((value) << PMC_GCSR0_GPID7_Pos))
#define PMC_GCSR0_GPID8_Pos                   _U_(8)                                               /**< (PMC_GCSR0) Generic Clock 8 Status Position */
#define PMC_GCSR0_GPID8_Msk                   (_U_(0x1) << PMC_GCSR0_GPID8_Pos)                    /**< (PMC_GCSR0) Generic Clock 8 Status Mask */
#define PMC_GCSR0_GPID8(value)                (PMC_GCSR0_GPID8_Msk & ((value) << PMC_GCSR0_GPID8_Pos))
#define PMC_GCSR0_GPID9_Pos                   _U_(9)                                               /**< (PMC_GCSR0) Generic Clock 9 Status Position */
#define PMC_GCSR0_GPID9_Msk                   (_U_(0x1) << PMC_GCSR0_GPID9_Pos)                    /**< (PMC_GCSR0) Generic Clock 9 Status Mask */
#define PMC_GCSR0_GPID9(value)                (PMC_GCSR0_GPID9_Msk & ((value) << PMC_GCSR0_GPID9_Pos))
#define PMC_GCSR0_GPID10_Pos                  _U_(10)                                              /**< (PMC_GCSR0) Generic Clock 10 Status Position */
#define PMC_GCSR0_GPID10_Msk                  (_U_(0x1) << PMC_GCSR0_GPID10_Pos)                   /**< (PMC_GCSR0) Generic Clock 10 Status Mask */
#define PMC_GCSR0_GPID10(value)               (PMC_GCSR0_GPID10_Msk & ((value) << PMC_GCSR0_GPID10_Pos))
#define PMC_GCSR0_GPID11_Pos                  _U_(11)                                              /**< (PMC_GCSR0) Generic Clock 11 Status Position */
#define PMC_GCSR0_GPID11_Msk                  (_U_(0x1) << PMC_GCSR0_GPID11_Pos)                   /**< (PMC_GCSR0) Generic Clock 11 Status Mask */
#define PMC_GCSR0_GPID11(value)               (PMC_GCSR0_GPID11_Msk & ((value) << PMC_GCSR0_GPID11_Pos))
#define PMC_GCSR0_GPID12_Pos                  _U_(12)                                              /**< (PMC_GCSR0) Generic Clock 12 Status Position */
#define PMC_GCSR0_GPID12_Msk                  (_U_(0x1) << PMC_GCSR0_GPID12_Pos)                   /**< (PMC_GCSR0) Generic Clock 12 Status Mask */
#define PMC_GCSR0_GPID12(value)               (PMC_GCSR0_GPID12_Msk & ((value) << PMC_GCSR0_GPID12_Pos))
#define PMC_GCSR0_GPID13_Pos                  _U_(13)                                              /**< (PMC_GCSR0) Generic Clock 13 Status Position */
#define PMC_GCSR0_GPID13_Msk                  (_U_(0x1) << PMC_GCSR0_GPID13_Pos)                   /**< (PMC_GCSR0) Generic Clock 13 Status Mask */
#define PMC_GCSR0_GPID13(value)               (PMC_GCSR0_GPID13_Msk & ((value) << PMC_GCSR0_GPID13_Pos))
#define PMC_GCSR0_GPID14_Pos                  _U_(14)                                              /**< (PMC_GCSR0) Generic Clock 14 Status Position */
#define PMC_GCSR0_GPID14_Msk                  (_U_(0x1) << PMC_GCSR0_GPID14_Pos)                   /**< (PMC_GCSR0) Generic Clock 14 Status Mask */
#define PMC_GCSR0_GPID14(value)               (PMC_GCSR0_GPID14_Msk & ((value) << PMC_GCSR0_GPID14_Pos))
#define PMC_GCSR0_GPID15_Pos                  _U_(15)                                              /**< (PMC_GCSR0) Generic Clock 15 Status Position */
#define PMC_GCSR0_GPID15_Msk                  (_U_(0x1) << PMC_GCSR0_GPID15_Pos)                   /**< (PMC_GCSR0) Generic Clock 15 Status Mask */
#define PMC_GCSR0_GPID15(value)               (PMC_GCSR0_GPID15_Msk & ((value) << PMC_GCSR0_GPID15_Pos))
#define PMC_GCSR0_GPID16_Pos                  _U_(16)                                              /**< (PMC_GCSR0) Generic Clock 16 Status Position */
#define PMC_GCSR0_GPID16_Msk                  (_U_(0x1) << PMC_GCSR0_GPID16_Pos)                   /**< (PMC_GCSR0) Generic Clock 16 Status Mask */
#define PMC_GCSR0_GPID16(value)               (PMC_GCSR0_GPID16_Msk & ((value) << PMC_GCSR0_GPID16_Pos))
#define PMC_GCSR0_GPID17_Pos                  _U_(17)                                              /**< (PMC_GCSR0) Generic Clock 17 Status Position */
#define PMC_GCSR0_GPID17_Msk                  (_U_(0x1) << PMC_GCSR0_GPID17_Pos)                   /**< (PMC_GCSR0) Generic Clock 17 Status Mask */
#define PMC_GCSR0_GPID17(value)               (PMC_GCSR0_GPID17_Msk & ((value) << PMC_GCSR0_GPID17_Pos))
#define PMC_GCSR0_GPID18_Pos                  _U_(18)                                              /**< (PMC_GCSR0) Generic Clock 18 Status Position */
#define PMC_GCSR0_GPID18_Msk                  (_U_(0x1) << PMC_GCSR0_GPID18_Pos)                   /**< (PMC_GCSR0) Generic Clock 18 Status Mask */
#define PMC_GCSR0_GPID18(value)               (PMC_GCSR0_GPID18_Msk & ((value) << PMC_GCSR0_GPID18_Pos))
#define PMC_GCSR0_GPID19_Pos                  _U_(19)                                              /**< (PMC_GCSR0) Generic Clock 19 Status Position */
#define PMC_GCSR0_GPID19_Msk                  (_U_(0x1) << PMC_GCSR0_GPID19_Pos)                   /**< (PMC_GCSR0) Generic Clock 19 Status Mask */
#define PMC_GCSR0_GPID19(value)               (PMC_GCSR0_GPID19_Msk & ((value) << PMC_GCSR0_GPID19_Pos))
#define PMC_GCSR0_GPID20_Pos                  _U_(20)                                              /**< (PMC_GCSR0) Generic Clock 20 Status Position */
#define PMC_GCSR0_GPID20_Msk                  (_U_(0x1) << PMC_GCSR0_GPID20_Pos)                   /**< (PMC_GCSR0) Generic Clock 20 Status Mask */
#define PMC_GCSR0_GPID20(value)               (PMC_GCSR0_GPID20_Msk & ((value) << PMC_GCSR0_GPID20_Pos))
#define PMC_GCSR0_GPID21_Pos                  _U_(21)                                              /**< (PMC_GCSR0) Generic Clock 21 Status Position */
#define PMC_GCSR0_GPID21_Msk                  (_U_(0x1) << PMC_GCSR0_GPID21_Pos)                   /**< (PMC_GCSR0) Generic Clock 21 Status Mask */
#define PMC_GCSR0_GPID21(value)               (PMC_GCSR0_GPID21_Msk & ((value) << PMC_GCSR0_GPID21_Pos))
#define PMC_GCSR0_GPID22_Pos                  _U_(22)                                              /**< (PMC_GCSR0) Generic Clock 22 Status Position */
#define PMC_GCSR0_GPID22_Msk                  (_U_(0x1) << PMC_GCSR0_GPID22_Pos)                   /**< (PMC_GCSR0) Generic Clock 22 Status Mask */
#define PMC_GCSR0_GPID22(value)               (PMC_GCSR0_GPID22_Msk & ((value) << PMC_GCSR0_GPID22_Pos))
#define PMC_GCSR0_GPID23_Pos                  _U_(23)                                              /**< (PMC_GCSR0) Generic Clock 23 Status Position */
#define PMC_GCSR0_GPID23_Msk                  (_U_(0x1) << PMC_GCSR0_GPID23_Pos)                   /**< (PMC_GCSR0) Generic Clock 23 Status Mask */
#define PMC_GCSR0_GPID23(value)               (PMC_GCSR0_GPID23_Msk & ((value) << PMC_GCSR0_GPID23_Pos))
#define PMC_GCSR0_GPID24_Pos                  _U_(24)                                              /**< (PMC_GCSR0) Generic Clock 24 Status Position */
#define PMC_GCSR0_GPID24_Msk                  (_U_(0x1) << PMC_GCSR0_GPID24_Pos)                   /**< (PMC_GCSR0) Generic Clock 24 Status Mask */
#define PMC_GCSR0_GPID24(value)               (PMC_GCSR0_GPID24_Msk & ((value) << PMC_GCSR0_GPID24_Pos))
#define PMC_GCSR0_GPID25_Pos                  _U_(25)                                              /**< (PMC_GCSR0) Generic Clock 25 Status Position */
#define PMC_GCSR0_GPID25_Msk                  (_U_(0x1) << PMC_GCSR0_GPID25_Pos)                   /**< (PMC_GCSR0) Generic Clock 25 Status Mask */
#define PMC_GCSR0_GPID25(value)               (PMC_GCSR0_GPID25_Msk & ((value) << PMC_GCSR0_GPID25_Pos))
#define PMC_GCSR0_GPID26_Pos                  _U_(26)                                              /**< (PMC_GCSR0) Generic Clock 26 Status Position */
#define PMC_GCSR0_GPID26_Msk                  (_U_(0x1) << PMC_GCSR0_GPID26_Pos)                   /**< (PMC_GCSR0) Generic Clock 26 Status Mask */
#define PMC_GCSR0_GPID26(value)               (PMC_GCSR0_GPID26_Msk & ((value) << PMC_GCSR0_GPID26_Pos))
#define PMC_GCSR0_GPID27_Pos                  _U_(27)                                              /**< (PMC_GCSR0) Generic Clock 27 Status Position */
#define PMC_GCSR0_GPID27_Msk                  (_U_(0x1) << PMC_GCSR0_GPID27_Pos)                   /**< (PMC_GCSR0) Generic Clock 27 Status Mask */
#define PMC_GCSR0_GPID27(value)               (PMC_GCSR0_GPID27_Msk & ((value) << PMC_GCSR0_GPID27_Pos))
#define PMC_GCSR0_GPID28_Pos                  _U_(28)                                              /**< (PMC_GCSR0) Generic Clock 28 Status Position */
#define PMC_GCSR0_GPID28_Msk                  (_U_(0x1) << PMC_GCSR0_GPID28_Pos)                   /**< (PMC_GCSR0) Generic Clock 28 Status Mask */
#define PMC_GCSR0_GPID28(value)               (PMC_GCSR0_GPID28_Msk & ((value) << PMC_GCSR0_GPID28_Pos))
#define PMC_GCSR0_GPID29_Pos                  _U_(29)                                              /**< (PMC_GCSR0) Generic Clock 29 Status Position */
#define PMC_GCSR0_GPID29_Msk                  (_U_(0x1) << PMC_GCSR0_GPID29_Pos)                   /**< (PMC_GCSR0) Generic Clock 29 Status Mask */
#define PMC_GCSR0_GPID29(value)               (PMC_GCSR0_GPID29_Msk & ((value) << PMC_GCSR0_GPID29_Pos))
#define PMC_GCSR0_GPID30_Pos                  _U_(30)                                              /**< (PMC_GCSR0) Generic Clock 30 Status Position */
#define PMC_GCSR0_GPID30_Msk                  (_U_(0x1) << PMC_GCSR0_GPID30_Pos)                   /**< (PMC_GCSR0) Generic Clock 30 Status Mask */
#define PMC_GCSR0_GPID30(value)               (PMC_GCSR0_GPID30_Msk & ((value) << PMC_GCSR0_GPID30_Pos))
#define PMC_GCSR0_GPID31_Pos                  _U_(31)                                              /**< (PMC_GCSR0) Generic Clock 31 Status Position */
#define PMC_GCSR0_GPID31_Msk                  (_U_(0x1) << PMC_GCSR0_GPID31_Pos)                   /**< (PMC_GCSR0) Generic Clock 31 Status Mask */
#define PMC_GCSR0_GPID31(value)               (PMC_GCSR0_GPID31_Msk & ((value) << PMC_GCSR0_GPID31_Pos))
#define PMC_GCSR0_Msk                         _U_(0xFFFFFFFF)                                      /**< (PMC_GCSR0) Register Mask  */

#define PMC_GCSR0_GPID_Pos                    _U_(0)                                               /**< (PMC_GCSR0 Position) Generic Clock 3x Status */
#define PMC_GCSR0_GPID_Msk                    (_U_(0xFFFFFFFF) << PMC_GCSR0_GPID_Pos)              /**< (PMC_GCSR0 Mask) GPID */
#define PMC_GCSR0_GPID(value)                 (PMC_GCSR0_GPID_Msk & ((value) << PMC_GCSR0_GPID_Pos)) 

/* -------- PMC_GCSR1 : (PMC Offset: 0x194) ( R/ 32) Generic Clock Status Register 1 -------- */
#define PMC_GCSR1_GPID32_Pos                  _U_(0)                                               /**< (PMC_GCSR1) Generic Clock 32 Status Position */
#define PMC_GCSR1_GPID32_Msk                  (_U_(0x1) << PMC_GCSR1_GPID32_Pos)                   /**< (PMC_GCSR1) Generic Clock 32 Status Mask */
#define PMC_GCSR1_GPID32(value)               (PMC_GCSR1_GPID32_Msk & ((value) << PMC_GCSR1_GPID32_Pos))
#define PMC_GCSR1_GPID33_Pos                  _U_(1)                                               /**< (PMC_GCSR1) Generic Clock 33 Status Position */
#define PMC_GCSR1_GPID33_Msk                  (_U_(0x1) << PMC_GCSR1_GPID33_Pos)                   /**< (PMC_GCSR1) Generic Clock 33 Status Mask */
#define PMC_GCSR1_GPID33(value)               (PMC_GCSR1_GPID33_Msk & ((value) << PMC_GCSR1_GPID33_Pos))
#define PMC_GCSR1_GPID34_Pos                  _U_(2)                                               /**< (PMC_GCSR1) Generic Clock 34 Status Position */
#define PMC_GCSR1_GPID34_Msk                  (_U_(0x1) << PMC_GCSR1_GPID34_Pos)                   /**< (PMC_GCSR1) Generic Clock 34 Status Mask */
#define PMC_GCSR1_GPID34(value)               (PMC_GCSR1_GPID34_Msk & ((value) << PMC_GCSR1_GPID34_Pos))
#define PMC_GCSR1_GPID35_Pos                  _U_(3)                                               /**< (PMC_GCSR1) Generic Clock 35 Status Position */
#define PMC_GCSR1_GPID35_Msk                  (_U_(0x1) << PMC_GCSR1_GPID35_Pos)                   /**< (PMC_GCSR1) Generic Clock 35 Status Mask */
#define PMC_GCSR1_GPID35(value)               (PMC_GCSR1_GPID35_Msk & ((value) << PMC_GCSR1_GPID35_Pos))
#define PMC_GCSR1_GPID36_Pos                  _U_(4)                                               /**< (PMC_GCSR1) Generic Clock 36 Status Position */
#define PMC_GCSR1_GPID36_Msk                  (_U_(0x1) << PMC_GCSR1_GPID36_Pos)                   /**< (PMC_GCSR1) Generic Clock 36 Status Mask */
#define PMC_GCSR1_GPID36(value)               (PMC_GCSR1_GPID36_Msk & ((value) << PMC_GCSR1_GPID36_Pos))
#define PMC_GCSR1_GPID37_Pos                  _U_(5)                                               /**< (PMC_GCSR1) Generic Clock 37 Status Position */
#define PMC_GCSR1_GPID37_Msk                  (_U_(0x1) << PMC_GCSR1_GPID37_Pos)                   /**< (PMC_GCSR1) Generic Clock 37 Status Mask */
#define PMC_GCSR1_GPID37(value)               (PMC_GCSR1_GPID37_Msk & ((value) << PMC_GCSR1_GPID37_Pos))
#define PMC_GCSR1_GPID38_Pos                  _U_(6)                                               /**< (PMC_GCSR1) Generic Clock 38 Status Position */
#define PMC_GCSR1_GPID38_Msk                  (_U_(0x1) << PMC_GCSR1_GPID38_Pos)                   /**< (PMC_GCSR1) Generic Clock 38 Status Mask */
#define PMC_GCSR1_GPID38(value)               (PMC_GCSR1_GPID38_Msk & ((value) << PMC_GCSR1_GPID38_Pos))
#define PMC_GCSR1_GPID39_Pos                  _U_(7)                                               /**< (PMC_GCSR1) Generic Clock 39 Status Position */
#define PMC_GCSR1_GPID39_Msk                  (_U_(0x1) << PMC_GCSR1_GPID39_Pos)                   /**< (PMC_GCSR1) Generic Clock 39 Status Mask */
#define PMC_GCSR1_GPID39(value)               (PMC_GCSR1_GPID39_Msk & ((value) << PMC_GCSR1_GPID39_Pos))
#define PMC_GCSR1_GPID40_Pos                  _U_(8)                                               /**< (PMC_GCSR1) Generic Clock 40 Status Position */
#define PMC_GCSR1_GPID40_Msk                  (_U_(0x1) << PMC_GCSR1_GPID40_Pos)                   /**< (PMC_GCSR1) Generic Clock 40 Status Mask */
#define PMC_GCSR1_GPID40(value)               (PMC_GCSR1_GPID40_Msk & ((value) << PMC_GCSR1_GPID40_Pos))
#define PMC_GCSR1_GPID41_Pos                  _U_(9)                                               /**< (PMC_GCSR1) Generic Clock 41 Status Position */
#define PMC_GCSR1_GPID41_Msk                  (_U_(0x1) << PMC_GCSR1_GPID41_Pos)                   /**< (PMC_GCSR1) Generic Clock 41 Status Mask */
#define PMC_GCSR1_GPID41(value)               (PMC_GCSR1_GPID41_Msk & ((value) << PMC_GCSR1_GPID41_Pos))
#define PMC_GCSR1_GPID42_Pos                  _U_(10)                                              /**< (PMC_GCSR1) Generic Clock 42 Status Position */
#define PMC_GCSR1_GPID42_Msk                  (_U_(0x1) << PMC_GCSR1_GPID42_Pos)                   /**< (PMC_GCSR1) Generic Clock 42 Status Mask */
#define PMC_GCSR1_GPID42(value)               (PMC_GCSR1_GPID42_Msk & ((value) << PMC_GCSR1_GPID42_Pos))
#define PMC_GCSR1_GPID43_Pos                  _U_(11)                                              /**< (PMC_GCSR1) Generic Clock 43 Status Position */
#define PMC_GCSR1_GPID43_Msk                  (_U_(0x1) << PMC_GCSR1_GPID43_Pos)                   /**< (PMC_GCSR1) Generic Clock 43 Status Mask */
#define PMC_GCSR1_GPID43(value)               (PMC_GCSR1_GPID43_Msk & ((value) << PMC_GCSR1_GPID43_Pos))
#define PMC_GCSR1_GPID44_Pos                  _U_(12)                                              /**< (PMC_GCSR1) Generic Clock 44 Status Position */
#define PMC_GCSR1_GPID44_Msk                  (_U_(0x1) << PMC_GCSR1_GPID44_Pos)                   /**< (PMC_GCSR1) Generic Clock 44 Status Mask */
#define PMC_GCSR1_GPID44(value)               (PMC_GCSR1_GPID44_Msk & ((value) << PMC_GCSR1_GPID44_Pos))
#define PMC_GCSR1_GPID45_Pos                  _U_(13)                                              /**< (PMC_GCSR1) Generic Clock 45 Status Position */
#define PMC_GCSR1_GPID45_Msk                  (_U_(0x1) << PMC_GCSR1_GPID45_Pos)                   /**< (PMC_GCSR1) Generic Clock 45 Status Mask */
#define PMC_GCSR1_GPID45(value)               (PMC_GCSR1_GPID45_Msk & ((value) << PMC_GCSR1_GPID45_Pos))
#define PMC_GCSR1_GPID46_Pos                  _U_(14)                                              /**< (PMC_GCSR1) Generic Clock 46 Status Position */
#define PMC_GCSR1_GPID46_Msk                  (_U_(0x1) << PMC_GCSR1_GPID46_Pos)                   /**< (PMC_GCSR1) Generic Clock 46 Status Mask */
#define PMC_GCSR1_GPID46(value)               (PMC_GCSR1_GPID46_Msk & ((value) << PMC_GCSR1_GPID46_Pos))
#define PMC_GCSR1_GPID47_Pos                  _U_(15)                                              /**< (PMC_GCSR1) Generic Clock 47 Status Position */
#define PMC_GCSR1_GPID47_Msk                  (_U_(0x1) << PMC_GCSR1_GPID47_Pos)                   /**< (PMC_GCSR1) Generic Clock 47 Status Mask */
#define PMC_GCSR1_GPID47(value)               (PMC_GCSR1_GPID47_Msk & ((value) << PMC_GCSR1_GPID47_Pos))
#define PMC_GCSR1_GPID48_Pos                  _U_(16)                                              /**< (PMC_GCSR1) Generic Clock 48 Status Position */
#define PMC_GCSR1_GPID48_Msk                  (_U_(0x1) << PMC_GCSR1_GPID48_Pos)                   /**< (PMC_GCSR1) Generic Clock 48 Status Mask */
#define PMC_GCSR1_GPID48(value)               (PMC_GCSR1_GPID48_Msk & ((value) << PMC_GCSR1_GPID48_Pos))
#define PMC_GCSR1_GPID49_Pos                  _U_(17)                                              /**< (PMC_GCSR1) Generic Clock 49 Status Position */
#define PMC_GCSR1_GPID49_Msk                  (_U_(0x1) << PMC_GCSR1_GPID49_Pos)                   /**< (PMC_GCSR1) Generic Clock 49 Status Mask */
#define PMC_GCSR1_GPID49(value)               (PMC_GCSR1_GPID49_Msk & ((value) << PMC_GCSR1_GPID49_Pos))
#define PMC_GCSR1_GPID50_Pos                  _U_(18)                                              /**< (PMC_GCSR1) Generic Clock 50 Status Position */
#define PMC_GCSR1_GPID50_Msk                  (_U_(0x1) << PMC_GCSR1_GPID50_Pos)                   /**< (PMC_GCSR1) Generic Clock 50 Status Mask */
#define PMC_GCSR1_GPID50(value)               (PMC_GCSR1_GPID50_Msk & ((value) << PMC_GCSR1_GPID50_Pos))
#define PMC_GCSR1_GPID51_Pos                  _U_(19)                                              /**< (PMC_GCSR1) Generic Clock 51 Status Position */
#define PMC_GCSR1_GPID51_Msk                  (_U_(0x1) << PMC_GCSR1_GPID51_Pos)                   /**< (PMC_GCSR1) Generic Clock 51 Status Mask */
#define PMC_GCSR1_GPID51(value)               (PMC_GCSR1_GPID51_Msk & ((value) << PMC_GCSR1_GPID51_Pos))
#define PMC_GCSR1_GPID52_Pos                  _U_(20)                                              /**< (PMC_GCSR1) Generic Clock 52 Status Position */
#define PMC_GCSR1_GPID52_Msk                  (_U_(0x1) << PMC_GCSR1_GPID52_Pos)                   /**< (PMC_GCSR1) Generic Clock 52 Status Mask */
#define PMC_GCSR1_GPID52(value)               (PMC_GCSR1_GPID52_Msk & ((value) << PMC_GCSR1_GPID52_Pos))
#define PMC_GCSR1_GPID53_Pos                  _U_(21)                                              /**< (PMC_GCSR1) Generic Clock 53 Status Position */
#define PMC_GCSR1_GPID53_Msk                  (_U_(0x1) << PMC_GCSR1_GPID53_Pos)                   /**< (PMC_GCSR1) Generic Clock 53 Status Mask */
#define PMC_GCSR1_GPID53(value)               (PMC_GCSR1_GPID53_Msk & ((value) << PMC_GCSR1_GPID53_Pos))
#define PMC_GCSR1_GPID54_Pos                  _U_(22)                                              /**< (PMC_GCSR1) Generic Clock 54 Status Position */
#define PMC_GCSR1_GPID54_Msk                  (_U_(0x1) << PMC_GCSR1_GPID54_Pos)                   /**< (PMC_GCSR1) Generic Clock 54 Status Mask */
#define PMC_GCSR1_GPID54(value)               (PMC_GCSR1_GPID54_Msk & ((value) << PMC_GCSR1_GPID54_Pos))
#define PMC_GCSR1_GPID55_Pos                  _U_(23)                                              /**< (PMC_GCSR1) Generic Clock 55 Status Position */
#define PMC_GCSR1_GPID55_Msk                  (_U_(0x1) << PMC_GCSR1_GPID55_Pos)                   /**< (PMC_GCSR1) Generic Clock 55 Status Mask */
#define PMC_GCSR1_GPID55(value)               (PMC_GCSR1_GPID55_Msk & ((value) << PMC_GCSR1_GPID55_Pos))
#define PMC_GCSR1_GPID56_Pos                  _U_(24)                                              /**< (PMC_GCSR1) Generic Clock 56 Status Position */
#define PMC_GCSR1_GPID56_Msk                  (_U_(0x1) << PMC_GCSR1_GPID56_Pos)                   /**< (PMC_GCSR1) Generic Clock 56 Status Mask */
#define PMC_GCSR1_GPID56(value)               (PMC_GCSR1_GPID56_Msk & ((value) << PMC_GCSR1_GPID56_Pos))
#define PMC_GCSR1_GPID57_Pos                  _U_(25)                                              /**< (PMC_GCSR1) Generic Clock 57 Status Position */
#define PMC_GCSR1_GPID57_Msk                  (_U_(0x1) << PMC_GCSR1_GPID57_Pos)                   /**< (PMC_GCSR1) Generic Clock 57 Status Mask */
#define PMC_GCSR1_GPID57(value)               (PMC_GCSR1_GPID57_Msk & ((value) << PMC_GCSR1_GPID57_Pos))
#define PMC_GCSR1_GPID58_Pos                  _U_(26)                                              /**< (PMC_GCSR1) Generic Clock 58 Status Position */
#define PMC_GCSR1_GPID58_Msk                  (_U_(0x1) << PMC_GCSR1_GPID58_Pos)                   /**< (PMC_GCSR1) Generic Clock 58 Status Mask */
#define PMC_GCSR1_GPID58(value)               (PMC_GCSR1_GPID58_Msk & ((value) << PMC_GCSR1_GPID58_Pos))
#define PMC_GCSR1_GPID59_Pos                  _U_(27)                                              /**< (PMC_GCSR1) Generic Clock 59 Status Position */
#define PMC_GCSR1_GPID59_Msk                  (_U_(0x1) << PMC_GCSR1_GPID59_Pos)                   /**< (PMC_GCSR1) Generic Clock 59 Status Mask */
#define PMC_GCSR1_GPID59(value)               (PMC_GCSR1_GPID59_Msk & ((value) << PMC_GCSR1_GPID59_Pos))
#define PMC_GCSR1_GPID60_Pos                  _U_(28)                                              /**< (PMC_GCSR1) Generic Clock 60 Status Position */
#define PMC_GCSR1_GPID60_Msk                  (_U_(0x1) << PMC_GCSR1_GPID60_Pos)                   /**< (PMC_GCSR1) Generic Clock 60 Status Mask */
#define PMC_GCSR1_GPID60(value)               (PMC_GCSR1_GPID60_Msk & ((value) << PMC_GCSR1_GPID60_Pos))
#define PMC_GCSR1_GPID61_Pos                  _U_(29)                                              /**< (PMC_GCSR1) Generic Clock 61 Status Position */
#define PMC_GCSR1_GPID61_Msk                  (_U_(0x1) << PMC_GCSR1_GPID61_Pos)                   /**< (PMC_GCSR1) Generic Clock 61 Status Mask */
#define PMC_GCSR1_GPID61(value)               (PMC_GCSR1_GPID61_Msk & ((value) << PMC_GCSR1_GPID61_Pos))
#define PMC_GCSR1_GPID62_Pos                  _U_(30)                                              /**< (PMC_GCSR1) Generic Clock 62 Status Position */
#define PMC_GCSR1_GPID62_Msk                  (_U_(0x1) << PMC_GCSR1_GPID62_Pos)                   /**< (PMC_GCSR1) Generic Clock 62 Status Mask */
#define PMC_GCSR1_GPID62(value)               (PMC_GCSR1_GPID62_Msk & ((value) << PMC_GCSR1_GPID62_Pos))
#define PMC_GCSR1_GPID63_Pos                  _U_(31)                                              /**< (PMC_GCSR1) Generic Clock 63 Status Position */
#define PMC_GCSR1_GPID63_Msk                  (_U_(0x1) << PMC_GCSR1_GPID63_Pos)                   /**< (PMC_GCSR1) Generic Clock 63 Status Mask */
#define PMC_GCSR1_GPID63(value)               (PMC_GCSR1_GPID63_Msk & ((value) << PMC_GCSR1_GPID63_Pos))
#define PMC_GCSR1_Msk                         _U_(0xFFFFFFFF)                                      /**< (PMC_GCSR1) Register Mask  */

#define PMC_GCSR1_GPID_Pos                    _U_(0)                                               /**< (PMC_GCSR1 Position) Generic Clock 63 Status */
#define PMC_GCSR1_GPID_Msk                    (_U_(0xFFFFFFFF) << PMC_GCSR1_GPID_Pos)              /**< (PMC_GCSR1 Mask) GPID */
#define PMC_GCSR1_GPID(value)                 (PMC_GCSR1_GPID_Msk & ((value) << PMC_GCSR1_GPID_Pos)) 

/* -------- PMC_GCSR2 : (PMC Offset: 0x198) ( R/ 32) Generic Clock Status Register 2 -------- */
#define PMC_GCSR2_GPID64_Pos                  _U_(0)                                               /**< (PMC_GCSR2) Generic Clock 64 Status Position */
#define PMC_GCSR2_GPID64_Msk                  (_U_(0x1) << PMC_GCSR2_GPID64_Pos)                   /**< (PMC_GCSR2) Generic Clock 64 Status Mask */
#define PMC_GCSR2_GPID64(value)               (PMC_GCSR2_GPID64_Msk & ((value) << PMC_GCSR2_GPID64_Pos))
#define PMC_GCSR2_GPID65_Pos                  _U_(1)                                               /**< (PMC_GCSR2) Generic Clock 65 Status Position */
#define PMC_GCSR2_GPID65_Msk                  (_U_(0x1) << PMC_GCSR2_GPID65_Pos)                   /**< (PMC_GCSR2) Generic Clock 65 Status Mask */
#define PMC_GCSR2_GPID65(value)               (PMC_GCSR2_GPID65_Msk & ((value) << PMC_GCSR2_GPID65_Pos))
#define PMC_GCSR2_GPID66_Pos                  _U_(2)                                               /**< (PMC_GCSR2) Generic Clock 66 Status Position */
#define PMC_GCSR2_GPID66_Msk                  (_U_(0x1) << PMC_GCSR2_GPID66_Pos)                   /**< (PMC_GCSR2) Generic Clock 66 Status Mask */
#define PMC_GCSR2_GPID66(value)               (PMC_GCSR2_GPID66_Msk & ((value) << PMC_GCSR2_GPID66_Pos))
#define PMC_GCSR2_GPID67_Pos                  _U_(3)                                               /**< (PMC_GCSR2) Generic Clock 67 Status Position */
#define PMC_GCSR2_GPID67_Msk                  (_U_(0x1) << PMC_GCSR2_GPID67_Pos)                   /**< (PMC_GCSR2) Generic Clock 67 Status Mask */
#define PMC_GCSR2_GPID67(value)               (PMC_GCSR2_GPID67_Msk & ((value) << PMC_GCSR2_GPID67_Pos))
#define PMC_GCSR2_GPID68_Pos                  _U_(4)                                               /**< (PMC_GCSR2) Generic Clock 68 Status Position */
#define PMC_GCSR2_GPID68_Msk                  (_U_(0x1) << PMC_GCSR2_GPID68_Pos)                   /**< (PMC_GCSR2) Generic Clock 68 Status Mask */
#define PMC_GCSR2_GPID68(value)               (PMC_GCSR2_GPID68_Msk & ((value) << PMC_GCSR2_GPID68_Pos))
#define PMC_GCSR2_GPID69_Pos                  _U_(5)                                               /**< (PMC_GCSR2) Generic Clock 69 Status Position */
#define PMC_GCSR2_GPID69_Msk                  (_U_(0x1) << PMC_GCSR2_GPID69_Pos)                   /**< (PMC_GCSR2) Generic Clock 69 Status Mask */
#define PMC_GCSR2_GPID69(value)               (PMC_GCSR2_GPID69_Msk & ((value) << PMC_GCSR2_GPID69_Pos))
#define PMC_GCSR2_GPID70_Pos                  _U_(6)                                               /**< (PMC_GCSR2) Generic Clock 70 Status Position */
#define PMC_GCSR2_GPID70_Msk                  (_U_(0x1) << PMC_GCSR2_GPID70_Pos)                   /**< (PMC_GCSR2) Generic Clock 70 Status Mask */
#define PMC_GCSR2_GPID70(value)               (PMC_GCSR2_GPID70_Msk & ((value) << PMC_GCSR2_GPID70_Pos))
#define PMC_GCSR2_GPID71_Pos                  _U_(7)                                               /**< (PMC_GCSR2) Generic Clock 71 Status Position */
#define PMC_GCSR2_GPID71_Msk                  (_U_(0x1) << PMC_GCSR2_GPID71_Pos)                   /**< (PMC_GCSR2) Generic Clock 71 Status Mask */
#define PMC_GCSR2_GPID71(value)               (PMC_GCSR2_GPID71_Msk & ((value) << PMC_GCSR2_GPID71_Pos))
#define PMC_GCSR2_GPID72_Pos                  _U_(8)                                               /**< (PMC_GCSR2) Generic Clock 72 Status Position */
#define PMC_GCSR2_GPID72_Msk                  (_U_(0x1) << PMC_GCSR2_GPID72_Pos)                   /**< (PMC_GCSR2) Generic Clock 72 Status Mask */
#define PMC_GCSR2_GPID72(value)               (PMC_GCSR2_GPID72_Msk & ((value) << PMC_GCSR2_GPID72_Pos))
#define PMC_GCSR2_GPID73_Pos                  _U_(9)                                               /**< (PMC_GCSR2) Generic Clock 73 Status Position */
#define PMC_GCSR2_GPID73_Msk                  (_U_(0x1) << PMC_GCSR2_GPID73_Pos)                   /**< (PMC_GCSR2) Generic Clock 73 Status Mask */
#define PMC_GCSR2_GPID73(value)               (PMC_GCSR2_GPID73_Msk & ((value) << PMC_GCSR2_GPID73_Pos))
#define PMC_GCSR2_GPID74_Pos                  _U_(10)                                              /**< (PMC_GCSR2) Generic Clock 74 Status Position */
#define PMC_GCSR2_GPID74_Msk                  (_U_(0x1) << PMC_GCSR2_GPID74_Pos)                   /**< (PMC_GCSR2) Generic Clock 74 Status Mask */
#define PMC_GCSR2_GPID74(value)               (PMC_GCSR2_GPID74_Msk & ((value) << PMC_GCSR2_GPID74_Pos))
#define PMC_GCSR2_GPID75_Pos                  _U_(11)                                              /**< (PMC_GCSR2) Generic Clock 75 Status Position */
#define PMC_GCSR2_GPID75_Msk                  (_U_(0x1) << PMC_GCSR2_GPID75_Pos)                   /**< (PMC_GCSR2) Generic Clock 75 Status Mask */
#define PMC_GCSR2_GPID75(value)               (PMC_GCSR2_GPID75_Msk & ((value) << PMC_GCSR2_GPID75_Pos))
#define PMC_GCSR2_GPID76_Pos                  _U_(12)                                              /**< (PMC_GCSR2) Generic Clock 76 Status Position */
#define PMC_GCSR2_GPID76_Msk                  (_U_(0x1) << PMC_GCSR2_GPID76_Pos)                   /**< (PMC_GCSR2) Generic Clock 76 Status Mask */
#define PMC_GCSR2_GPID76(value)               (PMC_GCSR2_GPID76_Msk & ((value) << PMC_GCSR2_GPID76_Pos))
#define PMC_GCSR2_GPID77_Pos                  _U_(13)                                              /**< (PMC_GCSR2) Generic Clock 77 Status Position */
#define PMC_GCSR2_GPID77_Msk                  (_U_(0x1) << PMC_GCSR2_GPID77_Pos)                   /**< (PMC_GCSR2) Generic Clock 77 Status Mask */
#define PMC_GCSR2_GPID77(value)               (PMC_GCSR2_GPID77_Msk & ((value) << PMC_GCSR2_GPID77_Pos))
#define PMC_GCSR2_GPID78_Pos                  _U_(14)                                              /**< (PMC_GCSR2) Generic Clock 78 Status Position */
#define PMC_GCSR2_GPID78_Msk                  (_U_(0x1) << PMC_GCSR2_GPID78_Pos)                   /**< (PMC_GCSR2) Generic Clock 78 Status Mask */
#define PMC_GCSR2_GPID78(value)               (PMC_GCSR2_GPID78_Msk & ((value) << PMC_GCSR2_GPID78_Pos))
#define PMC_GCSR2_GPID79_Pos                  _U_(15)                                              /**< (PMC_GCSR2) Generic Clock 79 Status Position */
#define PMC_GCSR2_GPID79_Msk                  (_U_(0x1) << PMC_GCSR2_GPID79_Pos)                   /**< (PMC_GCSR2) Generic Clock 79 Status Mask */
#define PMC_GCSR2_GPID79(value)               (PMC_GCSR2_GPID79_Msk & ((value) << PMC_GCSR2_GPID79_Pos))
#define PMC_GCSR2_GPID80_Pos                  _U_(16)                                              /**< (PMC_GCSR2) Generic Clock 80 Status Position */
#define PMC_GCSR2_GPID80_Msk                  (_U_(0x1) << PMC_GCSR2_GPID80_Pos)                   /**< (PMC_GCSR2) Generic Clock 80 Status Mask */
#define PMC_GCSR2_GPID80(value)               (PMC_GCSR2_GPID80_Msk & ((value) << PMC_GCSR2_GPID80_Pos))
#define PMC_GCSR2_GPID81_Pos                  _U_(17)                                              /**< (PMC_GCSR2) Generic Clock 81 Status Position */
#define PMC_GCSR2_GPID81_Msk                  (_U_(0x1) << PMC_GCSR2_GPID81_Pos)                   /**< (PMC_GCSR2) Generic Clock 81 Status Mask */
#define PMC_GCSR2_GPID81(value)               (PMC_GCSR2_GPID81_Msk & ((value) << PMC_GCSR2_GPID81_Pos))
#define PMC_GCSR2_GPID82_Pos                  _U_(18)                                              /**< (PMC_GCSR2) Generic Clock 82 Status Position */
#define PMC_GCSR2_GPID82_Msk                  (_U_(0x1) << PMC_GCSR2_GPID82_Pos)                   /**< (PMC_GCSR2) Generic Clock 82 Status Mask */
#define PMC_GCSR2_GPID82(value)               (PMC_GCSR2_GPID82_Msk & ((value) << PMC_GCSR2_GPID82_Pos))
#define PMC_GCSR2_GPID83_Pos                  _U_(19)                                              /**< (PMC_GCSR2) Generic Clock 83 Status Position */
#define PMC_GCSR2_GPID83_Msk                  (_U_(0x1) << PMC_GCSR2_GPID83_Pos)                   /**< (PMC_GCSR2) Generic Clock 83 Status Mask */
#define PMC_GCSR2_GPID83(value)               (PMC_GCSR2_GPID83_Msk & ((value) << PMC_GCSR2_GPID83_Pos))
#define PMC_GCSR2_GPID84_Pos                  _U_(20)                                              /**< (PMC_GCSR2) Generic Clock 84 Status Position */
#define PMC_GCSR2_GPID84_Msk                  (_U_(0x1) << PMC_GCSR2_GPID84_Pos)                   /**< (PMC_GCSR2) Generic Clock 84 Status Mask */
#define PMC_GCSR2_GPID84(value)               (PMC_GCSR2_GPID84_Msk & ((value) << PMC_GCSR2_GPID84_Pos))
#define PMC_GCSR2_GPID85_Pos                  _U_(21)                                              /**< (PMC_GCSR2) Generic Clock 85 Status Position */
#define PMC_GCSR2_GPID85_Msk                  (_U_(0x1) << PMC_GCSR2_GPID85_Pos)                   /**< (PMC_GCSR2) Generic Clock 85 Status Mask */
#define PMC_GCSR2_GPID85(value)               (PMC_GCSR2_GPID85_Msk & ((value) << PMC_GCSR2_GPID85_Pos))
#define PMC_GCSR2_GPID86_Pos                  _U_(22)                                              /**< (PMC_GCSR2) Generic Clock 86 Status Position */
#define PMC_GCSR2_GPID86_Msk                  (_U_(0x1) << PMC_GCSR2_GPID86_Pos)                   /**< (PMC_GCSR2) Generic Clock 86 Status Mask */
#define PMC_GCSR2_GPID86(value)               (PMC_GCSR2_GPID86_Msk & ((value) << PMC_GCSR2_GPID86_Pos))
#define PMC_GCSR2_GPID87_Pos                  _U_(23)                                              /**< (PMC_GCSR2) Generic Clock 87 Status Position */
#define PMC_GCSR2_GPID87_Msk                  (_U_(0x1) << PMC_GCSR2_GPID87_Pos)                   /**< (PMC_GCSR2) Generic Clock 87 Status Mask */
#define PMC_GCSR2_GPID87(value)               (PMC_GCSR2_GPID87_Msk & ((value) << PMC_GCSR2_GPID87_Pos))
#define PMC_GCSR2_GPID88_Pos                  _U_(24)                                              /**< (PMC_GCSR2) Generic Clock 88 Status Position */
#define PMC_GCSR2_GPID88_Msk                  (_U_(0x1) << PMC_GCSR2_GPID88_Pos)                   /**< (PMC_GCSR2) Generic Clock 88 Status Mask */
#define PMC_GCSR2_GPID88(value)               (PMC_GCSR2_GPID88_Msk & ((value) << PMC_GCSR2_GPID88_Pos))
#define PMC_GCSR2_GPID89_Pos                  _U_(25)                                              /**< (PMC_GCSR2) Generic Clock 89 Status Position */
#define PMC_GCSR2_GPID89_Msk                  (_U_(0x1) << PMC_GCSR2_GPID89_Pos)                   /**< (PMC_GCSR2) Generic Clock 89 Status Mask */
#define PMC_GCSR2_GPID89(value)               (PMC_GCSR2_GPID89_Msk & ((value) << PMC_GCSR2_GPID89_Pos))
#define PMC_GCSR2_GPID90_Pos                  _U_(26)                                              /**< (PMC_GCSR2) Generic Clock 90 Status Position */
#define PMC_GCSR2_GPID90_Msk                  (_U_(0x1) << PMC_GCSR2_GPID90_Pos)                   /**< (PMC_GCSR2) Generic Clock 90 Status Mask */
#define PMC_GCSR2_GPID90(value)               (PMC_GCSR2_GPID90_Msk & ((value) << PMC_GCSR2_GPID90_Pos))
#define PMC_GCSR2_GPID91_Pos                  _U_(27)                                              /**< (PMC_GCSR2) Generic Clock 91 Status Position */
#define PMC_GCSR2_GPID91_Msk                  (_U_(0x1) << PMC_GCSR2_GPID91_Pos)                   /**< (PMC_GCSR2) Generic Clock 91 Status Mask */
#define PMC_GCSR2_GPID91(value)               (PMC_GCSR2_GPID91_Msk & ((value) << PMC_GCSR2_GPID91_Pos))
#define PMC_GCSR2_GPID92_Pos                  _U_(28)                                              /**< (PMC_GCSR2) Generic Clock 92 Status Position */
#define PMC_GCSR2_GPID92_Msk                  (_U_(0x1) << PMC_GCSR2_GPID92_Pos)                   /**< (PMC_GCSR2) Generic Clock 92 Status Mask */
#define PMC_GCSR2_GPID92(value)               (PMC_GCSR2_GPID92_Msk & ((value) << PMC_GCSR2_GPID92_Pos))
#define PMC_GCSR2_GPID93_Pos                  _U_(29)                                              /**< (PMC_GCSR2) Generic Clock 93 Status Position */
#define PMC_GCSR2_GPID93_Msk                  (_U_(0x1) << PMC_GCSR2_GPID93_Pos)                   /**< (PMC_GCSR2) Generic Clock 93 Status Mask */
#define PMC_GCSR2_GPID93(value)               (PMC_GCSR2_GPID93_Msk & ((value) << PMC_GCSR2_GPID93_Pos))
#define PMC_GCSR2_GPID94_Pos                  _U_(30)                                              /**< (PMC_GCSR2) Generic Clock 94 Status Position */
#define PMC_GCSR2_GPID94_Msk                  (_U_(0x1) << PMC_GCSR2_GPID94_Pos)                   /**< (PMC_GCSR2) Generic Clock 94 Status Mask */
#define PMC_GCSR2_GPID94(value)               (PMC_GCSR2_GPID94_Msk & ((value) << PMC_GCSR2_GPID94_Pos))
#define PMC_GCSR2_GPID95_Pos                  _U_(31)                                              /**< (PMC_GCSR2) Generic Clock 95 Status Position */
#define PMC_GCSR2_GPID95_Msk                  (_U_(0x1) << PMC_GCSR2_GPID95_Pos)                   /**< (PMC_GCSR2) Generic Clock 95 Status Mask */
#define PMC_GCSR2_GPID95(value)               (PMC_GCSR2_GPID95_Msk & ((value) << PMC_GCSR2_GPID95_Pos))
#define PMC_GCSR2_Msk                         _U_(0xFFFFFFFF)                                      /**< (PMC_GCSR2) Register Mask  */

#define PMC_GCSR2_GPID_Pos                    _U_(0)                                               /**< (PMC_GCSR2 Position) Generic Clock 95 Status */
#define PMC_GCSR2_GPID_Msk                    (_U_(0xFFFFFFFF) << PMC_GCSR2_GPID_Pos)              /**< (PMC_GCSR2 Mask) GPID */
#define PMC_GCSR2_GPID(value)                 (PMC_GCSR2_GPID_Msk & ((value) << PMC_GCSR2_GPID_Pos)) 

/* -------- PMC_GCSR3 : (PMC Offset: 0x19C) ( R/ 32) Generic Clock Status Register 3 -------- */
#define PMC_GCSR3_GPID96_Pos                  _U_(0)                                               /**< (PMC_GCSR3) Generic Clock 96 Status Position */
#define PMC_GCSR3_GPID96_Msk                  (_U_(0x1) << PMC_GCSR3_GPID96_Pos)                   /**< (PMC_GCSR3) Generic Clock 96 Status Mask */
#define PMC_GCSR3_GPID96(value)               (PMC_GCSR3_GPID96_Msk & ((value) << PMC_GCSR3_GPID96_Pos))
#define PMC_GCSR3_GPID97_Pos                  _U_(1)                                               /**< (PMC_GCSR3) Generic Clock 97 Status Position */
#define PMC_GCSR3_GPID97_Msk                  (_U_(0x1) << PMC_GCSR3_GPID97_Pos)                   /**< (PMC_GCSR3) Generic Clock 97 Status Mask */
#define PMC_GCSR3_GPID97(value)               (PMC_GCSR3_GPID97_Msk & ((value) << PMC_GCSR3_GPID97_Pos))
#define PMC_GCSR3_GPID98_Pos                  _U_(2)                                               /**< (PMC_GCSR3) Generic Clock 98 Status Position */
#define PMC_GCSR3_GPID98_Msk                  (_U_(0x1) << PMC_GCSR3_GPID98_Pos)                   /**< (PMC_GCSR3) Generic Clock 98 Status Mask */
#define PMC_GCSR3_GPID98(value)               (PMC_GCSR3_GPID98_Msk & ((value) << PMC_GCSR3_GPID98_Pos))
#define PMC_GCSR3_GPID99_Pos                  _U_(3)                                               /**< (PMC_GCSR3) Generic Clock 99 Status Position */
#define PMC_GCSR3_GPID99_Msk                  (_U_(0x1) << PMC_GCSR3_GPID99_Pos)                   /**< (PMC_GCSR3) Generic Clock 99 Status Mask */
#define PMC_GCSR3_GPID99(value)               (PMC_GCSR3_GPID99_Msk & ((value) << PMC_GCSR3_GPID99_Pos))
#define PMC_GCSR3_GPID100_Pos                 _U_(4)                                               /**< (PMC_GCSR3) Generic Clock 100 Status Position */
#define PMC_GCSR3_GPID100_Msk                 (_U_(0x1) << PMC_GCSR3_GPID100_Pos)                  /**< (PMC_GCSR3) Generic Clock 100 Status Mask */
#define PMC_GCSR3_GPID100(value)              (PMC_GCSR3_GPID100_Msk & ((value) << PMC_GCSR3_GPID100_Pos))
#define PMC_GCSR3_GPID101_Pos                 _U_(5)                                               /**< (PMC_GCSR3) Generic Clock 101 Status Position */
#define PMC_GCSR3_GPID101_Msk                 (_U_(0x1) << PMC_GCSR3_GPID101_Pos)                  /**< (PMC_GCSR3) Generic Clock 101 Status Mask */
#define PMC_GCSR3_GPID101(value)              (PMC_GCSR3_GPID101_Msk & ((value) << PMC_GCSR3_GPID101_Pos))
#define PMC_GCSR3_GPID102_Pos                 _U_(6)                                               /**< (PMC_GCSR3) Generic Clock 102 Status Position */
#define PMC_GCSR3_GPID102_Msk                 (_U_(0x1) << PMC_GCSR3_GPID102_Pos)                  /**< (PMC_GCSR3) Generic Clock 102 Status Mask */
#define PMC_GCSR3_GPID102(value)              (PMC_GCSR3_GPID102_Msk & ((value) << PMC_GCSR3_GPID102_Pos))
#define PMC_GCSR3_GPID103_Pos                 _U_(7)                                               /**< (PMC_GCSR3) Generic Clock 103 Status Position */
#define PMC_GCSR3_GPID103_Msk                 (_U_(0x1) << PMC_GCSR3_GPID103_Pos)                  /**< (PMC_GCSR3) Generic Clock 103 Status Mask */
#define PMC_GCSR3_GPID103(value)              (PMC_GCSR3_GPID103_Msk & ((value) << PMC_GCSR3_GPID103_Pos))
#define PMC_GCSR3_GPID104_Pos                 _U_(8)                                               /**< (PMC_GCSR3) Generic Clock 104 Status Position */
#define PMC_GCSR3_GPID104_Msk                 (_U_(0x1) << PMC_GCSR3_GPID104_Pos)                  /**< (PMC_GCSR3) Generic Clock 104 Status Mask */
#define PMC_GCSR3_GPID104(value)              (PMC_GCSR3_GPID104_Msk & ((value) << PMC_GCSR3_GPID104_Pos))
#define PMC_GCSR3_GPID105_Pos                 _U_(9)                                               /**< (PMC_GCSR3) Generic Clock 105 Status Position */
#define PMC_GCSR3_GPID105_Msk                 (_U_(0x1) << PMC_GCSR3_GPID105_Pos)                  /**< (PMC_GCSR3) Generic Clock 105 Status Mask */
#define PMC_GCSR3_GPID105(value)              (PMC_GCSR3_GPID105_Msk & ((value) << PMC_GCSR3_GPID105_Pos))
#define PMC_GCSR3_GPID106_Pos                 _U_(10)                                              /**< (PMC_GCSR3) Generic Clock 106 Status Position */
#define PMC_GCSR3_GPID106_Msk                 (_U_(0x1) << PMC_GCSR3_GPID106_Pos)                  /**< (PMC_GCSR3) Generic Clock 106 Status Mask */
#define PMC_GCSR3_GPID106(value)              (PMC_GCSR3_GPID106_Msk & ((value) << PMC_GCSR3_GPID106_Pos))
#define PMC_GCSR3_GPID107_Pos                 _U_(11)                                              /**< (PMC_GCSR3) Generic Clock 107 Status Position */
#define PMC_GCSR3_GPID107_Msk                 (_U_(0x1) << PMC_GCSR3_GPID107_Pos)                  /**< (PMC_GCSR3) Generic Clock 107 Status Mask */
#define PMC_GCSR3_GPID107(value)              (PMC_GCSR3_GPID107_Msk & ((value) << PMC_GCSR3_GPID107_Pos))
#define PMC_GCSR3_GPID108_Pos                 _U_(12)                                              /**< (PMC_GCSR3) Generic Clock 108 Status Position */
#define PMC_GCSR3_GPID108_Msk                 (_U_(0x1) << PMC_GCSR3_GPID108_Pos)                  /**< (PMC_GCSR3) Generic Clock 108 Status Mask */
#define PMC_GCSR3_GPID108(value)              (PMC_GCSR3_GPID108_Msk & ((value) << PMC_GCSR3_GPID108_Pos))
#define PMC_GCSR3_GPID109_Pos                 _U_(13)                                              /**< (PMC_GCSR3) Generic Clock 109 Status Position */
#define PMC_GCSR3_GPID109_Msk                 (_U_(0x1) << PMC_GCSR3_GPID109_Pos)                  /**< (PMC_GCSR3) Generic Clock 109 Status Mask */
#define PMC_GCSR3_GPID109(value)              (PMC_GCSR3_GPID109_Msk & ((value) << PMC_GCSR3_GPID109_Pos))
#define PMC_GCSR3_GPID110_Pos                 _U_(14)                                              /**< (PMC_GCSR3) Generic Clock 110 Status Position */
#define PMC_GCSR3_GPID110_Msk                 (_U_(0x1) << PMC_GCSR3_GPID110_Pos)                  /**< (PMC_GCSR3) Generic Clock 110 Status Mask */
#define PMC_GCSR3_GPID110(value)              (PMC_GCSR3_GPID110_Msk & ((value) << PMC_GCSR3_GPID110_Pos))
#define PMC_GCSR3_GPID111_Pos                 _U_(15)                                              /**< (PMC_GCSR3) Generic Clock 111 Status Position */
#define PMC_GCSR3_GPID111_Msk                 (_U_(0x1) << PMC_GCSR3_GPID111_Pos)                  /**< (PMC_GCSR3) Generic Clock 111 Status Mask */
#define PMC_GCSR3_GPID111(value)              (PMC_GCSR3_GPID111_Msk & ((value) << PMC_GCSR3_GPID111_Pos))
#define PMC_GCSR3_GPID112_Pos                 _U_(16)                                              /**< (PMC_GCSR3) Generic Clock 112 Status Position */
#define PMC_GCSR3_GPID112_Msk                 (_U_(0x1) << PMC_GCSR3_GPID112_Pos)                  /**< (PMC_GCSR3) Generic Clock 112 Status Mask */
#define PMC_GCSR3_GPID112(value)              (PMC_GCSR3_GPID112_Msk & ((value) << PMC_GCSR3_GPID112_Pos))
#define PMC_GCSR3_GPID113_Pos                 _U_(17)                                              /**< (PMC_GCSR3) Generic Clock 113 Status Position */
#define PMC_GCSR3_GPID113_Msk                 (_U_(0x1) << PMC_GCSR3_GPID113_Pos)                  /**< (PMC_GCSR3) Generic Clock 113 Status Mask */
#define PMC_GCSR3_GPID113(value)              (PMC_GCSR3_GPID113_Msk & ((value) << PMC_GCSR3_GPID113_Pos))
#define PMC_GCSR3_GPID114_Pos                 _U_(18)                                              /**< (PMC_GCSR3) Generic Clock 114 Status Position */
#define PMC_GCSR3_GPID114_Msk                 (_U_(0x1) << PMC_GCSR3_GPID114_Pos)                  /**< (PMC_GCSR3) Generic Clock 114 Status Mask */
#define PMC_GCSR3_GPID114(value)              (PMC_GCSR3_GPID114_Msk & ((value) << PMC_GCSR3_GPID114_Pos))
#define PMC_GCSR3_GPID115_Pos                 _U_(19)                                              /**< (PMC_GCSR3) Generic Clock 115 Status Position */
#define PMC_GCSR3_GPID115_Msk                 (_U_(0x1) << PMC_GCSR3_GPID115_Pos)                  /**< (PMC_GCSR3) Generic Clock 115 Status Mask */
#define PMC_GCSR3_GPID115(value)              (PMC_GCSR3_GPID115_Msk & ((value) << PMC_GCSR3_GPID115_Pos))
#define PMC_GCSR3_GPID116_Pos                 _U_(20)                                              /**< (PMC_GCSR3) Generic Clock 116 Status Position */
#define PMC_GCSR3_GPID116_Msk                 (_U_(0x1) << PMC_GCSR3_GPID116_Pos)                  /**< (PMC_GCSR3) Generic Clock 116 Status Mask */
#define PMC_GCSR3_GPID116(value)              (PMC_GCSR3_GPID116_Msk & ((value) << PMC_GCSR3_GPID116_Pos))
#define PMC_GCSR3_GPID117_Pos                 _U_(21)                                              /**< (PMC_GCSR3) Generic Clock 117 Status Position */
#define PMC_GCSR3_GPID117_Msk                 (_U_(0x1) << PMC_GCSR3_GPID117_Pos)                  /**< (PMC_GCSR3) Generic Clock 117 Status Mask */
#define PMC_GCSR3_GPID117(value)              (PMC_GCSR3_GPID117_Msk & ((value) << PMC_GCSR3_GPID117_Pos))
#define PMC_GCSR3_GPID118_Pos                 _U_(22)                                              /**< (PMC_GCSR3) Generic Clock 118 Status Position */
#define PMC_GCSR3_GPID118_Msk                 (_U_(0x1) << PMC_GCSR3_GPID118_Pos)                  /**< (PMC_GCSR3) Generic Clock 118 Status Mask */
#define PMC_GCSR3_GPID118(value)              (PMC_GCSR3_GPID118_Msk & ((value) << PMC_GCSR3_GPID118_Pos))
#define PMC_GCSR3_GPID119_Pos                 _U_(23)                                              /**< (PMC_GCSR3) Generic Clock 119 Status Position */
#define PMC_GCSR3_GPID119_Msk                 (_U_(0x1) << PMC_GCSR3_GPID119_Pos)                  /**< (PMC_GCSR3) Generic Clock 119 Status Mask */
#define PMC_GCSR3_GPID119(value)              (PMC_GCSR3_GPID119_Msk & ((value) << PMC_GCSR3_GPID119_Pos))
#define PMC_GCSR3_GPID120_Pos                 _U_(24)                                              /**< (PMC_GCSR3) Generic Clock 120 Status Position */
#define PMC_GCSR3_GPID120_Msk                 (_U_(0x1) << PMC_GCSR3_GPID120_Pos)                  /**< (PMC_GCSR3) Generic Clock 120 Status Mask */
#define PMC_GCSR3_GPID120(value)              (PMC_GCSR3_GPID120_Msk & ((value) << PMC_GCSR3_GPID120_Pos))
#define PMC_GCSR3_GPID122_Pos                 _U_(25)                                              /**< (PMC_GCSR3) Generic Clock 122 Status Position */
#define PMC_GCSR3_GPID122_Msk                 (_U_(0x3) << PMC_GCSR3_GPID122_Pos)                  /**< (PMC_GCSR3) Generic Clock 122 Status Mask */
#define PMC_GCSR3_GPID122(value)              (PMC_GCSR3_GPID122_Msk & ((value) << PMC_GCSR3_GPID122_Pos))
#define PMC_GCSR3_GPID123_Pos                 _U_(27)                                              /**< (PMC_GCSR3) Generic Clock 123 Status Position */
#define PMC_GCSR3_GPID123_Msk                 (_U_(0x1) << PMC_GCSR3_GPID123_Pos)                  /**< (PMC_GCSR3) Generic Clock 123 Status Mask */
#define PMC_GCSR3_GPID123(value)              (PMC_GCSR3_GPID123_Msk & ((value) << PMC_GCSR3_GPID123_Pos))
#define PMC_GCSR3_GPID124_Pos                 _U_(28)                                              /**< (PMC_GCSR3) Generic Clock 124 Status Position */
#define PMC_GCSR3_GPID124_Msk                 (_U_(0x1) << PMC_GCSR3_GPID124_Pos)                  /**< (PMC_GCSR3) Generic Clock 124 Status Mask */
#define PMC_GCSR3_GPID124(value)              (PMC_GCSR3_GPID124_Msk & ((value) << PMC_GCSR3_GPID124_Pos))
#define PMC_GCSR3_GPID125_Pos                 _U_(29)                                              /**< (PMC_GCSR3) Generic Clock 125 Status Position */
#define PMC_GCSR3_GPID125_Msk                 (_U_(0x1) << PMC_GCSR3_GPID125_Pos)                  /**< (PMC_GCSR3) Generic Clock 125 Status Mask */
#define PMC_GCSR3_GPID125(value)              (PMC_GCSR3_GPID125_Msk & ((value) << PMC_GCSR3_GPID125_Pos))
#define PMC_GCSR3_GPID126_Pos                 _U_(30)                                              /**< (PMC_GCSR3) Generic Clock 126 Status Position */
#define PMC_GCSR3_GPID126_Msk                 (_U_(0x1) << PMC_GCSR3_GPID126_Pos)                  /**< (PMC_GCSR3) Generic Clock 126 Status Mask */
#define PMC_GCSR3_GPID126(value)              (PMC_GCSR3_GPID126_Msk & ((value) << PMC_GCSR3_GPID126_Pos))
#define PMC_GCSR3_GPID127_Pos                 _U_(31)                                              /**< (PMC_GCSR3) Generic Clock 127 Status Position */
#define PMC_GCSR3_GPID127_Msk                 (_U_(0x1) << PMC_GCSR3_GPID127_Pos)                  /**< (PMC_GCSR3) Generic Clock 127 Status Mask */
#define PMC_GCSR3_GPID127(value)              (PMC_GCSR3_GPID127_Msk & ((value) << PMC_GCSR3_GPID127_Pos))
#define PMC_GCSR3_Msk                         _U_(0xFFFFFFFF)                                      /**< (PMC_GCSR3) Register Mask  */

#define PMC_GCSR3_GPID_Pos                    _U_(27)                                              /**< (PMC_GCSR3 Position) Generic Clock x27 Status */
#define PMC_GCSR3_GPID_Msk                    (_U_(0x1F) << PMC_GCSR3_GPID_Pos)                    /**< (PMC_GCSR3 Mask) GPID */
#define PMC_GCSR3_GPID(value)                 (PMC_GCSR3_GPID_Msk & ((value) << PMC_GCSR3_GPID_Pos)) 

/* -------- PMC_OSC2 : (PMC Offset: 0x1B0) (R/W 32) Oscillator Control Register 2 -------- */
#define PMC_OSC2_EN_Pos                       _U_(0)                                               /**< (PMC_OSC2) Enable Position */
#define PMC_OSC2_EN_Msk                       (_U_(0x1) << PMC_OSC2_EN_Pos)                        /**< (PMC_OSC2) Enable Mask */
#define PMC_OSC2_EN(value)                    (PMC_OSC2_EN_Msk & ((value) << PMC_OSC2_EN_Pos))    
#define PMC_OSC2_OSCRCF_Pos                   _U_(4)                                               /**< (PMC_OSC2) 2nd Oscillator Frequency Selection Position */
#define PMC_OSC2_OSCRCF_Msk                   (_U_(0x3) << PMC_OSC2_OSCRCF_Pos)                    /**< (PMC_OSC2) 2nd Oscillator Frequency Selection Mask */
#define PMC_OSC2_OSCRCF(value)                (PMC_OSC2_OSCRCF_Msk & ((value) << PMC_OSC2_OSCRCF_Pos))
#define   PMC_OSC2_OSCRCF_4_MHZ_Val           _U_(0x0)                                             /**< (PMC_OSC2) The 2nd RC oscillator frequency is at 4 MHZ  */
#define   PMC_OSC2_OSCRCF_8_MHZ_Val           _U_(0x1)                                             /**< (PMC_OSC2) The 2nd RC oscillator frequency is at 8 MHZ  */
#define   PMC_OSC2_OSCRCF_10_MHZ_Val          _U_(0x2)                                             /**< (PMC_OSC2) The 2nd RC oscillator frequency is at 10 MHZ  */
#define   PMC_OSC2_OSCRCF_12_MHZ_Val          _U_(0x3)                                             /**< (PMC_OSC2) The 2nd RC oscillator frequency is at 12 MHZ  */
#define PMC_OSC2_OSCRCF_4_MHZ                 (PMC_OSC2_OSCRCF_4_MHZ_Val << PMC_OSC2_OSCRCF_Pos)   /**< (PMC_OSC2) The 2nd RC oscillator frequency is at 4 MHZ Position  */
#define PMC_OSC2_OSCRCF_8_MHZ                 (PMC_OSC2_OSCRCF_8_MHZ_Val << PMC_OSC2_OSCRCF_Pos)   /**< (PMC_OSC2) The 2nd RC oscillator frequency is at 8 MHZ Position  */
#define PMC_OSC2_OSCRCF_10_MHZ                (PMC_OSC2_OSCRCF_10_MHZ_Val << PMC_OSC2_OSCRCF_Pos)  /**< (PMC_OSC2) The 2nd RC oscillator frequency is at 10 MHZ Position  */
#define PMC_OSC2_OSCRCF_12_MHZ                (PMC_OSC2_OSCRCF_12_MHZ_Val << PMC_OSC2_OSCRCF_Pos)  /**< (PMC_OSC2) The 2nd RC oscillator frequency is at 12 MHZ Position  */
#define PMC_OSC2_EN_WR_CALIB_Pos              _U_(8)                                               /**< (PMC_OSC2) Enable Calibration Register Write Position */
#define PMC_OSC2_EN_WR_CALIB_Msk              (_U_(0x1) << PMC_OSC2_EN_WR_CALIB_Pos)               /**< (PMC_OSC2) Enable Calibration Register Write Mask */
#define PMC_OSC2_EN_WR_CALIB(value)           (PMC_OSC2_EN_WR_CALIB_Msk & ((value) << PMC_OSC2_EN_WR_CALIB_Pos))
#define PMC_OSC2_KEY_Pos                      _U_(16)                                              /**< (PMC_OSC2) Register Write Access Password Position */
#define PMC_OSC2_KEY_Msk                      (_U_(0xFF) << PMC_OSC2_KEY_Pos)                      /**< (PMC_OSC2) Register Write Access Password Mask */
#define PMC_OSC2_KEY(value)                   (PMC_OSC2_KEY_Msk & ((value) << PMC_OSC2_KEY_Pos))  
#define   PMC_OSC2_KEY_PASSWD_Val             _U_(0x37)                                            /**< (PMC_OSC2) Writing any other value in this field aborts the write operation.Always reads as 0.  */
#define PMC_OSC2_KEY_PASSWD                   (PMC_OSC2_KEY_PASSWD_Val << PMC_OSC2_KEY_Pos)        /**< (PMC_OSC2) Writing any other value in this field aborts the write operation.Always reads as 0. Position  */
#define PMC_OSC2_Msk                          _U_(0x00FF0131)                                      /**< (PMC_OSC2) Register Mask  */


/* -------- PMC_OCR2 : (PMC Offset: 0x1B4) (R/W 32) Oscillator Calibration Register 2 -------- */
#define PMC_OCR2_CAL4_Pos                     _U_(0)                                               /**< (PMC_OCR2) Main RC Oscillator Calibration Bits for 4 MHz Position */
#define PMC_OCR2_CAL4_Msk                     (_U_(0x7F) << PMC_OCR2_CAL4_Pos)                     /**< (PMC_OCR2) Main RC Oscillator Calibration Bits for 4 MHz Mask */
#define PMC_OCR2_CAL4(value)                  (PMC_OCR2_CAL4_Msk & ((value) << PMC_OCR2_CAL4_Pos))
#define PMC_OCR2_SEL4_Pos                     _U_(7)                                               /**< (PMC_OCR2) Selection of Main RC Oscillator Calibration Bits for 4 MHz Position */
#define PMC_OCR2_SEL4_Msk                     (_U_(0x1) << PMC_OCR2_SEL4_Pos)                      /**< (PMC_OCR2) Selection of Main RC Oscillator Calibration Bits for 4 MHz Mask */
#define PMC_OCR2_SEL4(value)                  (PMC_OCR2_SEL4_Msk & ((value) << PMC_OCR2_SEL4_Pos))
#define PMC_OCR2_CAL8_Pos                     _U_(8)                                               /**< (PMC_OCR2) Main RC Oscillator Calibration Bits for 8 MHz Position */
#define PMC_OCR2_CAL8_Msk                     (_U_(0x7F) << PMC_OCR2_CAL8_Pos)                     /**< (PMC_OCR2) Main RC Oscillator Calibration Bits for 8 MHz Mask */
#define PMC_OCR2_CAL8(value)                  (PMC_OCR2_CAL8_Msk & ((value) << PMC_OCR2_CAL8_Pos))
#define PMC_OCR2_SEL8_Pos                     _U_(15)                                              /**< (PMC_OCR2) Selection of Main RC Oscillator Calibration Bits for 8 MHz Position */
#define PMC_OCR2_SEL8_Msk                     (_U_(0x1) << PMC_OCR2_SEL8_Pos)                      /**< (PMC_OCR2) Selection of Main RC Oscillator Calibration Bits for 8 MHz Mask */
#define PMC_OCR2_SEL8(value)                  (PMC_OCR2_SEL8_Msk & ((value) << PMC_OCR2_SEL8_Pos))
#define PMC_OCR2_CAL10_Pos                    _U_(16)                                              /**< (PMC_OCR2) Main RC Oscillator Calibration Bits for 10 MHz Position */
#define PMC_OCR2_CAL10_Msk                    (_U_(0x7F) << PMC_OCR2_CAL10_Pos)                    /**< (PMC_OCR2) Main RC Oscillator Calibration Bits for 10 MHz Mask */
#define PMC_OCR2_CAL10(value)                 (PMC_OCR2_CAL10_Msk & ((value) << PMC_OCR2_CAL10_Pos))
#define PMC_OCR2_SEL10_Pos                    _U_(23)                                              /**< (PMC_OCR2) Selection of Main RC Oscillator Calibration Bits for 10 MHz Position */
#define PMC_OCR2_SEL10_Msk                    (_U_(0x1) << PMC_OCR2_SEL10_Pos)                     /**< (PMC_OCR2) Selection of Main RC Oscillator Calibration Bits for 10 MHz Mask */
#define PMC_OCR2_SEL10(value)                 (PMC_OCR2_SEL10_Msk & ((value) << PMC_OCR2_SEL10_Pos))
#define PMC_OCR2_CAL12_Pos                    _U_(24)                                              /**< (PMC_OCR2) Main RC Oscillator Calibration Bits for 12 MHz Position */
#define PMC_OCR2_CAL12_Msk                    (_U_(0x7F) << PMC_OCR2_CAL12_Pos)                    /**< (PMC_OCR2) Main RC Oscillator Calibration Bits for 12 MHz Mask */
#define PMC_OCR2_CAL12(value)                 (PMC_OCR2_CAL12_Msk & ((value) << PMC_OCR2_CAL12_Pos))
#define PMC_OCR2_SEL12_Pos                    _U_(31)                                              /**< (PMC_OCR2) Selection of Main RC Oscillator Calibration Bits for 12 MHz Position */
#define PMC_OCR2_SEL12_Msk                    (_U_(0x1) << PMC_OCR2_SEL12_Pos)                     /**< (PMC_OCR2) Selection of Main RC Oscillator Calibration Bits for 12 MHz Mask */
#define PMC_OCR2_SEL12(value)                 (PMC_OCR2_SEL12_Msk & ((value) << PMC_OCR2_SEL12_Pos))
#define PMC_OCR2_Msk                          _U_(0xFFFFFFFF)                                      /**< (PMC_OCR2) Register Mask  */


/** \brief PMC register offsets definitions */
#define PMC_SCER_REG_OFST              (0x00)              /**< (PMC_SCER) System Clock Enable Register Offset */
#define PMC_SCDR_REG_OFST              (0x04)              /**< (PMC_SCDR) System Clock Disable Register Offset */
#define PMC_SCSR_REG_OFST              (0x08)              /**< (PMC_SCSR) System Clock Status Register Offset */
#define CKGR_MOR_REG_OFST              (0x20)              /**< (CKGR_MOR) Main Oscillator Register Offset */
#define CKGR_MCFR_REG_OFST             (0x24)              /**< (CKGR_MCFR) Main Clock Frequency Register Offset */
#define CKGR_PLLAR_REG_OFST            (0x28)              /**< (CKGR_PLLAR) PLLA Register Offset */
#define CKGR_PLLBR_REG_OFST            (0x2C)              /**< (CKGR_PLLBR) PLLB Register Offset */
#define PMC_MCKR_REG_OFST              (0x30)              /**< (PMC_MCKR) Master Clock Register Offset */
#define PMC_PCK_REG_OFST               (0x40)              /**< (PMC_PCK) Programmable Clock Register Offset */
#define PMC_IER_REG_OFST               (0x60)              /**< (PMC_IER) Interrupt Enable Register Offset */
#define PMC_IDR_REG_OFST               (0x64)              /**< (PMC_IDR) Interrupt Disable Register Offset */
#define PMC_SR_REG_OFST                (0x68)              /**< (PMC_SR) Status Register Offset */
#define PMC_IMR_REG_OFST               (0x6C)              /**< (PMC_IMR) Interrupt Mask Register Offset */
#define PMC_FOCR_REG_OFST              (0x78)              /**< (PMC_FOCR) Fault Output Clear Register Offset */
#define PMC_PLL_CFG_REG_OFST           (0x80)              /**< (PMC_PLL_CFG) PLL Configuration Register Offset */
#define PMC_WPMR_REG_OFST              (0xE4)              /**< (PMC_WPMR) Write Protection Mode Register Offset */
#define PMC_WPSR_REG_OFST              (0xE8)              /**< (PMC_WPSR) Write Protection Status Register Offset */
#define PMC_PCR_REG_OFST               (0x10C)             /**< (PMC_PCR) Peripheral Control Register Offset */
#define PMC_OCR1_REG_OFST              (0x110)             /**< (PMC_OCR1) Oscillator Calibration Register Offset */
#define PMC_PMMR_REG_OFST              (0x130)             /**< (PMC_PMMR) PLL Maximum Multiplier Value Register Offset */
#define PMC_CPULIM_REG_OFST            (0x160)             /**< (PMC_CPULIM) CPU Monitor Limits Register Offset */
#define PMC_CSR0_REG_OFST              (0x170)             /**< (PMC_CSR0) Peripheral Clock Status Register 0 Offset */
#define PMC_CSR1_REG_OFST              (0x174)             /**< (PMC_CSR1) Peripheral Clock Status Register 1 Offset */
#define PMC_CSR2_REG_OFST              (0x178)             /**< (PMC_CSR2) Peripheral Clock Status Register 2 Offset */
#define PMC_CSR3_REG_OFST              (0x17C)             /**< (PMC_CSR3) Peripheral Clock Status Register 3 Offset */
#define PMC_GCSR0_REG_OFST             (0x190)             /**< (PMC_GCSR0) Generic Clock Status Register 0 Offset */
#define PMC_GCSR1_REG_OFST             (0x194)             /**< (PMC_GCSR1) Generic Clock Status Register 1 Offset */
#define PMC_GCSR2_REG_OFST             (0x198)             /**< (PMC_GCSR2) Generic Clock Status Register 2 Offset */
#define PMC_GCSR3_REG_OFST             (0x19C)             /**< (PMC_GCSR3) Generic Clock Status Register 3 Offset */
#define PMC_OSC2_REG_OFST              (0x1B0)             /**< (PMC_OSC2) Oscillator Control Register 2 Offset */
#define PMC_OCR2_REG_OFST              (0x1B4)             /**< (PMC_OCR2) Oscillator Calibration Register 2 Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief PMC register API structure */
typedef struct
{
  __O   uint32_t                       PMC_SCER;           /**< Offset: 0x00 ( /W  32) System Clock Enable Register */
  __O   uint32_t                       PMC_SCDR;           /**< Offset: 0x04 ( /W  32) System Clock Disable Register */
  __I   uint32_t                       PMC_SCSR;           /**< Offset: 0x08 (R/   32) System Clock Status Register */
  __I   uint8_t                        Reserved1[0x14];
  __IO  uint32_t                       CKGR_MOR;           /**< Offset: 0x20 (R/W  32) Main Oscillator Register */
  __IO  uint32_t                       CKGR_MCFR;          /**< Offset: 0x24 (R/W  32) Main Clock Frequency Register */
  __IO  uint32_t                       CKGR_PLLAR;         /**< Offset: 0x28 (R/W  32) PLLA Register */
  __IO  uint32_t                       CKGR_PLLBR;         /**< Offset: 0x2C (R/W  32) PLLB Register */
  __IO  uint32_t                       PMC_MCKR;           /**< Offset: 0x30 (R/W  32) Master Clock Register */
  __I   uint8_t                        Reserved2[0x0C];
  __IO  uint32_t                       PMC_PCK[4];         /**< Offset: 0x40 (R/W  32) Programmable Clock Register */
  __I   uint8_t                        Reserved3[0x10];
  __O   uint32_t                       PMC_IER;            /**< Offset: 0x60 ( /W  32) Interrupt Enable Register */
  __O   uint32_t                       PMC_IDR;            /**< Offset: 0x64 ( /W  32) Interrupt Disable Register */
  __I   uint32_t                       PMC_SR;             /**< Offset: 0x68 (R/   32) Status Register */
  __I   uint32_t                       PMC_IMR;            /**< Offset: 0x6C (R/   32) Interrupt Mask Register */
  __I   uint8_t                        Reserved4[0x08];
  __O   uint32_t                       PMC_FOCR;           /**< Offset: 0x78 ( /W  32) Fault Output Clear Register */
  __I   uint8_t                        Reserved5[0x04];
  __IO  uint32_t                       PMC_PLL_CFG;        /**< Offset: 0x80 (R/W  32) PLL Configuration Register */
  __I   uint8_t                        Reserved6[0x60];
  __IO  uint32_t                       PMC_WPMR;           /**< Offset: 0xE4 (R/W  32) Write Protection Mode Register */
  __I   uint32_t                       PMC_WPSR;           /**< Offset: 0xE8 (R/   32) Write Protection Status Register */
  __I   uint8_t                        Reserved7[0x20];
  __IO  uint32_t                       PMC_PCR;            /**< Offset: 0x10C (R/W  32) Peripheral Control Register */
  __IO  uint32_t                       PMC_OCR1;           /**< Offset: 0x110 (R/W  32) Oscillator Calibration Register */
  __I   uint8_t                        Reserved8[0x1C];
  __IO  uint32_t                       PMC_PMMR;           /**< Offset: 0x130 (R/W  32) PLL Maximum Multiplier Value Register */
  __I   uint8_t                        Reserved9[0x2C];
  __IO  uint32_t                       PMC_CPULIM;         /**< Offset: 0x160 (R/W  32) CPU Monitor Limits Register */
  __I   uint8_t                        Reserved10[0x0C];
  __I   uint32_t                       PMC_CSR0;           /**< Offset: 0x170 (R/   32) Peripheral Clock Status Register 0 */
  __I   uint32_t                       PMC_CSR1;           /**< Offset: 0x174 (R/   32) Peripheral Clock Status Register 1 */
  __I   uint32_t                       PMC_CSR2;           /**< Offset: 0x178 (R/   32) Peripheral Clock Status Register 2 */
  __I   uint32_t                       PMC_CSR3;           /**< Offset: 0x17C (R/   32) Peripheral Clock Status Register 3 */
  __I   uint8_t                        Reserved11[0x10];
  __I   uint32_t                       PMC_GCSR0;          /**< Offset: 0x190 (R/   32) Generic Clock Status Register 0 */
  __I   uint32_t                       PMC_GCSR1;          /**< Offset: 0x194 (R/   32) Generic Clock Status Register 1 */
  __I   uint32_t                       PMC_GCSR2;          /**< Offset: 0x198 (R/   32) Generic Clock Status Register 2 */
  __I   uint32_t                       PMC_GCSR3;          /**< Offset: 0x19C (R/   32) Generic Clock Status Register 3 */
  __I   uint8_t                        Reserved12[0x10];
  __IO  uint32_t                       PMC_OSC2;           /**< Offset: 0x1B0 (R/W  32) Oscillator Control Register 2 */
  __IO  uint32_t                       PMC_OCR2;           /**< Offset: 0x1B4 (R/W  32) Oscillator Calibration Register 2 */
} pmc_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _SAMRH71_PMC_COMPONENT_H_ */
