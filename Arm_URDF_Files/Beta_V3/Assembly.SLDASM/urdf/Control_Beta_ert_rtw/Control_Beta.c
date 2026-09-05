/*
 * File: Control_Beta.c
 *
 * Code generated for Simulink model 'Control_Beta'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Wed May 13 18:34:22 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Control_Beta.h"
#include "Control_Beta_private.h"
#include "rtwtypes.h"
#include <math.h>

/* Block states (default storage) */
DW_Control_Beta_T Control_Beta_DW;

/* Real-time model */
static RT_MODEL_Control_Beta_T Control_Beta_M_;
RT_MODEL_Control_Beta_T *const Control_Beta_M = &Control_Beta_M_;
real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function */
void Control_Beta_step(void)
{
  real_T u0;
  uint8_T tmp;

  /* MATLABSystem: '<Root>/Digital Output' incorporates:
   *  Constant: '<Root>/Constant'
   */
  u0 = rt_roundd_snf(Control_Beta_P.Constant_Value);
  if (u0 < 256.0) {
    if (u0 >= 0.0) {
      tmp = (uint8_T)u0;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(7, tmp);

  /* End of MATLABSystem: '<Root>/Digital Output' */

  /* MATLABSystem: '<Root>/Digital Output1' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  u0 = rt_roundd_snf(Control_Beta_P.Constant1_Value);
  if (u0 < 256.0) {
    if (u0 >= 0.0) {
      tmp = (uint8_T)u0;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(8, tmp);

  /* End of MATLABSystem: '<Root>/Digital Output1' */

  /* MATLABSystem: '<Root>/PWM' */
  Control_Beta_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);

  /* Step: '<Root>/Step' */
  if (Control_Beta_M->Timing.t[0] < Control_Beta_P.Step_Time) {
    u0 = Control_Beta_P.Step_Y0;
  } else {
    u0 = Control_Beta_P.Step_YFinal;
  }

  /* Start for MATLABSystem: '<Root>/PWM' incorporates:
   *  Step: '<Root>/Step'
   */
  if (!(u0 <= 255.0)) {
    u0 = 255.0;
  }

  if (!(u0 >= 0.0)) {
    u0 = 0.0;
  }

  /* MATLABSystem: '<Root>/PWM' */
  MW_PWM_SetDutyCycle(Control_Beta_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE, u0);

  {                                    /* Sample time: [0.0s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      ((Control_Beta_M->Timing.clockTick0 * 1) + 0)
      ;

    /* Trigger External Mode event */
    errorCode = extmodeEvent(0,currentTime);
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode event errors
         may be added here */
    }
  }

  {                                    /* Sample time: [0.1s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      ((Control_Beta_M->Timing.clockTick1 * 1) + 0)
      ;

    /* Trigger External Mode event */
    errorCode = extmodeEvent(1,currentTime);
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode event errors
         may be added here */
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Control_Beta_M->Timing.t[0] =
    ((time_T)(++Control_Beta_M->Timing.clockTick0)) *
    Control_Beta_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.1s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.1, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    Control_Beta_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void Control_Beta_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Control_Beta_M->solverInfo,
                          &Control_Beta_M->Timing.simTimeStep);
    rtsiSetTPtr(&Control_Beta_M->solverInfo, &rtmGetTPtr(Control_Beta_M));
    rtsiSetStepSizePtr(&Control_Beta_M->solverInfo,
                       &Control_Beta_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Control_Beta_M->solverInfo, (&rtmGetErrorStatus
      (Control_Beta_M)));
    rtsiSetRTModelPtr(&Control_Beta_M->solverInfo, Control_Beta_M);
  }

  rtsiSetSimTimeStep(&Control_Beta_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&Control_Beta_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(Control_Beta_M, &Control_Beta_M->Timing.tArray[0]);
  rtmSetTFinal(Control_Beta_M, 5.0);
  Control_Beta_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  Control_Beta_M->Sizes.checksums[0] = (847061078U);
  Control_Beta_M->Sizes.checksums[1] = (341438552U);
  Control_Beta_M->Sizes.checksums[2] = (986940363U);
  Control_Beta_M->Sizes.checksums[3] = (74132270U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    Control_Beta_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Control_Beta_M->extModeInfo,
      &Control_Beta_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Control_Beta_M->extModeInfo,
                        Control_Beta_M->Sizes.checksums);
    rteiSetTPtr(Control_Beta_M->extModeInfo, rtmGetTPtr(Control_Beta_M));
  }

  /* Start for MATLABSystem: '<Root>/Digital Output' */
  Control_Beta_DW.obj_h.matlabCodegenIsDeleted = false;
  Control_Beta_DW.obj_h.isInitialized = 1L;
  digitalIOSetup(7, 1);
  Control_Beta_DW.obj_h.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output1' */
  Control_Beta_DW.obj.matlabCodegenIsDeleted = false;
  Control_Beta_DW.obj.isInitialized = 1L;
  digitalIOSetup(8, 1);
  Control_Beta_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/PWM' */
  Control_Beta_DW.obj_i.matlabCodegenIsDeleted = false;
  Control_Beta_DW.obj_i.isInitialized = 1L;
  Control_Beta_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(9UL, 0.0, 0.0);
  Control_Beta_DW.obj_i.isSetupComplete = true;
}

/* Model terminate function */
void Control_Beta_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  if (!Control_Beta_DW.obj_h.matlabCodegenIsDeleted) {
    Control_Beta_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output1' */
  if (!Control_Beta_DW.obj.matlabCodegenIsDeleted) {
    Control_Beta_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output1' */

  /* Terminate for MATLABSystem: '<Root>/PWM' */
  if (!Control_Beta_DW.obj_i.matlabCodegenIsDeleted) {
    Control_Beta_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((Control_Beta_DW.obj_i.isInitialized == 1L) &&
        Control_Beta_DW.obj_i.isSetupComplete) {
      Control_Beta_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);
      MW_PWM_SetDutyCycle(Control_Beta_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      Control_Beta_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);
      MW_PWM_Close(Control_Beta_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
