#include <stdio.h>
#include "bst_int.h"
int bst_int_cmp(int a, int b) {
  if (a < b) return -1;
  if (a > b) return 1;
  return 0;
}

void bst_int_print_val(int val) {
  printf("%d", val);
}

void q_bst_int_node_print_node_val(bst_int_node* val) {
  bst_int_print_val(val->val);
}

#define ALLOW_DIRECT_INCLUDE
#include "../dsalib/bst.c"
