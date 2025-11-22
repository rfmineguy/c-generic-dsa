#ifndef TESTS_H
#define TESTS_H
#include "munit.h"

MunitResult ht_test_new(const MunitParameter[], void*);
MunitResult ht_test_free(const MunitParameter[], void*);
MunitResult ht_test_put(const MunitParameter[], void*);
MunitResult ht_test_iterator(const MunitParameter[], void*);

#endif
