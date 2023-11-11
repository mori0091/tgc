#include "cstr.h"
#include "primitive.h"

impl_Display_for(PTR(char)) {
  trait(Display(CStr)).fmt(cstr(self), out);
}
