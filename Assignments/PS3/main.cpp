// -*- mode: c++; tab-width: 4 -*-
// File: main.cpp--------------------------------------------------------------
// Author: Fan Feng
// NetID: ff242
// Course: CPSC 427/527
// Assignment: 3

#include "game.hpp"
#include "tools.hpp"

void run();

int main() {
    banner();
    run();
    bye();
}

// Instantiate Game and call play().
void run() {
	Game game;
	game.play();
}
