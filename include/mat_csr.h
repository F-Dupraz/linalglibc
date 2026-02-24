#ifndef MAT_CSR_H
#define MAT_CSR_H

#include <stdlib.h>
#include <stdio.h>

/* ── Instancia: int ─────────────────────────────────────────────────────────── */
#define MAT_CSR_TYPE    int
#define MAT_CSR_SUFFIX  int
#define MAT_CSR_FMT     "%d"
#define MAT_CSR_ZERO    0
#include "mat_csr_impl.h"

/* ── Instancia: float ───────────────────────────────────────────────────────── */
#define MAT_CSR_TYPE    float
#define MAT_CSR_SUFFIX  f
#define MAT_CSR_FMT     "%g"
#define MAT_CSR_ZERO    0.0f
#include "mat_csr_impl.h"

/* ── Instancia: double ──────────────────────────────────────────────────────── */
#define MAT_CSR_TYPE    double
#define MAT_CSR_SUFFIX  d
#define MAT_CSR_FMT     "%g"
#define MAT_CSR_ZERO    0.0
#include "mat_csr_impl.h"

/* ── API genérica vía _Generic (C11) ────────────────────────────────────────── */
#define mat_csr_create(rows, cols, nnz, sample_val) _Generic((sample_val), \
  int:    mat_csr_int_create,                                               \
  float:  mat_csr_f_create,                                                 \
  double: mat_csr_d_create                                                  \
)(rows, cols, nnz)

#define mat_csr_destroy(mat) _Generic((mat),         \
  mat_csr_int*: mat_csr_int_destroy,                 \
  mat_csr_f*:   mat_csr_f_destroy,                   \
  mat_csr_d*:   mat_csr_d_destroy                    \
)(mat)

#define mat_csr_print_dense(mat) _Generic((mat),          \
  mat_csr_int*: mat_csr_int_print_dense,                  \
  mat_csr_f*:   mat_csr_f_print_dense,                    \
  mat_csr_d*:   mat_csr_d_print_dense                     \
)(mat)

#define mat_csr_get(mat, row, col) _Generic((mat),  \
  mat_csr_int*: mat_csr_int_get,                    \
  mat_csr_f*:   mat_csr_f_get,                      \
  mat_csr_d*:   mat_csr_d_get                       \
)(mat, row, col)

#endif /* MAT_CSR_H */