# Compiler and flags
CC = gcc
CFLAGS = -pedantic -Wall -Wextra -Werror

# Source directory
SRCDIR = src

# Find all .c files in src directory
SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(SOURCES:.c=.o)

# Name of the final executable (change this if you want a different name)
TARGET = main

# Default target - build the executable
all: $(TARGET)

# Link all object files into the final executable
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

# Pattern rule to compile .c files to .o files
$(SRCDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Clean up generated files
clean:
	rm -f $(OBJECTS) $(TARGET)

# Run the executable
run: $(TARGET)
	./$(TARGET)

# Debug target to see what files were found
debug:
	@echo "Sources found: $(SOURCES)"
	@echo "Objects to build: $(OBJECTS)"
	@echo "Target executable: $(TARGET)"

# Phony targets
.PHONY: all clean run debug
