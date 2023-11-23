import { Divider } from 'primereact/divider';
import { ReactComponent as PMDEB } from '../../../Resources/Svgs/ControlBlock/Position_Measurement_and_Diagnosis-Equation_based.svg';
import { ReactComponent as PMDQD } from '../../../Resources/Svgs/ControlBlock/Position_Measurement_and_Diagnosis-Quadrature_decoder.svg';
import { ReactComponent as ZSMTHYBRID } from '../../../Resources/Svgs/ControlBlock/Position_Measurement_and_Diagnosis_ZSMT_Hybrid.svg';
import { ReactComponent as SMO } from '../../../Resources/Svgs/ControlBlock/Position_Measurement_and_Diagnosis_SMO.svg';

import React from 'react';

import {
  DialogCommonInitilizeCode,
  GetResetStatus,
  GetResetToDefaultStatus,
  ResetDialogSettings
} from '../CustomPopUp/CustomPopUp';
import {
  GetSymbolArray,
  GetSymbolLabelName,
  GetSymbolValue
} from '@mplab_harmony/harmony-plugin-core-service';
import { mc_component_id } from '../MainView/MainBlock';
import {
  AddImageAndParameters,
  AddTitleAndParameters
} from '@mplab_harmony/harmony-plugin-ui/build/utils/NodeUtils';
import { getIndex } from '@mplab_harmony/harmony-plugin-ui/build/utils/CommonUtil';
import {
  CallMouseMove,
  GetUIComponentWithOutLabel,
  StateLabel
} from '@mplab_harmony/harmony-plugin-ui';
import { CallMouseLeave } from '@mplab_harmony/harmony-plugin-ui/build/svg/MouseEvent';

let svgObj: any = null;
let childAndParent = new Map<any, any>();
let valueAndSVG = new Map<any, any>();
let svgAndToolTipObject = new Map<any, any>();
let ebIds = ['box_motor_model', 'box_ab_dq', 'box_lpf_top', 'box_lpf_middle', 'box_lpf_bottom'];
let qdIds = ['box-digitalnoisefilter', 'box-quadraturedecoder'];
let zsmtIds = [
  'box-primary-observer',
  'box-secondary-observer',
  'box-angle-tracker',
  'box-soft-switch'
];
let smoIds = [
  'box-current-observer',
  'box-switching-function',
  'box-bemf-observer',
  'box-flux-angle_calculator'
];
let actionIds = [...ebIds, ...qdIds, ...zsmtIds, ...smoIds];
let defaultViewGlobal = actionIds[0];

let showmotorModelSymbolsArray: any[] = [];
let showABIQModelSymbols: any[] = [];
let showLPFEdModelSymbols = ['MCPMSMFOC_ED_FILTER_PARAMETER'];
let showPFEqModelSymbols = ['MCPMSMFOC_EQ_FILTER_PARAMETER'];
let showLPFSpeedModelSymbols = ['MCPMSMFOC_SPEED_FILTER_PARAMETER'];
let showDigitalNoiseFilterSymbols = ['MCPMSMFOC_ENCODER_DNF_COUNT'];
let showQuadratureDecoderSymbols = ['MCPMSMFOC_ENCODER_QDEC_PULSE_PER_EREV'];
let showPrimaryObserverSymbols = [
  'MCPMSMFOC_ZSMT_HYB_PRIM_OBS',
  'MCPMSMFOC_ZSMT_HYB_HFI_MAGNITUDE'
];
let showSecondaryObserverSymbols = [
  'MCPMSMFOC_ZSMT_HYB_SEC_OBS',
  'MCPMSMFOC_ZSMT_HYB_BEMF_FILT_PARAM'
];
let showAngleTrackerSymbols = [
  'MCPMSMFOC_ZSMT_HYB_PLL_TRACKING_LOOP_TYPE',
  'MCPMSMFOC_ZSMT_HYB_HFI_KEPS',
  'MCPMSMFOC_ZSMT_HYB_ANGLE_TRACK_F0'
];
let showSoftSwitchSymbols = ['MCPMSMFOC_ZSMT_HYB_LOWER_TH', 'MCPMSMFOC_ZSMT_HYB_UPPER_TH'];
let showslidingModeCurrentObserverSymbols = [
  'MCPMSMFOC_R',
  'MCPMSMFOC_LD',
  'MCPMSMFOC_LQ',
  'MCPMSMFOC_POLE_PAIRS'
];

