/*
 * mat_csr_ops_impl.h — Template X-Macro para operaciones algebraicas
 *
 * Parámetros requeridos (definidos antes de incluir):
 *   MAT_CSR_TYPE    → tipo de dato (int, float, double, ...)
 *   MAT_CSR_SUFFIX  → sufijo (int, f, d, ...)
 *   MAT_CSR_ZERO    → valor cero del tipo
 *
 */

/* ── Helpers internos de concatenación ─────────────────────────────────────── */
#define _CSR_CAT2(a, b)   a##b
#define _CSR_CAT(a, b)    _CSR_CAT2(a, b)
#define _CSR_T            _CSR_CAT(mat_csr_, MAT_CSR_SUFFIX)
#define _CSR_FN(name)     _CSR_CAT(_CSR_T, _CSR_CAT(_, name))

/* ── Declaraciones / definiciones ───────────────────────────────────────────── */
static inline void _CSR_FN(scalar_mult)(_CSR_T *mat, MAT_CSR_TYPE n) {
  if (!mat) return;

  for(unsigned int j = 0; j < mat->nnz; ++j)
    mat->val[j] = n * mat->val[j];
}

/* ── Limpieza de macros ──────────── */
#undef _CSR_CAT2
#undef _CSR_CAT
#undef _CSR_T
#undef _CSR_FN
#undef MAT_CSR_TYPE
#undef MAT_CSR_SUFFIX
#undef MAT_CSR_ZERO