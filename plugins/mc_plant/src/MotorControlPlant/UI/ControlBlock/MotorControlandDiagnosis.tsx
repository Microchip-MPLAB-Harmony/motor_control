

import { Divider } from 'primereact/divider';
import { ReactComponent as MotorControlAndDiagnosis } from '../../../Resources/Svgs/ControlBlock/Motor_Control_and_Diagnosis-main_diagram.svg';
import PI_Parameters_Back_Calculation from '../../../Resources/Svgs/ControlBlock/Motor_Control_and_Diagnosis-PI_parameters-Back_Calculation.svg';
import Linear from '../../../Resources/Svgs/ControlBlock/Motor_Control_and_Diagnosis-Ramp_Profiler-Linear.svg';
import SCurve from '../../../Resources/Svgs/ControlBlock/Motor_Control_and_Diagnosis-Ramp_Profiler-SCurve.svg';
import Step from '../../../Resources/Svgs/ControlBlock/Motor_Control_and_Diagnosis-Ramp_Profiler-Step.svg';

import { GetSymbolArray, GetySymbolValue, mc_component_id } from '../../../MotorControlPlant/Common/SymbolAccess';
import { GetComponent } from '../../../MotorControlPlant/Common/UIComponent';
import MutlipleComponents from '../../../MotorControlPlant/Common/AddMultipleFields';
import { getIndex } from '../../../MotorControlPlant/Common/Utils';
import React from 'react';
import { LoadSVGasImage } from '../../Common/NodeUtils';
import { CallMouseLeave, CallMouseMove } from '../../Common/MouseEvent';



var svgdoc: any = null;
var toolTipObject: any = null;
let actionIds = ["ramp_profiler", "fw_max_torque", "speed_loop_pid", "foc_direct_axis_pid", "foc_quadrature_axis_pid"];
let defaultViewGlobal = actionIds[0];


interface IProps {
    parentUpdate: () => void,
    showToast : (arg0: any) => void  
}

interface IState {
    motorControlModeSelectedValue?: any;
    ramProfilerSelectedValue?: any;
    screenRefresh?: boolean;
}
let obj: MotorControlandDiagnosis | null = null;

let motorControlModeSymbol = "MCPMSMFOC_CONTROL";
let ramProfilerSelectSymbol = "MCPMSMFOC_RAMP";

class MotorControlandDiagnosis extends React.Component<IProps, IState> {
    constructor(props: IProps) {
        super(props);

        this.state = {
            screenRefresh: false,
            motorControlModeSelectedValue: GetySymbolValue(mc_component_id, motorControlModeSymbol),
            ramProfilerSelectedValue: GetySymbolValue(mc_component_id, ramProfilerSelectSymbol)
        }
        this.MotorControlChanged = this.MotorControlChanged.bind(this)
        this.RamProfileChanged = this.RamProfileChanged.bind(this);
        this.refreshScreen = this.refreshScreen.bind(this);
        obj = this;
    }
    ramProfilerSelectArray = GetSymbolArray(mc_component_id, ramProfilerSelectSymbol);

    refreshScreen() {
        this.setState({ screenRefresh: true });
    }

    RamProfileChanged(event: { value: any }) {
        this.setState({ ramProfilerSelectedValue: event.value });
    }

    MotorControlChanged(event: { value: any }) {
        this.setState({ motorControlModeSelectedValue: event.value });
    }

    GetImageAndParameters(props: { Image: any; Headding: any; parentUpdate: () => void; SymbolsArray: any }) {
        return (<div className="p-fluid">
            <div>
                {props.Image !== null && LoadSVGasImage(props.Image)}
                <br></br>
                <span  style={{ fontWeight: 'bold' }}>  {props.Headding} </span>  <br></br>
                <br></br>
                <MutlipleComponents componentId={mc_component_id} parentUpdate={props.parentUpdate} symbolsArray={props.SymbolsArray} />
            </div>
        </div>);
    }

    ramProfilerData() {
        return (
            <div>
                {getIndex(this.state.ramProfilerSelectedValue, this.ramProfilerSelectArray) === 0 && LoadSVGasImage(Step)}
                {getIndex(this.state.ramProfilerSelectedValue, this.ramProfilerSelectArray) === 1 && LoadSVGasImage(Linear)}
                {getIndex(this.state.ramProfilerSelectedValue, this.ramProfilerSelectArray) === 2 && LoadSVGasImage(SCurve)}

                <br></br> <span style={{ fontWeight: 'bold' }}>  Ramp Profiler </span>  <br></br>  <br></br>

                <GetComponent componentId={mc_component_id} symbolId={ramProfilerSelectSymbol} onChange={this.RamProfileChanged} />

                <MutlipleComponents componentId={mc_component_id} parentUpdate={this.refreshScreen} symbolsArray={["MCPMSMFOC_RAMP_TIME",
                    "MCPMSMFOC_RAMP_VELOCITY", "MCPMSMFOC_RAMP_ACCELERATION", "MCPMSMFOC_REF_INPUT", "MCPMSMFOC_END_TORQUE",
                    "MCPMSMFOC_END_SPEED", "MCPMSMFOC_MIN_TORQUE", "MCPMSMFOC_MAX_TORQUE"]} />
            </div>
        );
    }

