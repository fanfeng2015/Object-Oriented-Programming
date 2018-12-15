#------------------------------------------------------
# Macro definitions
CXXFLAGS = -O1 -g -Wall -std=c++17
OBJ = main.o tools.o simulator.o agent.o
TARGET = consensus
# -----------------------------------------------------
#  Rules
all: $(TARGET)
$(TARGET): $(OBJ)
	$(CXX) -o $@ $(OBJ)
clean:
	rm -f $(OBJ) $(TARGET)
#------------------------------------------------------
# Dependencies
main.o: main.cpp tools.hpp simulator.hpp agent.hpp
tools.o: tools.cpp tools.hpp
simulator.o: simulator.cpp simulator.hpp agent.hpp 
agent.o: agent.cpp agent.hpp
