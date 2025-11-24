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
int ll_pushfront(linkedlist* ll, int val) {
  linkedlist_node* n = calloc(1, sizeof(linkedlist_node));
  if (!n) return 1;
  n->val = val;

  if (!ll->head && !ll->tail) {
    ll->head = n;
    ll->tail = ll->head;
    return 0;
  }
  if (ll->head == ll->tail) {
    n->next = ll->head;
    ll->head->prev = n;
    ll->head = n;
    return 0;
  }
  n->next = ll->head;
  ll->head->prev = n;
  ll->head = n;
  return 0;
}

linkedlist_node* ll_popback(linkedlist* ll) {
  if (!ll->head) return 0;
  if (ll->head == ll->tail) {
    linkedlist_node *n = ll->head;
    ll->head = 0;
    ll->tail = 0;
    return n;
  }
  linkedlist_node* n = ll->tail;
  ll->tail = ll->tail->prev;
  ll->tail->next = 0;
  return n;
}
linkedlist_node* ll_popfront(linkedlist* ll) {
  if (!ll->head) return 0;
  if (ll->head == ll->tail) {
    linkedlist_node *n = ll->head;
    ll->head = 0;
    ll->tail = 0;
    return n;
  }
  linkedlist_node* n = ll->head;
  ll->head = ll->head->next;
  ll->head->prev = 0;
  return n;
}
linkedlist_node* ll_search(linkedlist* ll, int v) {
  linkedlist_node* n = ll->head;
  while (n && n->val != v) n = n->next;
  return n;
}
int ll_count(linkedlist* ll) {
  int count = 0;
  linkedlist_node* n = ll->head;
  while (n) {
    count++;
    n = n->next;
  }
  return count;
}
bool ll_empty(linkedlist* ll) {
  return ll->head == 0;
}
