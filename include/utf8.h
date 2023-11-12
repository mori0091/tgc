// -*- coding: utf-8-unix -*-

// Copyright (c) 2023 Daishi Mori (mori0091)
//
// This software is released under the MIT License.
// See https://github.com/mori0091/tgc/blob/main/LICENSE
//
// GitHub tgc project
// https://github.com/mori0091/tgc

#ifndef UTF8_H_
#define UTF8_H_

#include <stdbool.h>
#include <uchar.h>

#define UNICODE_CODEPOINT_MIN ((char32_t)0x0000)
#define UNICODE_CODEPOINT_MAX ((char32_t)0x10FFFF)

char32_t codepoint_from_utf8(unsigned char* p);

bool is_utf8_1(unsigned char* p);
bool is_utf8_2(unsigned char* p);
bool is_utf8_3(unsigned char* p);
bool is_utf8_4(unsigned char* p);

#if defined(IMPLEMENT)
#endif

#endif // UTF8_H_
