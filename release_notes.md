![Microchip logo](https://raw.githubusercontent.com/wiki/Microchip-MPLAB-Harmony/Microchip-MPLAB-Harmony.github.io/images/microchip_logo.png)
![Harmony logo small](https://raw.githubusercontent.com/wiki/Microchip-MPLAB-Harmony/Microchip-MPLAB-Harmony.github.io/images/microchip_mplab_harmony_logo_small.png)



# Microchip MPLAB Harmony 3 Release Notes
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
