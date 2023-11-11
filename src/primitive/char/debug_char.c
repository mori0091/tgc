#include "primitive.h"

impl_Debug_for(char) {
  fmt_write(out, "'%c'", self);
}
