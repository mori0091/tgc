#ifndef UNIT_H_
#define UNIT_H_

typedef struct {
  char _; /* dummy (ISO C don't permit zero-sized struct) */
} Unit;

extern const Unit UNIT;

#include "copy.h"
def_Copy(Unit);

#include "eq.h"
def_Eq(Unit);

#include "fmt/debug.h"
def_Debug(Unit);

#include "fmt/display.h"
def_Display(Unit);

#endif // UNIT_H_
