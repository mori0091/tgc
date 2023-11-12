// -*- coding: utf-8-unix -*-

// Copyright (c) 2023 Daishi Mori (mori0091)
//
// This software is released under the MIT License.
// See https://github.com/mori0091/tgc/blob/main/LICENSE
//
// GitHub tgc project
// https://github.com/mori0091/tgc

#ifndef TGC_FMT_FORMATTER_H_
#define TGC_FMT_FORMATTER_H_

#include "tgc/cstring/type_cstring.h"

#include <stdarg.h>
#include <stdio.h>

#define fmt_write(out_, fmt_, ...)

#undef fmt_write
#define fmt_write(out_, ...) ((out_).write((out_), __VA_ARGS__))

typedef struct Formatter Formatter;
struct Formatter {
  int (*write)(const Formatter self, const char* fmt, ...);
  union {
    CString* sp;
    FILE* fp;
  };
};
Formatter FUNC_NAME(from_sp, Formatter)(CString* sp);
Formatter FUNC_NAME(from_fp, Formatter)(FILE* fp);

#if defined(IMPLEMENT)
#endif

#endif // TGC_FMT_FORMATTER_H_
