

import { Divider } from 'primereact/divider';
import icon from '../../../Resources/Svgs/ControlBlock/Output_Stage_and_Diagnosis.svg';
import AddMultipleFields from '../../Common/AddMultipleFields';
import { mc_component_id } from '../../Common/SymbolAccess';
import { DialogCommonInitilizeCode } from '../CustomPopUp/CustomPopUp';
const OutputStageDiagnosis = (props :{ parentUpdate: () => void;  showToast : (arg0: any) => void ;} ) => {

    let SymbolsArray = ["MCPMSMFOC_CONTROL_TO_PWM_RATIO","MCPMSMFOC_MAXIMUM_RMS_VOLTAGE"];
        
    return (
        <div>
            {DialogCommonInitilizeCode(props.showToast, SymbolsArray)}
        <div className="p-d-flex" >
            <AddMultipleFields componentId = {mc_component_id} parentUpdate = {props.parentUpdate} symbolsArray = {SymbolsArray} />
            <Divider layout="vertical" />
            <img src={icon} alt='icon' />
        </div>
        </div>
        
    )
}
export default OutputStageDiagnosis;