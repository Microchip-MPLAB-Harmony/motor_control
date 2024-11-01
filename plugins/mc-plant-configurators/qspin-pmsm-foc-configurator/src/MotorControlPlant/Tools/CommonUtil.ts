import { ConfigSymbol, symbolUtilApi } from '@mplab_harmony/harmony-plugin-client-lib';

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
function getIndex(checkValue: any, array: any) {
  return array.findIndex((obj: any) => obj === checkValue);
}

function convertToBoolean(input: string): boolean {
  try {
    return JSON.parse(input);
  } catch (e) {
    return false;
  }
}

function CompareStrings(currentValue: string, checkValue: string) {
  if (currentValue === checkValue) {
    return true;
  } else {
    return false;
  }
}

const StoreSymbolArrayToMap = async (
  map: Map<String, Object>,
  componentId: any,
  symbolArray: string[]
) => {
  const symbols = (await symbolUtilApi.getSymbols(componentId, symbolArray)) as ConfigSymbol<any>[];
  for (let symbol of symbols) {
    map.set(symbol.symbolId, symbol.value);
  }
  return map;
};

function UpdateArrayofSymbolsResetAction(
  symbolValues: Map<String, Object>,
  componentId: any,
  symbols: string[]
) {
  const updateValues = symbols.map((symbolId) => ({
    symbolId,
    value: symbolValues.get(symbolId) as string | number | boolean
  }));
  symbolUtilApi.setValues(componentId, updateValues);
}

export {
  getIndex,
  StoreSymbolArrayToMap,
  UpdateArrayofSymbolsResetAction,
  convertToBoolean,
  CompareStrings
};
