---
parent: PMSM FOC Component
grand_parent: Microchip MPLAB® Harmony 3 Motor Control
title: Using the Library
nav_order: 4
has_children: false
has_toc: false
---

## Using the Library

-   Instantiate PMSM_FOC component
-   Connect to required PLIBs (ADC, PWM, QDEC) and X2CScope and UART. Configure ADC, PWM and QDEC parameters in PMSM_FOC UI. Please refer to the project graph shown below. **Note that PLIB names will be different for different devices**

![project graph](images/project_graph.png)

-   Select motor, control board, position feedback method in UI. Configure advanced parameters like field weakening, flying start. 
-   Configure pins in the pin manager
-   Generate the code
-   PMSM_FOC is initialized in the SYS_Initialize() function. Function name is PMSM_FOC_Initialize(). 
-   Call PMSM_FOC_Tasks() in the while loop in the main.c 
-   Call X2CScope_Communicate() in the while loop in the main.c
-   Motor start/stop and direction change is done on the switch event. For MCLV2 board, press S2 to start/stop the motor. And press switch S3 to change the direction of the motor when motor is stopped.  For MCHV3, press pushbutton to start/stop the motor
-   Vary the potentiometer to change the speed of the motor in speed loop


            PMSM_FOC_Tasks();
            X2CScope_Communicate();
