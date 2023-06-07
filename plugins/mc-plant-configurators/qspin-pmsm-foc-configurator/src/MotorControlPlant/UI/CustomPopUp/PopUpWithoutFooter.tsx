import { Dialog } from 'primereact/dialog';
import useForceUpdate from 'use-force-update';
import SummaryPage from '../Summary/Summary';
import { SummaryPageHeading } from '../MainView/MainBlock';

let dialogVisibleStatus = false;
let ActionId: any;
let message: any;
let Width: any;
let Height: any;
export function PopupWithoutFooterInput(
  Id: string,
  messageText: string,
  widthValue: string,
  heightValue: string
) {
  dialogVisibleStatus = true;
  ActionId = Id;
  message = messageText;
  Width = widthValue;
  Height = heightValue;
}
const PopUpWithoutFooter = () => {
  const update = useForceUpdate();
  const onHide = () => {
    dialogVisibleStatus = false;
    update();
  };
  return (
    <div>
      <div className='card p-mx-auto'>
        <Dialog
          visible={dialogVisibleStatus}
          maximizable={true}
          closeOnEscape
          closable
          focusOnShow
          modal
          header={ActionId}
          style={{ width: Width, height: Height, fontSize: '14px' }}
          onHide={() => onHide()}>
          {ActionId === SummaryPageHeading && <SummaryPage />}
          {message !== '' && (
            <div className='flex justify-content-center align-items-center align-text-center'>
              {message}
            </div>
          )}
        </Dialog>
      </div>
    </div>
  );
};
export default PopUpWithoutFooter;
