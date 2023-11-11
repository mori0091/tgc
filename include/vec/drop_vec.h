#ifndef VEC_DROP_VEC_H_
#define VEC_DROP_VEC_H_

#include "drop.h"
#include "vec/type_vec.h"

#if !defined(IMPLEMENT)
#define use_Drop_for_Vec(T) def_Drop_for_Vec(T)
#else
#define use_Drop_for_Vec(T)                                              \
  def_Drop_for_Vec(T);                                                   \
  impl_Drop_for_Vec(T)
#endif

#define def_Drop_for_Vec(T)                                              \
  require_trait(Drop(T));                                                \
  require_type(Vec(T));                                                  \
  def_Drop(Vec(T))

#define impl_Drop_for_Vec(T)                                             \
  impl_Drop_for(Vec(T)) {                                                \
    if (self) {                                                          \
      if (self->ptr) {                                                   \
        if (IS_DROP(T)) {                                                \
          for (size_t i = 0; i < self->len; ++i) {                       \
            trait(Drop(T)).drop(&self->ptr[i]);                          \
          }                                                              \
        }                                                                \
        free(self->ptr);                                                 \
      }                                                                  \
      *self = (Vec(T)){0};                                               \
    }                                                                    \
  }                                                                      \
  END_OF_STATEMENT

#endif // VEC_DROP_VEC_H_
