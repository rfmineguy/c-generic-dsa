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
bst_list_node* bst_put(bst *bst, const char* key, int value) {
  int hash = bst_hash((void*)key, strlen(key)) % bst->buckets_count;
  bst_list_node* n = bst->buckets[hash];
  if (!n) {
    bst->buckets[hash] = calloc(1, sizeof(bst_list_node));
    bst->buckets[hash]->value = value;
    bst->buckets[hash]->key = key;
    return bst->buckets[hash];
  }
  bst_list_node* new = calloc(1, sizeof(bst_list_node));
  new->key = key;
  new->value = value;
  bst->buckets[hash] = new;
  new->next = n;
  return new;
}
