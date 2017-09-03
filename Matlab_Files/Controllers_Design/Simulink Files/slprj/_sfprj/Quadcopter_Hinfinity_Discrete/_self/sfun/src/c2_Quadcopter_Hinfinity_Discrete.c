/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Quadcopter_Hinfinity_Discrete_sfun.h"
#include "c2_Quadcopter_Hinfinity_Discrete.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Quadcopter_Hinfinity_Discrete_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c2_debug_family_names[26] = { "g", "m", "Ixx", "Iyy", "Izz",
  "U1", "U2", "U3", "U4", "dX", "ddX", "dY", "ddY", "dZ", "ddZ", "dPsi", "ddPsi",
  "dTheta", "ddTheta", "dPhi", "ddPhi", "nargin", "nargout", "U", "States",
  "States_dot" };

/* Function Declarations */
static void initialize_c2_Quadcopter_Hinfinity_Discrete
  (SFc2_Quadcopter_Hinfinity_DiscreteInstanceStruct *chartInstance);
static void initialize_params_c2_Quadcopter_Hinfinity_Discrete
  (SFc2_Quadcopter_Hinfinity_DiscreteInstanceStruct *chartInstance);
static void enable_c2_Quadcopter_Hinfinity_Discrete
  (SFc2_Quadcopter_Hinfinity_DiscreteInstanceStruct *chartInstance);
