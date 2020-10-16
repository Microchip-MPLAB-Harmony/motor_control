/**
 * \brief Component description for HEFC
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
#ifndef _SAMRH71_HEFC_COMPONENT_H_
#define _SAMRH71_HEFC_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR HEFC                                         */
/* ************************************************************************** */

/* -------- HEFC_FMR : (HEFC Offset: 0x00) (R/W 32) HEFC Flash Mode Register -------- */
#define HEFC_FMR_FRDY_Pos                     _U_(0)                                               /**< (HEFC_FMR) Flash Ready Interrupt Enable Position */
#define HEFC_FMR_FRDY_Msk                     (_U_(0x1) << HEFC_FMR_FRDY_Pos)                      /**< (HEFC_FMR) Flash Ready Interrupt Enable Mask */
#define HEFC_FMR_FRDY(value)                  (HEFC_FMR_FRDY_Msk & ((value) << HEFC_FMR_FRDY_Pos))
#define HEFC_FMR_FPSI_Pos                     _U_(1)                                               /**< (HEFC_FMR) Flash Power Status Interrupt Enable Position */
#define HEFC_FMR_FPSI_Msk                     (_U_(0x1) << HEFC_FMR_FPSI_Pos)                      /**< (HEFC_FMR) Flash Power Status Interrupt Enable Mask */
#define HEFC_FMR_FPSI(value)                  (HEFC_FMR_FPSI_Msk & ((value) << HEFC_FMR_FPSI_Pos))
#define HEFC_FMR_ONE_Pos                      _U_(16)                                              /**< (HEFC_FMR) Must be written to 1 Position */
#define HEFC_FMR_ONE_Msk                      (_U_(0x1) << HEFC_FMR_ONE_Pos)                       /**< (HEFC_FMR) Must be written to 1 Mask */
#define HEFC_FMR_ONE(value)                   (HEFC_FMR_ONE_Msk & ((value) << HEFC_FMR_ONE_Pos))  
#define HEFC_FMR_Msk                          _U_(0x00010003)                                      /**< (HEFC_FMR) Register Mask  */


/* -------- HEFC_FCR : (HEFC Offset: 0x04) ( /W 32) HEFC Flash Command Register -------- */
#define HEFC_FCR_FCMD_Pos                     _U_(0)                                               /**< (HEFC_FCR) Flash Command Position */
#define HEFC_FCR_FCMD_Msk                     (_U_(0xFF) << HEFC_FCR_FCMD_Pos)                     /**< (HEFC_FCR) Flash Command Mask */
#define HEFC_FCR_FCMD(value)                  (HEFC_FCR_FCMD_Msk & ((value) << HEFC_FCR_FCMD_Pos))
#define   HEFC_FCR_FCMD_GETD_Val              _U_(0x0)                                             /**< (HEFC_FCR) Get Flash descriptor  */
#define   HEFC_FCR_FCMD_WP_Val                _U_(0x1)                                             /**< (HEFC_FCR) Write page  */
#define   HEFC_FCR_FCMD_WPL_Val               _U_(0x2)                                             /**< (HEFC_FCR) Write page and lock  */
#define   HEFC_FCR_FCMD_EA_Val                _U_(0x5)                                             /**< (HEFC_FCR) Erase all  */
#define   HEFC_FCR_FCMD_EP_Val                _U_(0x6)                                             /**< (HEFC_FCR) Erase page  */
#define   HEFC_FCR_FCMD_EPA_Val               _U_(0x7)                                             /**< (HEFC_FCR) Erase pages  */
#define   HEFC_FCR_FCMD_SLB_Val               _U_(0x8)                                             /**< (HEFC_FCR) Set lock bit  */
#define   HEFC_FCR_FCMD_CLB_Val               _U_(0x9)                                             /**< (HEFC_FCR) Clear lock bit  */
#define   HEFC_FCR_FCMD_GLB_Val               _U_(0xA)                                             /**< (HEFC_FCR) Get lock bit  */
#define   HEFC_FCR_FCMD_SGPB_Val              _U_(0xB)                                             /**< (HEFC_FCR) Set GPNVM bit  */
#define   HEFC_FCR_FCMD_CGPB_Val              _U_(0xC)                                             /**< (HEFC_FCR) Clear GPNVM bit  */
#define   HEFC_FCR_FCMD_GGPB_Val              _U_(0xD)                                             /**< (HEFC_FCR) Get GPNVM bit  */
#define   HEFC_FCR_FCMD_GCALB_Val             _U_(0x10)                                            /**< (HEFC_FCR) Get CALIB bit  */
#define   HEFC_FCR_FCMD_WUS_Val               _U_(0x12)                                            /**< (HEFC_FCR) Write user signature  */
#define   HEFC_FCR_FCMD_EUS_Val               _U_(0x13)                                            /**< (HEFC_FCR) Erase user signature  */
#define   HEFC_FCR_FCMD_STUS_Val              _U_(0x14)                                            /**< (HEFC_FCR) Start read user signature  */
#define   HEFC_FCR_FCMD_SPUS_Val              _U_(0x15)                                            /**< (HEFC_FCR) Stop read user signature  */
#define HEFC_FCR_FCMD_GETD                    (HEFC_FCR_FCMD_GETD_Val << HEFC_FCR_FCMD_Pos)        /**< (HEFC_FCR) Get Flash descriptor Position  */
#define HEFC_FCR_FCMD_WP                      (HEFC_FCR_FCMD_WP_Val << HEFC_FCR_FCMD_Pos)          /**< (HEFC_FCR) Write page Position  */
#define HEFC_FCR_FCMD_WPL                     (HEFC_FCR_FCMD_WPL_Val << HEFC_FCR_FCMD_Pos)         /**< (HEFC_FCR) Write page and lock Position  */
#define HEFC_FCR_FCMD_EA                      (HEFC_FCR_FCMD_EA_Val << HEFC_FCR_FCMD_Pos)          /**< (HEFC_FCR) Erase all Position  */
#define HEFC_FCR_FCMD_EP                      (HEFC_FCR_FCMD_EP_Val << HEFC_FCR_FCMD_Pos)          /**< (HEFC_FCR) Erase page Position  */
#define HEFC_FCR_FCMD_EPA                     (HEFC_FCR_FCMD_EPA_Val << HEFC_FCR_FCMD_Pos)         /**< (HEFC_FCR) Erase pages Position  */
#define HEFC_FCR_FCMD_SLB                     (HEFC_FCR_FCMD_SLB_Val << HEFC_FCR_FCMD_Pos)         /**< (HEFC_FCR) Set lock bit Position  */
#define HEFC_FCR_FCMD_CLB                     (HEFC_FCR_FCMD_CLB_Val << HEFC_FCR_FCMD_Pos)         /**< (HEFC_FCR) Clear lock bit Position  */
#define HEFC_FCR_FCMD_GLB                     (HEFC_FCR_FCMD_GLB_Val << HEFC_FCR_FCMD_Pos)         /**< (HEFC_FCR) Get lock bit Position  */
#define HEFC_FCR_FCMD_SGPB                    (HEFC_FCR_FCMD_SGPB_Val << HEFC_FCR_FCMD_Pos)        /**< (HEFC_FCR) Set GPNVM bit Position  */
#define HEFC_FCR_FCMD_CGPB                    (HEFC_FCR_FCMD_CGPB_Val << HEFC_FCR_FCMD_Pos)        /**< (HEFC_FCR) Clear GPNVM bit Position  */
#define HEFC_FCR_FCMD_GGPB                    (HEFC_FCR_FCMD_GGPB_Val << HEFC_FCR_FCMD_Pos)        /**< (HEFC_FCR) Get GPNVM bit Position  */
#define HEFC_FCR_FCMD_GCALB                   (HEFC_FCR_FCMD_GCALB_Val << HEFC_FCR_FCMD_Pos)       /**< (HEFC_FCR) Get CALIB bit Position  */
#define HEFC_FCR_FCMD_WUS                     (HEFC_FCR_FCMD_WUS_Val << HEFC_FCR_FCMD_Pos)         /**< (HEFC_FCR) Write user signature Position  */
#define HEFC_FCR_FCMD_EUS                     (HEFC_FCR_FCMD_EUS_Val << HEFC_FCR_FCMD_Pos)         /**< (HEFC_FCR) Erase user signature Position  */
#define HEFC_FCR_FCMD_STUS                    (HEFC_FCR_FCMD_STUS_Val << HEFC_FCR_FCMD_Pos)        /**< (HEFC_FCR) Start read user signature Position  */
#define HEFC_FCR_FCMD_SPUS                    (HEFC_FCR_FCMD_SPUS_Val << HEFC_FCR_FCMD_Pos)        /**< (HEFC_FCR) Stop read user signature Position  */
#define HEFC_FCR_FARG_Pos                     _U_(8)                                               /**< (HEFC_FCR) Flash Command Argument Position */
#define HEFC_FCR_FARG_Msk                     (_U_(0xFFFF) << HEFC_FCR_FARG_Pos)                   /**< (HEFC_FCR) Flash Command Argument Mask */
#define HEFC_FCR_FARG(value)                  (HEFC_FCR_FARG_Msk & ((value) << HEFC_FCR_FARG_Pos))
#define HEFC_FCR_FKEY_Pos                     _U_(24)                                              /**< (HEFC_FCR) Flash Writing Protection Key Position */
#define HEFC_FCR_FKEY_Msk                     (_U_(0xFF) << HEFC_FCR_FKEY_Pos)                     /**< (HEFC_FCR) Flash Writing Protection Key Mask */
#define HEFC_FCR_FKEY(value)                  (HEFC_FCR_FKEY_Msk & ((value) << HEFC_FCR_FKEY_Pos))
#define   HEFC_FCR_FKEY_PASSWD_Val            _U_(0x5A)                                            /**< (HEFC_FCR) The 0x5A value enables the command defined by the bits of the register. If the field is written with a different value, the write is not performed and no action is started.  */
#define HEFC_FCR_FKEY_PASSWD                  (HEFC_FCR_FKEY_PASSWD_Val << HEFC_FCR_FKEY_Pos)      /**< (HEFC_FCR) The 0x5A value enables the command defined by the bits of the register. If the field is written with a different value, the write is not performed and no action is started. Position  */
#define HEFC_FCR_Msk                          _U_(0xFFFFFFFF)                                      /**< (HEFC_FCR) Register Mask  */


/* -------- HEFC_FSR : (HEFC Offset: 0x08) ( R/ 32) HEFC Flash Status Register -------- */
#define HEFC_FSR_FRDY_Pos                     _U_(0)                                               /**< (HEFC_FSR) Flash Ready Status (cleared when Flash is busy) Position */
#define HEFC_FSR_FRDY_Msk                     (_U_(0x1) << HEFC_FSR_FRDY_Pos)                      /**< (HEFC_FSR) Flash Ready Status (cleared when Flash is busy) Mask */
#define HEFC_FSR_FRDY(value)                  (HEFC_FSR_FRDY_Msk & ((value) << HEFC_FSR_FRDY_Pos))
#define HEFC_FSR_FCMDE_Pos                    _U_(1)                                               /**< (HEFC_FSR) Flash Command Error Status (cleared on read or by writing HEFC_FCR) Position */
#define HEFC_FSR_FCMDE_Msk                    (_U_(0x1) << HEFC_FSR_FCMDE_Pos)                     /**< (HEFC_FSR) Flash Command Error Status (cleared on read or by writing HEFC_FCR) Mask */
#define HEFC_FSR_FCMDE(value)                 (HEFC_FSR_FCMDE_Msk & ((value) << HEFC_FSR_FCMDE_Pos))
#define HEFC_FSR_FLOCKE_Pos                   _U_(2)                                               /**< (HEFC_FSR) Flash Lock Error Status (cleared on read) Position */
#define HEFC_FSR_FLOCKE_Msk                   (_U_(0x1) << HEFC_FSR_FLOCKE_Pos)                    /**< (HEFC_FSR) Flash Lock Error Status (cleared on read) Mask */
#define HEFC_FSR_FLOCKE(value)                (HEFC_FSR_FLOCKE_Msk & ((value) << HEFC_FSR_FLOCKE_Pos))
#define HEFC_FSR_WREER_Pos                    _U_(4)                                               /**< (HEFC_FSR) Write Register Error Status (cleared on read) Position */
#define HEFC_FSR_WREER_Msk                    (_U_(0x1) << HEFC_FSR_WREER_Pos)                     /**< (HEFC_FSR) Write Register Error Status (cleared on read) Mask */
#define HEFC_FSR_WREER(value)                 (HEFC_FSR_WREER_Msk & ((value) << HEFC_FSR_WREER_Pos))
#define HEFC_FSR_Msk                          _U_(0x00000017)                                      /**< (HEFC_FSR) Register Mask  */


/* -------- HEFC_FRR : (HEFC Offset: 0x0C) ( R/ 32) HEFC Flash Result Register -------- */
#define HEFC_FRR_FVALUE_Pos                   _U_(0)                                               /**< (HEFC_FRR) Flash Result Value Position */
#define HEFC_FRR_FVALUE_Msk                   (_U_(0xFFFFFFFF) << HEFC_FRR_FVALUE_Pos)             /**< (HEFC_FRR) Flash Result Value Mask */
#define HEFC_FRR_FVALUE(value)                (HEFC_FRR_FVALUE_Msk & ((value) << HEFC_FRR_FVALUE_Pos))
#define HEFC_FRR_Msk                          _U_(0xFFFFFFFF)                                      /**< (HEFC_FRR) Register Mask  */


/* -------- HEFC_FPMR : (HEFC Offset: 0x40) (R/W 32) HEFC Flash Power Management Register -------- */
#define HEFC_FPMR_PWS_EN_Pos                  _U_(0)                                               /**< (HEFC_FPMR) Power switch enable Position */
#define HEFC_FPMR_PWS_EN_Msk                  (_U_(0x1) << HEFC_FPMR_PWS_EN_Pos)                   /**< (HEFC_FPMR) Power switch enable Mask */
#define HEFC_FPMR_PWS_EN(value)               (HEFC_FPMR_PWS_EN_Msk & ((value) << HEFC_FPMR_PWS_EN_Pos))
#define HEFC_FPMR_PWS_STAT_Pos                _U_(1)                                               /**< (HEFC_FPMR) Power switch Status Position */
#define HEFC_FPMR_PWS_STAT_Msk                (_U_(0x1) << HEFC_FPMR_PWS_STAT_Pos)                 /**< (HEFC_FPMR) Power switch Status Mask */
#define HEFC_FPMR_PWS_STAT(value)             (HEFC_FPMR_PWS_STAT_Msk & ((value) << HEFC_FPMR_PWS_STAT_Pos))
#define HEFC_FPMR_PWS_DLY_Pos                 _U_(2)                                               /**< (HEFC_FPMR) Power switch Delay Position */
#define HEFC_FPMR_PWS_DLY_Msk                 (_U_(0x3) << HEFC_FPMR_PWS_DLY_Pos)                  /**< (HEFC_FPMR) Power switch Delay Mask */
#define HEFC_FPMR_PWS_DLY(value)              (HEFC_FPMR_PWS_DLY_Msk & ((value) << HEFC_FPMR_PWS_DLY_Pos))
#define   HEFC_FPMR_PWS_DLY_75US_Val          _U_(0x0)                                             /**< (HEFC_FPMR) delay is set to 75 usec  */
#define   HEFC_FPMR_PWS_DLY_150US_Val         _U_(0x1)                                             /**< (HEFC_FPMR) delay is set to 150 usec  */
#define   HEFC_FPMR_PWS_DLY_300US_Val         _U_(0x2)                                             /**< (HEFC_FPMR) delay is set to 300 usec  */
#define   HEFC_FPMR_PWS_DLY_600US_Val         _U_(0x3)                                             /**< (HEFC_FPMR) delay is set to 600 usec  */
#define HEFC_FPMR_PWS_DLY_75US                (HEFC_FPMR_PWS_DLY_75US_Val << HEFC_FPMR_PWS_DLY_Pos) /**< (HEFC_FPMR) delay is set to 75 usec Position  */
#define HEFC_FPMR_PWS_DLY_150US               (HEFC_FPMR_PWS_DLY_150US_Val << HEFC_FPMR_PWS_DLY_Pos) /**< (HEFC_FPMR) delay is set to 150 usec Position  */
#define HEFC_FPMR_PWS_DLY_300US               (HEFC_FPMR_PWS_DLY_300US_Val << HEFC_FPMR_PWS_DLY_Pos) /**< (HEFC_FPMR) delay is set to 300 usec Position  */
#define HEFC_FPMR_PWS_DLY_600US               (HEFC_FPMR_PWS_DLY_600US_Val << HEFC_FPMR_PWS_DLY_Pos) /**< (HEFC_FPMR) delay is set to 600 usec Position  */
#define HEFC_FPMR_VAR_FACTOR_Pos              _U_(8)                                               /**< (HEFC_FPMR) Variation Factor Position */
#define HEFC_FPMR_VAR_FACTOR_Msk              (_U_(0x3F) << HEFC_FPMR_VAR_FACTOR_Pos)              /**< (HEFC_FPMR) Variation Factor Mask */
#define HEFC_FPMR_VAR_FACTOR(value)           (HEFC_FPMR_VAR_FACTOR_Msk & ((value) << HEFC_FPMR_VAR_FACTOR_Pos))
#define HEFC_FPMR_FUNC_ISOL_CTRL_N_Pos        _U_(16)                                              /**< (HEFC_FPMR) Flash insulated Control Status Position */
#define HEFC_FPMR_FUNC_ISOL_CTRL_N_Msk        (_U_(0x1) << HEFC_FPMR_FUNC_ISOL_CTRL_N_Pos)         /**< (HEFC_FPMR) Flash insulated Control Status Mask */
#define HEFC_FPMR_FUNC_ISOL_CTRL_N(value)     (HEFC_FPMR_FUNC_ISOL_CTRL_N_Msk & ((value) << HEFC_FPMR_FUNC_ISOL_CTRL_N_Pos))
#define HEFC_FPMR_Msk                         _U_(0x00013F0F)                                      /**< (HEFC_FPMR) Register Mask  */


