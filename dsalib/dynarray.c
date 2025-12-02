#include "dynarray.h"
#include <stdlib.h>

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
