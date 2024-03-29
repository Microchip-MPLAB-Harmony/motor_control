import { TabView, TabPanel } from 'primereact/tabview';
import { Divider } from 'primereact/divider';
import './StartUpConfigurator.css';
import StartupForcedAlignDAxis from '../../../Resources/Svgs/ControlBlock/StartupConfigurator-ForcedAlign-D-Axis.svg';
import StartupForcedAlignQAxis from '../../../Resources/Svgs/ControlBlock/StartupConfigurator-ForcedAlign-Q-Axis.svg';
import FlyingStart from '../../../Resources/Svgs/ControlBlock/StartupConfigurator-FlyingStart.svg';

import useForceUpdate from 'use-force-update';
import {
  GetSymbolArray,
  GetSymbolValue
} from '@mplab_harmony/harmony-plugin-core-service/build/database-access/SymbolAccess';
import { mc_component_id } from '../MainView/MainBlock';
import { useWindowDimensions } from '@mplab_harmony/harmony-plugin-ui/build/utils/Dimension';
import { convertToBoolean } from '@mplab_harmony/harmony-plugin-ui/build/utils/CommonUtil';
import {
  AddMultipleUIComponentsWithLabel,
  GetUIComponentWithLabel,
  LoadImage,
  getIndex
} from '@mplab_harmony/harmony-plugin-ui';
import { DialogCommonInitilizeCode } from '../CustomPopUp/CustomPopUp';

