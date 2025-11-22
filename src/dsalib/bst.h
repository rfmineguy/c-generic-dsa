#ifndef BST_H
#define BST_H
#include <stdbool.h>

typedef struct bst_list_node {
  const char* key;
  int value;
  struct bst_list_node *next, *prev;
} bst_list_node;

typedef struct bst {
  bst_list_node** buckets;
  int buckets_count;
} bst;

typedef struct bst_iter {
  int bucket, idx;
  bst_list_node* node;
} bst_iter;

bst  bst_new(int buckets_count);
void bst_free(bst* bst);

int bst_hash(void* key, int keysize);
bst_list_node* bst_put(bst* bst, const char* key, int value);
int* bst_get(bst* bst, const char* key);
void bst_rem(bst* bst, const char* key);

void bst_print(bst* bst);

bst_iter bst_begin(bst* bst);
bool     bst_end(bst* bst, bst_iter it);
bst_iter bst_next(bst* bst, bst_iter it);

#endif
