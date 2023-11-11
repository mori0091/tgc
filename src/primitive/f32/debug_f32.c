#include "primitive.h"

impl_Debug_for(f32) {
  fmt_write(out, "%f", (double)self);
}
