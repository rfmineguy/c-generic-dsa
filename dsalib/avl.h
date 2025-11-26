#ifndef AVL_H
#define AVL_H

typedef struct avl_node {
  int val;
  struct avl_node *left, *right;
} avl_node;

typedef struct {
  avl_node *root;
} avl;

typedef enum {
  INORDER,
  PREORDER,
  POSTORDER
} avl_iter_type;

typedef struct avl_iter {
  avl_iter_type type;
} avl_iter;

avl   avl_new();
void  avl_free(avl*);

void  avl_insert(avl*, int);
void  avl_remove(avl*, int);

int   avl_depth(avl_node*);
void  avl_print(avl*, int);

#ifdef AVL_GRAPH_ENABLE
#include <stdio.h>
void  avl_generate_graph(avl*, FILE*);
#endif

// traversal iterator



#endif
