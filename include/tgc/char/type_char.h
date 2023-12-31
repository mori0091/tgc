// -*- coding: utf-8-unix -*-

// Copyright (c) 2023 Daishi Mori (mori0091)
//
// This software is released under the MIT License.
// See https://github.com/mori0091/tgc/blob/main/LICENSE
//
// GitHub tgc project
// https://github.com/mori0091/tgc

#ifndef TGC_CHAR_TYPE_CHAR_H_
#define TGC_CHAR_TYPE_CHAR_H_

#include "tgc/byte/slice_byte.h"
#include "tgc/byte/type_byte.h"

typedef Slice(Byte) Char;
def_Copy(Char);

#endif // TGC_CHAR_TYPE_CHAR_H_
