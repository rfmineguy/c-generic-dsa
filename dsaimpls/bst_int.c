#define bst_type_name int
#define bst_type_type int

#include <stdio.h>
typedef struct bst_int_node bst_int_node;


#define stack_type_type bst_int_node*
#define stack_type_name bst_int_node
#include "../dsalib/stack.c"

#define q_type_type bst_int_node*
#define q_type_name bst_int_node
#define Q_ALLOW_DIRECT_INCLUDE
#include "../dsalib/queue.c"

#include "../dsalib/bst.h"

int bst_int_cmp(int a, int b) {
  if (a < b) return -1;
  if (a > b) return 1;
  return 0;
}

void bst_int_print_val(FILE* f, int val) {
  fprintf(f, "%d", val);
}

void q_bst_int_node_print_node_val(FILE* f, bst_int_node* val) {
  bst_int_print_val(f, val->val);
}

void stack_bst_int_node_print_node_val(FILE* f, bst_int_node* val) {
  bst_int_print_val(f, val->val);
}

#define ALLOW_DIRECT_INCLUDE
#include "../dsalib/bst.c"
