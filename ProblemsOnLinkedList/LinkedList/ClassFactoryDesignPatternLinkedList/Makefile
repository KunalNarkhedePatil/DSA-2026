# Compiler
CXX = g++
CXXFLAGS = -Wall -IHeaderFiles

# Folders
SRC_DIR = SourceFiles
INC_DIR = HeaderFiles
OBJ_DIR = obj
BIN_DIR = bin

# Target executable
TARGET = $(BIN_DIR)/myexe

# Source and object files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# Default rule
all: $(TARGET)

# Link objects to create executable
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile each .cpp into .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Run the program
run: all
	./$(TARGET)
