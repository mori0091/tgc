// -*- coding: utf-8-unix -*-

// Copyright (c) 2023 Daishi Mori (mori0091)
//
// This software is released under the MIT License.
// See https://github.com/mori0091/tgc/blob/main/LICENSE
//
// GitHub tgc project
// https://github.com/mori0091/tgc

#ifndef TGC_PRIMITIVE_H_
#define TGC_PRIMITIVE_H_

#include "tgc/core.h"

#include "tgc/copy.h"
#include "tgc/eq.h"
#include "tgc/fmt/debug.h"
#include "tgc/fmt/display.h"
#include "tgc/slice.h"

#include "cppmp/foreach.h"
#include "cppmp/squash.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

/**
 * A list of all typical primitive types except for type aliases.
 */
#define PRIMITIVE_TYPES                                                  \
  TOTALLY_ORDERED_PRIMITIVE_TYPES, PARTIALLY_ORDERED_PRIMITIVE_TYPES

/**
 * A list of typical primitive types that are totally ordered sets.
 */
#define TOTALLY_ORDERED_PRIMITIVE_TYPES                                  \
  BOOLEAN_TYPES, CHARACTER_TYPES, INTEGER_TYPES

/**
 * A list of typical primitive types that are partially ordered sets.
 */
#define PARTIALLY_ORDERED_PRIMITIVE_TYPES REAL_FLOATING_TYPES

/**
 * A list of typical primitive boolean types.
 */
#define BOOLEAN_TYPES bool

/**
 * A list of typical primitive character types.
 */
#define CHARACTER_TYPES char

/**
 * A list of typical primitive integer types.
 */
#define INTEGER_TYPES i8, i16, i32, i64, u8, u16, u32, u64

/**
 * A list of typical primitive real floating-point number types.
 */
#define REAL_FLOATING_TYPES f32, f64

/**
 * Shorthand of `size_t`.
 */
#define usize size_t

/**
 * Shorthand of `int8_t`.
 */
#define i8 int8_t
/**
 * Shorthand of `int16_t`.
 */
#define i16 int16_t
/**
 * Shorthand of `int32_t`.
 */
#define i32 int32_t
/**
 * Shorthand of `int64_t`.
 */
#define i64 int64_t

/**
 * Shorthand of `uint8_t`.
 */
#define u8 uint8_t
/**
 * Shorthand of `uint16_t`.
 */
#define u16 uint16_t
/**
 * Shorthand of `uint32_t`.
 */
#define u32 uint32_t
/**
 * Shorthand of `uint64_t`.
 */
#define u64 uint64_t

/**
 * Shorthand of `float`.
 */
#define f32 float
/**
 * Shorthand of `double`.
 */
#define f64      double

#define Ptr(T)   T*
#define Const(T) T const
#define PTR(T)   TYPE_NAME(PTR, TYPEOF(T))
#define CONST(T) TYPE_NAME(CONST, TYPEOF(T))

/**
 * `char *`.
 */
typedef Ptr(char) PTR(char);
def_Debug(PTR(char));
def_Display(PTR(char));

/**
 * `const char *`.
 */
typedef Ptr(Const(char)) PTR(CONST(char));
def_Debug(PTR(CONST(char)));
def_Display(PTR(CONST(char)));

#define def_(T)                                                          \
  def_Copy(T);                                                           \
  def_Eq(T);                                                             \
  def_Debug(T);                                                          \
  def_Display(T);                                                        \
  def_Slice(T);                                                          \
  END_OF_STATEMENT

FOREACH(def_, SQUASH(PRIMITIVE_TYPES));

#include <limits.h>

#if INT_MAX == INT16_MAX
static_assert(TYPEEQ(int, int16_t), "");
#define TYPEOF_int JUST(int16_t)

#elif INT_MAX == INT32_MAX
static_assert(TYPEEQ(int, int32_t), "");
#define TYPEOF_int JUST(int32_t)

#elif INT_MAX == INT64_MAX
static_assert(TYPEEQ(int, int64_t), "");
#define TYPEOF_int JUST(int64_t)

#else
#define NEED_INT
def_(int);

#endif

#if SIZE_MAX == UINT16_MAX
static_assert(TYPEEQ(size_t, uint16_t), "");
#define TYPEOF_size_t JUST(uint16_t)

#elif SIZE_MAX == UINT32_MAX
static_assert(TYPEEQ(size_t, uint32_t), "");
#define TYPEOF_size_t JUST(uint32_t)

#elif SIZE_MAX == UINT64_MAX
static_assert(TYPEEQ(size_t, uint64_t), "");
#define TYPEOF_size_t JUST(uint64_t)

#else
#define NEED_SIZE_T
def_(size_t);

#endif

#endif // TGC_PRIMITIVE_H_
