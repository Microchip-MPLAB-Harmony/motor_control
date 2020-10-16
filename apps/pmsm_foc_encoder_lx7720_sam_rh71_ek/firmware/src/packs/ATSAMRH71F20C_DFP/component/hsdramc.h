/**
 * \brief Component description for HSDRAMC
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
#ifndef _SAMRH71_HSDRAMC_COMPONENT_H_
#define _SAMRH71_HSDRAMC_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR HSDRAMC                                      */
/* ************************************************************************** */

/* -------- HSDRAMC_MR : (HSDRAMC Offset: 0x00) (R/W 32) Mode Register -------- */
#define HSDRAMC_MR_MODE_Pos                   _U_(0)                                               /**< (HSDRAMC_MR) SDRAMC Command Mode Position */
#define HSDRAMC_MR_MODE_Msk                   (_U_(0x7) << HSDRAMC_MR_MODE_Pos)                    /**< (HSDRAMC_MR) SDRAMC Command Mode Mask */
#define HSDRAMC_MR_MODE(value)                (HSDRAMC_MR_MODE_Msk & ((value) << HSDRAMC_MR_MODE_Pos))
#define   HSDRAMC_MR_MODE_NORMAL_Val          _U_(0x0)                                             /**< (HSDRAMC_MR) Normal mode. Any access to the SDRAM is decoded normally. To activate this mode, the command must be followed by a write to the SDRAM.  */
#define   HSDRAMC_MR_MODE_NOP_Val             _U_(0x1)                                             /**< (HSDRAMC_MR) The SDRAMC issues a NOP command when the SDRAM device is accessed regardless of the cycle. To activate this mode, the command must be followed by a write to the SDRAM.  */
#define   HSDRAMC_MR_MODE_ALLBANKS_PRECHARGE_Val _U_(0x2)                                             /**< (HSDRAMC_MR) The SDRAMC issues an "All Banks Precharge" command when the SDRAM device is accessed regardless of the cycle. To activate this mode, the command must be followed by a write to the SDRAM.  */
#define   HSDRAMC_MR_MODE_LOAD_MODEREG_Val    _U_(0x3)                                             /**< (HSDRAMC_MR) The SDRAMC issues a "Load Mode Register" command when the SDRAM device is accessed regardless of the cycle. To activate this mode, the command must be followed by a write to the SDRAM.  */
#define   HSDRAMC_MR_MODE_AUTO_REFRESH_Val    _U_(0x4)                                             /**< (HSDRAMC_MR) The SDRAMC issues an "Autorefresh" Command when the SDRAM device is accessed regardless of the cycle. Previously, an "All Banks Precharge" command must be issued. To activate this mode, the command must be followed by a write to the SDRAM.  */
#define   HSDRAMC_MR_MODE_EXT_LOAD_MODEREG_Val _U_(0x5)                                             /**< (HSDRAMC_MR) The SDRAMC issues an "Extended Load Mode Register" command when the SDRAM device is accessed regardless of the cycle. To activate this mode, the "Extended Load Mode Register" command must be followed by a write to the SDRAM. The write in the SDRAM must be done in the appropriate bank; most low-power SDRAM devices use the bank 1.  */
#define HSDRAMC_MR_MODE_NORMAL                (HSDRAMC_MR_MODE_NORMAL_Val << HSDRAMC_MR_MODE_Pos)  /**< (HSDRAMC_MR) Normal mode. Any access to the SDRAM is decoded normally. To activate this mode, the command must be followed by a write to the SDRAM. Position  */
#define HSDRAMC_MR_MODE_NOP                   (HSDRAMC_MR_MODE_NOP_Val << HSDRAMC_MR_MODE_Pos)     /**< (HSDRAMC_MR) The SDRAMC issues a NOP command when the SDRAM device is accessed regardless of the cycle. To activate this mode, the command must be followed by a write to the SDRAM. Position  */
#define HSDRAMC_MR_MODE_ALLBANKS_PRECHARGE    (HSDRAMC_MR_MODE_ALLBANKS_PRECHARGE_Val << HSDRAMC_MR_MODE_Pos) /**< (HSDRAMC_MR) The SDRAMC issues an "All Banks Precharge" command when the SDRAM device is accessed regardless of the cycle. To activate this mode, the command must be followed by a write to the SDRAM. Position  */
#define HSDRAMC_MR_MODE_LOAD_MODEREG          (HSDRAMC_MR_MODE_LOAD_MODEREG_Val << HSDRAMC_MR_MODE_Pos) /**< (HSDRAMC_MR) The SDRAMC issues a "Load Mode Register" command when the SDRAM device is accessed regardless of the cycle. To activate this mode, the command must be followed by a write to the SDRAM. Position  */
#define HSDRAMC_MR_MODE_AUTO_REFRESH          (HSDRAMC_MR_MODE_AUTO_REFRESH_Val << HSDRAMC_MR_MODE_Pos) /**< (HSDRAMC_MR) The SDRAMC issues an "Autorefresh" Command when the SDRAM device is accessed regardless of the cycle. Previously, an "All Banks Precharge" command must be issued. To activate this mode, the command must be followed by a write to the SDRAM. Position  */
#define HSDRAMC_MR_MODE_EXT_LOAD_MODEREG      (HSDRAMC_MR_MODE_EXT_LOAD_MODEREG_Val << HSDRAMC_MR_MODE_Pos) /**< (HSDRAMC_MR) The SDRAMC issues an "Extended Load Mode Register" command when the SDRAM device is accessed regardless of the cycle. To activate this mode, the "Extended Load Mode Register" command must be followed by a write to the SDRAM. The write in the SDRAM must be done in the appropriate bank; most low-power SDRAM devices use the bank 1. Position  */
#define HSDRAMC_MR_Msk                        _U_(0x00000007)                                      /**< (HSDRAMC_MR) Register Mask  */