let showReducedOrderLuenbergerObserver = [
  'MCPMSMFOC_BEMF_OBSERVER_ROLO_POLE',
  'MCPMSMFOC_ROLO_PHASE_DETECTION_ALGORITHAM',
  'MCPMSMFOC_ROLO_PHASE_DETECTION_F0'
];

let showSwitchingFunctionSymbols = [
  'MCPMSMFOC_SWITCHING_FUNCTION_BOUNDARY',
  'MCPMSMFOC_SWITCHING_FUNCTION_GAIN'
];
let showBackEMFObserverSymbols = ['MCPMSMFOC_BEMF_OBSERVER_POLE'];
let showFluxAngleCalculationSymbols = [
  'MCPMSMFOC_PHASE_DETECTION_ALGORITHM',
  'MCPMSMFOC_PHASE_DETECTION_F0'
];

interface IProps {
  showToast: (arg0: any) => void;
}

interface IState {
  positionMesurementModelSelectedValue?: any;
  currentView?: string;
}
let obj: PositionMesurementAndDiagnosis | null = null;

let positionMesurementModel = 'MCPMSMFOC_POSITION_CALC_ALGORITHM';

class PositionMesurementAndDiagnosis extends React.Component<IProps, IState> {
  constructor(props: IProps) {
    super(props);

    this.state = {
      currentView: defaultViewGlobal,
      positionMesurementModelSelectedValue: GetSymbolValue(mc_component_id, positionMesurementModel)
    };
    this.MotorControlChanged = this.MotorControlChanged.bind(this);
    this.currentViewChanged = this.currentViewChanged.bind(this);
    obj = this;
  }
  positionMesurementModelArray = GetSymbolArray(mc_component_id, positionMesurementModel);

  currentViewChanged(newView: string) {
    this.setState({ currentView: newView });
  }

  MotorControlChanged(onChangeData: Map<String, any>) {
    let newValue = onChangeData.get('symbolValue');
    this.setState({ positionMesurementModelSelectedValue: newValue });
    ResetDefaultView(getIndex(newValue, this.positionMesurementModelArray));
  }

  componentDidUpdate() {
    RegisterPositionControlDiagnosisSVGActions();
  }

  SymbolValueChanged(onchange: Map<String, any>) {
    // do nothing
  }

  showEB() {
    return (
      <div className='flex'>
        <div className='flex-column'>
          {this.GetPositonControlElement()}
          <div className='m-4'>
            <PMDEB id='PositionMesurementAndDiagnosisEB' />
          </div>
        </div>
        <Divider layout='vertical' />
        {getIndex(defaultViewGlobal, ebIds) === 0 && this.showMotorModel()}
        {getIndex(defaultViewGlobal, ebIds) === 1 && this.showABIQModel()}
        {getIndex(defaultViewGlobal, ebIds) === 2 &&
          this.showConfigProps('Ed Filter', showLPFEdModelSymbols)}
        {getIndex(defaultViewGlobal, ebIds) === 3 &&
          this.showConfigProps('Eq Filter', showPFEqModelSymbols)}
        {getIndex(defaultViewGlobal, ebIds) === 4 &&
          this.showConfigProps('Speed Filter', showLPFSpeedModelSymbols)}
      </div>
    );
  }

  showMotorModel() {
    return (
      <div className='flex flex-row'>
        {/* <Image
          src='../../../Resources/Svgs/ControlBlock/cleaned_motor1.svg'
          preview
        /> */}
        {this.showConfigProps('Motor Model', showmotorModelSymbolsArray)}
      </div>
    );
  }

  showABIQModel() {
    return (
      <div className='flex flex-row'>
        {/* <Avatar
          image='../../../Resources/Svgs/ControlBlock/Position_Measurement_and_Diagnosis-Equation_based_AB_DQ_Transformation.svg'
          size='large'
        /> */}
        {this.showConfigProps('AB - IQ Transform', showABIQModelSymbols)}
      </div>
    );
  }

  showQD() {
    return (
      <div className='flex'>
        <div className='flex-column'>
          {this.GetPositonControlElement()}
          <div className='m-4'>
            <PMDQD id='PositionMesurementAndDiagnosisQD' />
          </div>
        </div>
        <Divider layout='vertical' />
        {getIndex(defaultViewGlobal, qdIds) === 0 &&
          this.showConfigProps('Digital Noise Filter', showDigitalNoiseFilterSymbols)}
        {getIndex(defaultViewGlobal, qdIds) === 1 &&
          this.showConfigProps('Quadrature Decoder', showQuadratureDecoderSymbols)}
      </div>
    );
  }

