import { ComboBoxDefault, useComboSymbol } from '@mplab_harmony/harmony-plugin-client-lib';
export let motorSelectSymbol = 'MCPMSMFOC_MOTOR_SEL';
export default function MotorSelection(props: { componentId: string }) {
  const motorSelection = useComboSymbol({
    componentId: props.componentId,
    symbolId: motorSelectSymbol
  });
  return (
    <div style={{ paddingBottom: '20px' }}>
      <div className='flex'>
        <div className='m-2'>
          <label> {motorSelection.label} </label>
        </div>
        <div>
          <ComboBoxDefault
            componentId={props.componentId}
            symbolId={motorSelectSymbol}
          />
        </div>
      </div>
    </div>
  );
}
