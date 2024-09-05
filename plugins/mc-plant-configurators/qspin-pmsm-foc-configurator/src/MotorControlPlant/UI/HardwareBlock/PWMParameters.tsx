import { useEffect } from 'react';
import { AddTitleAndParameters } from '../../Tools/NodeUtils';
import { DialogCommonInitilizeCode } from '../CustomPopUp/CustomPopUp';
import { Divider } from 'primereact/divider';
import { useComboSymbol } from '@mplab_harmony/harmony-plugin-client-lib';
const PWMParameters = (props: { componentId: string; showToast: (arg0: any) => void }) => {
  const MCPMSMFOC_PWM_A_CHANNEL = useComboSymbol({
    componentId: props.componentId,
    symbolId: 'MCPMSMFOC_PWM_A_CHANNEL'
  });
  const MCPMSMFOC_PWM_B_CHANNEL = useComboSymbol({
    componentId: props.componentId,
    symbolId: 'MCPMSMFOC_PWM_B_CHANNEL'
  });
  const MCPMSMFOC_PWM_C_CHANNEL = useComboSymbol({
    componentId: props.componentId,
    symbolId: 'MCPMSMFOC_PWM_C_CHANNEL'
  });

  useEffect(() => {}, [MCPMSMFOC_PWM_A_CHANNEL, MCPMSMFOC_PWM_B_CHANNEL, MCPMSMFOC_PWM_C_CHANNEL]);

  let channelConfigurationn_instance = 'MCPMSMFOC_PWM_INSTANCE';
  let channelConfiguration = [
    channelConfigurationn_instance,
    'MCPMSMFOC_PWM_FREQUENCY',
    'MCPMSMFOC_PWM_PERIOD',
    'MCPMSMFOC_PWM_DEAD_TIME',
    'MCPMSMFOC_PWM_A_CHANNEL',
    'MCPMSMFOC_PWM_AH_PAD',
    'MCPMSMFOC_PWM_AL_PAD',
    'MCPMSMFOC_PWM_B_CHANNEL',
    'MCPMSMFOC_PWM_BH_PAD',
    'MCPMSMFOC_PWM_BL_PAD',
    'MCPMSMFOC_PWM_C_CHANNEL',
    'MCPMSMFOC_PWM_CH_PAD',
    'MCPMSMFOC_PWM_CL_PAD'
  ];

  let faultConfiguration = [
    'MCPMSMFOC_PWM_FAULT_SELECT',
    'MCPMSMFOC_PWM_FAULT_STATE',
    'MCPMSMFOC_PWM_FAULT_TYPE',
    'MCPMSMFOC_PWM_FAULT_FILTER',
    'MCPMSMFOC_PWM_FAULT_SOURCE'
  ];

  DialogCommonInitilizeCode(
    props.showToast,
    props.componentId,
    channelConfiguration.concat(faultConfiguration)
  );

  return (
    <div className='flex'>
      <AddTitleAndParameters
        Headding='Channel Configuration'
        SymbolsArray={channelConfiguration}
        component_id={props.componentId}
      />
      <Divider layout='vertical' />
      <br></br>
      <br></br>
      <br></br>
      <AddTitleAndParameters
        Headding='Fault Configuration'
        SymbolsArray={faultConfiguration}
        component_id={props.componentId}
      />
    </div>
  );
};
export default PWMParameters;
