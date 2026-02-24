#ifndef VEC_OPS_H
#define VEC_OPS_H

#include "vector.h"

#define VEC_TYPE   int
#define VEC_SUFFIX i
#define VEC_ZERO   0
#include "vector_ops_impl.h"

#define VEC_TYPE   float
#define VEC_SUFFIX f
#define VEC_ZERO   0.0f
#include "vector_ops_impl.h"

#define VEC_TYPE   double
#define VEC_SUFFIX d
#define VEC_ZERO   0.0
#include "vector_ops_impl.h"

/* ── API genérica vía _Generic (C11) ────────────────────────────────────── */
#define vec_scalar_mult(vec, s) _Generic((vec),  \
  vec_i*: vec_i_scalar_mult,              \
  vec_f*: vec_f_scalar_mult,               \
  vec_d*: vec_d_scalar_mult                 \
)(vec, s)

#endif /* VEC_OPS_H */