import { useContext, useEffect, useState } from 'react';
import ProjectSupportMessage from './ProjectSupportMessage';
import { error, info, PluginConfigContext } from '@mplab_harmony/harmony-plugin-client-lib';
import {
  ActivateComponent,
  IsComponentActive,
  IsComponentAvailable
} from '@mplab_harmony/harmony-plugin-core-service';
import MainBlock from './MainBlock';
import { Dialog } from 'primereact/dialog';

let IsOldHarmonyServices = false;
let PMSMComponentActiveStatus = false;
const Launcher = () => {
  const { componentId = 'pmsm_foc' } = useContext(PluginConfigContext);
  const [popUpStatus, setPopUpStatus] = useState(false);
  useEffect(() => {
    if (IsOldHarmonyServices) {
      setPopUpStatus(true);
    }
  }, []);

  const AddComponent = (componenentId: string) => {
    info(
      'Motor Control Plant',
      componenentId + ' component is not active. Checking component available status'
    );
    let isComponentAvailable = IsComponentAvailable(componenentId);
    if (isComponentAvailable) {
      info(
        'Motor Control Plant',
        componenentId + ' component is available to activate. So activating the component.'
      );
      ActivateComponent(componenentId);
      return true;
    } else {
      return false;
    }
  };
  PMSMComponentActiveStatus = IsComponentActive(componentId);

  if (PMSMComponentActiveStatus === undefined) {
    error(
      'Motor Control Plant',
      'Please update your harmony-services repository to latest version!'
    );
    IsOldHarmonyServices = true;
    PMSMComponentActiveStatus = true;
  } else {
    if (!PMSMComponentActiveStatus) {
      PMSMComponentActiveStatus = AddComponent(componentId);
      if (!PMSMComponentActiveStatus) {
        error(
          'MC Plant',
          componentId +
            ' component is not available to activate. So this project does not support mc plant configurator.'
        );
      }
    } else {
      info('MC Plant', componentId + ' component is active.');
    }
  }

  return (
    <div className='card'>
      {PMSMComponentActiveStatus && <MainBlock />}
      {!PMSMComponentActiveStatus && <ProjectSupportMessage />}
      <Dialog
        visible={popUpStatus}
        maximizable={true}
        closeOnEscape
        closable
        focusOnShow
        modal
        header={'Note'}
        style={{ width: '30vw', height: '15vh', fontSize: '14px' }}
        onHide={() => setPopUpStatus(false)}>
        <div className='flex justify-content-center align-items-center align-text-center'>
          Please update your harmony-services repository to latest version!
        </div>
      </Dialog>
    </div>
  );
};
export default Launcher;

(window as any).ComponentActivated = (value: any) => {
  info('MC Plant', value + ' component activated successfully');
};
(window as any).ComponentDeActivated = (value: any) => {
  info('MC Plant', value + ' component deactivated successfully');
};
