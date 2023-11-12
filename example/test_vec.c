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

#include "primitive.h"

#define IMPLEMENT
#define TYPES_FOR_VEC JUST(char, int)
// #define TYPES_FOR_VEC JUST(PRIMITIVE_TYPES)
#include "fmt/print.h" /* FIXME */
#include "vec.h"

FOREACH(use_Vec, EXTRACT_OR_DEFAULT(TYPES_FOR_VEC));

static void test_vec1(void) {
  // Vec(char) v = vec((char)'a', (char)'b', (char)'c');
  Vec(char) v = vecof(char, 'a', 'b', 'c');
  printf("v = ['%c'", v.ptr[0]);
  for (size_t i = 1; i < v.len; ++i) {
    printf(", '%c'", v.ptr[i]);
  }
  printf("]\n");
  g_drop(v);
}

static void test_vec2(void) {
  // Scoped(Vec(int)) v0 = vec(1, 2, 3);
  Scoped(Vec(int)) v0 = vecof(int, 1, 2, 3);
  assert(v0.len == 3 && v0.capacity >= v0.len);

  Scoped(Vec(int)) v1 = trait(Clone(Vec(int))).clone(v0);
  assert(v1.len == 3 && v1.capacity >= v1.len);

  printf("v1 = [");
  if (v1.len) {
    printf("%d", v1.ptr[0]);
    for (size_t i = 1; i < v1.len; ++i) {
      printf(", %d", v1.ptr[i]);
    }
  }
  printf("]\n");

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
