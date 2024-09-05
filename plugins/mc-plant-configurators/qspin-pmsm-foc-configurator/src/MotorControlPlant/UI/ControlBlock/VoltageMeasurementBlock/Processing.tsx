import { AddTitleAndParameters } from '../../../Tools/NodeUtils';
import { DialogCommonInitilizeCode } from '../../CustomPopUp/CustomPopUp';

const Processing = (props: {
  componentId: string;
  showToast: (arg0: any) => void;
  processingSymbolArray: string[];
}) => {
  DialogCommonInitilizeCode(props.showToast, props.componentId, props.processingSymbolArray);
  return (
    <div>
      <AddTitleAndParameters
        Headding='Processing'
        component_id={props.componentId}
        SymbolsArray={props.processingSymbolArray}
      />
    </div>
  );
};
export default Processing;
