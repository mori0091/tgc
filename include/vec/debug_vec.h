#ifndef VEC_DEBUG_VEC_H_
#define VEC_DEBUG_VEC_H_

#include "fmt/debug.h"
#include "vec/type_vec.h"

#if !defined(IMPLEMENT)
#define use_Debug_for_Vec(T) def_Debug_for_Vec(T)
#else
#define use_Debug_for_Vec(T)                                             \
  def_Debug_for_Vec(T);                                                  \
  impl_Debug_for_Vec(T)
#endif

#define def_Debug_for_Vec(T)                                             \
  require_type(Vec(T));                                                  \
  require_trait(Debug(T));                                               \
  def_Debug(Vec(T))

#define impl_Debug_for_Vec(T)                                            \
  impl_Debug_for(Vec(T)) {                                               \
    fmt_write(out, "[");                                                 \
    if (self.len) {                                                      \
      trait(Debug(T)).fmt(self.ptr[0], out);                             \
    }                                                                    \
    for (size_t i = 1; i < self.len; ++i) {                              \
      fmt_write(out, ", ");                                              \
      trait(Debug(T)).fmt(self.ptr[i], out);                             \
    }                                                                    \
    fmt_write(out, "]");                                                 \
  }                                                                      \
  END_OF_STATEMENT

#endif // VEC_DEBUG_VEC_H_
