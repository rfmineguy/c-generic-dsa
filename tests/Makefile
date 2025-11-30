THIS_MAKEFILE := $(lastword $(MAKEFILE_LIST))
THIS_DIR   := $(dir $(abspath $(THIS_MAKEFILE)))

OUT ?= out
TESTS_OUTDIR := $(OUT)

TESTS_SOURCES := $(THIS_DIR)/src/ht.c\
								 $(THIS_DIR)/src/ll.c\
								 $(THIS_DIR)/src/queue_int.c\
								 $(THIS_DIR)/src/queue_str.c\
								 $(THIS_DIR)/src/bst_int.c\
								 $(THIS_DIR)/src/bst_str.c\
								 $(THIS_DIR)/src/stack_int.c\
								 $(THIS_DIR)/src/munit.c\
								 $(THIS_DIR)/src/test_main.c

tests_always:
	mkdir -p $(OUT)

$(OUT)/test: $(TESTS_SOURCES) | $(OUT)/libdsaimpls.a tests_always
	$(CC) -o $@ $^ -L$(OUT) -ldsaimpls
