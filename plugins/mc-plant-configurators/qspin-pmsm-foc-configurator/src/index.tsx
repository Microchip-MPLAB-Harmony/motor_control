import reportWebVitals from './ProjectConfig/reportWebVitals';

import 'primeicons/primeicons.css';
import 'primereact/resources/themes/saga-blue/theme.css';
import 'primereact/resources/primereact.css';
import 'primeflex/primeflex.css';

import ReactDOM from 'react-dom/client';
import './Styles/index.css';
import Launcher from './MotorControlPlant/UI/MainView/Launcher';

const root = ReactDOM.createRoot(document.getElementById('root') as HTMLElement);
root.render(<Launcher />);
reportWebVitals();
