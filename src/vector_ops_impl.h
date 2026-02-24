/*
 * vector_ops_impl.h — Template X-Macro para vec_<SUFFIX>
 *
 * Parámetros requeridos antes de incluir:
 *   VEC_TYPE    → tipo de dato (int, float, double, ...)
 *   VEC_SUFFIX  → sufijo del nombre (i, f, d, ...)
 *   VEC_ZERO    → valor cero del tipo
 *
 */

/* ── Helpers internos de concatenación ─────────────────────────────────────── */
#define _VEC_CAT2(a, b)  a##b
#define _VEC_CAT(a, b)   _VEC_CAT2(a, b)
#define _VEC_T           _VEC_CAT(vec_, VEC_SUFFIX)
#define _VEC_FN(name)    _VEC_CAT(_VEC_T, _VEC_CAT(_, name))

/* ── Implementaciones ────────────────────────────────────────────────────────── */
static inline void _VEC_FN(scalar_mult)(_VEC_T *vec, VEC_TYPE n) {
  if(!vec) return;

  for(unsigned int j = 0; j < vec->n_dim; ++j)
    vec->val[j] = n * vec->val[j];
}

/* ── Limpieza ────────────────────────────────────────────────────────────────── */
#undef _VEC_CAT2
#undef _VEC_CAT
#undef _VEC_T
#undef _VEC_FN
#undef VEC_TYPE
#undef VEC_SUFFIX
#undef VEC_ZERO