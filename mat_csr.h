#ifndef MAT_CSR_H
#define MAT_CSR_H

#include <stddef.h>

typedef struct {
  int *val;
  unsigned int *col;
  unsigned int *row_ptr;
  unsigned int n_rows;
  unsigned int n_cols;
  unsigned int nnz;
} mat_csr_int;

typedef struct {
  float *val;
  unsigned int *col;
  unsigned int *row_ptr;
  unsigned int n_rows;
  unsigned int n_cols;
  unsigned int nnz;
} mat_csr_f;

mat_csr_int* mat_csr_int_create(unsigned int n_rows, unsigned int n_cols, unsigned int nnz);
void mat_csr_int_destroy(mat_csr_int *mat);
void mat_csr_int_print_dense(const mat_csr_int *mat);
int mat_csr_int_get(const mat_csr_int *mat, unsigned int row, unsigned int col);

mat_csr_f* mat_csr_f_create(unsigned int n_rows, unsigned int n_cols, unsigned int nnz);
void mat_csr_f_destroy(mat_csr_f *mat);
void mat_csr_f_print_dense(const mat_csr_f *mat);
float mat_csr_f_get(const mat_csr_f *mat, unsigned int row, unsigned int col);

#endif