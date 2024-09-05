import { KeyValueSetSymbolHook } from '@mplab_harmony/harmony-plugin-client-lib';
import { getIndex } from '../../../Tools/CommonUtil';
import { ReactComponent as PMDEB } from '../../../../Resources/Svgs/ControlBlock/Position_Measurement_and_Diagnosis-Equation_based.svg';
import PositionControlSelection from './PositionControlSelection';
import { Divider } from 'primereact/divider';
import { ShowConfigProps } from '../../../Tools/NodeUtils';

const ShowEB = (props: {
  componentId: string;
  showToast: (arg0: any) => void;
  positionSelection: KeyValueSetSymbolHook;
  currentView: string;
  ebIds: string[];
}) => {
  let showmotorModelSymbolsArray: any[] = [
    'MCPMSMFOC_R',
    'MCPMSMFOC_LD',
    'MCPMSMFOC_LQ',
    'MCPMSMFOC_POLE_PAIRS'
  ];
  let showABIQModelSymbols: any[] = [];

  let showLPFEdModelSymbols = ['MCPMSMFOC_ED_FILTER_PARAMETER'];
  let showPFEqModelSymbols = ['MCPMSMFOC_EQ_FILTER_PARAMETER'];
  let showLPFSpeedModelSymbols = ['MCPMSMFOC_SPEED_FILTER_PARAMETER'];
  return (
    <div className='flex'>
      <div className='flex-column'>
        <div className='m-4'>
          <PMDEB id='PositionMesurementAndDiagnosisEB' />
        </div>
      </div>
      <Divider layout='vertical' />
      {getIndex(props.currentView, props.ebIds) === 0 && (
        <div className='flex flex-row'>
          {/* <Image
          src='../../../Resources/Svgs/ControlBlock/cleaned_motor1.svg'
          preview
        /> */}
          <ShowConfigProps
            title='Motor Model'
            componentId={props.componentId}
            showToast={props.showToast}
            symbolsArray={showmotorModelSymbolsArray}
          />
        </div>
      )}
      {getIndex(props.currentView, props.ebIds) === 1 && (
        <div className='flex flex-row'>
          {/* <Avatar
          image='../../../Resources/Svgs/ControlBlock/Position_Measurement_and_Diagnosis-Equation_based_AB_DQ_Transformation.svg'
          size='large'
        /> */}
          <ShowConfigProps
            title='AB - IQ Transform'
            componentId={props.componentId}
            showToast={props.showToast}
            symbolsArray={showABIQModelSymbols}
          />
        </div>
      )}
      {getIndex(props.currentView, props.ebIds) === 2 && (
        <ShowConfigProps
          title='Ed Filter'
          componentId={props.componentId}
          showToast={props.showToast}
          symbolsArray={showLPFEdModelSymbols}
        />
      )}
      {getIndex(props.currentView, props.ebIds) === 3 && (
        <ShowConfigProps
          title='Eq Filter'
          componentId={props.componentId}
          showToast={props.showToast}
          symbolsArray={showPFEqModelSymbols}
        />
      )}
      {getIndex(props.currentView, props.ebIds) === 4 && (
        <ShowConfigProps
          title='Speed Filter'
          componentId={props.componentId}
          showToast={props.showToast}
          symbolsArray={showLPFSpeedModelSymbols}
        />
      )}
    </div>
  );
};
export default ShowEB;