static void disable_c2_Quadcopter_Hinfinity_Discrete
  (SFc2_Quadcopter_Hinfinity_DiscreteInstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_Quadcopter_Hinfinity_Discrete
  (SFc2_Quadcopter_Hinfinity_DiscreteInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_Quadcopter_Hinfinity_Discrete
  (SFc2_Quadcopter_Hinfinity_DiscreteInstanceStruct *chartInstance);
static void set_sim_state_c2_Quadcopter_Hinfinity_Discrete
  (SFc2_Quadcopter_Hinfinity_DiscreteInstanceStruct *chartInstance, const
   mxArray *c2_st);
static void finalize_c2_Quadcopter_Hinfinity_Discrete
  (SFc2_Quadcopter_Hinfinity_DiscreteInstanceStruct *chartInstance);
static void sf_c2_Quadcopter_Hinfinity_Discrete
  (SFc2_Quadcopter_Hinfinity_DiscreteInstanceStruct *chartInstance);
static void c2_chartstep_c2_Quadcopter_Hinfinity_Discrete
  (SFc2_Quadcopter_Hinfinity_DiscreteInstanceStruct *chartInstance);
static void initSimStructsc2_Quadcopter_Hinfinity_Discrete
  (SFc2_Quadcopter_Hinfinity_DiscreteInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static void c2_emlrt_marshallIn(SFc2_Quadcopter_Hinfinity_DiscreteInstanceStruct
  *chartInstance, const mxArray *c2_States_dot, const char_T *c2_identifier,
  real_T c2_y[12]);
static void c2_b_emlrt_marshallIn
  (SFc2_Quadcopter_Hinfinity_DiscreteInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[12]);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_c_emlrt_marshallIn
  (SFc2_Quadcopter_Hinfinity_DiscreteInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static void c2_info_helper(const mxArray **c2_info);
static const mxArray *c2_emlrt_marshallOut(char * c2_u);
static const mxArray *c2_b_emlrt_marshallOut(uint32_T c2_u);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_d_emlrt_marshallIn
  (SFc2_Quadcopter_Hinfinity_DiscreteInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_e_emlrt_marshallIn
  (SFc2_Quadcopter_Hinfinity_DiscreteInstanceStruct *chartInstance, const
   mxArray *c2_b_is_active_c2_Quadcopter_Hinfinity_Discrete, const char_T
   *c2_identifier);
static uint8_T c2_f_emlrt_marshallIn
  (SFc2_Quadcopter_Hinfinity_DiscreteInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info
  (SFc2_Quadcopter_Hinfinity_DiscreteInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c2_Quadcopter_Hinfinity_Discrete
  (SFc2_Quadcopter_Hinfinity_DiscreteInstanceStruct *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_is_active_c2_Quadcopter_Hinfinity_Discrete = 0U;
}

static void initialize_params_c2_Quadcopter_Hinfinity_Discrete
  (SFc2_Quadcopter_Hinfinity_DiscreteInstanceStruct *chartInstance)
{
}

static void enable_c2_Quadcopter_Hinfinity_Discrete
  (SFc2_Quadcopter_Hinfinity_DiscreteInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_Quadcopter_Hinfinity_Discrete
  (SFc2_Quadcopter_Hinfinity_DiscreteInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_Quadcopter_Hinfinity_Discrete
  (SFc2_Quadcopter_Hinfinity_DiscreteInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c2_Quadcopter_Hinfinity_Discrete
  (SFc2_Quadcopter_Hinfinity_DiscreteInstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  int32_T c2_i0;
  real_T c2_u[12];
  const mxArray *c2_b_y = NULL;
  uint8_T c2_hoistedGlobal;
  uint8_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  real_T (*c2_States_dot)[12];
  c2_States_dot = (real_T (*)[12])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(2), FALSE);
  for (c2_i0 = 0; c2_i0 < 12; c2_i0++) {
    c2_u[c2_i0] = (*c2_States_dot)[c2_i0];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 12), FALSE);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_hoistedGlobal =
    chartInstance->c2_is_active_c2_Quadcopter_Hinfinity_Discrete;
  c2_b_u = c2_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  sf_mex_assign(&c2_st, c2_y, FALSE);
  return c2_st;
}

static void set_sim_state_c2_Quadcopter_Hinfinity_Discrete
  (SFc2_Quadcopter_Hinfinity_DiscreteInstanceStruct *chartInstance, const
   mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T c2_dv0[12];
  int32_T c2_i1;
  real_T (*c2_States_dot)[12];
  c2_States_dot = (real_T (*)[12])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)),
                      "States_dot", c2_dv0);
  for (c2_i1 = 0; c2_i1 < 12; c2_i1++) {
    (*c2_States_dot)[c2_i1] = c2_dv0[c2_i1];
  }

  chartInstance->c2_is_active_c2_Quadcopter_Hinfinity_Discrete =
    c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 1)),
    "is_active_c2_Quadcopter_Hinfinity_Discrete");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_Quadcopter_Hinfinity_Discrete(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_Quadcopter_Hinfinity_Discrete
  (SFc2_Quadcopter_Hinfinity_DiscreteInstanceStruct *chartInstance)
{
}

static void sf_c2_Quadcopter_Hinfinity_Discrete
  (SFc2_Quadcopter_Hinfinity_DiscreteInstanceStruct *chartInstance)
{
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_i4;
  real_T (*c2_States_dot)[12];
  real_T (*c2_States)[12];
  real_T (*c2_U)[4];
  c2_States_dot = (real_T (*)[12])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_States = (real_T (*)[12])ssGetInputPortSignal(chartInstance->S, 1);
  c2_U = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  for (c2_i2 = 0; c2_i2 < 4; c2_i2++) {
    _SFD_DATA_RANGE_CHECK((*c2_U)[c2_i2], 0U);
  }

  for (c2_i3 = 0; c2_i3 < 12; c2_i3++) {
    _SFD_DATA_RANGE_CHECK((*c2_States)[c2_i3], 1U);
  }

  for (c2_i4 = 0; c2_i4 < 12; c2_i4++) {
    _SFD_DATA_RANGE_CHECK((*c2_States_dot)[c2_i4], 2U);
  }

  chartInstance->c2_sfEvent = CALL_EVENT;
  c2_chartstep_c2_Quadcopter_Hinfinity_Discrete(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY
    (_Quadcopter_Hinfinity_DiscreteMachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
}

static void c2_chartstep_c2_Quadcopter_Hinfinity_Discrete
  (SFc2_Quadcopter_Hinfinity_DiscreteInstanceStruct *chartInstance)
{
  int32_T c2_i5;
  real_T c2_U[4];
  int32_T c2_i6;
  real_T c2_States[12];
  uint32_T c2_debug_family_var_map[26];
  real_T c2_g;
  real_T c2_m;
  real_T c2_Ixx;
  real_T c2_Iyy;
  real_T c2_Izz;
  real_T c2_U1;
  real_T c2_U2;
  real_T c2_U3;
  real_T c2_U4;
  real_T c2_dX;
  real_T c2_ddX;
  real_T c2_dY;
  real_T c2_ddY;
  real_T c2_dZ;
  real_T c2_ddZ;
  real_T c2_dPsi;
  real_T c2_ddPsi;
  real_T c2_dTheta;
  real_T c2_ddTheta;
  real_T c2_dPhi;
  real_T c2_ddPhi;
  real_T c2_nargin = 2.0;
  real_T c2_nargout = 1.0;
  real_T c2_States_dot[12];
  real_T c2_A;
  real_T c2_x;
  real_T c2_b_x;
  real_T c2_y;
  real_T c2_c_x;
  real_T c2_d_x;
  real_T c2_a;
  real_T c2_b;
  real_T c2_b_y;
  real_T c2_e_x;
  real_T c2_f_x;
  real_T c2_b_b;
  real_T c2_c_y;
  real_T c2_b_A;
  real_T c2_g_x;
  real_T c2_h_x;
  real_T c2_d_y;
  real_T c2_i_x;
  real_T c2_j_x;
  real_T c2_b_a;
  real_T c2_c_b;
  real_T c2_e_y;
  real_T c2_k_x;
  real_T c2_l_x;
  real_T c2_c_a;
  real_T c2_d_b;
  real_T c2_f_y;
  real_T c2_m_x;
  real_T c2_n_x;
  real_T c2_e_b;
  real_T c2_g_y;
  real_T c2_o_x;
  real_T c2_p_x;
  real_T c2_d_a;
  real_T c2_f_b;
  real_T c2_h_y;
  real_T c2_c_A;
  real_T c2_q_x;
  real_T c2_r_x;
  real_T c2_i_y;
  real_T c2_s_x;
  real_T c2_t_x;
  real_T c2_e_a;
  real_T c2_g_b;
  real_T c2_j_y;
  real_T c2_u_x;
  real_T c2_v_x;
  real_T c2_f_a;
  real_T c2_h_b;
  real_T c2_k_y;
  real_T c2_w_x;
  real_T c2_x_x;
  real_T c2_i_b;
  real_T c2_l_y;
  real_T c2_y_x;
  real_T c2_ab_x;
  real_T c2_g_a;
  real_T c2_j_b;
  real_T c2_m_y;
  real_T c2_k_b;
  real_T c2_n_y;
  real_T c2_h_a;
  real_T c2_l_b;
  real_T c2_o_y;
  real_T c2_d_A;
  real_T c2_bb_x;
  real_T c2_cb_x;
  real_T c2_p_y;
  real_T c2_m_b;
  real_T c2_q_y;
  real_T c2_i_a;
  real_T c2_n_b;
  real_T c2_r_y;
  real_T c2_e_A;
  real_T c2_db_x;
  real_T c2_eb_x;
  real_T c2_s_y;
  real_T c2_o_b;
  real_T c2_t_y;
  real_T c2_j_a;
  real_T c2_p_b;
  real_T c2_u_y;
  real_T c2_f_A;
  real_T c2_fb_x;
  real_T c2_gb_x;
  real_T c2_v_y;
  real_T c2_b_dX[12];
  int32_T c2_i7;
  int32_T c2_i8;
  real_T (*c2_b_States_dot)[12];
  real_T (*c2_b_States)[12];
  real_T (*c2_b_U)[4];
  c2_b_States_dot = (real_T (*)[12])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_b_States = (real_T (*)[12])ssGetInputPortSignal(chartInstance->S, 1);
  c2_b_U = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  for (c2_i5 = 0; c2_i5 < 4; c2_i5++) {
    c2_U[c2_i5] = (*c2_b_U)[c2_i5];
  }

  for (c2_i6 = 0; c2_i6 < 12; c2_i6++) {
    c2_States[c2_i6] = (*c2_b_States)[c2_i6];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 26U, 26U, c2_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_g, 0U, c2_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_m, 1U, c2_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_Ixx, 2U, c2_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_Iyy, 3U, c2_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_Izz, 4U, c2_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_U1, 5U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_U2, 6U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_U3, 7U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_U4, 8U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_dX, 9U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_ddX, 10U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_dY, 11U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_ddY, 12U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_dZ, 13U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_ddZ, 14U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_dPsi, 15U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_ddPsi, 16U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_dTheta, 17U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_ddTheta, 18U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_dPhi, 19U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_ddPhi, 20U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 21U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 22U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_U, 23U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_States, 24U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_States_dot, 25U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 4);
  c2_g = 9.81;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 6);
  c2_m = 1.192;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 7);
  c2_Ixx = 0.014927;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 8);
  c2_Iyy = 0.014927;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 9);
  c2_Izz = 0.025345;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 16);
  c2_U1 = c2_U[0];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 17);
  c2_U2 = c2_U[1];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 18);
  c2_U3 = c2_U[2];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 19);
  c2_U4 = c2_U[3];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 21);
  c2_dX = c2_States[1];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 22);
  c2_A = -c2_U1;
  c2_x = c2_A;
  c2_b_x = c2_x;
  c2_y = c2_b_x / 1.192;
  c2_c_x = c2_States[8];
  c2_d_x = c2_c_x;
  c2_d_x = muDoubleScalarSin(c2_d_x);
  c2_a = c2_y;
  c2_b = c2_d_x;
  c2_b_y = c2_a * c2_b;
  c2_e_x = c2_States[8];
  c2_f_x = c2_e_x;
  c2_f_x = muDoubleScalarSin(c2_f_x);
  c2_b_b = c2_f_x;
  c2_c_y = 9.81 * c2_b_b;
  c2_ddX = c2_b_y - c2_c_y;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 23);
  c2_dY = c2_States[3];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 24);
  c2_b_A = c2_U1;
  c2_g_x = c2_b_A;
  c2_h_x = c2_g_x;
  c2_d_y = c2_h_x / 1.192;
  c2_i_x = c2_States[8];
  c2_j_x = c2_i_x;
  c2_j_x = muDoubleScalarCos(c2_j_x);
  c2_b_a = c2_d_y;
  c2_c_b = c2_j_x;
  c2_e_y = c2_b_a * c2_c_b;
  c2_k_x = c2_States[10];
  c2_l_x = c2_k_x;
  c2_l_x = muDoubleScalarSin(c2_l_x);
  c2_c_a = c2_e_y;
  c2_d_b = c2_l_x;
  c2_f_y = c2_c_a * c2_d_b;
  c2_m_x = c2_States[8];
  c2_n_x = c2_m_x;
  c2_n_x = muDoubleScalarCos(c2_n_x);
  c2_e_b = c2_n_x;
  c2_g_y = 9.81 * c2_e_b;
  c2_o_x = c2_States[10];
  c2_p_x = c2_o_x;
  c2_p_x = muDoubleScalarSin(c2_p_x);
  c2_d_a = c2_g_y;
  c2_f_b = c2_p_x;
  c2_h_y = c2_d_a * c2_f_b;
  c2_ddY = c2_f_y + c2_h_y;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 25);
  c2_dZ = c2_States[5];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 26);
  c2_c_A = c2_U1;
  c2_q_x = c2_c_A;
  c2_r_x = c2_q_x;
  c2_i_y = c2_r_x / 1.192;
  c2_s_x = c2_States[8];
  c2_t_x = c2_s_x;
  c2_t_x = muDoubleScalarCos(c2_t_x);
  c2_e_a = c2_i_y;
  c2_g_b = c2_t_x;
  c2_j_y = c2_e_a * c2_g_b;
  c2_u_x = c2_States[10];
  c2_v_x = c2_u_x;
  c2_v_x = muDoubleScalarCos(c2_v_x);
  c2_f_a = c2_j_y;
  c2_h_b = c2_v_x;
  c2_k_y = c2_f_a * c2_h_b;
  c2_w_x = c2_States[8];
  c2_x_x = c2_w_x;
  c2_x_x = muDoubleScalarCos(c2_x_x);
  c2_i_b = c2_x_x;
  c2_l_y = 9.81 * c2_i_b;
  c2_y_x = c2_States[10];
  c2_ab_x = c2_y_x;
  c2_ab_x = muDoubleScalarCos(c2_ab_x);
  c2_g_a = c2_l_y;
  c2_j_b = c2_ab_x;
  c2_m_y = c2_g_a * c2_j_b;
  c2_ddZ = (c2_k_y + c2_m_y) - c2_g;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 27);
  c2_dPsi = c2_States[7];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 28);
  c2_k_b = c2_States[11];
  c2_n_y = 0.0 * c2_k_b;
  c2_h_a = c2_n_y;
  c2_l_b = c2_States[9];
  c2_o_y = c2_h_a * c2_l_b;
  c2_d_A = c2_U2;
  c2_bb_x = c2_d_A;
  c2_cb_x = c2_bb_x;
  c2_p_y = c2_cb_x / 0.025345;
  c2_ddPsi = c2_o_y + c2_p_y;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 29);
  c2_dTheta = c2_States[9];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 30);
  c2_m_b = c2_States[11];
  c2_q_y = 0.69792992563810552 * c2_m_b;
  c2_i_a = c2_q_y;
  c2_n_b = c2_States[7];
  c2_r_y = c2_i_a * c2_n_b;
  c2_e_A = c2_U3;
  c2_db_x = c2_e_A;
  c2_eb_x = c2_db_x;
  c2_s_y = c2_eb_x / 0.014927;
  c2_ddTheta = c2_r_y + c2_s_y;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 31);
  c2_dPhi = c2_States[11];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 32);
  c2_o_b = c2_States[9];
  c2_t_y = -0.69792992563810552 * c2_o_b;
  c2_j_a = c2_t_y;
  c2_p_b = c2_States[7];
  c2_u_y = c2_j_a * c2_p_b;
  c2_f_A = c2_U4;
  c2_fb_x = c2_f_A;
  c2_gb_x = c2_fb_x;
  c2_v_y = c2_gb_x / 0.014927;
  c2_ddPhi = c2_u_y + c2_v_y;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 35);
  c2_b_dX[0] = c2_dX;
  c2_b_dX[1] = c2_ddX;
  c2_b_dX[2] = c2_dY;
  c2_b_dX[3] = c2_ddY;
  c2_b_dX[4] = c2_dZ;
  c2_b_dX[5] = c2_ddZ;
  c2_b_dX[6] = c2_dPsi;
  c2_b_dX[7] = c2_ddPsi;
  c2_b_dX[8] = c2_dTheta;
  c2_b_dX[9] = c2_ddTheta;
  c2_b_dX[10] = c2_dPhi;
  c2_b_dX[11] = c2_ddPhi;
  for (c2_i7 = 0; c2_i7 < 12; c2_i7++) {
    c2_States_dot[c2_i7] = c2_b_dX[c2_i7];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -35);
  _SFD_SYMBOL_SCOPE_POP();
  for (c2_i8 = 0; c2_i8 < 12; c2_i8++) {
    (*c2_b_States_dot)[c2_i8] = c2_States_dot[c2_i8];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
}

