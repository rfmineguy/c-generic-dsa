#include "tests.h" 
#include "../../dsaimpls/bst_str.h"
#define munit_assert_node_val(node, val_)\
  munit_assert_not_null((node));\
  munit_assert_string_equal((node)->val, val_)

#define TEST_STRINGS_COUNT 30
const char *bst_strings[TEST_STRINGS_COUNT] = {
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

MunitResult bst_str_test_new(const MunitParameter params[], void* fixture) {
  bst_str bst = bst_str_new();
  munit_assert_ptr_null(bst.root);
  return MUNIT_OK;
}

MunitResult bst_str_test_free(const MunitParameter params[], void* fixture) {
  bst_str bst = bst_str_new();
  bst.root = malloc(sizeof(bst_str_node));
  bst.root->left = malloc(sizeof(bst_str_node));
  bst.root->right = malloc(sizeof(bst_str_node));
  bst.root->right->right = malloc(sizeof(bst_str_node));
  bst_str_free(&bst);
  munit_assert_ptr_null(bst.root);
  return MUNIT_OK;
}

MunitResult bst_str_test_insert(const MunitParameter params[], void* fixture) {
  bst_str bst = bst_str_new();
  bst_str_insert(&bst, "5");
  bst_str_insert(&bst, "3");
  bst_str_insert(&bst, "4");
  bst_str_insert(&bst, "1");
  bst_str_insert(&bst, "2");
  bst_str_insert(&bst, "9");

  munit_assert_node_val(bst.root, "5");
  munit_assert_node_val(bst.root->left, "3");
  munit_assert_node_val(bst.root->right, "9");
  munit_assert_node_val(bst.root->left->left, "1");
  munit_assert_node_val(bst.root->left->right, "4");
  munit_assert_node_val(bst.root->left->left->right, "2");
  bst_str_free(&bst);
  return MUNIT_OK;
}

MunitResult bst_str_test_insert_duplicate(const MunitParameter params[], void* fixture) {
  bst_str bst = bst_str_new();
  for (int i = 0; i < TEST_STRINGS_COUNT; i++) bst_str_insert(&bst, bst_strings[i]);

  for (int i = 1; i < TEST_STRINGS_COUNT/2 + 1; i++) {
    bst_str_insert(&bst, bst_strings[0]);
    munit_assert_int(bst.root->count, ==, 1 + i);
  }

  bst_str_free(&bst);
  return MUNIT_OK;
}

MunitResult bst_str_test_delete(const MunitParameter params[], void* fixture) {
  bst_str bst = bst_str_new();
  for (int i = 0; i < TEST_STRINGS_COUNT; i++) bst_str_insert(&bst, bst_strings[i]);

  munit_assert_not_null(bst_str_delete(&bst, bst_strings[2]));
  munit_assert_not_null(bst_str_delete(&bst, bst_strings[0]));
  munit_assert_not_null(bst_str_delete(&bst, bst_strings[5]));
  munit_assert_null(bst_str_delete(&bst, "something not in the bst"));

  bst_str_free(&bst);
  return MUNIT_OK;
}

MunitResult bst_str_test_search(const MunitParameter params[], void* fixture) {
  bst_str bst = bst_str_new();
  const char** i = bst_str_search(&bst, bst_strings[0]);
  munit_assert_ptr_null(i);
  
  bst_str_insert(&bst, bst_strings[0]);
  i = bst_str_search(&bst, bst_strings[0]);
  munit_assert_ptr_not_null(i);

  for (int i = 0; i < TEST_STRINGS_COUNT; i++) {
    bst_str_insert(&bst, bst_strings[i]);
  }

  for (int i = TEST_STRINGS_COUNT-1; i >= 0; i--) {
    const char** b = bst_str_search(&bst, bst_strings[i]);
    munit_assert_not_null(b);
    munit_assert_string_equal(*b, bst_strings[i]);
  }

  bst_str_free(&bst);
  return MUNIT_OK;
}
