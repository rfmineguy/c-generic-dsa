#include "tests.h"

MunitTest ht[] = {
  { "/new",      ht_test_new, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/free",     ht_test_free, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/put",      ht_test_put, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/iterator", ht_test_iterator, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

MunitSuite suite = {
  "/ht", ht, NULL, 1, MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char** argv) {
  return munit_suite_main(&suite, 0, argc, argv);
}