static void initSimStructsc2_Quadcopter_Hinfinity_Discrete
  (SFc2_Quadcopter_Hinfinity_DiscreteInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i9;
  real_T c2_b_inData[12];
  int32_T c2_i10;
  real_T c2_u[12];
  const mxArray *c2_y = NULL;
  SFc2_Quadcopter_Hinfinity_DiscreteInstanceStruct *chartInstance;
  chartInstance = (SFc2_Quadcopter_Hinfinity_DiscreteInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i9 = 0; c2_i9 < 12; c2_i9++) {
    c2_b_inData[c2_i9] = (*(real_T (*)[12])c2_inData)[c2_i9];
  }

  for (c2_i10 = 0; c2_i10 < 12; c2_i10++) {
    c2_u[c2_i10] = c2_b_inData[c2_i10];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 12), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_emlrt_marshallIn(SFc2_Quadcopter_Hinfinity_DiscreteInstanceStruct
  *chartInstance, const mxArray *c2_States_dot, const char_T *c2_identifier,
  real_T c2_y[12])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_States_dot), &c2_thisId,
                        c2_y);
  sf_mex_destroy(&c2_States_dot);
}

static void c2_b_emlrt_marshallIn
  (SFc2_Quadcopter_Hinfinity_DiscreteInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[12])
{
  real_T c2_dv1[12];
  int32_T c2_i11;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv1, 1, 0, 0U, 1, 0U, 1, 12);
  for (c2_i11 = 0; c2_i11 < 12; c2_i11++) {
    c2_y[c2_i11] = c2_dv1[c2_i11];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_States_dot;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[12];
  int32_T c2_i12;
  SFc2_Quadcopter_Hinfinity_DiscreteInstanceStruct *chartInstance;
  chartInstance = (SFc2_Quadcopter_Hinfinity_DiscreteInstanceStruct *)
    chartInstanceVoid;
  c2_States_dot = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_States_dot), &c2_thisId,
                        c2_y);
  sf_mex_destroy(&c2_States_dot);
  for (c2_i12 = 0; c2_i12 < 12; c2_i12++) {
    (*(real_T (*)[12])c2_outData)[c2_i12] = c2_y[c2_i12];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i13;
  real_T c2_b_inData[4];
  int32_T c2_i14;
  real_T c2_u[4];
  const mxArray *c2_y = NULL;
  SFc2_Quadcopter_Hinfinity_DiscreteInstanceStruct *chartInstance;
  chartInstance = (SFc2_Quadcopter_Hinfinity_DiscreteInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i13 = 0; c2_i13 < 4; c2_i13++) {
    c2_b_inData[c2_i13] = (*(real_T (*)[4])c2_inData)[c2_i13];
  }

  for (c2_i14 = 0; c2_i14 < 4; c2_i14++) {
    c2_u[c2_i14] = c2_b_inData[c2_i14];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 4), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_Quadcopter_Hinfinity_DiscreteInstanceStruct *chartInstance;
  chartInstance = (SFc2_Quadcopter_Hinfinity_DiscreteInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_c_emlrt_marshallIn
  (SFc2_Quadcopter_Hinfinity_DiscreteInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_nargout;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_Quadcopter_Hinfinity_DiscreteInstanceStruct *chartInstance;
  chartInstance = (SFc2_Quadcopter_Hinfinity_DiscreteInstanceStruct *)
    chartInstanceVoid;
  c2_nargout = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nargout), &c2_thisId);
  sf_mex_destroy(&c2_nargout);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray
  *sf_c2_Quadcopter_Hinfinity_Discrete_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  sf_mex_assign(&c2_nameCaptureInfo, sf_mex_createstruct("structure", 2, 11, 1),
                FALSE);
  c2_info_helper(&c2_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c2_nameCaptureInfo);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(const mxArray **c2_info)
{
  const mxArray *c2_rhs0 = NULL;
  const mxArray *c2_lhs0 = NULL;
  const mxArray *c2_rhs1 = NULL;
  const mxArray *c2_lhs1 = NULL;
  const mxArray *c2_rhs2 = NULL;
  const mxArray *c2_lhs2 = NULL;
  const mxArray *c2_rhs3 = NULL;
  const mxArray *c2_lhs3 = NULL;
  const mxArray *c2_rhs4 = NULL;
  const mxArray *c2_lhs4 = NULL;
  const mxArray *c2_rhs5 = NULL;
  const mxArray *c2_lhs5 = NULL;
  const mxArray *c2_rhs6 = NULL;
  const mxArray *c2_lhs6 = NULL;
  const mxArray *c2_rhs7 = NULL;
  const mxArray *c2_lhs7 = NULL;
  const mxArray *c2_rhs8 = NULL;
  const mxArray *c2_lhs8 = NULL;
  const mxArray *c2_rhs9 = NULL;
  const mxArray *c2_lhs9 = NULL;
  const mxArray *c2_rhs10 = NULL;
  const mxArray *c2_lhs10 = NULL;
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("mrdivide"), "name", "name", 0);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1373331708U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1319755166U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c2_rhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 1);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("rdivide"), "name", "name", 1);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 1);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363735480U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c2_rhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 2);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363736156U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c2_rhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 3);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286843996U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c2_rhs3, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs3, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_div"), "name", "name", 4);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 4);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363735466U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c2_rhs4, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs4, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "context", "context", 5);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("sin"), "name", "name", 5);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1343855586U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c2_rhs5, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs5, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalar_sin"), "name",
                  "name", 6);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286843936U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c2_rhs6, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs6, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs6), "lhs", "lhs", 6);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "context", "context", 7);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("mtimes"), "name", "name", 7);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363735478U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c2_rhs7, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs7, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs7), "rhs", "rhs", 7);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs7), "lhs", "lhs", 7);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m!common_checks"),
                  "context", "context", 8);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 8);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363736156U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c2_rhs8, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs8, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs8), "rhs", "rhs", 8);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs8), "lhs", "lhs", 8);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "context", "context", 9);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("cos"), "name", "name", 9);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "resolved",
                  "resolved", 9);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1343855572U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c2_rhs9, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs9, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs9), "rhs", "rhs", 9);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs9), "lhs", "lhs", 9);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "context",
                  "context", 10);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalar_cos"), "name",
                  "name", 10);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286843922U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c2_rhs10, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs10, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs10), "lhs", "lhs",
                  10);
  sf_mex_destroy(&c2_rhs0);
  sf_mex_destroy(&c2_lhs0);
  sf_mex_destroy(&c2_rhs1);
  sf_mex_destroy(&c2_lhs1);
  sf_mex_destroy(&c2_rhs2);
  sf_mex_destroy(&c2_lhs2);
  sf_mex_destroy(&c2_rhs3);
  sf_mex_destroy(&c2_lhs3);
  sf_mex_destroy(&c2_rhs4);
  sf_mex_destroy(&c2_lhs4);
  sf_mex_destroy(&c2_rhs5);
  sf_mex_destroy(&c2_lhs5);
  sf_mex_destroy(&c2_rhs6);
  sf_mex_destroy(&c2_lhs6);
  sf_mex_destroy(&c2_rhs7);
  sf_mex_destroy(&c2_lhs7);
  sf_mex_destroy(&c2_rhs8);
  sf_mex_destroy(&c2_lhs8);
  sf_mex_destroy(&c2_rhs9);
  sf_mex_destroy(&c2_lhs9);
  sf_mex_destroy(&c2_rhs10);
  sf_mex_destroy(&c2_lhs10);
}

