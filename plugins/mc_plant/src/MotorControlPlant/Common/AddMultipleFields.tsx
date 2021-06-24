
import { GetComponent } from './UIComponent';
// import useForceUpdate from 'use-force-update';

const Parameters = (props: { componentId: any; parentUpdate: () => void; symbolsArray: string[] }) => {

    // const update = useForceUpdate();

    function updateValue() {
        // update();
        props.parentUpdate();
    }

    function GetComponents() {
        return (<div>
            {props.symbolsArray.map((object: string) => (
                <GetComponent componentId={props.componentId} symbolId={object} onChange={updateValue} />
            ))}
        </div>
        );
    }
    return (
        
        <div >
            <div >
                <div className="p-fluid" >
                    <GetComponents />
                </div>
            </div>

        </div >
    )
}
export default Parameters;

