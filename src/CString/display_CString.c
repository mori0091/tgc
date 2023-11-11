#include "cstring.h"

impl_Display_for(CString) {
  fmt_write(out, "%.*s", (int)self.len, self.ptr);
}
