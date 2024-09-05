import { Dialog } from 'primereact/dialog';

const PopUpWithoutFooter = (props: {
  Id: string;
  messageText: string;
  widthValue: string;
  heightValue: string;
  dialogVisibleStatus: boolean;
  onHide: () => void;
}) => {
  const onHide = () => {
    props.onHide();
  };
  return (
    <div>
      <div className='card p-mx-auto'>
        <Dialog
          visible={props.dialogVisibleStatus}
          maximizable={true}
          closeOnEscape
          closable
          focusOnShow
          modal
          header={props.Id}
          style={{ width: props.widthValue, height: props.heightValue, fontSize: '14px' }}
          onHide={() => onHide()}>
          {props.messageText !== '' && (
            <div className='flex justify-content-center align-items-center align-text-center'>
              {props.messageText}
            </div>
          )}
        </Dialog>
      </div>
    </div>
  );
};
export default PopUpWithoutFooter;
