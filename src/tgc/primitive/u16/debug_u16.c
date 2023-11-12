// -*- coding: utf-8-unix -*-

// Copyright (c) 2023 Daishi Mori (mori0091)
//
// This software is released under the MIT License.
// See https://github.com/mori0091/tgc/blob/main/LICENSE
//
// GitHub tgc project
// https://github.com/mori0091/tgc

#include "tgc/primitive.h"
#include <inttypes.h>

impl_Debug_for(u16) {
  fmt_write(out, "%" PRIu16, self);
}