/* -------- HSDRAMC_TR : (HSDRAMC Offset: 0x04) (R/W 32) Refresh Timer Register -------- */
#define HSDRAMC_TR_COUNT_Pos                  _U_(0)                                               /**< (HSDRAMC_TR) SDRAMC Refresh Timer Count Position */
#define HSDRAMC_TR_COUNT_Msk                  (_U_(0xFFF) << HSDRAMC_TR_COUNT_Pos)                 /**< (HSDRAMC_TR) SDRAMC Refresh Timer Count Mask */
#define HSDRAMC_TR_COUNT(value)               (HSDRAMC_TR_COUNT_Msk & ((value) << HSDRAMC_TR_COUNT_Pos))
#define HSDRAMC_TR_Msk                        _U_(0x00000FFF)                                      /**< (HSDRAMC_TR) Register Mask  */


/* -------- HSDRAMC_CR : (HSDRAMC Offset: 0x08) (R/W 32) Configuration Register -------- */
#define HSDRAMC_CR_NC_Pos                     _U_(0)                                               /**< (HSDRAMC_CR) Number of Column Bits Position */
#define HSDRAMC_CR_NC_Msk                     (_U_(0x7) << HSDRAMC_CR_NC_Pos)                      /**< (HSDRAMC_CR) Number of Column Bits Mask */
#define HSDRAMC_CR_NC(value)                  (HSDRAMC_CR_NC_Msk & ((value) << HSDRAMC_CR_NC_Pos))
#define   HSDRAMC_CR_NC_COL8_Val              _U_(0x0)                                             /**< (HSDRAMC_CR) 8 bits to define the column number, up to 256 columns  */
#define   HSDRAMC_CR_NC_COL9_Val              _U_(0x1)                                             /**< (HSDRAMC_CR) 9 bits to define the column number, up to 512 columns  */
#define   HSDRAMC_CR_NC_COL10_Val             _U_(0x2)                                             /**< (HSDRAMC_CR) 10 bits to define the column number, up to 1024 columns  */
#define   HSDRAMC_CR_NC_COL11_Val             _U_(0x3)                                             /**< (HSDRAMC_CR) 11 bits to define the column number, up to 2048 columns  */
#define   HSDRAMC_CR_NC_COL12_Val             _U_(0x4)                                             /**< (HSDRAMC_CR) 12 bits to define the column number, up to 4096 columns  */
#define HSDRAMC_CR_NC_COL8                    (HSDRAMC_CR_NC_COL8_Val << HSDRAMC_CR_NC_Pos)        /**< (HSDRAMC_CR) 8 bits to define the column number, up to 256 columns Position  */
#define HSDRAMC_CR_NC_COL9                    (HSDRAMC_CR_NC_COL9_Val << HSDRAMC_CR_NC_Pos)        /**< (HSDRAMC_CR) 9 bits to define the column number, up to 512 columns Position  */
#define HSDRAMC_CR_NC_COL10                   (HSDRAMC_CR_NC_COL10_Val << HSDRAMC_CR_NC_Pos)       /**< (HSDRAMC_CR) 10 bits to define the column number, up to 1024 columns Position  */
#define HSDRAMC_CR_NC_COL11                   (HSDRAMC_CR_NC_COL11_Val << HSDRAMC_CR_NC_Pos)       /**< (HSDRAMC_CR) 11 bits to define the column number, up to 2048 columns Position  */
#define HSDRAMC_CR_NC_COL12                   (HSDRAMC_CR_NC_COL12_Val << HSDRAMC_CR_NC_Pos)       /**< (HSDRAMC_CR) 12 bits to define the column number, up to 4096 columns Position  */
#define HSDRAMC_CR_NR_Pos                     _U_(3)                                               /**< (HSDRAMC_CR) Number of Row Bits Position */
#define HSDRAMC_CR_NR_Msk                     (_U_(0x3) << HSDRAMC_CR_NR_Pos)                      /**< (HSDRAMC_CR) Number of Row Bits Mask */
#define HSDRAMC_CR_NR(value)                  (HSDRAMC_CR_NR_Msk & ((value) << HSDRAMC_CR_NR_Pos))
#define   HSDRAMC_CR_NR_ROW11_Val             _U_(0x0)                                             /**< (HSDRAMC_CR) 11 bits to define the row number, up to 2048 rows  */
#define   HSDRAMC_CR_NR_ROW12_Val             _U_(0x1)                                             /**< (HSDRAMC_CR) 12 bits to define the row number, up to 4096 rows  */
#define   HSDRAMC_CR_NR_ROW13_Val             _U_(0x2)                                             /**< (HSDRAMC_CR) 13 bits to define the row number, up to 8192 rows  */
#define HSDRAMC_CR_NR_ROW11                   (HSDRAMC_CR_NR_ROW11_Val << HSDRAMC_CR_NR_Pos)       /**< (HSDRAMC_CR) 11 bits to define the row number, up to 2048 rows Position  */
#define HSDRAMC_CR_NR_ROW12                   (HSDRAMC_CR_NR_ROW12_Val << HSDRAMC_CR_NR_Pos)       /**< (HSDRAMC_CR) 12 bits to define the row number, up to 4096 rows Position  */
#define HSDRAMC_CR_NR_ROW13                   (HSDRAMC_CR_NR_ROW13_Val << HSDRAMC_CR_NR_Pos)       /**< (HSDRAMC_CR) 13 bits to define the row number, up to 8192 rows Position  */
#define HSDRAMC_CR_NB_Pos                     _U_(5)                                               /**< (HSDRAMC_CR) Number of Banks Position */
#define HSDRAMC_CR_NB_Msk                     (_U_(0x1) << HSDRAMC_CR_NB_Pos)                      /**< (HSDRAMC_CR) Number of Banks Mask */
#define HSDRAMC_CR_NB(value)                  (HSDRAMC_CR_NB_Msk & ((value) << HSDRAMC_CR_NB_Pos))
#define   HSDRAMC_CR_NB_BANK2_Val             _U_(0x0)                                             /**< (HSDRAMC_CR) 2 banks  */
#define   HSDRAMC_CR_NB_BANK4_Val             _U_(0x1)                                             /**< (HSDRAMC_CR) 4 banks  */
#define HSDRAMC_CR_NB_BANK2                   (HSDRAMC_CR_NB_BANK2_Val << HSDRAMC_CR_NB_Pos)       /**< (HSDRAMC_CR) 2 banks Position  */
#define HSDRAMC_CR_NB_BANK4                   (HSDRAMC_CR_NB_BANK4_Val << HSDRAMC_CR_NB_Pos)       /**< (HSDRAMC_CR) 4 banks Position  */
#define HSDRAMC_CR_CAS_Pos                    _U_(6)                                               /**< (HSDRAMC_CR) CAS Latency Position */
#define HSDRAMC_CR_CAS_Msk                    (_U_(0x3) << HSDRAMC_CR_CAS_Pos)                     /**< (HSDRAMC_CR) CAS Latency Mask */
#define HSDRAMC_CR_CAS(value)                 (HSDRAMC_CR_CAS_Msk & ((value) << HSDRAMC_CR_CAS_Pos))
#define   HSDRAMC_CR_CAS_LATENCY1_Val         _U_(0x1)                                             /**< (HSDRAMC_CR) 1 cycle latency  */
#define   HSDRAMC_CR_CAS_LATENCY2_Val         _U_(0x2)                                             /**< (HSDRAMC_CR) 2 cycle latency  */
#define   HSDRAMC_CR_CAS_LATENCY3_Val         _U_(0x3)                                             /**< (HSDRAMC_CR) 3 cycle latency  */
#define HSDRAMC_CR_CAS_LATENCY1               (HSDRAMC_CR_CAS_LATENCY1_Val << HSDRAMC_CR_CAS_Pos)  /**< (HSDRAMC_CR) 1 cycle latency Position  */
#define HSDRAMC_CR_CAS_LATENCY2               (HSDRAMC_CR_CAS_LATENCY2_Val << HSDRAMC_CR_CAS_Pos)  /**< (HSDRAMC_CR) 2 cycle latency Position  */
#define HSDRAMC_CR_CAS_LATENCY3               (HSDRAMC_CR_CAS_LATENCY3_Val << HSDRAMC_CR_CAS_Pos)  /**< (HSDRAMC_CR) 3 cycle latency Position  */
#define HSDRAMC_CR_DBW_Pos                    _U_(8)                                               /**< (HSDRAMC_CR) Data Bus Width Position */
#define HSDRAMC_CR_DBW_Msk                    (_U_(0x1) << HSDRAMC_CR_DBW_Pos)                     /**< (HSDRAMC_CR) Data Bus Width Mask */
#define HSDRAMC_CR_DBW(value)                 (HSDRAMC_CR_DBW_Msk & ((value) << HSDRAMC_CR_DBW_Pos))
#define HSDRAMC_CR_RMW_Pos                    _U_(9)                                               /**< (HSDRAMC_CR) Read Modify Write Position */
#define HSDRAMC_CR_RMW_Msk                    (_U_(0x1) << HSDRAMC_CR_RMW_Pos)                     /**< (HSDRAMC_CR) Read Modify Write Mask */
#define HSDRAMC_CR_RMW(value)                 (HSDRAMC_CR_RMW_Msk & ((value) << HSDRAMC_CR_RMW_Pos))
#define HSDRAMC_CR_Msk                        _U_(0x000003FF)                                      /**< (HSDRAMC_CR) Register Mask  */


