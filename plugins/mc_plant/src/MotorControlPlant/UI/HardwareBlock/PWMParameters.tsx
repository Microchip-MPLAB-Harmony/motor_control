


import Parameters from '../../Common/AddMultipleFields';
import { mc_component_id } from '../../Common/SymbolAccess';
import { DialogCommonInitilizeCode } from '../CustomPopUp/CustomPopUp';
const PWMParameters = (props :{ parentUpdate: () => void;  showToast : (arg0: any) => void ;} ) => {

    let SymbolsArray = ["MCPMSMFOC_PWM_FREQ", "MCPMSMFOC_PWM_PH_U", "MCPMSMFOC_PWM_PH_V", "MCPMSMFOC_PWM_PH_W",
        "MCPMSMFOC_PWM_DEAD_TIME", "MCPMSMFOC_PWM_FAULT"];
        
    return (
        <div >
            {DialogCommonInitilizeCode(props.showToast, SymbolsArray)}
            {/* <div className="p-fluid"> */}
                <Parameters componentId={mc_component_id} parentUpdate = {props.parentUpdate}symbolsArray={SymbolsArray}/>
            {/* </div> */}
        </div >
    )
}
export default PWMParameters;