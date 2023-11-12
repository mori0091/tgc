// -*- coding: utf-8-unix -*-

// Copyright (c) 2023 Daishi Mori (mori0091)
//
// This software is released under the MIT License.
// See https://github.com/mori0091/tgc/blob/main/LICENSE
//
// GitHub tgc project
// https://github.com/mori0091/tgc

#ifndef FMT_PRINT_H_
#define FMT_PRINT_H_

#include "cstr/type_cstr.h"

#include "fmt/debug.h"
#include "fmt/display.h"
#include "fmt/formatter.h"

#include "primitive.h"

#define println(...)      fprintln(stdout, __VA_ARGS__)
#define print(...)        fprint(stdout, __VA_ARGS__)

#define eprintln(...)     fprintln(stderr, __VA_ARGS__)
#define eprint(...)       fprint(stderr, __VA_ARGS__)

#define fprintln(fp, ...) fprint(fp, __VA_OPT__(__VA_ARGS__, ) "\n")
#define fprint(fp, ...)   fprint_(fp, __VA_ARGS__)

#define fprint_(fp, ...)                                                 \
  do {                                                                   \
    Formatter out = FUNC_NAME(from_fp, Formatter)(fp);                   \
    FOREACH(print1, __VA_ARGS__);                                        \
  } while (0)

#define print1(x) GENERIC_TRAIT_DISPLAY(x).fmt(x, out)

// #define TYPES_FOR_DISPLAY JUST(T1, T2, ...)
#define GENERIC_TRAIT_DISPLAY(x)                                         \
  (GENERIC((x), EXPAND, trait_Display, DISPLAY_INSTANCES()))

#define trait_Display(T) trait(Display(T))
#define DISPLAY_INSTANCES()                                              \
  SQUASH(EXTRACT_OR_DEFAULT(TYPES_FOR_DISPLAY, ), int, char,             \
         Slice(char), Char, CStr, PTR(char), PTR(CONST(char)))

// --------------------------------------------------------------------
// def_Debug(Slice(char));
// #if defined(IMPLEMENT)
// impl_Debug_for(Slice(char)) {
//   fmt_write(out, "\"%.*s\"", (int)self.len, self.ptr);
// }
// #endif

// def_Display(Slice(char));
//  #if defined(IMPLEMENT)
//  impl_Display_for(Slice(char)) {
//    fmt_write(out, "%.*s", (int)self.len, self.ptr);
//  }
//  #endif

#endif // FMT_PRINT_H_
