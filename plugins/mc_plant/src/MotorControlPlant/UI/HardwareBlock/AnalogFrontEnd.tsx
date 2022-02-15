import { Divider } from "primereact/divider";
import { ReactComponent as AnalogFrontendSVGIcon1 } from "../../../Resources/Svgs/HardwareBlock/AnalogFrontend-item1.svg";
import { ReactComponent as AnalogFrontendSVGIcon2 } from "../../../Resources/Svgs/HardwareBlock/AnalogFrontend-item2.svg";

import { getIndex } from "../../Common/Utils";
import React from "react";
import { AddImageAndParameters } from "../../Common/NodeUtils";
import { CallMouseLeave, CallMouseMove } from "../../Common/MouseEvent";

let svgIcon1_1: any = null;
let svgdocIcon1_2: any = null;
let svgdocIcon2: any = null;

let actionIds = ["af_item1", "af_item1_2", "af_item2"];
let defaultViewGlobal = actionIds[0];

let childAndParent = new Map<any, any>();
let svgAndToolTipObject = new Map<any, any>();

let Defautl_ICON1_1_Array = [
  "MCPMSMFOC_ANALOG_FRONT_END_IA_OPAMP",
  "MCPMSMFOC_ANALOG_FRONT_END_IA_GAIN",
  "MCPMSMFOC_ANALOG_FRONT_END_IA_OFFSET",
  "MCPMSMFOC_ANALOG_FRONT_END_IA_SHUNT",
];
let Defautl_ICON1_2_Array = [
  "MCPMSMFOC_ANALOG_FRONT_END_IB_OPAMP",
  "MCPMSMFOC_ANALOG_FRONT_END_IB_GAIN",
  "MCPMSMFOC_ANALOG_FRONT_END_IB_OFFSET",
  "MCPMSMFOC_ANALOG_FRONT_END_IB_SHUNT",
];
let Defautl_ICON2_1_Array_Current = [
  "MCPMSMFOC_ANALOG_FRONT_END_IDC_OPAMP",
  "MCPMSMFOC_ANALOG_FRONT_END_IDC_GAIN",
  "MCPMSMFOC_ANALOG_FRONT_END_IDC_OFFSET",
  "MCPMSMFOC_ANALOG_FRONT_END_IDC_SHUNT",
];

let Defautl_ICON2_1_Array_Voltage = [
  "MCPMSMFOC_ANALOG_FRONT_END_VDC_TOP_RES",
  "MCPMSMFOC_ANALOG_FRONT_END_VDC_BOTTOM_RES",
];

interface IProps {
  parentUpdate: () => void;
  showToast: (arg0: any) => void;
}

interface IState {
  screenRefresh?: boolean;
}
let obj: AnalogFrontEnd | null = null;

class AnalogFrontEnd extends React.Component<IProps, IState> {
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
      <AddImageAndParameters
        Image={null}
        Headding="Phase A Current"
        parentUpdate={this.refreshScreen}
        SymbolsArray={Defautl_ICON1_1_Array}
      />
    );
  }

  Default_ICON1_2() {
    return (
      <AddImageAndParameters
        Image={null}
        Headding="Phase B Current"
        parentUpdate={this.refreshScreen}
        SymbolsArray={Defautl_ICON1_2_Array}
      />
    );
  }

  Default_ICON2_1() {
    return (
      <div>
        {/* <AddImageAndParameters
          Image={null}
          Headding="DC Bus Current"
          parentUpdate={this.refreshScreen}
          SymbolsArray={Defautl_ICON2_1_Array_Current}
        /> */}
        <AddImageAndParameters
          Image={null}
          Headding="DC Bus Voltage"
          parentUpdate={this.refreshScreen}
          SymbolsArray={Defautl_ICON2_1_Array_Voltage}
        />
      </div>
    );
  }

  render() {
    return (
      <div>
        <div className="card">
          <div className="p-d-flex">
            <div className="p-d-flex p-flex-column">
              <div className="p-d-flex">
                <div className="p-mr-4">
                  <AnalogFrontendSVGIcon1 id="AnalogFrontendSVG1_1" />
                </div>
                <AnalogFrontendSVGIcon1 id="AnalogFrontendSVG1_2" />
              </div>
              <div className="p-mt-auto">
                <AnalogFrontendSVGIcon2 id="AnalogFrontendSVG2" />
              </div>
            </div>

            <Divider layout="vertical" />

            {getIndex(defaultViewGlobal, actionIds) === 0 &&
              this.Default_ICON1_1()}
            {getIndex(defaultViewGlobal, actionIds) === 1 &&
              this.Default_ICON1_2()}
            {getIndex(defaultViewGlobal, actionIds) === 2 &&
              this.Default_ICON2_1()}
          </div>
        </div>
      </div>
    );
  }
}
export default AnalogFrontEnd;

export function SetAnalogFrontEndDefaultWindowView() {
  defaultViewGlobal = actionIds[0];
}

export function RegisterAnalogFrontEndSVGActions() {
  svgIcon1_1 = document.getElementById("AnalogFrontendSVG1_1");
  svgdocIcon1_2 = document.getElementById("AnalogFrontendSVG1_2");
  svgdocIcon2 = document.getElementById("AnalogFrontendSVG2");
  let icon1_2 = svgdocIcon1_2.getElementById("af_item1");
  icon1_2.setAttribute("id", "af_item1_2");
  ChangeIcon1_2_Data(icon1_2);
  let valueAndSVG = new Map<string, any>();
  valueAndSVG.set(actionIds[0], svgIcon1_1);
  valueAndSVG.set(actionIds[1], svgdocIcon1_2);
  valueAndSVG.set(actionIds[2], svgdocIcon2);
  actionIds.forEach(function (value) {
    let tooltip = "View Icon Properties";
    addEventListeners(valueAndSVG.get(value), value, tooltip, true);
    let obj = valueAndSVG.get(value).getElementById("tooltip");
    svgAndToolTipObject.set(valueAndSVG.get(value), obj);
  });
}

function ChangeIcon1_2_Data(group: any) {
  for (let i = 0; i < group.childNodes.length; i++) {
    let childElement = group.childNodes[i];
    if (childElement.getAttribute("id") === "labels_af_item1") {
      ChangeIcon1_2_Data(childElement);
      return;
    }
    if (childElement.getAttribute("id") === "label_input1_af_item1") {
      childElement.textContent = "Iu (+)";
    } else if (childElement.getAttribute("id") === "label_input2_af_item1") {
      childElement.textContent = "Iu (-)";
    } else if (childElement.getAttribute("id") === "label_output_af_item1") {
      childElement.textContent = "IuSens";
    }
  }
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
