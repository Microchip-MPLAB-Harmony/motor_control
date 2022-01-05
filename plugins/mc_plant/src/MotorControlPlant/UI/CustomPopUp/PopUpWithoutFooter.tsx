import { Dialog } from "primereact/dialog";
import useForceUpdate from "use-force-update";

let dialogVisibleStatus = false;
let ActionId: {} | null | undefined;
let message: {} | null | undefined;
export function PopupWithoutFooterInput(Id: string, messageText: string) {
  dialogVisibleStatus = true;
  ActionId = Id;
  message = messageText;
}
const PopUpWithoutFooter = () => {
  const update = useForceUpdate();
  const onHide = () => {
    dialogVisibleStatus = false;
    update();
  };
  return (
    <div>
      <div className="card p-mx-auto">
        <Dialog
          visible={dialogVisibleStatus}
          closeOnEscape
          closable
          focusOnShow
          modal
          header={ActionId}
          onHide={() => onHide()}
        >
          <div>{message}</div>
        </Dialog>
      </div>
    </div>
  );
};
export default PopUpWithoutFooter;
