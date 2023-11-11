#ifndef CSTR_TYPE_CSTR_H_
#define CSTR_TYPE_CSTR_H_

#include "char/type_char.h"

typedef Slice(Byte) CStr;

def_trait(CStr) {
  CStr (*from_utf8)(Byte * ptr);
};
def_Copy(CStr);

#endif // CSTR_TYPE_CSTR_H_
