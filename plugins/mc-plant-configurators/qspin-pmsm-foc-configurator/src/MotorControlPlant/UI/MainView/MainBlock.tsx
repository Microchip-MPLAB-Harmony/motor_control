import { ReactComponent as MotorControlPlant } from '../../../Resources/Svgs/mc_plant_view.svg';
import { ReactComponent as Tooltip } from '../../../Resources/Svgs/Tooltip.svg';
import Headder from './ToolBar';
import { newInit, resetColors } from '../SVGScript';
import { SetComponentId } from '@mplab_harmony/harmony-plugin-core-service';
import { useEffect } from 'react';
import { globalSymbolSStateData } from '@mplab_harmony/harmony-plugin-ui/build/components/Components';
import {
  ChangeComponentState,
  ChangeStateLabelVisibleStatus
} from '@mplab_harmony/harmony-plugin-ui/build/utils/ComponentStateChangeUtils';
import { convertToBoolean } from '@mplab_harmony/harmony-plugin-ui/build/utils/CommonUtil';

export let mc_component_id = 'pmsm_foc';
export let core_id = 'core';
export let SummaryPageHeading = 'QSpin PMSM FOC Summary';
const MainBlock = () => {
  useEffect(() => {
    newInit();
    SetComponentId(mc_component_id);
    SetComponentId(core_id);
  }, []);

  function ShowAll() {
    resetColors();
  }

  return (
    <div>
      <Headder />
      <div className='card'>
        <MotorControlPlant
          id='motor'
          height={(window as any).javaConnector.getScreenHeight()}
          width={(window as any).javaConnector.getScreenWidth()}
          onContextMenu={(e) => ShowAll()}
        />
      </div>

      <div
        id='tooltip_object'
        style={{ display: 'none' }}>
        {' '}
        <Tooltip />
      </div>
    </div>
  );
};

export default MainBlock;

(window as any).SymbolValueChanged = (value: any) => {
  if (value !== null && value !== undefined) {
    let symbolData = value.split('M*C');
    let symbolId = symbolData[0];
    let symbolValue = symbolData[1];
    let editable = convertToBoolean(symbolData[2]);
    let visible = convertToBoolean(symbolData[3]);
    if (globalSymbolSStateData.get(symbolId) != null) {
      ChangeComponentState(symbolId, symbolValue, editable, visible);
    }
    ChangeStateLabelVisibleStatus(symbolId, visible);
  }
};
