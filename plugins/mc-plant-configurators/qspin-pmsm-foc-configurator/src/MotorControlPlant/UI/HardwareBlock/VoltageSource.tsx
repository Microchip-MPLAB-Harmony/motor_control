import MultipleUIComponentsWithLabel from '../../Tools/MultipleUIComponentsWithLabel';
import { DialogCommonInitilizeCode } from '../CustomPopUp/CustomPopUp';

const VoltageSource = (props: { componentId: string; showToast: (arg0: any) => void }) => {
  let SymbolsArray = ['MCPMSMFOC_VOLTAGE_MAGNITUDE'];
  DialogCommonInitilizeCode(props.showToast, props.componentId, SymbolsArray);
  return (
    <div>
      <div className='flex'>
        <MultipleUIComponentsWithLabel
          componentId={props.componentId}
          symbolsArray={SymbolsArray}
        />
      </div>
    </div>
  );
};

export default VoltageSource;