/* -------- HEFC_WPMR : (HEFC Offset: 0xE4) (R/W 32) Write Protection Mode Register -------- */
#define HEFC_WPMR_WPEN_Pos                    _U_(0)                                               /**< (HEFC_WPMR) Write Protection Enable Position */
#define HEFC_WPMR_WPEN_Msk                    (_U_(0x1) << HEFC_WPMR_WPEN_Pos)                     /**< (HEFC_WPMR) Write Protection Enable Mask */
#define HEFC_WPMR_WPEN(value)                 (HEFC_WPMR_WPEN_Msk & ((value) << HEFC_WPMR_WPEN_Pos))
#define HEFC_WPMR_GPNVMWP_Pos                 _U_(1)                                               /**< (HEFC_WPMR) GPNVM Bit Write Protection Position */
#define HEFC_WPMR_GPNVMWP_Msk                 (_U_(0x1) << HEFC_WPMR_GPNVMWP_Pos)                  /**< (HEFC_WPMR) GPNVM Bit Write Protection Mask */
#define HEFC_WPMR_GPNVMWP(value)              (HEFC_WPMR_GPNVMWP_Msk & ((value) << HEFC_WPMR_GPNVMWP_Pos))
#define HEFC_WPMR_LOCKWP_Pos                  _U_(2)                                               /**< (HEFC_WPMR) Lock Bit Write Protection Position */
#define HEFC_WPMR_LOCKWP_Msk                  (_U_(0x1) << HEFC_WPMR_LOCKWP_Pos)                   /**< (HEFC_WPMR) Lock Bit Write Protection Mask */
#define HEFC_WPMR_LOCKWP(value)               (HEFC_WPMR_LOCKWP_Msk & ((value) << HEFC_WPMR_LOCKWP_Pos))
#define HEFC_WPMR_ERASEWP_Pos                 _U_(3)                                               /**< (HEFC_WPMR) Page, Sector and Plane Write Protection Position */
#define HEFC_WPMR_ERASEWP_Msk                 (_U_(0x1) << HEFC_WPMR_ERASEWP_Pos)                  /**< (HEFC_WPMR) Page, Sector and Plane Write Protection Mask */
#define HEFC_WPMR_ERASEWP(value)              (HEFC_WPMR_ERASEWP_Msk & ((value) << HEFC_WPMR_ERASEWP_Pos))
#define HEFC_WPMR_USER_Pos                    _U_(4)                                               /**< (HEFC_WPMR) User Signature Write Protection Position */
#define HEFC_WPMR_USER_Msk                    (_U_(0x1) << HEFC_WPMR_USER_Pos)                     /**< (HEFC_WPMR) User Signature Write Protection Mask */
#define HEFC_WPMR_USER(value)                 (HEFC_WPMR_USER_Msk & ((value) << HEFC_WPMR_USER_Pos))
#define HEFC_WPMR_WPKEY_Pos                   _U_(8)                                               /**< (HEFC_WPMR) Write Protection Key Position */
#define HEFC_WPMR_WPKEY_Msk                   (_U_(0xFFFFFF) << HEFC_WPMR_WPKEY_Pos)               /**< (HEFC_WPMR) Write Protection Key Mask */
#define HEFC_WPMR_WPKEY(value)                (HEFC_WPMR_WPKEY_Msk & ((value) << HEFC_WPMR_WPKEY_Pos))
#define   HEFC_WPMR_WPKEY_PASSWD_Val          _U_(0x454643)                                        /**< (HEFC_WPMR) Writing any other value in this field aborts the write operation.Always reads as 0.  */
#define HEFC_WPMR_WPKEY_PASSWD                (HEFC_WPMR_WPKEY_PASSWD_Val << HEFC_WPMR_WPKEY_Pos)  /**< (HEFC_WPMR) Writing any other value in this field aborts the write operation.Always reads as 0. Position  */
#define HEFC_WPMR_Msk                         _U_(0xFFFFFF1F)                                      /**< (HEFC_WPMR) Register Mask  */


/* -------- HEFC_HECC_CR0 : (HEFC Offset: 0x100) (R/W 32) HECC Control Register ChannelNumbers (ChannelNumbers = 0) 0 -------- */
#define HEFC_HECC_CR0_ENABLE_Pos              _U_(0)                                               /**< (HEFC_HECC_CR0) ECC protection enable Position */
#define HEFC_HECC_CR0_ENABLE_Msk              (_U_(0x1) << HEFC_HECC_CR0_ENABLE_Pos)               /**< (HEFC_HECC_CR0) ECC protection enable Mask */
#define HEFC_HECC_CR0_ENABLE(value)           (HEFC_HECC_CR0_ENABLE_Msk & ((value) << HEFC_HECC_CR0_ENABLE_Pos))
#define HEFC_HECC_CR0_TEST_MODE_RD_Pos        _U_(1)                                               /**< (HEFC_HECC_CR0) test mode of ECC protection - read mode Position */
#define HEFC_HECC_CR0_TEST_MODE_RD_Msk        (_U_(0x1) << HEFC_HECC_CR0_TEST_MODE_RD_Pos)         /**< (HEFC_HECC_CR0) test mode of ECC protection - read mode Mask */
#define HEFC_HECC_CR0_TEST_MODE_RD(value)     (HEFC_HECC_CR0_TEST_MODE_RD_Msk & ((value) << HEFC_HECC_CR0_TEST_MODE_RD_Pos))
#define HEFC_HECC_CR0_TEST_MODE_WR_Pos        _U_(2)                                               /**< (HEFC_HECC_CR0) test mode of ECC protection - write mode Position */
#define HEFC_HECC_CR0_TEST_MODE_WR_Msk        (_U_(0x1) << HEFC_HECC_CR0_TEST_MODE_WR_Pos)         /**< (HEFC_HECC_CR0) test mode of ECC protection - write mode Mask */
#define HEFC_HECC_CR0_TEST_MODE_WR(value)     (HEFC_HECC_CR0_TEST_MODE_WR_Msk & ((value) << HEFC_HECC_CR0_TEST_MODE_WR_Pos))
#define HEFC_HECC_CR0_RST_FIX_CPT_Pos         _U_(4)                                               /**< (HEFC_HECC_CR0) reset the fixable error counter Position */
#define HEFC_HECC_CR0_RST_FIX_CPT_Msk         (_U_(0x1) << HEFC_HECC_CR0_RST_FIX_CPT_Pos)          /**< (HEFC_HECC_CR0) reset the fixable error counter Mask */
#define HEFC_HECC_CR0_RST_FIX_CPT(value)      (HEFC_HECC_CR0_RST_FIX_CPT_Msk & ((value) << HEFC_HECC_CR0_RST_FIX_CPT_Pos))
#define HEFC_HECC_CR0_RST_NOFIX_CPT_Pos       _U_(5)                                               /**< (HEFC_HECC_CR0) reset the un-fixable error counter Position */
#define HEFC_HECC_CR0_RST_NOFIX_CPT_Msk       (_U_(0x1) << HEFC_HECC_CR0_RST_NOFIX_CPT_Pos)        /**< (HEFC_HECC_CR0) reset the un-fixable error counter Mask */
#define HEFC_HECC_CR0_RST_NOFIX_CPT(value)    (HEFC_HECC_CR0_RST_NOFIX_CPT_Msk & ((value) << HEFC_HECC_CR0_RST_NOFIX_CPT_Pos))
#define HEFC_HECC_CR0_ECC12_ENABLE_Pos        _U_(6)                                               /**< (HEFC_HECC_CR0) BCH ECC enable Position */
#define HEFC_HECC_CR0_ECC12_ENABLE_Msk        (_U_(0x1) << HEFC_HECC_CR0_ECC12_ENABLE_Pos)         /**< (HEFC_HECC_CR0) BCH ECC enable Mask */
#define HEFC_HECC_CR0_ECC12_ENABLE(value)     (HEFC_HECC_CR0_ECC12_ENABLE_Msk & ((value) << HEFC_HECC_CR0_ECC12_ENABLE_Pos))
#define HEFC_HECC_CR0_Msk                     _U_(0x00000077)                                      /**< (HEFC_HECC_CR0) Register Mask  */


/* -------- HEFC_HECC_CR1 : (HEFC Offset: 0x104) (R/W 32) HECC Control Register ChannelNumbers (ChannelNumbers = 0) 1 -------- */
#define HEFC_HECC_CR1_ENABLE_Pos              _U_(0)                                               /**< (HEFC_HECC_CR1) ECC protection enable Position */
#define HEFC_HECC_CR1_ENABLE_Msk              (_U_(0x1) << HEFC_HECC_CR1_ENABLE_Pos)               /**< (HEFC_HECC_CR1) ECC protection enable Mask */
#define HEFC_HECC_CR1_ENABLE(value)           (HEFC_HECC_CR1_ENABLE_Msk & ((value) << HEFC_HECC_CR1_ENABLE_Pos))
#define HEFC_HECC_CR1_TEST_MODE_RD_Pos        _U_(1)                                               /**< (HEFC_HECC_CR1) test mode of ECC protection - read mode Position */
#define HEFC_HECC_CR1_TEST_MODE_RD_Msk        (_U_(0x1) << HEFC_HECC_CR1_TEST_MODE_RD_Pos)         /**< (HEFC_HECC_CR1) test mode of ECC protection - read mode Mask */
#define HEFC_HECC_CR1_TEST_MODE_RD(value)     (HEFC_HECC_CR1_TEST_MODE_RD_Msk & ((value) << HEFC_HECC_CR1_TEST_MODE_RD_Pos))
#define HEFC_HECC_CR1_TEST_MODE_WR_Pos        _U_(2)                                               /**< (HEFC_HECC_CR1) test mode of ECC protection - write mode Position */
#define HEFC_HECC_CR1_TEST_MODE_WR_Msk        (_U_(0x1) << HEFC_HECC_CR1_TEST_MODE_WR_Pos)         /**< (HEFC_HECC_CR1) test mode of ECC protection - write mode Mask */
#define HEFC_HECC_CR1_TEST_MODE_WR(value)     (HEFC_HECC_CR1_TEST_MODE_WR_Msk & ((value) << HEFC_HECC_CR1_TEST_MODE_WR_Pos))
#define HEFC_HECC_CR1_RST_FIX_CPT_Pos         _U_(4)                                               /**< (HEFC_HECC_CR1) reset the fixable error counter Position */
#define HEFC_HECC_CR1_RST_FIX_CPT_Msk         (_U_(0x1) << HEFC_HECC_CR1_RST_FIX_CPT_Pos)          /**< (HEFC_HECC_CR1) reset the fixable error counter Mask */
#define HEFC_HECC_CR1_RST_FIX_CPT(value)      (HEFC_HECC_CR1_RST_FIX_CPT_Msk & ((value) << HEFC_HECC_CR1_RST_FIX_CPT_Pos))
#define HEFC_HECC_CR1_RST_NOFIX_CPT_Pos       _U_(5)                                               /**< (HEFC_HECC_CR1) reset the un-fixable error counter Position */
#define HEFC_HECC_CR1_RST_NOFIX_CPT_Msk       (_U_(0x1) << HEFC_HECC_CR1_RST_NOFIX_CPT_Pos)        /**< (HEFC_HECC_CR1) reset the un-fixable error counter Mask */
#define HEFC_HECC_CR1_RST_NOFIX_CPT(value)    (HEFC_HECC_CR1_RST_NOFIX_CPT_Msk & ((value) << HEFC_HECC_CR1_RST_NOFIX_CPT_Pos))
#define HEFC_HECC_CR1_ECC12_ENABLE_Pos        _U_(6)                                               /**< (HEFC_HECC_CR1) BCH ECC enable Position */
#define HEFC_HECC_CR1_ECC12_ENABLE_Msk        (_U_(0x1) << HEFC_HECC_CR1_ECC12_ENABLE_Pos)         /**< (HEFC_HECC_CR1) BCH ECC enable Mask */
#define HEFC_HECC_CR1_ECC12_ENABLE(value)     (HEFC_HECC_CR1_ECC12_ENABLE_Msk & ((value) << HEFC_HECC_CR1_ECC12_ENABLE_Pos))
#define HEFC_HECC_CR1_Msk                     _U_(0x00000077)                                      /**< (HEFC_HECC_CR1) Register Mask  */


/* -------- HEFC_HECC_CR2 : (HEFC Offset: 0x108) (R/W 32) HECC Control Register ChannelNumbers (ChannelNumbers = 0) 2 -------- */
#define HEFC_HECC_CR2_ENABLE_Pos              _U_(0)                                               /**< (HEFC_HECC_CR2) ECC protection enable Position */
#define HEFC_HECC_CR2_ENABLE_Msk              (_U_(0x1) << HEFC_HECC_CR2_ENABLE_Pos)               /**< (HEFC_HECC_CR2) ECC protection enable Mask */
#define HEFC_HECC_CR2_ENABLE(value)           (HEFC_HECC_CR2_ENABLE_Msk & ((value) << HEFC_HECC_CR2_ENABLE_Pos))
#define HEFC_HECC_CR2_TEST_MODE_RD_Pos        _U_(1)                                               /**< (HEFC_HECC_CR2) test mode of ECC protection - read mode Position */
#define HEFC_HECC_CR2_TEST_MODE_RD_Msk        (_U_(0x1) << HEFC_HECC_CR2_TEST_MODE_RD_Pos)         /**< (HEFC_HECC_CR2) test mode of ECC protection - read mode Mask */
#define HEFC_HECC_CR2_TEST_MODE_RD(value)     (HEFC_HECC_CR2_TEST_MODE_RD_Msk & ((value) << HEFC_HECC_CR2_TEST_MODE_RD_Pos))
#define HEFC_HECC_CR2_TEST_MODE_WR_Pos        _U_(2)                                               /**< (HEFC_HECC_CR2) test mode of ECC protection - write mode Position */
#define HEFC_HECC_CR2_TEST_MODE_WR_Msk        (_U_(0x1) << HEFC_HECC_CR2_TEST_MODE_WR_Pos)         /**< (HEFC_HECC_CR2) test mode of ECC protection - write mode Mask */
#define HEFC_HECC_CR2_TEST_MODE_WR(value)     (HEFC_HECC_CR2_TEST_MODE_WR_Msk & ((value) << HEFC_HECC_CR2_TEST_MODE_WR_Pos))
#define HEFC_HECC_CR2_RST_FIX_CPT_Pos         _U_(4)                                               /**< (HEFC_HECC_CR2) reset the fixable error counter Position */
#define HEFC_HECC_CR2_RST_FIX_CPT_Msk         (_U_(0x1) << HEFC_HECC_CR2_RST_FIX_CPT_Pos)          /**< (HEFC_HECC_CR2) reset the fixable error counter Mask */
#define HEFC_HECC_CR2_RST_FIX_CPT(value)      (HEFC_HECC_CR2_RST_FIX_CPT_Msk & ((value) << HEFC_HECC_CR2_RST_FIX_CPT_Pos))
#define HEFC_HECC_CR2_RST_NOFIX_CPT_Pos       _U_(5)                                               /**< (HEFC_HECC_CR2) reset the un-fixable error counter Position */
#define HEFC_HECC_CR2_RST_NOFIX_CPT_Msk       (_U_(0x1) << HEFC_HECC_CR2_RST_NOFIX_CPT_Pos)        /**< (HEFC_HECC_CR2) reset the un-fixable error counter Mask */
#define HEFC_HECC_CR2_RST_NOFIX_CPT(value)    (HEFC_HECC_CR2_RST_NOFIX_CPT_Msk & ((value) << HEFC_HECC_CR2_RST_NOFIX_CPT_Pos))
#define HEFC_HECC_CR2_ECC12_ENABLE_Pos        _U_(6)                                               /**< (HEFC_HECC_CR2) BCH ECC enable Position */
#define HEFC_HECC_CR2_ECC12_ENABLE_Msk        (_U_(0x1) << HEFC_HECC_CR2_ECC12_ENABLE_Pos)         /**< (HEFC_HECC_CR2) BCH ECC enable Mask */
#define HEFC_HECC_CR2_ECC12_ENABLE(value)     (HEFC_HECC_CR2_ECC12_ENABLE_Msk & ((value) << HEFC_HECC_CR2_ECC12_ENABLE_Pos))
#define HEFC_HECC_CR2_Msk                     _U_(0x00000077)                                      /**< (HEFC_HECC_CR2) Register Mask  */


