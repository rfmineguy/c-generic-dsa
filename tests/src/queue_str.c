#include "tests.h"
#include "../../dsaimpls/queue_str.h"

#define TEST_STRINGS_COUNT 30
const char *q_strings[TEST_STRINGS_COUNT] = {
  "aj2kf",
  "z",
  "pQ9",
  "mve01t",
  "a42ja",
  "R8wZb0",
  "qur",
  "0x4b",
  "hJtP2",
  "F",
  "t9cLQe",
  "ox",
  "W3v7",
  "g4",
  "Ypks2M",
  "29",
  "bdXqtrN",
  "E0j",
  "UuVr",
  "H0",
  "aB9nQ",
  "m",
  "C2xH7pFd",
  "kXx",
  "s4D1",
  "Jv0R",
  "P",
  "Tt9wx",
  "fZ",
  "n3hKpQ0"
};

MunitResult q_str_test_new(const MunitParameter params[], void* fixture) {
  q_str q = q_str_new();
  munit_assert_null(q.head);
  munit_assert_null(q.tail);

  q_str_free(&q);
  return MUNIT_OK;
}
MunitResult q_str_test_free(const MunitParameter params[], void* fixture) {
  q_str q = q_str_new();
  q.head = malloc(sizeof(q_str_node));
  q.tail = malloc(sizeof(q_str_node));
  q_str_free(&q);
  munit_assert_null(q.head);
  munit_assert_null(q.tail);
  return MUNIT_OK;
}
MunitResult q_str_test_enqueue(const MunitParameter params[], void* fixture) {
  q_str q = q_str_new();
  for (int i = 0; i < TEST_STRINGS_COUNT; i++) {
    q_str_enqueue(&q, q_strings[i]);
    munit_assert_ptr_not_null(q.tail);
    munit_assert_string_equal(q.tail->val, q_strings[i]);
  }
  q_str_free(&q);
  return MUNIT_OK;
}
MunitResult q_str_test_dequeue(const MunitParameter params[], void* fixture) {
  q_str q = q_str_new();
  for (int i = 0; i < TEST_STRINGS_COUNT; i++) {
    q_str_enqueue(&q, q_strings[i]);
    q_str_node* n = q_str_dequeue(&q);
    munit_assert_ptr_not_null(n);
    munit_assert_null(q.tail);
    // munit_assert_string_equal(q.tail->val, q_strings[i]);
    free(n);
  }
  munit_assert_ptr_null(q_str_dequeue(&q));

  munit_assert_ptr_null(q.head);
  munit_assert_ptr_null(q.tail);
  q_str_free(&q);
  return MUNIT_OK;
}
MunitResult q_str_test_front(const MunitParameter params[], void* fixture) {
  q_str q = q_str_new();
  for (int i = 0; i < TEST_STRINGS_COUNT; i++) {
    q_str_enqueue(&q, q_strings[i]);
    const char** f = q_str_front(&q);
    munit_assert_ptr_not_null(f);
    munit_assert_string_equal(*f, q_strings[0]);
  }
  q_str_free(&q);
  return MUNIT_OK;
}