static const mxArray *c2_emlrt_marshallOut(char * c2_u)
{
  const mxArray *c2_y = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c2_u)), FALSE);
  return c2_y;
}

static const mxArray *c2_b_emlrt_marshallOut(uint32_T c2_u)
{
  const mxArray *c2_y = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 7, 0U, 0U, 0U, 0), FALSE);
  return c2_y;
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_Quadcopter_Hinfinity_DiscreteInstanceStruct *chartInstance;
  chartInstance = (SFc2_Quadcopter_Hinfinity_DiscreteInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static int32_T c2_d_emlrt_marshallIn
  (SFc2_Quadcopter_Hinfinity_DiscreteInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i15;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i15, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i15;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_Quadcopter_Hinfinity_DiscreteInstanceStruct *chartInstance;
  chartInstance = (SFc2_Quadcopter_Hinfinity_DiscreteInstanceStruct *)
    chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_e_emlrt_marshallIn
  (SFc2_Quadcopter_Hinfinity_DiscreteInstanceStruct *chartInstance, const
   mxArray *c2_b_is_active_c2_Quadcopter_Hinfinity_Discrete, const char_T
   *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_Quadcopter_Hinfinity_Discrete), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_Quadcopter_Hinfinity_Discrete);
  return c2_y;
}

