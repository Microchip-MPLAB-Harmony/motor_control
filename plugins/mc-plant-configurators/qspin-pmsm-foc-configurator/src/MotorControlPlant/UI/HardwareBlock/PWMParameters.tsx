import { AddDynamicSymbols } from '@mplab_harmony/harmony-plugin-core-service/build/database-access/SymbolUtils';
import { DialogCommonInitilizeCode } from '../CustomPopUp/CustomPopUp';
import { Divider } from 'primereact/divider';
import { mc_component_id } from '../MainView/MainBlock';
import { AddTitleAndParameters } from '@mplab_harmony/harmony-plugin-ui/build/utils/NodeUtils';
const PWMParameters = (props: { showToast: (arg0: any) => void }) => {
  let channelConfigurationn_instance = 'MCPMSMFOC_PWM_INSTANCE';
  let channelConfiguration = [
    channelConfigurationn_instance,
    'MCPMSMFOC_PWM_FREQUENCY',
    'MCPMSMFOC_PWM_PERIOD',
    'MCPMSMFOC_PWM_DEAD_TIME'
  ];

  channelConfiguration = AddDynamicSymbols(
    mc_component_id,
    channelConfigurationn_instance,
    'PWM_A',
    channelConfiguration
  );
  channelConfiguration = AddDynamicSymbols(
    mc_component_id,
    channelConfigurationn_instance,
    'PWM_B',
    channelConfiguration
  );
  channelConfiguration = AddDynamicSymbols(
    mc_component_id,
    channelConfigurationn_instance,
    'PWM_C',
    channelConfiguration
  );

  let faultConfiguration = [
    'MCPMSMFOC_PWM_FAULT_SELECT',
    'MCPMSMFOC_PWM_FAULT_STATE',
    'MCPMSMFOC_PWM_FAULT_TYPE',
    'MCPMSMFOC_PWM_FAULT_FILTER'
  ];

  function SymbolValueChanged(onchange: Map<String, any>) {
    // do nothing
  }

  DialogCommonInitilizeCode(props.showToast, channelConfiguration.concat(faultConfiguration));

  return (
    <div className='flex'>
      <AddTitleAndParameters
        Headding='Channel Configuration'
        SymbolsArray={channelConfiguration}
        onChange={SymbolValueChanged}
        component_id={mc_component_id}
      />
      <Divider layout='vertical' />
      <br></br>
      <br></br>
      <br></br>
      <AddTitleAndParameters
        Headding='Fault Configuration'
        SymbolsArray={faultConfiguration}
        onChange={SymbolValueChanged}
        component_id={mc_component_id}
      />
    </div>
  );
};
export default PWMParameters;
