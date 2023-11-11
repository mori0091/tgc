#ifndef REF_H_
#define REF_H_

#include "core.h"

/**
 * `Ref(T)`: Immutable reference to an object of type `T`.
 */
#define Ref(T) TYPE_NAME(Ref, T)

#define def_Ref(T)                                                       \
  typedef struct Ref(T) { const T* const ptr; }                          \
  Ref(T)

/**
 * `RefMut(T)`: Mutable reference to an object of type `T`.
 */
#define RefMut(T) TYPE_NAME(RefMut, T)

#define def_RefMut(T)                                                    \
  typedef struct RefMut(T) { T* const ptr; }                             \
  RefMut(T)

#define Box(T) TYPE_NAME(Box, T)

#define def_Box(T)                                                       \
  typedef struct Box(T) { const T* const ptr; }                          \
  Box(T)

#endif // REF_H_
