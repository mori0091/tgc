#include "char.h"

#include <string.h>

impl_Eq_for(Char) {
  return (a.len == b.len && !strncmp(a.ptr, b.ptr, a.len));
}
