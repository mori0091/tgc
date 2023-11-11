#ifndef INTERNAL_FUNCTION_H_
#define INTERNAL_FUNCTION_H_

#include "cppmp.h"

#include "copy.h"
#include "core.h"
#include "tuple.h"

#include <stdlib.h>

#define Fp(...) TYPE_NAME(Fp, __VA_ARGS__)

#define def_Fp(...)                                                      \
  typedef LAST(__VA_ARGS__) (*Fp(__VA_ARGS__))(                          \
    TRUNCATE_LAST(__VA_ARGS__));                                         \
  def_Copy(Fp(__VA_ARGS__))

#define impl_Fp(...)                                                     \
  /* impl_Copy(Fp(__VA_ARGS__)); */                                      \
  END_OF_STATEMENT

#undef Fn
#define Fn(...)     Fn_(__VA_ARGS__, )
#define Fn_(T, ...) IF(IS_NIL(__VA_ARGS__))(T, FOLDR(Fn2, T, __VA_ARGS__))
#define Fn2(T, R)   TYPE_NAME(Fn, TYPEOF(T), TYPEOF(R))

#undef def_Fn
#define def_Fn(...)                                                      \
  def_Fp(__VA_ARGS__);                                                   \
  def_Fn_(__VA_ARGS__);                                                  \
  def_Fn_(Fp(__VA_ARGS__), __VA_ARGS__);                                 \
  def_trait(Fn(__VA_ARGS__)) {                                           \
    Fn(__VA_ARGS__) (*from)(Fp(__VA_ARGS__) fp);                         \
  }

#define def_Fn_(T, ...)                                                  \
  enum { METADATA(Fn(T, __VA_ARGS__)) = E_DROP };                        \
  typedef struct Fn(T, __VA_ARGS__) Fn(T, __VA_ARGS__);                  \
  struct Fn(T, __VA_ARGS__) {                                            \
    Fn(__VA_ARGS__) (*apply)(void* args, T x);                           \
    void* args;                                                          \
    void (*drop)(void* self);                                            \
  };                                                                     \
  def_Drop(Fn(T, __VA_ARGS__));                                          \
  END_OF_STATEMENT

#undef impl_Fn
#define impl_Fn(...)                                                     \
  impl_Fp(__VA_ARGS__);                                                  \
  impl_Fn_(__VA_ARGS__);                                                 \
  impl_Fn_(Fp(__VA_ARGS__), __VA_ARGS__);                                \
  fn(FUNC_NAME(from_funptr, Fn(__VA_ARGS__)), Fp(__VA_ARGS__),           \
     __VA_ARGS__) {                                                      \
    return CALL_FP(__VA_ARGS__);                                         \
  }                                                                      \
  static Fn(__VA_ARGS__)                                                 \
    FUNC_NAME(from, Fn(__VA_ARGS__))(Fp(__VA_ARGS__) fp) {               \
    Fn(Fp(__VA_ARGS__), __VA_ARGS__) f =                                 \
      FUNC_NAME(from_funptr, Fn(__VA_ARGS__))();                         \
    Fn(__VA_ARGS__) g = fn_apply(f, fp);                                 \
    g.drop = f.drop;                                                     \
    return g;                                                            \
  }                                                                      \
  impl_trait(Fn(__VA_ARGS__)) {                                          \
    .from = FUNC_NAME(from, Fn(__VA_ARGS__)),                            \
  }

#define impl_Fn_(...)                                                    \
  impl_Drop_for(Fn(__VA_ARGS__)) {                                       \
    if (self->drop) {                                                    \
      self->drop(self);                                                  \
    }                                                                    \
  }                                                                      \
  END_OF_STATEMENT

#define CALL_FP(...) CAT(CALL_FP, VARIADIC_SIZE(__VA_ARGS__))
#define CALL_FP2     args->_0(args->_1)
#define CALL_FP3     args->_0(args->_1, args->_2)
#define CALL_FP4     args->_0(args->_1, args->_2, args->_3)
#define CALL_FP5     args->_0(args->_1, args->_2, args->_3, args->_4)
#define CALL_FP6                                                         \
  args->_0(args->_1, args->_2, args->_3, args->_4, args->_5)
#define CALL_FP7                                                         \
  args->_0(args->_1, args->_2, args->_3, args->_4, args->_5, args->_6)
#define CALL_FP8                                                         \
  args->_0(args->_1, args->_2, args->_3, args->_4, args->_5, args->_6,   \
           args->_7)
#define CALL_FP9                                                         \
  args->_0(args->_1, args->_2, args->_3, args->_4, args->_5, args->_6,   \
           args->_7, args->_8)

#undef def_recursive_Fn
#define def_recursive_Fn(...) def_recursive_Fn_(__VA_ARGS__)
#define def_recursive_Fn_(T, ...)                                        \
  CAT(def_recursive_Fn, VARIADIC_SIZE(__VA_ARGS__))(T, __VA_ARGS__)

#define def_recursive_Fn1(T, R) def_Fn(T, R)
#define def_recursive_Fn2(T, ...)                                        \
  def_recursive_Fn1(__VA_ARGS__);                                        \
  def_Fn(T, __VA_ARGS__)
#define def_recursive_Fn3(T, ...)                                        \
  def_recursive_Fn2(__VA_ARGS__);                                        \
  def_Fn(T, __VA_ARGS__)
