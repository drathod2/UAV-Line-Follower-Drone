/* Include files */

#include "flightControlSystem_sfun.h"
#include "c1_flightControlSystem.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(S);
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

/* Forward Declarations */

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static emlrtRSInfo c1_emlrtRSI = { 51, /* lineNo */
  "rgb2hsv",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\images\\rgb2hsv.m"/* pathName */
};

static emlrtRSInfo c1_b_emlrtRSI = { 14,/* lineNo */
  "Image Processing System/MATLAB Function",/* fcnName */
  "#flightControlSystem:2886"          /* pathName */
};

/* Function Declarations */
static void initialize_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void initialize_params_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void mdl_start_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void mdl_terminate_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void mdl_setup_runtime_resources_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void mdl_cleanup_runtime_resources_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void enable_c1_flightControlSystem(SFc1_flightControlSystemInstanceStruct
  *chartInstance);
static void disable_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void sf_gateway_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void ext_mode_exec_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void c1_update_jit_animation_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void c1_do_animation_call_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void set_sim_state_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const mxArray *c1_st);
static void initSimStructsc1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void initSubchartIOPointersc1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void c1_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_b_BW, const char_T *c1_identifier, boolean_T
  c1_y[19200]);
static void c1_b_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  boolean_T c1_y[19200]);
static uint8_T c1_c_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_flightControlSystem, const
  char_T *c1_identifier);
static uint8_T c1_d_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_slStringInitializeDynamicBuffers
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void c1_chart_data_browse_helper(SFc1_flightControlSystemInstanceStruct
  *chartInstance, int32_T c1_ssIdNumber, const mxArray **c1_mxData, uint8_T
  *c1_isValueTooBig);
static void init_dsm_address_info(SFc1_flightControlSystemInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc1_flightControlSystemInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c1_is_active_c1_flightControlSystem = 0U;
}

static void initialize_params_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_start_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
}

static void mdl_terminate_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_setup_runtime_resources_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  static const uint32_T c1_decisionTxtEndIdx = 0U;
  static const uint32_T c1_decisionTxtStartIdx = 0U;
  setDebuggerFlag(chartInstance->S, true);
  setDataBrowseFcn(chartInstance->S, (void *)&c1_chart_data_browse_helper);
  chartInstance->c1_RuntimeVar = sfListenerCacheSimStruct(chartInstance->S);
  sfListenerInitializeRuntimeVars(chartInstance->c1_RuntimeVar,
    &chartInstance->c1_IsDebuggerActive,
    &chartInstance->c1_IsSequenceViewerPresent, 0, 0,
    &chartInstance->c1_mlFcnLineNumber, &chartInstance->c1_IsHeatMapPresent, 0);
  covrtCreateStateflowInstanceData(chartInstance->c1_covrtInstance, 1U, 0U, 1U,
    26U);
  covrtChartInitFcn(chartInstance->c1_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c1_covrtInstance, 0U, 0U, false, false, false,
                    0U, &c1_decisionTxtStartIdx, &c1_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c1_covrtInstance, 0U, 0, NULL, NULL, 0U, NULL);
  covrtEmlInitFcn(chartInstance->c1_covrtInstance, "", 4U, 0U, 1U, 0U, 0U, 0U,
                  0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 0U,
                     "eML_blk_kernel", 0, -1, 1240);
}

static void mdl_cleanup_runtime_resources_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  sfListenerLightTerminate(chartInstance->c1_RuntimeVar);
  covrtDeleteStateflowInstanceData(chartInstance->c1_covrtInstance);
}

