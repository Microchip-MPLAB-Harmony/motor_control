import MultipleUIComponentsWithLabel from '../../Tools/MultipleUIComponentsWithLabel';
import { DialogCommonInitilizeCode } from '../CustomPopUp/CustomPopUp';

const QuickSettings = (props: { componentId: string; showToast: (arg0: any) => void }) => {
  let SymbolsArray = [
    'MCPMSMFOC_MOTOR_SEL',
    'MCPMSMFOC_BOARD_SEL',
    'MCPMSMFOC_CURRENT_MEAS_ALGORITHM',
    'MCPMSMFOC_POSITION_CALC_ALGORITHM'
  ];

  DialogCommonInitilizeCode(props.showToast, props.componentId, SymbolsArray);
  return (
    <div>
      <MultipleUIComponentsWithLabel
        componentId={props.componentId}
        symbolsArray={SymbolsArray}
      />
    </div>
  );
};

export default QuickSettings;
