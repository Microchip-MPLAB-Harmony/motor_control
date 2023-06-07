import { Divider } from 'primereact/divider';
import { ReactComponent as VoltageMeasurementDiagnosisSVG } from '../../../Resources/Svgs/ControlBlock/Voltage_Measurement_and_Diagnosis-main_diagram.svg';
import {
  DialogCommonInitilizeCode,
  GetResetStatus,
  GetResetToDefaultStatus,
  ResetDialogSettings
} from '../CustomPopUp/CustomPopUp';

import React from 'react';
import { AddTitleAndParameters } from '@mplab_harmony/harmony-plugin-ui/build/utils/NodeUtils';
import { mc_component_id } from '../MainView/MainBlock';
import { getIndex } from '@mplab_harmony/harmony-plugin-ui/build/utils/CommonUtil';
import {
  CallMouseLeave,
  CallMouseMove
} from '@mplab_harmony/harmony-plugin-ui/build/svg/MouseEvent';

var svgdoc: any = null;
var toolTipObject: any = null;
let actionIds = ['box-voltagescaling', 'box-processing', 'box-diagnosis'];
let defaultViewGlobal = actionIds[0];

let voltageScallingSymbolArray = [
  'MCPMSMFOC_VOLTAGE_SCALING_FORMAT',
  'MCPMSMFOC_VOLTAGE_SCALING_FACTORT'
];
let processingSymbolArray = ['MCPMSMFOC_VOLTAGE_PROCESSING'];
let diagnosisSymbolArray = [
  'MCPMSMFOC_OVER_VOLTAGE',
  'MCPMSMFOC_OVER_VOLTAGE_LIMIT',
  'MCPMSMFOC_OVER_VOLTAGE_DEBOUNCE',
  'MCPMSMFOC_OVER_VOLTAGE_FAULT_TYPE',
  'MCPMSMFOC_UNDER_VOLTAGE',
  'MCPMSMFOC_UNDER_VOLTAGE_LIMIT',
  'MCPMSMFOC_UNDER_VOLTAGE_DEBOUNCE',
  'MCPMSMFOC_UNDER_VOLTAGE_FAULT_TYPE'
];

interface IProps {
  showToast: (arg0: any) => void;
}

interface IState {
  currentView?: string;
}
let obj: VoltageMeasurementDiagnosis | null = null;

class VoltageMeasurementDiagnosis extends React.Component<IProps, IState> {
  constructor(props: IProps) {
    super(props);

    this.state = {
      currentView: defaultViewGlobal
    };
    this.currentViewChanged = this.currentViewChanged.bind(this);
    obj = this;
  }

  currentViewChanged(newView: string) {
    this.setState({ currentView: newView });
  }

  SymbolValueChanged(onchange: Map<String, any>) {
    // do nothing
  }

  VoltageScalling() {
    DialogCommonInitilizeCode(this.props.showToast, voltageScallingSymbolArray);
    return (
      <div>
        <AddTitleAndParameters
          Headding='Voltage Scaling'
          onChange={this.SymbolValueChanged}
          component_id={mc_component_id}
          SymbolsArray={voltageScallingSymbolArray}
        />
      </div>
    );
  }

  Processing() {
    DialogCommonInitilizeCode(this.props.showToast, processingSymbolArray);
    return (
      <div>
        <AddTitleAndParameters
          Headding='Processing'
          onChange={this.SymbolValueChanged}
          component_id={mc_component_id}
          SymbolsArray={processingSymbolArray}
        />
      </div>
    );
  }

  Diagnosis() {
    DialogCommonInitilizeCode(this.props.showToast, diagnosisSymbolArray);
    return (
      <div>
        <AddTitleAndParameters
          Headding='Diagnosis'
          onChange={this.SymbolValueChanged}
          component_id={mc_component_id}
          SymbolsArray={diagnosisSymbolArray}
        />
      </div>
    );
  }

  render() {
    return (
      <div>
        <div className='card'>
          <div className='flex'>
            <div className='flex-column'>
              <VoltageMeasurementDiagnosisSVG id='VoltageMeasurementDiagnosis' />
            </div>
            <Divider layout='vertical' />
            {getIndex(defaultViewGlobal, actionIds) === 0 && this.VoltageScalling()}
            {getIndex(defaultViewGlobal, actionIds) === 1 && this.Processing()}
            {getIndex(defaultViewGlobal, actionIds) === 2 && this.Diagnosis()}
          </div>
        </div>
      </div>
    );
  }
}
export default VoltageMeasurementDiagnosis;

export function SetVoltageMeasurementDefaultWindowView() {
  if (GetResetToDefaultStatus() || GetResetStatus()) {
    return;
  }
  defaultViewGlobal = actionIds[0];
}

export function RegisterVoltageMesasurementSVGActions() {
  svgdoc = document.getElementById('VoltageMeasurementDiagnosis');
  actionIds.forEach(function (value) {
    // let group = svgdoc.getElementById(value);
    let tooltip = 'Configure Parameters';
    addEventListeners(value, tooltip, true);
  });
  toolTipObject = svgdoc.getElementById('tooltip');
}

function sendClickAction(evt: { target: any }) {
  let target = evt.target;
  if (target.correspondingUseElement) target = target.correspondingUseElement;
  if (target.value) {
    defaultViewGlobal = target.value;
    ResetDialogSettings();
    obj?.currentViewChanged(defaultViewGlobal);
    return;
  }
}

function addEventListeners(groupid: any, dialogHeading: string, popupType: boolean) {
  let group = svgdoc.getElementById(groupid);
  IterateSVGelements(group, groupid, dialogHeading, popupType);
}
function IterateSVGelements(group: any, groupid: any, dialogHeading: string, popupType: boolean) {
  for (let i = 0; i < group.childNodes.length; i++) {
    let childElement = group.childNodes[i];
    childElement.addEventListener('click', sendClickAction, false);
    childElement.addEventListener('mousemove', mouseMove);
    childElement.addEventListener('mouseleave', mouseLeave);
    if (popupType) {
      childElement.value = groupid;
    }
    childElement.toolTip = dialogHeading;
    if (childElement.childNodes.length > 0) {
      IterateSVGelements(childElement, groupid, dialogHeading, popupType);
    }
  }
}

function mouseMove(evt: { target: any }) {
  CallMouseMove(evt, svgdoc, toolTipObject);
}

function mouseLeave(evt: { target: any }) {
  CallMouseLeave(evt, toolTipObject);
}
