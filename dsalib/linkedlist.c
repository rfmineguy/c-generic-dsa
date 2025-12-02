#include "linkedlist.h"
#include <stdlib.h>
#include <stdio.h>

ll() llfunc(new)() {
  ll() ll = {0};
  return ll;
}
void llfunc(free)(ll()* ll) {
  const ll_node()* n = ll->head;
  while (n) {
    const ll_node()* t = n;
    free((void*)t);
    n = n->next;
  }
  ll->head = 0;
  ll->tail = 0;
}

const ll_node()* llfunc(pushback)(ll()* ll, int val) {
  ll_node()* n = calloc(1, sizeof(ll_node()));
  if (!n) return NULL;
  n->val = val;

  if (!ll->head && !ll->tail) {
    ll->head = n;
    ll->tail = ll->head;
    return n;
  }
  if (ll->head == ll->tail) {
    n->prev = ll->tail;
    ll->tail->next = n;
    ll->tail = n;
    return n;
  }
  n->prev = ll->tail;
  ll->tail->next = n;
  ll->tail = n;
  return n;
}
const ll_node()* llfunc(pushfront)(ll()* ll, int val) {
  ll_node()* n = calloc(1, sizeof(ll_node()));
  if (!n) return NULL;
  n->val = val;

  if (!ll->head && !ll->tail) {
    ll->head = n;
    ll->tail = ll->head;
    return n;
  }
  if (ll->head == ll->tail) {
    n->next = ll->head;
    ll->head->prev = n;
    ll->head = n;
    return n;
  }
  n->next = ll->head;
  ll->head->prev = n;
  ll->head = n;
  return n;
}

ll_node()* llfunc(popback)(ll()* ll) {
  if (!ll->head && !ll->tail) 
    return 0;
  if (ll->head == ll->tail) {
    ll_node() *n = ll->tail;
    ll->head = 0;
    ll->tail = 0;
    return n;
  }
  ll_node()* n = ll->tail;
  ll->tail = ll->tail->prev;
  ll->tail->next = 0;
  return n;
}
ll_node()* llfunc(popfront)(ll()* ll) {
  if (!ll->head) return 0;
  if (ll->head == ll->tail) {
    ll_node() *n = ll->head;
    ll->head = 0;
    ll->tail = 0;
    return n;
  }
  ll_node()* n = ll->head;
  ll->head = ll->head->next;
  ll->head->prev = 0;
  return n;
}
ll_node()* llfunc(search)(ll()* ll, int v) {
  ll_node()* n = ll->head;
  while (n && n->val != v) n = n->next;
  return n;
}
int llfunc(count)(ll()* ll) {
  int count = 0;
  ll_node()* n = ll->head;
  while (n) {
    count++;
    n = n->next;
  }
  return count;
}
bool llfunc(empty)(ll()* ll) {
  return ll->head == 0;
}

void llfunc(print)(ll()* ll, FILE* fptr) {
  ll_node() *n = ll->head;
  while (n) {
    llfunc(print_node_val)(n->val, fptr);
    if (n->next)
      fprintf(fptr, " -> ");
    n = n->next;
  }
  fprintf(fptr, "\n");
}
