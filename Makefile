CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -Iinclude -Isrc

SRC = $(shell find src -name "*.cpp")
OBJ = $(patsubst src/%.cpp,.build/%.o,$(SRC))

TARGET = .build/server

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

.build/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf .build

re: clean all