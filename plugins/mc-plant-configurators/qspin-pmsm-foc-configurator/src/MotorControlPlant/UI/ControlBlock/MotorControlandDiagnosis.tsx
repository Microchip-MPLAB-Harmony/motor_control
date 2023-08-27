import { Divider } from 'primereact/divider';
import { ReactComponent as MotorControlAndDiagnosis } from '../../../Resources/Svgs/ControlBlock/Motor_Control_and_Diagnosis-main_diagram.svg';
import PI_Parameters_Back_Calculation from '../../../Resources/Svgs/ControlBlock/Motor_Control_and_Diagnosis-PI_parameters-Back_Calculation.svg';
import Linear from '../../../Resources/Svgs/ControlBlock/Motor_Control_and_Diagnosis-Ramp_Profiler-Linear.svg';
import SCurve from '../../../Resources/Svgs/ControlBlock/Motor_Control_and_Diagnosis-Ramp_Profiler-SCurve.svg';
import Step from '../../../Resources/Svgs/ControlBlock/Motor_Control_and_Diagnosis-Ramp_Profiler-Step.svg';

import React from 'react';
import {
  DialogCommonInitilizeCode,
  ResetDialogSettings,
  GetResetToDefaultStatus,
  GetResetStatus
} from '../CustomPopUp/CustomPopUp';
import { mc_component_id } from '../MainView/MainBlock';
import {
  GetSymbolArray,
  GetSymbolLabelName,
  GetSymbolReadOnlyStatus,
  GetSymbolValue
} from '@mplab_harmony/harmony-plugin-core-service/build/database-access/SymbolAccess';
import { getIndex } from '@mplab_harmony/harmony-plugin-ui/build/utils/CommonUtil';
import {
  AddImageAndParameters,
  LoadImage
} from '@mplab_harmony/harmony-plugin-ui/build/utils/NodeUtils';
import {
  GetUIComponentWithLabel,
  GetUIComponentWithOutLabel
} from '@mplab_harmony/harmony-plugin-ui/build/components/Components';
import {
  AddMultipleUIComponentsWithLabel,
  CallMouseMove,
  CheckBox,
  StateLabel
} from '@mplab_harmony/harmony-plugin-ui';
import { CallMouseLeave } from '@mplab_harmony/harmony-plugin-ui/build/svg/MouseEvent';

var svgdoc: any = null;
var toolTipObject: any = null;
let actionIds = [
  'box-ramp-profiler',
  'box-fw-mtpa',
  'box-sl-pid',
  'box-foc-pid-direct',
  'box-foc-pid-quadrature',
  'box-pl-pid',
  'box-pwm-modulator',
  'box-decouple-network'
];
let defaultViewGlobal = actionIds[0];

interface IProps {
  showToast: (arg0: any) => void;
}

interface IState {
  motorControlModeSelectedValue?: any;
  ramProfilerSelectedValue?: any;
  currentView?: string;
}
let obj: MotorControlandDiagnosis | null = null;

let motorControlModeSymbol = 'MCPMSMFOC_CONTROL_TYPE';
let ramProfilerSelectSymbol = 'MCPMSMFOC_RAMP_PROFILES';
let ramProfilerSymbols2 = [
  'MCPMSMFOC_RAMP_PROFILER_RAMP_TIME',
  'MCPMSMFOC_RAMP_PROFILER_MAX_SPEED',
  'MCPMSMFOC_RAMP_PROFILER_MAX_ACCEL'
];

let ramProfilerSymbolCollection = [ramProfilerSelectSymbol];

ramProfilerSymbolCollection = ramProfilerSymbolCollection.concat(ramProfilerSymbols2);

let fieldWeakeningSymbols = [
  'MCPMSMFOC_ENABLE_FW',
  'MCPMSMFOC_FW_MAX_NEGATIVE_ID',
  'MCPMSMFOC_FW_TUNING_PARAMETER',
  'MCPMSMFOC_ENABLE_MTPA',
  'MCPMSMFOC_MTPA_TUNING_PARAMETER'
];

let speedPIParametersArray = [
  'MCPMSMFOC_SPEED_PID_AW',
  'MCPMSMFOC_SPEED_PID_KP',
  'MCPMSMFOC_SPEED_PID_KI',
  'MCPMSMFOC_SPEED_PID_KV',
  'MCPMSMFOC_SPEED_PID_KC',
  'MCPMSMFOC_SPEED_PID_YIMAX',
  'MCPMSMFOC_SPEED_PID_YMAX'
];

let quadratureAxisCurrentPISymbols = [
  'MCPMSMFOC_IQ_PID_AW',
  'MCPMSMFOC_IQ_PID_KP',
  'MCPMSMFOC_IQ_PID_KI',
  'MCPMSMFOC_IQ_PID_KV',
  'MCPMSMFOC_IQ_PID_KC',
  'MCPMSMFOC_IQ_PID_YIMAX',
  'MCPMSMFOC_IQ_PID_YMAX'
];

