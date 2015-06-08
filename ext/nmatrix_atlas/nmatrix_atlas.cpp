#include <ruby.h>

#include "nmatrix.h"

extern "C" {
#if defined HAVE_CBLAS_H
  #include <cblas.h>
#elif defined HAVE_ATLAS_CBLAS_H
  #include <atlas/cblas.h>
#endif

#if defined HAVE_CLAPACK_H
  #include <clapack.h>
#elif defined HAVE_ATLAS_CLAPACK_H
  #include <atlas/clapack.h>
#endif
}

#include "data/data.h"

VALUE cNMatrix;
VALUE cNMatrix_LAPACK;

extern "C" {
void nm_math_init_atlas(); 
}

extern "C" {
static VALUE nm_test(VALUE self) {
  return INT2NUM(2);
}

void Init_nmatrix_atlas() {
  cNMatrix = rb_define_class("NMatrix", rb_cObject);

  rb_define_method(cNMatrix, "test_c_ext_return_2", (METHOD)nm_test, 0);

  nm_math_init_atlas();
}

}
