THIS_MAKEFILE := $(lastword $(MAKEFILE_LIST))
THIS_DIR   := $(dir $(abspath $(THIS_MAKEFILE)))

OUT ?= out
DRIVER_OUTDIR := $(OUT)
DRIVER_SOURCES := $(THIS_DIR)/main.c\
                  $(THIS_DIR)/bst_str_driver.c\
                  $(THIS_DIR)/bst_int_driver.c\
                  $(THIS_DIR)/ht_str_int_driver.c\
                  $(THIS_DIR)/q_int_driver.c\
                  $(THIS_DIR)/stack_int_driver.c\
                  $(THIS_DIR)/ll_int_driver.c\
                  $(THIS_DIR)/da_int_driver.c\
                  $(THIS_DIR)/avl_int_driver.c\

driver_always:
	mkdir -p $(OUT)

$(OUT)/driver: $(DRIVER_SOURCES) | driver_always $(OUT)/libdsaimpls.a
	gcc -std=c99 -o $@ $^ -L$(OUT) -ldsaimpls -ggdb
