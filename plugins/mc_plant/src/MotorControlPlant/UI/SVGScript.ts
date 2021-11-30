import React from "react";
import ReactDOM from "react-dom";
import { CallMouseLeave, CallMouseMove } from "../Common/MouseEvent";
import { RegisterMotorDiagnosisSVGActions } from "./ControlBlock/MotorControlandDiagnosis";
import { RegisterAnalogFrontEndSVGActions } from "./HardwareBlock/AnalogFrontEnd";
import DialogDemo from "./CustomPopUp/CustomPopUp";
import { StartUpConfiguratorLoad } from "./CustomPopUp/CustomPopUp";
import { RegisterAnalogInterfaceSVGActions } from "./HardwareBlock/AnalogInterface";
import { RegisterPositionControlDiagnosisSVGActions } from "./ControlBlock/PositionMesurementAndDiagnosis";
import { RegisterVoltageMesasurementSVGActions } from "./ControlBlock/VoltageMeasurementDiagnosis";
import { RegisterCurrentMesasurementSVGActions } from "./ControlBlock/CurrentMeasurementAndDiagnosisDualShunt";

let svgdoc: any = null;
let toolTipObject: any = null;

let childKeyAndGroupIdValue = new Map<string, string>();

export let hardWareGroup = "group_hardware";
export let controlGroup = "group_control";
export let peripheralGroup = "group_peripheral";
export let mcuGroup = "group_mcu_config";

export let groupArray = [
  hardWareGroup,
  controlGroup,
  peripheralGroup,
  mcuGroup,
];

let ribbonKeyAndGroupValue = new Map<string, string>();

export function newInit() {
  svgdoc = document.getElementById("motor");

  let ribbon_hardware = "ribbon_hardware";
  let ribbon_control = "ribbon_control";
  let ribbon_peripheral = "ribbon_peripheral";
  let ribbon_mcu_config = "ribbon_mcu_config";

  ribbonKeyAndGroupValue.set(ribbon_hardware, hardWareGroup);
  ribbonKeyAndGroupValue.set(ribbon_control, controlGroup);
  ribbonKeyAndGroupValue.set(ribbon_peripheral, peripheralGroup);
  ribbonKeyAndGroupValue.set(ribbon_mcu_config, mcuGroup);

  addEventListeners("box_quicksettings", "Quick Settings", true);
  addEventListeners(ribbon_hardware, "Hardware Configurations", false);
  addEventListeners(ribbon_control, "Control Configurations", false);
  addEventListeners(ribbon_peripheral, "Peripheral Configurations", false);
  addEventListeners(ribbon_mcu_config, "MCU Configurations", false);

  addEventListeners("box_analog_frontend", "Analog Front End", true);
  addEventListeners("box_motor", "Motor Parameters", true);
  addEventListeners("box_startup_configurator", "Start Up Configurator", true);
  addEventListeners(
    "box_motor_control_diagnosis",
    "Motor Control Diagnosis",
    true
  );
  addEventListeners("box_output_stage", "Output Stage Diagnosis", true);
  addEventListeners(
    "box_position_calculation_diagnosis",
    "Position Calculation Diagnosis",
    true
  );
  addEventListeners(
    "box_current_measurement_diagnosis",
    "Current Measurement Diagnosis",
    true
  );
  addEventListeners(
    "box_voltage_measurement_diagnosis",
    "Voltage Measurement Diagnosis",
    true
  );
  addEventListeners("box_pwm", "Pulse With Modulator", true);
  addEventListeners("box_analog_interface", "Analog Interface", true);
  addEventListeners("box_position_interface", "Position Interface", true);
  addEventListeners("box_vdc", "Voltage Source", true);
  addEventListeners("box_data_monitoring", "Data Monitoring", true);
  // alert(GetTooltipObject())
    //  svgdoc.appendChild(GetTooltipObject())
  toolTipObject = svgdoc.getElementById("tooltip");

  storeComponentColors();
}

function addEventListeners(
  groupid: any,
  dialogHeading: string,
  popupType: boolean
) {
  let group = svgdoc.getElementById(groupid);
  IterateSVGElements(group, groupid, dialogHeading, popupType);
}

