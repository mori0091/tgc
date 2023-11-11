#include "primitive.h"
#include <inttypes.h>

impl_Display_for(u8) {
  fmt_write(out, "%" PRIu8, self);
}
