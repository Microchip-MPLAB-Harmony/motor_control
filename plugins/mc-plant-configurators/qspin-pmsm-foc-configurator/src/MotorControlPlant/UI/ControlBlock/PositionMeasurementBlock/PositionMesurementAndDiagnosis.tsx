import { useEffect, useState } from 'react';

import {
  GetResetStatus,
  GetResetToDefaultStatus,
  ResetDialogSettings
} from '../../CustomPopUp/CustomPopUp';
import { useKeyValueSetSymbol } from '@mplab_harmony/harmony-plugin-client-lib';
import { addEventListeners } from '../../../Tools/svg/Svgscripts';
import ShowEB from './ShowEB';
import ShowQD from './ShowQD';
import ShowReducedOrderLuenberger from './ShowReducedOrderLuenberger';
import ShowSMO from './ShowSMO';
import ShowZSMTHybrid from './ShowZSMTHybrid';
import PositionControlSelection from './PositionControlSelection';

let svgObj: any = null;
let childAndParent = new Map<any, any>();
let valueAndSVG = new Map<any, any>();
let svgAndToolTipObject = new Map<any, any>();
let ebIds = ['box_motor_model', 'box_ab_dq', 'box_lpf_top', 'box_lpf_middle', 'box_lpf_bottom'];
let qdIds = ['box-digitalnoisefilter', 'box-quadraturedecoder'];
let zsmtIds = [
  'box-primary-observer',
  'box-secondary-observer',
  'box-primary-angle-tracker',
  'box-secondary-angle-tracker',
  'box-hysteris-switch'
];
let smoIds = [
  'box-current-observer',
  'box-switching-function',
  'box-bemf-observer',
  'box-flux-angle_calculator'
];
let roloIds = ['box-bemf-observer', 'box-flux-angle-calculation'];

