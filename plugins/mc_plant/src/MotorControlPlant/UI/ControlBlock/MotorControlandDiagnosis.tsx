import { Divider } from "primereact/divider";
import { ReactComponent as MotorControlAndDiagnosis } from "../../../Resources/Svgs/ControlBlock/Motor_Control_and_Diagnosis-main_diagram.svg";
import PI_Parameters_Back_Calculation from "../../../Resources/Svgs/ControlBlock/Motor_Control_and_Diagnosis-PI_parameters-Back_Calculation.svg";
import Linear from "../../../Resources/Svgs/ControlBlock/Motor_Control_and_Diagnosis-Ramp_Profiler-Linear.svg";
import SCurve from "../../../Resources/Svgs/ControlBlock/Motor_Control_and_Diagnosis-Ramp_Profiler-SCurve.svg";
import Step from "../../../Resources/Svgs/ControlBlock/Motor_Control_and_Diagnosis-Ramp_Profiler-Step.svg";

import {
  GetSymbolArray,
  GetySymbolValue,
  mc_component_id,
} from "../../../MotorControlPlant/Common/SymbolAccess";
import { GetComponent } from "../../../MotorControlPlant/Common/UIComponent";
import MutlipleComponents from "../../../MotorControlPlant/Common/AddMultipleFields";
import { getIndex } from "../../../MotorControlPlant/Common/Utils";
import React from "react";
import { AddImageAndParameters, LoadImage } from "../../Common/NodeUtils";
import { CallMouseLeave, CallMouseMove } from "../../Common/MouseEvent";

var svgdoc: any = null;
var toolTipObject: any = null;
let actionIds = [
  "box-ramp-profiler",
  "box-fw-mtpa",
  "box-sl-pid",
  "box-foc-pid-direct",
  "box-foc-pid-quadrature",
  "box-pl-pid",
  "box-pwm-modulator",
  "box-decouple-network",
];
let defaultViewGlobal = actionIds[0];

interface IProps {
  parentUpdate: () => void;
  showToast: (arg0: any) => void;
}

interface IState {
  motorControlModeSelectedValue?: any;
  ramProfilerSelectedValue?: any;
  screenRefresh?: boolean;
}
let obj: MotorControlandDiagnosis | null = null;

let motorControlModeSymbol = "MCPMSMFOC_CONTROL_TYPE";
let ramProfilerSelectSymbol = "MCPMSMFOC_RAMP_PROFILES";

class MotorControlandDiagnosis extends React.Component<IProps, IState> {
  constructor(props: IProps) {
    super(props);

    this.state = {
      screenRefresh: false,
      motorControlModeSelectedValue: GetySymbolValue(
        mc_component_id,
        motorControlModeSymbol
      ),
      ramProfilerSelectedValue: GetySymbolValue(
        mc_component_id,
        ramProfilerSelectSymbol
      ),
    };
    this.MotorControlChanged = this.MotorControlChanged.bind(this);
    this.RamProfileChanged = this.RamProfileChanged.bind(this);
    this.refreshScreen = this.refreshScreen.bind(this);
    obj = this;
  }
  ramProfilerSelectArray = GetSymbolArray(
    mc_component_id,
    ramProfilerSelectSymbol
  );

  refreshScreen() {
    this.setState({ screenRefresh: true });
  }

  RamProfileChanged(event: { value: any }) {
    this.setState({ ramProfilerSelectedValue: event.value });
  }

  MotorControlChanged(event: { value: any }) {
    this.setState({ motorControlModeSelectedValue: event.value });
  }

  ramProfilerData() {
    return (
      <div>
        {getIndex(
          this.state.ramProfilerSelectedValue,
          this.ramProfilerSelectArray
        ) === 0 && LoadImage(Step)}
        {getIndex(
          this.state.ramProfilerSelectedValue,
          this.ramProfilerSelectArray
        ) === 1 && LoadImage(Linear)}
        {getIndex(
          this.state.ramProfilerSelectedValue,
          this.ramProfilerSelectArray
        ) === 2 && LoadImage(SCurve)}
        <br></br> <span style={{ fontWeight: "bold" }}> Ramp Profiler </span>{" "}
        <br></br> <br></br>
        <GetComponent
          componentId={mc_component_id}
          symbolId={ramProfilerSelectSymbol}
          onChange={this.RamProfileChanged}
        />
        <MutlipleComponents
          componentId={mc_component_id}
          parentUpdate={this.refreshScreen}
          symbolsArray={[
            "MCPMSMFOC_RAMP_PROFILER_RAMP_TIME",
            "MCPMSMFOC_RAMP_PROFILER_MAX_SPEED",
            "MCPMSMFOC_RAMP_PROFILER_MAX_ACCEL",
          ]}
        />
      </div>
    );
  }

  speedPIParameters() {
    return (
      <AddImageAndParameters
        Image={PI_Parameters_Back_Calculation}
        Headding="Speed Controller"
        parentUpdate={this.refreshScreen}
        SymbolsArray={[
          "MCPMSMFOC_SPEED_PID_AW",
          "MCPMSMFOC_SPEED_PID_KP",
          "MCPMSMFOC_SPEED_PID_KI",
          "MCPMSMFOC_SPEED_PID_KV",
          "MCPMSMFOC_SPEED_PID_KC",
          "MCPMSMFOC_SPEED_PID_YIMAX",
          "MCPMSMFOC_SPEED_PID_YMAX",
        ]}
      />
    );
  }

