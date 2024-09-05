import { AddImageAndParameters } from '../../../Tools/NodeUtils';
import { DialogCommonInitilizeCode } from '../../CustomPopUp/CustomPopUp';

const DefaultICON12 = (props: {
  componentId: string;
  showToast: (arg0: any) => void;
  Defautl_ICON1_2_Array: string[];
}) => {
  DialogCommonInitilizeCode(props.showToast, props.componentId, props.Defautl_ICON1_2_Array);
  return (
    <div>
      <AddImageAndParameters
        Image={null}
        Headding='Phase B Current'
        SymbolsArray={props.Defautl_ICON1_2_Array}
        component_id={props.componentId}
      />
    </div>
  );
};
export default DefaultICON12;
