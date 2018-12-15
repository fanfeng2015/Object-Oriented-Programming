#------------------------------------------------------
# Macro definitions
CXXFLAGS = -O1 -g -Wall -std=c++17
OBJ = main.o tools.o simulator.o population.o blockchain.o SPtr.o block.o serial.o
TARGET = blockchain
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
population.o: population.cpp population.hpp agent.hpp fickle.hpp crowd.hpp nakamoto.hpp
blockchain.o: blockchain.cpp blockchain.hpp SPtr.hpp block.hpp serial.hpp
SPtr.o: SPtr.cpp SPtr.hpp block.hpp serial.hpp
block.o: block.cpp block.hpp
serial.o: serial.cpp serial.hpp
