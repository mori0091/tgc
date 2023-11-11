#include "fmt/formatter.h"

static int FUNC_NAME(printf, Formatter)(const Formatter self,
                                        const char* fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  int len = vfprintf(self.fp, fmt, ap);
  va_end(ap);
  return len;
}

Formatter FUNC_NAME(from_fp, Formatter)(FILE* fp) {
  return (Formatter){.write = FUNC_NAME(printf, Formatter), .fp = fp};
}
