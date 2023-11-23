import AddMultipleUIComponentsWithLabel from '@mplab_harmony/harmony-plugin-ui/build/utils/AddMultipleUIComponentsWithLabel';
import { DialogCommonInitilizeCode } from '../CustomPopUp/CustomPopUp';
import { mc_component_id } from '../MainView/MainBlock';

const DataMonitoring = (props: { showToast: (arg0: any) => void }) => {
  let SymbolsArray = [
    'MCPMSMFOC_DATA_MONITOR_ENABLE',
    'MCPMSMFOC_DATA_MONITOR_PROTOCOL',
    'MCPMSMFOC_X2CScope',
    'MCPMSMFOC_DATA_MONITOR_PERIPHERAL',
    'MCPMSMFOC_DATA_MONITOR_RECEIVE_PAD',
    'MCPMSMFOC_DATA_MONITOR_TRANSMIT_PAD'
  ];
  DialogCommonInitilizeCode(props.showToast, SymbolsArray);

  function SymbolValueChanged(onchange: Map<String, any>) {
    // do nothing
  }
  return (
    <div>
      <div>
        <AddMultipleUIComponentsWithLabel
          componentId={mc_component_id}
          onChange={SymbolValueChanged}
          symbolsArray={SymbolsArray}
        />
      </div>
    </div>
  );
};

export default DataMonitoring;
