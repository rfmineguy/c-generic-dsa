#include "avl.h"
#include "queue_avl_node.h"
#include <stdlib.h>
#include <stdio.h>

static void avl_free_node(avl_node* n) {
  if (!n) return;
  avl_free_node(n->left);
  avl_free_node(n->right);
  free(n);
}

static void avl_insert_node(avl_node** n, int val) {
  if (!(*n)) {
    *n = calloc(1, sizeof(avl_node));
    (*n)->val = val;
    return;
  }
  if (val < (*n)->val) 
    avl_insert_node(&(*n)->left, val);
  if (val >= (*n)->val) 
    avl_insert_node(&(*n)->right, val);
}

static void avl_print_node(avl_node* n, int depth) {
  if (!n) {
    printf("%*.s|_ None\n", 2 * (depth), " ");
    return;
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
