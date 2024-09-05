import { useEffect } from 'react';
import MultipleUIComponentsWithLabel from '../../../Tools/MultipleUIComponentsWithLabel';
import { DialogCommonInitilizeCode } from '../../CustomPopUp/CustomPopUp';
import { useBooleanSymbol } from '@mplab_harmony/harmony-plugin-client-lib';

const FieldAlignMentAndDetection = (props: {
  componentId: string;
  showToast: (arg0: any) => void;
}) => {
  const openLoop = useBooleanSymbol({
    componentId: props.componentId,
    symbolId: 'MCPMSMFOC_ENABLE_OPEN_LOOP_STARTUP'
  });
  useEffect(() => {}, [openLoop.value]);

  let filedDetectSymbolArray = [
    'MCPMSMFOC_ENABLE_ALIGN_OR_DETECT',
    'MCPMSMFOC_ALIGN_OR_DETECT_AXIS',
    'MCPMSMFOC_ALIGN_OR_DETECT_ALGORITHM',
    'MCPMSMFOC_STARTUP_CURRENT',
    'MCPMSMFOC_STARTUP_TIME'
  ];

  let initialPositionDetectionChildArray = [
    'MCPMSMFOC_IPD_PULSE_AMPLITUDE',
    'MCPMSMFOC_IPD_PULSE_DURATION',
    'MCPMSMFOC_IPD_PULSE_PERIOD'
  ];

  let openLoopSpeedRampSymbolArray = [
    'MCPMSMFOC_ENABLE_OPEN_LOOP_STARTUP',
    'MCPMSMFOC_OPEN_LOOP_END_SPEED',
    'MCPMSMFOC_OPEN_LOOP_RAMP_TIME',
    'MCPMSMFOC_OPEN_LOOP_STAB_TIME'
  ];
  DialogCommonInitilizeCode(
    props.showToast,
    props.componentId,
    filedDetectSymbolArray.concat(initialPositionDetectionChildArray, openLoopSpeedRampSymbolArray)
  );
  return (
    <div className='p-fluid'>
      <div>
        <span style={{ fontWeight: 'bold' }}> Field Alignment/Detection </span> <br></br>
        <br></br>
        <MultipleUIComponentsWithLabel
          componentId={props.componentId}
          symbolsArray={filedDetectSymbolArray}
        />
        <MultipleUIComponentsWithLabel
          componentId={props.componentId}
          symbolsArray={initialPositionDetectionChildArray}
        />
      </div>
      <div>
        <div>
          <span style={{ fontWeight: 'bold' }}> Open Loop Speed Ramp </span> <br></br> <br></br>
        </div>
        <MultipleUIComponentsWithLabel
          componentId={props.componentId}
          symbolsArray={openLoopSpeedRampSymbolArray}
        />
      </div>
    </div>
  );
};
export default FieldAlignMentAndDetection;
