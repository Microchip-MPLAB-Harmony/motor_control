
import React from 'react';
import ReactDOM from 'react-dom';
import { RegisterSVGActions } from './ControlBlock/MotorControlandDiagnosis';
// import Popup from './Popup';
// import PWMPopup from './PWMPopup';
import DialogDemo from './CustomPopUp/CustomPopUp';
// import { setPopUpTrue } from './Popup';
// import { setPopUpTrue2 } from './PWMPopup';
import { StarUpConfigurator } from './CustomPopUp/CustomPopUp';

var svgdoc: any = null;
var colorsArray: any = null;
var controllersArray: any = null;
var toolTipObject: any = null;


export function init() {
    //   http://www.w3.org/TR/DOM-Level-2-HTML/html.html#ID-9893177
    //   http://w3.org/TR/SVG11/struct.html#InterfaceGetsvgdocument


    svgdoc = document.getElementById("motor");

    //   http://www.w3.org/TR/DOM-Level-2-Views/views.html#Views-DocumentView

    // alert('SVG Doc Access found: ' + svgdoc);


    var hardWareColor = ["rgb(255, 153, 153)", "#f99"];
    var controlColor = ["rgb(0, 80, 239)", "#0050ef"];
    var peripheralColor = ["rgb(255, 219, 115)", "#ffdb73"];
    var mcuColor = ["rgb(168, 232, 166)", "#a8e8a6"];



    colorsArray = new Array(8);
    colorsArray[0] = hardWareColor[0];
    colorsArray[1] = hardWareColor[1];

    colorsArray[2] = controlColor[0];
    colorsArray[3] = controlColor[1];

    colorsArray[4] = peripheralColor[0];
    colorsArray[5] = peripheralColor[1];

    colorsArray[6] = mcuColor[0];
    colorsArray[7] = mcuColor[1];

    controllersArray = ["Hardware_Box", "Hardware_Text", "Control_Box", "Control_Text", "Peripheral_Box", "Peripheral_Text", "MCU_Config_Box", "MCU_Config_Text"];

    addEventListner("Hardware_Motor_Control_Box");
    svgdoc.getElementById("Hardware_Motor_Control_Box").Hardware_Motor_Control_Box = "Motor Parameters";
    svgdoc.getElementById("Hardware_Motor_Control_Box").toolTip = "click to configure Motor parameters..";
    addEventListner("Motor_Control_Text");
    svgdoc.getElementById("Motor_Control_Text").toolTip = "click to configure Motor parameters..";
    addEventListner("Peripheral");
    svgdoc.getElementById("Peripheral").pwmPopup = "Pulse With Modulator";
    svgdoc.getElementById("Peripheral").toolTip = "click to configure PWM parameters..";
    addEventListner("Start_Up_Configurator");
    svgdoc.getElementById("Start_Up_Configurator").Start_Up_Configurator = "Start Up Configurator";
    svgdoc.getElementById("Start_Up_Configurator").toolTip = "click to configure Start Up Configurator..";
    addEventListner("Motor_Control_Diagnosis");
    svgdoc.getElementById("Motor_Control_Diagnosis").Motor_Control_Diagnosis = "Motor Control Diagnosis";
    svgdoc.getElementById("Motor_Control_Diagnosis").toolTip = "click to configure Motor Control Diagnosis..";
    addEventListner("Output_Stage_Diagnosis");
    svgdoc.getElementById("Output_Stage_Diagnosis").Output_Stage_Diagnosis = "Output Stage Diagnosis";
    svgdoc.getElementById("Output_Stage_Diagnosis").toolTip = "click to configure Output Stage Diagnosis..";
    addEventListner("Current_Measurement_Diagnosis");
    svgdoc.getElementById("Current_Measurement_Diagnosis").Current_Measurement_Diagnosis = "Current Measurement Diagnosis";
    svgdoc.getElementById("Current_Measurement_Diagnosis").toolTip ="click to configure Current Measurement Diagnosis..";
    addEventListner("Voltage_Measurement_Diagnosis");
    svgdoc.getElementById("Voltage_Measurement_Diagnosis").Voltage_Measurement_Diagnosis = "Voltage Measurement Diagnosis";
    svgdoc.getElementById("Voltage_Measurement_Diagnosis").toolTip = "click to configure Voltage Measurement Diagnosis..";
    addEventListner("Position_Calculation_Diagnosis");
    svgdoc.getElementById("Position_Calculation_Diagnosis").Position_Calculation_Diagnosis = "Position Calculation Diagnosis";
    svgdoc.getElementById("Position_Calculation_Diagnosis").toolTip = "click to configure Position Calculation Diagnosis";

    addEventListner("Summary_Box");
    svgdoc.getElementById("Summary_Box").toolTip =  "click to view  Summary";
    addEventListner("Summary_Text");
    svgdoc.getElementById("Summary_Text").toolTip =  "click to view  Summary";

    addEventListner(controllersArray[0]);
    svgdoc.getElementById(controllersArray[0]).myParm = hardWareColor;
    svgdoc.getElementById(controllersArray[0]).toolTip = "click to view  Hardware Configurations only";
    addEventListner(controllersArray[1]);
    svgdoc.getElementById(controllersArray[1]).myParm= hardWareColor;
    svgdoc.getElementById(controllersArray[1]).toolTip= "click to view  Hardware Configurations only";

    addEventListner(controllersArray[2]);
    svgdoc.getElementById(controllersArray[2]).myParm = controlColor;
    svgdoc.getElementById(controllersArray[2]).toolTip = "click to view  Control Configurations only";
    addEventListner(controllersArray[3]);
    svgdoc.getElementById(controllersArray[3]).myParm = controlColor;
    svgdoc.getElementById(controllersArray[3]).toolTip = "click to view  Control Configurations only";

    addEventListner(controllersArray[4]);
    svgdoc.getElementById(controllersArray[4]).myParm = peripheralColor;
    svgdoc.getElementById(controllersArray[4]).toolTip = "click to view  Peripheral Configurations only";
    addEventListner(controllersArray[5]);
    svgdoc.getElementById(controllersArray[5]).myParm = peripheralColor;
    svgdoc.getElementById(controllersArray[5]).toolTip = "click to view  Peripheral Configurations only";

    addEventListner(controllersArray[6] );
    svgdoc.getElementById(controllersArray[6]).myParm = mcuColor;
    svgdoc.getElementById(controllersArray[6]).toolTip = "click to view  MCU Configurations only";
    addEventListner(controllersArray[7]);
    svgdoc.getElementById(controllersArray[7]).myParm = mcuColor;
    svgdoc.getElementById(controllersArray[7]).toolTip = "click to view  MCU Configurations only";

    toolTipObject = svgdoc.getElementById('tooltip');

    storeComponentColors();
}

