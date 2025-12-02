#include "tests.h"

MunitTest ht[] = {
  { "/new",      ht_test_new, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/free",     ht_test_free, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/put",      ht_test_put, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/rem",      ht_test_remove, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/iterator", ht_test_iterator, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

MunitTest ll_int[] = {
  { "/new",      ll_int_test_new, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/free",     ll_int_test_free, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/pushback", ll_int_test_pushback, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/pushfront",ll_int_test_pushfront, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/popback",  ll_int_test_popback, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/popfront", ll_int_test_popfront, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/search",   ll_int_test_search, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/empty",    ll_int_test_empty, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

MunitTest q_int[] = {
  { "/new",      q_int_test_new, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/free",     q_int_test_free, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/enqueue",  q_int_test_enqueue, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/dequeue",  q_int_test_dequeue, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/front",    q_int_test_front, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

MunitTest q_str[] = {
  { "/new",      q_str_test_new, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/free",     q_str_test_free, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/enqueue",  q_str_test_enqueue, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/dequeue",  q_str_test_dequeue, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/front",    q_str_test_front, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

MunitTest bst_int[] = {
  { "/new",         bst_int_test_new, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/free",        bst_int_test_free, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/ins",         bst_int_test_insert, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/ins_dup",     bst_int_test_insert_duplicate, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/ins_inc_inord", bst_int_test_insert_inorder_inc, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/ins_dec_inord", bst_int_test_insert_inorder_dec, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/del",         bst_int_test_delete, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/search",      bst_int_test_search, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/bfs_iter",    bst_int_test_bfs_iter, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

MunitTest bst_str[] = {
  { "/new",         bst_str_test_new, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/free",        bst_str_test_free, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/ins",         bst_str_test_insert, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/ins_dup",     bst_str_test_insert_duplicate, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/del",         bst_str_test_delete, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/search",      bst_str_test_search, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/bfs_iter",    bst_str_test_bfs_iter, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

MunitTest stack_int[] = {
  { "/new",         stack_int_test_new, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/free",        stack_int_test_free, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/push",        stack_int_test_push, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/pop",         stack_int_test_pop, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/top",         stack_int_test_top, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/empty",       stack_int_test_empty, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

MunitSuite all_suites[] = {
  { "/ht",      ht, NULL, 1, MUNIT_SUITE_OPTION_NONE },
  { "/ll_int",  ll_int, NULL, 1, MUNIT_SUITE_OPTION_NONE },
  { "/q_int",   q_int,  NULL, 1, MUNIT_SUITE_OPTION_NONE },
  { "/q_str",   q_str,  NULL, 1, MUNIT_SUITE_OPTION_NONE },
  { "/bst_int", bst_int,  NULL, 1, MUNIT_SUITE_OPTION_NONE },
  { "/bst_str", bst_str,  NULL, 1, MUNIT_SUITE_OPTION_NONE },
  { "/stack_int", stack_int,  NULL, 1, MUNIT_SUITE_OPTION_NONE },
  {NULL, NULL, NULL, 0, MUNIT_SUITE_OPTION_NONE},
};

MunitSuite suite = {
  "/dsa", NULL, all_suites, 1, MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char** argv) {
  return munit_suite_main(&suite, 0, argc, argv);
}
