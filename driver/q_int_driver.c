#include "../dsaimpls/queue_int.h"

void q_int_driver() {
  q_int q = q_int_new();
  q_int_enqueue(&q, 5);
  q_int_enqueue(&q, 4);
  q_int_enqueue(&q, 3);
  q_int_enqueue(&q, 2);
  q_int_enqueue(&q, 1);
  q_int_dequeue(&q);
  q_int_print(stdout, &q);
  q_int_free(&q);
}
