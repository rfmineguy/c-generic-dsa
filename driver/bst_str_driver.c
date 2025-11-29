#include "../dsaimpls/bst_str.h"

void bst_str_driver() {
  bst_str bst = bst_str_new();
  bst_str_insert(&bst, "5");
  bst_str_insert(&bst, "20");
  bst_str_insert(&bst, "5");
  bst_str_insert(&bst, "2");
  bst_str_insert(&bst, "8");
  bst_str_insert(&bst, "14");
  bst_str_insert(&bst, "12");
  bst_str_insert(&bst, "11");
  bst_str_insert(&bst, "16");
  bst_str_print(&bst);

  bst_str_delete(&bst, "16");
  bst_str_delete(&bst, "14");
  bst_str_delete(&bst, "12");
  bst_str_print(&bst);

  bst_str_delete(&bst, "11");
  bst_str_delete(&bst, "11");
  bst_str_print(&bst);

  bst_str_delete(&bst, "8");
  bst_str_print(&bst);

  bst_str_delete(&bst, "5");
  bst_str_delete(&bst, "20");
  bst_str_print(&bst);

  bst_str_delete(&bst, "2");
  bst_str_print(&bst);
}