let directAxisCurrentPIParametersSymbols = [
  'MCPMSMFOC_ID_PID_AW',
  'MCPMSMFOC_ID_PID_KP',
  'MCPMSMFOC_ID_PID_KI',
  'MCPMSMFOC_ID_PID_KV',
  'MCPMSMFOC_ID_PID_KC',
  'MCPMSMFOC_ID_PID_YIMAX',
  'MCPMSMFOC_ID_PID_YMAX'
];

let positionControlPIParametersSymbols = [
  'MCPMSMFOC_POSITION_PID_AW',
  'MCPMSMFOC_POSITION_PID_KP',
  'MCPMSMFOC_POSITION_PID_KI',
  'MCPMSMFOC_POSITION_PID_KV',
  'MCPMSMFOC_POSITION_PID_KC',
  'MCPMSMFOC_POSITION_PID_YIMAX',
  'MCPMSMFOC_POSITION_PID_YMAX'
];

let pwmModulatorSymbols = [
  'MCPMSMFOC_OVER_MODULATION',
  'MCPMSMFOC_MODULATION_TECHNIQUE',
  'MCPMSMFOC_SPACE_VECTOR_LIMIT'
];

let decoupleNetworkSymbols = ['MCPMSMFOC_ENABLE_DECOUPLING'];
let motorBasedDesignSymbolId = 'MCPMSMFOC_FOC_X2C_ENABLE';

class MotorControlandDiagnosis extends React.Component<IProps, IState> {
  constructor(props: IProps) {
    super(props);

    this.state = {
      currentView: defaultViewGlobal,
      motorControlModeSelectedValue: GetSymbolValue(mc_component_id, motorControlModeSymbol),
      ramProfilerSelectedValue: GetSymbolValue(mc_component_id, ramProfilerSelectSymbol)
    };
    this.MotorControlChanged = this.MotorControlChanged.bind(this);
    this.RamProfileChanged = this.RamProfileChanged.bind(this);
    this.currentViewChanged = this.currentViewChanged.bind(this);
    obj = this;
  }
  ramProfilerSelectArray = GetSymbolArray(mc_component_id, ramProfilerSelectSymbol);

  currentViewChanged(newView: string) {
    this.setState({ currentView: newView });
  }

  RamProfileChanged(onChangeData: Map<String, any>) {
    this.setState({ ramProfilerSelectedValue: onChangeData.get('symbolValue') });
  }

  MotorControlChanged(onChangeData: Map<String, any>) {
    // this.setState({ motorControlModeSelectedValue: onChangeData.get('symbolValue') });
  }

  SymbolValueChanged(onchange: Map<String, any>) {
    // do nothing
  }

  ramProfilerData() {
    DialogCommonInitilizeCode(this.props.showToast, ramProfilerSymbolCollection);
    return (
      <div>
        {getIndex(this.state.ramProfilerSelectedValue, this.ramProfilerSelectArray) === 0 &&
          LoadImage(Step)}
        {getIndex(this.state.ramProfilerSelectedValue, this.ramProfilerSelectArray) === 1 &&
          LoadImage(Linear)}
        {getIndex(this.state.ramProfilerSelectedValue, this.ramProfilerSelectArray) === 2 &&
          LoadImage(SCurve)}
        <br></br> <span style={{ fontWeight: 'bold' }}> Ramp Profiler </span> <br></br> <br></br>
        <GetUIComponentWithLabel
          componentId={mc_component_id}
          symbolId={ramProfilerSelectSymbol}
          onChange={this.RamProfileChanged}
          symbolListeners={[ramProfilerSelectSymbol]}
        />
        <AddMultipleUIComponentsWithLabel
          componentId={mc_component_id}
          onChange={this.SymbolValueChanged}
          symbolsArray={ramProfilerSymbols2}
        />
      </div>
    );
  }

  speedPIParameters() {
    DialogCommonInitilizeCode(this.props.showToast, speedPIParametersArray);
    return (
      <div>
        {}
        <AddImageAndParameters
          Image={PI_Parameters_Back_Calculation}
          Headding='Speed Controller'
          onChange={this.SymbolValueChanged}
          component_id={mc_component_id}
          SymbolsArray={speedPIParametersArray}
        />
      </div>
    );
  }

  QuadratureAxisCurrentPIController() {
    DialogCommonInitilizeCode(this.props.showToast, quadratureAxisCurrentPISymbols);
    return (
      <div>
        <AddImageAndParameters
          Image={PI_Parameters_Back_Calculation}
          Headding='Q-Axis Current Controller'
          onChange={this.SymbolValueChanged}
          component_id={mc_component_id}
          SymbolsArray={quadratureAxisCurrentPISymbols}
        />
      </div>
    );
  }

  DirectAxisCurrentPIParameters() {
    DialogCommonInitilizeCode(this.props.showToast, directAxisCurrentPIParametersSymbols);
    return (
      <div>
        <AddImageAndParameters
          Image={PI_Parameters_Back_Calculation}
          Headding='D-Axis Current Controller'
          onChange={this.SymbolValueChanged}
          component_id={mc_component_id}
          SymbolsArray={directAxisCurrentPIParametersSymbols}
        />
      </div>
    );
  }

