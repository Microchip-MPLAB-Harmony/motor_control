import React from 'react';
import ReactDOM from 'react-dom';
import MainBlock from './MotorControlPlant/UI/MainView/MainBlock';
import reportWebVitals from './ProjectConfig/reportWebVitals';
import { newInit} from './MotorControlPlant/UI/SVGScript';

import "primeicons/primeicons.css";
import "primereact/resources/themes/saga-blue/theme.css";
import "primereact/resources/primereact.css";
import "primeflex/primeflex.css";

import "./Styles/index.css";


ReactDOM.render(
  <React.StrictMode>
    <MainBlock />
  </React.StrictMode>,
  document.getElementById('root')
);
window.addEventListener("load", function() { newInit();});
reportWebVitals();
