// -*- coding: utf-8-unix -*-

// Copyright (c) 2023 Daishi Mori (mori0091)
//
// This software is released under the MIT License.
// See https://github.com/mori0091/tgc/blob/main/LICENSE
//
// GitHub tgc project
// https://github.com/mori0091/tgc

#ifndef FUNCTION_H_
#define FUNCTION_H_

/**
 * Constructs typename of function object.
 *
 * `Fn(T, R)` means the function object takes one argument of type `T` and
 * returns value of type `R`.
 *
 * Note that `Fn(T1, T2, R)` is same as `Fn(T1, Fn(T2, R))`.
 * `Fn(T1, T2, T3, R)` is same as `Fn(T1, Fn(T2, Fn(T3, R)))`.
 *
 * \param T,... Comma-separated list of argument and return type names.
 */
#define Fn(T, ...) internal

#if !defined(IMPLEMENT)
#define use_Fn(T, ...) def_Fn(T, __VA_ARGS__)
#else
#define use_Fn(T, ...)                                                   \
  def_Fn(T, __VA_ARGS__);                                                \
  impl_Fn(T, __VA_ARGS__)
#endif

#if !defined(IMPLEMENT)
#define use_recursive_Fn(T, ...) def_recursive_Fn(T, __VA_ARGS__)
#else
#define use_recursive_Fn(T, ...)                                         \
  def_recursive_Fn(T, __VA_ARGS__);                                      \
  impl_recursive_Fn(T, __VA_ARGS__)
#endif

/**
 * Defines function object type `Fn(T, ...)`.
 * \param T,... Comma-separated list of argument and return type names.
 */
#define def_Fn(T, ...) internal

/**
 * Implements boilerplate code of type `Fn(T, ...)`.
 * \param T,... Comma-separated list of argument and return type names.
 */
#define impl_Fn(T, ...) internal

/**
 * Defines function object type Fn(T, ...) and underlying function object
 * types recursively.
 *
 * For example, `def_recursive_Fn(A, B, C, Ret);` is same as the following
 * code:
 * ~~~c
 * def_Fn(C, Ret);
 * def_Fn(B, C, Ret);
 * def_Fn(A, B, C, Ret);
 * ~~~
 *
 * \param T,... Comma-separated list of argument and return type names.
 */
#define def_recursive_Fn(T, ...) internal

/**
 * Implements boilerplate code of type Fn(T, ...) and underlying function
 * object types recursively.
 *
 * For example, `impl_recursive_Fn(A, B, C, Ret);` is same as the
 * following code:
 * ~~~c
 * impl_Fn(C, Ret);
 * impl_Fn(B, C, Ret);
 * impl_Fn(A, B, C, Ret);
 * ~~~
 *
 * \param T,... Comma-separated list of argument and return type names.
 */
#define impl_recursive_Fn(T, ...) internal

/**
 * Defines constructor of function object of type `Fn(T, ...)`.
 *
 * `fn(name, T, ...) { ... }` defines constructor and function body of the
 * function object.
 *
 * For example:
 * \include test_function.c
 *
 * \param name  Name of the constructor of the function object.
 * \param T,... Comma-separated list of argument and return type
 * names of the function object.
 */
#define fn(name, T, ...) /* {implementation} */ internal

/**
 * Apply function object to one or more arguments (partial application).
 * \param f            A function object.
 * \param x,...  One or more arguments.
 * \return Result value or another function object.
 */
#define fn_apply(f, x, ...) internal

#include "./internal/function.h"

#endif // FUNCTION_H_
