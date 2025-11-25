#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

queue q_new() {
  queue q = {0};
  return q;
}
void q_free(queue* q) {
  if (!q->head) return;
  queue_node* n = q->head;
  while (n) {
    queue_node *t = n;
    n = n->next;
    free(t);
  }
  q->head = 0;
  q->tail = 0;
}
queue_node* q_enqueue(queue* q, int val) {
  queue_node* n = calloc(1, sizeof(queue_node));
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
queue_node* q_dequeue(queue* q) {
  if (!q->head) return 0;
  queue_node* n = q->head;
  q->head = q->head->next;
  if (!q->head) q->tail = 0;
  return n;
}