/* -------- HEFC_HECC_CR3 : (HEFC Offset: 0x10C) (R/W 32) HECC Control Register ChannelNumbers (ChannelNumbers = 0) 3 -------- */
#define HEFC_HECC_CR3_ENABLE_Pos              _U_(0)                                               /**< (HEFC_HECC_CR3) ECC protection enable Position */
#define HEFC_HECC_CR3_ENABLE_Msk              (_U_(0x1) << HEFC_HECC_CR3_ENABLE_Pos)               /**< (HEFC_HECC_CR3) ECC protection enable Mask */
#define HEFC_HECC_CR3_ENABLE(value)           (HEFC_HECC_CR3_ENABLE_Msk & ((value) << HEFC_HECC_CR3_ENABLE_Pos))
#define HEFC_HECC_CR3_TEST_MODE_RD_Pos        _U_(1)                                               /**< (HEFC_HECC_CR3) test mode of ECC protection - read mode Position */
#define HEFC_HECC_CR3_TEST_MODE_RD_Msk        (_U_(0x1) << HEFC_HECC_CR3_TEST_MODE_RD_Pos)         /**< (HEFC_HECC_CR3) test mode of ECC protection - read mode Mask */
#define HEFC_HECC_CR3_TEST_MODE_RD(value)     (HEFC_HECC_CR3_TEST_MODE_RD_Msk & ((value) << HEFC_HECC_CR3_TEST_MODE_RD_Pos))
#define HEFC_HECC_CR3_TEST_MODE_WR_Pos        _U_(2)                                               /**< (HEFC_HECC_CR3) test mode of ECC protection - write mode Position */
#define HEFC_HECC_CR3_TEST_MODE_WR_Msk        (_U_(0x1) << HEFC_HECC_CR3_TEST_MODE_WR_Pos)         /**< (HEFC_HECC_CR3) test mode of ECC protection - write mode Mask */
#define HEFC_HECC_CR3_TEST_MODE_WR(value)     (HEFC_HECC_CR3_TEST_MODE_WR_Msk & ((value) << HEFC_HECC_CR3_TEST_MODE_WR_Pos))
#define HEFC_HECC_CR3_RST_FIX_CPT_Pos         _U_(4)                                               /**< (HEFC_HECC_CR3) reset the fixable error counter Position */
#define HEFC_HECC_CR3_RST_FIX_CPT_Msk         (_U_(0x1) << HEFC_HECC_CR3_RST_FIX_CPT_Pos)          /**< (HEFC_HECC_CR3) reset the fixable error counter Mask */
#define HEFC_HECC_CR3_RST_FIX_CPT(value)      (HEFC_HECC_CR3_RST_FIX_CPT_Msk & ((value) << HEFC_HECC_CR3_RST_FIX_CPT_Pos))
#define HEFC_HECC_CR3_RST_NOFIX_CPT_Pos       _U_(5)                                               /**< (HEFC_HECC_CR3) reset the un-fixable error counter Position */
#define HEFC_HECC_CR3_RST_NOFIX_CPT_Msk       (_U_(0x1) << HEFC_HECC_CR3_RST_NOFIX_CPT_Pos)        /**< (HEFC_HECC_CR3) reset the un-fixable error counter Mask */
#define HEFC_HECC_CR3_RST_NOFIX_CPT(value)    (HEFC_HECC_CR3_RST_NOFIX_CPT_Msk & ((value) << HEFC_HECC_CR3_RST_NOFIX_CPT_Pos))
#define HEFC_HECC_CR3_ECC12_ENABLE_Pos        _U_(6)                                               /**< (HEFC_HECC_CR3) BCH ECC enable Position */
#define HEFC_HECC_CR3_ECC12_ENABLE_Msk        (_U_(0x1) << HEFC_HECC_CR3_ECC12_ENABLE_Pos)         /**< (HEFC_HECC_CR3) BCH ECC enable Mask */
#define HEFC_HECC_CR3_ECC12_ENABLE(value)     (HEFC_HECC_CR3_ECC12_ENABLE_Msk & ((value) << HEFC_HECC_CR3_ECC12_ENABLE_Pos))
#define HEFC_HECC_CR3_Msk                     _U_(0x00000077)                                      /**< (HEFC_HECC_CR3) Register Mask  */


/* -------- HEFC_HECC_CR4 : (HEFC Offset: 0x110) (R/W 32) HECC Control Register ChannelNumbers (ChannelNumbers = 0) 4 -------- */
#define HEFC_HECC_CR4_ENABLE_Pos              _U_(0)                                               /**< (HEFC_HECC_CR4) ECC protection enable Position */
#define HEFC_HECC_CR4_ENABLE_Msk              (_U_(0x1) << HEFC_HECC_CR4_ENABLE_Pos)               /**< (HEFC_HECC_CR4) ECC protection enable Mask */
#define HEFC_HECC_CR4_ENABLE(value)           (HEFC_HECC_CR4_ENABLE_Msk & ((value) << HEFC_HECC_CR4_ENABLE_Pos))
#define HEFC_HECC_CR4_TEST_MODE_RD_Pos        _U_(1)                                               /**< (HEFC_HECC_CR4) test mode of ECC protection - read mode Position */
#define HEFC_HECC_CR4_TEST_MODE_RD_Msk        (_U_(0x1) << HEFC_HECC_CR4_TEST_MODE_RD_Pos)         /**< (HEFC_HECC_CR4) test mode of ECC protection - read mode Mask */
#define HEFC_HECC_CR4_TEST_MODE_RD(value)     (HEFC_HECC_CR4_TEST_MODE_RD_Msk & ((value) << HEFC_HECC_CR4_TEST_MODE_RD_Pos))
#define HEFC_HECC_CR4_TEST_MODE_WR_Pos        _U_(2)                                               /**< (HEFC_HECC_CR4) test mode of ECC protection - write mode Position */
#define HEFC_HECC_CR4_TEST_MODE_WR_Msk        (_U_(0x1) << HEFC_HECC_CR4_TEST_MODE_WR_Pos)         /**< (HEFC_HECC_CR4) test mode of ECC protection - write mode Mask */
#define HEFC_HECC_CR4_TEST_MODE_WR(value)     (HEFC_HECC_CR4_TEST_MODE_WR_Msk & ((value) << HEFC_HECC_CR4_TEST_MODE_WR_Pos))
#define HEFC_HECC_CR4_RST_FIX_CPT_Pos         _U_(4)                                               /**< (HEFC_HECC_CR4) reset the fixable error counter Position */
#define HEFC_HECC_CR4_RST_FIX_CPT_Msk         (_U_(0x1) << HEFC_HECC_CR4_RST_FIX_CPT_Pos)          /**< (HEFC_HECC_CR4) reset the fixable error counter Mask */
#define HEFC_HECC_CR4_RST_FIX_CPT(value)      (HEFC_HECC_CR4_RST_FIX_CPT_Msk & ((value) << HEFC_HECC_CR4_RST_FIX_CPT_Pos))
#define HEFC_HECC_CR4_RST_NOFIX_CPT_Pos       _U_(5)                                               /**< (HEFC_HECC_CR4) reset the un-fixable error counter Position */
#define HEFC_HECC_CR4_RST_NOFIX_CPT_Msk       (_U_(0x1) << HEFC_HECC_CR4_RST_NOFIX_CPT_Pos)        /**< (HEFC_HECC_CR4) reset the un-fixable error counter Mask */
#define HEFC_HECC_CR4_RST_NOFIX_CPT(value)    (HEFC_HECC_CR4_RST_NOFIX_CPT_Msk & ((value) << HEFC_HECC_CR4_RST_NOFIX_CPT_Pos))
#define HEFC_HECC_CR4_ECC12_ENABLE_Pos        _U_(6)                                               /**< (HEFC_HECC_CR4) BCH ECC enable Position */
#define HEFC_HECC_CR4_ECC12_ENABLE_Msk        (_U_(0x1) << HEFC_HECC_CR4_ECC12_ENABLE_Pos)         /**< (HEFC_HECC_CR4) BCH ECC enable Mask */
#define HEFC_HECC_CR4_ECC12_ENABLE(value)     (HEFC_HECC_CR4_ECC12_ENABLE_Msk & ((value) << HEFC_HECC_CR4_ECC12_ENABLE_Pos))
#define HEFC_HECC_CR4_Msk                     _U_(0x00000077)                                      /**< (HEFC_HECC_CR4) Register Mask  */


/* -------- HEFC_HECC_CR5 : (HEFC Offset: 0x114) (R/W 32) HECC Control Register ChannelNumbers (ChannelNumbers = 0) 5 -------- */
#define HEFC_HECC_CR5_ENABLE_Pos              _U_(0)                                               /**< (HEFC_HECC_CR5) ECC protection enable Position */
#define HEFC_HECC_CR5_ENABLE_Msk              (_U_(0x1) << HEFC_HECC_CR5_ENABLE_Pos)               /**< (HEFC_HECC_CR5) ECC protection enable Mask */
#define HEFC_HECC_CR5_ENABLE(value)           (HEFC_HECC_CR5_ENABLE_Msk & ((value) << HEFC_HECC_CR5_ENABLE_Pos))
#define HEFC_HECC_CR5_TEST_MODE_RD_Pos        _U_(1)                                               /**< (HEFC_HECC_CR5) test mode of ECC protection - read mode Position */
#define HEFC_HECC_CR5_TEST_MODE_RD_Msk        (_U_(0x1) << HEFC_HECC_CR5_TEST_MODE_RD_Pos)         /**< (HEFC_HECC_CR5) test mode of ECC protection - read mode Mask */
#define HEFC_HECC_CR5_TEST_MODE_RD(value)     (HEFC_HECC_CR5_TEST_MODE_RD_Msk & ((value) << HEFC_HECC_CR5_TEST_MODE_RD_Pos))
#define HEFC_HECC_CR5_TEST_MODE_WR_Pos        _U_(2)                                               /**< (HEFC_HECC_CR5) test mode of ECC protection - write mode Position */
#define HEFC_HECC_CR5_TEST_MODE_WR_Msk        (_U_(0x1) << HEFC_HECC_CR5_TEST_MODE_WR_Pos)         /**< (HEFC_HECC_CR5) test mode of ECC protection - write mode Mask */
#define HEFC_HECC_CR5_TEST_MODE_WR(value)     (HEFC_HECC_CR5_TEST_MODE_WR_Msk & ((value) << HEFC_HECC_CR5_TEST_MODE_WR_Pos))
#define HEFC_HECC_CR5_RST_FIX_CPT_Pos         _U_(4)                                               /**< (HEFC_HECC_CR5) reset the fixable error counter Position */
#define HEFC_HECC_CR5_RST_FIX_CPT_Msk         (_U_(0x1) << HEFC_HECC_CR5_RST_FIX_CPT_Pos)          /**< (HEFC_HECC_CR5) reset the fixable error counter Mask */
#define HEFC_HECC_CR5_RST_FIX_CPT(value)      (HEFC_HECC_CR5_RST_FIX_CPT_Msk & ((value) << HEFC_HECC_CR5_RST_FIX_CPT_Pos))
#define HEFC_HECC_CR5_RST_NOFIX_CPT_Pos       _U_(5)                                               /**< (HEFC_HECC_CR5) reset the un-fixable error counter Position */
#define HEFC_HECC_CR5_RST_NOFIX_CPT_Msk       (_U_(0x1) << HEFC_HECC_CR5_RST_NOFIX_CPT_Pos)        /**< (HEFC_HECC_CR5) reset the un-fixable error counter Mask */
#define HEFC_HECC_CR5_RST_NOFIX_CPT(value)    (HEFC_HECC_CR5_RST_NOFIX_CPT_Msk & ((value) << HEFC_HECC_CR5_RST_NOFIX_CPT_Pos))
#define HEFC_HECC_CR5_ECC12_ENABLE_Pos        _U_(6)                                               /**< (HEFC_HECC_CR5) BCH ECC enable Position */
#define HEFC_HECC_CR5_ECC12_ENABLE_Msk        (_U_(0x1) << HEFC_HECC_CR5_ECC12_ENABLE_Pos)         /**< (HEFC_HECC_CR5) BCH ECC enable Mask */
#define HEFC_HECC_CR5_ECC12_ENABLE(value)     (HEFC_HECC_CR5_ECC12_ENABLE_Msk & ((value) << HEFC_HECC_CR5_ECC12_ENABLE_Pos))
#define HEFC_HECC_CR5_Msk                     _U_(0x00000077)                                      /**< (HEFC_HECC_CR5) Register Mask  */


/* -------- HEFC_HECC_CR6 : (HEFC Offset: 0x118) (R/W 32) HECC Control Register ChannelNumbers (ChannelNumbers = 0) 6 -------- */
#define HEFC_HECC_CR6_ENABLE_Pos              _U_(0)                                               /**< (HEFC_HECC_CR6) ECC protection enable Position */
#define HEFC_HECC_CR6_ENABLE_Msk              (_U_(0x1) << HEFC_HECC_CR6_ENABLE_Pos)               /**< (HEFC_HECC_CR6) ECC protection enable Mask */
#define HEFC_HECC_CR6_ENABLE(value)           (HEFC_HECC_CR6_ENABLE_Msk & ((value) << HEFC_HECC_CR6_ENABLE_Pos))
#define HEFC_HECC_CR6_TEST_MODE_RD_Pos        _U_(1)                                               /**< (HEFC_HECC_CR6) test mode of ECC protection - read mode Position */
#define HEFC_HECC_CR6_TEST_MODE_RD_Msk        (_U_(0x1) << HEFC_HECC_CR6_TEST_MODE_RD_Pos)         /**< (HEFC_HECC_CR6) test mode of ECC protection - read mode Mask */
#define HEFC_HECC_CR6_TEST_MODE_RD(value)     (HEFC_HECC_CR6_TEST_MODE_RD_Msk & ((value) << HEFC_HECC_CR6_TEST_MODE_RD_Pos))
#define HEFC_HECC_CR6_TEST_MODE_WR_Pos        _U_(2)                                               /**< (HEFC_HECC_CR6) test mode of ECC protection - write mode Position */
#define HEFC_HECC_CR6_TEST_MODE_WR_Msk        (_U_(0x1) << HEFC_HECC_CR6_TEST_MODE_WR_Pos)         /**< (HEFC_HECC_CR6) test mode of ECC protection - write mode Mask */
#define HEFC_HECC_CR6_TEST_MODE_WR(value)     (HEFC_HECC_CR6_TEST_MODE_WR_Msk & ((value) << HEFC_HECC_CR6_TEST_MODE_WR_Pos))
#define HEFC_HECC_CR6_RST_FIX_CPT_Pos         _U_(4)                                               /**< (HEFC_HECC_CR6) reset the fixable error counter Position */
#define HEFC_HECC_CR6_RST_FIX_CPT_Msk         (_U_(0x1) << HEFC_HECC_CR6_RST_FIX_CPT_Pos)          /**< (HEFC_HECC_CR6) reset the fixable error counter Mask */
#define HEFC_HECC_CR6_RST_FIX_CPT(value)      (HEFC_HECC_CR6_RST_FIX_CPT_Msk & ((value) << HEFC_HECC_CR6_RST_FIX_CPT_Pos))
#define HEFC_HECC_CR6_RST_NOFIX_CPT_Pos       _U_(5)                                               /**< (HEFC_HECC_CR6) reset the un-fixable error counter Position */
#define HEFC_HECC_CR6_RST_NOFIX_CPT_Msk       (_U_(0x1) << HEFC_HECC_CR6_RST_NOFIX_CPT_Pos)        /**< (HEFC_HECC_CR6) reset the un-fixable error counter Mask */
#define HEFC_HECC_CR6_RST_NOFIX_CPT(value)    (HEFC_HECC_CR6_RST_NOFIX_CPT_Msk & ((value) << HEFC_HECC_CR6_RST_NOFIX_CPT_Pos))
#define HEFC_HECC_CR6_ECC12_ENABLE_Pos        _U_(6)                                               /**< (HEFC_HECC_CR6) BCH ECC enable Position */
#define HEFC_HECC_CR6_ECC12_ENABLE_Msk        (_U_(0x1) << HEFC_HECC_CR6_ECC12_ENABLE_Pos)         /**< (HEFC_HECC_CR6) BCH ECC enable Mask */
#define HEFC_HECC_CR6_ECC12_ENABLE(value)     (HEFC_HECC_CR6_ECC12_ENABLE_Msk & ((value) << HEFC_HECC_CR6_ECC12_ENABLE_Pos))
#define HEFC_HECC_CR6_Msk                     _U_(0x00000077)                                      /**< (HEFC_HECC_CR6) Register Mask  */


/* -------- HEFC_HECC_CR7 : (HEFC Offset: 0x11C) (R/W 32) HECC Control Register ChannelNumbers (ChannelNumbers = 0) 7 -------- */
#define HEFC_HECC_CR7_ENABLE_Pos              _U_(0)                                               /**< (HEFC_HECC_CR7) ECC protection enable Position */
#define HEFC_HECC_CR7_ENABLE_Msk              (_U_(0x1) << HEFC_HECC_CR7_ENABLE_Pos)               /**< (HEFC_HECC_CR7) ECC protection enable Mask */
#define HEFC_HECC_CR7_ENABLE(value)           (HEFC_HECC_CR7_ENABLE_Msk & ((value) << HEFC_HECC_CR7_ENABLE_Pos))
#define HEFC_HECC_CR7_TEST_MODE_RD_Pos        _U_(1)                                               /**< (HEFC_HECC_CR7) test mode of ECC protection - read mode Position */
#define HEFC_HECC_CR7_TEST_MODE_RD_Msk        (_U_(0x1) << HEFC_HECC_CR7_TEST_MODE_RD_Pos)         /**< (HEFC_HECC_CR7) test mode of ECC protection - read mode Mask */
#define HEFC_HECC_CR7_TEST_MODE_RD(value)     (HEFC_HECC_CR7_TEST_MODE_RD_Msk & ((value) << HEFC_HECC_CR7_TEST_MODE_RD_Pos))
#define HEFC_HECC_CR7_TEST_MODE_WR_Pos        _U_(2)                                               /**< (HEFC_HECC_CR7) test mode of ECC protection - write mode Position */
#define HEFC_HECC_CR7_TEST_MODE_WR_Msk        (_U_(0x1) << HEFC_HECC_CR7_TEST_MODE_WR_Pos)         /**< (HEFC_HECC_CR7) test mode of ECC protection - write mode Mask */
#define HEFC_HECC_CR7_TEST_MODE_WR(value)     (HEFC_HECC_CR7_TEST_MODE_WR_Msk & ((value) << HEFC_HECC_CR7_TEST_MODE_WR_Pos))
#define HEFC_HECC_CR7_RST_FIX_CPT_Pos         _U_(4)                                               /**< (HEFC_HECC_CR7) reset the fixable error counter Position */
#define HEFC_HECC_CR7_RST_FIX_CPT_Msk         (_U_(0x1) << HEFC_HECC_CR7_RST_FIX_CPT_Pos)          /**< (HEFC_HECC_CR7) reset the fixable error counter Mask */
#define HEFC_HECC_CR7_RST_FIX_CPT(value)      (HEFC_HECC_CR7_RST_FIX_CPT_Msk & ((value) << HEFC_HECC_CR7_RST_FIX_CPT_Pos))
#define HEFC_HECC_CR7_RST_NOFIX_CPT_Pos       _U_(5)                                               /**< (HEFC_HECC_CR7) reset the un-fixable error counter Position */
#define HEFC_HECC_CR7_RST_NOFIX_CPT_Msk       (_U_(0x1) << HEFC_HECC_CR7_RST_NOFIX_CPT_Pos)        /**< (HEFC_HECC_CR7) reset the un-fixable error counter Mask */
#define HEFC_HECC_CR7_RST_NOFIX_CPT(value)    (HEFC_HECC_CR7_RST_NOFIX_CPT_Msk & ((value) << HEFC_HECC_CR7_RST_NOFIX_CPT_Pos))
#define HEFC_HECC_CR7_ECC12_ENABLE_Pos        _U_(6)                                               /**< (HEFC_HECC_CR7) BCH ECC enable Position */
#define HEFC_HECC_CR7_ECC12_ENABLE_Msk        (_U_(0x1) << HEFC_HECC_CR7_ECC12_ENABLE_Pos)         /**< (HEFC_HECC_CR7) BCH ECC enable Mask */
#define HEFC_HECC_CR7_ECC12_ENABLE(value)     (HEFC_HECC_CR7_ECC12_ENABLE_Msk & ((value) << HEFC_HECC_CR7_ECC12_ENABLE_Pos))
#define HEFC_HECC_CR7_Msk                     _U_(0x00000077)                                      /**< (HEFC_HECC_CR7) Register Mask  */


