import { clearSymbol, GetySymbolValue, UpdateSymbolValue } from './SymbolAccess';

export function getIndex(selectedValue: any, array: any) {
    return array.findIndex(((obj: any) => obj === selectedValue));
}

export function convertToBoolean(input: string): boolean  {
    try {
        return JSON.parse(input);
    }
    catch (e) {
        return false;
    }
}

export function clearAllSymbols(mc_component_id : any, symbolsArray: string[] ){
    return(symbolsArray.map((object: any) => (
        clearSymbol(mc_component_id, object)
    )));
}

export function StroeSymbolArrayToMap(map : Map<String, Object> , componentId : any,symbolArray : String[]){
    for (let index in symbolArray) {
        map.set(symbolArray[index], GetySymbolValue(componentId, symbolArray[index]));
    }
    return map;
}

// export function StroeSymbolToMap(map : Map<String, Object> , componentId : any, symbolID : String){
//     map.set(symbolID, GetySymbolValue(componentId, symbolID));
//     return map;
// }

export function UpdateArrayofSymbolsResetAction(map : Map<String, Object> , componentId : any, symbolArray : String[]){
    for (let index in symbolArray) {
        UpdateSymbolValue(componentId, symbolArray[index], map.get(symbolArray[index]));
    }
}
