// -*- coding: utf-8-unix -*-

// Copyright (c) 2023 Daishi Mori (mori0091)
//
// This software is released under the MIT License.
// See https://github.com/mori0091/tgc/blob/main/LICENSE
//
// GitHub tgc project
// https://github.com/mori0091/tgc

#include "unit.h"

const Unit UNIT = {0};

impl_Clone_for(Unit) {
  return UNIT;
}

impl_Drop_for(Unit) {
}

impl_Eq_for(Unit) {
  return true;
}

impl_Debug_for(Unit) {
  fmt_write(out, "()");
}

impl_Display_for(Unit) {
  fmt_write(out, "()");
}
