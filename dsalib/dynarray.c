#include "dynarray.h"
#include <stdlib.h>

bool dafunc(grow)(da()* da) {
  da->buffer = realloc(da->buffer, da->capacity * 2 * sizeof(da_type_type));
  if (!da->buffer) return false;
  da->capacity *= 2;
  return true;
}

da() dafunc(new)(int initial_capacity) {
  da() d = (da()) {.capacity = initial_capacity};
  d.buffer = calloc(initial_capacity, sizeof(da_type_type));
  d.size = 0;
  return d;
}

void dafunc(free)(da()* da) {
  free(da->buffer);
  da->buffer = 0;
}

bool dafunc(append)(da()* da, da_type_type v) {
  if (da->size + 1 >= da->capacity) {
    if (!dafunc(grow)(da)) return false;
  }
  da->buffer[da->size++] = v;
  return true;
}
