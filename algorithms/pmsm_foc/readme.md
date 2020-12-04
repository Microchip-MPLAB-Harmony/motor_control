---
title: PMSM FOC Component
nav_order: 1
has_children: true
has_toc: false
---

# PMSM FOC

PMSM_FOC component provides Field Oriented Control (FOC) algorithm for Permanent Magnet Synchronous Motor (PMSM). 
This component supports speed control with an inner current control loop to control motor speed and motor current. It also supports current control and open loop mode. Rotor position estimation techniques are configurable in the UI. 

PMSM_FOC connects to the Peripheral Libraries (PLIBs) from CSP repository and X2CScope component from X2C repository. 

This component depends on ADC PLIB for phase current measurement, DC bus voltage and potentiometer measurement. PWM PLIB is used to generate three phase signals to control the motor. For quadrature encoder sensor position feedback, PMSM_FOC interacts with QDEC peripheral. 


## Supported Microcontrollers and Development Boards

| Microcontroller     | MCLV2  | MCHV3                                               |
|------------| ---------------| -----------------------------------------------------------|
| SAME70       | Yes              | Yes |
| SAME54        | Yes      | Yes |
| PIC32MK MCF       | Yes  | Yes |
| PIC32MK MCM   | Yes | Yes |
||||

## Supported Features

| Feature     | Options  | 
|------------| -----------------------------------------------------------|
| Position Feedback       | <li> PLL Estimator </li> <li> Quadrature Encoder </li>             | 
| Current Measurement     | <li> Dual shunt </li>     | 
| Control Loop       | <li> Speed mode </li> <li>Torque mode </li>  <li>Open loop (For sensorless operation) </li>  | 
| Field Alignment   | <li> Q-axis alignment </li> <li>D-axis alignment </li>|
| Advanced Features | <li> Equation based field weakening </li> <li> Flying Start </li>| 
|||


[Software Design](sw_design.md)


[Control Algorithm](control_algorithm.md)


[Configuring the Library](configurations.md)

[Using the Library](using_the_library.md)