/* -------- HEFC_HECC_CR8 : (HEFC Offset: 0x120) (R/W 32) HECC Control Register ChannelNumbers (ChannelNumbers = 0) 8 -------- */
#define HEFC_HECC_CR8_ENABLE_Pos              _U_(0)                                               /**< (HEFC_HECC_CR8) ECC protection enable Position */
#define HEFC_HECC_CR8_ENABLE_Msk              (_U_(0x1) << HEFC_HECC_CR8_ENABLE_Pos)               /**< (HEFC_HECC_CR8) ECC protection enable Mask */
#define HEFC_HECC_CR8_ENABLE(value)           (HEFC_HECC_CR8_ENABLE_Msk & ((value) << HEFC_HECC_CR8_ENABLE_Pos))
#define HEFC_HECC_CR8_TEST_MODE_RD_Pos        _U_(1)                                               /**< (HEFC_HECC_CR8) test mode of ECC protection - read mode Position */
#define HEFC_HECC_CR8_TEST_MODE_RD_Msk        (_U_(0x1) << HEFC_HECC_CR8_TEST_MODE_RD_Pos)         /**< (HEFC_HECC_CR8) test mode of ECC protection - read mode Mask */
#define HEFC_HECC_CR8_TEST_MODE_RD(value)     (HEFC_HECC_CR8_TEST_MODE_RD_Msk & ((value) << HEFC_HECC_CR8_TEST_MODE_RD_Pos))
#define HEFC_HECC_CR8_TEST_MODE_WR_Pos        _U_(2)                                               /**< (HEFC_HECC_CR8) test mode of ECC protection - write mode Position */
#define HEFC_HECC_CR8_TEST_MODE_WR_Msk        (_U_(0x1) << HEFC_HECC_CR8_TEST_MODE_WR_Pos)         /**< (HEFC_HECC_CR8) test mode of ECC protection - write mode Mask */
#define HEFC_HECC_CR8_TEST_MODE_WR(value)     (HEFC_HECC_CR8_TEST_MODE_WR_Msk & ((value) << HEFC_HECC_CR8_TEST_MODE_WR_Pos))
#define HEFC_HECC_CR8_RST_FIX_CPT_Pos         _U_(4)                                               /**< (HEFC_HECC_CR8) reset the fixable error counter Position */
#define HEFC_HECC_CR8_RST_FIX_CPT_Msk         (_U_(0x1) << HEFC_HECC_CR8_RST_FIX_CPT_Pos)          /**< (HEFC_HECC_CR8) reset the fixable error counter Mask */
#define HEFC_HECC_CR8_RST_FIX_CPT(value)      (HEFC_HECC_CR8_RST_FIX_CPT_Msk & ((value) << HEFC_HECC_CR8_RST_FIX_CPT_Pos))
#define HEFC_HECC_CR8_RST_NOFIX_CPT_Pos       _U_(5)                                               /**< (HEFC_HECC_CR8) reset the un-fixable error counter Position */
#define HEFC_HECC_CR8_RST_NOFIX_CPT_Msk       (_U_(0x1) << HEFC_HECC_CR8_RST_NOFIX_CPT_Pos)        /**< (HEFC_HECC_CR8) reset the un-fixable error counter Mask */
#define HEFC_HECC_CR8_RST_NOFIX_CPT(value)    (HEFC_HECC_CR8_RST_NOFIX_CPT_Msk & ((value) << HEFC_HECC_CR8_RST_NOFIX_CPT_Pos))
#define HEFC_HECC_CR8_ECC12_ENABLE_Pos        _U_(6)                                               /**< (HEFC_HECC_CR8) BCH ECC enable Position */
#define HEFC_HECC_CR8_ECC12_ENABLE_Msk        (_U_(0x1) << HEFC_HECC_CR8_ECC12_ENABLE_Pos)         /**< (HEFC_HECC_CR8) BCH ECC enable Mask */
#define HEFC_HECC_CR8_ECC12_ENABLE(value)     (HEFC_HECC_CR8_ECC12_ENABLE_Msk & ((value) << HEFC_HECC_CR8_ECC12_ENABLE_Pos))
#define HEFC_HECC_CR8_Msk                     _U_(0x00000077)                                      /**< (HEFC_HECC_CR8) Register Mask  */


/* -------- HEFC_HECC_CR9 : (HEFC Offset: 0x124) (R/W 32) HECC Control Register ChannelNumbers (ChannelNumbers = 0) 9 -------- */
#define HEFC_HECC_CR9_ENABLE_Pos              _U_(0)                                               /**< (HEFC_HECC_CR9) ECC protection enable Position */
#define HEFC_HECC_CR9_ENABLE_Msk              (_U_(0x1) << HEFC_HECC_CR9_ENABLE_Pos)               /**< (HEFC_HECC_CR9) ECC protection enable Mask */
#define HEFC_HECC_CR9_ENABLE(value)           (HEFC_HECC_CR9_ENABLE_Msk & ((value) << HEFC_HECC_CR9_ENABLE_Pos))
#define HEFC_HECC_CR9_TEST_MODE_RD_Pos        _U_(1)                                               /**< (HEFC_HECC_CR9) test mode of ECC protection - read mode Position */
#define HEFC_HECC_CR9_TEST_MODE_RD_Msk        (_U_(0x1) << HEFC_HECC_CR9_TEST_MODE_RD_Pos)         /**< (HEFC_HECC_CR9) test mode of ECC protection - read mode Mask */
#define HEFC_HECC_CR9_TEST_MODE_RD(value)     (HEFC_HECC_CR9_TEST_MODE_RD_Msk & ((value) << HEFC_HECC_CR9_TEST_MODE_RD_Pos))
#define HEFC_HECC_CR9_TEST_MODE_WR_Pos        _U_(2)                                               /**< (HEFC_HECC_CR9) test mode of ECC protection - write mode Position */
#define HEFC_HECC_CR9_TEST_MODE_WR_Msk        (_U_(0x1) << HEFC_HECC_CR9_TEST_MODE_WR_Pos)         /**< (HEFC_HECC_CR9) test mode of ECC protection - write mode Mask */
#define HEFC_HECC_CR9_TEST_MODE_WR(value)     (HEFC_HECC_CR9_TEST_MODE_WR_Msk & ((value) << HEFC_HECC_CR9_TEST_MODE_WR_Pos))
#define HEFC_HECC_CR9_RST_FIX_CPT_Pos         _U_(4)                                               /**< (HEFC_HECC_CR9) reset the fixable error counter Position */
#define HEFC_HECC_CR9_RST_FIX_CPT_Msk         (_U_(0x1) << HEFC_HECC_CR9_RST_FIX_CPT_Pos)          /**< (HEFC_HECC_CR9) reset the fixable error counter Mask */
#define HEFC_HECC_CR9_RST_FIX_CPT(value)      (HEFC_HECC_CR9_RST_FIX_CPT_Msk & ((value) << HEFC_HECC_CR9_RST_FIX_CPT_Pos))
#define HEFC_HECC_CR9_RST_NOFIX_CPT_Pos       _U_(5)                                               /**< (HEFC_HECC_CR9) reset the un-fixable error counter Position */
#define HEFC_HECC_CR9_RST_NOFIX_CPT_Msk       (_U_(0x1) << HEFC_HECC_CR9_RST_NOFIX_CPT_Pos)        /**< (HEFC_HECC_CR9) reset the un-fixable error counter Mask */
#define HEFC_HECC_CR9_RST_NOFIX_CPT(value)    (HEFC_HECC_CR9_RST_NOFIX_CPT_Msk & ((value) << HEFC_HECC_CR9_RST_NOFIX_CPT_Pos))
#define HEFC_HECC_CR9_ECC12_ENABLE_Pos        _U_(6)                                               /**< (HEFC_HECC_CR9) BCH ECC enable Position */
#define HEFC_HECC_CR9_ECC12_ENABLE_Msk        (_U_(0x1) << HEFC_HECC_CR9_ECC12_ENABLE_Pos)         /**< (HEFC_HECC_CR9) BCH ECC enable Mask */
#define HEFC_HECC_CR9_ECC12_ENABLE(value)     (HEFC_HECC_CR9_ECC12_ENABLE_Msk & ((value) << HEFC_HECC_CR9_ECC12_ENABLE_Pos))
#define HEFC_HECC_CR9_Msk                     _U_(0x00000077)                                      /**< (HEFC_HECC_CR9) Register Mask  */


/* -------- HEFC_HECC_CR10 : (HEFC Offset: 0x128) (R/W 32) HECC Control Register ChannelNumbers (ChannelNumbers = 0) 10 -------- */
#define HEFC_HECC_CR10_ENABLE_Pos             _U_(0)                                               /**< (HEFC_HECC_CR10) ECC protection enable Position */
#define HEFC_HECC_CR10_ENABLE_Msk             (_U_(0x1) << HEFC_HECC_CR10_ENABLE_Pos)              /**< (HEFC_HECC_CR10) ECC protection enable Mask */
#define HEFC_HECC_CR10_ENABLE(value)          (HEFC_HECC_CR10_ENABLE_Msk & ((value) << HEFC_HECC_CR10_ENABLE_Pos))
#define HEFC_HECC_CR10_TEST_MODE_RD_Pos       _U_(1)                                               /**< (HEFC_HECC_CR10) test mode of ECC protection - read mode Position */
#define HEFC_HECC_CR10_TEST_MODE_RD_Msk       (_U_(0x1) << HEFC_HECC_CR10_TEST_MODE_RD_Pos)        /**< (HEFC_HECC_CR10) test mode of ECC protection - read mode Mask */
#define HEFC_HECC_CR10_TEST_MODE_RD(value)    (HEFC_HECC_CR10_TEST_MODE_RD_Msk & ((value) << HEFC_HECC_CR10_TEST_MODE_RD_Pos))
#define HEFC_HECC_CR10_TEST_MODE_WR_Pos       _U_(2)                                               /**< (HEFC_HECC_CR10) test mode of ECC protection - write mode Position */
#define HEFC_HECC_CR10_TEST_MODE_WR_Msk       (_U_(0x1) << HEFC_HECC_CR10_TEST_MODE_WR_Pos)        /**< (HEFC_HECC_CR10) test mode of ECC protection - write mode Mask */
#define HEFC_HECC_CR10_TEST_MODE_WR(value)    (HEFC_HECC_CR10_TEST_MODE_WR_Msk & ((value) << HEFC_HECC_CR10_TEST_MODE_WR_Pos))
#define HEFC_HECC_CR10_RST_FIX_CPT_Pos        _U_(4)                                               /**< (HEFC_HECC_CR10) reset the fixable error counter Position */
#define HEFC_HECC_CR10_RST_FIX_CPT_Msk        (_U_(0x1) << HEFC_HECC_CR10_RST_FIX_CPT_Pos)         /**< (HEFC_HECC_CR10) reset the fixable error counter Mask */
#define HEFC_HECC_CR10_RST_FIX_CPT(value)     (HEFC_HECC_CR10_RST_FIX_CPT_Msk & ((value) << HEFC_HECC_CR10_RST_FIX_CPT_Pos))
#define HEFC_HECC_CR10_RST_NOFIX_CPT_Pos      _U_(5)                                               /**< (HEFC_HECC_CR10) reset the un-fixable error counter Position */
#define HEFC_HECC_CR10_RST_NOFIX_CPT_Msk      (_U_(0x1) << HEFC_HECC_CR10_RST_NOFIX_CPT_Pos)       /**< (HEFC_HECC_CR10) reset the un-fixable error counter Mask */
#define HEFC_HECC_CR10_RST_NOFIX_CPT(value)   (HEFC_HECC_CR10_RST_NOFIX_CPT_Msk & ((value) << HEFC_HECC_CR10_RST_NOFIX_CPT_Pos))
#define HEFC_HECC_CR10_ECC12_ENABLE_Pos       _U_(6)                                               /**< (HEFC_HECC_CR10) BCH ECC enable Position */
#define HEFC_HECC_CR10_ECC12_ENABLE_Msk       (_U_(0x1) << HEFC_HECC_CR10_ECC12_ENABLE_Pos)        /**< (HEFC_HECC_CR10) BCH ECC enable Mask */
#define HEFC_HECC_CR10_ECC12_ENABLE(value)    (HEFC_HECC_CR10_ECC12_ENABLE_Msk & ((value) << HEFC_HECC_CR10_ECC12_ENABLE_Pos))
#define HEFC_HECC_CR10_Msk                    _U_(0x00000077)                                      /**< (HEFC_HECC_CR10) Register Mask  */


/* -------- HEFC_HECC_CR11 : (HEFC Offset: 0x12C) (R/W 32) HECC Control Register ChannelNumbers (ChannelNumbers = 0) 11 -------- */
#define HEFC_HECC_CR11_ENABLE_Pos             _U_(0)                                               /**< (HEFC_HECC_CR11) ECC protection enable Position */
#define HEFC_HECC_CR11_ENABLE_Msk             (_U_(0x1) << HEFC_HECC_CR11_ENABLE_Pos)              /**< (HEFC_HECC_CR11) ECC protection enable Mask */
#define HEFC_HECC_CR11_ENABLE(value)          (HEFC_HECC_CR11_ENABLE_Msk & ((value) << HEFC_HECC_CR11_ENABLE_Pos))
#define HEFC_HECC_CR11_TEST_MODE_RD_Pos       _U_(1)                                               /**< (HEFC_HECC_CR11) test mode of ECC protection - read mode Position */
#define HEFC_HECC_CR11_TEST_MODE_RD_Msk       (_U_(0x1) << HEFC_HECC_CR11_TEST_MODE_RD_Pos)        /**< (HEFC_HECC_CR11) test mode of ECC protection - read mode Mask */
#define HEFC_HECC_CR11_TEST_MODE_RD(value)    (HEFC_HECC_CR11_TEST_MODE_RD_Msk & ((value) << HEFC_HECC_CR11_TEST_MODE_RD_Pos))
#define HEFC_HECC_CR11_TEST_MODE_WR_Pos       _U_(2)                                               /**< (HEFC_HECC_CR11) test mode of ECC protection - write mode Position */
#define HEFC_HECC_CR11_TEST_MODE_WR_Msk       (_U_(0x1) << HEFC_HECC_CR11_TEST_MODE_WR_Pos)        /**< (HEFC_HECC_CR11) test mode of ECC protection - write mode Mask */
#define HEFC_HECC_CR11_TEST_MODE_WR(value)    (HEFC_HECC_CR11_TEST_MODE_WR_Msk & ((value) << HEFC_HECC_CR11_TEST_MODE_WR_Pos))
#define HEFC_HECC_CR11_RST_FIX_CPT_Pos        _U_(4)                                               /**< (HEFC_HECC_CR11) reset the fixable error counter Position */
#define HEFC_HECC_CR11_RST_FIX_CPT_Msk        (_U_(0x1) << HEFC_HECC_CR11_RST_FIX_CPT_Pos)         /**< (HEFC_HECC_CR11) reset the fixable error counter Mask */
#define HEFC_HECC_CR11_RST_FIX_CPT(value)     (HEFC_HECC_CR11_RST_FIX_CPT_Msk & ((value) << HEFC_HECC_CR11_RST_FIX_CPT_Pos))
#define HEFC_HECC_CR11_RST_NOFIX_CPT_Pos      _U_(5)                                               /**< (HEFC_HECC_CR11) reset the un-fixable error counter Position */
#define HEFC_HECC_CR11_RST_NOFIX_CPT_Msk      (_U_(0x1) << HEFC_HECC_CR11_RST_NOFIX_CPT_Pos)       /**< (HEFC_HECC_CR11) reset the un-fixable error counter Mask */
#define HEFC_HECC_CR11_RST_NOFIX_CPT(value)   (HEFC_HECC_CR11_RST_NOFIX_CPT_Msk & ((value) << HEFC_HECC_CR11_RST_NOFIX_CPT_Pos))
#define HEFC_HECC_CR11_ECC12_ENABLE_Pos       _U_(6)                                               /**< (HEFC_HECC_CR11) BCH ECC enable Position */
#define HEFC_HECC_CR11_ECC12_ENABLE_Msk       (_U_(0x1) << HEFC_HECC_CR11_ECC12_ENABLE_Pos)        /**< (HEFC_HECC_CR11) BCH ECC enable Mask */
#define HEFC_HECC_CR11_ECC12_ENABLE(value)    (HEFC_HECC_CR11_ECC12_ENABLE_Msk & ((value) << HEFC_HECC_CR11_ECC12_ENABLE_Pos))
#define HEFC_HECC_CR11_Msk                    _U_(0x00000077)                                      /**< (HEFC_HECC_CR11) Register Mask  */


