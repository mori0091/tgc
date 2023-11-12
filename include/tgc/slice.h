// -*- coding: utf-8-unix -*-

// Copyright (c) 2023 Daishi Mori (mori0091)
//
// This software is released under the MIT License.
// See https://github.com/mori0091/tgc/blob/main/LICENSE
//
// GitHub tgc project
// https://github.com/mori0091/tgc

#ifndef TGC_SLICE_H_
#define TGC_SLICE_H_

#include "tgc/slice/debug_slice.h"
#include "tgc/slice/display_slice.h"
#include "tgc/slice/eq_slice.h"
#include "tgc/slice/type_slice.h"

#if defined(IMPLEMENT)
#define use_Slice(T)                                                     \
  def_Slice(T);                                                          \
  impl_Slice(T)
#else
#define use_Slice(T) def_Slice(T)
#endif

#define def_Slice(T)                                                     \
  def_type_Slice(T);                                                     \
  def_Eq_for_Slice(T);                                                   \
  def_Debug_for_Slice(T);                                                \
  def_Display_for_Slice(T);                                              \
  END_OF_STATEMENT

#define impl_Slice(T)                                                    \
  impl_type_Slice(T);                                                    \
  impl_Eq_for_Slice(T);                                                  \
  impl_Debug_for_Slice(T);                                               \
  impl_Display_for_Slice(T);                                             \
  END_OF_STATEMENT

#endif // TGC_SLICE_H_
