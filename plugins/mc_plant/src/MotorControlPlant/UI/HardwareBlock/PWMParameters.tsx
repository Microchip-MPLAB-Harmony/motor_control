import { AddTitleAndParameters } from "../../Common/NodeUtils";
import { AddDynamicSymbols } from "../../Common/Utils";
import { DialogCommonInitilizeCode } from "../CustomPopUp/CustomPopUp";
import { Divider } from "primereact/divider";
const PWMParameters = (props: {
  parentUpdate: () => void;
  showToast: (arg0: any) => void;
}) => {
  let channelConfigurationn_instance = "MCPMSMFOC_PWM_INSTANCE_";
  let channelConfiguration = [
    channelConfigurationn_instance,
    "MCPMSMFOC_PWM_FREQUENCY",
    "MCPMSMFOC_PWM_DEAD_TIME",
  ];

  channelConfiguration = AddDynamicSymbols(
    channelConfigurationn_instance,
    "PWM_A",
    channelConfiguration
  );
  channelConfiguration = AddDynamicSymbols(
    channelConfigurationn_instance,
    "PWM_B",
    channelConfiguration
  );
  channelConfiguration = AddDynamicSymbols(
    channelConfigurationn_instance,
    "PWM_C",
    channelConfiguration
  );

  let faultConfiguration = [
    "MCPMSMFOC_PWM_FAULT_SELECT",
    "MCPMSMFOC_PWM_FAULT_STATE",
    "MCPMSMFOC_PWM_FAULT_TYPE",
    "MCPMSMFOC_PWM_FAULT_FILTER",
  ];

  return (
    <div className="p-d-flex">
      {DialogCommonInitilizeCode(
        props.showToast,
        channelConfiguration.concat(faultConfiguration)
      )}
      <AddTitleAndParameters
        Headding="Channel Configuration"
        parentUpdate={props.parentUpdate}
        SymbolsArray={channelConfiguration}
      />
      <Divider layout="vertical" />
      <br></br>
      <br></br>
      <br></br>
      <AddTitleAndParameters
        Headding="Fault Configuration"
        parentUpdate={props.parentUpdate}
        SymbolsArray={faultConfiguration}
      />
    </div>
  );
};
export default PWMParameters;
