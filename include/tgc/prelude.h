// -*- coding: utf-8-unix -*-

// Copyright (c) 2023 Daishi Mori (mori0091)
//
// This software is released under the MIT License.
// See https://github.com/mori0091/tgc/blob/main/LICENSE
//
// GitHub tgc project
// https://github.com/mori0091/tgc

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