static uint8_T c2_f_emlrt_marshallIn
  (SFc2_Quadcopter_Hinfinity_DiscreteInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info
  (SFc2_Quadcopter_Hinfinity_DiscreteInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
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

void sf_c2_Quadcopter_Hinfinity_Discrete_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2144566188U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3805624389U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2272786732U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1903941685U);
}

mxArray *sf_c2_Quadcopter_Hinfinity_Discrete_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("UiDxp2yoaoDuz9d9RJCou");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(12);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(12);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c2_Quadcopter_Hinfinity_Discrete_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c2_Quadcopter_Hinfinity_Discrete_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c2_Quadcopter_Hinfinity_Discrete
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"States_dot\",},{M[8],M[0],T\"is_active_c2_Quadcopter_Hinfinity_Discrete\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_Quadcopter_Hinfinity_Discrete_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_Quadcopter_Hinfinity_DiscreteInstanceStruct *chartInstance;
    chartInstance = (SFc2_Quadcopter_Hinfinity_DiscreteInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Quadcopter_Hinfinity_DiscreteMachineNumber_,
           2,
           1,
           1,
           3,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation
            (_Quadcopter_Hinfinity_DiscreteMachineNumber_,
             chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,
             _Quadcopter_Hinfinity_DiscreteMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Quadcopter_Hinfinity_DiscreteMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"U");
          _SFD_SET_DATA_PROPS(1,1,1,0,"States");
          _SFD_SET_DATA_PROPS(2,2,0,1,"States_dot");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1073);

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 12;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 12;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }

        {
          real_T (*c2_U)[4];
          real_T (*c2_States)[12];
          real_T (*c2_States_dot)[12];
          c2_States_dot = (real_T (*)[12])ssGetOutputPortSignal(chartInstance->S,
            1);
          c2_States = (real_T (*)[12])ssGetInputPortSignal(chartInstance->S, 1);
          c2_U = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c2_U);
          _SFD_SET_DATA_VALUE_PTR(1U, *c2_States);
          _SFD_SET_DATA_VALUE_PTR(2U, *c2_States_dot);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Quadcopter_Hinfinity_DiscreteMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "yWImB2MJJ31qTL7eBzhV5D";
}

