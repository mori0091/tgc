// -*- coding: utf-8-unix -*-

// Copyright (c) 2023 Daishi Mori (mori0091)
//
// This software is released under the MIT License.
// See https://github.com/mori0091/tgc/blob/main/LICENSE
//
// GitHub tgc project
// https://github.com/mori0091/tgc

#include "tgc/fmt/formatter.h"

static int FUNC_NAME(format, Formatter)(const Formatter self,
                                        const char* fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  int len = vsnprintf(NULL, 0, fmt, ap);
  va_end(ap);
  if (len <= 0)
    return len;
  trait(CString).reserve(self.sp, len);
  va_start(ap, fmt);
  vsnprintf(self.sp->ptr + self.sp->len, len + 1, fmt, ap);
  va_end(ap);
  self.sp->len += len;
  return len;
}

Formatter FUNC_NAME(from_sp, Formatter)(CString* sp) {
  return (Formatter){.write = FUNC_NAME(format, Formatter), .sp = sp};
}
