// -*- coding: utf-8-unix -*-

// Copyright (c) 2023 Daishi Mori (mori0091)
//
// This software is released under the MIT License.
// See https://github.com/mori0091/tgc/blob/main/LICENSE
//
// GitHub tgc project
// https://github.com/mori0091/tgc

#ifndef TGC_OPTION_H_
#define TGC_OPTION_H_

#include "tgc/clone.h"
#include "tgc/drop.h"

#define Option(T) TYPE_NAME(Option, TYPEOF(T))

#if defined(IMPLEMENT)
#define use_Option(T)                                                    \
  def_Option(T);                                                         \
  impl_Option(T)
#else
#define use_Option(T) def_Option(T);
#endif

#define def_Option(T)                                                    \
  enum { METADATA(Option(T)) = METADATA(T) };                            \
  typedef struct {                                                       \
    T value; /* available if and only if !is_none */                     \
    bool is_none;                                                        \
  } Option(T);                                                           \
                                                                         \
  def_Clone(Option(T));                                                  \
  def_Drop(Option(T));                                                   \
                                                                         \
  def_trait(Option(T)) {                                                 \
    Option(T) (*Some)(T value);                                          \
    Option(T) None;                                                      \
  }

#define impl_Option(T)                                                   \
  impl_Clone_for(Option(T)) {                                            \
    if (!IS_CLONE(T)) {                                                  \
      return self;                                                       \
    } else if (self.is_none) {                                           \
      return self;                                                       \
    } else {                                                             \
      return trait(Option(T)).Some(trait(Clone(T)).clone(self.value));   \
    }                                                                    \
  }                                                                      \
                                                                         \
  impl_Drop_for(Option(T)) {                                             \
    if (IS_DROP(T)) {                                                    \
      if (!self->is_none) {                                              \
        trait(Drop(T)).drop(&self->value);                               \
      }                                                                  \
    }                                                                    \
    *self = trait(Option(T)).None;                                       \
  }                                                                      \
                                                                         \
  static Option(T) FUNC_NAME(Some, Option(T))(T value) {                 \
    return (Option(T)){.value = value};                                  \
  }                                                                      \
  impl_trait(Option(T)) {                                                \
    .Some = FUNC_NAME(Some, Option(T)), .None = {.is_none = true},       \
  }

#endif // TGC_OPTION_H_
