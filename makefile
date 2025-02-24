CC = g++
CFLAGS = -Wall -g

# Source files
SRCS = lexer.cpp main.cpp symbole.cpp state.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
EXEC = a

# Default target
all: $(EXEC)

# Link object files to create the executable
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compile source files to object files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJS) $(EXEC)

.PHONY: all clean