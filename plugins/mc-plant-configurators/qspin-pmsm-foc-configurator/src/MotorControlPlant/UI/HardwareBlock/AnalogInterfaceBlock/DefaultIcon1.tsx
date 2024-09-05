import { AddImageAndParameters, AddTitileOnly } from '../../../Tools/NodeUtils';
import { DialogCommonInitilizeCode } from '../../CustomPopUp/CustomPopUp';

const DefaultIcon1 = (props: {
  componentId: string;
  showToast: (arg0: any) => void;
  Group1PhaseA: string[];
  Group1PhaseB: string[];
}) => {
  DialogCommonInitilizeCode(
    props.showToast,
    props.componentId,
    props.Group1PhaseA.concat(props.Group1PhaseB)
  );
  return (
    <div>
      <AddTitileOnly Headding='Group 01 Signals' />
      <AddImageAndParameters
        Image={null}
        Headding='Signal A Configuration'
        SymbolsArray={props.Group1PhaseA}
        component_id={props.componentId}
      />
      <AddImageAndParameters
        Image={null}
        Headding='Signal B Configuration'
        component_id={props.componentId}
        SymbolsArray={props.Group1PhaseB}
      />
    </div>
  );
};
export default DefaultIcon1;
