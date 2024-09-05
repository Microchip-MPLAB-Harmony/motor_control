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
import { useState, useEffect } from 'react';
import { ISymbol } from '@mplab_harmony/harmony-plugin-client-lib';
import {
  ConfigSymbol,
  DefaultControl,
  symbolUtilApi
} from '@mplab_harmony/harmony-plugin-client-lib';
const MultipleUIComponentsWithLabel = (props: { componentId: any; symbolsArray: string[] }) => {
  const symbolsComponent: React.JSX.Element[] = [];
  const [labelNames, setLabelNames] = useState<ConfigSymbol<any>[]>([]);
  const [symbols, setSymbols] = useState<ISymbol[]>([]);
  useEffect(() => {
    symbolUtilApi
      .getSymbols(props.componentId, props.symbolsArray)
      .then((e: ConfigSymbol<any>[]) => {
        setLabelNames(e);
      });
    symbolUtilApi.getSymbolTypes(props.componentId, props.symbolsArray).then((e: ISymbol[]) => {
      setSymbols(e);
    });
  }, [props.componentId, props.symbolsArray]);

  // eslint-disable-next-line array-callback-return
  labelNames.map((e) => {
    const labelName = e.label;
    const isComponentVisible = e.visible;
    if (labelName !== null && symbols.length !== 0 && isComponentVisible) {
      symbolsComponent.push(<label>{e.label}</label>);
      symbolsComponent.push(
        <DefaultControl
          key={e.symbolId}
          symbol={e}
        />
      );
    }
  });
  return (
    <div
      className='grid'
      style={{ width: '30rem' }}>
      {symbolsComponent.map((component, index) => (
        <div
          className='col-6 flex align-self-center flex align-items-center'
          key={index}>
          {component}
        </div>
      ))}
    </div>
  );
};
export default MultipleUIComponentsWithLabel;
