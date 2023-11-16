// -*- coding: utf-8-unix -*-

// Copyright (c) 2023 Daishi Mori (mori0091)
//
// This software is released under the MIT License.
// See https://github.com/mori0091/tgc/blob/main/LICENSE
//
// GitHub tgc project
// https://github.com/mori0091/tgc

#ifndef TGC_UNIT_TYPE_UNIT_H_
#define TGC_UNIT_TYPE_UNIT_H_

#include "tgc/copy.h"

typedef struct {
  char _; /* dummy (ISO C don't permit zero-sized struct) */
} Unit;

extern const Unit UNIT;

def_Copy(Unit);

#endif // TGC_UNIT_TYPE_UNIT_H_
