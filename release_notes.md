---
title: Release notes
nav_order: 99
has_children: true
---

![Microchip logo](https://raw.githubusercontent.com/wiki/Microchip-MPLAB-Harmony/Microchip-MPLAB-Harmony.github.io/images/microchip_logo.png)
![Harmony logo small](https://raw.githubusercontent.com/wiki/Microchip-MPLAB-Harmony/Microchip-MPLAB-Harmony.github.io/images/microchip_mplab_harmony_logo_small.png)

# Microchip MPLAB Harmony 3 Release Notes

## Motor Control Release v3.10.0

### New Features
* Adding SMO, Overmodulation, and MTPA support in QSpin.
* Adding ZS/MT Hybrid demo project for SAME54, PIC32MK MCF and PIC32MK MCM
* MISRA-C Compliance for motor control application files

### Known Issues
* None

### Required MPLAB Harmony v3 Modules
* csp v3.17.0
* bsp v3.16.1
* x2c v1.4.0
* harmony-services v1.3.1

### Development Tools
* [MPLAB X IDE v6.10](https://www.microchip.com/mplab/mplab-x-ide)
* [MPLAB XC32 C/C++ Compiler v4.30](https://www.microchip.com/mplab/compilers)
* MPLAB X IDE plug-ins:
  * MPLAB Code Configurator (MCC) v5.3.7
  * X2CScope v1.3.3.
    
## Motor Control Release v3.9.0

### New Features
* Motor Control Plant Manager is renamed as **QSpin Motor Control Configuration**
* Added QSpin support for PMSM_FOC_Component for PIC32MK MCA devices
* Added QSpin support for MCHV3 development board

### Known Issues
* None

### Required MPLAB Harmony v3 Modules
* csp v3.13.1
* bsp v3.14.0
* x2c v1.3.0
* dev_packs v3.13.1
* mcc H3 Library v1.1.5

### Development Tools
* [MPLAB X IDE v6.00](https://www.microchip.com/mplab/mplab-x-ide)
* [MPLAB XC32 C/C++ Compiler v4.10](https://www.microchip.com/mplab/compilers)
* MPLAB X IDE plug-ins:
  * MPLAB Code Configurator (MCC) v5.1.17
  * X2CScope v1.3.3.
  

## Motor Control Release v3.8.1

### Bug fixes
* Fix Package Plugin path ( Apple Mac issue )

### Known Issues
* same as v3.8.0

### Required MPLAB Harmony v3 Modules
* csp v3.11.0
* bsp v3.11.1
* x2c v1.2.0
* dev_packs v3.11.0
* mcc v1.1.0

### Development Tools
* [MPLAB X IDE v6.00](https://www.microchip.com/mplab/mplab-x-ide)
* [MPLAB XC32 C/C++ Compiler v4.00](https://www.microchip.com/mplab/compilers)
* MPLAB X IDE plug-ins:
  * MPLAB Code Configurator (MCC) v5.1.2
  * X2CScope v1.3.0.
  
  
## Motor Control Release v3.8.0

### New Features
* Added **Motor Control Plant** support for PMSM_FOC_Component for SAM E70, SAM E54 and PIC32MK devices

### Known Issues
* same as v3.7.0

### Required MPLAB Harmony v3 Modules
* csp v3.11.0
* bsp v3.11.1
* x2c v1.2.0
* dev_packs v3.11.0
* mcc v1.1.0

### Development Tools
* [MPLAB X IDE v6.00](https://www.microchip.com/mplab/mplab-x-ide)
* [MPLAB XC32 C/C++ Compiler v4.00](https://www.microchip.com/mplab/compilers)
* MPLAB X IDE plug-ins:
  * MPLAB Code Configurator (MCC) v5.1.2
  * X2CScope v1.3.0.

## Motor Control Release v3.7.0

### New Features
* SAMC2x and PIC32CM MC device support - Added Reduced Order Leuemberger Observer on SAMC21 and PIC32CM MC devices in PMSM_FOC component. 
* Added open loop support in encoder based FOC
* Supported user input for speed reference and current reference

### Known Issues
* In pmsm_foc_encoder_pic32_mk projects, overcurrent fault occurs at higher speeds in reverse direction with field weakening mode enabled.

* Isolated EDBG Card 

  * If programming failure occurs with message "java.lang.RuntimeException:RDDI_DAP_OPERATION_FAILED", then reset the Isolated EDBG Card's configuration by Go to File -> Project Properties -> EDBG -> Reset 

  * Programming or debugging PIC32CM, SAM C/D2x or SAM D/E5x MCU, using Isolated EDBG Card (board revision #02-10824-R1) on dsPICDEM™ MCHV-3 High Voltage Development Board may inhibit MCU from executing instructions if the MCU is reset by pressing on board 'Reset' switch or power cycling the board. Refer to the [Isolated EDBG Debugger Product Change Notice](https://www.microchip.com/DevelopmentTools/ProductDetails/AC320202) for details of hardware modification needed to resolve this issue.

* pmsm_foc_encoder_<device_family> applications running on dsPICDEM MCHV-3 requires increasing bandwidth of the quadrature encoder signal filter to maintain signal integrity of quadrature sensor signals at higher motor speeds. Without these modifications, motor operation may fail at higher speeds.
  * Reduce the capacitance value of C25, C26 and C27 from 100pF to 10pF 50V NPO 0805

### Required MPLAB Harmony v3 Modules
* csp v3.9.1
* x2c v1.1.4
* dev_packs v3.9.0
* mhc v3.8.0

### Development Tools
* [MPLAB X IDE v5.50](https://www.microchip.com/mplab/mplab-x-ide)
* [MPLAB XC32 C/C++ Compiler v3.01](https://www.microchip.com/mplab/compilers)
* MPLAB X IDE plug-ins:
  * MPLAB Harmony Configurator (MHC) v3.6.4.
  * X2CScope v1.3.0.


## Motor Control Release v3.6.1

### Bug Fixes
* Fixed issues to support XC32 compiler v3.00

### Known Issues
- Same as v3.6.0

### Development Tools
* [MPLAB X IDE v5.45](https://www.microchip.com/mplab/mplab-x-ide)
* [MPLAB XC32 C/C++ Compiler v3.00](https://www.microchip.com/mplab/compilers)
* MPLAB X IDE plug-ins:
  * MPLAB Harmony Configurator (MHC) v3.6.2.
  * X2CScope v1.3.0.

## Motor Control Release v3.6.0

* PMSM_FOC Component

    Following features were added to PMSM_FOC component

  - SAME5x device support
  - [dsPICDEM MCHV-3 board support](https://www.microchip.com/developmenttools/ProductDetails/dm330023-3)
  - Flying Start support

* Application Examples

  All motor control application examples were moved to [product family specific motor control apps repositories](apps/readme.md).

### Required MPLAB Harmony v3 Modules
* csp v3.8.3
* x2c v1.1.3
* dev_packs v3.8.0
* mhc v3.6.5

### Known Issues

* ATSAME54 Motor Control Plugin Module based demos may see noise coupling on the ADC channels resulting in motor instability/stall.
  * This issue can be resolved by ensuring that R1 (0 ohm) resistor is populated.


* Isolated EDBG Card 

  * If programming failure occurs with message "java.lang.RuntimeException:RDDI_DAP_OPERATION_FAILED", then reset the Isolated EDBG Card's configuration by Go to File -> Project Properties -> EDBG -> Reset 

  * Programming or debugging PIC32CM, SAM C/D2x or SAM D/E5x MCU, using Isolated EDBG Card (board revision #02-10824-R1) on dsPICDEM™ MCHV-3 High Voltage Development Board may inhibit MCU from executing instructions if the MCU is reset by pressing on board 'Reset' switch or power cycling the board. Refer to the [Isolated EDBG Debugger Product Change Notice](https://www.microchip.com/DevelopmentTools/ProductDetails/AC320202) for details of hardware modification needed to resolve this issue.

* pmsm_foc_encoder_<device_family> applications running on dsPICDEM MCHV-3 requires increasing bandwidth of the quadrature encoder signal filter to maintain signal integrity of quadrature sensor signals at higher motor speeds. Without these modifications, motor operation may fail at higher speeds.
  * Reduce the capacitance value of C25, C26 and C27 from 100pF to 10pF 50V NPO 0805
* pmsm_foc_rolo_1shunt may experience false over-current faults during alternate motor start command when operated in "TORQUE_MODE". Workaround - Reset the MCU before re-starting the motor in "TORQUE_MODE".
* For any demos running on ATSAMC21 Motor Control PIM, if any failures are observed while trying to use X2CScope, these failures may occur due to shortage of CPU computation bandwidth. In such cases, enable "RAM_EXECUTE" mode which speeds up execution by executing certain functions from RAM memory instead of Flash memory.


### Development Tools

* [MPLAB X IDE v5.45](https://www.microchip.com/mplab/mplab-x-ide)
* [MPLAB XC32 C/C++ Compiler v2.50](https://www.microchip.com/mplab/compilers)
* MPLAB X IDE plug-ins:
  * MPLAB Harmony Configurator (MHC) v3.6.2.
  * X2CScope v1.3.0.

## Motor Control Release v3.5.1


### New Applications

- The following table provides the list of algorithms added in this release.

| Algorithm | Description |Control Board | Inverter Board |
| --- | --- | --- | --- |
|[pmsm_foc_rolo_pic32_cm_mc](apps/pmsm_foc_rolo_pic32_cm_mc)| Sensorless Field Oriented Control of PMSM using Reduced Order Luenberger Observer | PIC32CM MC 00 Motor Control Plugin Module|<li>[dsPICDEM™ MCLV-2 Support](https://www.microchip.com/DevelopmentTools/ProductDetails/DM330021-2)</li> <li>[dsPICDEM™ MCHV-3 Support](https://www.microchip.com/developmenttools/ProductDetails/dm330023-3)</li>|
| [acim_vhz_pic32_cm_mc](apps/acim_vhz_pic32_cm_mc)| Open Loop V/F Control of AC Induction Motor | PIC32CM MC 00 Motor Control Plugin Module| <li>[dsPICDEM™ MCHV-3 Support](https://www.microchip.com/developmenttools/ProductDetails/dm330023-3)</li> |
| [bldc_bc_hall_pic32_cm_mc](apps/bldc_bc_hall_pic32_cm_mc)| Block Commutation based control of BLDC motor using Hall Sensors | PIC32CM MC 00 Motor Control Plugin Module|<li>[dsPICDEM™ MCLV-2 Support](https://www.microchip.com/DevelopmentTools/ProductDetails/DM330021-2)</li>|

### Updated Applications

| Application | Description | Control Board | Inverter Board| Revision History  |
| --- | --- | --- | --- | --- |
| [pmsm_foc_encoder_lx7720_sam_rh71_ek](apps/pmsm_foc_encoder_lx7720_sam_rh71_ek) | Sensored Field Oriented Control of PMSM using SAMRH71 MCU and LX7720 Motor Driver and Position decoder | [SAMRH71F20-EK Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/SAMRH71F20-EK) | [LX7720 Daughter Board](https://www.microsemi.com/product-directory/space-system-managers/3708-position-motor-controller-ic#resources) | <li> Regenerated demo applications using csp v3.8.1 </li><li>Added reverse direction capability</li><li> Optimized Speed Controller response </li>


### Required MPLAB Harmony v3 Modules
* csp v3.8.1
* x2c v1.1.2
* dev_packs v3.8.0
* mhc v3.5.1

### Known Issues

* Isolated EDBG Card 
  * This board is not supported in MPLABX v5.40. We recommend using [MPLABX v5.45 or above](https://www.microchip.com/mplab/mplab-x-ide) for programming/debugging any PIC32CM_MC, SAM C/D2x, SAM D/E5x and SAM E/V/S7x applications dsPICDEM™ MCHV-3 High Voltage Development Board

  * If programming failure occurs with message "java.lang.RuntimeException:RDDI_DAP_OPERATION_FAILED", then reset the Isolated EDBG Card's configuration by Go to File -> Project Properties -> EDBG -> Reset 

  * Programming or debugging PIC32CM, SAM C/D2x or SAM D/E5x MCU, using Isolated EDBG Card (board revision #02-10824-R1) on dsPICDEM™ MCHV-3 High Voltage Development Board may inhibit MCU from executing instructions if the MCU is reset by pressing on board 'Reset' switch or power cycling the board. Refer to the [Isolated EDBG Debugger Product Change Notice](https://www.microchip.com/DevelopmentTools/ProductDetails/AC320202) for details of hardware modification needed to resolve this issue.

* pmsm_foc_encoder_<device_family> applications running on dsPICDEM MCHV-3 requires increasing bandwidth of the quadrature encoder signal filter to maintain signal integrity of quadrature sensor signals at higher motor speeds. Without these modifications, motor operation may fail at higher speeds.
  * Reduce the capacitance value of C25, C26 and C27 from 100pF to 10pF 50V NPO 0805
* pmsm_foc_rolo_1shunt may experience false over-current faults during alternate motor start command when operated in "TORQUE_MODE". Workaround - Reset the MCU before re-starting the motor in "TORQUE_MODE".
* For any demos running on ATSAMC21 Motor Control PIM, if any failures are observed while trying to use X2CScope, these failures may occur due to shortage of CPU computation bandwidth. In such cases, enable "RAM_EXECUTE" mode which speeds up execution by executing certain functions from RAM memory instead of Flash memory.


### Development Tools

* [MPLAB X IDE v5.45](https://www.microchip.com/mplab/mplab-x-ide)
* [MPLAB XC32 C/C++ Compiler v2.41](https://www.microchip.com/mplab/compilers)
* MPLAB X IDE plug-ins:
  * MPLAB Harmony Configurator (MHC) v3.6.0.
  * X2CScope v1.3.0.

## Motor Control Release v3.5.0

### New Features


 | Feature | Description | Supported Device Family |
 | --- | --- | ---|
 | PMSM_FOC Component | An application library for Field Oriented Control (FOC) of Permanent Magnet Synchronous Motors (PMSM). This library can be configured using MPLAB Harmony Configurator (MHC) to auto-generate a fully functional application code which can drive a permanent magnet synchronous motor. | PIC32MK, SAME7x|
 

### New Applications

- The following table provides the list of algorithms added in this release.

| Algorithm | Description |Control Board | Inverter Board |
| --- | --- | --- | --- | 
| pmsm_foc_encoder_pic32_mk| Sensored Field Oriented Control of PMSM using Quadrature Encoder | PIC32MK MCM Motor Control Plugin Module|[dsPICDEM™ MCLV-2 Support](https://www.microchip.com/DevelopmentTools/ProductDetails/DM330021-2)| 
| pmsm_foc_pll_estimator_pic32_mk| Sensorless Field Oriented Control of PMSM using PLL Estimator | PIC32MK MCM Motor Control Plugin Module| [dsPICDEM™ MCLV-2 Support](https://www.microchip.com/DevelopmentTools/ProductDetails/DM330021-2)|
| pmsm_foc_encoder_lx7720_sam_rh71_ek | Sensored Field Oriented Control of PMSM using SAMRH71 MCU and LX7720 Motor Driver and Position decoder | [SAMRH71F20-EK Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/SAMRH71F20-EK) | [LX7720 Daughter Board](https://www.microsemi.com/product-directory/space-system-managers/3708-position-motor-controller-ic#resources)|


### Updated Applications

- All demo applications were regenerated using csp v3.7.1
- Following table lists the applications which are updated beyond regeneration using csp v3.7.1.

| Application | Description | Control Board | Inverter Board| Revision History  |
| --- | --- | --- | --- | --- |
| pmsm_foc_encoder_pic32_mk| Sensored Field Oriented Control of PMSM using Quadrature Encoder | [PIC32MK Motor Control Plugin Module](https://www.microchip.com/Developmenttools/ProductDetails/MA320024)   |<li>[dsPICDEM™ MCLV-2 Support](https://www.microchip.com/DevelopmentTools/ProductDetails/DM330021-2)</li>| <li> Regenerated low voltage demo (MCLV2) using PMSM_FOC component</li>|
| pmsm_foc_pll_estimator_pic32_mk| Sensorless Field Oriented Control of PMSM using PLL Estimator | [PIC32MK Motor Control Plugin Module](https://www.microchip.com/Developmenttools/ProductDetails/MA320024)   |<li>[dsPICDEM™ MCLV-2 Support](https://www.microchip.com/DevelopmentTools/ProductDetails/DM330021-2)</li>| <li> Regenerated low voltage demo (MCLV2) using PMSM_FOC component</li> |<li> Regenerated low voltage demo (MCLV2) using PMSM_FOC component</li>|
| pmsm_foc_encoder_sam_e70| Sensored Field Oriented Control of PMSM using Quadrature Encoder | [ATSAME70 Motor Control Plugin Module](https://www.microchip.com/Developmenttools/ProductDetails/MA320203)  |<li>[dsPICDEM™ MCLV-2 Support](https://www.microchip.com/DevelopmentTools/ProductDetails/DM330021-2)</li>| <li> Regenerated low voltage demo (MCLV2) using PMSM_FOC component</li>|
| pmsm_foc_pll_estimator_sam_e70| Sensorless Field Oriented Control of PMSM using PLL Estimator | [ATSAME70 Motor Control Plugin Module](https://www.microchip.com/Developmenttools/ProductDetails/MA320203)   |<li>[dsPICDEM™ MCLV-2 Support](https://www.microchip.com/DevelopmentTools/ProductDetails/DM330021-2)</li>| <li> Regenerated low voltage demo (MCLV2) using PMSM_FOC component</li> |<li> Regenerated low voltage demo (MCLV2) using PMSM_FOC component</li>|
|pmsm_foc_rolo_sam_c21| Sensorless Field Oriented Control of PMSM using Reduced Order Luenberger Observer | [ATSAMC21 Motor Control Plugin Module](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/MA320206)| <li>[dsPICDEM™ MCLV-2 Support](https://www.microchip.com/DevelopmentTools/ProductDetails/DM330021-2)</li> <li>[dsPICDEM™ MCHV-3 Support](https://www.microchip.com/developmenttools/ProductDetails/dm330023-3)</li>| <li> Implemented bug fix to use the most recent phase current measurement for current control </li><li> Implemented bug fix in integral saturation logic (upper limit) of the PI compensator </li>|
| pmsm_foc_rolo_wm_sam_c21| Sensorless Field Oriented Control of PMSM using Reduced Order Luenberger Observer with Windmilling Capability | [ATSAMC21 Motor Control Plugin Module](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/MA320206)| <li>[dsPICDEM™ MCLV-2 Support](https://www.microchip.com/DevelopmentTools/ProductDetails/DM330021-2)</li> <li>[dsPICDEM™ MCHV-3 Support](https://www.microchip.com/developmenttools/ProductDetails/dm330023-3)</li>|  <li> Implemented bug fix to use the most recent phase current measurement for current control </li><li> Implemented bug fix in integral saturation logic (upper limit) of the PI compensator </li>|
|pmsm_foc_rolo_fw_mtpa_sam_c21|  Sensorless Field Oriented Control of PMSM using Reduced Order Luenberger Observer with Field Weakening and MTPA Capability| [ATSAMC21 Motor Control Plugin Module](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/MA320206)| <li>[dsPICDEM™ MCLV-2 Support](https://www.microchip.com/DevelopmentTools/ProductDetails/DM330021-2)</li>|  <li> Implemented bug fix to use the most recent phase current measurement for current control </li><li> Implemented bug fix in integral saturation logic (upper limit) of the PI compensator </li>|
| acim_vhz_sam_c21| Open Loop V/F Control of AC Induction Motor | [ATSAMC21 Motor Control Plugin Module](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/MA320206)   | <li>[dsPICDEM™ MCHV-3 Support](https://www.microchip.com/developmenttools/ProductDetails/dm330023-3)</li> | <li> Implemented bug fix in integral saturation logic (upper limit) of the PI compensator </li>|
|pmsm_foc_rolo_1shunt| Sensorless Field Oriented Control of PMSM using Reduced Order Luenberger Observer with Single Shunt Current Sense | [ATSAMC21 Motor Control Plugin Module](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/MA320206)|<li>[dsPICDEM™ MCLV-2 Support](https://www.microchip.com/DevelopmentTools/ProductDetails/DM330021-2)</li> | <li> Implemented bug fix in integral saturation logic (upper limit) of the PI compensator </li>







### Required MPLAB Harmony v3 Modules
* csp v3.7.1
* x2c v1.0.1
* dev_packs v3.7.0
* mhc v3.5.0

### Known Issues

* Isolated EDBG Card (board revision #02-10824-R1) is not supported in MPLABX v5.40. We recommend using [MPLABX v5.35](https://www.microchip.com/development-tools/pic-and-dspic-downloads-archive) for programming/debugging any SAM C/D2x, SAM D/E5x and SAM E/V/S7x applications dsPICDEM™ MCHV-3 High Voltage Development Board
* MPLAB X IDE v5.35 fails to program ATSAME70 Motor Control Plugin Module on dsPICDEM™ MCHV-3
High Voltage Development Board. In order to resolve this issue, implement the following change in dap_cortex-m7.py, located at C:\Program Files (x86)\Microchip\MPLABX\v5.35\packs\Microchip\SAME70_DFP\4.2.59\scripts\

  * Goto line # 2, replace <span style="color:red; font-family:courier" >“comm_speed=8000000” </span>  with <span style="color:green; font-family:courier">“comm_speed=2000000” </span>

* Programming or debugging SAM C/D2x or SAM D/E5x MCU, using Isolated EDBG Card (board revision #02-10824-R1) on dsPICDEM™ MCHV-3 High Voltage Development Board may inhibit MCU from executing instructions if the MCU is reset by pressing on board 'Reset' switch or power cycling the board. Refer to the [Isolated EDBG Debugger Product Change Notice](https://www.microchip.com/DevelopmentTools/ProductDetails/AC320202) for details of hardware modification needed to resolve this issue.

* pmsm_foc_encoder_<device_family> applications running on dsPICDEM MCHV-3 requires increasing bandwidth of the quadrature encoder signal filter to maintain signal integrity of quadrature sensor signals at higher motor speeds. Without these modifications, motor operation may fail at higher speeds.
  * Reduce the capacitance value of C25, C26 and C27 from 100pF to 10pF 50V NPO 0805
* pmsm_foc_rolo_1shunt may experience false over-current faults during alternate motor start command when operated in "TORQUE_MODE". Workaround - Reset the MCU before re-starting the motor in "TORQUE_MODE".
* For any demos running on ATSAMC21 Motor Control PIM, if any failures are observed while trying to use X2CScope, these failures may occur due to shortage of CPU computation bandwidth. In such cases, enable "RAM_EXECUTE" mode which speeds up execution by executing certain functions from RAM memory instead of Flash memory.


### Development Tools

* [MPLAB X IDE v5.40](https://www.microchip.com/mplab/mplab-x-ide)
* [MPLAB XC32 C/C++ Compiler v2.41](https://www.microchip.com/mplab/compilers)
* MPLAB X IDE plug-ins:
  * MPLAB Harmony Configurator (MHC) v3.5.0.
  * X2CScope v1.3.0.

## Motor Control Release v3.4.1

### Updated Applications

- The following table provides the list of applications updated in this release.

| Application | Description | Supported Plug In Module | dsPICDEM™ MCHV-3 Support | dsPICDEM™ MCLV-2 Support  | Revision History  |
| --- | --- | --- | --- | --- | --- |
| pmsm_foc_encoder_pic32_mk| Sensored Field Oriented Control of PMSM using Quadrature Encoder | [PIC32MK Motor Control Plugin Module](https://www.microchip.com/Developmenttools/ProductDetails/MA320024)   | Yes | Yes | <li> PWM to Control Frequency was made 1:1 in Low Voltage Demo (MCLV-2) </li><li> Added High Voltage Support (MCHV-3)</li>|
| pmsm_foc_pll_estimator_pic32_mk| Sensorless Field Oriented Control of PMSM using PLL Estimator | [PIC32MK Motor Control Plugin Module](https://www.microchip.com/Developmenttools/ProductDetails/MA320024)   | No | Yes | Added High Voltage Support (MCHV-3)|


### Required MPLAB Harmony v3 Modules
* csp v3.5.0
* dev_packs v3.5.0
* mhc v3.3.0

### Known Issues

* Programming or debugging SAM C/D2x or SAM D/E5x MCU, using Isolated EDBG Card (board revision #02-10824-R1) on dsPICDEM™ MCHV-3 High Voltage Development Board may inhibit MCU from executing instructions if the MCU is reset by pressing on board 'Reset' switch or power cycling the board. Refer to the [Isolated EDBG Debugger Product Change Notice](https://www.microchip.com/DevelopmentTools/ProductDetails/AC320202) for details of hardware modification needed to resolve this issue.
* pmsm_foc_rolo_1shunt may experience false over-current faults during alternate motor start command when operated in "TORQUE_MODE". Workaround - Reset the MCU before re-starting the motor in "TORQUE_MODE".
* For any demos running on ATSAMC21 Motor Control PIM, if any failures are observed while trying to use X2CScope, these failures may occur due to shortage of CPU computation bandwidth. In such cases, kindly enable "RAM_EXECUTE" mode which speeds up execution by executing certain functions from RAM memory instead of Flash memory



### Development Tools

* [MPLAB X IDE v5.25](https://www.microchip.com/mplab/mplab-x-ide)
* [MPLAB XC32 C/C++ Compiler v2.30](https://www.microchip.com/mplab/compilers)
* MPLAB X IDE plug-ins:
  * MPLAB Harmony Configurator (MHC) v3.3.0.
  * X2CScope v1.2.3.

## Motor Control Release v3.4.0

### New Algorithms

- The following table provides the list of algorithms added in this release.

| Algorithm | Description | Supported Plug In Module | dsPICDEM™ MCHV-3 Support | dsPICDEM™ MCLV-2 Support  |
| --- | --- | --- | --- | --- |
| pmsm_foc_encoder_pic32_mk| Sensored Field Oriented Control of PMSM using Quadrature Encoder | [PIC32MK Motor Control Plugin Module](https://www.microchip.com/Developmenttools/ProductDetails/MA320024)   | No | Yes |
| pmsm_foc_pll_estimator_pic32_mk| Sensorless Field Oriented Control of PMSM using PLL Estimator | [PIC32MK Motor Control Plugin Module](https://www.microchip.com/Developmenttools/ProductDetails/MA320024)   | No | Yes |
| pmsm_foc_smo_sam_e70| Sensorless Field Oriented Control of PMSM using Sliding Mode Observer | [ATSAME70 Motor Control Plugin Module](https://www.microchip.com/Developmenttools/ProductDetails/MA320203)   | No | Yes |
|pmsm_foc_rolo_1shunt| Sensorless Field Oriented Control of PMSM using Reduced Order Luenberger Observer with Single Shunt Current Sense | [ATSAMC21 Motor Control Plugin Module](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/MA320206)|No| Yes|

### Updated Algorithms

- The following table provides the list of algorithms updated in this release.

| Algorithm | Description | Supported Plug In Module | dsPICDEM™ MCHV-3 Support | dsPICDEM™ MCLV-2 Support  | Revision History  |
| --- | --- | --- | --- | --- | --- |
| pmsm_foc_encoder_sam_e70| Sensored Field Oriented Control of PMSM using PDEC | [ATSAME70 Motor Control Plugin Module](https://www.microchip.com/Developmenttools/ProductDetails/MA320203)   | Yes | Yes |<li> Added motor start/stop Capability without resetting the MCU</li> <li> Added Field Weakening support on low voltage application (MCLV-2)</li><li> Added MCHV-3 support (without Field Weakening)</li> |
| pmsm_foc_pll_estimator_sam_e70| Sensorless Field Oriented Control of PMSM using PLL Estimator | [ATSAME70 Motor Control Plugin Module](https://www.microchip.com/Developmenttools/ProductDetails/MA320203)   | Yes | Yes | <li> Reduced dead-time in High Voltage demo (MCHV-3) to improve open loop to closed loop transition</li><li> Resolved bug in Field Weakening operation in reverse direction</li>|
| pmsm_foc_encoder_sam_e54| Sensored Field Oriented Control of PMSM using Quadrature Encoder | [ATSAME54 Motor Control Plugin Module](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/MA320207)   | Yes | Yes | <li>Added Field Weakening support on low voltage application (MCLV-2) </li><li> Added MCHV-3 Support (without field weakening support) </li>|
| pmsm_foc_encoder_position_sam_e54| FOC based Position Control of PMSM  using Quadrature Encoder | [ATSAME54 Motor Control Plugin Module](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/MA320207)   | Yes | Yes |<li> Replaced the PI type Compensator in the position loop with  P type Compensator</li><li> Added MCHV-3 Support </li>|
| pmsm_foc_pll_estimator_sam_e54| Sensorless Field Oriented Control of PMSM using PLL Estimator | [ATSAME54 Motor Control Plugin Module](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/MA320207)   | Yes | Yes | <li> Unswapped PWMH and PWML output in TCC0 configuration </li><li> Update PWM Duty Cycle Update implementation to accomodate for unswapping of the PWMH and PWML</li><li>Over-current fault was made recoverable i.e. Motor can be re-started after an over-current fault without resetting the MCU</li>|
|pmsm_foc_rolo_sam_c21| Sensorless Field Oriented Control of PMSM using Reduced Order Luenberger Observer | [ATSAMC21 Motor Control Plugin Module](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/MA320206)   | Yes | Yes |<li>Over-current fault was made recoverable i.e. Motor can be re-started after an over-current fault without resetting the MCU</li>|
| pmsm_foc_rolo_wm_sam_c21| Sensorless Field Oriented Control of PMSM using Reduced Order Luenberger Observer with Windmilling Capability | [ATSAMC21 Motor Control Plugin Module](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/MA320206)   | Yes | Yes |<li>Over-current fault was made recoverable i.e. Motor can be re-started after an over-current fault without resetting the MCU</li><li> Fixed Speed Filter implementation to make it direction agnostic|

### Required MPLAB Harmony v3 Modules
* csp v3.5.0
* dev_packs v3.5.0
* mhc v3.3.0

### Known Issues

* Programming or debugging SAM C/D2x or SAM D/E5x MCU, using Isolated EDBG Card (board revision #02-10824-R1) on dsPICDEM™ MCHV-3 High Voltage Development Board may inhibit MCU from executing instructions if the MCU is reset by pressing on board 'Reset' switch or power cycling the board. Refer to the [Isolated EDBG Debugger Product Change Notice](https://www.microchip.com/DevelopmentTools/ProductDetails/AC320202) for details of hardware modification needed to resolve this issue.
* pmsm_foc_rolo_1shunt may experience false over-current faults during alternate motor start command when operated in "TORQUE_MODE". Workaround - Reset the MCU before re-starting the motor in "TORQUE_MODE".
* For any demos running on ATSAMC21 Motor Control PIM, if any failures are observed while trying to use X2CScope, these failures may occur due to shortage of CPU computation bandwidth. In such cases, kindly enable "RAM_EXECUTE" mode which speeds up execution by executing certain functions from RAM memory instead of Flash memory



### Development Tools

* [MPLAB X IDE v5.25](https://www.microchip.com/mplab/mplab-x-ide)
* [MPLAB XC32 C/C++ Compiler v2.30](https://www.microchip.com/mplab/compilers)
* MPLAB X IDE plug-ins:
  * MPLAB Harmony Configurator (MHC) v3.3.0.
  * X2CScope v1.2.3.

## Motor Control Release v3.3.1


### Updated Algorithms

- The following table provides the list of algorithms updated in this release.

| Algorithm | Description | Supported Plug In Module | dsPICDEM™ MCHV-3 Support | dsPICDEM™ MCLV-2 Support  | Revision History  |
| --- | --- | --- | --- | --- | --- |
| pmsm_foc_pll_estimator_sam_e54| Sensorless Field Oriented Control of PMSM using PLL Estimator | [ATSAME54 Motor Control Plugin Module](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/MA320207)   | Yes | Yes | Added Windmilling (On-the-fly Startup) Support|
| pmsm_foc_rolo_fw_mtpa_sam_c21| Sensorless Field Oriented Control of PMSM using Reduced Order Luenberger Observer with Field Weakening and MTPA Capability | [ATSAMC21 Motor Control Plugin Module](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/MA320206)   | No | Yes | Fixed error in MTPA calculation|
| pmsm_foc_pll_estimator_sam_e70| Sensorless Field Oriented Control of PMSM using PLL Estimator | [ATSAME70 Motor Control Plugin Module](https://www.microchip.com/Developmenttools/ProductDetails/MA320203)   | Yes | Yes | Added Bi-directional Support|


### Required MPLAB Harmony v3.3.0 Modules
* csp v3.3.0
* dev_packs v3.3.0
* mhc v3.3.0

### Known Issues

* Programming or debugging SAM C/D2x or SAM D/E5x MCU, using Isolated EDBG Card (board revision #02-10824-R1) on dsPICDEM™ MCHV-3 High Voltage Development Board may inhibit MCU from executing instructions if the MCU is reset by pressing on board 'Reset' switch or power cycling the board. Refer to the [Isolated EDBG Debugger Product Change Notice](https://www.microchip.com/DevelopmentTools/ProductDetails/AC320202) for details of hardware modification needed to resolve this issue.



### Development Tools

* [MPLAB X IDE v5.20](https://www.microchip.com/mplab/mplab-x-ide)
* [MPLAB XC32 C/C++ Compiler v2.15](https://www.microchip.com/mplab/compilers)
* MPLAB X IDE plug-ins:
  * MPLAB Harmony Configurator (MHC) v3.3.0.
  * X2CScope v1.2.3.

## Motor Control Release v3.3.0

### New Algorithms

- The following table provides the list of algorithms added in this release.

| Algorithm | Description | Supported Plug In Module | dsPICDEM™ MCHV-3 Support | dsPICDEM™ MCLV-2 Support  |
| --- | --- | --- | --- | --- |
| pmsm_pfc_foc_pll_estimator_sam_e70| PFC and Sensorless Field Oriented Control of PMSM using PLL Estimator | [ATSAME70 Motor Control Plugin Module](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/MA320203)   | Yes | No |
| pmsm_foc_rolo_fw_mtpa_sam_c21| Sensorless Field Oriented Control of PMSM using Reduced Order Luenberger Observer with Field Weakening and MTPA Capability | [ATSAMC21 Motor Control Plugin Module](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/MA320206)   | No | Yes |
| bldc_bc_hall_sam_c21| Block Commutation based control of BLDC motor using Hall Sensors | [ATSAMC21 Motor Control Plugin Module](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/MA320206)   | No | Yes |
| pmsm_foc_pll_estimator_sam_e54| Sensorless Field Oriented Control of PMSM using PLL Estimator | [ATSAME54 Motor Control Plugin Module](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/MA320207)   | Yes | Yes |
| pmsm_foc_encoder_sam_e54| Sensored Field Oriented Control of PMSM using Quadrature Encoder | [ATSAME54 Motor Control Plugin Module](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/MA320207)   | No | Yes |
| pmsm_foc_encoder_position_sam_e54| FOC based Position Control of PMSM  using Quadrature Encoder | [ATSAME54 Motor Control Plugin Module](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/MA320207)   | No | Yes |


### Updated Algorithms

- The following table provides the list of algorithms updated in this release.

| Algorithm | Description | Supported Plug In Module | dsPICDEM™ MCHV-3 Support | dsPICDEM™ MCLV-2 Support  | Revision History  |
| --- | --- | --- | --- | --- | --- |
|pmsm_foc_rolo_sam_c21| Sensorless Field Oriented Control of PMSM using Reduced Order Luenberger Observer | [ATSAMC21 Motor Control Plugin Module](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/MA320206)   | Yes | Yes |Regenerated application with csp v3.3.0|
| pmsm_foc_rolo_wm_sam_c21| Sensorless Field Oriented Control of PMSM using Reduced Order Luenberger Observer with Windmilling Capability | [ATSAMC21 Motor Control Plugin Module](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/MA320206)   | Yes | Yes |Regenerated application with csp v3.3.0|
| acim_vhz_sam_c21| Open Loop V/F Control of AC Induction Motor | [ATSAMC21 Motor Control Plugin Module](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/MA320206)   | Yes | No | Regenerated application with csp v3.3.0|
| pmsm_foc_pll_estimator_sam_e70| Sensorless Field Oriented Control of PMSM using PLL Estimator | [ATSAME70 Motor Control Plugin Module](https://www.microchip.com/Developmenttools/ProductDetails/MA320203)   | Yes | Yes | Regenerated application with csp v3.3.0. Temporarily removed Field Weakening Support, to be added in future release.|
| pmsm_foc_encoder_sam_e70| Sensored Field Oriented Control of PMSM using PDEC | [ATSAME70 Motor Control Plugin Module](https://www.microchip.com/Developmenttools/ProductDetails/MA320203)   | No | Yes | Regenerated application with csp v3.3.0 and added ability to spin the motor in both directions.  |


### Required MPLAB Harmony v3.3.0 Modules
* csp v3.3.0
* dev_packs v3.3.0
* mhc v3.3.0

### Known Issues

* Programming or debugging SAM C/D2x or SAM D/E5x MCU, using Isolated EDBG Card (board revision #02-10824-R1) on dsPICDEM™ MCHV-3 High Voltage Development Board may inhibit MCU from executing instructions if the MCU is reset by pressing on board 'Reset' switch or power cycling the board. Refer to the [Isolated EDBG Debugger Product Change Notice](https://www.microchip.com/DevelopmentTools/ProductDetails/AC320202) for details of hardware modification needed to resolve this issue.



### Development Tools

* [MPLAB X IDE v5.20](https://www.microchip.com/mplab/mplab-x-ide)
* [MPLAB XC32 C/C++ Compiler v2.15](https://www.microchip.com/mplab/compilers)
* MPLAB X IDE plug-ins:
  * MPLAB Harmony Configurator (MHC) v3.3.0.
  * X2CScope v1.2.3.

## Motor Control Release v3.2.0

### New Algorithms

- The following table provides the list of algorithms added in this release.

| Algorithm | Description | Supported Plug In Module | dsPICDEM™ MCHV-3 Support | dsPICDEM™ MCLV-2 Support  |
| --- | --- | --- | --- | --- |
| pmsm_foc_rolo_sam_c21| Sensorless Field Oriented Control of PMSM using Reduced Order Luenberger Observer | [ATSAMC21 Motor Control Plugin Module](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/MA320206)   | Yes | Yes |
| pmsm_foc_rolo_wm_sam_c21| Sensorless Field Oriented Control of PMSM using Reduced Order Luenberger Observer with Windmilling Capability | [ATSAMC21 Motor Control Plugin Module](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/MA320206)   | Yes | Yes |
| acim_vhz_sam_c21| Open Loop V/F Control of AC Induction Motor | [ATSAMC21 Motor Control Plugin Module](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/MA320206)   | Yes | No |


### Updated Algorithms

- The following table provides the list of algorithms updated in this release.

| Algorithm | Description | Supported Plug In Module | dsPICDEM™ MCHV-3 Support | dsPICDEM™ MCLV-2 Support  | Revision History  |
| --- | --- | --- | --- | --- | --- |
| pmsm_foc_pll_estimator_sam_e70| Sensorless Field Oriented Control of PMSM using PLL Estimator | [ATSAME70 Motor Control Plugin Module](https://www.microchip.com/Developmenttools/ProductDetails/MA320203)   | Yes | Yes | Regenerated application with csp v3.2.0  |
| pmsm_foc_encoder_sam_e70| Sensored Field Oriented Control of PMSM using PDEC | [ATSAME70 Motor Control Plugin Module](https://www.microchip.com/Developmenttools/ProductDetails/MA320203)   | No | Yes | Regenerated application with csp v3.2.0 and added ability to spin the motor in both directions.  |


### Required MPLAB Harmony v3.2.0 Modules
* csp v3.2.0
* dev_packs v3.2.0
* mhc v3.2.0

### Known Issues

* MPLAB X IDE v5.15 fails to program ATSAME70 Motor Control Plugin Module on dsPICDEM™ MCHV-3
High Voltage Development Board. In order to resolve this issue, implement the following change in dap_cortex-m7.py, located at C:\Program Files (x86)\Microchip\MPLABX\v5.15\packs\Microchip\SAME70_DFP\3.0.10\scripts\

  * Goto line # 197, replace <span style="color:red; font-family:courier" >dap.Connect(True, 8000000L)</span>  with <span style="color:green; font-family:courier">dap.Connect(True, 2000000L)</span>


* Programming or debugging SAM C/D2x or SAM D/E5x MCU, using Isolated EDBG Card (board revision #02-10824-R1) on dsPICDEM™ MCHV-3 High Voltage Development Board may inhibit MCU from executing instructions if the MCU is reset by pressing on board 'Reset' switch or power cycling the board. Refer to the [Isolated EDBG Debugger Product Change Notice](https://www.microchip.com/DevelopmentTools/ProductDetails/AC320202) for details of hardware modification needed to resolve this issue.


### Development Tools

* [MPLAB X IDE v5.15](https://www.microchip.com/mplab/mplab-x-ide)
* [MPLAB XC32 C/C++ Compiler v2.15](https://www.microchip.com/mplab/compilers)
* MPLAB X IDE plug-ins:
  * MPLAB Harmony Configurator (MHC) v3.2.0.
  * X2CScope v1.2.3.

## Motor Control Release v3.1.0

### New Algorithms

  - The following table provides the list of algorithms added in this release.

| Algorithm | Description | Supported Plug In Module | dsPICDEM™ MCHV-3 Support | dsPICDEM™ MCLV-2 Support  |
| --- | --- | --- | --- | --- |
| pmsm_foc_pll_estimator_sam_e70| Sensorless Field Oriented Control of PMSM using PLL Estimator | [ATSAME70 Motor Control Plugin Module](https://www.microchip.com/Developmenttools/ProductDetails/MA320203)   | Yes | Yes |
| pmsm_foc_encoder_sam_e70| Sensored Field Oriented Control of PMSM using PDEC | [ATSAME70 Motor Control Plugin Module](https://www.microchip.com/Developmenttools/ProductDetails/MA320203)   | No | Yes |

### Required MPLAB Harmony v3.1.0 Modules
  * csp v3.1.0
  * dev_packs v3.1.0
  * mhc v3.1.0

### Known Issues

  * None.

### Development Tools

  * [MPLAB X IDE v5.10](https://www.microchip.com/mplab/mplab-x-ide)
  * [MPLAB XC32 C/C++ Compiler v2.15](https://www.microchip.com/mplab/compilers)
  * MPLAB X IDE plug-ins:
    * MPLAB Harmony Configurator (MHC) v3.1.0.
    * X2CScope v1.2.3.
