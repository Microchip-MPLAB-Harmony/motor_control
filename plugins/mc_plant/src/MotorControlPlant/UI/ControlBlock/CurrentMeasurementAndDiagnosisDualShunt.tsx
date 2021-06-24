

import { Divider } from 'primereact/divider';
import { mc_component_id } from '../../Common/SymbolAccess';
import { ReactComponent as CurrentMeasurementAndDiagnosisDualShuntSVG } from '../../../Resources/Svgs/ControlBlock/Current_Measurement_and_Diagnosis-Dual_Shunt.svg';
import { DialogCommonInitilizeCode } from '../CustomPopUp/CustomPopUp';
import { GetComponent } from '../../Common/UIComponent';
const CurrentMeasurementAndDiagnosisDualShunt = (props: { parentUpdate: () => void; showToast: (arg0: any) => void; }) => {

    let SymbolsArray = [""];

    function CurrentMeasurementMethodChange(evt: { target: any }) {
        // do nothing
    }

    return (
        <div>
            <div className="card">
                <div className="p-d-flex" >
                    <div className="p-d-flex p-flex-column">
                        {DialogCommonInitilizeCode(props.showToast, SymbolsArray)}
                        <div className="p-fluid">
                            <GetComponent componentId={mc_component_id} symbolId="MCPMSMFOC_CURRENT_MEAS" onChange={CurrentMeasurementMethodChange} />
                        </div>
                        <CurrentMeasurementAndDiagnosisDualShuntSVG />
                    </div>
                    <Divider layout="vertical" />
                    {/* <Parameters componentId = {mc_component_id} parentUpdate = {props.parentUpdate} symbolsArray = {SymbolsArray} /> */}

                </div>
            </div>
        </div>
    )
}
export default CurrentMeasurementAndDiagnosisDualShunt;