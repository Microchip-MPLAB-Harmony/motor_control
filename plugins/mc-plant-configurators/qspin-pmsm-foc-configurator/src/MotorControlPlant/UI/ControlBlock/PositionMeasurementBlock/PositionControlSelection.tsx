import { DropDownDefault, KeyValueSetSymbolHook } from '@mplab_harmony/harmony-plugin-client-lib';
import { useEffect } from 'react';
import { ResetDefaultView } from './PositionMesurementAndDiagnosis';

export default function PositionControlSelection(props: {
  componentId: string;
  positionSelection: KeyValueSetSymbolHook;
}) {
  useEffect(() => {
    ResetDefaultView(props.positionSelection.value);
  }, [props.positionSelection]);
  return (
    <div>
      <div className='flex'>
        <div className='m-2'>
          <label> {props.positionSelection.label} </label>
        </div>
        <div>
          <DropDownDefault
            componentId={props.componentId}
            symbolId={'MCPMSMFOC_POSITION_CALC_ALGORITHM'}
          />
        </div>
      </div>
    </div>
  );
}
