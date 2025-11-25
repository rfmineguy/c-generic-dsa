#include "tests.h"
#include "../src/dsalib/queue.h"

MunitResult q_test_new(const MunitParameter params[], void* fixture) {
  queue q = q_new();
  munit_assert_null(q.head);
  munit_assert_null(q.tail);

  q_free(&q);
  return MUNIT_OK;
}
MunitResult q_test_free(const MunitParameter params[], void* fixture) {
  queue q = q_new();
  q.head = malloc(sizeof(queue_node));
  q.tail = malloc(sizeof(queue_node));
  q_free(&q);
  munit_assert_null(q.head);
  munit_assert_null(q.tail);
  return MUNIT_OK;
}
MunitResult q_test_enqueue(const MunitParameter params[], void* fixture) {
  queue q = q_new();
  for (int i = 0; i < 100; i++) {
    q_enqueue(&q, i);
    munit_assert_ptr_not_null(q.tail);
    munit_assert_int(q.tail->val, ==, i);
  }
  q_free(&q);
  return MUNIT_OK;
}
MunitResult q_test_dequeue(const MunitParameter params[], void* fixture) {
  queue q = q_new();
  for (int i = 0; i < 100; i++) {
    q_enqueue(&q, i);
    queue_node* n = q_dequeue(&q);
    munit_assert_ptr_not_null(n);
    munit_assert_int(n->val, ==, i);
    free(n);
  }
  munit_assert_ptr_null(q_dequeue(&q));

  munit_assert_ptr_null(q.head);
  munit_assert_ptr_null(q.tail);
  q_free(&q);
  return MUNIT_OK;
}
MunitResult q_test_front(const MunitParameter params[], void* fixture) {
  queue q = q_new();
  for (int i = 0; i < 100; i++) {
    q_enqueue(&q, i);
    int* f = q_front(&q);
    munit_assert_ptr_not_null(f);
    munit_assert_int(*f, ==, 0);
  }
  q_free(&q);
  return MUNIT_OK;
}
