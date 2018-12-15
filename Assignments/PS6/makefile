#------------------------------------------------------
# Macro definitions
CXXFLAGS = -O1 -g -Wall -std=c++17
OBJ = main.o tools.o driver.o blockchain.o SPtr.o block.o serial.o
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
main.o: main.cpp tools.hpp driver.hpp blockchain.hpp SPtr.hpp block.hpp serial.hpp
tools.o: tools.cpp tools.hpp
driver.o: driver.cpp driver.hpp blockchain.hpp SPtr.hpp block.hpp serial.hpp
blockchain.o: blockchain.cpp blockchain.hpp SPtr.hpp block.hpp serial.hpp
SPtr.o: SPtr.cpp SPtr.hpp block.hpp serial.hpp
block.o: block.cpp block.hpp
serial.o: serial.cpp serial.hpp
