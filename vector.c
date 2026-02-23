#include "vector.h"
#include <stdlib.h>
#include <stdio.h>

vec_i* vec_i_create(unsigned int dims) {
  vec_i *vector = malloc(sizeof(vec_i));
  if(!vector) return NULL;

  vector->val = malloc(sizeof(int) * dims);

  if(!vector->val) {
    free(vector->val);
    free(vector);

    return NULL;
  }

  vector->n_dim = dims;

  return vector;
}

void vec_i_destroy(vec_i *vec) {
  if(!vec) return;
  free(vec->val);
  free(vec);
}

void vec_i_print_dense(const vec_i *vec) {
  for(unsigned int j = 0; j < vec->n_dim; ++j) {
    if(!vec->val[j])
      printf(" 0");
    else
      prinf(" %d", vec->val[j]);
  }
}

vec_f* vec_f_create(unsigned int dims) {
  vec_f *vector = malloc(sizeof(vec_f));
  if(!vector) return NULL;

  vector->val = malloc(sizeof(float) * dims);

  if(!vector->val) {
    free(vector->val);
    free(vector);

    return NULL;
  }

  vector->n_dim = dims;

  return vector;
}

void vec_f_destroy(vec_f *vec) {
  if(!vec) return;
  free(vec->val);
  free(vec);
}

void vec_f_print_dense(const vec_f *vec) {
  for(unsigned int j = 0; j < vec->n_dim; ++j) {
    if(!vec->val[j])
      printf(" 0");
    else
      prinf(" %f", vec->val[j]);
  }
}
