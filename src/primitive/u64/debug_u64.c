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

impl_Debug_for(u64) {
  fmt_write(out, "%" PRIu64, self);
}
