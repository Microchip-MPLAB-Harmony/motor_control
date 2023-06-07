import { AddMultipleUIComponentsWithLabel } from '@mplab_harmony/harmony-plugin-ui';
import { DialogCommonInitilizeCode } from '../CustomPopUp/CustomPopUp';
import { mc_component_id } from '../MainView/MainBlock';

const VoltageSource = (props: { parentUpdate: () => void; showToast: (arg0: any) => void }) => {
  let SymbolsArray = ['MCPMSMFOC_VOLTAGE_MAGNITUDE'];
  DialogCommonInitilizeCode(props.showToast, SymbolsArray);
  function SymbolValueChanged(onchange: Map<String, any>) {
    // do nothing
  }
  return (
    <div>
      <div className='flex'>
        <AddMultipleUIComponentsWithLabel
          componentId={mc_component_id}
          onChange={SymbolValueChanged}
          symbolsArray={SymbolsArray}
        />
      </div>
    </div>
  );
};

export default VoltageSource;
