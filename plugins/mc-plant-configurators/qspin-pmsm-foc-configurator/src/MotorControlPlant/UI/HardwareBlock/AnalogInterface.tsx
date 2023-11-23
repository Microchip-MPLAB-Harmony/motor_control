import { Divider } from 'primereact/divider';
import { ReactComponent as AnalogInterfaceGroup } from '../../../Resources/Svgs/HardwareBlock/AnalogInterface-group1.svg';

import React from 'react';
import {
  DialogCommonInitilizeCode,
  GetResetStatus,
  GetResetToDefaultStatus,
  ResetDialogSettings
} from '../CustomPopUp/CustomPopUp';
import {
  AddImageAndParameters,
  AddTitileOnly
} from '@mplab_harmony/harmony-plugin-ui/build/utils/NodeUtils';
import { getIndex } from '@mplab_harmony/harmony-plugin-ui/build/utils/CommonUtil';
import {
  CallMouseLeave,
  CallMouseMove
} from '@mplab_harmony/harmony-plugin-ui/build/svg/MouseEvent';

let svgGroup1: any = null;
let svgGroup2: any = null;

let childAndParent = new Map<any, any>();
let svgAndToolTipObject = new Map<any, any>();

let mc_component_id = 'pmsm_foc';

let actionIds = ['ai_item1', 'ai_item2'];
let defaultViewGlobal = actionIds[0];
let screenChangeStatus = 'true';

interface IProps {
  showToast: (arg0: any) => void;
}

interface IState {
  currentView?: string;
  count?: any;
  hasRendered?: string;
}
let obj: AnalogInterface | null = null;
let Group1PhaseA: any[];
let Group1PhaseB: any[];
let Group2PhaseA: any[];
let Group2PhaseB: any[];

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
  }

  currentViewChanged(newView: string) {
    this.setState({ currentView: newView });
  }

  SymbolValueChanged(onchange: Map<String, any>) {
    //do nothing
  }

  Default_ICON1_1() {
    DialogCommonInitilizeCode(this.props.showToast, Group1PhaseA.concat(Group1PhaseB));
    return (
      <div>
        <AddTitileOnly Headding='Group 01 Signals' />
        <AddImageAndParameters
          Image={null}
          Headding='Signal A Configuration'
          SymbolsArray={Group1PhaseA}
          onChange={this.SymbolValueChanged}
          component_id={mc_component_id}
        />
        <AddImageAndParameters
          Image={null}
          Headding='Signal B Configuration'
          onChange={this.SymbolValueChanged}
          component_id={mc_component_id}
          SymbolsArray={Group1PhaseB}
        />
      </div>
    );
  }

  Default_ICON1_2() {
    DialogCommonInitilizeCode(this.props.showToast, Group2PhaseA.concat(Group2PhaseB));
    return (
      <div>
        <AddTitileOnly Headding='Group 02 Signals' />
        <AddImageAndParameters
          Image={null}
          Headding='Signal A Configuration'
          SymbolsArray={Group2PhaseA}
          onChange={this.SymbolValueChanged}
          component_id={mc_component_id}
        />
        <AddImageAndParameters
          Image={null}
          Headding='Signal B Configuration'
          SymbolsArray={Group2PhaseB}
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
  try {
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
  } catch {}
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
