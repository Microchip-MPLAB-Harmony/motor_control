import { Divider } from 'primereact/divider';
import { ReactComponent as MotorControlAndDiagnosis } from '../../../../Resources/Svgs/ControlBlock/Motor_Control_and_Diagnosis-main_diagram.svg';

import { useEffect, useState } from 'react';
import {
  ResetDialogSettings,
  GetResetToDefaultStatus,
  GetResetStatus
} from '../../CustomPopUp/CustomPopUp';
import { ShowConfigProps } from '../../../Tools/NodeUtils';
import { getIndex } from '../../../Tools/CommonUtil';
import MotorModeSelection from './MotorModeSelection';
import { addEventListeners } from '../../../Tools/svg/Svgscripts';
import RamProfileSection from './RamProfileSection';
import MCDiagnosisCommonConfigBackCalCulation from './MCDiagnosisCommonConfigBackCalCulation';
import EnableFIeldWeaking from './EnableFIeldWeaking';

var svgdoc: any = null;
let childAndParent = new Map<any, any>();
let svgAndToolTipObject = new Map<any, any>();

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

const MotorControlandDiagnosis = (props: {
  componentId: string;
  showToast: (arg0: any) => void;
  dialogVisibleStatus: boolean;
}) => {
  useEffect(() => {
    if (!props.dialogVisibleStatus) {
      svgdoc = null;
      childAndParent.clear();
      svgAndToolTipObject.clear();
      return;
    }
    if (svgdoc === null) {
      RegisterMotorDiagnosisSVGActions();
      return;
    }
  });

  const [currentView, setCurrentView] = useState(defaultViewGlobal);

  function RegisterMotorDiagnosisSVGActions() {
    svgdoc = document.getElementById('MotorControlAndDiagnosis');
    let toolTipObject = svgdoc.getElementById('tooltip');
    svgAndToolTipObject.set(svgdoc, toolTipObject);
    actionIds.forEach(function (value) {
      let group = svgdoc.getElementById(value);
      let tooltip = group.getAttribute('harmony-tooltip');
      addEventListeners(
        svgdoc,
        value,
        tooltip,
        true,
        sendClickAction,
        childAndParent,
        svgAndToolTipObject
      );
    });
  }

  function sendClickAction(evt: { target: any }) {
    let target = evt.target;
    if (target.correspondingUseElement) target = target.correspondingUseElement;
    if (target.value) {
      defaultViewGlobal = target.value;
      ResetDialogSettings();
      setCurrentView(defaultViewGlobal);
      return;
    }
  }

  return (
    <div>
      <div className='card'>
        <div className='flex flex-row'>
          <div className='flex flex-column'>
            <label /> <br></br>
            <MotorModeSelection componentId={props.componentId} />
            <label /> <br></br>
            <MotorControlAndDiagnosis id='MotorControlAndDiagnosis' />
          </div>
          <Divider layout='vertical' />

          {getIndex(currentView, actionIds) === 0 && (
            <RamProfileSection
              componentId={props.componentId}
              showToast={props.showToast}
            />
          )}
          {getIndex(currentView, actionIds) === 1 && (
            <EnableFIeldWeaking
              componentId={props.componentId}
              showToast={props.showToast}
            />
          )}
          {getIndex(currentView, actionIds) === 2 && (
            <MCDiagnosisCommonConfigBackCalCulation
              title='Speed Controller'
              componentId={props.componentId}
              showToast={props.showToast}
              symbolsArray={speedPIParametersArray}
            />
          )}
          {getIndex(currentView, actionIds) === 3 && (
            <MCDiagnosisCommonConfigBackCalCulation
              title='D-Axis Current Controller'
              componentId={props.componentId}
              showToast={props.showToast}
              symbolsArray={directAxisCurrentPIParametersSymbols}
            />
          )}
          {getIndex(currentView, actionIds) === 4 && (
            <MCDiagnosisCommonConfigBackCalCulation
              title='Q-Axis Current Controller'
              componentId={props.componentId}
              showToast={props.showToast}
              symbolsArray={quadratureAxisCurrentPISymbols}
            />
          )}
          {getIndex(currentView, actionIds) === 5 && (
            <MCDiagnosisCommonConfigBackCalCulation
              title='Position Controller'
              componentId={props.componentId}
              showToast={props.showToast}
              symbolsArray={positionControlPIParametersSymbols}
            />
          )}
          {getIndex(currentView, actionIds) === 6 && (
            <ShowConfigProps
              title='PWM Modulator'
              componentId={props.componentId}
              showToast={props.showToast}
              symbolsArray={pwmModulatorSymbols}
            />
          )}
          {getIndex(currentView, actionIds) === 7 && (
            <ShowConfigProps
              title='Decoupling Network'
              componentId={props.componentId}
              showToast={props.showToast}
              symbolsArray={decoupleNetworkSymbols}
            />
          )}
        </div>
      </div>
    </div>
  );
};
export default MotorControlandDiagnosis;

export function SetMotorControlDiagnosisDefaultWindowView() {
  if (GetResetToDefaultStatus() || GetResetStatus()) {
    return;
  }
  defaultViewGlobal = actionIds[0];
}
