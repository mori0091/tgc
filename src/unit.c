#include "unit.h"

const Unit UNIT = {0};

impl_Clone_for(Unit) {
  return UNIT;
}

impl_Drop_for(Unit) {
}

impl_Eq_for(Unit) {
  return true;
}

impl_Debug_for(Unit) {
  fmt_write(out, "()");
}

impl_Display_for(Unit) {
  fmt_write(out, "()");
}
