#include <stdio.h>
#include "mat_csr.h"

int main() {
  // Crear matriz 4x4 con 6 elementos no-cero
  mat_csr_int *mat = mat_csr_int_create(3, 4, 6);
  if(!mat) {
    fprintf(stderr, "Error: no se pudo crear la matriz\n");
    return 1;
  }
  
  // Llenar valores
  mat->val[0] = 1;
  mat->val[1] = 7;
  mat->val[2] = 5;
  mat->val[3] = 2;
  mat->val[4] = 3;
  mat->val[5] = 1;
  
  mat->col[0] = 0;
  mat->col[1] = 2;
  mat->col[2] = 3;
  mat->col[3] = 1;
  mat->col[4] = 0;
  mat->col[5] = 3;
  
  mat->row_ptr[0] = 0;
  mat->row_ptr[1] = 3;
  mat->row_ptr[2] = 4;
  mat->row_ptr[3] = 6;
  
  mat_csr_int_print_dense(mat);
  
  mat_csr_int_destroy(mat);
  return 0;
}