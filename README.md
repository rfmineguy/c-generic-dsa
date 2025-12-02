# C Generic DSA
This is a project that aims to make creating generic and correct datastructures easy and type checked in C.

# Why?
Ever since I started programming in C, I've wanted the ability to use datastructures with different types but felt like re-writing it for each type seemed wasteful.

# How?
The C preprocessor is a wonderfully powerful system that can fascilitate this goal! By defining a single macro I am able to create an entire new data structure specialization.
This project implements a few DSAs as examples, but that doesn't mean you can't write your own in the same style. The macro based generic is a flexible system.

# Examples
For examples on how it works, I recommend looking at the `dsaimpls` folder.<br>
For examples on how to use them, I recommend looking at the `tests` folder.<br>

## Making a Binary Search Tree for Integers
`bst_int.h`
```c
typedef struct bst_int_node bst_int_node;     // forward declare the bst node type for the queue

#undef bst_type_name                          // undefine any previously defined parameters
#undef bst_type_type                          // -
#undef q_type_type                            // -
#undef q_type_name                            // -
#undef stack_type_type                        // -
#undef stack_type_name                        // -

#define stack_type_type bst_int_node*         // tell the stack what it is storing
#define stack_type_name bst_int_node          // -
#include "../dsalib/stack.h"

#define q_type_type bst_int_node*             // tell the queue what it is storing
#define q_type_name bst_int_node              // -
#include "../dsalib/queue.h"

#define bst_type_name int                     // tell the bst what it is storing
#define bst_type_type int                     // -
#include "../dsalib/bst.h"
```

`bst_int.c`
```c
#define bst_type_name int                     // tell the bst what its type is
#define bst_type_type int                     // -

#include <stdio.h>
typedef struct bst_int_node bst_int_node;     // forward declare the bst node like before

#define stack_type_type bst_int_node*         // tell the stack what it is storing
#define stack_type_name bst_int_node          // -
#include "../dsalib/stack.c"

#define q_type_type bst_int_node*             // tell the queue what it is storing
#define q_type_name bst_int_node              // -
#define Q_ALLOW_DIRECT_INCLUDE
#include "../dsalib/queue.c"
#include "../dsalib/bst.h"

// Write required functions specialized for the types you are storing
int bst_int_cmp(int a, int b) {
  if (a < b) return -1;
  if (a > b) return 1;
  return 0;
}

void bst_int_print_val(int val) {
  printf("%d", val);
}

void q_bst_int_node_print_node_val(bst_int_node* val) {
  bst_int_print_val(val->val);
}

void stack_bst_int_node_print_node_val(bst_int_node* val) {
  bst_int_print_val(val->val);
}

#define ALLOW_DIRECT_INCLUDE
#include "../dsalib/bst.c"
```
