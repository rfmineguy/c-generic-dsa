#ifndef BST_TEMPLATE_H
#define BST_TEMPLATE_H
#include "dsa.h"

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

#define bstfunc(namespace, name)\
  func_expand3(namespace, bst_type_name, name)

typedef enum {
  BFS,
  DFS_INORDER,
  DFS_PREORDER,
  DFS_POSTORDER,
} itertype;

struct bst_node() {
  bst_type_type val;
  int count;
  bst_node() *left, *right;
};

typedef struct bst_iter() {
  itertype iter_type;
  int end;
  q() q;
  bst_node() *node;
} bst_iter();

typedef struct bst() {
  bst_node()* root;
} bst();

bst() bstfunc(bst, new)();
void  bstfunc(bst, free)(bst()* b);

int        bstfunc(bst, cmp)(bst_type_type, bst_type_type);

void       bstfunc(bst, insert)(bst()* b, bst_type_type);
bst_node()*bstfunc(bst, delete)(bst()* b, bst_type_type);
bst_type_type* bstfunc(bst, search)(bst()* b, bst_type_type);

void       bstfunc(bst, print_val)(bst_type_type);
void       bstfunc(bst, print)(bst()* b);

bst_iter() bstfunc(bst, begin)(bst()* b, itertype iter_type);
int        bstfunc(bst, end)(bst()* b, bst_iter() it);
bst_iter() bstfunc(bst, next)(bst()* b, bst_iter() it);

#endif
