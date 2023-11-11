#include "cstr.h"
#include "primitive.h"

impl_Display_for(PTR(CONST(char))) {
  trait(Display(CStr)).fmt(cstr((char*)self), out);
}
