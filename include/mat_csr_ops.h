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

/* ── API genérica vía _Generic (C11) ────────────────────────────────────── */
#define mat_csr_scalar_mult(mat, s) _Generic((mat),  \
  mat_csr_int*: mat_csr_int_scalar_mult,            \
  mat_csr_f*:   mat_csr_f_scalar_mult,               \
  mat_csr_d*:   mat_csr_d_scalar_mult                 \
)(mat, s)

#define mat_csr_add(matA, matB) _Generic((matA),        \
  mat_csr_int*:       mat_csr_int_add,                  \
  mat_csr_f*:         mat_csr_f_add,                    \
  mat_csr_d*:         mat_csr_d_add,                    \
  const mat_csr_int*: mat_csr_int_add,                  \
  const mat_csr_f*:   mat_csr_f_add,                    \
  const mat_csr_d*:   mat_csr_d_add                     \
)(matA, matB)

#endif /* MAT_CSR_OPS_H */