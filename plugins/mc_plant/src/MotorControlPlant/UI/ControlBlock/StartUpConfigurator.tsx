

import { TabView, TabPanel } from 'primereact/tabview';
import { Divider } from 'primereact/divider';
import './StartUpConfigurator.css';
import StartupForcedAlignDAxis from '../../../Resources/Svgs/ControlBlock/StartupConfigurator-ForcedAlign-D-Axis.svg';
import StartupForcedAlignQAxis from '../../../Resources/Svgs/ControlBlock/StartupConfigurator-ForcedAlign-Q-Axis.svg';
import FlyingStart from '../../../Resources/Svgs/ControlBlock/StartupConfigurator-FlyingStart.svg';

import { GetSymbolArray, GetySymbolValue, mc_component_id } from '../../../MotorControlPlant/Common/SymbolAccess';
import { GetComponent } from '../../../MotorControlPlant/Common/UIComponent';
import useForceUpdate from 'use-force-update';
import PropertyWindowWithImage from '../../../MotorControlPlant/Common/AddMultipleFields';
import { getIndex } from '../../../MotorControlPlant/Common/Utils';
import { LoadImage } from '../../Common/NodeUtils';
import useWindowDimensions from '../../Common/Dimenstion';

const StartUpConfigurator = (props: { showToast: (arg0: any) => void; }) => {

    let rotor_rotation_symbolID = "MCPMSMFOC_ALIGNMENT";
    let rotor_rotation_SymbolArray = GetSymbolArray(mc_component_id, "MCPMSMFOC_ALIGNMENT");
    let alignment_current = "MCPMSMFOC_OL_IQ_REF";
    let alignment_time = "MCPMSMFOC_LOCK_TIME";

    let end_speed = "MCPMSMFOC_OL_END_SPEED";
    let startup_ramp_time = "MCPMSMFOC_OL_RAMP_TIME";

    let FlyingStartAllSymbolsArray = ["MCPMSMFOC_FLYING_START",
        "MCPMSMFOC_FLYING_START_ID_KP", "MCPMSMFOC_FLYING_START_ID_KI", "MCPMSMFOC_FLYING_START_ID_KC", "MCPMSMFOC_FLYING_START_IQ_KP",
        "MCPMSMFOC_FLYING_START_IQ_KI", "MCPMSMFOC_FLYING_START_IQ_KC", "MCPMSMFOC_FLYING_START_TIME", "MCPMSMFOC_FLYING_START_SPEED",
        "MCPMSMFOC_FLYING_START_STARTUP_CURRENT", "MCPMSMFOC_FLYING_START_NULL_BRAKING_TIME", "MCPMSMFOC_FLYING_START_REGENERATIVE_BRAKING_ENABLE",
        "MCPMSMFOC_FLYING_START_REGENERATIVE_BRAKING_CURRENT", "MCPMSMFOC_FLYING_START_REGENERATIVE_BRAKING_RAMP_TIME"];

    let selectedRotationAxis = GetySymbolValue(mc_component_id, rotor_rotation_symbolID);

    const update = useForceUpdate();


    const { height, width } = useWindowDimensions();

    function UpdateSymbolValue(event: { value: String, name: String }) {
        (window as any).javaConnector.updateSymbolData(mc_component_id, event.name, event.value);
        update();
    }

    function RotorPositionChanged(event: { value: any }) {
        (window as any).javaConnector.updateSymbolData(mc_component_id, rotor_rotation_symbolID, event.value);
        selectedRotationAxis = GetySymbolValue(mc_component_id, rotor_rotation_symbolID);
        update();
    }

    function GetDirectAndQuadrature() {
        return (<div className="p-fluid">
            <div>
                {/* <span >  Windmilling  </span>  <br></br>
                <span > -- Parameters symbol not af  </span>  <br></br><br></br> */}
                <span style={{ fontWeight: 'bold' }}>  Field Alignment/Detection  </span>  <br></br><br></br>
                <GetComponent componentId={mc_component_id} symbolId={alignment_current} onChange={UpdateSymbolValue} />
                <br></br>
                <GetComponent componentId={mc_component_id} symbolId={alignment_time} onChange={UpdateSymbolValue} />
                <br></br>
            </div>
        </div>);
    }

    return (
        <div className="tabbed-pane">
            <div className="card">
                <TabView >
                    <TabPanel header="Start-up" >
                        {/* {callDialogCommonInitilizeCode(InitialFieldAllSymbolsArray)} */}
                        <div className="card">
                            <br></br>
                            <div className="p-d-flex" >
                                <div className="p-d-flex p-flex-column">
                                   
                                    
                                    {getIndex(selectedRotationAxis, rotor_rotation_SymbolArray) === 0 && LoadImage(StartupForcedAlignQAxis)}
                                    {getIndex(selectedRotationAxis, rotor_rotation_SymbolArray) === 1 && LoadImage(StartupForcedAlignDAxis)}
                                </div>
                                <Divider layout="vertical" />

                                
                                <div className="p-fluid">
                                <GetComponent componentId={mc_component_id} symbolId={rotor_rotation_symbolID} onChange={RotorPositionChanged} />
                                {GetDirectAndQuadrature()}
                                    <div><span style={{ fontWeight: 'bold' }}>  Open Loop Start-up  </span>  <br></br><br></br></div>
                                    <div className="p-fluid">
                                  
                                        <div><GetComponent componentId={mc_component_id} symbolId={end_speed} onChange={UpdateSymbolValue} /><br></br></div>
                                        <div> <GetComponent componentId={mc_component_id} symbolId={startup_ramp_time} onChange={UpdateSymbolValue} /><br></br></div>
                                    </div>
                                </div>
                            </div>
                        </div>
                    </TabPanel>
                    <TabPanel header="Flying Start" >
                        {/* {callDialogCommonInitilizeCode(FlyingStartAllSymbolsArray)} */}
                        <div className="card">
                            <div className="p-d-flex">
                            <div>
                                        width: {width} ~ height: {height}
                                    </div>
                                {LoadImage(FlyingStart)}
                                <Divider layout="vertical" />
                                <div className="p-fluid">
                                    <div><span style={{ fontWeight: 'bold' }} >  Flying Start  </span>  <br></br><br></br></div>
                                    <div className="p-fluid">
                                        <PropertyWindowWithImage componentId={mc_component_id} parentUpdate={update} symbolsArray={FlyingStartAllSymbolsArray} />
                                    </div>
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

