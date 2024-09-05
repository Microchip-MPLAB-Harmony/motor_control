import { useComboSymbol } from '@mplab_harmony/harmony-plugin-client-lib';
import MultipleUIComponentsWithLabel from '../../Tools/MultipleUIComponentsWithLabel';
import { DialogCommonInitilizeCode } from '../CustomPopUp/CustomPopUp';
import { useEffect } from 'react';

const PositionInterface = (props: { componentId: string; showToast: (arg0: any) => void }) => {
  const selection = useComboSymbol({
    componentId: props.componentId,
    symbolId: 'MCPMSMFOC_ENCODER_PERIPHERAL'
  });
  useEffect(() => {}, [selection]);

  let selectInstance = 'MCPMSMFOC_ENCODER_PERIPHERAL';
  let SymbolsArray = [selectInstance, 'MCPMSMFOC_ENCODER_QEA_PAD', 'MCPMSMFOC_ENCODER_QEB_PAD'];

  DialogCommonInitilizeCode(props.showToast, props.componentId, SymbolsArray);
  return (
    <div className='flex'>
      <MultipleUIComponentsWithLabel
        componentId={props.componentId}
        symbolsArray={SymbolsArray}
      />
    </div>
  );
};
export default PositionInterface;
