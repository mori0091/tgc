// -*- coding: utf-8-unix -*-

// Copyright (c) 2023 Daishi Mori (mori0091)
//
// This software is released under the MIT License.
// See https://github.com/mori0091/tgc/blob/main/LICENSE
//
// GitHub tgc project
// https://github.com/mori0091/tgc

#include "cstring.h"

impl_Clone_for(CString) {
  CStr s = {.ptr = self.ptr, .len = self.len};
  CString ret = {0};
  trait(CString).push_str(&ret, s);
  return ret;
}
