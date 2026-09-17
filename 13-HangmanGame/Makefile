.SECONDARY:

CC = gcc
CFLAGS = -Wall -g -Iinclude

SRCS := $(notdir $(wildcard *.c))
TARGETS :=  $(SRCS:.c=)

.PHONY: all build print clean test log new

all:
	$(MAKE) clean
	$(MAKE) build

build: $(TARGETS)

%:
	$(CC) $(CFLAGS) $@.c -o $@

new-%:
	@if [ ! -f "$*.c" ]; then \
	echo "#include <stdio.h>\n\nint main()\n{\n    return 0;\n}" > "$*.c"; fi

print:
	@echo "Targets: $(TARGETS)"
	@echo "Srcs: $(SRCS)"

clean:
	rm -rf $(TARGETS) 

