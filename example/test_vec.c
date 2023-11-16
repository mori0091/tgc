// -*- coding: utf-8-unix -*-

// Copyright (c) 2023 Daishi Mori (mori0091)
//
// This software is released under the MIT License.
// See https://github.com/mori0091/tgc/blob/main/LICENSE
//
// GitHub tgc project
// https://github.com/mori0091/tgc

#include <assert.h>
#include <stdio.h>

#include "tgc/fmt/print.h"
#include "tgc/prelude.h"

#define TYPES_FOR_VEC     JUST(PRIMITIVE_TYPES)
#define TYPES_FOR_DROP    JUST(APPLY(Vec, PRIMITIVE_TYPES))
#define TYPES_FOR_DISPLAY JUST(APPLY(Vec, PRIMITIVE_TYPES))

static void test_vec1(void) {
  // Vec(char) v = vec((char)'a', (char)'b', (char)'c');
  Vec(char) v = vecof(char, 'a', 'b', 'c');
  println("v = ", v);
  g_drop(v);
}

static void test_vec2(void) {
  // Scoped(Vec(int)) v0 = vec(1, 2, 3);
  Scoped(Vec(int)) v0 = vecof(int, 1, 2, 3);
  assert(v0.len == 3 && v0.capacity >= v0.len);

  Scoped(Vec(int)) v1 = trait(Clone(Vec(int))).clone(v0);
  assert(v1.len == 3 && v1.capacity >= v1.len);

  println("v1 = ", v1);

#if !defined(__GNUC__)
  g_drop(v1);
  g_drop(v0);
#endif
}

int main(void) {
  test_vec1();
  test_vec2();
  return 0;
}
