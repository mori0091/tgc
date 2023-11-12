// -*- coding: utf-8-unix -*-

// Copyright (c) 2023 Daishi Mori (mori0091)
//
// This software is released under the MIT License.
// See https://github.com/mori0091/tgc/blob/main/LICENSE
//
// GitHub tgc project
// https://github.com/mori0091/tgc

#ifndef TGC_CSTRING_H_
#define TGC_CSTRING_H_

/**
 * \file cstring.h UTF-8 encoded growable string.
 *
 * - CString : UTF-8 encoded growable string.
 *   - CString trait(CString).with_capacity(size_t capacity)
 *   - CString trait(CString).from(CStr s)
 *   - void trait(CString).reserve(CString * self, size_t additional)
 *   - void trait(CString).push_str(CString * self, CStr s)
 *
 * - Clone(CString) :
 *   - CString trait(Clone(CString)).clone(const CString self)
 *
 * - Drop(CString) :
 *   - void trait(Drop(CString)).drop(CString * self)
 *
 * - Eq(CString) :
 *   - bool trait(Eq(CString)).eq(CString a, CString b)
 */

#include "tgc/cstr.h"

#include "tgc/cstring/type_cstring.h"

#include "tgc/cstring/clone_cstring.h"
#include "tgc/cstring/drop_cstring.h"
#include "tgc/cstring/eq_cstring.h"

#include "tgc/cstring/debug_cstring.h"
#include "tgc/cstring/display_cstring.h"

// --------------------------------------------------------------------
/**
 * Construct a CString from null-terminated char array.
 *
 * \param s Null-terminated array of chars (e.g. string literal in C).
 *
 * \note
 * `s` must be a null-terminated UTF-8 encoded string.
 */
#define cstring(s) (trait(CString).from(cstr(s)))

#endif // TGC_CSTRING_H_