function addEventListner(id : any){
    svgdoc.getElementById(id).addEventListener("click", sendClickAction, false);
    svgdoc.getElementById(id).addEventListener("mousemove", mouseEnter);
    svgdoc.getElementById(id).addEventListener("mouseleave", mouseLeave);
}


function hideTooltip() {
    toolTipObject.setAttributeNS(null, "visibility", "hidden");
}

function storeComponentColors() {
    var myNodelist = svgdoc.querySelectorAll("*");
    var i;
    for (i = 0; i < myNodelist.length; i++) {
        if (myNodelist[i].style) {
            myNodelist[i].myParm2 = myNodelist[i].style.fill;
        } else if (myNodelist[i].getAttribute("style") || myNodelist[i].getAttribute("fill")) {
            myNodelist[i].myParm2 = myNodelist[i].getAttribute("fill");
        }
    }
}

function mouseEnter(evt: { target: any, }) {
    document.body.style.cursor = "pointer";
    var target = evt.target;
    if (target.correspondingUseElement)
        target = target.correspondingUseElement;
    alert(target.id + target.toolTip)
    showTooltip(evt, target.toolTip);
}

function mouseLeave(evt: { target: any, }) {
    document.body.style.cursor = "auto";
    hideTooltip();
}

function showTooltip(evt: { target?: any; clientX?: any; clientY?: any; }, text: any) {
    var CTM = svgdoc.getScreenCTM();
    var mouseX = (evt.clientX - CTM.e) / CTM.a;
    var mouseY = (evt.clientY - CTM.f) / CTM.d;
    toolTipObject.setAttributeNS(null, "x", mouseX + 6 / CTM.a);
    toolTipObject.setAttributeNS(null, "y", mouseY + 20 / CTM.d);
    toolTipObject.setAttributeNS(null, "visibility", "visible");
    var x = (evt.clientX - CTM.e + 6) / CTM.a;
    var y = (evt.clientY - CTM.f + 20) / CTM.d;
    toolTipObject.setAttributeNS(null, "transform", "translate(" + x + " " + y + ")");
    
    var tooltipText = toolTipObject.getElementsByTagName('text')[0];
    tooltipText.firstChild.data = text;

    var tooltipRects = toolTipObject.getElementsByTagName('rect');
    var length = tooltipText.getComputedTextLength();
    for (var i = 0; i < tooltipRects.length; i++) {
        tooltipRects[i].setAttributeNS(null, "width", length + 8);
    }
}

