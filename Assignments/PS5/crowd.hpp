// -*- mode: c++; tab-width: 4 -*-
// File: crowd.hpp--------------------------------------------------------------
// Author: Fan Feng
// NetID: ff242
// Course: CPSC 427/527
// Assignment: 5

#ifndef CROWD_HPP
#define CROWD_HPP

#include "agent.hpp"

class Crowd : public Agent {
private:
	int cur;   // current value of agent
	int state; // current state of agent

public:
	Crowd(int ch);
	virtual ~Crowd() = default;

	virtual void update(int m);
	virtual int choice() const;
};

#endif