#define def_recursive_Fn4(T, ...)                                        \
  def_recursive_Fn3(__VA_ARGS__);                                        \
  def_Fn(T, __VA_ARGS__)
#define def_recursive_Fn5(T, ...)                                        \
  def_recursive_Fn4(__VA_ARGS__);                                        \
  def_Fn(T, __VA_ARGS__)
#define def_recursive_Fn6(T, ...)                                        \
  def_recursive_Fn5(__VA_ARGS__);                                        \
  def_Fn(T, __VA_ARGS__)
#define def_recursive_Fn7(T, ...)                                        \
  def_recursive_Fn6(__VA_ARGS__);                                        \
  def_Fn(T, __VA_ARGS__)
#define def_recursive_Fn8(T, ...)                                        \
  def_recursive_Fn7(__VA_ARGS__);                                        \
  def_Fn(T, __VA_ARGS__)
#define def_recursive_Fn9(T, ...)                                        \
  def_recursive_Fn8(__VA_ARGS__);                                        \
  def_Fn(T, __VA_ARGS__)

#undef impl_recursive_Fn
#define impl_recursive_Fn(...) impl_recursive_Fn_(__VA_ARGS__)
#define impl_recursive_Fn_(T, ...)                                       \
  CAT(impl_recursive_Fn, VARIADIC_SIZE(__VA_ARGS__))(T, __VA_ARGS__)

#define impl_recursive_Fn1(T, R) impl_Fn(T, R)
#define impl_recursive_Fn2(T, ...)                                       \
  impl_recursive_Fn1(__VA_ARGS__);                                       \
  impl_Fn(T, __VA_ARGS__)
#define impl_recursive_Fn3(T, ...)                                       \
  impl_recursive_Fn2(__VA_ARGS__);                                       \
  impl_Fn(T, __VA_ARGS__)
#define impl_recursive_Fn4(T, ...)                                       \
  impl_recursive_Fn3(__VA_ARGS__);                                       \
  impl_Fn(T, __VA_ARGS__)
#define impl_recursive_Fn5(T, ...)                                       \
  impl_recursive_Fn4(__VA_ARGS__);                                       \
  impl_Fn(T, __VA_ARGS__)
#define impl_recursive_Fn6(T, ...)                                       \
  impl_recursive_Fn5(__VA_ARGS__);                                       \
  impl_Fn(T, __VA_ARGS__)
#define impl_recursive_Fn7(T, ...)                                       \
  impl_recursive_Fn6(__VA_ARGS__);                                       \
  impl_Fn(T, __VA_ARGS__)
#define impl_recursive_Fn8(T, ...)                                       \
  impl_recursive_Fn7(__VA_ARGS__);                                       \
  impl_Fn(T, __VA_ARGS__)
#define impl_recursive_Fn9(T, ...)                                       \
  impl_recursive_Fn8(__VA_ARGS__);                                       \
  impl_Fn(T, __VA_ARGS__)

#undef fn
#define fn(name, ...) fn_(name, __VA_ARGS__)
#define fn_(name, T, ...)                                                \
  CAT(fn, VARIADIC_SIZE(__VA_ARGS__))(name, T, __VA_ARGS__)