function sendClickAction(evt: { target: any, }) {
    resetColors();
    var target = evt.target;
    if (target.correspondingUseElement)
        target = target.correspondingUseElement;

    if (target.Hardware_Motor_Control_Box) {
        callPopUp(DialogDemo, target.Hardware_Motor_Control_Box);
        return;
    }
    if (target.pwmPopup) {
        callPopUp(DialogDemo, target.pwmPopup);
        return;
    }

    if (target.Start_Up_Configurator) {
        callPopUp(DialogDemo, target.Start_Up_Configurator);
        return;
    }

    if (target.Motor_Control_Diagnosis) {
        callPopUp(DialogDemo, target.Motor_Control_Diagnosis);
        RegisterSVGActions();
        return;
    }

    if (target.Output_Stage_Diagnosis) {
        callPopUp(DialogDemo, target.Output_Stage_Diagnosis);
        return;
    }
    if (target.Current_Measurement_Diagnosis) {
        callPopUp(DialogDemo, target.Current_Measurement_Diagnosis);
        return;
    }
    if (target.Voltage_Measurement_Diagnosis) {
        callPopUp(DialogDemo, target.Voltage_Measurement_Diagnosis);
        return;
    }
    if (target.Position_Calculation_Diagnosis) {
        callPopUp(DialogDemo, target.Position_Calculation_Diagnosis);
        return;
    }

    //alert("You clicked '" + target.id + "' which is a " + target.myParm + " element");

    var myNodelist = svgdoc.querySelectorAll("*");
    var i;
    for (i = 0; i < myNodelist.length; i++) {
        if (myNodelist[i].style) {
            if ((!(target.myParm.indexOf(myNodelist[i].style.fill) > -1)) && (!(controllersArray.indexOf(myNodelist[i].id) > -1)) && colorsArray.indexOf(myNodelist[i].style.fill) > -1) {
                myNodelist[i].style.fill = "#dddddd";
            }
        }
        if (myNodelist[i].getAttribute("style") || myNodelist[i].getAttribute("fill")) {
            if ((!(target.myParm.indexOf(myNodelist[i].getAttribute("fill")) > -1)) && (!(controllersArray.indexOf(myNodelist[i].id) > -1)) && colorsArray.indexOf(myNodelist[i].getAttribute("fill")) > -1) {
                myNodelist[i].style.fill = "#dddddd";
            }
        }
    }
}

function callPopUp(Component: any, action_id: any) {
    const helloCreate = React.createElement(Component);
    alert(action_id);
    StarUpConfigurator(action_id);
    ReactDOM.render(
        helloCreate
        , document.querySelector("#popup"));
}

function resetColors() {
    var myNodelist = svgdoc.querySelectorAll("*");
    var i;
    for (i = 0; i < myNodelist.length; i++) {
        if (myNodelist[i].style) {
            myNodelist[i].style.fill = myNodelist[i].myParm2;
        }
    }
}

// function findElement(_arg: any){
//     var str = 
//     var allElements = svgdoc.querySelectorAll("[data-abc='asd']");
//     for (var i = 0; i < allElements.length; i++) {
//         var element = allElements[0];
//         alert(element);
//         var element2 = element.childNodes;
//         for (var j = 0; j < element2.length; j++) {
//             var element3 = element2[j];
//             alert(element3.getAttribute("fill"));
//             element3.setAttribute("fill", "#7FFF00");
//         }
//         return;
//     }
// }
