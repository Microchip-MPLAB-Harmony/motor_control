import React from 'react';
import ReactDOM from 'react-dom';
import './Styles/index.css';
import MyComponent from './MotorControlPlant/UI/MainView/MyComponent';
import reportWebVitals from './ProjectConfig/reportWebVitals';
import {init} from './MotorControlPlant/UI/SVGScript';

import "primeicons/primeicons.css";
import "primereact/resources/themes/saga-blue/theme.css";
import "primereact/resources/primereact.css";
import "primeflex/primeflex.css";


ReactDOM.render(
  <React.StrictMode>
    <MyComponent />
  </React.StrictMode>,
  document.getElementById('root')
);
window.addEventListener("load", function() { init();});
// If you want to start measuring performance in your app, pass a function
// to log results (for example: reportWebVitals(console.log))
// or send to an analytics endpoint. Learn more: https://bit.ly/CRA-vitals
reportWebVitals();
