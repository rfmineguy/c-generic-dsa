#include "../dsaimpls/bst_int.h"
#include <stdio.h>

void bst_int_driver_iterator() {
#define INSERT_ORDER_COUNT 10
  int insert_order[INSERT_ORDER_COUNT] = {50, 10, 30, 40, 15, 20, 21, 5, 8, 4};
  bst_int bst = bst_int_new();
  for (int i = 0; i < INSERT_ORDER_COUNT; i++) {
    bst_int_insert(&bst, insert_order[i]);
  }

  printf("BFS Iterator\n");
  for (bst_int_iter it = bst_int_begin(&bst, BFS); !bst_int_end(&bst, it); it = bst_int_next(&bst, it)) {
    printf("%d, ", it.node->val);
  }
  printf("\nBFS Iterator\n");

  printf("DFS Inorder Iterator\n");
  for (bst_int_iter it = bst_int_begin(&bst, DFS_INORDER); !bst_int_end(&bst, it); it = bst_int_next(&bst, it)) {
    printf("%d, ", it.node->val);
  }
  printf("\nDFS Inorder Iterator\n");

  printf("DFS Preorder Iterator\n");
  for (bst_int_iter it = bst_int_begin(&bst, DFS_PREORDER); !bst_int_end(&bst, it); it = bst_int_next(&bst, it)) {
    printf("%d, ", it.node->val);
  }
  printf("\nDFS Preorder Iterator\n");

  bst_int_print_dot(stdout, &bst);
}

void bst_int_driver_no_iterator() {
  bst_int bst = bst_int_new();
  bst_int_insert(&bst, 11);
  bst_int_insert(&bst, 20);
  bst_int_insert(&bst, 5);
  bst_int_insert(&bst, 2);
  bst_int_insert(&bst, 8);
  bst_int_insert(&bst, 14);
  bst_int_insert(&bst, 12);
  bst_int_insert(&bst, 11);
  bst_int_insert(&bst, 16);
  bst_int_print(stdout, &bst);
  bst_int_print_dot(stdout, &bst);

  bst_int_delete(&bst, 16);
  bst_int_delete(&bst, 14);
  bst_int_delete(&bst, 12);
  bst_int_print(stdout, &bst);

  bst_int_delete(&bst, 11);
  bst_int_delete(&bst, 11);
  bst_int_print(stdout, &bst);

  bst_int_delete(&bst, 8);
  bst_int_print(stdout, &bst);

  bst_int_delete(&bst, 5);
  bst_int_delete(&bst, 20);
  bst_int_print(stdout, &bst);

  // bst_int_delete(&bst, 2);
  bst_int_print(stdout, &bst);

  // for (bst_int_iter it = bst_int_begin(&bst, BFS); !bst_int_end(&bst, it); it = bst_int_next(&bst, it)) {
  //   bst_int_print_val(it.node->val);
  //   printf(" -> ");
  // }
  bst_int_print_dot(stdout, &bst);
}
