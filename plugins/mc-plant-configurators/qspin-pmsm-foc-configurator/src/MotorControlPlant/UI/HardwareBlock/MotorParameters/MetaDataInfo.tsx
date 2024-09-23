/*
 * Copyright (C) 2022 Microchip Technology Inc. and its subsidiaries.
 *
 * Subject to your compliance with these terms, you may use Microchip software
 * and any derivatives exclusively with Microchip products. It is your
 * responsibility to comply with third party license terms applicable to your
 * use of third party software (including open source software) that may
 * accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
 * PARTICULAR PURPOSE.
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
 * ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
 * THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 */

import { componentUtilApi, useComboSymbol } from '@mplab_harmony/harmony-plugin-client-lib';
import { AddTitleAndParameters } from '../../../Tools/NodeUtils';
import { DialogCommonInitilizeCode } from '../../CustomPopUp/CustomPopUp';
import { Button } from 'primereact/button';
import { useRef } from 'react';
import { Toast } from 'primereact/toast';
import { motorSelectSymbol } from './MotorParameters';
const MetaDataInfo = (props: {
  title: string;
  componentId: string;
  symbolsArray: string[];
  showToast: (arg0: any) => void;
}) => {
  const toastRef = useRef<any>();
  const motorSelection = useComboSymbol({
    componentId: props.componentId,
    symbolId: motorSelectSymbol
  });

  let saveMap = { custom_motor_set: true };

  DialogCommonInitilizeCode(props.showToast, props.componentId, props.symbolsArray);

  const handleClick = async () => {
    componentUtilApi.sendMessage(props.componentId, 'MESSAGE_FROM_QSPIN_GUI', saveMap).then((e) => {
      let type = 'none';
      if (e.type === 'warning') {
        type = 'warn';
      } else if (e.type === 'success') {
        type = 'success';
      } else if (e.type === 'info') {
        type = 'info';
      }
      if (e.type !== 'none') {
        toastRef.current.show({
          severity: type,
          summary: e.message,
          life: 4000
        });
      }
    });
  };
  return (
    <div>
      <Toast
        ref={toastRef}
        position='bottom-right'></Toast>
      <AddTitleAndParameters
        Headding={props.title}
        component_id={props.componentId}
        SymbolsArray={props.symbolsArray}
      />
      {motorSelection.value === 'Custom' && (
        <div className='grid'>
          <div className='col-6 flex align-self-center flex align-items-center'>
            <Button
              label='Save'
              //   tooltip={saveCheckBox.label}
              onClick={(e) => handleClick()}
            />
          </div>
        </div>
      )}
    </div>
  );
};
export default MetaDataInfo;
