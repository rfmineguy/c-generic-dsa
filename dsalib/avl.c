#include "avl.h"
#include "queue_avl_node.h"
#include <stdlib.h>
#include <stdio.h>

static void avl_free_node(avl_node* n) {
#define HPIPE "\u2014"
#define XPIPE "\u0371"
#define N     "\u221F"
#define ELBOW "\u23B8"

static int var(avl, rec_depth)[1000];

void avlfunc(print_node)(FILE* f, struct avl_node()* root, int depth, int is_last) {
    if (!root) return;

    for (int i = 0; i < depth; i++) {
        if (i == depth - 1) {
            // bottom connector
            printf("%s", is_last ? "└──" : "├──");
        } else {
            // ancestor levels
            printf("%s", var(avl, rec_depth)[i] ? "│  " : "   ");
        }
    }

    avlfunc(print_val)(f, root->val);
    if (root->count > 1) printf(" (%d)", root->count);
    printf("[%d]", avlfunc(height)(root));
    printf("\n");

    // Mark whether at this depth we should draw a vertical continuation later
    if (depth >= 0) var(avl, rec_depth)[depth] = !is_last;

    // Count children to determine who is last
    int has_left  = root->left  != NULL;
    int has_right = root->right != NULL;

    if (has_left) {
      var(avl, rec_depth)[depth] = has_right ? 1 : 0;
      avlfunc(print_node)(f, root->left, depth + 1, has_right ? 0 : 1);
      var(avl, rec_depth)[depth] = 0;
    }

    if (has_right) {
      var(avl, rec_depth)[depth] = 0;
      avlfunc(print_node)(f, root->right, depth + 1, 1); // right child is always last
      var(avl, rec_depth)[depth] = 0;
    }
}

static void avlfunc(free_node)(struct avl_node()* n) {
  if (!n) return;
  avlfunc(free_node)(n->left);
  avlfunc(free_node)(n->right);
  free(n);
}

static void avl_insert_node(avl_node** n, int val) {
static void avlfunc(update_height)(struct avl_node()* n) {
  if (!n) return;
  int hl = avlfunc(height)(n->left);
  int hr = avlfunc(height)(n->right);
  int max = (hl > hr ? hl : hr);
  n->height = max + 1;
}

static struct avl_node()* avlfunc(insert_node)(struct avl_node()** n, struct avl_node()* parent, int val) {
  if (!(*n)) {
    *n = calloc(1, sizeof(struct avl_node()));
    if (!(*n)) return 0;
    (*n)->val = val;
    (*n)->parent = parent;
    (*n)->count = 1;
    (*n)->height = 1;
    return *n;
  }
  int cmp = avlfunc(cmp)(val, (*n)->val);
  struct avl_node()* inserted = 0;
  if (cmp == 0) {
    (*n)->count++;
    inserted = *n;
  }
  if (cmp < 0) {
    inserted = avlfunc(insert_node)(&(*n)->left, *n, val);
  }
  if (cmp > 0){
    inserted = avlfunc(insert_node)(&(*n)->right, *n, val);
  }

  avlfunc(update_height)(*n);
  return inserted;
}

static struct avl_node()** avlfunc(search_node)(struct avl_node()** root, avl_type_type v) {
  if (!(*root)) return 0;

  int cmp = avlfunc(cmp)(v, (*root)->val);
  if (cmp == 0) return root;
  if (cmp < 0) return avlfunc(search_node)(&(*root)->left, v);
  return avlfunc(search_node)(&(*root)->right, v);
}

static struct avl_node()* avlfunc(delete_node)(struct avl_node()** root, struct avl_node()* parent, avl_type_type v) {
  if (!(*root)) return 0;
  int cmp = avlfunc(cmp)(v, (*root)->val);

  if (cmp < 0)      return avlfunc(delete_node)(&(*root)->left, *root, v);
  else if (cmp > 0) return avlfunc(delete_node)(&(*root)->right, *root, v);
  else {
    struct avl_node() *target = (*root);
    if ((*root)->count > 1) {
      (*root)->count--;
      return *root;
    }
    if ((*root)->left && (*root)->right) {
      struct avl_node() *parent_ = *root;
      struct avl_node() **left = &(*root)->left;
      while ((*left)->right) {
        parent_ = *left;
        left = &(*left)->right;
      }

      avl_type_type v = (*left)->val;
      (*left)->val = (*root)->val;
      (*root)->val = v;

      *left = (*left)->left;
      if (*left)
        (*left)->parent = parent_;
      return parent_;
    }
    if ((*root)->left && !(*root)->right) {
      (*root) = (*root)->left;
      if (*root)
        (*root)->parent = parent;
      return parent;
    }
    if (!(*root)->left && (*root)->right) {
      (*root) = (*root)->right;
      if (*root)
        (*root)->parent = parent;
      return parent;
    }
    *root = 0;
    avlfunc(update_height)(parent);
    return parent;
  }
}

/*
 *   A
 *  / \
 * Y   B
 *    / \
 *   X   C
 */
struct avl_node()* avlfunc(rotate_right)(struct avl_node()* n) {
  struct avl_node()* newroot = n->left;   // Y
  struct avl_node()* right = newroot->right;

  newroot->right = n;
  newroot->parent = n->parent;
  n->left = right;
  n->parent = newroot;
  if (right) right->parent = newroot;

  avlfunc(update_height)(n);
  avlfunc(update_height)(newroot);

  return newroot;
}

struct avl_node()* avlfunc(rotate_left)(struct avl_node()* n) {
  struct avl_node()* newroot = n->right;   // Y
  struct avl_node()* left = newroot->left;

  newroot->left = n;
  newroot->parent = n->parent;
  n->right = left;
  n->parent = newroot;
  if (left) left->parent = newroot;

  avlfunc(update_height)(n);
  avlfunc(update_height)(newroot);

  return newroot;
}

static int avlfunc(bf)(struct avl_node()* root) {
  if (!root) return 0;
  return avlfunc(height)(root->left) - avlfunc(height)(root->right);
}
static void avlfunc(rebalance_insert)(avl()* avl, struct avl_node()* n) {
  if (!n->parent) return;
  if (!n->parent->parent) return;

  struct avl_node()* gp = n->parent->parent;
  struct avl_node()* old_gp = gp;
  struct avl_node()* gpp = gp->parent;

  while (gp) {
    old_gp = gp;
    gpp = gp->parent;
    int bf = avlfunc(bf)(gp);

    if (bf > 1 && n->val < gp->left->val) {
      gp = avlfunc(rotate_right)(gp);
    }
    if (bf < -1 && n->val > gp->right->val) {
      gp = avlfunc(rotate_left)(gp);
    }
    if (bf > 1 && n->val > gp->left->val) {
      gp->left = avlfunc(rotate_left)(gp->left);
      gp = avlfunc(rotate_right)(gp);
    }
    if (bf < -1 && n->val < gp->right->val) {
      gp->right = avlfunc(rotate_right)(gp->right);
      gp = avlfunc(rotate_left)(gp);
    }

    if (gpp == NULL) {
      avl->root = gp;
      gp->parent = NULL;
    }
    else if (gpp->left == old_gp) {
      gpp->left = gp;
      gp->parent = gpp;
    }
    else {
      gpp->right = gp;
      gp->parent = gpp;
    }

    gp = gp->parent;
  }
}
static struct avl_node() **avlfunc(link_to)(avl() *avl, struct avl_node() *n) {
  if (!n->parent)
    return &avl->root;

  if (n->parent->left == n)
    return &n->parent->left;

  return &n->parent->right;
}
static void avlfunc(rebalance_delete)(struct avl_node()** root) {
  struct avl_node()* n = *root;
  int h_l = avlfunc(height)(n->left);
  int h_r = avlfunc(height)(n->right);
  int bf   = avlfunc(bf)(n);
  if (bf > 1) {
    if (avlfunc(height)(n->left->left) >= avlfunc(height)(n->left->right)) {
      *root = avlfunc(rotate_right)(n);
    }
    else {
      (*root)->left = avlfunc(rotate_left)(n->left);
      *root = avlfunc(rotate_right)(n);
    }
  }
  else if (bf < -1) {
    if (avlfunc(height)(n->right->right) >= avlfunc(height)(n->right->left)) {
      *root = avlfunc(rotate_left)(n);
    }
    else {
      (*root)->right = avlfunc(rotate_right)(n->right);
      *root = avlfunc(rotate_left)(n);
    }
  }

  avlfunc(update_height)(*root);
}
int avlfunc(height)(struct avl_node()* n) {
  if (!n) return 0;
  return n->height;
}

void avlfunc(print)(FILE* f, avl()* avl) {
  printf("AVL\n");
  avlfunc(print_node)(f, avl->root, 0, 1);
}
avl() avlfunc(new)() {
  avl() a = {0};
  return a;
}

void avlfunc(free)(avl()* avl) {
  avlfunc(free_node)(avl->root);
}

void avlfunc(insert)(avl()* avl, int val) {
  struct avl_node()* n = avlfunc(insert_node)(&avl->root, 0, val);
  if (!n) return;
  avlfunc(rebalance_insert)(avl, n);
}

void avlfunc(delete)(avl()* avl, int val) {
  struct avl_node()* n = avlfunc(delete_node)(&avl->root, 0, val);
  struct avl_node()* curr = n;
  while (curr) {
    avlfunc(rebalance_delete)(avlfunc(link_to)(avl, curr));
    curr = curr->parent;
  }
}

void avlfunc(print_dot)(FILE* f, avl()* avl) {
  fprintf(f, "digraph {\n");
  for (struct avl_iter() it = avlfunc(begin)(avl, AVL_BFS); !avlfunc(end)(avl, it); it = avlfunc(next)(avl, it)) {
    avlfunc(print_val)(f, it.node->val);
    fprintf(f, " -> {");
    if (it.node->left)  avlfunc(print_val)(f, it.node->left->val);
    if (it.node->left && it.node->right) {
      fprintf(f, ", ");
    }
    if (it.node->right) avlfunc(print_val)(f, it.node->right->val);
    fprintf(f, " }\n");
  }
  fprintf(f, "}\n");
}

static avl_iter() avlfunc(next_bfs)(avl()* b, avl_iter() it) {
  if (qfunc(empty)(&it.dsa.q)) {
    return (avl_iter()) {.dsa.q = it.dsa.q, .node = 0, .end = 1, .iter_type = it.iter_type};
  }
  it.node = qfunc(dequeue)(&it.dsa.q)->val;
  if (it.node->left)  qfunc(enqueue)(&it.dsa.q, it.node->left);
  if (it.node->right) qfunc(enqueue)(&it.dsa.q, it.node->right);
  return it;
}

static avl_iter() avlfunc(next_dfs_inorder)(avl()* b, avl_iter() it) {
  if (!stackfunc(top)(&it.dsa.stack)) 
    return (avl_iter()) {.dsa.stack = it.dsa.stack, .node = 0, .end = 1, .iter_type = it.iter_type};

  avl_node()* n = stackfunc(pop)(&it.dsa.stack)->val;
  if (!n) {
    it.end = 1;
    return it;
  }
  it.node = n;

  avl_node()* right = n->right;
  while (right) {
    stackfunc(push)(&it.dsa.stack, right);
    right = right->left;
  }
  return it;
}

static avl_iter() avlfunc(next_dfs_preorder)(avl()* b, avl_iter() it) {
  if (!stackfunc(top)(&it.dsa.stack)) 
    return (avl_iter()) {.dsa.stack = it.dsa.stack, .node = 0, .end = 1, .iter_type = it.iter_type};

  avl_node()* n = stackfunc(pop)(&it.dsa.stack)->val;
  it.node = n;

  if (n->right) stackfunc(push)(&it.dsa.stack, n->right);
  if (n->left) stackfunc(push)(&it.dsa.stack, n->left);

  return it;
}

static avl_iter() avlfunc(next_dfs_postorder)(avl()* b, avl_iter() it) {
  return (avl_iter()){};
}

avl_iter() avlfunc(begin)(avl()* b, avl_iter_type iter_type) {
  avl_iter() it = {};
  it.iter_type = iter_type;
  it.end = 0;
  switch (it.iter_type) {
    case AVL_BFS: {
      qfunc(free)(&it.dsa.q);
      it.dsa.q = qfunc(new)();
      it.node = b->root;
      if (b->root) {
        if (b->root->left) qfunc(enqueue)(&it.dsa.q, b->root->left);
        if (b->root->right) qfunc(enqueue)(&it.dsa.q, b->root->right);
      }
      else {
        it.end = 1;
      }
      break;
    }
    case AVL_INORDER: {
      stackfunc(free)(&it.dsa.stack);
      it.dsa.stack = stackfunc(new)();
      avl_node()* curr = b->root;
      while (curr) {
        stackfunc(push)(&it.dsa.stack, curr);
        curr = curr->left;
      }
      it.node = stackfunc(pop)(&it.dsa.stack)->val;
      if (!it.node) it.end = 1;
      break;
    }
    case AVL_PREORDER: {
      stackfunc(free)(&it.dsa.stack);
      it.dsa.stack = stackfunc(new)();
      it.node = b->root;
      if (b->root) {
        if (b->root->left) stackfunc(push)(&it.dsa.stack, b->root->left);
        if (b->root->right) stackfunc(push)(&it.dsa.stack, b->root->right);
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

int avlfunc(end)(avl()* b, avl_iter() it) {
  return it.end;
}

avl_iter() avlfunc(next)(avl()* b, avl_iter() it) {
  switch (it.iter_type) {
    case AVL_BFS:          return avlfunc(next_bfs)(b, it); break;
    case AVL_INORDER:  return avlfunc(next_dfs_inorder)(b, it); break;
    case AVL_PREORDER: return avlfunc(next_dfs_preorder)(b, it); break;
    case AVL_POSTORDER: return avlfunc(next_dfs_postorder)(b, it); break;
    default: assert(0 && "Not implmented");
  }
}
