// -*- coding: utf-8-unix -*-

// Copyright (c) 2023 Daishi Mori (mori0091)
//
// This software is released under the MIT License.
// See https://github.com/mori0091/tgc/blob/main/LICENSE
//
// GitHub tgc project
// https://github.com/mori0091/tgc

#ifndef CSTR_TYPE_CSTR_H_
#define CSTR_TYPE_CSTR_H_

#include "char/type_char.h"

typedef Slice(Byte) CStr;

def_trait(CStr) {
  CStr (*from_utf8)(Byte * ptr);
};
def_Copy(CStr);

#endif // CSTR_TYPE_CSTR_H_
