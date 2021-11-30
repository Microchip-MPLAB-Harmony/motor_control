import MutlipleComponents from "./AddMultipleFields";
import { mc_component_id } from "./SymbolAccess";

export function LoadImage(file: any) {
  return (
    <div>
      {" "}
      <img src={file} alt="icon" />{" "}
    </div>
  );
}

export function AddImageAndParameters(props: {
  Image: any;
  Headding: any;
  parentUpdate: () => void;
  SymbolsArray: any;
}) {
  return (
    <div className="p-fluid">
      <div>
        {props.Image !== null && LoadImage(props.Image)}
        <br></br>
        <span style={{ fontWeight: "bold" }}> {props.Headding} </span> <br></br>
        <br></br>
        <MutlipleComponents
          componentId={mc_component_id}
          parentUpdate={props.parentUpdate}
          symbolsArray={props.SymbolsArray}
        />
      </div>
    </div>
  );
}

export function AddTitileOnly(props: { Headding: any }) {
  return (
    <div className="p-fluid">
      <div>
        <span style={{ fontWeight: "bold" }}> {props.Headding} </span>
      </div>
    </div>
  );
}

export function AddTitleAndParameters(props: {
  Headding: any;
  parentUpdate: () => void;
  SymbolsArray: any;
}) {
  return (
    <div className="p-fluid">
      <div>
        <span style={{ fontWeight: "bold" }}> {props.Headding} </span> <br></br>
        <br></br>
        <MutlipleComponents
          componentId={mc_component_id}
          parentUpdate={props.parentUpdate}
          symbolsArray={props.SymbolsArray}
        />
      </div>
    </div>
  );
}

export function ShowDiv(elements: any, specifiedDisplay: any) {
  elements = elements.length ? elements : [elements];
  for (var index = 0; index < elements.length; index++) {
    elements[index].style.display = specifiedDisplay || "block";
  }
}

export function HideDiv(elements: any) {
  elements = elements.length ? elements : [elements];
  for (var index = 0; index < elements.length; index++) {
    elements[index].style.display = "none";
  }
}
