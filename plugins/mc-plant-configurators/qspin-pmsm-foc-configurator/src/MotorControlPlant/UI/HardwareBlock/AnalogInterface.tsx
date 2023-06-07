import { Divider } from 'primereact/divider';
import { ReactComponent as AnalogInterfaceGroup } from '../../../Resources/Svgs/HardwareBlock/AnalogInterface-group1.svg';

import React from 'react';
import {
  DialogCommonInitilizeCode,
  GetResetStatus,
  GetResetToDefaultStatus,
  ResetDialogSettings
} from '../CustomPopUp/CustomPopUp';
import { AddDynamicSymbols } from '@mplab_harmony/harmony-plugin-core-service/build/database-access/SymbolUtils';
import {
  AddImageAndParameters,
  AddTitileOnly
} from '@mplab_harmony/harmony-plugin-ui/build/utils/NodeUtils';
import { getIndex } from '@mplab_harmony/harmony-plugin-ui/build/utils/CommonUtil';
import {
  CallMouseLeave,
  CallMouseMove
} from '@mplab_harmony/harmony-plugin-ui/build/svg/MouseEvent';
import { GetSymbolValue } from '@mplab_harmony/harmony-plugin-core-service/build/database-access/SymbolAccess';

let svgGroup1: any = null;
let svgGroup2: any = null;

let childAndParent = new Map<any, any>();
let svgAndToolTipObject = new Map<any, any>();

let mc_component_id = 'pmsm_foc';

let actionIds = ['ai_item1', 'ai_item2'];
let defaultViewGlobal = actionIds[0];
let screenChangeStatus = 'true';

let Group1_A_ADC_Unit = 'MCPMSMFOC_PHASE_CURRENT_IA_UNIT';
let Group1_B_ADC_Unit = 'MCPMSMFOC_PHASE_CURRENT_IB_UNIT';
let Group2_A_ADC_Unit = 'MCPMSMFOC_BUS_VOLTAGE_VDC_UNIT';
let Group2_B_ADC_Unit = 'MCPMSMFOC_POTENTIOMETER_VPOT_UNIT';

let GROUP1_A = ['MCPMSMFOC_PHASE_CURRENT_IA_NAME', Group1_A_ADC_Unit];
let GROUP1_B = ['MCPMSMFOC_PHASE_CURRENT_IB_NAME', Group1_B_ADC_Unit];
let GROUP2_A = ['MCPMSMFOC_BUS_VOLTAGE_VDC_NAME', Group2_A_ADC_Unit];
let GROUP2_B = ['MCPMSMFOC_POTENTIOMETER_VPOT_NAME', Group2_B_ADC_Unit];

GROUP1_A = AddDynamicSymbols(mc_component_id, Group1_A_ADC_Unit, 'PHASE_CURRENT_IA', GROUP1_A);
GROUP1_B = AddDynamicSymbols(mc_component_id, Group1_B_ADC_Unit, 'PHASE_CURRENT_IB', GROUP1_B);
GROUP2_A = AddDynamicSymbols(mc_component_id, Group2_A_ADC_Unit, 'BUS_VOLTAGE_VDC', GROUP2_A);
GROUP2_B = AddDynamicSymbols(mc_component_id, Group2_B_ADC_Unit, 'POTENTIOMETER_VPOT', GROUP2_B);

interface IProps {
  showToast: (arg0: any) => void;
}

interface IState {
  currentView?: string;
  count?: any;
  hasRendered?: string;
}
let obj: AnalogInterface | null = null;

class AnalogInterface extends React.Component<IProps, IState> {
  constructor(props: IProps) {
    super(props);
    this.state = {
      currentView: defaultViewGlobal,
      count: 0,
      hasRendered: screenChangeStatus
    };
    this.currentViewChanged = this.currentViewChanged.bind(this);
    this.SymbolValueChanged = this.SymbolValueChanged.bind(this);
    obj = this;
  }

  currentViewChanged(newView: string) {
    this.setState({ currentView: newView });
  }

  SymbolValueChanged(onchange: Map<String, any>) {
    //do nothing
  }

