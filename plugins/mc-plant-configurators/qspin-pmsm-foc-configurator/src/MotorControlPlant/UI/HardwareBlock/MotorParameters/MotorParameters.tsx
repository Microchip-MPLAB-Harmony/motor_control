import {
  ComboBoxDefault,
  PluginConfigContext,
  useComboSymbol
} from '@mplab_harmony/harmony-plugin-client-lib';
import { useContext, useEffect, useState } from 'react';
import { ListBox } from 'primereact/listbox';
import DisplayMotorParameters from './DisplayMotorParameters';
interface Tab {
  name: string;
  status: string;
}
export let motorSelectSymbol = 'MCPMSMFOC_MOTOR_SEL';
export let metaDataName = 'Meta Data Parameters';
export let namePlate = 'Nameplate Parameters';
export let electrical = 'Electrical Parameters';
export let mechanical = 'Mechanical Parameters';
export let sensor = 'Sensor Parameters';

const MotorParameters = (props: { showToast: (arg0: any) => void }) => {
  const { initArgs } = useContext(PluginConfigContext);
  let comp =
    initArgs.motor_paramteters !== null && initArgs.motor_paramteters !== undefined
      ? initArgs.motor_paramteters
      : 'pmsm_motor';

  const motorSelection = useComboSymbol({
    componentId: comp,
    symbolId: motorSelectSymbol
  });
  useEffect(() => {}, [motorSelection.value]);

  // const tabTemplate = (option: any) => {
  //   // eslint-disable-next-line react-hooks/rules-of-hooks
  //   const motorSel = useComboSymbol({
  //     componentId: comp,
  //     symbolId: option.status
  //   });
  //   return (
  //     <div style={{ fontSize: '14px' }}>
  //       {option.name === 'Custom Motor Confiuration'
  //         ? motorSel.value !== 'Custom'
  //           ? ''
  //           : option.name
  //         : option.name}
  //     </div>
  //   );
  // };

  const motorParametersTab: Tab[] = [
    { name: metaDataName, status: motorSelectSymbol },
    {
      name: namePlate,
      status: motorSelectSymbol
    },
    {
      name: electrical,
      status: motorSelectSymbol
    },
    {
      name: mechanical,
      status: motorSelectSymbol
    },
    {
      name: sensor,
      status: motorSelectSymbol
    }
    // {
    //   name: custom,
    //   status: motorSelectSymbol
    // }
  ];

  const [value, setValue] = useState<Tab | null>(motorParametersTab[0]);

  return (
    <div>
      <div style={{ paddingBottom: '20px' }}>
        <div className='flex'>
          <div className='m-2'>
            <label> {motorSelection.label} </label>
          </div>
          <div>
            <ComboBoxDefault
              componentId={comp}
              symbolId={motorSelectSymbol}
            />
          </div>
        </div>
      </div>
      <div className='flex'>
        <ListBox
          style={{ height: '35rem', fontSize: '16px' }}
          value={value}
          options={motorParametersTab}
          optionLabel='name'
          // itemTemplate={tabTemplate}
          onChange={(e) => {
            setValue(e.value);
          }}
        />
        <div style={{ paddingLeft: '30px' }}>
          {value?.name && (
            <DisplayMotorParameters
              headdingName={value?.name ? value.name : metaDataName}
              componentId={comp}
              showToast={props.showToast}
            />
          )}
        </div>
      </div>
    </div>
  );
};
export default MotorParameters;