static void enable_c1_flightControlSystem(SFc1_flightControlSystemInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void sf_gateway_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  int32_T c1_b_j;
  int32_T c1_c_j;
  int32_T c1_d_j;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i10;
  int32_T c1_i11;
  int32_T c1_i12;
  int32_T c1_i13;
  int32_T c1_i14;
  int32_T c1_i15;
  int32_T c1_i16;
  int32_T c1_i17;
  int32_T c1_i18;
  int32_T c1_i19;
  int32_T c1_i2;
  int32_T c1_i20;
  int32_T c1_i21;
  int32_T c1_i22;
  int32_T c1_i23;
  int32_T c1_i24;
  int32_T c1_i25;
  int32_T c1_i26;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_i8;
  int32_T c1_i9;
  int32_T c1_iy;
  int32_T c1_j;
  uint8_T c1_RGB[57600];
  boolean_T c1_bv[19200];
  chartInstance->c1_JITTransitionAnimation[0] = 0U;
  _sfTime_ = sf_get_time(chartInstance->S);
  for (c1_i = 0; c1_i < 19200; c1_i++) {
    covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 2U, (real_T)
                      (*chartInstance->c1_B)[c1_i]);
  }

  for (c1_i1 = 0; c1_i1 < 19200; c1_i1++) {
    covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 1U, (real_T)
                      (*chartInstance->c1_G)[c1_i1]);
  }

  for (c1_i2 = 0; c1_i2 < 19200; c1_i2++) {
    covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 0U, (real_T)
                      (*chartInstance->c1_R)[c1_i2]);
  }

  chartInstance->c1_sfEvent = CALL_EVENT;
  covrtEmlFcnEval(chartInstance->c1_covrtInstance, 4U, 0, 0);
  c1_iy = -1;
  for (c1_j = 0; c1_j < 19200; c1_j++) {
    c1_c_j = c1_j;
    c1_iy++;
    c1_RGB[c1_iy] = (*chartInstance->c1_R)[c1_c_j];
  }

  for (c1_b_j = 0; c1_b_j < 19200; c1_b_j++) {
    c1_c_j = c1_b_j;
    c1_iy++;
    c1_RGB[c1_iy] = (*chartInstance->c1_G)[c1_c_j];
  }

  for (c1_d_j = 0; c1_d_j < 19200; c1_d_j++) {
    c1_c_j = c1_d_j;
    c1_iy++;
    c1_RGB[c1_iy] = (*chartInstance->c1_B)[c1_c_j];
  }

  rgb2hsv_tbb_uint8(&c1_RGB[0], 19200.0, &chartInstance->c1_I[0], true);
  c1_i3 = 0;
  for (c1_i4 = 0; c1_i4 < 160; c1_i4++) {
    for (c1_i6 = 0; c1_i6 < 120; c1_i6++) {
      (*chartInstance->c1_BW)[c1_i6 + c1_i3] = (chartInstance->c1_I[c1_i6 +
        c1_i3] >= 0.935);
    }

    c1_i3 += 120;
  }

  c1_i5 = 0;
  for (c1_i7 = 0; c1_i7 < 160; c1_i7++) {
    for (c1_i9 = 0; c1_i9 < 120; c1_i9++) {
      c1_bv[c1_i9 + c1_i5] = (chartInstance->c1_I[c1_i9 + c1_i5] <= 0.051);
    }

    c1_i5 += 120;
  }

  for (c1_i8 = 0; c1_i8 < 19200; c1_i8++) {
    (*chartInstance->c1_BW)[c1_i8] = ((*chartInstance->c1_BW)[c1_i8] ||
      c1_bv[c1_i8]);
  }

  c1_i10 = 0;
  for (c1_i11 = 0; c1_i11 < 160; c1_i11++) {
    for (c1_i13 = 0; c1_i13 < 120; c1_i13++) {
      c1_bv[c1_i13 + c1_i10] = (chartInstance->c1_I[(c1_i13 + c1_i10) + 19200] >=
        0.121);
    }

    c1_i10 += 120;
  }

  for (c1_i12 = 0; c1_i12 < 19200; c1_i12++) {
    (*chartInstance->c1_BW)[c1_i12] = ((*chartInstance->c1_BW)[c1_i12] &&
      c1_bv[c1_i12]);
  }

  c1_i14 = 0;
  for (c1_i15 = 0; c1_i15 < 160; c1_i15++) {
    for (c1_i17 = 0; c1_i17 < 120; c1_i17++) {
      c1_bv[c1_i17 + c1_i14] = (chartInstance->c1_I[(c1_i17 + c1_i14) + 19200] <=
        1.0);
    }

    c1_i14 += 120;
  }

  for (c1_i16 = 0; c1_i16 < 19200; c1_i16++) {
    (*chartInstance->c1_BW)[c1_i16] = ((*chartInstance->c1_BW)[c1_i16] &&
      c1_bv[c1_i16]);
  }

  c1_i18 = 0;
  for (c1_i19 = 0; c1_i19 < 160; c1_i19++) {
    for (c1_i21 = 0; c1_i21 < 120; c1_i21++) {
      c1_bv[c1_i21 + c1_i18] = (chartInstance->c1_I[(c1_i21 + c1_i18) + 38400] >=
        0.445);
    }

    c1_i18 += 120;
  }

  for (c1_i20 = 0; c1_i20 < 19200; c1_i20++) {
    (*chartInstance->c1_BW)[c1_i20] = ((*chartInstance->c1_BW)[c1_i20] &&
      c1_bv[c1_i20]);
  }

  c1_i22 = 0;
  for (c1_i23 = 0; c1_i23 < 160; c1_i23++) {
    for (c1_i25 = 0; c1_i25 < 120; c1_i25++) {
      c1_bv[c1_i25 + c1_i22] = (chartInstance->c1_I[(c1_i25 + c1_i22) + 38400] <=
        1.0);
    }

    c1_i22 += 120;
  }

  for (c1_i24 = 0; c1_i24 < 19200; c1_i24++) {
    (*chartInstance->c1_BW)[c1_i24] = ((*chartInstance->c1_BW)[c1_i24] &&
      c1_bv[c1_i24]);
  }

  c1_do_animation_call_c1_flightControlSystem(chartInstance);
  for (c1_i26 = 0; c1_i26 < 19200; c1_i26++) {
    covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 3U, (real_T)
                      (*chartInstance->c1_BW)[c1_i26]);
  }
}

