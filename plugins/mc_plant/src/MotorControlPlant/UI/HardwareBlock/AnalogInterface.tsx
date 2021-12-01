import { Divider } from "primereact/divider";
import { ReactComponent as AnalogInterfaceGroup } from "../../../Resources/Svgs/HardwareBlock/AnalogInterface-group1.svg";

import { AddDynamicSymbols, getIndex } from "../../Common/Utils";
import React from "react";
import { AddImageAndParameters, AddTitileOnly } from "../../Common/NodeUtils";
import { CallMouseLeave, CallMouseMove } from "../../Common/MouseEvent";

let svgGroup1: any = null;
let svgGroup2: any = null;

let childAndParent = new Map<any, any>();
let svgAndToolTipObject = new Map<any, any>();

let actionIds = ["ai_item1", "ai_item2"];
let defaultViewGlobal = actionIds[0];

let Group1_A_ADC_Unit = "MCPMSMFOC_PHASE_CURRENT_IA_UNIT";
let Group1_B_ADC_Unit = "MCPMSMFOC_PHASE_CURRENT_IB_UNIT";
let Group2_A_ADC_Unit = "MCPMSMFOC_BUS_VOLTAGE_VDC_UNIT";
let Group2_B_ADC_Unit = "MCPMSMFOC_POTENTIOMETER_VPOT_UNIT";

let GROUP1_A = ["MCPMSMFOC_PHASE_CURRENT_IA_NAME", Group1_A_ADC_Unit];
let GROUP1_B = ["MCPMSMFOC_PHASE_CURRENT_IB_NAME", Group1_B_ADC_Unit];
let GROUP2_A = ["MCPMSMFOC_BUS_VOLTAGE_VDC_NAME", Group2_A_ADC_Unit];
let GROUP2_B = ["MCPMSMFOC_POTENTIOMETER_VPOT_NAME", Group2_B_ADC_Unit];

GROUP1_A = AddDynamicSymbols(Group1_A_ADC_Unit, "PHASE_CURRENT_IA", GROUP1_A);
GROUP1_B = AddDynamicSymbols(Group1_B_ADC_Unit, "PHASE_CURRENT_IB", GROUP1_B);
GROUP2_A = AddDynamicSymbols(Group2_A_ADC_Unit, "BUS_VOLTAGE_VDC", GROUP2_A);
GROUP2_B = AddDynamicSymbols(Group2_B_ADC_Unit, "POTENTIOMETER_VPOT", GROUP2_B);

interface IProps {
  parentUpdate: () => void;
  showToast: (arg0: any) => void;
}

interface IState {
  screenRefresh?: boolean;
}
let obj: AnalogInterface | null = null;

class AnalogInterface extends React.Component<IProps, IState> {
  constructor(props: IProps) {
    super(props);
    this.state = {
      screenRefresh: false,
    };
    this.refreshScreen = this.refreshScreen.bind(this);
    obj = this;
  }

  refreshScreen() {
    this.setState({ screenRefresh: true });
  }

  Default_ICON1_1() {
    return (
      <div>
        <AddTitileOnly Headding="Group 01 Signals" />
        <AddImageAndParameters
          Image={null}
          Headding="Signal A Configuration"
          parentUpdate={this.refreshScreen}
          SymbolsArray={GROUP1_A}
        />
        <AddImageAndParameters
          Image={null}
          Headding="Signal B Configuration"
          parentUpdate={this.refreshScreen}
          SymbolsArray={GROUP1_B}
        />
      </div>
    );
  }

  Default_ICON1_2() {
    return (
      <div>
        <AddTitileOnly Headding="Group 02 Signals" />
        <AddImageAndParameters
          Image={null}
          Headding="Signal A Configuration"
          parentUpdate={this.refreshScreen}
          SymbolsArray={GROUP2_A}
        />
        <AddImageAndParameters
          Image={null}
          Headding="Signal B Configuration"
          parentUpdate={this.refreshScreen}
          SymbolsArray={GROUP2_B}
        />
      </div>
    );
  }

  render() {
    return (
      <div>
        <div className="card">
          {/* <div className="p-d-flex" > */}
          <div className="p-d-flex">
            <AnalogInterfaceGroup id="AanlogInterfaceGroup1" />
            <AnalogInterfaceGroup id="AanlogInterfaceGroup2" />
            <Divider layout="vertical" />

            {getIndex(defaultViewGlobal, actionIds) === 0 &&
              this.Default_ICON1_1()}
            {getIndex(defaultViewGlobal, actionIds) === 1 &&
              this.Default_ICON1_2()}
          </div>
        </div>
      </div>
    );
  }
}
export default AnalogInterface;

export function SetAnalogInterfaceDefaultWindowView() {
  defaultViewGlobal = actionIds[0];
}

export function RegisterAnalogInterfaceSVGActions() {
  svgGroup1 = document.getElementById("AanlogInterfaceGroup1");
  svgGroup2 = document.getElementById("AanlogInterfaceGroup2");
  let group2 = svgGroup2.getElementById("ai_item1");
  group2.setAttribute("id", "ai_item2");
  ChangeGroup2_Data(group2);
  let valueAndSVG = new Map<string, any>();
  valueAndSVG.set(actionIds[0], svgGroup1);
  valueAndSVG.set(actionIds[1], svgGroup2);
  actionIds.forEach(function (value) {
    let tooltip = "View Group Properties";
    addEventListeners(valueAndSVG.get(value), value, tooltip, true);
    let toolTipObject = valueAndSVG.get(value).getElementById("tooltip");
    svgAndToolTipObject.set(valueAndSVG.get(value), toolTipObject);
  });
}

function sendClickAction(evt: { target: any }) {
  let target = evt.target;
  if (target.correspondingUseElement) target = target.correspondingUseElement;
  if (target.value) {
    defaultViewGlobal = target.value;
    obj?.refreshScreen();
    return;
  }
}

function addEventListeners(
  svg: any,
  groupid: any,
  dialogHeading: string,
  popupType: boolean
) {
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
    childElement.addEventListener("click", sendClickAction, false);
    childElement.addEventListener("mousemove", mouseMove);
    childElement.addEventListener("mouseleave", mouseLeave);
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
    if (childElement.getAttribute("id") === "labels_ai_item1") {
      ChangeGroup2_Data(childElement);
      return;
    }
    if (childElement.getAttribute("id") === "label_input1_ai_item1") {
      childElement.textContent = "VdcSens";
    } else if (childElement.getAttribute("id") === "label_input2_ai_item1") {
      childElement.textContent = "VpotSens";
    } else if (childElement.getAttribute("id") === "label_group_ai_item1") {
      childElement.textContent = "Signal B configuration";
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