  GetPositonControlElement() {
    return (
      <div className='flex justify-content-start'>
        <div className='flex justify-content-start column-gap-4 row-gap-6'>
          <div className='m-2'>
            <StateLabel
              labelId={positionMesurementModel}
              isSymbolLabelName={true}
              labelDisplayText={GetSymbolLabelName(mc_component_id, positionMesurementModel)}
            />{' '}
          </div>
          <div>
            <GetUIComponentWithOutLabel
              componentId={mc_component_id}
              symbolId={positionMesurementModel}
              onChange={this.MotorControlChanged}
              symbolListeners={[positionMesurementModel]}
            />
          </div>
        </div>
      </div>
    );
  }

  showZSMT_Hybrid() {
    return (
      <div className='flex'>
        <div className='flex-column'>
          {this.GetPositonControlElement()}
          <div className='m-4'>
            <ZSMTHYBRID id='PositionMesurementAndDiagnosisZSMTHybrid' />
          </div>
        </div>
        <Divider layout='vertical' />
        {getIndex(defaultViewGlobal, zsmtIds) === 0 &&
          this.showConfigProps('Primary Observer', showPrimaryObserverSymbols)}
        {getIndex(defaultViewGlobal, zsmtIds) === 1 &&
          this.showConfigProps('Secondary Observer', showSecondaryObserverSymbols)}
        {getIndex(defaultViewGlobal, zsmtIds) === 2 &&
          this.showConfigProps('Angle Tracker', showAngleTrackerSymbols)}
        {getIndex(defaultViewGlobal, zsmtIds) === 3 &&
          this.showConfigProps('Soft Switch', showSoftSwitchSymbols)}
      </div>
    );
  }

  showConfigProps(title: string, symbolsArray: string[]) {
    DialogCommonInitilizeCode(this.props.showToast, symbolsArray);
    return (
      <div>
        {}
        <AddTitleAndParameters
          Headding={title}
          onChange={this.SymbolValueChanged}
          component_id={mc_component_id}
          SymbolsArray={symbolsArray}
        />
      </div>
    );
  }

  showConfigPropsWithImage(title: string, symbolsArray: string[], image: any) {
    DialogCommonInitilizeCode(this.props.showToast, symbolsArray);
    return (
      <div>
        {}
        <AddImageAndParameters
          Image={image}
          Headding={title}
          onChange={this.SymbolValueChanged}
          component_id={mc_component_id}
          SymbolsArray={symbolsArray}
        />
      </div>
    );
  }

  showSMO() {
    return (
      <div className='flex'>
        <div className='flex-column'>
          {this.GetPositonControlElement()}
          <div className='m-4'>
            <SMO id='PositionMesurementAndDiagnosisSMO' />
          </div>
        </div>
        <Divider layout='vertical' />
        {getIndex(defaultViewGlobal, smoIds) === 0 &&
          this.showConfigProps(
            'Sliding Mode Current Observer',
            showslidingModeCurrentObserverSymbols
          )}
        {getIndex(defaultViewGlobal, smoIds) === 1 &&
          this.showConfigProps('Switching Function', showSwitchingFunctionSymbols)}
        {getIndex(defaultViewGlobal, smoIds) === 2 &&
          this.showConfigProps('Back EMF Observer', showBackEMFObserverSymbols)}
        {getIndex(defaultViewGlobal, smoIds) === 3 &&
          this.showConfigProps('Flux Angle Calculation', showFluxAngleCalculationSymbols)}
      </div>
    );
  }

  showReducedOrderLuenberger() {
    DialogCommonInitilizeCode(this.props.showToast, showReducedOrderLuenbergerObserver);
    return (
      <div className='flex'>
        <div className='flex-column'>
          {this.GetPositonControlElement()}
          <div className='m-4'></div>
        </div>
        <Divider layout='vertical' />

        {this.showConfigProps(
          'Reduced order luenberger observer',
          showReducedOrderLuenbergerObserver
        )}
      </div>
    );
  }