/* -------- HSDRAMC_SDR : (HSDRAMC Offset: 0x0C) (R/W 32) Setup Delay Register -------- */
#define HSDRAMC_SDR_TWR_Pos                   _U_(0)                                               /**< (HSDRAMC_SDR) Write Recovery Delay Position */
#define HSDRAMC_SDR_TWR_Msk                   (_U_(0xF) << HSDRAMC_SDR_TWR_Pos)                    /**< (HSDRAMC_SDR) Write Recovery Delay Mask */
#define HSDRAMC_SDR_TWR(value)                (HSDRAMC_SDR_TWR_Msk & ((value) << HSDRAMC_SDR_TWR_Pos))
#define HSDRAMC_SDR_TRC_TRFC_Pos              _U_(4)                                               /**< (HSDRAMC_SDR) Row Cycle Delay and Row Refresh Cycle Position */
#define HSDRAMC_SDR_TRC_TRFC_Msk              (_U_(0xF) << HSDRAMC_SDR_TRC_TRFC_Pos)               /**< (HSDRAMC_SDR) Row Cycle Delay and Row Refresh Cycle Mask */
#define HSDRAMC_SDR_TRC_TRFC(value)           (HSDRAMC_SDR_TRC_TRFC_Msk & ((value) << HSDRAMC_SDR_TRC_TRFC_Pos))
#define HSDRAMC_SDR_TRP_Pos                   _U_(8)                                               /**< (HSDRAMC_SDR) Row Precharge Delay Position */
#define HSDRAMC_SDR_TRP_Msk                   (_U_(0xF) << HSDRAMC_SDR_TRP_Pos)                    /**< (HSDRAMC_SDR) Row Precharge Delay Mask */
#define HSDRAMC_SDR_TRP(value)                (HSDRAMC_SDR_TRP_Msk & ((value) << HSDRAMC_SDR_TRP_Pos))
#define HSDRAMC_SDR_TRCD_Pos                  _U_(12)                                              /**< (HSDRAMC_SDR) Row to Column Delay Position */
#define HSDRAMC_SDR_TRCD_Msk                  (_U_(0xF) << HSDRAMC_SDR_TRCD_Pos)                   /**< (HSDRAMC_SDR) Row to Column Delay Mask */
#define HSDRAMC_SDR_TRCD(value)               (HSDRAMC_SDR_TRCD_Msk & ((value) << HSDRAMC_SDR_TRCD_Pos))
#define HSDRAMC_SDR_TRAS_Pos                  _U_(16)                                              /**< (HSDRAMC_SDR) Active to Precharge Delay Position */
#define HSDRAMC_SDR_TRAS_Msk                  (_U_(0xF) << HSDRAMC_SDR_TRAS_Pos)                   /**< (HSDRAMC_SDR) Active to Precharge Delay Mask */
#define HSDRAMC_SDR_TRAS(value)               (HSDRAMC_SDR_TRAS_Msk & ((value) << HSDRAMC_SDR_TRAS_Pos))
#define HSDRAMC_SDR_TXSR_Pos                  _U_(20)                                              /**< (HSDRAMC_SDR) Exit Self-Refresh to Active Delay Position */
#define HSDRAMC_SDR_TXSR_Msk                  (_U_(0xF) << HSDRAMC_SDR_TXSR_Pos)                   /**< (HSDRAMC_SDR) Exit Self-Refresh to Active Delay Mask */
#define HSDRAMC_SDR_TXSR(value)               (HSDRAMC_SDR_TXSR_Msk & ((value) << HSDRAMC_SDR_TXSR_Pos))
#define HSDRAMC_SDR_Msk                       _U_(0x00FFFFFF)                                      /**< (HSDRAMC_SDR) Register Mask  */


