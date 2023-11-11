#include "primitive.h"

#if defined(NEED_SIZE_T)
impl_Eq_for(usize) {
  return a == b;
}
#endif
