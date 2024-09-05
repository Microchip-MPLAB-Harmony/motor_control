import { AddTitleAndParameters } from '../../../Tools/NodeUtils';
import { DialogCommonInitilizeCode } from '../../CustomPopUp/CustomPopUp';

const VoltageScalling = (props: {
  componentId: string;
  showToast: (arg0: any) => void;
  voltageScallingSymbolArray: string[];
}) => {
  DialogCommonInitilizeCode(props.showToast, props.componentId, props.voltageScallingSymbolArray);
  return (
    <div>
      <AddTitleAndParameters
        Headding='Voltage Scaling'
        component_id={props.componentId}
        SymbolsArray={props.voltageScallingSymbolArray}
      />
    </div>
  );
};
export default VoltageScalling;
