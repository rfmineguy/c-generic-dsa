#include "queue.h"
#include <stdlib.h>
#include <stdio.h>
#ifndef Q_ALLOW_DIRECT_INCLUDE
#error "This file is not intended to be compiled directly"
#endif

q() qfunc(new)() {
  q() q = {0};
  return q;
}
void qfunc(free)(q()* q) {
  if (!q->head) return;
  q_node()* n = q->head;
  while (n) {
    q_node() *t = n;
    n = n->next;
    free(t);
  }
  q->head = 0;
  q->tail = 0;
}
q_node()* qfunc(enqueue)(q() *q, q_type_type val) {
  q_node()* n = calloc(1, sizeof(q_node()));
  if (!n) return 0;
  n->val = val;

  if (!q->head) {
    q->head = n;
    q->tail = n;
    return n;
  }
  n->prev = q->tail;
  q->tail->next = n;
  q->tail = n;
  return n;
}
q_node()* qfunc(dequeue)(q() *q) {
  if (!q->head) return 0;
  q_node()* n = q->head;
  q->head = q->head->next;
  if (!q->head) q->tail = 0;
  return n;
}
q_type_type* qfunc(front)(const q() *q) {
  if (!q->head) return 0;
  return &q->head->val;
}
bool qfunc(empty)(const q() *q) {
  return q->head == q->tail && !q->head;
}
void qfunc(print)(FILE* f, q() *q) {
  for (q_node()* n = q->head; n != q->tail; n = n->next) {
    qfunc(print_node_val)(f, n->val);
    if (n->next) printf(", ");
  }
  printf("\n");
}
