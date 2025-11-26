#ifndef QUEUE_H
#define QUEUE_H
#include <stdbool.h>

#ifndef type_type
#define type_type int
#error "Must define type_type macro"
#endif

#ifndef type_name
#define type_name int
#error "Must define type_name macro"
#endif

#define JOIN2(a, b, sep) a##sep##b
#define join2(a, b, sep) JOIN2(a,b,sep)

#define JOIN3(a, b, c, sep) a##sep##b##sep##c
#define join3(a, b, c, sep) JOIN3(a,b,c,sep)

#define func_paste3(a, b, c) a##_##b##_##c
#define func_expand(a, b, c) func_paste3(a, b, c)
#define func(namespace, name)\
  func_expand(namespace, type_name, name)

#define q()\
  join2(q, type_name, _)

#define q_node()\
  join3(q, type_name, node, _)

typedef struct q_node() {
  type_type val;
  struct q_node() *next, *prev;
} q_node();
typedef struct {
  q_node() *head, *tail;
} q();

q()         func(q, new)();
void        func(q, free)(q()* q);
q_node()*   func(q, enqueue)(q()* q, type_type val);
q_node()*   func(q, dequeue)(q()* q);
type_type*  func(q, front)(const q()* q);
bool        func(q, empty)(const q()* q);

void        func(q, print)(q()* q);

#endif
