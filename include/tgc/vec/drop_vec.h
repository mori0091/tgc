// -*- coding: utf-8-unix -*-

// Copyright (c) 2023 Daishi Mori (mori0091)
//
// This software is released under the MIT License.
// See https://github.com/mori0091/tgc/blob/main/LICENSE
//
// GitHub tgc project
// https://github.com/mori0091/tgc

#ifndef TGC_VEC_DROP_VEC_H_
#define TGC_VEC_DROP_VEC_H_

#include "tgc/drop.h"
#include "tgc/vec/type_vec.h"

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

#endif // TGC_VEC_DROP_VEC_H_
