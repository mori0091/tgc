#include "primitive.h"

#if defined(NEED_INT)
impl_Debug_for(int) {
  fmt_write(out, "%d", self);
}
#endif
