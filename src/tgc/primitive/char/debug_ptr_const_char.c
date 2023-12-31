// -*- coding: utf-8-unix -*-

// Copyright (c) 2023 Daishi Mori (mori0091)
//
// This software is released under the MIT License.
// See https://github.com/mori0091/tgc/blob/main/LICENSE
//
// GitHub tgc project
// https://github.com/mori0091/tgc

#include "tgc/cstr.h"
#include "tgc/primitive.h"

impl_Debug_for(PTR(CONST(char))) {
  trait(Debug(CStr)).fmt(cstr((char*)self), out);
}
