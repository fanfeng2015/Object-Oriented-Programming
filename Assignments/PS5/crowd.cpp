// -*- mode: c++; tab-width: 4 -*-
// File: crowd.cpp--------------------------------------------------------------
// Author: Fan Feng
// NetID: ff242
// Course: CPSC 427/527
// Assignment: 5

#include "crowd.hpp"

// Constructor
Crowd::Crowd(int ch) {
	cur = ch;
	state = ch;
}

// Perform the update to the agent as specified by algorithm follow the
// crowd upon receipt of the message m.
void Crowd::update(int m) {
	if (state != m) {
		state = m;
	}
	else {
		cur = m;
	}
}

// Return the agent's current choice.
int Crowd::choice() const {
	return cur;
}
