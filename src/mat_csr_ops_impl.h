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

static inline _CSR_T* _CSR_FN(add)(_CSR_T *A, _CSR_T *B) {
  if (A->n_rows != B->n_rows || A->n_cols != B->n_cols) return NULL;

  unsigned int n_rows = A->n_rows;
  unsigned int n_cols = A->n_cols;

  unsigned int *mask = calloc(n_cols, sizeof(MAT_CSR_TYPE));
  if(!mask) return NULL;

  unsigned int nnz_result = 0;

  for(unsigned int i = 0; i < n_rows; ++i) {
    for (unsigned int k = A->row_ptr[i]; k < A->row_ptr[i+1]; ++k)
      mask[A->col[k]] = 1;
    for (unsigned int k = B->row_ptr[i]; k < B->row_ptr[i+1]; ++k)
      mask[B->col[k]] = 1;
    for (unsigned int j = 0; j < n_cols; ++j) {
      if (mask[j]) {
        nnz_result++;
        mask[j] = 0;
      }
    }
  }

  free(mask);

  _CSR_T *res = _CSR_FN(create)(n_rows, n_cols, nnz_result);
  if(!res) return NULL;

  MAT_CSR_TYPE *acc = calloc(n_cols, sizeof(MAT_CSR_TYPE));
  if(!acc) {
    _CSR_FN(destroy)(res);
    return NULL;
  }

  unsigned int pos = 0;
  res->row_ptr[0] = 0;

  for(unsigned int i = 0; i < n_rows; ++i) {
    for(unsigned int j = A->row_ptr[i]; j < A->row_ptr[i+1]; ++j)
      acc[A->col[j]] += A->val[j];

    for(unsigned int j = B->row_ptr[i]; j < B->row_ptr[i+1]; ++j)
      acc[B->col[j]] += B->val[j];

    for (unsigned int j = 0; j < n_cols; j++) {
      if (acc[j] != MAT_CSR_ZERO) {
        res->val[pos] = acc[j];
        res->col[pos] = j;
        pos++;
        acc[j] = 0;
      }
    }
    
    res->row_ptr[i+1] = pos;
  }

  free(acc);

  return res;
}

/* ── Limpieza de macros ──────────── */
#undef _CSR_CAT2
#undef _CSR_CAT
#undef _CSR_T
#undef _CSR_FN
#undef MAT_CSR_TYPE
#undef MAT_CSR_SUFFIX
#undef MAT_CSR_ZERO