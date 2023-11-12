// -*- coding: utf-8-unix -*-

// Copyright (c) 2023 Daishi Mori (mori0091)
//
// This software is released under the MIT License.
// See https://github.com/mori0091/tgc/blob/main/LICENSE
//
// GitHub tgc project
// https://github.com/mori0091/tgc

#include "cstr.h"
#include "utf8.h"

static CStr FUNC_NAME(from_utf8, CStr)(Byte* ptr) {
  if (!ptr) {
    return (CStr){0};
  }
  Byte* p = ptr;
  while (*p) {
    if (is_utf8_1((unsigned char*)p)) {
      p += 1;
      continue;
    }
    if (is_utf8_2((unsigned char*)p)) {
      p += 2;
      continue;
    }
    if (is_utf8_3((unsigned char*)p)) {
      p += 3;
      continue;
    }
    if (is_utf8_4((unsigned char*)p)) {
      p += 4;
      continue;
    }
    break;
  }
  if (p == ptr) {
    return (CStr){0};
  }
  return (CStr){.ptr = ptr, .len = p - ptr};
}

impl_trait(CStr){
  .from_utf8 = FUNC_NAME(from_utf8, CStr),
};
