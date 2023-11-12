// -*- coding: utf-8-unix -*-

// Copyright (c) 2023 Daishi Mori (mori0091)
//
// This software is released under the MIT License.
// See https://github.com/mori0091/tgc/blob/main/LICENSE
//
// GitHub tgc project
// https://github.com/mori0091/tgc

#define IMPLEMENT
#include "cstring.h"

#include <assert.h>
#include <stdio.h>

void test_cstring0(void) {
  printf("-- %s --\n", __func__);
  CString s1 = {0};
  CString s2 = cstring("");
  assert(!s1.ptr && !s1.len && !s1.capacity);
  assert(!s2.ptr && !s2.len && !s2.capacity);
  trait(Drop(CString)).drop(&s2); /* noop */
  trait(Drop(CString)).drop(&s1); /* noop */
}

void test_cstring1(void) {
  printf("-- %s --\n", __func__);
  CString s = trait(CString).with_capacity(10);
  assert(s.ptr && !s.len && 10 <= s.capacity);
  trait(Drop(CString)).drop(&s);
  assert(!s.ptr && !s.len && !s.capacity);
}

void test_cstring2(void) {
  printf("-- %s --\n", __func__);
  CString s1 = cstring("Hello ");
  CStr s2 = cstr("world");
  assert(s1.ptr && s1.len == 6 && s1.len <= s1.capacity);
  assert(s2.ptr && s2.len == 5);
  printf("s1 == \"%s\"\n", s1.ptr);
  printf("s2 == \"%s\"\n", s2.ptr);

  trait(CString).push_str(&s1, s2);
  assert(s1.ptr && s1.len == 11 && s1.len <= s1.capacity);
  printf("(s1 += s2) == \"%s\"\n", s1.ptr);

  trait(Drop(CString)).drop(&s1);
  assert(!s1.ptr && !s1.len && !s1.capacity);
}

void test_cstring3(void) {
  printf("-- %s --\n", __func__);
  CStr s = cstr(u8"こんにちは");
  assert(s.ptr && s.len == 15);
  printf("%s\n", s.ptr);
}

int main(void) {
  test_cstring0();
  test_cstring1();
  test_cstring2();
  test_cstring3();
  return 0;
}
