// -*- coding: utf-8-unix -*-

// Copyright (c) 2023 Daishi Mori (mori0091)
//
// This software is released under the MIT License.
// See https://github.com/mori0091/tgc/blob/main/LICENSE
//
// GitHub tgc project
// https://github.com/mori0091/tgc

#ifndef CLONE_H_
#define CLONE_H_

#include "core.h"
#include <stdlib.h>

/**
 * `Clone(T)`: Trait for cloneable object of type `T`.
 */
#define Clone(T) TYPE_NAME(Clone, TYPEOF(T))

#define def_Clone(T)                                                     \
  def_trait(Clone(T)) { T (*clone)(const T self); }

#define impl_Clone_for(T)                                                \
  static T FUNC_NAME(clone, Clone(T))(const T self);                     \
  impl_trait(Clone(T)){.clone = FUNC_NAME(clone, Clone(T))};             \
  static T FUNC_NAME(clone, Clone(T))(const T self) /* {...} */

// #define TYPES_FOR_CLONE JUST(T1, T2, ...)
#define GENERIC_CLONE(x)                                                 \
  (GENERIC_REDUNDANT((x), EXPAND, trait_Clone, CLONE_INSTANCES()))
#define trait_Clone(T) (trait(Clone(T)))
#define CLONE_INSTANCES()                                                \
  SQUASH(EXTRACT_OR_DEFAULT(TYPES_FOR_CLONE, ),                          \
         APPLY(Vec, EXTRACT_OR_DEFAULT(TYPES_FOR_VEC)))

#define g_clone(x) GENERIC_CLONE(x).clone(x)

#endif // CLONE_H_
