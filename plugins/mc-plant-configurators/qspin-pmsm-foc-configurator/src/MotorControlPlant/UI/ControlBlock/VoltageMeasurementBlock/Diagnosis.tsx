import { AddTitleAndParameters } from '../../../Tools/NodeUtils';
import { DialogCommonInitilizeCode } from '../../CustomPopUp/CustomPopUp';

const Diagnosis = (props: {
  componentId: string;
  showToast: (arg0: any) => void;
  diagnosisSymbolArray: string[];
}) => {
  DialogCommonInitilizeCode(props.showToast, props.componentId, props.diagnosisSymbolArray);
  return (
    <div>
      <AddTitleAndParameters
        Headding='Diagnosis'
        component_id={props.componentId}
        SymbolsArray={props.diagnosisSymbolArray}
      />
    </div>
  );
};
export default Diagnosis;
