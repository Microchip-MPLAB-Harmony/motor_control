import { Dialog } from 'primereact/dialog';
import { ConfirmDialog, confirmDialog } from 'primereact/confirmdialog';
import { Button } from 'primereact/button';
import MotorControlDiagnosis, {
  SetMotorControlDiagnosisDefaultWindowView
} from '../ControlBlock/MotorControlDiagnosis/MotorControlandDiagnosis';
import AnalogFrontEnd, {
  SetAnalogFrontEndDefaultWindowView
} from '../HardwareBlock/AnalogFrontEnd/AnalogFrontEnd';
import OutputStageDiagnosis from '../ControlBlock/OutputStageDiagnosis';
import MotorParameters from '../HardwareBlock/MotorParameters/MotorParameters';
import PWMParameters from '../HardwareBlock/PWMParameters';
import { Toast } from 'primereact/toast';
import { useContext, useRef, useState } from 'react';
import VoltageMeasurementDiagnosis, {
  SetVoltageMeasurementDefaultWindowView
} from '../ControlBlock/VoltageMeasurementBlock/VoltageMeasurementDiagnosis';
import CurrentMeasurementAndDiagnosisDualShunt, {
  SetCurrentMeasurementDefaultWindowView
} from '../ControlBlock/CurrentMeasurementAndDiagnosisDualShunt';
import PositionInterface from '../HardwareBlock/PositionInterface';
import QuickSettings from '../MainView/QuickSettings';
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
} from '../../UI/MainView/MainBlock';
import { PluginConfigContext, symbolUtilApi } from '@mplab_harmony/harmony-plugin-client-lib';
import { StoreSymbolArrayToMap, UpdateArrayofSymbolsResetAction } from '../../Tools/CommonUtil';
import LoadPositionMeasureBlock from '../ControlBlock/PositionMeasurementBlock/LoadPositionMeasureBlock';
import AnalogInterface, {
  SetAnalogInterfaceDefaultWindowView
} from '../HardwareBlock/AnalogInterfaceBlock/AnalogInterface';
import StartUpConfigurator from '../ControlBlock/StartUpBlock/StartUpConfigurator';

let resetToDefaultStatus = false;
let resetStatus = false;
let resetValues = new Map<String, Object>();

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

