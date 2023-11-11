#include "primitive.h"

impl_Display_for(char) {
  fmt_write(out, "%c", self);
}
