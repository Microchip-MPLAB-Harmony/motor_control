import { Checkbox } from "primereact/checkbox";
import { Dropdown } from "primereact/dropdown";
import { InputNumber } from "primereact/inputnumber";


import { GetSymbolArray, GetySymbolValue, GetSymbolLabelName, GetSymbolMinValue, GetSymbolMaxValue, GetSymbolType, GetSymbolVisibleStatus } from './SymbolAccess';

interface LabelProps {
    labelName: any;
}

export enum SymbolType {
    DropDown,
    InputNumber,
    CheckBox
};

function Component(props: { componentId: any; symbolId: any; onChange: (arg0: any) => void; }) {
    let component = null;
    let value = GetySymbolValue(props.componentId, props.symbolId);
    if (value === null) {
        alert("Symbol Not available: " + props.symbolId);
        return null;
    }

    let symbolVisibleStatus = GetSymbolVisibleStatus(props.componentId, props.symbolId)=== true ? true : false;
    if(!symbolVisibleStatus){
        alert("Symbol Visibility False : " + props.symbolId);
        return null;
    }

    let symbolType = GetComponentType({ componentId: props.componentId, symbolID: props.symbolId });

    switch (symbolType) {
        case SymbolType.DropDown:
            component =
                // <div className="card">
                    <div className="p-grid p-justify-between">
                        <div className="p-col p-col-align-center"> <GetLabelName labelName={GetSymbolLabelName(props.componentId, props.symbolId)} /></div>
                        <div className="p-col p-col-align-center"> <GetDropDown symbolValue={value} symbolArray={GetSymbolArray(props.componentId, props.symbolId)}
                            onChange={props.onChange} /></div>
                    {/* </div> */}
                </div>;
            break;
        case SymbolType.InputNumber:
            component =
                // <div className="card">
                    <div className="p-grid p-justify-between">
                        <div className="p-col p-col-align-center"> <GetLabelName labelName={GetSymbolLabelName(props.componentId, props.symbolId)} /></div>
                        <div className="p-col p-col-align-center">  <GetInputNumber symbolValue={value} minValue={GetSymbolMinValue(props.componentId, props.symbolId)}
                            maxValue={GetSymbolMaxValue(props.componentId, props.symbolId)} onChange={(e) => props.onChange(e)} /></div>
                    {/* </div> */}
                </div>;
            break;
        case SymbolType.CheckBox:
            component =
                // <div className="card">
                    <div className="p-grid p-justify-between">
                        <div className="p-col p-col-align-center"> <GetLabelName labelName={GetSymbolLabelName(props.componentId, props.symbolId)} /></div>
                        <div className="p-col p-col-align-center">  <GetCheckBox symbolValue={value} onChange={(e) => props.onChange(e)} /></div>
                    {/* </div> */}
                </div>;
            break;
        default:
            alert("Invalid SymbolType.");
    }
    return component;
}

function GetComponentType(props: { componentId: any, symbolID: any }) {
    let typeofSymbol = GetSymbolType(props.componentId, props.symbolID);
    let type = null;
    switch (typeofSymbol) {
        case "Boolean":
            type = SymbolType.CheckBox;
            break;
        case "Integer":
        case "Long":
        case "Hex":
        case "Float":
            type = SymbolType.InputNumber;
            break;
        case "KeyValueSet":
        case "ComboSymbol":
        case "Combo":
            type = SymbolType.DropDown;
            break;
        default:
            alert("Invalid SymbolType " + props.symbolID);
    }
    return type;
}

export function GetComponent(props: { componentId: any; symbolId: any; onChange: (arg0: any) => void; }) {
    return (
        <div className="p-d-flex" >
            <Component componentId={props.componentId} symbolId={props.symbolId} onChange={props.onChange} />
        </div>
    );
}


export const GetLabelName: React.FC<LabelProps> = (props): JSX.Element => (
    <>
        <label style={{ fontSize: '12px' }}  > {props.labelName + " "}  </label>
    </>
);

export function GetInputNumber(props: { symbolValue: any; minValue: any; maxValue: any; onChange: (arg0: any) => void; }) {
    return (
        <InputNumber
            style={{ width: '8rem', height: '1.4rem' }}
            value={props.symbolValue}
            showButtons
            min={props.minValue}
            max={props.maxValue}
            onChange={props.onChange}
        />
    );
}

export function GetDropDown(props: { symbolValue: any; symbolArray: any; onChange: (arg0: any) => void; }) {
    return (
        <Dropdown
            // style={{height: '2rem', }}
            value={props.symbolValue}
            options={props.symbolArray}
            onChange={props.onChange}
        />
    )
}

export function GetCheckBox(props: { symbolValue: boolean; onChange: (arg0: any) => void; }) {
    return (
        <Checkbox 
            inputId="binary" 
            checked={props.symbolValue} 
            onChange={props.onChange} 
        />
    )
}
