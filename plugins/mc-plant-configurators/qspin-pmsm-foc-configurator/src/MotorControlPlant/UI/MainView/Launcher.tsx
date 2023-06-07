import { useState } from 'react';
import MainBlock, { mc_component_id } from './MainBlock';
import {
  ActivateComponent,
  IsComponentActive,
  IsComponentAvailable
} from '@mplab_harmony/harmony-plugin-core-service/build/project-service/ComponentStateChange';
import { info } from '@mplab_harmony/harmony-plugin-core-service';
import ProjectSupportMessage from './ProjectSupportMessage';

const Launcher = () => {
  const [mainComponentStatus, setMainComponentStatus] = useState(
    IsComponentActive(mc_component_id)
  );

  if (!mainComponentStatus) {
    info(mc_component_id + ' component is not active. Checking component available status');
    let isMainComponentAvailable = IsComponentAvailable(mc_component_id);
    if (isMainComponentAvailable) {
      info(
        mc_component_id +
          ' component is available to activate. So activating the component to launch mc plant configurator.'
      );
      ActivateComponent(mc_component_id);
      info(mc_component_id + ' component activated successfully.');
      setMainComponentStatus(true);
    } else {
      info(
        mc_component_id +
          ' component is not available to activate. So this project does not support mc plant configurator.'
      );
    }
  } else {
    info(mc_component_id + ' component is active.');
  }

  return (
    <div className='card'>
      {mainComponentStatus && <MainBlock />}
      {!mainComponentStatus && <ProjectSupportMessage />}
    </div>
  );
};
export default Launcher;