    speedPIParameters() {
        return <this.GetImageAndParameters Image={PI_Parameters_Back_Calculation} Headding="Speed PI Parameters" parentUpdate={this.refreshScreen} SymbolsArray={["MCPMSMFOC_SPEED_KP", "MCPMSMFOC_SPEED_KI",
            "MCPMSMFOC_SPEED_OUT_MAX"]} />
    }

    QuadratureAxisCurrentPIController() {
        return <this.GetImageAndParameters Image={PI_Parameters_Back_Calculation} Headding="Quadrature axis current PI Parameters" parentUpdate={this.refreshScreen} SymbolsArray={["MCPMSMFOC_IQ_KP", "MCPMSMFOC_IQ_KI",
            "MCPMSMFOC_IQ_OUT_MAX"]} />
    }

    DirectAxisCurrentPIParameters() {
        return <this.GetImageAndParameters Image={PI_Parameters_Back_Calculation} Headding="Direct axis current PI Parameters" parentUpdate={this.refreshScreen} SymbolsArray={["MCPMSMFOC_ID_KP", "MCPMSMFOC_ID_KI",
            "MCPMSMFOC_ID_OUT_MAX"]} />
    }

    FWAndMTPA() {
        return <this.GetImageAndParameters Image={null} Headding="Field Weakening" parentUpdate={this.refreshScreen} SymbolsArray={["MCPMSMFOC_FIELD_WEAKENING", "MCPMSMFOC_MAX_FW_CURRENT"]} />
    }

    render() {
        return (
            <div >
                <div className="card">
                    <div className="p-d-flex" >
                        <div className="p-d-flex p-flex-column">
                            <label /> <br></br>
                            <GetComponent componentId={mc_component_id} symbolId={motorControlModeSymbol} onChange={this.MotorControlChanged} />
                            <label /> <br></br>
                            <MotorControlAndDiagnosis id="MotorControlAndDiagnosis" />

                        </div>
                        <Divider layout="vertical" />

                        {getIndex(defaultViewGlobal, actionIds) === 0 && this.ramProfilerData()}
                        {getIndex(defaultViewGlobal, actionIds) === 1 && this.FWAndMTPA()}
                        {getIndex(defaultViewGlobal, actionIds) === 2 && this.speedPIParameters()}
                        {getIndex(defaultViewGlobal, actionIds) === 3 && this.DirectAxisCurrentPIParameters()}
                        {getIndex(defaultViewGlobal, actionIds) === 4 && this.QuadratureAxisCurrentPIController()}
                    </div>

                </div>
            </div >

        );
    }
}
export default MotorControlandDiagnosis;

export function SetMotorControlDiagnosisDefaultWindowView(){
    defaultViewGlobal = actionIds[0];
}

export function RegisterSVGActions() {
    svgdoc = document.getElementById("MotorControlAndDiagnosis");
    actionIds.forEach(function (value) {
        findElement(value);
    });
    toolTipObject = svgdoc.getElementById('tooltip');
}

function sendClickAction(evt: { target: any }) {
    let target = evt.target;
    if (target.correspondingUseElement)
        target = target.correspondingUseElement;
    if (target.value) {
        defaultViewGlobal = target.value;
        obj?.refreshScreen();
        return;
    }
}

function findElement(id: any) {
    var allElements = svgdoc.querySelectorAll("[data-action_id='" + id + "']");
    for (var i = 0; i < allElements.length; i++) {
        var element = allElements[0];
        var tooltip = element.getAttribute("data-tooltip");
        var element2 = element.childNodes;
        for (var j = 0; j < element2.length; j++) {
            var element3 = element2[j];
            addEventListner(element3, id,tooltip);
        }
        return;
    }
}

function addEventListner(element : any, id : any,  tooltipText :any){
    element.addEventListener("click", sendClickAction, false);
    element.addEventListener("mousemove", mouseMove);
    element.addEventListener("mouseleave", mouseLeave);
    element.value=id;
    element.toolTip=tooltipText;
}

function mouseMove(evt: { target: any}) {
    CallMouseMove(evt, svgdoc, toolTipObject);
}

function mouseLeave(evt: { target: any }) {
    CallMouseLeave(evt, toolTipObject);
}





