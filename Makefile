CXX = g++
CXXFLAGS = -Wall -std=c++20 -Iinclude
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)
TARGET = run

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $^ -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

debug: CXXFLAGS += -g -O0
debug: all

.PHONY: all clean debug
