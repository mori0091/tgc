#include "primitive.h"
#include <inttypes.h>

impl_Debug_for(i16) {
  fmt_write(out, "%" PRId16, self);
}