/* -------- HEFC_HECC_CR12 : (HEFC Offset: 0x130) (R/W 32) HECC Control Register ChannelNumbers (ChannelNumbers = 0) 12 -------- */
#define HEFC_HECC_CR12_ENABLE_Pos             _U_(0)                                               /**< (HEFC_HECC_CR12) ECC protection enable Position */
#define HEFC_HECC_CR12_ENABLE_Msk             (_U_(0x1) << HEFC_HECC_CR12_ENABLE_Pos)              /**< (HEFC_HECC_CR12) ECC protection enable Mask */
#define HEFC_HECC_CR12_ENABLE(value)          (HEFC_HECC_CR12_ENABLE_Msk & ((value) << HEFC_HECC_CR12_ENABLE_Pos))
#define HEFC_HECC_CR12_TEST_MODE_RD_Pos       _U_(1)                                               /**< (HEFC_HECC_CR12) test mode of ECC protection - read mode Position */
#define HEFC_HECC_CR12_TEST_MODE_RD_Msk       (_U_(0x1) << HEFC_HECC_CR12_TEST_MODE_RD_Pos)        /**< (HEFC_HECC_CR12) test mode of ECC protection - read mode Mask */
#define HEFC_HECC_CR12_TEST_MODE_RD(value)    (HEFC_HECC_CR12_TEST_MODE_RD_Msk & ((value) << HEFC_HECC_CR12_TEST_MODE_RD_Pos))
#define HEFC_HECC_CR12_TEST_MODE_WR_Pos       _U_(2)                                               /**< (HEFC_HECC_CR12) test mode of ECC protection - write mode Position */
#define HEFC_HECC_CR12_TEST_MODE_WR_Msk       (_U_(0x1) << HEFC_HECC_CR12_TEST_MODE_WR_Pos)        /**< (HEFC_HECC_CR12) test mode of ECC protection - write mode Mask */
#define HEFC_HECC_CR12_TEST_MODE_WR(value)    (HEFC_HECC_CR12_TEST_MODE_WR_Msk & ((value) << HEFC_HECC_CR12_TEST_MODE_WR_Pos))
#define HEFC_HECC_CR12_RST_FIX_CPT_Pos        _U_(4)                                               /**< (HEFC_HECC_CR12) reset the fixable error counter Position */
#define HEFC_HECC_CR12_RST_FIX_CPT_Msk        (_U_(0x1) << HEFC_HECC_CR12_RST_FIX_CPT_Pos)         /**< (HEFC_HECC_CR12) reset the fixable error counter Mask */
#define HEFC_HECC_CR12_RST_FIX_CPT(value)     (HEFC_HECC_CR12_RST_FIX_CPT_Msk & ((value) << HEFC_HECC_CR12_RST_FIX_CPT_Pos))
#define HEFC_HECC_CR12_RST_NOFIX_CPT_Pos      _U_(5)                                               /**< (HEFC_HECC_CR12) reset the un-fixable error counter Position */
#define HEFC_HECC_CR12_RST_NOFIX_CPT_Msk      (_U_(0x1) << HEFC_HECC_CR12_RST_NOFIX_CPT_Pos)       /**< (HEFC_HECC_CR12) reset the un-fixable error counter Mask */
#define HEFC_HECC_CR12_RST_NOFIX_CPT(value)   (HEFC_HECC_CR12_RST_NOFIX_CPT_Msk & ((value) << HEFC_HECC_CR12_RST_NOFIX_CPT_Pos))
#define HEFC_HECC_CR12_ECC12_ENABLE_Pos       _U_(6)                                               /**< (HEFC_HECC_CR12) BCH ECC enable Position */
#define HEFC_HECC_CR12_ECC12_ENABLE_Msk       (_U_(0x1) << HEFC_HECC_CR12_ECC12_ENABLE_Pos)        /**< (HEFC_HECC_CR12) BCH ECC enable Mask */
#define HEFC_HECC_CR12_ECC12_ENABLE(value)    (HEFC_HECC_CR12_ECC12_ENABLE_Msk & ((value) << HEFC_HECC_CR12_ECC12_ENABLE_Pos))
#define HEFC_HECC_CR12_Msk                    _U_(0x00000077)                                      /**< (HEFC_HECC_CR12) Register Mask  */


/* -------- HEFC_HECC_CR13 : (HEFC Offset: 0x134) (R/W 32) HECC Control Register ChannelNumbers (ChannelNumbers = 0) 13 -------- */
#define HEFC_HECC_CR13_ENABLE_Pos             _U_(0)                                               /**< (HEFC_HECC_CR13) ECC protection enable Position */
#define HEFC_HECC_CR13_ENABLE_Msk             (_U_(0x1) << HEFC_HECC_CR13_ENABLE_Pos)              /**< (HEFC_HECC_CR13) ECC protection enable Mask */
#define HEFC_HECC_CR13_ENABLE(value)          (HEFC_HECC_CR13_ENABLE_Msk & ((value) << HEFC_HECC_CR13_ENABLE_Pos))
#define HEFC_HECC_CR13_TEST_MODE_RD_Pos       _U_(1)                                               /**< (HEFC_HECC_CR13) test mode of ECC protection - read mode Position */
#define HEFC_HECC_CR13_TEST_MODE_RD_Msk       (_U_(0x1) << HEFC_HECC_CR13_TEST_MODE_RD_Pos)        /**< (HEFC_HECC_CR13) test mode of ECC protection - read mode Mask */
#define HEFC_HECC_CR13_TEST_MODE_RD(value)    (HEFC_HECC_CR13_TEST_MODE_RD_Msk & ((value) << HEFC_HECC_CR13_TEST_MODE_RD_Pos))
#define HEFC_HECC_CR13_TEST_MODE_WR_Pos       _U_(2)                                               /**< (HEFC_HECC_CR13) test mode of ECC protection - write mode Position */
#define HEFC_HECC_CR13_TEST_MODE_WR_Msk       (_U_(0x1) << HEFC_HECC_CR13_TEST_MODE_WR_Pos)        /**< (HEFC_HECC_CR13) test mode of ECC protection - write mode Mask */
#define HEFC_HECC_CR13_TEST_MODE_WR(value)    (HEFC_HECC_CR13_TEST_MODE_WR_Msk & ((value) << HEFC_HECC_CR13_TEST_MODE_WR_Pos))
#define HEFC_HECC_CR13_RST_FIX_CPT_Pos        _U_(4)                                               /**< (HEFC_HECC_CR13) reset the fixable error counter Position */
#define HEFC_HECC_CR13_RST_FIX_CPT_Msk        (_U_(0x1) << HEFC_HECC_CR13_RST_FIX_CPT_Pos)         /**< (HEFC_HECC_CR13) reset the fixable error counter Mask */
#define HEFC_HECC_CR13_RST_FIX_CPT(value)     (HEFC_HECC_CR13_RST_FIX_CPT_Msk & ((value) << HEFC_HECC_CR13_RST_FIX_CPT_Pos))
#define HEFC_HECC_CR13_RST_NOFIX_CPT_Pos      _U_(5)                                               /**< (HEFC_HECC_CR13) reset the un-fixable error counter Position */
#define HEFC_HECC_CR13_RST_NOFIX_CPT_Msk      (_U_(0x1) << HEFC_HECC_CR13_RST_NOFIX_CPT_Pos)       /**< (HEFC_HECC_CR13) reset the un-fixable error counter Mask */
#define HEFC_HECC_CR13_RST_NOFIX_CPT(value)   (HEFC_HECC_CR13_RST_NOFIX_CPT_Msk & ((value) << HEFC_HECC_CR13_RST_NOFIX_CPT_Pos))
#define HEFC_HECC_CR13_ECC12_ENABLE_Pos       _U_(6)                                               /**< (HEFC_HECC_CR13) BCH ECC enable Position */
#define HEFC_HECC_CR13_ECC12_ENABLE_Msk       (_U_(0x1) << HEFC_HECC_CR13_ECC12_ENABLE_Pos)        /**< (HEFC_HECC_CR13) BCH ECC enable Mask */
#define HEFC_HECC_CR13_ECC12_ENABLE(value)    (HEFC_HECC_CR13_ECC12_ENABLE_Msk & ((value) << HEFC_HECC_CR13_ECC12_ENABLE_Pos))
#define HEFC_HECC_CR13_Msk                    _U_(0x00000077)                                      /**< (HEFC_HECC_CR13) Register Mask  */


/* -------- HEFC_HECC_CR14 : (HEFC Offset: 0x138) (R/W 32) HECC Control Register ChannelNumbers (ChannelNumbers = 0) 14 -------- */
#define HEFC_HECC_CR14_ENABLE_Pos             _U_(0)                                               /**< (HEFC_HECC_CR14) ECC protection enable Position */
#define HEFC_HECC_CR14_ENABLE_Msk             (_U_(0x1) << HEFC_HECC_CR14_ENABLE_Pos)              /**< (HEFC_HECC_CR14) ECC protection enable Mask */
#define HEFC_HECC_CR14_ENABLE(value)          (HEFC_HECC_CR14_ENABLE_Msk & ((value) << HEFC_HECC_CR14_ENABLE_Pos))
#define HEFC_HECC_CR14_TEST_MODE_RD_Pos       _U_(1)                                               /**< (HEFC_HECC_CR14) test mode of ECC protection - read mode Position */
#define HEFC_HECC_CR14_TEST_MODE_RD_Msk       (_U_(0x1) << HEFC_HECC_CR14_TEST_MODE_RD_Pos)        /**< (HEFC_HECC_CR14) test mode of ECC protection - read mode Mask */
#define HEFC_HECC_CR14_TEST_MODE_RD(value)    (HEFC_HECC_CR14_TEST_MODE_RD_Msk & ((value) << HEFC_HECC_CR14_TEST_MODE_RD_Pos))
#define HEFC_HECC_CR14_TEST_MODE_WR_Pos       _U_(2)                                               /**< (HEFC_HECC_CR14) test mode of ECC protection - write mode Position */
#define HEFC_HECC_CR14_TEST_MODE_WR_Msk       (_U_(0x1) << HEFC_HECC_CR14_TEST_MODE_WR_Pos)        /**< (HEFC_HECC_CR14) test mode of ECC protection - write mode Mask */
#define HEFC_HECC_CR14_TEST_MODE_WR(value)    (HEFC_HECC_CR14_TEST_MODE_WR_Msk & ((value) << HEFC_HECC_CR14_TEST_MODE_WR_Pos))
#define HEFC_HECC_CR14_RST_FIX_CPT_Pos        _U_(4)                                               /**< (HEFC_HECC_CR14) reset the fixable error counter Position */
#define HEFC_HECC_CR14_RST_FIX_CPT_Msk        (_U_(0x1) << HEFC_HECC_CR14_RST_FIX_CPT_Pos)         /**< (HEFC_HECC_CR14) reset the fixable error counter Mask */
#define HEFC_HECC_CR14_RST_FIX_CPT(value)     (HEFC_HECC_CR14_RST_FIX_CPT_Msk & ((value) << HEFC_HECC_CR14_RST_FIX_CPT_Pos))
#define HEFC_HECC_CR14_RST_NOFIX_CPT_Pos      _U_(5)                                               /**< (HEFC_HECC_CR14) reset the un-fixable error counter Position */
#define HEFC_HECC_CR14_RST_NOFIX_CPT_Msk      (_U_(0x1) << HEFC_HECC_CR14_RST_NOFIX_CPT_Pos)       /**< (HEFC_HECC_CR14) reset the un-fixable error counter Mask */
#define HEFC_HECC_CR14_RST_NOFIX_CPT(value)   (HEFC_HECC_CR14_RST_NOFIX_CPT_Msk & ((value) << HEFC_HECC_CR14_RST_NOFIX_CPT_Pos))
#define HEFC_HECC_CR14_ECC12_ENABLE_Pos       _U_(6)                                               /**< (HEFC_HECC_CR14) BCH ECC enable Position */
#define HEFC_HECC_CR14_ECC12_ENABLE_Msk       (_U_(0x1) << HEFC_HECC_CR14_ECC12_ENABLE_Pos)        /**< (HEFC_HECC_CR14) BCH ECC enable Mask */
#define HEFC_HECC_CR14_ECC12_ENABLE(value)    (HEFC_HECC_CR14_ECC12_ENABLE_Msk & ((value) << HEFC_HECC_CR14_ECC12_ENABLE_Pos))
#define HEFC_HECC_CR14_Msk                    _U_(0x00000077)                                      /**< (HEFC_HECC_CR14) Register Mask  */


/* -------- HEFC_HECC_CR15 : (HEFC Offset: 0x13C) (R/W 32) HECC Control Register ChannelNumbers (ChannelNumbers = 0) 15 -------- */
#define HEFC_HECC_CR15_ENABLE_Pos             _U_(0)                                               /**< (HEFC_HECC_CR15) ECC protection enable Position */
#define HEFC_HECC_CR15_ENABLE_Msk             (_U_(0x1) << HEFC_HECC_CR15_ENABLE_Pos)              /**< (HEFC_HECC_CR15) ECC protection enable Mask */
#define HEFC_HECC_CR15_ENABLE(value)          (HEFC_HECC_CR15_ENABLE_Msk & ((value) << HEFC_HECC_CR15_ENABLE_Pos))
#define HEFC_HECC_CR15_TEST_MODE_RD_Pos       _U_(1)                                               /**< (HEFC_HECC_CR15) test mode of ECC protection - read mode Position */
#define HEFC_HECC_CR15_TEST_MODE_RD_Msk       (_U_(0x1) << HEFC_HECC_CR15_TEST_MODE_RD_Pos)        /**< (HEFC_HECC_CR15) test mode of ECC protection - read mode Mask */
#define HEFC_HECC_CR15_TEST_MODE_RD(value)    (HEFC_HECC_CR15_TEST_MODE_RD_Msk & ((value) << HEFC_HECC_CR15_TEST_MODE_RD_Pos))
#define HEFC_HECC_CR15_TEST_MODE_WR_Pos       _U_(2)                                               /**< (HEFC_HECC_CR15) test mode of ECC protection - write mode Position */
#define HEFC_HECC_CR15_TEST_MODE_WR_Msk       (_U_(0x1) << HEFC_HECC_CR15_TEST_MODE_WR_Pos)        /**< (HEFC_HECC_CR15) test mode of ECC protection - write mode Mask */
#define HEFC_HECC_CR15_TEST_MODE_WR(value)    (HEFC_HECC_CR15_TEST_MODE_WR_Msk & ((value) << HEFC_HECC_CR15_TEST_MODE_WR_Pos))
#define HEFC_HECC_CR15_RST_FIX_CPT_Pos        _U_(4)                                               /**< (HEFC_HECC_CR15) reset the fixable error counter Position */
#define HEFC_HECC_CR15_RST_FIX_CPT_Msk        (_U_(0x1) << HEFC_HECC_CR15_RST_FIX_CPT_Pos)         /**< (HEFC_HECC_CR15) reset the fixable error counter Mask */
#define HEFC_HECC_CR15_RST_FIX_CPT(value)     (HEFC_HECC_CR15_RST_FIX_CPT_Msk & ((value) << HEFC_HECC_CR15_RST_FIX_CPT_Pos))
#define HEFC_HECC_CR15_RST_NOFIX_CPT_Pos      _U_(5)                                               /**< (HEFC_HECC_CR15) reset the un-fixable error counter Position */
#define HEFC_HECC_CR15_RST_NOFIX_CPT_Msk      (_U_(0x1) << HEFC_HECC_CR15_RST_NOFIX_CPT_Pos)       /**< (HEFC_HECC_CR15) reset the un-fixable error counter Mask */
#define HEFC_HECC_CR15_RST_NOFIX_CPT(value)   (HEFC_HECC_CR15_RST_NOFIX_CPT_Msk & ((value) << HEFC_HECC_CR15_RST_NOFIX_CPT_Pos))
#define HEFC_HECC_CR15_ECC12_ENABLE_Pos       _U_(6)                                               /**< (HEFC_HECC_CR15) BCH ECC enable Position */
#define HEFC_HECC_CR15_ECC12_ENABLE_Msk       (_U_(0x1) << HEFC_HECC_CR15_ECC12_ENABLE_Pos)        /**< (HEFC_HECC_CR15) BCH ECC enable Mask */
#define HEFC_HECC_CR15_ECC12_ENABLE(value)    (HEFC_HECC_CR15_ECC12_ENABLE_Msk & ((value) << HEFC_HECC_CR15_ECC12_ENABLE_Pos))
#define HEFC_HECC_CR15_Msk                    _U_(0x00000077)                                      /**< (HEFC_HECC_CR15) Register Mask  */


/* -------- HEFC_HECC_TESTCB0 : (HEFC Offset: 0x140) (R/W 32) HECC Test mode ChannelNumbers (ChannelNumbers = 0) 0 -------- */
#define HEFC_HECC_TESTCB0_TCB_Pos             _U_(0)                                               /**< (HEFC_HECC_TESTCB0) test check bit (16 bit) Position */
#define HEFC_HECC_TESTCB0_TCB_Msk             (_U_(0xFFFF) << HEFC_HECC_TESTCB0_TCB_Pos)           /**< (HEFC_HECC_TESTCB0) test check bit (16 bit) Mask */
#define HEFC_HECC_TESTCB0_TCB(value)          (HEFC_HECC_TESTCB0_TCB_Msk & ((value) << HEFC_HECC_TESTCB0_TCB_Pos))
#define HEFC_HECC_TESTCB0_Msk                 _U_(0x0000FFFF)                                      /**< (HEFC_HECC_TESTCB0) Register Mask  */


