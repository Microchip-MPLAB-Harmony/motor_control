import Parameters from "../../Common/AddMultipleFields";
import { mc_component_id } from "../../Common/SymbolAccess";
import { DialogCommonInitilizeCode } from "../CustomPopUp/CustomPopUp";

const DataMonitoring = (props: {
  parentUpdate: () => void;
  showToast: (arg0: any) => void;
}) => {
  let SymbolsArray = [
    "MCPMSMFOC_DATA_MONITOR_ENABLE",
    "MCPMSMFOC_DATA_MONITOR_PROTOCOL",
    "MCPMSMFOC_X2CScope",
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
        {/* </div> */}
      </div>
    </div>
  );
};

export default DataMonitoring;
