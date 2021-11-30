import { ReactComponent as MotorControlPlant } from "../../../Resources/Svgs/mc_plant_view.svg";
import { ReactComponent as Tooltip } from "../../../Resources/Svgs/Tooltip.svg";
import SummaryPage from "../Summary/Summary";
import Headder from "./ToolBar";
import { mc_component_id } from "../../Common/SymbolAccess";

const MainBlock = () => {
  function UpdateSymbolValue(event: { value: String; name: String }) {
    (window as any).javaConnector.updateSymbolData(
      mc_component_id,
      event.name,
      event.value
    );
  }
  return (
    <div>
      <Headder />
      <div className="p-fluid"></div>
      <MotorControlPlant
        id="motor"
        height={(window as any).javaConnector.getScreenHeight()}
        width={(window as any).javaConnector.getScreenWidth()}
      />
      <div id="summary" style={{ display: "none" }}>
        {" "}
        <SummaryPage />{" "}
      </div>
      <div id="tooltip_object" style={{ display: "none" }}>
        {" "}
        <Tooltip />{" "}
      </div>
    </div>
  );
};

export default MainBlock;
