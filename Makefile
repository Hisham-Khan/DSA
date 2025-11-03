# ==============================================================================
# Makefile for Data Structures and Algorithms (DSA) - Linked List
# ==============================================================================

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c11

# Source files
SOURCES = main.c LinkedList/LinkedList.c

# Output executable
TARGET = DsaOut

# ==============================================================================
# Targets
# ==============================================================================

# Default target - compile the program
all: $(TARGET)

# Compile and link
$(TARGET): $(SOURCES) LinkedList/LinkedList.h
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)
    @echo "Build complete: $(TARGET)"

# Run the program
run: $(TARGET)
	./$(TARGET)

# Clean compiled files
clean:
	rm -f $(TARGET)
	@echo "Clean complete"

# Rebuild
re: clean all

# Phony targets
.PHONY: all clean re run
