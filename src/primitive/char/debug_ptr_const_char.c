#include "cstr.h"
#include "primitive.h"

impl_Debug_for(PTR(CONST(char))) {
  trait(Debug(CStr)).fmt(cstr((char*)self), out);
}
