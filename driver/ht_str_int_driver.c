#include "../dsaimpls/ht_str_int.h"
#include <stdio.h>

void ht_str_int_driver() {
  ht_str_int b = ht_str_int_new(7);
  ht_str_int_put(&b, "hi", 4);
  ht_str_int_put(&b, "akjf", 6);
  ht_str_int_put(&b, "booger", 9);
  ht_str_int_put(&b, "something", 2);
  ht_str_int_put(&b, "general kant", 7);
  ht_str_int_put(&b, "hello", 3);
  ht_str_int_print(&b);

  for (ht_str_int_iter it = ht_str_int_begin(&b); !ht_str_int_end(&b, it); it = ht_str_int_next(&b, it)) {
     printf("%d, (%s, %d)\n", it.idx, it.node->key, it.node->value);
  }

  ht_str_int_rem(&b, "akjf");
  ht_str_int_free(&b);
}
