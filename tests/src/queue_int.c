#include "tests.h"
#include "../../dsaimpls/queue_int.h"

MunitResult q_int_test_new(const MunitParameter params[], void* fixture) {
  q_int q = q_int_new();
  munit_assert_null(q.head);
  munit_assert_null(q.tail);

  q_int_free(&q);
  return MUNIT_OK;
}
MunitResult q_int_test_free(const MunitParameter params[], void* fixture) {
  q_int q = q_int_new();
  q.head = malloc(sizeof(q_int_node));
  q.tail = malloc(sizeof(q_int_node));
  q_int_free(&q);
  munit_assert_null(q.head);
  munit_assert_null(q.tail);
  return MUNIT_OK;
}
MunitResult q_int_test_enqueue(const MunitParameter params[], void* fixture) {
  q_int q = q_int_new();
  for (int i = 0; i < 100; i++) {
    q_int_enqueue(&q, i);
    munit_assert_ptr_not_null(q.tail);
    munit_assert_int(q.tail->val, ==, i);
  }
  q_int_free(&q);
  return MUNIT_OK;
}
MunitResult q_int_test_dequeue(const MunitParameter params[], void* fixture) {
  q_int q = q_int_new();
  for (int i = 0; i < 100; i++) {
    q_int_enqueue(&q, i);
    q_int_node* n = q_int_dequeue(&q);
    munit_assert_ptr_not_null(n);
    munit_assert_int(n->val, ==, i);
    free(n);
  }
  munit_assert_ptr_null(q_int_dequeue(&q));

  munit_assert_ptr_null(q.head);
  munit_assert_ptr_null(q.tail);
  q_int_free(&q);
  return MUNIT_OK;
}
MunitResult q_int_test_front(const MunitParameter params[], void* fixture) {
  q_int q = q_int_new();
  for (int i = 0; i < 100; i++) {
    q_int_enqueue(&q, i);
    int* f = q_int_front(&q);
    munit_assert_ptr_not_null(f);
    munit_assert_int(*f, ==, 0);
  }
  q_int_free(&q);
  return MUNIT_OK;
}
