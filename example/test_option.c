// -*- coding: utf-8-unix -*-

// Copyright (c) 2023 Daishi Mori (mori0091)
//
// This software is released under the MIT License.
// See https://github.com/mori0091/tgc/blob/main/LICENSE
//
// GitHub tgc project
// https://github.com/mori0091/tgc

#include <assert.h>

#include "primitive.h"

#define IMPLEMENT
#include "option.h"

use_Option(int);

void test_option1(void) {
  Option(int) a = trait(Option(int)).Some(10);
  assert(!a.is_none);
  assert(a.value == 10);

  Option(int) n = trait(Option(int)).None;
  assert(n.is_none);

  Option(int) b = {.value = 20};
  assert(!b.is_none);
  assert(b.value == 20);

  Option(int) m = {.is_none = true};
  assert(m.is_none);
}

int main(void) {
  test_option1();
  return 0;
}
