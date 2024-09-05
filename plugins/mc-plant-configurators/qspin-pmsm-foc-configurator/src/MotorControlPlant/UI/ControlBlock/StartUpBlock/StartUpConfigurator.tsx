import { TabView, TabPanel } from 'primereact/tabview';
import { Divider } from 'primereact/divider';
import './StartUpConfigurator.css';
import StartupForcedAlignDAxis from '../../../../Resources/Svgs/ControlBlock/StartupConfigurator-ForcedAlign-D-Axis.svg';
import StartupInitialPosition from '../../../../Resources/Svgs/ControlBlock/StartupConfigurator-Initial_Position_Detection.svg';
import StartupForcedAlignQAxis from '../../../../Resources/Svgs/ControlBlock/StartupConfigurator-ForcedAlign-Q-Axis.svg';
import FlyingStart from '../../../../Resources/Svgs/ControlBlock/StartupConfigurator-FlyingStart.svg';

import { LoadImage } from '../../../Tools/NodeUtils';
import { useKeyValueSetSymbol } from '@mplab_harmony/harmony-plugin-client-lib';
import FieldAlignMentAndDetection from './FieldAlignMentAndDetection';
import FlytingStartBlock from './FlytingStartBlock';

const StartUpConfigurator = (props: { componentId: string; showToast: (arg0: any) => void }) => {
  const rotorRotation = useKeyValueSetSymbol({
    componentId: props.componentId,
    symbolId: 'MCPMSMFOC_ALIGN_OR_DETECT_AXIS'
  });
  return (
    <div className='tabbed-pane'>
      <div className='card'>
        <TabView>
          <TabPanel header='Start-up'>
            <div className='flex'>
              <div className='flex-column'>
                {rotorRotation.value === 0 && <LoadImage file={StartupForcedAlignQAxis} />}
                {rotorRotation.value === 1 && <LoadImage file={StartupForcedAlignDAxis} />}
                {rotorRotation.value === 2 && <LoadImage file={StartupInitialPosition} />}
              </div>
              <Divider layout='vertical' />
              <div className='p-fluid'>
                <FieldAlignMentAndDetection
                  componentId={props.componentId}
                  showToast={props.showToast}
                />
              </div>
            </div>
          </TabPanel>
          <TabPanel header='Flying Start'>
            <div className='flex'>
              <div>
                <LoadImage file={FlyingStart} />
              </div>
              <Divider layout='vertical' />
              <div className='p-fluid'>
                <FlytingStartBlock
                  componentId={props.componentId}
                  showToast={props.showToast}
                />
              </div>
            </div>
          </TabPanel>
        </TabView>
      </div>
    </div>
  );
};

export default StartUpConfigurator;
