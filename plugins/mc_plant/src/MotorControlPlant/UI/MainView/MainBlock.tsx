
// import { Toast } from 'primereact/toast';
// import { useRef } from 'react';
import useForceUpdate from 'use-force-update';
import { ReactComponent as MotorControlPlant } from '../../../Resources/Svgs/mc_plant_view.svg';
import { ReactComponent as Tooltip } from "../../../Resources/Svgs/Tooltip.svg";
import SummaryPage from '../Summary/Summary';
import Headder from './ToolBar';
import { HideDiv } from '../../Common/NodeUtils';
import { GetComponent } from '../../Common/UIComponent';
import { mc_component_id } from '../../Common/SymbolAccess';
import { Divider } from 'primereact/divider';

const MainBlock = () => {

    function UpdateSymbolValue(event: { value: String, name: String }) {
        (window as any).javaConnector.updateSymbolData(mc_component_id, event.name, event.value);
        // update();
    }
    // const toast = useRef<Toast>(null);
    return (

        <div>
            {/* <Toast ref={toast} position="bottom-right" /> */}
            {/* Logo is an actual React component */}
            {/* <MotorControlPlant id="motor" /> */}
            <Headder />
            {/* <Divider layout="horizontal" /> */}
            <div className="p-fluid">
                                        {/* <GetComponent componentId={mc_component_id} symbolId={"MCPMSMFOC_ALIGNMENT"} onChange={UpdateSymbolValue}  /> */}
                                    </div>
                                    {/* <Divider layout="horizontal" /> */}
            <MotorControlPlant id="motor"
                // height={(window as any).javaConnector.getScreenHeight()}
                // width={(window as any).javaConnector.getScreenWidth()}
            />
            <div id="summary" style={{display :'none'}}> <SummaryPage/> </div>
            <div id="tooltip_object" style={{display :'none'}}> <Tooltip/> </div>
            {/* { HideDiv(document.getElementById('summary'))} */}
           
            {/* <div id="help"> Help Page </div> */}
           {/* { HideDiv(document.getElementById('help'))} */}

            {/* <SVGComponent id="motora"/> */}

            {/* <img src={LogoName} id="raj" alt="logo"/> */}
            {/* document.querySelector("g").addEventListener("click", () => alert("clicked")); */}
            {/* console.log(Logo.port); */}
        </div>


    );
}

export default MainBlock;