  GetDynamicSymbolId(component_id: string, symbol: string, apend: string) {
    let symbolValue = GetSymbolValue(component_id, symbol);
    return symbol + '_' + apend + '_' + symbolValue;
  }

  Default_ICON1_1() {
    DialogCommonInitilizeCode(this.props.showToast, GROUP1_A.concat(GROUP1_B));
    return (
      <div>
        <AddTitileOnly Headding='Group 01 Signals' />
        <AddImageAndParameters
          Image={null}
          Headding='Signal A Configuration'
          SymbolsArray={GROUP1_A}
          onChange={this.SymbolValueChanged}
          component_id={mc_component_id}
        />
        <AddImageAndParameters
          Image={null}
          Headding='Signal B Configuration'
          onChange={this.SymbolValueChanged}
          component_id={mc_component_id}
          SymbolsArray={GROUP1_B}
        />
      </div>
    );
  }

  Default_ICON1_2() {
    DialogCommonInitilizeCode(this.props.showToast, GROUP2_A.concat(GROUP2_B));
    return (
      <div>
        <AddTitileOnly Headding='Group 02 Signals' />
        <AddImageAndParameters
          Image={null}
          Headding='Signal A Configuration'
          SymbolsArray={GROUP2_A}
          onChange={this.SymbolValueChanged}
          component_id={mc_component_id}
        />
        <AddImageAndParameters
          Image={null}
          Headding='Signal B Configuration'
          SymbolsArray={GROUP2_B}
          onChange={this.SymbolValueChanged}
          component_id={mc_component_id}
        />
      </div>
    );
  }

  render() {
    return (
      <div>
        <div className='card'>
          {/* <div className="p-d-flex" > */}
          <div className='flex'>
            <AnalogInterfaceGroup id='AanlogInterfaceGroup1' />
            <AnalogInterfaceGroup id='AanlogInterfaceGroup2' />
            <Divider layout='vertical' />

            {getIndex(defaultViewGlobal, actionIds) === 0 && this.Default_ICON1_1()}
            {getIndex(defaultViewGlobal, actionIds) === 1 && this.Default_ICON1_2()}
          </div>
        </div>
      </div>
    );
  }
}
export default AnalogInterface;

export function SetAnalogInterfaceDefaultWindowView() {
  if (GetResetToDefaultStatus() || GetResetStatus()) {
    return;
  }
  defaultViewGlobal = actionIds[0];
}

export function RegisterAnalogInterfaceSVGActions() {
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
    addEventListeners(valueAndSVG.get(value), value, tooltip, true);
    let toolTipObject = valueAndSVG.get(value).getElementById('tooltip');
    svgAndToolTipObject.set(valueAndSVG.get(value), toolTipObject);
  });
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

function addEventListeners(svg: any, groupid: any, dialogHeading: string, popupType: boolean) {
  let group = svg.getElementById(groupid);
  IterateSVGelements(svg, group, groupid, dialogHeading, popupType);
}
function IterateSVGelements(
  svg: any,
  group: any,
  groupid: any,
  dialogHeading: string,
  popupType: boolean
) {
  for (let i = 0; i < group.childNodes.length; i++) {
    let childElement = group.childNodes[i];
    childElement.addEventListener('click', sendClickAction, false);
    childElement.addEventListener('mousemove', mouseMove);
    childElement.addEventListener('mouseleave', mouseLeave);
    childAndParent.set(childElement, svg);
    if (popupType) {
      childElement.value = groupid;
    }
    childElement.toolTip = dialogHeading;
    if (childElement.childNodes.length > 0) {
      IterateSVGelements(svg, childElement, groupid, dialogHeading, popupType);
    }
  }
}

function ChangeGroup2_Data(group: any) {
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
}

function mouseMove(evt: { target: any }) {
  CallMouseMove(
    evt,
    childAndParent.get(evt.target),
    svgAndToolTipObject.get(childAndParent.get(evt.target))
  );
}

function mouseLeave(evt: { target: any }) {
  CallMouseLeave(evt, svgAndToolTipObject.get(childAndParent.get(evt.target)));
}