/* -------- HEFC_HECC_TESTCB1 : (HEFC Offset: 0x144) (R/W 32) HECC Test mode ChannelNumbers (ChannelNumbers = 0) 1 -------- */
#define HEFC_HECC_TESTCB1_TCB_Pos             _U_(0)                                               /**< (HEFC_HECC_TESTCB1) test check bit (16 bit) Position */
#define HEFC_HECC_TESTCB1_TCB_Msk             (_U_(0xFFFF) << HEFC_HECC_TESTCB1_TCB_Pos)           /**< (HEFC_HECC_TESTCB1) test check bit (16 bit) Mask */
#define HEFC_HECC_TESTCB1_TCB(value)          (HEFC_HECC_TESTCB1_TCB_Msk & ((value) << HEFC_HECC_TESTCB1_TCB_Pos))
#define HEFC_HECC_TESTCB1_Msk                 _U_(0x0000FFFF)                                      /**< (HEFC_HECC_TESTCB1) Register Mask  */


/* -------- HEFC_HECC_TESTCB2 : (HEFC Offset: 0x148) (R/W 32) HECC Test mode ChannelNumbers (ChannelNumbers = 0) 2 -------- */
#define HEFC_HECC_TESTCB2_TCB_Pos             _U_(0)                                               /**< (HEFC_HECC_TESTCB2) test check bit (16 bit) Position */
#define HEFC_HECC_TESTCB2_TCB_Msk             (_U_(0xFFFF) << HEFC_HECC_TESTCB2_TCB_Pos)           /**< (HEFC_HECC_TESTCB2) test check bit (16 bit) Mask */
#define HEFC_HECC_TESTCB2_TCB(value)          (HEFC_HECC_TESTCB2_TCB_Msk & ((value) << HEFC_HECC_TESTCB2_TCB_Pos))
#define HEFC_HECC_TESTCB2_Msk                 _U_(0x0000FFFF)                                      /**< (HEFC_HECC_TESTCB2) Register Mask  */


/* -------- HEFC_HECC_TESTCB3 : (HEFC Offset: 0x14C) (R/W 32) HECC Test mode ChannelNumbers (ChannelNumbers = 0) 3 -------- */
#define HEFC_HECC_TESTCB3_TCB_Pos             _U_(0)                                               /**< (HEFC_HECC_TESTCB3) test check bit (16 bit) Position */
#define HEFC_HECC_TESTCB3_TCB_Msk             (_U_(0xFFFF) << HEFC_HECC_TESTCB3_TCB_Pos)           /**< (HEFC_HECC_TESTCB3) test check bit (16 bit) Mask */
#define HEFC_HECC_TESTCB3_TCB(value)          (HEFC_HECC_TESTCB3_TCB_Msk & ((value) << HEFC_HECC_TESTCB3_TCB_Pos))
#define HEFC_HECC_TESTCB3_Msk                 _U_(0x0000FFFF)                                      /**< (HEFC_HECC_TESTCB3) Register Mask  */


/* -------- HEFC_HECC_TESTCB4 : (HEFC Offset: 0x150) (R/W 32) HECC Test mode ChannelNumbers (ChannelNumbers = 0) 4 -------- */
#define HEFC_HECC_TESTCB4_TCB_Pos             _U_(0)                                               /**< (HEFC_HECC_TESTCB4) test check bit (16 bit) Position */
#define HEFC_HECC_TESTCB4_TCB_Msk             (_U_(0xFFFF) << HEFC_HECC_TESTCB4_TCB_Pos)           /**< (HEFC_HECC_TESTCB4) test check bit (16 bit) Mask */
#define HEFC_HECC_TESTCB4_TCB(value)          (HEFC_HECC_TESTCB4_TCB_Msk & ((value) << HEFC_HECC_TESTCB4_TCB_Pos))
#define HEFC_HECC_TESTCB4_Msk                 _U_(0x0000FFFF)                                      /**< (HEFC_HECC_TESTCB4) Register Mask  */


/* -------- HEFC_HECC_TESTCB5 : (HEFC Offset: 0x154) (R/W 32) HECC Test mode ChannelNumbers (ChannelNumbers = 0) 5 -------- */
#define HEFC_HECC_TESTCB5_TCB_Pos             _U_(0)                                               /**< (HEFC_HECC_TESTCB5) test check bit (16 bit) Position */
#define HEFC_HECC_TESTCB5_TCB_Msk             (_U_(0xFFFF) << HEFC_HECC_TESTCB5_TCB_Pos)           /**< (HEFC_HECC_TESTCB5) test check bit (16 bit) Mask */
#define HEFC_HECC_TESTCB5_TCB(value)          (HEFC_HECC_TESTCB5_TCB_Msk & ((value) << HEFC_HECC_TESTCB5_TCB_Pos))
#define HEFC_HECC_TESTCB5_Msk                 _U_(0x0000FFFF)                                      /**< (HEFC_HECC_TESTCB5) Register Mask  */


/* -------- HEFC_HECC_TESTCB6 : (HEFC Offset: 0x158) (R/W 32) HECC Test mode ChannelNumbers (ChannelNumbers = 0) 6 -------- */
#define HEFC_HECC_TESTCB6_TCB_Pos             _U_(0)                                               /**< (HEFC_HECC_TESTCB6) test check bit (16 bit) Position */
#define HEFC_HECC_TESTCB6_TCB_Msk             (_U_(0xFFFF) << HEFC_HECC_TESTCB6_TCB_Pos)           /**< (HEFC_HECC_TESTCB6) test check bit (16 bit) Mask */
#define HEFC_HECC_TESTCB6_TCB(value)          (HEFC_HECC_TESTCB6_TCB_Msk & ((value) << HEFC_HECC_TESTCB6_TCB_Pos))
#define HEFC_HECC_TESTCB6_Msk                 _U_(0x0000FFFF)                                      /**< (HEFC_HECC_TESTCB6) Register Mask  */


/* -------- HEFC_HECC_TESTCB7 : (HEFC Offset: 0x15C) (R/W 32) HECC Test mode ChannelNumbers (ChannelNumbers = 0) 7 -------- */
#define HEFC_HECC_TESTCB7_TCB_Pos             _U_(0)                                               /**< (HEFC_HECC_TESTCB7) test check bit (16 bit) Position */
#define HEFC_HECC_TESTCB7_TCB_Msk             (_U_(0xFFFF) << HEFC_HECC_TESTCB7_TCB_Pos)           /**< (HEFC_HECC_TESTCB7) test check bit (16 bit) Mask */
#define HEFC_HECC_TESTCB7_TCB(value)          (HEFC_HECC_TESTCB7_TCB_Msk & ((value) << HEFC_HECC_TESTCB7_TCB_Pos))
#define HEFC_HECC_TESTCB7_Msk                 _U_(0x0000FFFF)                                      /**< (HEFC_HECC_TESTCB7) Register Mask  */


/* -------- HEFC_HECC_TESTCB8 : (HEFC Offset: 0x160) (R/W 32) HECC Test mode ChannelNumbers (ChannelNumbers = 0) 8 -------- */
#define HEFC_HECC_TESTCB8_TCB_Pos             _U_(0)                                               /**< (HEFC_HECC_TESTCB8) test check bit (16 bit) Position */
#define HEFC_HECC_TESTCB8_TCB_Msk             (_U_(0xFFFF) << HEFC_HECC_TESTCB8_TCB_Pos)           /**< (HEFC_HECC_TESTCB8) test check bit (16 bit) Mask */
#define HEFC_HECC_TESTCB8_TCB(value)          (HEFC_HECC_TESTCB8_TCB_Msk & ((value) << HEFC_HECC_TESTCB8_TCB_Pos))
#define HEFC_HECC_TESTCB8_Msk                 _U_(0x0000FFFF)                                      /**< (HEFC_HECC_TESTCB8) Register Mask  */


/* -------- HEFC_HECC_TESTCB9 : (HEFC Offset: 0x164) (R/W 32) HECC Test mode ChannelNumbers (ChannelNumbers = 0) 9 -------- */
#define HEFC_HECC_TESTCB9_TCB_Pos             _U_(0)                                               /**< (HEFC_HECC_TESTCB9) test check bit (16 bit) Position */
#define HEFC_HECC_TESTCB9_TCB_Msk             (_U_(0xFFFF) << HEFC_HECC_TESTCB9_TCB_Pos)           /**< (HEFC_HECC_TESTCB9) test check bit (16 bit) Mask */
#define HEFC_HECC_TESTCB9_TCB(value)          (HEFC_HECC_TESTCB9_TCB_Msk & ((value) << HEFC_HECC_TESTCB9_TCB_Pos))
#define HEFC_HECC_TESTCB9_Msk                 _U_(0x0000FFFF)                                      /**< (HEFC_HECC_TESTCB9) Register Mask  */


/* -------- HEFC_HECC_TESTCB10 : (HEFC Offset: 0x168) (R/W 32) HECC Test mode ChannelNumbers (ChannelNumbers = 0) 10 -------- */
#define HEFC_HECC_TESTCB10_TCB_Pos            _U_(0)                                               /**< (HEFC_HECC_TESTCB10) test check bit (16 bit) Position */
#define HEFC_HECC_TESTCB10_TCB_Msk            (_U_(0xFFFF) << HEFC_HECC_TESTCB10_TCB_Pos)          /**< (HEFC_HECC_TESTCB10) test check bit (16 bit) Mask */
#define HEFC_HECC_TESTCB10_TCB(value)         (HEFC_HECC_TESTCB10_TCB_Msk & ((value) << HEFC_HECC_TESTCB10_TCB_Pos))
#define HEFC_HECC_TESTCB10_Msk                _U_(0x0000FFFF)                                      /**< (HEFC_HECC_TESTCB10) Register Mask  */


/* -------- HEFC_HECC_TESTCB11 : (HEFC Offset: 0x16C) (R/W 32) HECC Test mode ChannelNumbers (ChannelNumbers = 0) 11 -------- */
#define HEFC_HECC_TESTCB11_TCB_Pos            _U_(0)                                               /**< (HEFC_HECC_TESTCB11) test check bit (16 bit) Position */
#define HEFC_HECC_TESTCB11_TCB_Msk            (_U_(0xFFFF) << HEFC_HECC_TESTCB11_TCB_Pos)          /**< (HEFC_HECC_TESTCB11) test check bit (16 bit) Mask */
#define HEFC_HECC_TESTCB11_TCB(value)         (HEFC_HECC_TESTCB11_TCB_Msk & ((value) << HEFC_HECC_TESTCB11_TCB_Pos))
#define HEFC_HECC_TESTCB11_Msk                _U_(0x0000FFFF)                                      /**< (HEFC_HECC_TESTCB11) Register Mask  */


/* -------- HEFC_HECC_TESTCB12 : (HEFC Offset: 0x170) (R/W 32) HECC Test mode ChannelNumbers (ChannelNumbers = 0) 12 -------- */
#define HEFC_HECC_TESTCB12_TCB_Pos            _U_(0)                                               /**< (HEFC_HECC_TESTCB12) test check bit (16 bit) Position */
#define HEFC_HECC_TESTCB12_TCB_Msk            (_U_(0xFFFF) << HEFC_HECC_TESTCB12_TCB_Pos)          /**< (HEFC_HECC_TESTCB12) test check bit (16 bit) Mask */
#define HEFC_HECC_TESTCB12_TCB(value)         (HEFC_HECC_TESTCB12_TCB_Msk & ((value) << HEFC_HECC_TESTCB12_TCB_Pos))
#define HEFC_HECC_TESTCB12_Msk                _U_(0x0000FFFF)                                      /**< (HEFC_HECC_TESTCB12) Register Mask  */


/* -------- HEFC_HECC_TESTCB13 : (HEFC Offset: 0x174) (R/W 32) HECC Test mode ChannelNumbers (ChannelNumbers = 0) 13 -------- */
#define HEFC_HECC_TESTCB13_TCB_Pos            _U_(0)                                               /**< (HEFC_HECC_TESTCB13) test check bit (16 bit) Position */
#define HEFC_HECC_TESTCB13_TCB_Msk            (_U_(0xFFFF) << HEFC_HECC_TESTCB13_TCB_Pos)          /**< (HEFC_HECC_TESTCB13) test check bit (16 bit) Mask */
#define HEFC_HECC_TESTCB13_TCB(value)         (HEFC_HECC_TESTCB13_TCB_Msk & ((value) << HEFC_HECC_TESTCB13_TCB_Pos))
#define HEFC_HECC_TESTCB13_Msk                _U_(0x0000FFFF)                                      /**< (HEFC_HECC_TESTCB13) Register Mask  */


/* -------- HEFC_HECC_TESTCB14 : (HEFC Offset: 0x178) (R/W 32) HECC Test mode ChannelNumbers (ChannelNumbers = 0) 14 -------- */
#define HEFC_HECC_TESTCB14_TCB_Pos            _U_(0)                                               /**< (HEFC_HECC_TESTCB14) test check bit (16 bit) Position */
#define HEFC_HECC_TESTCB14_TCB_Msk            (_U_(0xFFFF) << HEFC_HECC_TESTCB14_TCB_Pos)          /**< (HEFC_HECC_TESTCB14) test check bit (16 bit) Mask */
#define HEFC_HECC_TESTCB14_TCB(value)         (HEFC_HECC_TESTCB14_TCB_Msk & ((value) << HEFC_HECC_TESTCB14_TCB_Pos))
#define HEFC_HECC_TESTCB14_Msk                _U_(0x0000FFFF)                                      /**< (HEFC_HECC_TESTCB14) Register Mask  */


/* -------- HEFC_HECC_TESTCB15 : (HEFC Offset: 0x17C) (R/W 32) HECC Test mode ChannelNumbers (ChannelNumbers = 0) 15 -------- */
#define HEFC_HECC_TESTCB15_TCB_Pos            _U_(0)                                               /**< (HEFC_HECC_TESTCB15) test check bit (16 bit) Position */
#define HEFC_HECC_TESTCB15_TCB_Msk            (_U_(0xFFFF) << HEFC_HECC_TESTCB15_TCB_Pos)          /**< (HEFC_HECC_TESTCB15) test check bit (16 bit) Mask */
#define HEFC_HECC_TESTCB15_TCB(value)         (HEFC_HECC_TESTCB15_TCB_Msk & ((value) << HEFC_HECC_TESTCB15_TCB_Pos))
#define HEFC_HECC_TESTCB15_Msk                _U_(0x0000FFFF)                                      /**< (HEFC_HECC_TESTCB15) Register Mask  */


/* -------- HEFC_HECC_SR : (HEFC Offset: 0x180) ( R/ 32) HECC Status register -------- */
#define HEFC_HECC_SR_MEM_FIX_Pos              _U_(0)                                               /**< (HEFC_HECC_SR) Fixable error status Position */
#define HEFC_HECC_SR_MEM_FIX_Msk              (_U_(0x1) << HEFC_HECC_SR_MEM_FIX_Pos)               /**< (HEFC_HECC_SR) Fixable error status Mask */
#define HEFC_HECC_SR_MEM_FIX(value)           (HEFC_HECC_SR_MEM_FIX_Msk & ((value) << HEFC_HECC_SR_MEM_FIX_Pos))
#define HEFC_HECC_SR_CPT_FIX_Pos              _U_(2)                                               /**< (HEFC_HECC_SR) 5 bits counter Position */
#define HEFC_HECC_SR_CPT_FIX_Msk              (_U_(0x1F) << HEFC_HECC_SR_CPT_FIX_Pos)              /**< (HEFC_HECC_SR) 5 bits counter Mask */
#define HEFC_HECC_SR_CPT_FIX(value)           (HEFC_HECC_SR_CPT_FIX_Msk & ((value) << HEFC_HECC_SR_CPT_FIX_Pos))
#define HEFC_HECC_SR_OVER_FIX_Pos             _U_(7)                                               /**< (HEFC_HECC_SR) counter overflow Position */
#define HEFC_HECC_SR_OVER_FIX_Msk             (_U_(0x1) << HEFC_HECC_SR_OVER_FIX_Pos)              /**< (HEFC_HECC_SR) counter overflow Mask */
#define HEFC_HECC_SR_OVER_FIX(value)          (HEFC_HECC_SR_OVER_FIX_Msk & ((value) << HEFC_HECC_SR_OVER_FIX_Pos))
#define HEFC_HECC_SR_MEM_NOFIX_Pos            _U_(8)                                               /**< (HEFC_HECC_SR) Un-fixable error status Position */
#define HEFC_HECC_SR_MEM_NOFIX_Msk            (_U_(0x1) << HEFC_HECC_SR_MEM_NOFIX_Pos)             /**< (HEFC_HECC_SR) Un-fixable error status Mask */
#define HEFC_HECC_SR_MEM_NOFIX(value)         (HEFC_HECC_SR_MEM_NOFIX_Msk & ((value) << HEFC_HECC_SR_MEM_NOFIX_Pos))
#define HEFC_HECC_SR_CPT_NOFIX_Pos            _U_(10)                                              /**< (HEFC_HECC_SR) 5 bits counter Position */
#define HEFC_HECC_SR_CPT_NOFIX_Msk            (_U_(0x1F) << HEFC_HECC_SR_CPT_NOFIX_Pos)            /**< (HEFC_HECC_SR) 5 bits counter Mask */
#define HEFC_HECC_SR_CPT_NOFIX(value)         (HEFC_HECC_SR_CPT_NOFIX_Msk & ((value) << HEFC_HECC_SR_CPT_NOFIX_Pos))
#define HEFC_HECC_SR_OVER_NOFIX_Pos           _U_(15)                                              /**< (HEFC_HECC_SR) counter overflow Position */
#define HEFC_HECC_SR_OVER_NOFIX_Msk           (_U_(0x1) << HEFC_HECC_SR_OVER_NOFIX_Pos)            /**< (HEFC_HECC_SR) counter overflow Mask */
#define HEFC_HECC_SR_OVER_NOFIX(value)        (HEFC_HECC_SR_OVER_NOFIX_Msk & ((value) << HEFC_HECC_SR_OVER_NOFIX_Pos))
#define HEFC_HECC_SR_HES_Pos                  _U_(24)                                              /**< (HEFC_HECC_SR) Hardware Error Size Position */
#define HEFC_HECC_SR_HES_Msk                  (_U_(0x7) << HEFC_HECC_SR_HES_Pos)                   /**< (HEFC_HECC_SR) Hardware Error Size Mask */
#define HEFC_HECC_SR_HES(value)               (HEFC_HECC_SR_HES_Msk & ((value) << HEFC_HECC_SR_HES_Pos))
#define HEFC_HECC_SR_TYPE_Pos                 _U_(27)                                              /**< (HEFC_HECC_SR) write or read access Position */
#define HEFC_HECC_SR_TYPE_Msk                 (_U_(0x1) << HEFC_HECC_SR_TYPE_Pos)                  /**< (HEFC_HECC_SR) write or read access Mask */
#define HEFC_HECC_SR_TYPE(value)              (HEFC_HECC_SR_TYPE_Msk & ((value) << HEFC_HECC_SR_TYPE_Pos))
#define HEFC_HECC_SR_MEM_ID_Pos               _U_(28)                                              /**< (HEFC_HECC_SR) memory identification number Position */
#define HEFC_HECC_SR_MEM_ID_Msk               (_U_(0x3) << HEFC_HECC_SR_MEM_ID_Pos)                /**< (HEFC_HECC_SR) memory identification number Mask */
#define HEFC_HECC_SR_MEM_ID(value)            (HEFC_HECC_SR_MEM_ID_Msk & ((value) << HEFC_HECC_SR_MEM_ID_Pos))
#define HEFC_HECC_SR_Msk                      _U_(0x3F00FDFD)                                      /**< (HEFC_HECC_SR) Register Mask  */


