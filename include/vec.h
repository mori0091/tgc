#ifndef VEC_H_
#define VEC_H_

#include "vec/type_vec.h"

#include "vec/clone_vec.h"
#include "vec/drop_vec.h"
#include "vec/eq_vec.h"

#include "vec/debug_vec.h"
#include "vec/display_vec.h"

#if defined(IMPLEMENT)
#define use_Vec(T)                                                       \
  def_Vec(T);                                                            \
  impl_Vec(T)
#else
#define use_Vec(T) def_Vec(T)
#endif

#define def_Vec(T)                                                       \
  def_type_Vec(T);                                                       \
  def_Clone_for_Vec(T);                                                  \
  def_Drop_for_Vec(T);                                                   \
  def_Eq_for_Vec(T);                                                     \
  def_Debug_for_Vec(T);                                                  \
  def_Display_for_Vec(T);                                                \
  END_OF_STATEMENT

#define impl_Vec(T)                                                      \
  impl_type_Vec(T);                                                      \
  impl_Clone_for_Vec(T);                                                 \
  impl_Drop_for_Vec(T);                                                  \
  impl_Eq_for_Vec(T);                                                    \
  impl_Debug_for_Vec(T);                                                 \
  impl_Display_for_Vec(T);                                               \
  END_OF_STATEMENT

/**
 * Construct a Vec(T) initialized with the specified element values.
 *
 * \param T   Typename of the element type.
 * \param ... Element values.
 * \return    A Vec(T).
 */
#define vecof(T, ...) vec_(((T[]){__VA_ARGS__}))

/**
 * Construct a Vec(T) initialized with the specified element values.
 *
 * \param ... Element values.
 * \return Vec(T), where T is inferred to be the type of the first
 * element.
 *
 * \note Available for C23 or later.
 */
#define vec(...) vec_(((typeof(HEAD(__VA_ARGS__))[]){__VA_ARGS__}))

#define vec_(a)                                                          \
  (GENERIC_VEC((a)[0]).from(sizeof(a) / sizeof((a)[0]), (&(a)[0])))

// #define TYPES_FOR_VEC JUST(T1, T2, ...)

#define GENERIC_VEC(x)  (GENERIC((x), EXPAND, trait_Vec, VEC_INSTANCES()))
#define trait_Vec(T)    (trait(Vec(T)))
#define VEC_INSTANCES() SQUASH(EXTRACT_OR_DEFAULT(TYPES_FOR_VEC, ))

#endif // VEC_H_
