#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>
#include <stdio.h>

/* ── Instancia: int ─────────────────────────────────────────────────────────── */
#define VEC_TYPE    int
#define VEC_SUFFIX  i
#define VEC_FMT     "%d"
#define VEC_ZERO    0
#include "vector_impl.h"

/* ── Instancia: float ───────────────────────────────────────────────────────── */
#define VEC_TYPE    float
#define VEC_SUFFIX  f
#define VEC_FMT     "%g"
#define VEC_ZERO    0.0f
#include "vector_impl.h"

/* ── Instancia: double ──────────────────────────────────────────────────────── */
#define VEC_TYPE    double
#define VEC_SUFFIX  d
#define VEC_FMT     "%g"
#define VEC_ZERO    0.0
#include "vector_impl.h"

/* ── API genérica vía _Generic (C11) ────────────────────────────────────────── */
#define vec_create(dims, sample_val) _Generic((sample_val), \
  int:    vec_i_create,                                     \
  float:  vec_f_create,                                     \
  double: vec_d_create                                      \
)(dims)

#define vec_destroy(v) _Generic((v),    \
  vec_i*: vec_i_destroy,                \
  vec_f*: vec_f_destroy,                \
  vec_d*: vec_d_destroy                 \
)(v)

#define vec_print(v) _Generic((v), \
  vec_i*: vec_i_print,             \
  vec_f*: vec_f_print,             \
  vec_d*: vec_d_print              \
)(v)

#define vec_get(v, i) _Generic((v), \
  vec_i*: vec_i_get,                \
  vec_f*: vec_f_get,                \
  vec_d*: vec_d_get                 \
)(v, i)

#endif /* VECTOR_H */