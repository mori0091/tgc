#include "cstring.h"

#include <string.h>

impl_Eq_for(CString) {
  return (a.len == b.len && !strncmp(a.ptr, b.ptr, a.len));
}
