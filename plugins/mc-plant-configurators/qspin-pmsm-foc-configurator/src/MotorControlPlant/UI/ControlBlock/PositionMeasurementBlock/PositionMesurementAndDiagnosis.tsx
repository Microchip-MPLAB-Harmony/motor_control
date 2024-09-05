import { useEffect, useState } from 'react';

import {
  GetResetStatus,
  GetResetToDefaultStatus,
  ResetDialogSettings
} from '../../CustomPopUp/CustomPopUp';
import { KeyValueSetSymbolHook } from '@mplab_harmony/harmony-plugin-client-lib';
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

const PositionMesurementAndDiagnosis = (props: {
  componentId: string;
  showToast: (arg0: any) => void;
  dialogVisibleStatus: boolean;
  positionSelection: KeyValueSetSymbolHook;
}) => {
  useEffect(() => {
    if (!props.dialogVisibleStatus) {
      svgObj = null;
      childAndParent.clear();
      valueAndSVG.clear();
      svgAndToolTipObject.clear();
      return;
    }
    if (svgObj === null) {
      RegisterPositionControlDiagnosisSVGActions(props.positionSelection.value);
      return;
    }
  });
  useEffect(() => {
    RegisterPositionControlDiagnosisSVGActions(props.positionSelection.value);
    ResetDefaultView(props.positionSelection.value);
  }, [props.positionSelection.value]);

  const [currentView, setCurrentView] = useState(defaultViewGlobal);

  function RegisterPositionControlDiagnosisSVGActions(selectedIndex: any) {
    if (selectedIndex === 0) {
      AddEvents(ebIds, 'PositionMesurementAndDiagnosisEB');
    } else if (selectedIndex === 1) {
      AddEvents(qdIds, 'PositionMesurementAndDiagnosisQD');
    } else if (selectedIndex === 2) {
      AddEvents(roloIds, 'PositionMesurementAndDiagnosisROLO');
    } else if (selectedIndex === 3) {
      AddEvents(smoIds, 'PositionMesurementAndDiagnosisSMO');
    } else if (selectedIndex === 4) {
      AddEvents(zsmtIds, 'PositionMesurementAndDiagnosisZSMTHybrid');
    }
  }

  function ResetDefaultView(selectedIndex: any) {
    if (selectedIndex === 0) {
      setCurrentView(ebIds[0]);
    } else if (selectedIndex === 1) {
      setCurrentView(qdIds[0]);
    } else if (selectedIndex === 2) {
      setCurrentView(roloIds[0]);
    } else if (selectedIndex === 3) {
      setCurrentView(smoIds[0]);
    } else if (selectedIndex === 4) {
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
            positionSelection={props.positionSelection}
          />
        </div>
        {props.positionSelection.value === 0 && (
          <ShowEB
            componentId={props.componentId}
            showToast={props.showToast}
            positionSelection={props.positionSelection}
            currentView={currentView}
            ebIds={ebIds}
          />
        )}
        {props.positionSelection.value === 1 && (
          <ShowQD
            componentId={props.componentId}
            showToast={props.showToast}
            positionSelection={props.positionSelection}
            currentView={currentView}
            qdIds={qdIds}
          />
        )}
        {props.positionSelection.value === 2 && (
          <ShowReducedOrderLuenberger
            componentId={props.componentId}
            showToast={props.showToast}
            positionSelection={props.positionSelection}
            currentView={currentView}
            roloIds={roloIds}
          />
        )}
        {props.positionSelection.value === 3 && (
          <ShowSMO
            componentId={props.componentId}
            showToast={props.showToast}
            positionSelection={props.positionSelection}
            currentView={currentView}
            smoIds={smoIds}
          />
        )}
        {props.positionSelection.value === 4 && (
          <ShowZSMTHybrid
            componentId={props.componentId}
            showToast={props.showToast}
            positionSelection={props.positionSelection}
            currentView={currentView}
            zsmtIds={zsmtIds}
          />
        )}
      </div>
    </div>
  );
};
export default PositionMesurementAndDiagnosis;

export function SetPositionControlDiagnosisDefaultWindowView(positionSelectedIndex: number) {
  if (GetResetToDefaultStatus() || GetResetStatus()) {
    return;
  }
  ResetDefaultView(positionSelectedIndex);
}
export function ResetDefaultView(selectedIndex: any) {
  if (selectedIndex === 0) {
    defaultViewGlobal = ebIds[0];
  } else if (selectedIndex === 1) {
    defaultViewGlobal = qdIds[0];
  } else if (selectedIndex === 2) {
    defaultViewGlobal = roloIds[0];
  } else if (selectedIndex === 3) {
    defaultViewGlobal = smoIds[0];
  } else if (selectedIndex === 4) {
    defaultViewGlobal = zsmtIds[0];
  }
}
