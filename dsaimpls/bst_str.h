typedef struct bst_str_node bst_str_node;

#undef bst_type_name
#undef bst_type_type
#undef q_type_type
#undef q_type_name

#define q_type_type bst_str_node*
#define q_type_name bst_str_node
#include "../dsalib/queue.h"

#define bst_type_name str
#define bst_type_type const char*
#include "../dsalib/bst.h"
