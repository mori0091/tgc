#include "primitive.h"

impl_Display_for(f32) {
  fmt_write(out, "%f", (double)self);
}
