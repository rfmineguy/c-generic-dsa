#include "../dsaimpls/bst_int.h"

void bst_int_driver() {
  bst_int bst = bst_int_new();
  bst_int_insert(&bst, 11);
  bst_int_insert(&bst, 20);
  bst_int_insert(&bst, 5);
  bst_int_insert(&bst, 2);
  bst_int_insert(&bst, 8);
  bst_int_insert(&bst, 14);
  bst_int_insert(&bst, 12);
  bst_int_insert(&bst, 11);
  bst_int_insert(&bst, 16);
  bst_int_print(&bst);

  bst_int_delete(&bst, 16);
  bst_int_delete(&bst, 14);
  bst_int_delete(&bst, 12);
  bst_int_print(&bst);

  bst_int_delete(&bst, 11);
  bst_int_delete(&bst, 11);
  bst_int_print(&bst);

  bst_int_delete(&bst, 8);
  bst_int_print(&bst);

  bst_int_delete(&bst, 5);
  bst_int_delete(&bst, 20);
  bst_int_print(&bst);

  bst_int_delete(&bst, 2);
  bst_int_print(&bst);
}
