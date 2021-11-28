import { Divider } from "primereact/divider";
import { ReactComponent as VoltageMeasurementDiagnosisSVG } from "../../../Resources/Svgs/ControlBlock/Voltage_Measurement_and_Diagnosis-main_diagram.svg";
import { DialogCommonInitilizeCode } from "../CustomPopUp/CustomPopUp";

import { getIndex } from "../../../MotorControlPlant/Common/Utils";
import React from "react";
import { CallMouseLeave, CallMouseMove } from "../../Common/MouseEvent";
import { AddTitleAndParameters } from "../../Common/NodeUtils";

var svgdoc: any = null;
var toolTipObject: any = null;
let actionIds = ["box-voltagescaling", "box-processing", "box-diagnosis"];
let defaultViewGlobal = actionIds[0];

interface IProps {
  parentUpdate: () => void;
  showToast: (arg0: any) => void;
}

interface IState {
  screenRefresh?: boolean;
}
let obj: VoltageMeasurementDiagnosis | null = null;

class VoltageMeasurementDiagnosis extends React.Component<IProps, IState> {
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

  VoltageScalling() {
    return (
      <div>
        <AddTitleAndParameters
          Headding="Voltage Scaling"
          parentUpdate={this.refreshScreen}
          SymbolsArray={[
            "MCPMSMFOC_VOLTAGE_SCALING_FORMAT",
            "MCPMSMFOC_VOLTAGE_SCALING_FACTORT",
          ]}
        />
      </div>
    );
  }

  Processing() {
    return (
      <div>
        <AddTitleAndParameters
          Headding="Processing"
          parentUpdate={this.refreshScreen}
          SymbolsArray={["MCPMSMFOC_VOLTAGE_PROCESSING"]}
        />
      </div>
    );
  }

  Diagnosis() {
    return (
      <div>
        <AddTitleAndParameters
          Headding="Diagnosis"
          parentUpdate={this.refreshScreen}
          SymbolsArray={[
            "MCPMSMFOC_OVER_VOLTAGE",
            "MCPMSMFOC_OVER_VOLTAGE_LIMIT",
            "MCPMSMFOC_OVER_VOLTAGE_DEBOUNCE",
            "MCPMSMFOC_OVER_VOLTAGE_FAULT_TYPE",
            "MCPMSMFOC_UNDER_VOLTAGE",
            "MCPMSMFOC_UNDER_VOLTAGE_LIMIT",
            "MCPMSMFOC_UNDER_VOLTAGE_DEBOUNCE",
            "MCPMSMFOC_UNDER_VOLTAGE_FAULT_TYPE",
          ]}
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
              <VoltageMeasurementDiagnosisSVG id="VoltageMeasurementDiagnosis" />
            </div>
            <Divider layout="vertical" />
            {getIndex(defaultViewGlobal, actionIds) === 0 &&
              this.VoltageScalling()}
            {getIndex(defaultViewGlobal, actionIds) === 1 && this.Processing()}
            {getIndex(defaultViewGlobal, actionIds) === 2 && this.Diagnosis()}
          </div>
        </div>
      </div>
    );
  }
}
export default VoltageMeasurementDiagnosis;

export function SetVoltageMeasurementDefaultWindowView() {
  defaultViewGlobal = actionIds[0];
}

export function RegisterVoltageMesasurementSVGActions() {
  svgdoc = document.getElementById("VoltageMeasurementDiagnosis");
  actionIds.forEach(function (value) {
    // let group = svgdoc.getElementById(value);
    let tooltip = "Configure Parameters";
    addEventListeners(value, tooltip, true);
  });
  toolTipObject = svgdoc.getElementById("tooltip");
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
  groupid: any,
  dialogHeading: string,
  popupType: boolean
) {
  let group = svgdoc.getElementById(groupid);
  IterateSVGelements(group, groupid, dialogHeading, popupType);
}
function IterateSVGelements(
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
    if (popupType) {
      childElement.value = groupid;
    }
    childElement.toolTip = dialogHeading;
    if (childElement.childNodes.length > 0) {
      IterateSVGelements(childElement, groupid, dialogHeading, popupType);
    }
  }
}

function mouseMove(evt: { target: any }) {
  CallMouseMove(evt, svgdoc, toolTipObject);
}

function mouseLeave(evt: { target: any }) {
  CallMouseLeave(evt, toolTipObject);
}