function IterateSVGElements(
  group: any,
  groupid: any,
  dialogHeading: string,
  popupType: boolean
) {
  for (let i = 0; i < group.childNodes.length; i++) {
    let childElement = group.childNodes[i];
    childElement.addEventListener("click", sendClickAction, false);
    childElement.addEventListener("mousemove", mouseMove);
    childElement.addEventListener("mouseleave", mouseLeave);
    if (popupType) {
      childElement.value = dialogHeading;
    }
    childElement.toolTip = "View " + dialogHeading + " Configuration";
    if (childElement.childNodes.length > 0) {
      IterateSVGElements(childElement, groupid, dialogHeading, popupType);
    }else{
      try {
        if(childElement.hasAttribute("id")){
          let childId = childElement.getAttribute("id");
          childKeyAndGroupIdValue.set(childId, groupid);
        }
      }
      catch(err) {
      }
    }
  }
}

function mouseMove(evt: { target: any }) {
  CallMouseMove(evt, svgdoc, toolTipObject);
}

function mouseLeave(evt: { target: any }) {
  CallMouseLeave(evt, toolTipObject);
}

function storeComponentColors() {
  let myNodelist = svgdoc.querySelectorAll("*");
  let i;
  for (i = 0; i < myNodelist.length; i++) {
    if (myNodelist[i].style) {
      myNodelist[i].myParm2 = myNodelist[i].style.fill;
    } else if (myNodelist[i].getAttribute("fill")) {
      myNodelist[i].myParm2 = myNodelist[i].getAttribute("fill");
    }
  }
}

function sendClickAction(evt: { target: any }) {
  let target = evt.target;
  if (target.correspondingUseElement) target = target.correspondingUseElement;

  if (target.value && target.value === "Motor Control Diagnosis") {
    callPopUp(DialogDemo, target.value);
    RegisterMotorDiagnosisSVGActions();
    return;
  }else if (target.value && target.value === "Position Calculation Diagnosis") {
    callPopUp(DialogDemo, target.value);
    RegisterPositionControlDiagnosisSVGActions();
    return;
  } else if (target.value && target.value === "Analog Front End") {
    callPopUp(DialogDemo, target.value);
    RegisterAnalogFrontEndSVGActions();
    return;
  } else if (target.value && target.value === "Analog Interface") {
    callPopUp(DialogDemo, target.value);
    RegisterAnalogInterfaceSVGActions();
    return;
  } else if (target.value && target.value === "Voltage Measurement Diagnosis") {
    callPopUp(DialogDemo, target.value);
    RegisterVoltageMesasurementSVGActions();
    return;
  } else if (target.value && target.value === "Current Measurement Diagnosis") {
    callPopUp(DialogDemo, target.value);
    RegisterCurrentMesasurementSVGActions();
    return;
  }else if (target.value) {
    callPopUp(DialogDemo, target.value);
    return;
  }
  let value: string = childKeyAndGroupIdValue.get(target.id) || "";
  if (value !== null) {
    MainBlockControlAction(value);
  }
}

export function MainBlockControlAction(clickedRibbon: string) {
  if (clickedRibbon == null) {
    return;
  }

  resetColors();

  let i;
  for (i = 0; i < groupArray.length; i++) {
    let group = groupArray[i];
    alert(clickedRibbon);
    if (group !== ribbonKeyAndGroupValue.get(clickedRibbon)) {
      let element = svgdoc.getElementById(group);
      changeColor(element);
    }
  }
}

function changeColor(group: any) {
  for (let i = 0; i < group.childNodes.length; i++) {
    let element = group.childNodes[i];
    if (element.nodeType !== 3) {
      if (element.childNodes.length !== 0) {
        changeColor(element);
      } else if (
        (element.tagName === "rect" ||
          element.tagName === "path" ||
          element.tagName === "circle") &&
        element.id !== ""
      ) {
        if (element && element.getAttribute("fill")) {
          element.setAttribute("fill", "#757575");
        } else if (element && element.getAttribute("style")) {
          element.style.fill = "#757575";
        }
      }
    }
  }
}

function callPopUp(Component: any, action_id: any) {
  const helloCreate = React.createElement(Component);
  StartUpConfiguratorLoad(action_id);
  ReactDOM.render(helloCreate, document.querySelector("#popup"));
}

function resetColors() {
  let myNodelist = svgdoc.querySelectorAll("*");
  let i;
  for (i = 0; i < myNodelist.length; i++) {
    if (myNodelist[i].style) {
      myNodelist[i].style.fill = myNodelist[i].myParm2;
    } else if (myNodelist[i].getAttribute("fill")) {
      myNodelist[i].setAttribute("fill", myNodelist[i].myParm2);
    }
  }
}
function GetTooltipObject(): any {
  throw new Error("Function not implemented.");
}