#define fn1(name, T1, R)                                                 \
  typedef Tuple(T1) Env_##name;                                          \
  static void name##_drop(void* p) {                                     \
    Fn(T1, R)* self = p;                                                 \
    Env_##name* args = self->args;                                       \
    { /* Drop(Env_##name) */                                             \
      if (IS_DROP(T1))                                                   \
        trait(Drop(T1)).drop(&args->_0);                                 \
    }                                                                    \
    free(args);                                                          \
    *self = (Fn(T1, R)){0};                                              \
  }                                                                      \
  Fn(T1, R) name(void);                                                  \
  static R name##_1(void* args, T1 x1);                                  \
  static R name##_(Env_##name* args);                                    \
  Fn(T1, R) name(void) {                                                 \
    return (Fn(T1, R)){                                                  \
      .apply = name##_1,                                                 \
      .args = calloc(1, sizeof(Env_##name)),                             \
      .drop = name##_drop,                                               \
    };                                                                   \
  }                                                                      \
  static R name##_1(void* args, T1 x1) {                                 \
    ((Env_##name*)args)->_0 = x1;                                        \
    return name##_((Env_##name*)args);                                   \
  }                                                                      \
  static R name##_(Env_##name* args)

#define fn2(name, T1, T2, R)                                             \
  typedef Tuple(T1, T2) Env_##name;                                      \
  static void name##_drop(void* p) {                                     \
    Fn(T1, T2, R)* self = p;                                             \
    Env_##name* args = self->args;                                       \
    { /* Drop(Env_##name) */                                             \
      if (IS_DROP(T1))                                                   \
        trait(Drop(T1)).drop(&args->_0);                                 \
      if (IS_DROP(T2))                                                   \
        trait(Drop(T2)).drop(&args->_1);                                 \
    }                                                                    \
    free(args);                                                          \
    *self = (Fn(T1, T2, R)){0};                                          \
  }                                                                      \
  Fn(T1, T2, R) name(void);                                              \
  static Fn(T2, R) name##_1(void* args, T1 x1);                          \
  static R name##_2(void* args, T2 x2);                                  \
  static R name##_(Env_##name* args);                                    \
  Fn(T1, T2, R) name(void) {                                             \
    return (Fn(T1, T2, R)){                                              \
      .apply = name##_1,                                                 \
      .args = calloc(1, sizeof(Env_##name)),                             \
      .drop = name##_drop,                                               \
    };                                                                   \
  }                                                                      \
  static Fn(T2, R) name##_1(void* args, T1 x1) {                         \
    ((Env_##name*)args)->_0 = x1;                                        \
    return (Fn(T2, R)){                                                  \
      .apply = name##_2, .args = args, /* .drop = name##_drop, */        \
    };                                                                   \
  }                                                                      \
  static R name##_2(void* args, T2 x2) {                                 \
    ((Env_##name*)args)->_1 = x2;                                        \
    return name##_((Env_##name*)args);                                   \
  }                                                                      \
  static R name##_(Env_##name* args)

#define fn3(name, T1, T2, T3, R)                                         \
  typedef Tuple(T1, T2, T3) Env_##name;                                  \
  static void name##_drop(void* p) {                                     \
    Fn(T1, T2, T3, R)* self = p;                                         \
    Env_##name* args = self->args;                                       \
    { /* Drop(Env_##name) */                                             \
      if (IS_DROP(T1))                                                   \
        trait(Drop(T1)).drop(&args->_0);                                 \
      if (IS_DROP(T2))                                                   \
        trait(Drop(T2)).drop(&args->_1);                                 \
      if (IS_DROP(T3))                                                   \
        trait(Drop(T3)).drop(&args->_2);                                 \
    }                                                                    \
    free(args);                                                          \
    *self = (Fn(T1, T2, T3, R)){0};                                      \
  }                                                                      \
  Fn(T1, T2, T3, R) name(void);                                          \
  static Fn(T2, T3, R) name##_1(void* args, T1 x1);                      \
  static Fn(T3, R) name##_2(void* args, T2 x2);                          \
  static R name##_3(void* args, T3 x3);                                  \
  static R name##_(Env_##name* args);                                    \
  Fn(T1, T2, T3, R) name(void) {                                         \
    return (Fn(T1, T2, T3, R)){                                          \
      .apply = name##_1,                                                 \
      .args = calloc(1, sizeof(Env_##name)),                             \
      .drop = name##_drop,                                               \
    };                                                                   \
  }                                                                      \
  static Fn(T2, T3, R) name##_1(void* args, T1 x1) {                     \
    ((Env_##name*)args)->_0 = x1;                                        \
    return (Fn(T2, T3, R)){                                              \
      .apply = name##_2, .args = args, /* .drop = name##_drop, */        \
    };                                                                   \
  }                                                                      \
  static Fn(T3, R) name##_2(void* args, T2 x2) {                         \
    ((Env_##name*)args)->_1 = x2;                                        \
    return (Fn(T3, R)){                                                  \
      .apply = name##_3, .args = args, /* .drop = name##_drop, */        \
    };                                                                   \
  }                                                                      \
  static R name##_3(void* args, T3 x3) {                                 \
    ((Env_##name*)args)->_2 = x3;                                        \
    return name##_((Env_##name*)args);                                   \
  }                                                                      \
  static R name##_(Env_##name* args)

#define fn4(name, T1, T2, T3, T4, R)                                     \
  typedef Tuple(T1, T2, T3, T4) Env_##name;                              \
  static void name##_drop(void* p) {                                     \
    Fn(T1, T2, T3, T4, R)* self = p;                                     \
    Env_##name* args = self->args;                                       \
    { /* Drop(Env_##name) */                                             \
      if (IS_DROP(T1))                                                   \
        trait(Drop(T1)).drop(&args->_0);                                 \
      if (IS_DROP(T2))                                                   \
        trait(Drop(T2)).drop(&args->_1);                                 \
      if (IS_DROP(T3))                                                   \
        trait(Drop(T3)).drop(&args->_2);                                 \
      if (IS_DROP(T4))                                                   \
        trait(Drop(T4)).drop(&args->_3);                                 \
    }                                                                    \
    free(args);                                                          \
    *self = (Fn(T1, T2, T3, T4, R)){0};                                  \
  }                                                                      \
  Fn(T1, T2, T3, T4, R) name(void);                                      \
  static Fn(T2, T3, T4, R) name##_1(void* args, T1 x1);                  \
  static Fn(T3, T4, R) name##_2(void* args, T2 x2);                      \
  static Fn(T4, R) name##_3(void* args, T3 x3);                          \
  static R name##_4(void* args, T4 x4);                                  \
  static R name##_(Env_##name* args);                                    \
  Fn(T1, T2, T3, T4, R) name(void) {                                     \
    return (Fn(T1, T2, T3, T4, R)){                                      \
      .apply = name##_1,                                                 \
      .args = calloc(1, sizeof(Env_##name)),                             \
      .drop = name##_drop,                                               \
    };                                                                   \
  }                                                                      \
  static Fn(T2, T3, T4, R) name##_1(void* args, T1 x1) {                 \
    ((Env_##name*)args)->_0 = x1;                                        \
    return (Fn(T2, T3, T4, R)){                                          \
      .apply = name##_2, .args = args, /* .drop = name##_drop, */        \
    };                                                                   \
  }                                                                      \
  static Fn(T3, T4, R) name##_2(void* args, T2 x2) {                     \
    ((Env_##name*)args)->_1 = x2;                                        \
    return (Fn(T3, T4, R)){                                              \
      .apply = name##_3, .args = args, /* .drop = name##_drop, */        \
    };                                                                   \
  }                                                                      \
  static Fn(T4, R) name##_3(void* args, T3 x3) {                         \
    ((Env_##name*)args)->_2 = x3;                                        \
    return (Fn(T4, R)){                                                  \
      .apply = name##_4, .args = args, /* .drop = name##_drop, */        \
    };                                                                   \
  }                                                                      \
  static R name##_4(void* args, T4 x4) {                                 \
    ((Env_##name*)args)->_3 = x4;                                        \
    return name##_((Env_##name*)args);                                   \
  }                                                                      \
  static R name##_(Env_##name* args)

#define fn5(name, T1, T2, T3, T4, T5, R)                                 \
  typedef Tuple(T1, T2, T3, T4, T5) Env_##name;                          \
  static void name##_drop(void* p) {                                     \
    Fn(T1, T2, T3, T4, T5, R)* self = p;                                 \
    Env_##name* args = self->args;                                       \
    { /* Drop(Env_##name) */                                             \
      if (IS_DROP(T1))                                                   \
        trait(Drop(T1)).drop(&args->_0);                                 \
      if (IS_DROP(T2))                                                   \
        trait(Drop(T2)).drop(&args->_1);                                 \
      if (IS_DROP(T3))                                                   \
        trait(Drop(T3)).drop(&args->_2);                                 \
      if (IS_DROP(T4))                                                   \
        trait(Drop(T4)).drop(&args->_3);                                 \
      if (IS_DROP(T5))                                                   \
        trait(Drop(T5)).drop(&args->_4);                                 \
    }                                                                    \
    free(args);                                                          \
    *self = (Fn(T1, T2, T3, T4, T5, R)){0};                              \
  }                                                                      \
  Fn(T1, T2, T3, T4, T5, R) name(void);                                  \
  static Fn(T2, T3, T4, T5, R) name##_1(void* args, T1 x1);              \
  static Fn(T3, T4, T5, R) name##_2(void* args, T2 x2);                  \
  static Fn(T4, T5, R) name##_3(void* args, T3 x3);                      \
  static Fn(T5, R) name##_4(void* args, T4 x4);                          \
  static R name##_5(void* args, T5 x5);                                  \
  static R name##_(Env_##name* args);                                    \
  Fn(T1, T2, T3, T4, T5, R) name(void) {                                 \
    return (Fn(T1, T2, T3, T4, T5, R)){                                  \
      .apply = name##_1,                                                 \
      .args = calloc(1, sizeof(Env_##name)),                             \
      .drop = name##_drop,                                               \
    };                                                                   \
  }                                                                      \
  static Fn(T2, T3, T4, T5, R) name##_1(void* args, T1 x1) {             \
    ((Env_##name*)args)->_0 = x1;                                        \
    return (Fn(T2, T3, T4, T5, R)){                                      \
      .apply = name##_2, .args = args, /* .drop = name##_drop, */        \
    };                                                                   \
  }                                                                      \
  static Fn(T3, T4, T5, R) name##_2(void* args, T2 x2) {                 \
    ((Env_##name*)args)->_1 = x2;                                        \
    return (Fn(T3, T4, T5, R)){                                          \
      .apply = name##_3, .args = args, /* .drop = name##_drop, */        \
    };                                                                   \
  }                                                                      \
  static Fn(T4, T5, R) name##_3(void* args, T3 x3) {                     \
    ((Env_##name*)args)->_2 = x3;                                        \
    return (Fn(T4, T5, R)){                                              \
      .apply = name##_4, .args = args, /* .drop = name##_drop, */        \
    };                                                                   \
  }                                                                      \
  static Fn(T5, R) name##_4(void* args, T4 x4) {                         \
    ((Env_##name*)args)->_3 = x4;                                        \
    return (Fn(T5, R)){                                                  \
      .apply = name##_5, .args = args, /* .drop = name##_drop, */        \
    };                                                                   \
  }                                                                      \
  static R name##_5(void* args, T5 x5) {                                 \
    ((Env_##name*)args)->_4 = x5;                                        \
    return name##_((Env_##name*)args);                                   \
  }                                                                      \
  static R name##_(Env_##name* args)

#define fn6(name, T1, T2, T3, T4, T5, T6, R)                             \
  typedef Tuple(T1, T2, T3, T4, T5, T6) Env_##name;                      \
  static void name##_drop(void* p) {                                     \
    Fn(T1, T2, T3, T4, T5, T6, R)* self = p;                             \
    Env_##name* args = self->args;                                       \
    { /* Drop(Env_##name) */                                             \
      if (IS_DROP(T1))                                                   \
        trait(Drop(T1)).drop(&args->_0);                                 \
      if (IS_DROP(T2))                                                   \
        trait(Drop(T2)).drop(&args->_1);                                 \
      if (IS_DROP(T3))                                                   \
        trait(Drop(T3)).drop(&args->_2);                                 \
      if (IS_DROP(T4))                                                   \
        trait(Drop(T4)).drop(&args->_3);                                 \
      if (IS_DROP(T5))                                                   \
        trait(Drop(T5)).drop(&args->_4);                                 \
      if (IS_DROP(T6))                                                   \
        trait(Drop(T6)).drop(&args->_5);                                 \
    }                                                                    \
    free(args);                                                          \
    *self = (Fn(T1, T2, T3, T4, T5, T6, R)){0};                          \
  }                                                                      \
  Fn(T1, T2, T3, T4, T5, T6, R) name(void);                              \
  static Fn(T2, T3, T4, T5, T6, R) name##_1(void* args, T1 x1);          \
  static Fn(T3, T4, T5, T6, R) name##_2(void* args, T2 x2);              \
  static Fn(T4, T5, T6, R) name##_3(void* args, T3 x3);                  \
  static Fn(T5, T6, R) name##_4(void* args, T4 x4);                      \
  static Fn(T6, R) name##_5(void* args, T5 x5);                          \
  static R name##_6(void* args, T6 x6);                                  \
  static R name##_(Env_##name* args);                                    \
  Fn(T1, T2, T3, T4, T5, T6, R) name(void) {                             \
    return (Fn(T1, T2, T3, T4, T5, T6, R)){                              \
      .apply = name##_1,                                                 \
      .args = calloc(1, sizeof(Env_##name)),                             \
      .drop = name##_drop,                                               \
    };                                                                   \
  }                                                                      \
  static Fn(T2, T3, T4, T5, T6, R) name##_1(void* args, T1 x1) {         \
    ((Env_##name*)args)->_0 = x1;                                        \
    return (Fn(T2, T3, T4, T5, T6, R)){                                  \
      .apply = name##_2, .args = args, /* .drop = name##_drop, */        \
    };                                                                   \
  }                                                                      \
  static Fn(T3, T4, T5, T6, R) name##_2(void* args, T2 x2) {             \
    ((Env_##name*)args)->_1 = x2;                                        \
    return (Fn(T3, T4, T5, T6, R)){                                      \
      .apply = name##_3, .args = args, /* .drop = name##_drop, */        \
    };                                                                   \
  }                                                                      \
  static Fn(T4, T5, T6, R) name##_3(void* args, T3 x3) {                 \
    ((Env_##name*)args)->_2 = x3;                                        \
    return (Fn(T4, T5, T6, R)){                                          \
      .apply = name##_4, .args = args, /* .drop = name##_drop, */        \
    };                                                                   \
  }                                                                      \
  static Fn(T5, T6, R) name##_4(void* args, T4 x4) {                     \
    ((Env_##name*)args)->_3 = x4;                                        \
    return (Fn(T5, T6, R)){                                              \
      .apply = name##_5, .args = args, /* .drop = name##_drop, */        \
    };                                                                   \
  }                                                                      \
  static Fn(T6, R) name##_5(void* args, T5 x5) {                         \
    ((Env_##name*)args)->_4 = x5;                                        \
    return (Fn(T6, R)){                                                  \
      .apply = name##_6, .args = args, /* .drop = name##_drop, */        \
    };                                                                   \
  }                                                                      \
  static R name##_6(void* args, T6 x6) {                                 \
    ((Env_##name*)args)->_5 = x6;                                        \
    return name##_((Env_##name*)args);                                   \
  }                                                                      \
  static R name##_(Env_##name* args)

#define fn7(name, T1, T2, T3, T4, T5, T6, T7, R)                         \
  typedef Tuple(T1, T2, T3, T4, T5, T6, T7) Env_##name;                  \
  static void name##_drop(void* p) {                                     \
    Fn(T1, T2, T3, T4, T5, T6, T7, R)* self = p;                         \
    Env_##name* args = self->args;                                       \
    { /* Drop(Env_##name) */                                             \
      if (IS_DROP(T1))                                                   \
        trait(Drop(T1)).drop(&args->_0);                                 \
      if (IS_DROP(T2))                                                   \
        trait(Drop(T2)).drop(&args->_1);                                 \
      if (IS_DROP(T3))                                                   \
        trait(Drop(T3)).drop(&args->_2);                                 \
      if (IS_DROP(T4))                                                   \
        trait(Drop(T4)).drop(&args->_3);                                 \
      if (IS_DROP(T5))                                                   \
        trait(Drop(T5)).drop(&args->_4);                                 \
      if (IS_DROP(T6))                                                   \
        trait(Drop(T6)).drop(&args->_5);                                 \
      if (IS_DROP(T7))                                                   \
        trait(Drop(T7)).drop(&args->_6);                                 \
    }                                                                    \
    free(args);                                                          \
    *self = (Fn(T1, T2, T3, T4, T5, T6, T7, R)){0};                      \
  }                                                                      \
  Fn(T1, T2, T3, T4, T5, T6, T7, R) name(void);                          \
  static Fn(T2, T3, T4, T5, T6, T7, R) name##_1(void* args, T1 x1);      \
  static Fn(T3, T4, T5, T6, T7, R) name##_2(void* args, T2 x2);          \
  static Fn(T4, T5, T6, T7, R) name##_3(void* args, T3 x3);              \
  static Fn(T5, T6, T7, R) name##_4(void* args, T4 x4);                  \
  static Fn(T6, T7, R) name##_5(void* args, T5 x5);                      \
  static Fn(T7, R) name##_6(void* args, T6 x6);                          \
  static R name##_(Env_##name* args);                                    \
  Fn(T1, T2, T3, T4, T5, T6, T7, R) name(void) {                         \
    return (Fn(T1, T2, T3, T4, T5, T6, T7, R)){                          \
      .apply = name##_1,                                                 \
      .args = calloc(1, sizeof(Env_##name)),                             \
      .drop = name##_drop,                                               \
    };                                                                   \
  }                                                                      \
  static Fn(T2, T3, T4, T5, T6, T7, R) name##_1(void* args, T1 x1) {     \
    ((Env_##name*)args)->_0 = x1;                                        \
    return (Fn(T2, T3, T4, T5, T6, T7, R)){                              \
      .apply = name##_2, .args = args, /* .drop = name##_drop, */        \
    };                                                                   \
  }                                                                      \
  static Fn(T3, T4, T5, T6, T7, R) name##_2(void* args, T2 x2) {         \
    ((Env_##name*)args)->_1 = x2;                                        \
    return (Fn(T3, T4, T5, T6, T7, R)){                                  \
      .apply = name##_3, .args = args, /* .drop = name##_drop, */        \
    };                                                                   \
  }                                                                      \
  static Fn(T4, T5, T6, T7, R) name##_3(void* args, T3 x3) {             \
    ((Env_##name*)args)->_2 = x3;                                        \
    return (Fn(T4, T5, T6, T7, R)){                                      \
      .apply = name##_4, .args = args, /* .drop = name##_drop, */        \
    };                                                                   \
  }                                                                      \
  static Fn(T5, T6, T7, R) name##_4(void* args, T4 x4) {                 \
    ((Env_##name*)args)->_3 = x4;                                        \
    return (Fn(T5, T6, T7, R)){                                          \
      .apply = name##_5, .args = args, /* .drop = name##_drop, */        \
    };                                                                   \
  }                                                                      \
  static Fn(T6, T7, R) name##_5(void* args, T5 x5) {                     \
    ((Env_##name*)args)->_4 = x5;                                        \
    return (Fn(T6, T7, R)){                                              \
      .apply = name##_6, .args = args, /* .drop = name##_drop, */        \
    };                                                                   \
  }                                                                      \
  static Fn(T7, R) name##_6(void* args, T6 x6) {                         \
    ((Env_##name*)args)->_5 = x6;                                        \
    return (Fn(T7, R)){                                                  \
      .apply = name##_7, .args = args, /* .drop = name##_drop, */        \
    };                                                                   \
  }                                                                      \
  static R name##_7(void* args, T7 x7) {                                 \
    ((Env_##name*)args)->_6 = x7;                                        \
    return name##_((Env_##name*)args);                                   \
  }                                                                      \
  static R name##_(Env_##name* args)

#define fn8(name, T1, T2, T3, T4, T5, T6, T7, T8, R)                     \
  typedef Tuple(T1, T2, T3, T4, T5, T6, T7, T8) Env_##name;              \
  static void name##_drop(void* p) {                                     \
    Fn(T1, T2, T3, T4, T5, T6, T7, T8, R)* self = p;                     \
    Env_##name* args = self->args;                                       \
    { /* Drop(Env_##name) */                                             \
      if (IS_DROP(T1))                                                   \
        trait(Drop(T1)).drop(&args->_0);                                 \
      if (IS_DROP(T2))                                                   \
        trait(Drop(T2)).drop(&args->_1);                                 \
      if (IS_DROP(T3))                                                   \
        trait(Drop(T3)).drop(&args->_2);                                 \
      if (IS_DROP(T4))                                                   \
        trait(Drop(T4)).drop(&args->_3);                                 \
      if (IS_DROP(T5))                                                   \
        trait(Drop(T5)).drop(&args->_4);                                 \
      if (IS_DROP(T6))                                                   \
        trait(Drop(T6)).drop(&args->_5);                                 \
      if (IS_DROP(T7))                                                   \
        trait(Drop(T7)).drop(&args->_6);                                 \
      if (IS_DROP(T8))                                                   \
        trait(Drop(T8)).drop(&args->_7);                                 \
    }                                                                    \
    free(args);                                                          \
    *self = (Fn(T1, T2, T3, T4, T5, T6, T7, T8, R)){0};                  \
  }                                                                      \
  Fn(T1, T2, T3, T4, T5, T6, T7, T8, R) name(void);                      \
  static Fn(T2, T3, T4, T5, T6, T7, T8, R) name##_1(void* args, T1 x1);  \
  static Fn(T3, T4, T5, T6, T7, T8, R) name##_2(void* args, T2 x2);      \
  static Fn(T4, T5, T6, T7, T8, R) name##_3(void* args, T3 x3);          \
  static Fn(T5, T6, T7, T8, R) name##_4(void* args, T4 x4);              \
  static Fn(T6, T7, T8, R) name##_5(void* args, T5 x5);                  \
  static Fn(T7, T8, R) name##_6(void* args, T6 x6);                      \
  static Fn(T8, R) name##_7(void* args, T7 x7);                          \
  static R name##_(Env_##name* args);                                    \
  Fn(T1, T2, T3, T4, T5, T6, T7, T8, R) name(void) {                     \
    return (Fn(T1, T2, T3, T4, T5, T6, T7, T8, R)){                      \
      .apply = name##_1,                                                 \
      .args = calloc(1, sizeof(Env_##name)),                             \
      .drop = name##_drop,                                               \
    };                                                                   \
  }                                                                      \
  static Fn(T2, T3, T4, T5, T6, T7, T8, R) name##_1(void* args, T1 x1) { \
    ((Env_##name*)args)->_0 = x1;                                        \
    return (Fn(T2, T3, T4, T5, T6, T7, T8, R)){                          \
      .apply = name##_2, .args = args, /* .drop = name##_drop, */        \
    };                                                                   \
  }                                                                      \
  static Fn(T3, T4, T5, T6, T7, T8, R) name##_2(void* args, T2 x2) {     \
    ((Env_##name*)args)->_1 = x2;                                        \
    return (Fn(T3, T4, T5, T6, T7, T8, R)){                              \
      .apply = name##_3, .args = args, /* .drop = name##_drop, */        \
    };                                                                   \
  }                                                                      \
  static Fn(T4, T5, T6, T7, T8, R) name##_3(void* args, T3 x3) {         \
    ((Env_##name*)args)->_2 = x3;                                        \
    return (Fn(T4, T5, T6, T7, T8, R)){                                  \
      .apply = name##_4, .args = args, /* .drop = name##_drop, */        \
    };                                                                   \
  }                                                                      \
  static Fn(T5, T6, T7, T8, R) name##_4(void* args, T4 x4) {             \
    ((Env_##name*)args)->_3 = x4;                                        \
    return (Fn(T5, T6, T7, T8, R)){                                      \
      .apply = name##_5, .args = args, /* .drop = name##_drop, */        \
    };                                                                   \
  }                                                                      \
  static Fn(T6, T7, T8, R) name##_5(void* args, T5 x5) {                 \
    ((Env_##name*)args)->_4 = x5;                                        \
    return (Fn(T6, T7, T8, R)){                                          \
      .apply = name##_6, .args = args, /* .drop = name##_drop, */        \
    };                                                                   \
  }                                                                      \
  static Fn(T7, T8, R) name##_6(void* args, T6 x6) {                     \
    ((Env_##name*)args)->_5 = x6;                                        \
    return (Fn(T7, T8, R)){                                              \
      .apply = name##_7, .args = args, /* .drop = name##_drop, */        \
    };                                                                   \
  }                                                                      \
  static Fn(T8, R) name##_7(void* args, T7 x7) {                         \
    ((Env_##name*)args)->_6 = x7;                                        \
    return (Fn(T8, R)){                                                  \
      .apply = name##_8, .args = args, /* .drop = name##_drop, */        \
    };                                                                   \
  }                                                                      \
  static R name##_8(void* args, T8 x8) {                                 \
    ((Env_##name*)args)->_7 = x8;                                        \
    return name##_((Env_##name*)args);                                   \
  }                                                                      \
  static R name##_(Env_##name* args)

#define fn9(name, T1, T2, T3, T4, T5, T6, T7, T8, T9, R)                 \
  typedef Tuple(T1, T2, T3, T4, T5, T6, T7, T8, T9) Env_##name;          \
  static void name##_drop(void* p) {                                     \
    Fn(T1, T2, T3, T4, T5, T6, T7, T8, T9, R)* self = p;                 \
    Env_##name* args = self->args;                                       \
    { /* Drop(Env_##name) */                                             \
      if (IS_DROP(T1))                                                   \
        trait(Drop(T1)).drop(&args->_0);                                 \
      if (IS_DROP(T2))                                                   \
        trait(Drop(T2)).drop(&args->_1);                                 \
      if (IS_DROP(T3))                                                   \
        trait(Drop(T3)).drop(&args->_2);                                 \
      if (IS_DROP(T4))                                                   \
        trait(Drop(T4)).drop(&args->_3);                                 \
      if (IS_DROP(T5))                                                   \
        trait(Drop(T5)).drop(&args->_4);                                 \
      if (IS_DROP(T6))                                                   \
        trait(Drop(T6)).drop(&args->_5);                                 \
      if (IS_DROP(T7))                                                   \
        trait(Drop(T7)).drop(&args->_6);                                 \
      if (IS_DROP(T8))                                                   \
        trait(Drop(T8)).drop(&args->_7);                                 \
      if (IS_DROP(T9))                                                   \
        trait(Drop(T9)).drop(&args->_8);                                 \
    }                                                                    \
    free(args);                                                          \
    *self = (Fn(T1, T2, T3, T4, T5, T6, T7, T8, T9, R)){0};              \
  }                                                                      \
  Fn(T1, T2, T3, T4, T5, T6, T7, T8, T9, R) name(void);                  \
  static Fn(T2, T3, T4, T5, T6, T7, T8, T9, R)                           \
    name##_1(void* args, T1 x1);                                         \
  static Fn(T3, T4, T5, T6, T7, T8, T9, R) name##_2(void* args, T2 x2);  \
  static Fn(T4, T5, T6, T7, T8, T9, R) name##_3(void* args, T3 x3);      \
  static Fn(T5, T6, T7, T8, T9, R) name##_4(void* args, T4 x4);          \
  static Fn(T6, T7, T8, T9, R) name##_5(void* args, T5 x5);              \
  static Fn(T7, T8, T9, R) name##_6(void* args, T6 x6);                  \
  static Fn(T8, T9, R) name##_7(void* args, T7 x7);                      \
  static Fn(T9, R) name##_8(void* args, T8 x8);                          \
  static R name##_(Env_##name* args);                                    \
  Fn(T1, T2, T3, T4, T5, T6, T7, T8, T9, R) name(void) {                 \
    return (Fn(T1, T2, T3, T4, T5, T6, T7, T8, T9, R)){                  \
      .apply = name##_1,                                                 \
      .args = calloc(1, sizeof(Env_##name)),                             \
      .drop = name##_drop,                                               \
    };                                                                   \
  }                                                                      \
  static Fn(T2, T3, T4, T5, T6, T7, T8, T9, R)                           \
    name##_1(void* args, T1 x1) {                                        \
    ((Env_##name*)args)->_0 = x1;                                        \
    return (Fn(T2, T3, T4, T5, T6, T7, T8, T9, R)){                      \
      .apply = name##_2, .args = args, /* .drop = name##_drop, */        \
    };                                                                   \
  }                                                                      \
  static Fn(T3, T4, T5, T6, T7, T8, T9, R) name##_2(void* args, T2 x2) { \
    ((Env_##name*)args)->_1 = x2;                                        \
    return (Fn(T3, T4, T5, T6, T7, T8, T9, R)){                          \
      .apply = name##_3, .args = args, /* .drop = name##_drop, */        \
    };                                                                   \
  }                                                                      \
  static Fn(T4, T5, T6, T7, T8, T9, R) name##_3(void* args, T3 x3) {     \
    ((Env_##name*)args)->_2 = x3;                                        \
    return (Fn(T4, T5, T6, T7, T8, T9, R)){                              \
      .apply = name##_4, .args = args, /* .drop = name##_drop, */        \
    };                                                                   \
  }                                                                      \
  static Fn(T5, T6, T7, T8, T9, R) name##_4(void* args, T4 x4) {         \
    ((Env_##name*)args)->_3 = x4;                                        \
    return (Fn(T5, T6, T7, T8, T9, R)){                                  \
      .apply = name##_5, .args = args, /* .drop = name##_drop, */        \
    };                                                                   \
  }                                                                      \
  static Fn(T6, T7, T8, T9, R) name##_5(void* args, T5 x5) {             \
    ((Env_##name*)args)->_4 = x5;                                        \
    return (Fn(T6, T7, T8, T9, R)){                                      \
      .apply = name##_6, .args = args, /* .drop = name##_drop, */        \
    };                                                                   \
  }                                                                      \
  static Fn(T7, T8, T9, R) name##_6(void* args, T6 x6) {                 \
    ((Env_##name*)args)->_5 = x6;                                        \
    return (Fn(T7, T8, T9, R)){                                          \
      .apply = name##_7, .args = args, /* .drop = name##_drop, */        \
    };                                                                   \
  }                                                                      \
  static Fn(T8, T9, R) name##_7(void* args, T7 x7) {                     \
    ((Env_##name*)args)->_6 = x7;                                        \
    return (Fn(T8, T9, R)){                                              \
      .apply = name##_8, .args = args, /* .drop = name##_drop, */        \
    };                                                                   \
  }                                                                      \
  static Fn(T9, R) name##_8(void* args, T8 x8) {                         \
    ((Env_##name*)args)->_7 = x8;                                        \
    return (Fn(T9, R)){                                                  \
      .apply = name##_9, .args = args, /* .drop = name##_drop, */        \
    };                                                                   \
  }                                                                      \
  static R name##_9(void* args, T9 x9) {                                 \
    ((Env_##name*)args)->_8 = x9;                                        \
    return name##_((Env_##name*)args);                                   \
  }                                                                      \
  static R name##_(Env_##name* args)

#undef fn_apply
#define fn_apply(...) fn_apply_(__VA_ARGS__)

#define fn_apply_(f, ...)                                                \
  CAT(fn_apply, VARIADIC_SIZE(__VA_ARGS__))(f, __VA_ARGS__)

#define fn_apply1(f, x1)         f.apply(f.args, x1)
#define fn_apply2(f, x1, x2)     fn_apply1(f, x1).apply(f.args, x2)
#define fn_apply3(f, x1, x2, x3) fn_apply2(f, x1, x2).apply(f.args, x3)
#define fn_apply4(f, x1, x2, x3, x4)                                     \
  fn_apply3(f, x1, x2, x3).apply(f.args, x4)
#define fn_apply5(f, x1, x2, x3, x4, x5)                                 \
  fn_apply4(f, x1, x2, x3, x4).apply(f.args, x5)
#define fn_apply6(f, x1, x2, x3, x4, x5, x6)                             \
  fn_apply5(f, x1, x2, x3, x4, x5).apply(f.args, x6)
#define fn_apply7(f, x1, x2, x3, x4, x5, x6, x7)                         \
  fn_apply6(f, x1, x2, x3, x4, x5, x6).apply(f.args, x7)
#define fn_apply8(f, x1, x2, x3, x4, x5, x6, x7, x8)                     \
  fn_apply7(f, x1, x2, x3, x4, x5, x6, x7).apply(f.args, x8)
#define fn_apply9(f, x1, x2, x3, x4, x5, x6, x7, x8, x9)                 \
  fn_apply8(f, x1, x2, x3, x4, x5, x6, x7, x8).apply(f.args, x9)

#endif // INTERNAL_FUNCTION_H_
