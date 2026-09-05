/*
 * File: untitled.c
 *
 * Code generated for Simulink model 'untitled'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Wed May 13 18:32:02 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitled.h"
#include "untitled_private.h"
#include "rtwtypes.h"
#include <math.h>

/* Block states (default storage) */
DW_untitled_T untitled_DW;

/* Real-time model */
static RT_MODEL_untitled_T untitled_M_;
RT_MODEL_untitled_T *const untitled_M = &untitled_M_;
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
void untitled_step(void)
{
  real_T u0;
  uint8_T tmp;

  /* MATLABSystem: '<Root>/Digital Output' incorporates:
   *  Constant: '<Root>/Constant'
   */
  u0 = rt_roundd_snf(untitled_P.Constant_Value);
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
  u0 = rt_roundd_snf(untitled_P.Constant1_Value);
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
  untitled_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);

  /* Step: '<Root>/Step' */
  if (untitled_M->Timing.t[0] < untitled_P.Step_Time) {
    u0 = untitled_P.Step_Y0;
  } else {
    u0 = untitled_P.Step_YFinal;
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
  MW_PWM_SetDutyCycle(untitled_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE, u0);

  {                                    /* Sample time: [0.0s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      ((untitled_M->Timing.clockTick0 * 1) + 0)
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
      ((untitled_M->Timing.clockTick1 * 1) + 0)
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
  untitled_M->Timing.t[0] =
    ((time_T)(++untitled_M->Timing.clockTick0)) * untitled_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.1s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.1, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    untitled_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void untitled_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&untitled_M->solverInfo,
                          &untitled_M->Timing.simTimeStep);
    rtsiSetTPtr(&untitled_M->solverInfo, &rtmGetTPtr(untitled_M));
    rtsiSetStepSizePtr(&untitled_M->solverInfo, &untitled_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&untitled_M->solverInfo, (&rtmGetErrorStatus
      (untitled_M)));
    rtsiSetRTModelPtr(&untitled_M->solverInfo, untitled_M);
  }

  rtsiSetSimTimeStep(&untitled_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&untitled_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(untitled_M, &untitled_M->Timing.tArray[0]);
  rtmSetTFinal(untitled_M, 5.0);
  untitled_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  untitled_M->Sizes.checksums[0] = (785305295U);
  untitled_M->Sizes.checksums[1] = (2178567516U);
  untitled_M->Sizes.checksums[2] = (369931842U);
  untitled_M->Sizes.checksums[3] = (3945975289U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    untitled_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(untitled_M->extModeInfo,
      &untitled_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(untitled_M->extModeInfo, untitled_M->Sizes.checksums);
    rteiSetTPtr(untitled_M->extModeInfo, rtmGetTPtr(untitled_M));
  }

  /* Start for MATLABSystem: '<Root>/Digital Output' */
  untitled_DW.obj_h.matlabCodegenIsDeleted = false;
  untitled_DW.obj_h.isInitialized = 1L;
  digitalIOSetup(7, 1);
  untitled_DW.obj_h.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output1' */
  untitled_DW.obj.matlabCodegenIsDeleted = false;
  untitled_DW.obj.isInitialized = 1L;
  digitalIOSetup(8, 1);
  untitled_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/PWM' */
  untitled_DW.obj_i.matlabCodegenIsDeleted = false;
  untitled_DW.obj_i.isInitialized = 1L;
  untitled_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(9UL, 0.0, 0.0);
  untitled_DW.obj_i.isSetupComplete = true;
}

/* Model terminate function */
void untitled_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  if (!untitled_DW.obj_h.matlabCodegenIsDeleted) {
    untitled_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output1' */
  if (!untitled_DW.obj.matlabCodegenIsDeleted) {
    untitled_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output1' */

  /* Terminate for MATLABSystem: '<Root>/PWM' */
  if (!untitled_DW.obj_i.matlabCodegenIsDeleted) {
    untitled_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((untitled_DW.obj_i.isInitialized == 1L) &&
        untitled_DW.obj_i.isSetupComplete) {
      untitled_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);
      MW_PWM_SetDutyCycle(untitled_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      untitled_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);
      MW_PWM_Close(untitled_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
