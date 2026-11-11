CXX = g++
CXX_FLAGS = -std=c++20 -Wall -Wextra -Wpedantic

all:
	$(CXX) $(CXX_FLAGS) $(FILES) -o main
clean:
	