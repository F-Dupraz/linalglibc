/*
 * vec_impl.h — Template X-Macro para vec_<SUFFIX>
 *
 * Parámetros requeridos antes de incluir:
 *   VEC_TYPE    → tipo de dato (int, float, double, ...)
 *   VEC_SUFFIX  → sufijo del nombre (i, f, d, ...)
 *   VEC_FMT     → format string para printf ("%d", "%f", ...)
 *   VEC_ZERO    → valor cero del tipo
 *
 */

#define _VEC_CAT2(a, b)  a##b
#define _VEC_CAT(a, b)   _VEC_CAT2(a, b)
#define _VEC_T           _VEC_CAT(vec_, VEC_SUFFIX)
#define _VEC_FN(name)    _VEC_CAT(_VEC_T, _VEC_CAT(_, name))

/* ── Struct ──────────────────────────────────────────────────────────────────── */
typedef struct {
  VEC_TYPE    *val;
  unsigned int n_dim;
} _VEC_T;

/* ── Implementaciones ────────────────────────────────────────────────────────── */
static inline _VEC_T* _VEC_FN(create)(unsigned int dims) {
  _VEC_T *v = malloc(sizeof(_VEC_T));
  if (!v) return NULL;

  v->val = malloc(sizeof(VEC_TYPE) * dims);
  if (!v->val) {
    free(v);
    return NULL;
  }

  v->n_dim = dims;
  return v;
}

static inline void _VEC_FN(destroy)(_VEC_T *v) {
  if (!v) return;
  free(v->val);
  free(v);
}

static inline VEC_TYPE _VEC_FN(get)(const _VEC_T *v, unsigned int i) {
  if (i >= v->n_dim) return VEC_ZERO;
  return v->val[i];
}

static inline void _VEC_FN(print)(const _VEC_T *v) {
  printf("[");
  for (unsigned int i = 0; i < v->n_dim; ++i) {
    printf(" " VEC_FMT, v->val[i]);
  }
  printf(" ]\n");
}

/* ── Limpieza ────────────────────────────────────────────────────────────────── */
#undef _VEC_CAT2
#undef _VEC_CAT
#undef _VEC_T
#undef _VEC_FN
#undef VEC_TYPE
#undef VEC_SUFFIX
#undef VEC_FMT
#undef VEC_ZERO