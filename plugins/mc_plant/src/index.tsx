import React from 'react';
import ReactDOM from 'react-dom';
import MainBlock from './MotorControlPlant/UI/MainView/MainBlock';
import reportWebVitals from './ProjectConfig/reportWebVitals';
import { newInit} from './MotorControlPlant/UI/SVGScript';

import "primeicons/primeicons.css";
import "primereact/resources/themes/saga-blue/theme.css";
import "primereact/resources/primereact.css";
import "primeflex/primeflex.css";
import { HideDiv } from './MotorControlPlant/Common/NodeUtils';


ReactDOM.render(
  <React.StrictMode>
    <MainBlock />
       {/* { HideDiv(document.getElementById('summary'))} */}
  </React.StrictMode>,
  document.getElementById('root')
);
window.addEventListener("load", function() { newInit();});
// If you want to start measuring performance in your app, pass a function
// to log results (for example: reportWebVitals(console.log))
// or send to an analytics endpoint. Learn more: https://bit.ly/CRA-vitals
reportWebVitals();
