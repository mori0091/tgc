#ifndef CSTRING_H_
#define CSTRING_H_

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

#include "cstr.h"

#include "cstring/type_cstring.h"

#include "cstring/clone_cstring.h"
#include "cstring/drop_cstring.h"
#include "cstring/eq_cstring.h"

#include "cstring/debug_cstring.h"
#include "cstring/display_cstring.h"

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

#endif // CSTRING_H_
