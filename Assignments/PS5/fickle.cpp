// -*- mode: c++; tab-width: 4 -*-
// File: fickle.cpp--------------------------------------------------------------
// Author: Fan Feng
// NetID: ff242
// Course: CPSC 427/527
// Assignment: 5

#include "fickle.hpp"

// Constructor
Fickle::Fickle(int ch) {
	cur = ch;
}

// Perform the update to the agent as specified by algorithm fickle
// upon receipt of the message m.
void Fickle::update(int m) {
	cur = m;
}

// Return the agent's current choice.
int Fickle::choice() const {
	return cur;
}
