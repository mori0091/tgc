// -*- coding: utf-8-unix -*-

// Copyright (c) 2023 Daishi Mori (mori0091)
//
// This software is released under the MIT License.
// See https://github.com/mori0091/tgc/blob/main/LICENSE
//
// GitHub tgc project
// https://github.com/mori0091/tgc

#ifndef CSTRING_TYPE_CSTRING_H_
#define CSTRING_TYPE_CSTRING_H_

#include "cstr/type_cstr.h"

enum { METADATA(CString) = E_CLONE | E_DROP };

/**
 * Dynamically resizable string allocated on heap memory.
 */
typedef struct CString {
  /**
   * Pointer to a byte array allocated on heap memory, or `NULL` if
   * `capacity` was 0.
   */
  Byte* ptr;
  /**
   * Length of the string within the byte array in bytes (<= `capacity`).
   */
  size_t len;
  /**
   * Current capacity of the byte array.
   */
  size_t capacity;
} CString;

def_trait(CString) {
  CString (*with_capacity)(size_t capacity);
  CString (*from)(CStr s);
  void (*reserve)(CString * self, size_t additional);
  void (*push_str)(CString * self, CStr s);
};

#endif // CSTRING_TYPE_CSTRING_H_
