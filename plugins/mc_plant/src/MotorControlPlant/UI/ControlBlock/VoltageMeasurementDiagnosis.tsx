

import { Divider } from 'primereact/divider';
import Parameters from '../../Common/AddMultipleFields';
import { mc_component_id } from '../../Common/SymbolAccess';
import {ReactComponent as VoltageMeasurementDiagnosisSVG} from '../../../Resources/Svgs/ControlBlock/Voltage_Measurement_and_Diagnosis-main_diagram.svg';
import { DialogCommonInitilizeCode } from '../CustomPopUp/CustomPopUp';
const VoltageMeasurementDiagnosis = (props :{ parentUpdate: () => void;  showToast : (arg0: any) => void ;} ) => {

    let SymbolsArray = [""];
        
    return (
        <div>
            {DialogCommonInitilizeCode(props.showToast, SymbolsArray)}
        <div className="p-d-flex" >
            <VoltageMeasurementDiagnosisSVG />
            <Divider layout="vertical" />
            {/* <Parameters componentId = {mc_component_id} parentUpdate = {props.parentUpdate} symbolsArray = {SymbolsArray} /> */}
       
          
        </div>
        </div>
        
    )
}
export default VoltageMeasurementDiagnosis;