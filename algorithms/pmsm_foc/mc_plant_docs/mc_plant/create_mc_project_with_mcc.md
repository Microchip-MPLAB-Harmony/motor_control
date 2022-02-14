
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
# Create a new MPLAB® Harmony v3 project using MCC

This section describes step by step process for creating a new Motor Control Project using MPLAB Code Configurator (MCC) from scratch. 

## Procedure
The following section describes uses SAME70 microcontroller to illustrate the process for creating a new motor control project with Motor Control Plant.

1. Launch MPLAB® X IDE from the Microsoft Windows® Start menu. 
2. Go to the **File** option in the menu bar and select "**New project**"
3. In the Categories pane of the New Project dialog, select Microchip Embedded. In the Projects pane, select 32-bit MCC Harmony Project, then click Next.
4. In the Framework Path edit box, browse to the folder where you downloaded the framework. 
    <p align="center">
        <img src="images/create_project_step_03.jpg"/>
        <figcaption align= "center">Figure.1 - Framework path </figcaption>
    </p>


5. In the Project Settings window, apply the following settings:
    - **Location**: Indicates the path to the root folder of the new project. All project files will be placed inside this folder. The project location can be any valid path, for example: <Folder of your choice>\dev\same51n_getting_started.
    - **Folder**: Indicates the name of the MPLABX .X folder. Enter "sam_e51_cnano" to create a sam_e51_cnano.X folder.

    - **Name**: Enter the project’s logical name as "getting_started_sam_e51_cnano". This is the name that will be shown from within MPLAB X IDE.

    - Click Next to proceed to Configuration Settings.

    <p align="center">
        <img src="images/create_project_step_04.jpg"/>
        <figcaption align= "center">Figure.1 - Project set-up </figcaption>
    </p>

6. Follow the steps below to set the project’s Configuration Settings.

    - **Name**: Enter the configuration name as "mclv2_sam_e70_pim".

    - **Target Device**: Select ATSAME70Q21B as the target device.
        <p align="center">
            <img src="images/create_project_step_05.jpg"/>
            <figcaption align= "center">Figure.1 - Project set-up </figcaption>
        </p>

7. In MCC Content Manager Wizard window, click on "**Select MPLAB Harmony**"

    <p align="center">
        <img src="images/create_project_step_06.jpg"/>
        <figcaption align= "center">Figure.1 - Project set-up </figcaption>
    </p>

8. In MCC Content Manager Wizard window, click on "**Finish**"
    <p align="center">
            <img src="images/create_project_step_07.jpg"/>
            <figcaption align= "center">Figure.1 - Project set-up </figcaption>
    </p>

9. Add MCC components from the ** Device Resources** to the **Project Graph**
    - Add **PMSM FOC** component
    - Add and connect **ADC**, **PWM**, **QDEC** and **Data Stream** dependencies to **PMSM FOC**
    - Add **SAM E70 PIM MC Board** from the **Board Support Packages**

    <p align="center">
        <img src="images/create_project_step_08.jpg"/>
        <figcaption align= "center">Figure.1 - Project set-up </figcaption>
    </p>

10. Launch **Motor Control Plant Manager** plugin