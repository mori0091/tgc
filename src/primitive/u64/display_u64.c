#include "primitive.h"
#include <inttypes.h>

impl_Display_for(u64) {
  fmt_write(out, "%" PRIu64, self);
}
