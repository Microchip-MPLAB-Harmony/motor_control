

import Parameters from '../../Common/AddMultipleFields';
import { mc_component_id } from '../../Common/SymbolAccess';
import icon from '../../../Resources/Images/Motor_Parameters.png';
import { Divider } from 'primereact/divider';

const MotorParameters = () => {
    let SymbolsArray = ["MCPMSMFOC_MOTOR_SEL", "MCPMSMFOC_MOTOR_CONNECTION", "MCPMSMFOC_R", "MCPMSMFOC_LD", 
                            "MCPMSMFOC_LQ", "MCPMSMFOC_POLE_PAIRS", "MCPMSMFOC_BEMF_CONST", "MCPMSMFOC_RATED_SPEED", "MCPMSMFOC_MAX_SPEED", "MCPMSMFOC_MAX_MOTOR_CURRENT"];
    
    return (
        <div >
            <div className="p-d-flex" >
                <Parameters componentId = {mc_component_id}  symbolsArray = {SymbolsArray} />
                <Divider layout="vertical" />
                <img src={icon} alt='icon' />
            </div>
        </div >
    )
}

export default MotorParameters;