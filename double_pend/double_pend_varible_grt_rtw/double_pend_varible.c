/*
 * double_pend_varible.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "double_pend_varible".
 *
 * Model version              : 3.85
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Thu Jul 15 11:08:39 2021
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "double_pend_varible.h"
#include "double_pend_varible_private.h"

/* Block signals (default storage) */
B_double_pend_varible_T double_pend_varible_B;

/* Continuous states */
X_double_pend_varible_T double_pend_varible_X;

/* Block states (default storage) */
DW_double_pend_varible_T double_pend_varible_DW;

/* Real-time model */
static RT_MODEL_double_pend_varible_T double_pend_varible_M_;
RT_MODEL_double_pend_varible_T *const double_pend_varible_M =
  &double_pend_varible_M_;

/* Forward declaration for local functions */
static real_T double_pend_varible_xnrm2(int32_T n, const real_T x[32], int32_T
  ix0);
static void double_pend_varible_xgemv(int32_T m, int32_T n, const real_T A[32],
  int32_T ia0, const real_T x[32], int32_T ix0, real_T y[4]);
static void double_pend_varible_xgerc(int32_T m, int32_T n, real_T alpha1,
  int32_T ix0, const real_T y[4], real_T A[32], int32_T ia0);
static void double_pend_varible_qrFactor(const real_T A[16], real_T S[16], const
  real_T Ns[16]);
static void double_pend_varible_trisolve(const real_T A[16], real_T B[16]);
static void double_pend_varible_trisolve_e(const real_T A[16], real_T B[16]);
static void double_pend_varible_ppval(const real_T pp_breaks[5], const real_T
  pp_coefs[32], const real_T x[3], real_T v[6]);
static void double_pend_varib_cubicpolytraj(const real_T wayPoints[6], const
  real_T timePoints[3], const real_T t[3], const real_T varargin_2[6], real_T q
  [6], real_T qd[6], real_T qdd[6], real_T pp_breaks[5], real_T pp_coefs[32]);
static void double_pend_varible_ppval_i(const real_T pp_breaks[5], const real_T
  pp_coefs[32], real_T x, real_T v[2]);
static real_T double_pend_varible_xnrm2_n(const real_T x[4]);
static void double_pend_varible_xscal(real_T a, real_T x[4]);
static real_T double_pend_varible_xdotc(const real_T x[4], const real_T y[4]);
static void double_pend_varible_xaxpy(real_T a, real_T y[4]);
static void double_pend_varible_xscal_h(real_T a, real_T x[4], int32_T ix0);
static void double_pend_varible_xswap(real_T x[4], int32_T ix0, int32_T iy0);
static void double_pend_varible_xrotg(real_T *a, real_T *b, real_T *c, real_T *s);
static void double_pend_varible_xrot(real_T x[4], int32_T ix0, int32_T iy0,
  real_T c, real_T s);
static void double_pend_varible_svd(const real_T A[4], real_T U[4], real_T s[2],
  real_T V[4]);
static void double_pend_varible_pinv(const real_T A[4], real_T X[4]);
static real_T double_pend_varible_xnrm2_o(int32_T n, const real_T x[2], int32_T
  ix0);
static void double_pend_varible_qrpf(real_T A[2], int32_T ia0, int32_T m,
  int32_T n, real_T *tau, int32_T jpvt[2]);
static void double_pend_varible_xswap_n(real_T x[4]);
static void double_pend_varible_svd_i(const real_T A[4], real_T U[4], real_T s[2],
  real_T V[4]);

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 8;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  double_pend_varible_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  double_pend_varible_step();
  double_pend_varible_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  double_pend_varible_step();
  double_pend_varible_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/*
 * Output and update for atomic system:
 *    '<S4>/C'
 *    '<S31>/C'
 *    '<S11>/C'
 */
void double_pend_varible_C(const real_T rtu_m[2], const real_T rtu_l[2], const
  real_T rtu_q[2], const real_T rtu_qd[2], B_C_double_pend_varible_T *localB)
{
  real_T y_tmp;
  y_tmp = sin(rtu_q[0] - rtu_q[1]);
  localB->y[0] = rtu_m[1] * rtu_l[1] * rtu_qd[1] * rtu_qd[1] * y_tmp;
  localB->y[1] = -rtu_m[1] * rtu_l[0] * rtu_qd[0] * rtu_qd[0] * y_tmp;
}

/*
 * Output and update for atomic system:
 *    '<S5>/MATLAB Function'
 *    '<S6>/MATLAB Function'
 */
void double_pend_vari_MATLABFunction(const real_T rtu_q[2], const real_T rtu_l[2],
  B_MATLABFunction_double_pend__T *localB)
{
  localB->y[0] = rtu_l[0] * cos(rtu_q[0]);
  localB->y[2] = 0.0;
  localB->y[1] = rtu_l[0] * sin(rtu_q[0]);
  localB->y[3] = 0.0;
}

/*
 * Output and update for atomic system:
 *    '<S5>/MATLAB Function1'
 *    '<S6>/MATLAB Function1'
 */
void double_pend_var_MATLABFunction1(const real_T rtu_q[2], const real_T rtu_l[2],
  B_MATLABFunction1_double_pend_T *localB)
{
  localB->y[0] = rtu_l[0] * cos(rtu_q[0]);
  localB->y[2] = rtu_l[1] * cos(rtu_q[1]);
  localB->y[1] = rtu_l[0] * sin(rtu_q[0]);
  localB->y[3] = rtu_l[1] * sin(rtu_q[1]);
}

/*
 * Output and update for atomic system:
 *    '<S31>/G'
 *    '<S11>/G'
 */
void double_pend_varible_G(const real_T rtu_m[2], const real_T rtu_q[2],
  B_G_double_pend_varible_T *localB)
{
  localB->y[0] = (rtu_m[0] + rtu_m[1]) * 9.81 * sin(rtu_q[0]);
  localB->y[1] = rtu_m[1] * 9.81 * sin(rtu_q[1]);
}

/*
 * Output and update for atomic system:
 *    '<S31>/M'
 *    '<S11>/M1'
 */
void double_pend_varible_M_l(const real_T rtu_m[2], const real_T rtu_l[2], const
  real_T rtu_q[2], B_M_double_pend_varible_T *localB)
{
  real_T y_tmp;
  real_T y_tmp_0;
  y_tmp = cos(rtu_q[0] - rtu_q[1]);
  localB->y[0] = (rtu_m[0] + rtu_m[1]) * rtu_l[0];
  y_tmp_0 = rtu_m[1] * rtu_l[1];
  localB->y[2] = y_tmp_0 * y_tmp;
  localB->y[1] = rtu_l[0] * rtu_m[1] * y_tmp;
  localB->y[3] = y_tmp_0;
}

/* Function for MATLAB Function: '<S17>/Correct' */
static real_T double_pend_varible_xnrm2(int32_T n, const real_T x[32], int32_T
  ix0)
{
  real_T absxk;
  real_T scale;
  real_T t;
  real_T y;
  int32_T k;
  int32_T kend;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x[ix0 - 1]);
    } else {
      scale = 3.3121686421112381E-170;
      kend = (ix0 + n) - 1;
      for (k = ix0; k <= kend; k++) {
        absxk = fabs(x[k - 1]);
        if (absxk > scale) {
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          t = absxk / scale;
          y += t * t;
        }
      }

      y = scale * sqrt(y);
    }
  }

  return y;
}

real_T rt_hypotd_snf(real_T u0, real_T u1)
{
  real_T a;
  real_T y;
  a = fabs(u0);
  y = fabs(u1);
  if (a < y) {
    a /= y;
    y *= sqrt(a * a + 1.0);
  } else if (a > y) {
    y /= a;
    y = sqrt(y * y + 1.0) * a;
  } else if (!rtIsNaN(y)) {
    y = a * 1.4142135623730951;
  }

  return y;
}

/* Function for MATLAB Function: '<S17>/Correct' */
static void double_pend_varible_xgemv(int32_T m, int32_T n, const real_T A[32],
  int32_T ia0, const real_T x[32], int32_T ix0, real_T y[4])
{
  real_T c;
  int32_T b;
  int32_T b_iy;
  int32_T d;
  int32_T ia;
  int32_T iac;
  int32_T ix;
  if ((m != 0) && (n != 0)) {
    for (b_iy = 0; b_iy < n; b_iy++) {
      y[b_iy] = 0.0;
    }

    b_iy = 0;
    b = ((n - 1) << 3) + ia0;
    for (iac = ia0; iac <= b; iac += 8) {
      ix = ix0;
      c = 0.0;
      d = (iac + m) - 1;
      for (ia = iac; ia <= d; ia++) {
        c += A[ia - 1] * x[ix - 1];
        ix++;
      }

      y[b_iy] += c;
      b_iy++;
    }
  }
}

/* Function for MATLAB Function: '<S17>/Correct' */
static void double_pend_varible_xgerc(int32_T m, int32_T n, real_T alpha1,
  int32_T ix0, const real_T y[4], real_T A[32], int32_T ia0)
{
  real_T temp;
  int32_T b;
  int32_T ijA;
  int32_T ix;
  int32_T j;
  int32_T jA;
  int32_T jy;
  if (!(alpha1 == 0.0)) {
    jA = ia0 - 1;
    jy = 0;
    for (j = 0; j < n; j++) {
      if (y[jy] != 0.0) {
        temp = y[jy] * alpha1;
        ix = ix0;
        b = m + jA;
        for (ijA = jA; ijA < b; ijA++) {
          A[ijA] += A[ix - 1] * temp;
          ix++;
        }
      }

      jy++;
      jA += 8;
    }
  }
}

