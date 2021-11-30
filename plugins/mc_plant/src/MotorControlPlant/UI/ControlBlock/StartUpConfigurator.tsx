import { TabView, TabPanel } from "primereact/tabview";
import { Divider } from "primereact/divider";
import "./StartUpConfigurator.css";
import StartupForcedAlignDAxis from "../../../Resources/Svgs/ControlBlock/StartupConfigurator-ForcedAlign-D-Axis.svg";
import StartupForcedAlignQAxis from "../../../Resources/Svgs/ControlBlock/StartupConfigurator-ForcedAlign-Q-Axis.svg";
import FlyingStart from "../../../Resources/Svgs/ControlBlock/StartupConfigurator-FlyingStart.svg";

import {
  GetSymbolArray,
  GetySymbolValue,
  mc_component_id,
} from "../../../MotorControlPlant/Common/SymbolAccess";
import { GetComponent } from "../../../MotorControlPlant/Common/UIComponent";
import useForceUpdate from "use-force-update";
import { getIndex } from "../../../MotorControlPlant/Common/Utils";
import { LoadImage } from "../../Common/NodeUtils";
import useWindowDimensions from "../../Common/Dimenstion";
import AddMultipleFields from "../../../MotorControlPlant/Common/AddMultipleFields";

const StartUpConfigurator = (props: { showToast: (arg0: any) => void }) => {
  let rotor_rotation_symbolID = "MCPMSMFOC_ALIGN_OR_DETECT_AXIS";
  let rotor_rotation_SymbolArray = GetSymbolArray(
    mc_component_id,
    rotor_rotation_symbolID
  );

  let FlyingStartCheckBox = "MCPMSMFOC_ENABLE_FLYING_START";
  let FlyingStartSymbolsArray = [
    "MCPMSMFOC_FLY_START_DETECTION_TIME",
    "MCPMSMFOC_FLY_START_MINIMUM_SPEED",
    "MCPMSMFOC_FLY_START_CURRENT",
  ];

  let DAxisControllerSymbolArray = [
    "MCPMSMFOC_FLY_START_D_CONTROLLER_KP",
    "MCPMSMFOC_FLY_START_D_CONTROLLER_KI",
    "MCPMSMFOC_FLY_START_D_CONTROLLER_KC",
  ];
  let QAxisControllerSymbolArray = [
    "MCPMSMFOC_FLY_START_Q_CONTROLLER_KP",
    "MCPMSMFOC_FLY_START_Q_CONTROLLER_KI",
    "MCPMSMFOC_FLY_START_Q_CONTROLLER_KC",
  ];
  let AdvancedConfiguration = [
    "MCPMSMFOC_ENABLE_REGEN_BRAKE",
    "MCPMSMFOC_FLY_START_NULL_VECTOR_TIME",
    "MCPMSMFOC_FLY_START_PEAK_BRAKE_CURRENT",
    "MCPMSMFOC_FLY_START_BRAKE_RAMP_TIME",
  ];

  let selectedRotationAxis = GetySymbolValue(
    mc_component_id,
    rotor_rotation_symbolID
  );
  let flyingstartCheckBoxStatus = GetySymbolValue(
    mc_component_id,
    FlyingStartCheckBox
  );

  const update = useForceUpdate();

  const { height, width } = useWindowDimensions();

  function RotorPositionChanged(event: { value: any }) {
    (window as any).javaConnector.updateSymbolData(
      mc_component_id,
      rotor_rotation_symbolID,
      event.value
    );
    selectedRotationAxis = GetySymbolValue(
      mc_component_id,
      rotor_rotation_symbolID
    );
    update();
  }

  function FlyingStartCheckBoxChanged(event: { value: any }) {
    flyingstartCheckBoxStatus = GetySymbolValue(
      mc_component_id,
      FlyingStartCheckBox
    );
    update();
  }

  function GetFiledAlignMentAndDetection() {
    return (
      <div className="p-fluid">
        <div>
          <span style={{ fontWeight: "bold" }}>
            {" "}
            Field Alignment/Detection{" "}
          </span>{" "}
          <br></br>
          <br></br>
          <AddMultipleFields
            componentId={mc_component_id}
            symbolsArray={[
              "MCPMSMFOC_ENABLE_ALIGN_OR_DETECT",
              "MCPMSMFOC_ALIGN_OR_DETECT_ALGORITHM",
            ]}
            parentUpdate={update}
          />
          <GetComponent
            componentId={mc_component_id}
            symbolId={rotor_rotation_symbolID}
            onChange={RotorPositionChanged}
          />
          <AddMultipleFields
            componentId={mc_component_id}
            symbolsArray={[
              "MCPMSMFOC_STARTUP_CURRENT",
              "MCPMSMFOC_STARTUP_TIME",
            ]}
            parentUpdate={update}
          />
        </div>
      </div>
    );
  }

  function GetOpenLoopSpeedRamp() {
    return (
      <div className="p-fluid">
        <div>
          <div>
            <span style={{ fontWeight: "bold" }}> Open Loop Speed Ramp </span>{" "}
            <br></br> <br></br>
          </div>
          <AddMultipleFields
            componentId={mc_component_id}
            symbolsArray={[
              "MCPMSMFOC_ENABLE_OPEN_LOOP_STARTUP",
              "MCPMSMFOC_OPEN_LOOP_END_SPEED",
              "MCPMSMFOC_OPEN_LOOP_RAMP_TIME",
              "MCPMSMFOC_OPEN_LOOP_STAB_TIME",
            ]}
            parentUpdate={update}
          />
        </div>
      </div>
    );
  }

  function ShowFlyingStarttParameters() {
    return (
      <div className="p-fluid">
        {GetHeadder("Flying Start")}
        <GetComponent
          componentId={mc_component_id}
          symbolId={FlyingStartCheckBox}
          onChange={FlyingStartCheckBoxChanged}
        />
        {flyingstartCheckBoxStatus === "true" && AddFlyingStartChildren()}
      </div>
    );
  }

  function AddFlyingStartChildren() {
    return (
      <div>
        <AddMultipleFields
          componentId={mc_component_id}
          parentUpdate={update}
          symbolsArray={FlyingStartSymbolsArray}
        />
        {GetHeadder("D-Axis Controller")}
        <AddMultipleFields
          componentId={mc_component_id}
          parentUpdate={update}
          symbolsArray={DAxisControllerSymbolArray}
        />
        {GetHeadder("Q-axis Controller")}
        <AddMultipleFields
          componentId={mc_component_id}
          parentUpdate={update}
          symbolsArray={QAxisControllerSymbolArray}
        />
        {GetHeadder("Advanced Configuration")}
        <AddMultipleFields
          componentId={mc_component_id}
          parentUpdate={update}
          symbolsArray={AdvancedConfiguration}
        />
      </div>
    );
  }

  function GetHeadder(headder: string) {
    return (
      <div>
        <span style={{ fontWeight: "bold" }}> {headder} </span> <br></br>
        <br></br>
      </div>
    );
  }

  return (
    <div className="tabbed-pane">
      <div className="card">
        <TabView>
          <TabPanel header="Start-up">
            <div className="card">
              <br></br>
              <div className="p-d-flex">
                <div className="p-d-flex p-flex-column">
                  {getIndex(
                    selectedRotationAxis,
                    rotor_rotation_SymbolArray
                  ) === 0 && LoadImage(StartupForcedAlignQAxis)}
                  {getIndex(
                    selectedRotationAxis,
                    rotor_rotation_SymbolArray
                  ) === 1 && LoadImage(StartupForcedAlignDAxis)}
                </div>
                <Divider layout="vertical" />

                <div className="p-fluid">
                  {GetFiledAlignMentAndDetection()}
                  {GetOpenLoopSpeedRamp()}
                </div>
              </div>
            </div>
          </TabPanel>
          <TabPanel header="Flying Start">
            <div className="card">
              <div className="p-d-flex">
                {LoadImage(FlyingStart)}
                <Divider layout="vertical" />
                <div className="p-fluid">{ShowFlyingStarttParameters()}</div>
              </div>
            </div>
          </TabPanel>
        </TabView>
      </div>
    </div>
  );
};

export default StartUpConfigurator;
