#include "bst.h"
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define BST_ALLOW_DIRECT_INCLUDE ALLOW_DIRECT_INCLUDE

#ifndef BST_ALLOW_DIRECT_INCLUDE
#error "This file is not intended to be compiled directly"
#endif

#define HPIPE "\u2014"
#define XPIPE "\u0371"
#define N     "\u221F"
#define ELBOW "\u23B8"

static int var(bst, rec_depth)[1000];

static void bstfunc(bst, free_node)(struct bst_node()** n) {
  if (!*(n)) return;
  if ((*n)->left) bstfunc(bst, free_node)(&(*n)->left);
  if ((*n)->right) bstfunc(bst, free_node)(&(*n)->right);
  free((*n));
  *n = 0;
}
