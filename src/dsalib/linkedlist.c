#include "linkedlist.h"
#include <stdlib.h>
#include <stdio.h>

linkedlist ll_new() {
  linkedlist ll = {0};
  return ll;
}
void ll_free(linkedlist* ll) {
  const linkedlist_node* n = ll->head;
  while (n) {
    const linkedlist_node* t = n;
    free((void*)t);
    n = n->next;
  }
  ll->head = 0;
  ll->tail = 0;
}

int ll_pushback(linkedlist* ll, int val) {
  linkedlist_node* n = calloc(1, sizeof(linkedlist_node));
  if (!n) return 1;
  n->val = val;

  if (!ll->head && !ll->tail) {
    ll->head = n;
    ll->tail = ll->head;
    return 0;
  }
  if (ll->head == ll->tail) {
    n->prev = ll->tail;
    ll->tail->next = n;
    ll->tail = n;
    return 0;
  }
  n->prev = ll->tail;
  ll->tail->next = n;
  ll->tail = n;
  return 0;
}
