#include "primitive.h"
#include <inttypes.h>

impl_Debug_for(u64) {
  fmt_write(out, "%" PRIu64, self);
}
