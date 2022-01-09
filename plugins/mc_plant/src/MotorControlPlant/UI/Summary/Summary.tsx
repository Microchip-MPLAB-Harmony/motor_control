import { Panel } from "primereact/panel";
import { GetySymbolValue, mc_component_id } from "../../Common/SymbolAccess";

const SummaryPage = () => {
  function GetLabelAndValue(labelName: string, symbolId: string) {
    return (
      <div className="p-field p-grid">
        <div>
          <label style={{ fontSize: "16px" }} className="p-col">
            {" "}
            {"\u2022 " + labelName + " : "}
          </label>
        </div>
        <div className="p-col">
          {GetySymbolValue(mc_component_id, symbolId)}
        </div>
      </div>
    );
  }

  function BoardSettings() {
    return (
      <div className="p-fluid">
        {GetLabelAndValue("Board Selected", "MCPMSMFOC_BOARD_SEL")}
        {GetLabelAndValue("Board bus Voltage", "MCPMSMFOC_VOLTAGE_MAGNITUDE")}
        {GetLabelAndValue("Board Power", "MCPMSMFOC_BOARD_POWER")}
      </div>
    );
  }

  function MotorSettings() {
    return (
      <div className="p-d-flex p-flex-column">
        {GetLabelAndValue("Motor Selected", "MCPMSMFOC_MOTOR_SEL")}
      </div>
    );
  }

  function MotorParameters() {
    return (
      <div className="p-d-flex p-flex-column">
        {GetLabelAndValue("Connection Type", "MCPMSMFOC_MOTOR_CONNECTION")}
        {GetLabelAndValue("L-L Resistance", "MCPMSMFOC_R")}
        {GetLabelAndValue("D-axis Inductance", "MCPMSMFOC_LD")}
        {GetLabelAndValue("Q-axis inductance", "MCPMSMFOC_LD")}
        {GetLabelAndValue("Pole paris", "MCPMSMFOC_POLE_PAIRS")}
        {GetLabelAndValue("Rated Speed", "MCPMSMFOC_RATED_SPEED")}
        {GetLabelAndValue("Rated Current", "MCPMSMFOC_MAX_MOTOR_CURRENT")}
        {GetLabelAndValue("Max Speed", "MCPMSMFOC_MAX_SPEED")}
        {GetLabelAndValue("BEMF Constant", "MCPMSMFOC_BEMF_CONST")}
      </div>
    );
  }

  function AnalogInterface() {
    return (
      <div className="p-fluid">
        <div className="p-d-flex p-flex-column">
          <div className="p-field p-grid">
            {GetLabelAndValue("Phase Current A", "MCPMSMFOC_PHASE_CURRENT_IA_UNIT")},
            {GetySymbolValue(mc_component_id, "MCPMSMFOC_PHASE_CURRENT_IA_UNIT_PHASE_CURRENT_IA_FINAL")}
          </div>
          <div className="p-field p-grid">
            {GetLabelAndValue("Phase Current B", "MCPMSMFOC_PHASE_CURRENT_IB_UNIT")},
            {GetySymbolValue(mc_component_id, "MCPMSMFOC_PHASE_CURRENT_IB_UNIT_PHASE_CURRENT_IB_FINAL")}
          </div>
          {/* <div className="p-field p-grid">
            {GetLabelAndValue("DC Bus current", "MCPMSMFOC_DC_BUS_CURRENT_UNIT")},
            {GetySymbolValue(mc_component_id, "MCPMSMFOC_DC_BUS_CURRENT_UNIT_DC_BUS_CURRENT_B_FINAL")}
          </div> */}

          <div className="p-field p-grid">
            {GetLabelAndValue("DC Bus Voltage", "MCPMSMFOC_BUS_VOLTAGE_VDC_UNIT")},
            {GetySymbolValue(mc_component_id, "MCPMSMFOC_BUS_VOLTAGE_VDC_UNIT_BUS_VOLTAGE_VDC_FINAL")}
          </div>

          <div className="p-field p-grid">
            {GetLabelAndValue("Potentiometer", "MCPMSMFOC_POTENTIOMETER_VPOT_UNIT")},
            {GetySymbolValue(mc_component_id, "MCPMSMFOC_POTENTIOMETER_VPOT_UNIT_POTENTIOMETER_VPOT_FINAL")}
          </div>
        </div>
      </div>
    );
  }

  function DigitalInterface() {
    return (
      <div className="p-d-flex p-flex-column">
        {GetLabelAndValue("Start-stop button", "MCPMSMFOC_BUTTON_0_NUMBER")}
        {/* {GetLabelAndValue(
          "Direction Toggle button",
          "MCPMSMFOC_DIRECTION_BUTTON"
        )} */}
        {GetLabelAndValue("Fault LED", "MCPMSMFOC_LED_0_NUMBER")}
        {/* {GetLabelAndValue("Direction LED", "MCPMSMFOC_DIRECTION_LED")} */}
      </div>
    );
  }

  function Startup() {
    return (
      <div className="p-d-flex p-flex-column">
        <div className="p-field p-grid">
            {GetLabelAndValue("Alignment Type", "MCPMSMFOC_ALIGN_OR_DETECT_ALGORITHM")},
            {GetySymbolValue(mc_component_id, "MCPMSMFOC_ALIGN_OR_DETECT_AXIS")}
          </div>
        {GetLabelAndValue("Alignment Current", "MCPMSMFOC_STARTUP_CURRENT")}
        {GetLabelAndValue("Start-up current", "MCPMSMFOC_STARTUP_CURRENT")}
        {GetLabelAndValue("Start-up time", "MCPMSMFOC_OPEN_LOOP_RAMP_TIME")}
      </div>
    );
  }

  function PWMInterface() {
    return (
      <div className="p-d-flex p-flex-column">
        {GetLabelAndValue("Channel A", "MCPMSMFOC_PWM_INSTANCE_PWM_A_FINAL")}
        {GetLabelAndValue("Channel B", "MCPMSMFOC_PWM_INSTANCE_PWM_B_FINAL")}
        {GetLabelAndValue("Channel C", "MCPMSMFOC_PWM_INSTANCE_PWM_C_FINAL")}
        {GetLabelAndValue("Fault pin", "MCPMSMFOC_PWM_FAULT_SELECT")}
      </div>
    );
  }

  function MotorControl() {
    return (
      <div className="p-d-flex p-flex-column">
        {GetLabelAndValue("Control Type", "MCPMSMFOC_CONTROL_TYPE")}
        {/* {GetLabelAndValue("Control Feedback type", "MCPMSMFOC_CONTROL_TYPE")} */}
      </div>
    );
  }

  function RotorPosition() {
    return (
      <div className="p-d-flex p-flex-column">
        {GetLabelAndValue("Algorithm", "MCPMSMFOC_POSITION_CALC_ALGORITHM")}
      </div>
    );
  }

  function GetEnvironment() {
    return (
      <Panel header="Environment">
        <div className="p-formgroup-inline">
          <div className="p-field">
            <div className="p-fluid">
              <div className="p-field">
                <br></br>
                <span style={{ fontWeight: "bold" }}> Board Settings </span>
              </div>
              <div className="p-field">{BoardSettings()}</div>
            </div>
          </div>
          <div className="p-field">
            <div className="p-fluid">
              <div className="p-field">
                <br></br>
                <span style={{ fontWeight: "bold" }}> Motor Settings </span>
              </div>
              <div className="p-field">{MotorSettings()}</div>
            </div>
          </div>
        </div>
      </Panel>
    );
  }

  function GetHardware() {
    return (
      <Panel header="Hardware">
        <div className="p-formgroup-inline">
          <div className="p-field">
            <div className="p-fluid">
              <div className="p-field">
                <br></br>
                <span style={{ fontWeight: "bold" }}> Motor Parameters </span>
              </div>
              <div className="p-field">{MotorParameters()}</div>
            </div>
          </div>
          <div className="p-field">
            <div className="p-fluid">
              <div className="p-field">
                <br></br>
                <span style={{ fontWeight: "bold" }}> Analog Interface </span>
              </div>
              <div className="p-field">{AnalogInterface()}</div>
            </div>
          </div>
          <div className="p-field">
            <div className="p-fluid">
              <div className="p-field">
                <br></br>
                <span style={{ fontWeight: "bold" }}> Digital Interface </span>
              </div>
              <div className="p-field">{DigitalInterface()}</div>
            </div>
          </div>
          <div className="p-field">
            <div className="p-fluid">
              <div className="p-field">
                <br></br>
                <span style={{ fontWeight: "bold" }}> PWM Interface </span>
              </div>
              <div className="p-field">{PWMInterface()}</div>
            </div>
          </div>
        </div>
      </Panel>
    );
  }

  function GetControl() {
    return (
      <Panel header="Control">
        <div className="p-formgroup-inline">
          <div className="p-field">
            <div className="p-fluid">
              <div className="p-field">
                <br></br>
                <span style={{ fontWeight: "bold" }}> Start-up </span>
              </div>
              <div className="p-field">{Startup()}</div>
            </div>
          </div>
          <div className="p-field">
            <div className="p-fluid">
              <div className="p-field">
                <br></br>
                <span style={{ fontWeight: "bold" }}> Motor Control </span>
              </div>
              <div className="p-field">{MotorControl()}</div>
            </div>
          </div>
          <div className="p-field">
            <div className="p-fluid">
              <div className="p-field">
                <br></br>
                <span style={{ fontWeight: "bold" }}> Rotor Position </span>
              </div>
              <div className="p-field">{RotorPosition()}</div>
            </div>
          </div>
        </div>
      </Panel>
    );
  }

  return (
    <div>
      <div className="p-d-flex p-flex-column">
        {GetEnvironment()}
        {GetHardware()}
        {GetControl()}
      </div>
    </div>
  );
};

export default SummaryPage;