static void ext_mode_exec_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c1_update_jit_animation_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c1_do_animation_call_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  sfDoAnimationWrapper(chartInstance->S, false, true);
  sfDoAnimationWrapper(chartInstance->S, false, false);
}

static const mxArray *get_sim_state_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  const mxArray *c1_b_y = NULL;
  const mxArray *c1_c_y = NULL;
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellmatrix(2, 1), false);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", *chartInstance->c1_BW, 11, 0U, 1U,
    0U, 2, 120, 160), false);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y",
    &chartInstance->c1_is_active_c1_flightControlSystem, 3, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  sf_mex_assign(&c1_st, c1_y, false);
  return c1_st;
}

static void set_sim_state_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  int32_T c1_i;
  boolean_T c1_bv[19200];
  chartInstance->c1_doneDoubleBufferReInit = true;
  c1_u = sf_mex_dup(c1_st);
  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)), "BW",
                      c1_bv);
  for (c1_i = 0; c1_i < 19200; c1_i++) {
    (*chartInstance->c1_BW)[c1_i] = c1_bv[c1_i];
  }

  chartInstance->c1_is_active_c1_flightControlSystem = c1_c_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 1)),
     "is_active_c1_flightControlSystem");
  sf_mex_destroy(&c1_u);
  sf_mex_destroy(&c1_st);
}

static void initSimStructsc1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initSubchartIOPointersc1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

const mxArray *sf_c1_flightControlSystem_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c1_nameCaptureInfo;
}

static void c1_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_b_BW, const char_T *c1_identifier, boolean_T
  c1_y[19200])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = (const char_T *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_BW), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_b_BW);
}

static void c1_b_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  boolean_T c1_y[19200])
{
  int32_T c1_i;
  boolean_T c1_bv[19200];
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_bv, 1, 11, 0U, 1, 0U, 2, 120,
                160);
  for (c1_i = 0; c1_i < 19200; c1_i++) {
    c1_y[c1_i] = c1_bv[c1_i];
  }

  sf_mex_destroy(&c1_u);
}

static uint8_T c1_c_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_flightControlSystem, const
  char_T *c1_identifier)
{
  emlrtMsgIdentifier c1_thisId;
  uint8_T c1_y;
  c1_thisId.fIdentifier = (const char_T *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_flightControlSystem), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_flightControlSystem);
  return c1_y;
}

static uint8_T c1_d_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_b_u;
  uint8_T c1_y;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_b_u, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_b_u;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_slStringInitializeDynamicBuffers
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c1_chart_data_browse_helper(SFc1_flightControlSystemInstanceStruct
  *chartInstance, int32_T c1_ssIdNumber, const mxArray **c1_mxData, uint8_T
  *c1_isValueTooBig)
{
  *c1_mxData = NULL;
  *c1_mxData = NULL;
  *c1_isValueTooBig = 0U;
  switch (c1_ssIdNumber) {
   case 4U:
    sf_mex_assign(c1_mxData, sf_mex_create("mxData", *chartInstance->c1_R, 3, 0U,
      1U, 0U, 2, 120, 160), false);
    break;

   case 5U:
    sf_mex_assign(c1_mxData, sf_mex_create("mxData", *chartInstance->c1_BW, 11,
      0U, 1U, 0U, 2, 120, 160), false);
    break;

   case 6U:
    sf_mex_assign(c1_mxData, sf_mex_create("mxData", *chartInstance->c1_G, 3, 0U,
      1U, 0U, 2, 120, 160), false);
    break;

   case 7U:
    sf_mex_assign(c1_mxData, sf_mex_create("mxData", *chartInstance->c1_B, 3, 0U,
      1U, 0U, 2, 120, 160), false);
    break;
  }
}

