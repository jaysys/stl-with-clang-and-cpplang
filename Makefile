# Compilers
CC = gcc
CXX = g++

# Compiler flags
CFLAGS = -Wall -Wextra -std=c99
CXXFLAGS = -Wall -Wextra -std=c++17

# Source files
C_SRCS = app.c utils.c
CPP_SRCS = stl_usecase.cpp

# Object files
C_OBJS = $(C_SRCS:.c=.o)
CPP_OBJS = $(CPP_SRCS:.cpp=.o)

# Executable name
TARGET = app

# Default target
all: $(TARGET)


# Main target with C++ linking
$(TARGET): $(C_OBJS) $(CPP_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile .c files to .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Compile .cpp files to .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(C_OBJS) $(CPP_OBJS) $(TARGET) *.o

# Run program
run: $(TARGET)
	@echo "\n=== Running Program ==="
	@./$(TARGET)

# Clean and run
rerun: clean run

# Phony targets (don't create files with these names)
.PHONY: all clean run rerun
