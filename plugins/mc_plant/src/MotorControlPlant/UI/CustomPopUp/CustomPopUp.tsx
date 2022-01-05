import { Dialog } from "primereact/dialog";
import { confirmDialog } from "primereact/confirmdialog";
import { Button } from "primereact/button";
import StartUpConfigurator from "../ControlBlock/StartUpConfigurator";
import useForceUpdate from "use-force-update";
import MotorControlDiagnosis, {
  SetMotorControlDiagnosisDefaultWindowView,
} from "../ControlBlock/MotorControlandDiagnosis";
import AnalogFrontEnd, {
  SetAnalogFrontEndDefaultWindowView,
} from "../HardwareBlock/AnalogFrontEnd";
import OutputStageDiagnosis from "../ControlBlock/OutputStageDiagnosis";
import MotorParameters from "../HardwareBlock/MotorParameters";
import PWMParameters from "../HardwareBlock/PWMParameters";
import { Toast } from "primereact/toast";
import { useRef } from "react";
import PrimeReact from "primereact/api";
import {
  clearAllSymbols,
  StroeSymbolArrayToMap,
  UpdateArrayofSymbolsResetAction,
} from "../../Common/Utils";
import { mc_component_id } from "../../Common/SymbolAccess";
import VoltageMeasurementDiagnosis, {
  SetVoltageMeasurementDefaultWindowView,
} from "../ControlBlock/VoltageMeasurementDiagnosis";
import CurrentMeasurementAndDiagnosisDualShunt, {
  SetCurrentMeasurementDefaultWindowView,
} from "../ControlBlock/CurrentMeasurementAndDiagnosisDualShunt";
import AnalogInterface, {
  SetAnalogInterfaceDefaultWindowView,
} from "../HardwareBlock/AnalogInterface";
import PositionInterface from "../HardwareBlock/PositionInterface";
import QuickSettings from "../MainView/QuickSettings";
import PositionMesurementAndDiagnosis, {
  SetPositionControlDiagnosisDefaultWindowView,
} from "../ControlBlock/PositionMesurementAndDiagnosis";
import VoltageSource from "../HardwareBlock/VoltageSource";
import DataMonitoring from "../ControlBlock/DataMonitoring";

let dialogVisibleStatus = false;
let resetToDefaultStatus = false;
let resetStatus = false;
let resetValues = new Map<String, Object>();

let ActionId: {} | null | undefined;
export function StartUpConfiguratorLoad(Id: string) {
  dialogVisibleStatus = true;
  ActionId = Id;
}

export function GetResetToDefaultStatus() {
  return resetToDefaultStatus;
}

export function SetResetToDefaultStatus(value: boolean) {
  resetToDefaultStatus = value;
}

export function GetResetStatus() {
  return resetStatus;
}

export function SetResetStatus(value: boolean) {
  resetStatus = value;
}

