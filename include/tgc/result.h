// -*- coding: utf-8-unix -*-

// Copyright (c) 2023 Daishi Mori (mori0091)
//
// This software is released under the MIT License.
// See https://github.com/mori0091/tgc/blob/main/LICENSE
//
// GitHub tgc project
// https://github.com/mori0091/tgc

#ifndef TGC_RESULT_H_
#define TGC_RESULT_H_

#include "tgc/core.h"

#include <stdbool.h>

/**
 * Anonymous struct that holds either an ok value or an err value.
 *
 * ~~~c
 * // Define `MyResult` type.
 * // That has same structure of `Result(char, int)`.
 * typedef Result(char, int) MyResult;
 * // Constructor of `MyResult` of representing success (ok) value.
 * MyResult Ok(char ok) {
 *   return (MyResult){.ok = ok};
 * }
 * // Constructor of `MyResult` of representing error (err) value.
 * MyResult Err(int err) {
 *   return (MyResult){.err = err, .is_err = true};
 * }
 * ~~~
 */
#define Result(T, E)                                                     \
  struct {                                                               \
    union {                                                              \
      T ok;  /* available if and only if !is_err */                      \
      E err; /* available if and only if is_err */                       \
    };                                                                   \
    bool is_err;                                                         \
  }

// --------------------------------------------------------------------
#if 0

#define Result(T, E) TYPE_NAME(Result, T, E)

#if defined(IMPLEMENT)
#define use_Result(T, E)                                                 \
  def_Result(T, E);                                                      \
  impl_Result(T, E)
#else
#define use_Result(T, E) def_Result(T, E);
#endif

#define def_Result(T, E)                                                 \
  typedef struct {                                                       \
    const union {                                                        \
      T ok;  /* available if and only if !is_err */                      \
      E err; /* available if and only if is_err */                       \
    };                                                                   \
    const bool is_err;                                                   \
  } Result(T, E);                                                        \
  def_trait(Result(T, E)) {                                              \
    Result(T, E) (*Ok)(T ok);                                            \
    Result(T, E) (*Err)(E err);                                          \
  }

#define impl_Result(T, E)                                                \
  static Result(T, E) FUNC_NAME(Ok, Result(T, E))(T ok) {                \
    return (Result(T, E)){.ok = ok};                                     \
  }                                                                      \
  static Result(T, E) FUNC_NAME(Err, Result(T, E))(E err) {              \
    return (Result(T, E)){.err = err, .is_err = true};                   \
  }                                                                      \
  impl_trait(Result(T, E)) {                                             \
    .Ok = FUNC_NAME(Ok, Result(T, E)),                                   \
    .Err = FUNC_NAME(Err, Result(T, E)),                                 \
  }

#endif
// --------------------------------------------------------------------

#endif // TGC_RESULT_H_
