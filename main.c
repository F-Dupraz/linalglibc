#include <stdio.h>
#include "mat_csr_ops.h"
#include "vector_ops.h"

int main(void) {
  printf("=== mat_csr_int ===\n");
  mat_csr_int *mat = mat_csr_int_create(3, 4, 6);
  if (!mat) { fprintf(stderr, "Error: create falló\n"); return 1; }

  mat->val[0] = 1;  mat->val[1] = 7;  mat->val[2] = 5;
  mat->val[3] = 2;  mat->val[4] = 3;  mat->val[5] = 1;

  mat->col[0] = 0;  mat->col[1] = 2;  mat->col[2] = 3;
  mat->col[3] = 1;  mat->col[4] = 0;  mat->col[5] = 3;

  mat->row_ptr[0] = 0; mat->row_ptr[1] = 3;
  mat->row_ptr[2] = 4; mat->row_ptr[3] = 6;

  mat_csr_int_print_dense(mat);
  mat_csr_int_destroy(mat);

  printf("\n=== mat_csr_f ===\n");
  mat_csr_f *matf = mat_csr_f_create(3, 4, 6);
  if (!matf) { fprintf(stderr, "Error: create falló\n"); return 1; }

  matf->val[0] = 1.5f; matf->val[1] = 7.0f; matf->val[2] = 5.3f;
  matf->val[3] = 2.1f; matf->val[4] = 3.0f; matf->val[5] = 1.9f;

  matf->col[0] = 0; matf->col[1] = 2; matf->col[2] = 3;
  matf->col[3] = 1; matf->col[4] = 0; matf->col[5] = 3;

  matf->row_ptr[0] = 0; matf->row_ptr[1] = 3;
  matf->row_ptr[2] = 4; matf->row_ptr[3] = 6;

  mat_csr_print_dense(matf);
  printf("\n");
  mat_csr_f_scalar_mult(matf, 0.5);
  mat_csr_print_dense(matf);
  mat_csr_destroy(matf);

  printf("\n=== vec_i ===\n");
  vec_i *vi = vec_i_create(4);
  vi->val[0] = 10; vi->val[1] = 0; vi->val[2] = -3; vi->val[3] = 7;
  vec_print(vi);
  vec_i_scalar_mult(vi, 100);
  vec_print(vi);
  vec_destroy(vi);

  printf("\n=== vec_f ===\n");
  vec_f *vf = vec_f_create(3);
  vf->val[0] = 1.1f; vf->val[1] = 2.2f; vf->val[2] = 3.3f;
  vec_f_print(vf);
  vec_f_destroy(vf);

  printf("\n=== vec_d ===\n");
  vec_d *vd = vec_create(3, 1.1);
  vd->val[0] = 1.1; vd->val[1] = 2.2; vd->val[2] = 3.3;
  vec_print(vd);
  vec_destroy(vd);

  return 0;
}