import React from "react";
import { Button } from "primereact/button";
import { Toolbar } from "primereact/toolbar";
import icon from '../../../Resources/Images/MICH4C.png';

import '../../../Styles/Headder.css';
import PrimeReact from "primereact/api";
import { LoadImage, HideDiv, ShowDiv } from '../../Common/NodeUtils';


let portNumber = (window as any).javaConnector.getPortNumber();

const Headder = () => {
    PrimeReact.ripple = true;

    const leftContents = (
        <React.Fragment>
            {LoadImage(icon)}
            <label style={{ fontSize: '18px', fontWeight: 'bolder' }} > MOTOR CONTROL PLANT  </label>
        </React.Fragment>
    );

    const rightContents = (
        <React.Fragment>
            {/* <i className="pi pi-home" style={{ 'fontSize': '1.5em'}}/> */}
            <Button label="HOME" tooltip="View MC Plant Home Screen" tooltipOptions={{ position: 'bottom' }} icon="pi pi-home" iconPos="left" className="p-button p-button-text p-mr-2" style={{ fontWeight: 'bold', color: 'black' }} onClick={() => LoadHome()} />
            <Button label="SUMMARY" tooltip="View Summary" tooltipOptions={{ position: 'bottom' }} className="p-button p-button-text  p-mr-2" style={{ fontWeight: 'bold', color: 'black' }} onClick={() => LoadSummary()} />
            <Button label="HELP" tooltip="View MC Plant help" tooltipOptions={{ position: 'bottom' }} icon="pi pi-search" className="p-button p-button-text  p-mr-2" iconPos="right" style={{ fontWeight: 'bold', color: 'black' }} onClick={() => LoadHelp()} />
        </React.Fragment>
    );

    const HideAll = () => {
        HideDiv(document.getElementById('motor'));
        HideDiv(document.getElementById('summary'));
    }

    const LoadHome = () => {
        HideAll();
        ShowDiv(document.getElementById('motor'), null);
    }

    const LoadSummary = () => {
        HideAll();
        ShowDiv(document.getElementById('summary'), null);
    }

    const LoadHelp = () => {
        window.open('http://localhost:'+portNumber+'/motor_control/docs/index.html', '_blank', 'toolbar=0,location=0,menubar=0');
    }

    function openInNewTab(href: any) {
        Object.assign(document.createElement('a'), {
            target: '_blank',
            href: href,
        }).click();
    }

    return (
        <div className="Headder">
            <div>
                <Toolbar left={leftContents} right={rightContents} style={{ background: 'white', height: '60px', border: 'white' }} />
                {/* <Divider layout="horizontal" /> */}
            </div>
        </div>
    );
}

export default Headder;