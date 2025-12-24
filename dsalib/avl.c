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
  }
  printf("%*.s|_ %d\n", 2 * depth, " ", n->val);
  avl_print_node(n->left, depth + 1);
  avl_print_node(n->right, depth + 1);
}
int avl_depth(avl_node* n) {
  if (!n) return 0;
  int left = avl_depth(n->left);
  int right = avl_depth(n->right);
  return (left > right ? left : right) + 1;
}

void avl_print(avl* avl, int depth) {
  avl_print_node(avl->root, 0);
}
avl avl_new() {
  avl a = {0};
  return a;
}

void avl_free(avl* avl) {
  avl_free_node(avl->root);
}

void avl_insert(avl* avl, int val) {
  avl_insert_node(&avl->root, val);
}

void avl_remove(avl* avl, int val) {
}

void avl_generate_graph_node(avl_node* n, FILE* f) {
  if (!n) return;
  fprintf(f, "\t%d -> {", n->val);
  if (n->left) avl_generate_graph_node(n->left, f);
  if (n->right) avl_generate_graph_node(n->right, f);
  fprintf(f, "\t}\n");
}

void avl_generate_graph(avl* avl, FILE* f) {
  q_avl_node q = q_avl_node_new();
  q_avl_node_free(&q);

  fprintf(f, "digraph D{\n");
  avl_generate_graph_node(avl->root, f);
  fprintf(f, "}");

  q_avl_node_free(&q);
}
