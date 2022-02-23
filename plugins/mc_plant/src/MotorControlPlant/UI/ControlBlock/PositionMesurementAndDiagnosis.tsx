import { Divider } from "primereact/divider";
import { ReactComponent as PMDEB } from "../../../Resources/Svgs/ControlBlock/Position_Measurement_and_Diagnosis-Equation_based.svg";
import { ReactComponent as PMDQD } from "../../../Resources/Svgs/ControlBlock/Position_Measurement_and_Diagnosis-Quadrature_decoder.svg";

import {
  GetSymbolArray,
  GetySymbolValue,
  mc_component_id,
} from "../../Common/SymbolAccess";
import { GetComponent } from "../../Common/UIComponent";
import { getIndex } from "../../Common/Utils";
import React from "react";
import { CallMouseLeave, CallMouseMove } from "../../Common/MouseEvent";
import {
  AddImageAndParameters,
  AddTitleAndParameters,
} from "../../Common/NodeUtils";
import {
  DialogCommonInitilizeCode,
  GetResetStatus,
  GetResetToDefaultStatus,
  ResetDialogSettings,
} from "../CustomPopUp/CustomPopUp";

let svgEB: any = null;
let svgQD: any = null;
let childAndParent = new Map<any, any>();
let valueAndSVG = new Map<any, any>();
let svgAndToolTipObject = new Map<any, any>();
let actionIds = [
  "box_motor_model",
  "box_ab_dq",
  "box_lpf_top",
  "box_lpf_middle",
  "box_lpf_bottom",
  "box-digitalnoisefilter",
  "box-quadraturedecoder",
];
let defaultViewGlobal = actionIds[0];

let motorModelSymbolsArray: any[] = [];
let showABIQModelSymbols: any[] = [];
let showLPFEdModelSymbols = ["MCPMSMFOC_ED_FILTER_PARAMETER"];
let showPFEqModelSymbols = ["MCPMSMFOC_EQ_FILTER_PARAMETER"];
let showLPFSpeedModelSymbols = ["MCPMSMFOC_SPEED_FILTER_PARAMETER"];
let showDigitalNoiseFilterSymbols = ["MCPMSMFOC_ENCODER_DNF_COUNT"];
let showQuadratureDecoderSymbols = ["MCPMSMFOC_ENCODER_QDEC_PULSE_PER_EREV"];

interface IProps {
  parentUpdate: () => void;
  showToast: (arg0: any) => void;
}

interface IState {
  positionMesurementModelSelectedValue?: any;
  screenRefresh?: boolean;
}
let obj: PositionMesurementAndDiagnosis | null = null;

let positionMesurementModel = "MCPMSMFOC_POSITION_CALC_ALGORITHM";

class PositionMesurementAndDiagnosis extends React.Component<IProps, IState> {
  constructor(props: IProps) {
    super(props);

    this.state = {
      screenRefresh: false,
      positionMesurementModelSelectedValue: GetySymbolValue(
        mc_component_id,
        positionMesurementModel
      ),
    };
    this.MotorControlChanged = this.MotorControlChanged.bind(this);
    this.refreshScreen = this.refreshScreen.bind(this);
    obj = this;
  }
  positionMesurementModelArray = GetSymbolArray(
    mc_component_id,
    positionMesurementModel
  );

  refreshScreen() {
    this.setState({ screenRefresh: true });
  }

  MotorControlChanged(event: { value: any }) {
    SetPositionControlDiagnosisDefaultWindowView();
    this.setState({ positionMesurementModelSelectedValue: event.value });
  }

  componentDidUpdate() {
    RegisterPositionControlDiagnosisSVGActions();
  }

  ShowMotorModel() {
    return (
      <div>
        {DialogCommonInitilizeCode(
          this.props.showToast,
          motorModelSymbolsArray.concat([positionMesurementModel])
        )}
        <AddImageAndParameters
          Image={null}
          Headding="Motor Model"
          parentUpdate={this.refreshScreen}
          SymbolsArray={motorModelSymbolsArray}
        />
      </div>
    );
  }

  ShowABIQModel() {
    return (
      <div>
        {DialogCommonInitilizeCode(
          this.props.showToast,
          showABIQModelSymbols.concat([positionMesurementModel])
        )}
        <AddImageAndParameters
          Image={null}
          Headding="AB - IQ Transform"
          parentUpdate={this.refreshScreen}
          SymbolsArray={showABIQModelSymbols}
        />
      </div>
    );
  }

  ShowLPFEdModel() {
    return (
      <div>
        {DialogCommonInitilizeCode(
          this.props.showToast,
          showLPFEdModelSymbols.concat([positionMesurementModel])
        )}
        <AddTitleAndParameters
          Headding="Ed Filter"
          parentUpdate={this.refreshScreen}
          SymbolsArray={showLPFEdModelSymbols}
        />
      </div>
    );
  }

  ShowLPFEqModel() {
    return (
      <div>
        {DialogCommonInitilizeCode(
          this.props.showToast,
          showPFEqModelSymbols.concat([positionMesurementModel])
        )}
        <AddTitleAndParameters
          Headding="Eq Filter"
          parentUpdate={this.refreshScreen}
          SymbolsArray={showPFEqModelSymbols}
        />
      </div>
    );
  }

  ShowLPFSpeedModel() {
    return (
      <div>
        {DialogCommonInitilizeCode(
          this.props.showToast,
          showLPFSpeedModelSymbols.concat([positionMesurementModel])
        )}
        <AddTitleAndParameters
          Headding="Speed Filter"
          parentUpdate={this.refreshScreen}
          SymbolsArray={showLPFSpeedModelSymbols}
        />
      </div>
    );
  }

