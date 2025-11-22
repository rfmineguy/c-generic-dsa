#include "tests.h"
#include "../src/dsalib/hashtable.h"

typedef struct {
  const char* key;
  int value;
  bool found;
} test_pair;

test_pair test_pairs[20] = {
  {"hello", 4},
  {"world", 7},
  {"test", 12},
  {"alpha", 3},
  {"beta", 15},
  {"gamma", 9},
  {"delta", 1},
  {"omega", 22},
  {"foo", 0},
  {"bar", 18},
  {"baz", 6},
  {"abc", 11},
  {"xyz", 19},
  {"coffee", 27},
  {"kernel", 33},
  {"driver", 5},
  {"memory", 42},
  {"parser", 14},
  {"osdev", 8},
  {"stack", 23},
};

MunitResult ht_test_new(const MunitParameter params[], void* user_data_or_fixture) {
  ht h = ht_new(10);
  munit_assert_int(h.buckets_count, ==, 10);
  for (int i = 0; i < h.buckets_count; i++) {
    munit_assert_null(h.buckets[i]);
  }
  return MUNIT_OK;
}

MunitResult ht_test_free(const MunitParameter params[], void* user_data_or_fixture) {
  ht h = ht_new(10);
  ht_put(&h, "something", 4);
  ht_free(&h);

  munit_assert_null(h.buckets);
  munit_assert_int(h.buckets_count, ==, 0);

  return MUNIT_OK;
}

MunitResult ht_test_put(const MunitParameter params[], void* user_data_or_fixture) {
  ht h = ht_new(10);
  for (int i = 0; i < 20; i++) {
    ht_list_node *n = ht_put(&h, test_pairs[i].key, test_pairs[i].value);
    munit_assert_string_equal(n->key, test_pairs[i].key);
    munit_assert_int(n->value, ==, test_pairs[i].value);
  }
  return MUNIT_OK;
}

MunitResult ht_test_iterator(const MunitParameter params[], void* user_data_or_fixture) {
  return MUNIT_OK;
}
