#ifndef AVL_H
#define AVL_H
#include <stdio.h>
#include "dsa.h"

#ifndef avl_type_type
#define avl_type_type int
#error "Must define avl_type_type macro"
#endif

#ifndef avl_type_name
#define avl_type_name int
#error "Must define avl_type_name macro"
#endif

#define avl_iter()  join3(avl, avl_type_name, iter, _)
#define avl_node()  join3(avl, avl_type_name, node, _)
#define avl()       join2(avl, avl_type_name, _)

#define avlfunc(name)\
  func_expand3(avl, avl_type_name, name)

struct avl_node() {
  int val, count, height;
  struct avl_node() *parent;
  struct avl_node() *left, *right;
};

typedef struct {
  struct avl_node() *root;
} avl();

typedef enum {
  AVL_BFS,
  AVL_INORDER,
  AVL_PREORDER,
  AVL_POSTORDER
} avl_iter_type;

typedef struct avl_iter() {
  avl_iter_type iter_type;
  int end;
  union {
    q() q;
    stack() stack;
  } dsa;
  struct avl_node()* node, *last_visit;
} avl_iter();

#ifdef AVL_EXPOSE_INTERNAL
struct avl_node()* avlfunc(rotate_right)(struct avl_node()*);
struct avl_node()* avlfunc(rotate_left)(struct avl_node()*);
void avlfunc(print_node)(struct avl_node()* root, int depth, int is_last);
#endif

int   avlfunc(cmp)(avl_type_type, avl_type_type);
void  avlfunc(print_val)(FILE*, avl_type_type);

avl() avlfunc(new)();
void  avlfunc(free)(avl()*);

void  avlfunc(insert)(avl()*, int);
void  avlfunc(delete)(avl()*, int);

int   avlfunc(height)(struct avl_node()*);
int   avlfunc(depth)(struct avl_node()*);
void  avlfunc(print)(FILE*, avl()*);

avl_iter() avlfunc(begin)(avl()* b, avl_iter_type iter_type);
int        avlfunc(end)(avl()* b, avl_iter() it);
avl_iter() avlfunc(next)(avl()* b, avl_iter() it);

#ifdef AVL_GRAPH_ENABLE
#include <stdio.h>
void  avlfunc(print_dot)(FILE*, avl()*);
#endif

// traversal iterator



#endif
