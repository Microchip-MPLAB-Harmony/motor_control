<!-- Styling  -->
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

# Setting Hardware Modules
This section describes how to set-up hardware modules for motor control application project with Motor Control Plant.

## Configure PMSM parameters
The PMSM parameter can be configured in following simple steps:

1.  Click on the motor block to open PMSM parameter window as shown below.
![Motor Parameters](images/motor_parameters_01.jpg "Motor Parameters")

2. Configure the motor parameters as shown below.
![Select Motor](images/motor_parameters_02.JPG "Select Motor")

3. Close the window 
## Configure Development Board
There are two ways by which the motor control board can be configured.
1. By selecting the board from the list of Microchip's development boards and reference designs.
2. By configuring the board Parameters from scratch.

## Microchip's Development Board and Reference Designs
Microchip offers a number of motor control development boards and reference designs. These boards can be selected from **Quick Settings** logo to use these boards for developmental activities. 

Following steps list the procedure to select the Motor Control Plant supported development board and reference design.

- Click on the "Quick setting" icon as shown below.
![Quick Settings](images/quick_settings.jpg "Quick Settings")

- Select appropriate motor from "Select Board" option as shown below.

![Quick Settings](images/quick_settings_01.png "Quick Settings")


## Setting Board Parameters from Scratch
The Motor Control Plant can be used to configure the board parameters from scratch. Following steps list the procedure to configure the board parameters from scratch.

## Setting Analog Front End 
The following section describes various analog front end circuit and how it can be configured using Motor Control Plant.

### Theoretical Background
The Field Oriented Control of an AC motor requires current, voltage and rotor position information. These signals are processed using analog circuits before it is sent to the microcontroller to be used for the control tasks. The control software has to be cognizant of these analog circuit parameters in order to reconstruct the actual analog signal for control operations.

### Phase Current Measurement
There are a number of other ways of measuring the phase currents. For brief introduction refer [Current Measurement in AC motor drives](current_measurement.md). 


### DC Bus Voltage Measurement
The DC bus voltage is usually measured by using a resistor based potential divider.
 
<!-- $
V_{DC} = \frac{R_{BOTTOM} + R_{TOP}}{R_{BOTTOM}}V_{o}
$ --> 
<p align = center>
<img style="transform: translateY(0.1em); background: white;" src="..\..\..\..\svg\aR7vmVqBu4.svg">
</p>


### Configuring Analog front End with MC Plant
In Motor Control Plant analog parameters can be set in following steps.

1. Launch **Analog Front End** by clicking on the block

    ![Analog Front End](images/analog_front_end.jpg "Analog Front End")

2. Configure **Phase A** current measurement analog circuit parameters by clicking on the IaSens icon.

    ![Ia](images/analog_front_end_ia.jpg "Ia")

2. Configure **Phase B** current measurement analog circuit parameters by clicking on the IbSens icon.

    ![Ib](images/analog_front_end_ib.jpg "Ib")

2. Configure **DC Bus** current measurement analog circuit parameters by clicking on the VdcSens icon.

    ![Vdc](images/analog_front_end_vdc.jpg "Vdc")



## Setting Analog Interface
The following section describes the analog interfaces and how it can be configured using Motor Control Plant.

### Theoretical Background
The analog signals has to be converted to digital signals for the microcontroller devices to use. For Field Oriented control, the analog signals are converted to corresponding digital signals using ADCs. 

Figure shows a conceptual diagram of Analog to digital conversion.


For an ADC with 12 bit resolution, the conversion can be expressed as follows:
$
V_{adc} = \frac{4096*V_{in}}{V_{ref}}
$

The software essentially has to perform following tasks:
- Set the ADC unit and channel to be used to convert analog signals to digital signals
- Configure ADC parameters like resolution, trigger source etc.

### Configuring Analog Interface using MC Plant
In Motor Control Plant analog parameters can be set in following steps.

1. Launch **Analog Interface** by clicking on the block

    ![Analog Interface](images/analog_interface.jpg "Analog Interface")

2. Configure analog interface **Group 01** signals, i.e. phase current A and phase current B by clicking on **Group 01** icon

    ![Group 01 Signals](images/analog_interface_group_01.jpg "Group 01 Signals")

3. Configure analog interface **Group 02** signals, i.e. DC bus voltage and potentiometer by clicking on **Group 02** icon

    ![Group 02 Signals](images/analog_interface_group_02.jpg "Group 02 Signals")


