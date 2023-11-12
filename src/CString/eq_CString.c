// -*- coding: utf-8-unix -*-

// Copyright (c) 2023 Daishi Mori (mori0091)
//
// This software is released under the MIT License.
// See https://github.com/mori0091/tgc/blob/main/LICENSE
//
// GitHub tgc project
// https://github.com/mori0091/tgc

#include "cstring.h"

#include <string.h>

impl_Eq_for(CString) {
  return (a.len == b.len && !strncmp(a.ptr, b.ptr, a.len));
}
