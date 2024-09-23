import { useContext } from 'react';
import MultipleUIComponentsWithLabel from '../../Tools/MultipleUIComponentsWithLabel';
import { DialogCommonInitilizeCode } from '../CustomPopUp/CustomPopUp';
import { PluginConfigContext } from '@mplab_harmony/harmony-plugin-client-lib';

const QuickSettings = (props: { componentId: string; showToast: (arg0: any) => void }) => {
  const { initArgs } = useContext(PluginConfigContext);
  let motorComponent =
    initArgs.motor_paramteters !== null && initArgs.motor_paramteters !== undefined
      ? initArgs.motor_paramteters
      : 'pmsm_motor';
  let SymbolsArray1 = ['MCPMSMFOC_MOTOR_SEL'];
  let SymbolsArray2 = [
    'MCPMSMFOC_BOARD_SEL',
    'MCPMSMFOC_CURRENT_MEAS_ALGORITHM',
    'MCPMSMFOC_POSITION_CALC_ALGORITHM'
  ];
  DialogCommonInitilizeCode(props.showToast, motorComponent, SymbolsArray1);
  DialogCommonInitilizeCode(props.showToast, props.componentId, SymbolsArray2);
  return (
    <div>
      <MultipleUIComponentsWithLabel
        componentId={motorComponent}
        symbolsArray={SymbolsArray1}
      />
      <MultipleUIComponentsWithLabel
        componentId={props.componentId}
        symbolsArray={SymbolsArray2}
      />
    </div>
  );
};

export default QuickSettings;
