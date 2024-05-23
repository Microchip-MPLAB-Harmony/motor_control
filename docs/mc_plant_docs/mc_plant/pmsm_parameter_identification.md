# PMSM Parameter Identication
Knowledge of motor parameters is crucial process in Permanent Magnet Synchronous Motors (PMSMs) control applications, particularly in Field Oriented Control. 
While manufacturers may provide motor parameters, independently measuring them for Permanent Magnet Synchronous Motors (PMSMs) remains valuable. 
This introduction discusses different methodologies that can be used to determine PMSM parameters effectively.

Different recommended methods for parameter identification include:
- Generating motor parameters using Microchip's motorBench.
- Manual determination through experimental testing and analysis.

## Identify motor parameters using MATLAB auto-tuner.

## Generating motor parameters using Microchip's motorBench

## Manual determination through experimental testing and analysis.

PMSM parameters can be classified into following categories-
**Name plate parameters**
1. Rated continous current
2. Rated peak current
3. Rated voltage
4. Rated RPM
5. Maximum mechanical speed

**Electrical parameters**
1. Pole pairs
2. Winding resistance
3. Winding inductances -    Ld, Lq
4. Back EMF constant / Flux linkage

**Mechanical parameters**
1. Damping coeffient
2. Mechanical time constant
3. Moment of inertia

For manual calculation of motor parameters, approximate values plate parameters are required. They serve as foundational data points for subsequent calculations.

The following section lists steps to manually calculate the electrical parameters of PMSM motor.

### Electrical Parameters
#### Pole pairs
Pole pairs represent the number of magnetic pole pairs in a motor. If this information is not provided by the manufacturer, you can determine the pole pairs by following these steps:

1. Connect any two out of three phase wires to a DC power supply.
2. Set the current limit of the power supply to around 10% of the motor's continuous current rating.
3. Adjust the current limit of the supply until you can manually rotate the motor shaft, ensuring the motor aligns in stable positions.
4. Count the number of stable positions throughout the entire rotation range. The number of pole pairs equals the number of stable positions.

#### Resistance
The winding resistance of a PMSM motor is a crucial parameter. While some ohmmeters may not provide accurate readings due to limitations in their measurement range, the following steps can be taken to accurately measure the resistance:

1. Connect phase A and phase B wires to a positive and negative terminal of a DC power supply, respectively.
2. Set the current limit of the power supply to approximately 10% of the motor's continuous current rating.
3. Measure the voltage drop across phase A and phase B using a multimeter or oscilloscope.
4. Calculate the resistance using Ohm's law:
   \[
   R_{AB} = \frac{V_{AB}}{I_{\text{limit}}}
   \]
5. Repeat steps 1-4 for phase A and phase C, and phase B and phase C.
6. Determine the line-line resistance:
   \[
   R_{\text{line-line}} = \frac{1}{3}(R_{AB} + R_{BC} + R_{AC})
   \]
7. Calculate the per-phase resistance using the following formula:
   \[
   R_{\text{phase}} = \begin{cases}
       \frac{2}{3} R_{\text{line-line}} & \text{for delta connection}\\
       \frac{1}{2} R_{\text{line-line}} & \text{for star connection}
     \end{cases}
   \]



#### Inductance Values Ld, Lq

Winding inductance can be measured using an LCR meter with the following steps:

1. Connect phase A and phase B wires to a positive and negative terminal of an LCR meter, respectively.
2. Set the LCR frequency to the desired value.
3. Read the inductance values from the LCR meter.
4. Rotate the shaft of the motor manually and observe the change in inductance value.
5. Plot the inductance values as a function of shaft rotation angle.
6. Identify the lowest and highest readings on the plot.
7. Ld corresponds to the lowest inductance point, while Lq corresponds to the highest inductance point.

It's important to note that the motor may exhibit residual inductance, which requires time to settle. Shorting the leads on the motor can help with this.


#### Back EMF Constant/ Flux Linkage
The back-EMF (BEMF) constant, denoted by \( \lambda_m \), represents the flux linkage of the Permanent Magnet (PM). It can be obtained by 
measuring the no-load line voltage \( V_{\text{pk}} \) of the motor while it is driven through the shaft at a constant speed of \( \omega_m \). 
This constant provides a ratio between the BEMF voltage and the angular electrical frequency/speed.

To determine the back-EMF constant/flux linkage, follow these steps:

1. Rotate the motor at a relatively precise RPM, ideally more than 20% of the rated RPM for better accuracy.
2. Connect the ground end of your oscilloscope to one phase of the motor, and the probe to another phase.
3. Record the voltage amplitude and period from the oscilloscope display.
4. Calculate lambda using the following formula:
   \[ \lambda = V_{\text{peak}} \times T \]