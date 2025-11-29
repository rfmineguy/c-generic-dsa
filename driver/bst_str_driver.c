#include "../dsaimpls/bst_str.h"
#include <stdio.h>

#define TEST_STRINGS_COUNT 30
const char *strings[TEST_STRINGS_COUNT] = {
    "apple",
    "lantern",
    "river",
    "compass",
    "velvet",
    "horizon",
    "timber",
    "quartz",
    "meadow",
    "falcon",
    "ember",
    "summit",
    "orchid",
    "pinecone",
    "drift",
    "canyon",
    "mosaic",
    "harbor",
    "willow",
    "thicket",
    "cobalt",
    "sparrow",
    "granite",
    "cascade",
    "pollen",
    "ironwood",
    "tempest",
    "briar",
    "forest",
    "marble"
};


void bst_str_driver_iterator() {
  bst_str bst = bst_str_new();
  for (int i = 0; i < TEST_STRINGS_COUNT; i++) {
    bst_str_insert(&bst, strings[i]);
  }


  printf("Iterator\n");
  for (bst_str_iter it = bst_str_begin(&bst, BFS); !bst_str_end(&bst, it); it = bst_str_next(&bst, it)) {
    printf("'%s', ", it.node->val);
  }
  printf("\nIterator\n");

}

void bst_str_driver_no_iterator() {
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
  bst_str_free(&bst);

  bst = bst_str_new();
  for (int i = TEST_STRINGS_COUNT - 1; i >= 0; i--) {
    bst_str_insert(&bst, strings[i]);
  }
  for (int i = TEST_STRINGS_COUNT/2; i >= 0; i--) bst_str_insert(&bst, strings[i]);

  for (int i = 1; i < TEST_STRINGS_COUNT/2; i++) {
    bst_str_insert(&bst, strings[0]);
  }

  bst_str_free(&bst);
}
