import { useContext, useState } from 'react';
import ProjectSupportMessage from './ProjectSupportMessage';
import {
  Component,
  componentApi,
  componentUtilApi,
  error,
  info,
  PluginConfigContext
} from '@mplab_harmony/harmony-plugin-client-lib';

import MainBlock from './MainBlock';
import { Dialog } from 'primereact/dialog';

const Launcher = () => {
  const { componentId = 'pmsm_foc' } = useContext(PluginConfigContext);
  const [popUpStatus, setPopUpStatus] = useState(false);
  const [PMSMComponentActiveStatus, setPMSMComponentActiveStatus] = useState(false);
  const [notSupproted, setNotSupported] = useState(false);

  const updateComponentSupportStatus = (status: boolean) => {
    setPMSMComponentActiveStatus(status);
    setNotSupported(!status);
  };
  const addComponent = (componenentId: string) => {
    info(
      'Motor Control Plant',
      componenentId + ' component is not active. Checking component available status'
    );
    componentUtilApi.getAvailableComponents().then((values: Component[]) => {
      let isComponentAvailable = values.map((value: Component) => {
        return value.componentId === componenentId;
      });
      if (isComponentAvailable) {
        info(
          'Motor Control Plant',
          componenentId + ' component is available to activate. So activating the component.'
        );
        componentUtilApi.activateComponents([componenentId]).then((value) => {
          updateComponentSupportStatus(true);
        });
      } else {
        updateComponentSupportStatus(false);
        error(
          'MC Plant',
          componentId +
            ' component is not available to activate. So this project does not support mc plant configurator.'
        );
      }
    });
  };
  componentApi.isActive(componentId).then((value) => {
    if (value === undefined) {
      error(
        'Motor Control Plant',
        'Please update your harmony-services repository to latest version!'
      );
      setPopUpStatus(true);
      setPMSMComponentActiveStatus(false);
      setNotSupported(false);
    } else {
      if (!value) {
        addComponent(componentId);
      } else {
        updateComponentSupportStatus(true);
        info('MC Plant', componentId + ' component is active.');
      }
    }
  });

  return (
    <div>
      {PMSMComponentActiveStatus && <MainBlock />}
      {notSupproted && <ProjectSupportMessage />}
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
