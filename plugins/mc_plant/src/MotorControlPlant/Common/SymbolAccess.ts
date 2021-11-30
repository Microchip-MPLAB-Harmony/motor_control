export let mc_component_id = "pmsm_foc";
export let core_id = "core";

export function GetySymbolValue(componentId: any, value: any) {
  let symValue = (window as any).javaConnector.getSymbolData(
    componentId,
    value
  );
  return symValue;
}

export function GetSymbolArray(componentId: any, value: any) {
  let symbolArray = (window as any).javaConnector.getSymbolValues(
    componentId,
    value
  );
  if (symbolArray === null) {
    let temp: never[] = [];
    return temp;
  }
  let array = symbolArray.split("M*C");
  return array;
}

export function GetSymbolLabelName(componentId: any, value: any) {
  let labelName = (window as any).javaConnector.getSymbolLabelName(
    componentId,
    value
  );
  return labelName;
}

export function GetSymbolMinValue(componentId: any, value: any) {
  let minValue = (window as any).javaConnector.getSymbolMinValue(
    componentId,
    value
  );
  return minValue;
}

export function GetSymbolMaxValue(componentId: any, value: any) {
  let maxValue = (window as any).javaConnector.getSymbolMaxValue(
    componentId,
    value
  );
  return maxValue;
}

export function GetSymbolType(componentId: any, value: any) {
  let symbolType = (window as any).javaConnector.getSymbolType(
    componentId,
    value
  );
  return symbolType;
}

export function GetSymbolVisibleStatus(componentId: any, value: any) {
  let symbolVisibleStatus = (
    window as any
  ).javaConnector.getSymbolVisibleStatus(componentId, value);
  return symbolVisibleStatus;
}

export function UpdateSymbolValue(
  componentId: any,
  symbolId: any,
  symbolValue: any
): void {
  (window as any).javaConnector.updateSymbolData(
    componentId,
    symbolId,
    symbolValue
  );
}

export function clearSymbol(componentId: any, symbolId: any): void {
  (window as any).javaConnector.clearSymbol(componentId, symbolId);
}
