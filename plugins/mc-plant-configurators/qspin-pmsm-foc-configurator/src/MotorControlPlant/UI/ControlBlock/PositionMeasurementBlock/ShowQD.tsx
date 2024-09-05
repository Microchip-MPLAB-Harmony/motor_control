import { KeyValueSetSymbolHook } from '@mplab_harmony/harmony-plugin-client-lib';
import { getIndex } from '../../../Tools/CommonUtil';

import { ReactComponent as PMDQD } from '../../../../Resources/Svgs/ControlBlock/Position_Measurement_and_Diagnosis-Quadrature_decoder.svg';
import { Divider } from 'primereact/divider';
import { ShowConfigProps } from '../../../Tools/NodeUtils';

const ShowQD = (props: {
  componentId: string;
  showToast: (arg0: any) => void;
  positionSelection: KeyValueSetSymbolHook;
  currentView: string;
  qdIds: string[];
}) => {
  let showDigitalNoiseFilterSymbols = ['MCPMSMFOC_ENCODER_DNF_COUNT'];
  let showQuadratureDecoderSymbols = ['MCPMSMFOC_ENCODER_QDEC_PULSE_PER_EREV'];
  return (
    <div className='flex'>
      <div className='flex-column'>
        <div className='m-4'>
          <PMDQD id='PositionMesurementAndDiagnosisQD' />
        </div>
      </div>
      <Divider layout='vertical' />
      {getIndex(props.currentView, props.qdIds) === 0 && (
        <ShowConfigProps
          title='Digital Noise Filter'
          componentId={props.componentId}
          showToast={props.showToast}
          symbolsArray={showDigitalNoiseFilterSymbols}
        />
      )}
      {getIndex(props.currentView, props.qdIds) === 1 && (
        <ShowConfigProps
          title='Quadrature Decoder'
          componentId={props.componentId}
          showToast={props.showToast}
          symbolsArray={showQuadratureDecoderSymbols}
        />
      )}
    </div>
  );
};
export default ShowQD;
