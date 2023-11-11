#include "char.h"

impl_Display_for(Char) {
  fmt_write(out, "%.*s", (int)self.len, self.ptr);
}
