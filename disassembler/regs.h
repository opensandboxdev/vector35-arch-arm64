#pragma once

#include <stddef.h>

#ifdef _MSC_VER
#undef REG_NONE // collides with winnt's define
#endif

#ifdef __riscv
// On RISC-V musl defines REG_SP/REG_S0 in signal.h.
// Similarily, glibc defines REG_SP/REG_S0 in sys/ucontext.h.
#undef REG_SP
#undef REG_S0
#endif

//-----------------------------------------------------------------------------
// registers (non-system)
//-----------------------------------------------------------------------------

enum Register {
	REG_NONE,
	REG_W0,  REG_W1,  REG_W2,  REG_W3,  REG_W4,  REG_W5,  REG_W6,  REG_W7,
	REG_W8,  REG_W9,  REG_W10, REG_W11, REG_W12, REG_W13, REG_W14, REG_W15,
	REG_W16, REG_W17, REG_W18, REG_W19, REG_W20, REG_W21, REG_W22, REG_W23,
	REG_W24, REG_W25, REG_W26, REG_W27, REG_W28, REG_W29, REG_W30, REG_WZR, REG_WSP,
	REG_X0,  REG_X1,  REG_X2,  REG_X3,  REG_X4,  REG_X5,  REG_X6,  REG_X7,
	REG_X8,  REG_X9,  REG_X10, REG_X11, REG_X12, REG_X13, REG_X14, REG_X15,
	REG_X16, REG_X17, REG_X18, REG_X19, REG_X20, REG_X21, REG_X22, REG_X23,
	REG_X24, REG_X25, REG_X26, REG_X27, REG_X28, REG_X29, REG_X30, REG_XZR, REG_SP,
	REG_V0,  REG_V1,  REG_V2,  REG_V3,  REG_V4,  REG_V5,  REG_V6,  REG_V7,
	REG_V8,  REG_V9,  REG_V10, REG_V11, REG_V12, REG_V13, REG_V14, REG_V15,
	REG_V16, REG_V17, REG_V18, REG_V19, REG_V20, REG_V21, REG_V22, REG_V23,
	REG_V24, REG_V25, REG_V26, REG_V27, REG_V28, REG_V29, REG_V30, REG_VZR, REG_V31,
	REG_B0,  REG_B1,  REG_B2,  REG_B3,  REG_B4,  REG_B5,  REG_B6,  REG_B7,
	REG_B8,  REG_B9,  REG_B10, REG_B11, REG_B12, REG_B13, REG_B14, REG_B15,
	REG_B16, REG_B17, REG_B18, REG_B19, REG_B20, REG_B21, REG_B22, REG_B23,
	REG_B24, REG_B25, REG_B26, REG_B27, REG_B28, REG_B29, REG_B30, REG_BZR, REG_B31,
	REG_H0,  REG_H1,  REG_H2,  REG_H3,  REG_H4,  REG_H5,  REG_H6,  REG_H7,
	REG_H8,  REG_H9,  REG_H10, REG_H11, REG_H12, REG_H13, REG_H14, REG_H15,
	REG_H16, REG_H17, REG_H18, REG_H19, REG_H20, REG_H21, REG_H22, REG_H23,
	REG_H24, REG_H25, REG_H26, REG_H27, REG_H28, REG_H29, REG_H30, REG_HZR, REG_H31,
	REG_S0,  REG_S1,  REG_S2,  REG_S3,  REG_S4,  REG_S5,  REG_S6,  REG_S7,
	REG_S8,  REG_S9,  REG_S10, REG_S11, REG_S12, REG_S13, REG_S14, REG_S15,
	REG_S16, REG_S17, REG_S18, REG_S19, REG_S20, REG_S21, REG_S22, REG_S23,
	REG_S24, REG_S25, REG_S26, REG_S27, REG_S28, REG_S29, REG_S30, REG_SZR, REG_S31,
	REG_D0,  REG_D1,  REG_D2,  REG_D3,  REG_D4,  REG_D5,  REG_D6,  REG_D7,
	REG_D8,  REG_D9,  REG_D10, REG_D11, REG_D12, REG_D13, REG_D14, REG_D15,
	REG_D16, REG_D17, REG_D18, REG_D19, REG_D20, REG_D21, REG_D22, REG_D23,
	REG_D24, REG_D25, REG_D26, REG_D27, REG_D28, REG_D29, REG_D30, REG_DZR, REG_D31,
	REG_Q0,  REG_Q1,  REG_Q2,  REG_Q3,  REG_Q4,  REG_Q5,  REG_Q6,  REG_Q7,
	REG_Q8,  REG_Q9,  REG_Q10, REG_Q11, REG_Q12, REG_Q13, REG_Q14, REG_Q15,
	REG_Q16, REG_Q17, REG_Q18, REG_Q19, REG_Q20, REG_Q21, REG_Q22, REG_Q23,
	REG_Q24, REG_Q25, REG_Q26, REG_Q27, REG_Q28, REG_Q29, REG_Q30, REG_QZR, REG_Q31,
	// B vector
	REG_V0_B0, REG_V0_B1, REG_V0_B2, REG_V0_B3, REG_V0_B4, REG_V0_B5, REG_V0_B6, REG_V0_B7,
	REG_V0_B8, REG_V0_B9, REG_V0_B10, REG_V0_B11, REG_V0_B12, REG_V0_B13, REG_V0_B14, REG_V0_B15,
	REG_V1_B0, REG_V1_B1, REG_V1_B2, REG_V1_B3, REG_V1_B4, REG_V1_B5, REG_V1_B6, REG_V1_B7,
	REG_V1_B8, REG_V1_B9, REG_V1_B10, REG_V1_B11, REG_V1_B12, REG_V1_B13, REG_V1_B14, REG_V1_B15,
	REG_V2_B0, REG_V2_B1, REG_V2_B2, REG_V2_B3, REG_V2_B4, REG_V2_B5, REG_V2_B6, REG_V2_B7,
	REG_V2_B8, REG_V2_B9, REG_V2_B10, REG_V2_B11, REG_V2_B12, REG_V2_B13, REG_V2_B14, REG_V2_B15,
	REG_V3_B0, REG_V3_B1, REG_V3_B2, REG_V3_B3, REG_V3_B4, REG_V3_B5, REG_V3_B6, REG_V3_B7,
	REG_V3_B8, REG_V3_B9, REG_V3_B10, REG_V3_B11, REG_V3_B12, REG_V3_B13, REG_V3_B14, REG_V3_B15,
	REG_V4_B0, REG_V4_B1, REG_V4_B2, REG_V4_B3, REG_V4_B4, REG_V4_B5, REG_V4_B6, REG_V4_B7,
	REG_V4_B8, REG_V4_B9, REG_V4_B10, REG_V4_B11, REG_V4_B12, REG_V4_B13, REG_V4_B14, REG_V4_B15,
	REG_V5_B0, REG_V5_B1, REG_V5_B2, REG_V5_B3, REG_V5_B4, REG_V5_B5, REG_V5_B6, REG_V5_B7,
	REG_V5_B8, REG_V5_B9, REG_V5_B10, REG_V5_B11, REG_V5_B12, REG_V5_B13, REG_V5_B14, REG_V5_B15,
	REG_V6_B0, REG_V6_B1, REG_V6_B2, REG_V6_B3, REG_V6_B4, REG_V6_B5, REG_V6_B6, REG_V6_B7,
	REG_V6_B8, REG_V6_B9, REG_V6_B10, REG_V6_B11, REG_V6_B12, REG_V6_B13, REG_V6_B14, REG_V6_B15,
	REG_V7_B0, REG_V7_B1, REG_V7_B2, REG_V7_B3, REG_V7_B4, REG_V7_B5, REG_V7_B6, REG_V7_B7,
	REG_V7_B8, REG_V7_B9, REG_V7_B10, REG_V7_B11, REG_V7_B12, REG_V7_B13, REG_V7_B14, REG_V7_B15,
	REG_V8_B0, REG_V8_B1, REG_V8_B2, REG_V8_B3, REG_V8_B4, REG_V8_B5, REG_V8_B6, REG_V8_B7,
	REG_V8_B8, REG_V8_B9, REG_V8_B10, REG_V8_B11, REG_V8_B12, REG_V8_B13, REG_V8_B14, REG_V8_B15,
	REG_V9_B0, REG_V9_B1, REG_V9_B2, REG_V9_B3, REG_V9_B4, REG_V9_B5, REG_V9_B6, REG_V9_B7,
	REG_V9_B8, REG_V9_B9, REG_V9_B10, REG_V9_B11, REG_V9_B12, REG_V9_B13, REG_V9_B14, REG_V9_B15,
	REG_V10_B0, REG_V10_B1, REG_V10_B2, REG_V10_B3, REG_V10_B4, REG_V10_B5, REG_V10_B6, REG_V10_B7,
	REG_V10_B8, REG_V10_B9, REG_V10_B10, REG_V10_B11, REG_V10_B12, REG_V10_B13, REG_V10_B14, REG_V10_B15,
	REG_V11_B0, REG_V11_B1, REG_V11_B2, REG_V11_B3, REG_V11_B4, REG_V11_B5, REG_V11_B6, REG_V11_B7,
	REG_V11_B8, REG_V11_B9, REG_V11_B10, REG_V11_B11, REG_V11_B12, REG_V11_B13, REG_V11_B14, REG_V11_B15,
	REG_V12_B0, REG_V12_B1, REG_V12_B2, REG_V12_B3, REG_V12_B4, REG_V12_B5, REG_V12_B6, REG_V12_B7,
	REG_V12_B8, REG_V12_B9, REG_V12_B10, REG_V12_B11, REG_V12_B12, REG_V12_B13, REG_V12_B14, REG_V12_B15,
	REG_V13_B0, REG_V13_B1, REG_V13_B2, REG_V13_B3, REG_V13_B4, REG_V13_B5, REG_V13_B6, REG_V13_B7,
	REG_V13_B8, REG_V13_B9, REG_V13_B10, REG_V13_B11, REG_V13_B12, REG_V13_B13, REG_V13_B14, REG_V13_B15,
	REG_V14_B0, REG_V14_B1, REG_V14_B2, REG_V14_B3, REG_V14_B4, REG_V14_B5, REG_V14_B6, REG_V14_B7,
	REG_V14_B8, REG_V14_B9, REG_V14_B10, REG_V14_B11, REG_V14_B12, REG_V14_B13, REG_V14_B14, REG_V14_B15,
	REG_V15_B0, REG_V15_B1, REG_V15_B2, REG_V15_B3, REG_V15_B4, REG_V15_B5, REG_V15_B6, REG_V15_B7,
	REG_V15_B8, REG_V15_B9, REG_V15_B10, REG_V15_B11, REG_V15_B12, REG_V15_B13, REG_V15_B14, REG_V15_B15,
	REG_V16_B0, REG_V16_B1, REG_V16_B2, REG_V16_B3, REG_V16_B4, REG_V16_B5, REG_V16_B6, REG_V16_B7,
	REG_V16_B8, REG_V16_B9, REG_V16_B10, REG_V16_B11, REG_V16_B12, REG_V16_B13, REG_V16_B14, REG_V16_B15,
	REG_V17_B0, REG_V17_B1, REG_V17_B2, REG_V17_B3, REG_V17_B4, REG_V17_B5, REG_V17_B6, REG_V17_B7,
	REG_V17_B8, REG_V17_B9, REG_V17_B10, REG_V17_B11, REG_V17_B12, REG_V17_B13, REG_V17_B14, REG_V17_B15,
	REG_V18_B0, REG_V18_B1, REG_V18_B2, REG_V18_B3, REG_V18_B4, REG_V18_B5, REG_V18_B6, REG_V18_B7,
	REG_V18_B8, REG_V18_B9, REG_V18_B10, REG_V18_B11, REG_V18_B12, REG_V18_B13, REG_V18_B14, REG_V18_B15,
	REG_V19_B0, REG_V19_B1, REG_V19_B2, REG_V19_B3, REG_V19_B4, REG_V19_B5, REG_V19_B6, REG_V19_B7,
	REG_V19_B8, REG_V19_B9, REG_V19_B10, REG_V19_B11, REG_V19_B12, REG_V19_B13, REG_V19_B14, REG_V19_B15,
	REG_V20_B0, REG_V20_B1, REG_V20_B2, REG_V20_B3, REG_V20_B4, REG_V20_B5, REG_V20_B6, REG_V20_B7,
	REG_V20_B8, REG_V20_B9, REG_V20_B10, REG_V20_B11, REG_V20_B12, REG_V20_B13, REG_V20_B14, REG_V20_B15,
	REG_V21_B0, REG_V21_B1, REG_V21_B2, REG_V21_B3, REG_V21_B4, REG_V21_B5, REG_V21_B6, REG_V21_B7,
	REG_V21_B8, REG_V21_B9, REG_V21_B10, REG_V21_B11, REG_V21_B12, REG_V21_B13, REG_V21_B14, REG_V21_B15,
	REG_V22_B0, REG_V22_B1, REG_V22_B2, REG_V22_B3, REG_V22_B4, REG_V22_B5, REG_V22_B6, REG_V22_B7,
	REG_V22_B8, REG_V22_B9, REG_V22_B10, REG_V22_B11, REG_V22_B12, REG_V22_B13, REG_V22_B14, REG_V22_B15,
	REG_V23_B0, REG_V23_B1, REG_V23_B2, REG_V23_B3, REG_V23_B4, REG_V23_B5, REG_V23_B6, REG_V23_B7,
	REG_V23_B8, REG_V23_B9, REG_V23_B10, REG_V23_B11, REG_V23_B12, REG_V23_B13, REG_V23_B14, REG_V23_B15,
	REG_V24_B0, REG_V24_B1, REG_V24_B2, REG_V24_B3, REG_V24_B4, REG_V24_B5, REG_V24_B6, REG_V24_B7,
	REG_V24_B8, REG_V24_B9, REG_V24_B10, REG_V24_B11, REG_V24_B12, REG_V24_B13, REG_V24_B14, REG_V24_B15,
	REG_V25_B0, REG_V25_B1, REG_V25_B2, REG_V25_B3, REG_V25_B4, REG_V25_B5, REG_V25_B6, REG_V25_B7,
	REG_V25_B8, REG_V25_B9, REG_V25_B10, REG_V25_B11, REG_V25_B12, REG_V25_B13, REG_V25_B14, REG_V25_B15,
	REG_V26_B0, REG_V26_B1, REG_V26_B2, REG_V26_B3, REG_V26_B4, REG_V26_B5, REG_V26_B6, REG_V26_B7,
	REG_V26_B8, REG_V26_B9, REG_V26_B10, REG_V26_B11, REG_V26_B12, REG_V26_B13, REG_V26_B14, REG_V26_B15,
	REG_V27_B0, REG_V27_B1, REG_V27_B2, REG_V27_B3, REG_V27_B4, REG_V27_B5, REG_V27_B6, REG_V27_B7,
	REG_V27_B8, REG_V27_B9, REG_V27_B10, REG_V27_B11, REG_V27_B12, REG_V27_B13, REG_V27_B14, REG_V27_B15,
	REG_V28_B0, REG_V28_B1, REG_V28_B2, REG_V28_B3, REG_V28_B4, REG_V28_B5, REG_V28_B6, REG_V28_B7,
	REG_V28_B8, REG_V28_B9, REG_V28_B10, REG_V28_B11, REG_V28_B12, REG_V28_B13, REG_V28_B14, REG_V28_B15,
	REG_V29_B0, REG_V29_B1, REG_V29_B2, REG_V29_B3, REG_V29_B4, REG_V29_B5, REG_V29_B6, REG_V29_B7,
	REG_V29_B8, REG_V29_B9, REG_V29_B10, REG_V29_B11, REG_V29_B12, REG_V29_B13, REG_V29_B14, REG_V29_B15,
	REG_V30_B0, REG_V30_B1, REG_V30_B2, REG_V30_B3, REG_V30_B4, REG_V30_B5, REG_V30_B6, REG_V30_B7,
	REG_V30_B8, REG_V30_B9, REG_V30_B10, REG_V30_B11, REG_V30_B12, REG_V30_B13, REG_V30_B14, REG_V30_B15,
	REG_V31_B0, REG_V31_B1, REG_V31_B2, REG_V31_B3, REG_V31_B4, REG_V31_B5, REG_V31_B6, REG_V31_B7,
	REG_V31_B8, REG_V31_B9, REG_V31_B10, REG_V31_B11, REG_V31_B12, REG_V31_B13, REG_V31_B14, REG_V31_B15,
	// H vector
	REG_V0_H0, REG_V0_H1, REG_V0_H2, REG_V0_H3, REG_V0_H4, REG_V0_H5, REG_V0_H6, REG_V0_H7,
	REG_V1_H0, REG_V1_H1, REG_V1_H2, REG_V1_H3, REG_V1_H4, REG_V1_H5, REG_V1_H6, REG_V1_H7,
	REG_V2_H0, REG_V2_H1, REG_V2_H2, REG_V2_H3, REG_V2_H4, REG_V2_H5, REG_V2_H6, REG_V2_H7,
	REG_V3_H0, REG_V3_H1, REG_V3_H2, REG_V3_H3, REG_V3_H4, REG_V3_H5, REG_V3_H6, REG_V3_H7,
	REG_V4_H0, REG_V4_H1, REG_V4_H2, REG_V4_H3, REG_V4_H4, REG_V4_H5, REG_V4_H6, REG_V4_H7,
	REG_V5_H0, REG_V5_H1, REG_V5_H2, REG_V5_H3, REG_V5_H4, REG_V5_H5, REG_V5_H6, REG_V5_H7,
	REG_V6_H0, REG_V6_H1, REG_V6_H2, REG_V6_H3, REG_V6_H4, REG_V6_H5, REG_V6_H6, REG_V6_H7,
	REG_V7_H0, REG_V7_H1, REG_V7_H2, REG_V7_H3, REG_V7_H4, REG_V7_H5, REG_V7_H6, REG_V7_H7,
	REG_V8_H0, REG_V8_H1, REG_V8_H2, REG_V8_H3, REG_V8_H4, REG_V8_H5, REG_V8_H6, REG_V8_H7,
	REG_V9_H0, REG_V9_H1, REG_V9_H2, REG_V9_H3, REG_V9_H4, REG_V9_H5, REG_V9_H6, REG_V9_H7,
	REG_V10_H0, REG_V10_H1, REG_V10_H2, REG_V10_H3, REG_V10_H4, REG_V10_H5, REG_V10_H6, REG_V10_H7,
	REG_V11_H0, REG_V11_H1, REG_V11_H2, REG_V11_H3, REG_V11_H4, REG_V11_H5, REG_V11_H6, REG_V11_H7,
	REG_V12_H0, REG_V12_H1, REG_V12_H2, REG_V12_H3, REG_V12_H4, REG_V12_H5, REG_V12_H6, REG_V12_H7,
	REG_V13_H0, REG_V13_H1, REG_V13_H2, REG_V13_H3, REG_V13_H4, REG_V13_H5, REG_V13_H6, REG_V13_H7,
	REG_V14_H0, REG_V14_H1, REG_V14_H2, REG_V14_H3, REG_V14_H4, REG_V14_H5, REG_V14_H6, REG_V14_H7,
	REG_V15_H0, REG_V15_H1, REG_V15_H2, REG_V15_H3, REG_V15_H4, REG_V15_H5, REG_V15_H6, REG_V15_H7,
	REG_V16_H0, REG_V16_H1, REG_V16_H2, REG_V16_H3, REG_V16_H4, REG_V16_H5, REG_V16_H6, REG_V16_H7,
	REG_V17_H0, REG_V17_H1, REG_V17_H2, REG_V17_H3, REG_V17_H4, REG_V17_H5, REG_V17_H6, REG_V17_H7,
	REG_V18_H0, REG_V18_H1, REG_V18_H2, REG_V18_H3, REG_V18_H4, REG_V18_H5, REG_V18_H6, REG_V18_H7,
	REG_V19_H0, REG_V19_H1, REG_V19_H2, REG_V19_H3, REG_V19_H4, REG_V19_H5, REG_V19_H6, REG_V19_H7,
	REG_V20_H0, REG_V20_H1, REG_V20_H2, REG_V20_H3, REG_V20_H4, REG_V20_H5, REG_V20_H6, REG_V20_H7,
	REG_V21_H0, REG_V21_H1, REG_V21_H2, REG_V21_H3, REG_V21_H4, REG_V21_H5, REG_V21_H6, REG_V21_H7,
	REG_V22_H0, REG_V22_H1, REG_V22_H2, REG_V22_H3, REG_V22_H4, REG_V22_H5, REG_V22_H6, REG_V22_H7,
	REG_V23_H0, REG_V23_H1, REG_V23_H2, REG_V23_H3, REG_V23_H4, REG_V23_H5, REG_V23_H6, REG_V23_H7,
	REG_V24_H0, REG_V24_H1, REG_V24_H2, REG_V24_H3, REG_V24_H4, REG_V24_H5, REG_V24_H6, REG_V24_H7,
	REG_V25_H0, REG_V25_H1, REG_V25_H2, REG_V25_H3, REG_V25_H4, REG_V25_H5, REG_V25_H6, REG_V25_H7,
	REG_V26_H0, REG_V26_H1, REG_V26_H2, REG_V26_H3, REG_V26_H4, REG_V26_H5, REG_V26_H6, REG_V26_H7,
	REG_V27_H0, REG_V27_H1, REG_V27_H2, REG_V27_H3, REG_V27_H4, REG_V27_H5, REG_V27_H6, REG_V27_H7,
	REG_V28_H0, REG_V28_H1, REG_V28_H2, REG_V28_H3, REG_V28_H4, REG_V28_H5, REG_V28_H6, REG_V28_H7,
	REG_V29_H0, REG_V29_H1, REG_V29_H2, REG_V29_H3, REG_V29_H4, REG_V29_H5, REG_V29_H6, REG_V29_H7,
	REG_V30_H0, REG_V30_H1, REG_V30_H2, REG_V30_H3, REG_V30_H4, REG_V30_H5, REG_V30_H6, REG_V30_H7,
	REG_V31_H0, REG_V31_H1, REG_V31_H2, REG_V31_H3, REG_V31_H4, REG_V31_H5, REG_V31_H6, REG_V31_H7,
	// S vector
	REG_V0_S0, REG_V0_S1, REG_V0_S2, REG_V0_S3, REG_V1_S0, REG_V1_S1, REG_V1_S2, REG_V1_S3,
	REG_V2_S0, REG_V2_S1, REG_V2_S2, REG_V2_S3, REG_V3_S0, REG_V3_S1, REG_V3_S2, REG_V3_S3,
	REG_V4_S0, REG_V4_S1, REG_V4_S2, REG_V4_S3, REG_V5_S0, REG_V5_S1, REG_V5_S2, REG_V5_S3,
	REG_V6_S0, REG_V6_S1, REG_V6_S2, REG_V6_S3, REG_V7_S0, REG_V7_S1, REG_V7_S2, REG_V7_S3,
	REG_V8_S0, REG_V8_S1, REG_V8_S2, REG_V8_S3, REG_V9_S0, REG_V9_S1, REG_V9_S2, REG_V9_S3,
	REG_V10_S0, REG_V10_S1, REG_V10_S2, REG_V10_S3, REG_V11_S0, REG_V11_S1, REG_V11_S2, REG_V11_S3,
	REG_V12_S0, REG_V12_S1, REG_V12_S2, REG_V12_S3, REG_V13_S0, REG_V13_S1, REG_V13_S2, REG_V13_S3,
	REG_V14_S0, REG_V14_S1, REG_V14_S2, REG_V14_S3, REG_V15_S0, REG_V15_S1, REG_V15_S2, REG_V15_S3,
	REG_V16_S0, REG_V16_S1, REG_V16_S2, REG_V16_S3, REG_V17_S0, REG_V17_S1, REG_V17_S2, REG_V17_S3,
	REG_V18_S0, REG_V18_S1, REG_V18_S2, REG_V18_S3, REG_V19_S0, REG_V19_S1, REG_V19_S2, REG_V19_S3,
	REG_V20_S0, REG_V20_S1, REG_V20_S2, REG_V20_S3, REG_V21_S0, REG_V21_S1, REG_V21_S2, REG_V21_S3,
	REG_V22_S0, REG_V22_S1, REG_V22_S2, REG_V22_S3, REG_V23_S0, REG_V23_S1, REG_V23_S2, REG_V23_S3,
	REG_V24_S0, REG_V24_S1, REG_V24_S2, REG_V24_S3, REG_V25_S0, REG_V25_S1, REG_V25_S2, REG_V25_S3,
	REG_V26_S0, REG_V26_S1, REG_V26_S2, REG_V26_S3, REG_V27_S0, REG_V27_S1, REG_V27_S2, REG_V27_S3,
	REG_V28_S0, REG_V28_S1, REG_V28_S2, REG_V28_S3, REG_V29_S0, REG_V29_S1, REG_V29_S2, REG_V29_S3,
	REG_V30_S0, REG_V30_S1, REG_V30_S2, REG_V30_S3, REG_V31_S0, REG_V31_S1, REG_V31_S2, REG_V31_S3,
	// D vector
	REG_V0_D0, REG_V0_D1, REG_V1_D0, REG_V1_D1, REG_V2_D0, REG_V2_D1, REG_V3_D0, REG_V3_D1,
	REG_V4_D0, REG_V4_D1, REG_V5_D0, REG_V5_D1, REG_V6_D0, REG_V6_D1, REG_V7_D0, REG_V7_D1,
	REG_V8_D0, REG_V8_D1, REG_V9_D0, REG_V9_D1, REG_V10_D0, REG_V10_D1, REG_V11_D0, REG_V11_D1,
	REG_V12_D0, REG_V12_D1, REG_V13_D0, REG_V13_D1, REG_V14_D0, REG_V14_D1, REG_V15_D0, REG_V15_D1,
	REG_V16_D0, REG_V16_D1, REG_V17_D0, REG_V17_D1, REG_V18_D0, REG_V18_D1, REG_V19_D0, REG_V19_D1,
	REG_V20_D0, REG_V20_D1, REG_V21_D0, REG_V21_D1, REG_V22_D0, REG_V22_D1, REG_V23_D0, REG_V23_D1,
	REG_V24_D0, REG_V24_D1, REG_V25_D0, REG_V25_D1, REG_V26_D0, REG_V26_D1, REG_V27_D0, REG_V27_D1,
	REG_V28_D0, REG_V28_D1, REG_V29_D0, REG_V29_D1, REG_V30_D0, REG_V30_D1, REG_V31_D0, REG_V31_D1,
	// Q vector is already defined REG_V0, REG_V1, ..., REG_V31
	// SVE
	REG_Z0,  REG_Z1,  REG_Z2,  REG_Z3,  REG_Z4,  REG_Z5,  REG_Z6,  REG_Z7,
	REG_Z8,  REG_Z9,  REG_Z10, REG_Z11, REG_Z12, REG_Z13, REG_Z14, REG_Z15,
	REG_Z16, REG_Z17, REG_Z18, REG_Z19, REG_Z20, REG_Z21, REG_Z22, REG_Z23,
	REG_Z24, REG_Z25, REG_Z26, REG_Z27, REG_Z28, REG_Z29, REG_Z30, REG_ZZR, REG_Z31,
	REG_P0,  REG_P1,  REG_P2,  REG_P3,  REG_P4,  REG_P5,  REG_P6,  REG_P7,
	REG_P8,  REG_P9,  REG_P10, REG_P11, REG_P12, REG_P13, REG_P14, REG_P15,
	REG_P16, REG_P17, REG_P18, REG_P19, REG_P20, REG_P21, REG_P22, REG_P23,
	REG_P24, REG_P25, REG_P26, REG_P27, REG_P28, REG_P29, REG_P30, REG_P31,
	REG_PF0,  REG_PF1,  REG_PF2,  REG_PF3,  REG_PF4,  REG_PF5,  REG_PF6,  REG_PF7,
	REG_PF8,  REG_PF9,  REG_PF10, REG_PF11, REG_PF12, REG_PF13, REG_PF14, REG_PF15,
	REG_PF16, REG_PF17, REG_PF18, REG_PF19, REG_PF20, REG_PF21, REG_PF22, REG_PF23,
	REG_PF24, REG_PF25, REG_PF26, REG_PF27, REG_PF28, REG_PF29, REG_PF30, REG_PF31,
	REG_END
};

#ifdef __cplusplus
extern "C" {
#endif
const char *get_register_name(enum Register);
size_t get_register_size(enum Register);
#ifdef __cplusplus
}
#endif

