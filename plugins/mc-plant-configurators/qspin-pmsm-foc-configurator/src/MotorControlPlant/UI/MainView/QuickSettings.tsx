import { AddMultipleUIComponentsWithLabel } from '@mplab_harmony/harmony-plugin-ui';
import { DialogCommonInitilizeCode } from '../CustomPopUp/CustomPopUp';
import { mc_component_id } from './MainBlock';

const QuickSettings = (props: { parentUpdate: () => void; showToast: (arg0: any) => void }) => {
  let SymbolsArray = [
    'MCPMSMFOC_MOTOR_SEL',
    'MCPMSMFOC_BOARD_SEL',
    'MCPMSMFOC_CURRENT_MEAS_ALGORITHM',
    'MCPMSMFOC_POSITION_CALC_ALGORITHM'
  ];
  function SymbolValueChanged(onchange: Map<String, any>) {
    // do nothing
  }
  DialogCommonInitilizeCode(props.showToast, SymbolsArray);
  return (
    <div>
      <div className='flex'>
        <AddMultipleUIComponentsWithLabel
          componentId={mc_component_id}
          symbolsArray={SymbolsArray}
          onChange={SymbolValueChanged}
        />
      </div>
    </div>
  );
};

export default QuickSettings;
