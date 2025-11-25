#ifndef QUEUE_H
#define QUEUE_H
#include <stdbool.h>

typedef struct queue_node {
  int val;
  struct queue_node *next, *prev;
} queue_node;
typedef struct {
  queue_node *head, *tail;
} queue;

queue       q_new();
void        q_free(queue* q);
queue_node* q_enqueue(queue* q, int val);
queue_node* q_dequeue(queue* q);
int*        q_front(const queue* q);
bool        q_empty(const queue* q);

void        q_print(queue* q);

#endif