const GenericPopUp = () => {
  const update = useForceUpdate();

  PrimeReact.ripple = true;

  const toastRef = useRef<any>();

  const showToast = (message: any) => {
    toastRef.current.show({
      severity: "success",
      summary: message,
      life: 4000,
    });
  };

  const onHide = () => {
    dialogVisibleStatus = false;
    SetResetToDefaultStatus(false);
    SetResetStatus(false);
    resetValues.clear();
    update();
  };

  const callUpdate = () => {
    update();
  };

  const confirmPopupAccecpt = (name: String) => {
    if (name === "RESET_TO_DEFAULT") {
      SetResetToDefaultStatus(true);
    } else if (name === "RESET") {
      SetResetStatus(true);
    }
    callUpdate();
  };

  const confirmPopupReject = () => {
    // do nothing
  };

  const callConfirmDialog = (name: String) => {
    confirmDialog({
      message: "Are you sure you want to proceed?",
      header: "Confirmation",
      icon: "pi pi-exclamation-triangle",
      accept: () => confirmPopupAccecpt(name),
      reject: () => confirmPopupReject(),
    });
  };

  const onResetToDefault = () => {
    callConfirmDialog("RESET_TO_DEFAULT");
  };

  const onReset = () => {
    callConfirmDialog("RESET");
  };

  const renderFooter = () => {
    return (
      <div className="p-d-flex p-jc-between">
        <div>
          <Button
            type="button"
            className="p-button-raised p-button-rounded"
            label="Reset to Default"
            tooltip="Reset symbols to default value"
            tooltipOptions={{ position: "right" }}
            style={{ height: "1.75rem", fontSize: "14px" }}
            onClick={() => onResetToDefault()}
          />
        </div>
        <div>
          <Button
            type="button"
            className="p-button-raised p-button-rounded"
            label="Reset"
            tooltip="Reset symbols to original value"
            tooltipOptions={{ position: "left" }}
            style={{ height: "1.75rem", fontSize: "14px" }}
            onClick={() => onReset()}
          />
          <Button
            type="button"
            className="p-button-raised p-button-rounded"
            label="Close"
            style={{ height: "1.75rem", fontSize: "14px" }}
            onClick={() => onHide()}
            autoFocus
          />
        </div>
      </div>
    );
  };

  const LoadMotorDiagnosis = () => {
    return (
      <div>
        <MotorControlDiagnosis parentUpdate={update} showToast={showToast} />
        {SetMotorControlDiagnosisDefaultWindowView()}
      </div>
    );
  };

  const LoadPositionAndControlDiagnosis = () => {
    return (
      <div>
        <PositionMesurementAndDiagnosis
          parentUpdate={update}
          showToast={showToast}
        />
        {SetPositionControlDiagnosisDefaultWindowView()}
      </div>
    );
  };

  const VoltageMeasurementAndControlDiagnosis = () => {
    return (
      <div>
        <VoltageMeasurementDiagnosis
          parentUpdate={update}
          showToast={showToast}
        />
        {SetVoltageMeasurementDefaultWindowView()}
      </div>
    );
  };

  const CurrentMeasurementAndControlDiagnosis = () => {
    return (
      <div>
        <CurrentMeasurementAndDiagnosisDualShunt
          parentUpdate={update}
          showToast={showToast}
        />
        {SetCurrentMeasurementDefaultWindowView()}
      </div>
    );
  };

  const LoadAnalogFrontEnd = () => {
    return (
      <div>
        <AnalogFrontEnd parentUpdate={update} showToast={showToast} />
        {SetAnalogFrontEndDefaultWindowView()}
      </div>
    );
  };

  const LoadAnalogInterface = () => {
    return (
      <div>
        <AnalogInterface parentUpdate={update} showToast={showToast} />
        {SetAnalogInterfaceDefaultWindowView()}
      </div>
    );
  };

  return (
    <div className="dialog-demo">
      <Toast ref={toastRef} position="bottom-right"></Toast>
      <div className="card">
        <Dialog
          visible={dialogVisibleStatus}
          closeOnEscape
          closable
          focusOnShow
          modal
          header={ActionId}
          footer={renderFooter()}
          onHide={() => onHide()}
        >
          <div>
            {ActionId === "Motor Parameters" && (
              <MotorParameters parentUpdate={update} showToast={showToast} />
            )}
            {ActionId === "Pulse With Modulator" && (
              <PWMParameters parentUpdate={update} showToast={showToast} />
            )}
            {ActionId === "Start Up Configurator" && (
              <StartUpConfigurator showToast={showToast} />
            )}
            {ActionId === "Motor Control Diagnosis" && LoadMotorDiagnosis()}
            {ActionId === "Output Stage Diagnosis" && (
              <OutputStageDiagnosis
                parentUpdate={update}
                showToast={showToast}
              />
            )}
            {ActionId === "Current Measurement Diagnosis" &&
              CurrentMeasurementAndControlDiagnosis()}
            {ActionId === "Voltage Measurement Diagnosis" &&
              VoltageMeasurementAndControlDiagnosis()}
            {ActionId === "Position Calculation Diagnosis" &&
              LoadPositionAndControlDiagnosis()}
            {ActionId === "Analog Front End" && LoadAnalogFrontEnd()}
            {ActionId === "Analog Interface" && LoadAnalogInterface()}
            {ActionId === "Position Interface" && (
              <PositionInterface parentUpdate={update} showToast={showToast} />
            )}
            {ActionId === "Voltage Source" && (
              <VoltageSource parentUpdate={update} showToast={showToast} />
            )}
            {ActionId === "Data Monitoring" && (
              <DataMonitoring parentUpdate={update} showToast={showToast} />
            )}
            {ActionId === "Quick Settings" && (
              <QuickSettings parentUpdate={update} showToast={showToast} />
            )}
          </div>
        </Dialog>
      </div>
    </div>
  );
};

export default GenericPopUp;

export function callClearSymbols(
  showToast: (arg0: any) => void,
  symbolsArray: string[]
) {
  clearAllSymbols(mc_component_id, symbolsArray);
  SetResetToDefaultStatus(false);
  showToast("Reset to Default Action Completed!");
}

export function ResetSymbols(
  showToast: (arg0: any) => void,
  symbolsArray: string[]
) {
  UpdateArrayofSymbolsResetAction(resetValues, mc_component_id, symbolsArray);
  SetResetStatus(false);
  showToast("Reset Action Completed!");
}

export function DialogCommonInitilizeCode(
  showToast: (arg0: any) => void,
  symbolsArray: string[]
) {
  UpdateResetValues(symbolsArray);
  if (GetResetToDefaultStatus()) {
    callClearSymbols(showToast, symbolsArray);
  } else if (GetResetStatus()) {
    ResetSymbols(showToast, symbolsArray);
  }
}

export function UpdateResetValues(symbolsArray: string[]) {
  if (resetValues.size === 0 && symbolsArray.length !== 0) {
    resetValues = StroeSymbolArrayToMap(
      resetValues,
      mc_component_id,
      symbolsArray
    );
  }
}

export function ResetDialogSettings() {
  resetValues.clear();
}
