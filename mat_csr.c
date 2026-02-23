#include "mat_csr.h"
#include <stdlib.h>
#include <stdio.h>

mat_csr_int* mat_csr_int_create(unsigned int n_rows, unsigned int n_cols, unsigned int nnz) {
  mat_csr_int *mat = malloc(sizeof(mat_csr_int));
  if(!mat) return NULL;

  mat->val = malloc(sizeof(int) * nnz);
  mat->col = malloc(sizeof(unsigned int) * nnz);
  mat->row_ptr = malloc(sizeof(unsigned int) * (n_rows + 1));
  
  if(!mat->val || !mat->col || !mat->row_ptr) {
    free(mat->val);
    free(mat->col);
    free(mat->row_ptr);
    free(mat);
    return NULL;
  }

  mat->n_rows = n_rows;
  mat->n_cols = n_cols;
  mat->nnz = nnz;

  return mat;
}

void mat_csr_int_destroy(mat_csr_int *mat) {
  if(!mat) return;
  free(mat->val);
  free(mat->col);
  free(mat->row_ptr);
  free(mat);
}

int mat_csr_int_get(const mat_csr_int *mat, unsigned int row, unsigned int col) {
  if(row >= mat->n_rows || col >= mat->n_cols) return 0;

  for(unsigned int i = mat->row_ptr[row]; i < mat->row_ptr[row + 1]; ++i) {
    if(mat->col[i] == col) return mat->val[i];
  }

  return 0;
}

void mat_csr_int_print_dense(const mat_csr_int *mat) {
  for(unsigned int i = 0; i < mat->n_rows; ++i) {
    unsigned int k = mat->row_ptr[i];
    for(unsigned int j = 0; j < mat->n_cols; ++j) {
      if(k < mat->row_ptr[i+1] && mat->col[k] == j) {
        printf(" %d", mat->val[k]);
        ++k;
      } else {
        printf(" 0");
      }
    }
    printf("\n");
  }
}

mat_csr_f* mat_csr_f_create(unsigned int n_rows, unsigned int n_cols, unsigned int nnz) {
  mat_csr_f *mat = malloc(sizeof(mat_csr_f));
  if(!mat) return NULL;

  mat->val = malloc(sizeof(float) * nnz);
  mat->col = malloc(sizeof(unsigned int) * nnz);
  mat->row_ptr = malloc(sizeof(unsigned int) * (n_rows + 1));
  
  if(!mat->val || !mat->col || !mat->row_ptr) {
    free(mat->val);
    free(mat->col);
    free(mat->row_ptr);
    free(mat);
    return NULL;
  }

  mat->n_rows = n_rows;
  mat->n_cols = n_cols;
  mat->nnz = nnz;

  return mat;
}

void mat_csr_f_destroy(mat_csr_f *mat) {
  if(!mat) return;
  free(mat->val);
  free(mat->col);
  free(mat->row_ptr);
  free(mat);
}

float mat_csr_f_get(const mat_csr_f *mat, unsigned int row, unsigned int col) {
  if(row >= mat->n_rows || col >= mat->n_cols) return 0;

  for(unsigned int i = mat->row_ptr[row]; i < mat->row_ptr[row + 1]; ++i) {
    if(mat->col[i] == col) return mat->val[i];
  }

  return 0;
}

void mat_csr_f_print_dense(const mat_csr_f *mat) {
  for(unsigned int i = 0; i < mat->n_rows; ++i) {
    unsigned int k = mat->row_ptr[i];
    for(unsigned int j = 0; j < mat->n_cols; ++j) {
      if(k < mat->row_ptr[i+1] && mat->col[k] == j) {
        printf(" %f", mat->val[k]);
        ++k;
      } else {
        printf(" 0");
      }
    }
    printf("\n");
  }
}


