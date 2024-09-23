import { ReactComponent as MotorControlPlant } from '../../../Resources/Svgs/mc_plant_view.svg';
import { ReactComponent as Tooltip } from '../../../Resources/Svgs/Tooltip.svg';
import { useContext, useEffect, useState } from 'react';
import mainBlockCss from './block-diagram-view.module.css';
import {
  createClassResolver,
  PluginConfigContext,
  PluginToolbar,
  usePannableContainer,
  useZoomableContainer
} from '@mplab_harmony/harmony-plugin-client-lib';
import { MenuItem } from 'primereact/menuitem';
import { ConfirmDialog } from 'primereact/confirmdialog';
import { Dialog } from 'primereact/dialog';
import { CallMouseLeave, CallMouseMove } from '../../Tools/svg/MouseEvent';
import GenericPopUp from '../CustomPopUp/CustomPopUp';
import PopUpWithoutFooter from '../CustomPopUp/PopUpWithoutFooter';
import { changeColor, resetColors, storeComponentColors } from '../../Tools/svg/Svgscripts';

export let core_id = 'core';
export let SummaryPageHeading = 'QSpin PMSM FOC Summary';

let svgdoc: any = null;
let toolTipObject: any = null;

let childKeyAndGroupIdValue = new Map<string, string>();

export let hardWareGroup = 'group_hardware';
export let controlGroup = 'group_control';
export let peripheralGroup = 'group_peripheral';
export let mcuGroup = 'group_mcu_config';

export let groupArray = [hardWareGroup, controlGroup, peripheralGroup, mcuGroup];

let ribbonKeyAndGroupValue = new Map<string, string>();
export let quickSettingsText = 'Quick Settings';
export let analogFrontEndText = 'Analog Front End';
export let motorParameters = 'Motor Parameters';
export let startupConfiguratorText = 'Start Up Configurator';
export let motorControlDiagnosisText = 'Motor Control & Diagnosis';
export let positionMeasurementCalculationText = 'Position Calculation & Diagnosis';
export let currentMeasurementAndDiagnosisText = 'Current Measurement & Diagnosis';
export let voltageMeasurementAndDiagnosisText = 'Voltage Measurement & Diagnosis';
export let pulseWidthModulatorText = 'Pulse Width Modulator';
export let analogInterfaceText = 'Analog Interface';
export let positionInterfaceText = 'Position Interface';
export let voltageSourceText = 'Voltage Source';
export let dataMonitoringText = 'Data Monitoring';
export let outputStageDignosisText = 'Output Stage Diagnosis';

