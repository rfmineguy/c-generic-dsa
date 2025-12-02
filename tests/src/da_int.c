#include "tests.h"
#include "../../dsaimpls/da_int.h"

MunitResult da_int_test_new(const MunitParameter params[], void* fixture) {
  da_int da = da_int_new(10);
  munit_assert_not_null(da.buffer);
  munit_assert_int(da.capacity, ==, 10);
  munit_assert_int(da.size, ==, 0);
  da_int_free(&da);

  da = da_int_new(30);
  munit_assert_not_null(da.buffer);
  munit_assert_int(da.capacity, ==, 30);
  munit_assert_int(da.size, ==, 0);
  da_int_free(&da);

  return MUNIT_OK;
}

MunitResult da_int_test_free(const MunitParameter params[], void* fixture) {
  da_int da = da_int_new(10);
  munit_assert_not_null(da.buffer);

  da_int_free(&da);
  munit_assert_null(da.buffer);
  return MUNIT_OK;
}

MunitResult da_int_test_append(const MunitParameter params[], void* fixture) {
  da_int da = da_int_new(10);
  munit_assert_not_null(da.buffer);

  for (int i = 0; i < 20; i++) 
    munit_assert_true(da_int_append(&da, i));

  munit_assert_int(da.capacity, ==, 40);
  munit_assert_int(da.size, ==, 20);

  for (int i = 0; i < 20; i++)
    munit_assert_int(da.buffer[i], ==, i);

  da_int_append(&da, 20);
  munit_assert_int(da.capacity, ==, 40);

  da_int_free(&da);
  return MUNIT_OK;
}

MunitResult da_int_test_insert_at(const MunitParameter params[], void* fixture) {
  da_int da = da_int_new(10);

  munit_assert_false(da_int_insert_at(&da, 4, 2));
  munit_assert_true(da_int_insert_at(&da, 0, 2));
  munit_assert_int(da.buffer[0], ==, 2);
  munit_assert_int(da.size, ==, 1);
  munit_assert_int(da.capacity, ==, 10);

  munit_assert_true(da_int_insert_at(&da, 0, 4));
  munit_assert_int(da.buffer[0], ==, 4);
  munit_assert_int(da.buffer[1], ==, 2);
  munit_assert_int(da.size, ==, 2);
  munit_assert_int(da.capacity, ==, 10);

  munit_assert_true(da_int_insert_at(&da, 1, 5));
  munit_assert_int(da.buffer[0], ==, 4);
  munit_assert_int(da.buffer[1], ==, 5);
  munit_assert_int(da.buffer[2], ==, 2);
  munit_assert_int(da.size, ==, 3);
  munit_assert_int(da.capacity, ==, 10);

  for (int i = 0; i < 10; i++) {
    munit_assert_true(da_int_insert_at(&da, 1, i));
  }
  munit_assert_int(da.capacity, ==, 20);

  da_int_free(&da);
  return MUNIT_OK;
}

MunitResult da_int_test_delete_at(const MunitParameter params[], void* fixture) {
  da_int da = da_int_new(10);

  for (int i = 0; i < 10; i++)
    munit_assert_true(da_int_append(&da, i));

  int v;
  if (da_int_delete_at(&da, 0, &v)) munit_assert_int(v, ==, 0);
  if (da_int_delete_at(&da, 5, &v)) munit_assert_int(v, ==, 6);
  if (da_int_delete_at(&da, 9, &v)) munit_assert(false);
  if (da_int_delete_at(&da, 8, &v)) munit_assert(false);
  if (da_int_delete_at(&da, 7, &v)) munit_assert_int(v, ==, 9);

  if (da_int_delete_at(&da, 3, 0)) munit_assert(true);

  munit_assert_int(da.buffer[0], ==, 1);
  munit_assert_int(da.buffer[1], ==, 2);
  munit_assert_int(da.buffer[2], ==, 3);
  munit_assert_int(da.buffer[3], ==, 5);

  da_int_free(&da);
  return MUNIT_OK;
}

MunitResult da_int_test_at(const MunitParameter params[], void* fixture) {
  da_int da = da_int_new(10);

  for (int i = 0; i < 10; i++)
    munit_assert_true(da_int_append(&da, i));

  for (int i = 0; i < 10; i++) {
    int* v;
    munit_assert_not_null(v = da_int_at(&da, i));
    munit_assert_int(*v, ==, i);
  }
  return MUNIT_OK;
}
