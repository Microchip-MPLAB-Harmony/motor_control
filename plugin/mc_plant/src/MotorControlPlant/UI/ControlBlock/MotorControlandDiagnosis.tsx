

import { Divider } from 'primereact/divider';
import { ReactComponent as MotorControlAndDiagnosis } from '../dummy.svg';
import pi_parameters from '../../../Resources/Svgs/ControlBlock/pi_parameters.svg';

import { GetSymbolArray, GetySymbolValue, mc_component_id } from '../../../MotorControlPlant/Common/SymbolAccess';
import { GetComponent } from '../../../MotorControlPlant/Common/UIComponent';
import MutlipleComponents from '../../../MotorControlPlant/Common/AddMultipleFields';
import { getIndex } from '../../../MotorControlPlant/Common/Utils';
import React from 'react';



let svgdoc: any = null;
let actionIds = ["Field", "Accel", "Hold", "Close"];
let defaultViewGlobal = actionIds[0];

interface IProps {

}

interface IState {
    ramProfilerSelectedValue?: any;
}
let obj: MotorControlandDiagnosis | null = null;

let  ramProfilerSelectSymbol = "MCPMSMFOC_RAMP";

class MotorControlandDiagnosis extends React.Component<IProps, IState> {
    constructor(props: IProps) {
        super(props);
        obj = this;
        this.state = {
            ramProfilerSelectedValue : GetySymbolValue(mc_component_id, ramProfilerSelectSymbol)
        }
        this.RamProfileChanged = this.RamProfileChanged.bind(this);
    }
    
    ramProfilerSelectArray = GetSymbolArray(mc_component_id, ramProfilerSelectSymbol);

    update() {
        this.forceUpdate();
    }

    UpdateSymbolValue(event: { value: any }) {
        (window as any).javaConnector.updateSymbolData(mc_component_id, "", event.value);
        this.forceUpdate();
    }

    RamProfileChanged(event: { value: any }) {
        (window as any).javaConnector.updateSymbolData(mc_component_id, "", event.value);
        // this.ramProfilerSelectedValue = GetySymbolValue(mc_component_id, this.ramProfilerSelectSymbol);
        this.setState({ ramProfilerSelectedValue: event.value });
    }

    GetImageAndParameters(props: { Image: any; Headding: any; SymbolsArray: any }) {
        return (<div className="p-fluid">
            <div>
                {props.Image !== null && <div><img src={props.Image} alt='icon' /></div>}
                <br></br>
                <span >  {props.Headding} </span>  <br></br> 
                <br></br>
                <MutlipleComponents componentId={mc_component_id} symbolsArray={props.SymbolsArray} />
            </div>
        </div>);
    }

    ramProfilerData() {
        return (
            <div>
                {alert(this.state.ramProfilerSelectedValue)}
                {getIndex(this.state.ramProfilerSelectedValue, this.ramProfilerSelectArray) === 0 && <img src={pi_parameters} alt='icon' width={250} />}
                {getIndex(this.state.ramProfilerSelectedValue, this.ramProfilerSelectArray) === 1 && <img src={pi_parameters} alt='icon' width={350} />}
                {getIndex(this.state.ramProfilerSelectedValue, this.ramProfilerSelectArray) === 2 && <img src={pi_parameters} alt='icon' width={450} />}
              
                <br></br> <span >  Ramp Profiler </span>  <br></br>  <br></br> 

                <GetComponent componentId={mc_component_id} symbolId={ramProfilerSelectSymbol} onChange={this.RamProfileChanged} />
               
                <MutlipleComponents componentId={mc_component_id} symbolsArray={["MCPMSMFOC_RAMP_TIME",
                    "MCPMSMFOC_RAMP_VELOCITY", "MCPMSMFOC_RAMP_ACCELERATION", "MCPMSMFOC_REF_INPUT", "MCPMSMFOC_END_TORQUE",
                    "MCPMSMFOC_END_SPEED", "MCPMSMFOC_MIN_TORQUE", "MCPMSMFOC_MAX_TORQUE"]} />
            </div>
        );
    }

    speedPIParameters() {
        return <this.GetImageAndParameters Image={null} Headding="Speed PI Parameters" SymbolsArray={["MCPMSMFOC_SPEED_KP", "MCPMSMFOC_SPEED_KI",
            "MCPMSMFOC_SPEED_OUT_MAX"]} />
    }

    QuadratureAxisCurrentPIController() {
        return <this.GetImageAndParameters Image={null} Headding="Quadrature axis current PI Parameters" SymbolsArray={["MCPMSMFOC_IQ_KP", "MCPMSMFOC_IQ_KI",
            "MCPMSMFOC_IQ_OUT_MAX"]} />
    }

    DirectAxisCurrentPIParameters() {
        return <this.GetImageAndParameters Image={null} Headding="Direct axis current PI Parameters" SymbolsArray={["MCPMSMFOC_ID_KP", "MCPMSMFOC_ID_KI",
            "MCPMSMFOC_ID_OUT_MAX"]} />
    }

    FWAndMTPA() {
        return <this.GetImageAndParameters Image={null} Headding="Field Weakening" SymbolsArray={["MCPMSMFOC_FIELD_WEAKENING", "MCPMSMFOC_MAX_FW_CURRENT"]} />
    }

    render() {
        return (
            <div >
                <div className="card">
                    {/* <GetComponent componentId={mc_component_id} symbolId={motor_control_mode} onChange={RotorPositonChanged} /> */}
                    <label /><br></br>
                    <div className="card">
                        <div className="p-d-flex" >
                            <MotorControlAndDiagnosis id="MotorControlAndDiagnosis" width={600} />

                            <Divider layout="vertical" />
                            {getIndex(defaultViewGlobal, actionIds) === 0 && this.ramProfilerData()}
                            {getIndex(defaultViewGlobal, actionIds) === 1 && this.speedPIParameters()}
                            {getIndex(defaultViewGlobal, actionIds) === 2 && this.QuadratureAxisCurrentPIController()}
                            {getIndex(defaultViewGlobal, actionIds) === 3 && this.DirectAxisCurrentPIParameters()}

                        </div>
                    </div>
                </div>
            </div >

        );
    }
}
export default MotorControlandDiagnosis;

export function RegisterSVGActions() {
    svgdoc = document.getElementById("MotorControlAndDiagnosis");
    actionIds.forEach(function (value) {
        svgdoc.getElementById(value).addEventListener("click", sendClickAction, false);
        svgdoc.getElementById(value).value = value;
    });
}

function sendClickAction(evt: { target: any }) {
    let target = evt.target;
    if (target.correspondingUseElement)
        target = target.correspondingUseElement;
    if (target.value) {
        // this.inputRef.this.defaultView= target.value;
        defaultViewGlobal = target.value;
        obj?.update();
        return;
    }
}



