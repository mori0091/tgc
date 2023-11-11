#include "primitive.h"

#if defined(NEED_SIZE_T)
impl_Debug_for(usize) {
  fmt_write(out, "%zu", self);
}
#endif
