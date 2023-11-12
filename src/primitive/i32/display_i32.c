// -*- coding: utf-8-unix -*-

// Copyright (c) 2023 Daishi Mori (mori0091)
//
// This software is released under the MIT License.
// See https://github.com/mori0091/tgc/blob/main/LICENSE
//
// GitHub tgc project
// https://github.com/mori0091/tgc

#include "primitive.h"
#include <inttypes.h>

impl_Display_for(i32) {
  fmt_write(out, "%" PRId32, self);
}
