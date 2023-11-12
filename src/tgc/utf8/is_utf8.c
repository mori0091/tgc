// -*- coding: utf-8-unix -*-

// Copyright (c) 2023 Daishi Mori (mori0091)
//
// This software is released under the MIT License.
// See https://github.com/mori0091/tgc/blob/main/LICENSE
//
// GitHub tgc project
// https://github.com/mori0091/tgc

#include "tgc/utf8.h"

#define UTF8_tail(c) (0x80 <= (c) && (c) < 0xBF)

bool is_utf8_1(unsigned char* p) {
  return (p[0] < 0x80);
}

bool is_utf8_2(unsigned char* p) {
  return (0xC2 <= p[0] && p[0] <= 0xDF && UTF8_tail(p[1]));
}

bool is_utf8_3(unsigned char* p) {
  if (0xE0 == p[0]) {
    return (0xA0 <= p[1] && p[1] <= 0xBF && UTF8_tail(p[2]));
  }
  if (0xE1 <= p[0] && p[0] <= 0xEC) {
    return (UTF8_tail(p[1]) && UTF8_tail(p[2]));
  }
  if (0xED == p[0]) {
    return (0x80 <= p[1] && p[1] <= 0x9F && UTF8_tail(p[2]));
  }
  if (0xEE <= p[0] && p[0] <= 0xEF) {
    return (UTF8_tail(p[1]) && UTF8_tail(p[2]));
  }
  return false;
}

bool is_utf8_4(unsigned char* p) {
  if (0xF0 == p[0]) {
    return (0x90 <= p[1] && p[1] <= 0xBF && UTF8_tail(p[2]) &&
            UTF8_tail(p[3]));
  }
  if (0xF1 <= p[0] && p[0] <= 0xF3) {
    return (UTF8_tail(p[1]) && UTF8_tail(p[2]) && UTF8_tail(p[3]));
  }
  if (0xF4 == p[0]) {
    return (0x80 <= p[1] && p[1] <= 0x8F && UTF8_tail(p[2]) &&
            UTF8_tail(p[3]));
  }
  return false;
}
