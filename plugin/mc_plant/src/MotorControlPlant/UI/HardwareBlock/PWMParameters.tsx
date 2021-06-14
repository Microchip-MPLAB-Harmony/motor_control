

import Parameters from '../../Common/AddMultipleFields';
import { mc_component_id } from '../../Common/SymbolAccess';
const PWMParameters = () => {
    let SymbolsArray = ["MCPMSMFOC_PWM_FREQ", "MCPMSMFOC_PWM_PH_U", "MCPMSMFOC_PWM_PH_V", "MCPMSMFOC_PWM_PH_W",
        "MCPMSMFOC_PWM_DEAD_TIME", "MCPMSMFOC_PWM_FAULT"];
    return (
        <div >
            <Parameters componentId={mc_component_id} symbolsArray={SymbolsArray}/>
        </div >
    )
}
export default PWMParameters;