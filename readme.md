# Microchip MPLAB® Harmony 3 Motor Control

MPLAB Harmony 3 is an extension of the MPLAB® ecosystem for creating
embedded firmware solutions for Microchip 32-bit SAM and PIC32 microcontroller
and microprocessor devices.  Refer to the following links for more information.
 - [Microchip 32-bit MCUs for Motor Control Applications](https://www.microchip.com/design-centers/motor-control-and-drive/control-products/32-bit-solutions)
 - [Microchip 32-bit MCUs](https://www.microchip.com/design-centers/32-bit)
 - [Microchip 32-bit MPUs](https://www.microchip.com/design-centers/32-bit-mpus)
 - [Microchip MPLAB X IDE](https://www.microchip.com/mplab/mplab-x-ide)
 - [Microchip MPLAB Harmony](https://www.microchip.com/mplab/mplab-harmony)
 - [Microchip MPLAB Harmony Pages](https://microchip-mplab-harmony.github.io/)

This repository contains the MPLAB® Harmony 3 Motor Control module.  This module
contains motor control demonstrations implemented on Microchip's 32-bit SAM and PIC32
microcontrollers. Users can use these demonstrations as a reference for
developing their own motor control applications on Microchip's SAM and PIC32 series of
microcontrollers using MPLAB Harmony 3. Refer to the following links for release
notes and licensing information.

 - [Release Notes](./release_notes.md)
 - [MPLAB Harmony License](mplab_harmony_license.md)

# Contents Summary

| Folder     | Description                                               |
|------------|-----------------------------------------------------------|
| apps       | Demonstration applications for Motor Control              |
| doc        | Demonstration user guide in .chm format                   |
| docs       | Demonstration user guide in HTML format                   |


# Complete list of Motor Control Demo Applications

**PIC32MK Device Family**

| Algorithm | Description |Control Board | Inverter Board |
| --- | --- | --- | --- |
| [pmsm_foc_encoder_pic32_mk](apps/pmsm_foc_encoder_pic32_mk)| Sensored Field Oriented Control of PMSM using Quadrature Encoder | [PIC32MK MCM Motor Control Plugin Module](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/MA320211)| <li>[dsPICDEM™ MCLV-2 Support](https://www.microchip.com/DevelopmentTools/ProductDetails/DM330021-2)</li>| 
|  [pmsm_foc_encoder_pic32_mk](apps/pmsm_foc_encoder_pic32_mk)| Sensored Field Oriented Control of PMSM using Quadrature Encoder | [PIC32MK Motor Control Plugin Module](https://www.microchip.com/Developmenttools/ProductDetails/MA320024)| <li>[dsPICDEM™ MCLV-2 Support](https://www.microchip.com/DevelopmentTools/ProductDetails/DM330021-2)</li> <li>[dsPICDEM™ MCHV-3 Support](https://www.microchip.com/developmenttools/ProductDetails/dm330023-3)</li>|
| [pmsm_foc_pll_estimator_pic32_mk](apps/pmsm_foc_pll_estimator_pic32_mk)| Sensorless Field Oriented Control of PMSM using PLL Estimator | [PIC32MK MCM Motor Control Plugin Module](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/MA320211)| <li>[dsPICDEM™ MCLV-2 Support](https://www.microchip.com/DevelopmentTools/ProductDetails/DM330021-2)</li>| 
| [pmsm_foc_pll_estimator_pic32_mk](apps/pmsm_foc_pll_estimator_pic32_mk)| Sensorless Field Oriented Control of PMSM using PLL Estimator| [PIC32MK Motor Control Plugin Module](https://www.microchip.com/Developmenttools/ProductDetails/MA320024)| <li>[dsPICDEM™ MCLV-2 Support](https://www.microchip.com/DevelopmentTools/ProductDetails/DM330021-2)</li> <li>[dsPICDEM™ MCHV-3 Support](https://www.microchip.com/developmenttools/ProductDetails/dm330023-3)</li>|


**PIC32CM MC 00 Device Family**

| Algorithm | Description |Control Board | Inverter Board |
| --- | --- | --- | --- |
|[pmsm_foc_rolo_pic32_cm_mc](apps/pmsm_foc_rolo_pic32_cm_mc)| Sensorless Field Oriented Control of PMSM using Reduced Order Luenberger Observer | PIC32CM MC 00 Motor Control Plugin Module|<li>[dsPICDEM™ MCLV-2 Support](https://www.microchip.com/DevelopmentTools/ProductDetails/DM330021-2)</li> <li>[dsPICDEM™ MCHV-3 Support](https://www.microchip.com/developmenttools/ProductDetails/dm330023-3)</li>|
| [acim_vhz_pic32_cm_mc](apps/acim_vhz_pic32_cm_mc)| Open Loop V/F Control of AC Induction Motor | PIC32CM MC 00 Motor Control Plugin Module| <li>[dsPICDEM™ MCHV-3 Support](https://www.microchip.com/developmenttools/ProductDetails/dm330023-3)</li> |
| [bldc_bc_hall_pic32_cm_mc](apps/bldc_bc_hall_pic32_cm_mc)| Block Commutation based control of BLDC motor using Hall Sensors | PIC32CM MC 00 Motor Control Plugin Module|<li>[dsPICDEM™ MCLV-2 Support](https://www.microchip.com/DevelopmentTools/ProductDetails/DM330021-2)</li>|


**SAM C2x Device Family**

| Algorithm | Description |Control Board | Inverter Board |
| --- | --- | --- | --- |
| [acim_vhz_sam_c21](apps/acim_vhz_sam_c21)| Open Loop V/F Control of AC Induction Motor | [ATSAMC21 Motor Control Plugin Module](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/MA320206)   | <li>[dsPICDEM™ MCHV-3 Support](https://www.microchip.com/developmenttools/ProductDetails/dm330023-3)</li> | 
| [bldc_bc_hall_sam_c21](apps/bldc_bc_hall_sam_c21)| Block Commutation based control of BLDC motor using Hall Sensors | [ATSAMC21 Motor Control Plugin Module](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/MA320206)   | <li>[dsPICDEM™ MCLV-2 Support](https://www.microchip.com/DevelopmentTools/ProductDetails/DM330021-2)</li> |
|[pmsm_foc_rolo_1shunt](apps/pmsm_foc_rolo_1shunt)| Sensorless Field Oriented Control of PMSM using Reduced Order Luenberger Observer with Single Shunt Current Sense | [ATSAMC21 Motor Control Plugin Module](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/MA320206)|<li>[dsPICDEM™ MCLV-2 Support](https://www.microchip.com/DevelopmentTools/ProductDetails/DM330021-2)</li> |
|[pmsm_foc_rolo_fw_mtpa_sam_c21](apps/pmsm_foc_rolo_fw_mtpa_sam_c21) | Sensorless Field Oriented Control of PMSM using Reduced Order Luenberger Observer with Field Weakening and MTPA Capability | [ATSAMC21 Motor Control Plugin Module](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/MA320206)  |<li>[dsPICDEM™ MCLV-2 Support](https://www.microchip.com/DevelopmentTools/ProductDetails/DM330021-2)</li>|
|[pmsm_foc_rolo_sam_c21](apps/pmsm_foc_rolo_sam_c21) | Sensorless Field Oriented Control of PMSM using Reduced Order Luenberger Observer | [ATSAMC21 Motor Control Plugin Module](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/MA320206)   |<li>[dsPICDEM™ MCLV-2 Support](https://www.microchip.com/DevelopmentTools/ProductDetails/DM330021-2)</li> <li>[dsPICDEM™ MCHV-3 Support](https://www.microchip.com/developmenttools/ProductDetails/dm330023-3)</li>|
| [pmsm_foc_rolo_wm_sam_c21](apps/pmsm_foc_rolo_wm_sam_c21) | Sensorless Field Oriented Control of PMSM using Reduced Order Luenberger Observer with Windmilling Capability | [ATSAMC21 Motor Control Plugin Module](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/MA320206)   | <li>[dsPICDEM™ MCLV-2 Support](https://www.microchip.com/DevelopmentTools/ProductDetails/DM330021-2)</li> <li>[dsPICDEM™ MCHV-3 Support](https://www.microchip.com/developmenttools/ProductDetails/dm330023-3)</li>|


**SAM D/E5x Device Family**

| Algorithm | Description |Control Board | Inverter Board |
| --- | --- | --- | --- |
| [pmsm_foc_encoder_position_sam_e54](apps/pmsm_foc_encoder_position_sam_e54)| FOC based Position Control of PMSM  using Quadrature Encoder | [ATSAME54 Motor Control Plugin Module](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/MA320207)   |<li>[dsPICDEM™ MCLV-2 Support](https://www.microchip.com/DevelopmentTools/ProductDetails/DM330021-2)</li> <li>[dsPICDEM™ MCHV-3 Support](https://www.microchip.com/developmenttools/ProductDetails/dm330023-3)</li>|
| [pmsm_foc_encoder_sam_e54](apps/pmsm_foc_encoder_sam_e54)| Sensored Field Oriented Control of PMSM using Quadrature Encoder | [ATSAME54 Motor Control Plugin Module](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/MA320207)   |<li>[dsPICDEM™ MCLV-2 Support](https://www.microchip.com/DevelopmentTools/ProductDetails/DM330021-2)</li> <li>[dsPICDEM™ MCHV-3 Support](https://www.microchip.com/developmenttools/ProductDetails/dm330023-3)</li>|
| [pmsm_foc_pll_estimator_sam_e54](apps/pmsm_foc_pll_estimator_sam_e54)|Sensorless Field Oriented Control of PMSM using PLL Estimator | [ATSAME54 Motor Control Plugin Module](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/MA320207)   |<li>[dsPICDEM™ MCLV-2 Support](https://www.microchip.com/DevelopmentTools/ProductDetails/DM330021-2)</li> <li>[dsPICDEM™ MCHV-3 Support](https://www.microchip.com/developmenttools/ProductDetails/dm330023-3)</li>|


**SAM E7x Device Family**

| Algorithm | Description |Control Board | Inverter Board |
| --- | --- | --- | --- |
|[pmsm_foc_encoder_sam_e70](apps/pmsm_foc_encoder_sam_e70) |  Sensored Field Oriented Control of PMSM using Quadrature Encoder  | [ATSAME70 Motor Control Plugin Module](https://www.microchip.com/Developmenttools/ProductDetails/MA320203)   |<li>[dsPICDEM™ MCLV-2 Support](https://www.microchip.com/DevelopmentTools/ProductDetails/DM330021-2)</li> <li>[dsPICDEM™ MCHV-3 Support](https://www.microchip.com/developmenttools/ProductDetails/dm330023-3)</li>|
| [pmsm_foc_pll_estimator_sam_e70](apps/pmsm_foc_pll_estimator_sam_e70)| Sensorless Field Oriented Control of PMSM using PLL Estimator | [ATSAME70 Motor Control Plugin Module](https://www.microchip.com/Developmenttools/ProductDetails/MA320203)   |<li>[dsPICDEM™ MCLV-2 Support](https://www.microchip.com/DevelopmentTools/ProductDetails/DM330021-2)</li> <li>[dsPICDEM™ MCHV-3 Support](https://www.microchip.com/developmenttools/ProductDetails/dm330023-3)</li>|
| [pmsm_foc_smo_sam_e70](apps/pmsm_foc_smo_sam_e70)| Sensorless Field Oriented Control of PMSM using Sliding Mode Observer | [ATSAME70 Motor Control Plugin Module](https://www.microchip.com/Developmenttools/ProductDetails/MA320203)   |<li>[dsPICDEM™ MCLV-2 Support](https://www.microchip.com/DevelopmentTools/ProductDetails/DM330021-2)</li>|  
| [pmsm_pfc_foc_pll_estimator_sam_e70](apps/pmsm_pfc_foc_pll_estimator_sam_e70)| PFC and Sensorless Field Oriented Control of PMSM using PLL Estimator | [ATSAME70 Motor Control Plugin Module](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/MA320203)   |<li>[dsPICDEM™ MCHV-3 Support](https://www.microchip.com/developmenttools/ProductDetails/dm330023-3)</li>|


**SAM RH71 Device Family**

| Algorithm | Description |Control Board | Inverter Board |
| --- | --- | --- | --- |
|[pmsm_foc_encoder_lx7720_sam_rh71_ek](apps/pmsm_foc_encoder_lx7720_sam_rh71_ek)  | Sensored Field Oriented Control of PMSM using SAMRH71 MCU and LX7720 Motor Driver and Position decoder | [SAMRH71F20-EK Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/SAMRH71F20-EK) |<li>  [LX7720 Daughter Board](https://www.microsemi.com/product-directory/space-system-managers/3708-position-motor-controller-ic#resources) </li> |



____

[![License](https://img.shields.io/badge/license-Harmony%20license-orange.svg)](https://github.com/Microchip-MPLAB-Harmony/mc/blob/master/mplab_harmony_license.md)
[![Latest release](https://img.shields.io/github/release/Microchip-MPLAB-Harmony/mc.svg)](https://github.com/Microchip-MPLAB-Harmony/mc/releases/latest)
[![Latest release date](https://img.shields.io/github/release-date/Microchip-MPLAB-Harmony/mc.svg)](https://github.com/Microchip-MPLAB-Harmony/mc/releases/latest)
[![Commit activity](https://img.shields.io/github/commit-activity/y/Microchip-MPLAB-Harmony/mc.svg)](https://github.com/Microchip-MPLAB-Harmony/mc/graphs/commit-activity)
[![Contributors](https://img.shields.io/github/contributors-anon/Microchip-MPLAB-Harmony/mc.svg)]()
____

[![Follow us on Youtube](https://img.shields.io/badge/Youtube-Follow%20us%20on%20Youtube-red.svg)](https://www.youtube.com/user/MicrochipTechnology)
[![Follow us on LinkedIn](https://img.shields.io/badge/LinkedIn-Follow%20us%20on%20LinkedIn-blue.svg)](https://www.linkedin.com/company/microchip-technology)
[![Follow us on Facebook](https://img.shields.io/badge/Facebook-Follow%20us%20on%20Facebook-blue.svg)](https://www.facebook.com/microchiptechnology/)
[![Follow us on Twitter](https://img.shields.io/twitter/follow/MicrochipTech.svg?style=social)](https://twitter.com/MicrochipTech)

[![](https://img.shields.io/github/stars/Microchip-MPLAB-Harmony/mc.svg?style=social)]()
[![](https://img.shields.io/github/watchers/Microchip-MPLAB-Harmony/mc.svg?style=social)]()
