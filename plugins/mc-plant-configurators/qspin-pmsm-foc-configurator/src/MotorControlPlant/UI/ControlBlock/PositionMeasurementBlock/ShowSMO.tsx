import { Divider } from 'primereact/divider';
import { getIndex } from '../../../Tools/CommonUtil';
import { ReactComponent as SMO } from '../../../../Resources/Svgs/ControlBlock/Position_Measurement_and_Diagnosis_SMO.svg';
import { KeyValueSetSymbolHook } from '@mplab_harmony/harmony-plugin-client-lib';
import { ShowConfigProps } from '../../../Tools/NodeUtils';

const ShowSMO = (props: {
  componentId: string;
  showToast: (arg0: any) => void;
  positionSelection: KeyValueSetSymbolHook;
  currentView: string;
  smoIds: string[];
}) => {
  let showslidingModeCurrentObserverSymbols = [
    'MCPMSMFOC_R',
    'MCPMSMFOC_LD',
    'MCPMSMFOC_LQ',
    'MCPMSMFOC_POLE_PAIRS'
  ];

  let showSwitchingFunctionSymbols = [
    'MCPMSMFOC_SWITCHING_FUNCTION_BOUNDARY',
    'MCPMSMFOC_SWITCHING_FUNCTION_GAIN'
  ];
  let showBackEMFObserverSymbols = ['MCPMSMFOC_BEMF_OBSERVER_POLE'];
  let showFluxAngleCalculationSymbols = [
    'MCPMSMFOC_PHASE_DETECTION_ALGORITHM',
    'MCPMSMFOC_PHASE_DETECTION_F0'
  ];
  return (
    <div className='flex'>
      <div className='flex-column'>
        <div className='m-4'>
          <SMO id='PositionMesurementAndDiagnosisSMO' />
        </div>
      </div>
      <Divider layout='vertical' />
      {getIndex(props.currentView, props.smoIds) === 0 && (
        <ShowConfigProps
          title='Sliding Mode Current Observer'
          componentId={props.componentId}
          showToast={props.showToast}
          symbolsArray={showslidingModeCurrentObserverSymbols}
        />
      )}
      {getIndex(props.currentView, props.smoIds) === 1 && (
        <ShowConfigProps
          title='Switching Function'
          componentId={props.componentId}
          showToast={props.showToast}
          symbolsArray={showSwitchingFunctionSymbols}
        />
      )}
      {getIndex(props.currentView, props.smoIds) === 2 && (
        <ShowConfigProps
          title='Back EMF Observer'
          componentId={props.componentId}
          showToast={props.showToast}
          symbolsArray={showBackEMFObserverSymbols}
        />
      )}
      {getIndex(props.currentView, props.smoIds) === 3 && (
        <ShowConfigProps
          title='Flux Angle Calculation'
          componentId={props.componentId}
          showToast={props.showToast}
          symbolsArray={showFluxAngleCalculationSymbols}
        />
      )}
    </div>
  );
};
export default ShowSMO;
