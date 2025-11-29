#include "tests.h" 
#include "../../dsaimpls/bst_int.h"
#define munit_assert_node_val(node, val_)\
  munit_assert_not_null((node));\
  munit_assert_int((node)->val, ==, val_)

MunitResult bst_int_test_new(const MunitParameter params[], void* fixture) {
  bst_int bst = bst_int_new();
  munit_assert_ptr_null(bst.root);
  return MUNIT_OK;
}

MunitResult bst_int_test_free(const MunitParameter params[], void* fixture) {
  bst_int bst = bst_int_new();
  bst.root = malloc(sizeof(bst_int_node));
  bst.root->left = malloc(sizeof(bst_int_node));
  bst.root->right = malloc(sizeof(bst_int_node));
  bst.root->right->right = malloc(sizeof(bst_int_node));
  bst_int_free(&bst);
  munit_assert_ptr_null(bst.root);
  return MUNIT_OK;
}

MunitResult bst_int_test_insert(const MunitParameter params[], void* fixture) {
  bst_int bst = bst_int_new();
  bst_int_insert(&bst, 5);
  bst_int_insert(&bst, 3);
  bst_int_insert(&bst, 4);
  bst_int_insert(&bst, 1);
  bst_int_insert(&bst, 2);
  bst_int_insert(&bst, 9);

  munit_assert_node_val(bst.root, 5);
  munit_assert_node_val(bst.root->left, 3);
  munit_assert_node_val(bst.root->right, 9);
  munit_assert_node_val(bst.root->left->left, 1);
  munit_assert_node_val(bst.root->left->right, 4);
  munit_assert_node_val(bst.root->left->left->right, 2);
  bst_int_free(&bst);
  return MUNIT_OK;
}

MunitResult bst_int_test_insert_inorder_inc(const MunitParameter params[], void* fixture) {
  bst_int bst = bst_int_new();
  for (int i = 0; i < 10; i++) 
    bst_int_insert(&bst, i);

  bst_int_node* n = bst.root;
  for (int i = 0; i < 10; i++) {
    munit_assert_node_val(n, i);
    n = n->right;
  }
  return MUNIT_OK;
}

MunitResult bst_int_test_insert_inorder_dec(const MunitParameter params[], void* fixture) {
  bst_int bst = bst_int_new();
  for (int i = 10; i >= 0; i--)
    bst_int_insert(&bst, i);

  bst_int_node* n = bst.root;
  for (int i = 10; i >= 0; i--) {
    munit_assert_node_val(n, i);
    n = n->left;
  }
  return MUNIT_OK;
}

MunitResult bst_int_test_insert_duplicate(const MunitParameter params[], void* fixture) {
  bst_int bst = bst_int_new();
  bst_int_insert(&bst, 5);
  bst_int_insert(&bst, 3);
  bst_int_insert(&bst, 8);
  bst_int_insert(&bst, 6);
  bst_int_insert(&bst, 7);
  bst_int_insert(&bst, 6);

  munit_assert_node_val(bst.root->right->left, 6);
  munit_assert_int(bst.root->right->left->count, ==, 2);

  for (int i = 1; i < 10; i++) {
    bst_int_insert(&bst, 6);
    munit_assert_int(bst.root->right->left->count, ==, 2 + i);
  }

  bst_int_free(&bst);
  return MUNIT_OK;
}

MunitResult bst_int_test_delete(const MunitParameter params[], void* fixture) {
  bst_int bst = bst_int_new();
  bst_int_insert(&bst, 5);
  bst_int_insert(&bst, 3);
  bst_int_insert(&bst, 4);
  bst_int_insert(&bst, 1);
  bst_int_insert(&bst, 2);
  bst_int_insert(&bst, 9);

  bst_int_delete(&bst, 4);
  munit_assert_null(bst.root->left->right);

  bst_int_delete(&bst, 5);
  munit_assert_node_val(bst.root, 3);
  munit_assert_node_val(bst.root->left, 1);

  bst_int_delete(&bst, 10);

  bst_int_free(&bst);
  return MUNIT_OK;
}

MunitResult bst_int_test_search(const MunitParameter params[], void* fixture) {
#define INSERT_ORDER_COUNT 10
  int insert_order[INSERT_ORDER_COUNT] = {50, 10, 30, 40, 15, 20, 21, 5, 8, 4};
  bst_int bst = bst_int_new();
  int* i = bst_int_search(&bst, 10);
  munit_assert_ptr_null(i);
  
  bst_int_insert(&bst, 10);
  i = bst_int_search(&bst, 10);
  munit_assert_ptr_not_null(i);

  for (int i = 0; i < INSERT_ORDER_COUNT; i++) {
    bst_int_insert(&bst, insert_order[i]);
  }

  for (int i = INSERT_ORDER_COUNT-1; i >= 0; i--) {
    int* b = bst_int_search(&bst, insert_order[i]);
    munit_assert_not_null(b);
    munit_assert_int(*b, ==, insert_order[i]);
  }

  bst_int_free(&bst);
  return MUNIT_OK;
}

MunitResult bst_int_test_bfs_iter(const MunitParameter params[], void* fixture) {
#define INSERT_ORDER_COUNT 10
  int insert_order[INSERT_ORDER_COUNT] = {50, 10, 30, 40, 15, 20, 21, 5, 8, 4};
  bst_int bst = bst_int_new();
  for (int i = 0; i < INSERT_ORDER_COUNT; i++) {
    bst_int_insert(&bst, insert_order[i]);
  }

  int expected_bst_order[INSERT_ORDER_COUNT] = {50, 10, 5, 30, 4, 8, 15, 40, 20, 21};

  int i = 0;
  for (bst_int_iter it = bst_int_begin(&bst, BFS); !bst_int_end(&bst, it); it = bst_int_next(&bst, it)) {
    munit_assert_int(expected_bst_order[i++], ==, it.node->val);
  }

  return MUNIT_OK;
}
