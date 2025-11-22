OUT_DIR := out

# data structures library
DSA_LIB_OUTDIR  := $(OUT_DIR)/dsalib
DSA_LIB_SRCDIR  := src/dsalib
DSA_LIB_SOURCES := $(DSA_LIB_SRCDIR)/hashtable.c
DSA_LIB_OBJECTS := $(patsubst $(DSA_LIB_SRCDIR)/%.c, $(DSA_LIB_OUTDIR)/%.c.o, $(DSA_LIB_SOURCES))

# driver
DRIVER_SRCDIR := src/driver
DRIVER_SOURCES := $(DRIVER_SRCDIR)/main.c

# tests
TESTS_SRC_DIR := tests
TESTS_SOURCES := $(TESTS_SRC_DIR)/*.c

.PHONY: always clean
.PHONY: build_static
.PHONY: build_driver
.PHONY: build_tests run_tests

## ========================
##  Utility targets
## ========================
always:
	mkdir -p $(OUT_DIR)/tests
	mkdir -p $(OUT_DIR)/normal
	mkdir -p $(OUT_DIR)/dsalib

clean:
	rm -r $(OUT_DIR)

## ========================
##  Static library build
## ========================
build_static: always $(OUT_DIR)/libdsa.a

$(OUT_DIR)/libdsa.a: $(DSA_LIB_OBJECTS)
	ar rcs $@ $^

$(DSA_LIB_OUTDIR)/%.c.o: $(DSA_LIB_SRCDIR)/%.c
	$(CC) -c $^ -o $@
## ========================

## ========================
##  Driver build
## ========================
build_driver: always $(OUT_DIR)/driver

$(OUT_DIR)/driver: $(DRIVER_SOURCES) | $(OUT_DIR)/libdsa.a
	$(CC) $^ -o $@ -L$(OUT_DIR) -ldsa -I$(DSA_LIB_SRCDIR)
## ========================

## ========================
##  Tests build
## ========================
build_tests: always $(OUT_DIR)/test

$(OUT_DIR)/test: $(TESTS_SOURCES) | $(OUT_DIR)/libdsa.a
	$(CC) -o $@ $^ -L$(OUT_DIR) -ldsa -I$(DSA_LIB_SRCDIR)
## ========================
