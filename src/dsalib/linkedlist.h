#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdbool.h>

typedef struct linkedlist_node {
  int val;
  struct linkedlist_node *prev, *next;
} linkedlist_node;

typedef struct linkedlist {
  linkedlist_node *head, *tail;
} linkedlist;

linkedlist       ll_new();
void             ll_free(linkedlist* ll);

int              ll_pushback(linkedlist* ll, int val);
int              ll_pushfront(linkedlist* ll, int val);

linkedlist_node* ll_popback(linkedlist* ll);
linkedlist_node* ll_popfront(linkedlist* ll);

linkedlist_node* ll_search(linkedlist* ll, int v);

int              ll_count(linkedlist* ll);
bool             ll_empty(linkedlist* ll);

#endif
