# VARIABLES
CXX = g++
CXXFLAGS = -Wall -std=c++23
SRC_DIR = source
GAME_DIR = $(SRC_DIR)/game
BUILD_DIR = binary
PLAYER_DIR = $(GAME_DIR)/player
COMPUTER_DIR = $(GAME_DIR)/computer

# SOURCE & BUILD
SOURCES = $(SRC_DIR)/main.cpp \
          $(GAME_DIR)/rockPaperScissors.cpp \
          $(GAME_DIR)/usableStuffs.cpp \
		  $(COMPUTER_DIR)/computer.cpp
		  

TARGET = $(BUILD_DIR)/build.exe

# RULES

all: $(TARGET)

$(TARGET): $(SOURCES)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -rf $(BUILD_DIR)

rebuild: clean all