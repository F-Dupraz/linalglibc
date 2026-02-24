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

/* ── API ────────────────────────────────────────── */
#define vec_i_scalar_mult(v, s) vec_i_scalar_mult((v), (s))
#define vec_f_scalar_mult(v, s) vec_f_scalar_mult((v), (s))
#define vec_d_scalar_mult(v, s) vec_d_scalar_mult((v), (s))

#endif /* VEC_OPS_H */