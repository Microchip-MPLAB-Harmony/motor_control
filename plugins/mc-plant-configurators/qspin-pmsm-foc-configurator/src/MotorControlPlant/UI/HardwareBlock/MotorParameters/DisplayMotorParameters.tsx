import { ShowConfigProps } from '../../../Tools/NodeUtils';
import { electrical, mechanical, metaDataName, namePlate, sensor } from './MotorParameters';

let metaDataSymbolArray = [
  'MCPMSMFOC_METADATA_MOTOR_FILE_NAME',
  'MCPMSMFOC_METADATA_MOTOR_NAME_MANUFACTURER',
  'MCPMSMFOC_METADATA_MOTOR_MANUFACTURER',
  'MCPMSMFOC_METADATA_MOTOR_PART_NO',
  'MCPMSMFOC_CUSTOM_MOTOR_SAVE',
  'MCPMSMFOC_CUSTOM_MOTOR_WARNING'
];

let namePlateSymbols = [
  'MCPMSMFOC_MOTOR_CONNECTION',
  'MCPMSMFOC_POLE_PAIRS',
  'MCPMSMFOC_RATED_SPEED',
  'MCPMSMFOC_MAX_SPEED',
  'MCPMSMFOC_MAX_MOTOR_CURRENT',
  'MCPMSMFOC_RATED_VOLTAGE'
];

let electricalSymbols = ['MCPMSMFOC_R', 'MCPMSMFOC_LD', 'MCPMSMFOC_LQ', 'MCPMSMFOC_BEMF_CONST'];

let mechanicalSymbols = [
  'MCPMSMFOC_VISCOUS_DAMPING',
  'MCPMSMFOC_FRICTION_TORQUE',
  'MCPMSMFOC_ROTOR_INERTIA'
];
let sensorSymbols = [
  'MCPMSMFOC_MOTOR_SENSOR_SEL',
  'MCPMSMFOC_MOTOR_SENSOR_ENCODER_INDEX_PRESENT',
  'MCPMSMFOC_MOTOR_SENSOR_ENCODER_PPR'
];
// let customMotorSymbols = [
//   'MCPMSMFOC_CUSTOM_MOTOR_FILE_NAME',
//   'MCPMSMFOC_CUSTOM_MOTOR_MANUFACTURER',
//   'MCPMSMFOC_CUSTOM_MOTOR_PART_NO',
//   'MCPMSMFOC_CUSTOM_MOTOR_PARAMS',
//   'MCPMSMFOC_CUSTOM_MOTOR_SAVE',
//   'MCPMSMFOC_CUSTOM_MOTOR_WARNING'
// ];
const DisplayMotorParameters = (props: {
  headdingName: string;
  componentId: string;
  showToast: (arg0: any) => void;
}) => {
  switch (props.headdingName) {
    case metaDataName:
      return (
        <div>
          <ShowConfigProps
            title={props.headdingName}
            componentId={props.componentId}
            symbolsArray={metaDataSymbolArray}
            showToast={props.showToast}
          />
        </div>
      );
    case namePlate:
      return (
        <div>
          <ShowConfigProps
            title={props.headdingName}
            componentId={props.componentId}
            symbolsArray={namePlateSymbols}
            showToast={props.showToast}
          />
        </div>
      );
    case electrical:
      return (
        <div>
          <ShowConfigProps
            title={props.headdingName}
            componentId={props.componentId}
            symbolsArray={electricalSymbols}
            showToast={props.showToast}
          />
        </div>
      );
    case mechanical:
      return (
        <div>
          <ShowConfigProps
            title={props.headdingName}
            componentId={props.componentId}
            symbolsArray={mechanicalSymbols}
            showToast={props.showToast}
          />
        </div>
      );
    case sensor:
      return (
        <div>
          <ShowConfigProps
            title={props.headdingName}
            componentId={props.componentId}
            symbolsArray={sensorSymbols}
            showToast={props.showToast}
          />
        </div>
      );
    // case custom:
    //   return (
    //     <div>
    //       <ShowConfigProps
    //         title={props.headdingName}
    //         componentId={props.componentId}
    //         symbolsArray={customMotorSymbols}
    //         showToast={props.showToast}
    //       />
    //     </div>
    //   );
    default: {
      return <div></div>;
    }
  }
};
export default DisplayMotorParameters;
