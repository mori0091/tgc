#ifndef TGC_PRELUDE_H_
#define TGC_PRELUDE_H_

#include "tgc/char.h"
#include "tgc/cstr.h"
#include "tgc/cstring.h"
#include "tgc/primitive.h"
#include "tgc/unit.h"

#include "tgc/slice.h"
FOREACH(def_Slice, Unit, Char, CStr, PRIMITIVE_TYPES);
FOREACH(def_Slice, Slice(char));

#include "tgc/vec.h"
FOREACH(def_Vec, Unit, Char, CStr, PRIMITIVE_TYPES);
FOREACH(def_Vec, Slice(char));

#endif // TGC_PRELUDE_H_
