#include <stdbool.h>
#include <stdio.h>
#include "dsa.h"
#undef func
#undef q
#undef q_node

#ifndef q_type_type
#define q_type_type int
#error "Must define q_type_type macro"
#endif

#ifndef q_type_name
#define q_type_name int
#error "Must define q_type_name macro"
#endif

#define qfunc(name)\
  func_expand3(q, q_type_name, name)

#define q()\
  join2(q, q_type_name, _)

#define q_node()\
  join3(q, q_type_name, node, _)

typedef struct q_node() {
  q_type_type val;
  struct q_node() *next, *prev;
} q_node();
typedef struct q() {
  q_node() *head, *tail;
} q();

void        qfunc(print_node_val)(FILE* f, q_type_type val);

q()         qfunc(new)();
void        qfunc(free)(q()* q);
q_node()*   qfunc(enqueue)(q()* q, q_type_type val);
q_node()*   qfunc(dequeue)(q()* q);
q_type_type*qfunc(front)(const q()* q);
bool        qfunc(empty)(const q()* q);

void        qfunc(print)(FILE* f, q()* q);