/* -------- HSDRAMC_IER : (HSDRAMC Offset: 0x14) ( /W 32) Interrupt Enable Register -------- */
#define HSDRAMC_IER_RES_Pos                   _U_(0)                                               /**< (HSDRAMC_IER) Refresh Error Interrupt Enable Position */
#define HSDRAMC_IER_RES_Msk                   (_U_(0x1) << HSDRAMC_IER_RES_Pos)                    /**< (HSDRAMC_IER) Refresh Error Interrupt Enable Mask */
#define HSDRAMC_IER_RES(value)                (HSDRAMC_IER_RES_Msk & ((value) << HSDRAMC_IER_RES_Pos))
#define HSDRAMC_IER_Msk                       _U_(0x00000001)                                      /**< (HSDRAMC_IER) Register Mask  */


/* -------- HSDRAMC_IDR : (HSDRAMC Offset: 0x18) ( /W 32) Interrupt Disable Register -------- */
#define HSDRAMC_IDR_RES_Pos                   _U_(0)                                               /**< (HSDRAMC_IDR) Refresh Error Interrupt Disable Position */
#define HSDRAMC_IDR_RES_Msk                   (_U_(0x1) << HSDRAMC_IDR_RES_Pos)                    /**< (HSDRAMC_IDR) Refresh Error Interrupt Disable Mask */
#define HSDRAMC_IDR_RES(value)                (HSDRAMC_IDR_RES_Msk & ((value) << HSDRAMC_IDR_RES_Pos))
#define HSDRAMC_IDR_Msk                       _U_(0x00000001)                                      /**< (HSDRAMC_IDR) Register Mask  */


