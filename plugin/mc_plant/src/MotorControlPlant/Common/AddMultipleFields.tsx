
import { mc_component_id } from './SymbolAccess';
import { GetComponent } from './UIComponent';
import useForceUpdate from 'use-force-update';

const Parameters = (props: { componentId: any; symbolsArray: string[] }) => {

    const update = useForceUpdate();

    function UpdateSymbolValue(event: { value: any }) {
        (window as any).javaConnector.updateSymbolData(mc_component_id, "", event.value);
        update();
    }

    function GetComponents() {
        return (<div>
            {props.symbolsArray.map((object: string) => (
                <GetComponent componentId={props.componentId} symbolId={object} onChange={UpdateSymbolValue} />
            ))}
        </div>
        );
    }
    return (
        <div >

            <div className="card">
                <div className="p-d-flex" >
                    <GetComponents />
                </div>
            </div>

        </div >
    )
}
export default Parameters;

