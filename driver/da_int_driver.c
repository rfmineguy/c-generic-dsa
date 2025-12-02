#include "../dsaimpls/da_int.h"

void da_int_driver() {
  da_int da = da_int_new(10);
  for (int i = 0; i < 6; i++)
    da_int_append(&da, i);

  da_int_print(&da, stdout);

  for (int i = 3; i < 15; i++) {
    int c;
    if (!(c = da_int_append(&da, i)))
      fprintf(stderr, "Failed to append: %d\n", c);
    da_int_print(&da, stdout);
  }

  da_int_insert_at(&da, 0, 4);
  da_int_insert_at(&da, 3, 24);
  da_int_print(&da, stdout);
  da_int_delete_at(&da, 3, NULL);
  da_int_delete_at(&da, 0, NULL);
  da_int_print(&da, stdout);

  int* x;
  if ((x = da_int_at(&da, 6))) {
    printf("%d\n", *x);
  }

  da_int_free(&da);
}