const GenericPopUp = (props: {
  Id: string;
  helpLink?: string;
  widthValue: string;
  heightValue: string;
  dialogVisibleStatus: boolean;
  setGenericPopupVisible: (arg: boolean) => void;
}) => {
  const { componentId = 'pmsm_foc' } = useContext(PluginConfigContext);
  const [update, SetUpdate] = useState(false);
  const toastRef = useRef<any>();

  const showToast = (message: any) => {
    toastRef.current.show({
      severity: 'success',
      summary: message,
      life: 4000
    });
  };

  const onHide = () => {
    SetResetToDefaultStatus(false);
    SetResetStatus(false);
    resetValues.clear();
    props.setGenericPopupVisible(false);
  };

  const confirmPopupAccecpt = (name: String) => {
    if (name === 'RESET_TO_DEFAULT') {
      SetResetToDefaultStatus(true);
    } else if (name === 'RESET') {
      SetResetStatus(true);
    }
    SetUpdate(!update);
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
            style={{ height: '1.85rem', fontSize: '14px' }}
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
            style={{ height: '1.85rem', fontSize: '14px' }}
            onClick={() => onReset()}
          />
          <Button
            type='button'
            className='p-button-raised p-button-rounded'
            label='Close'
            style={{ height: '1.85rem', fontSize: '14px' }}
            onClick={() => onHide()}
            autoFocus
          />
        </div>
      </div>
    );
  };

  const renderHeader = () => {
    return (
      <div className='flex justify-content-between'>
        <div>
          <label>{props.Id}</label>
        </div>
        <div>
          <Button
            type='button'
            className='p-button-raised p-button-rounded'
            label='Help'
            icon='pi pi-search'
            style={{ height: '1.85rem', fontSize: '14px', marginRight: '20px' }}
            onClick={() =>
              props.helpLink
                ? onHelp(props.helpLink)
                : toastRef.current.show({
                    severity: 'error',
                    summary: 'Help not available !',
                    life: 4000
                  })
            }
            autoFocus
          />
        </div>
      </div>
    );
  };

  const onHelp = (helpLink: string) => {};

  const LoadMotorDiagnosis = () => {
    SetMotorControlDiagnosisDefaultWindowView();
    return (
      <div>
        <MotorControlDiagnosis
          componentId={componentId}
          showToast={showToast}
          dialogVisibleStatus={props.dialogVisibleStatus}
        />
      </div>
    );
  };

  const LoadPositionAndControlDiagnosis = () => {
    return (
      <div>
        <LoadPositionMeasureBlock
          showToast={showToast}
          componentId={componentId}
          dialogVisibleStatus={props.dialogVisibleStatus}
        />
      </div>
    );
  };

  const VoltageMeasurementAndControlDiagnosis = () => {
    SetVoltageMeasurementDefaultWindowView();
    return (
      <div>
        <VoltageMeasurementDiagnosis
          showToast={showToast}
          componentId={componentId}
          dialogVisibleStatus={props.dialogVisibleStatus}
        />
      </div>
    );
  };

  const CurrentMeasurementAndControlDiagnosis = () => {
    SetCurrentMeasurementDefaultWindowView();
    return (
      <div>
        <CurrentMeasurementAndDiagnosisDualShunt
          componentId={componentId}
          showToast={showToast}
          dialogVisibleStatus={props.dialogVisibleStatus}
        />
      </div>
    );
  };

  const LoadAnalogFrontEnd = () => {
    SetAnalogFrontEndDefaultWindowView();
    return (
      <div>
        <AnalogFrontEnd
          componentId={componentId}
          showToast={showToast}
          dialogVisibleStatus={props.dialogVisibleStatus}
        />
      </div>
    );
  };

  const LoadAnalogInterface = () => {
    SetAnalogInterfaceDefaultWindowView();
    return (
      <div>
        <AnalogInterface
          componentId={componentId}
          showToast={showToast}
          dialogVisibleStatus={props.dialogVisibleStatus}
        />
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
          visible={props.dialogVisibleStatus}
          maximizable={true}
          closeOnEscape
          closable
          focusOnShow
          modal
          style={{ width: props.widthValue, height: props.heightValue, fontSize: '14px' }}
          header={renderHeader()}
          footer={renderFooter()}
          onHide={() => onHide()}>
          <div>
            {props.Id === motorParameters && <MotorParameters showToast={showToast} />}
            {props.Id === pulseWidthModulatorText && (
              <PWMParameters
                componentId={componentId}
                showToast={showToast}
              />
            )}
            {props.Id === startupConfiguratorText && (
              <StartUpConfigurator
                showToast={showToast}
                componentId={componentId}
              />
            )}
            {props.Id === motorControlDiagnosisText && LoadMotorDiagnosis()}
            {props.Id === outputStageDignosisText && (
              <OutputStageDiagnosis
                showToast={showToast}
                componentId={componentId}
              />
            )}
            {props.Id === currentMeasurementAndDiagnosisText &&
              CurrentMeasurementAndControlDiagnosis()}
            {props.Id === voltageMeasurementAndDiagnosisText &&
              VoltageMeasurementAndControlDiagnosis()}
            {props.Id === positionMeasurementCalculationText && LoadPositionAndControlDiagnosis()}
            {props.Id === analogFrontEndText && LoadAnalogFrontEnd()}
            {props.Id === analogInterfaceText && LoadAnalogInterface()}
            {props.Id === positionInterfaceText && (
              <PositionInterface
                componentId={componentId}
                showToast={showToast}
              />
            )}
            {props.Id === voltageSourceText && (
              <VoltageSource
                componentId={componentId}
                showToast={showToast}
              />
            )}
            {props.Id === dataMonitoringText && (
              <DataMonitoring
                componentId={componentId}
                showToast={showToast}
              />
            )}
            {props.Id === quickSettingsText && (
              <QuickSettings
                componentId={componentId}
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

export function callClearSymbols(
  showToast: (arg0: any) => void,
  componentId: string,
  symbolsArray: string[]
) {
  symbolUtilApi.clearUserValue(componentId, symbolsArray).then((v) => {
    SetResetToDefaultStatus(false);
    ResetDialogSettings();
    showToast('Reset to Default Action Completed!');
  });
}

export const ResetSymbols = async (
  showToast: (arg0: any) => void,
  componentId: string,
  symbolsArray: string[]
) => {
  if (resetValues.size === 0) {
    symbolUtilApi.clearUserValue(componentId, symbolsArray);
  } else {
    UpdateArrayofSymbolsResetAction(resetValues, componentId, symbolsArray);
  }
  SetResetStatus(false);
  ResetDialogSettings();
  showToast('Revert Action Completed!');
};

export function DialogCommonInitilizeCode(
  showToast: (arg0: any) => void,
  componentId: string,
  symbolsArray: string[]
) {
  UpdateResetValues(componentId, symbolsArray);
  if (GetResetToDefaultStatus()) {
    callClearSymbols(showToast, componentId, symbolsArray);
  } else if (GetResetStatus()) {
    ResetSymbols(showToast, componentId, symbolsArray);
  }
}

export function UpdateResetValues(componentId: string, symbolsArray: string[]) {
  if (resetValues.size === 0 && symbolsArray.length !== 0) {
    StoreSymbolArrayToMap(resetValues, componentId, symbolsArray).then(
      (value) => (resetValues = value)
    );
  }
}

export function ResetDialogSettings() {
  resetValues.clear();
}
