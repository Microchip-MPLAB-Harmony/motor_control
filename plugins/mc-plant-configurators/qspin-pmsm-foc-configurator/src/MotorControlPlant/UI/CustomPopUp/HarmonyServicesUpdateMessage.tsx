import { Dialog } from 'primereact/dialog';
import { useEffect, useState } from 'react';

const HarmonyServicesUpdateMessage = () => {
  const [visible, setVisible] = useState(false);

  useEffect(() => {
    setVisible(true);
  }, []);

  const onHide = () => {
    setVisible(false);
  };
  return (
    <div>
      <div className='card p-mx-auto'>
        <Dialog
          visible={visible}
          maximizable={true}
          closeOnEscape
          closable
          focusOnShow
          modal
          header={'Note'}
          style={{ width: '30vw', height: '15vh', fontSize: '14px' }}
          onHide={() => onHide()}>
          <div className='flex justify-content-center align-items-center align-text-center'>
            Please update your harmony-services repository to latest version!
          </div>
        </Dialog>
      </div>
    </div>
  );
};
export default HarmonyServicesUpdateMessage;
