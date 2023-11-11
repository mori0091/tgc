#include "primitive.h"

#if defined(NEED_INT)
impl_Eq_for(int) {
  return a == b;
}
#endif
