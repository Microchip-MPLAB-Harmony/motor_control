import { Divider } from 'primereact/divider';
import icon from '../../../Resources/Svgs/ControlBlock/Output_Stage_and_Diagnosis.svg';
import { DialogCommonInitilizeCode } from '../CustomPopUp/CustomPopUp';
import MultipleUIComponentsWithLabel from '../../Tools/MultipleUIComponentsWithLabel';
const OutputStageDiagnosis = (props: { componentId: string; showToast: (arg0: any) => void }) => {
  let SymbolsArray = ['MCPMSMFOC_CONTROL_TO_PWM_RATIO', 'MCPMSMFOC_MAXIMUM_RMS_VOLTAGE'];

  DialogCommonInitilizeCode(props.showToast, props.componentId, SymbolsArray);

  return (
    <div>
      <div className='flex'>
        <MultipleUIComponentsWithLabel
          componentId={props.componentId}
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
