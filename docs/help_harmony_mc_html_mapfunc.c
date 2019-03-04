#include "help_harmony_mc_map.h"
#include "help_harmony_mc_html_map.h"

int HTML_ID_Mapping(int id)
{
  switch(id)
  {
    case IDH_Motor_Control_Overview                            : return IDH_HTML_Motor_Control_Overview;
    case IDH_X2CScope_Plugin                                   : return IDH_HTML_X2CScope_Plugin;
    case IDH_Applications_Help                                 : return IDH_HTML_Applications_Help;
    case IDH_pmsm_foc_Applications_Help                        : return IDH_HTML_pmsm_foc_Applications_Help;
    case IDH_pmsm_foc_Applications_pmsm_foc_pll_estimator_sam_e70: return IDH_HTML_pmsm_foc_Applications_pmsm_foc_pll_estimator_sam_e70;
    case IDH_pmsm_foc_pmsm_foc_pll_estimator_sam_e70_Building_The_Application: return IDH_HTML_pmsm_foc_pmsm_foc_pll_estimator_sam_e70_Building_The_Application;
    case IDH_pmsm_foc_pmsm_foc_pll_estimator_sam_e70_MPLAB_Harmony_Configurations: return IDH_HTML_pmsm_foc_pmsm_foc_pll_estimator_sam_e70_MPLAB_Harmony_Configurations;
    case IDH_pmsm_foc_pmsm_foc_pll_estimator_sam_e70_Control_Algorithm: return IDH_HTML_pmsm_foc_pmsm_foc_pll_estimator_sam_e70_Control_Algorithm;
    case IDH_pmsm_foc_pmsm_foc_pll_estimator_sam_e70_Hardware_Setup: return IDH_HTML_pmsm_foc_pmsm_foc_pll_estimator_sam_e70_Hardware_Setup;
    case IDH_pmsm_foc_pmsm_foc_pll_estimator_sam_e70_Running_The_Application: return IDH_HTML_pmsm_foc_pmsm_foc_pll_estimator_sam_e70_Running_The_Application;
    case IDH_pmsm_foc_encoder_Applications_Help                : return IDH_HTML_pmsm_foc_encoder_Applications_Help;
    case IDH_pmsm_foc_encoder_Applications_pmsm_foc_encoder_sam_e70: return IDH_HTML_pmsm_foc_encoder_Applications_pmsm_foc_encoder_sam_e70;
    case IDH_pmsm_foc_encoder_pmsm_foc_encoder_sam_e70_Building_The_Application: return IDH_HTML_pmsm_foc_encoder_pmsm_foc_encoder_sam_e70_Building_The_Application;
    case IDH_pmsm_foc_encoder_pmsm_foc_encoder_sam_e70_MPLAB_Harmony_Configurations: return IDH_HTML_pmsm_foc_encoder_pmsm_foc_encoder_sam_e70_MPLAB_Harmony_Configurations;
    case IDH_pmsm_foc_encoder_pmsm_foc_encoder_sam_e70_Control_Algorithm: return IDH_HTML_pmsm_foc_encoder_pmsm_foc_encoder_sam_e70_Control_Algorithm;
    case IDH_pmsm_foc_encoder_pmsm_foc_encoder_sam_e70_Hardware_Setup: return IDH_HTML_pmsm_foc_encoder_pmsm_foc_encoder_sam_e70_Hardware_Setup;
    case IDH_pmsm_foc_encoder_pmsm_foc_encoder_sam_e70_Running_The_Application: return IDH_HTML_pmsm_foc_encoder_pmsm_foc_encoder_sam_e70_Running_The_Application;
    case IDH_pmsm_foc_rolo_Applications_Help                   : return IDH_HTML_pmsm_foc_rolo_Applications_Help;
    case IDH_pmsm_foc_rolo_Applications_pmsm_foc_rolo_sam_c21  : return IDH_HTML_pmsm_foc_rolo_Applications_pmsm_foc_rolo_sam_c21;
    case IDH_pmsm_foc_rolo_pmsm_foc_rolo_sam_c21_Building_The_Application: return IDH_HTML_pmsm_foc_rolo_pmsm_foc_rolo_sam_c21_Building_The_Application;
    case IDH_pmsm_foc_rolo_pmsm_foc_rolo_sam_c21_MPLAB_Harmony_Configurations: return IDH_HTML_pmsm_foc_rolo_pmsm_foc_rolo_sam_c21_MPLAB_Harmony_Configurations;
    case IDH_pmsm_foc_rolo_pmsm_foc_rolo_sam_c21_Control_Algorithm: return IDH_HTML_pmsm_foc_rolo_pmsm_foc_rolo_sam_c21_Control_Algorithm;
    case IDH_pmsm_foc_rolo_pmsm_foc_rolo_sam_c21_Hardware_Setup: return IDH_HTML_pmsm_foc_rolo_pmsm_foc_rolo_sam_c21_Hardware_Setup;
    case IDH_pmsm_foc_rolo_pmsm_foc_rolo_sam_c21_Running_The_Application: return IDH_HTML_pmsm_foc_rolo_pmsm_foc_rolo_sam_c21_Running_The_Application;
    case IDH_pmsm_foc_rolo_wm_Applications_Help                : return IDH_HTML_pmsm_foc_rolo_wm_Applications_Help;
    case IDH_pmsm_foc_rolo_wm_Applications_pmsm_foc_rolo_wm_sam_c21: return IDH_HTML_pmsm_foc_rolo_wm_Applications_pmsm_foc_rolo_wm_sam_c21;
    case IDH_pmsm_foc_rolo_wm_pmsm_foc_rolo_wm_sam_c21_Building_The_Application: return IDH_HTML_pmsm_foc_rolo_wm_pmsm_foc_rolo_wm_sam_c21_Building_The_Application;
    case IDH_pmsm_foc_rolo_wm_pmsm_foc_rolo_wm_sam_c21_MPLAB_Harmony_Configurations: return IDH_HTML_pmsm_foc_rolo_wm_pmsm_foc_rolo_wm_sam_c21_MPLAB_Harmony_Configurations;
    case IDH_pmsm_foc_rolo_wm_pmsm_foc_rolo_wm_sam_c21_Control_Algorithm: return IDH_HTML_pmsm_foc_rolo_wm_pmsm_foc_rolo_wm_sam_c21_Control_Algorithm;
    case IDH_pmsm_foc_rolo_wm_pmsm_foc_rolo_wm_sam_c21_Hardware_Setup: return IDH_HTML_pmsm_foc_rolo_wm_pmsm_foc_rolo_wm_sam_c21_Hardware_Setup;
    case IDH_pmsm_foc_rolo_wm_pmsm_foc_rolo_wm_sam_c21_Running_The_Application: return IDH_HTML_pmsm_foc_rolo_wm_pmsm_foc_rolo_wm_sam_c21_Running_The_Application;
    default: return -1;
  }
}
