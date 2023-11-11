#include "primitive.h"

impl_Display_for(bool) {
  fmt_write(out, "%s", self ? "true" : "false");
}
