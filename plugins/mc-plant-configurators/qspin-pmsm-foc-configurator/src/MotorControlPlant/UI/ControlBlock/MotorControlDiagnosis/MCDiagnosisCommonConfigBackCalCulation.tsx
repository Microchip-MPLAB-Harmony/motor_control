import { AddTitleAndParameters, LoadImage } from '../../../Tools/NodeUtils';
import { DialogCommonInitilizeCode } from '../../CustomPopUp/CustomPopUp';
import PIParametersBackCalculation from '../../../../Resources/Svgs/ControlBlock/Motor_Control_and_Diagnosis-PI_parameters-Back_Calculation.svg';
const MCDiagnosisCommonConfigBackCalCulation = (props: {
  title: string;
  componentId: string;
  symbolsArray: string[];
  showToast: (arg0: any) => void;
}) => {
  DialogCommonInitilizeCode(props.showToast, props.componentId, props.symbolsArray);
  return (
    <div>
      <LoadImage file={PIParametersBackCalculation} />
      <AddTitleAndParameters
        Headding={props.title}
        component_id={props.componentId}
        SymbolsArray={props.symbolsArray}
      />
    </div>
  );
};
export default MCDiagnosisCommonConfigBackCalCulation;
