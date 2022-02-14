
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

## Configuring Peripheral Modules
This section describes how to configure MCU peripherals for motor control application projects with Motor Control Plant

## Setting PWM Interface
The following section describes the PWM interfaces and how it can be configured using Motor Control Plant.

### Theoretical Background
The three-phase actuation voltage is applied employing the Space Vector Pulse Width Modulation (SVPWM). 

Figure shows a conceptual diagram of Analog to digital conversion.

The software essentially has to perform following tasks:
- Set the PWM unit and channels to be used to modulate three-phase voltages 
- Configure PWM peripheral's frequency, dead-time, fault management etc.

### Configuring PWM Interface using MC Plant
In Motor Control Plant PWM Interface can be set in following steps.

1. Launch **PWM Interface** by clicking on the block

    ![PWM Interface](images/pwm_interface.jpg "PWM Interface")

2. Configure PWM interface 
    ![PWM Configuration](images/pwm_interface_01.jpg "PWM Configuration")


## Setting Position Interface
The following section describes the position interfaces and how it can be configured using Motor Control Plant.

### Theoretical Background
For sensored Field Oriented Control, the position sensor interface has to be configured to process rotor position signals.

The software essentially has to perform following tasks:
- Set the peripheral unit and channels to be used to for rotor position signals
- Configure rotor position interface peripheral.

### Configuring Position Interface using MC Plant

1. Launch **Position Interface** by clicking on the block

    ![Position Interface](images/position_interface.jpg "Position Interface")

2. Configure PWM interface

    ![Position Configuration](images/position_interface_01.jpg "Position Configuration")

