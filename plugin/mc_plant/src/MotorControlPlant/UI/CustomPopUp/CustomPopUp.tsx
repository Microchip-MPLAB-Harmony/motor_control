
import { Dialog } from 'primereact/dialog';
import { Button } from 'primereact/button';
import './CustomPopUp.css';
import TabbedPane from '../ControlBlock/StartUpConfigurator';
import useForceUpdate from 'use-force-update';
import GetMotorControlDiagnosis from '../ControlBlock/MotorControlandDiagnosis';
import MotorParameters from '../HardwareBlock/MotorParameters';
import PWMParameters from '../HardwareBlock/PWMParameters';

let status = false;
let ActionId: {} | null | undefined;
export function StarUpConfigurator(Id: string) {
    status = true;
    ActionId = Id;
}

const GenericPopUp = () => {

    const update = useForceUpdate();

    const onHide = (name: string) => {
        status = false;
        update();
    }

    const renderFooter = (name: string) => {
        return (
            <div   className="p-d-flex p-jc-between">
                <div>
                    <Button type="button" className="p-button-raised p-button-rounded" label="Reset to Default" style={{ height: '1.75rem', fontSize: '14px' }} />
                </div>
                <div>
                    <Button type="button" className="p-button-raised p-button-rounded" label="Reset" style={{ height: '1.75rem', fontSize: '12px' }} onClick={() => onHide(name)} />
                    <Button type="button" className="p-button-raised p-button-rounded" label="Close" style={{ height: '1.75rem', fontSize: '12px' }} onClick={() => onHide(name)} autoFocus />
                </div>

            </div>
        );
    }

    return (
        <div className="dialog-demo">
            <div className="card">
                <Dialog visible={status}  closeOnEscape closable focusOnShow maximizable modal header={ActionId} footer={renderFooter('displayMaximizable')} onHide={() => onHide('displayMaximizable')}>
                    <div>
                        {ActionId === "Motor Parameters" && <MotorParameters />}
                        {ActionId === "Pulse With Modulator" && <PWMParameters />}
                        {ActionId === "Start Up Configurator" && <TabbedPane />}
                        {ActionId === "Motor Control Diagnosis" && <GetMotorControlDiagnosis />}
                        {ActionId === "Output Stage Diagnosis" && <GetMotorControlDiagnosis />}
                        {ActionId === "Current Measurement Diagnosis" && <GetMotorControlDiagnosis />}
                        {ActionId === "Voltage Measurement Diagnosis" && <GetMotorControlDiagnosis />}
                        {ActionId === "Position Calculation Diagnosis" && <GetMotorControlDiagnosis />}
                    </div>

                </Dialog>
            </div>
        </div>
    )
}

export default GenericPopUp;

