#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

stack() stackfunc(stack, new)() {
  stack() s = {.head = 0};
  return s;
}

void stackfunc(stack, free)(stack()* stack) {
  struct stack_node()* n = stack->head;
  while (n) {
    struct stack_node()* t = n;
    n = n->next;
    free(t);
  }
}
