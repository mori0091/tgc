#include "primitive.h"
#include <inttypes.h>

impl_Debug_for(u8) {
  fmt_write(out, "%" PRIu8, self);
}
