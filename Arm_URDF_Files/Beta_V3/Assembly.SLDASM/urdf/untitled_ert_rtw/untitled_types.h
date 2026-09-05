/*
 * File: untitled_types.h
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

#ifndef RTW_HEADER_untitled_types_h_
#define RTW_HEADER_untitled_types_h_
#include "rtwtypes.h"
#include "MW_SVD.h"
#ifndef struct_tag_04b6x6tDldj9IrIH2gmbjG
#define struct_tag_04b6x6tDldj9IrIH2gmbjG

struct tag_04b6x6tDldj9IrIH2gmbjG
{
  int16_T __dummy;
};

#endif                                 /* struct_tag_04b6x6tDldj9IrIH2gmbjG */

#ifndef typedef_b_arduinodriver_ArduinoDigita_T
#define typedef_b_arduinodriver_ArduinoDigita_T

typedef struct tag_04b6x6tDldj9IrIH2gmbjG b_arduinodriver_ArduinoDigita_T;

#endif                             /* typedef_b_arduinodriver_ArduinoDigita_T */

#ifndef struct_tag_AYWgtFscQm3mLUJYb3A20C
#define struct_tag_AYWgtFscQm3mLUJYb3A20C

struct tag_AYWgtFscQm3mLUJYb3A20C
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_arduinodriver_ArduinoDigita_T DigitalIODriverObj;
};

#endif                                 /* struct_tag_AYWgtFscQm3mLUJYb3A20C */

#ifndef typedef_codertarget_arduinobase_block_T
#define typedef_codertarget_arduinobase_block_T

typedef struct tag_AYWgtFscQm3mLUJYb3A20C codertarget_arduinobase_block_T;

#endif                             /* typedef_codertarget_arduinobase_block_T */

/* Custom Type definition for MATLABSystem: '<Root>/PWM' */
#include "MW_SVD.h"
#ifndef struct_tag_g1WX34VPn8QzVKQriB4HN
#define struct_tag_g1WX34VPn8QzVKQriB4HN

struct tag_g1WX34VPn8QzVKQriB4HN
{
  MW_Handle_Type MW_PWM_HANDLE;
};

#endif                                 /* struct_tag_g1WX34VPn8QzVKQriB4HN */

#ifndef typedef_h_matlabshared_ioclient_perip_T
#define typedef_h_matlabshared_ioclient_perip_T

typedef struct tag_g1WX34VPn8QzVKQriB4HN h_matlabshared_ioclient_perip_T;

#endif                             /* typedef_h_matlabshared_ioclient_perip_T */

#ifndef struct_tag_4eDVzK5FiryyCjvjjvrZGB
#define struct_tag_4eDVzK5FiryyCjvjjvrZGB

struct tag_4eDVzK5FiryyCjvjjvrZGB
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  h_matlabshared_ioclient_perip_T PWMDriverObj;
};

#endif                                 /* struct_tag_4eDVzK5FiryyCjvjjvrZGB */

#ifndef typedef_codertarget_arduinobase_inter_T
#define typedef_codertarget_arduinobase_inter_T

typedef struct tag_4eDVzK5FiryyCjvjjvrZGB codertarget_arduinobase_inter_T;

#endif                             /* typedef_codertarget_arduinobase_inter_T */

/* Parameters (default storage) */
typedef struct P_untitled_T_ P_untitled_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_untitled_T RT_MODEL_untitled_T;

#endif                                 /* RTW_HEADER_untitled_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
