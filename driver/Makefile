THIS_MAKEFILE := $(lastword $(MAKEFILE_LIST))
THIS_DIR   := $(dir $(abspath $(THIS_MAKEFILE)))

OUT ?= out
DRIVER_OUTDIR := $(OUT)
DRIVER_SOURCES := $(THIS_DIR)/main.c

driver_always:
	mkdir -p $(OUT)

$(OUT)/driver: $(DRIVER_SOURCES) | driver_always $(OUT)/libdsaimpls.a
	$(CC) -o $@ $^ -L$(OUT) -ldsaimpls -ggdb
