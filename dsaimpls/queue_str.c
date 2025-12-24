#define q_type_type const char*
#define q_type_name str
#define Q_ALLOW_DIRECT_INCLUDE
#include <stdio.h>

void q_str_print_node_val(FILE* f, const char* val) {
  fprintf(f, "%s", val);
}

#include "../dsalib/queue.c"