/* -------- HSDRAMC_IMR : (HSDRAMC Offset: 0x1C) ( R/ 32) Interrupt Mask Register -------- */
#define HSDRAMC_IMR_RES_Pos                   _U_(0)                                               /**< (HSDRAMC_IMR) Refresh Error Interrupt Mask Position */
#define HSDRAMC_IMR_RES_Msk                   (_U_(0x1) << HSDRAMC_IMR_RES_Pos)                    /**< (HSDRAMC_IMR) Refresh Error Interrupt Mask Mask */
#define HSDRAMC_IMR_RES(value)                (HSDRAMC_IMR_RES_Msk & ((value) << HSDRAMC_IMR_RES_Pos))
#define HSDRAMC_IMR_Msk                       _U_(0x00000001)                                      /**< (HSDRAMC_IMR) Register Mask  */


/* -------- HSDRAMC_ISR : (HSDRAMC Offset: 0x20) ( R/ 32) Interrupt Status Register -------- */
#define HSDRAMC_ISR_RES_Pos                   _U_(0)                                               /**< (HSDRAMC_ISR) Refresh Error Status (cleared on read) Position */
#define HSDRAMC_ISR_RES_Msk                   (_U_(0x1) << HSDRAMC_ISR_RES_Pos)                    /**< (HSDRAMC_ISR) Refresh Error Status (cleared on read) Mask */
#define HSDRAMC_ISR_RES(value)                (HSDRAMC_ISR_RES_Msk & ((value) << HSDRAMC_ISR_RES_Pos))
#define HSDRAMC_ISR_Msk                       _U_(0x00000001)                                      /**< (HSDRAMC_ISR) Register Mask  */