static void sf_opaque_initialize_c2_Quadcopter_Hinfinity_Discrete(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_Quadcopter_Hinfinity_DiscreteInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_Quadcopter_Hinfinity_Discrete
    ((SFc2_Quadcopter_Hinfinity_DiscreteInstanceStruct*) chartInstanceVar);
  initialize_c2_Quadcopter_Hinfinity_Discrete
    ((SFc2_Quadcopter_Hinfinity_DiscreteInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_Quadcopter_Hinfinity_Discrete(void
  *chartInstanceVar)
{
  enable_c2_Quadcopter_Hinfinity_Discrete
    ((SFc2_Quadcopter_Hinfinity_DiscreteInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_Quadcopter_Hinfinity_Discrete(void
  *chartInstanceVar)
{
  disable_c2_Quadcopter_Hinfinity_Discrete
    ((SFc2_Quadcopter_Hinfinity_DiscreteInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_Quadcopter_Hinfinity_Discrete(void
  *chartInstanceVar)
{
  sf_c2_Quadcopter_Hinfinity_Discrete
    ((SFc2_Quadcopter_Hinfinity_DiscreteInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_Quadcopter_Hinfinity_Discrete
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_Quadcopter_Hinfinity_Discrete
    ((SFc2_Quadcopter_Hinfinity_DiscreteInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_Quadcopter_Hinfinity_Discrete();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c2_Quadcopter_Hinfinity_Discrete(SimStruct*
  S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_Quadcopter_Hinfinity_Discrete();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_Quadcopter_Hinfinity_Discrete
    ((SFc2_Quadcopter_Hinfinity_DiscreteInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_Quadcopter_Hinfinity_Discrete
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c2_Quadcopter_Hinfinity_Discrete(S);
}

static void sf_opaque_set_sim_state_c2_Quadcopter_Hinfinity_Discrete(SimStruct*
  S, const mxArray *st)
{
  sf_internal_set_sim_state_c2_Quadcopter_Hinfinity_Discrete(S, st);
}

static void sf_opaque_terminate_c2_Quadcopter_Hinfinity_Discrete(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_Quadcopter_Hinfinity_DiscreteInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Quadcopter_Hinfinity_Discrete_optimization_info();
    }

    finalize_c2_Quadcopter_Hinfinity_Discrete
      ((SFc2_Quadcopter_Hinfinity_DiscreteInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_Quadcopter_Hinfinity_Discrete
    ((SFc2_Quadcopter_Hinfinity_DiscreteInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_Quadcopter_Hinfinity_Discrete(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_Quadcopter_Hinfinity_Discrete
      ((SFc2_Quadcopter_Hinfinity_DiscreteInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_Quadcopter_Hinfinity_Discrete(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Quadcopter_Hinfinity_Discrete_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,2,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,2);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(791672582U));
  ssSetChecksum1(S,(2715319929U));
  ssSetChecksum2(S,(4001088877U));
  ssSetChecksum3(S,(1309605911U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_Quadcopter_Hinfinity_Discrete(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_Quadcopter_Hinfinity_Discrete(SimStruct *S)
{
  SFc2_Quadcopter_Hinfinity_DiscreteInstanceStruct *chartInstance;
  chartInstance = (SFc2_Quadcopter_Hinfinity_DiscreteInstanceStruct *)utMalloc
    (sizeof(SFc2_Quadcopter_Hinfinity_DiscreteInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc2_Quadcopter_Hinfinity_DiscreteInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_Quadcopter_Hinfinity_Discrete;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_Quadcopter_Hinfinity_Discrete;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_Quadcopter_Hinfinity_Discrete;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c2_Quadcopter_Hinfinity_Discrete;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c2_Quadcopter_Hinfinity_Discrete;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_Quadcopter_Hinfinity_Discrete;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_Quadcopter_Hinfinity_Discrete;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_Quadcopter_Hinfinity_Discrete;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_Quadcopter_Hinfinity_Discrete;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_Quadcopter_Hinfinity_Discrete;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_Quadcopter_Hinfinity_Discrete;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c2_Quadcopter_Hinfinity_Discrete_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_Quadcopter_Hinfinity_Discrete(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_Quadcopter_Hinfinity_Discrete(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_Quadcopter_Hinfinity_Discrete(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_Quadcopter_Hinfinity_Discrete_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
