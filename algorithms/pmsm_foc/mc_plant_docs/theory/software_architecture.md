---
parent: Software Design
grand_parent: Motor Control Plant Projects
title: Implementation Details
nav_order: 5
has_children: false
has_toc: false
--- 
<style>
 body {
        counter-reset: h1;
        padding: 20px;
    }

   h1 {
        background-color: red;
        color: white;
        counter-reset: h2
    }

    h2 {
        background-color: red;
        color: white;
        counter-reset: h3
    }

    h3 {
        background-color: red;
        color: white;
        counter-reset: h4
    }

    h1:before {
        background-color: red;
        color: white;
        counter-increment: h1;
        content: counter(h1) ". "
    }

    h2:before {
        background-color: red;
        color: white;
        counter-increment: h2;
        content: counter(h1) "." counter(h2) ". "
    }

    h3:before {
        background-color: red;
        color: white;
        counter-increment: h3;
        content: counter(h1) "." counter(h2) "." counter(h3) ". "
    }

    h4:before {
        background-color: red;
        color: white;
        counter-increment: h4;
        content: counter(h1) "." counter(h2) "." counter(h3) "." counter(h4) ". "
    }
    p{
        color: black;
        font-family: "Arial", Helvetica, sans-serif;
    }

    article {
        max-width: 50em;
        background: white;
        padding: 2em;
        margin: 1em auto;
    }

    .table-of-contents {
        float: right;
        width: 40%;
        background: #eee;
        font-size: 0.8em;
        padding: 1em 2em;
        margin: 0 0 0.5em 0.5em;
    }
    .table-of-contents ul {
        padding: 0;
    }
    .table-of-contents li {
        margin: 0 0 0.25em 0;
    }
    .table-of-contents a {
        text-decoration: none;
    }
    .table-of-contents a:hover,
    .table-of-contents a:active {
        text-decoration: underline;
    }

    h3:target {
        animation: highlight 1s ease;
    }

    @keyframes highlight {
    from { background: yellow; }
    to { background: white; }
    }

    li{
        color: black;
        font-family: "Arial", Helvetica, sans-serif;
    }

    table{
        color: black;
        font-family: "Arial", Helvetica, sans-serif;
    }

    }
}
</style>

# Field Oriented Control Implementation
The generated code from the Harmony QSpin intends to achieve following goals:
- to spin a motor based on simple user inputs
- to be modular and maintainable
- to be a clear example to Microchip customers for a motor control Application using Microchip's 32 bit MCU devices

The following section describes an overview of control software architecture to meet the above mentioned goals.

## Software Description (In Brief)
The software spins a motor using a velocity control loop, with an inner current loop using field-oriented control (FOC) to manage motor current and torque. Sensorless estimation techniques are used to estimate motor position for commutation and velocity control. User input is provided with a potentiometer and buttons to start and stop the motor, or to reverse direction. A state machine is used to control the transitions between these different modes of operation.

The motor startup process involves so-called “open-loop” operation. When the motor is at rest or moving very slowly, the sensorless estimator is not accurate enough; instead, a special set of states is provided to manage startup, in which commutation is forced at a desired acceleration rate, and the velocity control loop is disabled.

Figure XX shows a high level block diagram of the software.


## Software Architecture

The software performs following tasks:
- Microcontroller and motor control peripheral initialization
- FOC State machine in ADC ISR
- Motor start and stop command by GPIO button
- Motor speed command from potentiometer


### Motor control peripheral initialization.

On power-on reset, the software initializes the microcontroller and motor control peripherals according to the user requirements. 

### Motor control state machine
The software implements the motor control tasks in ADC ISR. The ADC ISR incorporates following states:
- **Idle**. In this state, the motor does not spin. The software waits for a valid button press from the user to start the motor.
 
- **Start-up**. In this state, the software executes the PMSM start-up procedure as described in section 4.1.

- **Close-loop speed control**. In this state, the software executes an SMO based sensorless FOC.

### Motor speed command from potentiometer
The software calculates the speed reference from the measured from the potentiometer input. 

### Motor start and stop Command by GPIO
The software polls the GPIO button every 10ms to check if the button has been pressed. If the button press is detected, the firmware changes the motor control state from “Idle” to “Start-up” to initiate the motor spin at the specified reference speed.

Figure 5.2 illustrates the software flow-chart of the example project

 
Figure 5.3. Software Flow Chart


## Modules and Components
The software is based on a modular design, and consists of a number of components that work together. 

The software contains following modules:

- Hardware Abstraction:
    <ul>
        <li style="font-family:consolas;">mc_hardware_abstraction.c</li>
        <li style="font-family:consolas;">mc_hardware_abstraction.h</li>
    </ul>

- Motor control API
    <ul>
        <li style="font-family:consolas;">mc_pmsm_foc.c</li>
        <li style="font-family:consolas;">mc_pmsm_foc.h</li>
    </ul>

- Function coordination
    <ul>
        <li style="font-family:consolas;">mc_function_coordinator.c</li>
        <li style="font-family:consolas;">mc_function_coordinator.h</li>
    </ul>

- Motor control 
    - State Machine
        <ul>
            <li style="font-family:consolas;">mc_motor_control.c</li>
            <li style="font-family:consolas;">mc_motor_control.h</li>
        </ul>

    - Speed control
        <ul>
            <li style="font-family:consolas;">mc_speed_control.c</li>
            <li style="font-family:consolas;">mc_speed_control.h</li>
        </ul>
    - Current control
        <ul>
            <li style="font-family:consolas;">mc_current_control.c</li>
            <li style="font-family:consolas;">mc_current_control.h</li>
        </ul>

    - Start-up
        <ul>
            <li style="font-family:consolas;">mc_start_up.c</li>
            <li style="font-family:consolas;">mc_start_up.h</li>
        </ul>
    - Phase currents
        <ul>
            <li style="font-family:consolas;">mc_current_calculation.c</li>
            <li style="font-family:consolas;">mc_current_calculation.h</li>
        </ul>
    - DC bus voltage
        <ul>
            <li style="font-family:consolas;">mc_voltage_measurement.c</li>
            <li style="font-family:consolas;">mc_voltage_measurement.h</li>
        </ul>
    - Rotor position
        <ul>
            <li style="font-family:consolas;">mc_rotor_position.c</li>
            <li style="font-family:consolas;">mc_rotor_position.h</li>
        </ul>

- Control library
    <ul>
        <li style="font-family:consolas;">mc_generic_library.c</li>
        <li style="font-family:consolas;">mc_generic_library.h</li>
    </ul>


- Data management
    <ul>
        <li style="font-family:consolas;">mc_interface_handling.c</li>
        <li style="font-family:consolas;">mc_interface_handling.h</li>
    </ul>

- User parameters
    <ul>
        <li style="font-family:consolas;">mc_userparams.h</li>
    </ul>





