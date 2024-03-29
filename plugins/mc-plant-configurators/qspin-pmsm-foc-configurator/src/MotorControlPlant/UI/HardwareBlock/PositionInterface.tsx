import { AddDynamicSymbols } from '@mplab_harmony/harmony-plugin-core-service/build/database-access/SymbolUtils';
import { DialogCommonInitilizeCode } from '../CustomPopUp/CustomPopUp';
import { mc_component_id } from '../MainView/MainBlock';
import { AddMultipleUIComponentsWithLabel } from '@mplab_harmony/harmony-plugin-ui';

const PositionInterface = (props: { parentUpdate: () => void; showToast: (arg0: any) => void }) => {
  let selectInstance = 'MCPMSMFOC_ENCODER_PERIPHERAL';
  let SymbolsArray = [selectInstance];

  SymbolsArray = AddDynamicSymbols(mc_component_id, selectInstance, 'QEA', SymbolsArray);
  SymbolsArray = AddDynamicSymbols(mc_component_id, selectInstance, 'QEB', SymbolsArray);

  DialogCommonInitilizeCode(props.showToast, SymbolsArray);

  function SymbolValueChanged(onchange: Map<String, any>) {
    // do nothing
  }

  return (
    <div className='flex'>
      <AddMultipleUIComponentsWithLabel
        componentId={mc_component_id}
        symbolsArray={SymbolsArray}
        onChange={SymbolValueChanged}
      />
    </div>
  );
};
export default PositionInterface;
