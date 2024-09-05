import MultipleUIComponentsWithLabel from '../../../Tools/MultipleUIComponentsWithLabel';
import { GetHeadder } from '../../../Tools/NodeUtils';

const FlyingStartChildComponent = (props: {
  componentId: string;
  FlyingStartSymbolsArray: string[];
  DAxisControllerSymbolArray: string[];
  QAxisControllerSymbolArray: string[];
  AdvancedConfiguration: string[];
}) => {
  return (
    <div>
      <MultipleUIComponentsWithLabel
        componentId={props.componentId}
        symbolsArray={props.FlyingStartSymbolsArray}
      />
      {/* <GetHeadder headder='D-Axis Controller' />

      <MultipleUIComponentsWithLabel
        componentId={props.componentId}
        symbolsArray={props.DAxisControllerSymbolArray}
      />
      <GetHeadder headder='Q-axis Controller' />

      <MultipleUIComponentsWithLabel
        componentId={props.componentId}
        symbolsArray={props.QAxisControllerSymbolArray}
      /> */}
      <GetHeadder headder='Advanced Configuration' />

      <MultipleUIComponentsWithLabel
        componentId={props.componentId}
        symbolsArray={props.AdvancedConfiguration}
      />
    </div>
  );
};
export default FlyingStartChildComponent;
