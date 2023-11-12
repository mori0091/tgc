// -*- coding: utf-8-unix -*-

// Copyright (c) 2023 Daishi Mori (mori0091)
//
// This software is released under the MIT License.
// See https://github.com/mori0091/tgc/blob/main/LICENSE
//
// GitHub tgc project
// https://github.com/mori0091/tgc

#ifndef VEC_EQ_VEC_H_
#define VEC_EQ_VEC_H_

#include "eq.h"
#include "vec/type_vec.h"

#if !defined(IMPLEMENT)
#define use_Eq_for_Vec(T) def_Eq_for_Vec(T)
#else
#define use_Eq_for_Vec(T)                                                \
  def_Eq_for_Vec(T);                                                     \
  impl_Eq_for_Vec(T)
#endif

#define def_Eq_for_Vec(T)                                                \
  require_trait(Eq(T));                                                  \
  require_type(Vec(T));                                                  \
  def_Eq(Vec(T))

#define impl_Eq_for_Vec(T)                                               \
  impl_Eq_for(Vec(T)) {                                                  \
    if (a.len != b.len)                                                  \
      return false;                                                      \
    for (size_t i = 0; i < a.len; ++i) {                                 \
      if (!trait(Eq(T)).eq(a.ptr[i], b.ptr[i]))                          \
        return false;                                                    \
    }                                                                    \
    return true;                                                         \
  }                                                                      \
  END_OF_STATEMENT

#endif // VEC_EQ_VEC_H_
