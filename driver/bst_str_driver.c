#include "../dsaimpls/bst_str.h"
#include <stdio.h>

#define TEST_STRINGS_COUNT 30
const char *strings[TEST_STRINGS_COUNT] = {
  "aj2kf",
  "z",
  "pQ9",
  "mve01t",
  "a42ja",
  "R8wZb0",
  "qur",
  "0x4b",
  "hJtP2",
  "F",
  "t9cLQe",
  "ox",
  "W3v7",
  "g4",
  "Ypks2M",
  "29",
  "bdXqtrN",
  "E0j",
  "UuVr",
  "H0",
  "aB9nQ",
  "m",
  "C2xH7pFd",
  "kXx",
  "s4D1",
  "Jv0R",
  "P",
  "Tt9wx",
  "fZ",
  "n3hKpQ0"
};

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
