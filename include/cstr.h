// -*- coding: utf-8-unix -*-

// Copyright (c) 2023 Daishi Mori (mori0091)
//
// This software is released under the MIT License.
// See https://github.com/mori0091/tgc/blob/main/LICENSE
//
// GitHub tgc project
// https://github.com/mori0091/tgc

#ifndef CSTR_H_
#define CSTR_H_

#include "cstr/eq_cstr.h"
#include "cstr/type_cstr.h"

#include "cstr/debug_cstr.h"
#include "cstr/display_cstr.h"

// --------------------------------------------------------------------
/**
 * Construct a CStr from null-terminated UTF-8 encoded string.
 *
 * \param s  Pointer to null-terminated UTF-8 encoded string.
 * \return A CStr.
 */
#define cstr(s) (trait(CStr).from_utf8(s))

#endif // CSTR_H_
