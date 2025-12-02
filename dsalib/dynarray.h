#include "dsa.h"
#include <stdio.h>
#include <stdbool.h>

#undef func
#undef da

#ifndef da_type_name
#define da_type_name int
#error "Must define da_type_name"
#endif

#ifndef da_type_type
#define da_type_type int
#error "Must define da_type_type"
#endif

#ifndef da_error_val
#define da_error_val -1
#error "Must define da_error_val"
#endif

#define dafunc(name)\
  func_expand3(da, da_type_name, name)

#define da()\
  join2(da, da_type_name, _)

typedef struct da() {
  da_type_type *buffer;
  int size, capacity;
} da();

void          dafunc(print_val)(da_type_type v, FILE* f);

da()          dafunc(new)(int initial_capacity);
void          dafunc(free)(da()* da);
bool          dafunc(append)(da()* da, da_type_type v);
bool          dafunc(insert_at)(da()* da, int index, da_type_type v);
bool          dafunc(delete_at)(da()* da, int index, da_type_type* out);
da_type_type* dafunc(at)(da()* da, int index);

void          dafunc(print)(da()* da, FILE* f);
