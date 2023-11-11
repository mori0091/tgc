#ifndef CHAR_TYPE_CHAR_H_
#define CHAR_TYPE_CHAR_H_

#include "byte/slice_byte.h"
#include "byte/type_byte.h"

typedef Slice(Byte) Char;
def_Copy(Char);

#endif // CHAR_TYPE_CHAR_H_
