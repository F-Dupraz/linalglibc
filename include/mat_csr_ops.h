#ifndef MAT_CSR_OPS_H
#define MAT_CSR_OPS_H

#include "mat_csr.h"

#define MAT_CSR_TYPE   int
#define MAT_CSR_SUFFIX int
#define MAT_CSR_ZERO   0 // Para uso futuro
#include "mat_csr_ops_impl.h"

#define MAT_CSR_TYPE   float
#define MAT_CSR_SUFFIX f
#define MAT_CSR_ZERO   0.0f // Para uso futuro
#include "mat_csr_ops_impl.h"

#define MAT_CSR_TYPE   double
#define MAT_CSR_SUFFIX d
#define MAT_CSR_ZERO   0.0 // Para uso futuro
#include "mat_csr_ops_impl.h"

/* ── API ────────────────────────────────────────── */
#define mat_csr_int_scalar_mult(mat, s) mat_csr_int_scalar_mult((mat), (s))
#define mat_csr_f_scalar_mult(mat, s)   mat_csr_f_scalar_mult((mat), (s))
#define mat_csr_d_scalar_mult(mat, s)   mat_csr_d_scalar_mult((mat), (s))

#endif /* MAT_CSR_OPS_H */