#include "primitive.h"
#include <inttypes.h>

impl_Display_for(i8) {
  fmt_write(out, "%" PRId8, self);
}
