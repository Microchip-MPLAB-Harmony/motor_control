import { KeyValueSetSymbolHook } from '@mplab_harmony/harmony-plugin-client-lib';
import { getIndex } from '../../../Tools/CommonUtil';
import { Divider } from 'primereact/divider';
import { ReactComponent as ZSMTHYBRID } from '../../../../Resources/Svgs/ControlBlock/Position_Measurement_and_Diagnosis_ZSMT_Hybrid.svg';
import { ShowConfigProps } from '../../../Tools/NodeUtils';
import ZSMTHybridPrimaryAngle from './ZSMTHybridPrimaryAngle';

const ShowZSMTHybrid = (props: {
  componentId: string;
  showToast: (arg0: any) => void;
  positionSelection: KeyValueSetSymbolHook;
  currentView: string;
  zsmtIds: string[];
}) => {
  let showPrimaryObserverSymbols = [
    'MCPMSMFOC_ZSMT_HYB_PRIM_OBS',
    'MCPMSMFOC_ZSMT_HYB_HFI_MAGNITUDE'
  ];
  let showSecondaryObserverSymbols = [
    'MCPMSMFOC_ZSMT_HYB_SEC_OBS',
    'MCPMSMFOC_ZSMT_HYB_BEMF_FILT_PARAM'
  ];

  let showAngleTrackerSymbolsBackEMF = [
    'MCPMSMFOC_BEMF_PLL_TRACKING_LOOP_TYPE',
    'MCPMSMFOC_BEMF_ANGLE_TRACK_F0',
    'MCPMSMFOC_BEMF_KEPS'
  ];
  let showSoftSwitchSymbols = ['MCPMSMFOC_ZSMT_HYB_LOWER_TH', 'MCPMSMFOC_ZSMT_HYB_UPPER_TH'];
  return (
    <div className='flex'>
      <div className='flex-column'>
        <div className='m-4'>
          <ZSMTHYBRID id='PositionMesurementAndDiagnosisZSMTHybrid' />
        </div>
      </div>
      <Divider layout='vertical' />
      {getIndex(props.currentView, props.zsmtIds) === 0 && (
        <ShowConfigProps
          title='Primary Observer'
          componentId={props.componentId}
          showToast={props.showToast}
          symbolsArray={showPrimaryObserverSymbols}
        />
      )}
      {getIndex(props.currentView, props.zsmtIds) === 1 && (
        <ShowConfigProps
          title='Secondary Observer'
          componentId={props.componentId}
          showToast={props.showToast}
          symbolsArray={showSecondaryObserverSymbols}
        />
      )}
      {getIndex(props.currentView, props.zsmtIds) === 2 && (
        <ZSMTHybridPrimaryAngle
          componentId={props.componentId}
          showToast={props.showToast}
        />
      )}
      {getIndex(props.currentView, props.zsmtIds) === 3 && (
        <ShowConfigProps
          title='Secondary Angle Tracker'
          componentId={props.componentId}
          showToast={props.showToast}
          symbolsArray={showAngleTrackerSymbolsBackEMF}
        />
      )}
      {getIndex(props.currentView, props.zsmtIds) === 4 && (
        <ShowConfigProps
          title='Soft Switch'
          componentId={props.componentId}
          showToast={props.showToast}
          symbolsArray={showSoftSwitchSymbols}
        />
      )}
    </div>
  );
};
export default ShowZSMTHybrid;
