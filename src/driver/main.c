#include "../dsalib/hashtable.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {
  ht b = ht_new(7);
  ht_put(&b, "hi", 4);
  ht_put(&b, "akjf", 6);
  ht_put(&b, "booger", 9);
  ht_put(&b, "something", 2);
  ht_put(&b, "general kant", 7);
  ht_put(&b, "hello", 3);
  ht_print(&b);

  for (ht_iter it = ht_begin(&b); !ht_end(&b, it); it = ht_next(&b, it)) {
     printf("%d, (%s, %d)\n", it.idx, it.node->key, it.node->value);
  }

  ht_free(&b);
}