/* -------- HEFC_HECC_IER : (HEFC Offset: 0x184) ( /W 32) HECC Interrupt Enable Register -------- */
#define HEFC_HECC_IER_MEM_FIX_Pos             _U_(0)                                               /**< (HEFC_HECC_IER) Fixable error Position */
#define HEFC_HECC_IER_MEM_FIX_Msk             (_U_(0x1) << HEFC_HECC_IER_MEM_FIX_Pos)              /**< (HEFC_HECC_IER) Fixable error Mask */
#define HEFC_HECC_IER_MEM_FIX(value)          (HEFC_HECC_IER_MEM_FIX_Msk & ((value) << HEFC_HECC_IER_MEM_FIX_Pos))
#define HEFC_HECC_IER_MEM_NOFIX_Pos           _U_(1)                                               /**< (HEFC_HECC_IER) Un-fixable error Position */
#define HEFC_HECC_IER_MEM_NOFIX_Msk           (_U_(0x1) << HEFC_HECC_IER_MEM_NOFIX_Pos)            /**< (HEFC_HECC_IER) Un-fixable error Mask */
#define HEFC_HECC_IER_MEM_NOFIX(value)        (HEFC_HECC_IER_MEM_NOFIX_Msk & ((value) << HEFC_HECC_IER_MEM_NOFIX_Pos))
#define HEFC_HECC_IER_Msk                     _U_(0x00000003)                                      /**< (HEFC_HECC_IER) Register Mask  */


/* -------- HEFC_HECC_IDR : (HEFC Offset: 0x188) ( /W 32) HECC Interrupt Disable Register -------- */
#define HEFC_HECC_IDR_MEM_FIX_Pos             _U_(0)                                               /**< (HEFC_HECC_IDR) fixable error Position */
#define HEFC_HECC_IDR_MEM_FIX_Msk             (_U_(0x1) << HEFC_HECC_IDR_MEM_FIX_Pos)              /**< (HEFC_HECC_IDR) fixable error Mask */
#define HEFC_HECC_IDR_MEM_FIX(value)          (HEFC_HECC_IDR_MEM_FIX_Msk & ((value) << HEFC_HECC_IDR_MEM_FIX_Pos))
#define HEFC_HECC_IDR_MEM_NOFIX_Pos           _U_(1)                                               /**< (HEFC_HECC_IDR) un-fixable error Position */
#define HEFC_HECC_IDR_MEM_NOFIX_Msk           (_U_(0x1) << HEFC_HECC_IDR_MEM_NOFIX_Pos)            /**< (HEFC_HECC_IDR) un-fixable error Mask */
#define HEFC_HECC_IDR_MEM_NOFIX(value)        (HEFC_HECC_IDR_MEM_NOFIX_Msk & ((value) << HEFC_HECC_IDR_MEM_NOFIX_Pos))
#define HEFC_HECC_IDR_Msk                     _U_(0x00000003)                                      /**< (HEFC_HECC_IDR) Register Mask  */


/* -------- HEFC_HECC_IMR : (HEFC Offset: 0x18C) ( R/ 32) HECC Interrupt Mask Register -------- */
#define HEFC_HECC_IMR_MEM_FIX_Pos             _U_(0)                                               /**< (HEFC_HECC_IMR) fixable error Position */
#define HEFC_HECC_IMR_MEM_FIX_Msk             (_U_(0x1) << HEFC_HECC_IMR_MEM_FIX_Pos)              /**< (HEFC_HECC_IMR) fixable error Mask */
#define HEFC_HECC_IMR_MEM_FIX(value)          (HEFC_HECC_IMR_MEM_FIX_Msk & ((value) << HEFC_HECC_IMR_MEM_FIX_Pos))
#define HEFC_HECC_IMR_MEM_NOFIX_Pos           _U_(1)                                               /**< (HEFC_HECC_IMR) un-fixable error Position */
#define HEFC_HECC_IMR_MEM_NOFIX_Msk           (_U_(0x1) << HEFC_HECC_IMR_MEM_NOFIX_Pos)            /**< (HEFC_HECC_IMR) un-fixable error Mask */
#define HEFC_HECC_IMR_MEM_NOFIX(value)        (HEFC_HECC_IMR_MEM_NOFIX_Msk & ((value) << HEFC_HECC_IMR_MEM_NOFIX_Pos))
#define HEFC_HECC_IMR_Msk                     _U_(0x00000003)                                      /**< (HEFC_HECC_IMR) Register Mask  */


/* -------- HEFC_HECC_FAILAR : (HEFC Offset: 0x190) ( R/ 32) HECC Fail address register -------- */
#define HEFC_HECC_FAILAR_ADDRESS_Pos          _U_(0)                                               /**< (HEFC_HECC_FAILAR) address of the error detected Position */
#define HEFC_HECC_FAILAR_ADDRESS_Msk          (_U_(0xFFFFFFFF) << HEFC_HECC_FAILAR_ADDRESS_Pos)    /**< (HEFC_HECC_FAILAR) address of the error detected Mask */
#define HEFC_HECC_FAILAR_ADDRESS(value)       (HEFC_HECC_FAILAR_ADDRESS_Msk & ((value) << HEFC_HECC_FAILAR_ADDRESS_Pos))
#define HEFC_HECC_FAILAR_Msk                  _U_(0xFFFFFFFF)                                      /**< (HEFC_HECC_FAILAR) Register Mask  */


/* -------- HEFC_GPNVM_MISC : (HEFC Offset: 0x00) (R/W 32) HEFC GPNVM word miscellaneous -------- */
#define HEFC_GPNVM_MISC_DEBUG_INTF_Pos        _U_(1)                                               /**< (HEFC_GPNVM_MISC) Debug interface Selection Position */
#define HEFC_GPNVM_MISC_DEBUG_INTF_Msk        (_U_(0x1) << HEFC_GPNVM_MISC_DEBUG_INTF_Pos)         /**< (HEFC_GPNVM_MISC) Debug interface Selection Mask */
#define HEFC_GPNVM_MISC_DEBUG_INTF(value)     (HEFC_GPNVM_MISC_DEBUG_INTF_Msk & ((value) << HEFC_GPNVM_MISC_DEBUG_INTF_Pos))
#define   HEFC_GPNVM_MISC_DEBUG_INTF_JTAG_Val _U_(0x0)                                             /**< (HEFC_GPNVM_MISC) JTAG  */
#define   HEFC_GPNVM_MISC_DEBUG_INTF_SWD_Val  _U_(0x1)                                             /**< (HEFC_GPNVM_MISC) SWD  */
#define HEFC_GPNVM_MISC_DEBUG_INTF_JTAG       (HEFC_GPNVM_MISC_DEBUG_INTF_JTAG_Val << HEFC_GPNVM_MISC_DEBUG_INTF_Pos) /**< (HEFC_GPNVM_MISC) JTAG Position  */
#define HEFC_GPNVM_MISC_DEBUG_INTF_SWD        (HEFC_GPNVM_MISC_DEBUG_INTF_SWD_Val << HEFC_GPNVM_MISC_DEBUG_INTF_Pos) /**< (HEFC_GPNVM_MISC) SWD Position  */
#define HEFC_GPNVM_MISC_PFD_TRIM_Pos          _U_(8)                                               /**< (HEFC_GPNVM_MISC) PFD Trim value Position */
#define HEFC_GPNVM_MISC_PFD_TRIM_Msk          (_U_(0x7) << HEFC_GPNVM_MISC_PFD_TRIM_Pos)           /**< (HEFC_GPNVM_MISC) PFD Trim value Mask */
#define HEFC_GPNVM_MISC_PFD_TRIM(value)       (HEFC_GPNVM_MISC_PFD_TRIM_Msk & ((value) << HEFC_GPNVM_MISC_PFD_TRIM_Pos))
#define HEFC_GPNVM_MISC_Msk                   _U_(0x00000702)                                      /**< (HEFC_GPNVM_MISC) Register Mask  */


/* -------- HEFC_GPNVM_RC_TRIM : (HEFC Offset: 0x04) (R/W 32) HEFC GPNVM word RC trim (1..3) -------- */
#define HEFC_GPNVM_RC_TRIM_RC_TTRIM_Pos       _U_(0)                                               /**< (HEFC_GPNVM_RC_TRIM) RC Temperature Trim Position */
#define HEFC_GPNVM_RC_TRIM_RC_TTRIM_Msk       (_U_(0x3) << HEFC_GPNVM_RC_TRIM_RC_TTRIM_Pos)        /**< (HEFC_GPNVM_RC_TRIM) RC Temperature Trim Mask */
#define HEFC_GPNVM_RC_TRIM_RC_TTRIM(value)    (HEFC_GPNVM_RC_TRIM_RC_TTRIM_Msk & ((value) << HEFC_GPNVM_RC_TRIM_RC_TTRIM_Pos))
#define HEFC_GPNVM_RC_TRIM_RC2_TTRIM_Pos      _U_(2)                                               /**< (HEFC_GPNVM_RC_TRIM) RC2 Temperature Trim Position */
#define HEFC_GPNVM_RC_TRIM_RC2_TTRIM_Msk      (_U_(0x3) << HEFC_GPNVM_RC_TRIM_RC2_TTRIM_Pos)       /**< (HEFC_GPNVM_RC_TRIM) RC2 Temperature Trim Mask */
#define HEFC_GPNVM_RC_TRIM_RC2_TTRIM(value)   (HEFC_GPNVM_RC_TRIM_RC2_TTRIM_Msk & ((value) << HEFC_GPNVM_RC_TRIM_RC2_TTRIM_Pos))
#define HEFC_GPNVM_RC_TRIM_RC_FTRIM_4MHZ_Pos  _U_(4)                                               /**< (HEFC_GPNVM_RC_TRIM) RC Frequency Trim 4MHz Position */
#define HEFC_GPNVM_RC_TRIM_RC_FTRIM_4MHZ_Msk  (_U_(0x7) << HEFC_GPNVM_RC_TRIM_RC_FTRIM_4MHZ_Pos)   /**< (HEFC_GPNVM_RC_TRIM) RC Frequency Trim 4MHz Mask */
#define HEFC_GPNVM_RC_TRIM_RC_FTRIM_4MHZ(value) (HEFC_GPNVM_RC_TRIM_RC_FTRIM_4MHZ_Msk & ((value) << HEFC_GPNVM_RC_TRIM_RC_FTRIM_4MHZ_Pos))
#define HEFC_GPNVM_RC_TRIM_RC_FTRIM_8MHZ_Pos  _U_(7)                                               /**< (HEFC_GPNVM_RC_TRIM) RC Frequency Trim 8MHz Position */
#define HEFC_GPNVM_RC_TRIM_RC_FTRIM_8MHZ_Msk  (_U_(0x7) << HEFC_GPNVM_RC_TRIM_RC_FTRIM_8MHZ_Pos)   /**< (HEFC_GPNVM_RC_TRIM) RC Frequency Trim 8MHz Mask */
#define HEFC_GPNVM_RC_TRIM_RC_FTRIM_8MHZ(value) (HEFC_GPNVM_RC_TRIM_RC_FTRIM_8MHZ_Msk & ((value) << HEFC_GPNVM_RC_TRIM_RC_FTRIM_8MHZ_Pos))
#define HEFC_GPNVM_RC_TRIM_RC_FTRIM_10MHZ_Pos _U_(10)                                              /**< (HEFC_GPNVM_RC_TRIM) RC Frequency Trim 10MHz Position */
#define HEFC_GPNVM_RC_TRIM_RC_FTRIM_10MHZ_Msk (_U_(0x7) << HEFC_GPNVM_RC_TRIM_RC_FTRIM_10MHZ_Pos)  /**< (HEFC_GPNVM_RC_TRIM) RC Frequency Trim 10MHz Mask */
#define HEFC_GPNVM_RC_TRIM_RC_FTRIM_10MHZ(value) (HEFC_GPNVM_RC_TRIM_RC_FTRIM_10MHZ_Msk & ((value) << HEFC_GPNVM_RC_TRIM_RC_FTRIM_10MHZ_Pos))
#define HEFC_GPNVM_RC_TRIM_RC_FTRIM_12MHZ_Pos _U_(13)                                              /**< (HEFC_GPNVM_RC_TRIM) RC Frequency Trim 12MHz Position */
#define HEFC_GPNVM_RC_TRIM_RC_FTRIM_12MHZ_Msk (_U_(0x7) << HEFC_GPNVM_RC_TRIM_RC_FTRIM_12MHZ_Pos)  /**< (HEFC_GPNVM_RC_TRIM) RC Frequency Trim 12MHz Mask */
#define HEFC_GPNVM_RC_TRIM_RC_FTRIM_12MHZ(value) (HEFC_GPNVM_RC_TRIM_RC_FTRIM_12MHZ_Msk & ((value) << HEFC_GPNVM_RC_TRIM_RC_FTRIM_12MHZ_Pos))
#define HEFC_GPNVM_RC_TRIM_RC2_FTRIM_4MHZ_Pos _U_(16)                                              /**< (HEFC_GPNVM_RC_TRIM) RC2 Frequency Trim 4MHz Position */
#define HEFC_GPNVM_RC_TRIM_RC2_FTRIM_4MHZ_Msk (_U_(0x7) << HEFC_GPNVM_RC_TRIM_RC2_FTRIM_4MHZ_Pos)  /**< (HEFC_GPNVM_RC_TRIM) RC2 Frequency Trim 4MHz Mask */
#define HEFC_GPNVM_RC_TRIM_RC2_FTRIM_4MHZ(value) (HEFC_GPNVM_RC_TRIM_RC2_FTRIM_4MHZ_Msk & ((value) << HEFC_GPNVM_RC_TRIM_RC2_FTRIM_4MHZ_Pos))
#define HEFC_GPNVM_RC_TRIM_RC2_FTRIM_8MHZ_Pos _U_(19)                                              /**< (HEFC_GPNVM_RC_TRIM) RC2 Frequency Trim 8MHz Position */
#define HEFC_GPNVM_RC_TRIM_RC2_FTRIM_8MHZ_Msk (_U_(0x7) << HEFC_GPNVM_RC_TRIM_RC2_FTRIM_8MHZ_Pos)  /**< (HEFC_GPNVM_RC_TRIM) RC2 Frequency Trim 8MHz Mask */
#define HEFC_GPNVM_RC_TRIM_RC2_FTRIM_8MHZ(value) (HEFC_GPNVM_RC_TRIM_RC2_FTRIM_8MHZ_Msk & ((value) << HEFC_GPNVM_RC_TRIM_RC2_FTRIM_8MHZ_Pos))
#define HEFC_GPNVM_RC_TRIM_RC2_FTRIM_10MHZ_Pos _U_(22)                                              /**< (HEFC_GPNVM_RC_TRIM) RC2 Frequency Trim 10MHz Position */
#define HEFC_GPNVM_RC_TRIM_RC2_FTRIM_10MHZ_Msk (_U_(0x7) << HEFC_GPNVM_RC_TRIM_RC2_FTRIM_10MHZ_Pos) /**< (HEFC_GPNVM_RC_TRIM) RC2 Frequency Trim 10MHz Mask */
#define HEFC_GPNVM_RC_TRIM_RC2_FTRIM_10MHZ(value) (HEFC_GPNVM_RC_TRIM_RC2_FTRIM_10MHZ_Msk & ((value) << HEFC_GPNVM_RC_TRIM_RC2_FTRIM_10MHZ_Pos))
#define HEFC_GPNVM_RC_TRIM_RC2_FTRIM_12MHZ_Pos _U_(25)                                              /**< (HEFC_GPNVM_RC_TRIM) RC2 Frequency Trim 12MHz Position */
#define HEFC_GPNVM_RC_TRIM_RC2_FTRIM_12MHZ_Msk (_U_(0x7) << HEFC_GPNVM_RC_TRIM_RC2_FTRIM_12MHZ_Pos) /**< (HEFC_GPNVM_RC_TRIM) RC2 Frequency Trim 12MHz Mask */
#define HEFC_GPNVM_RC_TRIM_RC2_FTRIM_12MHZ(value) (HEFC_GPNVM_RC_TRIM_RC2_FTRIM_12MHZ_Msk & ((value) << HEFC_GPNVM_RC_TRIM_RC2_FTRIM_12MHZ_Pos))
#define HEFC_GPNVM_RC_TRIM_Msk                _U_(0x0FFFFFFF)                                      /**< (HEFC_GPNVM_RC_TRIM) Register Mask  */


