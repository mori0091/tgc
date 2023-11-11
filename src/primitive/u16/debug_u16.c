#include "primitive.h"
#include <inttypes.h>

impl_Debug_for(u16) {
  fmt_write(out, "%" PRIu16, self);
}
