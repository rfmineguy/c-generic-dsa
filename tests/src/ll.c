#include "tests.h"
#include "../../dsalib/linkedlist.h"

// MunitResult ll_test_new(const MunitParameter params[], void* user_data_or_fixture) {
//   linkedlist ll = ll_new();
//   munit_assert_null(ll.head);
//   munit_assert_null(ll.tail);
// 
//   ll_free(&ll);
//   return MUNIT_OK;
// }
// 
// MunitResult ll_test_free(const MunitParameter params[], void* user_data) {
//   linkedlist ll = ll_new();
//   ll.head = malloc(sizeof(linkedlist_node));
//   ll.tail = malloc(sizeof(linkedlist_node));
//   ll_free(&ll);
// 
//   munit_assert_null(ll.head);
//   munit_assert_null(ll.tail);
//   return MUNIT_OK;
// }
// 
// MunitResult ll_test_pushback(const MunitParameter params[], void* user_data) {
//   linkedlist ll = ll_new();
// 
//   // push into the list
//   for (int i = 0; i < 100; i++) {
//     munit_assert_int(ll_pushback(&ll, i), ==, 0);
//   }
//   munit_assert_int(ll_count(&ll), ==, 100);
// 
//   // check list content backward
//   linkedlist_node* n = ll.tail;
//   for (int i = 99; i >= 0; i--) {
//     munit_assert_int(n->val, ==, i);
//     n = n->prev;
//   }
// 
//   ll_free(&ll);
//   return MUNIT_OK;
// }
// 
// MunitResult ll_test_pushfront(const MunitParameter params[], void* user_data) {
//   linkedlist ll = ll_new();
// 
//   // push into the list
//   for (int i = 0; i < 100; i++) {
//     munit_assert_int(ll_pushfront(&ll, i), ==, 0);
//   }
//   munit_assert_int(ll_count(&ll), ==, 100);
// 
//   // check list content forward
//   linkedlist_node* n = ll.head;
//   for (int i = 99; i >= 0; i--) {
//     munit_assert_int(n->val, ==, i);
//     n = n->next;
//   }
// 
//   ll_free(&ll);
//   return MUNIT_OK;
// }
// 
// MunitResult ll_test_popback(const MunitParameter params[], void* user_data) {
//   linkedlist ll = ll_new();
//   for (int i = 0; i < 100; i++) munit_assert_int(ll_pushback(&ll, i), ==, 0);
//   munit_assert_int(ll_count(&ll), ==, 100);
//   for (int i = 0; i < 100; i++) ll_popback(&ll);
//   munit_assert_int(ll_count(&ll), ==, 0);
// 
//   munit_assert_ptr_null(ll_popback(&ll));
//   ll_free(&ll);
//   return MUNIT_OK;
// }
// 
// MunitResult ll_test_popfront(const MunitParameter params[], void* user_data) {
//   linkedlist ll = ll_new();
//   for (int i = 0; i < 100; i++) munit_assert_int(ll_pushfront(&ll, i), ==, 0);
//   munit_assert_int(ll_count(&ll), ==, 100);
//   for (int i = 0; i < 100; i++) munit_assert_ptr_not_null(ll_popfront(&ll));
//   munit_assert_int(ll_count(&ll), ==, 0);
// 
//   munit_assert_ptr_null(ll_popfront(&ll));
//   return MUNIT_OK;
// }
// 
// MunitResult ll_test_search(const MunitParameter params[], void* user_data) {
//   linkedlist ll = ll_new();
// 
//   for (int i = 0; i < 100; i++) munit_assert_int(ll_pushfront(&ll, i), ==, 0);
//   munit_assert_int(ll_count(&ll), ==, 100);
// 
//   for (int i = 0; i < 100; i++) {
//     int r = munit_rand_int_range(0, 99);
//     munit_assert_not_null(ll_search(&ll, r));
//   }
// 
//   ll_free(&ll);
//   return MUNIT_OK;
// }
// 
// MunitResult ll_test_empty(const MunitParameter params[], void* user_data) {
//   linkedlist ll = ll_new();
// 
//   for (int i = 0; i < 100; i++) munit_assert_int(ll_pushfront(&ll, i), ==, 0);
//   munit_assert_int(ll_count(&ll), ==, 100);
// 
//   for (int i = 0; i < 100; i++) {
//     int r = munit_rand_int_range(0, 99);
//     munit_assert_not_null(ll_search(&ll, r));
//   }
// 
//   while (!ll_empty(&ll)) free(ll_popfront(&ll));
// 
//   munit_assert_int(ll_count(&ll), ==, 0);
//   munit_assert_true(ll_empty(&ll));
// 
//   ll_free(&ll);
//   return MUNIT_OK;
// }
