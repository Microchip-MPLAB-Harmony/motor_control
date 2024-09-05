import 'primeicons/primeicons.css';
import 'primereact/resources/themes/saga-blue/theme.css';
import 'primereact/resources/primereact.css';
import 'primeflex/primeflex.css';

import ReactDOM from 'react-dom/client';
import './Styles/index.css';
import Launcher from './MotorControlPlant/UI/MainView/Launcher';
import React from 'react';
import { HarmonyContextProvider } from '@mplab_harmony/harmony-plugin-client-lib';

const root = ReactDOM.createRoot(document.getElementById('root') as HTMLElement);
root.render(
  <React.StrictMode>
    <HarmonyContextProvider>
      <Launcher />
    </HarmonyContextProvider>
  </React.StrictMode>
);
