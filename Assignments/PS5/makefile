#------------------------------------------------------
# Macro definitions
CXXFLAGS = -O1 -g -Wall -std=c++17
OBJ = main.o tools.o simulator.o population.o fickle.o crowd.o
TARGET = consensus2
# -----------------------------------------------------
#  Rules
all: $(TARGET)
$(TARGET): $(OBJ)
	$(CXX) -o $@ $(OBJ)
clean:
	rm -f $(OBJ) $(TARGET)
#------------------------------------------------------
# Dependencies
main.o: main.cpp tools.hpp simulator.hpp population.hpp agent.hpp
tools.o: tools.cpp tools.hpp
simulator.o: simulator.cpp simulator.hpp population.hpp agent.hpp
population.o: population.cpp population.hpp agent.hpp fickle.hpp crowd.hpp
fickle.o: fickle.cpp fickle.hpp agent.hpp
crowd.o: crowd.cpp crowd.hpp agent.hpp
