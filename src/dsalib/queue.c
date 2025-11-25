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
