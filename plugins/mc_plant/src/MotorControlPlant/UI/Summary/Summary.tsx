import { Divider } from "primereact/divider";
import { Panel } from 'primereact/panel';
import { GetySymbolValue, mc_component_id } from "../../Common/SymbolAccess";
import { GetLabelName } from "../../Common/UIComponent";

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
        {GetLabelAndValue("Board bus Voltage", "")}
        {GetLabelAndValue("Board Power", "")}
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
        {GetLabelAndValue("Pole paris", "")}
        {GetLabelAndValue("Rated Speed", "MCPMSMFOC_RATED_SPEED")}
        {GetLabelAndValue("Rated Current", "")}
        {GetLabelAndValue("Max Speed", "MCPMSMFOC_MAX_SPEED")}
        {GetLabelAndValue("BEMF Constant", "MCPMSMFOC_BEMF_CONSTANT")}
      </div>
    );
  }

  function AnalogInterface() {
    return (
      <div className="p-fluid">
        <div className="p-d-flex p-flex-column">
          <div className="p-field p-grid">
            {GetLabelAndValue("Phase Current A", "MCPMSMFOC_PHASEU_MODULE")},
            {GetySymbolValue(mc_component_id, "MCPMSMFOC_PHASEU_CH")}
          </div>
          <div className="p-field p-grid">
            {GetLabelAndValue("Phase Current B", "MCPMSMFOC_PHASEV_MODULE")},
            {GetySymbolValue(mc_component_id, "MCPMSMFOC_PHASEV_CH")}
          </div>
          <div className="p-field p-grid">
          {GetLabelAndValue("DC Bus current", "")}
          </div>
          
          <div className="p-field p-grid">
            {GetLabelAndValue("DC Bus Voltage", "MCPMSMFOC_DCBUSV_MODULE")},
            {GetySymbolValue(mc_component_id, "MCPMSMFOC_DCBUSV_CH")}
          </div>

          <div className="p-field p-grid">
            {GetLabelAndValue("Potentiometer", "MCPMSMFOC_POT_MODULE")},
            {GetySymbolValue(mc_component_id, "MCPMSMFOC_DCBUSV_CH")}
          </div>
        </div>
      </div>
    );
  }

  function DigitalInterface() {
    return (
      <div className="p-d-flex p-flex-column">
        {GetLabelAndValue("Start-stop button", "MCPMSMFOC_START_BUTTON")}
        {GetLabelAndValue(
          "Direction Toggle button",
          "MCPMSMFOC_DIRECTION_BUTTON"
        )}
        {GetLabelAndValue("Fault LED", "MCPMSMFOC_FAULT_LED")}
        {GetLabelAndValue("Direction LED", "MCPMSMFOC_DIRECTION_LED")}
      </div>
    );
  }

  function Startup() {
    return (
      <div className="p-d-flex p-flex-column">
        {GetLabelAndValue("Alignment Type", "MCPMSMFOC_ALIGNMENT")}
        {GetLabelAndValue("Alignment Current", "MCPMSMFOC_OL_IQ_REF")}
        {GetLabelAndValue("Start-up current", "MCPMSMFOC_OL_IQ_REF")}
        {GetLabelAndValue("Start-up time", "MCPMSMFOC_OL_RAMP_TIME")}
      </div>
    );
  }

  function PWMInterface() {
    return (
      <div className="p-d-flex p-flex-column">
        {GetLabelAndValue("Channel A", "MCPMSMFOC_PWM_PH_U")}
        {GetLabelAndValue("Channel B", "MCPMSMFOC_PWM_PH_V")}
        {GetLabelAndValue("Channel C", "MCPMSMFOC_PWM_PH_W")}
        {GetLabelAndValue("Fault pin", "MCPMSMFOC_PWM_FAULT")}
      </div>
    );
  }

  function MotorControl() {
    return (
      <div className="p-d-flex p-flex-column">
        {GetLabelAndValue("Control Type", "")}
        {GetLabelAndValue("Control Feedback type", "MCPMSMFOC_CURRENT_MEAS")}
      </div>
    );
  }

  function RotorPosition() {
    return (
      <div className="p-d-flex p-flex-column">
        {GetLabelAndValue("Algorithm", "MCPMSMFOC_POSITION_FB")}
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
              <span style={{   fontWeight: "bold" }}> Board Settings </span>
            </div>
            <div className="p-field">{BoardSettings()}</div>
          </div>
        </div>
        <div className="p-field">
          <div className="p-fluid">
            <div className="p-field">
              <br></br>
              <span style={{   fontWeight: "bold" }}> Motor Settings </span>
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
      <Panel header="Hardware" >
           <div className="p-formgroup-inline">
        <div className="p-field">
          <div className="p-fluid">
            <div className="p-field">
              <br></br>
              <span style={{  fontWeight: "bold" }}> Motor Parameters </span>
            </div>
            <div className="p-field">{MotorParameters()}</div>
          </div>
        </div>
        <div className="p-field">
          <div className="p-fluid">
            <div className="p-field">
              <br></br>
              <span style={{  fontWeight: "bold" }}> Analog Interface </span>
            </div>
            <div className="p-field">{AnalogInterface()}</div>
          </div>
        </div>
        <div className="p-field">
          <div className="p-fluid">
            <div className="p-field">
              <br></br>
              <span style={{   fontWeight: "bold" }}> Digital Interface </span>
            </div>
            <div className="p-field">{DigitalInterface()}</div>
          </div>
        </div>
        <div className="p-field">
          <div className="p-fluid">
            <div className="p-field">
              <br></br>
              <span style={{   fontWeight: "bold" }}> PWM Interface </span>
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
      <Panel header="Control" >
           <div className="p-formgroup-inline">
        <div className="p-field">
          <div className="p-fluid">
            <div className="p-field">
              <br></br>
              <span style={{  fontWeight: "bold" }}> Start-up </span>
            </div>
            <div className="p-field">{Startup()}</div>
          </div>
        </div>
        <div className="p-field">
          <div className="p-fluid">
            <div className="p-field">
              <br></br>
              <span style={{  fontWeight: "bold" }}> Motor Control </span>
            </div>
            <div className="p-field">{MotorControl()}</div>
          </div>
        </div>
        <div className="p-field">
          <div className="p-fluid">
            <div className="p-field">
              <br></br>
              <span style={{   fontWeight: "bold" }}> Rotor Position </span>
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
