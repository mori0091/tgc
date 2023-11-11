#ifndef DROP_H_
#define DROP_H_

#include "core.h"

/**
 * `Drop(T)`: Name of trait for deallocatable object of type `T`.
 *
 * \param T   A typename.
 */
#define Drop(T) TYPE_NAME(Drop, TYPEOF(T))

#define def_Drop(T)                                                      \
  def_trait(Drop(T)) { void (*drop)(T * self); }

#define impl_Drop_for(T)                                                 \
  void FUNC_NAME(drop, Drop(T))(T * self);                               \
  impl_trait(Drop(T)){.drop = FUNC_NAME(drop, Drop(T))};                 \
  void FUNC_NAME(drop, Drop(T))(T * self) /* {...} */

// #define TYPES_FOR_DROP JUST(T1, T2, ...)
#define GENERIC_DROP(x)                                                  \
  (GENERIC_REDUNDANT((x), EXPAND, trait_Drop, DROP_INSTANCES()))
#define trait_Drop(T) (trait(Drop(T)))
#define DROP_INSTANCES()                                                 \
  SQUASH(EXTRACT_OR_DEFAULT(TYPES_FOR_DROP, ),                           \
         APPLY(Vec, EXTRACT_OR_DEFAULT(TYPES_FOR_VEC)))

#define g_drop(x) GENERIC_DROP(x).drop(&x)

#if defined(__GNUC__)
#define Scoped(T) T __attribute__((cleanup(FUNC_NAME(drop, Drop(T)))))
#else
#warning "Scoped(T) RAII feature is not supported."
#define Scoped(T) T
#endif

#endif // DROP_H_
