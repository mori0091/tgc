#include "primitive.h"

impl_Display_for(f64) {
  fmt_write(out, "%f", self);
}
