import { useEffect } from 'react';
import MainBlock, { core_id, mc_component_id } from './MainBlock';
import {
  ActivateComponent,
  IsComponentActive,
  IsComponentAvailable
} from '@mplab_harmony/harmony-plugin-core-service/build/project-service/ComponentStateChange';
import { SetComponentId, error, info } from '@mplab_harmony/harmony-plugin-core-service';
import ProjectSupportMessage from './ProjectSupportMessage';
import { popUproot } from '../SVGScript';
import React from 'react';
import HarmonyServicesUpdateMessage from '../CustomPopUp/HarmonyServicesUpdateMessage';

let IsOldHarmonyServices = false;
let PMSMComponentActiveStatus = false;
const Launcher = () => {
  useEffect(() => {
    if (IsOldHarmonyServices) {
      const element = React.createElement(HarmonyServicesUpdateMessage);
      popUproot.render(element);
    }
  }, []);

  const AddComponent = (componenentId: string) => {
    info(componenentId + ' component is not active. Checking component available status');
    let isComponentAvailable = IsComponentAvailable(componenentId);
    if (isComponentAvailable) {
      info(componenentId + ' component is available to activate. So activating the component.');
      ActivateComponent(componenentId);
      return true;
    } else {
      return false;
    }
  };

  SetComponentId(mc_component_id);
  SetComponentId(core_id);

  PMSMComponentActiveStatus = IsComponentActive(mc_component_id);

  if (PMSMComponentActiveStatus === undefined) {
    error('Please update your harmony-services repository to latest version!');
    IsOldHarmonyServices = true;
    PMSMComponentActiveStatus = true;
  } else {
    if (!PMSMComponentActiveStatus) {
      PMSMComponentActiveStatus = AddComponent(mc_component_id);
      if (!PMSMComponentActiveStatus) {
        error(
          mc_component_id +
            ' component is not available to activate. So this project does not support mc plant configurator.'
        );
      }
    } else {
      info(mc_component_id + ' component is active.');
    }
  }

  return (
    <div className='card'>
      {PMSMComponentActiveStatus && <MainBlock />}
      {!PMSMComponentActiveStatus && <ProjectSupportMessage />}
    </div>
  );
};
export default Launcher;

(window as any).ComponentActivated = (value: any) => {
  info(value + ' component activated successfully');
};
(window as any).ComponentDeActivated = (value: any) => {
  info(value + ' component deactivated successfully');
};