/* Function for MATLAB Function: '<S17>/Correct' */
static void double_pend_varible_qrFactor(const real_T A[16], real_T S[16], const
  real_T Ns[16])
{
  real_T b_A[32];
  real_T y[16];
  real_T work[4];
  real_T beta1;
  real_T s;
  real_T tau_idx_0;
  int32_T aoffset;
  int32_T coffset;
  int32_T exitg1;
  int32_T ii;
  int32_T knt;
  boolean_T exitg2;
  for (knt = 0; knt < 4; knt++) {
    coffset = knt << 2;
    for (ii = 0; ii < 4; ii++) {
      aoffset = ii << 2;
      y[coffset + ii] = ((S[aoffset + 1] * A[knt + 4] + S[aoffset] * A[knt]) +
                         S[aoffset + 2] * A[knt + 8]) + S[aoffset + 3] * A[knt +
        12];
    }
  }

  for (coffset = 0; coffset < 4; coffset++) {
    aoffset = coffset << 3;
    knt = coffset << 2;
    b_A[aoffset] = y[knt];
    b_A[aoffset + 4] = Ns[coffset];
    b_A[aoffset + 1] = y[knt + 1];
    b_A[aoffset + 5] = Ns[coffset + 4];
    b_A[aoffset + 2] = y[knt + 2];
    b_A[aoffset + 6] = Ns[coffset + 8];
    b_A[aoffset + 3] = y[knt + 3];
    b_A[aoffset + 7] = Ns[coffset + 12];
    work[coffset] = 0.0;
  }

  s = b_A[0];
  tau_idx_0 = 0.0;
  beta1 = double_pend_varible_xnrm2(7, b_A, 2);
  if (beta1 != 0.0) {
    beta1 = rt_hypotd_snf(b_A[0], beta1);
    if (b_A[0] >= 0.0) {
      beta1 = -beta1;
    }

    if (fabs(beta1) < 1.0020841800044864E-292) {
      knt = -1;
      coffset = 0;
      do {
        knt++;
        for (aoffset = 1; aoffset < 8; aoffset++) {
          b_A[aoffset] *= 9.9792015476736E+291;
        }

        beta1 *= 9.9792015476736E+291;
        s *= 9.9792015476736E+291;
      } while (!(fabs(beta1) >= 1.0020841800044864E-292));

      beta1 = rt_hypotd_snf(s, double_pend_varible_xnrm2(7, b_A, 2));
      if (s >= 0.0) {
        beta1 = -beta1;
      }

      tau_idx_0 = (beta1 - s) / beta1;
      s = 1.0 / (s - beta1);
      for (aoffset = 1; aoffset < 8; aoffset++) {
        b_A[aoffset] *= s;
      }

      while (coffset <= knt) {
        beta1 *= 1.0020841800044864E-292;
        coffset++;
      }

      s = beta1;
    } else {
      tau_idx_0 = (beta1 - b_A[0]) / beta1;
      s = 1.0 / (b_A[0] - beta1);
      for (coffset = 1; coffset < 8; coffset++) {
        b_A[coffset] *= s;
      }

      s = beta1;
    }
  }

  b_A[0] = 1.0;
  if (tau_idx_0 != 0.0) {
    knt = 8;
    coffset = 0;
    while ((knt > 0) && (b_A[coffset + 7] == 0.0)) {
      knt--;
      coffset--;
    }

    coffset = 3;
    exitg2 = false;
    while ((!exitg2) && (coffset > 0)) {
      aoffset = ((coffset - 1) << 3) + 8;
      ii = aoffset;
      do {
        exitg1 = 0;
        if (ii + 1 <= aoffset + knt) {
          if (b_A[ii] != 0.0) {
            exitg1 = 1;
          } else {
            ii++;
          }
        } else {
          coffset--;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }
  } else {
    knt = 0;
    coffset = 0;
  }

  if (knt > 0) {
    double_pend_varible_xgemv(knt, coffset, b_A, 9, b_A, 1, work);
    double_pend_varible_xgerc(knt, coffset, -tau_idx_0, 1, work, b_A, 9);
  }

  b_A[0] = s;
  s = b_A[9];
  tau_idx_0 = 0.0;
  beta1 = double_pend_varible_xnrm2(6, b_A, 11);
  if (beta1 != 0.0) {
    beta1 = rt_hypotd_snf(b_A[9], beta1);
    if (b_A[9] >= 0.0) {
      beta1 = -beta1;
    }

    if (fabs(beta1) < 1.0020841800044864E-292) {
      knt = -1;
      do {
        knt++;
        for (aoffset = 10; aoffset < 16; aoffset++) {
          b_A[aoffset] *= 9.9792015476736E+291;
        }

        beta1 *= 9.9792015476736E+291;
        s *= 9.9792015476736E+291;
      } while (!(fabs(beta1) >= 1.0020841800044864E-292));

      beta1 = rt_hypotd_snf(s, double_pend_varible_xnrm2(6, b_A, 11));
      if (s >= 0.0) {
        beta1 = -beta1;
      }

      tau_idx_0 = (beta1 - s) / beta1;
      s = 1.0 / (s - beta1);
      for (aoffset = 10; aoffset < 16; aoffset++) {
        b_A[aoffset] *= s;
      }

      for (coffset = 0; coffset <= knt; coffset++) {
        beta1 *= 1.0020841800044864E-292;
      }

      s = beta1;
    } else {
      tau_idx_0 = (beta1 - b_A[9]) / beta1;
      s = 1.0 / (b_A[9] - beta1);
      for (coffset = 10; coffset < 16; coffset++) {
        b_A[coffset] *= s;
      }

      s = beta1;
    }
  }

  b_A[9] = 1.0;
  if (tau_idx_0 != 0.0) {
    knt = 7;
    coffset = 8;
    while ((knt > 0) && (b_A[coffset + 7] == 0.0)) {
      knt--;
      coffset--;
    }

    coffset = 2;
    exitg2 = false;
    while ((!exitg2) && (coffset > 0)) {
      aoffset = ((coffset - 1) << 3) + 17;
      ii = aoffset;
      do {
        exitg1 = 0;
        if (ii + 1 <= aoffset + knt) {
          if (b_A[ii] != 0.0) {
            exitg1 = 1;
          } else {
            ii++;
          }
        } else {
          coffset--;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }
  } else {
    knt = 0;
    coffset = 0;
  }

  if (knt > 0) {
    double_pend_varible_xgemv(knt, coffset, b_A, 18, b_A, 10, work);
    double_pend_varible_xgerc(knt, coffset, -tau_idx_0, 10, work, b_A, 18);
  }

  b_A[9] = s;
  s = b_A[18];
  tau_idx_0 = 0.0;
  beta1 = double_pend_varible_xnrm2(5, b_A, 20);
  if (beta1 != 0.0) {
    beta1 = rt_hypotd_snf(b_A[18], beta1);
    if (b_A[18] >= 0.0) {
      beta1 = -beta1;
    }

    if (fabs(beta1) < 1.0020841800044864E-292) {
      knt = -1;
      do {
        knt++;
        for (aoffset = 19; aoffset < 24; aoffset++) {
          b_A[aoffset] *= 9.9792015476736E+291;
        }

        beta1 *= 9.9792015476736E+291;
        s *= 9.9792015476736E+291;
      } while (!(fabs(beta1) >= 1.0020841800044864E-292));

      beta1 = rt_hypotd_snf(s, double_pend_varible_xnrm2(5, b_A, 20));
      if (s >= 0.0) {
        beta1 = -beta1;
      }

      tau_idx_0 = (beta1 - s) / beta1;
      s = 1.0 / (s - beta1);
      for (aoffset = 19; aoffset < 24; aoffset++) {
        b_A[aoffset] *= s;
      }

      for (coffset = 0; coffset <= knt; coffset++) {
        beta1 *= 1.0020841800044864E-292;
      }

      s = beta1;
    } else {
      tau_idx_0 = (beta1 - b_A[18]) / beta1;
      s = 1.0 / (b_A[18] - beta1);
      for (coffset = 19; coffset < 24; coffset++) {
        b_A[coffset] *= s;
      }

      s = beta1;
    }
  }

  b_A[18] = 1.0;
  if (tau_idx_0 != 0.0) {
    knt = 6;
    coffset = 16;
    while ((knt > 0) && (b_A[coffset + 7] == 0.0)) {
      knt--;
      coffset--;
    }

    coffset = 1;
    ii = 26;
    do {
      exitg1 = 0;
      if (ii + 1 <= 26 + knt) {
        if (b_A[ii] != 0.0) {
          exitg1 = 1;
        } else {
          ii++;
        }
      } else {
        coffset = 0;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  } else {
    knt = 0;
    coffset = 0;
  }

  if (knt > 0) {
    double_pend_varible_xgemv(knt, coffset, b_A, 27, b_A, 19, work);
    double_pend_varible_xgerc(knt, coffset, -tau_idx_0, 19, work, b_A, 27);
  }

  b_A[18] = s;
  s = b_A[27];
  beta1 = double_pend_varible_xnrm2(4, b_A, 29);
  if (beta1 != 0.0) {
    beta1 = rt_hypotd_snf(b_A[27], beta1);
    if (b_A[27] >= 0.0) {
      beta1 = -beta1;
    }

    if (fabs(beta1) < 1.0020841800044864E-292) {
      knt = -1;
      do {
        knt++;
        for (aoffset = 28; aoffset < 32; aoffset++) {
          b_A[aoffset] *= 9.9792015476736E+291;
        }

        beta1 *= 9.9792015476736E+291;
        s *= 9.9792015476736E+291;
      } while (!(fabs(beta1) >= 1.0020841800044864E-292));

      beta1 = rt_hypotd_snf(s, double_pend_varible_xnrm2(4, b_A, 29));
      if (s >= 0.0) {
        beta1 = -beta1;
      }

      s = 1.0 / (s - beta1);
      for (aoffset = 28; aoffset < 32; aoffset++) {
        b_A[aoffset] *= s;
      }

      for (coffset = 0; coffset <= knt; coffset++) {
        beta1 *= 1.0020841800044864E-292;
      }

      s = beta1;
    } else {
      s = 1.0 / (b_A[27] - beta1);
      for (coffset = 28; coffset < 32; coffset++) {
        b_A[coffset] *= s;
      }

      s = beta1;
    }
  }

  b_A[27] = s;
  y[0] = b_A[0];
  for (ii = 1; ii + 1 < 5; ii++) {
    y[ii] = 0.0;
  }

  for (ii = 0; ii < 2; ii++) {
    y[ii + 4] = b_A[ii + 8];
  }

  while (ii + 1 < 5) {
    y[ii + 4] = 0.0;
    ii++;
  }

  for (ii = 0; ii < 3; ii++) {
    y[ii + 8] = b_A[ii + 16];
  }

  while (ii + 1 < 5) {
    y[ii + 8] = 0.0;
    ii++;
  }

  for (ii = 0; ii < 4; ii++) {
    y[ii + 12] = b_A[ii + 24];
  }

  for (coffset = 0; coffset < 4; coffset++) {
    aoffset = coffset << 2;
    S[aoffset] = y[coffset];
    S[aoffset + 1] = y[coffset + 4];
    S[aoffset + 2] = y[coffset + 8];
    S[aoffset + 3] = y[coffset + 12];
  }
}

/* Function for MATLAB Function: '<S17>/Correct' */
static void double_pend_varible_trisolve(const real_T A[16], real_T B[16])
{
  real_T tmp;
  int32_T i;
  int32_T j;
  int32_T jBcol;
  int32_T tmp_0;
  for (j = 0; j < 4; j++) {
    jBcol = j << 2;
    if (B[jBcol] != 0.0) {
      B[jBcol] /= A[0];
      for (i = 2; i < 5; i++) {
        tmp_0 = (i + jBcol) - 1;
        B[tmp_0] -= A[i - 1] * B[jBcol];
      }
    }

    tmp = B[jBcol + 1];
    if (tmp != 0.0) {
      B[jBcol + 1] = tmp / A[5];
      for (i = 3; i < 5; i++) {
        tmp_0 = (i + jBcol) - 1;
        B[tmp_0] -= B[jBcol + 1] * A[i + 3];
      }
    }

    tmp = B[jBcol + 2];
    if (tmp != 0.0) {
      B[jBcol + 2] = tmp / A[10];
      B[jBcol + 3] -= B[jBcol + 2] * A[11];
    }

    if (B[jBcol + 3] != 0.0) {
      B[jBcol + 3] /= A[15];
    }
  }
}

/* Function for MATLAB Function: '<S17>/Correct' */
static void double_pend_varible_trisolve_e(const real_T A[16], real_T B[16])
{
  real_T tmp;
  int32_T i;
  int32_T j;
  int32_T jBcol;
  int32_T tmp_0;
  for (j = 0; j < 4; j++) {
    jBcol = j << 2;
    tmp = B[jBcol + 3];
    if (tmp != 0.0) {
      B[jBcol + 3] = tmp / A[15];
      for (i = 0; i < 3; i++) {
        tmp_0 = i + jBcol;
        B[tmp_0] -= B[jBcol + 3] * A[i + 12];
      }
    }

    tmp = B[jBcol + 2];
    if (tmp != 0.0) {
      B[jBcol + 2] = tmp / A[10];
      for (i = 0; i < 2; i++) {
        tmp_0 = i + jBcol;
        B[tmp_0] -= B[jBcol + 2] * A[i + 8];
      }
    }

    tmp = B[jBcol + 1];
    if (tmp != 0.0) {
      B[jBcol + 1] = tmp / A[5];
      B[jBcol] -= B[jBcol + 1] * A[4];
    }

    if (B[jBcol] != 0.0) {
      B[jBcol] /= A[0];
    }
  }
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T tmp;
  real_T tmp_0;
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

static void double_pend_varible_ppval(const real_T pp_breaks[5], const real_T
  pp_coefs[32], const real_T x[3], real_T v[6])
{
  real_T xloc;
  int32_T b_ix;
  int32_T high_i;
  int32_T iv0;
  int32_T low_i;
  int32_T low_ip1;
  int32_T mid_i;
  for (b_ix = 0; b_ix < 3; b_ix++) {
    iv0 = (b_ix << 1) - 1;
    if (rtIsNaN(x[b_ix])) {
      v[iv0 + 1] = x[b_ix];
      v[iv0 + 2] = x[b_ix];
    } else {
      low_i = 0;
      low_ip1 = 1;
      high_i = 5;
      while (high_i > low_ip1 + 1) {
        mid_i = ((low_i + high_i) + 1) >> 1;
        if (x[b_ix] >= pp_breaks[mid_i - 1]) {
          low_i = mid_i - 1;
          low_ip1 = mid_i;
        } else {
          high_i = mid_i;
        }
      }

      low_ip1 = low_i << 1;
      xloc = x[b_ix] - pp_breaks[low_i];
      v[iv0 + 1] = pp_coefs[low_ip1];
      v[iv0 + 2] = pp_coefs[low_ip1 + 1];
      for (low_i = 0; low_i < 3; low_i++) {
        high_i = (((low_i + 1) << 3) + low_ip1) - 1;
        v[iv0 + 1] = v[iv0 + 1] * xloc + pp_coefs[high_i + 1];
        v[iv0 + 2] = v[iv0 + 2] * xloc + pp_coefs[high_i + 2];
      }
    }
  }
}

static void double_pend_varib_cubicpolytraj(const real_T wayPoints[6], const
  real_T timePoints[3], const real_T t[3], const real_T varargin_2[6], real_T q
  [6], real_T qd[6], real_T qdd[6], real_T pp_breaks[5], real_T pp_coefs[32])
{
  real_T dCoeffs[32];
  real_T ddCoeffs[32];
  real_T coefsWithFlatStart[24];
  real_T coefMat[16];
  real_T coeffMat[8];
  real_T derivativeBreaks[5];
  real_T b_coeffVec[4];
  real_T evalPointVector_idx_0;
  real_T evalPointVector_idx_1;
  real_T evalPointVector_idx_2;
  real_T finalTime;
  int32_T b_coeffVec_tmp;
  int32_T b_j;
  int32_T idx;
  int32_T ii_data;
  boolean_T x[3];
  boolean_T exitg1;
  memset(&coefMat[0], 0, sizeof(real_T) << 4U);
  for (idx = 0; idx < 2; idx++) {
    finalTime = timePoints[idx + 1] - timePoints[idx];
    for (b_j = 0; b_j < 2; b_j++) {
      b_coeffVec_tmp = (idx << 1) + b_j;
      b_coeffVec[0] = wayPoints[b_coeffVec_tmp];
      b_coeffVec[1] = varargin_2[b_coeffVec_tmp];
      b_coeffVec_tmp = ((idx + 1) << 1) + b_j;
      evalPointVector_idx_0 = wayPoints[b_coeffVec_tmp] - (finalTime *
        b_coeffVec[1] + b_coeffVec[0]);
      evalPointVector_idx_1 = varargin_2[b_coeffVec_tmp] - (0.0 * b_coeffVec[0]
        + b_coeffVec[1]);
      b_coeffVec[3] = b_coeffVec[0];
      b_coeffVec_tmp = ((idx << 1) + b_j) + 1;
      evalPointVector_idx_2 = finalTime * finalTime;
      coefMat[b_coeffVec_tmp - 1] = 1.0 / evalPointVector_idx_2 *
        evalPointVector_idx_1 + -2.0 / rt_powd_snf(finalTime, 3.0) *
        evalPointVector_idx_0;
      coefMat[b_coeffVec_tmp + 3] = 3.0 / evalPointVector_idx_2 *
        evalPointVector_idx_0 + -1.0 / finalTime * evalPointVector_idx_1;
      coefMat[b_coeffVec_tmp + 7] = b_coeffVec[1];
      coefMat[b_coeffVec_tmp + 11] = b_coeffVec[3];
    }
  }

  memset(&coeffMat[0], 0, sizeof(real_T) << 3U);
  for (b_j = 0; b_j < 2; b_j++) {
    coeffMat[b_j + 6] = 0.0;
    coeffMat[b_j + 6] += coefMat[b_j] * 0.0;
    coeffMat[b_j + 6] += coefMat[b_j + 4] * 0.0;
    coeffMat[b_j + 6] += coefMat[b_j + 8] * 0.0;
    coeffMat[b_j + 6] += coefMat[b_j + 12];
  }

  for (b_j = 0; b_j < 4; b_j++) {
    idx = b_j << 1;
    coefsWithFlatStart[6 * b_j] = coeffMat[idx];
    coefsWithFlatStart[6 * b_j + 1] = coeffMat[idx + 1];
    idx = b_j << 2;
    coefsWithFlatStart[6 * b_j + 2] = coefMat[idx];
    coefsWithFlatStart[6 * b_j + 3] = coefMat[idx + 1];
    coefsWithFlatStart[6 * b_j + 4] = coefMat[idx + 2];
    coefsWithFlatStart[6 * b_j + 5] = coefMat[idx + 3];
  }

  b_coeffVec[0] = timePoints[0] - 1.0;
  b_coeffVec[1] = timePoints[0];
  b_coeffVec[2] = timePoints[1];
  b_coeffVec[3] = timePoints[2];
  finalTime = timePoints[2] - timePoints[1];
  evalPointVector_idx_0 = rt_powd_snf(finalTime, 3.0);
  evalPointVector_idx_1 = rt_powd_snf(finalTime, 2.0);
  evalPointVector_idx_2 = rt_powd_snf(finalTime, 1.0);
  finalTime = rt_powd_snf(finalTime, 0.0);
  memset(&coeffMat[0], 0, sizeof(real_T) << 3U);
  for (b_j = 0; b_j < 2; b_j++) {
    coeffMat[b_j + 6] = 0.0;
    coeffMat[b_j + 6] += coefsWithFlatStart[b_j + 4] * evalPointVector_idx_0;
    coeffMat[b_j + 6] += coefsWithFlatStart[b_j + 10] * evalPointVector_idx_1;
    coeffMat[b_j + 6] += coefsWithFlatStart[b_j + 16] * evalPointVector_idx_2;
    coeffMat[b_j + 6] += coefsWithFlatStart[b_j + 22] * finalTime;
  }

  memset(&pp_coefs[0], 0, sizeof(real_T) << 5U);
  for (b_j = 0; b_j < 4; b_j++) {
    for (idx = 0; idx < 6; idx++) {
      pp_coefs[((idx + 1) + (b_j << 3)) - 1] = coefsWithFlatStart[6 * b_j + idx];
    }

    idx = b_j << 1;
    b_coeffVec_tmp = b_j << 3;
    pp_coefs[b_coeffVec_tmp + 6] = coeffMat[idx];
    pp_coefs[b_coeffVec_tmp + 7] = coeffMat[idx + 1];
    pp_breaks[b_j] = b_coeffVec[b_j];
  }

  pp_breaks[4] = timePoints[2] + 1.0;
  double_pend_varible_ppval(pp_breaks, pp_coefs, t, q);
  for (b_j = 0; b_j < 5; b_j++) {
    derivativeBreaks[b_j] = pp_breaks[b_j];
  }

  finalTime = 0.01;
  x[0] = (t[0] > pp_breaks[3]);
  x[1] = (t[1] > pp_breaks[3]);
  x[2] = (t[2] > pp_breaks[3]);
  idx = 0;
  b_coeffVec_tmp = 1;
  b_j = 1;
  exitg1 = false;
  while ((!exitg1) && (b_j - 1 < 3)) {
    if (x[b_j - 1]) {
      idx = 1;
      ii_data = b_j;
      exitg1 = true;
    } else {
      b_j++;
    }
  }

  if (idx == 0) {
    b_coeffVec_tmp = 0;
  }

  if (b_coeffVec_tmp != 0) {
    finalTime = fmin((t[ii_data - 1] - pp_breaks[3]) / 2.0, 0.01);
  }

  derivativeBreaks[3] = pp_breaks[3] + finalTime;
  memset(&dCoeffs[0], 0, sizeof(real_T) << 5U);
  for (idx = 0; idx < 3; idx++) {
    for (b_j = 0; b_j < 8; b_j++) {
      dCoeffs[b_j + ((idx + 1) << 3)] = pp_coefs[(idx << 3) + b_j] * (real_T)(3
        - idx);
    }
  }

  double_pend_varible_ppval(derivativeBreaks, dCoeffs, t, qd);
  memset(&ddCoeffs[0], 0, sizeof(real_T) << 5U);
  for (idx = 0; idx < 3; idx++) {
    for (b_j = 0; b_j < 8; b_j++) {
      ddCoeffs[b_j + ((idx + 1) << 3)] = dCoeffs[(idx << 3) + b_j] * (real_T)(3
        - idx);
    }
  }

  double_pend_varible_ppval(derivativeBreaks, ddCoeffs, t, qdd);
}

static void double_pend_varible_ppval_i(const real_T pp_breaks[5], const real_T
  pp_coefs[32], real_T x, real_T v[2])
{
  real_T xloc;
  int32_T high_i;
  int32_T ic0;
  int32_T low_i;
  int32_T low_ip1;
  if (rtIsNaN(x)) {
    v[0] = x;
    v[1] = x;
  } else {
    low_i = 0;
    low_ip1 = 1;
    high_i = 5;
    while (high_i > low_ip1 + 1) {
      ic0 = ((low_i + high_i) + 1) >> 1;
      if (x >= pp_breaks[ic0 - 1]) {
        low_i = ic0 - 1;
        low_ip1 = ic0;
      } else {
        high_i = ic0;
      }
    }

    low_ip1 = low_i << 1;
    xloc = x - pp_breaks[low_i];
    v[0] = pp_coefs[low_ip1];
    v[1] = pp_coefs[low_ip1 + 1];
    for (high_i = 0; high_i < 3; high_i++) {
      ic0 = (((high_i + 1) << 3) + low_ip1) - 1;
      v[0] = xloc * v[0] + pp_coefs[ic0 + 1];
      v[1] = xloc * v[1] + pp_coefs[ic0 + 2];
    }
  }
}

/* Function for MATLAB Function: '<S19>/Predict' */
static real_T double_pend_varible_xnrm2_n(const real_T x[4])
{
  real_T absxk;
  real_T scale;
  real_T t;
  real_T y;
  scale = 3.3121686421112381E-170;
  absxk = fabs(x[0]);
  if (absxk > 3.3121686421112381E-170) {
    y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    y = t * t;
  }

  absxk = fabs(x[1]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  return scale * sqrt(y);
}

/* Function for MATLAB Function: '<S19>/Predict' */
static void double_pend_varible_xscal(real_T a, real_T x[4])
{
  x[0] *= a;
  x[1] *= a;
}

/* Function for MATLAB Function: '<S19>/Predict' */
static real_T double_pend_varible_xdotc(const real_T x[4], const real_T y[4])
{
  return x[0] * y[2] + x[1] * y[3];
}

/* Function for MATLAB Function: '<S19>/Predict' */
static void double_pend_varible_xaxpy(real_T a, real_T y[4])
{
  if (!(a == 0.0)) {
    y[2] += a * y[0];
    y[3] += a * y[1];
  }
}

/* Function for MATLAB Function: '<S19>/Predict' */
static void double_pend_varible_xscal_h(real_T a, real_T x[4], int32_T ix0)
{
  int32_T k;
  for (k = ix0; k <= ix0 + 1; k++) {
    x[k - 1] *= a;
  }
}

/* Function for MATLAB Function: '<S19>/Predict' */
static void double_pend_varible_xswap(real_T x[4], int32_T ix0, int32_T iy0)
{
  real_T temp;
  temp = x[ix0 - 1];
  x[ix0 - 1] = x[iy0 - 1];
  x[iy0 - 1] = temp;
  temp = x[ix0];
  x[ix0] = x[iy0];
  x[iy0] = temp;
}

/* Function for MATLAB Function: '<S19>/Predict' */
static void double_pend_varible_xrotg(real_T *a, real_T *b, real_T *c, real_T *s)
{
  real_T absa;
  real_T absb;
  real_T ads;
  real_T bds;
  real_T roe;
  real_T scale;
  roe = *b;
  absa = fabs(*a);
  absb = fabs(*b);
  if (absa > absb) {
    roe = *a;
  }

  scale = absa + absb;
  if (scale == 0.0) {
    *s = 0.0;
    *c = 1.0;
    *b = 0.0;
  } else {
    ads = absa / scale;
    bds = absb / scale;
    scale *= sqrt(ads * ads + bds * bds);
    if (roe < 0.0) {
      scale = -scale;
    }

    *c = *a / scale;
    *s = *b / scale;
    if (absa > absb) {
      *b = *s;
    } else if (*c != 0.0) {
      *b = 1.0 / *c;
    } else {
      *b = 1.0;
    }
  }

  *a = scale;
}

/* Function for MATLAB Function: '<S19>/Predict' */
static void double_pend_varible_xrot(real_T x[4], int32_T ix0, int32_T iy0,
  real_T c, real_T s)
{
  real_T temp;
  real_T temp_tmp;
  temp = x[iy0 - 1];
  temp_tmp = x[ix0 - 1];
  x[iy0 - 1] = temp * c - temp_tmp * s;
  x[ix0 - 1] = temp_tmp * c + temp * s;
  temp = x[ix0] * c + x[iy0] * s;
  x[iy0] = x[iy0] * c - x[ix0] * s;
  x[ix0] = temp;
}

/* Function for MATLAB Function: '<S19>/Predict' */
static void double_pend_varible_svd(const real_T A[4], real_T U[4], real_T s[2],
  real_T V[4])
{
  real_T Vf[4];
  real_T b_A[4];
  real_T b_s[2];
  real_T e[2];
  real_T emm1;
  real_T nrm;
  real_T rt;
  real_T shift;
  real_T smm1;
  real_T sqds;
  real_T ztest;
  int32_T iter;
  int32_T kase;
  int32_T m;
  int32_T q;
  int32_T qs;
  boolean_T exitg1;
  b_A[0] = A[0];
  b_A[1] = A[1];
  b_A[2] = A[2];
  b_A[3] = A[3];
  nrm = double_pend_varible_xnrm2_n(A);
  if (nrm > 0.0) {
    if (A[0] < 0.0) {
      nrm = -nrm;
    }

    if (fabs(nrm) >= 1.0020841800044864E-292) {
      double_pend_varible_xscal(1.0 / nrm, b_A);
    } else {
      b_A[0] = A[0] / nrm;
      b_A[1] = A[1] / nrm;
    }

    b_A[0]++;
    b_s[0] = -nrm;
    double_pend_varible_xaxpy(-(double_pend_varible_xdotc(b_A, b_A) / b_A[0]),
      b_A);
  } else {
    b_s[0] = 0.0;
  }

  b_s[1] = b_A[3];
  e[1] = 0.0;
  U[0] = b_A[0];
  U[2] = 0.0;
  U[1] = b_A[1];
  m = 0;
  U[3] = 1.0;
  if (b_s[0] != 0.0) {
    double_pend_varible_xaxpy(-(double_pend_varible_xdotc(U, U) / b_A[0]), U);
    U[1] = -U[1];
    U[0] = -U[0] + 1.0;
  } else {
    U[1] = 0.0;
    U[0] = 1.0;
  }

  Vf[2] = 0.0;
  Vf[3] = 1.0;
  Vf[1] = 0.0;
  Vf[0] = 1.0;
  ztest = b_A[2];
  if (b_s[0] != 0.0) {
    rt = fabs(b_s[0]);
    nrm = b_s[0] / rt;
    b_s[0] = rt;
    ztest = b_A[2] / nrm;
    double_pend_varible_xscal_h(nrm, U, 1);
  }

  if (ztest != 0.0) {
    rt = fabs(ztest);
    nrm = rt / ztest;
    ztest = rt;
    b_s[1] = b_A[3] * nrm;
    double_pend_varible_xscal_h(nrm, Vf, 3);
  }

  if (b_s[1] != 0.0) {
    rt = fabs(b_s[1]);
    nrm = b_s[1] / rt;
    b_s[1] = rt;
    double_pend_varible_xscal_h(nrm, U, 3);
  }

  e[0] = ztest;
  iter = 0;
  nrm = fmax(fmax(b_s[0], ztest), fmax(b_s[1], 0.0));
  while ((m + 2 > 0) && (iter < 75)) {
    q = m + 1;
    exitg1 = false;
    while (!(exitg1 || (q == 0))) {
      rt = fabs(e[0]);
      if ((rt <= (fabs(b_s[0]) + fabs(b_s[1])) * 2.2204460492503131E-16) || ((rt
            <= 1.0020841800044864E-292) || ((iter > 20) && (rt <=
             2.2204460492503131E-16 * nrm)))) {
        e[0] = 0.0;
        exitg1 = true;
      } else {
        q = 0;
      }
    }

    if (m + 1 == q) {
      kase = 4;
    } else {
      qs = m + 2;
      kase = m + 2;
      exitg1 = false;
      while ((!exitg1) && (kase >= q)) {
        qs = kase;
        if (kase == q) {
          exitg1 = true;
        } else {
          rt = 0.0;
          if (kase < m + 2) {
            rt = fabs(e[kase - 1]);
          }

          if (kase > q + 1) {
            rt += fabs(e[0]);
          }

          ztest = fabs(b_s[kase - 1]);
          if ((ztest <= 2.2204460492503131E-16 * rt) || (ztest <=
               1.0020841800044864E-292)) {
            b_s[kase - 1] = 0.0;
            exitg1 = true;
          } else {
            kase--;
          }
        }
      }

      if (qs == q) {
        kase = 3;
      } else if (m + 2 == qs) {
        kase = 1;
      } else {
        kase = 2;
        q = qs;
      }
    }

    switch (kase) {
     case 1:
      rt = e[m];
      e[m] = 0.0;
      qs = m + 1;
      while (qs >= q + 1) {
        double_pend_varible_xrotg(&b_s[0], &rt, &ztest, &sqds);
        double_pend_varible_xrot(Vf, 1, ((m + 1) << 1) + 1, ztest, sqds);
        qs = 0;
      }
      break;

     case 2:
      rt = e[q - 1];
      e[q - 1] = 0.0;
      for (qs = q; qs < m + 2; qs++) {
        double_pend_varible_xrotg(&b_s[qs], &rt, &ztest, &sqds);
        rt = -sqds * e[qs];
        e[qs] *= ztest;
        double_pend_varible_xrot(U, (qs << 1) + 1, ((q - 1) << 1) + 1, ztest,
          sqds);
      }
      break;

     case 3:
      rt = b_s[m + 1];
      ztest = fmax(fmax(fmax(fmax(fabs(rt), fabs(b_s[m])), fabs(e[m])), fabs
                        (b_s[q])), fabs(e[q]));
      rt /= ztest;
      smm1 = b_s[m] / ztest;
      emm1 = e[m] / ztest;
      sqds = b_s[q] / ztest;
      smm1 = ((smm1 + rt) * (smm1 - rt) + emm1 * emm1) / 2.0;
      emm1 *= rt;
      emm1 *= emm1;
      if ((smm1 != 0.0) || (emm1 != 0.0)) {
        shift = sqrt(smm1 * smm1 + emm1);
        if (smm1 < 0.0) {
          shift = -shift;
        }

        shift = emm1 / (smm1 + shift);
      } else {
        shift = 0.0;
      }

      rt = (sqds + rt) * (sqds - rt) + shift;
      ztest = e[q] / ztest * sqds;
      while (q + 1 <= m + 1) {
        double_pend_varible_xrotg(&rt, &ztest, &sqds, &smm1);
        rt = sqds * b_s[0] + smm1 * e[0];
        e[0] = sqds * e[0] - smm1 * b_s[0];
        ztest = smm1 * b_s[1];
        b_s[1] *= sqds;
        double_pend_varible_xrot(Vf, 1, 3, sqds, smm1);
        double_pend_varible_xrotg(&rt, &ztest, &sqds, &smm1);
        b_s[0] = rt;
        rt = sqds * e[0] + smm1 * b_s[1];
        b_s[1] = -smm1 * e[0] + sqds * b_s[1];
        ztest = smm1 * e[1];
        e[1] *= sqds;
        double_pend_varible_xrot(U, 1, 3, sqds, smm1);
        q = 1;
      }

      e[m] = rt;
      iter++;
      break;

     default:
      if (b_s[q] < 0.0) {
        b_s[q] = -b_s[q];
        double_pend_varible_xscal_h(-1.0, Vf, (q << 1) + 1);
      }

      iter = q + 1;
      while ((q + 1 < 2) && (b_s[q] < b_s[iter])) {
        rt = b_s[q];
        b_s[q] = b_s[iter];
        b_s[iter] = rt;
        double_pend_varible_xswap(Vf, (q << 1) + 1, ((q + 1) << 1) + 1);
        double_pend_varible_xswap(U, (q << 1) + 1, ((q + 1) << 1) + 1);
        q = iter;
        iter++;
      }

      iter = 0;
      m--;
      break;
    }
  }

  s[0] = b_s[0];
  V[0] = Vf[0];
  V[1] = Vf[1];
  s[1] = b_s[1];
  V[2] = Vf[2];
  V[3] = Vf[3];
}

/* Function for MATLAB Function: '<S19>/Predict' */
static void double_pend_varible_pinv(const real_T A[4], real_T X[4])
{
  real_T U[4];
  real_T V[4];
  real_T s[2];
  real_T absx;
  int32_T ar;
  int32_T b_ic;
  int32_T ia;
  int32_T r;
  int32_T vcol;
  boolean_T p;
  p = true;
  X[0] = 0.0;
  if (rtIsInf(A[0]) || rtIsNaN(A[0])) {
    p = false;
  }

  X[1] = 0.0;
  if (p && ((!rtIsInf(A[1])) && (!rtIsNaN(A[1])))) {
  } else {
    p = false;
  }

  X[2] = 0.0;
  if (p && ((!rtIsInf(A[2])) && (!rtIsNaN(A[2])))) {
  } else {
    p = false;
  }

  X[3] = 0.0;
  if (p && ((!rtIsInf(A[3])) && (!rtIsNaN(A[3])))) {
  } else {
    p = false;
  }

  if (!p) {
    X[0] = (rtNaN);
    X[1] = (rtNaN);
    X[2] = (rtNaN);
    X[3] = (rtNaN);
  } else {
    double_pend_varible_svd(A, U, s, V);
    absx = fabs(s[0]);
    if ((!rtIsInf(absx)) && (!rtIsNaN(absx))) {
      if (absx <= 2.2250738585072014E-308) {
        absx = 4.94065645841247E-324;
      } else {
        frexp(absx, &vcol);
        absx = ldexp(1.0, vcol - 53);
      }
    } else {
      absx = (rtNaN);
    }

    absx *= 2.0;
    r = -1;
    vcol = 0;
    while ((vcol < 2) && (s[vcol] > absx)) {
      r++;
      vcol++;
    }

    if (r + 1 > 0) {
      vcol = 0;
      for (ia = 0; ia <= r; ia++) {
        absx = 1.0 / s[ia];
        for (ar = vcol; ar < vcol + 2; ar++) {
          V[ar] *= absx;
        }

        vcol += 2;
      }

      for (ia = 0; ia < 2; ia++) {
        X[ia] = 0.0;
      }

      for (ia = 2; ia < 4; ia++) {
        X[ia] = 0.0;
      }

      ar = -1;
      vcol = r << 1;
      for (r = 1; r <= vcol + 1; r += 2) {
        ia = ar;
        for (b_ic = 0; b_ic < 2; b_ic++) {
          ia++;
          X[b_ic] += U[r - 1] * V[ia];
        }

        ar += 2;
      }

      ar = -1;
      for (r = 2; r <= vcol + 2; r += 2) {
        ia = ar;
        for (b_ic = 2; b_ic < 4; b_ic++) {
          ia++;
          X[b_ic] += U[r - 1] * V[ia];
        }

        ar += 2;
      }
    }
  }
}

/* Function for MATLAB Function: '<S3>/MATLAB Function' */
static real_T double_pend_varible_xnrm2_o(int32_T n, const real_T x[2], int32_T
  ix0)
{
  real_T absxk;
  real_T scale;
  real_T t;
  real_T y;
  int32_T k;
  int32_T kend;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x[ix0 - 1]);
    } else {
      scale = 3.3121686421112381E-170;
      kend = (ix0 + n) - 1;
      for (k = ix0; k <= kend; k++) {
        absxk = fabs(x[k - 1]);
        if (absxk > scale) {
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          t = absxk / scale;
          y += t * t;
        }
      }

      y = scale * sqrt(y);
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S3>/MATLAB Function' */
static void double_pend_varible_qrpf(real_T A[2], int32_T ia0, int32_T m,
  int32_T n, real_T *tau, int32_T jpvt[2])
{
  real_T vn1[2];
  real_T vn2[2];
  real_T work[2];
  real_T beta1;
  real_T smax;
  int32_T b_j;
  int32_T b_k;
  int32_T c_ix;
  int32_T e;
  int32_T exitg1;
  int32_T ia;
  int32_T ii;
  int32_T ii_tmp;
  int32_T ix;
  int32_T iy;
  int32_T minmn;
  int32_T mmi;
  int32_T nmi;
  int32_T pvt;
  boolean_T exitg2;
  if (m < n) {
    minmn = m;
  } else {
    minmn = n;
  }

  work[0] = 0.0;
  vn1[0] = 0.0;
  vn2[0] = 0.0;
  work[1] = 0.0;
  vn1[1] = 0.0;
  vn2[1] = 0.0;
  for (b_j = 0; b_j < n; b_j++) {
    vn1[b_j] = double_pend_varible_xnrm2_o(m, A, ia0 + b_j);
    vn2[b_j] = vn1[b_j];
  }

  for (b_j = 0; b_j < minmn; b_j++) {
    ii_tmp = ia0 + b_j;
    ii = (ii_tmp + b_j) - 1;
    nmi = n - b_j;
    mmi = (m - b_j) - 1;
    if (nmi < 1) {
      pvt = -1;
    } else {
      pvt = 0;
      if (nmi > 1) {
        ix = b_j;
        smax = fabs(vn1[b_j]);
        for (iy = 2; iy <= nmi; iy++) {
          ix++;
          beta1 = fabs(vn1[ix]);
          if (beta1 > smax) {
            pvt = iy - 1;
            smax = beta1;
          }
        }
      }
    }

    pvt += b_j;
    if (pvt + 1 != b_j + 1) {
      ix = (ia0 + pvt) - 1;
      iy = ii_tmp - 1;
      for (b_k = 0; b_k < m; b_k++) {
        smax = A[ix];
        A[ix] = A[iy];
        A[iy] = smax;
        ix++;
        iy++;
      }

      ix = jpvt[pvt];
      jpvt[pvt] = jpvt[b_j];
      jpvt[b_j] = ix;
      vn1[pvt] = vn1[b_j];
      vn2[pvt] = vn2[b_j];
    }

    if (b_j + 1 < m) {
      smax = A[ii];
      *tau = 0.0;
      if (mmi + 1 > 0) {
        beta1 = double_pend_varible_xnrm2_o(mmi, A, ii + 2);
        if (beta1 != 0.0) {
          beta1 = rt_hypotd_snf(A[ii], beta1);
          if (A[ii] >= 0.0) {
            beta1 = -beta1;
          }

          if (fabs(beta1) < 1.0020841800044864E-292) {
            pvt = -1;
            ix = (ii + mmi) + 1;
            do {
              pvt++;
              for (iy = ii + 1; iy < ix; iy++) {
                A[iy] *= 9.9792015476736E+291;
              }

              beta1 *= 9.9792015476736E+291;
              smax *= 9.9792015476736E+291;
            } while (!(fabs(beta1) >= 1.0020841800044864E-292));

            beta1 = rt_hypotd_snf(smax, double_pend_varible_xnrm2_o(mmi, A, ii +
              2));
            if (smax >= 0.0) {
              beta1 = -beta1;
            }

            *tau = (beta1 - smax) / beta1;
            smax = 1.0 / (smax - beta1);
            ix = (ii + mmi) + 1;
            for (iy = ii + 1; iy < ix; iy++) {
              A[iy] *= smax;
            }

            for (ix = 0; ix <= pvt; ix++) {
              beta1 *= 1.0020841800044864E-292;
            }

            smax = beta1;
          } else {
            *tau = (beta1 - A[ii]) / beta1;
            smax = 1.0 / (A[ii] - beta1);
            pvt = (ii + mmi) + 1;
            for (ix = ii + 1; ix < pvt; ix++) {
              A[ix] *= smax;
            }

            smax = beta1;
          }
        }
      }

      A[ii] = smax;
    } else {
      *tau = 0.0;
    }

    if (b_j + 1 < n) {
      smax = A[ii];
      A[ii] = 1.0;
      if (*tau != 0.0) {
        pvt = mmi + 1;
        ix = ii + mmi;
        while ((pvt > 0) && (A[ix] == 0.0)) {
          pvt--;
          ix--;
        }

        nmi--;
        exitg2 = false;
        while ((!exitg2) && (nmi > 0)) {
          ix = (ii + nmi) + 1;
          iy = ix;
          do {
            exitg1 = 0;
            if (iy <= (ix + pvt) - 1) {
              if (A[iy - 1] != 0.0) {
                exitg1 = 1;
              } else {
                iy++;
              }
            } else {
              nmi--;
              exitg1 = 2;
            }
          } while (exitg1 == 0);

          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
      } else {
        pvt = 0;
        nmi = 0;
      }

      if (pvt > 0) {
        if (nmi != 0) {
          for (ix = 0; ix < nmi; ix++) {
            work[ix] = 0.0;
          }

          ix = 0;
          iy = (ii + nmi) + 1;
          for (b_k = ii + 2; b_k <= iy; b_k++) {
            c_ix = ii;
            beta1 = 0.0;
            e = (b_k + pvt) - 1;
            for (ia = b_k; ia <= e; ia++) {
              beta1 += A[ia - 1] * A[c_ix];
              c_ix++;
            }

            work[ix] += beta1;
            ix++;
          }
        }

        if (!(-*tau == 0.0)) {
          ix = ii + 1;
          iy = 0;
          for (b_k = 0; b_k < nmi; b_k++) {
            if (work[iy] != 0.0) {
              beta1 = work[iy] * -*tau;
              c_ix = ii;
              e = pvt + ix;
              for (ia = ix; ia < e; ia++) {
                A[ia] += A[c_ix] * beta1;
                c_ix++;
              }
            }

            iy++;
            ix++;
          }
        }
      }

      A[ii] = smax;
    }

    for (ii = b_j + 1; ii < n; ii++) {
      nmi = ii_tmp + ii;
      if (vn1[ii] != 0.0) {
        smax = fabs(A[nmi - 1]) / vn1[ii];
        smax = 1.0 - smax * smax;
        if (smax < 0.0) {
          smax = 0.0;
        }

        beta1 = vn1[ii] / vn2[ii];
        beta1 = beta1 * beta1 * smax;
        if (beta1 <= 1.4901161193847656E-8) {
          if (b_j + 1 < m) {
            vn1[ii] = double_pend_varible_xnrm2_o(mmi, A, nmi + 1);
            vn2[ii] = vn1[ii];
          } else {
            vn1[ii] = 0.0;
            vn2[ii] = 0.0;
          }
        } else {
          vn1[ii] *= sqrt(smax);
        }
      }
    }
  }
}

/* Function for MATLAB Function: '<S4>/M' */
static void double_pend_varible_xswap_n(real_T x[4])
{
  real_T temp;
  temp = x[0];
  x[0] = x[2];
  x[2] = temp;
  temp = x[1];
  x[1] = x[3];
  x[3] = temp;
}

/* Function for MATLAB Function: '<S4>/M' */
static void double_pend_varible_svd_i(const real_T A[4], real_T U[4], real_T s[2],
  real_T V[4])
{
  real_T Vf[4];
  real_T b_A[4];
  real_T b_s[2];
  real_T e[2];
  real_T emm1;
  real_T nrm;
  real_T rt;
  real_T shift;
  real_T smm1;
  real_T sqds;
  real_T ztest;
  int32_T iter;
  int32_T kase;
  int32_T m;
  int32_T q;
  int32_T qs;
  boolean_T exitg1;
  b_A[0] = A[0];
  b_A[1] = A[1];
  b_A[2] = A[2];
  b_A[3] = A[3];
  nrm = double_pend_varible_xnrm2_n(A);
  if (nrm > 0.0) {
    if (A[0] < 0.0) {
      nrm = -nrm;
    }

    if (fabs(nrm) >= 1.0020841800044864E-292) {
      double_pend_varible_xscal(1.0 / nrm, b_A);
    } else {
      b_A[0] = A[0] / nrm;
      b_A[1] = A[1] / nrm;
    }

    b_A[0]++;
    b_s[0] = -nrm;
    double_pend_varible_xaxpy(-(double_pend_varible_xdotc(b_A, b_A) / b_A[0]),
      b_A);
  } else {
    b_s[0] = 0.0;
  }

  b_s[1] = b_A[3];
  e[1] = 0.0;
  U[0] = b_A[0];
  U[2] = 0.0;
  U[1] = b_A[1];
  m = 2;
  U[3] = 1.0;
  if (b_s[0] != 0.0) {
    double_pend_varible_xaxpy(-(double_pend_varible_xdotc(U, U) / b_A[0]), U);
    U[1] = -U[1];
    U[0] = -U[0] + 1.0;
  } else {
    U[1] = 0.0;
    U[0] = 1.0;
  }

  Vf[2] = 0.0;
  Vf[3] = 1.0;
  Vf[1] = 0.0;
  Vf[0] = 1.0;
  ztest = b_A[2];
  if (b_s[0] != 0.0) {
    rt = fabs(b_s[0]);
    nrm = b_s[0] / rt;
    b_s[0] = rt;
    ztest = b_A[2] / nrm;
    double_pend_varible_xscal_h(nrm, U, 1);
  }

  if (ztest != 0.0) {
    rt = fabs(ztest);
    nrm = rt / ztest;
    ztest = rt;
    b_s[1] = b_A[3] * nrm;
    double_pend_varible_xscal_h(nrm, Vf, 3);
  }

  if (b_s[1] != 0.0) {
    rt = fabs(b_s[1]);
    nrm = b_s[1] / rt;
    b_s[1] = rt;
    double_pend_varible_xscal_h(nrm, U, 3);
  }

  e[0] = ztest;
  iter = 0;
  nrm = fmax(fmax(b_s[0], ztest), fmax(b_s[1], 0.0));
  while ((m > 0) && (iter < 75)) {
    q = m - 1;
    exitg1 = false;
    while (!(exitg1 || (q == 0))) {
      rt = fabs(e[0]);
      if ((rt <= (fabs(b_s[0]) + fabs(b_s[1])) * 2.2204460492503131E-16) || ((rt
            <= 1.0020841800044864E-292) || ((iter > 20) && (rt <=
             2.2204460492503131E-16 * nrm)))) {
        e[0] = 0.0;
        exitg1 = true;
      } else {
        q = 0;
      }
    }

    if (m - 1 == q) {
      kase = 4;
    } else {
      qs = m;
      kase = m;
      exitg1 = false;
      while ((!exitg1) && (kase >= q)) {
        qs = kase;
        if (kase == q) {
          exitg1 = true;
        } else {
          rt = 0.0;
          if (kase < m) {
            rt = fabs(e[0]);
          }

          if (kase > q + 1) {
            rt += fabs(e[0]);
          }

          ztest = fabs(b_s[kase - 1]);
          if ((ztest <= 2.2204460492503131E-16 * rt) || (ztest <=
               1.0020841800044864E-292)) {
            b_s[kase - 1] = 0.0;
            exitg1 = true;
          } else {
            kase--;
          }
        }
      }

      if (qs == q) {
        kase = 3;
      } else if (qs == m) {
        kase = 1;
      } else {
        kase = 2;
        q = qs;
      }
    }

    switch (kase) {
     case 1:
      rt = e[0];
      e[0] = 0.0;
      qs = m - 1;
      while (qs >= q + 1) {
        double_pend_varible_xrotg(&b_s[0], &rt, &ztest, &sqds);
        double_pend_varible_xrot(Vf, 1, ((m - 1) << 1) + 1, ztest, sqds);
        qs = 0;
      }
      break;

     case 2:
      rt = e[q - 1];
      e[q - 1] = 0.0;
      for (qs = q; qs < m; qs++) {
        double_pend_varible_xrotg(&b_s[qs], &rt, &ztest, &sqds);
        rt = -sqds * e[qs];
        e[qs] *= ztest;
        double_pend_varible_xrot(U, (qs << 1) + 1, ((q - 1) << 1) + 1, ztest,
          sqds);
      }
      break;

     case 3:
      rt = b_s[m - 1];
      ztest = fmax(fmax(fmax(fmax(fabs(rt), fabs(b_s[0])), fabs(e[0])), fabs
                        (b_s[q])), fabs(e[q]));
      rt /= ztest;
      smm1 = b_s[0] / ztest;
      emm1 = e[0] / ztest;
      sqds = b_s[q] / ztest;
      smm1 = ((smm1 + rt) * (smm1 - rt) + emm1 * emm1) / 2.0;
      emm1 *= rt;
      emm1 *= emm1;
      if ((smm1 != 0.0) || (emm1 != 0.0)) {
        shift = sqrt(smm1 * smm1 + emm1);
        if (smm1 < 0.0) {
          shift = -shift;
        }

        shift = emm1 / (smm1 + shift);
      } else {
        shift = 0.0;
      }

      rt = (sqds + rt) * (sqds - rt) + shift;
      ztest = e[q] / ztest * sqds;
      while (q + 1 < 2) {
        double_pend_varible_xrotg(&rt, &ztest, &sqds, &smm1);
        rt = sqds * b_s[0] + smm1 * e[0];
        e[0] = sqds * e[0] - smm1 * b_s[0];
        ztest = smm1 * b_s[1];
        b_s[1] *= sqds;
        double_pend_varible_xrot(Vf, 1, 3, sqds, smm1);
        double_pend_varible_xrotg(&rt, &ztest, &sqds, &smm1);
        b_s[0] = rt;
        rt = sqds * e[0] + smm1 * b_s[1];
        b_s[1] = -smm1 * e[0] + sqds * b_s[1];
        ztest = smm1 * e[1];
        e[1] *= sqds;
        double_pend_varible_xrot(U, 1, 3, sqds, smm1);
        q = 1;
      }

      e[0] = rt;
      iter++;
      break;

     default:
      if (b_s[q] < 0.0) {
        b_s[q] = -b_s[q];
        double_pend_varible_xscal_h(-1.0, Vf, (q << 1) + 1);
      }

      while ((q + 1 < 2) && (b_s[0] < b_s[1])) {
        rt = b_s[0];
        b_s[0] = b_s[1];
        b_s[1] = rt;
        double_pend_varible_xswap_n(Vf);
        double_pend_varible_xswap_n(U);
        q = 1;
      }

      iter = 0;
      m--;
      break;
    }
  }

  s[0] = b_s[0];
  V[0] = Vf[0];
  V[1] = Vf[1];
  s[1] = b_s[1];
  V[2] = Vf[2];
  V[3] = Vf[3];
}

/* Model step function */
void double_pend_varible_step(void)
{
  real_T dCoefs[32];
  real_T ddCoefs[32];
  real_T pp_coefs[32];
  real_T A[16];
  real_T C[16];
  real_T K[16];
  real_T K_0[16];
  real_T dHdx[16];
  real_T rtb_P_n[16];
  real_T a__2[6];
  real_T a__3[6];
  real_T a__4[6];
  real_T newBreaks[5];
  real_T pp_breaks[5];
  real_T Kn0[4];
  real_T imvec[4];
  real_T imvec_0[4];
  real_T z[4];
  real_T rtb_Add1[2];
  real_T rtb_Trajectorygeneration_o2[2];
  real_T epsilon;
  real_T epsilon_idx_0;
  real_T epsilon_idx_1;
  real_T rtb_Clock1;
  real_T rtb_Gain6;
  real_T rtb_Product2_idx_0;
  real_T rtb_Product2_idx_1;
  real_T rtb_Product3;
  real_T temp;
  real_T temp_0;
  real_T temp_idx_0;
  real_T tmp;
  real_T tmp_0;
  real_T tmp_1;
  real_T tmp_2;
  int32_T jpvt[2];
  int32_T A_tmp_tmp;
  int32_T b_i;
  int32_T i;
  int32_T r;
  int32_T rankA;
  boolean_T exitg1;
  boolean_T p;
  boolean_T p_0;
  if (rtmIsMajorTimeStep(double_pend_varible_M)) {
    /* set solver stop time */
    if (!(double_pend_varible_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&double_pend_varible_M->solverInfo,
                            ((double_pend_varible_M->Timing.clockTickH0 + 1) *
        double_pend_varible_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&double_pend_varible_M->solverInfo,
                            ((double_pend_varible_M->Timing.clockTick0 + 1) *
        double_pend_varible_M->Timing.stepSize0 +
        double_pend_varible_M->Timing.clockTickH0 *
        double_pend_varible_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(double_pend_varible_M)) {
    double_pend_varible_M->Timing.t[0] = rtsiGetT
      (&double_pend_varible_M->solverInfo);
  }

  /* Clock: '<Root>/Clock1' */
  rtb_Clock1 = double_pend_varible_M->Timing.t[0];

  /* Product: '<Root>/Product' incorporates:
   *  Abs: '<Root>/Abs'
   *  Constant: '<Root>/Constant2'
   *  Math: '<Root>/Exp'
   *  Product: '<Root>/Product1'
   *  Sin: '<Root>/Sine Wave Function'
   *
   * About '<Root>/Exp':
   *  Operator: exp
   */
  double_pend_varible_B.Product = fabs(sin
    (double_pend_varible_P.SineWaveFunction_Freq * rtb_Clock1 +
     double_pend_varible_P.SineWaveFunction_Phase) *
    double_pend_varible_P.SineWaveFunction_Amp +
    double_pend_varible_P.SineWaveFunction_Bias) * exp(rtb_Clock1 *
    double_pend_varible_P.Constant2_Value);
  if (rtmIsMajorTimeStep(double_pend_varible_M)) {
  }

  /* Integrator: '<S4>/Integrator4' */
  double_pend_varible_B.Integrator4[0] =
    double_pend_varible_X.Integrator4_CSTATE[0];
  double_pend_varible_B.Integrator4[1] =
    double_pend_varible_X.Integrator4_CSTATE[1];

  /* MATLAB Function: '<S5>/MATLAB Function' incorporates:
   *  Constant: '<S5>/Constant'
   */
  double_pend_vari_MATLABFunction(double_pend_varible_B.Integrator4,
    double_pend_varible_P.l, &double_pend_varible_B.sf_MATLABFunction_h);

  /* Integrator: '<S4>/Integrator1' */
  double_pend_varible_B.Integrator1[0] =
    double_pend_varible_X.Integrator1_CSTATE[0];
  double_pend_varible_B.Integrator1[1] =
    double_pend_varible_X.Integrator1_CSTATE[1];
  if (rtmIsMajorTimeStep(double_pend_varible_M)) {
    /* Outputs for Enabled SubSystem: '<S16>/Correct1' incorporates:
     *  EnablePort: '<S17>/Enable'
     */
    /* DataTypeConversion: '<S16>/DataTypeConversion_Enable1' incorporates:
     *  Constant: '<S2>/Constant5'
     */
    if (double_pend_varible_P.Constant5_Value != 0.0) {
      /* DataStoreRead: '<S17>/Data Store ReadP' */
      memcpy(&rtb_P_n[0], &double_pend_varible_DW.P[0], sizeof(real_T) << 4U);

      /* MATLAB Function: '<S17>/Correct' incorporates:
       *  Constant: '<S16>/R1'
       *  DataStoreRead: '<S17>/Data Store ReadP'
       *  DataStoreRead: '<S17>/Data Store ReadX'
       */
      for (rankA = 0; rankA < 4; rankA++) {
        imvec[0] = double_pend_varible_DW.x[0];
        imvec[1] = double_pend_varible_DW.x[1];
        imvec[2] = double_pend_varible_DW.x[2];
        imvec[3] = double_pend_varible_DW.x[3];
        epsilon = fmax(1.4901161193847656E-8, 1.4901161193847656E-8 * fabs
                       (double_pend_varible_DW.x[rankA]));
        imvec[rankA] = double_pend_varible_DW.x[rankA] + epsilon;
        i = rankA << 2;
        dHdx[i] = (imvec[0] - double_pend_varible_DW.x[0]) / epsilon;
        dHdx[i + 1] = (imvec[1] - double_pend_varible_DW.x[1]) / epsilon;
        dHdx[i + 2] = (imvec[2] - double_pend_varible_DW.x[2]) / epsilon;
        dHdx[i + 3] = (imvec[3] - double_pend_varible_DW.x[3]) / epsilon;
      }

      memcpy(&K[0], &double_pend_varible_DW.P[0], sizeof(real_T) << 4U);
      double_pend_varible_qrFactor(dHdx, K, double_pend_varible_P.R1_Value);
      for (i = 0; i < 4; i++) {
        for (b_i = 0; b_i < 4; b_i++) {
          rankA = b_i + (i << 2);
          C[rankA] = 0.0;
          C[rankA] += double_pend_varible_DW.P[b_i] * double_pend_varible_DW.P[i];
          C[rankA] += double_pend_varible_DW.P[b_i + 4] *
            double_pend_varible_DW.P[i + 4];
          C[rankA] += double_pend_varible_DW.P[b_i + 8] *
            double_pend_varible_DW.P[i + 8];
          C[rankA] += double_pend_varible_DW.P[b_i + 12] *
            double_pend_varible_DW.P[i + 12];
        }
      }

      for (i = 0; i < 4; i++) {
        for (b_i = 0; b_i < 4; b_i++) {
          rankA = b_i + (i << 2);
          A[rankA] = 0.0;
          A[rankA] += C[i] * dHdx[b_i];
          A[rankA] += C[i + 4] * dHdx[b_i + 4];
          A[rankA] += C[i + 8] * dHdx[b_i + 8];
          A[rankA] += C[i + 12] * dHdx[b_i + 12];
        }
      }

      for (rankA = 0; rankA < 4; rankA++) {
        i = rankA << 2;
        C[i] = A[i];
        C[i + 1] = A[i + 1];
        C[i + 2] = A[i + 2];
        i = (rankA << 2) + 3;
        C[i] = A[i];
      }

      double_pend_varible_trisolve(K, C);
      for (b_i = 0; b_i < 4; b_i++) {
        rankA = b_i << 2;
        A[rankA] = C[rankA];
        A[rankA + 1] = C[rankA + 1];
        A[rankA + 2] = C[rankA + 2];
        A[rankA + 3] = C[rankA + 3];
        K_0[rankA] = K[b_i];
        K_0[rankA + 1] = K[b_i + 4];
        K_0[rankA + 2] = K[b_i + 8];
        K_0[rankA + 3] = K[b_i + 12];
      }

      double_pend_varible_trisolve_e(K_0, A);
      for (i = 0; i < 4; i++) {
        rankA = i << 2;
        K[rankA] = A[i];
        K[rankA + 1] = A[i + 4];
        K[rankA + 2] = A[i + 8];
        K[rankA + 3] = A[i + 12];
      }

      for (i = 0; i < 16; i++) {
        K_0[i] = -K[i];
      }

      for (i = 0; i < 4; i++) {
        for (b_i = 0; b_i < 4; b_i++) {
          A_tmp_tmp = i << 2;
          rankA = b_i + A_tmp_tmp;
          A[rankA] = 0.0;
          A[rankA] += dHdx[A_tmp_tmp] * K_0[b_i];
          A[rankA] += dHdx[A_tmp_tmp + 1] * K_0[b_i + 4];
          A[rankA] += dHdx[A_tmp_tmp + 2] * K_0[b_i + 8];
          A[rankA] += dHdx[A_tmp_tmp + 3] * K_0[b_i + 12];
        }
      }

      for (b_i = 0; b_i < 4; b_i++) {
        for (i = 0; i < 4; i++) {
          A_tmp_tmp = i << 2;
          rankA = b_i + A_tmp_tmp;
          K_0[rankA] = 0.0;
          K_0[rankA] += double_pend_varible_P.R1_Value[A_tmp_tmp] * K[b_i];
          K_0[rankA] += double_pend_varible_P.R1_Value[A_tmp_tmp + 1] * K[b_i +
            4];
          K_0[rankA] += double_pend_varible_P.R1_Value[A_tmp_tmp + 2] * K[b_i +
            8];
          rankA = A_tmp_tmp + b_i;
          K_0[rankA] += double_pend_varible_P.R1_Value[A_tmp_tmp + 3] * K[b_i +
            12];
        }

        rankA = (b_i << 2) + b_i;
        A[rankA]++;
      }

      double_pend_varible_qrFactor(A, rtb_P_n, K_0);

      /* DataStoreWrite: '<S17>/Data Store WriteP' */
      memcpy(&double_pend_varible_DW.P[0], &rtb_P_n[0], sizeof(real_T) << 4U);

      /* ZeroOrderHold: '<S2>/Zero-Order Hold' incorporates:
       *  DataStoreRead: '<S17>/Data Store ReadX'
       *  MATLAB Function: '<S17>/Correct'
       */
      rtb_Gain6 = double_pend_varible_B.Integrator4[0] -
        double_pend_varible_DW.x[0];
      tmp_0 = double_pend_varible_B.Integrator1[0] - double_pend_varible_DW.x[2];
      temp_idx_0 = double_pend_varible_B.Integrator4[1] -
        double_pend_varible_DW.x[1];
      tmp = double_pend_varible_B.Integrator1[1] - double_pend_varible_DW.x[3];

      /* DataStoreWrite: '<S17>/Data Store WriteX' incorporates:
       *  DataStoreRead: '<S17>/Data Store ReadX'
       *  MATLAB Function: '<S17>/Correct'
       */
      for (i = 0; i < 4; i++) {
        double_pend_varible_DW.x[i] += ((K[i + 4] * temp_idx_0 + K[i] *
          rtb_Gain6) + K[i + 8] * tmp_0) + K[i + 12] * tmp;
      }

      /* End of DataStoreWrite: '<S17>/Data Store WriteX' */
    }

    /* End of DataTypeConversion: '<S16>/DataTypeConversion_Enable1' */
    /* End of Outputs for SubSystem: '<S16>/Correct1' */

    /* Outputs for Atomic SubSystem: '<S16>/Output' */
    /* DataStoreRead: '<S18>/Data Store Read' */
    double_pend_varible_B.DataStoreRead[0] = double_pend_varible_DW.x[0];
    double_pend_varible_B.DataStoreRead[1] = double_pend_varible_DW.x[1];
    double_pend_varible_B.DataStoreRead[2] = double_pend_varible_DW.x[2];
    double_pend_varible_B.DataStoreRead[3] = double_pend_varible_DW.x[3];

    /* End of Outputs for SubSystem: '<S16>/Output' */

    /* Gain: '<S14>/Gain5' incorporates:
     *  Trigonometry: '<S14>/Trigonometric Function4'
     */
    double_pend_varible_B.Gain5 = double_pend_varible_P.l[0] * sin
      (double_pend_varible_B.DataStoreRead[0]);

    /* Gain: '<S14>/Gain6' incorporates:
     *  Trigonometry: '<S14>/Trigonometric Function5'
     */
    double_pend_varible_B.Gain6 = -double_pend_varible_P.l[0] * cos
      (double_pend_varible_B.DataStoreRead[0]);
  }

  /* Trigonometry: '<S15>/Trigonometric Function4' incorporates:
   *  MATLAB Function: '<S4>/G'
   */
  tmp_0 = sin(double_pend_varible_B.Integrator4[0]);

  /* Gain: '<S15>/Gain5' incorporates:
   *  Gain: '<S15>/Gain4'
   *  Trigonometry: '<S15>/Trigonometric Function4'
   */
  temp_idx_0 = double_pend_varible_P.l[0] * tmp_0;

  /* Trigonometry: '<S15>/Trigonometric Function5' incorporates:
   *  Trigonometry: '<S15>/Trigonometric Function1'
   */
  epsilon = cos(double_pend_varible_B.Integrator4[0]);

  /* Gain: '<S15>/Gain6' incorporates:
   *  Trigonometry: '<S15>/Trigonometric Function5'
   */
  rtb_Gain6 = -double_pend_varible_P.l[0] * epsilon;
  if (rtmIsMajorTimeStep(double_pend_varible_M)) {
    /* Product: '<S14>/Product2' incorporates:
     *  Gain: '<S14>/Gain3'
     *  Trigonometry: '<S14>/Trigonometric Function1'
     */
    double_pend_varible_B.Product2 = double_pend_varible_P.l[0] * cos
      (double_pend_varible_B.DataStoreRead[0]) *
      double_pend_varible_B.DataStoreRead[2];

    /* Product: '<S14>/Product3' incorporates:
     *  Gain: '<S14>/Gain4'
     *  Trigonometry: '<S14>/Trigonometric Function8'
     */
    double_pend_varible_B.Product3 = double_pend_varible_P.l[0] * sin
      (double_pend_varible_B.DataStoreRead[0]) *
      double_pend_varible_B.DataStoreRead[2];
  }

  /* Product: '<S15>/Product2' incorporates:
   *  Gain: '<S15>/Gain3'
   */
  epsilon = double_pend_varible_P.l[0] * epsilon *
    double_pend_varible_B.Integrator1[0];

  /* Product: '<S15>/Product3' */
  rtb_Product3 = temp_idx_0 * double_pend_varible_B.Integrator1[0];

  /* Sum: '<S12>/Subtract' incorporates:
   *  Gain: '<S15>/Gain5'
   */
  epsilon_idx_0 = temp_idx_0 - double_pend_varible_B.Gain5;

  /* Sum: '<S12>/Subtract1' */
  rtb_Product2_idx_0 = epsilon - double_pend_varible_B.Product2;

  /* Sum: '<S12>/Subtract' */
  epsilon_idx_1 = rtb_Gain6 - double_pend_varible_B.Gain6;

  /* Sum: '<S12>/Subtract1' */
  rtb_Product2_idx_1 = rtb_Product3 - double_pend_varible_B.Product3;

  /* Sum: '<S12>/Subtract2' incorporates:
   *  Gain: '<S12>/Gain3'
   *  Gain: '<S12>/Gain4'
   */
  double_pend_varible_B.Subtract2[0] = (double_pend_varible_P.spring[0] *
    epsilon_idx_0 + double_pend_varible_P.spring[2] * epsilon_idx_1) +
    (double_pend_varible_P.dampener[0] * rtb_Product2_idx_0 +
     double_pend_varible_P.dampener[2] * rtb_Product2_idx_1);
  double_pend_varible_B.Subtract2[1] = (double_pend_varible_P.spring[1] *
    epsilon_idx_0 + double_pend_varible_P.spring[3] * epsilon_idx_1) +
    (double_pend_varible_P.dampener[1] * rtb_Product2_idx_0 +
     double_pend_varible_P.dampener[3] * rtb_Product2_idx_1);

  /* MATLAB Function: '<S5>/MATLAB Function1' incorporates:
   *  Constant: '<S5>/Constant'
   */
  double_pend_var_MATLABFunction1(double_pend_varible_B.Integrator4,
    double_pend_varible_P.l, &double_pend_varible_B.sf_MATLABFunction1);
  if (rtmIsMajorTimeStep(double_pend_varible_M)) {
    /* Trigonometry: '<S14>/Trigonometric Function7' incorporates:
     *  Trigonometry: '<S14>/Trigonometric Function2'
     */
    epsilon_idx_1 = cos(double_pend_varible_B.DataStoreRead[1]);

    /* Gain: '<S14>/Gain7' incorporates:
     *  Gain: '<S14>/Gain2'
     *  Trigonometry: '<S14>/Trigonometric Function6'
     */
    tmp = double_pend_varible_P.l[1] * sin(double_pend_varible_B.DataStoreRead[1]);

    /* Sum: '<S14>/Add' incorporates:
     *  Gain: '<S14>/Gain7'
     *  Gain: '<S14>/Gain8'
     *  Trigonometry: '<S14>/Trigonometric Function7'
     */
    double_pend_varible_B.Add[0] = tmp + double_pend_varible_B.Gain5;
    double_pend_varible_B.Add[1] = -double_pend_varible_P.l[1] * epsilon_idx_1 +
      double_pend_varible_B.Gain6;

    /* Sum: '<S14>/Add1' incorporates:
     *  Gain: '<S14>/Gain1'
     *  Product: '<S14>/Product1'
     *  Product: '<S14>/Product4'
     */
    double_pend_varible_B.Add1[0] = double_pend_varible_P.l[1] * epsilon_idx_1 *
      double_pend_varible_B.DataStoreRead[3] + double_pend_varible_B.Product2;
    double_pend_varible_B.Add1[1] = tmp * double_pend_varible_B.DataStoreRead[3]
      + double_pend_varible_B.Product3;
  }

  /* Trigonometry: '<S15>/Trigonometric Function7' incorporates:
   *  Trigonometry: '<S15>/Trigonometric Function2'
   */
  epsilon_idx_1 = cos(double_pend_varible_B.Integrator4[1]);

  /* Trigonometry: '<S15>/Trigonometric Function6' incorporates:
   *  MATLAB Function: '<S4>/G'
   */
  tmp = sin(double_pend_varible_B.Integrator4[1]);

  /* Gain: '<S15>/Gain7' incorporates:
   *  Gain: '<S15>/Gain2'
   *  Product: '<S15>/Product4'
   *  Trigonometry: '<S15>/Trigonometric Function6'
   */
  rtb_Product2_idx_1 = double_pend_varible_P.l[1] * tmp;

  /* Sum: '<S13>/Subtract' incorporates:
   *  Gain: '<S15>/Gain5'
   *  Gain: '<S15>/Gain7'
   *  Sum: '<S15>/Add'
   */
  epsilon_idx_0 = (rtb_Product2_idx_1 + temp_idx_0) - double_pend_varible_B.Add
    [0];

  /* Sum: '<S13>/Subtract1' incorporates:
   *  Gain: '<S15>/Gain1'
   *  Product: '<S15>/Product1'
   *  Sum: '<S15>/Add1'
   */
  rtb_Product2_idx_0 = (double_pend_varible_P.l[1] * epsilon_idx_1 *
                        double_pend_varible_B.Integrator1[1] + epsilon) -
    double_pend_varible_B.Add1[0];

  /* Sum: '<S13>/Subtract' incorporates:
   *  Gain: '<S15>/Gain8'
   *  Sum: '<S15>/Add'
   *  Trigonometry: '<S15>/Trigonometric Function7'
   */
  epsilon_idx_1 = (-double_pend_varible_P.l[1] * epsilon_idx_1 + rtb_Gain6) -
    double_pend_varible_B.Add[1];

  /* Sum: '<S13>/Subtract1' incorporates:
   *  Product: '<S15>/Product4'
   *  Sum: '<S15>/Add1'
   */
  rtb_Product2_idx_1 = (rtb_Product2_idx_1 * double_pend_varible_B.Integrator1[1]
                        + rtb_Product3) - double_pend_varible_B.Add1[1];

  /* Sum: '<S13>/Subtract2' incorporates:
   *  Gain: '<S13>/Gain3'
   *  Gain: '<S13>/Gain4'
   */
  double_pend_varible_B.Subtract2_c[0] = (double_pend_varible_P.spring[0] *
    epsilon_idx_0 + double_pend_varible_P.spring[2] * epsilon_idx_1) +
    (double_pend_varible_P.dampener[0] * rtb_Product2_idx_0 +
     double_pend_varible_P.dampener[2] * rtb_Product2_idx_1);
  double_pend_varible_B.Subtract2_c[1] = (double_pend_varible_P.spring[1] *
    epsilon_idx_0 + double_pend_varible_P.spring[3] * epsilon_idx_1) +
    (double_pend_varible_P.dampener[1] * rtb_Product2_idx_0 +
     double_pend_varible_P.dampener[3] * rtb_Product2_idx_1);

  /* Sum: '<S5>/Add' incorporates:
   *  Math: '<S5>/Transpose1'
   *  Math: '<S5>/Transpose2'
   *  Product: '<S5>/Product1'
   *  Product: '<S5>/Product2'
   */
  double_pend_varible_B.Add_b[0] = (double_pend_varible_B.sf_MATLABFunction_h.y
    [0] * double_pend_varible_B.Subtract2[0] +
    double_pend_varible_B.sf_MATLABFunction_h.y[1] *
    double_pend_varible_B.Subtract2[1]) +
    (double_pend_varible_B.sf_MATLABFunction1.y[0] *
     double_pend_varible_B.Subtract2_c[0] +
     double_pend_varible_B.sf_MATLABFunction1.y[1] *
     double_pend_varible_B.Subtract2_c[1]);
  double_pend_varible_B.Add_b[1] = (double_pend_varible_B.Subtract2[0] *
    double_pend_varible_B.sf_MATLABFunction_h.y[2] +
    double_pend_varible_B.Subtract2[1] *
    double_pend_varible_B.sf_MATLABFunction_h.y[3]) +
    (double_pend_varible_B.Subtract2_c[0] *
     double_pend_varible_B.sf_MATLABFunction1.y[2] +
     double_pend_varible_B.Subtract2_c[1] *
     double_pend_varible_B.sf_MATLABFunction1.y[3]);
  if (rtmIsMajorTimeStep(double_pend_varible_M)) {
  }

  /* MATLABSystem: '<Root>/Trajectory generation' */
  p = false;
  p_0 = true;
  b_i = 0;
  exitg1 = false;
  while ((!exitg1) && (b_i < 6)) {
    if (!(double_pend_varible_DW.obj.Waypoints[b_i] ==
          double_pend_varible_P.Trajectorygeneration_Waypoints[b_i])) {
      p_0 = false;
      exitg1 = true;
    } else {
      b_i++;
    }
  }

  if (p_0) {
    p = true;
  }

  if (!p) {
    if (double_pend_varible_DW.obj.isInitialized == 1) {
      double_pend_varible_DW.obj.TunablePropsChanged = true;
    }

    for (i = 0; i < 6; i++) {
      double_pend_varible_DW.obj.Waypoints[i] =
        double_pend_varible_P.Trajectorygeneration_Waypoints[i];
    }
  }

  p = false;
  p_0 = true;
  b_i = 0;
  exitg1 = false;
  while ((!exitg1) && (b_i < 3)) {
    if (!(double_pend_varible_DW.obj.TimePoints[b_i] ==
          double_pend_varible_P.Trajectorygeneration_TimePoints[b_i])) {
      p_0 = false;
      exitg1 = true;
    } else {
      b_i++;
    }
  }

  if (p_0) {
    p = true;
  }

  if (!p) {
    if (double_pend_varible_DW.obj.isInitialized == 1) {
      double_pend_varible_DW.obj.TunablePropsChanged = true;
    }

    double_pend_varible_DW.obj.TimePoints[0] =
      double_pend_varible_P.Trajectorygeneration_TimePoints[0];
    double_pend_varible_DW.obj.TimePoints[1] =
      double_pend_varible_P.Trajectorygeneration_TimePoints[1];
    double_pend_varible_DW.obj.TimePoints[2] =
      double_pend_varible_P.Trajectorygeneration_TimePoints[2];
  }

  p = false;
  p_0 = true;
  b_i = 0;
  exitg1 = false;
  while ((!exitg1) && (b_i < 6)) {
    if (!(double_pend_varible_DW.obj.VelocityBoundaryCondition[b_i] ==
          double_pend_varible_P.Trajectorygeneration_VelocityBo[b_i])) {
      p_0 = false;
      exitg1 = true;
    } else {
      b_i++;
    }
  }

  if (p_0) {
    p = true;
  }

  if (!p) {
    if (double_pend_varible_DW.obj.isInitialized == 1) {
      double_pend_varible_DW.obj.TunablePropsChanged = true;
    }

    for (i = 0; i < 6; i++) {
      double_pend_varible_DW.obj.VelocityBoundaryCondition[i] =
        double_pend_varible_P.Trajectorygeneration_VelocityBo[i];
    }
  }

  if (double_pend_varible_DW.obj.TunablePropsChanged) {
    double_pend_varible_DW.obj.TunablePropsChanged = false;
  }

  double_pend_varib_cubicpolytraj(double_pend_varible_DW.obj.Waypoints,
    double_pend_varible_DW.obj.TimePoints, double_pend_varible_DW.obj.TimePoints,
    double_pend_varible_DW.obj.VelocityBoundaryCondition, a__2, a__3, a__4,
    pp_breaks, pp_coefs);
  for (i = 0; i < 5; i++) {
    newBreaks[i] = pp_breaks[i];
  }

  epsilon = 0.01;
  if (rtb_Clock1 > pp_breaks[3]) {
    rankA = 1;
    i = 1;
  } else {
    rankA = 0;
    i = 0;
  }

  if ((rankA != 0) && (i != 0)) {
    epsilon = fmin((rtb_Clock1 - pp_breaks[3]) / 2.0, 0.01);
  }

  newBreaks[3] = pp_breaks[3] + epsilon;
  memset(&dCoefs[0], 0, sizeof(real_T) << 5U);
  for (b_i = 0; b_i < 3; b_i++) {
    for (i = 0; i < 8; i++) {
      dCoefs[i + ((b_i + 1) << 3)] = pp_coefs[(b_i << 3) + i] * (real_T)(3 - b_i);
    }
  }

  memset(&ddCoefs[0], 0, sizeof(real_T) << 5U);
  for (b_i = 0; b_i < 3; b_i++) {
    for (i = 0; i < 8; i++) {
      ddCoefs[i + ((b_i + 1) << 3)] = dCoefs[(b_i << 3) + i] * (real_T)(3 - b_i);
    }
  }

  double_pend_varible_ppval_i(pp_breaks, pp_coefs, rtb_Clock1,
    double_pend_varible_B.Trajectorygeneration_o1);
  double_pend_varible_ppval_i(newBreaks, dCoefs, rtb_Clock1,
    rtb_Trajectorygeneration_o2);

  /* Sum: '<S3>/Sum1' incorporates:
   *  Integrator: '<S3>/Integrator1'
   *  Integrator: '<S4>/Integrator4'
   *  MATLABSystem: '<Root>/Trajectory generation'
   *  Sum: '<S3>/Sum7'
   */
  double_pend_varible_B.q_add[0] = double_pend_varible_B.Integrator4[0] -
    (double_pend_varible_B.Trajectorygeneration_o1[0] +
     double_pend_varible_X.Integrator1_CSTATE_j[0]);
  double_pend_varible_B.q_add[1] = double_pend_varible_B.Integrator4[1] -
    (double_pend_varible_B.Trajectorygeneration_o1[1] +
     double_pend_varible_X.Integrator1_CSTATE_j[1]);
  if (rtmIsMajorTimeStep(double_pend_varible_M)) {
  }

  /* Integrator: '<S3>/Integrator' */
  double_pend_varible_B.qd_add[0] = double_pend_varible_X.Integrator_CSTATE[0];

  /* Sum: '<S3>/Sum2' incorporates:
   *  Integrator: '<S4>/Integrator1'
   *  MATLABSystem: '<Root>/Trajectory generation'
   *  Sum: '<S3>/Sum8'
   */
  double_pend_varible_B.q_add_a[0] = double_pend_varible_B.Integrator1[0] -
    (double_pend_varible_B.qd_add[0] + rtb_Trajectorygeneration_o2[0]);

  /* Integrator: '<S3>/Integrator' */
  double_pend_varible_B.qd_add[1] = double_pend_varible_X.Integrator_CSTATE[1];

  /* Sum: '<S3>/Sum2' incorporates:
   *  Integrator: '<S4>/Integrator1'
   *  MATLABSystem: '<Root>/Trajectory generation'
   *  Sum: '<S3>/Sum8'
   */
  double_pend_varible_B.q_add_a[1] = double_pend_varible_B.Integrator1[1] -
    (double_pend_varible_B.qd_add[1] + rtb_Trajectorygeneration_o2[1]);
  if (rtmIsMajorTimeStep(double_pend_varible_M)) {
    /* MATLAB Function: '<S6>/MATLAB Function' incorporates:
     *  Constant: '<S6>/Constant'
     */
    double_pend_vari_MATLABFunction(&double_pend_varible_B.DataStoreRead[0],
      double_pend_varible_P.l, &double_pend_varible_B.sf_MATLABFunction_h1);

    /* Math: '<S6>/Transpose1' */
    double_pend_varible_B.Transpose1[0] =
      double_pend_varible_B.sf_MATLABFunction_h1.y[0];
    double_pend_varible_B.Transpose1[1] =
      double_pend_varible_B.sf_MATLABFunction_h1.y[2];
    double_pend_varible_B.Transpose1[2] =
      double_pend_varible_B.sf_MATLABFunction_h1.y[1];
    double_pend_varible_B.Transpose1[3] =
      double_pend_varible_B.sf_MATLABFunction_h1.y[3];

    /* MATLAB Function: '<S6>/MATLAB Function1' incorporates:
     *  Constant: '<S6>/Constant'
     */
    double_pend_var_MATLABFunction1(&double_pend_varible_B.DataStoreRead[0],
      double_pend_varible_P.l, &double_pend_varible_B.sf_MATLABFunction1_d);

    /* Math: '<S6>/Transpose2' */
    double_pend_varible_B.Transpose2[0] =
      double_pend_varible_B.sf_MATLABFunction1_d.y[0];
    double_pend_varible_B.Transpose2[1] =
      double_pend_varible_B.sf_MATLABFunction1_d.y[2];
    double_pend_varible_B.Transpose2[2] =
      double_pend_varible_B.sf_MATLABFunction1_d.y[1];
    double_pend_varible_B.Transpose2[3] =
      double_pend_varible_B.sf_MATLABFunction1_d.y[3];
  }

  /* Sum: '<S7>/Sum3' incorporates:
   *  MATLABSystem: '<Root>/Trajectory generation'
   */
  rtb_Gain6 = double_pend_varible_B.Trajectorygeneration_o1[0] -
    double_pend_varible_B.DataStoreRead[0];

  /* Sum: '<S7>/Sum1' incorporates:
   *  MATLABSystem: '<Root>/Trajectory generation'
   */
  epsilon = rtb_Trajectorygeneration_o2[0] -
    double_pend_varible_B.DataStoreRead[2];

  /* Sum: '<S7>/Sum3' incorporates:
   *  MATLABSystem: '<Root>/Trajectory generation'
   */
  temp_idx_0 = double_pend_varible_B.Trajectorygeneration_o1[1] -
    double_pend_varible_B.DataStoreRead[1];

  /* Sum: '<S7>/Sum1' incorporates:
   *  MATLABSystem: '<Root>/Trajectory generation'
   */
  rtb_Product3 = rtb_Trajectorygeneration_o2[1] -
    double_pend_varible_B.DataStoreRead[3];

  /* Saturate: '<S7>/Saturation' incorporates:
   *  Gain: '<S7>/Gain1'
   *  Gain: '<S7>/Gain2'
   *  Sum: '<S7>/Add2'
   */
  epsilon_idx_0 = (double_pend_varible_P.Km1[0] * rtb_Gain6 +
                   double_pend_varible_P.Km1[2] * temp_idx_0) +
    (double_pend_varible_P.Dm1[0] * epsilon + double_pend_varible_P.Dm1[2] *
     rtb_Product3);
  if (epsilon_idx_0 > double_pend_varible_P.Saturation_UpperSat) {
    epsilon_idx_0 = double_pend_varible_P.Saturation_UpperSat;
  } else if (epsilon_idx_0 < double_pend_varible_P.Saturation_LowerSat) {
    epsilon_idx_0 = double_pend_varible_P.Saturation_LowerSat;
  }

  /* Saturate: '<Root>/Saturation3' incorporates:
   *  Math: '<S6>/Transpose1'
   *  Math: '<S6>/Transpose2'
   *  Product: '<Root>/Product2'
   *  Product: '<S6>/Product1'
   *  Product: '<S6>/Product2'
   *  Sum: '<Root>/Sum2'
   *  Sum: '<S6>/Add'
   */
  epsilon_idx_0 = ((double_pend_varible_B.Transpose1[0] *
                    double_pend_varible_B.Subtract2[0] +
                    double_pend_varible_B.Subtract2[1] *
                    double_pend_varible_B.Transpose1[2]) +
                   (double_pend_varible_B.Transpose2[0] *
                    double_pend_varible_B.Subtract2_c[0] +
                    double_pend_varible_B.Subtract2_c[1] *
                    double_pend_varible_B.Transpose2[2])) +
    double_pend_varible_B.Product * epsilon_idx_0;
  if (epsilon_idx_0 > double_pend_varible_P.human_sat) {
    /* Saturate: '<Root>/Saturation3' */
    double_pend_varible_B.Nm[0] = double_pend_varible_P.human_sat;
  } else if (epsilon_idx_0 < -double_pend_varible_P.human_sat) {
    /* Saturate: '<Root>/Saturation3' */
    double_pend_varible_B.Nm[0] = -double_pend_varible_P.human_sat;
  } else {
    /* Saturate: '<Root>/Saturation3' */
    double_pend_varible_B.Nm[0] = epsilon_idx_0;
  }

  /* Saturate: '<S7>/Saturation' incorporates:
   *  Gain: '<S7>/Gain1'
   *  Gain: '<S7>/Gain2'
   *  Sum: '<S7>/Add2'
   */
  epsilon_idx_0 = (double_pend_varible_P.Km1[1] * rtb_Gain6 +
                   double_pend_varible_P.Km1[3] * temp_idx_0) +
    (double_pend_varible_P.Dm1[1] * epsilon + double_pend_varible_P.Dm1[3] *
     rtb_Product3);
  if (epsilon_idx_0 > double_pend_varible_P.Saturation_UpperSat) {
    epsilon_idx_0 = double_pend_varible_P.Saturation_UpperSat;
  } else if (epsilon_idx_0 < double_pend_varible_P.Saturation_LowerSat) {
    epsilon_idx_0 = double_pend_varible_P.Saturation_LowerSat;
  }

  /* Saturate: '<Root>/Saturation3' incorporates:
   *  Math: '<S6>/Transpose1'
   *  Math: '<S6>/Transpose2'
   *  Product: '<Root>/Product2'
   *  Product: '<S6>/Product1'
   *  Product: '<S6>/Product2'
   *  Sum: '<Root>/Sum2'
   *  Sum: '<S6>/Add'
   */
  epsilon_idx_0 = ((double_pend_varible_B.Subtract2[0] *
                    double_pend_varible_B.Transpose1[1] +
                    double_pend_varible_B.Subtract2[1] *
                    double_pend_varible_B.Transpose1[3]) +
                   (double_pend_varible_B.Subtract2_c[0] *
                    double_pend_varible_B.Transpose2[1] +
                    double_pend_varible_B.Subtract2_c[1] *
                    double_pend_varible_B.Transpose2[3])) +
    double_pend_varible_B.Product * epsilon_idx_0;
  if (epsilon_idx_0 > double_pend_varible_P.human_sat) {
    /* Saturate: '<Root>/Saturation3' */
    double_pend_varible_B.Nm[1] = double_pend_varible_P.human_sat;
  } else if (epsilon_idx_0 < -double_pend_varible_P.human_sat) {
    /* Saturate: '<Root>/Saturation3' */
    double_pend_varible_B.Nm[1] = -double_pend_varible_P.human_sat;
  } else {
    /* Saturate: '<Root>/Saturation3' */
    double_pend_varible_B.Nm[1] = epsilon_idx_0;
  }

  if (rtmIsMajorTimeStep(double_pend_varible_M)) {
    /* Outputs for Atomic SubSystem: '<S16>/Predict' */
    /* MATLAB Function: '<S19>/Predict' incorporates:
     *  DataStoreRead: '<S19>/Data Store ReadX'
     *  Saturate: '<Root>/Saturation3'
     *  ZeroOrderHold: '<S2>/Zero-Order Hold1'
     */
    Kn0[0] = 5.0777280000000005;
    tmp_1 = double_pend_varible_DW.x[0] - double_pend_varible_DW.x[1];
    rtb_Product3 = cos(tmp_1);
    epsilon_idx_0 = rtb_Product3 * 1.50072;
    Kn0[2] = epsilon_idx_0;
    rtb_Product3 *= 1.246752;
    Kn0[1] = rtb_Product3;
    Kn0[3] = 1.50072;
    double_pend_varible_pinv(Kn0, imvec);
    rtb_Product2_idx_0 = double_pend_varible_DW.x[2] * double_pend_varible_DW.x
      [2];
    epsilon_idx_1 = double_pend_varible_DW.x[3] * double_pend_varible_DW.x[3];
    Kn0[0] = 5.0777280000000005;
    Kn0[2] = epsilon_idx_0;
    Kn0[1] = rtb_Product3;
    Kn0[3] = 1.50072;
    double_pend_varible_pinv(Kn0, imvec);
    temp_idx_0 = sin(tmp_1);
    rtb_Product2_idx_1 = (double_pend_varible_B.Nm[0] - 1.50072 *
                          double_pend_varible_DW.x[3] *
                          double_pend_varible_DW.x[3] * temp_idx_0) - 153.74232 *
      sin(double_pend_varible_DW.x[0]);
    rtb_Gain6 = rtb_Product2_idx_1 - (100.0 * rtb_Product2_idx_0 + epsilon_idx_1
      * 0.0);
    tmp_2 = (double_pend_varible_B.Nm[1] - -1.246752 * double_pend_varible_DW.x
             [2] * double_pend_varible_DW.x[2] * temp_idx_0) - 37.74888 * sin
      (double_pend_varible_DW.x[1]);
    temp_idx_0 = tmp_2 - (rtb_Product2_idx_0 * 0.0 + epsilon_idx_1 * 100.0);
    temp = imvec[0] * rtb_Gain6 + imvec[2] * temp_idx_0;
    temp_0 = imvec[1] * rtb_Gain6 + imvec[3] * temp_idx_0;
    z[0] = double_pend_varible_DW.x[2];
    z[2] = double_pend_varible_DW.x[3];
    Kn0[0] = 5.0777280000000005;
    Kn0[3] = 1.50072;
    for (rankA = 0; rankA < 4; rankA++) {
      imvec[0] = double_pend_varible_DW.x[0];
      imvec[1] = double_pend_varible_DW.x[1];
      imvec[2] = double_pend_varible_DW.x[2];
      imvec[3] = double_pend_varible_DW.x[3];
      epsilon = fmax(1.4901161193847656E-8, 1.4901161193847656E-8 * fabs
                     (double_pend_varible_DW.x[rankA]));
      imvec[rankA] = double_pend_varible_DW.x[rankA] + epsilon;
      rtb_Add1[0] = imvec[2] * imvec[2];
      rtb_Add1[1] = imvec[3] * imvec[3];
      tmp_1 = imvec[0] - imvec[1];
      rtb_Gain6 = cos(tmp_1);
      Kn0[2] = rtb_Gain6 * 1.50072;
      Kn0[1] = rtb_Gain6 * 1.246752;
      double_pend_varible_pinv(Kn0, imvec_0);
      temp_idx_0 = sin(tmp_1);
      rtb_Gain6 = ((double_pend_varible_B.Nm[0] - 1.50072 * imvec[3] * imvec[3] *
                    temp_idx_0) - 153.74232 * sin(imvec[0])) - (100.0 *
        rtb_Add1[0] + rtb_Add1[1] * 0.0);
      temp_idx_0 = ((double_pend_varible_B.Nm[1] - -1.246752 * imvec[2] * imvec
                     [2] * temp_idx_0) - 37.74888 * sin(imvec[1])) - (rtb_Add1[0]
        * 0.0 + rtb_Add1[1] * 100.0);
      i = rankA << 2;
      rtb_P_n[i] = (imvec[2] - z[0]) / epsilon;
      rtb_P_n[i + 1] = ((imvec_0[0] * rtb_Gain6 + imvec_0[2] * temp_idx_0) -
                        temp) / epsilon;
      rtb_P_n[i + 2] = (imvec[3] - z[2]) / epsilon;
      rtb_P_n[i + 3] = ((imvec_0[1] * rtb_Gain6 + imvec_0[3] * temp_idx_0) -
                        temp_0) / epsilon;
    }

    Kn0[0] = 5.0777280000000005;
    Kn0[2] = epsilon_idx_0;
    Kn0[1] = rtb_Product3;
    Kn0[3] = 1.50072;
    double_pend_varible_pinv(Kn0, imvec);
    rtb_Gain6 = rtb_Product2_idx_1 - (100.0 * rtb_Product2_idx_0 + epsilon_idx_1
      * 0.0);
    temp_idx_0 = tmp_2 - (rtb_Product2_idx_0 * 0.0 + epsilon_idx_1 * 100.0);

    /* DataStoreWrite: '<S19>/Data Store WriteP' incorporates:
     *  Constant: '<S16>/Q'
     *  MATLAB Function: '<S19>/Predict'
     */
    double_pend_varible_qrFactor(rtb_P_n, double_pend_varible_DW.P,
      double_pend_varible_P.Q_Value);

    /* MATLAB Function: '<S19>/Predict' incorporates:
     *  DataStoreRead: '<S19>/Data Store ReadX'
     */
    tmp_1 = double_pend_varible_DW.x[2];

    /* DataStoreWrite: '<S19>/Data Store WriteX' incorporates:
     *  DataStoreRead: '<S19>/Data Store ReadX'
     *  MATLAB Function: '<S19>/Predict'
     */
    double_pend_varible_DW.x[2] = double_pend_varible_DW.x[3];
    double_pend_varible_DW.x[0] = tmp_1;
    double_pend_varible_DW.x[1] = imvec[0] * rtb_Gain6 + imvec[2] * temp_idx_0;
    double_pend_varible_DW.x[3] = imvec[1] * rtb_Gain6 + imvec[3] * temp_idx_0;

    /* End of Outputs for SubSystem: '<S16>/Predict' */
  }

  /* MATLAB Function: '<S31>/M' incorporates:
   *  Constant: '<S31>/Constant'
   *  Constant: '<S31>/Constant1'
   */
  double_pend_varible_M_l(double_pend_varible_P.me, double_pend_varible_P.l,
    double_pend_varible_B.Integrator4, &double_pend_varible_B.sf_M_l);

  /* Sum: '<S10>/Add' incorporates:
   *  Gain: '<S10>/Gain3'
   *  Sum: '<S3>/Sum1'
   *  Sum: '<S3>/Sum2'
   */
  double_pend_varible_B.Add_j[0] = (double_pend_varible_P.lambda2[0] *
    double_pend_varible_B.q_add[0] + double_pend_varible_B.q_add[1] *
    double_pend_varible_P.lambda2[2]) + double_pend_varible_B.q_add_a[0];

  /* Trigonometry: '<S10>/Tanh' incorporates:
   *  Gain: '<S10>/Gain18'
   *  Sum: '<S10>/Add'
   */
  double_pend_varible_B.Tanh[0] = tanh(double_pend_varible_P.beta[0] *
    double_pend_varible_B.Add_j[0]);

  /* Sum: '<S10>/Add' incorporates:
   *  Gain: '<S10>/Gain3'
   *  Sum: '<S3>/Sum1'
   *  Sum: '<S3>/Sum2'
   */
  double_pend_varible_B.Add_j[1] = (double_pend_varible_B.q_add[0] *
    double_pend_varible_P.lambda2[1] + double_pend_varible_B.q_add[1] *
    double_pend_varible_P.lambda2[3]) + double_pend_varible_B.q_add_a[1];

  /* Trigonometry: '<S10>/Tanh' incorporates:
   *  Gain: '<S10>/Gain18'
   *  Sum: '<S10>/Add'
   */
  double_pend_varible_B.Tanh[1] = tanh(double_pend_varible_P.beta[1] *
    double_pend_varible_B.Add_j[1]);

  /* MATLAB Function: '<S31>/C' incorporates:
   *  Constant: '<S31>/Constant'
   *  Constant: '<S31>/Constant1'
   */
  double_pend_varible_C(double_pend_varible_P.me, double_pend_varible_P.l,
                        double_pend_varible_B.Integrator4,
                        double_pend_varible_B.Integrator1,
                        &double_pend_varible_B.sf_C_e);

  /* MATLAB Function: '<S31>/G' incorporates:
   *  Constant: '<S31>/Constant'
   */
  double_pend_varible_G(double_pend_varible_P.me,
                        double_pend_varible_B.Integrator4,
                        &double_pend_varible_B.sf_G_p);
  if (rtmIsMajorTimeStep(double_pend_varible_M)) {
  }

  /* MATLAB Function: '<S11>/M1' incorporates:
   *  Constant: '<S11>/Constant2'
   *  Constant: '<S11>/Constant3'
   */
  double_pend_varible_M_l(double_pend_varible_P.mh, double_pend_varible_P.l,
    double_pend_varible_B.Integrator4, &double_pend_varible_B.sf_M1);

  /* MATLAB Function: '<S11>/C' incorporates:
   *  Constant: '<S11>/Constant2'
   *  Constant: '<S11>/Constant3'
   */
  double_pend_varible_C(double_pend_varible_P.mh, double_pend_varible_P.l,
                        double_pend_varible_B.Integrator4,
                        double_pend_varible_B.Integrator1,
                        &double_pend_varible_B.sf_C_i);

  /* MATLAB Function: '<S11>/G' incorporates:
   *  Constant: '<S11>/Constant2'
   */
  double_pend_varible_G(double_pend_varible_P.mh,
                        double_pend_varible_B.Integrator4,
                        &double_pend_varible_B.sf_G_pn);

  /* Sum: '<S11>/Add1' incorporates:
   *  Constant: '<Root>/Constant3'
   *  Product: '<S11>/Product1'
   */
  rtb_Add1[0] = ((double_pend_varible_B.sf_M1.y[0] *
                  double_pend_varible_P.Constant3_Value[0] +
                  double_pend_varible_P.Constant3_Value[1] *
                  double_pend_varible_B.sf_M1.y[2]) +
                 double_pend_varible_B.sf_C_i.y[0]) +
    double_pend_varible_B.sf_G_pn.y[0];
  rtb_Add1[1] = ((double_pend_varible_P.Constant3_Value[0] *
                  double_pend_varible_B.sf_M1.y[1] +
                  double_pend_varible_P.Constant3_Value[1] *
                  double_pend_varible_B.sf_M1.y[3]) +
                 double_pend_varible_B.sf_C_i.y[1]) +
    double_pend_varible_B.sf_G_pn.y[1];

  /* Sum: '<S3>/Sum' */
  temp_idx_0 = rtb_Add1[0] - double_pend_varible_B.Add_b[0];
  rtb_Product3 = rtb_Add1[1] - double_pend_varible_B.Add_b[1];

  /* MATLAB Function: '<S3>/MATLAB Function' incorporates:
   *  Constant: '<S3>/Constant'
   *  Constant: '<S3>/Constant1'
   *  Constant: '<S3>/Constant4'
   *  Constant: '<S3>/Constant5'
   */
  jpvt[0] = 1;
  if (rtb_Trajectorygeneration_o2[0] < 0.0) {
    rtb_Trajectorygeneration_o2[0] = -1.0;
  } else if (rtb_Trajectorygeneration_o2[0] > 0.0) {
    rtb_Trajectorygeneration_o2[0] = 1.0;
  } else if (rtb_Trajectorygeneration_o2[0] == 0.0) {
    rtb_Trajectorygeneration_o2[0] = 0.0;
  } else {
    rtb_Trajectorygeneration_o2[0] = (rtNaN);
  }

  jpvt[1] = 2;
  epsilon = 0.0;
  double_pend_varible_qrpf(rtb_Add1, 1, 1, 2, &epsilon, jpvt);
  rankA = 0;
  rtb_Gain6 = fabs(rtb_Add1[0]);
  if (!(rtb_Gain6 <= 4.4408920985006262E-15 * rtb_Gain6)) {
    rankA = 1;
  }

  imvec_0[0] = 0.0;
  imvec_0[1] = 0.0;
  imvec_0[2] = 0.0;
  imvec_0[3] = 0.0;
  epsilon_idx_0 = temp_idx_0;
  rtb_Product2_idx_0 = rtb_Product3;
  if (epsilon != 0.0) {
    rtb_Gain6 = epsilon * temp_idx_0;
    if (rtb_Gain6 != 0.0) {
      epsilon_idx_0 = temp_idx_0 - rtb_Gain6;
    }

    rtb_Gain6 = epsilon * rtb_Product3;
    if (rtb_Gain6 != 0.0) {
      rtb_Product2_idx_0 = rtb_Product3 - rtb_Gain6;
    }
  }

  if (0 <= rankA - 1) {
    imvec_0[jpvt[0] - 1] = epsilon_idx_0;
  }

  b_i = rankA;
  while (b_i > 0) {
    imvec_0[jpvt[0] - 1] /= rtb_Add1[0];
    b_i = 0;
  }

  if (b_i <= rankA - 1) {
    imvec_0[jpvt[0] + 1] = rtb_Product2_idx_0;
  }

  b_i = rankA;
  while (b_i > 0) {
    imvec_0[jpvt[0] + 1] /= rtb_Add1[0];
    b_i = 0;
  }

  z[0] = imvec_0[0];
  z[1] = imvec_0[2];
  imvec_0[0] = fabs(z[0]);
  double_pend_varible_B.K[0] = 0.0;
  imvec_0[1] = fabs(z[1]);
  double_pend_varible_B.K[1] = 0.0;
  double_pend_varible_B.K[2] = 0.0;
  double_pend_varible_B.K[3] = 0.0;
  double_pend_varible_B.K[0] = 1.0;
  double_pend_varible_B.K[3] = 1.0;
  double_pend_varible_B.B[0] = 0.0;
  double_pend_varible_B.B[1] = 0.0;
  double_pend_varible_B.B[2] = 0.0;
  double_pend_varible_B.B[3] = 0.0;
  double_pend_varible_B.B[0] = 1.0;
  double_pend_varible_B.B[3] = 1.0;
  if (temp_idx_0 < 0.0) {
    epsilon = -1.0;
  } else if (temp_idx_0 > 0.0) {
    epsilon = 1.0;
  } else if (temp_idx_0 == 0.0) {
    epsilon = 0.0;
  } else {
    epsilon = (rtNaN);
  }

  if (epsilon == rtb_Trajectorygeneration_o2[0]) {
    double_pend_varible_B.K[0] = double_pend_varible_P.gamma[0] * imvec_0[0] +
      double_pend_varible_P.Kp0[0];
    double_pend_varible_B.B[0] = double_pend_varible_P.alpha[0] * imvec_0[0] +
      double_pend_varible_P.Kp0[0];
  } else {
    double_pend_varible_B.K[0] = double_pend_varible_P.Kn0[0] - imvec_0[0] *
      double_pend_varible_P.gamma[1];
    double_pend_varible_B.B[0] = 500.0 - imvec_0[0] *
      double_pend_varible_P.alpha[1];
  }

  if (rtb_Product3 < 0.0) {
    epsilon = -1.0;
  } else if (rtb_Product3 > 0.0) {
    epsilon = 1.0;
  } else if (rtb_Product3 == 0.0) {
    epsilon = 0.0;
  } else {
    epsilon = (rtNaN);
  }

  if (rtb_Trajectorygeneration_o2[1] < 0.0) {
    rtb_Gain6 = -1.0;
  } else if (rtb_Trajectorygeneration_o2[1] > 0.0) {
    rtb_Gain6 = 1.0;
  } else if (rtb_Trajectorygeneration_o2[1] == 0.0) {
    rtb_Gain6 = 0.0;
  } else {
    rtb_Gain6 = (rtNaN);
  }

  if (epsilon == rtb_Gain6) {
    double_pend_varible_B.K[3] = double_pend_varible_P.gamma[0] * imvec_0[1] +
      double_pend_varible_P.Kp0[1];
    double_pend_varible_B.B[3] = double_pend_varible_P.alpha[0] * imvec_0[1] +
      double_pend_varible_P.Kp0[1];
  } else {
    double_pend_varible_B.K[3] = double_pend_varible_P.Kn0[1] -
      double_pend_varible_P.gamma[1] * imvec_0[1];
    double_pend_varible_B.B[3] = 500.0 - double_pend_varible_P.alpha[1] *
      imvec_0[1];
  }

  /* End of MATLAB Function: '<S3>/MATLAB Function' */
  if (rtmIsMajorTimeStep(double_pend_varible_M)) {
  }

  /* Sum: '<S3>/Sum6' incorporates:
   *  Integrator: '<S3>/Integrator1'
   *  Product: '<S3>/Product'
   *  Product: '<S3>/Product1'
   *  Sum: '<S3>/Add1'
   */
  temp_idx_0 -= (double_pend_varible_B.K[0] *
                 double_pend_varible_X.Integrator1_CSTATE_j[0] +
                 double_pend_varible_X.Integrator1_CSTATE_j[1] *
                 double_pend_varible_B.K[2]) + (double_pend_varible_B.B[0] *
    double_pend_varible_B.qd_add[0] + double_pend_varible_B.qd_add[1] *
    double_pend_varible_B.B[2]);
  rtb_Product3 -= (double_pend_varible_X.Integrator1_CSTATE_j[0] *
                   double_pend_varible_B.K[1] +
                   double_pend_varible_X.Integrator1_CSTATE_j[1] *
                   double_pend_varible_B.K[3]) + (double_pend_varible_B.qd_add[0]
    * double_pend_varible_B.B[1] + double_pend_varible_B.qd_add[1] *
    double_pend_varible_B.B[3]);

  /* Gain: '<S3>/Gain5' */
  double_pend_varible_B.qd_add_b[0] = 0.0;
  double_pend_varible_B.qd_add_b[0] += double_pend_varible_P.Gain5_Gain[0] *
    temp_idx_0;
  double_pend_varible_B.qd_add_b[0] += double_pend_varible_P.Gain5_Gain[2] *
    rtb_Product3;
  double_pend_varible_B.qd_add_b[1] = 0.0;
  double_pend_varible_B.qd_add_b[1] += double_pend_varible_P.Gain5_Gain[1] *
    temp_idx_0;
  double_pend_varible_B.qd_add_b[1] += double_pend_varible_P.Gain5_Gain[3] *
    rtb_Product3;

  /* MATLAB Function: '<S4>/C' incorporates:
   *  Constant: '<S4>/Constant'
   *  Constant: '<S4>/Constant1'
   */
  double_pend_varible_C(double_pend_varible_P.me, double_pend_varible_P.l,
                        double_pend_varible_B.Integrator4,
                        double_pend_varible_B.Integrator1,
                        &double_pend_varible_B.sf_C);

  /* MATLAB Function: '<S4>/M' incorporates:
   *  Constant: '<S4>/Constant'
   *  Constant: '<S4>/Constant1'
   *  MATLAB Function: '<S4>/G'
   */
  epsilon = cos(double_pend_varible_B.Integrator4[0] -
                double_pend_varible_B.Integrator4[1]);
  rtb_Product3 = double_pend_varible_P.me[0] + double_pend_varible_P.me[1];
  imvec[0] = rtb_Product3 * double_pend_varible_P.l[0];
  rtb_Gain6 = double_pend_varible_P.me[1] * double_pend_varible_P.l[1];
  imvec[2] = rtb_Gain6 * epsilon;
  imvec[1] = double_pend_varible_P.l[0] * double_pend_varible_P.me[1] * epsilon;
  imvec[3] = rtb_Gain6;
  p = true;
  Kn0[0] = 0.0;
  if (rtIsInf(imvec[0]) || rtIsNaN(imvec[0])) {
    p = false;
  }

  Kn0[1] = 0.0;
  if (p && ((!rtIsInf(imvec[1])) && (!rtIsNaN(imvec[1])))) {
  } else {
    p = false;
  }

  Kn0[2] = 0.0;
  if (p && ((!rtIsInf(imvec[2])) && (!rtIsNaN(imvec[2])))) {
  } else {
    p = false;
  }

  Kn0[3] = 0.0;
  if (p && ((!rtIsInf(rtb_Gain6)) && (!rtIsNaN(rtb_Gain6)))) {
  } else {
    p = false;
  }

  if (!p) {
    Kn0[0] = (rtNaN);
    Kn0[1] = (rtNaN);
    Kn0[2] = (rtNaN);
    Kn0[3] = (rtNaN);
  } else {
    double_pend_varible_svd_i(imvec, z, rtb_Trajectorygeneration_o2, imvec_0);
    epsilon = fabs(rtb_Trajectorygeneration_o2[0]);
    if ((!rtIsInf(epsilon)) && (!rtIsNaN(epsilon))) {
      if (epsilon <= 2.2250738585072014E-308) {
        epsilon = 4.94065645841247E-324;
      } else {
        frexp(epsilon, &r);
        epsilon = ldexp(1.0, r - 53);
      }
    } else {
      epsilon = (rtNaN);
    }

    epsilon *= 2.0;
    r = -1;
    rankA = 0;
    while ((rankA < 2) && (rtb_Trajectorygeneration_o2[rankA] > epsilon)) {
      r++;
      rankA++;
    }

    if (r + 1 > 0) {
      i = 0;
      for (rankA = 0; rankA <= r; rankA++) {
        epsilon = 1.0 / rtb_Trajectorygeneration_o2[rankA];
        for (b_i = i; b_i < i + 2; b_i++) {
          imvec_0[b_i] *= epsilon;
        }

        i += 2;
      }

      for (b_i = 0; b_i < 2; b_i++) {
        Kn0[b_i] = 0.0;
      }

      for (b_i = 2; b_i < 4; b_i++) {
        Kn0[b_i] = 0.0;
      }

      i = -1;
      r <<= 1;
      for (b_i = 1; b_i <= r + 1; b_i += 2) {
        rankA = i;
        for (A_tmp_tmp = 0; A_tmp_tmp < 2; A_tmp_tmp++) {
          rankA++;
          Kn0[A_tmp_tmp] += z[b_i - 1] * imvec_0[rankA];
        }

        i += 2;
      }

      i = -1;
      for (b_i = 2; b_i <= r + 2; b_i += 2) {
        rankA = i;
        for (A_tmp_tmp = 2; A_tmp_tmp < 4; A_tmp_tmp++) {
          rankA++;
          Kn0[A_tmp_tmp] += z[b_i - 1] * imvec_0[rankA];
        }

        i += 2;
      }
    }
  }

  /* End of MATLAB Function: '<S4>/M' */

  /* MATLABSystem: '<Root>/Trajectory generation' */
  double_pend_varible_ppval_i(newBreaks, ddCoefs, rtb_Clock1,
    rtb_Trajectorygeneration_o2);

  /* Sum: '<S10>/Add1' incorporates:
   *  Gain: '<S10>/Gain12'
   *  Gain: '<S10>/Gain4'
   *  Sum: '<S3>/Sum2'
   *  Trigonometry: '<S10>/Tanh'
   */
  rtb_Gain6 = (rtb_Trajectorygeneration_o2[0] - (double_pend_varible_P.rho2[0] *
    double_pend_varible_B.Tanh[0] + double_pend_varible_B.Tanh[1] *
    double_pend_varible_P.rho2[2])) - (double_pend_varible_P.lambda2[0] *
    double_pend_varible_B.q_add_a[0] + double_pend_varible_B.q_add_a[1] *
    double_pend_varible_P.lambda2[2]);
  temp_idx_0 = (rtb_Trajectorygeneration_o2[1] - (double_pend_varible_B.Tanh[0] *
    double_pend_varible_P.rho2[1] + double_pend_varible_B.Tanh[1] *
    double_pend_varible_P.rho2[3])) - (double_pend_varible_B.q_add_a[0] *
    double_pend_varible_P.lambda2[1] + double_pend_varible_B.q_add_a[1] *
    double_pend_varible_P.lambda2[3]);

  /* Sum: '<Root>/Sum' incorporates:
   *  Product: '<S31>/Product'
   *  Sum: '<S31>/Add2'
   */
  rtb_Clock1 = (((double_pend_varible_B.sf_M_l.y[0] * rtb_Gain6 +
                  double_pend_varible_B.sf_M_l.y[2] * temp_idx_0) +
                 double_pend_varible_B.sf_C_e.y[0]) +
                double_pend_varible_B.sf_G_p.y[0]) -
    double_pend_varible_B.Add_b[0];
  temp_idx_0 = (((double_pend_varible_B.sf_M_l.y[1] * rtb_Gain6 +
                  double_pend_varible_B.sf_M_l.y[3] * temp_idx_0) +
                 double_pend_varible_B.sf_C_e.y[1]) +
                double_pend_varible_B.sf_G_p.y[1]) -
    double_pend_varible_B.Add_b[1];

  /* Saturate: '<Root>/Saturation' */
  if (rtb_Clock1 > double_pend_varible_P.exo_sat) {
    rtb_Clock1 = double_pend_varible_P.exo_sat;
  } else if (rtb_Clock1 < -double_pend_varible_P.exo_sat) {
    rtb_Clock1 = -double_pend_varible_P.exo_sat;
  }

  /* Sum: '<S4>/Add2' incorporates:
   *  MATLAB Function: '<S4>/G'
   *  Saturate: '<Root>/Saturation'
   */
  rtb_Gain6 = (rtb_Clock1 - (rtb_Product3 * 9.81 * tmp_0 + 50.0)) -
    double_pend_varible_B.sf_C.y[0];

  /* Saturate: '<Root>/Saturation' */
  if (temp_idx_0 > double_pend_varible_P.exo_sat) {
    temp_idx_0 = double_pend_varible_P.exo_sat;
  } else if (temp_idx_0 < -double_pend_varible_P.exo_sat) {
    temp_idx_0 = -double_pend_varible_P.exo_sat;
  }

  /* Sum: '<S4>/Add2' incorporates:
   *  Constant: '<S4>/Constant'
   *  MATLAB Function: '<S4>/G'
   *  Saturate: '<Root>/Saturation'
   */
  temp_idx_0 = (temp_idx_0 - (double_pend_varible_P.me[1] * 9.81 * tmp + 50.0))
    - double_pend_varible_B.sf_C.y[1];

  /* Product: '<S4>/Product1' */
  double_pend_varible_B.Product1[0] = 0.0;
  double_pend_varible_B.Product1[0] += Kn0[0] * rtb_Gain6;
  double_pend_varible_B.Product1[0] += Kn0[2] * temp_idx_0;
  double_pend_varible_B.Product1[1] = 0.0;
  double_pend_varible_B.Product1[1] += Kn0[1] * rtb_Gain6;
  double_pend_varible_B.Product1[1] += Kn0[3] * temp_idx_0;
  if (rtmIsMajorTimeStep(double_pend_varible_M)) {
  }

  /* Signum: '<S10>/Sign' incorporates:
   *  Sum: '<S10>/Add'
   */
  if (double_pend_varible_B.Add_j[0] < 0.0) {
    /* Signum: '<S10>/Sign' */
    double_pend_varible_B.Sign[0] = -1.0;
  } else if (double_pend_varible_B.Add_j[0] > 0.0) {
    /* Signum: '<S10>/Sign' */
    double_pend_varible_B.Sign[0] = 1.0;
  } else if (double_pend_varible_B.Add_j[0] == 0.0) {
    /* Signum: '<S10>/Sign' */
    double_pend_varible_B.Sign[0] = 0.0;
  } else {
    /* Signum: '<S10>/Sign' */
    double_pend_varible_B.Sign[0] = (rtNaN);
  }

  if (double_pend_varible_B.Add_j[1] < 0.0) {
    /* Signum: '<S10>/Sign' */
    double_pend_varible_B.Sign[1] = -1.0;
  } else if (double_pend_varible_B.Add_j[1] > 0.0) {
    /* Signum: '<S10>/Sign' */
    double_pend_varible_B.Sign[1] = 1.0;
  } else if (double_pend_varible_B.Add_j[1] == 0.0) {
    /* Signum: '<S10>/Sign' */
    double_pend_varible_B.Sign[1] = 0.0;
  } else {
    /* Signum: '<S10>/Sign' */
    double_pend_varible_B.Sign[1] = (rtNaN);
  }

  /* End of Signum: '<S10>/Sign' */
  if (rtmIsMajorTimeStep(double_pend_varible_M)) {
  }

  if (rtmIsMajorTimeStep(double_pend_varible_M)) {
    /* Matfile logging */
    rt_UpdateTXYLogVars(double_pend_varible_M->rtwLogInfo,
                        (double_pend_varible_M->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(double_pend_varible_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(double_pend_varible_M)!=-1) &&
          !((rtmGetTFinal(double_pend_varible_M)-
             (((double_pend_varible_M->Timing.clockTick1+
                double_pend_varible_M->Timing.clockTickH1* 4294967296.0)) * 0.01))
            > (((double_pend_varible_M->Timing.clockTick1+
                 double_pend_varible_M->Timing.clockTickH1* 4294967296.0)) *
               0.01) * (DBL_EPSILON))) {
        rtmSetErrorStatus(double_pend_varible_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&double_pend_varible_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++double_pend_varible_M->Timing.clockTick0)) {
      ++double_pend_varible_M->Timing.clockTickH0;
    }

    double_pend_varible_M->Timing.t[0] = rtsiGetSolverStopTime
      (&double_pend_varible_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.01s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.01, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      double_pend_varible_M->Timing.clockTick1++;
      if (!double_pend_varible_M->Timing.clockTick1) {
        double_pend_varible_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void double_pend_varible_derivatives(void)
{
  XDot_double_pend_varible_T *_rtXdot;
  _rtXdot = ((XDot_double_pend_varible_T *) double_pend_varible_M->derivs);

  /* Derivatives for Integrator: '<S4>/Integrator4' incorporates:
   *  Integrator: '<S4>/Integrator1'
   */
  _rtXdot->Integrator4_CSTATE[0] = double_pend_varible_B.Integrator1[0];

  /* Derivatives for Integrator: '<S4>/Integrator1' incorporates:
   *  Product: '<S4>/Product1'
   */
  _rtXdot->Integrator1_CSTATE[0] = double_pend_varible_B.Product1[0];

  /* Derivatives for Integrator: '<S3>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_j[0] = double_pend_varible_B.qd_add[0];

  /* Derivatives for Integrator: '<S3>/Integrator' */
  _rtXdot->Integrator_CSTATE[0] = double_pend_varible_B.qd_add_b[0];

  /* Derivatives for Integrator: '<S4>/Integrator4' incorporates:
   *  Integrator: '<S4>/Integrator1'
   */
  _rtXdot->Integrator4_CSTATE[1] = double_pend_varible_B.Integrator1[1];

  /* Derivatives for Integrator: '<S4>/Integrator1' incorporates:
   *  Product: '<S4>/Product1'
   */
  _rtXdot->Integrator1_CSTATE[1] = double_pend_varible_B.Product1[1];

  /* Derivatives for Integrator: '<S3>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_j[1] = double_pend_varible_B.qd_add[1];

  /* Derivatives for Integrator: '<S3>/Integrator' */
  _rtXdot->Integrator_CSTATE[1] = double_pend_varible_B.qd_add_b[1];
}

/* Model initialize function */
void double_pend_varible_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)double_pend_varible_M, 0,
                sizeof(RT_MODEL_double_pend_varible_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&double_pend_varible_M->solverInfo,
                          &double_pend_varible_M->Timing.simTimeStep);
    rtsiSetTPtr(&double_pend_varible_M->solverInfo, &rtmGetTPtr
                (double_pend_varible_M));
    rtsiSetStepSizePtr(&double_pend_varible_M->solverInfo,
                       &double_pend_varible_M->Timing.stepSize0);
    rtsiSetdXPtr(&double_pend_varible_M->solverInfo,
                 &double_pend_varible_M->derivs);
    rtsiSetContStatesPtr(&double_pend_varible_M->solverInfo, (real_T **)
                         &double_pend_varible_M->contStates);
    rtsiSetNumContStatesPtr(&double_pend_varible_M->solverInfo,
      &double_pend_varible_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&double_pend_varible_M->solverInfo,
      &double_pend_varible_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&double_pend_varible_M->solverInfo,
      &double_pend_varible_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&double_pend_varible_M->solverInfo,
      &double_pend_varible_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&double_pend_varible_M->solverInfo,
                          (&rtmGetErrorStatus(double_pend_varible_M)));
    rtsiSetRTModelPtr(&double_pend_varible_M->solverInfo, double_pend_varible_M);
  }

  rtsiSetSimTimeStep(&double_pend_varible_M->solverInfo, MAJOR_TIME_STEP);
  double_pend_varible_M->intgData.y = double_pend_varible_M->odeY;
  double_pend_varible_M->intgData.f[0] = double_pend_varible_M->odeF[0];
  double_pend_varible_M->intgData.f[1] = double_pend_varible_M->odeF[1];
  double_pend_varible_M->intgData.f[2] = double_pend_varible_M->odeF[2];
  double_pend_varible_M->contStates = ((X_double_pend_varible_T *)
    &double_pend_varible_X);
  rtsiSetSolverData(&double_pend_varible_M->solverInfo, (void *)
                    &double_pend_varible_M->intgData);
  rtsiSetSolverName(&double_pend_varible_M->solverInfo,"ode3");
  rtmSetTPtr(double_pend_varible_M, &double_pend_varible_M->Timing.tArray[0]);
  rtmSetTFinal(double_pend_varible_M, 10.0);
  double_pend_varible_M->Timing.stepSize0 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    double_pend_varible_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(double_pend_varible_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(double_pend_varible_M->rtwLogInfo, (NULL));
    rtliSetLogT(double_pend_varible_M->rtwLogInfo, "tout");
    rtliSetLogX(double_pend_varible_M->rtwLogInfo, "");
    rtliSetLogXFinal(double_pend_varible_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(double_pend_varible_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(double_pend_varible_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(double_pend_varible_M->rtwLogInfo, 0);
    rtliSetLogDecimation(double_pend_varible_M->rtwLogInfo, 1);
    rtliSetLogY(double_pend_varible_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(double_pend_varible_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(double_pend_varible_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &double_pend_varible_B), 0,
                sizeof(B_double_pend_varible_T));

  /* states (continuous) */
  {
    (void) memset((void *)&double_pend_varible_X, 0,
                  sizeof(X_double_pend_varible_T));
  }

  /* states (dwork) */
  (void) memset((void *)&double_pend_varible_DW, 0,
                sizeof(DW_double_pend_varible_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(double_pend_varible_M->rtwLogInfo, 0.0,
    rtmGetTFinal(double_pend_varible_M), double_pend_varible_M->Timing.stepSize0,
    (&rtmGetErrorStatus(double_pend_varible_M)));

  /* Start for DataStoreMemory: '<S16>/DataStoreMemory - P' */
  memcpy(&double_pend_varible_DW.P[0],
         &double_pend_varible_P.DataStoreMemoryP_InitialValue[0], sizeof(real_T)
         << 4U);

  /* Start for DataStoreMemory: '<S16>/DataStoreMemory - x' */
  double_pend_varible_DW.x[0] =
    double_pend_varible_P.DataStoreMemoryx_InitialValue[0];
  double_pend_varible_DW.x[1] =
    double_pend_varible_P.DataStoreMemoryx_InitialValue[1];
  double_pend_varible_DW.x[2] =
    double_pend_varible_P.DataStoreMemoryx_InitialValue[2];
  double_pend_varible_DW.x[3] =
    double_pend_varible_P.DataStoreMemoryx_InitialValue[3];

  {
    int32_T i;

    /* InitializeConditions for Integrator: '<S4>/Integrator4' */
    double_pend_varible_X.Integrator4_CSTATE[0] =
      double_pend_varible_P.Integrator4_IC[0];

    /* InitializeConditions for Integrator: '<S4>/Integrator1' */
    double_pend_varible_X.Integrator1_CSTATE[0] =
      double_pend_varible_P.Integrator1_IC[0];

    /* InitializeConditions for Integrator: '<S3>/Integrator1' */
    double_pend_varible_X.Integrator1_CSTATE_j[0] =
      double_pend_varible_P.Integrator1_IC_n[0];

    /* InitializeConditions for Integrator: '<S3>/Integrator' */
    double_pend_varible_X.Integrator_CSTATE[0] =
      double_pend_varible_P.Integrator_IC;

    /* InitializeConditions for Integrator: '<S4>/Integrator4' */
    double_pend_varible_X.Integrator4_CSTATE[1] =
      double_pend_varible_P.Integrator4_IC[1];

    /* InitializeConditions for Integrator: '<S4>/Integrator1' */
    double_pend_varible_X.Integrator1_CSTATE[1] =
      double_pend_varible_P.Integrator1_IC[1];

    /* InitializeConditions for Integrator: '<S3>/Integrator1' */
    double_pend_varible_X.Integrator1_CSTATE_j[1] =
      double_pend_varible_P.Integrator1_IC_n[1];

    /* InitializeConditions for Integrator: '<S3>/Integrator' */
    double_pend_varible_X.Integrator_CSTATE[1] =
      double_pend_varible_P.Integrator_IC;

    /* Start for MATLABSystem: '<Root>/Trajectory generation' */
    memset(&double_pend_varible_DW.obj.AccelerationBoundaryCondition[0], 0, 10U *
           sizeof(real_T));
    double_pend_varible_DW.obj.isInitialized = 0;
    double_pend_varible_DW.objisempty = true;
    for (i = 0; i < 6; i++) {
      double_pend_varible_DW.obj.Waypoints[i] =
        double_pend_varible_P.Trajectorygeneration_Waypoints[i];
    }

    double_pend_varible_DW.obj.TimePoints[0] =
      double_pend_varible_P.Trajectorygeneration_TimePoints[0];
    double_pend_varible_DW.obj.TimePoints[1] =
      double_pend_varible_P.Trajectorygeneration_TimePoints[1];
    double_pend_varible_DW.obj.TimePoints[2] =
      double_pend_varible_P.Trajectorygeneration_TimePoints[2];
    for (i = 0; i < 6; i++) {
      double_pend_varible_DW.obj.VelocityBoundaryCondition[i] =
        double_pend_varible_P.Trajectorygeneration_VelocityBo[i];
    }

    double_pend_varible_DW.obj.isInitialized = 1;
    double_pend_varible_DW.obj.TunablePropsChanged = false;

    /* End of Start for MATLABSystem: '<Root>/Trajectory generation' */
  }
}

/* Model terminate function */
void double_pend_varible_terminate(void)
{
  /* (no terminate code required) */
}
