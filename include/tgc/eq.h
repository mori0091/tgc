// -*- coding: utf-8-unix -*-

// Copyright (c) 2023 Daishi Mori (mori0091)
//
// This software is released under the MIT License.
// See https://github.com/mori0091/tgc/blob/main/LICENSE
//
// GitHub tgc project
// https://github.com/mori0091/tgc

#ifndef TGC_EQ_H_
#define TGC_EQ_H_

#include "tgc/core.h"

#include <stdbool.h>

/**
 * `Eq(T)`: Name of trait for equality test of type `T`.
 *
 * \param T   A typename.
 */
#define Eq(T) TYPE_NAME(Eq, TYPEOF(T))

#define def_Eq(T)                                                        \
  def_trait(Eq(T)) {                                                     \
    /* Required method. */                                               \
    bool (*eq)(T a, T b);                                                \
    /* Provided methods. */                                              \
    bool (*ne)(T a, T b);                                                \
  }

#define impl_Eq_for(T)                                                   \
  static bool FUNC_NAME(eq, Eq(T))(T a, T b);                            \
  static bool FUNC_NAME(ne, Eq(T))(T a, T b);                            \
  impl_trait(Eq(T)){                                                     \
    .eq = FUNC_NAME(eq, Eq(T)),                                          \
    .ne = FUNC_NAME(ne, Eq(T)),                                          \
  };                                                                     \
  static bool FUNC_NAME(ne, Eq(T))(T a, T b) {                           \
    return !trait(Eq(T)).eq(a, b);                                       \
  }                                                                      \
  static bool FUNC_NAME(eq, Eq(T))(T a, T b) /* {...} */

#define g_eq(a, b)          (GENERIC_TRAIT_EQ(a).eq((a), (b)))
#define g_ne(a, b)          (GENERIC_TRAIT_EQ(a).ne((a), (b)))

#define GENERIC_TRAIT_EQ(a) GENERIC(a, EXPAND, trait_Eq, EQ_INSTANCES())
#define trait_Eq(T)         trait(Eq(T))
#define EQ_INSTANCES()      SQUASH(EXTRACT_OR_DEFAULT(TYPES_FOR_EQ, ))

#endif // TGC_EQ_H_
