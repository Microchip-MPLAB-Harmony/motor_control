import Parameters from "../../Common/AddMultipleFields";
import { mc_component_id } from "../../Common/SymbolAccess";
import { DialogCommonInitilizeCode } from "../CustomPopUp/CustomPopUp";

const QuickSettings = (props: {
  parentUpdate: () => void;
  showToast: (arg0: any) => void;
}) => {
  let SymbolsArray = [
    "MCPMSMFOC_MOTOR_SEL",
    "MCPMSMFOC_BOARD_SEL",
    "MCPMSMFOC_CURRENT_MEAS_ALGORITHM",
    "MCPMSMFOC_POSITION_CALC_ALGORITHM",
  ];

  return (
    <div>
      {DialogCommonInitilizeCode(props.showToast, SymbolsArray)}
      <div className="p-d-flex">
        {/* <div className="p-fluid"> */}
        <Parameters
          componentId={mc_component_id}
          parentUpdate={props.parentUpdate}
          symbolsArray={SymbolsArray}
        />
      </div>
    </div>
  );
};

export default QuickSettings;
