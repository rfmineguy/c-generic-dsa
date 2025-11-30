#include "tests.h"
#include "../../dsaimpls/stack_int.h"

MunitResult stack_int_test_new(const MunitParameter params[], void* fixture) {
  stack_int s = stack_int_new();
  munit_assert_ptr_null(s.head);
  return MUNIT_OK;
};
MunitResult stack_int_test_free(const MunitParameter params[], void* fixture) {
  stack_int s = stack_int_new();
  s.head = malloc(sizeof(struct stack_int_node*));
  stack_int_free(&s);
  munit_assert_ptr_null(s.head);
  return MUNIT_OK;
};
MunitResult stack_int_test_push(const MunitParameter params[], void* fixture) {
  stack_int s = stack_int_new();
  munit_assert_ptr_not_null(stack_int_push(&s, 3));
  munit_assert_ptr_not_null(stack_int_push(&s, 5));
  munit_assert_int(s.head->val, ==, 5);
  stack_int_free(&s);
  return MUNIT_OK;
};
MunitResult stack_int_test_pop(const MunitParameter params[], void* fixture) {
  stack_int s = stack_int_new();
  munit_assert_ptr_not_null(stack_int_push(&s, 3));
  struct stack_int_node* n = stack_int_pop(&s);
  munit_assert_ptr_not_null(n);
  munit_assert_int(n->val, ==, 3);
  free(n);
  munit_assert_ptr_null(s.head);

  munit_assert_ptr_null(stack_int_pop(&s));
  stack_int_free(&s);
  return MUNIT_OK;
};
MunitResult stack_int_test_top(const MunitParameter params[], void* fixture) {
  stack_int s = stack_int_new();
  munit_assert_ptr_not_null(stack_int_push(&s, 3));
  munit_assert_ptr_not_null(stack_int_top(&s));
  munit_assert_int(*stack_int_top(&s), ==, 3);

  munit_assert_ptr_not_null(stack_int_push(&s, 9));
  munit_assert_ptr_not_null(stack_int_top(&s));
  munit_assert_int(*stack_int_top(&s), ==, 9);

  struct stack_int_node* n = stack_int_pop(&s);
  munit_assert_ptr_not_null(n);
  free(n);
  munit_assert_int(*stack_int_top(&s), ==, 3);

  n = stack_int_pop(&s);
  munit_assert_ptr_null(stack_int_top(&s));
  free(n);

  stack_int_free(&s);
  return MUNIT_OK;
};
MunitResult stack_int_test_empty(const MunitParameter params[], void* fixture) {
  stack_int s = stack_int_new();
  munit_assert_true(stack_int_empty(&s));
  stack_int_push(&s, 5);
  munit_assert_false(stack_int_empty(&s));
  free(stack_int_pop(&s));
  munit_assert_true(stack_int_empty(&s));
  stack_int_free(&s);
  return MUNIT_OK;
};
