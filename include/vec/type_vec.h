#ifndef VEC_TYPE_VEC_H_
#define VEC_TYPE_VEC_H_

#include <stdlib.h>
#include <string.h>

/**
 * `Vec(T)`: Variable length array, allocated on heap memory, of type `T`.
 */
#define Vec(T) TYPE_NAME(Vec, TYPEOF(T))

#if !defined(IMPLEMENT)
#define use_type_Vec(T) def_type_Vec(T)
#else
#define use_type_Vec(T)                                                  \
  def_type_Vec(T);                                                       \
  impl_type_Vec(T)
#endif

#define def_type_Vec(T)                                                  \
  enum { METADATA(Vec(T)) = E_CLONE | E_DROP };                          \
  typedef struct Vec(T) {                                                \
    T* ptr;                                                              \
    size_t len;                                                          \
    size_t capacity;                                                     \
  }                                                                      \
  Vec(T);                                                                \
                                                                         \
  def_trait(Vec(T)) {                                                    \
    Vec(T) (*with_capacity)(size_t capacity);                            \
    Vec(T) (*from)(size_t len, const T* a);                              \
    void (*push)(Vec(T) * v, T x);                                       \
  };                                                                     \
                                                                         \
  END_OF_STATEMENT

#define impl_type_Vec(T)                                                 \
  static Vec(T) FUNC_NAME(with_capacity, Vec(T))(size_t capacity) {      \
    if (!capacity) {                                                     \
      return (Vec(T)){0};                                                \
    } else {                                                             \
      return (Vec(T)){.ptr = calloc(capacity, sizeof(T)),                \
                      .len = 0,                                          \
                      .capacity = capacity};                             \
    }                                                                    \
  }                                                                      \
  static Vec(T) FUNC_NAME(from, Vec(T))(size_t len, const T* a) {        \
    if (!len) {                                                          \
      return (Vec(T)){0};                                                \
    } else {                                                             \
      Vec(T) v = FUNC_NAME(with_capacity, Vec(T))(len);                  \
      v.len = len;                                                       \
      if (IS_COPY(T)) {                                                  \
        memcpy(v.ptr, a, len * sizeof(T));                               \
      } else {                                                           \
        for (size_t i = 0; i < v.len; ++i) {                             \
          v.ptr[i] = trait(Clone(T)).clone(a[i]);                        \
        }                                                                \
      }                                                                  \
      return v;                                                          \
    }                                                                    \
  }                                                                      \
  static void FUNC_NAME(push, Vec(T))(Vec(T) * v, T x) {                 \
    if (v->len == v->capacity) {                                         \
      v->capacity += 8;                                                  \
      if (v->ptr) {                                                      \
        v->ptr = realloc(v->ptr, v->capacity * sizeof(T));               \
      } else {                                                           \
        v->ptr = calloc(v->capacity, sizeof(T));                         \
      }                                                                  \
    }                                                                    \
    v->ptr[v->len++] = x;                                                \
  }                                                                      \
  impl_trait(Vec(T)){                                                    \
    .with_capacity = FUNC_NAME(with_capacity, Vec(T)),                   \
    .from = FUNC_NAME(from, Vec(T)),                                     \
    .push = FUNC_NAME(push, Vec(T)),                                     \
  };                                                                     \
  END_OF_STATEMENT

#endif // VEC_TYPE_VEC_H_
