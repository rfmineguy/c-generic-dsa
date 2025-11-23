#include "hashtable.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

ht ht_new(int buckets_count) {
  ht b = {0};
  b.buckets_count = buckets_count;
  b.buckets = malloc(buckets_count * sizeof(ht_list_node));
  return b;
}
void ht_free(ht* ht) {
  for (int i = 0; i < ht->buckets_count; i++) {
    ht_list_node* n = ht->buckets[i];
    while (n) {
      ht_list_node* t = n;
      n = n->next;
      free(t);
    }
    ht->buckets[i] = 0;
  }
  free(ht->buckets);
  ht->buckets = 0;
  ht->buckets_count = 0;
}
int ht_hash(void* key, int keysize) {
  int hash = 0;
  for (int i = 0; i < keysize; i++) {
    char c = *(char*)(key + i);
    hash += c * 3 * i;
  }
  return hash;
}
ht_list_node* ht_put(ht *ht, const char* key, int value) {
  int hash = ht_hash((void*)key, strlen(key)) % ht->buckets_count;
  ht_list_node* n = ht->buckets[hash];
  if (!n) {
    ht->buckets[hash] = calloc(1, sizeof(ht_list_node));
    ht->buckets[hash]->value = value;
    ht->buckets[hash]->key = key;
    return ht->buckets[hash];
  }
  ht_list_node* new = calloc(1, sizeof(ht_list_node));
  new->key = key;
  new->value = value;
  ht->buckets[hash] = new;
  new->next = n;
  return new;
}
int* ht_get(ht *ht, const char* key) {
  int hash = ht_hash((void*)key, strlen(key)) % ht->buckets_count;
  ht_list_node* n = ht->buckets[hash];
  if (!n) return 0;
  while (n && strcmp(n->key, key) != 0) n = n->next;
  if (n) return &n->value;
  return 0;
}
void ht_rem(ht *ht, const char* key) {
  int hash = ht_hash((void*)key, strlen(key)) % ht->buckets_count;
  ht_list_node* n = ht->buckets[hash];

  // Find node with key
  while (n && strcmp(n->key, key) != 0) n = n->next;
  if (n == 0) return;

  // If the node is the head
  if (!n->prev) {
    ht->buckets[hash] = n->next;
    free(n);
    return;
  }
  else if (n) {
    n->prev->next = n->next;
    free(n);
  }
}
void ht_print(ht* ht) {
  printf("=========================\n");
  for (int i = 0; i < ht->buckets_count; i++) {
    printf("%d: ", i);
    ht_list_node* n = ht->buckets[i];
    while (n) {
      printf("(%s, %d) -> ", n->key, n->value);
      n = n->next;
    }
    printf("\n");
  }
  printf("=========================\n");
}

ht_iter ht_begin(ht *ht) {
  for (int i = 0; i < ht->buckets_count; i++) {
    if (ht->buckets[i]) {
      return (ht_iter) {.bucket = i, .node = ht->buckets[i], .idx = 0};
    }
  }
  return (ht_iter) {.node = 0};
}

bool ht_end(ht* ht, ht_iter it) {
  return it.node == 0;
}

ht_iter ht_next(ht *ht, ht_iter it) {
  // go to next node in bucket
  if (it.node && it.node->next) {
    it.node = it.node->next;
    it.idx++;
    return it;
  }

  // find next bucket with something in it
  int i;
  for (i = it.bucket + 1; i < ht->buckets_count; i++) {
    if (ht->buckets[i]) {
      it.bucket = i;
      it.node = ht->buckets[i];
      break;
    }
  }
  if (i == ht->buckets_count) return (ht_iter){.node = 0};
  it.idx++;
  return it;
}
