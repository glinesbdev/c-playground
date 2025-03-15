CC ::= gcc
CFLAGS ::= -Wall -g -Isrc
SRC_DIR := src
SRC := $(wildcard $(SRC_DIR)/*.c)
EXE := bin/reverse
RM := rm -rf

TEST_DIR := tests
TEST_INCLUDES := unity/src
TEST_SRC := $(wildcard $(TEST_DIR)/*.c)
TEST_SRC += $(wildcard $(TEST_INCLUDES)/*.c)
TEST_SRC += $(SRC_DIR)/strings.c
TEST_EXE := $(TEST_DIR)/bin/tests

all: $(EXE)

test: $(TEST_EXE)

test_run: test
	./$(TEST_EXE)

clean:
	$(RM) $(EXE)
	$(RM) $(TEST_EXE)

$(EXE): $(SRC) $(DEPS)
	$(CC) $(CFLAGS) $^ -o $@

$(TEST_EXE): $(TEST_SRC)
	$(CC) $(CFLAGS) -I$(TEST_INCLUDES) $^ -o $@

.PHONY: all test test_run clean