  PositionControllerPIParameters() {
    DialogCommonInitilizeCode(this.props.showToast, positionControlPIParametersSymbols);
    return (
      <div>
        <AddImageAndParameters
          Image={PI_Parameters_Back_Calculation}
          Headding='Position Controller'
          onChange={this.SymbolValueChanged}
          component_id={mc_component_id}
          SymbolsArray={positionControlPIParametersSymbols}
        />
      </div>
    );
  }

  FWAndMTPA() {
    DialogCommonInitilizeCode(this.props.showToast, fieldWeakeningSymbols);
    return (
      <div>
        <AddImageAndParameters
          Image={null}
          Headding='Field Weakening And MTPA'
          onChange={this.SymbolValueChanged}
          component_id={mc_component_id}
          SymbolsArray={fieldWeakeningSymbols}
        />
      </div>
    );
  }

  PWMModulator() {
    DialogCommonInitilizeCode(this.props.showToast, pwmModulatorSymbols);
    return (
      <div>
        {}
        <AddImageAndParameters
          Image={null}
          Headding='PWM Modulator'
          onChange={this.SymbolValueChanged}
          component_id={mc_component_id}
          SymbolsArray={pwmModulatorSymbols}
        />
      </div>
    );
  }

  DecoupleNetwork() {
    DialogCommonInitilizeCode(this.props.showToast, decoupleNetworkSymbols);
    return (
      <div>
        {}
        <AddImageAndParameters
          Image={null}
          Headding='Decoupling Network'
          onChange={this.SymbolValueChanged}
          component_id={mc_component_id}
          SymbolsArray={decoupleNetworkSymbols}
        />
      </div>
    );
  }

  render() {
    return (
      <div>
        <div className='card'>
          <div className='flex flex-row'>
            <div className='flex flex-column'>
              <label /> <br></br>
              <div className='flex justify-content-between column-gap-4 row-gap-6'>
                <div className='flex'>
                  <div className='m-2'>
                    <StateLabel
                      labelId={motorControlModeSymbol}
                      isSymbolLabelName={true}
                      labelDisplayText={GetSymbolLabelName(mc_component_id, motorControlModeSymbol)}
                    />{' '}
                  </div>
                  <div>
                    <GetUIComponentWithOutLabel
                      componentId={mc_component_id}
                      symbolId={motorControlModeSymbol}
                      onChange={this.MotorControlChanged}
                      symbolListeners={[motorControlModeSymbol]}
                    />
                  </div>
                </div>

                <div className='flex align-items-center'>
                  <CheckBox
                    componentId={mc_component_id}
                    symbolId={motorBasedDesignSymbolId}
                    symbolListeners={[motorBasedDesignSymbolId]}
                    onChange={this.MotorControlChanged}
                    symbolValue={GetSymbolValue(mc_component_id, motorBasedDesignSymbolId)}
                    styleObject={{ width: '20px', height: '20px' }}
                    className={'ml-4'}
                    readOnly={GetSymbolReadOnlyStatus(mc_component_id, motorBasedDesignSymbolId)}
                    visible={true}
                  />
                  <label
                    htmlFor='ingredient1'
                    className='ml-2'
                    style={{ fontWeight: 'bold' }}>
                    Model based design
                  </label>
                </div>
              </div>
              <label /> <br></br>
              <MotorControlAndDiagnosis id='MotorControlAndDiagnosis' />
            </div>
            <Divider layout='vertical' />

            {getIndex(defaultViewGlobal, actionIds) === 0 && this.ramProfilerData()}
            {getIndex(defaultViewGlobal, actionIds) === 1 && this.FWAndMTPA()}
            {getIndex(defaultViewGlobal, actionIds) === 2 && this.speedPIParameters()}
            {getIndex(defaultViewGlobal, actionIds) === 3 && this.DirectAxisCurrentPIParameters()}
            {getIndex(defaultViewGlobal, actionIds) === 4 &&
              this.QuadratureAxisCurrentPIController()}
            {getIndex(defaultViewGlobal, actionIds) === 5 && this.PositionControllerPIParameters()}
            {getIndex(defaultViewGlobal, actionIds) === 6 && this.PWMModulator()}
            {getIndex(defaultViewGlobal, actionIds) === 7 && this.DecoupleNetwork()}
          </div>
        </div>
      </div>
    );
  }
}
export default MotorControlandDiagnosis;

export function SetMotorControlDiagnosisDefaultWindowView() {
  if (GetResetToDefaultStatus() || GetResetStatus()) {
    return;
  }
  defaultViewGlobal = actionIds[0];
}

export function RegisterMotorDiagnosisSVGActions() {
  svgdoc = document.getElementById('MotorControlAndDiagnosis');
  actionIds.forEach(function (value) {
    let group = svgdoc.getElementById(value);
    let tooltip = group.getAttribute('harmony-tooltip');
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
