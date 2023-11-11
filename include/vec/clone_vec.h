#ifndef VEC_CLONE_VEC_H_
#define VEC_CLONE_VEC_H_

#include "clone.h"
#include "vec/type_vec.h"

#if !defined(IMPLEMENT)
#define use_Clone_for_Vec(T) def_Clone_for_Vec(T)
#else
#define use_Clone_for_Vec(T)                                             \
  def_Clone_for_Vec(T);                                                  \
  impl_Clone_for_Vec(T)
#endif

#define def_Clone_for_Vec(T)                                             \
  require_trait(Clone(T));                                               \
  require_type(Vec(T));                                                  \
  def_Clone(Vec(T))

#define impl_Clone_for_Vec(T)                                            \
  impl_Clone_for(Vec(T)) {                                               \
    return trait(Vec(T)).from(self.len, self.ptr);                       \
  }                                                                      \
  END_OF_STATEMENT

#endif // VEC_CLONE_VEC_H_
