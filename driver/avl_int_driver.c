#define AVL_EXPOSE_INTERNAL
#define AVL_GRAPH_ENABLE
#include "../dsaimpls/avl_int.h"
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

/*
 * This driver produces .dot files that need to be transformed into images with the following
 *   bash expression
 *
 * $ for file in out/avl_dot/*.dot; do dot -Tpng "$file" >> "$file.png"; done
 *
 */
void avl_int_driver() {
  char filename[1000];
  avl_int d = avl_int_new();
  struct stat st;
  if (stat("out/avl_dot", &st) == -1) {
    mkdir("out/avl_dot", 0700);
  }

  for (int i = 1; i < 10; i++) {
    snprintf(filename, 1000, "out/avl_dot/out_insert%d.dot", i);
    FILE* f = fopen(filename, "w");
    avl_int_insert(&d, i);
    avl_int_print_dot(f, &d);
    fclose(f);
  }

  for (int i = 0; i < 5; i++) {
    snprintf(filename, 1000, "out/avl_dot/out_remove%d.dot", i);
    FILE* f = fopen(filename, "w");
    avl_int_delete(&d, d.root->val);
    avl_int_print_dot(f, &d);
    fclose(f);
  }

  avl_int_free(&d);
}
