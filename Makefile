CC := gcc
CFLAGS := -Wall -Wextra -pedantic --std=c99 -Isrc
DEBUG := $(CFLAGS) -g -O0
RELEASE := $(CFLAGS) -O3

BINARY := reverse
SRC_DIR := src
SRC := $(wildcard $(SRC_DIR)/*.c)
EXE := bin/debug
RELEASE_EXE := bin/release
RM := rm -rf
MKDIR_P := mkdir -p

TEST_DIR := tests
TEST_INCLUDES := unity/src
TEST_SRC := $(wildcard $(TEST_DIR)/*.c)
TEST_SRC += $(wildcard $(TEST_INCLUDES)/*.c)
TEST_SRC += $(SRC_DIR)/strings.c
TEST_EXE := $(TEST_DIR)/bin/tests

all: $(EXE)

release: $(RELEASE_EXE)

tests: $(TEST_EXE)

run_tests: tests
	./$(TEST_EXE)

clean:
	$(RM) $(EXE)
	$(RM) $(RELEASE_EXE)
	$(RM) $(TEST_EXE)

$(EXE): $(SRC) $(DEPS)
	$(MKDIR_P) $@
	$(CC) $(DEBUG) $^ -o $@/$(BINARY)

$(RELEASE_EXE): $(SRC) $(DEPS)
	$(MKDIR_P) $@
	$(CC) $(RELEASE) $^ -o $@/$(BINARY)

$(TEST_EXE): $(TEST_SRC)
	$(CC) $(DEBUG) -I$(TEST_INCLUDES) $^ -o $@

.PHONY: all test test_run clean

