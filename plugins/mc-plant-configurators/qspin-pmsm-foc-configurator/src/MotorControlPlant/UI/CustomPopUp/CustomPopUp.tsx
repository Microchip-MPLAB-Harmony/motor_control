import { Dialog } from 'primereact/dialog';
import { ConfirmDialog, confirmDialog } from 'primereact/confirmdialog';
import { Button } from 'primereact/button';
import StartUpConfigurator from '../ControlBlock/StartUpConfigurator';
import useForceUpdate from 'use-force-update';
import MotorControlDiagnosis, {
  SetMotorControlDiagnosisDefaultWindowView
} from '../ControlBlock/MotorControlandDiagnosis';
import AnalogFrontEnd, {
  SetAnalogFrontEndDefaultWindowView
} from '../HardwareBlock/AnalogFrontEnd';
import OutputStageDiagnosis from '../ControlBlock/OutputStageDiagnosis';
import MotorParameters from '../HardwareBlock/MotorParameters';
import PWMParameters from '../HardwareBlock/PWMParameters';
import { Toast } from 'primereact/toast';
import { useRef } from 'react';
import VoltageMeasurementDiagnosis, {
  SetVoltageMeasurementDefaultWindowView
} from '../ControlBlock/VoltageMeasurementDiagnosis';
import CurrentMeasurementAndDiagnosisDualShunt, {
  SetCurrentMeasurementDefaultWindowView
} from '../ControlBlock/CurrentMeasurementAndDiagnosisDualShunt';
import AnalogInterface, {
  SetAnalogInterfaceDefaultWindowView
} from '../HardwareBlock/AnalogInterface';
import PositionInterface from '../HardwareBlock/PositionInterface';
import QuickSettings from '../MainView/QuickSettings';
import PositionMesurementAndDiagnosis, {
  SetPositionControlDiagnosisDefaultWindowView
} from '../ControlBlock/PositionMesurementAndDiagnosis';
import VoltageSource from '../HardwareBlock/VoltageSource';
import DataMonitoring from '../ControlBlock/DataMonitoring';
import {
  motorControlDiagnosisText,
  motorParameters,
  pulseWidthModulatorText,
  startupConfiguratorText,
  outputStageDignosisText,
  currentMeasurementAndDiagnosisText,
  voltageMeasurementAndDiagnosisText,
  positionMeasurementCalculationText,
  analogFrontEndText,
  analogInterfaceText,
  positionInterfaceText,
  voltageSourceText,
  dataMonitoringText,
  quickSettingsText
} from '../SVGScript';
import {
  StoreSymbolArrayToMap,
  UpdateArrayofSymbolsResetAction,
  clearAllSymbols
} from '@mplab_harmony/harmony-plugin-core-service/build/database-access/SymbolUtils';
import { mc_component_id } from '../MainView/MainBlock';

let dialogVisibleStatus = false;
let resetToDefaultStatus = false;
let resetStatus = false;
let resetValues = new Map<String, Object>();

