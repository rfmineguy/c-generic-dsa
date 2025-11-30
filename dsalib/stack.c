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

struct stack_node()* stackfunc(stack, push)(stack()* stack, stack_type_type val) {
  struct stack_node()* n = calloc(1, sizeof(struct stack_node()));
  if (!n) return n;
  n->val = val;
  n->next = 0;

  if (!stack->head)
    stack->head = n;
  else {
    struct stack_node()* oldhead = stack->head;
    stack->head = n;
    stack->head->next = oldhead;
  }

  return n;
}

struct stack_node()* stackfunc(stack, pop)(stack()* stack) {
  if (!stack->head) return 0;

  struct stack_node()* n = stack->head;
  stack->head = stack->head->next;
  return n;
}