let actionIds = [...ebIds, ...qdIds, ...roloIds, ...zsmtIds, ...smoIds];
let defaultViewGlobal = actionIds[0];
let equactionBasedPLL = 'Equation based PLL';
let quadratureEncoder = 'Quadrature Encoder';
let reducedOrderLuenbergerObserver = 'Reduced Order Luenberger Observer';
let slidingModeObserver = 'Sliding Mode Observer';
let zsmtObserver = 'ZSMT Hybrid';
const PositionMesurementAndDiagnosis = (props: {
  componentId: string;
  showToast: (arg0: any) => void;
  dialogVisibleStatus: boolean;
}) => {
  const positionSelection = useKeyValueSetSymbol({
    componentId: props.componentId,
    symbolId: 'MCPMSMFOC_POSITION_CALC_ALGORITHM'
  });
  useEffect(() => {
    if (!props.dialogVisibleStatus) {
      svgObj = null;
      childAndParent.clear();
      valueAndSVG.clear();
      svgAndToolTipObject.clear();
      return;
    }
    if (svgObj === null) {
      RegisterPositionControlDiagnosisSVGActions(positionSelection.selectedOption);
      return;
    }
  });
  useEffect(() => {
    RegisterPositionControlDiagnosisSVGActions(positionSelection.selectedOption);
    ResetDefaultView(positionSelection.selectedOption);
  }, [positionSelection.selectedOption]);

  const [currentView, setCurrentView] = useState(defaultViewGlobal);

  function RegisterPositionControlDiagnosisSVGActions(selectedValue: string) {
    if (selectedValue.startsWith(equactionBasedPLL)) {
      AddEvents(ebIds, 'PositionMesurementAndDiagnosisEB');
    } else if (selectedValue.startsWith(quadratureEncoder)) {
      AddEvents(qdIds, 'PositionMesurementAndDiagnosisQD');
    } else if (selectedValue.startsWith(reducedOrderLuenbergerObserver)) {
      AddEvents(roloIds, 'PositionMesurementAndDiagnosisROLO');
    } else if (selectedValue.startsWith(slidingModeObserver)) {
      AddEvents(smoIds, 'PositionMesurementAndDiagnosisSMO');
    } else if (selectedValue.startsWith(zsmtObserver)) {
      AddEvents(zsmtIds, 'PositionMesurementAndDiagnosisZSMTHybrid');
    }
  }

  function ResetDefaultView(selectedValue: string) {
    if (selectedValue.startsWith(equactionBasedPLL)) {
      setCurrentView(ebIds[0]);
    } else if (selectedValue.startsWith(quadratureEncoder)) {
      setCurrentView(qdIds[0]);
    } else if (selectedValue.startsWith(reducedOrderLuenbergerObserver)) {
      setCurrentView(roloIds[0]);
    } else if (selectedValue.startsWith(slidingModeObserver)) {
      setCurrentView(smoIds[0]);
    } else if (selectedValue.startsWith(zsmtObserver)) {
      setCurrentView(zsmtIds[0]);
    }
  }

  function AddEvents(array: any, svgObjId: any) {
    svgObj = document.getElementById(svgObjId);
    if (svgObj == null) {
      return;
    }
    for (let i = 0; i < array.length; i++) {
      valueAndSVG.set(array[i], svgObj);
      AddingEvents(array[i]);
    }
  }

  function AddingEvents(value: string) {
    let tooltip = 'Configure Parameters';
    if (value === 'box_motor_model' || value === 'box_ab_dq') {
      tooltip = '';
    }
    let obj = valueAndSVG.get(value).getElementById('tooltip');
    svgAndToolTipObject.set(valueAndSVG.get(value), obj);
    addEventListeners(
      valueAndSVG.get(value),
      value,
      tooltip,
      true,
      sendClickAction,
      childAndParent,
      svgAndToolTipObject
    );
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
      <div className='flex-column'>
        <div className='flex justify-content-start column-gap-4 row-gap-6'>
          <PositionControlSelection
            componentId={props.componentId}
            positionSelection={positionSelection}
          />
        </div>
        {positionSelection.selectedOption.startsWith(equactionBasedPLL) && (
          <ShowEB
            componentId={props.componentId}
            showToast={props.showToast}
            positionSelection={positionSelection}
            currentView={currentView}
            ebIds={ebIds}
          />
        )}
        {positionSelection.selectedOption.startsWith(quadratureEncoder) && (
          <ShowQD
            componentId={props.componentId}
            showToast={props.showToast}
            positionSelection={positionSelection}
            currentView={currentView}
            qdIds={qdIds}
          />
        )}
        {positionSelection.selectedOption.startsWith(reducedOrderLuenbergerObserver) && (
          <ShowReducedOrderLuenberger
            componentId={props.componentId}
            showToast={props.showToast}
            positionSelection={positionSelection}
            currentView={currentView}
            roloIds={roloIds}
          />
        )}
        {positionSelection.selectedOption.startsWith(slidingModeObserver) && (
          <ShowSMO
            componentId={props.componentId}
            showToast={props.showToast}
            positionSelection={positionSelection}
            currentView={currentView}
            smoIds={smoIds}
          />
        )}
        {positionSelection.selectedOption.startsWith(zsmtObserver) && (
          <ShowZSMTHybrid
            componentId={props.componentId}
            showToast={props.showToast}
            positionSelection={positionSelection}
            currentView={currentView}
            zsmtIds={zsmtIds}
          />
        )}
      </div>
    </div>
  );
};
export default PositionMesurementAndDiagnosis;

export function SetPositionControlDiagnosisDefaultWindowView(positionSelectedValue: string) {
  if (GetResetToDefaultStatus() || GetResetStatus()) {
    return;
  }
  ResetDefaultView(positionSelectedValue);
}
export function ResetDefaultView(selectedValue: string) {
  if (selectedValue.startsWith(equactionBasedPLL)) {
    defaultViewGlobal = ebIds[0];
  } else if (selectedValue.startsWith(quadratureEncoder)) {
    defaultViewGlobal = qdIds[0];
  } else if (selectedValue.startsWith(reducedOrderLuenbergerObserver)) {
    defaultViewGlobal = roloIds[0];
  } else if (selectedValue.startsWith(slidingModeObserver)) {
    defaultViewGlobal = smoIds[0];
  } else if (selectedValue.startsWith(zsmtObserver)) {
    defaultViewGlobal = zsmtIds[0];
  }
}
