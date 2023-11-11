#include "cstr.h"

impl_Debug_for(CStr) {
  fmt_write(out, "\"%.*s\"", (int)self.len, self.ptr);
}
