#include "cstring.h"

impl_Drop_for(CString) {
  if (self) {
    if (self->ptr) {
      free(self->ptr);
    }
    *self = (CString){0};
  }
}
