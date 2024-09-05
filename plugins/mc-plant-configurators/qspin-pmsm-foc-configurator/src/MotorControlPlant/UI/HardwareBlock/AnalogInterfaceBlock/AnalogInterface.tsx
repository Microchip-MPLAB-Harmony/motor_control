import { Divider } from 'primereact/divider';
import { ReactComponent as AnalogInterfaceGroup } from '../../../../Resources/Svgs/HardwareBlock/AnalogInterface-group1.svg';

import { useEffect, useState } from 'react';
import {
  GetResetStatus,
  GetResetToDefaultStatus,
  ResetDialogSettings
} from '../../CustomPopUp/CustomPopUp';
import { getIndex } from '../../../Tools/CommonUtil';
import DefaultIcon1 from './DefaultIcon1';
import DefaultIcon2 from './DefaultIcon2';
import { addEventListeners } from '../../../Tools/svg/Svgscripts';

let svgGroup1: any = null;
let svgGroup2: any = null;

let childAndParent = new Map<any, any>();
let svgAndToolTipObject = new Map<any, any>();

let actionIds = ['ai_item1', 'ai_item2'];
let defaultViewGlobal = actionIds[0];

let Group1PhaseA: any[];
let Group1PhaseB: any[];
let Group2PhaseA: any[];
let Group2PhaseB: any[];

const AnalogInterfaceFunctional = (props: {
  componentId: string;
  showToast: (arg0: any) => void;
  dialogVisibleStatus: boolean;
}) => {
  useEffect(() => {
    if (!props.dialogVisibleStatus) {
      svgGroup1 = null;
      svgGroup2 = null;
      childAndParent.clear();
      svgAndToolTipObject.clear();
      return;
    }
    if (svgGroup1 === null) {
      RegisterAnalogInterfaceSVGActions();
      return;
    }
  });
  const [currentView, setCurrentView] = useState(defaultViewGlobal);
  Group1PhaseA = [
    'MCPMSMFOC_PHASE_CURRENT_IA_NAME',
    'MCPMSMFOC_PHASE_CURRENT_IA_UNIT',
    'MCPMSMFOC_PHASE_CURRENT_IA_CHANNEL',
    'MCPMSMFOC_PHASE_CURRENT_IA_PAD'
  ];
  Group1PhaseB = [
    'MCPMSMFOC_PHASE_CURRENT_IB_NAME',
    'MCPMSMFOC_PHASE_CURRENT_IB_UNIT',
    'MCPMSMFOC_PHASE_CURRENT_IB_CHANNEL',
    'MCPMSMFOC_PHASE_CURRENT_IB_PAD'
  ];
  Group2PhaseA = [
    'MCPMSMFOC_BUS_VOLTAGE_VDC_NAME',
    'MCPMSMFOC_BUS_VOLTAGE_VDC_UNIT',
    'MCPMSMFOC_BUS_VOLTAGE_VDC_CHANNEL',
    'MCPMSMFOC_BUS_VOLTAGE_VDC_PAD'
  ];
  Group2PhaseB = [
    'MCPMSMFOC_POTENTIOMETER_VPOT_NAME',
    'MCPMSMFOC_POTENTIOMETER_VPOT_UNIT',
    'MCPMSMFOC_POTENTIOMETER_VPOT_CHANNEL',
    'MCPMSMFOC_POTENTIOMETER_VPOT_PAD'
  ];

  function RegisterAnalogInterfaceSVGActions() {
    svgGroup1 = document.getElementById('AanlogInterfaceGroup1');
    svgGroup2 = document.getElementById('AanlogInterfaceGroup2');
    let group2 = svgGroup2.getElementById('ai_item1');
    group2.setAttribute('id', 'ai_item2');
    ChangeGroup2_Data(group2);
    let valueAndSVG = new Map<string, any>();
    valueAndSVG.set(actionIds[0], svgGroup1);
    valueAndSVG.set(actionIds[1], svgGroup2);
    actionIds.forEach(function (value) {
      let tooltip = 'View Group Properties';
      let toolTipObject = valueAndSVG.get(value).getElementById('tooltip');
      svgAndToolTipObject.set(valueAndSVG.get(value), toolTipObject);
      addEventListeners(
        valueAndSVG.get(value),
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
      ResetDialogSettings();
      defaultViewGlobal = target.value;
      setCurrentView(defaultViewGlobal);
      return;
    }
  }

  function ChangeGroup2_Data(group: any) {
    try {
      for (let i = 0; i < group.childNodes.length; i++) {
        let childElement = group.childNodes[i];
        if (childElement.getAttribute('id') === 'labels_ai_item1') {
          ChangeGroup2_Data(childElement);
          return;
        }
        if (childElement.getAttribute('id') === 'label_input1_ai_item1') {
          childElement.textContent = 'VdcSens';
        } else if (childElement.getAttribute('id') === 'label_input2_ai_item1') {
          childElement.textContent = 'VpotSens';
        } else if (childElement.getAttribute('id') === 'label_group_ai_item1') {
          childElement.textContent = 'Group 02 Signals';
        }
      }
    } catch {}
  }

  return (
    <div>
      <div className='card'>
        <div className='flex'>
          <AnalogInterfaceGroup id='AanlogInterfaceGroup1' />
          <AnalogInterfaceGroup id='AanlogInterfaceGroup2' />
          <Divider layout='vertical' />
          {getIndex(currentView, actionIds) === 0 && (
            <DefaultIcon1
              componentId={props.componentId}
              showToast={props.showToast}
              Group1PhaseA={Group1PhaseA}
              Group1PhaseB={Group1PhaseB}
            />
          )}
          {getIndex(currentView, actionIds) === 1 && (
            <DefaultIcon2
              componentId={props.componentId}
              showToast={props.showToast}
              Group2PhaseA={Group2PhaseA}
              Group2PhaseB={Group2PhaseB}
            />
          )}
        </div>
      </div>
    </div>
  );
};
export default AnalogInterfaceFunctional;

export function SetAnalogInterfaceDefaultWindowView() {
  if (GetResetToDefaultStatus() || GetResetStatus()) {
    return;
  }
  defaultViewGlobal = actionIds[0];
}
