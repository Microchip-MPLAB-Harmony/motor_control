import MultipleUIComponentsWithLabel from '../../../Tools/MultipleUIComponentsWithLabel';

import Linear from '../../../../Resources/Svgs/ControlBlock/Motor_Control_and_Diagnosis-Ramp_Profiler-Linear.svg';
import SCurve from '../../../../Resources/Svgs/ControlBlock/Motor_Control_and_Diagnosis-Ramp_Profiler-SCurve.svg';
import Step from '../../../../Resources/Svgs/ControlBlock/Motor_Control_and_Diagnosis-Ramp_Profiler-Step.svg';
import { LoadImage } from '../../../Tools/NodeUtils';
import { useComboSymbol } from '@mplab_harmony/harmony-plugin-client-lib';
import { DialogCommonInitilizeCode } from '../../CustomPopUp/CustomPopUp';
import { useEffect, useState } from 'react';

const RamProfileSection = (props: { componentId: string; showToast: (arg0: any) => void }) => {
  const ramProfilerSelectedSymbol = useComboSymbol({
    componentId: props.componentId,
    symbolId: 'MCPMSMFOC_RAMP_PROFILES'
  });
  useEffect(() => {
    setState(ramProfilerSelectedSymbol.value);
  }, [ramProfilerSelectedSymbol.value]);
  const [state, setState] = useState(ramProfilerSelectedSymbol.value);
  let ramProfilerSymbols2 = [
    'MCPMSMFOC_RAMP_PROFILES',
    'MCPMSMFOC_RAMP_PROFILER_RAMP_TIME',
    'MCPMSMFOC_RAMP_PROFILER_MAX_SPEED',
    'MCPMSMFOC_RAMP_PROFILER_MAX_ACCEL'
  ];
  DialogCommonInitilizeCode(props.showToast, props.componentId, ramProfilerSymbols2);
  return (
    <div>
      {state === 'Step' && <LoadImage file={Step} />}
      {state === 'Linear' && <LoadImage file={Linear} />}
      {state === 'SCurve' && <LoadImage file={SCurve} />}
      <br></br> <span style={{ fontWeight: 'bold' }}> Ramp Profiler </span> <br></br> <br></br>
      <MultipleUIComponentsWithLabel
        componentId={props.componentId}
        symbolsArray={ramProfilerSymbols2}
      />
    </div>
  );
};

export default RamProfileSection;
