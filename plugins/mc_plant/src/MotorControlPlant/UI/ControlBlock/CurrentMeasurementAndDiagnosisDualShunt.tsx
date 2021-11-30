import { Divider } from "primereact/divider";
import { ReactComponent as CurrentMeasurementAndDiagnosisDualShuntSVG } from "../../../Resources/Svgs/ControlBlock/Current_Measurement_and_Diagnosis-Dual_Shunt.svg";

import { getIndex } from "../../../MotorControlPlant/Common/Utils";
import React from "react";
import { CallMouseLeave, CallMouseMove } from "../../Common/MouseEvent";
import { AddTitleAndParameters } from "../../Common/NodeUtils";

var svgdoc: any = null;
var toolTipObject: any = null;
let actionIds = [
  "box-offset-correction",
  "box-current-scaling-bottom",
  "box-diagnosis",
];
let defaultViewGlobal = actionIds[0];

interface IProps {
  parentUpdate: () => void;
  showToast: (arg0: any) => void;
}

interface IState {
  screenRefresh?: boolean;
}
let obj: CurrentMeasurementAndDiagnosisDualShunt | null = null;

class CurrentMeasurementAndDiagnosisDualShunt extends React.Component<
  IProps,
  IState
> {
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

  OffsetCorrection() {
    return (
      <div>
        <AddTitleAndParameters
          Headding="Offset Correction"
          parentUpdate={this.refreshScreen}
          SymbolsArray={[
            "MCPMSMFOC_OFFSET_CORRECTION_ALGORITHM",
            "MCPMSMFOC_OFFSET_CORRECTION_SAMPLE",
          ]}
        />
      </div>
    );
  }

  CurrentScaling() {
    return (
      <div>
        <AddTitleAndParameters
          Headding="Current Scaling"
          parentUpdate={this.refreshScreen}
          SymbolsArray={[
            "MCPMSMFOC_CURRENT_SCALING_FORMAT",
            "MCPMSMFOC_CURRENT_SCALING_FACTORT",
          ]}
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
            "MCPMSMFOC_CURRENT_OOR",
            "MCPMSMFOC_CURRENT_OOR_MAXIMUM",
            "MCPMSMFOC_CURRENT_OOR_DEBOUNCE",
            "MCPMSMFOC_CURRENT_OOR_FAULT_TYPE",
            "MCPMSMFOC_OFFSET_OOR",
            "MCPMSMFOC_OFFSET_OOR_MAXIMUM",
            "MCPMSMFOC_OFFSET_OOR_MINIMUM",
            "MCPMSMFOC_OFFSET_OOR_DEBOUNCE",
            "MCPMSMFOC_OFFSET_OOR_FAULT_TYPE",
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
              <CurrentMeasurementAndDiagnosisDualShuntSVG id="CurrentMeasurementAndDiagnosisDualShuntSVG" />
            </div>
            <Divider layout="vertical" />
            {getIndex(defaultViewGlobal, actionIds) === 0 &&
              this.OffsetCorrection()}
            {getIndex(defaultViewGlobal, actionIds) === 1 &&
              this.CurrentScaling()}
            {getIndex(defaultViewGlobal, actionIds) === 2 && this.Diagnosis()}
          </div>
        </div>
      </div>
    );
  }
}
export default CurrentMeasurementAndDiagnosisDualShunt;

export function SetCurrentMeasurementDefaultWindowView() {
  defaultViewGlobal = actionIds[0];
}

export function RegisterCurrentMesasurementSVGActions() {
  svgdoc = document.getElementById(
    "CurrentMeasurementAndDiagnosisDualShuntSVG"
  );
  actionIds.forEach(function (value) {
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