let ActionId: any;
let Width: any;
let Height: any;
export function CustomPopUpLoadConfig(Id: string, widthValue: string, heightValue: string) {
  dialogVisibleStatus = true;
  ActionId = Id;
  Width = widthValue;
  Height = heightValue;
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

  const toastRef = useRef<any>();

  const showToast = (message: any) => {
    toastRef.current.show({
      severity: 'success',
      summary: message,
      life: 4000
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
    if (name === 'RESET_TO_DEFAULT') {
      SetResetToDefaultStatus(true);
    } else if (name === 'RESET') {
      SetResetStatus(true);
    }
    callUpdate();
  };

  const confirmPopupReject = () => {
    // do nothing
  };

  const callConfirmDialog = (name: String) => {
    confirmDialog({
      message: 'Are you sure you want to proceed?',
      header: 'Confirmation',
      icon: 'pi pi-exclamation-triangle',
      accept: () => confirmPopupAccecpt(name),
      reject: () => confirmPopupReject()
    });
  };

  const onResetToDefault = () => {
    callConfirmDialog('RESET_TO_DEFAULT');
  };

  const onReset = () => {
    callConfirmDialog('RESET');
  };

  const renderFooter = () => {
    return (
      <div className='flex justify-content-between'>
        <div>
          <Button
            type='button'
            className='p-button-raised p-button-rounded'
            label='Reset to Default'
            tooltip='Reset symbols to default value'
            tooltipOptions={{ position: 'right' }}
            style={{ height: '1.75rem', fontSize: '14px' }}
            onClick={() => onResetToDefault()}
          />
        </div>
        <div>
          <Button
            type='button'
            className='p-button-raised p-button-rounded'
            label='Revert'
            tooltip='Revert symbols to previous saved value'
            tooltipOptions={{ position: 'left' }}
            style={{ height: '1.75rem', fontSize: '14px' }}
            onClick={() => onReset()}
          />
          <Button
            type='button'
            className='p-button-raised p-button-rounded'
            label='Close'
            style={{ height: '1.75rem', fontSize: '14px' }}
            onClick={() => onHide()}
            autoFocus
          />
        </div>
      </div>
    );
  };

  const LoadMotorDiagnosis = () => {
    SetMotorControlDiagnosisDefaultWindowView();
    return (
      <div>
        <MotorControlDiagnosis showToast={showToast} />
      </div>
    );
  };

  const LoadPositionAndControlDiagnosis = () => {
    SetPositionControlDiagnosisDefaultWindowView();
    return (
      <div>
        <PositionMesurementAndDiagnosis showToast={showToast} />
      </div>
    );
  };

  const VoltageMeasurementAndControlDiagnosis = () => {
    SetVoltageMeasurementDefaultWindowView();
    return (
      <div>
        <VoltageMeasurementDiagnosis showToast={showToast} />
      </div>
    );
  };

  const CurrentMeasurementAndControlDiagnosis = () => {
    SetCurrentMeasurementDefaultWindowView();
    return (
      <div>
        <CurrentMeasurementAndDiagnosisDualShunt showToast={showToast} />
      </div>
    );
  };

  const LoadAnalogFrontEnd = () => {
    SetAnalogFrontEndDefaultWindowView();
    return (
      <div>
        <AnalogFrontEnd showToast={showToast} />
      </div>
    );
  };

  const LoadAnalogInterface = () => {
    SetAnalogInterfaceDefaultWindowView();
    return (
      <div>
        <AnalogInterface showToast={showToast} />
      </div>
    );
  };

  return (
    <div className='dialog-demo'>
      <ConfirmDialog />
      <Toast
        ref={toastRef}
        position='bottom-right'></Toast>
      <div className='card'>
        <Dialog
          visible={dialogVisibleStatus}
          maximizable={true}
          closeOnEscape
          closable
          focusOnShow
          modal
          style={{ width: Width, height: Height, fontSize: '14px' }}
          header={ActionId}
          footer={renderFooter()}
          onHide={() => onHide()}>
          <div>
            {ActionId === motorParameters && <MotorParameters showToast={showToast} />}
            {ActionId === pulseWidthModulatorText && <PWMParameters showToast={showToast} />}
            {ActionId === startupConfiguratorText && <StartUpConfigurator showToast={showToast} />}
            {ActionId === motorControlDiagnosisText && LoadMotorDiagnosis()}
            {ActionId === outputStageDignosisText && <OutputStageDiagnosis showToast={showToast} />}
            {ActionId === currentMeasurementAndDiagnosisText &&
              CurrentMeasurementAndControlDiagnosis()}
            {ActionId === voltageMeasurementAndDiagnosisText &&
              VoltageMeasurementAndControlDiagnosis()}
            {ActionId === positionMeasurementCalculationText && LoadPositionAndControlDiagnosis()}
            {ActionId === analogFrontEndText && LoadAnalogFrontEnd()}
            {ActionId === analogInterfaceText && LoadAnalogInterface()}
            {ActionId === positionInterfaceText && (
              <PositionInterface
                parentUpdate={update}
                showToast={showToast}
              />
            )}
            {ActionId === voltageSourceText && (
              <VoltageSource
                parentUpdate={update}
                showToast={showToast}
              />
            )}
            {ActionId === dataMonitoringText && <DataMonitoring showToast={showToast} />}
            {ActionId === quickSettingsText && (
              <QuickSettings
                parentUpdate={update}
                showToast={showToast}
              />
            )}
          </div>
        </Dialog>
      </div>
    </div>
  );
};

export default GenericPopUp;

export function callClearSymbols(showToast: (arg0: any) => void, symbolsArray: string[]) {
  clearAllSymbols(mc_component_id, symbolsArray);
  SetResetToDefaultStatus(false);
  ResetDialogSettings();
  showToast('Reset to Default Action Completed!');
}

export function ResetSymbols(showToast: (arg0: any) => void, symbolsArray: string[]) {
  if (resetValues.size === 0) {
    clearAllSymbols(mc_component_id, symbolsArray);
  } else {
    UpdateArrayofSymbolsResetAction(resetValues, mc_component_id, symbolsArray);
  }
  SetResetStatus(false);
  ResetDialogSettings();
  showToast('Revert Action Completed!');
}

export function DialogCommonInitilizeCode(showToast: (arg0: any) => void, symbolsArray: string[]) {
  UpdateResetValues(symbolsArray);
  if (GetResetToDefaultStatus()) {
    callClearSymbols(showToast, symbolsArray);
  } else if (GetResetStatus()) {
    ResetSymbols(showToast, symbolsArray);
  }
}

export function UpdateResetValues(symbolsArray: string[]) {
  if (resetValues.size === 0 && symbolsArray.length !== 0) {
    resetValues = StoreSymbolArrayToMap(resetValues, mc_component_id, symbolsArray);
  }
}

export function ResetDialogSettings() {
  resetValues.clear();
}
