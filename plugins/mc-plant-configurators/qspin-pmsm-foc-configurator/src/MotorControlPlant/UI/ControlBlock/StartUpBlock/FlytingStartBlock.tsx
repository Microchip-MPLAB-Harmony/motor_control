import { useBooleanSymbol } from '@mplab_harmony/harmony-plugin-client-lib';
import { useEffect } from 'react';
import { DialogCommonInitilizeCode } from '../../CustomPopUp/CustomPopUp';
import { GetHeadder } from '../../../Tools/NodeUtils';
import FlyingStartChildComponent from './FlyingStartChildComponent';
import MultipleUIComponentsWithLabel from '../../../Tools/MultipleUIComponentsWithLabel';

const FlytingStartBlock = (props: { componentId: string; showToast: (arg0: any) => void }) => {
  const flytingStartCheckBox = useBooleanSymbol({
    componentId: props.componentId,
    symbolId: 'MCPMSMFOC_ENABLE_FLYING_START'
  });
  let FlyingStartCheckBox = [
    'MCPMSMFOC_ENABLE_FLYING_START',
    'MCPMSMFOC_FLY_START_FADEOUT_TIME',
    'MCPMSMFOC_FLY_START_FADEOUT_BURST_PERIOD'
  ];
  let FlyingStartSymbolsArray = [
    'MCPMSMFOC_FLY_START_DETECTION_TIME',
    'MCPMSMFOC_FLY_START_MINIMUM_SPEED',
    'MCPMSMFOC_FLY_START_CURRENT'
  ];

  let DAxisControllerSymbolArray = [
    'MCPMSMFOC_FLY_START_D_CONTROLLER_KP',
    'MCPMSMFOC_FLY_START_D_CONTROLLER_KI',
    'MCPMSMFOC_FLY_START_D_CONTROLLER_KC'
  ];
  let QAxisControllerSymbolArray = [
    'MCPMSMFOC_FLY_START_Q_CONTROLLER_KP',
    'MCPMSMFOC_FLY_START_Q_CONTROLLER_KI',
    'MCPMSMFOC_FLY_START_Q_CONTROLLER_KC'
  ];
  let AdvancedConfiguration = [
    'MCPMSMFOC_ENABLE_REGEN_BRAKE',
    'MCPMSMFOC_FLY_START_NULL_VECTOR_TIME',
    'MCPMSMFOC_FLY_START_PEAK_BRAKE_CURRENT',
    'MCPMSMFOC_FLY_START_BRAKE_RAMP_TIME'
  ];

  useEffect(() => {}, []);
  DialogCommonInitilizeCode(
    props.showToast,
    props.componentId,
    FlyingStartCheckBox.concat(
      FlyingStartSymbolsArray,
      DAxisControllerSymbolArray,
      QAxisControllerSymbolArray,
      AdvancedConfiguration
    )
  );
  return (
    <div>
      <GetHeadder headder={'Flying Start'} />
      <div className='flex-column'>
        <MultipleUIComponentsWithLabel
          componentId={props.componentId}
          symbolsArray={FlyingStartCheckBox}
        />
        {flytingStartCheckBox.value === true && (
          <FlyingStartChildComponent
            componentId={props.componentId}
            FlyingStartSymbolsArray={FlyingStartSymbolsArray}
            DAxisControllerSymbolArray={DAxisControllerSymbolArray}
            QAxisControllerSymbolArray={QAxisControllerSymbolArray}
            AdvancedConfiguration={AdvancedConfiguration}
          />
        )}
      </div>
    </div>
  );
};
export default FlytingStartBlock;
