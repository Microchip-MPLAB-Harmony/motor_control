import { AddImageAndParameters } from '../../../Tools/NodeUtils';
import { DialogCommonInitilizeCode } from '../../CustomPopUp/CustomPopUp';

const DefaultICON21 = (props: {
  componentId: string;
  showToast: (arg0: any) => void;
  Defautl_ICON2_1_Array_Voltage: string[];
}) => {
  DialogCommonInitilizeCode(
    props.showToast,
    props.componentId,
    props.Defautl_ICON2_1_Array_Voltage
  );
  return (
    <div>
      {/* <AddImageAndParameters
          Image={null}
          Headding="DC Bus Current"
          parentUpdate={this.refreshScreen}
          SymbolsArray={Defautl_ICON2_1_Array_Current}
        /> */}
      <AddImageAndParameters
        Image={null}
        Headding='DC Bus Voltage'
        SymbolsArray={props.Defautl_ICON2_1_Array_Voltage}
        component_id={props.componentId}
      />
    </div>
  );
};
export default DefaultICON21;
