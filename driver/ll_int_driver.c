#include "../dsaimpls/ll_int.h"

void ll_int_driver() {
  ll_int ll = ll_int_new();
  ll_int_pushback(&ll, 4);
  ll_int_pushback(&ll, 9);
  ll_int_pushback(&ll, 3);
  ll_int_pushfront(&ll, 3);
  ll_int_print(&ll, stdout);
  ll_int_free(&ll);

  ll = ll_int_new();
  ll_int_pushfront(&ll, 3);
  ll_int_pushfront(&ll, 5);
  ll_int_pushfront(&ll, 6);
  ll_int_print(&ll, stdout);

  ll_int_node *n;
  if ((n = ll_int_popfront(&ll))) printf("%d\n", n->val);
  if ((n = ll_int_popfront(&ll))) printf("%d\n", n->val);
  if ((n = ll_int_popfront(&ll))) printf("%d\n", n->val);
  if ((n = ll_int_popfront(&ll))) printf("%d\n", n->val);
  else printf("Null\n");
  // ll_int_popback(&ll);
  // ll_int_popback(&ll);
  // ll_int_popback(&ll);
  ll_int_free(&ll);
}
