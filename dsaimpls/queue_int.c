#define q_type_type int
#define q_type_name int
#define Q_ALLOW_DIRECT_INCLUDE
#include <stdio.h>

void q_int_print_node_val(int val) {
  printf("%d", val);
}

#include "../dsalib/queue.c"
