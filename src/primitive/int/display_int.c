#include "primitive.h"

#if defined(NEED_INT)
impl_Display_for(int) {
  fmt_write(out, "%d", self);
}
#endif