/* -------- HSDRAMC_CFR1 : (HSDRAMC Offset: 0x24) (R/W 32) Configuration Register 1 -------- */
#define HSDRAMC_CFR1_TMRD_Pos                 _U_(0)                                               /**< (HSDRAMC_CFR1) Load Mode Register Command to Active or Refresh Command Position */
#define HSDRAMC_CFR1_TMRD_Msk                 (_U_(0xF) << HSDRAMC_CFR1_TMRD_Pos)                  /**< (HSDRAMC_CFR1) Load Mode Register Command to Active or Refresh Command Mask */
#define HSDRAMC_CFR1_TMRD(value)              (HSDRAMC_CFR1_TMRD_Msk & ((value) << HSDRAMC_CFR1_TMRD_Pos))
#define HSDRAMC_CFR1_UNAL_Pos                 _U_(8)                                               /**< (HSDRAMC_CFR1) Support Unaligned Access Position */
#define HSDRAMC_CFR1_UNAL_Msk                 (_U_(0x1) << HSDRAMC_CFR1_UNAL_Pos)                  /**< (HSDRAMC_CFR1) Support Unaligned Access Mask */
#define HSDRAMC_CFR1_UNAL(value)              (HSDRAMC_CFR1_UNAL_Msk & ((value) << HSDRAMC_CFR1_UNAL_Pos))
#define   HSDRAMC_CFR1_UNAL_UNSUPPORTED_Val   _U_(0x0)                                             /**< (HSDRAMC_CFR1) Unaligned access is not supported.  */
#define   HSDRAMC_CFR1_UNAL_SUPPORTED_Val     _U_(0x1)                                             /**< (HSDRAMC_CFR1) Unaligned access is supported.  */
#define HSDRAMC_CFR1_UNAL_UNSUPPORTED         (HSDRAMC_CFR1_UNAL_UNSUPPORTED_Val << HSDRAMC_CFR1_UNAL_Pos) /**< (HSDRAMC_CFR1) Unaligned access is not supported. Position  */
#define HSDRAMC_CFR1_UNAL_SUPPORTED           (HSDRAMC_CFR1_UNAL_SUPPORTED_Val << HSDRAMC_CFR1_UNAL_Pos) /**< (HSDRAMC_CFR1) Unaligned access is supported. Position  */
#define HSDRAMC_CFR1_Msk                      _U_(0x0000010F)                                      /**< (HSDRAMC_CFR1) Register Mask  */


