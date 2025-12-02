#include <limits.h>
#define da_type_name int
#define da_type_type int
#define da_error_val INT_MIN
#include <stdio.h>

void da_int_print_val(int v, FILE* f) {
  fprintf(f, "%d", v);
}

#include "../dsalib/dynarray.c"
