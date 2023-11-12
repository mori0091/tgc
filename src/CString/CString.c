// -*- coding: utf-8-unix -*-

// Copyright (c) 2023 Daishi Mori (mori0091)
//
// This software is released under the MIT License.
// See https://github.com/mori0091/tgc/blob/main/LICENSE
//
// GitHub tgc project
// https://github.com/mori0091/tgc

#include "cstring.h"

#include <assert.h>
#include <stdlib.h>
#include <string.h>

static CString FUNC_NAME(with_capacity, CString)(size_t capacity) {
  if (!capacity) {
    return (CString){0};
  } else {
    void* ptr = calloc(capacity * sizeof(Byte) + 1, 1);
    return (CString){.ptr = ptr, .len = 0, .capacity = capacity};
  }
}

static CString FUNC_NAME(from, CString)(CStr s) {
  if (!s.ptr || !s.len) {
    return (CString){0};
  } else {
    void* ptr = calloc(s.len * sizeof(Byte) + 1, 1);
    memcpy(ptr, s.ptr, s.len * sizeof(Byte));
    return (CString){.ptr = ptr, .len = s.len, .capacity = s.len};
  }
}

static void FUNC_NAME(reserve, CString)(CString* self,
                                        size_t additional) {
  if (self->capacity < self->len + additional) {
    if (!self->ptr) {
      assert(!self->len && !self->capacity);
      *self = FUNC_NAME(with_capacity, CString)(additional);
    } else {
      self->ptr = realloc(
        self->ptr,
        (self->capacity = self->len + additional) * sizeof(Byte) + 1);
      memset(self->ptr + self->len, 0,
             (self->capacity - self->len) * sizeof(Byte) + 1);
    }
  }
}

static void FUNC_NAME(push_str, CString)(CString* self, CStr s) {
  if (s.ptr && s.len) {
    FUNC_NAME(reserve, CString)(self, s.len);
    memcpy(self->ptr + self->len, s.ptr, s.len * sizeof(Byte));
    self->len += s.len;
  }
}

impl_trait(CString){
  .with_capacity = FUNC_NAME(with_capacity, CString),
  .from = FUNC_NAME(from, CString),
  .reserve = FUNC_NAME(reserve, CString),
  .push_str = FUNC_NAME(push_str, CString),
};