  QuadratureAxisCurrentPIController() {
    return (
      <AddImageAndParameters
        Image={PI_Parameters_Back_Calculation}
        Headding="Q-Axis Current Controller"
        parentUpdate={this.refreshScreen}
        SymbolsArray={[
          "MCPMSMFOC_IQ_PID_AW",
          "MCPMSMFOC_IQ_PID_KP",
          "MCPMSMFOC_IQ_PID_KI",
          "MCPMSMFOC_IQ_PID_KV",
          "MCPMSMFOC_IQ_PID_KC",
          "MCPMSMFOC_IQ_PID_YIMAX",
          "MCPMSMFOC_IQ_PID_YMAX",
        ]}
      />
    );
  }

  DirectAxisCurrentPIParameters() {
    return (
      <AddImageAndParameters
        Image={PI_Parameters_Back_Calculation}
        Headding="D-Axis Current Controller"
        parentUpdate={this.refreshScreen}
        SymbolsArray={[
          "MCPMSMFOC_ID_PID_AW",
          "MCPMSMFOC_ID_PID_KP",
          "MCPMSMFOC_ID_PID_KI",
          "MCPMSMFOC_ID_PID_KV",
          "MCPMSMFOC_ID_PID_KC",
          "MCPMSMFOC_ID_PID_YIMAX",
          "MCPMSMFOC_ID_PID_YMAX",
        ]}
      />
    );
  }

  PositionControllerPIParameters() {
    return (
      <AddImageAndParameters
        Image={PI_Parameters_Back_Calculation}
        Headding="Position Controller"
        parentUpdate={this.refreshScreen}
        SymbolsArray={[
          "MCPMSMFOC_POSITION_PID_AW",
          "MCPMSMFOC_POSITION_PID_KP",
          "MCPMSMFOC_POSITION_PID_KI",
          "MCPMSMFOC_POSITION_PID_KV",
          "MCPMSMFOC_POSITION_PID_KC",
          "MCPMSMFOC_POSITION_PID_YIMAX",
          "MCPMSMFOC_POSITION_PID_YMAX",
        ]}
      />
    );
  }

  FWAndMTPA() {
    return (
      <AddImageAndParameters
        Image={null}
        Headding="Field Weakening And MTPA"
        parentUpdate={this.refreshScreen}
        SymbolsArray={[
          "MCPMSMFOC_ENABLE_FW",
          "MCPMSMFOC_FW_MAX_NEGATIVE_ID",
          "MCPMSMFOC_FW_TUNING_PARAMETER",
          "MCPMSMFOC_ENABLE_MTPA",
          "MCPMSMFOC_MTPA_TUNING_PARAMETER",
        ]}
      />
    );
  }

  PWMModulator() {
    return (
      <AddImageAndParameters
        Image={null}
        Headding="PWM Modulator"
        parentUpdate={this.refreshScreen}
        SymbolsArray={[
          "MCPMSMFOC_OVER_MODULATION",
          "MCPMSMFOC_MODULATION_TECHNIQUE",
          "MCPMSMFOC_SPACE_VECTOR_LIMIT",
        ]}
      />
    );
  }

  DecoupleNetwork() {
    return (
      <AddImageAndParameters
        Image={null}
        Headding="Decoupling Network"
        parentUpdate={this.refreshScreen}
        SymbolsArray={["MCPMSMFOC_ENABLE_DECOUPLING"]}
      />
    );
  }

  render() {
    return (
      <div>
        <div className="card">
          <div className="p-d-flex">
            <div className="p-d-flex p-flex-column">
              <label /> <br></br>
              <GetComponent
                componentId={mc_component_id}
                symbolId={motorControlModeSymbol}
                onChange={this.MotorControlChanged}
              />
              <label /> <br></br>
              <MotorControlAndDiagnosis id="MotorControlAndDiagnosis" />
            </div>
            <Divider layout="vertical" />

            {getIndex(defaultViewGlobal, actionIds) === 0 &&
              this.ramProfilerData()}
            {getIndex(defaultViewGlobal, actionIds) === 1 && this.FWAndMTPA()}
            {getIndex(defaultViewGlobal, actionIds) === 2 &&
              this.speedPIParameters()}
            {getIndex(defaultViewGlobal, actionIds) === 3 &&
              this.DirectAxisCurrentPIParameters()}
            {getIndex(defaultViewGlobal, actionIds) === 4 &&
              this.QuadratureAxisCurrentPIController()}
            {getIndex(defaultViewGlobal, actionIds) === 5 &&
              this.PositionControllerPIParameters()}
            {getIndex(defaultViewGlobal, actionIds) === 6 &&
              this.PWMModulator()}
            {getIndex(defaultViewGlobal, actionIds) === 7 &&
              this.DecoupleNetwork()}
          </div>
        </div>
      </div>
    );
  }
}
export default MotorControlandDiagnosis;

export function SetMotorControlDiagnosisDefaultWindowView() {
  defaultViewGlobal = actionIds[0];
}

export function RegisterMotorDiagnosisSVGActions() {
  svgdoc = document.getElementById("MotorControlAndDiagnosis");
  actionIds.forEach(function (value) {
    let group = svgdoc.getElementById(value);
    let tooltip = group.getAttribute("harmony-tooltip");
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
