import { Divider } from 'primereact/divider';
import icon from '../../../Resources/Svgs/ControlBlock/Output_Stage_and_Diagnosis.svg';
import { DialogCommonInitilizeCode } from '../CustomPopUp/CustomPopUp';
import { AddMultipleUIComponentsWithLabel } from '@mplab_harmony/harmony-plugin-ui';
import { mc_component_id } from '../MainView/MainBlock';
const OutputStageDiagnosis = (props: { showToast: (arg0: any) => void }) => {
  let SymbolsArray = ['MCPMSMFOC_CONTROL_TO_PWM_RATIO', 'MCPMSMFOC_MAXIMUM_RMS_VOLTAGE'];

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
        <Divider layout='vertical' />
        <img
          src={icon}
          alt='icon'
        />
      </div>
    </div>
  );
};
export default OutputStageDiagnosis;
