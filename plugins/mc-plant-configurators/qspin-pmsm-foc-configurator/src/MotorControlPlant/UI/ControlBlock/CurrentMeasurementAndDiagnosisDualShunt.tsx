import { Divider } from 'primereact/divider';
import { ReactComponent as CurrentMeasurementAndDiagnosisDualShuntSVG } from '../../../Resources/Svgs/ControlBlock/Current_Measurement_and_Diagnosis-Dual_Shunt.svg';

import { useEffect, useState } from 'react';
import {
  GetResetStatus,
  GetResetToDefaultStatus,
  ResetDialogSettings
} from '../CustomPopUp/CustomPopUp';
import { getIndex } from '../../Tools/CommonUtil';
import { ShowConfigProps } from '../../Tools/NodeUtils';
import { addEventListeners } from '../../Tools/svg/Svgscripts';

var svgdoc: any = null;
var toolTipObject: any = null;
let childAndParent = new Map<any, any>();
let svgAndToolTipObject = new Map<any, any>();
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

const CurrentMeasurementAndDiagnosisDualShunt = (props: {
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
      RegisterCurrentMesasurementSVGActions();
      return;
    }
  });
  const [currentView, setCurrentView] = useState(defaultViewGlobal);

  function RegisterCurrentMesasurementSVGActions() {
    svgdoc = document.getElementById('CurrentMeasurementAndDiagnosisDualShuntSVG');
    toolTipObject = svgdoc.getElementById('tooltip');
    svgAndToolTipObject.set(svgdoc, toolTipObject);
    actionIds.forEach(function (value) {
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
      <div className='flex flex-row'>
        <CurrentMeasurementAndDiagnosisDualShuntSVG id='CurrentMeasurementAndDiagnosisDualShuntSVG' />
        <Divider layout='vertical' />
        {getIndex(currentView, actionIds) === 0 && (
          <ShowConfigProps
            title='Offset Correction'
            componentId={props.componentId}
            showToast={props.showToast}
            symbolsArray={offsetCorrectionSymbolArray}
          />
        )}
        {(getIndex(currentView, actionIds) === 1 || getIndex(currentView, actionIds) === 2) && (
          <ShowConfigProps
            title='Current Scaling'
            componentId={props.componentId}
            showToast={props.showToast}
            symbolsArray={currentScalingSymbolArray}
          />
        )}
        {getIndex(currentView, actionIds) === 3 && (
          <ShowConfigProps
            title='Diagnosis'
            componentId={props.componentId}
            showToast={props.showToast}
            symbolsArray={diagnosisSymbolArray}
          />
        )}
      </div>
    </div>
  );
};
export default CurrentMeasurementAndDiagnosisDualShunt;

export function SetCurrentMeasurementDefaultWindowView() {
  if (GetResetToDefaultStatus() || GetResetStatus()) {
    return;
  }
  defaultViewGlobal = actionIds[0];
}