const cx = createClassResolver(mainBlockCss);
let popUpHelp = '';
export let portNumber = (window as any).javaConnector.getPortNumber();
const MainBlock = () => {
  const { componentId = 'pmsm_foc' } = useContext(PluginConfigContext);
  const [summaryDialogVisible, setSummaryDialogVisible] = useState(false);
  const [genericPopupVisible, setGenericPopupVisible] = useState(false);
  const [messagePopup, setMessagePopup] = useState(false);
  const [actionId, setActionId] = useState('');

  const [dialogWidth, setDialogWidth] = useState('');
  const [dialogHeight, setDialogHeight] = useState('');
  const [messageText, setMessageText] = useState('');

  const zoomableContainer = useZoomableContainer();
  const pannableContainer = usePannableContainer();

  useEffect(() => {
    if (svgdoc === null) {
      newInit();
    }
  });

  const items: MenuItem[] = [
    {
      label: 'Summary',
      icon: 'pi pi-fw pi-chart-bar',
      command: () => setSummaryDialogVisible(true)
    },
    {
      label: 'Help',
      icon: 'pi pi-search',
      command: () => LoadHelp()
    },
    {
      label: 'Zoom',
      icon: 'pi pi-search-plus',
      items: [
        {
          label: 'Zoom In (Alt + Scroll Up)',
          icon: 'pi pi-fw pi-search-plus',
          command: () => zoomableContainer.zoomIn()
        },
        {
          label: 'Reset Zoom (Alt + Scroll Click)',
          icon: 'pi pi-fw pi-refresh',
          command: () => zoomableContainer.resetZoom()
        },
        {
          label: 'Zoom Out (Alt + Scroll Down)',
          icon: 'pi pi-fw pi-search-minus',
          command: () => zoomableContainer.zoomOut()
        }
      ]
    }
  ];

  const LoadHelp = () => {
    window.open(
      'http://localhost:' + portNumber + '/motor_control/documents/index.html',
      '_blank',
      'toolbar=0,location=0,menubar=0'
    );
  };

  function ShowAll() {
    resetColors(svgdoc);
  }

  function newInit() {
    svgdoc = document.getElementById('motor');

    let ribbon_hardware = 'ribbon_hardware';
    let ribbon_control = 'ribbon_control';
    let ribbon_peripheral = 'ribbon_peripheral';
    let ribbon_mcu_config = 'ribbon_mcu_config';

    ribbonKeyAndGroupValue.set(ribbon_hardware, hardWareGroup);
    ribbonKeyAndGroupValue.set(ribbon_control, controlGroup);
    ribbonKeyAndGroupValue.set(ribbon_peripheral, peripheralGroup);
    ribbonKeyAndGroupValue.set(ribbon_mcu_config, mcuGroup);

    addEventListeners('box_quicksettings', quickSettingsText, true);
    addEventListeners(ribbon_hardware, 'Hardware Configurations', false);
    addEventListeners(ribbon_control, 'Control Configurations', false);
    addEventListeners(ribbon_peripheral, 'Peripheral Configurations', false);
    addEventListeners(ribbon_mcu_config, 'MCU Configurations', false);

    addEventListeners('box_analog_frontend', analogFrontEndText, true);
    addEventListeners('box_motor', motorParameters, true);
    addEventListeners('box_startup_configurator', startupConfiguratorText, true);
    addEventListeners('box_motor_control_diagnosis', motorControlDiagnosisText, true);
    addEventListeners('box_output_stage', outputStageDignosisText, true);
    addEventListeners(
      'box_position_calculation_diagnosis',
      positionMeasurementCalculationText,
      true
    );
    addEventListeners(
      'box_current_measurement_diagnosis',
      currentMeasurementAndDiagnosisText,
      true
    );
    addEventListeners(
      'box_voltage_measurement_diagnosis',
      voltageMeasurementAndDiagnosisText,
      true
    );
    addEventListeners('box_pwm', pulseWidthModulatorText, true);
    addEventListeners('box_analog_interface', analogInterfaceText, true);
    addEventListeners('box_position_interface', positionInterfaceText, true);
    addEventListeners('box_vdc', voltageSourceText, true);
    addEventListeners('box_data_monitoring', dataMonitoringText, true);

    addEventListeners('box_clock_manager', 'Clock Manager', true);
    addEventListeners('box_io_manager', 'IO Manager', true);
    addEventListeners('box_interrupts_exception', 'Interrupts Exception Manager', true);
    addEventListeners('box_memory_manager', 'Memory Control Manager', true);

    toolTipObject = svgdoc.getElementById('tooltip');
    storeComponentColors(svgdoc);
  }

  function addEventListeners(groupid: any, dialogHeading: string, popupType: boolean) {
    let group = svgdoc.getElementById(groupid);
    IterateSVGElements(group, groupid, dialogHeading, popupType);
  }

  function IterateSVGElements(group: any, groupid: any, dialogHeading: string, popupType: boolean) {
    for (let i = 0; i < group.childNodes.length; i++) {
      let childElement = group.childNodes[i];
      childElement.addEventListener('click', sendClickAction, false);
      childElement.addEventListener('mousemove', mouseMove);
      childElement.addEventListener('mouseleave', mouseLeave);
      if (popupType) {
        childElement.value = dialogHeading;
      }
      childElement.toolTip = 'View ' + dialogHeading + ' Configuration';
      if (childElement.childNodes.length > 0) {
        IterateSVGElements(childElement, groupid, dialogHeading, popupType);
      }
      try {
        if (childElement.hasAttribute('id')) {
          let childId = childElement.getAttribute('id');
          childKeyAndGroupIdValue.set(childId, groupid);
        }
      } catch (err) {}
    }
  }

  function mouseMove(evt: { target: any }) {
    CallMouseMove(evt, svgdoc, toolTipObject);
  }

  function mouseLeave(evt: { target: any }) {
    CallMouseLeave(evt, toolTipObject);
  }

  function updateDialogInfo(actionId: string, width: string, height: string, helpUrl: string) {
    setGenericPopupVisible(true);
    setActionId(actionId);
    setDialogWidth(width);
    setDialogHeight(height);
    if (helpUrl !== '') {
      popUpHelp = helpUrl;
    } else {
      popUpHelp = '';
    }
  }

  function udpateMessageDialogInfo(
    actionId: string,
    width: string,
    height: string,
    message: string
  ) {
    setMessagePopup(true);
    setActionId(actionId);
    setDialogWidth(width);
    setDialogHeight(height);
    setMessageText(message);
  }

  function sendClickAction(evt: { target: any }) {
    let target = evt.target;
    if (target.correspondingUseElement) target = target.correspondingUseElement;

    switch (target.value) {
      case motorControlDiagnosisText: {
        updateDialogInfo(
          target.value,
          '102rem',
          '60rem',
          'GUID-1247DA32-16EE-410F-8821-9996138029EC.html'
        );
        return;
      }
      case positionMeasurementCalculationText: {
        updateDialogInfo(
          target.value,
          '102rem',
          '50rem',
          'GUID-3FC371D1-5F20-4FD5-BE9C-5E735208822F.html'
        );
        return;
      }
      case analogFrontEndText: {
        updateDialogInfo(
          target.value,
          '75rem',
          '40rem',
          'GUID-989E7AA5-599B-44EF-B07B-92CF360E8489.html'
        );
        return;
      }
      case analogInterfaceText: {
        updateDialogInfo(
          target.value,
          '70rem',
          '42rem',
          'GUID-F357EFE7-06A7-410D-9D17-FBE6A6933412.html'
        );
        return;
      }
      case voltageMeasurementAndDiagnosisText: {
        updateDialogInfo(
          target.value,
          '80rem',
          '35rem',
          'GUID-01B46490-213A-4272-8195-738256105928.html'
        );
        return;
      }
      case currentMeasurementAndDiagnosisText: {
        updateDialogInfo(
          target.value,
          '85rem',
          '40rem',
          'GUID-D30380EE-7150-40F0-8CD4-972379CEF307.html'
        );
        return;
      }
      case 'Clock Manager': {
        udpateMessageDialogInfo(
          target.value,
          '50rem',
          '15rem',
          'To configure Clock Manager, Please goto "Project Graph/plugins/Clock Manager" '
        );
        return;
      }
      case 'IO Manager': {
        udpateMessageDialogInfo(
          target.value,
          '50rem',
          '15rem',
          'To configure IO Manager, Please goto "Project Graph/plugins/PIN Manager" '
        );
        return;
      }
      case 'Interrupts Exception Manager': {
        udpateMessageDialogInfo(
          target.value,
          '50rem',
          '15rem',
          'To configure Interrupts Exception Manager, Please goto "Project Graph/plugins/NVIC Configuration" '
        );
        return;
      }
      case 'Memory Control Manager': {
        udpateMessageDialogInfo(
          target.value,
          '50rem',
          '15rem',
          'To configure Memory Control Manager, Please goto "Project Graph/plugins/MPU Configuration" '
        );
        return;
      }
      case motorParameters: {
        updateDialogInfo(
          target.value,
          '70rem',
          '50rem',
          'GUID-0B134E27-482C-48C3-8895-2AF0AEAFBA99.html'
        );
        return;
      }
      case pulseWidthModulatorText: {
        updateDialogInfo(
          target.value,
          '70rem',
          '45rem',
          'GUID-074A0B6E-2F55-48D4-9597-C94198261D9A.html'
        );
        return;
      }
      case positionInterfaceText: {
        updateDialogInfo(
          target.value,
          '30rem',
          '30rem',
          'GUID-593B51D7-753B-4F45-907A-9A084230C6CB.html'
        );
        return;
      }
      case outputStageDignosisText: {
        updateDialogInfo(
          target.value,
          '45rem',
          '20rem',
          'GUID-52CA4CA5-55BC-423F-B79E-B814E889984B.html'
        );
        return;
      }
      case startupConfiguratorText: {
        updateDialogInfo(
          target.value,
          '105rem',
          '60rem',
          'GUID-2E524004-ED37-4174-9ECC-3075003F70A7.html'
        );
        return;
      }
      case quickSettingsText: {
        updateDialogInfo(target.value, '40rem', '25rem', '');
        return;
      }
      case dataMonitoringText: {
        updateDialogInfo(
          target.value,
          '35rem',
          '20rem',
          'GUID-04C38070-686B-47B2-92B4-277FB5A980FC.html'
        );
        return;
      }
      case voltageSourceText: {
        updateDialogInfo(
          target.value,
          '35rem',
          '20rem',
          'GUID-39CB4463-8D2C-49F3-8335-00B1A0426867.html'
        );
        return;
      }
    }
    if (target.value) {
      updateDialogInfo(target.value, '80rem', '70rem', '');
      return;
    }
    let value: string = childKeyAndGroupIdValue.get(target.id) || '';
    if (value !== null) {
      MainBlockControlAction(value);
    }
  }

  function MainBlockControlAction(clickedRibbon: string) {
    if (clickedRibbon == null) {
      return;
    }
    resetColors(svgdoc);

    let i;
    for (i = 0; i < groupArray.length; i++) {
      let group = groupArray[i];
      if (group !== ribbonKeyAndGroupValue.get(clickedRibbon)) {
        let element = svgdoc.getElementById(group);
        changeColor(element);
      }
    }
  }

  return (
    <>
      <ConfirmDialog />
      <PluginToolbar
        menuItems={items}
        title='Harmony QSpin PMSM FOC'
      />
      <div
        className={cx('pannable-container')}
        ref={pannableContainer.ref}
        {...pannableContainer.props}>
        <div
          className={cx('svg-container')}
          ref={zoomableContainer.ref}
          {...zoomableContainer.props}>
          <MotorControlPlant
            id='motor'
            className='svg-container'
            onContextMenu={(e) => ShowAll()}
          />
        </div>
        <Dialog
          header={SummaryPageHeading}
          visible={summaryDialogVisible}
          maximizable={true}
          onHide={() => {
            setSummaryDialogVisible(!summaryDialogVisible);
          }}>
          {/* <Summary /> */}
        </Dialog>
        <GenericPopUp
          Id={actionId}
          widthValue={dialogWidth}
          heightValue={dialogHeight}
          helpLink={popUpHelp}
          dialogVisibleStatus={genericPopupVisible}
          setGenericPopupVisible={setGenericPopupVisible}
        />
        <PopUpWithoutFooter
          Id={actionId}
          messageText={messageText}
          widthValue={dialogWidth}
          heightValue={dialogHeight}
          dialogVisibleStatus={messagePopup}
          onHide={function (): void {
            setMessagePopup(false);
          }}
        />
        <div
          id='tooltip_object'
          style={{ display: 'none' }}>
          <Tooltip />
        </div>
      </div>
    </>
  );
};

export default MainBlock;
