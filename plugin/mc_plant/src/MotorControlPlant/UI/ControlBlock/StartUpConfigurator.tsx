

import { TabView, TabPanel } from 'primereact/tabview';
import { Divider } from 'primereact/divider';
import './StartUpConfigurator.css';
import { ReactComponent as QuadratureAxis } from '../../../Resources/Svgs/ControlBlock/Quadrature_axis_forced_updated.svg';
import { ReactComponent as DirectAxis } from '../../../Resources/Svgs/ControlBlock/Quadrature_axis_forced_updated.svg';
import { ReactComponent as InitialPositionAxis } from '../../../Resources/Svgs/ControlBlock/Quadrature_axis_forced_updated.svg';

import { GetSymbolArray, GetySymbolValue, mc_component_id } from '../../../MotorControlPlant/Common/SymbolAccess';
import { GetComponent } from '../../../MotorControlPlant/Common/UIComponent';
import useForceUpdate from 'use-force-update';
import PropertyWindowWithImage from '../../../MotorControlPlant/Common/AddMultipleFields';
import { getIndex } from '../../../MotorControlPlant/Common/Utils';

const StartUpConfigurator = () => {

    let rotor_rotation_symbolID = "MCPMSMFOC_ALIGNMENT";
    let rotor_rotation_SymbolArray = GetSymbolArray(mc_component_id, "MCPMSMFOC_ALIGNMENT");
    let alignment_current = "MCPMSMFOC_OL_IQ_REF";
    let alignment_time = "MCPMSMFOC_LOCK_TIME";

    let end_speed = "MCPMSMFOC_OL_END_SPEED";
    let startup_ramp_time = "MCPMSMFOC_OL_RAMP_TIME";
    let startup_time = "";

    let selectedRotationAxis = GetySymbolValue(mc_component_id, rotor_rotation_symbolID);

    const update = useForceUpdate();


    function UpdateSymbolValue(event: { value: String }) {
        (window as any).javaConnector.updateSymbolData(mc_component_id, alignment_current, event.value);
        update();
    }

    function RotorPositonChanged(event: { value: any }) {
        (window as any).javaConnector.updateSymbolData(mc_component_id, rotor_rotation_symbolID, event.value);
        selectedRotationAxis = GetySymbolValue(mc_component_id, rotor_rotation_symbolID);
        update();
    }

    function GetDirectAndQuadrature() {
        return (<div className="p-fluid">
            <div>
                <span >  Windmilling  </span>  <br></br>
                <span > -- Parameters symbol not af  </span>  <br></br><br></br>
                <span >  Rotor Position alignment  </span>  <br></br><br></br>
                <GetComponent componentId={mc_component_id} symbolId={alignment_current} onChange={UpdateSymbolValue} />
                <br></br>
                <GetComponent componentId={mc_component_id} symbolId={alignment_time} onChange={UpdateSymbolValue} />
                <br></br>
            </div>
        </div>);
    }

    function GetIntialPositonComponents() {
        return (<div className="p-fluid">
            <div>
                <span >  Windmilling  </span>  <br></br>
                <span > -- Parameters symbol not updated  </span>  <br></br><br></br>
                <span >  Rotor Position alignment  </span>  <br></br>
                <span > -- Parameters symbol not updated  </span>  <br></br><br></br>
            </div>
        </div>);
    }

    return (
        <div className="tabbed-pane">
            <div className="card">
                <TabView >
                    <TabPanel header="Initial Field Detection" >
                        <div className="card">
                        <br></br>
                            
                            <div className="p-d-flex" >
                                <div className="p-d-flex p-flex-column">
                                <GetComponent componentId={mc_component_id} symbolId={rotor_rotation_symbolID} onChange={RotorPositonChanged} />
                                <label /> <br></br>
                                {getIndex(selectedRotationAxis, rotor_rotation_SymbolArray) === 0 && <QuadratureAxis width={600} />}
                                {getIndex(selectedRotationAxis, rotor_rotation_SymbolArray) === 1 && <DirectAxis width={500} />}
                                {getIndex(selectedRotationAxis, rotor_rotation_SymbolArray) === 2 && <InitialPositionAxis width={700} />}
                                </div>
                                <Divider layout="vertical" />

                                {getIndex(selectedRotationAxis, rotor_rotation_SymbolArray) === 0 && GetDirectAndQuadrature()}
                                {getIndex(selectedRotationAxis, rotor_rotation_SymbolArray) === 1 && GetDirectAndQuadrature()}
                                {getIndex(selectedRotationAxis, rotor_rotation_SymbolArray) === 2 && GetIntialPositonComponents()}
                            </div>
                        </div>
                    </TabPanel>
                    <TabPanel header="Flying Start" >
                    <div className="card">
                        <div className="p-d-flex">
                                <QuadratureAxis width={600} />
                                <Divider layout="vertical" />
                                <div className="p-fluid">
                                    <div><span >  Flying Start  </span>  <br></br><br></br></div>
                                    <PropertyWindowWithImage componentId = {mc_component_id}  symbolsArray = {["MCPMSMFOC_FLYING_START",
                                    "MCPMSMFOC_FLYING_START_ID_KP", "MCPMSMFOC_FLYING_START_ID_KI", "MCPMSMFOC_FLYING_START_ID_KC", "MCPMSMFOC_FLYING_START_IQ_KP",
                                    "MCPMSMFOC_FLYING_START_IQ_KI", "MCPMSMFOC_FLYING_START_IQ_KC", "MCPMSMFOC_FLYING_START_TIME", "MCPMSMFOC_FLYING_START_SPEED",
                                    "MCPMSMFOC_FLYING_START_STARTUP_CURRENT", "MCPMSMFOC_FLYING_START_NULL_BRAKING_TIME", "MCPMSMFOC_FLYING_START_REGENERATIVE_BRAKING_ENABLE",
                                    "MCPMSMFOC_FLYING_START_REGENERATIVE_BRAKING_CURRENT", "MCPMSMFOC_FLYING_START_REGENERATIVE_BRAKING_RAMP_TIME" ]} />
                                </div>
                            </div>
                        </div>
                    </TabPanel>
                    <TabPanel header="Open Loop Start-up ">
                        <div className="card">
                            <div className="p-d-flex">
                                <QuadratureAxis width={600} />
                                <Divider layout="vertical" />
                                <div className="p-fluid">
                                    <div><span >  Open Loop Start-up  </span>  <br></br><br></br></div>
                                    <GetComponent componentId={mc_component_id} symbolId={end_speed} onChange={UpdateSymbolValue} /><br></br>
                                    <GetComponent componentId={mc_component_id} symbolId={startup_ramp_time} onChange={UpdateSymbolValue} /><br></br>
                                </div>
                            </div>
                        </div>
                    </TabPanel>
                </TabView>
            </div>
        </div >
    )
}

export default StartUpConfigurator;
