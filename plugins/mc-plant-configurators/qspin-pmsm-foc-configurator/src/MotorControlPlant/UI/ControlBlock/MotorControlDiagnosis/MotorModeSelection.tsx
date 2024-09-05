import {
  CheckBoxDefault,
  DropDownDefault,
  useKeyValueSetSymbol
} from '@mplab_harmony/harmony-plugin-client-lib';

export default function MotorModeSelection(props: { componentId: string }) {
  const motorModeSelction = useKeyValueSetSymbol({
    componentId: props.componentId,
    symbolId: 'MCPMSMFOC_CONTROL_TYPE'
  });
  return (
    <div className='flex justify-content-between column-gap-4 row-gap-6'>
      <div className='flex'>
        <div className='m-2'>
          <label> {motorModeSelction.label} </label>
        </div>
        <div>
          <DropDownDefault
            componentId={props.componentId}
            symbolId={'MCPMSMFOC_CONTROL_TYPE'}
          />
        </div>
      </div>
      <div className='flex align-items-center'>
        <CheckBoxDefault
          componentId={props.componentId}
          symbolId={'MCPMSMFOC_FOC_X2C_ENABLE'}
        />
        <label
          htmlFor='ingredient1'
          className='ml-2'
          style={{ fontWeight: 'bold' }}>
          Model based design
        </label>
      </div>
    </div>
  );
}
