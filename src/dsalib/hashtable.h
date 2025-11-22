#ifndef BST_H
#define BST_H
#include <stdbool.h>

typedef struct ht_list_node {
  const char* key;
  int value;
  struct ht_list_node *next, *prev;
} ht_list_node;

typedef struct ht {
  ht_list_node** buckets;
  int buckets_count;
} ht;

typedef struct ht_iter {
  int bucket, idx;
  ht_list_node* node;
} ht_iter;

ht  ht_new(int buckets_count);
void ht_free(ht* ht);

int ht_hash(void* key, int keysize);
ht_list_node* ht_put(ht* ht, const char* key, int value);
int* ht_get(ht* ht, const char* key);
void ht_rem(ht* ht, const char* key);

void ht_print(ht* ht);

ht_iter ht_begin(ht* ht);
bool     ht_end(ht* ht, ht_iter it);
ht_iter ht_next(ht* ht, ht_iter it);

#endif
