import { AddTitleAndParameters } from '../../../Tools/NodeUtils';
import { DialogCommonInitilizeCode } from '../../CustomPopUp/CustomPopUp';
let showAngleTrackerSymbolsUp = [
  'MCPMSMFOC_ZSMT_HYB_PLL_TRACKING_LOOP_TYPE',
  'MCPMSMFOC_ZSMT_HYB_HFI_KEPS',
  'MCPMSMFOC_ZSMT_HYB_ANGLE_TRACK_F0'
];
let showAngleTrackerrInitialPosition = [
  'MCPMSMFOC_IPC_PULSE_MAGNITUDE',
  'MCPMSMFOC_IPC_PULSE_DUTY',
  'MCPMSMFOC_IPC_PULSE_DURATION'
];
const ZSMTHybridPrimaryAngle = (props: { componentId: string; showToast: (arg0: any) => void }) => {
  DialogCommonInitilizeCode(
    props.showToast,
    props.componentId,
    showAngleTrackerSymbolsUp.concat(showAngleTrackerrInitialPosition)
  );
  return (
    <div>
      <AddTitleAndParameters
        Headding={'Primary Angle Tracker'}
        component_id={props.componentId}
        SymbolsArray={showAngleTrackerSymbolsUp}
      />
      <AddTitleAndParameters
        Headding={'Initial Position Correction'}
        component_id={props.componentId}
        SymbolsArray={showAngleTrackerrInitialPosition}
      />
    </div>
  );
};
export default ZSMTHybridPrimaryAngle;
