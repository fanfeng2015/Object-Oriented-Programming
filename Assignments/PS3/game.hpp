// -*- mode: c++; tab-width: 4 -*-
// File: game.hpp--------------------------------------------------------------
// Author: Fan Feng
// NetID: ff242
// Course: CPSC 427/527
// Assignment: 3

#include "thinkadot.hpp"
#include "tools.hpp"

class Game {
private:
	ThinkADot tad;

public:
	Game() = default;
	void play();
};
