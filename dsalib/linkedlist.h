#include <stdbool.h>
#include <stdio.h>
#include "dsa.h"

#undef func
#undef ll
#undef ll_node

#ifndef ll_type_name
#define ll_type_name int
#error "Must define ll_type_name macro"
#endif

#ifndef ll_type_type
#define ll_type_type int
#error "Must define ll_type_type macro"
#endif

#define llfunc(name)\
  func_expand3(ll, ll_type_name, name)

#define ll()\
  join2(ll, ll_type_name, _)

#define ll_node()\
  join3(ll, ll_type_name, node, _)

typedef struct ll_node() {
  ll_type_type val;
  struct ll_node() *prev, *next;
} ll_node();

typedef struct ll() {
  ll_node() *head, *tail;
} ll();

void             llfunc(print_node_val)(ll_type_type, FILE*);

ll()             llfunc(new)();
void             llfunc(free)(ll()* ll);

const ll_node()* llfunc(pushback)(ll()* ll, ll_type_type val);
const ll_node()* llfunc(pushfront)(ll()* ll, ll_type_type val);

ll_node()*       llfunc(popback)(ll()* ll);
ll_node()*       llfunc(popfront)(ll()* ll);

ll_node()*       llfunc(search)(ll()* ll, ll_type_type v);

ll_type_type     llfunc(count)(ll()* ll);
bool             llfunc(empty)(ll()* ll);

void             llfunc(print)(ll()* ll, FILE* file);