const StartUpConfigurator = (props: { showToast: (arg0: any) => void }) => {
  let rotor_rotation_symbolID = 'MCPMSMFOC_ALIGN_OR_DETECT_AXIS';
  let rotor_rotation_SymbolArray = GetSymbolArray(mc_component_id, rotor_rotation_symbolID);

  let filedDetectSymbolArray = [
    'MCPMSMFOC_ENABLE_ALIGN_OR_DETECT',
    'MCPMSMFOC_ALIGN_OR_DETECT_ALGORITHM'
  ];

  let fieldDetectSymbolArray2 = ['MCPMSMFOC_STARTUP_CURRENT', 'MCPMSMFOC_STARTUP_TIME'];

  let openLoopSpeedRampSymbolArray = [
    'MCPMSMFOC_ENABLE_OPEN_LOOP_STARTUP',
    'MCPMSMFOC_OPEN_LOOP_END_SPEED',
    'MCPMSMFOC_OPEN_LOOP_RAMP_TIME',
    'MCPMSMFOC_OPEN_LOOP_STAB_TIME'
  ];

  let FlyingStartCheckBox = 'MCPMSMFOC_ENABLE_FLYING_START';
  let FlyingStartSymbolsArray = [
    'MCPMSMFOC_FLY_START_DETECTION_TIME',
    'MCPMSMFOC_FLY_START_MINIMUM_SPEED',
    'MCPMSMFOC_FLY_START_CURRENT'
  ];

  let DAxisControllerSymbolArray = [
    'MCPMSMFOC_FLY_START_D_CONTROLLER_KP',
    'MCPMSMFOC_FLY_START_D_CONTROLLER_KI',
    'MCPMSMFOC_FLY_START_D_CONTROLLER_KC'
  ];
  let QAxisControllerSymbolArray = [
    'MCPMSMFOC_FLY_START_Q_CONTROLLER_KP',
    'MCPMSMFOC_FLY_START_Q_CONTROLLER_KI',
    'MCPMSMFOC_FLY_START_Q_CONTROLLER_KC'
  ];
  let AdvancedConfiguration = [
    'MCPMSMFOC_ENABLE_REGEN_BRAKE',
    'MCPMSMFOC_FLY_START_NULL_VECTOR_TIME',
    'MCPMSMFOC_FLY_START_PEAK_BRAKE_CURRENT',
    'MCPMSMFOC_FLY_START_BRAKE_RAMP_TIME'
  ];

  let selectedRotationAxis = GetSymbolValue(mc_component_id, rotor_rotation_symbolID);
  let flyingstartCheckBoxStatus = convertToBoolean(
    GetSymbolValue(mc_component_id, FlyingStartCheckBox)
  );

  const update = useForceUpdate();

  const { height, width } = useWindowDimensions();

  function RotorPositionChanged(onChangeData: Map<String, any>) {
    selectedRotationAxis = onChangeData.get('symbolValue');
    update();
  }

  function FlyingStartCheckBoxChanged(onChangeData: Map<String, any>) {
    flyingstartCheckBoxStatus = convertToBoolean(onChangeData.get('symbolValue'));
    update();
  }

  function SymbolValueChanged(onchange: Map<String, any>) {
    // do nothing
  }

  function GetFiledAlignMentAndDetection() {
    DialogCommonInitilizeCode(
      props.showToast,
      filedDetectSymbolArray.concat(
        [rotor_rotation_symbolID],
        fieldDetectSymbolArray2,
        openLoopSpeedRampSymbolArray
      )
    );
    return (
      <div className='p-fluid'>
        <div>
          <span style={{ fontWeight: 'bold' }}> Field Alignment/Detection </span> <br></br>
          <br></br>
          <AddMultipleUIComponentsWithLabel
            componentId={mc_component_id}
            symbolsArray={filedDetectSymbolArray}
            onChange={SymbolValueChanged}
          />
          <GetUIComponentWithLabel
            componentId={mc_component_id}
            symbolId={rotor_rotation_symbolID}
            onChange={RotorPositionChanged}
            symbolListeners={[rotor_rotation_symbolID]}
          />
          <AddMultipleUIComponentsWithLabel
            componentId={mc_component_id}
            symbolsArray={fieldDetectSymbolArray2}
            onChange={SymbolValueChanged}
          />
        </div>
      </div>
    );
  }

  function GetOpenLoopSpeedRamp() {
    return (
      <div className='p-fluid'>
        <div>
          <div>
            <span style={{ fontWeight: 'bold' }}> Open Loop Speed Ramp </span> <br></br> <br></br>
          </div>
          <AddMultipleUIComponentsWithLabel
            componentId={mc_component_id}
            symbolsArray={openLoopSpeedRampSymbolArray}
            onChange={SymbolValueChanged}
          />
        </div>
      </div>
    );
  }

  function ShowFlyingStarttParameters() {
    DialogCommonInitilizeCode(
      props.showToast,
      [FlyingStartCheckBox].concat(
        FlyingStartSymbolsArray,
        DAxisControllerSymbolArray,
        QAxisControllerSymbolArray,
        AdvancedConfiguration
      )
    );
    return (
      <div className='p-fluid'>
        {GetHeadder('Flying Start')}
        <GetUIComponentWithLabel
          componentId={mc_component_id}
          symbolId={FlyingStartCheckBox}
          onChange={FlyingStartCheckBoxChanged}
          symbolListeners={[FlyingStartCheckBox]}
        />
        {flyingstartCheckBoxStatus === true && AddFlyingStartChildren()}
      </div>
    );
  }

  function AddFlyingStartChildren() {
    return (
      <div>
        <AddMultipleUIComponentsWithLabel
          componentId={mc_component_id}
          onChange={SymbolValueChanged}
          symbolsArray={FlyingStartSymbolsArray}
        />
        {GetHeadder('D-Axis Controller')}
        <AddMultipleUIComponentsWithLabel
          componentId={mc_component_id}
          onChange={SymbolValueChanged}
          symbolsArray={DAxisControllerSymbolArray}
        />
        {GetHeadder('Q-axis Controller')}
        <AddMultipleUIComponentsWithLabel
          componentId={mc_component_id}
          onChange={SymbolValueChanged}
          symbolsArray={QAxisControllerSymbolArray}
        />
        {GetHeadder('Advanced Configuration')}
        <AddMultipleUIComponentsWithLabel
          componentId={mc_component_id}
          onChange={SymbolValueChanged}
          symbolsArray={AdvancedConfiguration}
        />
      </div>
    );
  }

  function GetHeadder(headder: string) {
    return (
      <div>
        <span style={{ fontWeight: 'bold' }}> {headder} </span> <br></br>
        <br></br>
      </div>
    );
  }

  return (
    <div className='tabbed-pane'>
      <div className='card'>
        <TabView>
          <TabPanel header='Start-up'>
            <div className='card'>
              <br></br>
              <div className='flex'>
                <div className='flex-column'>
                  {getIndex(selectedRotationAxis, rotor_rotation_SymbolArray) === 0 &&
                    LoadImage(StartupForcedAlignQAxis)}
                  {getIndex(selectedRotationAxis, rotor_rotation_SymbolArray) === 1 &&
                    LoadImage(StartupForcedAlignDAxis)}
                </div>
                <Divider layout='vertical' />

                <div className='p-fluid'>
                  {GetFiledAlignMentAndDetection()}
                  {GetOpenLoopSpeedRamp()}
                </div>
              </div>
            </div>
          </TabPanel>
          <TabPanel header='Flying Start'>
            <div className='card'>
              <div className='flex'>
                <div> {LoadImage(FlyingStart)}</div>
                <Divider layout='vertical' />
                <div className='p-fluid'>{ShowFlyingStarttParameters()}</div>
              </div>
            </div>
          </TabPanel>
        </TabView>
      </div>
    </div>
  );
};

export default StartUpConfigurator;
