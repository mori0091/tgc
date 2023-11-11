#include "cstring.h"

impl_Debug_for(CString) {
  fmt_write(out, "\"%.*s\"", (int)self.len, self.ptr);
}
