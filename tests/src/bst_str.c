#include "tests.h" 
#include "../../dsaimpls/bst_str.h"
#define munit_assert_node_val(node, val_)\
  munit_assert_not_null((node));\
  munit_assert_string_equal((node)->val, val_)

#define TEST_STRINGS_COUNT 30
const char *bst_strings[TEST_STRINGS_COUNT] = {
    "apple",
    "lantern",
    "river",
    "compass",
    "velvet",
    "horizon",
    "timber",
    "quartz",
    "meadow",
    "falcon",
    "ember",
    "summit",
    "orchid",
    "pinecone",
    "drift",
    "canyon",
    "mosaic",
    "harbor",
    "willow",
    "thicket",
    "cobalt",
    "sparrow",
    "granite",
    "cascade",
    "pollen",
    "ironwood",
    "tempest",
    "briar",
    "forest",
    "marble"
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

MunitResult bst_str_test_bfs_iter(const MunitParameter params[], void* fixture) {
  bst_str bst = bst_str_new();
  for (int i = 0; i < TEST_STRINGS_COUNT; i++) {
    bst_str_insert(&bst, bst_strings[i]);
  }

  const char* expected_bst_order[TEST_STRINGS_COUNT] = {
  "apple", "lantern", "compass", "river", "canyon", "horizon", "quartz", "velvet", "briar", "cobalt", "falcon", "ironwood", "meadow", "timber", "willow", "cascade", "ember", "harbor", "marble", "orchid", "summit", "drift", "granite", "mosaic", "pinecone", "sparrow", "thicket", "forest", "pollen", "tempest",
  };

  int i = 0;
  for (bst_str_iter it = bst_str_begin(&bst, BFS); !bst_str_end(&bst, it); it = bst_str_next(&bst, it)) {
    munit_assert_string_equal(expected_bst_order[i++], it.node->val);
  }

  return MUNIT_OK;
}
