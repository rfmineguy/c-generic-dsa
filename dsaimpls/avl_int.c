#define avl_type_name int
#define avl_type_type int

#include <stdio.h>
typedef struct avl_int_node avl_int_node;

#define stack_type_type avl_int_node*
#define stack_type_name avl_int_node
#include "../dsalib/stack.c"

#define q_type_type avl_int_node*
#define q_type_name avl_int_node
#define Q_ALLOW_DIRECT_INCLUDE
#include "../dsalib/queue.c"

#include "../dsalib/avl.h"

int avl_int_cmp(int a, int b) {
  if (a < b) return -1;
  if (a > b) return 1;
  return 0;
}

void avl_int_print_val(FILE *f, int val) {
  fprintf(f, "%d", val);
}

void q_avl_int_node_print_node_val(FILE* f, avl_int_node *val) {
  avl_int_print_val(f, val->val);
}

void stack_avl_int_node_print_node_val(FILE* f, avl_int_node* val) {
  avl_int_print_val(f, val->val);
}

#define ALLOW_DIRECT_INCLUDE
#define AVL_GRAPH_ENABLE
#include "../dsalib/avl.c"
