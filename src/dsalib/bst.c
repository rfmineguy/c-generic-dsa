#include "bst.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

bst bst_new(int buckets_count) {
  bst b = {0};
  b.buckets_count = buckets_count;
  b.buckets = malloc(buckets_count * sizeof(bst_list_node));
  return b;
}
void bst_free(bst* bst) {
  for (int i = 0; i < bst->buckets_count; i++) {
    bst_list_node* n = bst->buckets[i];
    while (n) {
      bst_list_node* t = n;
      n = n->next;
      free(t);
    }
    bst->buckets[i] = 0;
  }
  free(bst->buckets);
  bst->buckets = 0;
}
