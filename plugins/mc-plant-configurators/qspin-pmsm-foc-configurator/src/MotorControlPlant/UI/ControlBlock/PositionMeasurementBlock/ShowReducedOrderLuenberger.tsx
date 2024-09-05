import { Divider } from 'primereact/divider';
import { KeyValueSetSymbolHook } from '@mplab_harmony/harmony-plugin-client-lib';
import { ShowConfigProps } from '../../../Tools/NodeUtils';
import { ReactComponent as ROLO } from '../../../../Resources/Svgs/ControlBlock/Position_Measurement_and_Diagnosis_ROLO.svg';
import { getIndex } from '../../../Tools/CommonUtil';

const ShowReducedOrderLuenberger = (props: {
  componentId: string;
  showToast: (arg0: any) => void;
  positionSelection: KeyValueSetSymbolHook;
  currentView: string;
  roloIds: string[];
}) => {
  let showReducedOrderLuenbergerObserver = ['MCPMSMFOC_BEMF_OBSERVER_ROLO_POLE'];
  let fluxAngle = [
    'MCPMSMFOC_ROLO_PHASE_DETECTION_ALGORITHAM',
    'MCPMSMFOC_ROLO_PHASE_DETECTION_F0'
  ];
  return (
    <div className='flex'>
      <div className='flex-column'>
        <div className='m-4'>
          <ROLO id='PositionMesurementAndDiagnosisROLO' />
        </div>
      </div>
      <Divider layout='vertical' />

      {getIndex(props.currentView, props.roloIds) === 0 && (
        <ShowConfigProps
          title='Reduced order luenberger observer'
          componentId={props.componentId}
          showToast={props.showToast}
          symbolsArray={showReducedOrderLuenbergerObserver}
        />
      )}
      {getIndex(props.currentView, props.roloIds) === 1 && (
        <ShowConfigProps
          title='Flux Angle Calculation'
          componentId={props.componentId}
          showToast={props.showToast}
          symbolsArray={fluxAngle}
        />
      )}
    </div>
  );
};
export default ShowReducedOrderLuenberger;
