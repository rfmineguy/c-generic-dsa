#ifndef BST_TEMPLATE_H
#define BST_TEMPLATE_H
#include "dsa.h"
#include <stdio.h>

#ifndef bst_type_type
#define bst_type_type int
#error "Must define bst_type_name macro"
#endif

#ifndef bst_type_name
#define bst_type_name int
#error "Must define bst_type_name macro"
#endif

#define bst_iter()  join3(bst, bst_type_name, iter, _)
#define bst_node()  join3(bst, bst_type_name, node, _)
#define bst()       join2(bst, bst_type_name, _)

#define bstfunc(name)\
  func_expand3(bst, bst_type_name, name)

typedef enum {
  BFS,
  DFS_INORDER,
  DFS_PREORDER,
  DFS_POSTORDER,
} bst_itertype;

struct bst_node() {
  bst_type_type val;
  int count;
  bst_node() *left, *right;
};

typedef struct bst_iter() {
  bst_itertype iter_type;
  int end;
  union {
    q() q;
    stack() stack;
  } dsa;
  bst_node() *node, *last_visit;
} bst_iter();

typedef struct bst() {
  bst_node()* root;
} bst();

bst() bstfunc(new)();
void  bstfunc(free)(bst()* b);

int        bstfunc(cmp)(bst_type_type, bst_type_type);

void       bstfunc(insert)(bst()* b, bst_type_type);
bst_node()*bstfunc(delete)(bst()* b, bst_type_type);
bst_type_type* bstfunc(search)(bst()* b, bst_type_type);

void       bstfunc(print_val)(FILE*, bst_type_type);
void       bstfunc(print)(FILE* f, bst()* b);
void       bstfunc(print_dot)(FILE* f, bst()* b);

bst_iter() bstfunc(begin)(bst()* b, bst_itertype iter_type);
int        bstfunc(end)(bst()* b, bst_iter() it);
bst_iter() bstfunc(next)(bst()* b, bst_iter() it);

#endif
