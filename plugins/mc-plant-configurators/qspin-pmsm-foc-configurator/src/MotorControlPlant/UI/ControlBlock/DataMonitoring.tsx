import MultipleUIComponentsWithLabel from '../../Tools/MultipleUIComponentsWithLabel';
import { DialogCommonInitilizeCode } from '../CustomPopUp/CustomPopUp';

const DataMonitoring = (props: { componentId: string; showToast: (arg0: any) => void }) => {
  let SymbolsArray = [
    'MCPMSMFOC_DATA_MONITOR_ENABLE',
    'MCPMSMFOC_DATA_MONITOR_PROTOCOL',
    'MCPMSMFOC_X2CScope',
    'MCPMSMFOC_DATA_MONITOR_PERIPHERAL',
    'MCPMSMFOC_DATA_MONITOR_RECEIVE_PAD',
    'MCPMSMFOC_DATA_MONITOR_TRANSMIT_PAD'
  ];
  DialogCommonInitilizeCode(props.showToast, props.componentId, SymbolsArray);

  return (
    <div>
      <div>
        <MultipleUIComponentsWithLabel
          componentId={props.componentId}
          symbolsArray={SymbolsArray}
        />
      </div>
    </div>
  );
};

export default DataMonitoring;
