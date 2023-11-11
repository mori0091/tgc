#ifndef SLICE_H_
#define SLICE_H_

#include "slice/debug_slice.h"
#include "slice/display_slice.h"
#include "slice/eq_slice.h"
#include "slice/type_slice.h"

#if defined(IMPLEMENT)
#define use_Slice(T)                                                     \
  def_Slice(T);                                                          \
  impl_Slice(T)
#else
#define use_Slice(T) def_Slice(T)
#endif

#define def_Slice(T)                                                     \
  def_type_Slice(T);                                                     \
  def_Eq_for_Slice(T);                                                   \
  def_Debug_for_Slice(T);                                                \
  def_Display_for_Slice(T);                                              \
  END_OF_STATEMENT

#define impl_Slice(T)                                                    \
  impl_type_Slice(T);                                                    \
  impl_Eq_for_Slice(T);                                                  \
  impl_Debug_for_Slice(T);                                               \
  impl_Display_for_Slice(T);                                             \
  END_OF_STATEMENT

#endif // SLICE_H_
