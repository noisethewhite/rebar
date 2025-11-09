# ==== CONFIGURATION ====

# Compiler
CXX := g++
CXXFLAGS := -std=c++20 -Wall -Wextra -Wno-subobject-linkage -O2 $(shell pkg-config --cflags sdl3)

# Linker flags (SDL3 libs, etc.)
LDFLAGS := $(shell pkg-config --libs sdl3)

# Folders
SRC_DIR := src
BUILD_DIR := dist
BIN := $(BUILD_DIR)/app

# Find all .cpp files recursively
SRC := $(shell find $(SRC_DIR) -name '*.cc')
OBJ := $(SRC:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# ==== RULES ====

# Default target
all: $(BIN)

# Link final executable
$(BIN): $(OBJ)
	@mkdir -p $(dir $@)
	$(CXX) $(OBJ) -o $@ $(LDFLAGS)

# Compile each .cpp into a .o file inside dist/
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR)

# Run program
run: $(BIN)
	./$(BIN)

# Phony targets
.PHONY: all clean run