  showEB() {
    return (
      <div className="p-d-flex">
        <div className="p-d-flex p-flex-column">
          {this.GetPositonControlElement()}
          <PMDEB id="PositionMesurementAndDiagnosisEB" />
        </div>
        <Divider layout="vertical" />
        {getIndex(defaultViewGlobal, actionIds) === 0 && this.ShowMotorModel()}
        {getIndex(defaultViewGlobal, actionIds) === 1 && this.ShowABIQModel()}
        {getIndex(defaultViewGlobal, actionIds) === 2 && this.ShowLPFEdModel()}
        {getIndex(defaultViewGlobal, actionIds) === 3 && this.ShowLPFEqModel()}
        {getIndex(defaultViewGlobal, actionIds) === 4 &&
          this.ShowLPFSpeedModel()}
      </div>
    );
  }

  showDigitalNoiseFilter() {
    return (
      <div>
        {DialogCommonInitilizeCode(
          this.props.showToast,
          showDigitalNoiseFilterSymbols.concat([positionMesurementModel])
        )}
        <AddTitleAndParameters
          Headding="Digital Noise Filter"
          parentUpdate={this.refreshScreen}
          SymbolsArray={showDigitalNoiseFilterSymbols}
        />
      </div>
    );
  }

  showQuadratureDecoder() {
    return (
      <div>
        {DialogCommonInitilizeCode(
          this.props.showToast,
          showQuadratureDecoderSymbols.concat([positionMesurementModel])
        )}
        <AddTitleAndParameters
          Headding="Quadrature Decoder"
          parentUpdate={this.refreshScreen}
          SymbolsArray={showQuadratureDecoderSymbols}
        />
      </div>
    );
  }

  showQD() {
    return (
      <div className="p-d-flex">
        <div className="p-d-flex p-flex-column">
          {this.GetPositonControlElement()}
          <PMDQD id="PositionMesurementAndDiagnosisQD" />
        </div>
        <Divider layout="vertical" />
        {getIndex(defaultViewGlobal, actionIds) === 5 &&
          this.showDigitalNoiseFilter()}
        {getIndex(defaultViewGlobal, actionIds) === 6 &&
          this.showQuadratureDecoder()}
      </div>
    );
  }

  GetPositonControlElement() {
    return (
      <div>
        {" "}
        <label /> <br></br>
        <GetComponent
          componentId={mc_component_id}
          symbolId={positionMesurementModel}
          onChange={this.MotorControlChanged}
        />{" "}
        <label /> <br></br>
      </div>
    );
  }

  showUnderDevlopMent() {
    return (
      <div className="p-d-flex">
        <div className="p-d-flex p-flex-column">
          {this.GetPositonControlElement()}
          <h2> Under Implementation... </h2>
        </div>
      </div>
    );
  }

  render() {
    return (
      <div>
        <div className="card">
          {GetSelectedPositionControlIndex() === 0 && this.showEB()}
          {GetSelectedPositionControlIndex() === 1 && this.showQD()}
          {(GetSelectedPositionControlIndex() === 2 || GetSelectedPositionControlIndex() === 3)  && this.showUnderDevlopMent()}
        </div>
      </div>
    );
  }
}
export default PositionMesurementAndDiagnosis;

export function SetPositionControlDiagnosisDefaultWindowView() {
  if (GetResetToDefaultStatus() || GetResetStatus()) {
    return;
  }
  if (GetSelectedPositionControlIndex() === 0) {
    defaultViewGlobal = actionIds[0];
  } else if (GetSelectedPositionControlIndex() === 1) {
    defaultViewGlobal = actionIds[5];
  }
}

function GetSelectedPositionControlIndex() {
  let symbolValue = GetySymbolValue(mc_component_id, positionMesurementModel);
  let symbolArray = GetSymbolArray(mc_component_id, positionMesurementModel);
  return getIndex(symbolValue, symbolArray);
}

export function RegisterPositionControlDiagnosisSVGActions() {
  if (GetSelectedPositionControlIndex() === 0) {
    AddEBEvents();
  } else if (GetSelectedPositionControlIndex() === 1) {
    AddQDEvents();
  }
}

function AddEBEvents() {
  svgEB = document.getElementById("PositionMesurementAndDiagnosisEB");
  if (svgEB == null) {
    return;
  }
  for (let i = 0; i < actionIds.length; i++) {
    if (i <= 4) {
      valueAndSVG.set(actionIds[i], svgEB);
      AddingEvents(actionIds[i]);
    }
  }
}

function AddQDEvents() {
  svgQD = document.getElementById("PositionMesurementAndDiagnosisQD");
  if (svgQD == null) {
    return;
  }
  for (let i = 0; i < actionIds.length; i++) {
    if (i > 4) {
      valueAndSVG.set(actionIds[i], svgQD);
      AddingEvents(actionIds[i]);
    }
  }
}

function AddingEvents(value: string) {
  let tooltip = "Configure Parameters";
  addEventListeners(valueAndSVG.get(value), value, tooltip, true);
  let obj = valueAndSVG.get(value).getElementById("tooltip");
  svgAndToolTipObject.set(valueAndSVG.get(value), obj);
}

function sendClickAction(evt: { target: any }) {
  let target = evt.target;
  if (target.correspondingUseElement) target = target.correspondingUseElement;
  if (target.value) {
    defaultViewGlobal = target.value;
    ResetDialogSettings();
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
