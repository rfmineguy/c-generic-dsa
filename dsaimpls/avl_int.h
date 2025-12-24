typedef struct avl_int_node avl_int_node;

#undef avl_type_name
#undef avl_type_type
#undef q_type_type
#undef q_type_name
#undef stack_type_type
#undef stack_type_name

#define stack_type_type avl_int_node*
#define stack_type_name avl_int_node
#include "../dsalib/stack.h"

#define q_type_type avl_int_node*
#define q_type_name avl_int_node
#include "../dsalib/queue.h"

#define avl_type_name int
#define avl_type_type int
#include "../dsalib/avl.h"
