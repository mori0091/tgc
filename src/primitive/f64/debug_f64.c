#include "primitive.h"

impl_Debug_for(f64) {
  fmt_write(out, "%f", self);
}
