---
parent: Getting Started
grand_parent: Motor Control Plant Projects
title: MC Plant Manager
nav_order: 2
has_children: false
has_toc: false
--- 
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

# Motor Control Plant Manager
The Motor Control Plant Manager (MCPM) is an intuitive graphical tool for developing motor control application software.

The following section briefly describes how to configure motor control firmware for a user application.

## How to configure Motor Control Application
1. Launch the Motor Control Plant Manager from the MCC plugin list.    
    <p align="center">
    <img src="images/launch_plant_manager.jpg"/>
    <figcaption align= "center">Figure.1 - Launching Motor Control Plant Manager </figcaption>
    </p>

2. Set the motor and board parameters.
    <p align="center">
        <img src="images/hardware_configuration.jpg"/>
        <figcaption align= "center">Figure.2 - Motor and Board Parameters </figcaption>
    </p>

    [Click here for details](hardware_modules.md)
 
3. Set the microcontroller peripherals.        
    <p align="center">
        <img src="images/peripheral_configuration.jpg"/>
        <figcaption align= "center">Figure.3 - Microcontroller Peripherals </figcaption>
    </p>

    [Click here for details](peripheral_modules.md)

4. Set the software modules.   
    <p align="center">
        <img src="images/control_configuration.jpg"/>
        <figcaption align= "center">Figure.4 - Software modules </figcaption>
    </p>

    [Click here for details](software_modules.md)

5. Set advanced project options.
   
    <p align="center">
        <img src="images/advanced_options.jpg"/>
        <figcaption align= "center">Figure.5 - Advanced options </figcaption>
    </p>
