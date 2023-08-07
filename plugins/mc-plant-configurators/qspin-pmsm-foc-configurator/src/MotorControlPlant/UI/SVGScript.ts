import React from 'react';
import ReactDOM from 'react-dom/client';
import { RegisterMotorDiagnosisSVGActions } from './ControlBlock/MotorControlandDiagnosis';
import { RegisterAnalogFrontEndSVGActions } from './HardwareBlock/AnalogFrontEnd';
import DialogDemo, { CustomPopUpLoadConfig } from './CustomPopUp/CustomPopUp';
import PopUpWithoutFooter, { PopupWithoutFooterInput } from './CustomPopUp/PopUpWithoutFooter';
import { RegisterAnalogInterfaceSVGActions } from './HardwareBlock/AnalogInterface';
import { RegisterPositionControlDiagnosisSVGActions } from './ControlBlock/PositionMesurementAndDiagnosis';
import { RegisterVoltageMesasurementSVGActions } from './ControlBlock/VoltageMeasurementDiagnosis';
import { RegisterCurrentMesasurementSVGActions } from './ControlBlock/CurrentMeasurementAndDiagnosisDualShunt';
import {
  CallMouseLeave,
  CallMouseMove
} from '@mplab_harmony/harmony-plugin-ui/build/svg/MouseEvent';

let svgdoc: any = null;
let toolTipObject: any = null;

let childKeyAndGroupIdValue = new Map<string, string>();

export let hardWareGroup = 'group_hardware';
export let controlGroup = 'group_control';
export let peripheralGroup = 'group_peripheral';
export let mcuGroup = 'group_mcu_config';

export let groupArray = [hardWareGroup, controlGroup, peripheralGroup, mcuGroup];

let ribbonKeyAndGroupValue = new Map<string, string>();
export let quickSettingsText = 'Quick Settings';
export let analogFrontEndText = 'Analog Front End';
export let motorParameters = 'Motor Parameters';
export let startupConfiguratorText = 'Start Up Configurator';
export let motorControlDiagnosisText = 'Motor Control & Diagnosis';
export let positionMeasurementCalculationText = 'Position Calculation & Diagnosis';
export let currentMeasurementAndDiagnosisText = 'Current Measurement & Diagnosis';
export let voltageMeasurementAndDiagnosisText = 'Voltage Measurement & Diagnosis';
export let pulseWidthModulatorText = 'Pulse Width Modulator';
export let analogInterfaceText = 'Analog Interface';
export let positionInterfaceText = 'Position Interface';
export let voltageSourceText = 'Voltage Source';
export let dataMonitoringText = 'Data Monitoring';
export let outputStageDignosisText = 'Output Stage Diagnosis';

export const popUproot = ReactDOM.createRoot(document.querySelector('#popup') as HTMLElement);

export function newInit() {
  svgdoc = document.getElementById('motor');

  let ribbon_hardware = 'ribbon_hardware';
  let ribbon_control = 'ribbon_control';
  let ribbon_peripheral = 'ribbon_peripheral';
  let ribbon_mcu_config = 'ribbon_mcu_config';

  ribbonKeyAndGroupValue.set(ribbon_hardware, hardWareGroup);
  ribbonKeyAndGroupValue.set(ribbon_control, controlGroup);
  ribbonKeyAndGroupValue.set(ribbon_peripheral, peripheralGroup);
  ribbonKeyAndGroupValue.set(ribbon_mcu_config, mcuGroup);

  addEventListeners('box_quicksettings', quickSettingsText, true);
  addEventListeners(ribbon_hardware, 'Hardware Configurations', false);
  addEventListeners(ribbon_control, 'Control Configurations', false);
  addEventListeners(ribbon_peripheral, 'Peripheral Configurations', false);
  addEventListeners(ribbon_mcu_config, 'MCU Configurations', false);

  addEventListeners('box_analog_frontend', analogFrontEndText, true);
  addEventListeners('box_motor', motorParameters, true);
  addEventListeners('box_startup_configurator', startupConfiguratorText, true);
  addEventListeners('box_motor_control_diagnosis', motorControlDiagnosisText, true);
  addEventListeners('box_output_stage', outputStageDignosisText, true);
  addEventListeners('box_position_calculation_diagnosis', positionMeasurementCalculationText, true);
  addEventListeners('box_current_measurement_diagnosis', currentMeasurementAndDiagnosisText, true);
  addEventListeners('box_voltage_measurement_diagnosis', voltageMeasurementAndDiagnosisText, true);
  addEventListeners('box_pwm', pulseWidthModulatorText, true);
  addEventListeners('box_analog_interface', analogInterfaceText, true);
  addEventListeners('box_position_interface', positionInterfaceText, true);
  addEventListeners('box_vdc', voltageSourceText, true);
  addEventListeners('box_data_monitoring', dataMonitoringText, true);

  addEventListeners('box_clock_manager', 'Clock Manager', true);
  addEventListeners('box_io_manager', 'IO Manager', true);
  addEventListeners('box_interrupts_exception', 'Interrupts Exception Manager', true);
  addEventListeners('box_memory_manager', 'Memory Control Manager', true);

  toolTipObject = svgdoc.getElementById('tooltip');

  storeComponentColors();
}

