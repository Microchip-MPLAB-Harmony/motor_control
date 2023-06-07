import { GetSymbolValue } from '@mplab_harmony/harmony-plugin-core-service/build/database-access/SymbolAccess';
import { Panel } from 'primereact/panel';
import { mc_component_id } from '../MainView/MainBlock';

const SummaryPage = () => {
  function GetLabelAndValue(labelName: string, symbolId: string) {
    return (
      <div className='field grid'>
        <div>
          <label
            style={{ fontSize: '16px' }}
            className='col'>
            {' '}
            {'\u2022 ' + labelName + ' : '}
          </label>
        </div>
        <div className='col'>{GetSymbolValue(mc_component_id, symbolId)}</div>
      </div>
    );
  }

  function BoardSettings() {
    return (
      <div className='flex flex-column'>
        {GetLabelAndValue('Board Selected', 'MCPMSMFOC_BOARD_SEL')}
        {GetLabelAndValue('Board bus Voltage', 'MCPMSMFOC_VOLTAGE_MAGNITUDE')}
        {GetLabelAndValue('Board Power', 'MCPMSMFOC_BOARD_POWER')}
      </div>
    );
  }

  function MotorSettings() {
    return (
      <div className='flex flex-column'>
        {GetLabelAndValue('Motor Selected', 'MCPMSMFOC_MOTOR_SEL')}
      </div>
    );
  }

  function MotorParameters() {
    return (
      <div className='flex flex-column'>
        {GetLabelAndValue('Connection Type', 'MCPMSMFOC_MOTOR_CONNECTION')}
        {GetLabelAndValue('L-L Resistance', 'MCPMSMFOC_R')}
        {GetLabelAndValue('D-axis Inductance', 'MCPMSMFOC_LD')}
        {GetLabelAndValue('Q-axis inductance', 'MCPMSMFOC_LD')}
        {GetLabelAndValue('Pole paris', 'MCPMSMFOC_POLE_PAIRS')}
        {GetLabelAndValue('Rated Speed', 'MCPMSMFOC_RATED_SPEED')}
        {GetLabelAndValue('Rated Current', 'MCPMSMFOC_MAX_MOTOR_CURRENT')}
        {GetLabelAndValue('Max Speed', 'MCPMSMFOC_MAX_SPEED')}
        {GetLabelAndValue('BEMF Constant', 'MCPMSMFOC_BEMF_CONST')}
      </div>
    );
  }

  function AnalogInterface() {
    return (
      <div className='flex'>
        <div className='flex flex-column'>
          <div className='field grid m-2'>
            {GetLabelAndValue('Phase Current A', 'MCPMSMFOC_PHASE_CURRENT_IA_UNIT')},
            <div className='ml-1'>
              {GetSymbolValue(
                mc_component_id,
                'MCPMSMFOC_PHASE_CURRENT_IA_UNIT_PHASE_CURRENT_IA_FINAL'
              )}
            </div>
          </div>
          <div className='field grid m-2'>
            {GetLabelAndValue('Phase Current B', 'MCPMSMFOC_PHASE_CURRENT_IB_UNIT')},
            <div className='ml-1'>
              {GetSymbolValue(
                mc_component_id,
                'MCPMSMFOC_PHASE_CURRENT_IB_UNIT_PHASE_CURRENT_IB_FINAL'
              )}
            </div>
          </div>
          {/* <div className="field p-grid">
            {GetLabelAndValue("DC Bus current", "MCPMSMFOC_DC_BUS_CURRENT_UNIT")},
            {GetSymbolValue(mc_component_id, "MCPMSMFOC_DC_BUS_CURRENT_UNIT_DC_BUS_CURRENT_B_FINAL")}
          </div> */}
          <div className='field grid m-2'>
            {GetLabelAndValue('DC Bus Voltage', 'MCPMSMFOC_BUS_VOLTAGE_VDC_UNIT')},
            <div className='ml-1'>
              {GetSymbolValue(
                mc_component_id,
                'MCPMSMFOC_BUS_VOLTAGE_VDC_UNIT_BUS_VOLTAGE_VDC_FINAL'
              )}
            </div>
          </div>
          <div className='field grid m-2'>
            {' '}
            {GetLabelAndValue('Potentiometer', 'MCPMSMFOC_POTENTIOMETER_VPOT_UNIT')},
            <div className='ml-1'>
              {GetSymbolValue(
                mc_component_id,
                'MCPMSMFOC_POTENTIOMETER_VPOT_UNIT_POTENTIOMETER_VPOT_FINAL'
              )}
            </div>
          </div>
        </div>
      </div>
    );
  }

  function DigitalInterface() {
    return (
      <div className='flex flex-column'>
        {GetLabelAndValue('Start-stop button', 'MCPMSMFOC_BUTTON_0_NUMBER')}
        {/* {GetLabelAndValue(
          "Direction Toggle button",
          "MCPMSMFOC_DIRECTION_BUTTON"
        )} */}
        {GetLabelAndValue('Fault LED', 'MCPMSMFOC_LED_0_NUMBER')}
        {/* {GetLabelAndValue("Direction LED", "MCPMSMFOC_DIRECTION_LED")} */}
      </div>
    );
  }

  function Startup() {
    return (
      <div className='flex flex-column'>
        <div className='field grid m-2'>
          {GetLabelAndValue('Alignment Type', 'MCPMSMFOC_ALIGN_OR_DETECT_ALGORITHM')},
          <div className='ml-1'>
            {GetSymbolValue(mc_component_id, 'MCPMSMFOC_ALIGN_OR_DETECT_AXIS')}
          </div>
        </div>
        {GetLabelAndValue('Alignment Current', 'MCPMSMFOC_STARTUP_CURRENT')}
        {GetLabelAndValue('Start-up current', 'MCPMSMFOC_STARTUP_CURRENT')}
        {GetLabelAndValue('Start-up time', 'MCPMSMFOC_OPEN_LOOP_RAMP_TIME')}
      </div>
    );
  }

  function PWMInterface() {
    return (
      <div className='flex flex-column'>
        {GetLabelAndValue('Channel A', 'MCPMSMFOC_PWM_INSTANCE_PWM_A_FINAL')}
        {GetLabelAndValue('Channel B', 'MCPMSMFOC_PWM_INSTANCE_PWM_B_FINAL')}
        {GetLabelAndValue('Channel C', 'MCPMSMFOC_PWM_INSTANCE_PWM_C_FINAL')}
        {GetLabelAndValue('Fault pin', 'MCPMSMFOC_PWM_FAULT_SELECT')}
      </div>
    );
  }

  function MotorControl() {
    return (
      <div className='flex flex-column'>
        {GetLabelAndValue('Control Type', 'MCPMSMFOC_CONTROL_TYPE')}
        {/* {GetLabelAndValue("Control Feedback type", "MCPMSMFOC_CONTROL_TYPE")} */}
      </div>
    );
  }

  function RotorPosition() {
    return (
      <div className='flex flex-column'>
        {GetLabelAndValue('Algorithm', 'MCPMSMFOC_POSITION_CALC_ALGORITHM')}
      </div>
    );
  }

  function GetEnvironment() {
    return (
      <Panel header='Environment'>
        <div className='flex flex-row'>
          <div className='field col-3'>
            <div className='fluid'>
              <div className='field'>
                <br></br>
                <span style={{ fontWeight: 'bold' }}> Board Settings </span>
              </div>
              <div className='field'>{BoardSettings()}</div>
            </div>
          </div>
          <div className='field col-3'>
            <div className='fluid'>
              <div className='field'>
                <br></br>
                <span style={{ fontWeight: 'bold' }}> Motor Settings </span>
              </div>
              <div className='field'>{MotorSettings()}</div>
            </div>
          </div>
        </div>
      </Panel>
    );
  }

  function GetHardware() {
    return (
      <Panel header='Hardware'>
        <div className='flex flex-row'>
          <div className='field col-3'>
            <div className='fluid'>
              <div className='field'>
                <br></br>
                <span style={{ fontWeight: 'bold' }}> Motor Parameters </span>
              </div>
              <div className='field'>{MotorParameters()}</div>
            </div>
          </div>
          <div className='field col-3'>
            <div className='fluid'>
              <div className='field'>
                <br></br>
                <span style={{ fontWeight: 'bold' }}> Analog Interface </span>
              </div>
              <div className='field'>{AnalogInterface()}</div>
            </div>
          </div>
          <div className='field col-3'>
            <div className='fluid'>
              <div className='field'>
                <br></br>
                <span style={{ fontWeight: 'bold' }}> Digital Interface </span>
              </div>
              <div className='field'>{DigitalInterface()}</div>
            </div>
          </div>
          <div className='field col-3'>
            <div className='fluid'>
              <div className='field'>
                <br></br>
                <span style={{ fontWeight: 'bold' }}> PWM Interface </span>
              </div>
              <div className='field'>{PWMInterface()}</div>
            </div>
          </div>
        </div>
      </Panel>
    );
  }

  function GetControl() {
    return (
      <Panel header='Control'>
        <div className='flex flex-row'>
          <div className='field col-3'>
            <div className='fluid'>
              <div className='field'>
                <br></br>
                <span style={{ fontWeight: 'bold' }}> Start-up </span>
              </div>
              <div className='field'>{Startup()}</div>
            </div>
          </div>
          <div className='field col-3'>
            <div className='fluid'>
              <div className='field'>
                <br></br>
                <span style={{ fontWeight: 'bold' }}> Motor Control </span>
              </div>
              <div className='field'>{MotorControl()}</div>
            </div>
          </div>
          <div className='field col-3'>
            <div className='fluid'>
              <div className='field'>
                <br></br>
                <span style={{ fontWeight: 'bold' }}> Rotor Position </span>
              </div>
              <div className='field'>{RotorPosition()}</div>
            </div>
          </div>
        </div>
      </Panel>
    );
  }

  return (
    <div>
      <div className='flex flex-column'>
        {GetEnvironment()}
        {GetHardware()}
        {GetControl()}
      </div>
    </div>
  );
};

export default SummaryPage;