  render() {
    return (
      <div>
        <div className='flex'>
          {GetSelectedPositionControlIndex() === 0 && this.showEB()}
          {GetSelectedPositionControlIndex() === 1 && this.showQD()}
          {GetSelectedPositionControlIndex() === 2 && this.showReducedOrderLuenberger()}
          {GetSelectedPositionControlIndex() === 3 && this.showSMO()}
          {GetSelectedPositionControlIndex() === 4 && this.showZSMT_Hybrid()}
        </div>
      </div>
    );
  }
}
export default PositionMesurementAndDiagnosis;

export function SetPositionControlDiagnosisDefaultWindowView() {
  if (GetResetToDefaultStatus() || GetResetStatus()) {
    return;
  }
  ResetDefaultView(GetSelectedPositionControlIndex());
}

function GetSelectedPositionControlIndex() {
  let symbolValue = GetSymbolValue(mc_component_id, positionMesurementModel);
  let symbolArray = GetSymbolArray(mc_component_id, positionMesurementModel);
  return getIndex(symbolValue, symbolArray);
}

function ResetDefaultView(selectedIndex: any) {
  if (selectedIndex === 0) {
    defaultViewGlobal = ebIds[0];
  } else if (selectedIndex === 1) {
    defaultViewGlobal = qdIds[0];
  } else if (selectedIndex === 3) {
    defaultViewGlobal = smoIds[0];
  } else if (selectedIndex === 4) {
    defaultViewGlobal = zsmtIds[0];
  }
}

export function RegisterPositionControlDiagnosisSVGActions() {
  if (GetSelectedPositionControlIndex() === 0) {
    AddEvents(ebIds, 'PositionMesurementAndDiagnosisEB');
  } else if (GetSelectedPositionControlIndex() === 1) {
    AddEvents(qdIds, 'PositionMesurementAndDiagnosisQD');
  } else if (GetSelectedPositionControlIndex() === 3) {
    AddEvents(smoIds, 'PositionMesurementAndDiagnosisSMO');
  } else if (GetSelectedPositionControlIndex() === 4) {
    AddEvents(zsmtIds, 'PositionMesurementAndDiagnosisZSMTHybrid');
  }
}

function AddEvents(array: any, svgObjId: any) {
  svgObj = document.getElementById(svgObjId);
  if (svgObj == null) {
    return;
  }
  for (let i = 0; i < array.length; i++) {
    valueAndSVG.set(array[i], svgObj);
    AddingEvents(array[i]);
  }
}

function AddingEvents(value: string) {
  let tooltip = 'Configure Parameters';
  if (value === 'box_motor_model' || value === 'box_ab_dq') {
    tooltip = '';
  }
  addEventListeners(valueAndSVG.get(value), value, tooltip, true);
  let obj = valueAndSVG.get(value).getElementById('tooltip');
  svgAndToolTipObject.set(valueAndSVG.get(value), obj);
}

function sendClickAction(evt: { target: any }) {
  let target = evt.target;
  if (target.correspondingUseElement) target = target.correspondingUseElement;
  if (target.value) {
    defaultViewGlobal = target.value;
    ResetDialogSettings();
    obj?.currentViewChanged(defaultViewGlobal);
    return;
  }
}

function addEventListeners(svg: any, groupid: any, dialogHeading: string, popupType: boolean) {
  let group = svg.getElementById(groupid);
  IterateSVGelements(svg, group, groupid, dialogHeading, popupType);
}
function IterateSVGelements(
  svg: any,
  group: any,
  groupid: any,
  dialogHeading: string,
  popupType: boolean
) {
  for (let i = 0; i < group.childNodes.length; i++) {
    let childElement = group.childNodes[i];
    childElement.addEventListener('click', sendClickAction, false);
    childElement.addEventListener('mousemove', mouseMove);
    childElement.addEventListener('mouseleave', mouseLeave);
    childAndParent.set(childElement, svg);
    if (popupType) {
      childElement.value = groupid;
    }
    childElement.toolTip = dialogHeading;
    if (childElement.childNodes.length > 0) {
      IterateSVGelements(svg, childElement, groupid, dialogHeading, popupType);
    }
  }
}

function mouseMove(evt: { target: any }) {
  CallMouseMove(
    evt,
    childAndParent.get(evt.target),
    svgAndToolTipObject.get(childAndParent.get(evt.target))
  );
}

function mouseLeave(evt: { target: any }) {
  CallMouseLeave(evt, svgAndToolTipObject.get(childAndParent.get(evt.target)));
}
