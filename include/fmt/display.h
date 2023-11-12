// -*- coding: utf-8-unix -*-

// Copyright (c) 2023 Daishi Mori (mori0091)
//
// This software is released under the MIT License.
// See https://github.com/mori0091/tgc/blob/main/LICENSE
//
// GitHub tgc project
// https://github.com/mori0091/tgc

#ifndef FMT_DISPLAY_H_
#define FMT_DISPLAY_H_

#include "fmt/formatter.h"

#define Display(T) TYPE_NAME(Display, TYPEOF(T))

#define def_Display(T)                                                   \
  def_trait(Display(T)) { void (*fmt)(T self, const Formatter out); }

#define impl_Display_for(T)                                              \
  static void FUNC_NAME(fmt, Display(T))(T self, const Formatter out);   \
  impl_trait(Display(T)){                                                \
    .fmt = FUNC_NAME(fmt, Display(T)),                                   \
  };                                                                     \
  static void FUNC_NAME(fmt, Display(T))(                                \
    T self, const Formatter out) /* {...} */

#endif // FMT_DISPLAY_H_
