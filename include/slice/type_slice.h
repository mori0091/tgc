// -*- coding: utf-8-unix -*-

// Copyright (c) 2023 Daishi Mori (mori0091)
//
// This software is released under the MIT License.
// See https://github.com/mori0091/tgc/blob/main/LICENSE
//
// GitHub tgc project
// https://github.com/mori0091/tgc

#ifndef SLICE_TYPE_SLICE_H_
#define SLICE_TYPE_SLICE_H_

#include "copy.h"

#include <stddef.h>

/**
 * `Slice(T)`: Reference to a sequence of objects of type `T`.
 */
#define Slice(T) TYPE_NAME(Slice, TYPEOF(T))

#if defined(IMPLEMENT)
#define use_type_Slice(T)                                                \
  def_type_Slice(T);                                                     \
  impl_type_Slice(T)
#else
#define use_type_Slice(T) def_type_Slice(T)
#endif

#define def_type_Slice(T)                                                \
  typedef struct Slice(T) {                                              \
    T* ptr;                                                              \
    size_t len;                                                          \
  }                                                                      \
  Slice(T);                                                              \
                                                                         \
  def_Copy(Slice(T));                                                    \
                                                                         \
  def_trait(Slice(T)) { Slice(T) (*from)(size_t len, T * s); }

#define impl_type_Slice(T)                                               \
  static Slice(T) FUNC_NAME(from, Slice(T))(size_t len, T * s) {         \
    return (Slice(T)){.ptr = s, .len = len};                             \
  }                                                                      \
  impl_trait(Slice(T)) { .from = FUNC_NAME(from, Slice(T)), }

#endif // TYPE_SLICE_H_
