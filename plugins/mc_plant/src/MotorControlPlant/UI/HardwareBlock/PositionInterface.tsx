import Parameters from "../../Common/AddMultipleFields";
import { mc_component_id } from "../../Common/SymbolAccess";
import { AddDynamicSymbols } from "../../Common/Utils";
import { DialogCommonInitilizeCode } from "../CustomPopUp/CustomPopUp";
const PositionInterface = (props: {
  parentUpdate: () => void;
  showToast: (arg0: any) => void;
}) => {
  let selectInstance = "MCPMSMFOC_ENCODER_PERIPHERAL";
  let SymbolsArray = [selectInstance];
  SymbolsArray = AddDynamicSymbols(selectInstance, "QEA", SymbolsArray);
  SymbolsArray = AddDynamicSymbols(selectInstance, "QEB", SymbolsArray);

  return (
    <div>
      {DialogCommonInitilizeCode(props.showToast, SymbolsArray)}
      <Parameters
        componentId={mc_component_id}
        parentUpdate={props.parentUpdate}
        symbolsArray={SymbolsArray}
      />
    </div>
  );
};
export default PositionInterface;
