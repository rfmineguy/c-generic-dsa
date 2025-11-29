THIS_MAKEFILE := $(lastword $(MAKEFILE_LIST))
THIS_DIR   := $(dir $(abspath $(THIS_MAKEFILE)))

OUT ?= out
DSA_IMPL_LIB_OUTDIR := $(OUT)/libdsaimpl

DSA_IMPL_LIB_SOURCES := $(THIS_DIR)/queue_int.c\
                        $(THIS_DIR)/queue_str.c\
                        $(THIS_DIR)/queue_avl_node.c\
                        $(THIS_DIR)/ht_str_int.c\
                        $(THIS_DIR)/bst_int.c\
                        $(THIS_DIR)/bst_str.c

DSA_IMPL_LIB_OBJECTS := $(patsubst $(THIS_DIR)/%.c, $(DSA_IMPL_LIB_OUTDIR)/%.c.o, $(DSA_IMPL_LIB_SOURCES))

dsaimpls_always:
	mkdir -p $(DSA_IMPL_LIB_OUTDIR)

$(OUT)/libdsaimpls.a: $(DSA_IMPL_LIB_OBJECTS)
	ar rcs $@ $^

$(DSA_IMPL_LIB_OUTDIR)/%.c.o: $(THIS_DIR)/%.c | dsaimpls_always
	$(CC) -c $^ -o $@ -ggdb