function addEventListeners(groupid: any, dialogHeading: string, popupType: boolean) {
  let group = svgdoc.getElementById(groupid);
  IterateSVGElements(group, groupid, dialogHeading, popupType);
}

function IterateSVGElements(group: any, groupid: any, dialogHeading: string, popupType: boolean) {
  for (let i = 0; i < group.childNodes.length; i++) {
    let childElement = group.childNodes[i];
    childElement.addEventListener('click', sendClickAction, false);
    childElement.addEventListener('mousemove', mouseMove);
    childElement.addEventListener('mouseleave', mouseLeave);
    if (popupType) {
      childElement.value = dialogHeading;
    }
    childElement.toolTip = 'View ' + dialogHeading + ' Configuration';
    if (childElement.childNodes.length > 0) {
      IterateSVGElements(childElement, groupid, dialogHeading, popupType);
    }
    try {
      if (childElement.hasAttribute('id')) {
        let childId = childElement.getAttribute('id');
        childKeyAndGroupIdValue.set(childId, groupid);
      }
    } catch (err) {}
  }
}

function mouseMove(evt: { target: any }) {
  CallMouseMove(evt, svgdoc, toolTipObject);
}

function mouseLeave(evt: { target: any }) {
  CallMouseLeave(evt, toolTipObject);
}

function storeComponentColors() {
  let myNodelist = svgdoc.querySelectorAll('*');
  let i;
  for (i = 0; i < myNodelist.length; i++) {
    if (myNodelist[i].style) {
      myNodelist[i].myParm2 = myNodelist[i].style.fill;
    } else if (myNodelist[i].getAttribute('fill')) {
      myNodelist[i].myParm2 = myNodelist[i].getAttribute('fill');
    }
  }
}