/* -------- HSDRAMC_WPMR : (HSDRAMC Offset: 0x28) (R/W 32) Write Protection Mode Register -------- */
#define HSDRAMC_WPMR_WPEN_Pos                 _U_(0)                                               /**< (HSDRAMC_WPMR) Write Protection Enable Position */
#define HSDRAMC_WPMR_WPEN_Msk                 (_U_(0x1) << HSDRAMC_WPMR_WPEN_Pos)                  /**< (HSDRAMC_WPMR) Write Protection Enable Mask */
#define HSDRAMC_WPMR_WPEN(value)              (HSDRAMC_WPMR_WPEN_Msk & ((value) << HSDRAMC_WPMR_WPEN_Pos))
#define HSDRAMC_WPMR_WPKEY_Pos                _U_(8)                                               /**< (HSDRAMC_WPMR) Write Protection Key Position */
#define HSDRAMC_WPMR_WPKEY_Msk                (_U_(0xFFFFFF) << HSDRAMC_WPMR_WPKEY_Pos)            /**< (HSDRAMC_WPMR) Write Protection Key Mask */
#define HSDRAMC_WPMR_WPKEY(value)             (HSDRAMC_WPMR_WPKEY_Msk & ((value) << HSDRAMC_WPMR_WPKEY_Pos))
#define   HSDRAMC_WPMR_WPKEY_PASSWD_Val       _U_(0x534452)                                        /**< (HSDRAMC_WPMR) Writing any other value in this field aborts the write operation of the WPEN bit.Always reads as 0.  */
#define HSDRAMC_WPMR_WPKEY_PASSWD             (HSDRAMC_WPMR_WPKEY_PASSWD_Val << HSDRAMC_WPMR_WPKEY_Pos) /**< (HSDRAMC_WPMR) Writing any other value in this field aborts the write operation of the WPEN bit.Always reads as 0. Position  */
#define HSDRAMC_WPMR_Msk                      _U_(0xFFFFFF01)                                      /**< (HSDRAMC_WPMR) Register Mask  */


/* -------- HSDRAMC_WPSR : (HSDRAMC Offset: 0x2C) ( R/ 32) Write Protection Status Register -------- */
#define HSDRAMC_WPSR_WPVS_Pos                 _U_(0)                                               /**< (HSDRAMC_WPSR) Write Protection Violation Status Position */
#define HSDRAMC_WPSR_WPVS_Msk                 (_U_(0x1) << HSDRAMC_WPSR_WPVS_Pos)                  /**< (HSDRAMC_WPSR) Write Protection Violation Status Mask */
#define HSDRAMC_WPSR_WPVS(value)              (HSDRAMC_WPSR_WPVS_Msk & ((value) << HSDRAMC_WPSR_WPVS_Pos))
#define HSDRAMC_WPSR_WPVSRC_Pos               _U_(8)                                               /**< (HSDRAMC_WPSR) Write Protection Violation Source Position */
#define HSDRAMC_WPSR_WPVSRC_Msk               (_U_(0xFF) << HSDRAMC_WPSR_WPVSRC_Pos)               /**< (HSDRAMC_WPSR) Write Protection Violation Source Mask */
#define HSDRAMC_WPSR_WPVSRC(value)            (HSDRAMC_WPSR_WPVSRC_Msk & ((value) << HSDRAMC_WPSR_WPVSRC_Pos))
#define HSDRAMC_WPSR_Msk                      _U_(0x0000FF01)                                      /**< (HSDRAMC_WPSR) Register Mask  */


