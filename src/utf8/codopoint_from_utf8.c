// -*- coding: utf-8-unix -*-

// Copyright (c) 2023 Daishi Mori (mori0091)
//
// This software is released under the MIT License.
// See https://github.com/mori0091/tgc/blob/main/LICENSE
//
// GitHub tgc project
// https://github.com/mori0091/tgc

#include "utf8.h"

char32_t codepoint_from_utf8(unsigned char* p) {
  if (is_utf8_1(p)) {
    return (char32_t)p[0];
  }
  if (is_utf8_2(p)) {
    return ((char32_t)(p[0] & 0x1F) << 6) | (char32_t)(p[1] & 0x3F);
  }
  if (is_utf8_3(p)) {
    return ((char32_t)(p[0] & 0x0F) << 12) |
           ((char32_t)(p[1] & 0x3F) << 6) | (char32_t)(p[2] & 0x3F);
  }
  if (is_utf8_4(p)) {
    return ((char32_t)(p[0] & 0x07) << 18) |
           ((char32_t)(p[1] & 0x3F) << 12) |
           ((char32_t)(p[2] & 0x3F) << 6) | (char32_t)(p[3] & 0x3F);
  }
  return (char32_t)0xFFFFFFFF;
}