static void init_dsm_address_info(SFc1_flightControlSystemInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc1_flightControlSystemInstanceStruct
  *chartInstance)
{
  chartInstance->c1_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
  chartInstance->c1_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c1_R = (uint8_T (*)[19200])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c1_BW = (boolean_T (*)[19200])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c1_G = (uint8_T (*)[19200])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c1_B = (uint8_T (*)[19200])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SFunction Glue Code */
void sf_c1_flightControlSystem_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(294179283U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2220195658U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3830404390U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2691782724U);
}

mxArray *sf_c1_flightControlSystem_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,1);
  mxSetCell(mxcell3p, 0, mxCreateString(
             "images.internal.coder.buildable.Rgb2hsvBuildable"));
  return(mxcell3p);
}

mxArray *sf_c1_flightControlSystem_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("late");
  mxArray *fallbackReason = mxCreateString("ir_function_calls");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("rgb2hsv_tbb_uint8");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c1_flightControlSystem_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c1_flightControlSystem(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNpjYPT0ZQACPiD+wcjAwAakOYCYiQECWKF8RqgYI1ycBS6uAMQllQWpIPHiomTPFCCdl5gL5ie"
    "WVnjmpeWDzbdgQJjPhsV8RiTzOaHiEPDBnjL9Ig4g/QZI+lkI+E8AyHMKh4QLLHzIt1/BgTL9EP"
    "sDCLhfAcX9EH5mcXxicklmWWp8smF8Wk5mekaJc35eSVF+TnBlcUlqLsx/AIV4HNc="
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_flightControlSystem_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "sXw7wIzQK686WZdHgOJPqwD";
}

