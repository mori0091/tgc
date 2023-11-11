#include "cstr.h"

#include <string.h>

impl_Eq_for(CStr) {
  return (a.len == b.len && !strncmp(a.ptr, b.ptr, a.len));
}
