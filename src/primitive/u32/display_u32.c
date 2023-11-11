#include "primitive.h"
#include <inttypes.h>

impl_Display_for(u32) {
  fmt_write(out, "%" PRIu32, self);
}
