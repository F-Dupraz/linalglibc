/*
 * mat_csr_impl.h — Template X-Macro para mat_csr_<SUFFIX>
 *
 * Parámetros requeridos antes de incluir este archivo:
 *   MAT_CSR_TYPE    → tipo de dato (int, float, double, ...)
 *   MAT_CSR_SUFFIX  → sufijo del nombre (int, f, d, ...)
 *   MAT_CSR_FMT     → format string para printf ("%d", "%f", ...)
 *   MAT_CSR_ZERO    → valor cero del tipo (0, 0.0f, 0.0, ...)
 *
 */

/* ── Helpers internos de concatenación ─────────────────────────────────────── */
#define _CSR_CAT2(a, b)   a##b
#define _CSR_CAT(a, b)    _CSR_CAT2(a, b)
#define _CSR_T            _CSR_CAT(mat_csr_, MAT_CSR_SUFFIX)
#define _CSR_FN(name)     _CSR_CAT(_CSR_T, _CSR_CAT(_, name))

/* ── Struct ──────────────────────────────────────────────────────────────────── */
typedef struct {
  MAT_CSR_TYPE *val;
  unsigned int *col;
  unsigned int *row_ptr;
  unsigned int  n_rows;
  unsigned int  n_cols;
  unsigned int  nnz;
} _CSR_T;

/* ── Declaraciones / definiciones ───────────────────────────────────────────── */
static inline _CSR_T* _CSR_FN(create)(unsigned int n_rows, unsigned int n_cols, unsigned int nnz) {
  _CSR_T *mat = malloc(sizeof(_CSR_T));
  if (!mat) return NULL;

  mat->val     = malloc(sizeof(MAT_CSR_TYPE) * nnz);
  mat->col     = malloc(sizeof(unsigned int) * nnz);
  mat->row_ptr = malloc(sizeof(unsigned int) * (n_rows + 1));

  if (!mat->val || !mat->col || !mat->row_ptr) {
    free(mat->val);
    free(mat->col);
    free(mat->row_ptr);
    free(mat);
    return NULL;
  }

  mat->n_rows = n_rows;
  mat->n_cols = n_cols;
  mat->nnz    = nnz;
  return mat;
}

static inline void _CSR_FN(destroy)(_CSR_T *mat) {
  if (!mat) return;
  free(mat->val);
  free(mat->col);
  free(mat->row_ptr);
  free(mat);
}

static inline MAT_CSR_TYPE _CSR_FN(get)(const _CSR_T *mat, unsigned int row, unsigned int col) {
  if (row >= mat->n_rows || col >= mat->n_cols) return MAT_CSR_ZERO;

  for (unsigned int i = mat->row_ptr[row]; i < mat->row_ptr[row + 1]; ++i) {
    if (mat->col[i] == col) return mat->val[i];
  }
  return MAT_CSR_ZERO;
}

static inline void _CSR_FN(print_dense)(const _CSR_T *mat) {
  for (unsigned int i = 0; i < mat->n_rows; ++i) {
    unsigned int k = mat->row_ptr[i];
    for (unsigned int j = 0; j < mat->n_cols; ++j) {
      if (k < mat->row_ptr[i + 1] && mat->col[k] == j) {
        printf(" " MAT_CSR_FMT, mat->val[k]);
        ++k;
      } else {
        printf(" 0");
      }
    }
    printf("\n");
  }
}

/* ── Limpieza de macros (obligatoria para la próxima instanciación) ──────────── */
#undef _CSR_CAT2
#undef _CSR_CAT
#undef _CSR_T
#undef _CSR_FN
#undef MAT_CSR_TYPE
#undef MAT_CSR_SUFFIX
#undef MAT_CSR_FMT
#undef MAT_CSR_ZERO