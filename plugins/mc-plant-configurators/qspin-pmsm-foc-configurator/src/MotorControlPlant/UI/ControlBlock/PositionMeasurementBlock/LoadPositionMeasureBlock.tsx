import { useKeyValueSetSymbol } from '@mplab_harmony/harmony-plugin-client-lib';
import PositionMesurementAndDiagnosis, {
  SetPositionControlDiagnosisDefaultWindowView
} from './PositionMesurementAndDiagnosis';

export default function LoadPositionMeasureBlock(props: {
  componentId: string;
  showToast: (arg0: any) => void;
  dialogVisibleStatus: boolean;
}) {
  const positionSelection = useKeyValueSetSymbol({
    componentId: props.componentId,
    symbolId: 'MCPMSMFOC_POSITION_CALC_ALGORITHM'
  });
  SetPositionControlDiagnosisDefaultWindowView(positionSelection.value);
  return (
    <div>
      <PositionMesurementAndDiagnosis
        componentId={props.componentId}
        positionSelection={positionSelection}
        showToast={props.showToast}
        dialogVisibleStatus={props.dialogVisibleStatus}
      />
    </div>
  );
}
