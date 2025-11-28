#include <stdbool.h>
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

#define qfunc(namespace, name)\
  func_expand3(namespace, q_type_name, name)

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

void        qfunc(q, print_node_val)(q_type_type val);

q()         qfunc(q, new)();
void        qfunc(q, free)(q()* q);
q_node()*   qfunc(q, enqueue)(q()* q, q_type_type val);
q_node()*   qfunc(q, dequeue)(q()* q);
q_type_type*qfunc(q, front)(const q()* q);
bool        qfunc(q, empty)(const q()* q);

void        qfunc(q, print)(q()* q);
