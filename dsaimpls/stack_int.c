#define stack_type_type int
#define stack_type_name int
#include <stdio.h>

void stack_int_print_node_val(FILE* f, int v) {
  fprintf(f, "%d", v);
}
#include "../dsalib/stack.c"
