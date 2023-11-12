// -*- coding: utf-8-unix -*-

// Copyright (c) 2023 Daishi Mori (mori0091)
//
// This software is released under the MIT License.
// See https://github.com/mori0091/tgc/blob/main/LICENSE
//
// GitHub tgc project
// https://github.com/mori0091/tgc

#ifndef TGC_UNIT_H_
#define TGC_UNIT_H_

typedef struct {
  char _; /* dummy (ISO C don't permit zero-sized struct) */
} Unit;

extern const Unit UNIT;

#include "tgc/copy.h"
def_Copy(Unit);

#include "tgc/eq.h"
def_Eq(Unit);

#include "tgc/fmt/debug.h"
def_Debug(Unit);

#include "tgc/fmt/display.h"
def_Display(Unit);

#endif // TGC_UNIT_H_