static void sf_opaque_initialize_c1_flightControlSystem(void *chartInstanceVar)
{
  initialize_params_c1_flightControlSystem
    ((SFc1_flightControlSystemInstanceStruct*) chartInstanceVar);
  initialize_c1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c1_flightControlSystem(void *chartInstanceVar)
{
  enable_c1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c1_flightControlSystem(void *chartInstanceVar)
{
  disable_c1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c1_flightControlSystem(void *chartInstanceVar)
{
  sf_gateway_c1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c1_flightControlSystem(SimStruct*
  S)
{
  return get_sim_state_c1_flightControlSystem
    ((SFc1_flightControlSystemInstanceStruct *)sf_get_chart_instance_ptr(S));/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c1_flightControlSystem(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_cleanup_runtime_resources_c1_flightControlSystem(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_flightControlSystemInstanceStruct*) chartInstanceVar
      )->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_flightControlSystem_optimization_info();
    }

    mdl_cleanup_runtime_resources_c1_flightControlSystem
      ((SFc1_flightControlSystemInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_mdl_start_c1_flightControlSystem(void *chartInstanceVar)
{
  mdl_start_c1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    chartInstanceVar);
  if (chartInstanceVar) {
    sf_reset_warnings_ChartRunTimeInfo(((SFc1_flightControlSystemInstanceStruct*)
      chartInstanceVar)->S);
  }
}

static void sf_opaque_mdl_terminate_c1_flightControlSystem(void
  *chartInstanceVar)
{
  mdl_terminate_c1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_flightControlSystem(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  sf_warn_if_symbolic_dimension_param_changed(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_flightControlSystem
      ((SFc1_flightControlSystemInstanceStruct*)sf_get_chart_instance_ptr(S));
    initSubchartIOPointersc1_flightControlSystem
      ((SFc1_flightControlSystemInstanceStruct*)sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c1_flightControlSystem_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [22] = {
    "eNrtWN1uG0UUHqchoqJEuUCtkJDIJRcgaBFtLhAk/qOGhBjWSVBvqsnusXfk2ZnN/NhxxCUPgMR",
    "L8BK8B+/ADZe95Mzu2nU3xt5xRGkRKzmb2d3vfOecPX+zpNY5Inhs4+/ndwnZwvOb+Nsg+fFGsa",
    "7N/fLrm+TzYv3jW4SEMoIBiMD2++yS+B3CJl2qaKKJ/yFoAt+DltwaJkVH9GV1LBN9UCBCFJBKZ",
    "bx4NUssZ2LYtiJ0zPosZmEcxNLyqI4CaXQs+OTveFNrusjYZApC0waITKykHcRtTgfLvaDMuBFD",
    "ONQ28faVBhPY1Jmqjyw3LOXQuoSwI7Sh6AW9wt7AUAMNc+nnZGevDqZomaScUVHd1zHVAaQYHQZ",
    "O0gj/HluD3quEDWOqTB1iOgJ9yIYZuxRQiZ1pfPqcCWqkYpS3Et5w0ira2+Vo4xGmBPd9R2hvXQ",
    "EdppIJ45kQQRv93BL0nEMTzu3AkzeAC+uy4ZTBGJTf++035AgUHcCx8NM5e0etyywoZ7lUEWtYA",
    "qdUHYQYuxoiv7qBSacDiuEIPRTjhYXMxR3dU2yEseFb6zou/deqdTbJo1+vhc14WyPwjqsZbzsU",
    "Dcq59sP2ZHoII+AZf5MaugY25/cAa82insTocNXGs2JZwTATCmxDiohVj8pRCZU1tm+xSVWAs8S",
    "lAUTo5pnqM0Gr8shqI5MGlpzm4WFFvuvYjjCg+jSEyj1GUaYBFc7iypM3YtolEqLRSyazsrKEPA",
    "fXghLdt6I5lmqIPvZtZs995TLBDw3RAAuzgazItTC6Tym3FXVO9ADzB8PjRGOV9eNFrMuftcAhD",
    "WOIXOdkHI6wzqKAqq9Yu5Z/gNaOmJk0QYeKpVUzyWJBx6brvNSbpHAihkKORVvJJCgmryVxBYBV",
    "gyrBxKCOLVxN2qh8Na0VXPSy6u475Dg/U8PpuYuNr0BgN3S2uqmBhphVLYEjMip0E2zArnCIEZp",
    "pg416krf6vO+5+f0xeT6/by6Y3+/Oze87xTq8/7TP2SB2hcYoyYMJyk5yeZ/MybtTYT8w1WMZjl",
    "zDkRluev5gDl9bwEvmzmW+2xsvPn+rxLeBV2q1Wobbn8O9XeLZLOG2Cp/t/Fb/Ze/q0c4fH9/r/",
    "/RhdLiKv3aNv5b973C/bvjtt7aL9XvTuWlWpUfXClmVeLhXige31j+MH407V99983Dv4dmT6PHg",
    "+OvuxbiZyXtWW67vRknf6fVdN6thEmc1QYWdqNi3uTW1+X7Cyd+b03drhT9uz8UTIX9+eTP8O/v",
    "l97i5wr4dXNXPXozb9fl392+Gz/m7K/TfLb3v3Wx2f0pdhYaniyvBdsU8WxbnvjjyknGvi57/++",
    "Wft69Kn7u1Jm5dPvKScTe1z7d/v+7PL+sbpPT8zitsR/m87hz3qtn1O/Gbs94v1l/MviM0YsajB",
    "TuZ4jZuNvqL7v5H4vuZp/+mc2XL+a/44Pzk0wNB+QS3LvnWsLjcVe674eyWAqoX7w//jX4yPe+v",
    "mKvulPLbrcdMRHKsP7r/4LMHN+lPfwF1PBys",
    ""
  };

  static char newstr [1537] = "";
  newstr[0] = '\0';
  for (i = 0; i < 22; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c1_flightControlSystem(SimStruct *S)
{
  const char* newstr = sf_c1_flightControlSystem_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(2470624528U));
  ssSetChecksum1(S,(272071224U));
  ssSetChecksum2(S,(1712795627U));
  ssSetChecksum3(S,(1281633412U));
}

static void mdlRTW_c1_flightControlSystem(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlSetupRuntimeResources_c1_flightControlSystem(SimStruct *S)
{
  SFc1_flightControlSystemInstanceStruct *chartInstance;
  chartInstance = (SFc1_flightControlSystemInstanceStruct *)utMalloc(sizeof
    (SFc1_flightControlSystemInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc1_flightControlSystemInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_flightControlSystem;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_flightControlSystem;
  chartInstance->chartInfo.mdlStart = sf_opaque_mdl_start_c1_flightControlSystem;
  chartInstance->chartInfo.mdlTerminate =
    sf_opaque_mdl_terminate_c1_flightControlSystem;
  chartInstance->chartInfo.mdlCleanupRuntimeResources =
    sf_opaque_cleanup_runtime_resources_c1_flightControlSystem;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_flightControlSystem;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c1_flightControlSystem;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_flightControlSystem;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_flightControlSystem;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_flightControlSystem;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_flightControlSystem;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_flightControlSystem;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartEventFcn = NULL;
  chartInstance->S = S;
  chartInstance->chartInfo.dispatchToExportedFcn = NULL;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0,
    chartInstance->c1_JITStateAnimation,
    chartInstance->c1_JITTransitionAnimation);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  mdl_setup_runtime_resources_c1_flightControlSystem(chartInstance);
}

void c1_flightControlSystem_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_SETUP_RUNTIME_RESOURCES:
    mdlSetupRuntimeResources_c1_flightControlSystem(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_flightControlSystem(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_flightControlSystem(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_flightControlSystem_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