/** \brief HSDRAMC register offsets definitions */
#define HSDRAMC_MR_REG_OFST            (0x00)              /**< (HSDRAMC_MR) Mode Register Offset */
#define HSDRAMC_TR_REG_OFST            (0x04)              /**< (HSDRAMC_TR) Refresh Timer Register Offset */
#define HSDRAMC_CR_REG_OFST            (0x08)              /**< (HSDRAMC_CR) Configuration Register Offset */
#define HSDRAMC_SDR_REG_OFST           (0x0C)              /**< (HSDRAMC_SDR) Setup Delay Register Offset */
#define HSDRAMC_IER_REG_OFST           (0x14)              /**< (HSDRAMC_IER) Interrupt Enable Register Offset */
#define HSDRAMC_IDR_REG_OFST           (0x18)              /**< (HSDRAMC_IDR) Interrupt Disable Register Offset */
#define HSDRAMC_IMR_REG_OFST           (0x1C)              /**< (HSDRAMC_IMR) Interrupt Mask Register Offset */
#define HSDRAMC_ISR_REG_OFST           (0x20)              /**< (HSDRAMC_ISR) Interrupt Status Register Offset */
#define HSDRAMC_CFR1_REG_OFST          (0x24)              /**< (HSDRAMC_CFR1) Configuration Register 1 Offset */
#define HSDRAMC_WPMR_REG_OFST          (0x28)              /**< (HSDRAMC_WPMR) Write Protection Mode Register Offset */
#define HSDRAMC_WPSR_REG_OFST          (0x2C)              /**< (HSDRAMC_WPSR) Write Protection Status Register Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief HSDRAMC register API structure */
typedef struct
{
  __IO  uint32_t                       HSDRAMC_MR;         /**< Offset: 0x00 (R/W  32) Mode Register */
  __IO  uint32_t                       HSDRAMC_TR;         /**< Offset: 0x04 (R/W  32) Refresh Timer Register */
  __IO  uint32_t                       HSDRAMC_CR;         /**< Offset: 0x08 (R/W  32) Configuration Register */
  __IO  uint32_t                       HSDRAMC_SDR;        /**< Offset: 0x0C (R/W  32) Setup Delay Register */
  __I   uint8_t                        Reserved1[0x04];
  __O   uint32_t                       HSDRAMC_IER;        /**< Offset: 0x14 ( /W  32) Interrupt Enable Register */
  __O   uint32_t                       HSDRAMC_IDR;        /**< Offset: 0x18 ( /W  32) Interrupt Disable Register */
  __I   uint32_t                       HSDRAMC_IMR;        /**< Offset: 0x1C (R/   32) Interrupt Mask Register */
  __I   uint32_t                       HSDRAMC_ISR;        /**< Offset: 0x20 (R/   32) Interrupt Status Register */
  __IO  uint32_t                       HSDRAMC_CFR1;       /**< Offset: 0x24 (R/W  32) Configuration Register 1 */
  __IO  uint32_t                       HSDRAMC_WPMR;       /**< Offset: 0x28 (R/W  32) Write Protection Mode Register */
  __I   uint32_t                       HSDRAMC_WPSR;       /**< Offset: 0x2C (R/   32) Write Protection Status Register */
} hsdramc_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _SAMRH71_HSDRAMC_COMPONENT_H_ */
