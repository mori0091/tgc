#ifndef FMT_DEBUG_H_
#define FMT_DEBUG_H_

#include "fmt/formatter.h"

#define Debug(T) TYPE_NAME(Debug, TYPEOF(T))

#define def_Debug(T)                                                     \
  def_trait(Debug(T)) { void (*fmt)(T self, const Formatter out); }

#define impl_Debug_for(T)                                                \
  static void FUNC_NAME(fmt, Debug(T))(T self, const Formatter out);     \
  impl_trait(Debug(T)){                                                  \
    .fmt = FUNC_NAME(fmt, Debug(T)),                                     \
  };                                                                     \
  static void FUNC_NAME(fmt, Debug(T))(T self,                           \
                                       const Formatter out) /* {...} */

#endif // FMT_DEBUG_H_
