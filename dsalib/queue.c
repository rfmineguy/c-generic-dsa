#include "queue.h"
#include <stdlib.h>
#include <stdio.h>
#ifndef ALLOW_DIRECT_INCLUDE
#error "This file is not intended to be compiled directly"
#endif

q() func(q, new)() {
  q() q = {0};
  return q;
}
void func(q, free)(q()* q) {
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
q_node()* func(q, enqueue)(q() *q, type_type val) {
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
q_node()* func(q, dequeue)(q() *q) {
  if (!q->head) return 0;
  q_node()* n = q->head;
  q->head = q->head->next;
  if (!q->head) q->tail = 0;
  return n;
}
type_type* func(q, front)(const q() *q) {
  if (!q->head) return 0;
  return &q->head->val;
}
bool func(q, empty)(const q() *q) {
  return q->head == q->tail && !q->head;
}
void func(q, print)(q() *q) {
  for (q_node()* n = q->head; n != q->tail; n = n->next) {
    printf("%d", n->val);
    if (n->next) printf(", ");
  }
  printf("\n");
}
