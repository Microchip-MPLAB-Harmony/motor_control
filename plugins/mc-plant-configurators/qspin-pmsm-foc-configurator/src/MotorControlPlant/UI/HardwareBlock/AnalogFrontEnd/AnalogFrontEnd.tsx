import { Divider } from 'primereact/divider';
import { ReactComponent as AnalogFrontendSVGIcon1 } from '../../../../Resources/Svgs/HardwareBlock/AnalogFrontend-item1.svg';
import { ReactComponent as AnalogFrontendSVGIcon2 } from '../../../../Resources/Svgs/HardwareBlock/AnalogFrontend-item2.svg';

import {
  GetResetStatus,
  GetResetToDefaultStatus,
  ResetDialogSettings
} from '../../CustomPopUp/CustomPopUp';
import { getIndex } from '../../../Tools/CommonUtil';
import { useEffect, useState } from 'react';
import DefaultICON11 from './DefaultICON11';
import DefaultICON12 from './DefaultICON12';
import DefaultICON21 from './DefaultICON21';
import { addEventListeners } from '../../../Tools/svg/Svgscripts';

let svgIcon1_1: any = null;
let svgdocIcon1_2: any = null;
let svgdocIcon2: any = null;

let actionIds = ['af_item1', 'af_item1_2', 'af_item2'];
let defaultViewGlobal = actionIds[0];

let childAndParent = new Map<any, any>();
let svgAndToolTipObject = new Map<any, any>();

let Defautl_ICON1_1_Array = [
  'MCPMSMFOC_ANALOG_FRONT_END_IA_OPAMP',
  'MCPMSMFOC_ANALOG_FRONT_END_IA_GAIN',
  'MCPMSMFOC_ANALOG_FRONT_END_IA_OFFSET',
  'MCPMSMFOC_ANALOG_FRONT_END_IA_SHUNT'
];
let Defautl_ICON1_2_Array = [
  'MCPMSMFOC_ANALOG_FRONT_END_IB_OPAMP',
  'MCPMSMFOC_ANALOG_FRONT_END_IB_GAIN',
  'MCPMSMFOC_ANALOG_FRONT_END_IB_OFFSET',
  'MCPMSMFOC_ANALOG_FRONT_END_IB_SHUNT'
];
// let Defautl_ICON2_1_Array_Current = [
//   'MCPMSMFOC_ANALOG_FRONT_END_IDC_OPAMP',
//   'MCPMSMFOC_ANALOG_FRONT_END_IDC_GAIN',
//   'MCPMSMFOC_ANALOG_FRONT_END_IDC_OFFSET',
//   'MCPMSMFOC_ANALOG_FRONT_END_IDC_SHUNT'
// ];

let Defautl_ICON2_1_Array_Voltage = [
  'MCPMSMFOC_ANALOG_FRONT_END_VDC_TOP_RES',
  'MCPMSMFOC_ANALOG_FRONT_END_VDC_BOTTOM_RES',
  'MCPMSMFOC_DC_BUS_RATIO'
];

const AnalogFrontEnd = (props: {
  componentId: string;
  showToast: (arg0: any) => void;
  dialogVisibleStatus: boolean;
}) => {
  useEffect(() => {
    if (!props.dialogVisibleStatus) {
      svgIcon1_1 = null;
      svgdocIcon1_2 = null;
      svgdocIcon2 = null;
      childAndParent.clear();
      svgAndToolTipObject.clear();
      return;
    }
    if (svgIcon1_1 === null) {
      RegisterAnalogFrontEndSVGActions();
      return;
    }
  });
  const [currentView, setCurrentView] = useState(defaultViewGlobal);

  function RegisterAnalogFrontEndSVGActions() {
    svgIcon1_1 = document.getElementById('AnalogFrontendSVG1_1');
    svgdocIcon1_2 = document.getElementById('AnalogFrontendSVG1_2');
    svgdocIcon2 = document.getElementById('AnalogFrontendSVG2');
    let icon1_2 = svgdocIcon1_2.getElementById('af_item1');
    icon1_2.setAttribute('id', 'af_item1_2');
    ChangeIcon1_2_Data(icon1_2);
    let valueAndSVG = new Map<string, any>();
    valueAndSVG.set(actionIds[0], svgIcon1_1);
    valueAndSVG.set(actionIds[1], svgdocIcon1_2);
    valueAndSVG.set(actionIds[2], svgdocIcon2);
    actionIds.forEach(function (value) {
      let tooltip = 'View Icon Properties';
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
    });
  }

  function ChangeIcon1_2_Data(group: any) {
    try {
      for (let i = 0; i < group.childNodes.length; i++) {
        let childElement = group.childNodes[i];
        if (childElement.getAttribute('id') === 'labels_af_item1') {
          ChangeIcon1_2_Data(childElement);
          return;
        }
        if (childElement.getAttribute('id') === 'label_input1_af_item1') {
          childElement.textContent = 'Iu (+)';
        } else if (childElement.getAttribute('id') === 'label_input2_af_item1') {
          childElement.textContent = 'Iu (-)';
        } else if (childElement.getAttribute('id') === 'label_output_af_item1') {
          childElement.textContent = 'IuSens';
        }
      }
    } catch {}
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
            <div className='flex'>
              <div className='mr-4'>
                <AnalogFrontendSVGIcon1 id='AnalogFrontendSVG1_1' />
              </div>
              <AnalogFrontendSVGIcon1 id='AnalogFrontendSVG1_2' />
            </div>
            <div className='mt-auto'>
              <AnalogFrontendSVGIcon2 id='AnalogFrontendSVG2' />
            </div>
          </div>
          <Divider layout='vertical' />
          {getIndex(currentView, actionIds) === 0 && (
            <DefaultICON11
              componentId={props.componentId}
              showToast={props.showToast}
              Defautl_ICON1_1_Array={Defautl_ICON1_1_Array}
            />
          )}
          {getIndex(currentView, actionIds) === 1 && (
            <DefaultICON12
              componentId={props.componentId}
              showToast={props.showToast}
              Defautl_ICON1_2_Array={Defautl_ICON1_2_Array}
            />
          )}
          {getIndex(currentView, actionIds) === 2 && (
            <DefaultICON21
              componentId={props.componentId}
              showToast={props.showToast}
              Defautl_ICON2_1_Array_Voltage={Defautl_ICON2_1_Array_Voltage}
            />
          )}
        </div>
      </div>
    </div>
  );
};
export default AnalogFrontEnd;

export function SetAnalogFrontEndDefaultWindowView() {
  if (GetResetToDefaultStatus() || GetResetStatus()) {
    return;
  }
  defaultViewGlobal = actionIds[0];
}
