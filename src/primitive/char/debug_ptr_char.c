#include "cstr.h"
#include "primitive.h"

impl_Debug_for(PTR(char)) {
  trait(Debug(CStr)).fmt(cstr(self), out);
}
