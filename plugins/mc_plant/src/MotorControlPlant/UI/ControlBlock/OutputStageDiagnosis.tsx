

import { Divider } from 'primereact/divider';
import icon from '../../../Resources/Svgs/ControlBlock/Output_Stage_and_Diagnosis.svg';
import { DialogCommonInitilizeCode } from '../CustomPopUp/CustomPopUp';
const OutputStageDiagnosis = (props :{ parentUpdate: () => void;  showToast : (arg0: any) => void ;} ) => {

    let SymbolsArray = [""];
        
    return (
        <div>
            {/* {DialogCommonInitilizeCode(props.showToast, SymbolsArray)} */}
        <div className="p-d-flex" >
            {/* <Parameters componentId = {mc_component_id} parentUpdate = {props.parentUpdate} symbolsArray = {SymbolsArray} /> */}
            <Divider layout="vertical" />
            <img src={icon} alt='icon' />
        </div>
        </div>
        
    )
}
export default OutputStageDiagnosis;