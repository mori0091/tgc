// -*- coding: utf-8-unix -*-

// Copyright (c) 2023 Daishi Mori (mori0091)
//
// This software is released under the MIT License.
// See https://github.com/mori0091/tgc/blob/main/LICENSE
//
// GitHub tgc project
// https://github.com/mori0091/tgc

#ifndef TGC_G_ASSERT_H_
#define TGC_G_ASSERT_H_

#include "tgc/eq.h"
// #include "tgc/ord.h"

#define assert_eq(a, b)                                                  \
  assert_binop_(__FILE__, __LINE__, #a, "==", #b, (a), g_eq, (b))

#define assert_binop_(file_, line_, expra_, exprop_, exprb_, a_, op_,    \
                      b_)                                                \
  do {                                                                   \
    if (op_(a_, b_))                                                     \
      break;                                                             \
    println("Assertion failed:", file_, ":", line_);                     \
    println("Expected " ESC_YELLOW, expra_, " ", exprop_, " ", exprb_,   \
            ESC_DEFAULT);                                                \
    println("But LHS (", expra_, ") was " ESC_GREEN, a_, ESC_DEFAULT);   \
    println("    RHS (", exprb_, ") was " ESC_RED, b_, ESC_DEFAULT);     \
    abort();                                                             \
  } while (0)

#define ESC_RESET         "\033[0m"

#define ESC_RED           "\033[31m"
#define ESC_GREEN         "\033[32m"
#define ESC_YELLOW        "\033[33m"
#define ESC_BLUE          "\033[34m"
#define ESC_MAGENTA       "\033[35m"
#define ESC_CYAN          "\033[36m"
#define ESC_WHITE         "\033[37m"

#define ESC_DEFAULT       "\033[39m"

#define ESC_LIGHT_RED     "\033[91m"
#define ESC_LIGHT_GREEN   "\033[92m"
#define ESC_LIGHT_YELLOW  "\033[93m"
#define ESC_LIGHT_BLUE    "\033[94m"
#define ESC_LIGHT_MAGENTA "\033[95m"
#define ESC_LIGHT_CYAN    "\033[96m"
#define ESC_LIGHT_WHITE   "\033[97m"

#endif // TGC_G_ASSERT_H_
