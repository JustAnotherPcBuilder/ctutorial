.SECONDARY:
.NOTPARALLEL: all

CC = gcc
CFLAGS = -Wall -g -Iinclude

BIN_DIR := bin
SRC_DIR := src
OBJ_DIR := obj
TEST_DIR := test

TESTS	:= $(notdir $(wildcard $(TEST_DIR)/*.c))
SRCS	:= $(notdir $(wildcard $(SRC_DIR)/*.c))
OBJS	:= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

TARGETS := $(addprefix $(BIN_DIR)/, $(TESTS:.c=))

.PHONY: all clean build run print new #test log

all: clean build run

build: $(TARGETS) 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN_DIR)/%: $(TEST_DIR)/%.c $(OBJS)
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $(OBJS) $< -o $@

new-%:
	@mkdir -p $(TEST_DIR)
	@if [ ! -f "$(TEST_DIR)/$*.c" ]; then \
	printf "#include <stdio.h>\n\nint main()\n{\n    return 0;\n}" > "$(TEST_DIR)/$*.c"; fi

print:
	@echo "Targets: $(TARGETS)"
	@echo "Srcs: $(SRCS)"
	@echo "objs: $(OBJS)"

run: $(TARGETS)
	@for t in $(TARGETS); do \
		echo "Running: $$t"; \
		./$$t; \
	done

clean:
	rm -rf $(BIN_DIR) $(OBJ_DIR)
