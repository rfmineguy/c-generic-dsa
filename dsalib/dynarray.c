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

bool dafunc(insert_at)(da()* da, int index, da_type_type v) {
  if (index < 0 || index > da->size) return false;
  if (da->size + 1 >= da->capacity) {
    if (!dafunc(grow)(da)) return false;
  }
  da->size++;
  for (int i = da->size; i > index; i--) {
    da->buffer[i] = da->buffer[i - 1];
  }
  da->buffer[index] = v;
  return true;
}

bool dafunc(delete_at)(da()* da, int index, da_type_type* out_removed) {
  if (index < 0 || index >= da->size) return false;
  if (out_removed) *out_removed = da->buffer[index];
  for (int i = index; i < da->size - 1; i++) {
    da->buffer[i] = da->buffer[i + 1];
  }
  da->size--;
  return true;
}

da_type_type* dafunc(at)(da()* da, int index) {
  if (index < 0 || index >= da->size) return 0;
  return &da->buffer[index];
}

void dafunc(print)(da()* da, FILE* f) {
  fprintf(f, "[");
  for (int i = 0; i < da->size; i++) {
    dafunc(print_val)(da->buffer[i], f);
    if (i < da->size - 1)
      fprintf(f, ",");
  }
  fprintf(f, "]\n");
}
