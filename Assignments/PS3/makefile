#------------------------------------------------------
# Macro definitions
CXXFLAGS = -O1 -g -Wall -std=c++17
OBJ = main.o tools.o game.o thinkadot.o
TARGET = tad
# -----------------------------------------------------
#  Rules
all: $(TARGET)
$(TARGET): $(OBJ)
	$(CXX) -o $@ $(OBJ)
clean:
	rm -f $(OBJ) $(TARGET)
#------------------------------------------------------
# Dependencies
main.o: main.cpp tools.hpp game.hpp thinkadot.hpp flipflop.hpp
tools.o: tools.cpp tools.hpp
game.o: game.cpp game.hpp tools.hpp thinkadot.hpp flipflop.hpp
thinkadot.o: thinkadot.cpp thinkadot.hpp tools.hpp flipflop.hpp
