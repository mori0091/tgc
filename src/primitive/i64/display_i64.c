#include "primitive.h"
#include <inttypes.h>

impl_Display_for(i64) {
  fmt_write(out, "%" PRId64, self);
}
