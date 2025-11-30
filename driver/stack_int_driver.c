#include "../dsaimpls/stack_int.h"
#include <stdio.h>

void stack_int_driver() {
  stack_int stack = stack_int_new();
  stack_int_push(&stack, 4);
  stack_int_push(&stack, 8);
  stack_int_print(&stack);

  int* v;
  if ((v = stack_int_top(&stack))) {
    printf("top: %d\n", *v);
  }
  stack_int_free(&stack);
}
