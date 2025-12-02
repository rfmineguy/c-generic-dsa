#include "tests.h"
#include "../../dsaimpls/ll_int.h"

#define munit_assert_node(node, val_) {\
  ll_int_node* n = (node);\
  munit_assert_ptr_not_null(n);\
  munit_assert_int(n->val, ==, val_);\
}

MunitResult ll_int_test_new(const MunitParameter params[], void* fixture) {
  ll_int ll = ll_int_new();
  munit_assert_null(ll.head);
  munit_assert_null(ll.tail);
  return MUNIT_OK;
}

MunitResult ll_int_test_free(const MunitParameter params[], void* fixture) {
  ll_int ll = ll_int_new();
  ll.head = malloc(sizeof(ll_int_node));
  ll.tail = ll.head;
  ll_int_free(&ll);

  munit_assert_null(ll.head);
  munit_assert_null(ll.tail);
  return MUNIT_OK;
}

MunitResult ll_int_test_pushback(const MunitParameter params[], void* fixture) {
  ll_int ll = ll_int_new();
  munit_assert_not_null(ll_int_pushback(&ll, 3));
  munit_assert_node(ll.tail, 3);
  munit_assert_not_null(ll_int_pushback(&ll, 5));
  munit_assert_node(ll.tail, 5);
  munit_assert_not_null(ll_int_pushback(&ll, 6));
  munit_assert_node(ll.tail, 6);

  munit_assert_node(ll.head, 3);
  munit_assert_node(ll.head->next, 5);
  munit_assert_node(ll.head->next->next, 6);
  munit_assert_node(ll.tail, 6);

  ll_int_free(&ll);
  return MUNIT_OK;
}

MunitResult ll_int_test_pushfront(const MunitParameter params[], void* fixture) {
  ll_int ll = ll_int_new();
  munit_assert_not_null(ll_int_pushfront(&ll, 3));
  munit_assert_node(ll.head, 3);
  munit_assert_not_null(ll_int_pushfront(&ll, 5));
  munit_assert_node(ll.head, 5);
  munit_assert_not_null(ll_int_pushfront(&ll, 6));
  munit_assert_node(ll.head, 6);

  munit_assert_node(ll.head, 6);
  munit_assert_node(ll.head->next, 5);
  munit_assert_node(ll.head->next->next, 3);
  munit_assert_node(ll.tail, 3);

  ll_int_free(&ll);
  return MUNIT_OK;
}

MunitResult ll_int_test_popback(const MunitParameter params[], void* fixture) {
  ll_int ll = ll_int_new();
  munit_assert_not_null(ll_int_pushfront(&ll, 3));
  munit_assert_node(ll.head, 3);
  munit_assert_node(ll.tail, 3);
  munit_assert_not_null(ll_int_pushfront(&ll, 5));
  munit_assert_node(ll.head, 5);
  munit_assert_node(ll.tail, 3);
  munit_assert_not_null(ll_int_pushfront(&ll, 6));
  munit_assert_node(ll.head, 6);
  munit_assert_node(ll.tail, 3);

  munit_assert_node(ll_int_popback(&ll), 3);
  munit_assert_node(ll_int_popback(&ll), 5);
  munit_assert_node(ll_int_popback(&ll), 6);
  munit_assert_null(ll_int_popback(&ll));
  ll_int_free(&ll);
  return MUNIT_OK;
}

MunitResult ll_int_test_popfront(const MunitParameter params[], void* fixture) {
  ll_int ll = ll_int_new();
  ll_int_node* n;
  munit_assert_not_null(ll_int_pushfront(&ll, 3));
  munit_assert_not_null(ll_int_pushfront(&ll, 5));
  munit_assert_not_null(ll_int_pushfront(&ll, 6));
  munit_assert_node(ll_int_popfront(&ll), 6);
  munit_assert_node(ll_int_popfront(&ll), 5);
  munit_assert_node(ll_int_popfront(&ll), 3);
  munit_assert_null(ll_int_popfront(&ll));
  ll_int_free(&ll);
  return MUNIT_OK;
}

MunitResult ll_int_test_search(const MunitParameter params[], void* fixture) {
  ll_int ll = ll_int_new();
  for (int i = 0; i < 30; i++)
    munit_assert_not_null(ll_int_pushfront(&ll, i));

  for (int i = 30; i < 100; i++)
    munit_assert_null(ll_int_search(&ll, i));

  ll_int_free(&ll);
  return MUNIT_OK;
}

MunitResult ll_int_test_empty(const MunitParameter params[], void* fixture) {
  ll_int ll = ll_int_new();
  munit_assert_true(ll_int_empty(&ll));
  ll_int_pushback(&ll, 3);
  munit_assert_false(ll_int_empty(&ll));
  munit_assert_node(ll_int_popback(&ll), 3);
  munit_assert_true(ll_int_empty(&ll));

  ll_int_free(&ll);
  return MUNIT_OK;
}
