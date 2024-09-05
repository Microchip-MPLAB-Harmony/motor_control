import { Divider } from 'primereact/divider';
import { ReactComponent as VoltageMeasurementDiagnosisSVG } from '../../../../Resources/Svgs/ControlBlock/Voltage_Measurement_and_Diagnosis-main_diagram.svg';
import {
  GetResetStatus,
  GetResetToDefaultStatus,
  ResetDialogSettings
} from '../../CustomPopUp/CustomPopUp';

import { useEffect, useState } from 'react';
import { getIndex } from '../../../Tools/CommonUtil';
import { addEventListeners } from '../../../Tools/svg/Svgscripts';
import VoltageScalling from './VoltageScalling';
import Processing from './Processing';
import Diagnosis from './Diagnosis';

let svgdoc: any = null;
let toolTipObject: any = null;

let childAndParent = new Map<any, any>();
let svgAndToolTipObject = new Map<any, any>();

let actionIds = ['box-voltagescaling', 'box-processing', 'box-diagnosis'];
let defaultViewGlobal = actionIds[0];

let voltageScallingSymbolArray = [
  'MCPMSMFOC_VOLTAGE_SCALING_FORMAT',
  'MCPMSMFOC_VOLTAGE_SCALING_FACTORT',
  'MCPMSMFOC_ADC_TO_VOLTS_FACTORT'
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

const VoltageMeasurementDiagnosis = (props: {
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
      RegisterVoltageMesasurementSVGActions();
      return;
    }
  });
  const [currentView, setCurrentView] = useState(defaultViewGlobal);

  function RegisterVoltageMesasurementSVGActions() {
    svgdoc = document.getElementById('VoltageMeasurementDiagnosis');
    toolTipObject = svgdoc.getElementById('tooltip');
    svgAndToolTipObject.set(svgdoc, toolTipObject);
    actionIds.forEach(function (value) {
      // let group = svgdoc.getElementById(value);
      let tooltip = 'Configure Parameters';
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
        <div className='flex'>
          <div className='flex-column'>
            <VoltageMeasurementDiagnosisSVG id='VoltageMeasurementDiagnosis' />
          </div>
          <Divider layout='vertical' />
          {getIndex(currentView, actionIds) === 0 && (
            <VoltageScalling
              componentId={props.componentId}
              showToast={props.showToast}
              voltageScallingSymbolArray={voltageScallingSymbolArray}
            />
          )}
          {getIndex(currentView, actionIds) === 1 && (
            <Processing
              componentId={props.componentId}
              showToast={props.showToast}
              processingSymbolArray={processingSymbolArray}
            />
          )}
          {getIndex(currentView, actionIds) === 2 && (
            <Diagnosis
              componentId={props.componentId}
              showToast={props.showToast}
              diagnosisSymbolArray={diagnosisSymbolArray}
            />
          )}
        </div>
      </div>
    </div>
  );
};
export default VoltageMeasurementDiagnosis;

export function SetVoltageMeasurementDefaultWindowView() {
  if (GetResetToDefaultStatus() || GetResetStatus()) {
    return;
  }
  defaultViewGlobal = actionIds[0];
}
