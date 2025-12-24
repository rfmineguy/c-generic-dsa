#ifndef STACK_TEMPLATE_H
#define STACK_TEMPLATE_H
#include "dsa.h"
#include <stdbool.h>
#include <stdio.h>

#ifndef stack_type_type
#define stack_type_type int
#error "Must define stack_type_type macro"
#endif

#ifndef stack_type_name
#define stack_type_name int
#error "Must define stack_type_name macro"
#endif

#define stack_node()  join3(stack, stack_type_name, node, _)
#define stack()       join2(stack, stack_type_name, _)

#define stackfunc(name)\
  func_expand3(stack, stack_type_name, name)

struct stack_node() {
  stack_type_type val;
  struct stack_node() *next;
};

typedef struct stack() {
  struct stack_node() *head;
} stack();

void                 stackfunc(print_node_val)(FILE*, stack_type_type);

stack()              stackfunc(new)();
void                 stackfunc(free)(stack()*);

struct stack_node()* stackfunc(push)(stack()*, stack_type_type);
struct stack_node()* stackfunc(pop)(stack()*);
stack_type_type*     stackfunc(top)(const stack()*);
bool                 stackfunc(empty)(const stack()*);
void                 stackfunc(print)(FILE*, const stack()*);

#endif
