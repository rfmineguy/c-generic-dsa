#include "../dsaimpls/ht_str_int.h"
#include "../dsaimpls/queue_int.h"
#include <stdio.h>

int main() {
  ht_str_int b = ht_str_int_new(7);
  ht_str_int_put(&b, "hi", 4);
  ht_str_int_put(&b, "akjf", 6);
  ht_str_int_put(&b, "booger", 9);
  ht_str_int_put(&b, "something", 2);
  ht_str_int_put(&b, "general kant", 7);
  ht_str_int_put(&b, "hello", 3);
  ht_str_int_print(&b);

  for (ht_str_int_iter it = ht_str_int_begin(&b); !ht_str_int_end(&b, it); it = ht_str_int_next(&b, it)) {
     printf("%d, (%s, %d)\n", it.idx, it.node->key, it.node->value);
  }

  ht_str_int_rem(&b, "akjf");
  ht_str_int_free(&b);


  // linkedlist l = ll_new();
  // ll_pushback(&l, 3);
  // ll_pushback(&l, 4);
  // ll_pushback(&l, 5);
  // ll_pushfront(&l, 2);
  // ll_pushfront(&l, 1);
  // ll_popback(&l);
  // ll_popback(&l);
  // ll_popfront(&l);
  // ll_popfront(&l);
  // ll_popfront(&l);

  // linkedlist_node *n = l.head;
  // while (n) {
  //   printf("%d\n", n->val);
  //   n = n->next;
  // }

  // ll_free(&l);

  q_int q = q_int_new();
  q_int_enqueue(&q, 5);
  q_int_enqueue(&q, 4);
  q_int_enqueue(&q, 3);
  q_int_enqueue(&q, 2);
  q_int_enqueue(&q, 1);
  q_int_dequeue(&q);
  q_int_print(&q);

  int* v;
  if((v = q_int_front(&q))) printf("%d\n", *v);
}
