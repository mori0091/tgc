// -*- coding: utf-8-unix -*-

// Copyright (c) 2023 Daishi Mori (mori0091)
//
// This software is released under the MIT License.
// See https://github.com/mori0091/tgc/blob/main/LICENSE
//
// GitHub tgc project
// https://github.com/mori0091/tgc

#ifndef TGC_CORE_H_
#define TGC_CORE_H_

#include <assert.h>
#include <stdbool.h>
#include <stdint.h>

#include "cppmp.h"

/**
 * May be used as the end-mark of a complex function-like macro
 * definition.
 */
#define END_OF_STATEMENT typedef struct end_of_statement end_of_statement

/**
 * Constructs typename identifier (of generic type).
 */
#define TYPE_NAME(...) MANGLE(__VA_ARGS__)

#define TYPEOF(T)      EXTRACT_OR_DEFAULT(CAT(TYPEOF_, T), T)

/**
 * Constructs function name identifier.
 *
 * \param f    Name of function (method).
 * \param ...  Typename of type parameters
 */
// #define FUNC_NAME(f, ...) FUNC_NAME_(f, MANGLE(__VA_ARGS__))
#define FUNC_NAME(f, ...) FUNC_NAME_(f, TYPE_NAME(__VA_ARGS__))
#define FUNC_NAME_(f, T)  CAT(T, CAT(_fn_, f))

/**
 * Typename of the trait struct of type `T`.
 */
#define Trait(T) TYPE_NAME(Trait, T)

/**
 * Name of trait object of type `T`.
 */
// #define trait(T) CAT(T, _trait_)
#define trait(T) CAT(TYPE_NAME(T), _trait_)

/**
 * Declare `trait(T)`.
 */
#define def_trait(T)                                                     \
  typedef struct Trait(T) Trait(T);                                      \
  extern const Trait(T) trait(T);                                        \
  struct Trait(T) /* {...}; */

/**
 * Define `trait(T)`.
 */
#define impl_trait(T) const Trait(T) trait(T) = /* {...}; */

#define METADATA(T)   CAT(TYPEOF(T), _METADATA)
#define IS_COPY(T)    (METADATA(T) & E_COPY)
#define IS_CLONE(T)   (METADATA(T) & E_CLONE)
#define IS_DROP(T)    (METADATA(T) & E_DROP)

enum {
  E_COPY = (1 << 0),
  E_CLONE = (1 << 1),
  E_DROP = (1 << 2),
};

/**
 * Causes compile error unless all traits specified in the arguments is
 * defined.
 * \param ... list of names of trait.
 */
#define require_trait(...) require_type(SEP_BY(COMMA, trait, __VA_ARGS__))

/**
 * Causes compile error unless all types specified in the arguments is
 * defined.
 * \param ... list of typenames.
 */
#define require_type(...) SEP_BY(SEMICOLON, require_type_, __VA_ARGS__)
#define require_type_(T)  static_assert(sizeof(T) == sizeof(T), "")

#define TYPEEQ(T, U)      _Generic(((T){0}), U : true, default : false)

#if __STDC_VERSION__ >= 202311L || defined(__GNUC__)
#define typeeq(a, b)                                                     \
  _Generic(((typeof(a)){0}), typeof(b) : true, default : false)
#endif

#endif // TGC_CORE_H_