/** \brief HEFC register offsets definitions */
#define HEFC_FMR_REG_OFST              (0x00)              /**< (HEFC_FMR) HEFC Flash Mode Register Offset */
#define HEFC_FCR_REG_OFST              (0x04)              /**< (HEFC_FCR) HEFC Flash Command Register Offset */
#define HEFC_FSR_REG_OFST              (0x08)              /**< (HEFC_FSR) HEFC Flash Status Register Offset */
#define HEFC_FRR_REG_OFST              (0x0C)              /**< (HEFC_FRR) HEFC Flash Result Register Offset */
#define HEFC_FPMR_REG_OFST             (0x40)              /**< (HEFC_FPMR) HEFC Flash Power Management Register Offset */
#define HEFC_WPMR_REG_OFST             (0xE4)              /**< (HEFC_WPMR) Write Protection Mode Register Offset */
#define HEFC_HECC_CR0_REG_OFST         (0x100)             /**< (HEFC_HECC_CR0) HECC Control Register ChannelNumbers (ChannelNumbers = 0) 0 Offset */
#define HEFC_HECC_CR1_REG_OFST         (0x104)             /**< (HEFC_HECC_CR1) HECC Control Register ChannelNumbers (ChannelNumbers = 0) 1 Offset */
#define HEFC_HECC_CR2_REG_OFST         (0x108)             /**< (HEFC_HECC_CR2) HECC Control Register ChannelNumbers (ChannelNumbers = 0) 2 Offset */
#define HEFC_HECC_CR3_REG_OFST         (0x10C)             /**< (HEFC_HECC_CR3) HECC Control Register ChannelNumbers (ChannelNumbers = 0) 3 Offset */
#define HEFC_HECC_CR4_REG_OFST         (0x110)             /**< (HEFC_HECC_CR4) HECC Control Register ChannelNumbers (ChannelNumbers = 0) 4 Offset */
#define HEFC_HECC_CR5_REG_OFST         (0x114)             /**< (HEFC_HECC_CR5) HECC Control Register ChannelNumbers (ChannelNumbers = 0) 5 Offset */
#define HEFC_HECC_CR6_REG_OFST         (0x118)             /**< (HEFC_HECC_CR6) HECC Control Register ChannelNumbers (ChannelNumbers = 0) 6 Offset */
#define HEFC_HECC_CR7_REG_OFST         (0x11C)             /**< (HEFC_HECC_CR7) HECC Control Register ChannelNumbers (ChannelNumbers = 0) 7 Offset */
#define HEFC_HECC_CR8_REG_OFST         (0x120)             /**< (HEFC_HECC_CR8) HECC Control Register ChannelNumbers (ChannelNumbers = 0) 8 Offset */
#define HEFC_HECC_CR9_REG_OFST         (0x124)             /**< (HEFC_HECC_CR9) HECC Control Register ChannelNumbers (ChannelNumbers = 0) 9 Offset */
#define HEFC_HECC_CR10_REG_OFST        (0x128)             /**< (HEFC_HECC_CR10) HECC Control Register ChannelNumbers (ChannelNumbers = 0) 10 Offset */
#define HEFC_HECC_CR11_REG_OFST        (0x12C)             /**< (HEFC_HECC_CR11) HECC Control Register ChannelNumbers (ChannelNumbers = 0) 11 Offset */
#define HEFC_HECC_CR12_REG_OFST        (0x130)             /**< (HEFC_HECC_CR12) HECC Control Register ChannelNumbers (ChannelNumbers = 0) 12 Offset */
#define HEFC_HECC_CR13_REG_OFST        (0x134)             /**< (HEFC_HECC_CR13) HECC Control Register ChannelNumbers (ChannelNumbers = 0) 13 Offset */
#define HEFC_HECC_CR14_REG_OFST        (0x138)             /**< (HEFC_HECC_CR14) HECC Control Register ChannelNumbers (ChannelNumbers = 0) 14 Offset */
#define HEFC_HECC_CR15_REG_OFST        (0x13C)             /**< (HEFC_HECC_CR15) HECC Control Register ChannelNumbers (ChannelNumbers = 0) 15 Offset */
#define HEFC_HECC_TESTCB0_REG_OFST     (0x140)             /**< (HEFC_HECC_TESTCB0) HECC Test mode ChannelNumbers (ChannelNumbers = 0) 0 Offset */
#define HEFC_HECC_TESTCB1_REG_OFST     (0x144)             /**< (HEFC_HECC_TESTCB1) HECC Test mode ChannelNumbers (ChannelNumbers = 0) 1 Offset */
#define HEFC_HECC_TESTCB2_REG_OFST     (0x148)             /**< (HEFC_HECC_TESTCB2) HECC Test mode ChannelNumbers (ChannelNumbers = 0) 2 Offset */
#define HEFC_HECC_TESTCB3_REG_OFST     (0x14C)             /**< (HEFC_HECC_TESTCB3) HECC Test mode ChannelNumbers (ChannelNumbers = 0) 3 Offset */
#define HEFC_HECC_TESTCB4_REG_OFST     (0x150)             /**< (HEFC_HECC_TESTCB4) HECC Test mode ChannelNumbers (ChannelNumbers = 0) 4 Offset */
#define HEFC_HECC_TESTCB5_REG_OFST     (0x154)             /**< (HEFC_HECC_TESTCB5) HECC Test mode ChannelNumbers (ChannelNumbers = 0) 5 Offset */
#define HEFC_HECC_TESTCB6_REG_OFST     (0x158)             /**< (HEFC_HECC_TESTCB6) HECC Test mode ChannelNumbers (ChannelNumbers = 0) 6 Offset */
#define HEFC_HECC_TESTCB7_REG_OFST     (0x15C)             /**< (HEFC_HECC_TESTCB7) HECC Test mode ChannelNumbers (ChannelNumbers = 0) 7 Offset */
#define HEFC_HECC_TESTCB8_REG_OFST     (0x160)             /**< (HEFC_HECC_TESTCB8) HECC Test mode ChannelNumbers (ChannelNumbers = 0) 8 Offset */
#define HEFC_HECC_TESTCB9_REG_OFST     (0x164)             /**< (HEFC_HECC_TESTCB9) HECC Test mode ChannelNumbers (ChannelNumbers = 0) 9 Offset */
#define HEFC_HECC_TESTCB10_REG_OFST    (0x168)             /**< (HEFC_HECC_TESTCB10) HECC Test mode ChannelNumbers (ChannelNumbers = 0) 10 Offset */
#define HEFC_HECC_TESTCB11_REG_OFST    (0x16C)             /**< (HEFC_HECC_TESTCB11) HECC Test mode ChannelNumbers (ChannelNumbers = 0) 11 Offset */
#define HEFC_HECC_TESTCB12_REG_OFST    (0x170)             /**< (HEFC_HECC_TESTCB12) HECC Test mode ChannelNumbers (ChannelNumbers = 0) 12 Offset */
#define HEFC_HECC_TESTCB13_REG_OFST    (0x174)             /**< (HEFC_HECC_TESTCB13) HECC Test mode ChannelNumbers (ChannelNumbers = 0) 13 Offset */
#define HEFC_HECC_TESTCB14_REG_OFST    (0x178)             /**< (HEFC_HECC_TESTCB14) HECC Test mode ChannelNumbers (ChannelNumbers = 0) 14 Offset */
#define HEFC_HECC_TESTCB15_REG_OFST    (0x17C)             /**< (HEFC_HECC_TESTCB15) HECC Test mode ChannelNumbers (ChannelNumbers = 0) 15 Offset */
#define HEFC_HECC_SR_REG_OFST          (0x180)             /**< (HEFC_HECC_SR) HECC Status register Offset */
#define HEFC_HECC_IER_REG_OFST         (0x184)             /**< (HEFC_HECC_IER) HECC Interrupt Enable Register Offset */
#define HEFC_HECC_IDR_REG_OFST         (0x188)             /**< (HEFC_HECC_IDR) HECC Interrupt Disable Register Offset */
#define HEFC_HECC_IMR_REG_OFST         (0x18C)             /**< (HEFC_HECC_IMR) HECC Interrupt Mask Register Offset */
#define HEFC_HECC_FAILAR_REG_OFST      (0x190)             /**< (HEFC_HECC_FAILAR) HECC Fail address register Offset */
#define HEFC_GPNVM_MISC_REG_OFST       (0x00)              /**< (HEFC_GPNVM_MISC) HEFC GPNVM word miscellaneous Offset */
#define HEFC_GPNVM_RC_TRIM_REG_OFST    (0x04)              /**< (HEFC_GPNVM_RC_TRIM) HEFC GPNVM word RC trim (1..3) Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief HEFC register API structure */
typedef struct
{
  __IO  uint32_t                       HEFC_FMR;           /**< Offset: 0x00 (R/W  32) HEFC Flash Mode Register */
  __O   uint32_t                       HEFC_FCR;           /**< Offset: 0x04 ( /W  32) HEFC Flash Command Register */
  __I   uint32_t                       HEFC_FSR;           /**< Offset: 0x08 (R/   32) HEFC Flash Status Register */
  __I   uint32_t                       HEFC_FRR;           /**< Offset: 0x0C (R/   32) HEFC Flash Result Register */
  __I   uint8_t                        Reserved1[0x30];
  __IO  uint32_t                       HEFC_FPMR;          /**< Offset: 0x40 (R/W  32) HEFC Flash Power Management Register */
  __I   uint8_t                        Reserved2[0xA0];
  __IO  uint32_t                       HEFC_WPMR;          /**< Offset: 0xE4 (R/W  32) Write Protection Mode Register */
  __I   uint8_t                        Reserved3[0x18];
  __IO  uint32_t                       HEFC_HECC_CR0;      /**< Offset: 0x100 (R/W  32) HECC Control Register ChannelNumbers (ChannelNumbers = 0) 0 */
  __IO  uint32_t                       HEFC_HECC_CR1;      /**< Offset: 0x104 (R/W  32) HECC Control Register ChannelNumbers (ChannelNumbers = 0) 1 */
  __IO  uint32_t                       HEFC_HECC_CR2;      /**< Offset: 0x108 (R/W  32) HECC Control Register ChannelNumbers (ChannelNumbers = 0) 2 */
  __IO  uint32_t                       HEFC_HECC_CR3;      /**< Offset: 0x10C (R/W  32) HECC Control Register ChannelNumbers (ChannelNumbers = 0) 3 */
  __IO  uint32_t                       HEFC_HECC_CR4;      /**< Offset: 0x110 (R/W  32) HECC Control Register ChannelNumbers (ChannelNumbers = 0) 4 */
  __IO  uint32_t                       HEFC_HECC_CR5;      /**< Offset: 0x114 (R/W  32) HECC Control Register ChannelNumbers (ChannelNumbers = 0) 5 */
  __IO  uint32_t                       HEFC_HECC_CR6;      /**< Offset: 0x118 (R/W  32) HECC Control Register ChannelNumbers (ChannelNumbers = 0) 6 */
  __IO  uint32_t                       HEFC_HECC_CR7;      /**< Offset: 0x11C (R/W  32) HECC Control Register ChannelNumbers (ChannelNumbers = 0) 7 */
  __IO  uint32_t                       HEFC_HECC_CR8;      /**< Offset: 0x120 (R/W  32) HECC Control Register ChannelNumbers (ChannelNumbers = 0) 8 */
  __IO  uint32_t                       HEFC_HECC_CR9;      /**< Offset: 0x124 (R/W  32) HECC Control Register ChannelNumbers (ChannelNumbers = 0) 9 */
  __IO  uint32_t                       HEFC_HECC_CR10;     /**< Offset: 0x128 (R/W  32) HECC Control Register ChannelNumbers (ChannelNumbers = 0) 10 */
  __IO  uint32_t                       HEFC_HECC_CR11;     /**< Offset: 0x12C (R/W  32) HECC Control Register ChannelNumbers (ChannelNumbers = 0) 11 */
  __IO  uint32_t                       HEFC_HECC_CR12;     /**< Offset: 0x130 (R/W  32) HECC Control Register ChannelNumbers (ChannelNumbers = 0) 12 */
  __IO  uint32_t                       HEFC_HECC_CR13;     /**< Offset: 0x134 (R/W  32) HECC Control Register ChannelNumbers (ChannelNumbers = 0) 13 */
  __IO  uint32_t                       HEFC_HECC_CR14;     /**< Offset: 0x138 (R/W  32) HECC Control Register ChannelNumbers (ChannelNumbers = 0) 14 */
  __IO  uint32_t                       HEFC_HECC_CR15;     /**< Offset: 0x13C (R/W  32) HECC Control Register ChannelNumbers (ChannelNumbers = 0) 15 */
  __IO  uint32_t                       HEFC_HECC_TESTCB0;  /**< Offset: 0x140 (R/W  32) HECC Test mode ChannelNumbers (ChannelNumbers = 0) 0 */
  __IO  uint32_t                       HEFC_HECC_TESTCB1;  /**< Offset: 0x144 (R/W  32) HECC Test mode ChannelNumbers (ChannelNumbers = 0) 1 */
  __IO  uint32_t                       HEFC_HECC_TESTCB2;  /**< Offset: 0x148 (R/W  32) HECC Test mode ChannelNumbers (ChannelNumbers = 0) 2 */
  __IO  uint32_t                       HEFC_HECC_TESTCB3;  /**< Offset: 0x14C (R/W  32) HECC Test mode ChannelNumbers (ChannelNumbers = 0) 3 */
  __IO  uint32_t                       HEFC_HECC_TESTCB4;  /**< Offset: 0x150 (R/W  32) HECC Test mode ChannelNumbers (ChannelNumbers = 0) 4 */
  __IO  uint32_t                       HEFC_HECC_TESTCB5;  /**< Offset: 0x154 (R/W  32) HECC Test mode ChannelNumbers (ChannelNumbers = 0) 5 */
  __IO  uint32_t                       HEFC_HECC_TESTCB6;  /**< Offset: 0x158 (R/W  32) HECC Test mode ChannelNumbers (ChannelNumbers = 0) 6 */
  __IO  uint32_t                       HEFC_HECC_TESTCB7;  /**< Offset: 0x15C (R/W  32) HECC Test mode ChannelNumbers (ChannelNumbers = 0) 7 */
  __IO  uint32_t                       HEFC_HECC_TESTCB8;  /**< Offset: 0x160 (R/W  32) HECC Test mode ChannelNumbers (ChannelNumbers = 0) 8 */
  __IO  uint32_t                       HEFC_HECC_TESTCB9;  /**< Offset: 0x164 (R/W  32) HECC Test mode ChannelNumbers (ChannelNumbers = 0) 9 */
  __IO  uint32_t                       HEFC_HECC_TESTCB10; /**< Offset: 0x168 (R/W  32) HECC Test mode ChannelNumbers (ChannelNumbers = 0) 10 */
  __IO  uint32_t                       HEFC_HECC_TESTCB11; /**< Offset: 0x16C (R/W  32) HECC Test mode ChannelNumbers (ChannelNumbers = 0) 11 */
  __IO  uint32_t                       HEFC_HECC_TESTCB12; /**< Offset: 0x170 (R/W  32) HECC Test mode ChannelNumbers (ChannelNumbers = 0) 12 */
  __IO  uint32_t                       HEFC_HECC_TESTCB13; /**< Offset: 0x174 (R/W  32) HECC Test mode ChannelNumbers (ChannelNumbers = 0) 13 */
  __IO  uint32_t                       HEFC_HECC_TESTCB14; /**< Offset: 0x178 (R/W  32) HECC Test mode ChannelNumbers (ChannelNumbers = 0) 14 */
  __IO  uint32_t                       HEFC_HECC_TESTCB15; /**< Offset: 0x17C (R/W  32) HECC Test mode ChannelNumbers (ChannelNumbers = 0) 15 */
  __I   uint32_t                       HEFC_HECC_SR;       /**< Offset: 0x180 (R/   32) HECC Status register */
  __O   uint32_t                       HEFC_HECC_IER;      /**< Offset: 0x184 ( /W  32) HECC Interrupt Enable Register */
  __O   uint32_t                       HEFC_HECC_IDR;      /**< Offset: 0x188 ( /W  32) HECC Interrupt Disable Register */
  __I   uint32_t                       HEFC_HECC_IMR;      /**< Offset: 0x18C (R/   32) HECC Interrupt Mask Register */
  __I   uint32_t                       HEFC_HECC_FAILAR;   /**< Offset: 0x190 (R/   32) HECC Fail address register */
} hefc_registers_t;

/** \brief GPNVMBITS register API structure */
typedef struct
{  /* GPNVM Bits */
  __IO  uint32_t                       HEFC_GPNVM_MISC;    /**< Offset: 0x00 (R/W  32) HEFC GPNVM word miscellaneous */
  __IO  uint32_t                       HEFC_GPNVM_RC_TRIM[3]; /**< Offset: 0x04 (R/W  32) HEFC GPNVM word RC trim (1..3) */
} hefc_gpnvmbits_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _SAMRH71_HEFC_COMPONENT_H_ */
