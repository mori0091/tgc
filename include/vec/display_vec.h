#ifndef VEC_DISPLAY_VEC_H_
#define VEC_DISPLAY_VEC_H_

#include "fmt/display.h"
#include "vec/type_vec.h"

#if !defined(IMPLEMENT)
#define use_Display_for_Vec(T) def_Display_for_Vec(T)
#else
#define use_Display_for_Vec(T)                                           \
  def_Display_for_Vec(T);                                                \
  impl_Display_for_Vec(T)
#endif

#define def_Display_for_Vec(T)                                           \
  require_type(Vec(T));                                                  \
  require_trait(Display(T));                                             \
  def_Display(Vec(T))

#define impl_Display_for_Vec(T)                                          \
  impl_Display_for(Vec(T)) {                                             \
    fmt_write(out, "[");                                                 \
    if (self.len) {                                                      \
      trait(Display(T)).fmt(self.ptr[0], out);                           \
    }                                                                    \
    for (size_t i = 1; i < self.len; ++i) {                              \
      fmt_write(out, ", ");                                              \
      trait(Display(T)).fmt(self.ptr[i], out);                           \
    }                                                                    \
    fmt_write(out, "]");                                                 \
  }                                                                      \
  END_OF_STATEMENT

#endif // VEC_DISPLAY_VEC_H_
