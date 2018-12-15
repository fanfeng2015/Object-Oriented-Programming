// -*- mode: c++; tab-width: 4 -*-
// File: agent.cpp--------------------------------------------------------------
// Author: Fan Feng
// NetID: ff242
// Course: CPSC 427/527
// Assignment: 4

#include "agent.hpp"

// Constructor
Agent::Agent(int ch) {
	cur = ch;
}

// Perform the update to the agent as specified by algorithm fickle
// upon receipt of the message m.
void Agent::update(int m) {
	cur = m;
}

// Return the agent's current choice.
int Agent::choice() const {
	return cur;
}
