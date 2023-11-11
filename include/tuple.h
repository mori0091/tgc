#ifndef TUPLE_H_
#define TUPLE_H_

#include "./cppmp.h"

/**
 * Anonymous struct that represents a product types (tuples).
 *
 * For example, `Tuple(int, double)` is `struct {int _0; double _1;}`.
 */
#define Tuple(...) CAT(Tuple, VARIADIC_SIZE(__VA_ARGS__))(__VA_ARGS__)

#define Tuple1(T0)                                                       \
  struct {                                                               \
    T0 _0;                                                               \
  }

#define Tuple2(T0, T1)                                                   \
  struct {                                                               \
    T0 _0;                                                               \
    T1 _1;                                                               \
  }

#define Tuple3(T0, T1, T2)                                               \
  struct {                                                               \
    T0 _0;                                                               \
    T1 _1;                                                               \
    T2 _2;                                                               \
  }

#define Tuple4(T0, T1, T2, T3)                                           \
  struct {                                                               \
    T0 _0;                                                               \
    T1 _1;                                                               \
    T2 _2;                                                               \
    T3 _3;                                                               \
  }

#define Tuple5(T0, T1, T2, T3, T4)                                       \
  struct {                                                               \
    T0 _0;                                                               \
    T1 _1;                                                               \
    T2 _2;                                                               \
    T3 _3;                                                               \
    T4 _4;                                                               \
  }

#define Tuple6(T0, T1, T2, T3, T4, T5)                                   \
  struct {                                                               \
    T0 _0;                                                               \
    T1 _1;                                                               \
    T2 _2;                                                               \
    T3 _3;                                                               \
    T4 _4;                                                               \
    T5 _5;                                                               \
  }

#define Tuple7(T0, T1, T2, T3, T4, T5, T6)                               \
  struct {                                                               \
    T0 _0;                                                               \
    T1 _1;                                                               \
    T2 _2;                                                               \
    T3 _3;                                                               \
    T4 _4;                                                               \
    T5 _5;                                                               \
    T6 _6;                                                               \
  }

#define Tuple8(T0, T1, T2, T3, T4, T5, T6, T7)                           \
  struct {                                                               \
    T0 _0;                                                               \
    T1 _1;                                                               \
    T2 _2;                                                               \
    T3 _3;                                                               \
    T4 _4;                                                               \
    T5 _5;                                                               \
    T6 _6;                                                               \
    T7 _7;                                                               \
  }

#define Tuple9(T0, T1, T2, T3, T4, T5, T6, T7, T8)                       \
  struct {                                                               \
    T0 _0;                                                               \
    T1 _1;                                                               \
    T2 _2;                                                               \
    T3 _3;                                                               \
    T4 _4;                                                               \
    T5 _5;                                                               \
    T6 _6;                                                               \
    T7 _7;                                                               \
    T8 _8;                                                               \
  }

#define Tuple10(T0, T1, T2, T3, T4, T5, T6, T7, T8, T9)                  \
  struct {                                                               \
    T0 _0;                                                               \
    T1 _1;                                                               \
    T2 _2;                                                               \
    T3 _3;                                                               \
    T4 _4;                                                               \
    T5 _5;                                                               \
    T6 _6;                                                               \
    T7 _7;                                                               \
    T8 _8;                                                               \
    T9 _9;                                                               \
  }

/**
 * Construct a value of anonymous tuple type.
 *
 * For example, `tuple(1, 2.0)` is `(struct {int _0; double
 * _1;}){1, 2.0}`.
 */
#define tuple(...) CAT(tuple, VARIADIC_SIZE(__VA_ARGS__))(__VA_ARGS__)

#define tuple1(e0)                                                       \
  (Tuple(typeof(e0))) { (e0) }

#define tuple2(e0, e1)                                                   \
  (Tuple(typeof(e0), typeof(e1))) { (e0), (e1) }

#define tuple3(e0, e1, e2)                                               \
  (Tuple(typeof(e0), typeof(e1), typeof(e2))) { (e0), (e1), (e2) }

#define tuple4(e0, e1, e2, e3)                                           \
  (Tuple(typeof(e0), typeof(e1), typeof(e2), typeof(e3))) {              \
    (e0), (e1), (e2), (e3)                                               \
  }

#define tuple5(e0, e1, e2, e3, e4)                                       \
  (Tuple(typeof(e0), typeof(e1), typeof(e2), typeof(e3), typeof(e4))) {  \
    (e0), (e1), (e2), (e3), (e4)                                         \
  }

#define tuple6(e0, e1, e2, e3, e4, e5)                                   \
  (Tuple(typeof(e0), typeof(e1), typeof(e2), typeof(e3), typeof(e4),     \
         typeof(e5))) {                                                  \
    (e0), (e1), (e2), (e3), (e4), (e5)                                   \
  }

#define tuple7(e0, e1, e2, e3, e4, e5, e6)                               \
  (Tuple(typeof(e0), typeof(e1), typeof(e2), typeof(e3), typeof(e4),     \
         typeof(e5), typeof(e6))) {                                      \
    (e0), (e1), (e2), (e3), (e4), (e5), (e6)                             \
  }

#define tuple8(e0, e1, e2, e3, e4, e5, e6, e7)                           \
  (Tuple(typeof(e0), typeof(e1), typeof(e2), typeof(e3), typeof(e4),     \
         typeof(e5), typeof(e6), typeof(e7))) {                          \
    (e0), (e1), (e2), (e3), (e4), (e5), (e6), (e7)                       \
  }

#define tuple9(e0, e1, e2, e3, e4, e5, e6, e7, e8)                       \
  (Tuple(typeof(e0), typeof(e1), typeof(e2), typeof(e3), typeof(e4),     \
         typeof(e5), typeof(e6), typeof(e7), typeof(e8))) {              \
    (e0), (e1), (e2), (e3), (e4), (e5), (e6), (e7), (e8)                 \
  }

#define tuple10(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9)                  \
  (Tuple(typeof(e0), typeof(e1), typeof(e2), typeof(e3), typeof(e4),     \
         typeof(e5), typeof(e6), typeof(e7), typeof(e8), typeof(e9))) {  \
    (e0), (e1), (e2), (e3), (e4), (e5), (e6), (e7), (e8), (e9)           \
  }

#endif // TUPLE_H_
