import { DialogCommonInitilizeCode } from '../CustomPopUp/CustomPopUp';
import { mc_component_id } from '../MainView/MainBlock';
import AddMultipleUIComponentsWithLabel from '@mplab_harmony/harmony-plugin-ui/build/utils/AddMultipleUIComponentsWithLabel';

const MotorParameters = (props: { showToast: (arg0: any) => void }) => {
  let SymbolsArray = [
    'MCPMSMFOC_MOTOR_SEL',
    'MCPMSMFOC_MOTOR_CONNECTION',
    'MCPMSMFOC_R',
    'MCPMSMFOC_LD',
    'MCPMSMFOC_LQ',
    'MCPMSMFOC_POLE_PAIRS',
    'MCPMSMFOC_BEMF_CONST',
    'MCPMSMFOC_RATED_SPEED',
    'MCPMSMFOC_MAX_SPEED',
    'MCPMSMFOC_MAX_MOTOR_CURRENT'
  ];
  DialogCommonInitilizeCode(props.showToast, SymbolsArray);

  function SymbolValueChanged(onchange: Map<String, any>) {
    // do nothing
  }

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
export default MotorParameters;
