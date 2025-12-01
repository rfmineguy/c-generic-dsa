typedef struct bst_int_node bst_int_node;

#undef bst_type_name
#undef bst_type_type
#undef q_type_type
#undef q_type_name
#undef stack_type_type
#undef stack_type_name

#define stack_type_type bst_int_node*
#define stack_type_name bst_int_node
#include "../dsalib/stack.h"

#define q_type_type bst_int_node*
#define q_type_name bst_int_node
#include "../dsalib/queue.h"

#define bst_type_name int
#define bst_type_type int
#include "../dsalib/bst.h"
