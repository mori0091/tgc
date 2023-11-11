#include "cstring.h"

impl_Clone_for(CString) {
  CStr s = {.ptr = self.ptr, .len = self.len};
  CString ret = {0};
  trait(CString).push_str(&ret, s);
  return ret;
}
