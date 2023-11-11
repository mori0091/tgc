#ifndef FMT_FORMATTER_H_
#define FMT_FORMATTER_H_

#include "cstring/type_cstring.h"

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

#endif // FMT_FORMATTER_H_
