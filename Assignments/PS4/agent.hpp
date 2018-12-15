// -*- mode: c++; tab-width: 4 -*-
// File: agent.hpp--------------------------------------------------------------
// Author: Fan Feng
// NetID: ff242
// Course: CPSC 427/527
// Assignment: 4

#include "tools.hpp"

class Agent {
private:
	int cur;

public:
	Agent() = default;
	Agent(int ch);

	void update(int m);
	int choice() const;
};
