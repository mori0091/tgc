#include "primitive.h"
#include <inttypes.h>

impl_Display_for(i32) {
  fmt_write(out, "%" PRId32, self);
}
