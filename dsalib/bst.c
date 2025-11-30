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

static void bstfunc(bst, insert_node)(struct bst_node()** root, bst_type_type v) {
  if (!(*root)) {
    *root = calloc(1, sizeof(struct bst_node()));
    (*root)->val = v;
    (*root)->count = 1;
    return;
  }
  int cmp = bstfunc(bst, cmp)(v, (*root)->val);
  if (cmp == 0) (*root)->count++;
  if (cmp < 0) bstfunc(bst, insert_node)(&(*root)->left, v);
  if (cmp > 0) bstfunc(bst, insert_node)(&(*root)->right, v);
}

static struct bst_node()* bstfunc(bst, search_node)(struct bst_node()* root, bst_type_type v) {
  if (!root) return 0;

  int cmp = bstfunc(bst, cmp)(v, root->val);
  if (cmp == 0) return root;
  if (cmp < 0) return bstfunc(bst, search_node)(root->left, v);
  return bstfunc(bst, search_node)(root->right, v);
}

static struct bst_node()* bstfunc(bst, delete_node)(struct bst_node()** root, bst_type_type v) {
  if (!(*root)) return 0;
  int cmp = bstfunc(bst, cmp)(v, (*root)->val);

  if (cmp < 0)      return bstfunc(bst, delete_node)(&(*root)->left, v);
  else if (cmp > 0) return bstfunc(bst, delete_node)(&(*root)->right, v);
  else {
    struct bst_node() *target = (*root);
    if ((*root)->count > 1) {
      (*root)->count--;
      return *root;
    }
    if ((*root)->left && (*root)->right) {
      struct bst_node() **left = &(*root)->left;
      while ((*left)->right)
        left = &(*left)->right;

      bst_type_type v = (*left)->val;
      (*left)->val = (*root)->val;
      (*root)->val = v;

      *left = (*left)->left;
      return target;
    }
    if ((*root)->left && !(*root)->right) {
      (*root) = (*root)->left;
      return target;
    }
    if (!(*root)->left && (*root)->right) {
      (*root) = (*root)->right;
      return target;
    }
    *root = 0;
    return target;
  }
}

static void bstfunc(bst, print_node)(struct bst_node()* root, int depth, int is_last) {
    if (!root) return;

    for (int i = 0; i < depth; i++) {
        if (i == depth - 1) {
            // bottom connector
            printf("%s", is_last ? "└──" : "├──");
        } else {
            // ancestor levels
            printf("%s", var(bst, rec_depth)[i] ? "│  " : "   ");
        }
    }

    bstfunc(bst, print_val)(root->val);
    printf(" (%d)\n", root->count);

    // Mark whether at this depth we should draw a vertical continuation later
    if (depth >= 0) var(bst, rec_depth)[depth] = !is_last;

    // Count children to determine who is last
    int has_left  = root->left  != NULL;
    int has_right = root->right != NULL;

    if (has_left) {
      var(bst, rec_depth)[depth] = has_right ? 1 : 0;
      bstfunc(bst, print_node)(root->left, depth + 1, has_right ? 0 : 1);
      var(bst, rec_depth)[depth] = 0;
    }

    if (has_right) {
      var(bst, rec_depth)[depth] = 0;
      bstfunc(bst, print_node)(root->right, depth + 1, 1); // right child is always last
      var(bst, rec_depth)[depth] = 0;
    }
}

bst() bstfunc(bst, new)() {
  return (bst()){.root = 0};
}
void  bstfunc(bst, free)(bst()* b) {
  bstfunc(bst, free_node)(&b->root);
  b->root = 0;
}

void bstfunc(bst, insert)(bst()* b, bst_type_type v) {
  bstfunc(bst, insert_node)(&b->root, v);
}
struct bst_node()* bstfunc(bst, delete)(bst()* b, bst_type_type v) {
  return bstfunc(bst, delete_node)(&b->root, v);
}
bst_type_type* bstfunc(bst, search)(bst()* b, bst_type_type v) {
  struct bst_node()* n = bstfunc(bst, search_node)(b->root, v);
  if (!n) return 0;
  return &n->val;
}
void bstfunc(bst, print)(bst()* b) {
  memset(var(bst, rec_depth), 0, 1000);
  printf("------------\n");
  if (b->root)  bstfunc(bst, print_node)(b->root, 0, 1);
  printf("------------\n");
}

void bstfunc(bst, print_dot)(bst()* b) {
  printf("digraph {\n");
  for (bst_iter() it = bstfunc(bst, begin)(b, BFS); !bstfunc(bst, end)(b, it); it = bstfunc(bst, next)(b, it)) {
    bstfunc(bst, print_val)(it.node->val);
    printf(" -> {");
    if (it.node->left)  bstfunc(bst, print_val)(it.node->left->val);
    if (it.node->right) {
      printf(", ");
      bstfunc(bst, print_val)(it.node->right->val);
    }
    printf(" }\n");
  }
  printf("}\n");
}

static bst_iter() bstfunc(bst, next_bfs)(bst()* b, bst_iter() it) {
  if (qfunc(q, empty)(&it.q)) {
    return (bst_iter()) {.q = it.q, .node = 0, .end = 1};
  }
  it.node = qfunc(q, dequeue)(&it.q)->val;
  if (it.node->left)  qfunc(q, enqueue)(&it.q, it.node->left);
  if (it.node->right) qfunc(q, enqueue)(&it.q, it.node->right);
  return it;
}

static bst_iter() bstfunc(bst, next_dfs_inorder)(bst()* b, bst_iter() it) {
  return (bst_iter()){};
}

static bst_iter() bstfunc(bst, next_dfs_preorder)(bst()* b, bst_iter() it) {
  return (bst_iter()){};
}

static bst_iter() bstfunc(bst, next_dfs_postorder)(bst()* b, bst_iter() it) {
  return (bst_iter()){};
}

bst_iter() bstfunc(bst, begin)(bst()* b, itertype iter_type) {
  bst_iter() it = {};
  it.iter_type = iter_type;
  it.end = 0;
  switch (it.iter_type) {
    case 0: {
      qfunc(q, free)(&it.q);
      it.q = qfunc(q, new)();
      it.node = b->root;
      if (b->root) {
        if (b->root->left) qfunc(q, enqueue)(&it.q, b->root->left);
        if (b->root->right) qfunc(q, enqueue)(&it.q, b->root->right);
      }
      else {
        it.end = 1;
      }
      break;
    }
    default: assert(0 && "Not implmented");
  }
  return it;
}

int bstfunc(bst, end)(bst()* b, bst_iter() it) {
  return it.end;
}

bst_iter() bstfunc(bst, next)(bst()* b, bst_iter() it) {
  switch (it.iter_type) {
    case BFS:          return bstfunc(bst, next_bfs)(b, it); break;
    case DFS_INORDER:  return bstfunc(bst, next_dfs_inorder)(b, it); break;
    case DFS_PREORDER: return bstfunc(bst, next_dfs_preorder)(b, it); break;
    case DFS_POSTORDER: return bstfunc(bst, next_dfs_postorder)(b, it); break;
    default: assert(0 && "Not implmented");
  }
}
