// -*- coding: utf-8-unix -*-

// Copyright (c) 2023 Daishi Mori (mori0091)
//
// This software is released under the MIT License.
// See https://github.com/mori0091/tgc/blob/main/LICENSE
//
// GitHub tgc project
// https://github.com/mori0091/tgc

#ifndef TGC_SLICE_EQ_SLICE_H_
#define TGC_SLICE_EQ_SLICE_H_

#include "tgc/eq.h"
#include "tgc/slice/type_slice.h"

#include <string.h>

#if !defined(IMPLEMENT)
#define use_Eq_for_Slice(T) def_Eq_for_Slice(T)
#else
#define use_Eq_for_Slice(T)                                              \
  def_Eq_for_Slice(T);                                                   \
  impl_Eq_for_Slice(T)
#endif

#define def_Eq_for_Slice(T)                                              \
  require_trait(Eq(T));                                                  \
  require_type(Slice(T));                                                \
  def_Eq(Slice(T))

#define impl_Eq_for_Slice(T)                                             \
  impl_Eq_for(Slice(T)) {                                                \
    if (a.len != b.len)                                                  \
      return false;                                                      \
    if (IS_COPY(T)) {                                                    \
      return !memcmp(a.ptr, b.ptr, a.len);                               \
    } else {                                                             \
      for (size_t i = 0; i < a.len; i++) {                               \
        if (trait(Eq(T)).ne(a.ptr[i], b.ptr[i]))                         \
          return false;                                                  \
      }                                                                  \
      return true;                                                       \
    }                                                                    \
  }                                                                      \
  END_OF_STATEMENT

#endif // TGC_SLICE_EQ_SLICE_H_
