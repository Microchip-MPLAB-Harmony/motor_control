import { AddImageAndParameters, AddTitileOnly } from '../../../Tools/NodeUtils';
import { DialogCommonInitilizeCode } from '../../CustomPopUp/CustomPopUp';

const DefaultIcon2 = (props: {
  componentId: string;
  showToast: (arg0: any) => void;
  Group2PhaseA: string[];
  Group2PhaseB: string[];
}) => {
  DialogCommonInitilizeCode(
    props.showToast,
    props.componentId,
    props.Group2PhaseA.concat(props.Group2PhaseB)
  );
  return (
    <div>
      <AddTitileOnly Headding='Group 02 Signals' />
      <AddImageAndParameters
        Image={null}
        Headding='Signal A Configuration'
        SymbolsArray={props.Group2PhaseA}
        component_id={props.componentId}
      />
      <AddImageAndParameters
        Image={null}
        Headding='Signal B Configuration'
        SymbolsArray={props.Group2PhaseB}
        component_id={props.componentId}
      />
    </div>
  );
};
export default DefaultIcon2;
