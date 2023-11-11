#include "cstr.h"

impl_Display_for(CStr) {
  fmt_write(out, "%.*s", (int)self.len, self.ptr);
}
