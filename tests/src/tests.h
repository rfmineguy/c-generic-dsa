#ifndef TESTS_H
#define TESTS_H
#include "munit.h"

MunitResult ht_str_int_test_new(const MunitParameter[], void*);
MunitResult ht_str_int_test_free(const MunitParameter[], void*);
MunitResult ht_str_int_test_put(const MunitParameter[], void*);
MunitResult ht_str_int_test_remove(const MunitParameter[], void*);
MunitResult ht_str_int_test_iterator(const MunitParameter[], void*);

MunitResult ll_int_test_new(const MunitParameter[], void*);
MunitResult ll_int_test_free(const MunitParameter[], void*);
MunitResult ll_int_test_pushback(const MunitParameter[], void*);
MunitResult ll_int_test_pushfront(const MunitParameter[], void*);
MunitResult ll_int_test_popback(const MunitParameter[], void*);
MunitResult ll_int_test_popfront(const MunitParameter[], void*);
MunitResult ll_int_test_search(const MunitParameter[], void*);
MunitResult ll_int_test_empty(const MunitParameter [], void*);

MunitResult q_int_test_new(const MunitParameter [], void*);
MunitResult q_int_test_free(const MunitParameter [], void*);
MunitResult q_int_test_enqueue(const MunitParameter [], void*);
MunitResult q_int_test_dequeue(const MunitParameter [], void*);
MunitResult q_int_test_front(const MunitParameter [], void*);

MunitResult q_str_test_new(const MunitParameter [], void*);
MunitResult q_str_test_free(const MunitParameter [], void*);
MunitResult q_str_test_enqueue(const MunitParameter [], void*);
MunitResult q_str_test_dequeue(const MunitParameter [], void*);
MunitResult q_str_test_front(const MunitParameter [], void*);

MunitResult bst_int_test_new(const MunitParameter [], void*);
MunitResult bst_int_test_free(const MunitParameter [], void*);
MunitResult bst_int_test_insert(const MunitParameter [], void*);
MunitResult bst_int_test_insert_duplicate(const MunitParameter [], void*);
MunitResult bst_int_test_insert_inorder_inc(const MunitParameter [], void*);
MunitResult bst_int_test_insert_inorder_dec(const MunitParameter [], void*);
MunitResult bst_int_test_delete(const MunitParameter [], void*);
MunitResult bst_int_test_search(const MunitParameter [], void*);
MunitResult bst_int_test_bfs_iter(const MunitParameter [], void*);

MunitResult bst_str_test_new(const MunitParameter [], void*);
MunitResult bst_str_test_free(const MunitParameter [], void*);
MunitResult bst_str_test_insert(const MunitParameter [], void*);
MunitResult bst_str_test_insert_duplicate(const MunitParameter [], void*);
MunitResult bst_str_test_delete(const MunitParameter [], void*);
MunitResult bst_str_test_search(const MunitParameter [], void*);
MunitResult bst_str_test_bfs_iter(const MunitParameter [], void*);

MunitResult stack_int_test_new(const MunitParameter [], void*);
MunitResult stack_int_test_free(const MunitParameter [], void*);
MunitResult stack_int_test_push(const MunitParameter [], void*);
MunitResult stack_int_test_pop(const MunitParameter [], void*);
MunitResult stack_int_test_top(const MunitParameter [], void*);
MunitResult stack_int_test_empty(const MunitParameter [], void*);

#endif
