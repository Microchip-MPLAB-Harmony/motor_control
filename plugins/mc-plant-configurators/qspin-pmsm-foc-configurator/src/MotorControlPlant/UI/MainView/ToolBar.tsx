import React from 'react';
import { Button } from 'primereact/button';
import { Toolbar } from 'primereact/toolbar';

import '../../../Styles/Headder.css';
import {
  ZoomInReact,
  ZoomOutReact
} from '@mplab_harmony/harmony-plugin-core-service/build/project-service/ProjectService';
import ReactDOM from 'react-dom';
import PopUpWithoutFooter, { PopupWithoutFooterInput } from '../CustomPopUp/PopUpWithoutFooter';
import { SummaryPageHeading } from './MainBlock';

let portNumber = (window as any).javaConnector.getPortNumber();

const Headder = () => {
  const leftContents = (
    <React.Fragment>
      <label style={{ fontSize: '18px', fontWeight: 'bolder' }}> Harmony QSpin PMSM FOC </label>
    </React.Fragment>
  );

  const rightContents = (
    <React.Fragment>
      <Button
        label='SUMMARY'
        tooltip='View Summary'
        tooltipOptions={{ position: 'bottom' }}
        className='p-button p-button-text  p-mr-2'
        style={{ fontWeight: 'bold', color: 'black' }}
        onClick={() => LoadSummary()}
      />
      <Button
        label='HELP'
        tooltip='View MC Plant help'
        tooltipOptions={{ position: 'bottom' }}
        // icon="pi pi-search"
        className='p-button p-button-text  p-mr-2'
        iconPos='right'
        style={{ fontWeight: 'bold', color: 'black' }}
        onClick={() => LoadHelp()}
      />
      <Button
        tooltip='Ctrl + Mouse Scroll Up'
        tooltipOptions={{ position: 'left' }}
        icon='pi pi-search-plus'
        className='p-button-rounded p-button-text p-button-plain p-button-lg p-mr-1'
        onClick={() => ZoomIn()}
      />
      <Button
        tooltip='Ctrl + Mouse Scroll Down'
        tooltipOptions={{ position: 'left' }}
        icon='pi pi-search-minus'
        className='p-button-rounded p-button-text p-button-lg p-button-plain'
        onClick={() => ZoomOut()}
      />
    </React.Fragment>
  );

  const LoadSummary = () => {
    callPopUp(PopUpWithoutFooter, SummaryPageHeading, '95vw');
  };

  function callPopUp(Component: any, action_id: any, width: any) {
    const createPopup = React.createElement(Component);
    PopupWithoutFooterInput(action_id, '', '95vw', '95vh');
    ReactDOM.render(createPopup, document.querySelector('#popup'));
  }

  const LoadHelp = () => {
    window.open(
      'http://localhost:' + portNumber + '/motor_control/docs/index.html',
      '_blank',
      'toolbar=0,location=0,menubar=0'
    );
  };

  function ZoomIn() {
    ZoomInReact();
  }

  function ZoomOut() {
    ZoomOutReact();
  }

  return (
    <div className='Headder'>
      <div>
        <Toolbar
          left={leftContents}
          right={rightContents}
          style={{
            background: 'white',
            height: '60px',
            maxHeight: '60px',
            border: 'white',
            top: '0',
            overflow: 'hidden'
          }}
        />
      </div>
    </div>
  );
};

export default Headder;
