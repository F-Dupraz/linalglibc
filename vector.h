#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>

typedef struct {
  int *val;
  unsigned int n_dim;
} vec_i;

typedef struct {
  float *val;
  unsigned int n_dim;
} vec_f;

vec_i* vec_i_create(unsigned int dims);
void vec_i_destroy(vec_i *vec);
void vec_i_print_dense(const vec_i *vec);

vec_f* vec_f_create(unsigned int dims);
void vec_f_destroy(vec_f *vec);
void vec_f_print_dense(const vec_f *vec);

#endif