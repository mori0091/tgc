// -*- coding: utf-8-unix -*-

// Copyright (c) 2023 Daishi Mori (mori0091)
//
// This software is released under the MIT License.
// See https://github.com/mori0091/tgc/blob/main/LICENSE
//
// GitHub tgc project
// https://github.com/mori0091/tgc

#ifndef TGC_VEC_DEBUG_VEC_H_
#define TGC_VEC_DEBUG_VEC_H_

#include "tgc/fmt/debug.h"
#include "tgc/vec/type_vec.h"

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

#endif // TGC_VEC_DEBUG_VEC_H_
