#define bst_type_name str
#define bst_type_type const char*

#include <stdio.h>
#include <string.h>
typedef struct bst_str_node bst_str_node;

#define stack_type_type bst_str_node*
#define stack_type_name bst_str_node
#include "../dsalib/stack.c"

#define q_type_type bst_str_node*
#define q_type_name bst_str_node
#define Q_ALLOW_DIRECT_INCLUDE
#include "../dsalib/queue.c"
#include "../dsalib/bst.h"

int bst_str_cmp(const char* a, const char* b) {
  int v = strcmp(a, b);
  return v;
}

void bst_str_print_val(const char* val) {
  printf("%s", val);
}

void q_bst_str_node_print_node_val(bst_str_node* val) {
  bst_str_print_val(val->val);
}
void stack_bst_str_node_print_node_val(bst_str_node* val) {
  bst_str_print_val(val->val);
}
#include "../dsalib/bst.c"
