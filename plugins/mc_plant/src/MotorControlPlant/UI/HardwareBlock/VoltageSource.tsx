

import Parameters from '../../Common/AddMultipleFields';
import { mc_component_id } from '../../Common/SymbolAccess';
import { DialogCommonInitilizeCode } from '../CustomPopUp/CustomPopUp';

const VoltageSource = (props :{ parentUpdate: () => void;  showToast : (arg0: any) => void ;} ) => {

    let SymbolsArray = ["MCPMSMFOC_VOLTAGE_MAGNITUDE"];

    return (
        <div >
            {DialogCommonInitilizeCode(props.showToast, SymbolsArray)}
            <div className="p-d-flex" >
                {/* <div className="p-fluid"> */}
                    <Parameters componentId = {mc_component_id} parentUpdate = {props.parentUpdate} symbolsArray = {SymbolsArray} />
                {/* </div> */}
            </div>
        </div >
    )
}

export default VoltageSource;