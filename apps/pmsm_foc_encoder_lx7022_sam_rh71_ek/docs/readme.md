# PMSM FOC using Quadrature Encoder with SAMRH71-EK and LX7022 boards

This example shows how to perform motor control using the SAMRH71-EK board connected to the LX7022 board. The control strategy is the sensored FOC, in which rotor position is determined by the Quadrature Encoder. And speed is calculated from the position. 

## Building The Application 
The parent folder for all the MPLAB X IDE projects for this application is given below:

**Application Path** : motor_control\apps\pmsm_foc_encoder_lx7022_sam_rh71_ek\firmware

To build the application, refer to the table below and open the appropriate project file in MPLABX IDE.

| Project Name  | Description   |
| ------------- |:-------------:|
| sam_rh71_ek.X | SAM RH71 Evaluation Kit board  |
	

## MPLAB Harmony Configurations 

Refer to the MHC project graph for the components used and the respective configuration options.

* PWM Peripheral:
    * This peripheral is used to generated three phases synchronous PWM waveforms. Fault functionality is also enabled to switch off the output waveforms asynchronously
* TC Peripherals:
    * TC0
        * To trigger periodic PWM duty updates.
    * TC1
        * Used for sampling the sigma delta modulators signals from LX7022 board.
    * TC3
        * This peripheral is used in quadrature encoder mode for position measurement
* FLEXCOM Peripheral:
    * The UART is used for X2CScope communication to observe graphs and variable values in run time.

## Algorithm and current measurement

The control algorithm is the same as in the PMSM using an Encoder based Field Oriented Control (FOC) in the SAME70 microcontroller example

An additional algorithm is used to get the currents on phase A and B from the LX7720. A decimation filter is used to convert the sigma delta modulators output from LX7720.

### Current conversion with decimation filter

The second order sigma delta modulator output of the LX7720 is a noise shaped signal where le low frequency noise is pushed toward the high frequencies.

The SAMRH71 provide a 25MHz clock to the LX7720 modulator which in turn generates modulated signals that can be sampled by the SAMRH71.

The sampling is done with one timer counter per motor phase (A and B). The timer counters use two channels clocked at 50MHz. For each channel we use the "Burst signal" selection to have respectively XC0 (TCLK3) or (TCLK4) XC1 ANDed with the counting clock. The channel 0 of the same timer is used as reference to trigger a periodic interrupt for sampling, here every 4µs. This first sampling act as first SINC1 filter with OSR1=50.

A digital third order CIC filter (also known as SINC3) is used to do anti-aliasing filtering and decimate to the desired data-rate​. This filter is applied on every SINC1 samples (OSR2=5).
With this configuration we get SINC3 samples every 20µs which corresponds to 2.5 samples per PWM periods.

The final calculation for phases A and B currents is performed in the FOC control interrupt routine. The currents are calculated with a weighted average on the last 4 samples.

The FOC control loop is executed in an interrupt routine generate by a timer counter. This counter starts when the PWM event signal is raised. Then the interrupt is triggered after 20µs using the timer compare mode. This ensures that we have at least one current SINC3 sample calculated before the weight average calculation.

![PWM and Current samples diagram](img/pwm_current_sample_diagram.jpg "PWM and Current samples diagram")

## Hardware Setup

1. Project sam_rh71_xult.X
    * Hardware Used
        * SAM RH71 Evaluation Kit
        * LX7022 board
        * Hurst DMA0204024B101 BLDC Motor
    * Hardware Setup
        * Connect the debugger probe to J33
        * Connect the USB port on the board to the computer using a mini USB cable.
        * Connect the 3 motors phases to the LX board.
        * Connect the motor encoders A and B respectively to LX7022 BLI1 and BLI2. Connecter encoder VCC to LX7720 5V and encoder GND to LX7720 SGND.
        * LX7720 jumpers configuration
            * SM_EN to ON with J39
            * SCP forced high with J38
        * Connect the followings signals between SAMRH71-EK board and LX7720 board.

            | SAMRH71F20-EK        | LX7720                |
            | -------------        |:-------------:        |
            | PA4 (J24.8)          |   LD_IN_A_C   (J20.2) | 
            | PA0 (J24.7)          |   UD_IN_A_C   (J20.1) | 
            | PA5 (J24.6)          |   LD_IN_B_C   (J20.6) | 
            | PA1 (J24.9)          |   UD_IN_B_C   (J20.5) | 
            | PA6 (J24.17)         |   LD_IN_C_C   (J20.10)|
            | PA2 (J24.16)         |   UD_IN_C_C   (J20.9) |
            | PA09 (J24.3)         |   OC_FAULT    (J20.32)|
            | PB8 (J30.5) (TCLK3)  |   SNS_OUT_A   (J20.3) |
            | PB11 (J30.18) (TCLK4)|   SNS_OUT_B   (J20.7) |
            | PC24 (J30.15) (TIOB9)|   BLO2        (J20.36)|
            | PC22 (J30.17) (TIOA9)|   BLO1        (J20.35)|
            | PA11 (J24.5) (PCK0)  |   MOD_CLK     (J20.18)|
            | PA10 (J24.4) (PCK2)  |   CP_CLK      (J20.17)|

## Running The Application

1. Build and Program the application using the MPLAB X IDE.
2. Press PB0 on SAMRH71-EK board to start the motor, it will set LED0 indicating the control loop is running.
3. Increase speed with PB1 and decrease speed with PB2.
4. Stop the motor by pressing again PB0.