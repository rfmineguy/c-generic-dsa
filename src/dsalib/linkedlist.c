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
