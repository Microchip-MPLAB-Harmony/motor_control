import { Checkbox } from "primereact/checkbox";
import { Dropdown } from "primereact/dropdown";
import { InputNumber } from "primereact/inputnumber";
import { useState } from "react";
import useForceUpdate from "use-force-update";


import { GetSymbolArray, GetySymbolValue, GetSymbolLabelName, GetSymbolMinValue, GetSymbolMaxValue, GetSymbolType, GetSymbolVisibleStatus, UpdateSymbolValue } from './SymbolAccess';
import { convertToBoolean } from "./Utils";

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
        return null;
    }

    let symbolType = GetComponentType({ componentId: props.componentId, symbolID: props.symbolId });

    switch (symbolType) {
        case SymbolType.DropDown:
            component =
                // <div className="p-fluid">
                    <div className="p-field p-grid">
                         <GetLabelName labelName={GetSymbolLabelName(props.componentId, props.symbolId)} />
                        <div className="p-col"> <GetDropDown componentId={props.componentId} symbolId={props.symbolId} symbolValue={value} symbolArray={GetSymbolArray(props.componentId, props.symbolId)}
                            onChange={(target) => props.onChange(target.target)} /></div>
                    </div>
                // </div>;
            break;
        case SymbolType.InputNumber:
            component =
                // <div className="p-fluid">
                    <div className="p-field p-grid">
                        <GetLabelName labelName={GetSymbolLabelName(props.componentId, props.symbolId)} />
                        <div className="p-col">  <GetInputNumber componentId={props.componentId} symbolId={props.symbolId} symbolValue={value} minValue={GetSymbolMinValue(props.componentId, props.symbolId)}
                            maxValue={GetSymbolMaxValue(props.componentId, props.symbolId)} onChange={(target) => props.onChange(target.target)} /></div>
                    </div>
                // </div>;
            break;
        case SymbolType.CheckBox:
            component =
                // <div className="card">
                    <div className="p-field p-grid">
                        <div> <GetLabelName labelName={GetSymbolLabelName(props.componentId, props.symbolId)} /></div>
                        <div className="p-col">  <GetCheckBox componentId={props.componentId} symbolId={props.symbolId} symbolValue={value} onChange={(target) => props.onChange(target.target)} /></div>
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
        <div>
            <Component componentId={props.componentId} symbolId={props.symbolId} onChange={props.onChange} />
        </div>
    );
}


export const GetLabelName: React.FC<LabelProps> = (props): JSX.Element => (
    <>
        <label style={{ fontSize: '12px' }}  className="p-col"> {props.labelName + " "}  </label>
    </>
);

export function GetInputNumber(props: {componentId: any; symbolId: any;  symbolValue: any; minValue: any; maxValue: any; onChange: (arg0: any) => void; }) {
    // const [value, setValue] = useState(props.symbolValue);
    // const update = useForceUpdate();
    function updateValue(value : any){
        // setValue(event.value);
        UpdateSymbolValue(props.componentId, props.symbolId, value);
        // props.onChange(value);
    }
    return (
        <InputNumber
            id={props.symbolId}
            style={{ width: '8rem', height: '1.4rem' }}
            value={props.symbolValue}
            showButtons
            min={props.minValue}
            max={props.maxValue}
            onChange={(target) => updateValue(target.value)}
        />
    );
}

export function GetDropDown(props: {componentId: any; symbolId: any; symbolValue: any; symbolArray: any; onChange: (arg0: any) => void; }) {
    function updateValue(event : {value : any}){
        UpdateSymbolValue(props.componentId, props.symbolId, event.value);
        props.onChange(event);
    }
    return (
        <Dropdown
            // style={{height: '2rem', }}
            id={props.symbolId}
            value={props.symbolValue}
            options={props.symbolArray}
            onChange={(e) => updateValue(e)}
        />
    )
}

export function GetCheckBox(props: {componentId: any; symbolId: any; symbolValue: string; onChange: (arg0: any) => void; }) {
    function updateValue(checked : boolean){
        UpdateSymbolValue(props.componentId, props.symbolId, checked);
        props.onChange(checked);
    }
    return (
        <Checkbox 
            id={props.symbolId}
            inputId="binary" 
            checked={convertToBoolean(props.symbolValue)} 
            onChange={e => updateValue(e.checked)} 
        />
    )
}

