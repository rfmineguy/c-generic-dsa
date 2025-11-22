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
int bst_hash(void* key, int keysize) {
  int hash = 0;
  for (int i = 0; i < keysize; i++) {
    char c = *(char*)(key + i);
    hash += c * 3 * i;
  }
  return hash;
}
