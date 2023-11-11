#include "primitive.h"

#if defined(NEED_SIZE_T)
impl_Display_for(usize) {
  fmt_write(out, "%zu", self);
}
#endif
