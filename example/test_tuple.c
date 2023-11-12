// -*- coding: utf-8-unix -*-

// Copyright (c) 2023 Daishi Mori (mori0091)
//
// This software is released under the MIT License.
// See https://github.com/mori0091/tgc/blob/main/LICENSE
//
// GitHub tgc project
// https://github.com/mori0091/tgc

#include "tuple.h"

#include "core.h"

#include <assert.h>
#include <stdio.h>

void test_tuple1(void) {
  __auto_type b = tuple(1, (char)'a');
  __auto_type c = tuple(2, (char)'b');
  printf("b = {._0 = %d, .1 = '%c'}\n", b._0, b._1);
  printf("c = {._0 = %d, .1 = '%c'}\n", c._0, c._1);
  static_assert(!typeeq(b, c), "");

  typedef Tuple(int, char) T;
  T d = {1, 'a'};
  T e = {2, 'b'};
  printf("d = {._0 = %d, .1 = '%c'}\n", d._0, d._1);
  printf("e = {._0 = %d, .1 = '%c'}\n", e._0, e._1);
  static_assert(typeeq(d, e), "");

  typedef Tuple(int, Tuple(int, char)) T2;
  T2 f = {1, {2, 'c'}};
  printf("f = {._0 = %d, ._1 = {._0 = %d, ._1 = '%c'}}\n", f._0, f._1._0,
         f._1._1);
}

int main(void) {
  printf("__STDC_VERSION__=%ld\n", __STDC_VERSION__);
  test_tuple1();
  return 0;
}
