#include "primitive.h"

impl_Debug_for(bool) {
  fmt_write(out, "%s", self ? "true" : "false");
}
