#
#   Copyright (c) 2025 - Matt C
#    All rights reserved.
#

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -Wnarrowing -Wconversion -Werror -std=c++20

# Source files
SRC = project.cpp point.cpp board.cpp direction.cpp tile.cpp utils.cpp user_input.cpp

# Header files
HEADERS = point.h board.h direction.h tile.h utils.h user_input.h

# Output file
TARGET = 15_Puzzle

# Build
$(TARGET): $(SRC) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

# Run
run: $(TARGET)
	./$(TARGET)

# Clean
clean:
	rm -rf $(TARGET)