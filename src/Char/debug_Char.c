#include "char.h"

impl_Debug_for(Char) {
  fmt_write(out, "'%.*s'", (int)self.len, self.ptr);
}
