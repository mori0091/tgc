// -*- coding: utf-8-unix -*-

// Copyright (c) 2023 Daishi Mori (mori0091)
//
// This software is released under the MIT License.
// See https://github.com/mori0091/tgc/blob/main/LICENSE
//
// GitHub tgc project
// https://github.com/mori0091/tgc

#ifndef COPY_H_
#define COPY_H_

#include "clone.h"
#include "drop.h"

#define def_Copy(T)                                                      \
  enum { METADATA(T) = E_COPY };                                         \
  def_Clone(T);                                                          \
  def_Drop(T)

#define impl_Copy(T)                                                     \
  impl_Clone_for(T) { return self; }                                     \
  impl_Drop_for(T) { *self = (T){0}; }                                   \
  END_OF_STATEMENT

#endif // COPY_H_
