#include "primitive.h"
#include <inttypes.h>

impl_Display_for(u16) {
  fmt_write(out, "%" PRIu16, self);
}