// -*- coding: utf-8-unix -*-

// Copyright (c) 2023 Daishi Mori (mori0091)
//
// This software is released under the MIT License.
// See https://github.com/mori0091/tgc/blob/main/LICENSE
//
// GitHub tgc project
// https://github.com/mori0091/tgc

#ifndef SLICE_DEBUG_SLICE_H_
#define SLICE_DEBUG_SLICE_H_

#include "fmt/debug.h"
#include "slice/type_slice.h"

#if !defined(IMPLEMENT)
#define use_Debug_for_Slice(T) def_Debug_for_Slice(T)
#else
#define use_Debug_for_Slice(T)                                           \
  def_Debug_for_Slice(T);                                                \
  impl_Debug_for_Slice(T)
#endif

#define def_Debug_for_Slice(T)                                           \
  require_type(Slice(T));                                                \
  require_trait(Debug(T));                                               \
  def_Debug(Slice(T))

#define impl_Debug_for_Slice(T)                                          \
  impl_Debug_for(Slice(T)) {                                             \
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

#endif // SLICE_DEBUG_SLICE_H_
