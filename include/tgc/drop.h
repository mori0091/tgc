// -*- coding: utf-8-unix -*-

// Copyright (c) 2023 Daishi Mori (mori0091)
//
// This software is released under the MIT License.
// See https://github.com/mori0091/tgc/blob/main/LICENSE
//
// GitHub tgc project
// https://github.com/mori0091/tgc

#ifndef TGC_DROP_H_
#define TGC_DROP_H_

#include "tgc/core.h"

/**
 * `Drop(T)`: Name of trait for deallocatable object of type `T`.
 *
 * \param T   A typename.
 */
#define Drop(T) TYPE_NAME(Drop, TYPEOF(T))

#define def_Drop(T)                                                      \
  void FUNC_NAME(drop, Drop(T))(T * self);                               \
  def_trait(Drop(T)) { void (*drop)(T * self); }

#define impl_Drop_for(T)                                                 \
  impl_trait(Drop(T)){.drop = FUNC_NAME(drop, Drop(T))};                 \
  void FUNC_NAME(drop, Drop(T))(T * self) /* {...} */

// #define TYPES_FOR_DROP JUST(T1, T2, ...)
#define GENERIC_DROP(x)                                                  \
  (GENERIC((x), EXPAND, trait_Drop, DROP_INSTANCES()))
#define trait_Drop(T) (trait(Drop(T)))
#define DROP_INSTANCES()                                                 \
  SQUASH(EXTRACT_OR_DEFAULT(TYPES_FOR_DROP, UNDEFINED))

#define g_drop(x) GENERIC_DROP(x).drop(&x)

#if defined(__GNUC__)
#define Scoped(T) T __attribute__((cleanup(FUNC_NAME(drop, Drop(T)))))
#else
#warning "Scoped(T) RAII feature is not supported."
#define Scoped(T) T
#endif

#endif // TGC_DROP_H_
