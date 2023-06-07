import { Divider } from 'primereact/divider';
import { ReactComponent as CurrentMeasurementAndDiagnosisDualShuntSVG } from '../../../Resources/Svgs/ControlBlock/Current_Measurement_and_Diagnosis-Dual_Shunt.svg';

import React from 'react';
import {
  DialogCommonInitilizeCode,
  GetResetStatus,
  GetResetToDefaultStatus,
  ResetDialogSettings
} from '../CustomPopUp/CustomPopUp';
import { AddTitleAndParameters } from '@mplab_harmony/harmony-plugin-ui/build/utils/NodeUtils';
import { mc_component_id } from '../MainView/MainBlock';
import { getIndex } from '@mplab_harmony/harmony-plugin-ui/build/utils/CommonUtil';
import {
  CallMouseLeave,
  CallMouseMove
} from '@mplab_harmony/harmony-plugin-ui/build/svg/MouseEvent';

var svgdoc: any = null;
var toolTipObject: any = null;
let actionIds = [
  'box-offset-correction',
  'box-current-scaling-bottom',
  'box-current-scaling-top',
  'box-diagnosis'
];
let defaultViewGlobal = actionIds[0];

let offsetCorrectionSymbolArray = [
  'MCPMSMFOC_OFFSET_CORRECTION_ALGORITHM',
  'MCPMSMFOC_OFFSET_CORRECTION_SAMPLE'
];
let currentScalingSymbolArray = [
  'MCPMSMFOC_CURRENT_SCALING_FORMAT',
  'MCPMSMFOC_CURRENT_SCALING_FACTORT'
];
let diagnosisSymbolArray = [
  'MCPMSMFOC_CURRENT_OOR',
  'MCPMSMFOC_CURRENT_OOR_MAXIMUM',
  'MCPMSMFOC_CURRENT_OOR_DEBOUNCE',
  'MCPMSMFOC_CURRENT_OOR_FAULT_TYPE',
  'MCPMSMFOC_OFFSET_OOR',
  'MCPMSMFOC_OFFSET_OOR_MAXIMUM',
  'MCPMSMFOC_OFFSET_OOR_MINIMUM',
  'MCPMSMFOC_OFFSET_OOR_DEBOUNCE',
  'MCPMSMFOC_OFFSET_OOR_FAULT_TYPE'
];

interface IProps {
  showToast: (arg0: any) => void;
}

interface IState {
  selectedBoxView?: string;
}
let obj: CurrentMeasurementAndDiagnosisDualShunt | null = null;

class CurrentMeasurementAndDiagnosisDualShunt extends React.Component<IProps, IState> {
  constructor(props: IProps) {
    super(props);

    this.state = {
      selectedBoxView: defaultViewGlobal
    };
    this.boxViewChanged = this.boxViewChanged.bind(this);
    obj = this;
  }

  boxViewChanged(actionId: string) {
    this.setState({ selectedBoxView: actionId });
  }

  symbolValueChanged(onChangeData: Map<String, any>) {
    // do nothing
  }

  OffsetCorrection() {
    DialogCommonInitilizeCode(this.props.showToast, offsetCorrectionSymbolArray);
    return (
      <div>
        <AddTitleAndParameters
          Headding='Offset Correction'
          SymbolsArray={offsetCorrectionSymbolArray}
          component_id={mc_component_id}
          onChange={this.symbolValueChanged}
        />
      </div>
    );
  }

  CurrentScaling() {
    DialogCommonInitilizeCode(this.props.showToast, currentScalingSymbolArray);
    return (
      <div>
        <AddTitleAndParameters
          Headding='Current Scaling'
          onChange={this.symbolValueChanged}
          SymbolsArray={currentScalingSymbolArray}
          component_id={mc_component_id}
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
          onChange={this.symbolValueChanged}
          SymbolsArray={diagnosisSymbolArray}
          component_id={mc_component_id}
        />
      </div>
    );
  }

  render() {
    return (
      <div>
        <div className='flex flex-row'>
          <CurrentMeasurementAndDiagnosisDualShuntSVG id='CurrentMeasurementAndDiagnosisDualShuntSVG' />
          <Divider layout='vertical' />
          {getIndex(defaultViewGlobal, actionIds) === 0 && this.OffsetCorrection()}
          {(getIndex(defaultViewGlobal, actionIds) === 1 ||
            getIndex(defaultViewGlobal, actionIds) === 2) &&
            this.CurrentScaling()}
          {getIndex(defaultViewGlobal, actionIds) === 3 && this.Diagnosis()}
        </div>
      </div>
    );
  }
}
export default CurrentMeasurementAndDiagnosisDualShunt;

export function SetCurrentMeasurementDefaultWindowView() {
  if (GetResetToDefaultStatus() || GetResetStatus()) {
    return;
  }
  defaultViewGlobal = actionIds[0];
}

export function RegisterCurrentMesasurementSVGActions() {
  svgdoc = document.getElementById('CurrentMeasurementAndDiagnosisDualShuntSVG');
  actionIds.forEach(function (value) {
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
    obj?.boxViewChanged(defaultViewGlobal);
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