function sendClickAction(evt: { target: any }) {
  let target = evt.target;
  if (target.correspondingUseElement) target = target.correspondingUseElement;

  if (target.value && target.value === motorControlDiagnosisText) {
    callPopUp(DialogDemo, target.value, '95rem', '60rem');
    setTimeout(() => {
      RegisterMotorDiagnosisSVGActions();
    }, 1000);
    return;
  } else if (target.value && target.value === positionMeasurementCalculationText) {
    callPopUp(DialogDemo, target.value, '98rem', '50rem');
    setTimeout(() => {
      RegisterPositionControlDiagnosisSVGActions();
    }, 1000);
    return;
  } else if (target.value && target.value === analogFrontEndText) {
    callPopUp(DialogDemo, target.value, '75rem', '40rem');
    setTimeout(() => {
      RegisterAnalogFrontEndSVGActions();
    }, 1000);
    return;
  } else if (target.value && target.value === analogInterfaceText) {
    callPopUp(DialogDemo, target.value, '70rem', '42rem');
    setTimeout(() => {
      RegisterAnalogInterfaceSVGActions();
    }, 1000);
    return;
  } else if (target.value && target.value === voltageMeasurementAndDiagnosisText) {
    callPopUp(DialogDemo, target.value, '80rem', '35rem');
    setTimeout(() => {
      RegisterVoltageMesasurementSVGActions();
    }, 1000);
    return;
  } else if (target.value && target.value === currentMeasurementAndDiagnosisText) {
    callPopUp(DialogDemo, target.value, '85rem', '40rem');
    setTimeout(() => {
      RegisterCurrentMesasurementSVGActions();
    }, 1000);
    return;
  } else if (target.value && target.value === 'Clock Manager') {
    callPopUpWithOutFooter(
      PopUpWithoutFooter,
      target.value,
      'To configure Clock Manager, Please goto "Project Graph/plugins/Clock Manager" '
    );
    return;
  } else if (target.value && target.value === 'IO Manager') {
    callPopUpWithOutFooter(
      PopUpWithoutFooter,
      target.value,
      'To configure IO Manager, Please goto "Project Graph/plugins/PIN Manager" '
    );
    return;
  } else if (target.value && target.value === 'Interrupts Exception Manager') {
    callPopUpWithOutFooter(
      PopUpWithoutFooter,
      target.value,
      'To configure Interrupts Exception Manager, Please goto "Project Graph/plugins/NVIC Configuration" '
    );
    return;
  } else if (target.value && target.value === 'Memory Control Manager') {
    callPopUpWithOutFooter(
      PopUpWithoutFooter,
      target.value,
      'To configure Memory Control Manager, Please goto "Project Graph/plugins/MPU Configuration" '
    );
    return;
  } else if (target.value === motorParameters) {
    callPopUp(DialogDemo, target.value, '50rem', '50rem');
    return;
  } else if (target.value === pulseWidthModulatorText) {
    callPopUp(DialogDemo, target.value, '70rem', '45rem');
    return;
  } else if (target.value === positionInterfaceText) {
    callPopUp(DialogDemo, target.value, '30rem', '30rem');
    return;
  } else if (target.value === outputStageDignosisText) {
    callPopUp(DialogDemo, target.value, '45rem', '20rem');
    return;
  } else if (target.value === startupConfiguratorText) {
    callPopUp(DialogDemo, target.value, '90rem', '60rem');
    return;
  } else if (target.value === quickSettingsText) {
    callPopUp(DialogDemo, target.value, '40rem', '25rem');
    return;
  } else if (target.value === dataMonitoringText) {
    callPopUp(DialogDemo, target.value, '35rem', '20rem');
    return;
  } else if (target.value === voltageSourceText) {
    callPopUp(DialogDemo, target.value, '35rem', '20rem');
    return;
  } else if (target.value) {
    callPopUp(DialogDemo, target.value, '80rem', '70rem');
    return;
  }
  let value: string = childKeyAndGroupIdValue.get(target.id) || '';
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
        (element.tagName === 'rect' ||
          element.tagName === 'path' ||
          element.tagName === 'circle') &&
        element.id !== ''
      ) {
        if (element && element.getAttribute('fill')) {
          element.setAttribute('fill', '#757575');
        } else if (element && element.getAttribute('style')) {
          element.style.fill = '#757575';
        }
      }
    }
  }
}

function callPopUp(Component: any, action_id: any, width: any, height: any) {
  const element = React.createElement(Component);
  CustomPopUpLoadConfig(action_id, width, height);
  popUproot.render(element);
}

function callPopUpWithOutFooter(Component: any, action_id: any, message: string) {
  const element = React.createElement(Component);
  PopupWithoutFooterInput(action_id, message, '50rem', '15rem');
  popUproot.render(element);
}

export function resetColors() {
  let myNodelist = svgdoc.querySelectorAll('*');
  let i;
  for (i = 0; i < myNodelist.length; i++) {
    if (myNodelist[i].style) {
      myNodelist[i].style.fill = myNodelist[i].myParm2;
    } else if (myNodelist[i].getAttribute('fill')) {
      myNodelist[i].setAttribute('fill', myNodelist[i].myParm2);
    }
  }
}
