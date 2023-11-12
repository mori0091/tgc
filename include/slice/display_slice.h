// -*- coding: utf-8-unix -*-

// Copyright (c) 2023 Daishi Mori (mori0091)
//
// This software is released under the MIT License.
// See https://github.com/mori0091/tgc/blob/main/LICENSE
//
// GitHub tgc project
// https://github.com/mori0091/tgc

#ifndef SLICE_DISPLAY_SLICE_H_
#define SLICE_DISPLAY_SLICE_H_

#include "fmt/display.h"
#include "slice/type_slice.h"

#if !defined(IMPLEMENT)
#define use_Display_for_Slice(T) def_Display_for_Slice(T)
#else
#define use_Display_for_Slice(T)                                         \
  def_Display_for_Slice(T);                                              \
  impl_Display_for_Slice(T)
#endif

#define def_Display_for_Slice(T)                                         \
  require_type(Slice(T));                                                \
  require_trait(Display(T));                                             \
  def_Display(Slice(T))

#define impl_Display_for_Slice(T)                                        \
  impl_Display_for(Slice(T)) {                                           \
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

#endif // SLICE_DISPLAY_SLICE_H_
